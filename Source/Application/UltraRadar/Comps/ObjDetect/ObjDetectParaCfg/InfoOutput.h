#ifndef _INFOOUTPUT_H_
#define _INFOOUTPUT_H_

/* Determine driver information output */

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"
#include "ObjectProcess.h"

/* 200cm. */
#define DIS_SAMPLE_MAX              2000
#define DIS_SAMPLE_MAX_DISTORTION   1
/* 40cm. */
#define DIS_SAMPLE_MIN              400
#define DIS_SAMPLE_MIN_DISTORTION   58



typedef struct{
	uchar cSysStatus;
	uchar cNearestZone;
	uchar cZone[REGION_NUM];
	word wDis[REGION_NUM];
	word wNearestDis;
}tObjInfoStructType;

typedef enum{
	CHIME_ZONE1 = 0,
	CHIME_ZONE2,
	CHIME_ZONE3,
	CHIME_ZONE4,
	CHIME_ZONE5,
	CHIME_ZONE6,
	CHIME_ZONE7,
	CHIME_ZONE8,
	CHIME_ZONE9,
	CHIME_ZONE10,
	CHIME_ZONE11,
	CHIME_ZONE12,
	CHIME_ZONE13,
	CHIME_ZONE14,
	CHIME_ZONE15,
	CHIME_REV_ROGER,
	CHIME_FWD_ROGER,
	CHIME_FIRST_REPORT,
	CHIME_PA_FAILED,
	CHIME_APA_ACTIVATED_PARALLEL_IN,
	CHIME_APA_ACTIVATED_PERPEN_IN,
	CHIME_APA_ACTIVATED_PARK_EXIT,
	CHIME_APA_SLOT_FOUND,
	CHIME_APA_ENTER_AUTO_PARKING,
	CHIME_APA_STOP_COMMAND,
	CHIME_APA_PARKING_FAILED,
	CHIME_APA_DEACTIVATED,
	CHIME_APA_PARKING_SUCESS,
	CHIME_SBSA_OBJ_DET_TURNING_LIGHT_ON,	
	CHIME_STOP
} tSpeakerChimeCmdType;								

typedef union{
  word wEvent;
  struct{
		word PASwPressed: 1;
  	word IntoReverse: 1;
  	word IntoFwd: 1;
  	word PAStatusChanged: 1;
  	word IntoPark: 1;
  	word RvsSpdTooHigh: 1;
  	word FwdSpdTooHigh: 1;
  	word OutOfPark: 1;
  	word OutOfReverse: 1;
  	word Unused: 7;
  }bEvent; 
} tDtmDrvInfoOutputEventType;

typedef enum{
 	PASwPressedEventIndex = 0,
	IntoReverseEventIndex,
	IntoFwdEventIndex,
	PAStatusChangedEventIndex,
	IntoParkEventIndex,
	RvsSpdTooHighEventIndex,
	FwdSpdTooHighEventIndex,
	OutOfParkEventIndex,
	OutOfReverseEventIndex	
} tDtmDrvInfoOutputEventIndexType;

typedef struct{
  uchar cFlashNum;
  uchar cFlashOnTime;
  uchar cFlashOffTime;
} tFlashInfoStructType;

typedef struct{
  tFlashInfoStructType FlashInfo;
  uchar cFlashOnTimer;
  uchar cFlashOffTimer;
} tFlashTimerType;

typedef struct{
	uchar cFlashOnTimer;
	uchar cFlashOffTimer;
} tDisplayLEDFlashTimerType;

typedef union{
 	uchar cFlag;
	struct{
		uchar SendSignal: 1;
		uchar CmdAck: 1;
		uchar NewChimeCmd: 1;
		uchar ChimeStopDueToChimeOnTimerTimeOut: 1;
		uchar RequestedChmCmdAcked: 1;
		uchar Unused: 3;
	}bFlag; 
} tSpeakerTaskFlagType;


typedef struct{
	_c_Chime_Command_buf ChimeCmdBuf;
  uchar cDutyCycle;
  word wSndFreq;
  word wHighLevelTime;
  word wLowLevelTime;
} tSoundInfoStructType;


typedef struct{
	uchar cPrevCmd;
	tSpeakerTaskFlagType TaskFlag;
	word wChimeHighLevelTimer;
	word wChimeLowLevelTimer;
	word wChimeOnTimer;
	uchar cNmOfRep;
	tSoundInfoStructType SoundInfo;
} tSpeakerChimeInfoType;

typedef enum
{
	ROAD_STATE_INIT,
	ROAD_STATE_NORMAL,
	ROAD_STATE_BUMP
}VehicleMovingRoadStates;

	
#define DTM_DRV_INFO_OUTPUT_EVENT_NUM									7  /* Except for "OutOfPark and OutOfReverse */

#define LED_ALL_OFF																		0
#define LED_ALL_ON																		1
#define ALL_LED_FLASH																	2
#define LED_AMBER1_AMBER2_ON													3
#define LED_AMBER2_ON																	4
#define LED_AMBER1_ON																	5
#define LED_RED_ON																		6
#define LED_FLASH_FAIL																7
#define LED_TEST																			8
#define RED_LED_FLASH																	9

extern tDtmDrvInfoOutputEventType  DtmDrvInfoOutputEvent;
extern uchar  cSpeakerPinLevel[PA_SYS_NUM];
extern tSpeakerChimeInfoType  SpeakerChimeInfo[PA_SYS_NUM];
extern tObjInfoStructType  ObjInfo[PA_SYS_NUM];
extern  uchar  cWallDetectedFlag[PA_SYS_NUM][2];
extern uchar  cLEDTestHighLevelCnt;
extern uchar  cLEDTestLowLevelCnt;
extern uchar  cDisplayLEDSelectCnt;
extern uchar  cDisplayLEDState;
extern word  wRearSpeakerHighPulseTime;
extern word  wRearSpeakerLowPulseTime;
extern tWordBitType  DtmDrvInfoOutputFlag;
#define bTeenDrvAct									DtmDrvInfoOutputFlag.Bits.BIT8	
#define bTeenDrvPrkAstOffUnbIO						DtmDrvInfoOutputFlag.Bits.BIT9	
extern signed short abs(signed short);


typedef enum {
	SBSA_LED_FAIL_SHORT_TO_BAT = 0,
	SBSA_LED_FAIL_SHORT_TO_GND,
	SBSA_LED_FAIL_OPEN
} tSBSALedFailType;

extern uchar  SpeakerStopChimeCmdReqTxFlag; 

typedef enum {
	OBJ_ABSENT = 0,
	OBJ_APPROACHING,
	OBJ_STATIC,
	OBJ_DESCENDING
} ObjStateType;

extern uchar   cWallDetectedFlag[PA_SYS_NUM][2];

extern uchar  cNonTriObjState[PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cNonTriObjStaticTimer[PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cNonTriObjNotDetectedTimer[PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cNonTriObjBeingDtdCnt[PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];
extern word  wNonTriObjPrevDis[PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];

extern uchar  cTriObjState[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cTriObjStaticTimer[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cTriObjNotDetectedTimer[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
extern uchar  cTriObjBeingDtdCnt[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
extern word  wTriObjPrevDis[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];

extern tObjInfoStructType  ObjInfo[PA_SYS_NUM];
extern tObjInfoStructType  ObjInfoSent[PA_SYS_NUM];


extern uchar   cObjPrevZone[PA_SYS_NUM];

extern uchar  cNearestObjState[PA_SYS_NUM];

extern word g_warnZoneDis[PA_SYS_NUM][REGION_NUM-1];

extern VehicleMovingRoadStates CurrentMovingRoadState;


void ObjDetect_InfoOutParInit(void);
void InitObjInfo(uchar cSysType);
/*
** ===================================================================
**     Method      :  DtmDrvInfOutput(void)
**
**     Description :
**         Determine driver information output accroding to the PA
**         operating state.
**     Parameters  :
**         NAME            - DESCRIPTION
**        none             - ---
**     Returns     :
**         none             
** ===================================================================
*/											
void DtmDrvInfOutputTask(void);

void DisplayLEDDiagnosisTask(void);
void DisplayLEDDiagnosisLEDSelection(void);
void DisplayLEDDiagnosisLEDCaptureInit(void);
void DisplayLEDTask(void);
void SpeakerTask(void);
void SpeakerFeedBackPinCheck(uchar cSysType, uchar cSpeakerFeedBackPin);

void SBSALedFeedBackPinCheck(uchar SideIndex);

void BikeRackDetectionTask(void);
void TrailerDetectionTask(void);
void ObjectDetect_DataProcess_Main_T10(void);                                                    
void SendChimeCmdSignals(_c_Chime_Command_buf *ChimeCmdBuf);
uchar InfoOutput_GetZone(word wDis, uchar cSysType, uchar cPrevZone);

unsigned int ObjDetect_GetRlsNearestObjDis(void);
unsigned int ObjDetect_GetRrsNearestObjDis(void);
unsigned int ObjDetect_GetFlsNearestObjDis(void);
unsigned int ObjDetect_GetFrsNearestObjDis(void);
unsigned int ObjDetect_GetRlNearestObjDis(void);
unsigned int ObjDetect_GetRrNearestObjDis(void);
unsigned int ObjDetect_GetFlNearestObjDis(void);
unsigned int ObjDetect_GetFrNearestObjDis(void);
unsigned int ObjDetect_GetRrmNearestObjDis(void);
unsigned int ObjDetect_GetRlmNearestObjDis(void);
unsigned int ObjDetect_GetFrmNearestObjDis(void);
unsigned int ObjDetect_GetFlmNearestObjDis(void);

unsigned int ObjDetect_GetRlsNearestObjDis_AddCoefficient(void);
unsigned int ObjDetect_GetRrsNearestObjDis_AddCoefficient(void);
unsigned int ObjDetect_GetFlsNearestObjDis_AddCoefficient(void);
unsigned int ObjDetect_GetFrsNearestObjDis_AddCoefficient(void);


unsigned int ObjDetect_GetRmidNearestObjDis(void);
unsigned int ObjDetect_GetFmidNearestObjDis(void);


/* Debug UPA_L_R-distance. */
unsigned int GetDistance_FLtx_FLrx(void);
unsigned int GetDistance_FLtx_FLMrx(void);
unsigned int GetDistance_FLMtx_FLMrx(void);
unsigned int GetDistance_FLMtx_FLrx(void);
unsigned int GetDistance_FRtx_FRrx(void);
unsigned int GetDistance_FRtx_FRMrx(void);
unsigned int GetDistance_FRMtx_FRMrx(void);
unsigned int GetDistance_FRMtx_FRrx(void);

unsigned int GetDistance_RLtx_RLrx(void);
unsigned int GetDistance_RLtx_RLMrx(void);
unsigned int GetDistance_RLMtx_RLrx(void);
unsigned int GetDistance_RRtx_RRrx(void);
unsigned int GetDistance_RRtx_RRMrx(void);
unsigned int GetDistance_RRMtx_RRrx(void);

unsigned int GetDistance_RLMtx_RLMrx(void);
unsigned int GetDistance_RRMtx_RRMrx(void);
unsigned int GetDistance_RLMtx_RRMrx(void);
unsigned int GetDistance_RRMtx_RLMrx(void);

/* Large FOV object distance. */
unsigned int getUssRrObjDis(void);
unsigned int getUssRrmObjDis(void);
unsigned int getUssRlmObjDis(void);
unsigned int getUssRlObjDis(void);
unsigned int getUssFrObjDis(void);
unsigned int getUssFrmObjDis(void);
unsigned int getUssFlmObjDis(void);
unsigned int getUssFlObjDis(void);
void CalUssSensorOutPutObjDistance(void);


/* debug FM/FM distance. */
unsigned int Get_distance_FRMtx_FRMrx(void);
unsigned int Get_distance_FRMtx_FLMrx(void);
unsigned int Get_distance_FLMtx_FLMrx(void);
unsigned int Get_distance_FLMtx_FRMrx(void);
unsigned int GetFmid_distance_TriangleMin(void);

VehicleMovingRoadStates InfoOuputVehicleSpeedFeatureAnalyse(void);
unsigned int InfoOutputSensorDistancePDCFilterHandler(unsigned int SensorDis, PASysSnsIndexType SensorIndex);
unsigned int InfoOutputSensorDistanceControlFilterHandler(unsigned int SensorDis, PASysSnsIndexType SensorIndex);
unsigned int getUssFrObjDisForPDC(void);
unsigned int getUssFrmObjDisForPDC(void);
unsigned int getUssFlmObjDisForPDC(void);
unsigned int getUssFlObjDisForPDC(void);
unsigned int getUssRrObjDisForPDC(void);
unsigned int getUssRrmObjDisForPDC(void);
unsigned int getUssRlmObjDisForPDC(void);
unsigned int getUssRlObjDisForPDC(void);
unsigned int getUssFrObjDisForControl(void);
unsigned int getUssFrmObjDisForControl(void);
unsigned int getUssFlmObjDisForControl(void);
unsigned int getUssFlObjDisForControl(void);
unsigned int getUssRrObjDisForControl(void);
unsigned int getUssRrmObjDisForControl(void);
unsigned int getUssRlmObjDisForControl(void);
unsigned int getUssRlObjDisForControl(void);

unsigned int getRMRechoHeight(void);
unsigned int getRMLechoHeight(void);

unsigned int getSnsDiagnosticStatus(PASysSnsIndexType SnsIndex);

unsigned long long ObjDetect_GetObjdetectLibVersion(void);
void ObjDetectSetEnableSnsRegsReadCmdFlag(BOOLEAN bool);
void ObjDetectReadSnsRegs(SnsRegsReadCmdType RegsReadCmd,BOOLEAN bChangeStatFlag);
SnsRegsReadCmdType ObjDetectGetSnsRegsReadCmdType(void);
BOOLEAN ObjDetectGetEnableSnsRegsReadCmdFlag(void);

/* Other module use. */
void ReqReinitSns(void);
unsigned char GetSnsStatus(void);

/* Current module use. */
unsigned char GetReqToReinitCmd(void);
void SetSnsStatus(void);


#endif		 /* ifndef DTM_OBSTACLE_ST_H */
