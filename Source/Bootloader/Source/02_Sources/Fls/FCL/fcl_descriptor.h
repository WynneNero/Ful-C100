#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_OFF 0292
#endif
/************************************************************************************************************
* File Name     : $Source: fcl_descriptor.h $
* Mod. Revision : $Revision: 1.3 $
* Mod. Date     : $Date: 2016/05/31 14:04:59JST $
* Device(s)     : RV40 Flash based RH850 microcontroller
* Description   : Target specific defines
************************************************************************************************************/

/************************************************************************************************************
* DISCLAIMER 
* This software is supplied by Renesas Electronics Corporation and is only  intended for use with
* Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
* Corporation and is protected under all applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, 
* WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. 
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
* ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
* CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the 
* availability of this software. By using this software, you agree to the additional terms and conditions
* found by accessing the  following link: 
* http://www.renesas.com/disclaimer 
* 
* Copyright (C) 2015-2016 Renesas Electronics Corporation. All rights reserved.     
************************************************************************************************************/

#ifdef ENABLE_QAC_TEST
    #pragma PRQA_MESSAGES_ON 0292
#endif

/************************************************************************************************************
* MISRA Rule:   MISRA-C 2004 rule 3.1 (QAC message 0292)
* Reason:       To support automatic insertion of revision, module name etc. by the source 
*               revision control system it is necessary to violate the rule, because the 
*               system uses non basic characters as placeholders.
* Verification: The placeholders are used in commentary only. Therefore rule violation cannot 
*               influence code compilation.
************************************************************************************************************/

#ifndef FCL_DESCRIPTOR_H
#define FCL_DESCRIPTOR_H

/************************************************************************************************************
Macro definitions
************************************************************************************************************/
#define FCL_CPU_FREQUENCY_MHZ  (120)                          /*!< CPU frequency in MHz */
#define FCL_AUTHENTICATION_ID {0xFFFFFFFF, \
                               0xFFFFFFFF, \
                               0xFFFFFFFF, \
                               0xFFFFFFFF}                    /*!< 128Bit authentication ID */
#define FCL_RAM_ADDRESS         0xFEDD0000//0xFEDFC000//0xFEDF8000                     /*!< RAM address range blocked for FCL */

/************************************************************************************************************
Typedef definitions
************************************************************************************************************/


/************************************************************************************************************
Exported global variables
************************************************************************************************************/
extern r_fcl_descriptor_t sampleApp_fclConfig_enu; /*!< FCL descriptor variable */


/************************************************************************************************************
Exported global functions (to be accessed by other files) 
************************************************************************************************************/



#endif /* end of FCL_DESCRIPTOR_H */