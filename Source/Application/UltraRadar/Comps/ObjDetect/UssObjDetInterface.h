#ifndef _OBJECT_DETECT_INTERFACE_H_
#define _OBJECT_DETECT_INTERFACE_H_

#include "ObjDetect_Pub.h"


/* CALIB_WRITE interface. */
typedef struct{

	unsigned char F_DRV;
	unsigned char I_DRV;
	unsigned char G_ANA;
	unsigned char G_DIG;

	unsigned char CUSTOMER_BITS;
	unsigned char OSC_TRIM;
	unsigned char reserve1;
	unsigned char reserve2;

}SnsCaibDatType;

extern unsigned int ObjDetect_GetApaSensorDetectedDistance(ObjectProcApaSensorIndex index);
extern unsigned char ObjDetect_GetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index);
extern void ObjDetect_SetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index, unsigned char setValue);
extern unsigned int ObjDetect_GetApaSensorDetectedDistanceAddDebouncing(ObjectProcApaSensorIndex index);
extern unsigned int ObjDetect_GetRlsNearestObjDis(void);
extern unsigned int ObjDetect_GetRrsNearestObjDis(void);
extern unsigned int ObjDetect_GetFrsNearestObjDis(void);
extern unsigned int ObjDetect_GetFlsNearestObjDis(void);

extern unsigned int Get_distance_FLMtx_FRMrx(void);
extern unsigned int Get_distance_FLMtx_FLMrx(void);
extern unsigned int Get_distance_FRMtx_FLMrx(void);
extern unsigned int Get_distance_FRMtx_FRMrx(void);
extern unsigned int GetDistance_FLtx_FLMrx(void);
extern unsigned int GetDistance_FLMtx_FLrx(void);
extern unsigned int GetDistance_FRtx_FRMrx(void);
extern unsigned int GetDistance_FRMtx_FRrx(void);
extern unsigned int GetDistance_RLtx_RLMrx(void);
extern unsigned int GetDistance_RLMtx_RLrx(void);
extern unsigned int GetDistance_RRtx_RRMrx(void);
extern unsigned int GetDistance_RRMtx_RRrx(void);
extern unsigned int GetDistance_RLMtx_RLMrx(void);
extern unsigned int GetDistance_RRMtx_RRMrx(void);
extern unsigned int GetDistance_RLMtx_RRMrx(void);
extern unsigned int GetDistance_RRMtx_RLMrx(void);
extern unsigned int ObjDetect_GetRrNearestObjDis(void);
extern unsigned int GetDistance_RRtx_RRrx(void);
extern unsigned int GetDistance_FRMtx_FRMrx(void);
extern unsigned int GetDistance_FLMtx_FLMrx(void);
extern unsigned int ObjDetect_GetRrmNearestObjDis(void);
extern unsigned int ObjDetect_GetRlmNearestObjDis(void);
extern unsigned int ObjDetect_GetRlNearestObjDis(void);
extern unsigned int GetDistance_RLtx_RLrx(void);
extern unsigned int ObjDetect_GetFrNearestObjDis(void);
extern unsigned int GetDistance_FRtx_FRrx(void);
extern unsigned int ObjDetect_GetFrmNearestObjDis(void);
extern unsigned int ObjDetect_GetFlmNearestObjDis(void);
extern unsigned int ObjDetect_GetFlNearestObjDis(void);
extern unsigned int GetDistance_FLtx_FLrx(void);
extern unsigned int ObjDetect_GetRmidNearestObjDis(void);
extern unsigned int ObjDetect_GetFmidNearestObjDis(void);
extern unsigned int getTriangleDisOf_Fmid(void);
extern unsigned int getTriangleDisOf_Rmid (void);
extern unsigned char ObjDetect_GetZoneByRegion(unsigned char cSysType, unsigned char region);
extern unsigned char ObjDetect_GetParkingSwitchPressedFlag(void);
extern unsigned int getSnsDiagnosticStatus(PASysSnsIndexType SnsIndex);
extern void ReqReinitSns(void);
extern unsigned char GetSnsStatus(void);
extern unsigned char GetUssObjectDetectLibVer(char *soft_ver);
extern unsigned int getSysStatus(void);

/* Large FOV object distance. */
extern unsigned int getUssRrObjDis(void);
extern unsigned int getUssRrmObjDis(void);
extern unsigned int getUssRlmObjDis(void);
extern unsigned int getUssRlObjDis(void);
extern unsigned int getUssFrObjDis(void);
extern unsigned int getUssFrmObjDis(void);
extern unsigned int getUssFlmObjDis(void);
extern unsigned int getUssFlObjDis(void);
extern void CalUssSensorOutPutObjDistance(void);

/* Echo height. */
extern unsigned int getRMRechoHeight(void);
extern unsigned int getRMLechoHeight(void);

#endif
