#ifndef _OBJDETECTPARACFG_H_
#define _OBJDETECTPARACFG_H_

/* Global variables and const data and macro definitions*/

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"
#include "ObjectProcess.h"
#include "ObjDetectStateMachine.h"
#include "InfoOutput.h"


/*1.1************************************* COMMON MACRO-DEFINITION START ******************************************/
#define SENSOR_VERSION_NUM                              1
#define SNS_PARAMETER_NUM                               15
#define OBJ_MAX_ZONE_NUM                                15
#define OBJ_OFFSET_FROM_BUMPER_DEVIDE_DIS               100 /* unit : mm */  
#define OBJ_OFFSET_FROM_BUMPER_DEVIDE_NUM               11 /* Total bumper length: 11 * 10 * 2 = 220 cm */
#define UPA_INITIAL_STATE_OFF                           0
#define UPA_INITIAL_STATE_ON                            1
#define UPA_INITIAL_STATE_LAST                          2
#define MAX_SUPPORT_SNS_TYPE_NUM				        2
/* About: CornerSnsSinAlfa and CosAlfa
	|	20 |
  |<-->|----------------------------------------------+-------|
  |     \														wDeltaHightForSns	|	     /
  |       \		sensor 1																|	   /
  |---------@----------------												__|__@
  |           \	\			|	Alfa													  /
  |             \		 \  			sensor 2							  /
  |               \_______\@______________@_________/
  eg. Alfa = 20 degree. CornerSnsSinAlfa = Sin(20) * DTM_OBJ_POS_UNIT_FACTOR =  0.342 * 1000 = 342
                        CornerSnsCosAlfa = Cos(20) * DTM_OBJ_POS_UNIT_FACTOR =  0.9397 * 1000 = 940
*/
#define SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM                     	15
#define SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_DISTACNE            		DISTANCE30CM_TIME
#define APA_SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM                 	15
#define APA_SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_DISTACNE            	DISTANCE30CM_TIME
#define SNS_INTI_MAX_NUM_SPEED  								    8
#define SNS_INTI_MAX_NUM_TEMPERATURE   							    5

#define TRIANGLE_EXIST_CALIBRATING_POINT_NUM				        5
#define PA_REGION_DIVIDE_DIS_TOL_NUM					            5
#define REAR_DISPLAY_CHECK_DELAY_TIME						        430 /* ms, task 10ms. default 530ms, need to great than SYS_ACTIVE_OBJ_REPORT_DELAYTIME*/
#define SYS_ACTIVE_OBJ_REPORT_DELAYTIME								400 /* ms, task 30ms. default 500ms */
#define SPEAKER_ROGER_TONE_CHIME_DELAY_TIME						    1 * SPK_CHIME_TASK_CALL_TIME /* ms, 1 * SPK_CHIME_TASK_CALL_TIME - alwayse wants the roger tone, 
otherwise should same as the REAR_DISPLAY_CHECK_DELAY_TIME = 230ms, task 1ms. */
#define SENSOR_NORMAL_EMIT_AND_THEN_READ_RING_TIME_WHEN_PA_ENTER_ACTIVE 0
#define SENSOR_READ_RING_TIME_FIRST_WHEN_PA_ENTER_ACTIVE			    1
#define MULTI_SENSOR_EMIT_WHEN_PA_ENTER_ACTIVE						    2
#define HAPTIC_SEAT_PRESENT_NOT_PRESENT 								0
#define HAPTIC_SEAT_PRESENT_PRESENT 								    1
#define ESS_CONTROLLER_PRESENT_NOT_PRESENT 							    0
#define ESS_CONTROLLER_PRESENT_PRESENT 									1
#define TURN_OFF_ALL_LED_WHEN_PA_FAIL							        0
#define FLASH_LED_WHEN_ANY_PA_FAIL								        1
#define ILLUMINATE_RED_LED_WHEN_ANY_PA_FAIL						        2
#define FLASH_LED_WHEN_PA_OR_FRONT_FAIL							        3
#define ILLUMINATE_RED_LED_WHEN_PA_OR_FRONT_FAIL				        4
#define FLASH_LED_WHEN_PA_OR_REAR_SYS__FAIL						        5
#define ILLUMINATE_RED_LED_WHEN_PA_OR_REAR_FAIL					        6
/*1.1.1***OBJECT DETECTE STRUCTURE DEFINE START****/
#define XML_PART_NUMBER_BYTE1										    0x01
#define XML_PART_NUMBER_BYTE2									        0x89
#define XML_PART_NUMBER_BYTE3									        0x94
#define XML_PART_NUMBER_BYTE4									        0x8c
/*1.1************************************* COMMON MACRO-DEFINITION END ******************************************/


/*1.2************************************* COMMON TYPEDEFINE START ***********************************************/
typedef float SNS_DISTANCE_CAL_FLOAT_TYPE;
typedef struct
{
	uchar cTempZoneNum;
	uchar  cToleranceTemp;
	schar cTempArray[SNS_INTI_MAX_NUM_TEMPERATURE];
} tTemperatureInfoStruct;
typedef struct
{
	uchar cSpeedZoneNum;
	word cToleranceSpeed;
	word cSpeedArray[SNS_INTI_MAX_NUM_SPEED];
} tSpeedInfoStruct;
typedef struct
{
	word wDisBetweenSns[PA_REAR_SNS_NUM][2];
	SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosSinAlfa[PA_REAR_SNS_NUM][2];
	SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosCosAlfa[PA_REAR_SNS_NUM][2];
	word wDeltaHightForSns[PA_REAR_SNS_NUM][2];
	word wObjOffsetFromBumper[OBJ_OFFSET_FROM_BUMPER_DEVIDE_NUM];
} SnsAssemblyParameterType;
typedef struct
{
	uchar cSnsDefThresholdData[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SNS_NUM * (SNS_PARAMETER_NUM)];
	unsigned long long cSnsDefCaliData[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SNS_NUM];
	word wMinSnsRingTime[MAX_SUPPORT_SNS_TYPE_NUM];
	word wMaxSnsRingTime[MAX_SUPPORT_SNS_TYPE_NUM];
	word wMinNormalSnsRingTime[MAX_SUPPORT_SNS_TYPE_NUM];
	word wMaxNormalSnsRingTime[MAX_SUPPORT_SNS_TYPE_NUM];
	word wMaxSnsDeltaRingTime;
	word wMinSnsRingTimeBlocked[MAX_SUPPORT_SNS_TYPE_NUM];
	word wObjIsWithinRingTimeObjDtdTime1;
	word wObjIsWithinRingTimeObjDtdTime2;
	word wValidObjBkWvWidthTxRx[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
	word wValidObjBkWvWidthRxOnly[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
	word wValidObjBkWvWidthTxRxForSideSns[SNS_SUPPORT_OPERATION_MODE_NUM][APA_SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
	uchar MAX_SNS_FAIL_CNT[SNS_SUPPORT_TOTAL_FAILED_TYPE_NUM];
	word MIN_PA_DISABLE_TOTAL_NOISE_TIME;
	uchar MAX_SNS_DISTURBED_PULSES_NUM_AFTER_TIME15MS;
	uchar MAX_PA_DISABLE_SNS_INT_NUM;
} SnsParameterType;
typedef struct
{
	uchar cObjZoneNum;
	uchar cToleranceDis;
	uchar cObjZoneArray[OBJ_MAX_ZONE_NUM];
} tObjZoneInfoStruct;
typedef enum
{
	PA_ZONE1_SOUND_INDEX = 0,
	PA_ZONE2_SOUND_INDEX,
	PA_ZONE3_SOUND_INDEX,
	PA_ZONE4_SOUND_INDEX,
	PA_ZONE5_SOUND_INDEX,
	PA_ZONE6_SOUND_INDEX,
	PA_ZONE7_SOUND_INDEX,
	PA_ZONE8_SOUND_INDEX,
	PA_ZONE9_SOUND_INDEX,
	PA_ZONE10_SOUND_INDEX,
	PA_ZONE11_SOUND_INDEX,
	PA_ZONE12_SOUND_INDEX,
	PA_ZONE13_SOUND_INDEX,
	PA_ZONE14_SOUND_INDEX,
	PA_ZONE15_SOUND_INDEX,
	PA_REV_ROGER_SOUND_INDEX,
	PA_FWD_ROGER_SOUND_INDEX,
	PA_FIRST_REPORT_SOUND_INDEX,
	PA_FAIL_SOUND_INDEX,
	APA_ACTIVATED_PARALLEL_IN_SOUND_INDEX,
	APA_ACTIVATED_PERPEN_IN_SOUND_INDEX,
	APA_ACTIVATED_PARK_EXIT_SOUND_INDEX,
	APA_SLOT_FOUND_SOUND_INDEX,
	APA_ENTER_AUTO_PARKING_SOUND_INDEX,
	APA_STOP_COMMAND_SOUND_INDEX,
	APA_PARKING_FAILED_SOUND_INDEX,
	APA_DEACTIVATED_SOUND_INDEX,
	APA_PARKING_SUCESS_SOUND_INDEX,
	SBSA_OBJ_DET_TURNING_LIGHT_ON_SOUND_INDEX	

} tSpeakerChimeInfoIndexType;
/*1.2************************************* COMMON TYPEDEFINE END **************************************************/




/*2.1************************************* OBJECT DETECTE STRUCTURE DEFINE START **********************************/
typedef struct
{
	/*2.1.1***Sensors dispatching.****/
	uchar cSnsSupportMaxDtCntPerLoop;
	uchar cSnsTxSnsMask[PA_SYS_NUM][SNS_SUPPORT_OPERATION_MODE_NUM][SNS_SUPPORT_DT_CNT_PER_LOOP];// If corresponding bit is 1: Tx.
	uchar cSnsRxSnsMask[PA_SYS_NUM][SNS_SUPPORT_OPERATION_MODE_NUM][SNS_SUPPORT_DT_CNT_PER_LOOP];// If corresponding bit is 1: Rx.
	
	/*2.1.2***Sensors parameter.****/
	tSnsEEPROMDataType SnsEEPROMData[PA_SYS_NUM][SNS_INTI_MAX_NUM_TEMPERATURE + 1][PA_REAR_SNS_NUM];
	uchar cSnsRingTimeUpdateCnt;
	uchar UPAFUCID;
	
	/*2.1.3***Sensors mask.****/
	uchar cPASnsMask[PA_SYS_NUM];
	
	/*2.1.4***Customization data.****/
	tDIDA1ECUConfigOrCustomizationData1Type DIDA1ECUConfigData1;
	
	/*2.1.5***Vehicle speed factor.****/
	// Max reverse speed: 0 ~ 255 km/h
	word wPAReverseCutOffSpdUp;
	word wPAReverseCutOffSpdBack;
	// Max forward speed : 0 ~ 255 km/h
	word wPAForwardCutOffSpdUp;
	word wPAForwardCutOffSpdBack;
	word wPAForwardSpdInhibit2;

	/*2.1.6***Warn zone.****/
	tObjZoneInfoStruct ObjZoneInfoStruct[PA_SYS_NUM];
	
	/*2.1.7***Distance tolerance.****/
	uchar cObjStateApproachingToleranceDis;
	uchar cObjStateDescendingToleranceDis;
	
	uchar cObjNotDetectedObjStateUpdateTime;
	/*uchar cObjNotDetectedPrevObjDisUpdateTime;*/
	
	/*2.1.8***Maximum times, sensor emit.****/
	uchar cMaxSensorEmitCnt[PA_SYS_NUM];
	
	uchar cRemainLastValueWhenSnsDstbd;
	/*uchar cMaxSnsSignalInvalidOrIncorrectComponentCnt;*/
	uchar cSnsMaxDataTxTryCnt[SNS_OPERATING_DATA_SEND_REQ_NUM];
	uchar cSnsReInitDelayTime;
	
	/*2.1.9***12 Sensors parameter.****/
	SnsParameterType SnsPar[SENSOR_VERSION_NUM];

	word wAPASnsDtdObjDisCompensateFactor;

	/*2.1.10***Begin to accumulate data after the time.****/
	word wAccumulateSnsBackWaveStartTime;
	word wAccumulateNoisePulseNumStartTime;
	
	word wTwoDataIsWithinTolleranceTime;

	uchar cSnsDisturbedCounterInitialValue;
	uchar cMaxSnsDisburbedCount;
	uchar cSns3EmitDisturbedCount;
	uchar cSns4EmitDisturbedCount;
	uchar cSnsBadlyDisburbedCounterAddStep;
	uchar cSnsSlightlyDisburbedCounterAddStep;
	uchar cCurrentFirstObjMismatchPrevousFirstObjDisburbedCounterAddStep;/**/
	
	/*2.1.11***Assembly parameter.****/
	SnsAssemblyParameterType SnsAssemblyParameter[PA_SYS_NUM];
	
	uchar cSnsOperatingCmdWhenPAEnterActive;
	uchar cSnsRxChannelIndex[SNS_INPUT_CAPTURE_CHANNEL_NUM][2];
	word wMaxEachSnsDtTime[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_INPUT_CAPTURE_CHANNEL_NUM / 2][3];
	word wMinEachSnsDtTime[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_INPUT_CAPTURE_CHANNEL_NUM / 2][3];
	
	/*2.1.12***Parameter of FOV.****/
	word wMinSnsDtDis[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
	
	word wMaxSnsDtDis[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
	word wMaxSnsDtDisNoFOVCut[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SYS_NUM];
	word wMinRMTxLMRxObjCutOffDis[PA_SYS_NUM];
	word wRMTxRRxObjCutOffHDis[PA_SYS_NUM];
	word wMinRmTxRRxObjCutOffDis[PA_SYS_NUM];
	word wRMTxRRxObjCutOffHDis2[PA_SYS_NUM];
	word wMinRmTxRRxObjCutOffDis2[PA_SYS_NUM];
	word wMinRmTxRRxObjCutOffDis3[PA_SYS_NUM];
	word wRTxRMRxObjCutOffHDis[PA_SYS_NUM];
	word wMaxRTxRMRxObjCutOffDis[PA_SYS_NUM];
	word wMinSnsTriDtDis[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
	word wMaxSnsTriDtDis[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];

	word wSnsRingTimeCheckCycle;

	word wVehicleOutSideCutOffDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM][TRIANGLE_EXIST_CALIBRATING_POINT_NUM];
	word wSnsSideOfDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM];
	word wVehicleInSideCutOffDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM][TRIANGLE_EXIST_CALIBRATING_POINT_NUM];
	uchar cWallDetectionEnabled[PA_SYS_NUM];
	/*uchar cObjStaticJudgeMethod;*/
	word wWallDetectionCutOffSpd[PA_SYS_NUM];
	uchar cWallDetectEnableTime;
	uchar cMinWallDetectHysteresisDis;
	word wWallDetectInnerCutOffDis[PA_SYS_NUM][2][6];
	word wWallDetectHCutOffDis[PA_SYS_NUM];
	uchar cRegionDivideDis[PA_SYS_NUM];
	uchar cRegionDivideDisTol[PA_SYS_NUM][PA_REGION_DIVIDE_DIS_TOL_NUM];

	uchar cMinRegionReportDis[PA_SYS_NUM];

	tSpeedInfoStruct SpeedChangeReqSensorInitStruct;
	tTemperatureInfoStruct TemperatureChangeReqSensorInitStruct;
	
	/*2.1.13***Threshold value change by speed.****/
	SINT8 sSensorThresholdDeltaBySpeedChange[MAX_SUPPORT_SNS_TYPE_NUM][SNS_INTI_MAX_NUM_SPEED + 1][SNS_PARAMETER_NUM - 1];
	SINT8 sSensorThresholdDeltaByTemperatureChange[MAX_SUPPORT_SNS_TYPE_NUM][SNS_INTI_MAX_NUM_TEMPERATURE + 1][SNS_PARAMETER_NUM - 1];

    uchar cSupportAPASystemDegradationFunction;
	
    /*2.1.14***Below parameters is regarding vehicle HMI, ignore them.****/
	uchar cFrontDisplayOnDelayTime;
	word wFrontDisplayCheckOnTime;
	word wRearDisplayCheckRogerOnTime;
	uchar cFlashRearLEDAtRvSpdTooHigh;
	tDisplayLEDFlashTimerType DisplayLEDFlashInfo[PA_SYS_NUM];
	uchar cMaxLEDTestTime[2];
	uchar cMaxLEDTestPassCnt[2];
	uchar cMaxLEDTestFailCnt[2];
	uchar cSendGMLANSignalFrontSysStatus;
	uchar cSendGMLANSignalRearSysStatus;
	uchar cSendGMLANSignalGeneralStatus;
	uchar cSendGMLANSignalODIIndAndEnumeDynData;
	uchar cSendGMLANSignalODIEvent;
	uchar cRepeatDisableMessage;
	uchar cRepeatFailDisableMessage;
	uchar cPADisbleEnblLEDCmd;
	word wDsblEnblLEDFlashMask;
	tFlashInfoStructType DsblEnblLEDFlashInfo;
	uchar cMaxGMLANSignalsValueUpdateCnt;
	word wNeutralDeactiveDelayTime;
	word wBatteryVoltageOverSetDtcTime;
	word wBatteryVoltageUnderSetDtcTime;
	uchar cSendGMLANPowerUpInitSig;
	uchar cObjDisBufSize[PA_SYS_NUM];
	uchar cCheckGMLANSignalOutside_Air_Temperature_LS;
	uchar cShowTheNearestObjRegionAndZone;
	uchar cUPAInitialState;
	uchar cUPAODISupportJustTurnOnOffUPASys;
	uchar DisableTheEntireSytemWhenAttachedObjDtd;
	uchar cHapticSeatPresent;
	uchar cSpkeakerActivatedEvenHapticSeatIsPresent;
	uchar cHapticSeatVibrationReptition[PA_SYS_NUM][OBJ_MAX_ZONE_NUM];
	uchar cESSControllerPresent;// Enhanced safety system-->>electronic stop system
	uchar cSendGMLANSignalFrntPrkAstDrvSeatVibReqLS;
	uchar cSendGMLANSignalParkAssistESSbasedInfoLS;
	uchar cSendGMLANSignalRearPrkAstDrvSeatVibReqLS;
	uchar cVibrateOnlyOnceAtZone21;
	uchar cTeenParkAssistAlwaysOn;			

} PACalibrationDataType;
/*2.1************************************* OBJECT DETECTE STRUCTURE DEFINE END ************************************/

extern const PACalibrationDataType PACal;

#endif
