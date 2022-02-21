#ifndef _INPUT_SIGNAL_PROC_H_
#define _INPUT_SIGNAL_PROC_H_

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"

typedef enum
{

	APAWheelPlsCntrLeftDrvIndex = 0,
	APAWheelPlsCntrRightDrvIndex,
	APAWheelPlsCntrLeftNonDrvIndex,
	APAWheelPlsCntrRightNonDrvIndex

} InputSignalWheelIndex_Enum;

typedef enum
{
	CANSignalAcqSuccess = 0,
	CANSignalAcqFailur
}CANSignalAcqState;

typedef enum
{
	SlotSearchingSwitchFailur = 0,
	SlotSearchingSwitchStandby,
	SlotSearchingSwitchTurnOn,
	SlotSearchingSwitchTurnOff
}SlotSearchingFunctionState;

#define APA_SUPPORT_WHEEL_PLUSE_COUNTER_NUM			   	 4
#define APA_SUPPORT_WHEEL_PLUSE_COUNTER_MASK			 0x0f

#define TEMPERATURE_DEFAULT     25

extern word wObjBeingDtdTimeSave[SNS_INPUT_CAPTURE_CHANNEL_NUM][SNS_SUPPORT_MAX_DT_OBJ_NUM];
extern unsigned short wInputSignal_DisCoefficient;

typedef struct
{
  unsigned short InputSignal_LeftDrvWheelPulseCnt;
  unsigned short InputSignal_RightDrvWheelPulseCnt;
  unsigned short InputSignal_LeftNonDrvWheelPulseCnt;
  unsigned short InputSignal_RightNonDrvWheelPulseCnt;
  signed short  InputSignal_SteeringWheelAngle;
  unsigned char InputSignal_OutAirTemperature;
  unsigned char InputSignal_GeerPosision;
  unsigned char InputSignal_OriGeerPosision;
  unsigned char InputSignal_GeerPosisionValidFalg;
  unsigned char InputSignal_VehicleSpeedValidFlag;
  float InputSignal_VehicleSpeed;
  float InputSignal_WhlGrndVlctyLftNnDrvn;
  float InputSignal_WhlGrndVlctyRtNnDrvn;
  unsigned char InputSignal_TrnSwAct;
  unsigned char InputSignal_WhlPlsPerRevDrvn;
  unsigned char InputSignal_WhlPlsPerRevNonDrvn;
  unsigned char InputSignal_EcuWorkingMode;

} USS_CAN_DATA_Type,*USS_CAN_DATA_Handle;




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
unsigned short InputSignal_GetWheelPulseCnt(unsigned short index );


/*****************************************************************************
** Function:    InputSignal_GetSteerWheelAngle()
** Description: This function provide the steer wheel angle
** Parameter:   none
** Return:      steer wheel angle
**              
******************************************************************************/
signed short InputSignal_GetSteerWheelAngle(void);

/*****************************************************************************
** Function:    InputSignal_GetAirTemperature()
** Description: This function provide the environment temperature
** Parameter:   none
** Return:      Air temperature
**              
******************************************************************************/
signed char  InputSignal_GetAirTemperature(void);

/*****************************************************************************
** Function:	InputSignal_TrnSwAct()
** Description: This function provide left or right turnning indicator
** Parameter:	none
** Return:		Left or right indicator
**				
******************************************************************************/
unsigned char InputSignal_TrnSwAct(void);

/*****************************************************************************
** Function:	InputSignal_WhlPlsPerRevDrvn()
** Description: This function provide the pulse counter per wheel circle of drive wheel
** Parameter:	none
** Return:		
**				
******************************************************************************/
unsigned char InputSignal_WhlPlsPerRevDrvn(void);

/*****************************************************************************
** Function:	InputSignal_WhlPlsPerRevDrvn()
** Description: This function provide the pulse counter per wheel circle of non drive wheel
** Parameter:	none
** Return:		
**				
******************************************************************************/
unsigned char InputSignal_WhlPlsPerRevNonDrvn(void);

/*****************************************************************************
** Function:    InputSignal_GetGeerPositionValidFlag()
** Description: This function provide if the geer positon signal is valid or not
** Parameter:   none
** Return:      FLASE - invalid
**              TRUE  - Valid 
**              
******************************************************************************/
unsigned char InputSignal_GetGeerPositionValidFlag(void);

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
unsigned char InputSignal_GetGeerPosition(void);

/*****************************************************************************
** Function:    InputSignal_GetGeerPosition()
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
unsigned char InputSignal_GetOriGeerPosition(void);

/*****************************************************************************
** Function:    InputSignal_GetVehicleSpeedValidFlag()
** Description: This function provide if the vehicle speed signal is valid or not
** Parameter:   none
** Return:      FLASE - invalid
**              TRUE  - Valid 
**              
******************************************************************************/
unsigned char InputSignal_GetVehicleSpeedValidFlag(void);

/*****************************************************************************
** Function:    InputSignal_GetVehicleSpeed()
** Description: This function provide the vehicle speed 
** Parameter:   none
** Return:      Unit: km/h
**              
******************************************************************************/
float InputSignal_GetVehicleSpeed(void);

/*****************************************************************************
** Function:    InputSignal_GetWhlGrndVlctyLftNnDrvn()
** Description: This function provide the wheel speed of left non-drive wheel
** Parameter:   none
** Return:      Unit: m/s
**              
******************************************************************************/
float InputSignal_GetWhlGrndVlctyLftNnDrvn(void);

/*****************************************************************************
** Function:    InputSignal_GetWhlGrndVlctyRtNnDrvn()
** Description: This function provide the wheel speed of right non-drive wheel
** Parameter:   none
** Return:      Unit: m/s
**              
******************************************************************************/
float InputSignal_GetWhlGrndVlctyRtNnDrvn(void);

/*****************************************************************************
** Function:    InputSignal_GetEcuWokingMode()
** Description: This ECU working mode, slotsearching or not
** Parameter:   none
** Return:      0: other mode 				1: searching mode 
**              
******************************************************************************/
unsigned char InputSignal_GetEcuWokingMode(void);


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
uchar SaveObjBeingDtdTime(word  beingDtdTime,uchar cChannelIndex, uchar cArrayIndex);

void TaskIsrLockSchedule(void);
void TaskIsrUnLockSchedule(void);

/*Inline funciton Define End*/

#endif
