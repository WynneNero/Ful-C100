/*------------------------------------------------------------------------------

    File Name: RadarMsg_IF.h

    Interface to USS algorithm.
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
#ifndef _RADAR_MSG_IF_H_
#define _RADAR_MSG_IF_H_

#if 0
typedef struct {
	unsigned short LeftDriveWheelSpeedRC;
	unsigned char LeftDriveWheelSpeedRCValidity;
	unsigned short RightDriveWheelSpeedRC;
	unsigned char RightDriveWheelSpeedRCValidity;
	unsigned short LeftNonDriveWheelSpeedRC;
	unsigned char LeftNonDriveWheelSpeedRCValidity;
	unsigned short RightNonDriveWheelSpeedRC;
	unsigned char RightNonDriveWheelSpeedRCValidity;
	unsigned char GearStatus;
	unsigned char GearStatusValidity;
	float SteeringAngle;
	unsigned char steeringAngleValidity;
	float LeftNonDriveWheelSpeed;
	unsigned char LeftNonDriveWheelSpeedValidity;
	float RightNonDriveWheelSpeed;
	unsigned char RightNonDriveWheelSpeedValidity;
	float VehicleSpeed;
	unsigned char VehicleSpeedValidity;
	unsigned char PEPSPowerMode;
	unsigned char PEPSPowerModeValidity;
	unsigned char EPBSwitchSts;
	unsigned char EPBSwitchStsValidity;
	unsigned char EngineSts;
	unsigned char TurnLight;
	float AmbientTemperature;
	unsigned char AmbientTemperatureValidity;
} USS_CAN_DATA_Type, * USS_CAN_DATA_Handle;


extern unsigned char  USS_Get_CAN_Data(USS_CAN_DATA_Handle can_signal);
#endif


#endif
