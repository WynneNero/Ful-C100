/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department :  IDA_SW2      									   *
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
* Version       Date    Name    Changes and comments
 ----------------------------------------------------------------------
* 0.1    Jun 26,2016                        Initial version
*=====================================================================*/
#ifndef _HAL_IF_H_
#define _HAL_IF_H_ 

/**** Definition of constants ****/
/**** Definition of macros ****/
/* Macro definitions*/
typedef enum _DEV_PWR_OP_TYPE
{
  DEV_OP_UNKNOW,
  DEV_OP_OPEN,       
  DEV_OP_PWR_ON,
  DEV_OP_PWR_WAKEUP,
  DEV_OP_PWR_SLEEP,
  DEV_OP_PWR_OFF,
  DEV_OP_CLOSE,
  DEV_OP_MAX,
}DEV_PWR_OP_TYPE;

typedef enum
{
  DEV_STATE_UNKNOW,
  DEV_OPEN_ING,  // open
  DEV_OPEN_ING_TIMEOUT,
  DEV_OPEN,
  
  DEV_ON_ING,     // powerControl(DEV_OP_PWR_ON)
  DEV_ON_ING_TIMEOUT,
  DEV_ON,
  DEV_WAKE_ING,
  DEV_WAKE_ING_TIMEOUT,
  DEV_WAKE,
  DEV_SLEEP_ING, // powerControl(DEV_OP_PWR_SLEEP)
  DEV_SLEEP_ING_TIMEOUT,
  DEV_SLEEP,
  DEV_OFF_ING, // powerControl(DEV_OP_PWR_OFF)
  DEV_OFF_ING_TIMEOUT,
  DEV_OFF,
  
  DEV_CLOSE_ING, // close
  DEV_CLOSE_ING_TIMEOUT,
  DEV_CLOSE,
}DEV_PWR_STATE_TYPE;

#endif 

/****************************** END OF FILE ***************************/

