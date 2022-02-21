/*------------------------------------------------------------------------------

    File Name: RadarCanSignalMgr.c

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

#include "RadarCanSignalMgr.h"
#include "CanApp.h"
#include "il_inc.h"
#include "ApsCanAPP.h"

/***********************************************************************
* FUNCTION    : USS_Get_CAN_Data
* DESCRIPTION :ITTI USS Algorithm Received CAN	Signal
* INPUTS      : USS_CAN_DATA_Handle can_signal
* RETURN      : unsigned char
* RETURN VALUE: 0:OK	1:NOT_OK
***********************************************************************/

unsigned char  USS_Get_CAN_Data(USS_CAN_DATA_Handle can_signal)
{
	if(can_signal!=NULL)
		{
			can_signal->InputSignal_LeftDrvWheelPulseCnt/*FL*/ = Get_Wheel_Speed_Pulse_Counter_Handler(E_Left_Drive_Wheel_SpeedRC);
			can_signal->InputSignal_RightDrvWheelPulseCnt/*FR*/ = Get_Wheel_Speed_Pulse_Counter_Handler(E_Right_Drive_Wheel_SpeedRC);
			can_signal->InputSignal_LeftNonDrvWheelPulseCnt/*RL*/ = Get_Wheel_Speed_Pulse_Counter_Handler(E_Left_NonDrive_Wheel_SpeedRC);
			can_signal->InputSignal_RightNonDrvWheelPulseCnt/*RR*/ = Get_Wheel_Speed_Pulse_Counter_Handler(E_Right_NonDrive_WheelSpeedRC);
			can_signal->InputSignal_SteeringWheelAngle = Get_SteeringAngle_Handler();
			can_signal->InputSignal_OutAirTemperature = Get_Ambient_Temperature_Handler();
			can_signal->InputSignal_GeerPosision = Get_GearStatus_Handler();
			can_signal->InputSignal_OriGeerPosision = 0;
			can_signal->InputSignal_GeerPosisionValidFalg = Get_Signals_Validity_Handler(E_GearStatus_Validity);
			can_signal->InputSignal_VehicleSpeedValidFlag = Get_Signals_Validity_Handler(E_VehicleSpeed_Validity);
			can_signal->InputSignal_VehicleSpeed = Get_Vehicle_Average_Speed_Handler();
			can_signal->InputSignal_WhlGrndVlctyLftNnDrvn = Get_Wheel_Speed_Handler(E_Rear_Left_Speed);
			can_signal->InputSignal_WhlGrndVlctyRtNnDrvn = Get_Wheel_Speed_Handler(E_Rear_Right_Speed);
			can_signal->InputSignal_TrnSwAct = Get_Turn_Light_Status_Handler();
			can_signal->InputSignal_WhlPlsPerRevDrvn = 96;
			can_signal->InputSignal_WhlPlsPerRevNonDrvn = 96;	
			can_signal->InputSignal_EcuWorkingMode = Get_Ecu_Working_Mode();
			return USS_GET_INFO_OK;
		}
	else
		{
			return USS_GET_INFO_FAIL;
		}
}

/***********************************************************************
* FUNCTION    : Get_Signals_Validity_Handler
* DESCRIPTION :ITTI USS Algorithm get CAN Signal validity
* INPUTS      : Validity_Type ValiditySignalType
* RETURN      : unsigned char
* RETURN VALUE: enum : Valid 0x00,   Invalid 0x01
***********************************************************************/
U8 Get_Signals_Validity_Handler(Validity_Type ValiditySignalType)
{
	U8 ValidityRet = 0;
	if(ValiditySignalType < E_Validity_End)
	{
		switch(ValiditySignalType)
		{
			case E_Left_Drive_Wheel_SpeedRC_Validity:
			//ValidityRet = can_receive_sig(BCS_RLWheelSpdVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_Right_Drive_Wheel_SpeedRC_Validity:
				//ValidityRet = can_receive_sig(BCS_RRWheelSpdVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_Left_NonDrive_Wheel_SpeedRC_Validity:
				//ValidityRet = can_receive_sig(BCS_FLWheelSpdVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_Right_NonDrive_WheelSpeedRC_Validity:
				//ValidityRet = can_receive_sig(BCS_FRWheelSpdVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_GearStatus_Validity:
				//ValidityRet = can_receive_sig(TCU_CurrentGearStVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_steeringAngle_Validity:
				//ValidityRet = can_receive_sig(SAS_SteeringAngleVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_Left_NonDriveWheelSpeedValidity:
				ValidityRet = Valid;
				break;
				
			case E_Right_NonDriveWheelSpeedValidity:
				ValidityRet = Valid;
				break;
				
			case E_VehicleSpeed_Validity:
				//ValidityRet = can_receive_sig(BCS_VehSpdVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			case E_PEPS_PowerMode_Validity:
				ValidityRet == Valid;
				break;
				
			case E_EPBSwitchSts_Validity:
				ValidityRet == Valid;
				break;
				
			case E_Ambient_Temperature_Validity:
				//ValidityRet = can_receive_sig(HVACF_CorrectedExterTempVD);
				if(1 == ValidityRet)
				{
					ValidityRet = Valid;
				}
				break;
				
			default:
				break;
		}

	}
	else 
	{
		ValidityRet = Invalid;
	}
	return ValidityRet;
		
}

/***********************************************************************
* FUNCTION    : Get_Wheel_Speed_Pulse_Counter_Handler
* DESCRIPTION :ITTI USS Algorithm get Wheel Speed Pulse Signal 
* INPUTS      : Validity_Type ValiditySignalType
* RETURN      : unsigned char
* RETURN VALUE: enum : Valid 0x00,   Invalid 0x01
***********************************************************************/
U16 Get_Wheel_Speed_Pulse_Counter_Handler(Wheel_Pulse_Type WheelPulseType)
{
	U16 WheelPulse = 0;
	if(WheelPulseType < E_Wheel_Pulse_Counter_End)
	{
		switch(WheelPulseType)
		{
			case E_Left_Drive_Wheel_SpeedRC:
				//WheelPulse = can_receive_sig(BCS_RLWheelSpdEdgesSum);
				break;
						
			case E_Right_Drive_Wheel_SpeedRC:
				//WheelPulse = can_receive_sig(BCS_RRWheelSpdEdgesSum);
				break;
				
			case E_Left_NonDrive_Wheel_SpeedRC:
				//WheelPulse = can_receive_sig(BCS_FLWheelSpdEdgesSum);
				break;
				
			case E_Right_NonDrive_WheelSpeedRC:
				//WheelPulse = can_receive_sig(BCS_FRWheelSpdEdgesSum);
				break;
								
			default:
				WheelPulse = 0x00;
				break;
		}

	}
	else 
	{
		WheelPulse = 0x00;
	}
	return WheelPulse;
		
}

/***********************************************************************
* FUNCTION    : Get_GearStatus_Handler
* DESCRIPTION :ITTI USS Algorithm get Gear Status Signal 
* INPUTS      : void
* RETURN      : IPK_DisplayGears_Type
* RETURN VALUE: NONE P R N D      VW: 5 6 7 8 9 PRNDS
***********************************************************************/
U8 GearStatus_backup = GEAR_DISPLAY_INVALID;
IPK_DisplayGears_Type Get_GearStatus_Handler(void)
{
	IPK_DisplayGears_Type IPKDisPlayGear = 0;
	U8 GearStatus;
	U8 GearStatus_active;
	//GearStatus = can_receive_sig(TCU_CurrentGearSt);

	/*
	if(can_receive_sig(TCU_CurrentGearStVD) == Gear_invaild)   //0=Not Valid 1= Valid
    {
        GearStatus = GearStatus_backup;
    }
	else
	{
		if(can_receive_sig(TCU_GearForDisp) == CARGEAR_P)
		{
			GearStatus = E_DisPlay_Gear_P;
		}
		else if(can_receive_sig(TCU_GearForDisp) == CARGEAR_R)
		{
			GearStatus = E_DisPlay_Gear_R;
		}
		else if(can_receive_sig(TCU_GearForDisp) == CARGEAR_N)
		{
			GearStatus = E_DisPlay_Gear_N;
		}
		else if((can_receive_sig(TCU_GearForDisp) >= 0x1)&&(can_receive_sig(TCU_GearForDisp) <= 0x9) || (can_receive_sig(TCU_GearForDisp) == 0x0B) || (can_receive_sig(TCU_GearForDisp) == CARGEAR_D))
		{
			GearStatus = E_DisPlay_Gear_D;
		}
        else if(can_receive_sig(TCU_GearForDisp) == 0x0A)
        {
            GearStatus = GearStatus_backup;
        }
		else
		{
			GearStatus = E_DisPlay_Gear_Invalid;
		}
	}
    */
	GearStatus_backup = GearStatus;
	return GearStatus;
		
}


/***********************************************************************
* FUNCTION    : Get_SteeringAngle_Handler
* DESCRIPTION :ITTI USS Algorithm get Steering Angle Signal 
* INPUTS      : void
* RETURN      : float
* RETURN VALUE: steering angle
***********************************************************************/
float Get_SteeringAngle_Handler(void)
{
	U16 Raw_SteeringAngle = 0;
	S16 Phy_SteeringAngle;
	//Raw_SteeringAngle = can_receive_sig(SAS_SteeringAngle);
	Phy_SteeringAngle = (S16)Raw_SteeringAngle * (0.1)-780;
	return Phy_SteeringAngle;		
}


/***********************************************************************
* FUNCTION    : Get_Wheel_Speed_Handler
* DESCRIPTION :ITTI USS Algorithm get Wheel speed Signal 
* INPUTS      : void
* RETURN      : float
* RETURN VALUE: Wheel_Speed
***********************************************************************/
float Get_Wheel_Speed_Handler(Wheel_Speed_Type WheelSpeedType)
{
	U16 Raw_Speed = 0;
	float Phy_Speed = 0;
	if(WheelSpeedType < E_Wheel_Speed_End)
	{
		switch(WheelSpeedType)
		{
			case E_Front_Left_Speed:
				//Raw_Speed = can_receive_sig(BCS_FLWheelSpd);
				Phy_Speed = (float)Raw_Speed * 0.05625;
				break;
						
			case E_Front_Right_Speed:
				//Raw_Speed = can_receive_sig(BCS_FRWheelSpd);
				Phy_Speed = (float)Raw_Speed * 0.05625;
				break;
				
			case E_Rear_Left_Speed:
				//Raw_Speed = can_receive_sig(BCS_RLWheelSpd);
				Phy_Speed = (float)Raw_Speed * 0.05625;
				break;
				
			case E_Rear_Right_Speed:
				//Raw_Speed = can_receive_sig(BCS_RRWheelSpd);
				Phy_Speed = (float)Raw_Speed * 0.05625;
				break;

			default:
				Phy_Speed = 0x00;
				break;
		}

	}
	else 
	{
		Phy_Speed = 0x00;
	}
	return Phy_Speed;		
}

/***********************************************************************
* FUNCTION    : Get_PEPS_Power_Status_Handler
* DESCRIPTION :ITTI USS Algorithm get PEPS Power mode Status Signal 
* INPUTS      : void
* RETURN      : PEPS_Power_Mode_Type
* RETURN VALUE: OFF ACC ACCON INGON

ZAS_Kl_15
KL-15   0X00 OFF    0X01 ON 
***********************************************************************/
PEPS_Power_Mode_Type Get_PEPS_Power_Status_Handler(void)
{
	PEPS_Power_Mode_Type PEPSMode = E_PEPS_Mode_OFF;
	U8 Raw_PEPSMode;
	//Raw_PEPSMode = can_receive_sig(BCM_KeySt);
	if(!Raw_PEPSMode)
	{
		PEPSMode = E_PEPS_Mode_OFF;
	}
	else if(Raw_PEPSMode == 0x01)
	{
		PEPSMode = E_PEPS_Mode_ACC;
	}
	else if(Raw_PEPSMode == 0x02)
	{
		PEPSMode = E_PEPS_Mode_ACC_ON;
	}
	else if(Raw_PEPSMode == 0x03)
	{
		PEPSMode = E_PEPS_Mode_ACC_ON;
	}
	else
	{
		PEPSMode = E_PEPS_Mode_ACC_ON;
	}
	return PEPSMode;
}

/***********************************************************************
* FUNCTION    : Get_EPB_Work_Status_Handler
* DESCRIPTION :ITTI USS Algorithm get EPB Work Status Signal 
* INPUTS      : void
* RETURN      : EPB_Work_Status_Type
* RETURN VALUE: Released Closed InProgress DefaultValue
***********************************************************************/
EPB_Work_Status_Type Get_EPB_Work_Status_Handler(void)
{
	EPB_Work_Status_Type EPBWorkStatus = E_EPB_DefaultValue;
	return EPBWorkStatus;		
}

/***********************************************************************
* FUNCTION    : Get_Engine_Work_Status_Handler
* DESCRIPTION :ITTI USS Algorithm get Engine Work Status Signal 
* INPUTS      : void
* RETURN      : Engine_Work_Status_Type
* RETURN VALUE: stop cranking stopping running abnormal
***********************************************************************/
Engine_Work_Status_Type Get_Engines_Work_Status_Handler(void)
{
	Engine_Work_Status_Type EngineWorkStatus = 0;
	return EngineWorkStatus;		
}

/***********************************************************************
* FUNCTION    : Get_Turn_Light_Status_Handler
* DESCRIPTION :ITTI USS Algorithm get Turn Light Work Status Signal 
* INPUTS      : void
* RETURN      : Turn_Light_Status_Type
* RETURN VALUE: Default Left Right Invalid
***********************************************************************/
Turn_Light_Status_Type Get_Turn_Light_Status_Handler(void)
{

	return E_TurnLight_Default;		
}

/***********************************************************************
* FUNCTION    : Get_Ambient_Temperature_Handler
* DESCRIPTION :ITTI USS Algorithm get Ambient Temperature Signal 
* INPUTS      : void
* RETURN      : Turn_Light_Status_Type
* RETURN VALUE: Default Left Right Invalid
***********************************************************************/
signed char Get_Ambient_Temperature_Handler(void)
{
	unsigned char Phy_AmbientTemperature = 0;
	U16 Raw_AmbientTemperature;
	//Raw_AmbientTemperature = can_receive_sig(HVACF_CorrectedExterTemp);
	Phy_AmbientTemperature = (unsigned char)((Raw_AmbientTemperature * 0.5) - 0x28);// + 40); //Temp offset +40
	return Phy_AmbientTemperature;		
}

/***********************************************************************
* FUNCTION    : Get_Vehicle_Average_Speed_Handler
* DESCRIPTION :ITTI USS Algorithm get average speed  Signal 
* INPUTS      : void
* RETURN      : U16
* RETURN VALUE: 
***********************************************************************/
float Get_Vehicle_Average_Speed_Handler(void)
{
	float Raw_Speed;
	U16	Phy_Speed;
	//Raw_Speed = can_receive_sig(BCS_VehSpd);
	Phy_Speed = (U16)(Raw_Speed * 0.05625);

	return Phy_Speed;
}

/***********************************************************************
* FUNCTION    : Get_Ecu_Working_Mode
* DESCRIPTION :ITTI USS Algorithm get average speed  Signal 
* INPUTS      : void
* RETURN      : U16
* RETURN VALUE: 
***********************************************************************/
extern APS_MODULE_STATUS APSModuleCurrentStatus;
Turn_Ecu_Woking_Status_Type Get_Ecu_Working_Mode(void)
{
	Turn_Ecu_Woking_Status_Type Mode = E_OTHER_MODE;
	if(APSModuleCurrentStatus == APS_PARKING_SEARCH_PARKIN)
	{
		Mode = E_SLOTSEARCHING_MODE;
	}
	else if(APSModuleCurrentStatus == APS_PARKING_MAP_UPDATE || APSModuleCurrentStatus == APS_PARKING_ACTIVE_PARKIN )
	{
		Mode = E_APAPARKING_MODE;
	}
	else
	{
		Mode = E_OTHER_MODE;
	}
	return Mode;
}

