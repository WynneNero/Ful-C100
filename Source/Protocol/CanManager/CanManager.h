/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ      									   *
*   AUTHOR	   :            										   *
************************************************************************
* Object        : 
* Module        : 
* Instance      : 
* Description   : 
*-----------------------------------------------------------------------
* Version: 
* Date: 
* Author: 
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date        Name                  Changes and comments
*----------------------------------------------------------------------
*  0.1  Feb 20,2017       ZhangJie               Init Version.
*=====================================================================*/
#ifndef _CAN_MANAGER_
#define _CAN_MANAGER_
#include "iodefine.h"
#include "can_par.h"

/*****************CAN Channel *******************/
#define CAN_Public 		    0				//CAN_Channel0, CAN1  
#define CAN_Private 		1				//CAN_Channel1, CAN0

typedef enum
{
	E_CAN_IDIT,

    E_CAN_POWERON,
	E_CAN_WAKEUP,
    E_CAN_WAIT_LINE_STABLE,
    E_CAN_CHECK,
    E_CAN_WAIT_POWER_STABLE,
    E_CAN_NORMAL,
    E_CAN_SLEEP,
    E_CAN_EER,    
    E_CAN_SLEEP_WAIT,
    E_CAN_BUSOFF_ENTER_SLEEP,
    E_CAN_RESET,
}CAN_STATE;

#define LOW_POWER_OFF_RECOVER_TIME 2 //50ms 
#define QUICK_POWER_OFF_RECOVER_TIME 17//200ms
#define BUS_OFF_ENTER_QUICK_RECOVER_MODE_TIME_CNT 4
#define TNoACK 15  //150MS
#define TPause 15  //150MS

extern void CanManager_10ms_Entry(void);
extern CAN_STATE GetCanstate(void);
extern U32 CanDriver_GetSeed(void);
extern void CanManager_BusOffStart(void);
extern void CanManager_BusOffEnd(void);
extern void CanMsgControlWithVoltage(void);
extern BOOL bCANisOnFlag;
extern BOOL CheckNetworkState(void) ;
#endif/*_CANAPP_H*/

