/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				                   *
*				  All Rights Reserved.          					                          *
*   Department   	: CT AD     									   		     *
*   AUTHOR	    	: 									                                 *
************************************************************************
* Object            	:
* Module           	:
* Instance         	:
* Description      	:
*-----------------------------------------------------------------------
* Version			:
* Date			:
* Author			:
***********************************************************************/
/*-History---------------------------------------------------------------
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
*
*======================================================*/
#if !defined(_SLOT_PARA_CFG_H_)
#define _SLOT_PARA_CFG_H_

#include "ObjDetectCommonDefine.h"
#include "ObjDetectStateMachine.h"
#include "DataTypeDef.h"
//#include "ApaStateMachine.h"
#include "math.h"

#define PI																					3.1415926535897932384626
#define MATH_FABS																			fabsf
#define MATH_COS																			cosf
#define MATH_SIN																			sinf
#define MATH_TAN																			tanf
#define MATH_SQRT																			sqrtf
#define MATH_ATAN																			atanf
#define MATH_ASIN																			asinf
#define MATH_ACOS																			acosf

#define APA_SUPPORT_APA_SNS_NUM															12
#define APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE										25 // 1s, 1000 / 40ms
#define APA_SUPPORT_MAX_APA_DISABLE_CAUSES_BUF_SIZE									6
#define APA_SUPPORT_MAX_APA_FAILED_CAUSES_BUF_SIZE									7
#define APA_SIDE_SENSOR_NUM																4

#define MAX_TIRE_SIZE_NUM																	32
#define MAX_SUPPORT_TIRE_SIZE_NUM														20

#define MAXSHORT																			0x7fff
#define APA_SUPPORT_MAX_DISTANCE															MAXSHORT // mm
#define APA_DISTANCE_OVERFLOW															(APA_SUPPORT_MAX_DISTANCE - 500)
#define APA_SUPPORT_DEBUG_CAR_TRAVEL_DISTANCE
#define APA_SUPPORT_MAX_VEH_SPD_BUF_SIZE        											7 // 70ms, 70 / 10ms
#define APA_SUPPORT_ORIGINAL_STEP_DATA_NUM												4
#define APA_SUPPORT_MAX_CAR_TURNING_RADIUS												(1e5) // m. It is only used for float calcualtion.

#define APA_CAR_PARK_AT_LEFT_SIDE															0
#define APA_CAR_PARK_AT_RIGHT_SIDE														1

/*1.1************************************* COMMON MICRO-DEFINITION END ******************************************/

/*1.2******************************** SEARCHING SLOT MACRO-DEFINITION START *************************************/
#define APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM											50
#define APA_SLOT_SUPPORT_MAX_SLOT_NUM													3
#define APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM									4
#define APA_SLOT_SUPPORT_SEARCHING_SLOT_FRS_SENSOR_INDEX								0
#define APA_SLOT_SUPPORT_SEARCHING_SLOT_FLS_SENSOR_INDEX								1
#define APA_SLOT_SUPPORT_SLOT_BORDER_LINE_NUM											8	// 8 * 1m = 8m....
#define APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_DEVIDED_NUM							6

#define APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM										(20)
#define APA_SLOT_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE								(5)

#define APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS_REGARD_NO_OBJ1OR2				(SlotCaliCfg.APASlotMaxSlotLength) // mm
#define APA_SLOT_SENSOR_HFOV_MAX_DT_DIS													(5000)
#define APA_SLOT_SENSOR_HFOV_DIVIDED_SEG_DIS											(APA_SLOT_SENSOR_HFOV_MAX_DT_DIS / APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM)
#define APA_SLOT_NO_SLOT_DETECTED														(0)// mm


#define APA_TRAJCAL_CHECK_IF_CAR_IS_DRIVING_STRAIGHTLY(SteeringAng) \
	(MATH_FABS(SteeringAng) <= (SlotCaliCfg.APAParkProcCarDriveStraightlyMinSteeringWheelAng))


#define bAPASupportFunctionModeParallelParkingIn       										SlotCaliCfg._APASupportFunctionMode.Bits.BIT0
#define bAPASupportFunctionModePerpendicularlParkingIn   									SlotCaliCfg._APASupportFunctionMode.Bits.BIT1
#define bAPASupportFunctionModeAngularParkingIn             										SlotCaliCfg._APASupportFunctionMode.Bits.BIT2
#define bAPASupportFunctionModeParkingExit                											SlotCaliCfg._APASupportFunctionMode.Bits.BIT3
#define APA_SUPPORT_FUNC_MODE_ParallelParkingIn											0x01
#define APA_SUPPORT_FUNC_MODE_PerpendicularlParkingIn									0x02

extern    tAPAWordBitType  _APACommonFlag0;
#define APACommonFlag0                          														_APACommonFlag0.Word
#define bAPARxSteeringWheelAngleDirection        												_APACommonFlag0.Bits.BIT0
#define bAPASteeringWheelCtrlTask_APAOperatingStateChanged									_APACommonFlag0.Bits.BIT1
#define bAPATrajectoryCalTaskActivated                  											_APACommonFlag0.Bits.BIT2
#define bAPASnsDtdObjDisInfoBufOverFlowed               											_APACommonFlag0.Bits.BIT3
#define bAPARequestReconnectEPS               													_APACommonFlag0.Bits.BIT4
#define bAPAVehicleIsStatic																	_APACommonFlag0.Bits.BIT7
#define bAPAIsActiveBeforeSpeedTooHigh														_APACommonFlag0.Bits.BIT8
#define bAPATrajGearPutIntoReverse															_APACommonFlag0.Bits.BIT10
#define bAPATrajGearPutIntoDrive																_APACommonFlag0.Bits.BIT11
#define bDriverTryToControlTheEPS															_APACommonFlag0.Bits.BIT12
#define bAPATrajCalCarParkAlongCurb															_APACommonFlag0.Bits.BIT14


/*1.3***************************** TRAJECTORY CALCULATE MACRO-DEFINITION END	*********************************/

/*1.4******************************* PARKING PROCESS MACRO-DEFINITION START	*************************************/
#define APA_PARKPROC_SUPPORT_MAX_SYS_DT_MIN_DIS_NUM									(1000 / 100) // 1s / 100ms
#define APA_PARKPROC_MAX_SUPPORT_PARKING_STEPS_NUM									15
#define APA_PARKPROC_MAX_SUPPORT_STORED_PARKING_STEPS_NUM							12
#define APA_PARKPROC_MAX_MS_TIME_VALUE													0xffff
#define APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ1									0
#define APA_PARKPROC_CAR_END_POSITION_CLOSE_TO_OBJ2									1
#define APA_PARKPROC_CAR_END_POSITION_MID_BETWEEN_OBJ1_AND_OBJ2 					2
#define APA_PARKPROC_CAR_CAN_DRV_MIN_DIS_TO_OBJ_BY_SNS_DTD_SCENARIO_NUM 			2
#define APA_PARKPROC_CAR_DRV_CIRCLE_SIDE_NUM											2

typedef enum {
	APA_RRS_SNS_INDEX = 0,
	APA_RR_SNS_INDEX,
	APA_RRM_SNS_INDEX,
	APA_RLM_SNS_INDEX,
	APA_RL_SNS_INDEX,
	APA_RLS_SNS_INDEX,
	APA_FRS_SNS_INDEX,
	APA_FR_SNS_INDEX,
	APA_FRM_SNS_INDEX,
	APA_FLM_SNS_INDEX,
	APA_FL_SNS_INDEX,
	APA_FLS_SNS_INDEX
} APASnsIndexType;

typedef enum {
	APAODIDispCmdType_NoMessage = 0,
	// APANotAvailable,
	APAODIDispCmdType_SearchingForParkingSlotRight,/******1*****/
	APAODIDispCmdType_EndPositionAchieved,/******2*****/
	APAODIDispCmdType_DriveBackward,/******3*****/
	APAODIDispCmdType_DriveForward,/******4*****/
	APAODIDispCmdType_APAStop,/******5*****/
	APAODIDispCmdType_LimitDriveSpeed,/******6*****/
	APAODIDispCmdType_APACancel,/******7*****/
	APAODIDispCmdType_ParkingFailedDoOver,/******8*****/
	APAODIDispCmdType_SearchingForParkingSlotLeft,/******9*****/
	APAODIDispCmdType_StopTightParking,/******10*****/
	APAODIDispCmdType_APASlotFoundRight,/******11*****/
	APAODIDispCmdType_APASlotFoundLeft,/******12*****/
	// For APA system
	APAODIDispCmdType_PutTheGearToReverse,/******13*****/
	APAODIDispCmdType_RequestControlEPS,/******14*****/
	APAODIDispCmdType_CarIsControlledByAPA,/******15*****/
	APAODIDispCmdType_PutTheGearToDrive,/******16*****/
	APAODIDispCmdType_APANotAvailableSteeringFailed,/******17*****////
	APAODIDispCmdType_VehicleAutoSteeringActivatedREABOff,/******18*****/
	APAODIDispCmdType_VehicleUnParkRight,/******19*****/
	APAODIDispCmdType_VehicleUnParkLeft,/******20*****/
	APAODIDispCmdType_APAStopEndPositionAchieved/******21*****/
}APAODIDispCmdType;


typedef enum {
	APA_FRS_SNS_DT_OBJ_DIS_INDEX = 0,
	APA_FLS_SNS_DT_OBJ_DIS_INDEX,
	APA_RRS_SNS_DT_OBJ_DIS_INDEX,
	APA_RLS_SNS_DT_OBJ_DIS_INDEX
} APASideSnsDtObjDisIndexType;

typedef enum {
	APA_FRC_SNS_DT_OBJ_DIS_INDEX = 0,
	APA_FLC_SNS_DT_OBJ_DIS_INDEX,
	APA_RRC_SNS_DT_OBJ_DIS_INDEX,
	APA_RLC_SNS_DT_OBJ_DIS_INDEX
} APACornerSnsDtObjDisIndexType;

typedef enum {
	APA_CAR_CORNER_FR_INDEX = 0,
	APA_CAR_CORNER_FL_INDEX,
	APA_CAR_CORNER_RL_INDEX,
	APA_CAR_CORNER_RR_INDEX
} tAPACarCornerIndexType;
/*
		FL +-----+ FR
		    |          |
		    |          |
		    |    +    |
		    |          |
		RL +-----+ RR
*/

typedef enum {
	 APA_RUNNING_STATE_DEACTIVATED = 0,
	 APA_RUNNING_STATE_SEARCHING_FOR_SLOT,
	 APA_RUNNING_STATE_SLOT_FOUND,
	 APA_RUNNING_STATE_PARKING_START_REQ_CONTROL_EPS,
	 APA_RUNNING_STATE_PARKING_START_EPS_CONTROL_CONNECTING,
	 APA_RUNNING_STATE_PARKING_STEPN,
	 APA_RUNNING_STATE_PARKING_END_POSITION_ACHIEVED,
	 APA_RUNNING_STATE_PARKING_FAIL
} tAPARunningStateDataType;

typedef enum {
	APACarParkingStepDataCheckSeqNoChecked = 0,
	APACarParkingStepDataCheckSeqCheckOK,
	APACarParkingStepDataCheckSeqCheckNG
} tAPACarParkingStepDataCheckSeqType;

typedef enum {
	APALineIsIncline = 0,
	APALineIsVertical,
	APALineIsHorizontal,
	APALineIsInvalidLineType
} APALineIsVerticalOrHorizontalType;

typedef enum {
	APA_SPEAKER_NO_SPEAKER = 0,
	APA_SPEAKER_TYPE_FRONT_MASK,
	APA_SPEAKER_TYPE_REAR_MASK
} tAPASpeakerType;

typedef short	APA_DISTANCE_TYPE;
typedef signed long APA_INT_TYPE;
typedef float	APA_SPEED_TYPE;
typedef unsigned short APA_SPEED_WORD_TYPE;
typedef float	APA_SPEED_CAL_FLOAT_TYPE;
typedef float APA_ANGLE_TYPE;
typedef unsigned short APA_MS_TIME_TYPE;
typedef short APA_TIMES_TYPE;

typedef float APA_S_TIME_CAL_FLOAT_TYPE;
typedef signed char APA_ENUM_TYPE;
typedef float APA_RATIO_TYPE;
typedef signed long APA_DISTANCE_CAL_INT_TYPE;
typedef float	APA_DISTANCE_CAL_FLOAT_TYPE;
typedef float	APA_ANGLE_CAL_FLOAT_TYPE;
typedef signed char APA_INDEX_TYPE;
typedef float APA_CAL_FLOAT_TYPE;
typedef int APA_CAL_INT_TYPE;
typedef unsigned char APA_SPEAKER_CHIME_DELAY_TIMER_TYPE;
typedef short APA_WEIGHT_COEFFICIENT_TYPE;
typedef word SIA_ERROR_FLAG_TYPE;
typedef word APA_CAR_POS_WHEEL_PULSE_CNT_TYPE;
typedef signed char APA_SLOT_ID_TYPE;



//        |<---------->|
/********PT1***********|        *PT3*****************/
/*		    	      *|        *
/				      *|        *
/				      PT2********

*/


/****************DIAG TRACE TEST******************/

typedef enum {
	APASlotMirrorReqType_IDLE = 0,
	APASlotMirrorReqType_REQ,
	APASlotMirrorReqType_PERMIT
}APASlotMirrorReqType;

#define APA_SLOT_SUPPORT_OBJ_TYPE_NUM						3
typedef enum {
  APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
  APA_SLOT_OBJ_TYPE_ROUND,
  APA_SLOT_OBJ_TYPE_SQUARE
} APASlotObjTypeType;

typedef enum {
	APA_SLOT_TYPE_INVALID = 0,
	APA_SLOT_TYPE_PARALLEL,
	APA_SLOT_TYPE_PERPENDICULAR,
	APA_SLOT_TYPE_ANGULAR
} tAPASlotType;

typedef enum {
	APA_SLOT_DT_FAILED_BY_NO_FAILURE = 0,
	APA_SLOT_DT_FAILED_BY_INVALID_FRONT_OBJECT,
	APA_SLOT_DT_FAILED_BY_SLOT_LENGTH_TOO_SMALL,
	APA_SLOT_DT_FAILED_BY_SIDE_OBJECT_TOO_CLOSE
} APASlotDetectFailCausesType;

/*1.2******************************** SEARCHING SLOT MACRO-DEFINITION END	*************************************/

/*1.3***************************** TRAJECTORY CALCULATE MACRO-DEFINITION START **********************************/


typedef enum {
	APATrajCalCmd_SetupSystemCoordinateAccordingToSlotData = 1,
	APATrajCalCmd_SlotFoundReCalSlot,
	APATrajCalCmd_InStepNSearchForAnotherTrajectory1,
	APATrajCalCmd_InStepNSearchForCorTrajectory1, // Cal correct to step 2 with one correct step only.
	APATrajCalCmd_InStepNSearchForCorTrajectory2
} APATrajCalCmdType;

typedef enum {
	APATrajCalStatus_IDLE = 0,
	APATrajCalStatus_REQUESTCAL,
	APATrajCalStatus_BUSY,
	APATrajCalStatus_CALFINISHED
}APATrajCalStatusType;

typedef enum {
	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngLess10degIndex = 0,
	APAParkProcPCarCanDrvMinDisToObjBySnsDtdAngGreat10degIndex
} tAPAParkProcPCarCanDrvFwMinDisToObjBySnsDtdScenarioIndexType;

typedef enum {
	APAParkProcPCarDrvCircleLeftIndex = 0,
	APAParkProcPCarDrvCircleRightIndex
} tAPAParkProcPCarDrvCircleSideIndexType;

typedef enum {
	APAParkProcPECarEndPosCarWillNotHitFrontCornerObj = 0,
	APAParkProcPECarEndPosParallelToFrontObj
} tAPAParkProcParkExitCarEndPosModeType;

typedef enum {
	APA_PARKPROC_PARKING_MODE_PARALLEL =	0,
	APA_PARKPROC_PARKING_MODE_PERPENDICULAR,
	APA_PARKPROC_PARKING_MODE_ANGULAR,
	APA_PARKPROC_PARKING_MODE_PARKEXIT
} tAPAParkProcParkingModeType;

typedef enum{
	APA_PARKPROC_PARKING_STEP_1_INDEX = 0,
	APA_PARKPROC_PARKING_STEP_2_INDEX,
	APA_PARKPROC_PARKING_STEP_3_INDEX,
	APA_PARKPROC_PARKING_STEP_4_INDEX,
	APA_PARKPROC_PARKING_STEP_5_INDEX,
	APA_PARKPROC_PARKING_STEP_6_INDEX,
	APA_PARKPROC_PARKING_STEP_7_INDEX,
	APA_PARKPROC_PARKING_STEP_8_INDEX,
	APA_PARKPROC_PARKING_STEP_9_INDEX,
	APA_PARKPROC_PARKING_STEP_10_INDEX,
	APA_PARKPROC_PARKING_STEP_11_INDEX,
	APA_PARKPROC_PARKING_STEP_12_INDEX,
	APA_PARKPROC_PARKING_STEP_BACK_UP_1_INDEX,
	APA_PARKPROC_PARKING_STEP_BACK_UP_2_INDEX,
	APA_PARKPROC_PARKING_STEP_BACK_UP_3_INDEX
} tAPAParkProcParkingStepIndexType;

typedef enum {
	APAParkProcSlotFoundTrajCalReqWithoutCaled = 0,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithoutObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithoutObj2MoreThanOneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPPerpendSlotWithObj2MoreThanOneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen1OkPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen1OkPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToMidOneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen2OkPkToMidMoreSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen3OkPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqPParalSlotLen3OkPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj1OneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj1MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj2OneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToObj2MoreSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToMidOneSlot,
	APAParkProcSlotFoundTrajCalReqParalSlotPkToMidMoreSlot

} tAPAParkProcSlotFoundTrajCalRequestType;


typedef enum{
	APAGearPositionP = 0,
	APAGearPositionN,
	APAGearPositionD,
	APAGearPositionR

} tAPAGearPositionType;





typedef union {
  byte CarMayHitObjCmdDisplayFlag;
  struct {
    byte CarMayHitRObjStopCmdShown       	:1; // Indicate when the car may hit the rear object and the stop command has been shown on the IPC.
    byte CarMayHitRObjStopCmdShownCarDrvDir	:1; // Indicate the car driving direction when the car may hit the rear object and the stop cmd has been shown on the IPC.
    byte CarMayHitFObjStopCmdShown       	:1;
    byte CarMayHitFObjStopCmdShownCarDrvDir	:1; // 0 - Drive backwards, 1 - Drive forwards.
    byte CarWillHitObjStopTheCarAndWaiting	:1;
  	byte CarMayHitObjStopCmdHasBeenShown	:1;
    byte Reserved        		 			:2;
  } Bits;
} tAPAParkProcCarMayHitObjCmdDisplayFlagType;


#define APA_CAR_MAY_WILL_HIT_OBJ_INDICATION_MASK				0x00ff

typedef union {
  word CarHitObjInd;
  struct {
    word CarWillHitFrontRCornerObj       	:1;
	word CarWillHitFrontMidObj				:1;
    word CarWillHitFrontLCornerObj       	:1;
    word CarWillHitFrontObj      			:1;
    word CarWillHitRearRCornerObj       	:1;
	word CarWillHitRearMidObj				:1;
    word CarWillHitRearLCornerObj       	:1;
    word CarWillHitRearObj       			:1;

  	word CarMayHitFrontObj					:1;
  	word CarMayHitRearObj					:1;
	word Reserved							:6;
  } Bits;
} tAPACarHitObjIndicationType;

typedef union {
	word APACalBooleanType;
	struct{
		word bAPARearTireIsNonDrivenWheel						:1;
		word bAPATrajCalAPSysYDirIsSameAsCarDirWithObj1Exist	:1;
		word bAPATrajCalPCarParkingAlongCurbIfCurbDetected		:1;
		word bAPATrajCalCarParkingAlongCurbIfCurbDetected		:1;
		word bAPAParkProcKeepCurrentSlotAndCarPosition			:1;
		word bAPAParkProcPEEPCanBeActivatedAtForward			:1;
		word bAPACarSupportLongitudinalAcceleration				:1;
		word bAPACarSupportWheelSpeedCANSignal					:1;
		word bAPASlotCorPCheckObjExistOrNot						:1;
		word bAPASlotCorPUseCornerSnsToCorrectSlotBorderLine	:1;
		word bAPASlotCorPSupportCorrectSlotBorderLine			:1;
		word bAPASlotCorPReDetermineEndPosSide					:1;
		word bAPASlotCorPParkParallelToObjIfEndPosIsCloseToObj	:1;
		word Reserved											:3;
	}Bits;
}tAPACalBooleanType;

typedef union{
	dword APACarParFlag1;
	struct{
		dword bAPADistanceOverFlow												:1;
		dword bAPATrajectoryCalResultChecked									:1;
		dword bAPAParkExitModeConfirmed											:1;
		dword bAPAParkModeChanged												:1;
		dword bAPAVehicleSpeedIsValid											:1;
		dword bCarIsDrivingBackwards											:1;
		dword bSlotDataIsMirrorChanged											:1;
		dword bCarPosCalWheelPlsCntrMissUpdatedFlagIsSet						:1;
		dword reserved															:1;
		dword bParkProcAPATrajCalDriveStraightlyFirstStep						:1;
		dword bParkProcAPATrajCalInSlotFirstStepAllowUseGivenTurningRadius		:1;
		dword bParkProcAPATrajCalUseTheCurSteeringAngToCal						:1;
		dword bParkProcAPATrajCalTargetDriveDirectionIsForward					:1;
		dword bParkProcCarIsInTheSlotCarEndPosCanBeAchievedWithCurSteeringAng	:1;
		dword bParkProcCarIsInTheSlotCarEndPosCanBeAchievedWithCurStepData		:1;
		dword bParkProcCarIsInTheSlotSteeringCtrlCorrected						:1;
		dword bParkProcLastStepSteeringWheelReturnToZero						:1;
		dword bParkProcLastStepSteeringWheelReqReturnToZero						:1;
		dword bParkProcCarIsInTheSlotCriteria1									:1;
		dword bParkProcParkingLimitSpeed										:1;
		dword bParkProcCurrentStepDriveDirectionForward							:1;
		dword bParkProcKeepCurrentSlotAndCarPosition							:1;
		dword bParkProcDriveDirectionChange										:1;
		dword bParkProcRecalculatingTrajectory									:1;
		dword bParkProcCurrentCarOnCalTrajectory								:1;
		dword bParkProcSteeringWheelIsTurning									:1;
		dword bParkProcCarEndPosAngleAchieved									:1;
		dword bParkProcSaveParkingParIntoEEPROM									:1;
		dword bParkProcSaveMaxParkVehilceSpeedIntoEEPROM						:1;
		dword bParkProcSlotFoundReqReSetUpSystemCoordinate						:1;
		dword bSlotProcSlotObj2Exist											:1;
		dword bSlotProcSlotObj1Exist											:1;
	}Bits;
}tAPACarParFlag1Type;

typedef union{
	byte APACarParFlag2;
	struct{
		byte bParkProcAPATrajCalNextTargetDriveDirectionIsForward				:1;
		byte bParkProcAPATrajCalInslotLastStepInhibitUseCorStep					:1;
		byte bParkProcAPATrajCalInslotLastStepUseCorStepCalculated				:1;
		byte bParkProcPrevDesiredDrvDirIsFw										:1;
		byte bAPACalCarPosBiDirWhlSpeSnsSignalInvalid							:1;
		byte Reserved															:3;
	}Bits;
}tAPACarParFlag2Type;


typedef struct {
	APA_DISTANCE_TYPE x;
	APA_DISTANCE_TYPE y;
} APACoordinateDataType;

typedef struct {
	APA_DISTANCE_CAL_FLOAT_TYPE x;
	APA_DISTANCE_CAL_FLOAT_TYPE y;
} APACoordinateDataCalFloatType;

typedef struct {
	APACoordinateDataCalFloatType LeftTop;
	APACoordinateDataCalFloatType RightTop;
	APACoordinateDataCalFloatType LeftBottom;
	APACoordinateDataCalFloatType RightBottom;
} APARectCoordinateDataCalFloatType;     //APA 轨迹用到的结构体

typedef struct {

	// Line equation: AX + BY + C = 0;
	// One line at least 1m.
	// LineType: Incline: Y = AX + C; Y = KX + C;
	//           Vertical X = C;
	//           Horizontal Y = C;

	APALineIsVerticalOrHorizontalType LineType;
	APA_DISTANCE_CAL_FLOAT_TYPE A;
	APA_DISTANCE_CAL_FLOAT_TYPE B;
	APA_DISTANCE_CAL_FLOAT_TYPE C;

} APALineParameterABCType;

typedef struct {
	// Line equation: Y = KX + B;
	// One line at least 1m.
	APA_DISTANCE_CAL_FLOAT_TYPE K;
	APA_DISTANCE_CAL_FLOAT_TYPE B;

} APALineParameterKBType;

typedef struct {
	APACoordinateDataType Coordinate;
	APA_ANGLE_TYPE CarAng;
} APACarCoordinateDataType;

typedef struct {
	APACoordinateDataCalFloatType Coordinate;
	APA_ANGLE_CAL_FLOAT_TYPE CarAng;
} APACarCoordinateDataCalFloatType;

typedef struct {
    APA_DISTANCE_TYPE APASnsDtdObjDis[APA_SIDE_SENSOR_NUM];
	//APA_DISTANCE_TYPE APACorSnsDtdObjDis[APA_CORNER_SENSOR_NUM];
    APACarCoordinateDataCalFloatType CarCenterPt;
	APA_SPEED_TYPE VehicleSpd;
} APASnsDtdObjDisInfoType;


typedef struct {
	APA_DISTANCE_TYPE RSObjDis; // Obj detected by the R side sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE RObjDis; // Obj detected by the R corner sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE MidObjDis; // Obj detected by the RM, LM, R tx RM Rx, RM tx R Rx, L tx LM rx, LM tx L rx. UPA FOV.
	APA_DISTANCE_TYPE LObjDis; // Obj detected by the L corner sns. dis from 20cm ~ 200cm
	APA_DISTANCE_TYPE LSObjDis; // Obj detected by the L side sns. dis from 20cm ~ 200cm
} APASnsDtdNearestObjDisDataType;

typedef struct {
	APASnsDtdNearestObjDisDataType ObjDis[APA_PARKPROC_SUPPORT_MAX_SYS_DT_MIN_DIS_NUM];
	APA_SPEED_TYPE ObjSpeed[5];
} APASnsDtdNearestObjDisBufAndObjSpeedDataType;

/*2.1************************************* COMMON USE STRUCTURE  END ********************************************/



/*2.2************************* APA SLOT INFO BASE STRUCTURE  START ************************************************/
typedef struct {
	APACoordinateDataType Coordinate;
	APA_DISTANCE_TYPE DisFromCarToObj;
} APASlotCoordinateDataType;

typedef struct {
	APACoordinateDataCalFloatType Coordinate;
	APA_DISTANCE_TYPE DisFromCarToObj;
} APASlotCoordinateDataCalFloatType;

typedef struct  {
	APACarCoordinateDataType CarPos;
	APACoordinateDataType Pt;
	APA_DISTANCE_TYPE ObjDis; // Object distance detected by the APA sensor.
	APA_DISTANCE_TYPE ObjToCarVDis; // Object to the car vertical distance.
	APA_ENUM_TYPE WeightCoe; /* Weight coefficient indicates how many times the object has been detected. A delta weight coefficient is defined. It is related to the vehicle speed. The higher the speed is the large delta weight coefficient will be. If the WeightCoe is less than 50, it indicates there is no object (or object has been removed. The max WeightCoe is 100.*/
	APA_CAL_FLOAT_TYPE bel;// indicates the confidence of object has been detected
	APA_CAL_FLOAT_TYPE Lt; // odds of the state
	APA_ENUM_TYPE DisStatus;
} APASlotSnsDtdObjPointType;

typedef struct  {
	APASlotSnsDtdObjPointType ObjPtBuf[APA_SLOT_MAX_SUPPORT_SNS_DTD_OBJ_POINT_BUF_SIZE];
	APA_ENUM_TYPE ObjType; /*APASlotObjTypeType ObjType; Object type indicates what kind of object it is. It can be Round, Square or Unknown object type. */
	APA_ENUM_TYPE SnsDtLoopCnt; // Indicate how many times the sensor has detected.
	APA_ENUM_TYPE WrIndex;
} APASlotSnsDtdObjPtBufType;

typedef struct  {
	APACoordinateDataType Pt;
	APACarCoordinateDataType CarPos;
	APA_DISTANCE_TYPE ObjDis; // Object distance detected by the APA sensor.
	APA_ENUM_TYPE ObjType; /*APASlotObjTypeType ObjType; Object type indicates what kind of object it is. It can be Round, Square or Unknown object type. */
} APASlotObjPointType;

typedef struct {
	APACoordinateDataType CarCenterPoint[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM]; // Car center point.
	APA_DISTANCE_TYPE DisFromCarToObj[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM]; // Slot outline point.
	APACoordinateDataType ObjPt[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
	APA_ANGLE_TYPE CarAng[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
	APA_ENUM_TYPE ObjType[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
	UCHAR WrIndex;
	APA_ENUM_TYPE ObjPtCnt;
} APASlotOutlineCoordinateDataType;

typedef union {
	APASlotOutlineCoordinateDataType Lane;
	UCHAR Data[sizeof(APASlotOutlineCoordinateDataType)];
} APASlotOutlineDataType;

typedef struct {
	// Line equation: Y = KX + B;
	// One line at least 1m.
	APALineParameterKBType LinePar;
	APA_ENUM_TYPE StartPtIndex;
	APA_ENUM_TYPE EndPtIndex;
	APA_ENUM_TYPE QuarterStartLinePtIndex;
	APA_ENUM_TYPE ThreeQuarterLineEndPtIndex;
	APACoordinateDataCalFloatType NearestPointToCar;
	APA_DISTANCE_TYPE LineDepth;
} APASlotBorderLineParameterType;

typedef struct {
	APASlotBorderLineParameterType LineBuf[APA_SLOT_SUPPORT_SLOT_BORDER_LINE_NUM]; // 8 * 15 bytes = 120 bytes.
	APA_ENUM_TYPE LineNum; // indicate how many lines in the line buffer
} APASlotBorderLineInfoType;

/*
				Slot Parameter:

							SlotStartIndex
		SlotStartIndex - 1							                     SlotEndIndex
				+			+ --+-					                              +--+-----+---
DisCarToObj2ByPassingSlot	|	|					                              |  |     |
				| 			|	|					                              |  |     |
				V			| SlotCalDisCarToObj1	                              | SlotCalDisCarToObj2
				------------+	|	+				+              +              |  |     DisCarToObj2ByPassingSlot
							|	|	|				|              |              V  |     |
							|	|	SlotDepth1		SlotDepth2     SlotDepth3     +--|-----+------
							|	|	|				|              |              |
							|	|	|				|              |              |
							|   |   |         +-----+-------+      |              |
                            |   |   |         |             |      |              |
                            |   |   |         | SlotLength2 |      |              |
                            V   |   |         |             |      |              |
                            +---+---+---------+             +------+--------------+
                                              |
							+---SlotLength1---+             +---SlotLength3-------+

							+------------------ SlotLengthTotal ------------------+
*/

typedef struct  {
	APA_ENUM_TYPE SlotType;
	APA_INDEX_TYPE SlotStartIndex;
	APA_INDEX_TYPE SlotEndIndex;
	APA_INDEX_TYPE SlotAIndex;
	APA_INDEX_TYPE SlotDIndex;
	APA_DISTANCE_TYPE SlotCalDisCarToObj1; // for parking out, it is the rear obj dis
	APA_DISTANCE_TYPE SlotCalDisCarToObj2; // for parking out, it is the front obj dis
	APA_DISTANCE_TYPE SlotLengthDetected1; // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthDetected2; // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthDetected3; // Slot length detected by the slot process task, only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLengthTotal; // Slot length detected by the slot process task
	APA_DISTANCE_TYPE SlotDepthDetected1; // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotDepthDetected2; // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotDepthDetected3; // only used for perpendicular parking
	APA_DISTANCE_TYPE SlotLength; // Slot length recalculated by setup system coordinate and use to cal the trajectory.
	APA_DISTANCE_TYPE SlotDepthParallel;
	APA_DISTANCE_TYPE SlotDepth;			// for parking out, it is the left object dis
	APA_DISTANCE_TYPE SubSlotDepth;			// for parking out, it is the right object dis
	APA_DISTANCE_TYPE DisCarToObj1ByPassingSlot; // for parking out, it is the left object X coordinate.
	APA_DISTANCE_TYPE DisCarToObj2ByPassingSlot;
    APA_DISTANCE_TYPE CarPassTheSlotEndPtDistance;
    APA_DISTANCE_TYPE CarPassTheSlotStartPtDistance;
    APA_DISTANCE_TYPE CarPassTheSlotDistanceTrajectoryCaled;
	APALineParameterKBType SlotCenterLinePar;
    APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead;
    APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail;
	APA_INDEX_TYPE TrajectoryCalRequestType;
	BOOLEAN bSlotCalConfirmed;
	BOOLEAN bSlotCalConfirmedSpeakerHasChimed;
	APA_SLOT_ID_TYPE SlotID; // To identify a slot uniq ID.
	APA_SPEED_TYPE APAVehicleSpeedWhenSlotFound;
    APACoordinateDataCalFloatType PointB_Coordinator;
    APACoordinateDataCalFloatType PointC_Coordinator;
	APACoordinateDataCalFloatType PointA_Coordinator;
	APACoordinateDataCalFloatType PointD_Coordinator;
	APA_ENUM_TYPE slotPointBBeUpdatedByCurve;
	APA_ENUM_TYPE slotPointCBeUpdatedByCurve;
} APASlotParameterType;

typedef struct  {
	APASlotOutlineDataType SlotOutline;
	APASlotBorderLineInfoType BorderLineInfo;
	UCHAR SlotNum;
	BOOLEAN bRequestToRemoveOneSlot;
	APA_ENUM_TYPE PrevSlotEndIndex;
	APASlotParameterType SlotPar[APA_SLOT_SUPPORT_MAX_SLOT_NUM];
	// Parking out parameter start
	APASlotDetectFailCausesType SlotDtFailCause;
	// Parking out parameter end
} APASlotInfoDataType;


typedef struct  {
	APA_ENUM_TYPE SlotType;
	APA_DISTANCE_TYPE SlotDepth;
	APA_DISTANCE_TYPE SlotLength;
	BOOLEAN bSlotCalConfirmed;
	BOOLEAN bSlotisWithCurb;
	BOOLEAN bIsPointBObjectExist;
	BOOLEAN bIsPointCObjectExist;
	APACoordinateDataCalFloatType Point_B_Coordinate;
	APACoordinateDataCalFloatType Point_C_Coordinate;
	APACoordinateDataCalFloatType Point_A_Coordinate;
	APACoordinateDataCalFloatType Point_D_Coordinate;
	float fSlotAngle;
} SlotSearchingResultDataType;


/*2.2************************* APA SLOT BASE STRUCTURE  END ************************************************/
typedef struct _APASlotSearchingPointRefinedCal
{
	APA_INDEX_TYPE SlotStartIndex;
	APA_INDEX_TYPE SlotEndIndex;
	APA_INDEX_TYPE minIdxStart;
	APA_INDEX_TYPE minIdxEnd;
	APA_INDEX_TYPE StartEdageIdx;
	APA_INDEX_TYPE EndEdageIdx;
	APA_INDEX_TYPE SlotPointAIndex;
	APA_INDEX_TYPE SlotPointDIndex;
}APASlotSearchingPointRefinedCal;


/*2.3************************* APA TRAJECTORY BASE CALCULATE STRUCTURE START ***********************************/

typedef struct {
	APACoordinateDataCalFloatType Coordinate;
	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenter;
	APA_DISTANCE_CAL_FLOAT_TYPE DisToCarCenterSquare;
	APA_ANGLE_TYPE Ang;
	APA_DISTANCE_CAL_FLOAT_TYPE MinInnerTurningRadius;
	APA_DISTANCE_CAL_FLOAT_TYPE MinOuterTurningRadius;
} APATrajCalPointOnCarPosDataCalFloatType;

typedef struct {
	APACarCoordinateDataCalFloatType CarPos;
	APA_ANGLE_TYPE SteeringWheelAngle;
//	APA_ANGLE_TYPE SteeringWheelAngleTanValue;
	APACoordinateDataCalFloatType CarTurningCenterPt;
	APA_DISTANCE_CAL_FLOAT_TYPE CarRearAxisCenterTurningRadius;

} APATrajCalCarParkingStepDataType;

typedef struct{
    // APACarCoordinateDataCalFloatType Step1KeyPt; //Back up data of step1 changed from this to the new for step1 is a circle
   	APATrajCalCarParkingStepDataType StepData[APA_SUPPORT_ORIGINAL_STEP_DATA_NUM];
	APA_ENUM_TYPE TrajDataCheckSeq;
	APA_ENUM_TYPE StepNum;
	APA_SLOT_ID_TYPE TrajCaledSlotID; // indicated the corresponding slot ID for the current traj.
} APATrajCalCarParkingOriginalStepDataType;

/*2.3************************* APA TRAJECTORY BASE CALCULATE STRUCTURE END ***********************************/

typedef struct{
	BOOLEAN bParkingSide;
	BOOLEAN bParkingCurbDetected;
	APA_DISTANCE_TYPE SlotLength;
	APA_DISTANCE_TYPE SlotDepth;
	APA_DISTANCE_TYPE SlotPositionX;
	APA_DISTANCE_TYPE SlotPositionY;
	APA_DISTANCE_TYPE SlotAngle;
} tAPADefaultParkingSlotInfo;

typedef struct{
	BOOLEAN bDiagnosticTraceFuncAct;
	BOOLEAN bDefaultParkingTestFuncAct;
	tAPADefaultParkingSlotInfo APADefaultParallelSlotInfo;
	tAPADefaultParkingSlotInfo APADefaultPerpendicularSlotInfo;
} tAPADiagnosticTraceInfoType;



/*2.4************************* APA CALIBRATION STRUCTURE START	*********************************************/
typedef struct  {
/*2.4.1***Vehicle pararmeter****/
	APA_DISTANCE_TYPE LengthOfCar;
	APA_DISTANCE_TYPE WidthOfCar;
	APA_DISTANCE_TYPE HalfWidthOfCar;
	APA_DISTANCE_TYPE HalfWidthOfFrontAxis;
	APA_DISTANCE_TYPE HalfWidthOfRearAxis;
	APA_DISTANCE_TYPE LenBetweenFRAxis;
	APA_DISTANCE_TYPE LenBetweenRAxisAndFBumper;
	APA_DISTANCE_TYPE LenBetweenRAxisAndRBumper;
	APA_DISTANCE_TYPE WheelTireDiameter[MAX_TIRE_SIZE_NUM];
/*2.4.2***Sensor fixed information****/
	APACoordinateDataType SnsPos[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center
	APA_ANGLE_TYPE SnsAng[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center, (unit: radian)
	APA_ANGLE_CAL_FLOAT_TYPE SnsAngCos[APA_SUPPORT_APA_SNS_NUM];
	APA_ANGLE_CAL_FLOAT_TYPE SnsAngSin[APA_SUPPORT_APA_SNS_NUM];

/*2.4.5***apa state relatively ****/
	APA_ENUM_TYPE CarParkAtLeftOrRightSide; // Car park at left if true other wise park at right
	tAPAByteBitType _APASupportFunctionMode;


/*2.4.7***boolean define ****/

	tAPACalBooleanType APACalCommonFlags;


/*2.4.8*** common use ****/

	APA_ANGLE_TYPE APARxSteeringWheelAngleConvertFactor; //Convert the D0 (EPS Tx steering wheel angle) to unit: rad. APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR

	APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol; // For different tire radius and pulse cnt, this value should be different.
	APA_DISTANCE_CAL_FLOAT_TYPE APAWheelPulseNeedUpdateDis; //when the car position is not updated,and the wheel distance is more than NeedUpdateDis,then updated the car positon.
	UINT16 APASupportMaxWheelPulseCnt;//for different type of cars,the supported max wheel pulse cnt would be different.

/*2.4.9*** Searching Slot Algorithm****/
/*2.4.9.1*** Parrallel slot****/
	APA_DISTANCE_TYPE APASlotRoundObjPtSearchBackMaxDis;
	APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis;
	APA_DISTANCE_TYPE APASlotCarToObjDisCalObjWidthToBeConsidered;
	APA_DISTANCE_TYPE APASlotPointFilterDeltaDis;
	APA_DISTANCE_TYPE APASlotCarToObjDisCalObjToCarDisTolLen;
	APA_DISTANCE_TYPE APASlotSnsDtRoundObjMaxDeltaDis;
	APA_DISTANCE_TYPE APASlotSnsDtRoundObjMinDeltaDis;
	APA_DISTANCE_TYPE APASlotSnsDtSQuareObjMaxDeltaDis;
	APA_ENUM_TYPE APASlotObjDetProbabilityPercentage; // 1~90%
	APA_DISTANCE_TYPE APASlotHFOVWidthBySeg[APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM];
	APA_ENUM_TYPE APASlotLAPASnsIndex;
	APA_ENUM_TYPE APASlotRAPASnsIndex;
	APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead[APA_SLOT_SUPPORT_OBJ_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_DEVIDED_NUM]; // Slot start
	APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail[APA_SLOT_SUPPORT_OBJ_TYPE_NUM][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_DEVIDED_NUM]; // Slot end.
	APA_DISTANCE_TYPE APASlotDetectionToleranceDis;
	APA_DISTANCE_TYPE APASlotMaxSlotLengthWithInvalidObj2;
	APA_DISTANCE_TYPE APASlotMinDisCarToObjByPassingSlot; // Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlot;// Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;
	APA_DISTANCE_TYPE APASlotMaxDisForCurbDetection;// Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotConsiderSecondSlotDepthMinDeltaSlotLen;
	APA_DISTANCE_TYPE APASlotRegardAsFirstSlotDepthMinSlotLen;
	APA_DISTANCE_TYPE APASlotMinStartCheckingCurbOffsetLen;
	APA_DISTANCE_TYPE APASlotMinRegardedAsCurbMinCurbLenAtSlotHeadAndTail;
	APA_DISTANCE_TYPE APASlotMinSmallSlotLen; // 6 steps parking.
	APA_DISTANCE_TYPE APASlotMaxSlotLength;
	APA_DISTANCE_TYPE APASlotCurbLineTolerance;
	APA_DISTANCE_TYPE APASlotMinSlotDepth;// Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotMaxSlotDepth;// Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotMaxPathAfterSlot;
	APA_DISTANCE_TYPE APASlotMinPathAfterSlot; // With obj 2 valid. dis cal from slot end pt.

/*2.4.9.2*** Perpendicular slot ****/
	APA_DISTANCE_TYPE APASlotPMinSmallSlotLen; // 6 steps parking.
	APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj1;
	APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj2;
	APA_DISTANCE_TYPE APASlotPMaxSlotLength;
	APA_DISTANCE_TYPE APASlotPMinSlotDepth;// Use car rear axis center as the reference point
	APA_DISTANCE_TYPE APASlotPMinStartCheckingCurbOffsetLen;

	APA_ANGLE_TYPE APAParkProcCarDriveStraightlyMinSteeringWheelAng;
	APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeed;
	APA_SPEED_TYPE APAParkProcMaxSearchingSlotSpeed;

	APA_ANGLE_TYPE APATrajCalCarDriveVerticallyMaxCarAng;
	APA_ANGLE_TYPE APATrajCalCarDriveHorMinCarAng;

	APA_DISTANCE_TYPE APASlotCurbLineFitAllowSnsDtObjDisTolerance;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance2;
	APA_ENUM_TYPE APASlotCurbLineFitAllowMinObjPt;
	APA_DISTANCE_TYPE APASlotCurbLineFitAllowMinCurbLength;
	APA_RATIO_TYPE APATrajCalLineIsHMinK; // if the K of the line is less than APATrajCalLineIsHMinK, means the line is horizontal,
	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng;
	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxCurbLineAndYAng;
	APA_ANGLE_TYPE APASlotCurbLineFitCurbLineAngCompensateRatio;

/*2.4.10***Car position calculate parament****/
	APA_TIMES_TYPE APACarPosCalculationTaskCallCycleTime;
	APA_ENUM_TYPE APACalCarPosUpdateCycleTimeCount;
	APA_ENUM_TYPE APASupportWheelPluseCounterErrorRecoverCycleTimeCount;
	APA_TIMES_TYPE APASupportMaxUseVehicleSpeedAndAccToEvaluateCarPosDurationCycleTimeCount;
	APA_DISTANCE_TYPE APASupportMaxUseVehicleSpeedAndAccToEvaluateCarPosTotalDis;
	APA_DISTANCE_TYPE APASupportMaxCarPosCalUpdateDetalTolance;
	APA_SPEED_TYPE APASupportMaxVehicleSpeedUpdateDeltaTolance;
	APA_SPEED_TYPE APACalCarPosVehicleSpeedCalAccFactor;
	APA_ENUM_TYPE APACalCarPosVehicleSpeedEvaluateByCarDriveDisDeltaCycleTime;
	APA_ENUM_TYPE APACalCarPosVehicleSpeedMissToBeUpdatedRecoverTime;
	APA_SPEED_TYPE APACalCarPosStartToAccumulateDisMinVehicleSpeed;
	APA_DISTANCE_TYPE APASlotCarCenterPointXDefaultValue;
	APA_DISTANCE_TYPE APASlotCarCenterPointYDefaultValue;
	APA_DISTANCE_TYPE APASlotCarCenterPointResetYValueMax;
	APA_DISTANCE_TYPE APASlotCarCenterPointResetYValueMin;
	APA_CAL_FLOAT_TYPE APASlotCarCenterPointResetCarAngMax;

/*2.4.11***Slot Searching Common Define***/
	APA_DISTANCE_TYPE APASlotSamplePtNoObjDisPtRemoveMinSlotLen;
	APA_DISTANCE_TYPE APASlotSamplePointUpdateLongDeltaLen;
	APA_DISTANCE_TYPE APASlotSamplePointUpdateSmallDeltaLen;
	APA_DISTANCE_TYPE APASlotPointCanBeRemovedContiguousPointMinDisP;
	APA_DISTANCE_TYPE APASlotMaxDistanceBetweenStartEndPtWithObj1Invalid;
	APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetweenStartEndPt;
	APA_ANGLE_TYPE APASlotMaxDeltaCarAngBetweenObjPt;
	APA_TIMES_TYPE APASlotSensorDtOneLoopTimeMs;
	APA_SPEED_TYPE APASlotNumberOfDtTimesCalMinSpd;
	APA_TIMES_TYPE APASlotMaxNumberOfDtTimes;
	APA_DISTANCE_TYPE APASlotObjectMaxWeightCoefficient;
	APA_DISTANCE_TYPE APASlotObjectAckWeightCoefficient;
	APA_DISTANCE_TYPE APASlotSensorDetectSameObjTolDis;
	APA_DISTANCE_TYPE APASlotSensorDetectObjRegionAreaWidth;
	APA_TIMES_TYPE APASlotSensorMaxDetectLoopCntToConfirmObject;
	APA_DISTANCE_TYPE APASlotMinPerSlotDeltaCarPosDisAtSlotStAndEndPt;
	APA_DISTANCE_TYPE APASlotApSlotDisToCarCheckCarTravellingDis;
	APA_TIMES_TYPE APASlotVehicleStaticUpdateSlotPtTime;
	APA_DISTANCE_TYPE APASlotSearcingEdgeDistanceTolerance;
	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular;
	APA_DISTANCE_TYPE APASlotMaxOffsetBetweenMinDisToCarIndexToObjEdgeIndex;
} SlotSearchingCaliCfgData;

/*2.4************************* APA CALIBRATION STRUCTURE END	*********************************************/

/*2.5************************* APACarPar STRUCTURE START	***************************************************/

typedef struct {

/*2.5.1  BOOLEAN Variables	****************/
	tAPACarParFlag1Type APACommonFlags;
	tAPACarParFlag2Type APACommonFlags2;

/*2.5.2  COMMON USE Variables	****************/

	APA_SPEED_TYPE APAVehicleSpeed; // Unit: m/s
	APA_ENUM_TYPE APAGearPosition;
	APA_SPEED_CAL_FLOAT_TYPE APAVehicleAcceleration;
	APA_ENUM_TYPE APACarParkAtLeftOrRightSide; // Car park at left if true other wise park at right
	APA_ENUM_TYPE APACarParkingMode; // Parallel or perpendicular parking.
	APA_ANGLE_TYPE APASteeringWheelAngle; // (unit: radian) . = 9.751 -> R = 15000 mm
	APA_ANGLE_CAL_FLOAT_TYPE APASteeringWheelAngleTangentValue; // MATH_TAN(SteeringWheelAngle), the range of the value (-&, +&)
	APA_ANGLE_CAL_FLOAT_TYPE APASteeringWheelAngleCosValue; // Cos(SteeringWheelAngle) , the value will always >= 0
	APACarCoordinateDataCalFloatType APACarCenterPt;
	APACarCoordinateDataCalFloatType APACarCenterPtCaledByWheelCnt;
	APA_ENUM_TYPE APACurrentCarAngState;	// 0 -- Normal, ie. oblique line. inclined line
										// 1 - vertical.
										// 2 - horizontal.
	APA_ENUM_TYPE APARunningState;
	APA_ENUM_TYPE APAState;
	APA_ENUM_TYPE APADisableCauses;
	APA_ENUM_TYPE APADisableCausesBuf[APA_SUPPORT_MAX_APA_DISABLE_CAUSES_BUF_SIZE];
	APA_ENUM_TYPE APADisplayCmd;
	APA_ENUM_TYPE APACurDisplayCmd;
	APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadiusFLTire; // unit: m
	APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadiusFRTire; // unit: m
	APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadiusRLTire; // unit: m
	APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadiusRRTire; // unit: m

    APASnsDtdObjDisInfoType APASnsDtdObjDisInfoBuf[APA_MAX_SUPPORT_SNS_DTD_OBJ_DIS_BUF_SIZE];

    APA_ENUM_TYPE APASnsDtdObjDisInfoBufReadIndex;
    APA_ENUM_TYPE APASnsDtdObjDisInfoBufWriteIndex;
	APA_ENUM_TYPE APARequestToMirrorSlot;
	APA_INDEX_TYPE APARightSlotDataIndex;
	APA_INDEX_TYPE APALeftSlotDataIndex;

////2.5.2.1 APARxSteeringWheelAngleMsgProcess
    APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadius; // unit: mm
	APA_ENUM_TYPE APACurrentSteeringAngState;	// 0 -- drive straightly
										// 1 - turning right.
										// 2 - turning left.
    APA_DISTANCE_CAL_FLOAT_TYPE APACurrentCarTurningRadiusSquare; // unit: mm
////2.5.2.2 calculate Carpos
	APA_SPEED_TYPE APAVehicleSpeedArray[APA_SUPPORT_MAX_VEH_SPD_BUF_SIZE];


/*2.5.3  SEARCHING SLOT USE Variables	****************/
	APASlotInfoDataType Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_SENSOR_NUM];//
	APA_MS_TIME_TYPE SlotPEStartSlotCheckTimer;
	APA_DISTANCE_TYPE SlotCarEndPosXPrevValue; // Use for perpendicular parking: car end pos correction to save the value when the car end pos angle is 90deg.
	APA_SLOT_ID_TYPE SlotPrevID; // To identify a slot uniq ID.

/*2.5.4  TRAJECTORY CALCULATION USE Variables	********/
	APACarCoordinateDataCalFloatType TrajCalCarEndPos;
	APALineParameterABCType TrajCalCarEndPosLine;
	APACoordinateDataCalFloatType TrajCalObj1Pos;
	APACoordinateDataCalFloatType TrajCalObj2Pos;
	APALineParameterKBType TrajCalSlotRightSideLine;
	APALineParameterKBType TrajCalSlotLeftSideLine;
	APA_ENUM_TYPE TrajCalCarParkingStepsNum;
	APA_ENUM_TYPE TrajCalCarParkingInSlotStepsNum;
	APA_ENUM_TYPE TrajCalCarParkingCurrentStepIndex;
	APATrajCalCarParkingStepDataType TrajCalCarParkingStepDataArray[APA_PARKPROC_MAX_SUPPORT_PARKING_STEPS_NUM];
	APATrajCalCarParkingOriginalStepDataType TrajCalCarParkingOriginalStepData;
	APASlotCoordinateDataCalFloatType TrajCalCorrectSlotDataArray[5]; // ??????????????
	APA_DISTANCE_CAL_FLOAT_TYPE TrajCalCarParkingTrajectoryOuterTurningCircleMaxX; //
	APA_ANGLE_TYPE TrajCalSteeringWheelAngleCal; // (unit: radian) . = 9.751 -> R = 15000 mm
    APA_DISTANCE_CAL_FLOAT_TYPE TrajCalCurrentCarTurningRadiusCal; // unit: m
    APACoordinateDataCalFloatType TrajCalCurrentCarTurningCenterPtCal; // unit: mm
 	APA_ENUM_TYPE TrajCalAPATrajectoryCalResult;
	APA_ENUM_TYPE TrajCalAPATrajectoryCalStatus;
	APA_DISTANCE_TYPE TrajCalFrontSnsDtdNearestDis;
	APA_DISTANCE_TYPE TrajCalRearSnsDtdNearestDis;
	APA_DISTANCE_TYPE TrajCalSubLaneObjX;
	APA_DISTANCE_TYPE TrajCalPEMinCarEndPosCoordinateX;
    APACoordinateDataCalFloatType TrajCalCurrentCarTurningCenterPt; // unit: mm
    APACarCoordinateDataCalFloatType TrajCalCarCenterPtCal;
    APA_ENUM_TYPE TrajCalCurrentCarAngStateCal; // 0 -- Normal, ie. oblique line. inclined line
	APA_ENUM_TYPE TrajCalCurrentCalSlotIndex;
	APA_SLOT_ID_TYPE TrajCalCurrentCalSlotID;

/*2.5.5  PARK PROCESS USE Variables	********/
	APACarCoordinateDataCalFloatType ParkProcSysNewCarCenterPt;
	APA_ANGLE_TYPE ParkProcCheckIfCarIsOnTheTrajectorySteeringAngle;
                                         // 1 - vertical.
                                         // 2 - horizontal.
	APA_ENUM_TYPE ParkProcAPARunningStateCalSequence;
	APA_ENUM_TYPE ParkProcSlotConfirmedIndex;

	UCHAR ParkProcProcessPercentage; // This indicator should go from 0 ~ 100.
	APA_DISTANCE_CAL_FLOAT_TYPE ParkProcCarStartPosToDestPosDisWithCurDriveDirection;
	APA_ENUM_TYPE ParkProcAPADriverInfoDisplayCmdConfirmCnt;
	APA_MS_TIME_TYPE ParkProcAPADriverInfoDisplayTimer;
	APA_MS_TIME_TYPE ParkProcCarMayHitObjectStopWaitingTimer;
	APA_ENUM_TYPE ParkProcAPATrajectoryCalCmd;
	APA_MS_TIME_TYPE ParkProcAPATrajectoryCalTimer;
	APA_MS_TIME_TYPE ParkProcAPARuningStateControlTimer;
	APA_MS_TIME_TYPE ParkProcAPARuningStateControlTimer2;
	APA_ANGLE_TYPE ParkProcAPATargetSteeringWheelAngle;
	APA_ANGLE_TYPE ParkProcSteeringWheelAngleCtrlStep;
	APA_ANGLE_TYPE ParkProcEPSSteeringWheelAngleTurningStep; // unit: rad.
	APA_ENUM_TYPE ParkProcTrajRecalCheckVehPosAndDriveDirSequence;
	tAPACarHitObjIndicationType ParkProcCarWillHitObjIndication;
	APA_MS_TIME_TYPE wParkProcSteeringWheelTurningTimer;
	APA_MS_TIME_TYPE wParkProcSteeringWheelAngleHoldTimer;
	APA_ENUM_TYPE ParkProcCalculateTrajectoryTryTimes;
	APA_ENUM_TYPE ParkProcRequestControlEPSTryTimes;
	APA_CAL_FLOAT_TYPE ParkProcSteeringWheelTurnPercentProgress;
	APA_ENUM_TYPE ParkProcCurrentGearPosition;//the CurrentGearPosition will only he set to APAGearPositionD or APAGearPositionR
	APA_ANGLE_TYPE ParkProcAPAFinalTargetSteeringWheelAngle;
	APACoordinateDataCalFloatType ParkProcCarCentrePointStartingToTurnSteeringWheel;
	APA_ANGLE_TYPE ParkProcSteerngWheelAngleStartingToTurnSteeringWheel;
	APA_CAL_FLOAT_TYPE ParkProcCurrentCarCentrePointToCurrentKeyPointDis;
	APA_ENUM_TYPE ParkProcIPCOutPutTaskAPARunningState;
	APA_CAL_FLOAT_TYPE ParkProcDisBtStTurnSteerAndEndTrunSteerWheel;
	APA_ENUM_TYPE ParkProcAPATrajectoryCalCntAtTheSameDriveDirection;
	APA_ENUM_TYPE ParkProcCarInTheSlotDriveForwardAndBackwardCnt;
	APA_DISTANCE_TYPE ParkProcCarInTheSlotDriveForwardAndBackwardPrevPos;
	APA_ANGLE_TYPE ParkProcCarIsInTheSlotSteeringCtrlCorrectedTargetAngle;
	APA_ENUM_TYPE ParkProcCarInSlotLastStepCircleRecalCnt;
	APA_ENUM_TYPE ParkProcDtmCarPosRequestToCalTrajCarDriveDirection;
	APA_DISTANCE_TYPE ParkProcCarParkingAllowedDeviateDisFromCalTrajectory;
	APA_ANGLE_TYPE ParkProcCarParkingAllowedDeviateCarAngFromCalTrajectory;
	signed short wParkProcAPARxSteerWheelAngle;
	uchar cParkProcAPARxSteeringWheelAngleDirection;
	APASnsDtdNearestObjDisDataType ParkProcSnsDtNearestDis[PA_SYS_NUM];
	APASnsDtdNearestObjDisBufAndObjSpeedDataType ParkProcSnsDtObjBufAndObjSpd[PA_SYS_NUM];
	APA_DISTANCE_TYPE ParkProcRearSnsDtdNearestDis;
	APA_DISTANCE_TYPE ParkProcFrontSnsDtdNearestDis;
	APA_MS_TIME_TYPE  ParkProcObjectMovingSpeedProcessTimer;
	APA_MS_TIME_TYPE  ParkProcVehicleStaticTimer; // Indicate how long the vehicle has been static.
	APA_MS_TIME_TYPE  ParkProcAPAParkingTimer;
	APA_ENUM_TYPE ParkProcCarEndPosition;
	APA_ENUM_TYPE ParkProcAPAParkingFailedCauses;
	APA_ENUM_TYPE ParkProcAPAParkingFailedCausesBuf[APA_SUPPORT_MAX_APA_FAILED_CAUSES_BUF_SIZE];
	tAPAParkProcCarMayHitObjCmdDisplayFlagType ParkProcCarMayHitObjCmdDisplayFlag;
	APA_MS_TIME_TYPE  ParkProcRObjRegardedAsNotExistTimer;
	APA_MS_TIME_TYPE  ParkProcFObjRegardedAsNotExistTimer;
	//APACoordinateDataType ParkProcCarPosWhenCarDrvDirChanged;
	APA_DISTANCE_CAL_FLOAT_TYPE ParkProcReCalTrajPrevCarPosX;
	APA_ENUM_TYPE ParkProcSlotBorderLineReqCalSeq;
	APA_DISTANCE_TYPE ParkProcCarEndPositionTol; // end pos tolerance
	APA_ANGLE_TYPE ParkProcCarEndPositionCarAngTol; // end pos tolerance
	APA_DISTANCE_CAL_FLOAT_TYPE ParkProcCarDriveCmdDisplayPrevCarPosX;
	APA_DISTANCE_TYPE ParkProcSafetyDisToObjAtFront;
	APA_DISTANCE_TYPE ParkProcSafetyDisToObjAtRear;


#ifdef APA_SUPPORT_DEBUG_CAR_TRAVEL_DISTANCE
    long CarTravelDistanceY;
    long CarTravelDistanceX;
#endif

	/***********************DIAG TRACE TEST **************************/
	tAPADiagnosticTraceInfoType APADiagnosticTraceInfo;
	/***********************DIAG TRACE TEST **************************/
}APACarParameterInfoType;

/*2.5************************* APACarPar STRUCTURE END	**********************************************************/


/*2.6************************* VARIABLE STATEMENT STRUCTURE START	**********************************************/
extern    APASlotSnsDtdObjPtBufType  APASnsDtdObjPtBuf[APA_SIDE_SENSOR_NUM];
extern    uchar  cAPARequestChimeCmd;
extern    APACarParameterInfoType  APACarPar;
extern    APA_DISTANCE_TYPE  APASnsDtdObjDis[APA_SIDE_SENSOR_NUM];
extern       UCHAR   APACalCarPosVehicleSpeedMissToBeUpdatedTimer; // unit: /10ms
extern   const  SlotSearchingCaliCfgData  SlotCaliCfg;
extern void SlotSearching_ParameterInit(void);
extern APA_DISTANCE_TYPE SlotSearching_GetTwoPointDisInt(
    APA_DISTANCE_TYPE X1,
    APA_DISTANCE_TYPE Y1,
    APA_DISTANCE_TYPE X2,
    APA_DISTANCE_TYPE Y2);

extern APACoordinateDataCalFloatType APASlotProcCalObjPtCoordinateBySnsDtdDis(
	APA_DISTANCE_TYPE SnsDtdDis,
	APA_ANGLE_CAL_FLOAT_TYPE AngBetObjAndSnsCenterLine,
	UCHAR SnsIndex);

extern void APADiagnosticTraceParInit(void);

#endif

