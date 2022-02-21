
#ifndef _OBJECT_PROCESS_H_
#define _OBJECT_PROCESS_H_

#ifdef OBJPROCESS
    #define EXTERN
#else
    #define EXTERN extern
#endif


#include "DataTypeDef.h"
#include "SlotParaCfg.h"
#include "Dem_IntErrId.h"

/*Start the Envelope Measurement*/
//#define ENVELOPE_MEASUREMENT
/*End the Envelope Measurement*/


/*Macro Define*/
#define DEBUG_ULTRASONIC_INTERFERENCE
#define SNS_OP_CMD_BIT_NUM												4
#define SNS_OP_CMD_WR_THRESHOLD_VALUE									0x0//0x01
#define SNS_OP_CMD_RD_THRESHOLD_SETUP									0xF  //Confirm
#define SNS_OP_CMD_RD_STATUS_VALUE										0x2  //Confirm
#define SNS_OP_CMD_WR_MEASUREMENT_SETUP									0x1  //Confirm
#define SNS_OP_CMD_RD_MEASUREMENT_SETUP									0x7  //Confirm
#define SNS_OP_CMD_RD_CAL_PULSE									        0x3  //Confirm
#define SNS_OP_CMD_RD_TEMPERATURE									    0x4  //Confirm
#define SNS_OP_CMD_ENVELOPE_SEND_A									    0x5  //Confirm
#define SNS_OP_CMD_ENVELOPE_REC_A									    0x6  //Confirm
#define SNS_OP_CMD_CALIBRATION_WR								        0x8  //Confirm
#define SNS_OP_CMD_CALIBRATION_RD								        0x9  //Confirm
#define SNS_OP_CMD_EE_COPY								                0xA  //Confirm
#define SNS_OP_CMD_EE_RD								                0xB  //Confirm

#define OBJPROCESS_APA_SENSOR_NUM                                       (4)
#define SNS_SUPPORT_MAX_BK_WV_INT_NUM									120

#define SNS_CAPTURE_INPUT_RISING_EDGE		  			0
#define SNS_CAPTURE_INPUT_FALLING_EDGE		  			1

#define SNS_CAPTURE_ALL_SNS_INPUT_RISING_EDGE		  	0
#define SNS_CAPTURE_ALL_SNS_INPUT_FALLING_EDGE		  	0xffff

#define SNS_BK_WV_BUF_SIZE                30

#define SNS_EMIT_TIME                     2
#define SNS_FIRST_EMIT                    0
#define SNS_SECOND_EMIT                   1

#define SNS_DT_VERY_CLOSE_OBJ_DISTANCE									500 // 500mm.


#define SENSOR_DETECTION_FAILURE														0
#define SENSOR_DETECTION_OK																1
#define SENSOR_SLIGHTLY_DISTURBED														2
#define SENSOR_BADLY_DISTURBED															3
#define SENSOR_APA_FAILURE										    					4

#define SENSOR_INPUT_CAPTURE_PORT_READ_TIMES						3
#define SNS_OP_CMD_DT_OBJ_ONE_CYCLE_TIME                                 (OBJECT_TIME31MS+OBJECT_TIME4MS+OBJECT_TIME2_3MS)  
#define SNS_EMIT_PULSE_DELAY_TIME_AFTER_RX_EMIT_CMD						OBJECT_TIME160US

#define SNS_PEAK_DETECT_DEAY_TIME_UPA_CMD						        OBJECT_TIME200US
#define SNS_PEAK_DETECT_DEAY_TIME_APA_CMD						        OBJECT_TIME350US


#define SNS_SUPPORT_OPERATION_MODE_NUM								3
#define SNS_SUPPORT_DT_CNT_PER_LOOP									4

#define SNS_SUPPORT_MEASUREMENT_CONFIGURATION_BIT_NUM				0
#define SNS_SUPPORT_CALIBRATION_DATA_BIT_NUM						34
#define SNS_SUPPORT_READ_STATUS_BIT_NUM								10

#define SNS_EEPROM_DATA_ALL_DATA_BIT_MASK							0x000fffff
#define SNS_OPERATING_DATA_SEND_REQ_NUM								3
#define SNS_OP_DATA_SEND_STATE_ALL_REQ_MASK						0x05

#define SNS_INIT_TYPE_NUM                                2

#define SNS_COMMUNCIATION_FREQ_INVALID  0X7F


#define SNS_SUPPORT_TOTAL_FAILED_TYPE_NUM      			9

#define SNS_FAILED_SHORT_TO_BATTERY_INDEX     			0
#define SNS_FAILED_SHORT_TO_GND_INDEX 		  			1
#define SNS_FAILED_BLOCKED_INDEX              			2
#define SNS_FAILED_RING_TIME_TOO_LONG_INDEX   			3
#define SNS_FAILED_NO_RING_TIME_OR_RING_TIME_TOO_SHORT_INDEX  4
#define SNS_FAILED_NO_BACK_WAVE_INDEX        			5
#define SNS_FAILED_SIGNAL_INVALID_INDEX		  			6
#define SNS_FAILED_COMPONENT_INCORRECT_INDEX  			7
#define SNS_FAILED_DISTURBED_INDEX 						8
#define SNS_FAILED_TYPE_INVALID_INDEX  					0x7F

#define DtObjDisableAllSnsInputCapture 					SnsIntp_DisableAllInt


#define SNS_INPUT_CAPTURE_ALL_CHANNEL_MASK                  0x0FFF

#define DTM_OBJ_POS_UNIT_FACTOR           10000
#define TWO_TIME_OF_ALL_OBJ_MAX_DIS             1000  /* unit : cm */
#define VEHICLE_SIDE_CUT_OFF_DIS_NUM            4
#define SNS_PAIR_NUM                            4
#define UNKNOWN_SNS_VERSION                           0xff
#define OBJ_DT_SPD_DIV                    5 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR /* Unit : Km/h */
#define OBJ_DT_TLR_TIME_LW_SPD            TIME500US
#define OBJ_DT_TLR_TIME_HI_SPD			  TIME1300US
#define UPA_SNS_DT_OBJ_DIS_TOL_WITHIN_40MS				170 // 170mm, with 15km/h: 40ms detect cycle.

#define PA_SNS_RING_TIME_TOO_LONG_CHECK_TIME			8000 /* 8s */

#define SNS_REINIT_DELAY_TIME							1000 /* 10s , 10ms loops */
                                           
#define bRSnsBlocked                   DtAndDtmObjLocFlag[PARearSys].Bits.BIT0
#define bRSnsDstbd                     DtAndDtmObjLocFlag[PARearSys].Bits.BIT1
#define bRUPASnsFail                   DtAndDtmObjLocFlag[PARearSys].Bits.BIT2
#define bRSnsRingTimeTooLong           DtAndDtmObjLocFlag[PARearSys].Bits.BIT3

#define bFSnsBlocked                   DtAndDtmObjLocFlag[PAFrontSys].Bits.BIT0
#define bFSnsDstbd                     DtAndDtmObjLocFlag[PAFrontSys].Bits.BIT1
#define bFUPASnsFail                   DtAndDtmObjLocFlag[PAFrontSys].Bits.BIT2
#define bFSnsRingTimeTooLong           DtAndDtmObjLocFlag[PAFrontSys].Bits.BIT3


#define bRSnsWallDtd                   		DtAndDtmObjLocFlag1[PARearSys].Bits.BIT0
#define bRSnsReInitedDueToSnsDisturbed 		DtAndDtmObjLocFlag1[PARearSys].Bits.BIT1
#define bRSnsReInitedDueToLowTemperature	DtAndDtmObjLocFlag1[PARearSys].Bits.BIT2
#define bSBSASnsNeedDoubleCheck				DtAndDtmObjLocFlag1[PARearSys].Bits.BIT3

#define bFSnsWallDtd                   		DtAndDtmObjLocFlag1[PAFrontSys].Bits.BIT0
#define bFSnsReInitedDueToSnsDisturbed 		DtAndDtmObjLocFlag1[PAFrontSys].Bits.BIT1
#define bFSnsReInitedDueToLowTemperature	DtAndDtmObjLocFlag1[PAFrontSys].Bits.BIT2

#define bAPASensorParSuccessfullyInited		DtAndDtmObjLocFlag2.Bits.BIT0
#define bUPASensorParSuccessfullyInited		DtAndDtmObjLocFlag2.Bits.BIT1
#define bSensorFailTypeDTCHasBeenSet        DtAndDtmObjLocFlag2.Bits.BIT2  
#define bPowerUpSnsParInitHasBeenDelayed	DtAndDtmObjLocFlag2.Bits.BIT3
#define bSnsParInitFailed					DtAndDtmObjLocFlag2.Bits.BIT4
#define bAPASnsParInitFailed                DtAndDtmObjLocFlag2.Bits.BIT5
#define bUPASnsParInitFailed                DtAndDtmObjLocFlag2.Bits.BIT6

#define bFRAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT0
#define bFLAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT1
#define bRRAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT2
#define bRLAPASnsDtdObjDisUpdated                       APAObjDisUpdateFlag.Bits.BIT3
#define bRRCUPASnsDtdObjDisUpdated                      APAObjDisUpdateFlag.Bits.BIT4 // Rear Right Corner sensor.
#define bRLCUPASnsDtdObjDisUpdated                      APAObjDisUpdateFlag.Bits.BIT5 // Rear Left Corner sensor.

/*Data type Define*/
typedef enum 
{

	SNS_SIG_LINE_OP_CMD_SET_ALL_SNS_SIG_LINE_HIGH = 0,
	SNS_SIG_LINE_OP_CMD_TX_SIGNAL

} tSnsSignalLineOpCmdType;


typedef union 
{
	unsigned long long dwEEPROMData;
	unsigned char cEEPROMData[8];
	struct 
	{
		unsigned long long F_DRV		 :8;// Byte 7
		unsigned long long I_DRV		 :5; 
		unsigned long long G_ANA 	     :3;
		unsigned long long G_DIG	     :7;
		unsigned long long CUSTOMERBITS  :7;
		unsigned long long OSC_TRIM		 :4; 
		unsigned long long Reserved		 :30;
	} Bits;
	
	struct 
	{
		unsigned long long UnderVoltageDetected		    :1; // Byte 7, bit 0
		unsigned long long OverVoltageDetected		    :1; // Byte 7, bit 1
		unsigned long long IsLastMeasureWrSuccessful    :1; // Byte 7, bit 2
		unsigned long long IsLastThresWrSuccessful		:1; // Byte 7, bit 3
		unsigned long long IsFreqMeasResultValid	    :1; // Byte 7, bit 4
		unsigned long long FreqDeviationValue			:5; // byte 7 & 6 
		unsigned long long Reserved						:54;
	} ReadStatusBits;
	
} tSnsEEPROMDataType;


typedef struct
{

	uchar cSnsOpCmd[PA_SYS_NUM][PA_REAR_SNS_NUM];
	uchar *pSnsData;
	uchar cCurBitIndex;
	uchar cSnsOpCmdTxBitCnt;
	uchar cDataBitIndex;
	uchar cDataCnt;
	word wDataAddr;
	uchar cDataTxTryCnt;
	uchar cDataRxTryCnt;
	uchar cCheckSum[PA_SYS_NUM][PA_REAR_SNS_NUM];
	uchar cReadStatusBitIndex[SNS_INPUT_CAPTURE_CHANNEL_NUM];
	tSnsEEPROMDataType SnsEEPROMData[SNS_INPUT_CAPTURE_CHANNEL_NUM];
	word wPrevSnsBkWvTime[SNS_INPUT_CAPTURE_CHANNEL_NUM];
} tSnsOpInfoType;


typedef union 
{
	word  wSnsBkWvTime[SNS_INPUT_CAPTURE_CHANNEL_NUM][SNS_BK_WV_BUF_SIZE];
	tSnsOpInfoType SnsOpInfo;
} tSnsDtBufType;

typedef enum
{
	SnsOpCmdSnsOff = 0,
	SnsOpCmdDtObj,      
	SnsOpCmdThresholdProgramming,
	SnsOpCmdReadStatus,
	SnsOpCmdCalibrationWrite,
	SnsOpCmdCalibrationRead,
	SnsOpCmdMeasurementSetup,
	SnsOpCmdEnvelopeMeasurement,
	SnsOpCmdThresholdRead,
	SnsOpCmdMeasurementRead

} tSnsOperationCmdType;

typedef enum
{

	SnsOpModeUPA = 0,
	SnsOpModeAPASearchingSlot,
	SnsOpModeSBSA
	
} tSnsOperationModeType;

typedef enum { 
	//VEHICLE_SPEED_NO_ZONE,
	VEHICLE_SPEED_ZONE1 = 0,
	VEHICLE_SPEED_ZONE2 ,
	VEHICLE_SPEED_ZONE3 , 
	VEHICLE_SPEED_ZONE4 ,
	VEHICLE_SPEED_ZONE5 ,
	VEHICLE_SPEED_ZONE6 

} tSnsInitDueToSpeedType;
typedef enum {

	//TEMPERATURE_NO_ZONE ,
	TEMPERATURE_ZONE1 = 0,
	TEMPERATURE_ZONE2,
	TEMPERATURE_ZONE3,
	TEMPERATURE_ZONE4,
	TEMPERATURE_ZONE5,
	TEMPERATURE_ZONE6
	
} tSnsInitDueToTempType;
#define TEMPERATURE_ZONE_DEFAULT TEMPERATURE_ZONE3


typedef union 
{
	uchar cState;
	struct 
	{
		uchar SnsThresholdDataReqSent			:1;
		uchar SnsEEPROMDataReqSent				:1;
		uchar SnsMeasurementConfigDataReqSent	:1;
		uchar Reserved							:5;
	} Bits;

} tSnsOperatingDataSendStateType;

typedef enum
{

    SNS_DATA_SEND_SEQ_IDLE = 0,
    SNS_DATA_SEND_SEQ_DELAY_TO_INIT,
    SNS_DATA_SEND_SEQ_INIT,
	SNS_DATA_SEND_SEQ_TX_CMD,
	SNS_DATA_SEND_SEQ_TX_DATA_BIT_START,
	SNS_DATA_SEND_SEQ_TX_DATA_BIT_LOGIC1_TIMEOUT,
	SNS_DATA_SEND_SEQ_TX_DATA_BIT_LOGIC0_TIMEOUT,
	SNS_DATA_SEND_SEQ_DATA_OK,

	SNS_DATA_RECEIVE_SEQ_START,
	SNS_DATA_RECEIVE_SEQ_DATA_RX,
	SNS_DATA_RECEIVE_SEQ_OK,

	SNS_OBJ_DT_SEQ_PAR_INIT,
	SNS_OBJ_DT_SEQ_EMIT_REQUEST,
	SNS_OBJ_DT_SEQ_WAIT_FOR_NEXT_SNS_EMIT,
	SNS_OBJ_DT_SEQ_SNS_EMIT_REQUEST_WAIT,
	SNS_OBJ_DT_SEQ_PROCESS_RX_DATA,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_1,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_2,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_3,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_4,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_5,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_6,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_7,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_8,
	SNS_OBJ_DT_SEQ_RX_DATA_POST_PROCESS_SES_DIAGNOSIS
	
} tSnsOperationSequenceType;

typedef enum
{

    SNS_READ_STATUS_SEQ_INIT = 0,
	SNS_READ_STATUS_SEQ_TX_CMD,
	SNS_READ_STATUS_SEQ_RX_DATA,
	SNS_READ_STATUS_SEQ_OK
	
}tSnsThresholdDataSendSequenceType;

typedef enum 
{          

	SNS_COMMUNCIATION_FREQ_NOMRAL= 0,
	SNS_COMMUNCIATION_FREQ_MIN,
	SNS_COMMUNCIATION_FREQ_MAX
	
} tSnsCommunicationLowPulsevalueType;

typedef enum
{          

	SnsInitSequenceAPASnsInit = 0,
	SnsInitSequenceUPASnsInit
	
} tSnsInitSequeceType;

typedef struct
{
	word wDis[UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE];
	SINT16 wX[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE]; /* Horrizontal distance of the obj */
	word wY[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM][UPA_SNS_DT_OBJ_BUF_SIZE]; /* Distance between the Obj and the bumper */
} tDtObjUPASnsDtObjDisInfoType;

typedef struct
{
	word wDis[UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
	SINT16 wX[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM]; /* Horrizontal distance of the obj */
	word wY[UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM]; /* Distance between the Obj and the bumper */
} tDtObjSnsDtObjNearestDisInfoType;

/* global variable */
EXTERN    uchar  cSnsOperatingCmdSendDelayTime;
EXTERN    uchar  cSnsOperatingCmd;
EXTERN    uchar  cSnsPreOperatingCmd;
EXTERN    uchar  cDtObjSnsOperatingMode;
EXTERN    uchar  cSnsOpSequence;
EXTERN    tSnsDtBufType  SnsDtBuf;
EXTERN    tSnsEEPROMDataType  SnsEEPROMData[PA_SYS_NUM][PA_REAR_SNS_NUM];
EXTERN    uchar  cSnsOperatingState[PA_SYS_NUM];
EXTERN    uchar  cSnsOpSnsMask[PA_SYS_NUM]; // RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
EXTERN    uchar  cSnsPreOpSnsMask[PA_SYS_NUM]; // RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
EXTERN    uchar  cSnsOpSnsSignalLineLevelMask[PA_SYS_NUM]; // RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
EXTERN    word  wSnsInputCaptureEdge;
EXTERN    uchar  cSnsInputCaptureIntCnt[SNS_INPUT_CAPTURE_CHANNEL_NUM];
EXTERN    uchar  cSnsInputCaptureIntWriteCnt[SNS_INPUT_CAPTURE_CHANNEL_NUM];
EXTERN    word  wSnsInputChannelLowLevel;
EXTERN    word  wSnsInputChannelHighLevel;
EXTERN    word  wSnsCheckFailedAtCurDetection[SNS_SUPPORT_TOTAL_FAILED_TYPE_NUM];
EXTERN    uchar  cSnsFailCnt[PA_SYS_NUM][SNS_SUPPORT_TOTAL_FAILED_TYPE_NUM][PA_REAR_SNS_NUM];
EXTERN    uchar  cAPASnsDtObjBufWrIndex;
EXTERN    uchar  cCurrentDetectionTotalNoisePulseNum[SNS_INPUT_CAPTURE_CHANNEL_NUM];
EXTERN    word   wCurrentDetectionTotalNoiseBackWaveWidth[SNS_INPUT_CAPTURE_CHANNEL_NUM];
EXTERN    word   wCurrentDetectionTotalWallBackWaveWidth[SNS_INPUT_CAPTURE_CHANNEL_NUM];
EXTERN    uchar  cSnsEmitLoopCnt[PA_SYS_NUM];
EXTERN    uchar  cSnsEmitCnt[PA_SYS_NUM];		// At current detection, how many counts for the current sensor has been emited.
EXTERN    uchar  cSnsDtObjNum[SNS_INPUT_CAPTURE_CHANNEL_NUM][SNS_EMIT_TIME];
EXTERN    uchar  cSnsVersion[PA_SYS_NUM][PA_REAR_SNS_NUM];
EXTERN    word  wSnsRingTimeRealTime[PA_SYS_NUM][PA_REAR_SNS_NUM];		
EXTERN    word  wSnsNormalRingTime[PA_SYS_NUM][PA_REAR_SNS_NUM];		
EXTERN    uchar  cSnsRingTimeUpdateCnt[PA_SYS_NUM];
EXTERN    word  wSnsRingTimeCheckTimer[PA_SYS_NUM];
EXTERN    uchar  cSnsDtObjDataProcessIndex[PA_SYS_NUM];
EXTERN    uchar  cSnsCommnicationFreqStatus[SNS_INIT_TYPE_NUM]; 
EXTERN    uchar  cSnsCommnicationFreqStatusIfOKSnsIsExsiting[SNS_INIT_TYPE_NUM]; 
EXTERN    uchar  cSnsTypeInitSequence; 
EXTERN    uchar  cTemperatureZone;
EXTERN    uchar  cPrevTemperatureZone;
EXTERN    uchar  cVehicleSpeedZone;
EXTERN    uchar  cPreviousVehicleSpeedZone;
EXTERN    word   wDistanceCoefficient;



EXTERN    uchar  cDtObjDataProcessLoop;
EXTERN    uchar  cDtObjToBeProcessedSysType;
EXTERN    word  wProcessedObjNearestDis[PA_SYS_NUM];
EXTERN    uchar  cDtObjProcessedResult;
EXTERN    word  wProcessedObjDisArray1[6];
EXTERN    word  wProcessedObjDisArray2[6];
EXTERN    SINT16  siProcessedObjHDisDtd1[2];
EXTERN    SINT16  siProcessedObjHDisDtd2[2];
EXTERN    uchar  cProcessedObjIndex1;
EXTERN    uchar  cProcessedObjIndex2;
EXTERN    word  wProcessedObjBeingDtdDis[4][SNS_SUPPORT_MAX_DT_OBJ_NUM];
EXTERN    word  wUPASnsDtObjDisUpdatedFlag[PA_SYS_NUM];    /* Bit 0 - 9 --- UPA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM */
EXTERN    word  wAppDescUPASnsDtObjDisUpdatedFlag[PA_SYS_NUM];    /* Bit 0 - 9 --- UPA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM */
EXTERN    uchar  cUPASnsDtTriObjDisUpdatedFlag[PA_SYS_NUM];    /* Bit 0 - 5 --- UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM */
EXTERN    uchar  cSnsRingTimeTooLongIGNCnt[PA_SYS_NUM][PA_REAR_SNS_NUM];

EXTERN    word  wTotalSnsDetectObjectTime; 


EXTERN    uchar  cAPASnsObjDtCnt[PA_SYS_NUM][2];
EXTERN    uchar  cAPASnsNoObjDtCnt[PA_SYS_NUM][2];
EXTERN    SINT16  wAPASnsDtdPrevObjDis[PA_SYS_NUM][2];
EXTERN    uchar  cPrevObjDetectSequence;
EXTERN    uchar  cSnsDisturbedCounter[PA_SYS_NUM];
EXTERN    uchar  cDegradedModePASnsMask[PA_SYS_NUM]; /* Bit0 ~ Bit7: RS, R, RM, LM, L, LS */  // Active sensor by Calibration
EXTERN    word  wObjBeingDtdTime[SNS_INPUT_CAPTURE_CHANNEL_NUM][SNS_SUPPORT_MAX_DT_OBJ_NUM];
EXTERN    tDtObjUPASnsDtObjDisInfoType  DtObjUPASnsDtObjDisInfo[PA_SYS_NUM];
EXTERN    tDtObjSnsDtObjNearestDisInfoType  SnsDtObjNearestDisInfo[PA_SYS_NUM];
EXTERN    tByteBitType  APAObjDisUpdateFlag; /* APA    Bit0-1  FLS  FRS*/
EXTERN     uchar  cSnsBlockedFlag[PA_SYS_NUM];
EXTERN    uchar  cSnsDstbdFlag[PA_SYS_NUM];
EXTERN    uchar  cSnsSigInvalidFlag[PA_SYS_NUM];
EXTERN    tByteBitType  DtAndDtmObjLocFlag[PA_SYS_NUM];
EXTERN    tByteBitType  DtAndDtmObjLocFlag1[PA_SYS_NUM];
EXTERN    tByteBitType  DtAndDtmObjLocFlag2;
EXTERN    uchar  cObjLessThan30cmDetectedFlag[PA_SYS_NUM];
EXTERN    uchar  cSnsDataRxFailed[PA_SYS_NUM];
EXTERN    uchar cSnsRainDtFor3TimeCompareLoopCnt[PA_SYS_NUM];
EXTERN    word   wSnsRingTimeHasBeenProcessedFlag;
EXTERN    tSnsOperatingDataSendStateType  cSnsOperatingDataSendState;
EXTERN SINT16 APASideSnsDtObjDisBuf[PA_SYS_NUM][2][25];

EXTERN diagnosticTypedef g_Diagnostic[12];

EXTERN BOOLEAN bEnableSnsRegsReadCmdFlag;
EXTERN SnsRegsReadCmdType  SnsRegsReadCmd;
EXTERN BOOLEAN  SnsRegsReadCmdSendFlag;
extern BOOLEAN g_SnsInitOverCntFlg;

/* Function Definition */
unsigned int  ussDisDebouncing(unsigned int  dis, PASysSnsIndexType SnsIndex);
void ElmosCtl_TimerInterrupt(void);
void ObjectProcessMainTask_Bg(void);
uchar DtObjGetTemperatureZoneToInitSensor(schar cAirTemperature, uchar cPreviousTempZone); 
uchar DtObjGetVehicleSpeedZoneToInitSensor(word wVehicleSpeed, uchar cPreviousSpeedZone); 
void ElmosCtl_SensorInputInterrupt(unsigned char index);
word GetDeltaLength(word wDis1, word wDis2, uchar cFlag);
void DtObjSaveSnsDtdObjTime(uchar cChannelIndex, uchar cSysType, word wTime, BOOLEAN bSnsEmitPulse, BOOLEAN bSnsRingTimeTooLong); 
word DtObjCalObjAssumedDis(word wDisBetweenTwoSns, word wDis);
void DtObjSnsDiagnosis(void);
void DtObjRxDataPostProcess_1(void);
void DtObjRxDataPostProcess_2(void);
void DtObjRxDataPostProcess_3(void);
void DtObjRxDataPostProcess_4(void);
void DtObjRxDataPostProcess_5(void);
void DtObjRxDataPostProcess_6(void);
void DtObjRxDataPostProcess_7(void);
void DtObjSaveSnsDtdObjTime(uchar cChannelIndex, uchar cSysType, word wTime, BOOLEAN bSnsEmitPulse, BOOLEAN bSnsRingTimeTooLong);
void DtObjAPASnsDtObjDisProcess(void);
void DtObjSensorDTCCheck(void);
void DtObjInitUPASnsDtObjDisInfo(uchar cSysType);
uchar DtObjGetVehicleSpeedZoneToInitSensor(word wVehicleSpeed, uchar cPreviousSpeedZone); 
SINT8 DtObjGetSnsInitThreshold(uchar cData, uchar cDataCnt, SINT8 DeltaThresholdTemp, SINT8 DeltaThresholdSpeed);
void ObjDetect_SequenceFlowParInit(void);
void DtObjSetSnsSignalLineLevel(uchar cCmd,SINT16 siDelayTime) ; 
void DtObjSnsEmitRequest(void);
void DtObjSnsInputPortStatusRead(void);
void DtObjProcessSnsEchoData(void);
uchar DtObjCheckIfTheNonTriObjIsWithinFOV(word wDis, uchar cObjIndex);
uchar DtObjCheckIfTheTriObjIsWithinFOV(word wDis, SINT16 siHDis, uchar cObjIndex);
uchar DtObjCheckIfTheObjIsWithinFOV(uchar cSaveObjDis);
uchar DtObjDtmObjHPosition(word wDisArray2[3], 
	SINT16 siHDis2, 
	uchar cSnsIndexMain, 
	uchar cSnsIndexSub, 
	uchar cFlag,
	uchar cObjDisArrayState); 
uchar DtObjGetProcessedObjDisArrayState(void);
uchar DtObjGetVehicleSpeedZoneToInitSensor(word wVehicleSpeed, uchar cPreviousSpeedZone);
SINT8 DtObjGetSnsInitThreshold(uchar cData, uchar cDataCnt, SINT8 DeltaThresholdTemp, SINT8 DeltaThresholdSpeed);
void DtObjGetSnsSignalLineOpMask(void); 
word GetDeltaLength(word wDis1, word wDis2, uchar cFlag);
void ElmosCtrl_EmitRequest(void);
void DtObjSnsDataSendCmdInit(void);
void DtObjSnsOpCmdReadDataCompleteDataProcess(void);

#ifdef DEBUG_ULTRASONIC_INTERFERENCE
//unsigned int ObjDetect_GetApaSensorDetectedDistanceAddDebouncing(ObjectProcApaSensorIndex index);

#define DIS_BUFFER_MAX						30
#define FETCH_DIS_BUFFER_MAX_INDEX 			(DIS_BUFFER_MAX-1)
//#define FETCH_DIS_BUFFER_MIN_INDEX			15
#define FETCH_DIS_BUFFER_LEN					20
#define THRESHOLD_AMOUNT					(FETCH_DIS_BUFFER_LEN/4)
#define DIS_TOLERANCE_VALUE					200
#define DIS_TOLERANCE_CNT_MAX				4

void DatBubbleSort(unsigned int dis[DIS_BUFFER_MAX]);
#endif

#undef EXTERN

#endif 
