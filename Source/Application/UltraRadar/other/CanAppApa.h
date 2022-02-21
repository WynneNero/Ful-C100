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
#ifndef CAN_APP_APA_H
#define CAN_APP_APA_H

#include "Define.h"
#include "CanAPP.h"

typedef enum
{
	Veh_TurnningOff,
	Veh_TurnningLeft,
	Veh_TurnningRight,
	Veh_TurnningLeftAndRight
}VehicleTurnningSig;

typedef enum
{
	EPS_TemInhibit,
	EPS_AvailableControl,
	EPS_Active,
	EPS_PermanentlyFailed
}EpsAvalStat;

typedef struct
{
	float SteerWheelAng;	
	float VehSpdAvgDrvn;	
	U16 RearRightWheelSpeedCounter;
	U16 RearLeftWheelSpeedCounter; 
	U8 TrnsShftLvrPos;
	U8 BrkPdlPos;
	VehicleTurnningSig TurnningSignal;
	EpsAvalStat EpsAvailablityStatus;
}Appl_Vehicle_MessageType;

void CanApp_APA_Init(void);
void CanApp_APA_DeInit(void);

typedef struct
{
	Appl_Brake_Apply_Information_CE_msgType Brake_Apply_Information_CE;
	Appl_Automatic_Braking_Status_CE_msgType Automatic_Braking_Status_CE;
	Appl_Driven_Wheel_Grnd_Velocity_CE_msgType Driven_Wheel_Grnd_Velocity_CE;
	Appl_NonDriven_Wheel_Grnd_Velocity_CE_msgType NonDriven_Wheel_Grnd_Velocity_CE;
	Appl_PPEI_Chassis_General_Status_1_CE_msgType PPEI_Chassis_General_Status_1_CE;
	Appl_PPEI_Vehicle_Speed_Status_CE_msgType PPEI_Vehicle_Speed_Status_CE;
	Appl_NonDrivn_Whl_Rotationl_Stat_CE_msgType NonDrivn_Whl_Rotationl_Stat_CE;
	Appl_Driven_Whl_Rotational_Stat_CE_msgType Driven_Whl_Rotational_Stat_CE;
	Appl_PPEI_Steering_Wheel_Angle_CE_msgType PPEI_Steering_Wheel_Angle_CE;
	Appl_Trans_General_Status_2_CE_msgType Trans_General_Status_2_CE;
	Appl_Electric_Power_Steering_CE_msgType Electric_Power_Steering_CE;
	Appl_Outside_Air_Temp_Status_CE_msgType Outside_Air_Temp_Status_CE;
	#ifdef APA_Slot_Searching_Replay
	Appl_USS_APA_NonHandler_Dis_msgType USS_APA_NonHandler_Dis;
	#endif
}Appl_APA_CAN_RxMsg;

typedef struct
{
	Appl_Dis_Long_EchoHeight_msgType Dis_Long_EchoHeight;
	Appl_Dis_Short_EchoHeight_msgType Dis_Short_EchoHeight;
	Appl_Dis_ShortSensors_msgType Dis_ShortSensors;
	Appl_Dis_Sensors_Status_msgType Dis_Sensors_Status;
	Appl_Dis_SidesSensors_msgType Dis_SidesSensors;
	Appl_USS_Slot_Outline_Info_msgType USS_Slot_Outline_Info;
	#ifndef APA_Slot_Searching_Replay
	Appl_USS_APA_NonHandler_Dis_msgType USS_APA_NonHandler_Dis;
	#endif
	Appl_Warningboard_Rx_msgType Warningboard_Rx;
	Appl_Park_Assist_Parallel_CE_msgType Park_Assist_Parallel_CE;
}Appl_APA_CAN_TxMsg;


void CanApp_APA_Init(void);
void CanApp_APA_DeInit(void);
void Appl_get_ApaControl_Info(void);
void Appl_set_ApaControl_Info(void);

#endif/*CANAPP_IF_H*/
