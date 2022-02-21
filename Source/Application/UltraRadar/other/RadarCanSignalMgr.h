/*------------------------------------------------------------------------------

    File Name: RadarCanSignalMgr.h

    Convert the signal of USS algorithm.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    LinFeng       uidp5358       Desay SV HZH / IDA R&D

--------------------------------------------------------------------------------
                      R E V I S I O N   H I S T O R Y
--------------------------------------------------------------------------------
    Date           Ver       Author      Description
    ----------     ---       ------      --------------------------------------------
	2019-08-014    1.0      uidp5358     first version 
--------------------------------------------------------------------------------
                           C O P Y R I G H T
--------------------------------------------------------------------------------
         Copyright (c) 2019 by Huizhou Desay SV Automotive Co., Ltd.
                          All rights reserved.
------------------------------------------------------------------------------*/
#ifndef _RADAR_CAN_SIGNAL_MGR_H_
#define _RADAR_CAN_SIGNAL_MGR_H_

#include "Define.h"
#include "RadarMsg_IF.h"
#include "InputSignalProc.h"

#define USS_GET_INFO_OK    0
#define USS_GET_INFO_FAIL  1

#define Valid  0x00 
#define Invalid 0x01


typedef enum
{
	E_Validity_Start,
	E_Left_Drive_Wheel_SpeedRC_Validity,
	E_Right_Drive_Wheel_SpeedRC_Validity,
	E_Left_NonDrive_Wheel_SpeedRC_Validity,
	E_Right_NonDrive_WheelSpeedRC_Validity,
	E_GearStatus_Validity,
	E_steeringAngle_Validity,
	E_Left_NonDriveWheelSpeedValidity,
	E_Right_NonDriveWheelSpeedValidity,
	E_VehicleSpeed_Validity,
	E_PEPS_PowerMode_Validity,
	E_EPBSwitchSts_Validity,
	E_Ambient_Temperature_Validity,
	E_Validity_End,
}Validity_Type;

typedef enum
{
	E_Wheel_Pulse_Counter_Start,
	E_Left_Drive_Wheel_SpeedRC,
	E_Right_Drive_Wheel_SpeedRC,
	E_Left_NonDrive_Wheel_SpeedRC,
	E_Right_NonDrive_WheelSpeedRC,
	E_Wheel_Pulse_Counter_End,
}Wheel_Pulse_Type;

typedef enum
{
	E_DisPlay_Gear_P,
	E_DisPlay_Gear_N,
	E_DisPlay_Gear_D,
	E_DisPlay_Gear_R,
	E_DisPlay_Gear_Invalid,
}IPK_DisplayGears_Type;

typedef enum
{
	E_Wheel_Speed_Start,
	E_Front_Left_Speed,
	E_Front_Right_Speed,
	E_Rear_Left_Speed,
	E_Rear_Right_Speed,
	E_Wheel_Speed_End,
}Wheel_Speed_Type;

typedef enum
{
	E_PEPS_Mode_OFF,
	E_PEPS_Mode_ACC,
	E_PEPS_Mode_ACC_ON,
	E_PEPS_Mode_IGN_ON,
}PEPS_Power_Mode_Type;

typedef enum
{
	E_EPB_Released,
	E_EPB_Closed,
	E_EPB_InProgress,
	E_EPB_DefaultValue,
}EPB_Work_Status_Type;

typedef enum
{
	E_Engine_Stop,
	E_Engine_Cranking,
	E_Engine_Stoping,
	E_Engine_Running,
	E_Engine_Abnormal,
}Engine_Work_Status_Type;

typedef enum
{
	E_TurnLight_Default,
	E_TurnLight_Left,
	E_TurnLight_Right,
	E_TurnLight_Invalid,
}Turn_Light_Status_Type;

typedef enum
{
	E_OTHER_MODE,
	E_SLOTSEARCHING_MODE,
	E_APAPARKING_MODE
}Turn_Ecu_Woking_Status_Type;

unsigned char  USS_Get_CAN_Data(USS_CAN_DATA_Handle can_signal);
U8 Get_Signals_Validity_Handler(Validity_Type ValiditySignalType);
U16 Get_Wheel_Speed_Pulse_Counter_Handler(Wheel_Pulse_Type WheelPulseType);
IPK_DisplayGears_Type Get_GearStatus_Handler(void);
float Get_SteeringAngle_Handler(void);
float Get_Wheel_Speed_Handler(Wheel_Speed_Type WheelSpeedType);
PEPS_Power_Mode_Type Get_PEPS_Power_Status_Handler(void);
EPB_Work_Status_Type Get_EPB_Work_Status_Handler(void);
Engine_Work_Status_Type Get_Engines_Work_Status_Handler(void);
Turn_Light_Status_Type Get_Turn_Light_Status_Handler(void);
signed char Get_Ambient_Temperature_Handler(void);
float Get_Vehicle_Average_Speed_Handler(void);
Turn_Ecu_Woking_Status_Type Get_Ecu_Working_Mode(void);



#endif

