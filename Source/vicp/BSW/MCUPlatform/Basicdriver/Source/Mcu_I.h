/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD      									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        : Mcu.h
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1    Jan 20,2016  Init Version
* ----------------------------------------------------------------------
* 0.2    Dec 20,2016  ShangQIuju remove other module used interface here.
* ----------------------------------------------------------------------
* 0.3    Dec 29,2016  PEI Jingli  Change for codeReview result  
*------------------------------------------------------------------------
* 0.4    Jan 11,2017  ZhangJie   And add u for constant value to avoid Coverity warning.
 ----------------------------------------------------------------------
* 0.5    Jan 16,2017   RenWeimin  Add test code.
*-----------------------------------------------------------------------
* 0.6    Jan 24,2017    ZhangJie     Remove unused include headfile.
*-----------------------------------------------------------------------
* 0.7    Feb 09,2017   ZhangJie   Using micro to call app function.
*=====================================================================*/
#ifndef _MCU_I_H_
#define _MCU_I_H_
#include "cpu.h"
#include "Define.h"

#if MCU_PIN==PIN100
#include "mcu_pin_cc.h"
#elif MCU_PIN==PIN64
#include "mcu_64pin_cc.h"
#endif
/**** Definition of constants ****/
/*SWRESA:software reset register*/
#define MCU_REG_RESET                        (*(CPU_REG32 *)0xFFF80A04u)
/*RESF:reset factor register*/
#define MCU_REG_RESET_REASON         (*(CPU_REG32 *)0xFFF80760u)
/*RESFC:Reset factor clear reg*/
#define MCU_REG_RESETFLAG_CLEAR    (*(CPU_REG32 *)0xFFF80768u)

/* Configrations of PE Guard Area */
#define  PEG_BASE_ADDRESS                       ( (CPU_INT32U )0xFFFEE600u) 
#define  PEG_REG_PEGSP                              (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x000C))
#define  PEG_REG_PEGG0MK                          (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0080))
#define  PEG_REG_PEGG0BA                          (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0084))
#define  PEG_REG_PEGGnMK(n)                     (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0080+0x10*(n)))
#define  PEG_REG_PEGGnBA(n)                     (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0084+0x10*(n)))

/* PE Guard Area 0~3 */
#define SPID0_ENABLE   0x00000010
#define SPID0_DISABLE 0x00000000
#define SPID1_ENABLE   0x00000020
#define SPID1_DISABLE 0x00000000
#define SPID2_ENABLE   0x00000040
#define SPID2_DISABLE 0x00000000
#define SPID3_ENABLE  0x00000080
#define SPID3_DISABLE 0x00000000

#define PEG_WR_ENABLE  0x00000004
#define PEG_WR_DISABLE 0x00000000
#define PEG_RD_ENABLE   0x00000002
#define PEG_RD_DISABLE 0x00000000

typedef struct{
  BOOL AreaEnable;
  U32   Config;   /* PEG_REG_PEGGnBA */
}PEG_CONFIG_ST;

#endif /* _MCU_I_H_ */
/****************************** END OF FILE ***************************/

