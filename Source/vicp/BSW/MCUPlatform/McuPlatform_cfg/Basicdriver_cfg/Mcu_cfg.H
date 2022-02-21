/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department :  CT AD NKG 
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
***********************************************************************/
/*-History--------------------------------------------------------------
* Ver    Date           Name        Changes and comment
* ----------------------------------------------------------------------
* 0.1    Jul 21,2016    PEI Jingli  Initial version
* ----------------------------------------------------------------------
* 0.2    Aug 10,2016    PEI Jingli  Add MOSC defination
* ----------------------------------------------------------------------
* 0.3    Nov 25,2016    PEI Jingli  Remove cpu clock related
*=====================================================================*/
#ifndef _MCU_CFG_H
#define _MCU_CFG_H
#include "CONFIG.h"
#include "define.h"
#include <Basicdriver_if.h>

/******************************************************************************
 *                                            wakeup factors config             
 *Define unmask wakeup factors for registers as WUFMSK0,WUFMSK20,WUFMSK_ISO0. 
 * bit val=0 unmask,  =1 mask
 ******************************************************************************/
/* WUFMSK0 used :Stop->Run, Deepstop->Run,  Cyclic stop->Cyclic Run 
* wakeup factors bit0:TNMI  bit1:WDTA0NMI  bit2:INTLVIL  bit3:  bit4:  bit5:INTP0  bit6:INTP1  bit7: INTP2  
* bit8:INTWDTA0  bit9:INTP3  bit10:INTP4  bit11:INTP5  bit12:INTP10  bit13:INTP13  bit14:WKTRG1  bit15:TAUJ0I0 
* bit16:TAUJ0I1  bit17:TAUJ0I2  bit18:TAUJ0I3  bit19:WTRG0  bit20:INTP6  bit21:INTP7  bit22:INTP8  bit23:INTP12
* bit24:INTP9  bit25:INTP13  bit26:INTP14  bit27:INTP15  
*/
#define STBC_CFG_STOP_WUFMSK0          0xfffffbff //used INTP4
/* WUFMSK20 used :Deepstop->Cyclic Run,  Cyclic stop->Cyclic Run 
*wakeup factors bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:                                                     */
#define STBC_CFG_STOP_WUFMSK20        0xffffffff
/* WUFMSK_ISO0 used :Stop->Run, Cyclic stop->Cyclic Run
*wakeup factors bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:  bit:                                                     */
#define STBC_CFG_STOP_WUFMSK_ISO0  0xffffffff

extern const U16 pwmClocKCfg[E_PWMCLK_MAX];
extern const PWM_CLKTYPE pwmChannelClocK[PWM_CHANNEL_MAX];


#endif /*_MCU_CFG_H */
/**************** END OF FILE *****************************************/

