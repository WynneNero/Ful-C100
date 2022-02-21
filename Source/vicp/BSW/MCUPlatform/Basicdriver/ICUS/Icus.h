/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				*
*				  All Rights Reserved.          			*
*   Department : ITC R&D NKG      						*
*   AUTHOR	   : 					*
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :  Head file
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

#ifndef _ICUS_H_
#define _ICUS_H_

/*============================================================================
 Includes
============================================================================*/
#include "Icus_define.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define ICUS_KEYEXTRACT_KEY_INFORMATION_OFFSET                       (15u)
#define ICUS_KEYEXTRACT_AUTHID_MASK                                  (0x0F)
#define ICUS_KEYEXTRACT_KEYID_MASK                                   (0xF0)

#define ICUS_KEYEXTRACT_LENGTH_M1                                    (16u)
#define ICUS_KEYEXTRACT_LENGTH_M2                                    (32u)
#define ICUS_KEYEXTRACT_LENGTH_M3                                    (16u)
#define ICUS_KEYEXTRACT_LENGTH_M4                                    (32u)
#define ICUS_KEYEXTRACT_LENGTH_M5                                    (16u)
#define ICUS_KEYEXTRACT_LENGTH_M4M5                               (ICUS_KEYEXTRACT_LENGTH_M4 + ICUS_KEYEXTRACT_LENGTH_M5)

#define ICUS_KEYEXTRACT_OFFSET_M1                                    (0u)
#define ICUS_KEYEXTRACT_OFFSET_M2                                    (ICUS_KEYEXTRACT_LENGTH_M1)
#define ICUS_KEYEXTRACT_OFFSET_M3                                    (ICUS_KEYEXTRACT_OFFSET_M2 + ICUS_KEYEXTRACT_LENGTH_M2)
#define ICUS_KEYEXTRACT_OFFSET_M4                                    (0u)
#define ICUS_KEYEXTRACT_OFFSET_M5                                    (ICUS_KEYEXTRACT_LENGTH_M4)

#define ICUS_KEYEXTRACT_OFFSET_M2_SEC                       (16u)
#define ICUS_KEYEXTRACT_OFFSET_M4_SEC                       (16u)

#define ICUS_AESENCRYPT128_IVBLOCK                                   (1u)
#define ICUS_AESENCRYPT128_BLOCKSIZE                                 (16u)
#define ICUS_AESDECRYPT128_IVBLOCK                                   (1u)
#define ICUS_AESDECRYPT128_BLOCKSIZE                                 (16u)

#define ICUS_CMACAES128GEN_BLOCKSIZE                                 (16u)
#define ICUS_CMACAES128GEN_BITS_PER_BYTE                             (8u)
#define ICUS_CMACAES128VER_MAX_MAC_LENGTH_IN_BITS                    (128u)
#define ICUS_CMACAES128VER_BLOCKSIZE                                 (16u)
#define ICUS_CMACAES128VER_BITS_PER_BYTE                             (8u)
#define ICUS_CMACAES128VER_VERIFICATION_STATUS_OFFSET                (0u)
#define ICUS_CMACAES128VER_VERIFICATION_STATUS_MASK                  (0x01u)

/* Random Number Generator specific service defines */
#define ICUS_RNG_RND_SIZE                    (16u)

#define ICUS_END_OF_FIRST_KEYPAGE              (RAM_KEY)
#define ICUS_RAW_OFFSET_SECOND_KEYPAGE         (0x10u)

#define ICUS_E_VER_OK (0U)
#define ICUS_E_VER_NOT_OK (1U)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/ 
#define ICU_BASE_ADDRESS                       ( (CPU_INT32U )0xFFF60000u)    /*!< Base Address (Configurable) */

#define ICUSTXREQ            (0x00000001u) 
#define ICUSRXREQ            (0x00000002u)
#define FLAG_WRRDY          ((ICU_SWINT & ICUSTXREQ) >> (ICUSTXREQ-1))
#define FLAG_RDRDY          ((ICU_SWINT & ICUSRXREQ) >> (ICUSRXREQ-1))
#define CLEAR_WRRDY         {ICU_SWINTCL = ICUSTXREQ;} while(0);
#define CLEAR_RDRDY         {ICU_SWINTCL = ICUSRXREQ;} while(0);
#define WAIT4_WRRDY         {while((ICU_SWINT & ICUSTXREQ) == 0); } while(0);
#define WAIT4_RDRDY         {while((ICU_SWINT & ICUSRXREQ) == 0); } while(0);
#define WAIT4_WRRDY_OR_ERR  {while(((ICU_SWINT & ICUSTXREQ) == 0) && (ICU_ERR == 0)); } while(0);
#define WAIT4_RDRDY_OR_ERR  {while(((ICU_SWINT & ICUSRXREQ) == 0) && (ICU_ERR == 0)); } while(0);


#define ICU_CMD             (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x00u))  /*ICUS Command Register */     
#define ICU_IDAT            (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x04u))    
#define ICU_ODAT           (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x08u))  
#define ICU_STS              (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x0Cu))     
#define ICU_ERR              (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x10u))      
#define ICU_SWINT         (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x14u))  
#define ICU_STAT            (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x18u))    
#define ICU_IDATNUM     (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x1Cu)) 
#define ICU_ACC              (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x20u)) 
#define ICU_SWINTCL      (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x24u)) 
#define ICU_RST              (*(CPU_REG32 *) (ICU_BASE_ADDRESS + 0x2Cu))    

/*ICUS0ICRCMD*/
#define ICUS_CMD_CMD_MASK                   (0x0000FFFFu)                                                /*Command */
#define ICUS_CMD_CMD_OFFSET                 (0u)
#define ICUS_CMD_CMD_LENGTH                 (16u)
#define ICUS_CMD_KEYID_MASK                 (0x000F0000u)   
#define ICUS_CMD_KEYID_OFFSET               ICUS_CMD_CMD_LENGTH
#define ICUS_CMD_KEYID_LENGTH               (4u)
#define ICUS_CMD_KEYMD_MASK                 (0x00100000u)                                                /*Selection of keyPage */
#define ICUS_CMD_KEYMD_OFFSET               (ICUS_CMD_CMD_LENGTH + ICUS_CMD_KEYID_LENGTH)
#define ICUS_CMD_KEYMD_LENGTH               (1u)

/*ICUS0ICRERR*/
#define ICUS_ERR_ERR_MASK                   (0x00000FFFu) /*ICUS Error Code */

/*ICUS0ICRSTS*/
#define ICUS_STS_BUSY                       (0x00000001u)                                                /*ICUS is busy */
#define ICUS_STS_SECURE_BOOT                (0x00000002u)                                                /*Secure boot is executing */
#define ICUS_STS_BOOT_INIT                  (0x00000004u)                                                /*Secure boot has been initialized */
#define ICUS_STS_BOOT_FINISHED              (0x00000008u)                                                /*Secure Boot has finished */
#define ICUS_STS_BOOT_OK                    (0x00000010u)                                                /*Sate of the Secure Boot */
#define ICUS_STS_RND_INIT                   (0x00000020u)                                                /*Random number generator initialized */
#define ICUS_STS_EXT_DEBUGGER               (0x00000040u)                                                /*External debugger connected */
#define ICUS_STS_INT_DEBUGGER               (0x00000080u)                                                /*Internal debug mode */

/*ICUS0ICRICUSTS*/
#define ICUS_STAT_ICUEN                   (0x00000001u)                                                /*ICUS enabled status */

/* SHE constants */
#define ICUS_ICU_ENABLED                    (0x00) /* ICUS is enabled */
#define ICUS_ICU_DISABLED                   (0x01) /*ICUS is disabled */

/* SHE Error codes */
#define ICUS_ERC_NO_ERROR                   (0x000) /* ERC_NO_ERROR */
#define ICUS_ERC_BUSY                       (0x200) /*ERC_BUSY  */
#define ICUS_ERC_MEMORY_FAILURE             (0x400) /*ERC_MEMORY_FAILURE*/
#define ICUS_ERC_GENERAL_ERROR              (0x800) /*ERC_GENERAL_ERROR*/

/*===========================================================================
  ICU-S commands
  ===========================================================================*/

#define CMD_GET_STATUS	        (0x00u)
#define CMD_ENC_ECB	        (0x01u)
#define CMD_ENC_CBC	        (0x02u)
#define CMD_DEC_ECB	        (0x03u)
#define CMD_DEC_CBC	        (0x04u)
#define CMD_GENERATE_MAC	(0x05u)
#define CMD_VERIFY_MAC	    	(0x07u)
#define CMD_LOAD_KEY	    	(0x08u)
#define CMD_LOAD_PLAIN_KEY	(0x09u)
#define CMD_EXPORT_RAM_KEY	(0x0Au)
#define CMD_INIT_RNG	    	(0x0Bu)
#define CMD_EXTEND_SEED	    	(0x0Cu)
#define CMD_RND	            	(0x0Du)
#define CMD_SECURE_BOOT	    	(0x0Eu)
#define CMD_BOOT_FAILURE	(0x20u)
#define CMD_BOOT_OK	        (0x21u)
#define CMD_GET_ID	        (0x22u)
#define CMD_DEBUG	        (0x23u)
#define CMD_CANCEL	        (0x3Fu)

#define ICUS_FIFO_DEPTH_0 (0x0u)
#define ICUS_FIFO_DEPTH_1 (0x4u)
#define ICUS_FIFO_DEPTH_2 (0x8u)
#define ICUS_FIFO_DEPTH_3 (0xCu)

#endif  /* End of module include.  */