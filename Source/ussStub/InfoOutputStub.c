
/* Determine driver information output */

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"
#include "ObjectProcess.h"
#include "InfoOutput.h"

void ObjDetect_InfoOutParInit(void)
{
}
void InitObjInfo(uchar cSysType)
{
}
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
void DtmDrvInfOutputTask(void)
{
}

void DisplayLEDDiagnosisTask(void)
{
}

void DisplayLEDDiagnosisLEDSelection(void)
{
}
void DisplayLEDDiagnosisLEDCaptureInit(void)
{
}
void DisplayLEDTask(void)
{
}
void SpeakerTask(void)
{
}
void SpeakerFeedBackPinCheck(uchar cSysType, uchar cSpeakerFeedBackPin)
{
}

void SBSALedFeedBackPinCheck(uchar SideIndex)
{
}

void BikeRackDetectionTask(void)
{
}
void TrailerDetectionTask(void)
{
}
void ObjectDetect_DataProcess_Main_T10(void)
{
}	
void SendChimeCmdSignals(_c_Chime_Command_buf *ChimeCmdBuf)
{
}
uchar InfoOutput_GetZone(word wDis, uchar cSysType, uchar cPrevZone)
{
}

unsigned int ObjDetect_GetRlsNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRrsNearestObjDis(void)
{
}
unsigned int ObjDetect_GetFlsNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFrsNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRlNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRrNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFlNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFrNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRrmNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRlmNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFrmNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFlmNearestObjDis(void)
{
	return 0x7fff;
}

unsigned int ObjDetect_GetRlsNearestObjDis_AddCoefficient(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetRrsNearestObjDis_AddCoefficient(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFlsNearestObjDis_AddCoefficient(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFrsNearestObjDis_AddCoefficient(void)
{
	return 0x7fff;
}


unsigned int ObjDetect_GetRmidNearestObjDis(void)
{
	return 0x7fff;
}
unsigned int ObjDetect_GetFmidNearestObjDis(void)
{
	return 0x7fff;
}

unsigned int getRMRechoHeight(void)
{
	return 0x7fff;
}
unsigned int getRMLechoHeight(void)
{
	return 0x7fff;
}


/* Debug UPA_L_R-distance. */
unsigned int GetDistance_FLtx_FLrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FLtx_FLMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FLMtx_FLMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FLMtx_FLrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FRtx_FRrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FRtx_FRMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FRMtx_FRMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_FRMtx_FRrx(void)
{
	return 0x7fff;
}

unsigned int GetDistance_RLtx_RLrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RLtx_RLMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RLMtx_RLrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RRtx_RRrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RRtx_RRMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RRMtx_RRrx(void)
{
	return 0x7fff;
}

unsigned int GetDistance_RLMtx_RLMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RRMtx_RRMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RLMtx_RRMrx(void)
{
	return 0x7fff;
}
unsigned int GetDistance_RRMtx_RLMrx(void)
{
	return 0x7fff;
}

/* Large FOV object distance. */
unsigned int getUssRrObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssRrmObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssRlmObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssRlObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssFrObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssFrmObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssFlmObjDis(void)
{
	return 0x7fff;
}
unsigned int getUssFlObjDis(void)
{
	return 0x7fff;
}
void CalUssSensorOutPutObjDistance(void)
{
	
}


/* debug FM/FM distance. */
unsigned int Get_distance_FRMtx_FRMrx(void)
{
	return 0x7fff;
}
unsigned int Get_distance_FRMtx_FLMrx(void)
{
	return 0x7fff;
}
unsigned int Get_distance_FLMtx_FLMrx(void)
{
	return 0x7fff;
}
unsigned int Get_distance_FLMtx_FRMrx(void)
{
	return 0x7fff;
}
unsigned int GetFmid_distance_TriangleMin(void)
{
	return 0x7fff;
}

VehicleMovingRoadStates InfoOuputVehicleSpeedFeatureAnalyse(void)
{
	return 0x7fff;
}
unsigned int InfoOuputSensorDistancePDCFilterHandler(unsigned int SensorDis, PASysSnsIndexType SensorIndex)
{
	return 0x7fff;
}
unsigned int InfoOuputSensorDistanceControlFilterHandler(unsigned int SensorDis, PASysSnsIndexType SensorIndex)
{
	return 0x7fff;
}
unsigned int getUssFrObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssFrmObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssFlmObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssFlObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssRrObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssRrmObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssRlmObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssRlObjDisForPDC(void)
{
	return 0x7fff;
}
unsigned int getUssFrObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssFrmObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssFlmObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssFlObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssRrObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssRrmObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssRlmObjDisForControl(void)
{
	return 0x7fff;
}
unsigned int getUssRlObjDisForControl(void)
{
	return 0x7fff;
}

unsigned int getSnsDiagnosticStatus(PASysSnsIndexType SnsIndex)
{
	return 0x7fff;
}

unsigned long long ObjDetect_GetObjdetectLibVersion(void)
{
	return 0x7fff;
}
void ObjDetectSetEnableSnsRegsReadCmdFlag(BOOLEAN bool)
{
}
void ObjDetectReadSnsRegs(SnsRegsReadCmdType RegsReadCmd,BOOLEAN bChangeStatFlag)
{
	
}
SnsRegsReadCmdType ObjDetectGetSnsRegsReadCmdType(void)
{
}
BOOLEAN ObjDetectGetEnableSnsRegsReadCmdFlag(void)
{
	
}

/* Other module use. */
void ReqReinitSns(void)
{
	
}
unsigned char GetSnsStatus(void)
{
	
}

/* Current module use. */
unsigned char GetReqToReinitCmd(void)
{
}
void SetSnsStatus(void)
{
}


