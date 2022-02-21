/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                			     *
*                 All Rights Reserved.                                 						     *
*   Department : CT_ITTI_HZ                                         						     *
*   AUTHOR     :                                       									     *
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
* Version       	Date    			Name    			Changes and comments
* ----------------------------------------------------------------------
* 
*======================================================*/
#include "CONFIG.H"
#include "TYPES.H"
#include <Tools.h>
#include "Cansig_cfg_if.h"
#include "Core_Cfg.h"
#include "CpuUsageRate.h"
#include "OSAdapter_if.h"
#include "CanAPPApa.h"
#include "com_cfg.h"
#include "InputSignalProc.h"
#include "SlotParaCfg.h"
#include "CanAppUltraRadar_IF.h"
#include "ObjDetect_Pub.h"
#include "UltraRadarObjDetect.h"
#include "UltraRadarDriver.h"
#include "UssObjDetInterface.h"
#include "InfoOutput.h"

/*---Global-----------------------------------------------------------*/
extern void ElmosStateMachine_T10(void);
extern void ObjectDetectStateMachine_T10(void);
extern void ObjectDetect_DataProcess_Main_T10(void);
extern void InputSignal_ProcessMain_T10(void);
extern void SlotSearchingFunctionStateMachine(void);
extern void SnsBkSig_SnsFrameInfoClear(uchar cChannelIndex);
void UltraRadarDiagnosticMsg(void);

/*---Global--variable-----------------------------------------------------------*/

U8 FL_WarnZone_Msg;
U8 FML_WarnZone_Msg;
U8 FMR_WarnZone_Msg;
U8 FR_WarnZone_Msg;
U8 Fmid_WarnZone_Msg;

U8 RL_WarnZone_Msg;
U8 RML_WarnZone_Msg;
U8 RMR_WarnZone_Msg;
U8 RR_WarnZone_Msg;
U8 Rmid_WarnZone_Msg;

/*---Local--variable-----------------------------------------------------------*/

USS_WARNNING_LEVEL RlDisWarningLevel = OUT_OF_BOUNDS;
USS_WARNNING_LEVEL RrDisWarningLevel = OUT_OF_BOUNDS;
USS_WARNNING_LEVEL FlDisWarningLevel = OUT_OF_BOUNDS;
USS_WARNNING_LEVEL FrDisWarningLevel = OUT_OF_BOUNDS;
USS_WARNNING_LEVEL RmidDisWarningLevel = OUT_OF_BOUNDS;
USS_WARNNING_LEVEL FmidDisWarningLevel = OUT_OF_BOUNDS;
U8 BeepEnableFlag = WARN_CLOSE;

// Software version
U8 SoftWareVersionByte0 = 0x00;
U8 SoftWareVersionByte1 = 0x00;
U8 SoftWareVersionByte2 = 0x00;
U8 SoftWareVersionByte3 = 0x19;
U8 SoftWareVersionByte4 = 0x06;
U8 SoftWareVersionByte5 = 0x02;
U8 SoftWareVersionByte6 = 0xB1;
U8 SoftWareVersionByte7 = 0x25;

// TO save Sns Status information after 'SEND' and 'RECEIVE' commands and Echo Height
word wAppSnsBkStatus[SNS_INPUT_CAPTURE_CHANNEL_NUM]={0};

word wAppSnsBkEchoHeight[SNS_INPUT_CAPTURE_CHANNEL_NUM]={0};
#define BK_ECHO_HEIGHT_BITSNUM_6  0x003F  //EchoHeight Bits Num is 6
#define ECHO_HEIGHT_MIN 0

// USE for sns work type
ULTRA_SNS_WORK_MODE tAppUltraSnsWorkMode[SNS_INPUT_CAPTURE_CHANNEL_NUM] = {ULTRA_SNS_NONE};
word wAppSnsMask[PA_SYS_NUM]={0}; // PA system type

word wAppSnsFirstEchoTimeFromObjdetAlgLib[SNS_INPUT_CAPTURE_CHANNEL_NUM] = {0};
word wAppSnsFirstEchoTimeNonObjdetAlgLib[SNS_INPUT_CAPTURE_CHANNEL_NUM] = {0};
signed short wAppSnsFirstEchoTimeNonObjdetAlgLibDis[SNS_INPUT_CAPTURE_CHANNEL_NUM] = {0};

word DelayCnt = 0;
#define DELAY_500MS 100
#define USE_DIS_OF_OBJ_2_SNS_AND_TRIANGLE

//USS distance calculate

#define  APASnsDtdObjDisCompensateFactor 1021// 1.021, = 2.1% tolerance. // word wAPASnsDtdObjDisCompensateFactor;



/***********************************************************************
*  Name        : UltraRadarCyclicTask10msEntry
*  Description :  
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void UltraRadarCyclicTask10msEntry(void)
{
	ElmosStateMachine_T10();
	ObjectDetectStateMachine_T10();
	ObjectDetect_DataProcess_Main_T10();
	InputSignal_ProcessMain_T10();
	UltraRadarDetectWarnZoneTask();
    SlotSearchingFunctionStateMachine();
	UltraRadar_BuzzerAlarm_Cyclic_Task();
    
	UltraRadarGetNearestObjDisMsg();
	UltraRadarDiagnosticMsg();
	InfoOuputVehicleSpeedFeatureAnalyse();
	CalUssSensorOutPutObjDistance();
}

unsigned int RlsNearestObjDis = 0;
unsigned int RrsNearestObjDis = 0;
unsigned int FlsNearestObjDis = 0;
unsigned int FrsNearestObjDis = 0;
unsigned int RlNearestObjDis = 0;
unsigned int RrNearestObjDis = 0;
unsigned int FlNearestObjDis = 0;
unsigned int FrNearestObjDis = 0;
unsigned int FlmNearestObjDis = 0;
unsigned int FrmNearestObjDis = 0;
unsigned int RlmNearestObjDis = 0;
unsigned int RrmNearestObjDis = 0;


unsigned int RlsNearestObjDis_AddCoefficient = 0;
unsigned int RrsNearestObjDis_AddCoefficient = 0;
unsigned int FlsNearestObjDis_AddCoefficient = 0;
unsigned int FrsNearestObjDis_AddCoefficient = 0;

/* UPA_FL_FR-distance. */
unsigned int Distance_FLtx_FLrx = 0x0000;
unsigned int Distance_FLtx_FLMrx = 0x0000;
unsigned int Distance_FLMtx_FLrx = 0x0000;
unsigned int Distance_FRtx_FRrx = 0x0000;
unsigned int Distance_FRtx_FRMrx = 0x0000;
unsigned int Distance_FRMtx_FRrx = 0x0000;

unsigned int Distance_RLtx_RLrx = 0x0000;
unsigned int Distance_RLtx_RLMrx = 0x0000;
unsigned int Distance_RLMtx_RLMrx = 0x0000;

unsigned int Distance_RLMtx_RRMrx = 0x0000;
unsigned int Distance_RRMtx_RLMrx = 0x0000;

unsigned int Distance_RLMtx_RLrx = 0x0000;
unsigned int Distance_RRtx_RRrx = 0x0000;
unsigned int Distance_RRtx_RRMrx = 0x0000;
unsigned int Distance_RRMtx_RRMrx = 0x0000;
unsigned int Distance_RRMtx_RRrx = 0x0000;

/* FM/FM distance. */
unsigned int Distance_FRMtx_FRMrx = 0x0000;
unsigned int Distance_FRMtx_FLMrx = 0x0000;
unsigned int Distance_FLMtx_FLMrx = 0x0000;
unsigned int Distance_FLMtx_FRMrx = 0x0000;
unsigned int Distance_Fmid_TriangleMin = 0x0000;

unsigned int TriangleDisOf_Fmid = 0x0000;
unsigned int TriangleDisOf_Rmid = 0x0000;


unsigned int RmidNearestObjDis = 0;
unsigned int FmidNearestObjDis = 0;

/* Diagnostic. */
diagnosticTypedef g_RrsDTC;
diagnosticTypedef g_RrDTC = 0x0000;
diagnosticTypedef g_RrmDTC = 0x0000;
diagnosticTypedef g_RlmDTC = 0x0000;
diagnosticTypedef g_RlDTC = 0x0000;
diagnosticTypedef g_RlsDTC = 0x0000;

diagnosticTypedef g_FrsDTC = 0x0000;
diagnosticTypedef g_FrDTC = 0x0000;
diagnosticTypedef g_FrmDTC = 0x0000;
diagnosticTypedef g_FlmDTC = 0x0000;
diagnosticTypedef g_FlDTC = 0x0000;
diagnosticTypedef g_FlsDTC = 0x0000;

// Sns Scheduling logic
U8 UpaFrontSnsTxSnsMask = 0;
U8 UpaRearSnsTxSnsMask = 0;

#define TEST_BUFFER_SIZE 15
U8 TestSnsHeight[SNS_INPUT_CAPTURE_CHANNEL_NUM][TEST_BUFFER_SIZE] = {0};
U8 TestSnsHeightCount[SNS_INPUT_CAPTURE_CHANNEL_NUM] = {0};

/***********************************************************************
*  Name        : UltraRadarDiagnosticMsg
*  Description :  Push the diagnostic code to the XCP CAN bus.
*  Parameter   : None.
*  Returns     : None.
***********************************************************************/
void UltraRadarDiagnosticMsg(void)
{
    unsigned char datTemp[8] = {0x00};
    g_RrsDTC.allStatus = getSnsDiagnosticStatus(RRS_SNS_INDEX);
    g_RrDTC.allStatus = getSnsDiagnosticStatus(RR_SNS_INDEX);
    g_RrmDTC.allStatus = getSnsDiagnosticStatus(RRM_SNS_INDEX);
    g_RlmDTC.allStatus = getSnsDiagnosticStatus(RLM_SNS_INDEX);
    g_RlDTC.allStatus = getSnsDiagnosticStatus(RL_SNS_INDEX);
    g_RlsDTC.allStatus = getSnsDiagnosticStatus(RLS_SNS_INDEX);
    
    g_FrsDTC.allStatus = getSnsDiagnosticStatus(FRS_SNS_INDEX);
    g_FrDTC.allStatus = getSnsDiagnosticStatus(FR_SNS_INDEX);
    g_FrmDTC.allStatus = getSnsDiagnosticStatus(FRM_SNS_INDEX);
    g_FlmDTC.allStatus = getSnsDiagnosticStatus(FLM_SNS_INDEX);
    g_FlDTC.allStatus = getSnsDiagnosticStatus(FL_SNS_INDEX);
    g_FlsDTC.allStatus = getSnsDiagnosticStatus(FLS_SNS_INDEX);


//    /* RRS-diagnostic. */
//    Appl_AVMDVR_Send_RRS_DTC_shortToBattery((U8)g_RrsDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RRS_DTC_shortToGND((U8)g_RrsDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RRS_DTC_isBlocked((U8)g_RrsDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RRS_DTC_ringTimeTooShort((U8)g_RrsDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RRS_DTC_ringTimeTooLong((U8)g_RrsDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RRS_DTC_signalDisturbed((U8)g_RrsDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RRS_DTC_signalError((U8)g_RrsDTC.item.signalError);
//    Appl_AVMDVR_Send_RRS_DTC_initFail((U8)g_RrsDTC.item.initFail);
//    /* RR-diagnostic. */
//    Appl_AVMDVR_Send_RR_DTC_shortToBattery((U8)g_RrDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RR_DTC_shortToGND((U8)g_RrDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RR_DTC_isBlocked((U8)g_RrDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RR_DTC_ringTimeTooShort((U8)g_RrDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RR_DTC_ringTimeTooLong((U8)g_RrDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RR_DTC_signalDisturbed((U8)g_RrDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RR_DTC_signalError((U8)g_RrDTC.item.signalError);
//    Appl_AVMDVR_Send_RR_DTC_initFail((U8)g_RrDTC.item.initFail);
//    /* RRM-diagnostic. */
//    Appl_AVMDVR_Send_RRM_DTC_shortToBattery((U8)g_RrmDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RRM_DTC_shortToGND((U8)g_RrmDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RRM_DTC_isBlocked((U8)g_RrmDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RRM_DTC_ringTimeTooShort((U8)g_RrmDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RRM_DTC_ringTimeTooLong((U8)g_RrmDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RRM_DTC_signalDisturbed((U8)g_RrmDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RRM_DTC_signalError((U8)g_RrmDTC.item.signalError);
//    Appl_AVMDVR_Send_RRM_DTC_initFail((U8)g_RrmDTC.item.initFail);
//    /* RLM-diagnostic. */
//    Appl_AVMDVR_Send_RLM_DTC_shortToBattery((U8)g_RlmDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RLM_DTC_shortToGND((U8)g_RlmDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RLM_DTC_isBlocked((U8)g_RlmDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RLM_DTC_ringTimeTooShort((U8)g_RlmDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RLM_DTC_ringTimeTooLong((U8)g_RlmDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RLM_DTC_signalDisturbed((U8)g_RlmDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RLM_DTC_signalError((U8)g_RlmDTC.item.signalError);
//    Appl_AVMDVR_Send_RLM_DTC_initFail((U8)g_RlmDTC.item.initFail);
//    /* RL-diagnostic. */
//    Appl_AVMDVR_Send_RL_DTC_shortToBattery((U8)g_RlDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RL_DTC_shortToGND((U8)g_RlDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RL_DTC_isBlocked((U8)g_RlDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RL_DTC_ringTimeTooShort((U8)g_RlDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RL_DTC_ringTimeTooLong((U8)g_RlDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RL_DTC_signalDisturbed((U8)g_RlDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RL_DTC_signalError((U8)g_RlDTC.item.signalError);
//    Appl_AVMDVR_Send_RL_DTC_initFail((U8)g_RlDTC.item.initFail);
//    /* RLS-diagnostic. */
//    Appl_AVMDVR_Send_RLS_DTC_shortToBattery((U8)g_RlsDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_RLS_DTC_shortToGND((U8)g_RlsDTC.item.shortToGND);
//    Appl_AVMDVR_Send_RLS_DTC_isBlocked((U8)g_RlsDTC.item.isBlocked);
//    Appl_AVMDVR_Send_RLS_DTC_ringTimeTooShort((U8)g_RlsDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_RLS_DTC_ringTimeTooLong((U8)g_RlsDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_RLS_DTC_signalDisturbed((U8)g_RlsDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_RLS_DTC_signalError((U8)g_RlsDTC.item.signalError);
//    Appl_AVMDVR_Send_RLS_DTC_initFail((U8)g_RlsDTC.item.initFail);


//    /* FRS-diagnostic. */
//    Appl_AVMDVR_Send_FRS_DTC_shortToBattery((U8)g_FrsDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FRS_DTC_shortToGND((U8)g_FrsDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FRS_DTC_isBlocked((U8)g_FrsDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FRS_DTC_ringTimeTooShort((U8)g_FrsDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FRS_DTC_ringTimeTooLong((U8)g_FrsDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FRS_DTC_signalDisturbed((U8)g_FrsDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FRS_DTC_signalError((U8)g_FrsDTC.item.signalError);
//    Appl_AVMDVR_Send_FRS_DTC_initFail((U8)g_FrsDTC.item.initFail);
//    /* FR-diagnostic. */
//    Appl_AVMDVR_Send_FR_DTC_shortToBattery((U8)g_FrDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FR_DTC_shortToGND((U8)g_FrDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FR_DTC_isBlocked((U8)g_FrDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FR_DTC_ringTimeTooShort((U8)g_FrDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FR_DTC_ringTimeTooLong((U8)g_FrDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FR_DTC_signalDisturbed((U8)g_FrDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FR_DTC_signalError((U8)g_FrDTC.item.signalError);
//    Appl_AVMDVR_Send_FR_DTC_initFail((U8)g_FrDTC.item.initFail);
//    /* FRM-diagnostic. */
//    Appl_AVMDVR_Send_FRM_DTC_shortToBattery((U8)g_FrmDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FRM_DTC_shortToGND((U8)g_FrmDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FRM_DTC_isBlocked((U8)g_FrmDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FRM_DTC_ringTimeTooShort((U8)g_FrmDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FRM_DTC_ringTimeTooLong((U8)g_FrmDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FRM_DTC_signalDisturbed((U8)g_FrmDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FRM_DTC_signalError((U8)g_FrmDTC.item.signalError);
//    Appl_AVMDVR_Send_FRM_DTC_initFail((U8)g_FrmDTC.item.initFail);
//    /* FLM-diagnostic. */
//    Appl_AVMDVR_Send_FLM_DTC_shortToBattery((U8)g_FlmDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FLM_DTC_shortToGND((U8)g_FlmDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FLM_DTC_isBlocked((U8)g_FlmDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FLM_DTC_ringTimeTooShort((U8)g_FlmDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FLM_DTC_ringTimeTooLong((U8)g_FlmDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FLM_DTC_signalDisturbed((U8)g_FlmDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FLM_DTC_signalError((U8)g_FlmDTC.item.signalError);
//    Appl_AVMDVR_Send_FLM_DTC_initFail((U8)g_FlmDTC.item.initFail);
//    /* FL-diagnostic. */
//    Appl_AVMDVR_Send_FL_DTC_shortToBattery((U8)g_FlDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FL_DTC_shortToGND((U8)g_FlDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FL_DTC_isBlocked((U8)g_FlDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FL_DTC_ringTimeTooShort((U8)g_FlDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FL_DTC_ringTimeTooLong((U8)g_FlDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FL_DTC_signalDisturbed((U8)g_FlDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FL_DTC_signalError((U8)g_FlDTC.item.signalError);
//    Appl_AVMDVR_Send_FL_DTC_initFail((U8)g_FlDTC.item.initFail);
//    /* FLS-diagnostic. */
//    Appl_AVMDVR_Send_FLS_DTC_shortToBattery((U8)g_FlsDTC.item.shortToBattery);
//    Appl_AVMDVR_Send_FLS_DTC_shortToGND((U8)g_FlsDTC.item.shortToGND);
//    Appl_AVMDVR_Send_FLS_DTC_isBlocked((U8)g_FlsDTC.item.isBlocked);
//    Appl_AVMDVR_Send_FLS_DTC_ringTimeTooShort((U8)g_FlsDTC.item.ringTimeTooShort);
//    Appl_AVMDVR_Send_FLS_DTC_ringTimeTooLong((U8)g_FlsDTC.item.ringTimeTooLong);
//    Appl_AVMDVR_Send_FLS_DTC_signalDisturbed((U8)g_FlsDTC.item.signalDisturbed);
//    Appl_AVMDVR_Send_FLS_DTC_signalError((U8)g_FlsDTC.item.signalError);
//    Appl_AVMDVR_Send_FLS_DTC_initFail((U8)g_FlsDTC.item.initFail);
}


/***********************************************************************
*  Name        : UltraRadarGetNearestObjDisMsg
*  Description :  
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void UltraRadarGetNearestObjDisMsg(void)
{
	//Get Obj detect distance info from lib
	RlsNearestObjDis = ObjDetect_GetRlsNearestObjDis();
	RrsNearestObjDis = ObjDetect_GetRrsNearestObjDis();
    FlsNearestObjDis = ObjDetect_GetFlsNearestObjDis();
	FrsNearestObjDis = ObjDetect_GetFrsNearestObjDis();
	RlNearestObjDis = ObjDetect_GetRlNearestObjDis();
	RrNearestObjDis = ObjDetect_GetRrNearestObjDis();
	FlNearestObjDis = ObjDetect_GetFlNearestObjDis();
	FrNearestObjDis = ObjDetect_GetFrNearestObjDis();
	RmidNearestObjDis = ObjDetect_GetRmidNearestObjDis();
	FmidNearestObjDis = ObjDetect_GetFmidNearestObjDis();

    TriangleDisOf_Fmid = getTriangleDisOf_Fmid();
    TriangleDisOf_Rmid = getTriangleDisOf_Rmid();
    
    /* Get APA distance with coefficient. */


	//if short sensors work in Triangle mode,
	// the value of FlmNearestObjDis,FrmNearestObjDis same as FmidNearestObjDis
	// the value of RlmNearestObjDis,RrmNearestObjDis same as RmidNearestObjDis

	FlmNearestObjDis= ObjDetect_GetFlmNearestObjDis();
	FrmNearestObjDis= ObjDetect_GetFrmNearestObjDis();
	RlmNearestObjDis= ObjDetect_GetRlmNearestObjDis();
	RrmNearestObjDis= ObjDetect_GetRrmNearestObjDis();

    /* UPA distance. */
    Distance_FLtx_FLrx = GetDistance_FLtx_FLrx();
    Distance_FLtx_FLMrx = GetDistance_FLtx_FLMrx();
    Distance_FLMtx_FLrx = GetDistance_FLMtx_FLrx();
    Distance_FRtx_FRrx = GetDistance_FRtx_FRrx();
    Distance_FRtx_FRMrx = GetDistance_FRtx_FRMrx();
    Distance_FRMtx_FRrx = GetDistance_FRMtx_FRrx();
    
    /* Fmid/Fmid_Triangle distance. */
    Distance_FRMtx_FRMrx = Get_distance_FRMtx_FRMrx();
    Distance_FRMtx_FLMrx = Get_distance_FRMtx_FLMrx();
    Distance_FLMtx_FLMrx = Get_distance_FLMtx_FLMrx();
    Distance_FLMtx_FRMrx = Get_distance_FLMtx_FRMrx();
    
    Distance_RLtx_RLrx = GetDistance_RLtx_RLrx();
    Distance_RLtx_RLMrx = GetDistance_RLtx_RLMrx();
    Distance_RLMtx_RLMrx = GetDistance_RLMtx_RLMrx();
    Distance_RRMtx_RRMrx = GetDistance_RRMtx_RRMrx();

    Distance_RLMtx_RRMrx = GetDistance_RLMtx_RRMrx();
    Distance_RRMtx_RLMrx = GetDistance_RRMtx_RLMrx();
    
    Distance_RLMtx_RLrx = GetDistance_RLMtx_RLrx();
    Distance_RRtx_RRrx = GetDistance_RRtx_RRrx();
    Distance_RRtx_RRMrx = GetDistance_RRtx_RRMrx();
    Distance_RRMtx_RRrx = GetDistance_RRMtx_RRrx();

	//distance check again,Sns NearestObjDis set to default ,if no Obj Echo detected 
	
#if 0
	// NOTE: there is a bug, UPA distance can not be always set to default value, the cause is not clear
	UltraRadarDisResetToDefaultValue(&FlNearestObjDis,PAFrontSys,FL_SNS_INDEX,FL_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&FrNearestObjDis,PAFrontSys,FR_SNS_INDEX,FR_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&FlmNearestObjDis,PAFrontSys,FLM_SNS_INDEX,FLM_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&FrmNearestObjDis,PAFrontSys,FRM_SNS_INDEX,FRM_SNS_INDEX,FALSE);

	UltraRadarDisResetToDefaultValue(&RlNearestObjDis,PARearSys,RL_SNS_INDEX,RL_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&RrNearestObjDis,PARearSys,RR_SNS_INDEX,RR_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&RlmNearestObjDis,PARearSys,RLM_SNS_INDEX,RLM_SNS_INDEX,FALSE);
	UltraRadarDisResetToDefaultValue(&RrmNearestObjDis,PARearSys,RRM_SNS_INDEX,RRM_SNS_INDEX,FALSE);

	UltraRadarDisResetToDefaultValue(&FmidNearestObjDis,PAFrontSys,FLM_SNS_INDEX,FRM_SNS_INDEX,TRUE);
	UltraRadarDisResetToDefaultValue(&RmidNearestObjDis,PARearSys,RLM_SNS_INDEX,RRM_SNS_INDEX,TRUE);
#else
    
#endif

	//Distance send to CAN bus
	#ifdef USE_DIS_OF_OBJ_2_SNS_AND_TRIANGLE
    
	Appl_AVMDVR_Send_FL(Distance_FLtx_FLrx);
	Appl_AVMDVR_Send_FR(Distance_FRtx_FRrx);
	Appl_AVMDVR_Send_FLM(FlmNearestObjDis);
	Appl_AVMDVR_Send_FRM(FrmNearestObjDis);
    
	Appl_AVMDVR_Send_RL(Distance_RLtx_RLrx);
	Appl_AVMDVR_Send_RR(Distance_RRtx_RRrx);
	Appl_AVMDVR_Send_RLM(RlmNearestObjDis);
	Appl_AVMDVR_Send_RRM(RrmNearestObjDis);
    
	Appl_AVMDVR_Send_FSL(FlsNearestObjDis);
	Appl_AVMDVR_Send_FSR(FrsNearestObjDis);
	Appl_AVMDVR_Send_RSL(RlsNearestObjDis);
	Appl_AVMDVR_Send_RSR(RrsNearestObjDis);
    
	Appl_AVMDVR_Send_FrontMid( TriangleDisOf_Fmid);
	Appl_AVMDVR_Send_RearMid(TriangleDisOf_Rmid);

    #else
	Appl_AVMDVR_Send_FL(FlNearestObjDis);
	Appl_AVMDVR_Send_FR(FrNearestObjDis);
	Appl_AVMDVR_Send_FLM(FlmNearestObjDis);
	Appl_AVMDVR_Send_FRM(FrmNearestObjDis);
	Appl_AVMDVR_Send_RL(RlNearestObjDis);
	Appl_AVMDVR_Send_RR(RrNearestObjDis);
	Appl_AVMDVR_Send_RLM(RlmNearestObjDis);
	Appl_AVMDVR_Send_RRM(RrmNearestObjDis);
	Appl_AVMDVR_Send_FSL(FlsNearestObjDis);
	Appl_AVMDVR_Send_FSR(FrsNearestObjDis);
	Appl_AVMDVR_Send_RSL(RlsNearestObjDis);
	Appl_AVMDVR_Send_RSR(RrsNearestObjDis);
	Appl_AVMDVR_Send_FrontMid( FmidNearestObjDis);
	Appl_AVMDVR_Send_RearMid(RmidNearestObjDis);
    #endif
    #if 0    
    /* APA distance with coefficient. */


    //Distance of object to sensor. 
    /* UPA distance. */
    Appl_AVMDVR_Send_FLtx_FLrx(Distance_FLtx_FLrx);
    Appl_AVMDVR_Send_FLtx_FLMrx(Distance_FLtx_FLMrx);
    Appl_AVMDVR_Send_FLMtx_FLrx(Distance_FLMtx_FLrx);
    
    Appl_AVMDVR_Send_FRtx_FRrx(Distance_FRtx_FRrx);
    Appl_AVMDVR_Send_FRtx_FRMrx(Distance_FRtx_FRMrx);
    Appl_AVMDVR_Send_FRMtx_FRrx(Distance_FRMtx_FRrx);
    Appl_AVMDVR_Send_FRMtx_FRMrx(Distance_FRMtx_FRMrx);
    Appl_AVMDVR_Send_FRMtx_FLMrx(Distance_FRMtx_FLMrx);
    Appl_AVMDVR_Send_FLMtx_FLMrx(Distance_FLMtx_FLMrx);
    Appl_AVMDVR_Send_FLMtx_FRMrx(Distance_FLMtx_FRMrx);
    Appl_AVMDVR_Send_FmidTriangle(Distance_Fmid_TriangleMin);

    
    Appl_AVMDVR_Send_RLtx_RLrx(Distance_RLtx_RLrx);
    Appl_AVMDVR_Send_RLtx_RLMrx(Distance_RLtx_RLMrx);
    Appl_AVMDVR_Send_RLMtx_RLrx(Distance_RLMtx_RLrx);
    
    Appl_AVMDVR_Send_RRMtx_RRMrx(Distance_RRMtx_RRMrx);
    Appl_AVMDVR_Send_RLMtx_RLMrx(Distance_RLMtx_RLMrx);
    Appl_AVMDVR_Send_RLMtx_RRMrx(Distance_RLMtx_RRMrx);
    Appl_AVMDVR_Send_RRMtx_RLMrx(Distance_RRMtx_RLMrx);
    
    Appl_AVMDVR_Send_RRtx_RRrx(Distance_RRtx_RRrx);
    Appl_AVMDVR_Send_RRtx_RRMrx(Distance_RRtx_RRMrx);
    Appl_AVMDVR_Send_RRMtx_RRrx(Distance_RRMtx_RRrx);
    #endif


	//EchoHeight send to CAN bus
	Appl_AVMDVR_Send_FL_EchoHeight((U8)wAppSnsBkEchoHeight[FL_SNS_INDEX]);
	Appl_AVMDVR_Send_FR_EchoHeight((U8)wAppSnsBkEchoHeight[FR_SNS_INDEX]);
	Appl_AVMDVR_Send_FML_EchoHeight((U8)wAppSnsBkEchoHeight[FLM_SNS_INDEX]);
	Appl_AVMDVR_Send_FMR_EchoHeight((U8)wAppSnsBkEchoHeight[FRM_SNS_INDEX]);
	Appl_AVMDVR_Send_RL_EchoHeight((U8)wAppSnsBkEchoHeight[RL_SNS_INDEX]);
	Appl_AVMDVR_Send_RR_EchoHeight((U8)wAppSnsBkEchoHeight[RR_SNS_INDEX]);
	Appl_AVMDVR_Send_RML_EchoHeight((U8)wAppSnsBkEchoHeight[RLM_SNS_INDEX]);
	Appl_AVMDVR_Send_RMR_EchoHeight((U8)wAppSnsBkEchoHeight[RRM_SNS_INDEX]);
	Appl_AVMDVR_Send_FLL_EchoHeight((U8)wAppSnsBkEchoHeight[FLS_SNS_INDEX]);
	Appl_AVMDVR_Send_FRL_EchoHeight((U8)wAppSnsBkEchoHeight[FRS_SNS_INDEX]);
	Appl_AVMDVR_Send_RLL_EchoHeight((U8)wAppSnsBkEchoHeight[RLS_SNS_INDEX]);
	Appl_AVMDVR_Send_RRL_EchoHeight((U8)wAppSnsBkEchoHeight[RRS_SNS_INDEX]);

	UltraRadarSendSoftWareVersion();
}

/******************************************************************************
** Function:    void UltraRadarDetectWarnZoneTask(void)
** Description:  check and send WarnZone infomation to can bus
** Parameter:   None
** Return:      
******************************************************************************/
void UltraRadarDetectWarnZoneTask(void)
{

	U8 FL_WarnZone = NO_OBJ_ZONE;
	U8 FML_WarnZone = NO_OBJ_ZONE;
	U8 FMR_WarnZone = NO_OBJ_ZONE;
	U8 FR_WarnZone = NO_OBJ_ZONE;

	U8 RL_WarnZone = NO_OBJ_ZONE;
	U8 RML_WarnZone = NO_OBJ_ZONE;
	U8 RMR_WarnZone = NO_OBJ_ZONE;
	U8 RR_WarnZone = NO_OBJ_ZONE;

	FL_WarnZone = ObjDetect_GetZoneByRegion(PAFrontSys,FRONT_REGION_LEFT);
	FML_WarnZone = ObjDetect_GetZoneByRegion(PAFrontSys,FRONT_REGION_MID);
	FMR_WarnZone = ObjDetect_GetZoneByRegion(PAFrontSys,FRONT_REGION_MID);
	FR_WarnZone = ObjDetect_GetZoneByRegion(PAFrontSys,FRONT_REGION_RIGHT);

	RL_WarnZone = ObjDetect_GetZoneByRegion(PARearSys,REAR_REGION_LEFT);
	RML_WarnZone = ObjDetect_GetZoneByRegion(PARearSys,REAR_REGION_MID);
	RMR_WarnZone = ObjDetect_GetZoneByRegion(PARearSys,REAR_REGION_MID);
	RR_WarnZone = ObjDetect_GetZoneByRegion(PARearSys,REAR_REGION_RIGHT);

	// Get Warning Zone
	//NOTE: NO_OBJ_ZONE and OUT_OF_BOUNDS has the same value
    RlDisWarningLevel = RL_WarnZone;
    RrDisWarningLevel = RR_WarnZone;
    FlDisWarningLevel = FL_WarnZone;
    FrDisWarningLevel = FR_WarnZone;

    RmidDisWarningLevel = RML_WarnZone;
    FmidDisWarningLevel = FML_WarnZone;

	// NOTE: FL\FR\RL\RR Sns only define three warn zone 
	// e.g NO_OBJ_ZONE\OBJ_ZONE3\OBJ_ZONE4
	if((OBJ_ZONE3 == RlDisWarningLevel)||(OBJ_ZONE4 == RlDisWarningLevel))
	{
		RlDisWarningLevel = NO_OBJ_ZONE;
	}

	if((OBJ_ZONE3 == RrDisWarningLevel)||(OBJ_ZONE4 == RrDisWarningLevel))
	{
		RrDisWarningLevel = NO_OBJ_ZONE;
	}

	if((OBJ_ZONE3 == FlDisWarningLevel)||(OBJ_ZONE4 == FlDisWarningLevel))
	{
		FlDisWarningLevel = NO_OBJ_ZONE;
	}

	if((OBJ_ZONE3 == FrDisWarningLevel)||(OBJ_ZONE4 == FrDisWarningLevel))
	{
		FrDisWarningLevel = NO_OBJ_ZONE;
	}

    //warning message
    FL_WarnZone_Msg  =  GetPAsysWarnZone(PAFrontSys,FRONT_REGION_LEFT,FL_WarnZone); //Msg define, cSysType	1 bit ;region	 3 Bit;Zone 	 4 Bit
	FML_WarnZone_Msg = GetPAsysWarnZone(PAFrontSys,FRONT_REGION_MID,FML_WarnZone);
	FMR_WarnZone_Msg = GetPAsysWarnZone(PAFrontSys,FRONT_REGION_MID,FMR_WarnZone);
	FR_WarnZone_Msg = GetPAsysWarnZone(PAFrontSys,FRONT_REGION_RIGHT,FR_WarnZone);
    Fmid_WarnZone_Msg = GetPAsysWarnZone(PAFrontSys,FRONT_REGION_MID,FML_WarnZone);

	RL_WarnZone_Msg  =  GetPAsysWarnZone(PARearSys,FRONT_REGION_LEFT,RL_WarnZone);
	RML_WarnZone_Msg = GetPAsysWarnZone(PARearSys,FRONT_REGION_MID,RML_WarnZone);
	RMR_WarnZone_Msg = GetPAsysWarnZone(PARearSys,FRONT_REGION_MID,RMR_WarnZone);
	RR_WarnZone_Msg = GetPAsysWarnZone(PARearSys,FRONT_REGION_RIGHT,RR_WarnZone);
    Rmid_WarnZone_Msg = GetPAsysWarnZone(PARearSys,FRONT_REGION_MID,RML_WarnZone);

	// open warning 
	if((FL_WarnZone!=NO_OBJ_ZONE)|(FML_WarnZone!=NO_OBJ_ZONE)|(FMR_WarnZone!=NO_OBJ_ZONE)|(FR_WarnZone!=NO_OBJ_ZONE)|
		(RL_WarnZone!=NO_OBJ_ZONE)|(RML_WarnZone!=NO_OBJ_ZONE)|(RMR_WarnZone!=NO_OBJ_ZONE)|(RR_WarnZone!=NO_OBJ_ZONE)){
		BeepEnableFlag= WARN_OPEN;
	}
	else{
		BeepEnableFlag= WARN_CLOSE;
	}
#if 0		
	Appl_AVMDVR_Send_FL_WarnZone(FL_WarnZone_Msg);
	Appl_AVMDVR_Send_FML_WarnZone(FML_WarnZone_Msg);
	Appl_AVMDVR_Send_FMR_WarnZone(FMR_WarnZone_Msg);
	Appl_AVMDVR_Send_FR_WarnZone(FR_WarnZone_Msg);
	Appl_AVMDVR_Send_RL_WarnZone(RL_WarnZone_Msg);
	Appl_AVMDVR_Send_RML_WarnZone(RML_WarnZone_Msg);
	Appl_AVMDVR_Send_RMR_WarnZone(RMR_WarnZone_Msg);
	Appl_AVMDVR_Send_RR_WarnZone(RR_WarnZone_Msg);

	Appl_AVMDVR_Send_FL_WarnZone_2(FL_WarnZone_Msg);
	Appl_AVMDVR_Send_Fmid_WarnZone(Fmid_WarnZone_Msg);
	Appl_AVMDVR_Send_FR_WarnZone_2(FR_WarnZone_Msg);
    
	Appl_AVMDVR_Send_RL_WarnZone_2(RL_WarnZone_Msg);
	Appl_AVMDVR_Send_Rmid_WarnZone(Rmid_WarnZone_Msg);
	Appl_AVMDVR_Send_RR_WarnZone_2(RR_WarnZone_Msg);
	#endif
}

/***********************************************************************
*  Name        : void UltraRadar_BuzzerAlarm_Cyclic_Task(void)
*  Description : Drive Buzzer with different frequence,according to Warning Level
*  Parameter   :
*  Returns     : 
***********************************************************************/
void UltraRadar_BuzzerAlarm_Cyclic_Task(void)
{
	if(WARN_OPEN ==BeepEnableFlag)
	{
		//Drive Warning Board
		Appl_AVMDVR_Send_WarnControl(WARN_OPEN);
		
		if((LEVEL_A==FlDisWarningLevel)|(LEVEL_A==FrDisWarningLevel)|
		   (LEVEL_A==RlDisWarningLevel)|(LEVEL_A==RrDisWarningLevel)|
		   (LEVEL_A==FmidDisWarningLevel)|(LEVEL_A==RmidDisWarningLevel))
		{
			// Warning FZ
			Appl_AVMDVR_Send_WarnFz(WARN_FZ_LONG);
		}
		else if((LEVEL_B==FlDisWarningLevel)|(LEVEL_B==FrDisWarningLevel)|
				   (LEVEL_B==RlDisWarningLevel)|(LEVEL_B==RrDisWarningLevel)|
				   (LEVEL_B==FmidDisWarningLevel)|(LEVEL_B==RmidDisWarningLevel))
		{
			// Warning FZ
			Appl_AVMDVR_Send_WarnFz(WARN_FZ_4HZ);
			
		}
		else if((LEVEL_C==FmidDisWarningLevel)|(LEVEL_C==RmidDisWarningLevel))
		{
			// Warning FZ
			Appl_AVMDVR_Send_WarnFz(WARN_FZ_2HZ);
		}
	    else if((LEVEL_D==RmidDisWarningLevel))
		{
			// Warning FZ
			Appl_AVMDVR_Send_WarnFz(WARN_FZ_1HZ);
		}
		else
		{
			//No Need Warning,Disable Warning Board
			Appl_AVMDVR_Send_WarnControl(WARN_CLOSE);
		}
	}
	else{
		//No Need Warning,Disable Warning Board
		Appl_AVMDVR_Send_WarnControl(WARN_CLOSE);
	}
}

/***********************************************************************
*  Name        : void UltraRadarSendSoftWareVersion(void)
*  Description :  
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void UltraRadarSendSoftWareVersion(void)
{
	Appl_AVMDVR_Send_SoftVersionByte0(SoftWareVersionByte0);
	Appl_AVMDVR_Send_SoftVersionByte1(SoftWareVersionByte1);
	Appl_AVMDVR_Send_SoftVersionByte2(SoftWareVersionByte2);
	Appl_AVMDVR_Send_SoftVersionByte3(SoftWareVersionByte3);
	Appl_AVMDVR_Send_SoftVersionByte4(SoftWareVersionByte4);
	Appl_AVMDVR_Send_SoftVersionByte5(SoftWareVersionByte5);
	Appl_AVMDVR_Send_SoftVersionByte6(SoftWareVersionByte6);
	Appl_AVMDVR_Send_SoftVersionByte7(SoftWareVersionByte7);
}

/**************** END OF FILE *****************************************/
