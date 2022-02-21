/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : IDA R&D SW1      									   *
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
* ----------------------------------------------------------------------
* 0.1    Oct 7,2017   11111			   Initial version      
*=====================================================================*/
#include "config.h"
#include "CanApp.h"
#include "SocCommunicator.H"
#include "il_inc.h"
#include "il_par.h"
#include "Sig_Combine.H"
#include "Signal_IF.H"
#include "NaviApp.h"
#include "EEP_EOLconfig.h"
#include "ApsCanApp.h"
#include "APSAPP.h"
#include "SocManager.h"
#include "CanMacroDefine.h"
#include "candiagdtc.h"
#include "EEP_DiagData.h"
#include "GPIO.h"
#include "GPIO_IF.H"
#include "candiagdtc.h"

#include "Dem_IntErrId.h"

#include "M4MsgHandler.h"
#include "M4MsgHandler_IF.h"
#include "UssInfoMsg.h"
#include "xprintf.h"
#include "FVAlgLibInterface.h"

/*********************extern variable*******************/
extern APS_MODULE_STATUS APSModuleCurrentStatus;
extern diagnosticTypedef USSFailureStatus_Info_called[12];
extern BOOL APA_FoundSlotBuzzerTip;


/*******************/
U8 can_ParkPlace_Type = 0;
BOOL Camera_Status;
BOOL SOC_Send_Point_Flag = FALSE;

float32 can_WheelAngleValue = 0;
float32 can_VehicleSpeedValue = 0;
float32 Facing_Space = 0;
APA_SLOTINFO APA_SlotInfo[8] = {0};
APS_MODULE_STATUS SocCurrentParkingStatus;
APA_RELOAT_PLACE_INFO apa_reloat_place_info;


/***********parkplace_info*************/
float32 can_ParkPlace_X_1 = 0;
float32 can_ParkPlace_Y_1 = 0;
float32 can_ParkPlace_X_2 = 0;
float32 can_ParkPlace_Y_2 = 0;

float32 can_ParkPlace_X_3 = 0;
float32 can_ParkPlace_Y_3 = 0;
float32 can_ParkPlace_X_4 = 0;
float32 can_ParkPlace_Y_4 = 0;

/****************************************************************************
*  Name			: SocApsCan_20ms_Entry
*  Description	: 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void SocApsCan_20ms_Entry(void)
{
	apscan_ESC_Standstill_status();
	apscan_ESC_FrontWheelSpeedsKPH();
	apscan_ESC_status();
	apscan_YRS_Status();

	apscan_SAS_SteeringAngleVD();
	apscan_ESC_WheelSpeedsRC();
    apscan_TCU_ActGear();
    apscan_ABS_VehicleSpeed();
}

float32 get_WheelAngleValue(void)
{
	return can_WheelAngleValue;
}


static float32 can_BCS_FLWheelSpd = 0;
static float32 can_BCS_FRWheelSpd = 0;
static float32 can_BCS_RLWheelSpd = 0;
static float32 can_BCS_RRWheelSpd = 0;

static U8  can_ABS_DrivingDirection = InvalidValue;
/****************************************************************************
*  Name			: apscan_ESC_FrontWheelSpeedsKPH
*  Description	: 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_ESC_FrontWheelSpeedsKPH(void)
{
	U16 calValueFL = can_receive_sig(WheelSpeed_FL);
	U16 calValueFR = can_receive_sig(WheelSpeed_FR);
	U16 calValueRL = can_receive_sig(WheelSpeed_RL);
	U16 calValueRR = can_receive_sig(WheelSpeed_RR);
    
	can_BCS_FLWheelSpd = ((float32)calValueFL)*WHEELSPEEDKPHFACTOR;
	M4Msg_Update(E_M4_FLWheelSpeed_U16,can_BCS_FLWheelSpd);//uidp5358
	
	can_BCS_FRWheelSpd = ((float32)calValueFR)*WHEELSPEEDKPHFACTOR;
	M4Msg_Update(E_M4_FRwheelSpeed_U16,can_BCS_FRWheelSpd);//uidp5358

	can_BCS_RLWheelSpd = ((float32)calValueRL)*WHEELSPEEDKPHFACTOR;
	M4Msg_Update(E_M4_RLwheelSpeed_U16,can_BCS_RLWheelSpd);//uidp5358
 		
	can_BCS_RRWheelSpd = ((float32)calValueRR)*WHEELSPEEDKPHFACTOR;
	M4Msg_Update(E_M4_RRwheelSpeed_U16,can_BCS_RRWheelSpd);//uidp5358

    can_ABS_DrivingDirection = can_receive_sig(DrivingDirection);
}

float32 get_BCS_FLWheelSpd(void)
{
	return can_BCS_FLWheelSpd;
}
float32 get_BCS_FRWheelSpd(void)
{
	return can_BCS_FRWheelSpd;
}
float32 get_BCS_RLWheelSpd(void)
{
	return can_BCS_RLWheelSpd;
}
float32 get_BCS_RRWheelSpd(void)
{
	return can_BCS_RRWheelSpd;
}

U8 get_can_ABS_DrivingDirection(void)
{
    return can_ABS_DrivingDirection;
}


U8  can_EMS_BrakePedalSt = 0;
U8  can_EPB_SysSt = 0;
/****************************************************************************
*  Name			: apscan_ESC_status
*  Description	: 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_ESC_status(void)
{
	can_EPB_SysSt = can_receive_sig(WorkingSt_EPB);
	M4Msg_Update(E_M4_EPBStatus_U8,can_EPB_SysSt);//uidp5358
	
	can_EMS_BrakePedalSt = can_receive_sig(BrakePedalSt);
	M4Msg_Update(E_M4_BrakePedalSwitchStatus_U8,can_EMS_BrakePedalSt);//uidp5358
}

U8 get_EMS_BrakePedalSt(void)
{
     return can_EMS_BrakePedalSt;
}

U8 get_EPB_SysSt(void)
{
	return can_EPB_SysSt;
}


float32 canActYawRate = 0;
float32 canActVehLaltrlAccel = 0;
float32 canActVehLongAccel = 0;
/****************************************************************************
*  Name			: apscan_YRS_Status
*  Description	: 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_YRS_Status(void)
{
	S16 canYawRate = 0;      //unit : degree/s  (conversion: rad * 57.3 -> degree)
	S16 canVehLaltrlAccel = 0;   //unit : m/s2
	S16 canVehLongAccel = 0;     //unit : m/s2
	
	S16 canYawRateOffset = 0;
	S16 canVehLaltrlAccelOffset = 0;
	S16 canVehLongAccelOffset = 0;

    U8 canYRSErrorStatus = can_receive_sig(ErrorSt_YRS);
    U8 canYRSStatus = can_receive_sig(YRSSt);

    if(canYRSErrorStatus == NoError && canYRSStatus == Calibrated)
    {
        canYawRate = can_receive_sig(YawRate);    
    	canActYawRate = ((float32)(canYawRate * YAWRATEFACTOR) - YAWRATEOFFSET);	
    	M4Msg_Update(E_M4_YawRate_Multiple1K_U32,canActYawRate);

        canVehLaltrlAccel = can_receive_sig(Acceleration_Y);
    	canActVehLaltrlAccel = ((float32)(canVehLaltrlAccel * VEHLALTRLACCELFACTOR - VEHLALTRLACCELOFFSET));
    	M4Msg_Update(E_M4_LateralAcce_Multiple1K_U16,canActVehLaltrlAccel);

        canVehLongAccel = can_receive_sig(Acceleration_X);
    	canActVehLongAccel = ( (float32)(canVehLongAccel * VEHLONGACCELFACTORT - VEHLONGACCELOFFSET));
    	M4Msg_Update(E_M4_LongitAcce_Multiple1K_U16,canActVehLongAccel); 
    }   
}

float32 get_ActVehLaltrlAccel(void)
{
	return canActVehLaltrlAccel;
}

float32 get_ActYawRate(void)
{
	return canActYawRate;
}

float32 get_ActVehLongAccel(void)
{
	return canActVehLongAccel;
}

U8 canActSASStatus = 0;
S16 canWheelSteerAngle_FV = 0;
float32 canActWheelSteerAngle = 0;
/****************************************************************************
*  Name			: apscan_SAS_SteeringAngleVD
*  Description	: send to FV
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_SAS_SteeringAngleVD(void)
{
    U8  canSteeringWheelAngleDiretion = 0;  
    
	canActSASStatus = can_receive_sig(SAS_St);
    if(canActSASStatus == SASCorrect)
    {       
    	canWheelSteerAngle_FV = can_receive_sig(SteeringWheelAngle);//* STEERINGWHEELANGLEFACTOR;
        canSteeringWheelAngleDiretion = can_receive_sig(SteeringWheelAngleSign); //0-left,1-right
        
    	if(canSteeringWheelAngleDiretion == SteeringWheelAngleLeft)
    	{
    		canWheelSteerAngle_FV = (canWheelSteerAngle_FV); //left
    	}
    	else
    	{
    		canWheelSteerAngle_FV = (canWheelSteerAngle_FV) * (-1);  //right
    	}
    }
    canActWheelSteerAngle = (float32)(canWheelSteerAngle_FV) * STEERINGWHEELANGLEFACTOR;   
}

U8 get_SAS_SteeringAngleVD(void)
{
	return canActSASStatus;
}

S16 get_SAS_WheelSteerAngle_FV(void)
{
	return canWheelSteerAngle_FV;
}

float32 get_SAS_WheelSteerAngle(void)
{
	return canActWheelSteerAngle;
}



U8 canGear;
/****************************************************************************
*  Name			: apscan_TCU_ActGear
*  Description	: 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_TCU_ActGear(void)
{	
    static U8 canGearBackup = GEAR_INVALID;
    canGear = can_receive_sig(LeverInfo);

	if(canGear > GEAR_D)
    {
        if(canGear == GEAR_S || canGear == GEAR_M || canGear == GEAR_E || canGear == GEAR_W || canGear == GEAR_B)
        {
            canGear = GEAR_D;
        }
        else
        {
            canGear = GEAR_INVALID;
        }
    }
	
    if(canGear == GEAR_INVALID || canGear == GEAR_CONNECTION)   
    {
        canGear = canGearBackup;
    }
    
	canGearBackup = canGear;  
	M4Msg_Update(E_M4_GearStatus_U8,canGear);

}

U8 get_ActGear(void)
{
    return canGear;
}

U8 can_ABS_WheelPulse_FL = 0;
U8 can_ABS_WheelPulse_FR = 0;
U8 can_ABS_WheelPulse_RL = 0;
U8 can_ABS_WheelPulse_RR = 0;
/****************************************************************************
*  Name			: apscan_ESC_WheelSpeedsRC
*  Description	: get Wheel Pulse Counter 
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_ESC_WheelSpeedsRC(void)
{	
	can_ABS_WheelPulse_FL = can_receive_sig(WheelPulse_FL);
	M4Msg_Update(E_M4_FLWheelSpeed_PULSE_U16,can_ABS_WheelPulse_FL);//uidp5358

	can_ABS_WheelPulse_FR = can_receive_sig(WheelPulse_FR);
	M4Msg_Update(E_M4_FRwheelSpeed_PULSE_U16,can_ABS_WheelPulse_FR);//uidp5358
	
	can_ABS_WheelPulse_RL = can_receive_sig(WheelPulse_RL);
	M4Msg_Update(E_M4_RLwheelSpeed_PULSE_U16,can_ABS_WheelPulse_FR);//uidp5358
	
	can_ABS_WheelPulse_RR = can_receive_sig(WheelPulse_RR);
	M4Msg_Update(E_M4_RRwheelSpeed_PULSE_U16,can_ABS_WheelPulse_RR);//uidp5358

}

U8 get_WheelPulse_FL(void)
{
    return can_ABS_WheelPulse_FL;
}
U8 get_WheelPulse_FR(void)
{
	return can_ABS_WheelPulse_FR;
}
U8 get_WheelPulse_RL(void)
{
	return can_ABS_WheelPulse_RL;
}
U8 get_WheelPulse_RR(void)
{
	return can_ABS_WheelPulse_RR;
}


float32 can_ESC_VehicleSpeed = 0;
/****************************************************************************
*  Name			: apscan_EMS_GasPedalActPst
*  Description	: Scan EMS_GasPedalActPst Value
*  Parameter	: None
*  Returns		: None
****************************************************************************/
void apscan_ABS_VehicleSpeed(void)
{
	can_ESC_VehicleSpeed = can_receive_sig(VehicleSpeed) * VEHICELSPEEDFACTOR;
	M4Msg_Update(E_M4_VehicleSpeed_U16, can_ESC_VehicleSpeed);
}

float32 get_VehSpd(void)
{
	return can_ESC_VehicleSpeed;
}


/****************************************************************************
*  Name			: apscan_AC_OutsideTemperature
*  Description	: OutsideTemperature Value
*  Parameter	: None
*  Returns		: None
****************************************************************************/
float32 apscan_AC_OutsideTemperature(void)
{
    float32 can_AC_Temperature;
	can_AC_Temperature = can_receive_sig(AmbientTemp) * TEMPERATUREFACTOR - TEMPERATUREOFFSET;
    return can_AC_Temperature;
}


U8 SocPositionSendStatus = FALSE;
U8 SocParkTypeSendStatus = FALSE;
U8 SOC_Request_Exit_APS = FALSE;
U8 g_APA_park_fusion_type = AVM_SLOT_TYPE;
U8 Down_Slot_SOD = FALSE;
/****************************************************************************
*  Name		: ApsCanApp_recvnavimsg_handler
*  Description	: 
*  Parameter	: None
*  Returns	: None
****************************************************************************/
void ApsCanApp_recvnavimsg_handler(U16 commandid, U8* data)
{
	S16 ParkPlace_X_1 = 0;
	S16 ParkPlace_Y_1 = 0;
	S16 ParkPlace_X_2 = 0;
	S16 ParkPlace_Y_2 = 0;
	S16 ParkPlace_X_3 = 0;
	S16 ParkPlace_Y_3 = 0;
	S16 ParkPlace_X_4 = 0;
	S16 ParkPlace_Y_4 = 0;
#if XPRINTF_ENABLE
	LOG(SOC_MESSAGE_TRACE,"Read command_id: 0x%x \r\n",commandid);
#endif
	switch (commandid)
    {
    	case SOC_NOTIFY_RADIO_CAMERA_FAULT_STATUS: //443D
			if(data[0] != 0||data[1] != 0||data[2] != 0||data[3] != 0)
			{
				Camera_Status = TRUE;
			}
			else
			{
				Camera_Status = FALSE;
			}
		break;

        case SOC_SEND_MCU_SLOT_POINT:   //45C0
        	SOC_Send_Point_Flag = TRUE;
			APA_SlotInfo[0].APS_SlotCenterPoint_X	 = (((data[0]&0x00FF)<<8) + (data[1]&0xFF));		 
			APA_SlotInfo[0].APS_SlotCenterPoint_Y	 = (((data[2]&0x00FF)<<8) + (data[3]&0xFF));
			APA_SlotInfo[0].APS_Slot_Width			 = (((data[4]&0x00FF)<<8) + (data[5]&0xFF));
			APA_SlotInfo[0].APS_Slot_Length 		 = (((data[6]&0x00FF)<<8) + (data[7]&0xFF));  
			 
			APA_SlotInfo[0].APS_Slot_LineAngle		 = (((data[8]&0x00FF)<<8) + (data[9]&0xFF)); 		 
			APA_SlotInfo[0].APS_Slot1_ParkDirection  = data[10];   
			APA_SlotInfo[0].APS_Slot1_DetectStatus	 = data[11];
			APA_SlotInfo[0].APS_Slot1_Info			 = data[12];

			 
			APA_SlotInfo[1].APS_SlotCenterPoint_X	 = (((data[13]&0x00FF)<<8) + (data[14]&0xFF));			
			APA_SlotInfo[1].APS_SlotCenterPoint_Y	 = (((data[15]&0x00FF)<<8) + (data[16]&0xFF));
			APA_SlotInfo[1].APS_Slot_Width		 	 = (((data[17]&0x00FF)<<8) + (data[18]&0xFF));
			APA_SlotInfo[1].APS_Slot_Length 	 	 = (((data[19]&0x00FF)<<8) + (data[20]&0xFF));	
			 
			APA_SlotInfo[1].APS_Slot_LineAngle	 	 = (((data[21]&0x00FF)<<8) + (data[22]&0xFF));		   
			APA_SlotInfo[1].APS_Slot1_ParkDirection  = data[23];
			APA_SlotInfo[1].APS_Slot1_DetectStatus	 = data[24]; 		
			APA_SlotInfo[1].APS_Slot1_Info		 	 = data[25];


			APA_SlotInfo[2].APS_SlotCenterPoint_X	 = (((data[26]&0x00FF)<<8) + (data[27]&0xFF));			
			APA_SlotInfo[2].APS_SlotCenterPoint_Y	 = (((data[28]&0x00FF)<<8) + (data[29]&0xFF));
			APA_SlotInfo[2].APS_Slot_Width			 = (((data[30]&0x00FF)<<8) + (data[31]&0xFF));
			APA_SlotInfo[2].APS_Slot_Length 	 	 = (((data[32]&0x00FF)<<8) + (data[33]&0xFF));	
			 
			APA_SlotInfo[2].APS_Slot_LineAngle		 = (((data[34]&0x00FF)<<8) + (data[35]&0xFF));		   
			APA_SlotInfo[2].APS_Slot1_DetectStatus	 = data[36];
			APA_SlotInfo[2].APS_Slot1_ParkDirection  = data[37];
			APA_SlotInfo[2].APS_Slot1_Info		 	 = data[38];

			 
			APA_SlotInfo[3].APS_SlotCenterPoint_X	 = (((data[39]&0x00FF)<<8) + (data[40]&0xFF));			
			APA_SlotInfo[3].APS_SlotCenterPoint_Y	 = (((data[41]&0x00FF)<<8) + (data[42]&0xFF));
			APA_SlotInfo[3].APS_Slot_Width		 	 = (((data[43]&0x00FF)<<8) + (data[44]&0xFF));
			APA_SlotInfo[3].APS_Slot_Length 	 	 = (((data[45]&0x00FF)<<8) + (data[46]&0xFF));	

			APA_SlotInfo[3].APS_Slot_LineAngle	 	 = (((data[47]&0x00FF)<<8) + (data[48]&0xFF));		   
			APA_SlotInfo[3].APS_Slot1_DetectStatus	 = data[49];
			APA_SlotInfo[3].APS_Slot1_ParkDirection  = data[50];
			APA_SlotInfo[3].APS_Slot1_Info		 	 = data[51];


			APA_SlotInfo[4].APS_SlotCenterPoint_X	 = (((data[52]&0x00FF)<<8) + (data[53]&0xFF));			
			APA_SlotInfo[4].APS_SlotCenterPoint_Y	 = (((data[54]&0x00FF)<<8) + (data[55]&0xFF));
			APA_SlotInfo[4].APS_Slot_Width		 	 = (((data[56]&0x00FF)<<8) + (data[57]&0xFF));
			APA_SlotInfo[4].APS_Slot_Length 	 	 = (((data[58]&0x00FF)<<8) + (data[59]&0xFF));	

			APA_SlotInfo[4].APS_Slot_LineAngle	 	 = (((data[60]&0x00FF)<<8) + (data[61]&0xFF));		   
			APA_SlotInfo[4].APS_Slot1_DetectStatus	 = data[62];
			APA_SlotInfo[4].APS_Slot1_ParkDirection  = data[63];
			APA_SlotInfo[4].APS_Slot1_Info			 = data[64];


			APA_SlotInfo[5].APS_SlotCenterPoint_X	 = (((data[65]&0x00FF)<<8) + (data[66]&0xFF));			
			APA_SlotInfo[5].APS_SlotCenterPoint_Y	 = (((data[67]&0x00FF)<<8) + (data[68]&0xFF));
			APA_SlotInfo[5].APS_Slot_Width		 	 = (((data[69]&0x00FF)<<8) + (data[70]&0xFF));
			APA_SlotInfo[5].APS_Slot_Length 	 	 = (((data[71]&0x00FF)<<8) + (data[72]&0xFF));	

			APA_SlotInfo[5].APS_Slot_LineAngle	 	 = (((data[73]&0x00FF)<<8) + (data[74]&0xFF));		   
			APA_SlotInfo[5].APS_Slot1_DetectStatus	 = data[75];
			APA_SlotInfo[5].APS_Slot1_ParkDirection  = data[76]; 
			APA_SlotInfo[5].APS_Slot1_Info		 	 = data[77];
					
			break;
            
		case CPU_NOTIFY_M3_APA_SYSTEM_STATUS:// 0x44C6
		    switch(data[0])
            {
                case 0x00:
                    SocCurrentParkingStatus = APS_PARKING_INIT;
                    break;
                case 0x01:
                    SocCurrentParkingStatus = APS_PARKING_STANDBY;
                    break;
                case 0x02:
                    SocCurrentParkingStatus = APS_PARKING_SEARCH_PARKIN;
                    break;
                case 0x03:
                    SocCurrentParkingStatus = APS_PARKING_SEARCH_PARKOUT;
                    break;
                case 0x04:
                    SocCurrentParkingStatus = APS_PARKING_MAP_UPDATE;
                    break;
                case 0x05:
                    SocCurrentParkingStatus = APS_PARKING_ACTIVE_PARKIN;
                    break;
                case 0x06:
                    SocCurrentParkingStatus = APS_PARKING_ACTIVE_PARKOUT;
                    break;
				case 0x07:
					SocCurrentParkingStatus = APS_PARKING_AVMMODE;
					break;						
                default:
                    break;
            }      
		break;

		case CPU_NOTIFY_M3_APA_CURRENTPARKTYPE: // 0x44C8
			if(data[0] != 0)
			{
				if(data[0] == 4)
				{
					can_ParkPlace_Type = 1;
				}
				else
				{
					can_ParkPlace_Type = data[0];
				}
				SocParkTypeSendStatus = TRUE;
			}
			else
			{
				SocParkTypeSendStatus = FALSE;
			}
			g_APA_park_fusion_type = data[1];
		break;
		
		case CPU_NOTIFY_M3_APA_PARKPLACE: // 0x44D0
			SocPositionSendStatus = TRUE;
            
			ParkPlace_X_1 = (((data[0]&0x00FF)<<8) + (data[1]&0xFF));
			ParkPlace_Y_1 = (((data[2]&0x00FF)<<8) + (data[3]&0xFF));
			ParkPlace_X_2 = (((data[4]&0x00FF)<<8) + (data[5]&0xFF));
			ParkPlace_Y_2 = (((data[6]&0x00FF)<<8) + (data[7]&0xFF));
            
			ParkPlace_X_3 = (((data[8]&0x00FF)<<8) + (data[9]&0xFF));
			ParkPlace_Y_3 = (((data[10]&0x00FF)<<8) + (data[11]&0xFF));
			ParkPlace_X_4 = (((data[12]&0x00FF)<<8) + (data[13]&0xFF));
			ParkPlace_Y_4 = (((data[14]&0x00FF)<<8) + (data[15]&0xFF));
            
			can_ParkPlace_X_1 = (float)(ParkPlace_X_1);
			can_ParkPlace_Y_1 = (float)(ParkPlace_Y_1);
			can_ParkPlace_X_2 = (float)(ParkPlace_X_2);
			can_ParkPlace_Y_2 = (float)(ParkPlace_Y_2);
            
			can_ParkPlace_X_3 = (float)(ParkPlace_X_3);
			can_ParkPlace_Y_3 = (float)(ParkPlace_Y_3);
			can_ParkPlace_X_4 = (float)(ParkPlace_X_4);
			can_ParkPlace_Y_4 = (float)(ParkPlace_Y_4);
		break;
		
		case SOC_NOTIFY_RADIO_APA_PARKPLACE_INFO: // 0x44D5			
			if(can_ParkPlace_Type == 0x1 || can_ParkPlace_Type == 0x3)	// PERPENDICULAR || OBLIQUE
			{
				apa_reloat_place_info.L_Valid = data[0];
				apa_reloat_place_info.R_Valid = data[1];
				
				if(data[0] != 0)
				{
					if(data[2]&0x80)
					{
						apa_reloat_place_info.ThetaL = (((data[2]&0x007F)<<8)+(data[3]&0xFF))*(-1);
					}
					else
					{
						apa_reloat_place_info.ThetaL = (((data[2]&0x00FF)<<8) + (data[3]&0xFF));
					}
					apa_reloat_place_info.DistL = (((data[6]&0x00FF)<<8) + (data[7]&0xFF));
				}
				else
				{
					apa_reloat_place_info.DistL = 0;
					apa_reloat_place_info.ThetaL = 0;
				}
				
				if(data[1] != 0)
				{
					if(data[4]&0x80)
					{
						apa_reloat_place_info.ThetaR =(((data[4]&0x007F)<<8) + (data[5]&0xFF))*(-1);
					}
					else
					{
						apa_reloat_place_info.ThetaR = (((data[4]&0x00FF)<<8) + (data[5]&0xFF));
					}
					apa_reloat_place_info.DistR = (((data[8]&0x00FF)<<8) + (data[9]&0xFF));
				}
				else
				{
					apa_reloat_place_info.DistR = 0;
					apa_reloat_place_info.ThetaR = 0;
				}	
			}
			else if(can_ParkPlace_Type == 0x2)		//PARALLEL
			{
				apa_reloat_place_info.L_Valid = data[10];
				apa_reloat_place_info.R_Valid = data[11];
				
				if(data[10] != 0)	//Top
				{
					if(data[12]&0x80)
					{
						apa_reloat_place_info.ThetaL = (((data[12]&0x007F)<<8)+(data[13]&0xFF))*(-1);
					}
					else
					{
						apa_reloat_place_info.ThetaL = (((data[12]&0x00FF)<<8) + (data[13]&0xFF));
					}
					apa_reloat_place_info.DistL = (((data[16]&0x00FF)<<8) + (data[17]&0xFF));
				}
				else
				{
					apa_reloat_place_info.DistL = 0;
					apa_reloat_place_info.ThetaL = 0;
				}

				if(data[11] != 0)	//Down
				{
					if(data[14]&0x80)
					{
						apa_reloat_place_info.ThetaL = (((data[14]&0x007F)<<8)+(data[15]&0xFF))*(-1);
					}
					else
					{
						apa_reloat_place_info.ThetaL = (((data[14]&0x00FF)<<8) + (data[15]&0xFF));
					}
					apa_reloat_place_info.DistL = (((data[18]&0x00FF)<<8) + (data[19]&0xFF));
				}
				else
				{
					apa_reloat_place_info.DistL = 0;
					apa_reloat_place_info.ThetaL = 0;
				}
			}
		break;

		case SOC_NOTIFY_RADIO_DOWN_SLOT_SOD_PARKPLACE_INFO: //44D8
			Down_Slot_SOD = data[0];
		break;

		case SOC_NOTIFY_PARK_SLOT_HAVE_FOUND:
			APA_FoundSlotBuzzerTip = data[0];
		break;
        
		case SOC_NOTIFY_APA_FACING_SPACE:
			Facing_Space = (((data[0]&0x00FF)<<8) + (data[1]&0xFF))*0.001;//mm->m
		break;	
					
		default:
		break;
	}
}

float32 get_ParkPlace_X_1(void)
{
	return can_ParkPlace_X_1;
}
float32 get_ParkPlace_Y_1(void)
{
	return can_ParkPlace_Y_1;
}
float32 get_ParkPlace_X_2(void)
{
	return can_ParkPlace_X_2;
}
float32 get_ParkPlace_Y_2(void)
{
	return can_ParkPlace_Y_2;
}
float32 get_ParkPlace_X_3(void)
{
	return can_ParkPlace_X_3;
}
float32 get_ParkPlace_Y_3(void)
{
	return can_ParkPlace_Y_3;
}

float32 get_ParkPlace_X_4(void)
{
	return can_ParkPlace_X_4;
}
float32 get_ParkPlace_Y_4(void)
{
	return can_ParkPlace_Y_4;
}

U8 get_ParkPlace_Type(void)
{
    return can_ParkPlace_Type;
}

BOOL aps_receive_camera_fault(void)
{
	return Camera_Status;
}

int Get_SOC_Slot_Direction(void)
{
	static int direction = SOC_Slot_Direction_None;
	if (GetAPSCurrentStatus() >= APS_PARKING_SEARCH_PARKIN)
	{
		if(can_ParkPlace_X_1 > 0 && can_ParkPlace_X_2 > 0
		&& can_ParkPlace_X_3 > 0 && can_ParkPlace_X_4 > 0)
		{
			direction = SOC_Slot_Direction_Right;
		}
		else if(can_ParkPlace_X_1 < 0 && can_ParkPlace_X_2 < 0
		&& can_ParkPlace_X_3 < 0 && can_ParkPlace_X_4 < 0 )
		{
			direction = SOC_Slot_Direction_Left;
		}
		else
		{
			direction = SOC_Slot_Direction_None;
		}
	}
	else 
	{
		direction = SOC_Slot_Direction_None;
	}
	return direction;
	}

U8 GetDownSlotSODStatus(void)
{
	return Down_Slot_SOD;
}
void ClearDownSlotStatus(void)
{
	Down_Slot_SOD = 0;
}
U8 GetFacing_Space(void)
{
	return Facing_Space;
}
void ClearFacing_Space(void)
{
	Facing_Space = 0;
}


/****************************************************************************
*  Name		: GetSocCurrentAPSStatus
*  Description	: 
*  Parameter	: None
*  Returns	: APS_MODULE_STATUS
****************************************************************************/
APS_MODULE_STATUS GetSocCurrentAPSStatus(void)
{
	return SocCurrentParkingStatus;
}


/****************************************************************************
*  Name		: GetAPASlotType
*  Description	: 
*  Parameter	: None
*  Returns	: ParkingPlace_Info_Type
****************************************************************************/
U8 GetAPASlotType(void)
{
	return g_APA_park_fusion_type;
}

/****************************************************************************
*  Name		: get_ESC_Standstill_status
*  Description	: 
*  Parameter	: None
*  Returns	: U8
****************************************************************************/
U8 get_ESC_Standstill_status(void)
{
	VehMoveState esc_standstill_status = Standstill;
    if(can_receive_sig(DrivingDirection) == Stop)
	{
		esc_standstill_status = Standstill;
    }
    else if(can_receive_sig(DrivingDirection) == Forward || can_receive_sig(DrivingDirection) == Backward)
    {
        esc_standstill_status = Moving;
    }
	return esc_standstill_status;
}


extern BOOL bReqToSendVehicleStandsitllSts;
void apscan_ESC_Standstill_status(void)
{
	static U8 esc_standstill_status_backup=Vstatemax;
	if(esc_standstill_status_backup != get_ESC_Standstill_status() || bReqToSendVehicleStandsitllSts == TRUE)
	{
		esc_standstill_status_backup = get_ESC_Standstill_status();
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_SEND_APA_CAR_STANDSTILL_STATUS,1,&esc_standstill_status_backup);
		bReqToSendVehicleStandsitllSts = FALSE;
	}
}

/****************************************************************************
*  Name 	:USS_FAIL
*  Description	: This function is used for Detect USS_FAIL
*  Parameter	: None
*  Returns		: BOOL
****************************************************************************/
BOOL USS_FAIL(void)
{
	BOOL USS_FAIL_Flag = FALSE;
	U8 i_uss;
	
	for (i_uss = 0; i_uss< 12; i_uss++)
	{
		if(USSFailureStatus_Info_called[i_uss].allStatus!=0)
		{
			USS_FAIL_Flag = TRUE;
		}
	}
	return 	USS_FAIL_Flag;
}

