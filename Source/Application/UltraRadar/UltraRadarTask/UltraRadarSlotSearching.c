/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                			     *
*                 All Rights Reserved.                                 						     *
*   Department : CT_ITTI_HZ                                         						     *
*   AUTHOR     :                                       									     *
************************************************************************
* Object        	:
* Module        	:
* Instance      :
* Description  	:
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       	Date    			Name    			Changes and comments
* ----------------------------------------------------------------------
* 0.1    		Aug 28,2018          Zheng Xiaolei 		init version
*======================================================*/
#include "CONFIG.H"
#include "TYPES.H"
#include <Tools.h>
#include "CanAppApa.h"
#include "com_cfg.h"
#include "InputSignalProc.h"
#include "SlotParaCfg.h"
#include "ObjDetect_Pub.h"
#include "il_inc.h"
#include "il_par.h"
#include "UltraRadarSlotSearching.h"
#include "CanApp.h"
#include "InteractiveInterfaceDefine.h"
#include "UssObjDetInterface.h"

#if 0
/*---Global-----------------------------------------------------------*/
extern void ApaSwitch_Main_T10(void);
//extern void APADetermineStatusTask(void);
extern void APACalculateCarPosTask_T10(void);
extern void SlotSearching_GetLeftSideSlotInfo(SlotSearchingResultDataType *slotSearchingResult, unsigned char slotIndex);
extern void SlotSearching_GetRightSideSlotInfo(SlotSearchingResultDataType *slotSearchingResult, unsigned char slotIndex);
extern unsigned int ObjDetect_GetApaSensorDetectedDistance(ObjectProcApaSensorIndex index);
extern APASlotOutlineCoordinateDataType SlotSearching_GetSlotOutlineInfo(unsigned char CurrentProcessSlotIndex);
//extern void TurnOnSlotSearchingFunction(void);
extern void ApplPutTxUSS_Slot_Outline_InfoMsg(Appl_USS_Slot_Outline_Info_msgType setVehInfo);

/*---Global--variable-----------------------------------------------------------*/
//extern Appl_APA_CAN_TxMsg APATxCANMsg;
extern Appl_APA_CAN_RxMsg APARxCANMsg;
extern short USS_Slot_OutLine_X_Value;
extern short USS_Slot_OutLine_Y_Value;


/*---Local--variable-----------------------------------------------------------*/
signed short FrsNonHandlerObjDis = 0;
signed short FlsNonHandlerObjDis = 0;
signed short RrsNonHandlerObjDis = 0;
signed short RlsNonHandlerObjDis = 0;
SlotSearchingResultDataType SlotLeftInformation[APA_SLOT_SUPPORT_MAX_SLOT_NUM];
SlotSearchingResultDataType SlotRightInformation[APA_SLOT_SUPPORT_MAX_SLOT_NUM];
extern SlotSearchingResultDataType SlotLeftNearestInformation;
extern SlotSearchingResultDataType SlotRightNearestInformation;
signed cAPAState;
unsigned char SlotOutLineFlag = FALSE;
unsigned char SlotOutLineCount = 0;
SlotSearchingDirection SlotOutlineDir = SlotSearching_None;
APACarCoordinateDataCalFloatType SlotSearchingCarPosition;

/***********************************************************************
*  Name        : APASlotSearchingHandler
*  Description :
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void APASlotSearchingHandler(void)
{
	ApaSwitch_Main_T10();
	//APADetermineStatusTask();
	APACalculateCarPosTask_T10();
	UltraRadarSlotSearchingHandlerMsg();
}

/***********************************************************************
*  Name        : UltraRadarSlotSearchingHandlerMsg
*  Description :
*  Parameter   : None
*  Returns     : None
***********************************************************************/
float32 drx_test;
float32 dry_test;
float32 drtheta_test;
float32 drreserve_test;

void UltraRadarSlotSearchingHandlerMsg(void)
{
	U8 i , SlotNum;
	signed char k;
	unsigned int * ppp;
	unsigned int * pppp;
	unsigned int * ppppp;
	#ifndef REPLAY_DEBUG
	FrsNonHandlerObjDis = ObjDetect_GetApaSensorDetectedDistance(OBJ_PROC_FRS_INDEX);
	FlsNonHandlerObjDis = ObjDetect_GetApaSensorDetectedDistance(OBJ_PROC_FLS_INDEX);
	RrsNonHandlerObjDis = ObjDetect_GetApaSensorDetectedDistance(OBJ_PROC_RRS_INDEX);
	RlsNonHandlerObjDis = ObjDetect_GetApaSensorDetectedDistance(OBJ_PROC_RLS_INDEX);
	#else
	FlsNonHandlerObjDis = can_receive_sig(USS_FL_long);
	FrsNonHandlerObjDis = can_receive_sig(USS_FR_long);
	RlsNonHandlerObjDis = can_receive_sig(USS_RL_long);
	RrsNonHandlerObjDis = can_receive_sig(USS_RR_long);
	#endif

	cAPAState= APACarPar.APAState;

	SlotSearchingCarPosition.Coordinate.x = APACarPar.APACarCenterPt.Coordinate.x;
	SlotSearchingCarPosition.Coordinate.y = APACarPar.APACarCenterPt.Coordinate.y;
	SlotSearchingCarPosition.CarAng = APACarPar.APACarCenterPt.CarAng;

	drx_test = SlotSearchingCarPosition.Coordinate.x;
	dry_test = SlotSearchingCarPosition.Coordinate.y;
	drtheta_test = SlotSearchingCarPosition.CarAng;

	for(i=0;i<APA_SLOT_SUPPORT_MAX_SLOT_NUM;i++)
	{
		SlotSearching_GetLeftSideSlotInfo(&SlotLeftInformation[i], i);
		SlotSearching_GetRightSideSlotInfo(&SlotRightInformation[i], i);
	}

	SlotNum = APACarPar.Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_FLS_SENSOR_INDEX].SlotNum;
	_memset((U8*)&SlotLeftNearestInformation, 0, sizeof(SlotSearchingResultDataType));
	if(SlotNum > 0)
	{
		for(k = SlotNum - 1; k>=0; k--)
		{
			if(APACarPar.Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_FLS_SENSOR_INDEX].SlotPar[k].CarPassTheSlotEndPtDistance
				>= APACarPassTheSlotConfirmDis)
			{
				_memcpy((U8*)&SlotLeftNearestInformation, (U8*)&SlotLeftInformation[k], sizeof(SlotSearchingResultDataType));
				break;
			}
		}
	}


	SlotNum = APACarPar.Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_FRS_SENSOR_INDEX].SlotNum;
	_memset((U8*)&SlotRightNearestInformation, 0, sizeof(SlotSearchingResultDataType));
	if(SlotNum > 0)
	{
		for(k = SlotNum - 1; k>=0; k--)
		{
			if(APACarPar.Slot[APA_SLOT_SUPPORT_SEARCHING_SLOT_FRS_SENSOR_INDEX].SlotPar[k].CarPassTheSlotEndPtDistance
				>= APACarPassTheSlotConfirmDis)
			{
				_memcpy((U8*)&SlotRightNearestInformation, (U8*)&SlotRightInformation[k], sizeof(SlotSearchingResultDataType));
				break;
			}
		}
	}

	ppp = &drx_test;
	pppp = &dry_test;
	ppppp = &drtheta_test;
	if(GetMmiTouchDebugFlag())
	{
		can_send_sig(UssDr_x_L,*ppp);
		can_send_sig(UssDr_y_L,*pppp);
		can_send_sig(UssDr_theta_L,*ppppp);
	}
}

/***********************************************************************
*  Name        : UltraRadarSlotSearchingSlotOutLineMsg
*  Description :
*  Parameter   : None
*  Returns     : None
***********************************************************************/
//extern PDC_CAN_RX_DATA_Type PdcCanData_Rx;
void UltraRadarSlotSearchingSlotOutLineMsg(void)
{
	APASlotOutlineCoordinateDataType SlotOutlineCoordinate = {{{0},{0}},{0},{{0},{0}},{0},{0},0,0};

	if(SlotOutlineDir == SlotSearching_Left)
	{
		SlotOutlineCoordinate = SlotSearching_GetSlotOutlineInfo(APACarPar.APALeftSlotDataIndex);
	}
	else if(SlotOutlineDir == SlotSearching_Right)
	{
		SlotOutlineCoordinate = SlotSearching_GetSlotOutlineInfo(APACarPar.APARightSlotDataIndex);
	}

	if(SlotOutLineFlag == TRUE)
	{
		if(SlotOutLineCount < SlotOutlineCoordinate.ObjPtCnt)
		{
			USS_Slot_OutLine_X_Value = SlotOutlineCoordinate.ObjPt[SlotOutLineCount].x;
			USS_Slot_OutLine_Y_Value = SlotOutlineCoordinate.ObjPt[SlotOutLineCount].y;
			if(GetMmiTouchDebugFlag() == 1)
			{
				can_send_sig(Uss_Slot_Outline_X,USS_Slot_OutLine_X_Value);
				can_send_sig(Uss_Slot_Outline_Y,USS_Slot_OutLine_Y_Value);
			}
			else
			{}
			SlotOutLineCount++;
		}
		else
		{
			SlotOutLineFlag = FALSE;
			SlotOutLineCount = 0;
		}
	}
	else
	{
		SlotOutLineCount = 0;
	}

}
#endif
/**************** END OF FILE *****************************************/
