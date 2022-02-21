/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   		     *
*				  All Rights Reserved.          					                          *
*   Department 	: ITTI_HZ     									   		     *
*   AUTHOR	   	: 									                                 *
************************************************************************
* Object        		:
* Module        		:
* Instance      	:
* Description  		:
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 0.1    	2018/8/23   Zheng Xiaolei    Initial version
*======================================================*/
#ifndef ULTRA_RADAR_DRIVER_H
#define ULTRA_RADAR_DRIVER_H

#include "TimerUnit_if.h"

/**** Definition of constants **********************************************/
#if 0
typedef enum{
  RRS_SNS_INDEX = 0,
  RR_SNS_INDEX, /*1*/
  RRM_SNS_INDEX,/*2*/
  RLM_SNS_INDEX,/*3*/
  RL_SNS_INDEX, /*4*/
  RLS_SNS_INDEX,/*5*/
  FRS_SNS_INDEX,/*6*/
  FR_SNS_INDEX, /*7*/
  FRM_SNS_INDEX,/*8*/
  FLM_SNS_INDEX,/*9*/
  FL_SNS_INDEX, /*10*/
  FLS_SNS_INDEX,/*11*/
} PASysSnsIndexType;
#endif
/**** Definition of types *************************************************/

/**** Definition of functions **********************************************/
extern void SnsIntp_EnableInt(unsigned char index);
extern void HWA_DisableElmosRxPinInt(unsigned char index);
extern void SnsIntp_DisableAllInt(void);
extern void HWA_TimeDelay(unsigned short wTime /*UNIT: us*/);
extern unsigned long HWA_Get_Intp_Init_Time_Point(void);
extern void Intp_init(void);
extern unsigned long TAUJ0I0_Timer_GetCount(void);
extern void TAUD0I1_Timer_callback(void);
extern void TAUD0I3_Timer_callback(void);
extern void TAUJ0_Channel0_start(void);
extern void TAUD0_Channel1_start(void);
extern void TAUJ0_Channel1_start(unsigned short tauj_channel1_duty);
extern void TAUD_SysTime_start(void);
extern void TAUJ0_Channel0_stop(void);
extern void TAUD0_Channel1_stop(void);
extern void TAUD_SysTime_stop(void);
extern unsigned long HWA_Get_Systime(void);
extern void HWA_SetRrSensorHigh(void);
extern void HWA_SetRrSensorLow(void);
extern void HWA_SetRlSensorHigh(void);
extern void HWA_SetRlSensorLow(void);
extern void HWA_SetRrmSensorHigh(void);
extern void HWA_SetRrmSensorLow(void);
extern void HWA_SetRlmSensorHigh(void);
extern void HWA_SetRlmSensorLow(void);
extern void HWA_SetRrsSensorHigh(void);
extern void HWA_SetRrsSensorLow(void);
extern void HWA_SetRlsSensorHigh(void);
extern void HWA_SetRlsSensorLow(void);
extern void HWA_SetFrSensorHigh(void);
extern void HWA_SetFrSensorLow(void);
extern void HWA_SetFlSensorHigh(void);
extern void HWA_SetFlSensorLow(void);
extern void HWA_SetFrmSensorHigh(void);
extern void HWA_SetFrmSensorLow(void);
extern void HWA_SetFlmSensorHigh(void);
extern void HWA_SetFlmSensorLow(void);
extern void HWA_SetFrsSensorHigh(void);
extern void HWA_SetFrsSensorLow(void);
extern void HWA_SetFlsSensorHigh(void);
extern void HWA_SetFlsSensorLow(void);
extern unsigned char HWA_GetSensorLineLevel(unsigned char index);
extern void HWA_SetAllApaSensorLineHigh(void);
extern void HWA_SetAllUpaSensorLineHigh(void);
#endif /* ULTRA_RADAR_DRIVER_H */
