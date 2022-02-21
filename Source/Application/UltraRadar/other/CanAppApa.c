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
#include "Define.h"
#include "CanApp.h"
#include "Can_App_il.h"
#include "CanSig_Def.h"
#include "CanSig_cfg.h"
#include "can_cfg.h"
#include "can_def.h"
#include "Cansig_cfg_if.h"
#include "CanAppApa.h"

/*---Global-------------------------------------------------------------*/
Appl_APA_CAN_RxMsg APARxCANMsg;
Appl_APA_CAN_TxMsg APATxCANMsg;

/*===FUNCTIONS===========================================*/


/***********************************************************************
* FUNCTION    : CanApp_APA_Init
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void CanApp_APA_Init(void)
{

}

/***********************************************************************
* FUNCTION    : CanApp_APA_DeInit
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void CanApp_APA_DeInit(void)
{

}

/***********************************************************************
* FUNCTION    : APA_CAN_Message_Handler
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void APA_CAN_Message_Handler(void)
{
	Appl_get_ApaControl_Info();
	Appl_set_ApaControl_Info();
}

/***********************************************************************
* FUNCTION    : Appl_get_ApaControl_Info
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void Appl_get_ApaControl_Info(void)
{
	ApplGetRxBrake_Apply_Information_CEMsg			(&APARxCANMsg.Brake_Apply_Information_CE);
	ApplGetRxAutomatic_Braking_Status_CEMsg			(&APARxCANMsg.Automatic_Braking_Status_CE);
	ApplGetRxDriven_Wheel_Grnd_Velocity_CEMsg			(&APARxCANMsg.Driven_Wheel_Grnd_Velocity_CE);
	ApplGetRxNonDriven_Wheel_Grnd_Velocity_CEMsg		(&APARxCANMsg.NonDriven_Wheel_Grnd_Velocity_CE);
	ApplGetRxPPEI_Chassis_General_Status_1_CEMsg		(&APARxCANMsg.PPEI_Chassis_General_Status_1_CE);
	ApplGetRxPPEI_Vehicle_Speed_Status_CEMsg			(&APARxCANMsg.PPEI_Vehicle_Speed_Status_CE);
	ApplGetRxNonDrivn_Whl_Rotationl_Stat_CEMsg		(&APARxCANMsg.NonDrivn_Whl_Rotationl_Stat_CE);
	ApplGetRxDriven_Whl_Rotational_Stat_CEMsg			(&APARxCANMsg.Driven_Whl_Rotational_Stat_CE);
	ApplGetRxPPEI_Steering_Wheel_Angle_CEMsg			(&APARxCANMsg.PPEI_Steering_Wheel_Angle_CE);
	ApplGetRxTrans_General_Status_2_CEMsg				(&APARxCANMsg.Trans_General_Status_2_CE);
	ApplGetRxElectric_Power_Steering_CEMsg				(&APARxCANMsg.Electric_Power_Steering_CE);
	ApplGetRxOutside_Air_Temp_Status_CEMsg			(&APARxCANMsg.Outside_Air_Temp_Status_CE);
	#ifdef APA_Slot_Searching_Replay
	ApplGetRxUSS_APA_NonHandler_DisMsg				(&APARxCANMsg.USS_APA_NonHandler_Dis);
	#endif
}

/***********************************************************************
* FUNCTION    : Appl_set_ApaControl_Info
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void Appl_set_ApaControl_Info(void)
{
	ApplPutTxPark_Assist_Parallel_CEMsg					(APATxCANMsg.Park_Assist_Parallel_CE);
	ApplPutTxDis_Long_EchoHeightMsg					(APATxCANMsg.Dis_Long_EchoHeight);
	ApplPutTxDis_Short_EchoHeightMsg					(APATxCANMsg.Dis_Short_EchoHeight);
	ApplPutTxDis_ShortSensorsMsg						(APATxCANMsg.Dis_ShortSensors);
	ApplPutTxDis_Sensors_StatusMsg						(APATxCANMsg.Dis_Sensors_Status);
	ApplPutTxDis_SidesSensorsMsg						(APATxCANMsg.Dis_SidesSensors);
	ApplPutTxUSS_Slot_Outline_InfoMsg					(APATxCANMsg.USS_Slot_Outline_Info);
	#ifndef APA_Slot_Searching_Replay
	ApplPutTxUSS_APA_NonHandler_DisMsg				(APATxCANMsg.USS_APA_NonHandler_Dis);
	#endif
	ApplPutTxWarningboard_RxMsg						(APATxCANMsg.Warningboard_Rx);
}

