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

#ifndef _ICUS_IF_H_
#define _ICUS_IF_H_

/*============================================================================
 Includes
============================================================================*/
#include "Icus_define.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
/*The Timeout value for ICUS polling*/
#define WAIT4_WRRDY_TIMER   (0x200u)/*timeout value for write flag polling*/
#define WAIT4_RDRDY_TIMER   (0x200u)/*timeout value for read flag polling*/
#define WAIT4_BUSY_TIMER_SHORT   (0x200u)/*timeout value for busy flag short polling*/
#define WAIT4_BUSY_TIMER_LONG   (0x10000u)/*timeout value for busy flag long polling*/
#define WAIT4_BUSY_TIMER_DMA   (0x10000u)  //(0x10000u)/*timeout value for busy flag DMA polling*/

/*===========================================================================
  ICU-S key indexes
  ===========================================================================*/

#define SECRET_KEY	    	    (0x00u) 
#define MASTER_ECU_KEY	    	(0x01u)
#define BOOT_MAC_KEY	    	(0x02u)
#define BOOT_MAC	            (0x03u)
#define KEY_1	            	(0x04u)
#define KEY_2	            	(0x05u)
#define KEY_3	            	(0x06u)
#define KEY_4	            	(0x07u)
#define KEY_5	            	(0x08u)
#define KEY_6	            	(0x09u)
#define KEY_7	            	(0x0Au)
#define KEY_8	            	(0x0Bu)
#define KEY_9	            	(0x0Cu)
#define KEY_10	            	(0x0Du)
#define RAM_KEY	            	(0x0Eu)
#define KEY_11	            	(0x14u)
#define KEY_12	            	(0x15u)
#define KEY_13	            	(0x16u)
#define KEY_14	            	(0x17u)
#define KEY_15	            	(0x18u)
#define KEY_16	            	(0x19u)
#define KEY_17	            	(0x1Au)
#define KEY_18	            	(0x1Bu)
#define KEY_19	            	(0x1Cu)
#define KEY_20	            	(0x1Du)


extern void icus_main(void);
extern void Icus_Init(void);
extern ERR_TYPE Icus_Loadkey(U32 key_id, const U8 *dataPtr, U8 *resultPtr);
extern ERR_TYPE Icus_CmacAes128Gen(U32 key_id, const U8 *dataPtr, U32 dataLength, U8* MacPtr,U32 MacLength);
extern ERR_TYPE Icus_CmacAes128Ver(U32 key_id, const U8* dataPtr, U32 dataLength, const U8 *MacPtr, U32 MacLength, U8 *resultPtr);
extern ERR_TYPE Icus_AesEncrypt128ECB(U32 key_id, const U8 *plainTextPtr, U32 plainTextLength, U8*cipherTextPtr);
extern ERR_TYPE Icus_AesDecrypt128ECB(U32 key_id, const U8 *cipherTextPtr, U32 cipherTextLength, U8*plainTextPtr);
extern ERR_TYPE Icus_AesEncrypt128CBC(U32 key_id, const U8 *plainTextPtr, U32 plainTextLength, U8*cipherTextPtr,const U8 *IV);
extern ERR_TYPE Icus_AesDecrypt128CBC(U32 key_id, const U8 *cipherTextPtr, U32 cipherTextLength, U8*plainTextPtr, const U8 *IV);
extern void Icus_RngInit(void);
extern ERR_TYPE Icus_RngGenerate(U8 *resultPtr,U32 resultLength);
extern ERR_TYPE Icus_SecureBoot_DMA(const U8 *dataPtr, U32 dataLength, U8 *resultPtr);
extern ERR_TYPE Icus_CmdGetID(U8 *pId,U8 *pMac);

#endif  /* End of module include.  */



