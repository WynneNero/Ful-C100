/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ    	 								   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:0.1
* Date:20151014
* Author:Shang Qiuju
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1  Oct 14,2015  SHANG Qiuju Initial version
* ----------------------------------------------------------------------
* 0.2  Mar 08,2017 Zhang Jie       Remove duplicate headfile.
* ----------------------------------------------------------------------
* 0.3  Mar 17,2017 Zhang Jie       Add io control funcrtion.
=====================================================================*/
#ifndef _CAN_DRIVER_IF_H_
#define _CAN_DRIVER_IF_H_
#include "Driver_IF.h"
#include "define.h"
//#include "GPIO_IF.H"

#include "desc.h"
#include "Appdesc_Cfg.h"
typedef void (*CanDiagFuncCallBackType)(APPL_DESC_SERVICE_ID_TYPE MsgContextId, DescMsgContext* pMsgContext);

extern void can_irq_enable(void);
extern void can_irq_disable(void);
extern ERR_TYPE CanDriver_Open(void);
extern ERR_TYPE CanDriver_Close(void);
extern U8 CanDriver_Control(U8 type, void* buffer);
extern void CanDriver_powercontrol(E_DEV_POWER type);
extern U8 CanDriver_GetpowerStatus(void);
extern void CanDriver_10ms_Entry(void);
extern void CanDriver_Init(void);
extern void CanDriver_SetBusOffState(BOOL bBusOff);
#endif
