
#include "SlotParaCfg.h"

#include "InputSignalProc.h"

#include "InputSignalProc.h"
#include "Com_pub.h"

#include "RadarCanSignalMgr.h"
#include "OSAPI.h"

#define INPUTSIGNAL_CE_WhlGrndVlcty_FACTOR_UNIT						(0.03125 / 3.6) // unit: m/s.


extern uchar  cTemperatureZone;
extern uchar  cPrevTemperatureZone;
uchar DtObjGetTemperatureZoneToInitSensor(schar cAirTemperature, uchar cPreviousTempZone); 


APA_CAR_POS_WHEEL_PULSE_CNT_TYPE   wInputSignal_WheelPulseCnt[APA_SUPPORT_WHEEL_PLUSE_COUNTER_NUM];

signed char cInputSignal_OutAirTemperature;
unsigned char cInputSignal_GeerPosision;
unsigned char cInputSignal_OriGeerPosision;
unsigned char cInputSignal_GeerPosisionValidFalg;
unsigned char cInputSignal_VehicleSpeedValidFlag;
unsigned char cInputSignal_TrnSwAct;
unsigned char cInputSignal_WhlPlsPerRevDrvn;
unsigned char cInputSignal_WhlPlsPerRevNonDrvn;

float wInputSignal_VehicleSpeed;
float fInputSignal_WhlGrndVlctyLftNnDrvn;
float fInputSignal_WhlGrndVlctyRtNnDrvn;
unsigned short wInputSignal_DisCoefficient;
signed short wInputSignal_SteeringWheelAngle;
unsigned char cInputSignal_EcuWorkingMode;

word wObjBeingDtdTimeSave[SNS_INPUT_CAPTURE_CHANNEL_NUM][SNS_SUPPORT_MAX_DT_OBJ_NUM];
tSnsSaveUpaTxRxDisInfo  SnsSaveUpaTxRxDisInfo;

/*****************local define***********/
#define VEHICEL_TYPE_ANGKEWEI 0x01

/*****************local function*********/
BOOLEAN cInputSignal_XcpOutsideTempEnable = FALSE;
float fInputSignal_XcpOutsideTemp = 0;
SlotSearchingFunctionState SlotSearchingFuctionSwitch = SlotSearchingSwitchFailur;


void InputSignal_ProcessInit(void)
{
	unsigned char cTempt;

    for(cTempt = 0;cTempt < APA_SUPPORT_WHEEL_PLUSE_COUNTER_NUM;cTempt++)
    {
    	wInputSignal_WheelPulseCnt[cTempt] = 0;
    }

	wInputSignal_DisCoefficient = DISTANCE_COEFFICIENT;
	cInputSignal_OutAirTemperature = TEMPERATURE_DEFAULT;
	wInputSignal_SteeringWheelAngle = 0;
	cInputSignal_GeerPosision = 0;
	cInputSignal_GeerPosisionValidFalg = 0;

}

void InputSignal_ProcessMain_T10(void)
{

	USS_CAN_DATA_Type Can_data;
	float fRealTemp;
	unsigned long dwTemp1;
	unsigned char cTemp;

	//USS_Get_CAN_Data(&Can_data);
	if (USS_Get_CAN_Data(&Can_data) == CANSignalAcqSuccess)
	{
		wInputSignal_WheelPulseCnt[APAWheelPlsCntrLeftDrvIndex] = Can_data.InputSignal_LeftDrvWheelPulseCnt;
		wInputSignal_WheelPulseCnt[APAWheelPlsCntrRightDrvIndex] = Can_data.InputSignal_RightDrvWheelPulseCnt;
		wInputSignal_WheelPulseCnt[APAWheelPlsCntrLeftNonDrvIndex] = Can_data.InputSignal_LeftNonDrvWheelPulseCnt;
		wInputSignal_WheelPulseCnt[APAWheelPlsCntrRightNonDrvIndex] = Can_data.InputSignal_RightNonDrvWheelPulseCnt;
		wInputSignal_SteeringWheelAngle = Can_data.InputSignal_SteeringWheelAngle;
		cInputSignal_TrnSwAct = Can_data.InputSignal_TrnSwAct;
		cInputSignal_OutAirTemperature = Can_data.InputSignal_OutAirTemperature;
		cInputSignal_WhlPlsPerRevDrvn = Can_data.InputSignal_WhlPlsPerRevDrvn;
		cInputSignal_WhlPlsPerRevNonDrvn = Can_data.InputSignal_WhlPlsPerRevNonDrvn;
		cInputSignal_GeerPosisionValidFalg = Can_data.InputSignal_GeerPosisionValidFalg;
		cInputSignal_GeerPosision = Can_data.InputSignal_GeerPosision;
		cInputSignal_OriGeerPosision = Can_data.InputSignal_OriGeerPosision;
		cInputSignal_VehicleSpeedValidFlag = Can_data.InputSignal_VehicleSpeedValidFlag;
		wInputSignal_VehicleSpeed = Can_data.InputSignal_VehicleSpeed;
		fInputSignal_WhlGrndVlctyLftNnDrvn = Can_data.InputSignal_WhlGrndVlctyLftNnDrvn;
		fInputSignal_WhlGrndVlctyRtNnDrvn = Can_data.InputSignal_WhlGrndVlctyRtNnDrvn;
		cInputSignal_EcuWorkingMode = Can_data.InputSignal_EcuWorkingMode;
		if(cInputSignal_XcpOutsideTempEnable)
		{
			fRealTemp = fInputSignal_XcpOutsideTemp;
		}
		else
		{
			fRealTemp = cInputSignal_OutAirTemperature;
		}

		//dwTemp1 = (SOUND_SPEED_AT_NEGATIVE_40_DEGREE + TEMPERATURE_COEFFICIENT_FOR_SOUND_SPEED *(2*fRealTemp+80)) / SOUND_SPEED_UNIT_FACTOR;
		//wInputSignal_DisCoefficient = (word)(dwTemp1);
	}else
	{

	}

}

void SlotSearchingFunctionStateMachine(void)
{
	switch(SlotSearchingFuctionSwitch)
	{
        case SlotSearchingSwitchFailur:
			 if(cInputSignal_GeerPosision == APAGearPositionR)
			 {
				SlotSearchingFuctionSwitch = SlotSearchingSwitchStandby;
			 }
			 break;
		case SlotSearchingSwitchStandby:
			if(cInputSignal_GeerPosision == APAGearPositionD)
			{
				SlotSearchingFuctionSwitch = SlotSearchingSwitchTurnOn;
			}
			break;
		case SlotSearchingSwitchTurnOn:
             {

				 SlotSearchingFuctionSwitch = SlotSearchingSwitchTurnOff;
		     }
			break;
		case SlotSearchingSwitchTurnOff:
			if((cInputSignal_GeerPosision != APAGearPositionN)
				&& (cInputSignal_GeerPosision != APAGearPositionD))
			{

				SlotSearchingFuctionSwitch = SlotSearchingSwitchFailur;
			}
			break;
		default:
			break;
	}

}


/*Inline funciton Define Start*/

/*****************************************************************************
** Function:    InputSignal_GetWheelPulseCnt()
** Description: This function receive the wheel pulse counter
** Parameter:   unsigned short index:
                APAWheelPlsCntrLeftDrvIndex = 0,
				APAWheelPlsCntrRightDrvIndex,
				APAWheelPlsCntrLeftNonDrvIndex,
				APAWheelPlsCntrRightNonDrvIndex
** Return:      pulse counter
**
******************************************************************************/
unsigned short InputSignal_GetWheelPulseCnt(unsigned short index )
{
    if(index < APA_SUPPORT_WHEEL_PLUSE_COUNTER_NUM)
    {
        return wInputSignal_WheelPulseCnt[index];
    }else
    {
        return 0;
	}
}


/*****************************************************************************
** Function:    InputSignal_GetSteerWheelAngle()
** Description: This function provide the steer wheel angle
** Parameter:   none
** Return:      steer wheel angle
**
******************************************************************************/
signed short InputSignal_GetSteerWheelAngle(void)
{
    return wInputSignal_SteeringWheelAngle;
}

/*****************************************************************************
** Function:    InputSignal_GetAirTemperature()
** Description: This function provide the environment temperature
** Parameter:   none
** Return:      Air temperature
**
******************************************************************************/
signed char InputSignal_GetAirTemperature(void)
{
    return cInputSignal_OutAirTemperature;
}

/*****************************************************************************
** Function:	InputSignal_TrnSwAct()
** Description: This function provide left or right turnning indicator
** Parameter:	none
** Return:		Left or right indicator
**				
******************************************************************************/
unsigned char InputSignal_TrnSwAct(void)
{
	return cInputSignal_TrnSwAct;
}

/*****************************************************************************
** Function:	InputSignal_WhlPlsPerRevDrvn()
** Description: This function provide the pulse counter per wheel circle of drive wheel
** Parameter:	none
** Return:		
**				
******************************************************************************/
unsigned char InputSignal_WhlPlsPerRevDrvn(void)
{
	return cInputSignal_WhlPlsPerRevDrvn;
}

/*****************************************************************************
** Function:	InputSignal_WhlPlsPerRevDrvn()
** Description: This function provide the pulse counter per wheel circle of non drive wheel
** Parameter:	none
** Return:		
**				
******************************************************************************/
unsigned char InputSignal_WhlPlsPerRevNonDrvn(void)
{
	return cInputSignal_WhlPlsPerRevNonDrvn;
}


/*****************************************************************************
** Function:    InputSignal_GetGeerPositionValidFlag()
** Description: This function provide if the geer positon signal is valid or not
** Parameter:   none
** Return:      FLASE - invalid
**              TRUE  - Valid 
**              
******************************************************************************/
unsigned char InputSignal_GetGeerPositionValidFlag(void)
{
    return cInputSignal_GeerPosisionValidFalg;
}

/*****************************************************************************
** Function:    InputSignal_GetGeerPosition()
** Description: This function provide the geer positon signal 
** Parameter:   none
** Return:      GeerPositon
                typedef enum{
            	APAGearPositionP = 0,
            	APAGearPositionN,
            	APAGearPositionD,
            	APAGearPositionR
	
                             } 

**              
******************************************************************************/
unsigned char InputSignal_GetGeerPosition(void)
{
    return cInputSignal_GeerPosision;
}

/*****************************************************************************
** Function:    InputSignal_GetOriGeerPosition()
** Description: This function provide the geer positon signal 
** Parameter:   none
** Return:      GeerPositon
                #define kTrnsShftLvrPos_1_Forward_Range_H    11
                #define kTrnsShftLvrPos_1_Forward_Range_G    10
                #define kTrnsShftLvrPos_1_Forward_Range_F    9
                #define kTrnsShftLvrPos_1_Forward_Range_E    8
                #define kTrnsShftLvrPos_1_Forward_Range_D    7
                #define kTrnsShftLvrPos_1_Forward_Range_C    6
                #define kTrnsShftLvrPos_1_Forward_Range_B    5
                #define kTrnsShftLvrPos_1_Forward_Range_A    4
                #define kTrnsShftLvrPos_1_Neutral_Range      3
                #define kTrnsShftLvrPos_1_Reverse_Range      2
                #define kTrnsShftLvrPos_1_Park_Range         1
                #define kTrnsShftLvrPos_1_Between_Ranges     0

**              
******************************************************************************/
unsigned char InputSignal_GetOriGeerPosition(void)
{
    return cInputSignal_OriGeerPosision;
}


/*****************************************************************************
** Function:    InputSignal_GetVehicleSpeedValidFlag()
** Description: This function provide if the vehicle speed signal is valid or not
** Parameter:   none
** Return:      FLASE - invalid
**              TRUE  - Valid 
**              
******************************************************************************/
unsigned char InputSignal_GetVehicleSpeedValidFlag(void)
{
    return cInputSignal_VehicleSpeedValidFlag;
}

/*****************************************************************************
** Function:    InputSignal_GetVehicleSpeed()
** Description: This function provide the vehicle speed 
** Parameter:   none
** Return:      Unit: km/h
**              
******************************************************************************/
float InputSignal_GetVehicleSpeed(void)
{
    return wInputSignal_VehicleSpeed;
}


/*****************************************************************************
** Function:    InputSignal_GetWhlGrndVlctyLftNnDrvn()
** Description: This function provide the wheel speed of left non-drive wheel
** Parameter:   none
** Return:      Unit: m/s
**              
******************************************************************************/
float InputSignal_GetWhlGrndVlctyLftNnDrvn(void)
{
    return fInputSignal_WhlGrndVlctyLftNnDrvn;
}

/*****************************************************************************
** Function:    InputSignal_GetWhlGrndVlctyRtNnDrvn()
** Description: This function provide the wheel speed of right non-drive wheel
** Parameter:   none
** Return:      Unit: m/s
**              
******************************************************************************/
float InputSignal_GetWhlGrndVlctyRtNnDrvn(void)
{
    return fInputSignal_WhlGrndVlctyRtNnDrvn;
}

/*****************************************************************************
** Function:    InputSignal_GetEcuWokingMode()
** Description: This ECU working mode, slotsearching or not
** Parameter:   none
** Return:      Unit: 
**              
******************************************************************************/
unsigned char InputSignal_GetEcuWokingMode(void)
{
    return cInputSignal_EcuWorkingMode;
}


/*Inline funciton Define End*/
/******************************************************************************
** Function:    uchar SaveObjBeingDtdTime(word  beingDtdTime,uchar cChannelIndex, uchar cArrayIndex)
** Description:  save Echo backwave Time
**  cChannelIndex value define as follows,each channel could save five Echo backwave Time
**  RRS_SNS_INDEX = 0,0
** RR_SNS_INDEX,  1
** RRM_SNS_INDEX, 2
** RLM_SNS_INDEX, 3
** RL_SNS_INDEX,  4
** RLS_SNS_INDEX, 5
** FRS_SNS_INDEX, 6
** FR_SNS_INDEX,  7
** FRM_SNS_INDEX, 8
** FLM_SNS_INDEX, 9
** FL_SNS_INDEX,  10
** FLS_SNS_INDEX  11
** Parameter:   None
** Return:      
*-History--------------------------------------------------------------
* Version       Date         Name            Changes and comments
------------------------------------------------------------------------
*  0.1          2018.11.26     Hechunhong     Init version.
------------------------------------------------------------------------
******************************************************************************/
uchar SaveObjBeingDtdTime(word  beingDtdTime,uchar cChannelIndex, uchar cArrayIndex)
{
	UINT8 ret = 0;
	wObjBeingDtdTimeSave[cChannelIndex][cArrayIndex] = beingDtdTime;
	return ret;
}

/*****************************************************************************
** Function:    TaskIsrLockSchedule()
** Description: TaskIsrLockSchedule
** Parameter:   none
** Return:      None
******************************************************************************/
void TaskIsrLockSchedule(void)
{
	OSAPI_LockSchedule();
}

/*****************************************************************************
** Function:    TaskIsrLockSchedule()
** Description: TaskIsrLockSchedule
** Parameter:   none
** Return:     none
******************************************************************************/
void TaskIsrUnLockSchedule(void)
{
	OSAPI_UnlockSchedule();
}

/*Inline funciton Define End*/


