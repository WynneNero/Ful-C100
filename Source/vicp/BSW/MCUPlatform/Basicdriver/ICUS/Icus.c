/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department : ITC R&D NKG                                                  *
*   AUTHOR     :                                                       *
************************************************************************
* Object        :
* Module        :	ICUS
* Instance      :
* Description   :	ICUS opertaion.								
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*------------------------------------------------------------------------
* 0.1	   Sep 01,2017   ZhangJie  Initial version
*------------------------------------------------------------------------
* 0.2	   Sep 06,2017   ZhangJie  Update after code review
*------------------------------------------------------------------------
* 0.3	   Sep 08,2017   ZhangJie  Remove unused include head file
*=====================================================================*/

/*============================================================================
 Includes
============================================================================*/
#include "icus.h"
#include "icus_if.h"
#include "icus_dma_if.h"
#include "Icus_define.h"

static U32 Icus_SwappedByteToWord(const U8 * source);
static void Icus_SwappedWordToByte(U32 source, U8 * destination);
static U32 Icus_SwapWord(U32 source);
static ERR_TYPE Icus_WriteData(const U8 *data);
static ERR_TYPE Icus_ReadData(U8 *data);
static ERR_TYPE Icus_WriteMacVerificationData(U32 n_blocks, U32 dataLength, const U8 *dataPtr);
static ERR_TYPE Icus_WriteMacData(U32 dataLength, const U8 *dataPtr);
static ERR_TYPE Icus_WaitBusyFlag(void);
static void Icus_SendCommand(U32 cmd, U32 keyId);
static void Icus_CancelCommand(void);
static ERR_TYPE Icus_Wait4_WRRDY(void);
static ERR_TYPE Icus_Wait4_RDRDY(void);

static U32 nblocks;
static U32 *source_address;

/***********************************************************************
*  Name        : Icus_Init
*  Description : Init function of Icus module.
*  Parameter   : void
*  Returns     :   void
***********************************************************************/
void Icus_Init(void)
{
    Icus_RngInit();
}

/***********************************************************************
*  Name        : Icus_RngInit
*  Description : Init function of Icus RNG generate.
*  Parameter   : void
*  Returns     :   void
***********************************************************************/
void Icus_RngInit(void)
{
    /* Init RNG when not already initialized. */
    if ((ICU_STS & ICUS_STS_RND_INIT) != ICUS_STS_RND_INIT) /* PRQA S 0303 */ /* MD_CRY_0303_REGISTER_ACCESS */ /* SBSW_CRY_REGISTER_ACCESS */
    {
        /* Send command for initializing the RNG */
        ICU_CMD = CMD_INIT_RNG; 

        /* Wait until ICU has finished */
        (void)Icus_WaitBusyFlag();
    }
}

/***********************************************************************
*  Name        : Icus_load_key
*  Description : Extract key to ICUS.
*  Parameter   : dataPtr is the pointer to the messages M1~M5
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_Loadkey(U32 key_id, const U8 *dataPtr, U8 *resultPtr)
{
    ERR_TYPE retVal = ERR_IDLE;
    const U8 *m1m2m3Ptr =NULL;
    U8 *m4m5Ptr =NULL;
    U8 keyId = 0u;
    U8 authId = 0u;
	U8 keyIdBuf = key_id;

    /* Extract KeyID and AuthID from M1 */
    m1m2m3Ptr = dataPtr;
    keyId = (U8)((m1m2m3Ptr[ICUS_KEYEXTRACT_KEY_INFORMATION_OFFSET] & ICUS_KEYEXTRACT_KEYID_MASK) >> 4u);
    authId = (U8)(m1m2m3Ptr[ICUS_KEYEXTRACT_KEY_INFORMATION_OFFSET] & ICUS_KEYEXTRACT_AUTHID_MASK);

    if(key_id > KEY_20)
    {
		retVal = ERR_INVALID_PARAMETER; 
	    return retVal;
	}
	else if (key_id > ICUS_END_OF_FIRST_KEYPAGE )
    {
        keyIdBuf = key_id - ICUS_RAW_OFFSET_SECOND_KEYPAGE;
    }
	else
	{
		keyIdBuf = key_id;	
	}
	
    if((( authId == MASTER_ECU_KEY ) || ( authId == keyId))  
		&& (keyIdBuf == keyId)
      )
    {
        // starts the load key command
        Icus_SendCommand(CMD_LOAD_KEY,key_id);
        
        /* Write the messages M1 to M3 to the ICU*/
        retVal = Icus_WriteData(&m1m2m3Ptr[ICUS_KEYEXTRACT_OFFSET_M1]);
        if(retVal == ERR_OK)
        {
            retVal = Icus_WriteData(&m1m2m3Ptr[ICUS_KEYEXTRACT_OFFSET_M2]);
            if(retVal == ERR_OK)
            {
                retVal = Icus_WriteData(&m1m2m3Ptr[ICUS_KEYEXTRACT_OFFSET_M2+ICUS_KEYEXTRACT_OFFSET_M2_SEC]);
                if(retVal == ERR_OK)
                {
                    retVal = Icus_WriteData(&m1m2m3Ptr[ICUS_KEYEXTRACT_OFFSET_M3]);
                    if(retVal == ERR_OK)
                    {
                        /* M4 and M5 will be stored to the dummy buffer which will be discarded */
                        m4m5Ptr = resultPtr;
                        
                        /* Read response from ICU and save it to the dummy buffer */
                        retVal = Icus_ReadData(&m4m5Ptr[ICUS_KEYEXTRACT_OFFSET_M4]);
                        if(retVal == ERR_OK)
                        {
                            retVal = Icus_ReadData(&m4m5Ptr[ICUS_KEYEXTRACT_OFFSET_M4+ICUS_KEYEXTRACT_OFFSET_M4_SEC]);
                            if(retVal == ERR_OK)
                            {
                                retVal = Icus_ReadData(&m4m5Ptr[ICUS_KEYEXTRACT_OFFSET_M5]);
                                if(retVal == ERR_OK)
                                {
                                    /* Wait until ICU has finished */
                                    retVal = Icus_WaitBusyFlag();
                                    if(retVal == ERR_OK)
                                    {
                                         /* Check if errors occured*/
                                        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
                                        {
                                            retVal = ERR_OK;
                                        }
                                        else
                                        {
                                            retVal = ERR_FAULT;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        Icus_CancelCommand();
        CLEAR_RDRDY;
        CLEAR_WRRDY;
   }
   else
   {
       retVal = ERR_INVALID_PARAMETER;
   }
   return retVal;
}

/***********************************************************************
*  Name        : Icus_CmacAes128Gen
*  Description : Generate data CMAC using Aes128.
*  Parameter   : key_id is the key used to generate CMAC
                        dataPtr is the point to the source data
                        dataLength is the source data length
                        MacPtr is the point to the data after CMAC generate 
                        MacLength is the MAC data length
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_CmacAes128Gen(U32 key_id, const U8 *dataPtr, U32 dataLength, U8* MacPtr,U32 MacLength)
{
    ERR_TYPE retVal = ERR_IDLE;
    U32 block;
    U32 offset;
    U32 n_blocks;
    U8 writeBuffer[ICUS_CMACAES128GEN_BLOCKSIZE];
    U8 readBuffer[ICUS_CMACAES128GEN_BLOCKSIZE];
    U8 i;

    /* Calculate number of needed blocks */
    n_blocks = dataLength / ICUS_CMACAES128GEN_BLOCKSIZE;
    /* Calculate Modulo when padding is necessary */
    if ((dataLength & (ICUS_CMACAES128GEN_BLOCKSIZE - 1)) != 0u)
    {
        n_blocks++;
    }

    /* Write the 64bit message length to the ICU */  
    ICU_IDAT = 0u;   /* HighWord always zero - Assume that the message doesn't exceed 512 mBytes */ 
    ICU_IDAT = Icus_SwapWord(dataLength * ICUS_CMACAES128GEN_BITS_PER_BYTE); /* Write LowWord to ICU */ 
    ICU_IDAT = 0u;   /* HighWord of MAC is 0 */
    ICU_IDAT = 0u;   /* LowWord of MAC is 0 */

    /* Send the command for generating the MAC */
    Icus_SendCommand(CMD_GENERATE_MAC,key_id);

    /* Write message to ICU */
    for (block = 0u; block < n_blocks; block++)
    {
        /* Get the offset for the block */
        offset = block * ICUS_CMACAES128GEN_BLOCKSIZE;

        /* Copy source to buffer */
        for (i = 0u; i < ICUS_CMACAES128GEN_BLOCKSIZE; i++)
        {
            /* Check if there is enough data available */
            if ((offset + i) < dataLength)
            {
                writeBuffer[i] = dataPtr[offset + i]; 
            }
            else
            {
                /* Padding with 0 */
                writeBuffer[i] = 0u; 
            }
        }

        /* Wait for input request and send current block of plain text to ICU */
        retVal = Icus_WriteData(writeBuffer); 
        if(retVal !=ERR_OK)
        {
            break;
        }
    }
    if(retVal ==ERR_OK)
    {
        /* Wait for output request and read current block of cipher text from ICU */
        retVal = Icus_ReadData(readBuffer); 
        if(retVal ==ERR_OK)
        {
            for (i = 0u; i < MacLength; i++)
            {
                MacPtr[i] = readBuffer[i];
            }
            /* Wait until ICU has finished */
            retVal = Icus_WaitBusyFlag();
        }
    }
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    if(retVal ==ERR_OK)
    {
        /* Check if errors occured*/
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            retVal = ERR_OK;
        }
        else
        {
            retVal = ERR_FAULT;
        }
    }
    return retVal;
    
}

/***********************************************************************
*  Name        : Icus_CmacAes128Ver
*  Description : Verify data CMAC using Aes128.
*  Parameter   : key_id is the key used to verify CMAC
                        dataPtr is the point to the source data
                        dataLength is the source data length
                        MacPtr is the point to the CMAC data
                        MacLength is the CMAC data length
                        resultPtr is the result after CMAC verify
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_CmacAes128Ver(U32 key_id, const U8* dataPtr, U32 dataLength, const U8 *MacPtr, U32 MacLength, U8 *resultPtr)
{
    ERR_TYPE retVal = ERR_IDLE;
    U8 verifyResult = ICUS_E_VER_NOT_OK;
    U32 n_blocks;
    U8 verificationStatus[ICUS_CMACAES128VER_BLOCKSIZE];
    U32 macLengthInBits;
    if (MacLength != 0)
    {
        macLengthInBits = MacLength * ICUS_CMACAES128VER_BITS_PER_BYTE;
        
        /* Calculate number of needed blocks */
        n_blocks = dataLength / ICUS_CMACAES128VER_BLOCKSIZE;

        /* Calculate modulo to find out if padding is necessary */
        if ((dataLength & (ICUS_CMACAES128VER_BLOCKSIZE - 1)) != 0u)
        {
            n_blocks++;
        }
        
        /* Write the 64bit message length to the ICU */ 
        ICU_IDAT = 0u;   /* HighWord always zero - Assume that the message doesn't exceed 512 mBytes */ 
        ICU_IDAT = Icus_SwapWord(dataLength * ICUS_CMACAES128VER_BITS_PER_BYTE); /* Write data length LowWord to ICU */
        if (macLengthInBits != ICUS_CMACAES128VER_MAX_MAC_LENGTH_IN_BITS)
        {
            ICU_IDAT = macLengthInBits; /* MacLength in Bits */ 
        }
        else
        {
            ICU_IDAT = 0u; /* Write zero when verifying 128 bits */
        }
        ICU_IDAT = 0u;   /* LowWord of MAC is always 0 */

        /* Send MAC verification command to ICUS */
        Icus_SendCommand(CMD_VERIFY_MAC,key_id);

        /* Write message to ICUS */
        retVal = Icus_WriteMacVerificationData(n_blocks, dataLength, dataPtr);

        if(retVal == ERR_OK)
        {
            /* Write MAC to ICUS */
            retVal = Icus_WriteMacData(MacLength, MacPtr);

            if(retVal == ERR_OK)
            {
                if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
                {
                    /* Read verification status only when no errors occured */
                    retVal = Icus_ReadData(verificationStatus);
                }
                else
                {
                    verificationStatus[ICUS_CMACAES128VER_VERIFICATION_STATUS_OFFSET] = 1u; 
                }
                if(retVal == ERR_OK)
                {
                    /* Wait until ICUS has finished. */
                    retVal = Icus_WaitBusyFlag();
                }
            }
        }
        
        if(retVal == ERR_OK)
        {
            /* Check for errors */
            if ((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR)
            {
                if ((verificationStatus[ICUS_CMACAES128VER_VERIFICATION_STATUS_OFFSET] & ICUS_CMACAES128VER_VERIFICATION_STATUS_MASK) == 0u)
                {
                    verifyResult = ICUS_E_VER_OK;
                }
                else
                {
                    verifyResult = ICUS_E_VER_NOT_OK;
                }
                retVal = ERR_OK;
            }
            else if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_GENERAL_ERROR)
            {
                verifyResult = ICUS_E_VER_NOT_OK;
                retVal = ERR_OK;
            }
            else
            {
                retVal = ERR_FAULT;
                verifyResult = ICUS_E_VER_NOT_OK;
            }
        }
    }
    else/* MacLength == 0 */
    {
        verifyResult = ICUS_E_VER_OK;
        retVal = ERR_OK;
    }

    Icus_CancelCommand();
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    
    /* Write back the result of the verification */
    *resultPtr = verifyResult;
    return retVal ;
}

/***********************************************************************
*  Name        : Icus_EncryptECB
*  Description : Encrypt message via ECB.
*  Parameter   : key_id is the key used to encrypt
                        plainTextPtr is the point to the message which need encrypt
                        plainTextLength is the encrypt message length
                        cipherTextPtr is the point to the data after encrypt finished
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_AesEncrypt128ECB(U32 key_id, const U8 *plainTextPtr, U32 plainTextLength, U8*cipherTextPtr)
{  
    ERR_TYPE retVal = ERR_IDLE;
    U32  n_blocks = 0u;
    U32 current_block = 0u;
    U32 offset = 0u;

     /* Calculate number of needed blocks for the encryption. */
    n_blocks = plainTextLength / ICUS_AESENCRYPT128_BLOCKSIZE;

    /* Set number of blocks to be transfered */
    ICU_IDATNUM = n_blocks;

    /* Set key id and command for AES encryption in ECB mode */
    Icus_SendCommand(CMD_ENC_ECB,key_id);

    // processes n blocks of 128 bits
    for (current_block = 0u; current_block < n_blocks; current_block++)
    {
        /* Get the offset for the block */
        offset = current_block * ICUS_AESENCRYPT128_BLOCKSIZE;

        /* Wait for input request and send current block of plain text to ICU */
        retVal = Icus_WriteData(&plainTextPtr[offset]);

        if(retVal == ERR_OK)
        {
            /* Wait for output request and read current block of cipher text from ICU */
            retVal = Icus_ReadData(&cipherTextPtr[offset]); 
        }
    }


    if(retVal == ERR_OK)
    {
        /* Wait until ICUS has finished. */
        retVal = Icus_WaitBusyFlag();
    }

    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if(retVal == ERR_OK)
    {
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            retVal = ERR_OK;
        }
        else
        {
            retVal = ERR_FAULT;
        }
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_DecryptECB
*  Description : Decrypt message via ECB.
*  Parameter   : key_id is the key used to Decrypt
                        cipherTextPtr is the point to the message which need decrypt
                        cipherTextLength is the decrypt message length
                        plainTextPtr is the point to the data after decrypt finished
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_AesDecrypt128ECB(U32 key_id, const U8 *cipherTextPtr, U32 cipherTextLength, U8*plainTextPtr)
{  
    ERR_TYPE retVal = ERR_IDLE;
    U32  n_blocks = 0u;
    U32 current_block = 0u;
    U32 offset = 0u;

    /* Calculate number of needed blocks for the decryption. */
    n_blocks = cipherTextLength / ICUS_AESENCRYPT128_BLOCKSIZE;

    /* Set number of blocks to be transfered */
    ICU_IDATNUM = n_blocks;

    /* Set key id and command for AES decryption in ECB mode */
    Icus_SendCommand(CMD_DEC_ECB,key_id);

    // processes n blocks of 128 bits
    for (current_block = 0u; current_block < n_blocks; current_block++)
    {
        /* Get the offset for the block */
        offset = current_block * ICUS_AESENCRYPT128_BLOCKSIZE;

        /* Wait for input request and send current block of plain text to ICU */
        retVal = Icus_WriteData(&cipherTextPtr[offset]);

        if(retVal == ERR_OK)
        {
            /* Wait for output request and read current block of cipher text from ICU */
            retVal = Icus_ReadData(&plainTextPtr[offset]); 
        }
    }


    if(retVal == ERR_OK)
    {
        /* Wait until ICUS has finished. */
        retVal = Icus_WaitBusyFlag();
    }
    
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if(retVal == ERR_OK)
    {
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            retVal = ERR_OK;
        }
        else
        {
            retVal = ERR_FAULT;
        }
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_EncryptCBC
*  Description : Encrypt message via CBC.
*  Parameter   : key_id is the key used to encrypt
                        plainTextPtr is the point to the message which need encrypt
                        plainTextLength is the encrypt message length
                        cipherTextPtr is the point to the data after encrypt finished
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_AesEncrypt128CBC(U32 key_id, const U8 *plainTextPtr, U32 plainTextLength, U8*cipherTextPtr,const U8 *IV)
{  
    ERR_TYPE retVal = ERR_IDLE;
    U32  n_blocks = 0u;
    U32 current_block = 0u;
    U32 offset = 0u;

    /* Calculate number of needed blocks for the encryption. */
    n_blocks = plainTextLength / ICUS_AESDECRYPT128_BLOCKSIZE;

    /* Set number of blocks to be transfered (plainText + IV) */
    ICU_IDATNUM = n_blocks + ICUS_AESDECRYPT128_IVBLOCK;

    /* Set key id and command for AES encryption in CBC mode */
    Icus_SendCommand(CMD_ENC_CBC,key_id);

    /* Send IV from workspace to ICUS in case AES is in CBC mode */
    retVal = Icus_WriteData(IV);

    // processes n blocks of 128 bits
    if(retVal == ERR_OK)
    {
        for (current_block = 0u; current_block < n_blocks; current_block++)
        {
            /* Get the offset for the block */
            offset = current_block * ICUS_AESDECRYPT128_BLOCKSIZE;

            /* Wait for input request and send current block of plain text to ICU */
            retVal = Icus_WriteData(&plainTextPtr[offset]);

            if(retVal == ERR_OK)
            {
                /* Wait for output request and read current block of cipher text from ICU */
                retVal = Icus_ReadData(&cipherTextPtr[offset]); 
            }
        }
    }

    if(retVal == ERR_OK)
    {
        /* Wait until ICUS has finished */
        retVal = Icus_WaitBusyFlag();
    }

    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if(retVal == ERR_OK)
    {
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            retVal = ERR_OK;
        }
        else
        {
            retVal = ERR_FAULT;
        }
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_DecryptCBC
*  Description : Decrypt message via CBC.
*  Parameter   : key_id is the key used to Decrypt
                        cipherTextPtr is the point to the message which need decrypt
                        cipherTextLength is the decrypt message length
                        plainTextPtr is the point to the data after decrypt finished
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_AesDecrypt128CBC(U32 key_id, const U8 *cipherTextPtr, U32 cipherTextLength, U8*plainTextPtr, const U8 *IV)
{  
    ERR_TYPE retVal = ERR_IDLE;
    U32  n_blocks = 0u;
    U32 current_block = 0u;
    U32 offset = 0u;

    /* Calculate number of needed blocks for the decryption. */
    n_blocks = cipherTextLength / ICUS_AESDECRYPT128_BLOCKSIZE;

    /* Set number of blocks to be transfered */
    ICU_IDATNUM = n_blocks + ICUS_AESDECRYPT128_IVBLOCK;

    /* Set key id and command for AES decryption in ECB mode */
    Icus_SendCommand(CMD_DEC_CBC,key_id);

    /* Send IV from workspace to ICUS in case AES is in CBC mode */
    retVal = Icus_WriteData(IV);

    if(retVal == ERR_OK)
    {
        // processes n blocks of 128 bits
        for (current_block = 0u; current_block < n_blocks; current_block++)
        {
            /* Get the offset for the block */
            offset = current_block * ICUS_AESDECRYPT128_BLOCKSIZE;

            /* Wait for input request and send current block of plain text to ICU */
            retVal = Icus_WriteData(&cipherTextPtr[offset]);

            if(retVal == ERR_OK)
            {
                /* Wait for output request and read current block of cipher text from ICU */
                retVal = Icus_ReadData(&plainTextPtr[offset]); 
            }
        }
    }

    if(retVal == ERR_OK)
    {
        /* Wait until ICUS has finished */
        retVal = Icus_WaitBusyFlag();
    }

    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if(retVal == ERR_OK)
    {
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            retVal = ERR_OK;
        }
        else
        {
            retVal = ERR_FAULT;
        }
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_RngGenerate
*  Description : Generate Rng.
*  Parameter   : resultPtr is the point to save the generate rng data
                        resultLength is generate rngdata length
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_RngGenerate(U8 *resultPtr,U32 resultLength)
{
    ERR_TYPE retVal = ERR_IDLE;
    U8 randomNumberBuffer[ICUS_RNG_RND_SIZE];
    U8 i;
    
    /* Check if the RNG is initialized. */
    if (((ICU_STS & ICUS_STS_RND_INIT) == ICUS_STS_RND_INIT)) 
    {
        /* Send the command for generating the RND. */
        ICU_CMD = CMD_RND;  

        /* Read the generated data from ICU and write it to the pointer. */
        retVal = Icus_ReadData(randomNumberBuffer); 

        if(retVal == ERR_OK)
        {
            /* Wait until ICU has finished */
            retVal = Icus_WaitBusyFlag();
        }

        if(retVal == ERR_OK)
        {
            /* Write back data. */
            for (i = 0u; i < resultLength; i++)
            {
                resultPtr[i] = randomNumberBuffer[i]; 
            }
        }

        Icus_CancelCommand();
        CLEAR_RDRDY;
        CLEAR_WRRDY;
    }
    else
    {
        retVal = ERR_FAULT;
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_SecureBoot_DMA
*  Description : Secure Boot using DMA with interrupt handling.
                       Caution that if data length is 0x20000(bytes), that this funciton need 10ms~11ms to execute.
                       The execute time will increase with the increase of data length.
*  Parameter   : dataPtr is the point to boot
                        dataLength is boot length
*  Returns     :   ERR_OK -operation ok.
			   ERR_FAULT - error occured.
			   ERR_INVALID_PARAMETER key is invalid.
***********************************************************************/
ERR_TYPE Icus_SecureBoot_DMA(const U8 *dataPtr, U32 dataLength, U8 *resultPtr)
{
    ERR_TYPE retVal = ERR_IDLE;
    U8 verifyResult = ICUS_E_VER_NOT_OK;
    // configures the DMA for writing to and reading from the ICU-S
    Icus_DMA_Init(DMA_SECUREBOOT);
    Icus_DMA_ConfigBlock_RD(DMA_SECUREBOOT,(U32)dataPtr, dataLength/4);
    
    // set function parameters to global variables
    nblocks = dataLength/4;
    source_address = (U32 *)dataPtr;

    // starts DMA operation
    Icus_DMA_Start_RD(DMA_SECUREBOOT);

    // initializes CMD_SECURE_BOOT
    ICU_IDAT = Icus_SwapWord(dataLength);
    ICU_IDAT = 0;
    ICU_IDAT = 0;
    ICU_IDAT = 0;
    ICU_CMD = CMD_SECURE_BOOT;

    retVal = Icus_WaitBusyFlag();
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if(retVal == ERR_OK)
    {
        if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
        {
            if (((ICU_STS & ICUS_STS_SECURE_BOOT) == 1u)
             &&((ICU_STS & ICUS_STS_BOOT_OK) == 1u))
            {
                verifyResult = ICUS_E_VER_OK;
            }
            else
            {
                verifyResult = ICUS_E_VER_NOT_OK;
            }
            retVal = ERR_OK;
        }
        else
        {
            verifyResult = ICUS_E_VER_NOT_OK;
            retVal = ERR_FAULT;
        }
    }
    
    nblocks = 0;
    Icus_DMA_Stop(DMA_SECUREBOOT);
    *resultPtr = verifyResult;
    return(retVal);
}

ERR_TYPE Icus_SecureBoot(const U8 *pData, U32 dataLength)
{
	ERR_TYPE err = ERR_IDLE;
	U32 cnt;
	U8  i;
	const U8  *ptr =pData;

	cnt= dataLength/16;
	if(cnt>0)	
		return ERR_INVALID_PARAMETER;	
	ICU_IDAT = Icus_SwapWord(dataLength);
    ICU_IDAT = 0;
    ICU_IDAT = 0;
    ICU_IDAT = 0;
    ICU_CMD  = CMD_SECURE_BOOT;

	err = Icus_WaitBusyFlag();
	if(err != ERR_OK)
	{
		return err;
	}
    CLEAR_RDRDY;
    CLEAR_WRRDY;
	for(i=0;i<cnt;i++)
	{        
		ptr = pData +i*16;
		err = Icus_WriteData(ptr);
		if(err != ERR_OK)
		{
			return err;
		}
	}
	//if secure boot is ok	

	Icus_CancelCommand();
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
    {
        err = ERR_OK;
    }
    else
    {
        err = ERR_FAULT;
    }
	return err;
}


#if 0
ERR_TYPE Icus_CmdGetID(void)
{
	U32 cnt,timeout;
	U32 RngData[4]={0};
	ERR_TYPE err= ERR_IDLE;
	U8 i;
	U32 IdBuf[4]={0};
	U32 MacBuf[4]={0};

	err = Icus_RngGenerate(RngData, 16);
	if(err != ERR_OK)
	{
		return err;
	}	
	ICU_CMD = CMD_GET_ID;
	err = Icus_Wait4_WRRDY();
	if(err != ERR_OK)
	{
		return err;
	}
	else
	{		
		for(i=4;i>0;i--)				
			ICU_IDAT = Icus_SwapWord(RngData[i-1]);
        err = Icus_Wait4_RDRDY();
        if(err != ERR_OK)
		{
			return ERR_FAULT;
		}
		else
		{
			for(i=0;i<4;i++)
				IdBuf[i] = ICU_ODAT;  //UID SREG				
		}
		err = Icus_Wait4_RDRDY();
        if(err != ERR_OK)
		{
			return ERR_FAULT;
		}
		else
		{
			for(i=0;i<4;i++)
				MacBuf[i] = ICU_ODAT;  //MAC				
		}
	}
	return ERR_OK;
}
#endif

ERR_TYPE Icus_CmdGetID(U8 *pId,U8 *pMac)
{
	ERR_TYPE err= ERR_IDLE;
	U8  challenge[16]={0};
	//U8  i;

	err = Icus_RngGenerate(challenge, 16);
	if(err != ERR_OK)
	{
		return err;
	}	
	ICU_CMD = CMD_GET_ID;
	err = Icus_WriteData(challenge);
	if(err != ERR_OK)
	{
		return err;
	}
	err = Icus_ReadData(pId);
	if(err != ERR_OK)
	{
		return err;
	}
	err = Icus_ReadData(pMac);
	if(err != ERR_OK)
	{
		return err;
	}

	Icus_CancelCommand();
    CLEAR_RDRDY;
    CLEAR_WRRDY;
    /* Check if errors occured*/
    if((ICU_ERR & ICUS_ERR_ERR_MASK) == ICUS_ERC_NO_ERROR) 
    {
        err = ERR_OK;
    }
    else
    {
        err = ERR_FAULT;
    }
	return err;
}


ERR_TYPE Icus_CmdDebug(void)
{


	return 0;
}


/***********************************************************************
*  Name        : INTDMA0
*  Description : Secure Boot DMA interrupt handler.
*  Parameter   : void
*  Returns     :   void
***********************************************************************/
__interrupt void INTDMA0(void)
{   
    if(ICU_ERR == 0)
    {
        // managing CMAC generation
        if(nblocks >= DMA_MAXCTR)
        {
            // not all blocks have been transfered to the ICU-S yet
            // reconfigures the DMA for writing to the ICU-S
            nblocks -= DMA_MAXCTR;
            source_address += DMA_MAXCTR;
            Icus_DMA_ConfigBlock_RD(DMA_SECUREBOOT,(U32)source_address, nblocks);
            // restarts the DMA w/o clearing the pending request
            Icus_DMA_Restart_RD(DMA_SECUREBOOT);
        }
        else
        {
            // all blocks have been transfered to the ICU-S
            // do nothing; next processing step in HANDLER_INTDMA_WR
        }
    }
    else
    {
        nblocks = 0;
        Icus_DMA_Stop(DMA_SECUREBOOT);
    }
}

/***********************************************************************
*  Name        : Icus_SwappedByteToWord
*  Description : Swap bytes to word.eg.{0x11,0x22,0x33,0x44} -> 0x4332211
*  Parameter   : source is the pointer to source data
*  Returns     :   The converted word data.
***********************************************************************/
static U32 Icus_SwappedByteToWord(const U8* source)
{
   return ((U32)source[0]       & 0x000000ffu
        | (((U32)source[1]) << 8 & 0x0000ff00u) 
        | (((U32)source[2]) << 16& 0x00ff0000u) 
        | (((U32)source[3]) << 24& 0xff000000u));
        
}

/***********************************************************************
*  Name        : Icus_SwappedWordToByte
*  Description : Swap word to bytes.eg.0x4332211 ->  {0x11,0x22,0x33,0x44}
*  Parameter   : source is the pointer to source data
                        destination is the point to destination data
*  Returns     :   null
***********************************************************************/
static void Icus_SwappedWordToByte(U32 source, U8 * destination)
{
    /* Copy word to byte array and swap the bytes. */
    destination[3] = (U8)((source >> 24) & 0xFFu);
    destination[2] = (U8)((source >> 16) & 0xFFu);
    destination[1] = (U8)((source >>  8) & 0xFFu);
    destination[0] = (U8)(source         & 0xFFu); 
}

/***********************************************************************
*  Name        : Icus_SwapWord
*  Description : Swap word sequence eg. 0x11223344 -> 0x44332211.
*  Parameter   : Source is the pointer to source data.
*  Returns     :   The data after swap.
***********************************************************************/
static U32 Icus_SwapWord(U32 source)
{
    /* Swap word bytewise and return it. */
    return ( ( (source >> 24) & 0x000000ffu )
         | ( (source >>  8) & 0x0000ff00u )
         | ( (source <<  8) & 0x00ff0000u )
         | ( (source << 24) & 0xff000000u ) );
}

/***********************************************************************
*  Name        : Icus_WriteData
*  Description : Write data to ICUS indata register.
*  Parameter   : data is the pointer to source data
*  Returns     :   null
***********************************************************************/
static ERR_TYPE Icus_WriteData(const U8 *data)
{
    ERR_TYPE retVal = ERR_IDLE;
    retVal = Icus_Wait4_WRRDY();
    if(retVal == ERR_OK)
    {
        CLEAR_WRRDY;
        /*The Input Data Register consists of FIFO of 32bits *4(128bits)*/
        ICU_IDAT = Icus_SwappedByteToWord(&data[ICUS_FIFO_DEPTH_0]); 
        ICU_IDAT = Icus_SwappedByteToWord(&data[ICUS_FIFO_DEPTH_1]);  
        ICU_IDAT = Icus_SwappedByteToWord(&data[ICUS_FIFO_DEPTH_2]); 
        ICU_IDAT = Icus_SwappedByteToWord(&data[ICUS_FIFO_DEPTH_3]); 
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_ReadData
*  Description : Read data from ICUS outdata register.
*  Parameter   : data is the pointer to destination data
*  Returns     :   null
***********************************************************************/
static ERR_TYPE Icus_ReadData(U8 *data)
{
    ERR_TYPE retVal = ERR_IDLE;
    retVal = Icus_Wait4_RDRDY();
    if(retVal == ERR_OK)
    {
        CLEAR_RDRDY;
        /*The Output Data Register consists of FIFO of 32bits *4(128bits)*/
        Icus_SwappedWordToByte(ICU_ODAT,&data[ICUS_FIFO_DEPTH_0]);
        Icus_SwappedWordToByte(ICU_ODAT,&data[ICUS_FIFO_DEPTH_1]);
        Icus_SwappedWordToByte(ICU_ODAT,&data[ICUS_FIFO_DEPTH_2]);
        Icus_SwappedWordToByte(ICU_ODAT,&data[ICUS_FIFO_DEPTH_3]);
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_WriteMacVerificationData
*  Description : Write CMAC data to  ICUS indata register.
*  Parameter   : n_blocks is the block size for ICUS input data
                        dataLength is the input data length.
                        dataPtr is the pointer to input data.
*  Returns     :   null
***********************************************************************/
static ERR_TYPE Icus_WriteMacVerificationData(U32 n_blocks, U32 dataLength, const U8 *dataPtr)
{
    ERR_TYPE retVal = ERR_IDLE;
    U8 writeBuffer[ICUS_CMACAES128VER_BLOCKSIZE];
    U32 block;
    U32 offset;
    U8 i; 

    for (block = 0u; block < n_blocks; block++)
    {
        /* Get the offset for the block */
        offset = block * ICUS_CMACAES128VER_BLOCKSIZE;

        /* Copy source to buffer */
        for (i = 0u; i < ICUS_CMACAES128VER_BLOCKSIZE; i++)
        {
            /* Check if there is enough data available */
            if ((offset + i) < dataLength)
            {
                writeBuffer[i] = dataPtr[offset + i]; 
            }
            else
            {
                /* Padding with 0 */
                writeBuffer[i] = 0u; 
            }
        }

        /* Wait for input request and send current block of the message to ICUSB */
        retVal = Icus_WriteData(writeBuffer); 
        if(retVal !=ERR_OK)
        {
            break;
        }
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_WriteMacData
*  Description : Read CMAC data from ICUS outdata register.
*  Parameter   : dataLength is the input data length.
                        dataPtr is the pointer to input data.
*  Returns     :   null
***********************************************************************/
static ERR_TYPE Icus_WriteMacData(U32 dataLength, const U8 *dataPtr)
{
    ERR_TYPE retVal = ERR_IDLE;
    U8 writeBuffer[ICUS_CMACAES128VER_BLOCKSIZE];
    U32 i;
    /* Initialize the buffer with zero */
    for (i = 0; i < ICUS_CMACAES128VER_BLOCKSIZE; i++)
    {
        writeBuffer[i] = 0u; 
    }

    /* Store MAC in write buffer */
    for (i = 0u; i < dataLength; i++)
    {
        writeBuffer[i] = dataPtr[i]; 
    }

    /* write MAC to ICUS */
    retVal = Icus_WriteData(writeBuffer);   
    return retVal;
}

/***********************************************************************
*  Name        : Icus_WaitBusyFlag
*  Description : Check ICUS busy state.
*  Parameter   : void
*  Returns     :   null
***********************************************************************/
static ERR_TYPE Icus_WaitBusyFlag(void)
{
    ERR_TYPE retVal = ERR_IDLE;
    U32 Icus_Wait_Counter;
    if(ICU_CMD == CMD_SECURE_BOOT)
    {
        Icus_Wait_Counter = WAIT4_BUSY_TIMER_DMA;
    }
    else if(ICU_CMD == CMD_INIT_RNG)
    {
        Icus_Wait_Counter = WAIT4_BUSY_TIMER_LONG;
    }
    else
    {
        Icus_Wait_Counter = WAIT4_BUSY_TIMER_SHORT;
    }
    while( ( (ICU_STS & ICUS_STS_BUSY) == ICUS_STS_BUSY )
        && ( (ICU_ERR & ICUS_ERR_ERR_MASK) != ICUS_ERC_MEMORY_FAILURE) 
        && ( (ICU_ERR & ICUS_ERR_ERR_MASK) != ICUS_ERC_BUSY)
        && (Icus_Wait_Counter >0))
    {
        /*Wait until busy flag is cleared (polling)or timeout*/
        Icus_Wait_Counter--;
    }
    if(((ICU_STS & ICUS_STS_BUSY) != ICUS_STS_BUSY)&&(ICU_ERR == 0)&&(Icus_Wait_Counter>0u))
    {
        CLEAR_RDRDY;
        retVal = ERR_OK;
    }
    else
    {
        retVal = ERR_FAULT;
    }
    return retVal;
}

/***********************************************************************
*  Name        : Icus_SendCommand
*  Description : Send ICUS command.
*  Parameter   : cmd is the command type.
                        keyId is the key for current command.
*  Returns     :   null
***********************************************************************/
static void Icus_SendCommand(U32 cmd, U32 keyId)
{
    U32 tmpKeyId = 0u;
    U32 flagKeyMd = 0u;
    tmpKeyId = keyId;
    if (keyId > ICUS_END_OF_FIRST_KEYPAGE)
    {
        flagKeyMd = 1u;
        tmpKeyId = keyId - ICUS_RAW_OFFSET_SECOND_KEYPAGE;
    }
//    if (cmd == CMD_LOAD_KEY)
    {
//        tmpKeyId = 0u;
    }
    ICU_CMD = ( ICUS_CMD_CMD_MASK   & ( (cmd)       << ICUS_CMD_CMD_OFFSET ) ) /* SBSW_CRY_REGISTER_ACCESS */
              | ( ICUS_CMD_KEYID_MASK & ( (tmpKeyId)  << ICUS_CMD_KEYID_OFFSET ) )
              | ( ICUS_CMD_KEYMD_MASK & ( (flagKeyMd) << ICUS_CMD_KEYMD_OFFSET ) );
}

/***********************************************************************
*  Name        : Icus_CancelCommand
*  Description : Cancel ICUS command.
*  Parameter   : null.
*  Returns     :   null
***********************************************************************/
static void Icus_CancelCommand(void)
{
    if ( (ICU_STAT & ICUS_STAT_ICUEN) == ICUS_ICU_ENABLED )
    {
        if ( (ICU_STS & ICUS_STS_BUSY) == ICUS_STS_BUSY ) 
        {
            ICU_CMD = CMD_CANCEL;
            (void)Icus_WaitBusyFlag();
        }
    }
}

ERR_TYPE Icus_Wait4_WRRDY(void)
{
    ERR_TYPE retVal = ERR_IDLE;
    U32 Icus_Wait_Counter = WAIT4_WRRDY_TIMER;
    while(((ICU_SWINT & ICUSTXREQ) == 0) && (ICU_ERR == 0) && (Icus_Wait_Counter>0u))   //ICU_STS: busy?
    {
        Icus_Wait_Counter--;
    }
    if(((ICU_SWINT & ICUSTXREQ) == ICUSTXREQ)&&(ICU_ERR == 0)&&(Icus_Wait_Counter>0u))
    {
        retVal = ERR_OK;
    }
    else
    {
        retVal = ERR_FAULT;
    }
    return retVal;    
}

ERR_TYPE Icus_Wait4_RDRDY(void)
{
    ERR_TYPE retVal = ERR_IDLE;
    U32 Icus_Wait_Counter = WAIT4_RDRDY_TIMER;
    while(((ICU_SWINT & ICUSRXREQ) == 0) && (ICU_ERR == 0) && (Icus_Wait_Counter>0u))
    {
        Icus_Wait_Counter--; 
    }
    if(((ICU_SWINT & ICUSRXREQ) == ICUSRXREQ)&&(ICU_ERR == 0)&&(Icus_Wait_Counter>0u))
    {
        retVal = ERR_OK;
    }
    else
    {
        retVal = ERR_FAULT;
    }
    return retVal;
}







