/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   		   *
*   AUTHOR	   : 									                   *
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
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 0.1    	2017/8/28  					    Initial version
*=====================================================================*/
#include "CONFIG.H"
#include "TYPES.H"
#include "il_inc.h"
#include "il_par.h"
#include "CanApp.h"
#include "SocCommunicator.h"
#include "SocManager.h"
#include "TYPES.H"
#include "Sig_Combine.H"
#include "Signal_IF.H"
#include "CanMacroDefine.h"
#include "APSAPP.h"
#include "ApsCanApp.h"
#include "M4MsgHandler_IF.h"
#include "math.h"
#include "UssInfoMsg.h"
#include "FVAlgLibInterface.h"


/*********************Internal variable*******************/
U8 APSModuleCurrentStatus = APS_PARKING_INIT;
U8 APSModuleLastStatus = APS_PARKING_INIT;
PARKING_SLOT_TYPE APA_Park_type = ParkingType_PARALLEL;
U8 TargetSlotInfo_ParkDirection = 0;

BOOL APA_FoundSlotBuzzerTip = FALSE;


/*********************static variable*******************/
static BOOL ConfirmSwitchSendFlag = FALSE;
static BOOL ParkDirectionSendFlag = FALSE;


/*********************extern variable*******************/
extern BOOL DRIsAbsolutePose;
extern BOOL SOC_Send_Point_Flag;
extern float32 Facing_Space;

extern APA_SLOTINFO APA_SlotInfo[8];
extern APS_PATH_PLAN_STATUS PathPlanStatus;
extern APA_RELOAT_PLACE_INFO apa_reloat_place_info;


/*********************static function*******************/
static void APSModuleStatusChange(void);
static void APSModuleInitHandler(void);
static void APSModuleStandbyHandler(void);
static void APSModuleParkingInSearchHandler(void);

static void APSModuleParkingOutSearchHandler(void);
static void APSModuleMapUpdateHandler(void);
static void APSModuleParkingActiveInHandler(void);
static void APSModuleParkingActiveOutHandler(void);

static void APSModuleAvmModeHandler();
static void APA_SearchInfo_Sender(void);
static void APA_ParkIn_SlotInfo_Sender(void);
static void APA_ParkIn_TargetSlotInfo_Receiver(void);

static void APA_ParkInSearch_CurbstoneInfo_Sender(void);
static void APA_ParkInSearch_FoundSlotBuzzerTip_Sender(void);
static void APA_ParkingActiveIn_ReloadPlaceInfo_Sender(void);
static void APA_ParkingActiveIn_FreeSpace_Sender(void);

static void APA_ParkingActiveIn_TargetTracing_Receiver(void);
static void APA_ParkingActiveIn_PathTracing_Receiver(void);
static void APA_Clear_APA_FoundSlotBuzzerTip(void);
static void APSModuleStatusMessageHandler(APS_MODULE_STATUS Status,U8 DelayTime);

static void APA_ParkingActiveIn_BothSidesInfo_Receiver(void);
static void APA_CloseReloadPlaceInfo_Sender(void);
static void APA_ExitParkInSearch_CurbstoneInfo_Clear(void);



const APS_EventCallback_t APS_EventProcessList[APS_STATUS_MAX] =
{
    &APSModuleInitHandler,
	&APSModuleStandbyHandler,
	&APSModuleParkingInSearchHandler,
	&APSModuleParkingOutSearchHandler,
	&APSModuleMapUpdateHandler,
	&APSModuleParkingActiveInHandler,
	&APSModuleParkingActiveOutHandler,
	&APSModuleAvmModeHandler,
};      
#define APS_DO_EVENT_PROCESSER(event)   APS_EventProcessList[event]()

/***********************************************************************
*  Name        : APS_Module_Manager_5ms_Entry
*  Description :
*  Parameter   :
*  Returns     :
***********************************************************************/
void APS_Module_Manager_5ms_Entry(void)
{  
    APSModuleStatusChange();
	APS_DO_EVENT_PROCESSER(APSModuleCurrentStatus);	
	APSModuleStatusMessageHandler(APSModuleCurrentStatus,40);
	APA_ParkInSearch_FoundSlotBuzzerTip_Sender();	
}

static void APSModuleStatusChange(void)
{
    APSModuleCurrentStatus = can_receive_sig(ADV_ParkStatus);
    can_send_sig(APS_Status, APSModuleCurrentStatus);
	
	if(APSModuleCurrentStatus == 0xC)		//AVM_MODE
	{
		APSModuleCurrentStatus = APS_PARKING_AVMMODE;
	}
	else if(APSModuleCurrentStatus >= APS_STATUS_MAX)
	{
		APSModuleCurrentStatus = APSModuleLastStatus;
	}	
	
    if(APSModuleCurrentStatus != APSModuleLastStatus)
    {
        //exit Last Status
        switch(APSModuleLastStatus)
        {

			case APS_PARKING_INIT:
				Timer_Start(OPEN_VEHICLE_DEAD_RECKONING, 20,TIMER_PERIODIC);
				break;
			
			case APS_PARKING_STANDBY:
			break;
            case APS_PARKING_SEARCH_PARKIN:
				SOC_Send_Point_Flag = FALSE;
                Timer_Stop(DR_ISRESET_POLLING);
				APA_Clear_APA_FoundSlotBuzzerTip();
			break;
            case APS_PARKING_SEARCH_PARKOUT:
			break;
            case APS_PARKING_MAP_UPDATE:				
				APA_ExitParkInSearch_CurbstoneInfo_Clear();
			break;
            case APS_PARKING_ACTIVE_PARKIN:
				APA_CloseReloadPlaceInfo_Sender();
				break;

				
            case APS_PARKING_ACTIVE_PARKOUT:
				break;
            default:
			break;  

        }

        //enter Current Status
        switch(APSModuleCurrentStatus)
        {
        	case APS_PARKING_INIT:
				Timer_Stop(DR_ISRESET_POLLING);
				Timer_Stop(OPEN_VEHICLE_DEAD_RECKONING);
			break;
			
            case APS_PARKING_STANDBY:
				APS_Init_Handler();
                ClearFacing_Space(); 
                ClearDownSlotStatus();

				DRInitRequest(TRUE);
				
				APA_ExitParkInSearch_CurbstoneInfo_Clear();
				Timer_Start(DR_ISRESET_POLLING, 20,TIMER_PERIODIC);
            	break;
            
            case APS_PARKING_SEARCH_PARKIN:
				SOC_Send_Point_Flag = FALSE;
                DRInitRequest(TRUE);
				Set_Dr_Calculate(TRUE);
				
                Timer_Start(DR_ISRESET_POLLING, 20,TIMER_PERIODIC);            
                Timer_Start(OPEN_VEHICLE_DEAD_RECKONING, 20,TIMER_PERIODIC);
            	break;
            
            case APS_PARKING_SEARCH_PARKOUT:                             
                Timer_Stop(OPEN_VEHICLE_DEAD_RECKONING); 
           		break;
            
            case APS_PARKING_MAP_UPDATE:				
				Get_FV_Current_DR();
                Set_Avm_OppositeSpace(GetFacing_Space());
                Set_Avm_NeighBoringSlotStatus(GetDownSlotSODStatus());                               
            	break;
            
            case APS_PARKING_ACTIVE_PARKIN:
				Clear_ReloatPlaceInfo();
           		break;
            case APS_PARKING_ACTIVE_PARKOUT:   
				break;
			case APS_PARKING_AVMMODE:
				APS_Init_Handler();
				DRInitRequest(TRUE);			
				APA_ExitParkInSearch_CurbstoneInfo_Clear();
            	break;
				
            default:
            	break;
        }       
    }
    
    APSModuleLastStatus = APSModuleCurrentStatus;    
    Notify_FV_ApaState(APSModuleCurrentStatus);
}

static void APSModuleInitHandler(void)
{

}


static void APSModuleStandbyHandler(void)
{
    

}

static void APSModuleParkingInSearchHandler(void)
{
   APA_SearchInfo_Sender();
   APA_ParkIn_SlotInfo_Sender();
   APA_ParkIn_TargetSlotInfo_Receiver();

   APA_ParkInSearch_CurbstoneInfo_Sender();
   APA_ParkingActiveIn_FreeSpace_Sender();
   APA_ParkingActiveIn_BothSidesInfo_Receiver();
}

static void APSModuleParkingOutSearchHandler(void)
{
	APA_ParkingActiveIn_FreeSpace_Sender();
}

static void APSModuleMapUpdateHandler(void)
{	
	APA_ParkIn_TargetSlotInfo_Receiver();
	APA_ParkInSearch_CurbstoneInfo_Sender();
	APA_ParkingActiveIn_FreeSpace_Sender();
}
static void APSModuleParkingActiveInHandler(void)
{
	APA_ParkingActiveIn_ReloadPlaceInfo_Sender();
	APA_ParkingActiveIn_FreeSpace_Sender();
	APA_ParkingActiveIn_TargetTracing_Receiver();
	APA_ParkingActiveIn_PathTracing_Receiver();
}

static void APSModuleParkingActiveOutHandler(void)
{
	APA_ParkingActiveIn_FreeSpace_Sender();
	APA_ParkingActiveIn_TargetTracing_Receiver();
	APA_ParkingActiveIn_PathTracing_Receiver();
}

static void APSModuleAvmModeHandler()
{

}


/***********************************************************************
*  Name        : APS_Init_Handler
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APS_Init_Handler(void)
{	
	DRIsAbsolutePose = FALSE;

	SocPositionSendStatus = FALSE;
	SocParkTypeSendStatus = FALSE;
	ConfirmSwitchSendFlag = FALSE;
	ParkDirectionSendFlag = FALSE;
}

/***********************************************************************
*  Name        : GetAPSCurrentStatus
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
APS_MODULE_STATUS GetAPSCurrentStatus(void)
{
	return APSModuleCurrentStatus;
}

/***********************************************************************
*  Name         : APSModuleStatusMessageHandler
*  Description  : Send APA state to SOC
*  Parameter 1  : APA state
*  Parameter 2  : DelayTime
*  Returns      : 
***********************************************************************/
void APSModuleStatusMessageHandler(APS_MODULE_STATUS Status,U8 DelayTime)
{	
    U8 APSMsg = 0;
    static U8 TimeCnt = 0;
	if(GetSocCurrentAPSStatus() != Status && CAN_FACTROY_MODE != uAVSViewMode)
	{   
        if(0 == TimeCnt)
        {
            APSMsg = Status;
            SocManager_SendMsg(HQ_CMD, TYPE_EVENT, RADIO_NOTIFY_SEND_APA_SYSTEM_STATUS, 1, &APSMsg);
        }
        
        if(TimeCnt++ >= DelayTime)
        {
            TimeCnt = 0;
        }
	}
	else
	{
		TimeCnt = 0;
	}
}

/***********************************************************************
*  Name 	   : APSModuleStsChangeToInitByAcc
*  Description : 
*  Parameter   :
*  Returns	   : 
***********************************************************************/
BOOL APSModuleStsChangeToInitByAcc(void)
{
	BOOL bChangeToInitStsByAcc = FALSE;
	U8 bAccPowerModeSts = 0x0;
	
	CS_SIG_SyncReceive(SIG_ACC_CAN_IN_STATUS, &bAccPowerModeSts);

	if((bAccPowerModeSts == FALSE) || (bPowerOnAllow ==FALSE))
	{
		bChangeToInitStsByAcc = TRUE;
		APSModuleCurrentStatus = APS_PARKING_INIT;
	}
	return bChangeToInitStsByAcc;
}

/***********************************************************************
*  Name 	   : APSModuleStsChangeToInitByAcc
*  Description : send park type and Search Mode
*  Parameter   :
*  Returns	   : 
***********************************************************************/
void APA_SearchInfo_Sender(void)
{
    PARKING_SLOT_TYPE APA_Park_type_cur;
    static PARKING_SLOT_TYPE APA_Park_type_bak = ParkingType_PERPENDICULAR;
	
	static SEARCHING_MODE APA_SlotSearchMode_bak = SearchMode_AUTO;
    SEARCHING_MODE APA_SlotSearchMode_cur;
    U8 Search_Msg[2] = {0};
    
//    APA_Park_type_cur = can_receive_sig(TargetSelection_ParkType);
	if(APA_Park_type_cur == ParkingType_INACTIVE)
	{
		APA_Park_type_cur = APA_Park_type_bak;
	}
	
    APA_SlotSearchMode_cur = can_receive_sig(ADV_ParkInSlotSearchMode);

    if((APA_SlotSearchMode_cur != APA_SlotSearchMode_bak) && (CAN_FACTROY_MODE != uAVSViewMode))
    {
		if(APA_SlotSearchMode_cur == SearchMode_MANUAL)
		{
			APA_Clear_APA_FoundSlotBuzzerTip();
		}
		
        APA_Park_type = APA_Park_type_cur;
		APA_Park_type_bak = APA_Park_type_cur;
		APA_SlotSearchMode_bak = APA_SlotSearchMode_cur;

        Search_Msg[1] = APA_SlotSearchMode_bak + 1;        
        SocManager_SendMsg(HQ_CMD,TYPE_EVENT,MCU_NOTIFY_SOC_SEARCHINFO,2,Search_Msg);
    }
}


/***********************************************************************
*  Name 	   : APA_ParkIn_SlotInfo_Sender
*  Description : send slot infomation
*  Parameter   :
*  Returns	   : 
***********************************************************************/
void APA_ParkIn_SlotInfo_Sender(void)
{
	U8 ParkPlace_Type_ToADV = 0;

	switch(can_ParkPlace_Type)
	{
		case 0x1:				
			ParkPlace_Type_ToADV = ParkingType_PERPENDICULAR;
			break;
		
		case 0x2:
			ParkPlace_Type_ToADV = ParkingType_PARALLEL;
			break;

		case 0x3:
			ParkPlace_Type_ToADV = ParkingType_OBLIQUE;
			break;				
	}
	
	if(TRUE == SOC_Send_Point_Flag && (APSModuleCurrentStatus == APS_PARKING_SEARCH_PARKIN) && (TRUE == APA_FoundSlotBuzzerTip))
	{
		if((1000 >= APA_SlotInfo[0].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[0].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[0].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[0].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot1_DetectStatus,    APA_SlotInfo[0].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot1_Info,            APA_SlotInfo[0].APS_Slot1_Info);
			can_send_sig(APS_Slot1_ParkDirection,   APA_SlotInfo[0].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot1_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot1_Length,          APA_SlotInfo[0].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot1_LineAngle,       APA_SlotInfo[0].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot1CenterPoint_Angle,APA_SlotInfo[0].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot1_Width,           APA_SlotInfo[0].APS_Slot_Width);
			can_send_sig(APS_Slot1CenterPoint_X1,   APA_SlotInfo[0].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot1CenterPoint_Y1,   APA_SlotInfo[0].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot1_DetectStatus,    0);
			can_send_sig(APS_Slot1_Info,            0);
			can_send_sig(APS_Slot1_ParkDirection,   0);
			can_send_sig(APS_Slot1_ParkType,        0);

			can_send_sig(APS_Slot1_Length,          0);      //cm
			can_send_sig(APS_Slot1_LineAngle,       0);			
			can_send_sig(APS_Slot1CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot1_Width,           0);
			can_send_sig(APS_Slot1CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot1CenterPoint_Y1,   0 + SLOTOFFSET);
		}

		//APS_Slot2
		if((1000 >= APA_SlotInfo[1].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[1].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[1].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[1].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot2_DetectStatus,    APA_SlotInfo[1].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot2_Info,            APA_SlotInfo[1].APS_Slot1_Info);
			can_send_sig(APS_Slot2_ParkDirection,   APA_SlotInfo[1].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot2_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot2_Length,          APA_SlotInfo[1].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot2_LineAngle,       APA_SlotInfo[1].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot2CenterPoint_Angle,APA_SlotInfo[1].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot2_Width,           APA_SlotInfo[1].APS_Slot_Width);
			can_send_sig(APS_Slot2CenterPoint_X1,   APA_SlotInfo[1].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot2CenterPoint_Y1,   APA_SlotInfo[1].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot2_DetectStatus,    0);
			can_send_sig(APS_Slot2_Info,            0);
			can_send_sig(APS_Slot2_ParkDirection,   0);
			can_send_sig(APS_Slot2_ParkType,        0);

			can_send_sig(APS_Slot2_Length,          0);      //cm
			can_send_sig(APS_Slot2_LineAngle,       0);			
			can_send_sig(APS_Slot2CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot2_Width,           0);
			can_send_sig(APS_Slot2CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot2CenterPoint_Y1,   0 + SLOTOFFSET);
		}

		//APS_Slot3
		if((1000 >= APA_SlotInfo[2].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[2].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[2].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[2].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot3_DetectStatus,    APA_SlotInfo[2].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot3_Info,            APA_SlotInfo[2].APS_Slot1_Info);
			can_send_sig(APS_Slot3_ParkDirection,   APA_SlotInfo[2].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot3_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot3_Length,          APA_SlotInfo[2].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot3_LineAngle,       APA_SlotInfo[2].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot3CenterPoint_Angle,APA_SlotInfo[2].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot3_Width,           APA_SlotInfo[2].APS_Slot_Width);
			can_send_sig(APS_Slot3CenterPoint_X1,   APA_SlotInfo[2].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot3CenterPoint_Y1,   APA_SlotInfo[2].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot3_DetectStatus,    0);
			can_send_sig(APS_Slot3_Info,            0);
			can_send_sig(APS_Slot3_ParkDirection,   0);
			can_send_sig(APS_Slot3_ParkType,        0);

			can_send_sig(APS_Slot3_Length,          0);      //cm
			can_send_sig(APS_Slot3_LineAngle,       0);
			can_send_sig(APS_Slot3CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot3_Width,           0);
			can_send_sig(APS_Slot3CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot3CenterPoint_Y1,   0 + SLOTOFFSET);
		}

		//APS_Slot4
		if((1000 >= APA_SlotInfo[3].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[3].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[3].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[3].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot4_DetectStatus,    APA_SlotInfo[3].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot4_Info,            APA_SlotInfo[3].APS_Slot1_Info);
			can_send_sig(APS_Slot4_ParkDirection,   APA_SlotInfo[3].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot4_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot4_Length,          APA_SlotInfo[3].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot4_LineAngle,       APA_SlotInfo[3].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot4CenterPoint_Angle,APA_SlotInfo[3].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot4_Width,           APA_SlotInfo[3].APS_Slot_Width);
			can_send_sig(APS_Slot4CenterPoint_X1,   APA_SlotInfo[3].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot4CenterPoint_Y1,   APA_SlotInfo[3].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot4_DetectStatus,    0);
			can_send_sig(APS_Slot4_Info,            0);
			can_send_sig(APS_Slot4_ParkDirection,   0);
			can_send_sig(APS_Slot4_ParkType,        0);

			can_send_sig(APS_Slot4_Length,          0);      //cm
			can_send_sig(APS_Slot4_LineAngle,       0);
			can_send_sig(APS_Slot4CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot4_Width,           0);
			can_send_sig(APS_Slot4CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot4CenterPoint_Y1,   0 + SLOTOFFSET);
		}

		//APS_Slot5
		if((1000 >= APA_SlotInfo[4].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[4].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[4].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[4].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot5_DetectStatus,    APA_SlotInfo[4].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot5_Info,            APA_SlotInfo[4].APS_Slot1_Info);
			can_send_sig(APS_Slot5_ParkDirection,   APA_SlotInfo[4].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot5_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot5_Length,          APA_SlotInfo[4].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot5_LineAngle,       APA_SlotInfo[4].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot5CenterPoint_Angle,APA_SlotInfo[4].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot5_Width,           APA_SlotInfo[4].APS_Slot_Width);
			can_send_sig(APS_Slot5CenterPoint_X1,   APA_SlotInfo[4].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot5CenterPoint_Y1,   APA_SlotInfo[4].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot5_DetectStatus,    0);
			can_send_sig(APS_Slot5_Info,            0);
			can_send_sig(APS_Slot5_ParkDirection,   0);
			can_send_sig(APS_Slot5_ParkType,        0);

			can_send_sig(APS_Slot5_Length,          0);      //cm
			can_send_sig(APS_Slot5_LineAngle,       0);
			can_send_sig(APS_Slot5CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot5_Width,           0);
			can_send_sig(APS_Slot5CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot5CenterPoint_Y1,   0 + SLOTOFFSET);
		}

		//APS_Slot6
		if((1000 >= APA_SlotInfo[5].APS_SlotCenterPoint_X && -1000 <= APA_SlotInfo[5].APS_SlotCenterPoint_X)
		&& (1000 >= APA_SlotInfo[5].APS_SlotCenterPoint_Y && -1000 <= APA_SlotInfo[5].APS_SlotCenterPoint_Y))
		{
			can_send_sig(APS_Slot6_DetectStatus,    APA_SlotInfo[5].APS_Slot1_DetectStatus);
			can_send_sig(APS_Slot6_Info,            APA_SlotInfo[5].APS_Slot1_Info);
			can_send_sig(APS_Slot6_ParkDirection,   APA_SlotInfo[5].APS_Slot1_ParkDirection - 1);
			can_send_sig(APS_Slot6_ParkType,        ParkPlace_Type_ToADV);

			can_send_sig(APS_Slot6_Length,          APA_SlotInfo[5].APS_Slot_Length);      //cm
			can_send_sig(APS_Slot6_LineAngle,       APA_SlotInfo[5].APS_Slot_LineAngle);			
			can_send_sig(APS_Slot6CenterPoint_Angle,APA_SlotInfo[5].APS_Slot_LineAngle * 10);
			
			can_send_sig(APS_Slot6_Width,           APA_SlotInfo[5].APS_Slot_Width);
			can_send_sig(APS_Slot6CenterPoint_X1,   APA_SlotInfo[5].APS_SlotCenterPoint_X + SLOTOFFSET);
			can_send_sig(APS_Slot6CenterPoint_Y1,   APA_SlotInfo[5].APS_SlotCenterPoint_Y + SLOTOFFSET);
		}
		else
		{
			can_send_sig(APS_Slot6_DetectStatus,    0);
			can_send_sig(APS_Slot6_Info,            0);
			can_send_sig(APS_Slot6_ParkDirection,   0);
			can_send_sig(APS_Slot6_ParkType,        0);

			can_send_sig(APS_Slot6_Length,          0);      //cm
			can_send_sig(APS_Slot6_LineAngle,       0);
			can_send_sig(APS_Slot6CenterPoint_Angle,0);
			
			can_send_sig(APS_Slot6_Width,           0);
			can_send_sig(APS_Slot6CenterPoint_X1,   0 + SLOTOFFSET);
			can_send_sig(APS_Slot6CenterPoint_Y1,   0 + SLOTOFFSET);
		}
	
	}	
	else
	{
		can_send_sig(APS_Slot1_DetectStatus,	0);
		can_send_sig(APS_Slot1_Info,			0);
		can_send_sig(APS_Slot1_ParkDirection,	0);
		can_send_sig(APS_Slot1_ParkType,		0);
		
		can_send_sig(APS_Slot1_Length,			0); 	 //cm
		can_send_sig(APS_Slot1_LineAngle,		0);
		can_send_sig(APS_Slot1CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot1_Width,			0);
		can_send_sig(APS_Slot1CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot1CenterPoint_Y1,	0 + SLOTOFFSET);
		
		//APS_Slot2
		can_send_sig(APS_Slot2_DetectStatus,	0);
		can_send_sig(APS_Slot2_Info,			0);
		can_send_sig(APS_Slot2_ParkDirection,	0);
		can_send_sig(APS_Slot2_ParkType,		0);
		
		can_send_sig(APS_Slot2_Length,			0); 	 //cm
		can_send_sig(APS_Slot2_LineAngle,		0);
		can_send_sig(APS_Slot2CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot2_Width,			0);
		can_send_sig(APS_Slot2CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot2CenterPoint_Y1,	0 + SLOTOFFSET);
		
		//APS_Slot3
		can_send_sig(APS_Slot3_DetectStatus,	0);
		can_send_sig(APS_Slot3_Info,			0);
		can_send_sig(APS_Slot3_ParkDirection,	0);
		can_send_sig(APS_Slot3_ParkType,		0);
		
		can_send_sig(APS_Slot3_Length,			0); 	 //cm
		can_send_sig(APS_Slot3_LineAngle,		0);
		can_send_sig(APS_Slot3CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot3_Width,			0);
		can_send_sig(APS_Slot3CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot3CenterPoint_Y1,	0 + SLOTOFFSET);
		
		//APS_Slot4
		can_send_sig(APS_Slot4_DetectStatus,	0);
		can_send_sig(APS_Slot4_Info,			0);
		can_send_sig(APS_Slot4_ParkDirection,	0);
		can_send_sig(APS_Slot4_ParkType,		0);
		
		can_send_sig(APS_Slot4_Length,			0); 	 //cm
		can_send_sig(APS_Slot4_LineAngle,		0);
		can_send_sig(APS_Slot4CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot4_Width,			0);
		can_send_sig(APS_Slot4CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot4CenterPoint_Y1,	0 + SLOTOFFSET);
		
		//APS_Slot5
		can_send_sig(APS_Slot5_DetectStatus,	0);
		can_send_sig(APS_Slot5_Info,			0);
		can_send_sig(APS_Slot5_ParkDirection,	0);
		can_send_sig(APS_Slot5_ParkType,		0);
		
		can_send_sig(APS_Slot5_Length,			0); 	 //cm
		can_send_sig(APS_Slot5_LineAngle,		0);
		can_send_sig(APS_Slot5CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot5_Width,			0);
		can_send_sig(APS_Slot5CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot5CenterPoint_Y1,	0 + SLOTOFFSET);
		
		//APS_Slot6
		can_send_sig(APS_Slot6_DetectStatus,	0);
		can_send_sig(APS_Slot6_Info,			0);
		can_send_sig(APS_Slot6_ParkDirection,	0);
		can_send_sig(APS_Slot6_ParkType,		0);
		
		can_send_sig(APS_Slot6_Length,			0); 	 //cm
		can_send_sig(APS_Slot6_LineAngle,		0);
		can_send_sig(APS_Slot6CenterPoint_Angle,0);
		
		can_send_sig(APS_Slot6_Width,			0);
		can_send_sig(APS_Slot6CenterPoint_X1,	0 + SLOTOFFSET);
		can_send_sig(APS_Slot6CenterPoint_Y1,	0 + SLOTOFFSET);

	}
}


void APA_ParkIn_TargetSlotInfo_Receiver(void)
{
    S8 TargetSlotInfo[10];
	U8 TargetSlotInfo_ParkType;
	
	S16 TargetSlotInfo_X;
	S16 TargetSlotInfo_Y;   
	U16 TargetSlotInfo_Angle;
	U16 TargetSlotInfo_LineAngle;

	static U8 CAN_RX_TargetSelection_ConfirmReq_backup = 0;
	
	U8 CAN_RX_TargetSelection_ConfirmReq = can_receive_sig(TargetSelection_ConfirmReq);	
	U8 CAN_RX_Target_Selection_ParkDirection = can_receive_sig(TargetSelection_ParkDirection);
	
	if(CAN_RX_TargetSelection_ConfirmReq == 0x1 && CAN_RX_TargetSelection_ConfirmReq_backup == 0x0)
	{
		ConfirmSwitchSendFlag = TRUE;
	}	
	CAN_RX_TargetSelection_ConfirmReq_backup = CAN_RX_TargetSelection_ConfirmReq;

	if(ConfirmSwitchSendFlag == TRUE && 0x1 == can_receive_sig(ADV_ParkInSlotSearchMode))	//Manual mode
	{
		ConfirmSwitchSendFlag = FALSE;
		TargetSlotInfo_X = can_receive_sig(TargetSelectionCenter_X) - SLOTOFFSET;
		TargetSlotInfo_Y = can_receive_sig(TargetSelectionCenter_Y) - SLOTOFFSET;	
		TargetSlotInfo_Angle = can_receive_sig(TargetSelectionCenter_Angle);
		
		TargetSlotInfo_LineAngle = can_receive_sig(TargetSelection_LineAngle);
		TargetSlotInfo_ParkType = can_receive_sig(TargetSelection_ParkType);

	    TargetSlotInfo[0] = TargetSlotInfo_X & 0X00FF;
	    TargetSlotInfo[1] = (TargetSlotInfo_X  >> 8) & 0X00FF;
	    TargetSlotInfo[2] = TargetSlotInfo_Y & 0X00FF;
	    TargetSlotInfo[3] = (TargetSlotInfo_Y  >> 8) & 0X00FF;
   
	    TargetSlotInfo[4] = TargetSlotInfo_Angle & 0X00FF;
	    TargetSlotInfo[5] = (TargetSlotInfo_Angle  >> 8) & 0X00FF;
	    TargetSlotInfo[6] = TargetSlotInfo_LineAngle & 0X00FF;
		TargetSlotInfo[7] = (TargetSlotInfo_LineAngle  >> 8) & 0X00FF;

	    TargetSlotInfo[8] = TargetSlotInfo_ParkType & 0XFF;
	    TargetSlotInfo[9] = CAN_RX_Target_Selection_ParkDirection & 0XFF;    
	    SocManager_SendMsg(HQ_CMD,TYPE_EVENT,MCU_SEND_SOC_TARGETSLOT_POINT,10,TargetSlotInfo); 	
	}
}

/***********************************************************************
*  Name        : APA_ParkInSearch_FoundSlotBuzzerTip_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkInSearch_FoundSlotBuzzerTip_Sender(void)
{
	can_send_sig(FoundSlotBuzzerTip, APA_FoundSlotBuzzerTip); 
}

void APA_Clear_APA_FoundSlotBuzzerTip(void)
{
	APA_FoundSlotBuzzerTip = FALSE;
}

/***********************************************************************
*  Name        : APA_ParkInSearch_CurbstoneInfo_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkInSearch_CurbstoneInfo_Sender(void)
{
	static gTye_CurbstoneInfo_st CurbstoneInfo_Right = {0};
	static gTye_CurbstoneInfo_st CurbstoneInfo_Left  = {0};
	
	g_FV_adiGetCurbstoneInfo_bl(&CurbstoneInfo_Right,g_SideRight_enm);	
	g_FV_adiGetCurbstoneInfo_bl(&CurbstoneInfo_Left,g_SideLeft_enm);
	
	/*********************Left Curb stone Info **********************/ 
	if(CurbstoneInfo_Left.CurbDegValid == TRUE)
	{
		can_send_sig(LeftCurb_Angle, CurbstoneInfo_Left.CurbDeg_si16 + ANGELOFFSET); 
	}
	else
	{		
		can_send_sig(LeftCurb_Angle, ANGELOFFSET); 
	}	
	can_send_sig(LeftCurb_AngleFlag, CurbstoneInfo_Left.CurbDegValid);
 
//	can_send_sig(LeftCurb_Height, CurbstoneInfo_Left.CurbDeg_si16);	
//	can_send_sig(LeftCurb_Direction, CurbstoneInfo_Left.CurbDeg_si16); 
	
	if(CurbstoneInfo_Left.CurbEndValid == TRUE)
	{
		if(CurbstoneInfo_Left.CurbEndP_st.X_si16 != 0)
		{
			can_send_sig(LeftCurb_EndPointX, CurbstoneInfo_Left.CurbEndP_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
		}
		else
		{
			can_send_sig(LeftCurb_EndPointX, SLOTOFFSET); 
		}

		if(CurbstoneInfo_Left.CurbEndP_st.Y_si16 != 0)
		{
			can_send_sig(LeftCurb_EndPointY, CurbstoneInfo_Left.CurbEndP_st.Y_si16 + SLOTOFFSET);
		}
		else
		{
			can_send_sig(LeftCurb_EndPointX, SLOTOFFSET); 
		}
	}
	else
	{
		can_send_sig(LeftCurb_EndPointX, SLOTOFFSET); 
		can_send_sig(LeftCurb_EndPointY, SLOTOFFSET);
	}	
	can_send_sig(LeftCurb_EndPointFlag, CurbstoneInfo_Left.CurbEndValid); 

	if(CurbstoneInfo_Left.CurbStartValid == TRUE)
	{
		if(CurbstoneInfo_Left.CurbStartP_st.X_si16 != 0)
		{
			can_send_sig(LeftCurb_StartPointX, CurbstoneInfo_Left.CurbStartP_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 	
		}
		else
		{
			can_send_sig(LeftCurb_StartPointX, SLOTOFFSET); 	
		}

		if(CurbstoneInfo_Left.CurbStartP_st.Y_si16 != 0)
		{
			can_send_sig(LeftCurb_StartPointY, CurbstoneInfo_Left.CurbStartP_st.Y_si16 + SLOTOFFSET); 
		}
		else
		{
			can_send_sig(LeftCurb_StartPointY, SLOTOFFSET); 
		}
	}
	else
	{
		can_send_sig(LeftCurb_StartPointX, SLOTOFFSET); 	
		can_send_sig(LeftCurb_StartPointY, SLOTOFFSET); 
	}	
	can_send_sig(LeftCurb_StartPointFlag, CurbstoneInfo_Left.CurbStartValid);


	/*********************Right Curb stone Info **********************/
	if(CurbstoneInfo_Right.CurbDegValid == TRUE)
	{
		can_send_sig(RightCurb_Angle, CurbstoneInfo_Right.CurbDeg_si16 + ANGELOFFSET); 
	}
	else
	{		
		can_send_sig(RightCurb_Angle, ANGELOFFSET); 
	}	
	can_send_sig(RightCurb_AngleFlag, CurbstoneInfo_Right.CurbDegValid);
 
//	can_send_sig(LeftCurb_Height, CurbstoneInfo_Left.CurbDeg_si16); 
//	can_send_sig(LeftCurb_Direction, CurbstoneInfo_Left.CurbDeg_si16); 
	
	if(CurbstoneInfo_Right.CurbEndValid == TRUE)
	{
		if(CurbstoneInfo_Right.CurbEndP_st.X_si16 != 0)
		{
			can_send_sig(RightCurb_EndPointX, CurbstoneInfo_Right.CurbEndP_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
		}
		else
		{
			can_send_sig(RightCurb_EndPointX, SLOTOFFSET); 
		}

		if(CurbstoneInfo_Right.CurbEndP_st.Y_si16 != 0)
		{
			can_send_sig(RightCurb_EndPointY, CurbstoneInfo_Right.CurbEndP_st.Y_si16 + SLOTOFFSET);
		}
		else
		{
			can_send_sig(RightCurb_EndPointY, SLOTOFFSET);
		}
	}
	else
	{
		can_send_sig(RightCurb_EndPointX, SLOTOFFSET); 
		can_send_sig(RightCurb_EndPointY, SLOTOFFSET);
	}	
	can_send_sig(RightCurb_EndPointFlag, CurbstoneInfo_Right.CurbEndValid); 

	if(CurbstoneInfo_Right.CurbStartValid == TRUE)
	{
		if(CurbstoneInfo_Right.CurbStartP_st.X_si16 != 0)
		{
			can_send_sig(RightCurb_StartPointX, CurbstoneInfo_Right.CurbStartP_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET);	
		}
		else
		{
			can_send_sig(RightCurb_StartPointX, SLOTOFFSET);	
		}

		if(CurbstoneInfo_Right.CurbStartP_st.Y_si16 != 0)
		{
			can_send_sig(RightCurb_StartPointY, CurbstoneInfo_Right.CurbStartP_st.Y_si16 + SLOTOFFSET); 
		}
		else
		{
			can_send_sig(RightCurb_StartPointY, SLOTOFFSET); 
		}
	}
	else
	{
		can_send_sig(RightCurb_StartPointX, SLOTOFFSET);	
		can_send_sig(RightCurb_StartPointY, SLOTOFFSET); 
	}	
	can_send_sig(RightCurb_StartPointFlag, CurbstoneInfo_Right.CurbStartValid);
}


/***********************************************************************
*  Name        : APA_ParkInSearch_CurbstoneInfo_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ExitParkInSearch_CurbstoneInfo_Clear(void)
{
	can_send_sig(LeftCurb_StartPointFlag,  0);	
	can_send_sig(LeftCurb_EndPointFlag,    0); 	
	can_send_sig(LeftCurb_AngleFlag, 	   0);
	can_send_sig(LeftCurb_Angle,           ANGELOFFSET); 	
	
	can_send_sig(LeftCurb_StartPointX,     SLOTOFFSET);	
	can_send_sig(LeftCurb_StartPointY,     SLOTOFFSET); 
	can_send_sig(LeftCurb_EndPointX,       SLOTOFFSET); 
	can_send_sig(LeftCurb_EndPointY,       SLOTOFFSET);

	can_send_sig(RightCurb_StartPointFlag, 0);	
	can_send_sig(RightCurb_EndPointFlag,   0); 	
	can_send_sig(RightCurb_AngleFlag, 	   0);
	can_send_sig(RightCurb_Angle,          ANGELOFFSET); 
	
	can_send_sig(RightCurb_StartPointX,    SLOTOFFSET);	
	can_send_sig(RightCurb_StartPointY,    SLOTOFFSET); 
	can_send_sig(RightCurb_EndPointX,      SLOTOFFSET); 
	can_send_sig(RightCurb_EndPointY,      SLOTOFFSET);

}

/***********************************************************************
*  Name        : APA_ParkingActiveIn_ReloadPlaceInfo_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_CloseReloadPlaceInfo_Sender(void)
{
	U8 CloseReplanModeFlag = 0;
	
	can_send_sig(APS_Replan_LeftLineFlag,	   0);
	can_send_sig(APS_Replan_LeftStatus, 	   0);	
	can_send_sig(APS_Replan_LeftLineDistance,  SLOTOFFSET); 
	can_send_sig(APS_Replan_LeftLineAngle,	   ANGELOFFSET); 

	can_send_sig(APS_Replan_RightLineFlag,	   0);
	can_send_sig(APS_Replan_RightStatus,	   0);	
	can_send_sig(APS_Replan_RightLineDistance, SLOTOFFSET);
	can_send_sig(APS_Replan_RightLineAngle,    ANGELOFFSET); 

	can_send_sig(APS_ReplanType,    0); 
	SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_SOC_APA_RELOCATION_REQ,1,&CloseReplanModeFlag);
}


/***********************************************************************
*  Name        : APA_ParkingActiveIn_ReloadPlaceInfo_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkingActiveIn_ReloadPlaceInfo_Sender(void)
{
	U8 ADV_ReplanMode_Current = 0;
	U8 CAN_TX_APS_ReplanType = 0;
	static U8 ADV_ReplanMode_Backup = 0;

	/***************************** send reloadplace status to soc by spi *****************************/
	ADV_ReplanMode_Current = can_receive_sig(ADV_ReplanMode);
	if(ADV_ReplanMode_Current != ADV_ReplanMode_Backup)
	{
		ADV_ReplanMode_Backup = ADV_ReplanMode_Current;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_SOC_APA_RELOCATION_REQ,1,&ADV_ReplanMode_Current);
	}

	/****************************** send replan infomation by can *******************************************/		
	if(can_ParkPlace_Type == 0x1 || can_ParkPlace_Type == 0x3)	// PERPENDICULAR || OBLIQUE
	{
		if(apa_reloat_place_info.L_Valid == 1 || apa_reloat_place_info.R_Valid == 1)
		{
			CAN_TX_APS_ReplanType = 0x1;
		}
		else if(apa_reloat_place_info.L_Valid == 2 || apa_reloat_place_info.R_Valid == 2)
		{
			CAN_TX_APS_ReplanType = 0x2;
		}
		else
		{
			CAN_TX_APS_ReplanType = 0x0;
		}
	}
	else if(can_ParkPlace_Type == 0x2)		//PARALLEL
	{
		if(apa_reloat_place_info.L_Valid == 1 || apa_reloat_place_info.R_Valid == 1)
		{
			CAN_TX_APS_ReplanType = 0x3;
		}
		else if(apa_reloat_place_info.L_Valid == 2 || apa_reloat_place_info.R_Valid == 2)
		{
			CAN_TX_APS_ReplanType = 0x4;
		}
		else
		{
			CAN_TX_APS_ReplanType = 0x0;
		}
	}


	if(0x1 == ADV_ReplanMode_Current && (apa_reloat_place_info.L_Valid != 0 || apa_reloat_place_info.R_Valid != 0))
	{
		if(apa_reloat_place_info.L_Valid != 0)
		{		
			can_send_sig(APS_Replan_LeftLineFlag,      1);			
			can_send_sig(APS_Replan_LeftStatus,	   	   apa_reloat_place_info.L_Valid);
			can_send_sig(APS_Replan_LeftLineDistance,  apa_reloat_place_info.DistL); 
			can_send_sig(APS_Replan_LeftLineAngle,     apa_reloat_place_info.ThetaL); 
		}
		else
		{
			can_send_sig(APS_Replan_LeftLineFlag,	   0);
			can_send_sig(APS_Replan_LeftStatus, 	   0);	
			can_send_sig(APS_Replan_LeftLineDistance,  SLOTOFFSET); 
			can_send_sig(APS_Replan_LeftLineAngle,	   ANGELOFFSET); 

		}

		if(apa_reloat_place_info.R_Valid != 0)
		{			
			can_send_sig(APS_Replan_RightLineFlag,     1);				
			can_send_sig(APS_Replan_RightStatus,	   apa_reloat_place_info.R_Valid);		
			can_send_sig(APS_Replan_RightLineDistance, apa_reloat_place_info.DistR);
			can_send_sig(APS_Replan_RightLineAngle,    apa_reloat_place_info.ThetaR); 
		}
		else
		{
			can_send_sig(APS_Replan_RightLineFlag,	   0);
			can_send_sig(APS_Replan_RightStatus,	   0);	
			can_send_sig(APS_Replan_RightLineDistance, SLOTOFFSET);
			can_send_sig(APS_Replan_RightLineAngle,    ANGELOFFSET); 
		}
		
		can_send_sig(APS_ReplanType,CAN_TX_APS_ReplanType); 
	}
	else 
	{		
		can_send_sig(APS_ReplanType,			   0); 
		
		can_send_sig(APS_Replan_LeftLineFlag,	   0);
		can_send_sig(APS_Replan_LeftStatus, 	   0);	
		can_send_sig(APS_Replan_LeftLineDistance,  SLOTOFFSET); 
		can_send_sig(APS_Replan_LeftLineAngle,	   ANGELOFFSET); 
		
		can_send_sig(APS_Replan_RightLineFlag,	   0);
		can_send_sig(APS_Replan_RightStatus,	   0);	
		can_send_sig(APS_Replan_RightLineDistance, SLOTOFFSET);
		can_send_sig(APS_Replan_RightLineAngle,    ANGELOFFSET); 		
	}
	
}


/***********************************************************************
*  Name        : APA_ParkingActiveIn_FreeSpace_Sender
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkingActiveIn_FreeSpace_Sender(void)
{
	U8 FreeSpaceInfo_Nums = 0;
	gTye_SideObjectMessage_st FreeSpaceInfo_Left[6]  = {0};
	gTye_SideObjectMessage_st FreeSpaceInfo_Right[6] = {0};

	
	/************************** get free space infomation from FV *****************************/
	for(FreeSpaceInfo_Nums;FreeSpaceInfo_Nums < 6 ; FreeSpaceInfo_Nums ++)
	{
		g_FV_adiGetPSLObjectDataInfo_bl(FreeSpaceInfo_Nums,FreeSpaceInfo_Left,g_SideLeft_enm);
		g_FV_adiGetPSLObjectDataInfo_bl(FreeSpaceInfo_Nums,FreeSpaceInfo_Right,g_SideRight_enm);
	}

	/*********************************** Freespace 0 ******************************************/
	can_send_sig(Freespace0_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace0_ObstacleProperty, 			FreeSpaceInfo_Left[0].StPointConner_bl);	
	can_send_sig(Freespace0_ObstacleHeight,             FreeSpaceInfo_Left[0].HeightStatus_en); 	
	can_send_sig(Freespace0_ObstacleStartPointFlag,     FreeSpaceInfo_Left[0].EdPointValid_bl); 	
	can_send_sig(Freespace0_ObstacleEndPointFlag,       FreeSpaceInfo_Left[0].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[0].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace0_ObstacleStartPointY,    FreeSpaceInfo_Left[0].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace0_ObstacleStartPointX,    FreeSpaceInfo_Left[0].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace0_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace0_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[0].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace0_ObstacleEndPointY,      FreeSpaceInfo_Left[0].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace0_ObstacleEndPointX,      FreeSpaceInfo_Left[0].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace0_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace0_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 1 ******************************************/
	can_send_sig(Freespace1_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace1_ObstacleProperty, 			FreeSpaceInfo_Left[1].StPointConner_bl);
	can_send_sig(Freespace1_ObstacleHeight,             FreeSpaceInfo_Left[1].HeightStatus_en); 	
	can_send_sig(Freespace1_ObstacleStartPointFlag,     FreeSpaceInfo_Left[1].EdPointValid_bl); 	
	can_send_sig(Freespace1_ObstacleEndPointFlag,       FreeSpaceInfo_Left[1].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[1].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace1_ObstacleStartPointY,    FreeSpaceInfo_Left[1].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace1_ObstacleStartPointX,    FreeSpaceInfo_Left[1].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace1_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace1_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[1].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace1_ObstacleEndPointY,      FreeSpaceInfo_Left[1].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace1_ObstacleEndPointX,      FreeSpaceInfo_Left[1].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace1_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace1_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 2 ******************************************/
	can_send_sig(Freespace2_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace2_ObstacleProperty, 			FreeSpaceInfo_Left[2].StPointConner_bl);
	can_send_sig(Freespace2_ObstacleHeight,             FreeSpaceInfo_Left[2].HeightStatus_en); 	
	can_send_sig(Freespace2_ObstacleStartPointFlag,     FreeSpaceInfo_Left[2].EdPointValid_bl); 	
	can_send_sig(Freespace2_ObstacleEndPointFlag,       FreeSpaceInfo_Left[2].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[2].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace2_ObstacleStartPointY,    FreeSpaceInfo_Left[2].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace2_ObstacleStartPointX,    FreeSpaceInfo_Left[2].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace2_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace2_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[2].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace2_ObstacleEndPointY,      FreeSpaceInfo_Left[2].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace2_ObstacleEndPointX,      FreeSpaceInfo_Left[2].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace2_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace2_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 3 ******************************************/
	can_send_sig(Freespace3_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace3_ObstacleProperty, 			FreeSpaceInfo_Left[3].StPointConner_bl);	
	can_send_sig(Freespace3_ObstacleHeight,             FreeSpaceInfo_Left[3].HeightStatus_en); 	
	can_send_sig(Freespace3_ObstacleStartPointFlag,     FreeSpaceInfo_Left[3].EdPointValid_bl); 	
	can_send_sig(Freespace3_ObstacleEndPointFlag,       FreeSpaceInfo_Left[3].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[3].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace3_ObstacleStartPointY,    FreeSpaceInfo_Left[3].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace3_ObstacleStartPointX,    FreeSpaceInfo_Left[3].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace3_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace3_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[3].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace3_ObstacleEndPointY,      FreeSpaceInfo_Left[3].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace3_ObstacleEndPointX,      FreeSpaceInfo_Left[3].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace3_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace3_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 4 ******************************************/
	can_send_sig(Freespace4_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace4_ObstacleProperty, 			FreeSpaceInfo_Left[4].StPointConner_bl);	
	can_send_sig(Freespace4_ObstacleHeight,             FreeSpaceInfo_Left[4].HeightStatus_en); 	
	can_send_sig(Freespace4_ObstacleStartPointFlag,     FreeSpaceInfo_Left[4].EdPointValid_bl); 	
	can_send_sig(Freespace4_ObstacleEndPointFlag,       FreeSpaceInfo_Left[4].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[4].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace4_ObstacleStartPointY,    FreeSpaceInfo_Left[4].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace4_ObstacleStartPointX,    FreeSpaceInfo_Left[4].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace4_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace4_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[4].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace4_ObstacleEndPointY,      FreeSpaceInfo_Left[4].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace4_ObstacleEndPointX,      FreeSpaceInfo_Left[4].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace4_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace4_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 5 ******************************************/
	can_send_sig(Freespace5_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace5_ObstacleProperty,			FreeSpaceInfo_Left[5].StPointConner_bl);	
	can_send_sig(Freespace5_ObstacleHeight,             FreeSpaceInfo_Left[5].HeightStatus_en); 	
	can_send_sig(Freespace5_ObstacleStartPointFlag,     FreeSpaceInfo_Left[5].EdPointValid_bl); 	
	can_send_sig(Freespace5_ObstacleEndPointFlag,       FreeSpaceInfo_Left[5].StPointValid_bl); 
	
	if(FreeSpaceInfo_Left[5].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace5_ObstacleStartPointY,    FreeSpaceInfo_Left[5].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace5_ObstacleStartPointX,    FreeSpaceInfo_Left[5].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace5_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace5_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Left[5].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace5_ObstacleEndPointY,      FreeSpaceInfo_Left[5].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace5_ObstacleEndPointX,      FreeSpaceInfo_Left[5].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace5_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace5_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 6 ******************************************/
	can_send_sig(Freespace6_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace6_ObstacleProperty, 			FreeSpaceInfo_Right[0].StPointConner_bl);
	can_send_sig(Freespace6_ObstacleHeight,             FreeSpaceInfo_Right[0].HeightStatus_en); 	
	can_send_sig(Freespace6_ObstacleStartPointFlag,     FreeSpaceInfo_Right[0].EdPointValid_bl); 	
	can_send_sig(Freespace6_ObstacleEndPointFlag,       FreeSpaceInfo_Right[0].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[0].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace6_ObstacleStartPointY,    FreeSpaceInfo_Right[0].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace6_ObstacleStartPointX,    FreeSpaceInfo_Right[0].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace6_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace6_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[0].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace6_ObstacleEndPointY,      FreeSpaceInfo_Right[0].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace6_ObstacleEndPointX,      FreeSpaceInfo_Right[0].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace6_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace6_ObstacleEndPointX,	SLOTOFFSET); 
	}


	/*********************************** Freespace 7 ******************************************/
	can_send_sig(Freespace7_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace7_ObstacleProperty, 			FreeSpaceInfo_Right[1].StPointConner_bl);
	can_send_sig(Freespace7_ObstacleHeight,             FreeSpaceInfo_Right[1].HeightStatus_en); 	
	can_send_sig(Freespace7_ObstacleStartPointFlag,     FreeSpaceInfo_Right[1].EdPointValid_bl); 	
	can_send_sig(Freespace7_ObstacleEndPointFlag,       FreeSpaceInfo_Right[1].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[1].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace7_ObstacleStartPointY,    FreeSpaceInfo_Right[1].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace7_ObstacleStartPointX,    FreeSpaceInfo_Right[1].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace7_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace7_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[1].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace7_ObstacleEndPointY,      FreeSpaceInfo_Right[1].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace7_ObstacleEndPointX,      FreeSpaceInfo_Right[1].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace7_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace7_ObstacleEndPointX,	SLOTOFFSET); 
	}


	/*********************************** Freespace 8 ******************************************/
	can_send_sig(Freespace8_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace8_ObstacleProperty, 			FreeSpaceInfo_Right[2].StPointConner_bl);	
	can_send_sig(Freespace8_ObstacleHeight,             FreeSpaceInfo_Right[2].HeightStatus_en); 	
	can_send_sig(Freespace8_ObstacleStartPointFlag,     FreeSpaceInfo_Right[2].EdPointValid_bl); 	
	can_send_sig(Freespace8_ObstacleEndPointFlag,       FreeSpaceInfo_Right[2].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[2].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace8_ObstacleStartPointY,    FreeSpaceInfo_Right[2].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace8_ObstacleStartPointX,    FreeSpaceInfo_Right[2].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace8_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace8_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[2].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace8_ObstacleEndPointY,      FreeSpaceInfo_Right[2].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace8_ObstacleEndPointX,      FreeSpaceInfo_Right[2].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace8_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace8_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 9 ******************************************/
	can_send_sig(Freespace9_ObstacleStatus, 			0x3); 
	can_send_sig(Freespace9_ObstacleProperty, 			FreeSpaceInfo_Right[3].StPointConner_bl);	
	can_send_sig(Freespace9_ObstacleHeight,             FreeSpaceInfo_Right[3].HeightStatus_en); 	
	can_send_sig(Freespace9_ObstacleStartPointFlag,     FreeSpaceInfo_Right[3].EdPointValid_bl); 	
	can_send_sig(Freespace9_ObstacleEndPointFlag,       FreeSpaceInfo_Right[3].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[3].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace9_ObstacleStartPointY,    FreeSpaceInfo_Right[3].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace9_ObstacleStartPointX,    FreeSpaceInfo_Right[3].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace9_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace9_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[3].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace9_ObstacleEndPointY,      FreeSpaceInfo_Right[3].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace9_ObstacleEndPointX,      FreeSpaceInfo_Right[3].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace9_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace9_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 10 ******************************************/
	can_send_sig(Freespace10_ObstacleStatus, 			 0x3); 
	can_send_sig(Freespace10_ObstacleProperty, 			 FreeSpaceInfo_Right[4].StPointConner_bl);	
	can_send_sig(Freespace10_ObstacleHeight,             FreeSpaceInfo_Right[4].HeightStatus_en); 	
	can_send_sig(Freespace10_ObstacleStartPointFlag,     FreeSpaceInfo_Right[4].EdPointValid_bl); 	
	can_send_sig(Freespace10_ObstacleEndPointFlag,       FreeSpaceInfo_Right[4].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[4].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace10_ObstacleStartPointY,    FreeSpaceInfo_Right[4].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace10_ObstacleStartPointX,    FreeSpaceInfo_Right[4].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace10_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace10_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[4].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace10_ObstacleEndPointY,      FreeSpaceInfo_Right[4].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace10_ObstacleEndPointX,      FreeSpaceInfo_Right[4].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace10_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace10_ObstacleEndPointX,	SLOTOFFSET); 
	}

	/*********************************** Freespace 11 ******************************************/
	can_send_sig(Freespace11_ObstacleStatus, 			 0x3); 
	can_send_sig(Freespace11_ObstacleProperty, 			 FreeSpaceInfo_Right[5].StPointConner_bl);
	can_send_sig(Freespace11_ObstacleHeight,             FreeSpaceInfo_Right[5].HeightStatus_en); 	
	can_send_sig(Freespace11_ObstacleStartPointFlag,     FreeSpaceInfo_Right[5].EdPointValid_bl); 	
	can_send_sig(Freespace11_ObstacleEndPointFlag,       FreeSpaceInfo_Right[5].StPointValid_bl); 
	
	if(FreeSpaceInfo_Right[5].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace11_ObstacleStartPointY,    FreeSpaceInfo_Right[5].Obj1stCorner_st.Y_si16  + SLOTOFFSET); 
		can_send_sig(Freespace11_ObstacleStartPointX,    FreeSpaceInfo_Right[5].Obj1stCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace11_ObstacleStartPointY,	SLOTOFFSET); 
		can_send_sig(Freespace11_ObstacleStartPointX,	SLOTOFFSET); 
	}
																			
	if(FreeSpaceInfo_Right[5].EdPointValid_bl == TRUE)
	{
		can_send_sig(Freespace11_ObstacleEndPointY,      FreeSpaceInfo_Right[5].Obj2ndCorner_st.Y_si16 + SLOTOFFSET); 
		can_send_sig(Freespace11_ObstacleEndPointX,      FreeSpaceInfo_Right[5].Obj2ndCorner_st.X_si16 - CAR_REAR_AXLE_TO_CENTER_UNIT_CM + SLOTOFFSET); 
	}
	else
	{
		can_send_sig(Freespace11_ObstacleEndPointY,	SLOTOFFSET); 
		can_send_sig(Freespace11_ObstacleEndPointX,	SLOTOFFSET); 
	}

}

/***********************************************************************
*  Name        : APA_ParkingActiveIn_ShadowOfTheVehicle_Receiver
*  Description : tenth:1/10
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkingActiveIn_TargetTracing_Receiver(void)
{
	U8 PathTracingInfo[11] = {0};
	U8 PathTracingInfo_bak[11] = {0};	
	U8 CAN_RX_ADV_TotalPathNumber = can_receive_sig(ADV_TotalPathNumber);
	U8 CAN_RX_ADV_CurrentPathNumber = can_receive_sig(ADV_CurrentPathNumber);

	static U8 Delay_SendSPI_45C2_Counter = 0x0;

	S16 CAN_RX_ADV_TracingAngle_degree          = 0;
	S16 CAN_RX_ADV_TracingCenter_X_cm           = 0;
	S16 CAN_RX_ADV_TracingCenter_Y_cm           = 0;
	S16 CAN_RX_ADV_TargetTracingLength_cm       = 0;
	S16 CAN_RX_ADV_TargetTracingWidth_cm		= 0;

	U16 CAN_RX_ADV_TracingAngle_degree_U16      = 0;
	U16 CAN_RX_ADV_TracingCenter_X_cm_U16       = 0;
	U16 CAN_RX_ADV_TracingCenter_Y_cm_U16       = 0;
	U16 CAN_RX_ADV_TargetTracingLength_cm_U16   = 0;
	U16 CAN_RX_ADV_TargetTracingWidth_cm_U16	= 0;

	static S16 CAN_RX_ADV_TracingAngle_degree_bak       = 0;
	static S16 CAN_RX_ADV_TracingCenter_X_cm_bak        = 0;
	static S16 CAN_RX_ADV_TracingCenter_Y_cm_bak        = 0;
	static S16 CAN_RX_ADV_TargetTracingLength_cm_bak    = 0;
	static S16 CAN_RX_ADV_TargetTracingWidth_cm_bak		= 0;
	
	if(CAN_RX_ADV_TotalPathNumber != 0 && CAN_RX_ADV_TotalPathNumber != 0)
	{			
		if(0x1 == can_receive_sig(ADV_TargetTracingAvaialble))	//Avaialble
		{
			if(can_ParkPlace_Type == 0x1 || can_ParkPlace_Type == 0x3)	// PERPENDICULAR || OBLIQUE
			{
				CAN_RX_ADV_TargetTracingLength_cm = can_receive_sig(ADV_TargetTracingLength); 
				CAN_RX_ADV_TargetTracingWidth_cm  = can_receive_sig(ADV_TargetTracingWidth);
			}
			
			else if(can_ParkPlace_Type == 0x2)		//PARALLEL
			{
				CAN_RX_ADV_TargetTracingLength_cm = can_receive_sig(ADV_TargetTracingWidth);
				CAN_RX_ADV_TargetTracingWidth_cm =  can_receive_sig(ADV_TargetTracingLength);
			}
			
			CAN_RX_ADV_TracingAngle_degree          = can_receive_sig(ADV_TargetTracingAngle);
			CAN_RX_ADV_TracingCenter_X_cm           = can_receive_sig(ADV_TargetTracingCenter_X) - SLOTOFFSET;  
			CAN_RX_ADV_TracingCenter_Y_cm           = can_receive_sig(ADV_TargetTracingCenter_Y) - SLOTOFFSET;  

			if(CAN_RX_ADV_TracingCenter_X_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm);
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm * (-1));
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 | 0x8000);
			}

			if(CAN_RX_ADV_TracingCenter_Y_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm);
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm * (-1));
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 | 0x8000);
			}
			
			if(CAN_RX_ADV_TracingAngle_degree >= 0)
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree);
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree * (-1));
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 | 0x8000);
			}

			if(CAN_RX_ADV_TargetTracingLength_cm >= 0)
			{
				CAN_RX_ADV_TargetTracingLength_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingLength_cm);
				CAN_RX_ADV_TargetTracingLength_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingLength_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TargetTracingLength_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm * (-1));
				CAN_RX_ADV_TargetTracingLength_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingLength_cm_U16 | 0x8000);
			} 

			if(CAN_RX_ADV_TargetTracingWidth_cm >= 0)
			{
				CAN_RX_ADV_TargetTracingWidth_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingWidth_cm);
				CAN_RX_ADV_TargetTracingWidth_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingWidth_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TargetTracingWidth_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingWidth_cm * (-1));
				CAN_RX_ADV_TargetTracingWidth_cm_U16 = (U16)(CAN_RX_ADV_TargetTracingWidth_cm_U16 | 0x8000);
			}

			PathTracingInfo[0]  = (U8)(CAN_RX_ADV_TracingCenter_X_cm & 0xFF);
			PathTracingInfo[1]  = (U8)(CAN_RX_ADV_TracingCenter_X_cm>>8)&0xFF;
			PathTracingInfo[2]  = (U8)(CAN_RX_ADV_TracingCenter_Y_cm & 0xFF);
			PathTracingInfo[3]  = (U8)(CAN_RX_ADV_TracingCenter_Y_cm>>8)&0xFF;

			PathTracingInfo[4]  = (U8)(CAN_RX_ADV_TracingAngle_degree & 0xFF);		
			PathTracingInfo[5]  = (U8)(CAN_RX_ADV_TracingAngle_degree>>8)&0xFF;
			PathTracingInfo[6]  = (U8)(CAN_RX_ADV_TargetTracingLength_cm & 0xFF);
			PathTracingInfo[7]  = (U8)(CAN_RX_ADV_TargetTracingLength_cm>>8)&0xFF;
			
			PathTracingInfo[8]  = (U8)(CAN_RX_ADV_TargetTracingWidth_cm & 0xFF);
			PathTracingInfo[9]  = (U8)(CAN_RX_ADV_TargetTracingWidth_cm>>8)&0xFF;	
			PathTracingInfo[10] = Slot_Target; 
			
			Delay_SendSPI_45C2_Counter ++;
			if(Delay_SendSPI_45C2_Counter >= 8)		//8 * 5ms = 40ms
			{
				Delay_SendSPI_45C2_Counter = 0;
				if(PathTracingInfo_bak[0] != PathTracingInfo[0] || PathTracingInfo_bak[1] != PathTracingInfo[1]
				|| PathTracingInfo_bak[2] != PathTracingInfo[2] || PathTracingInfo_bak[3] != PathTracingInfo[3]
				|| PathTracingInfo_bak[4] != PathTracingInfo[4] || PathTracingInfo_bak[5] != PathTracingInfo[5]
				|| PathTracingInfo_bak[6] != PathTracingInfo[6] || PathTracingInfo_bak[7] != PathTracingInfo[7]
				|| PathTracingInfo_bak[8] != PathTracingInfo[8] || PathTracingInfo_bak[9] != PathTracingInfo[9])
				{
					PathTracingInfo_bak[0] = PathTracingInfo[0];
					PathTracingInfo_bak[1] = PathTracingInfo[1];
					PathTracingInfo_bak[2] = PathTracingInfo[2];
					PathTracingInfo_bak[3] = PathTracingInfo[3];

					PathTracingInfo_bak[4] = PathTracingInfo[4];
					PathTracingInfo_bak[5] = PathTracingInfo[5];
					PathTracingInfo_bak[6] = PathTracingInfo[6];
					PathTracingInfo_bak[7] = PathTracingInfo[7];
					PathTracingInfo_bak[8] = PathTracingInfo[8];

					PathTracingInfo_bak[9] = PathTracingInfo[9];
					SocManager_SendMsg(HQ_CMD,TYPE_EVENT,CPU_NOTIFY_M3_APA_PREDICTED_PARK_PLACE,11,PathTracingInfo);
				}
			}
			else
			{
				//do nothing
			}
		}
	}	
}

/***********************************************************************
*  Name        : APA_ParkingActiveIn_ShadowOfTheVehicle_Receiver
*  Description : tenth:1/10
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkingActiveIn_PathTracing_Receiver(void)
{
	U8 PathTracingInfo[11] = {0};
	U8 PathTracingInfo_bak[6] = {0};	
	U8 CAN_RX_ADV_TotalPathNumber = can_receive_sig(ADV_TotalPathNumber);
	U8 CAN_RX_ADV_CurrentPathNumber = can_receive_sig(ADV_CurrentPathNumber);

	static U8 Delay_SendSPI_45C2_Counter = 0x0;

	S16 CAN_RX_ADV_TracingAngle_degree          = 0;
	S16 CAN_RX_ADV_TracingCenter_X_cm           = 0;
	S16 CAN_RX_ADV_TracingCenter_Y_cm           = 0;

	U16 CAN_RX_ADV_TracingAngle_degree_U16      = 0;
	U16 CAN_RX_ADV_TracingCenter_X_cm_U16       = 0;
	U16 CAN_RX_ADV_TracingCenter_Y_cm_U16       = 0;

	static S16 CAN_RX_ADV_TracingAngle_degree_bak       = 0;
	static S16 CAN_RX_ADV_TracingCenter_X_cm_bak        = 0;
	static S16 CAN_RX_ADV_TracingCenter_Y_cm_bak        = 0;

	if(CAN_RX_ADV_TotalPathNumber != 0 && CAN_RX_ADV_TotalPathNumber != 0)
	{
		PathTracingInfo[10] = Slot_Predicted; 
		
		if(0x1 == can_receive_sig(ADV_PathTracingAvaialble)) //Avaialble
		{
			CAN_RX_ADV_TracingAngle_degree	        = (can_receive_sig(ADV_PathTracingAngle));
			CAN_RX_ADV_TracingCenter_X_cm			= can_receive_sig(ADV_PathTracingCenter_X) - SLOTOFFSET;   
			CAN_RX_ADV_TracingCenter_Y_cm			= can_receive_sig(ADV_PathTracingCenter_Y) - SLOTOFFSET;   

			if(CAN_RX_ADV_TracingCenter_X_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm);
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm * (-1));
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 | 0x8000);
			}

			if(CAN_RX_ADV_TracingCenter_Y_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm);
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm * (-1));
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 | 0x8000);
			}
			
			if(CAN_RX_ADV_TracingAngle_degree >= 0)
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree);
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree * (-1));
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 | 0x8000);
			}


			if(CAN_RX_ADV_TracingCenter_X_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm);
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm * (-1));
				CAN_RX_ADV_TracingCenter_X_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_X_cm_U16 | 0x8000);
			}

			if(CAN_RX_ADV_TracingCenter_Y_cm >= 0)
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm);
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm * (-1));
				CAN_RX_ADV_TracingCenter_Y_cm_U16 = (U16)(CAN_RX_ADV_TracingCenter_Y_cm_U16 | 0x8000);
			}
			
			if(CAN_RX_ADV_TracingAngle_degree >= 0)
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree);
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 & 0x7FFF);
			}
			else
			{
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree * (-1));
				CAN_RX_ADV_TracingAngle_degree_U16 = (U16)(CAN_RX_ADV_TracingAngle_degree_U16 | 0x8000);
			}


			PathTracingInfo[0]  = (U8)(CAN_RX_ADV_TracingCenter_X_cm & 0xFF);
			PathTracingInfo[1]  = (U8)(CAN_RX_ADV_TracingCenter_X_cm>>8)&0xFF;
			PathTracingInfo[2]  = (U8)(CAN_RX_ADV_TracingCenter_Y_cm & 0xFF);
			PathTracingInfo[3]  = (U8)(CAN_RX_ADV_TracingCenter_Y_cm>>8)&0xFF;

			PathTracingInfo[4]  = (U8)(CAN_RX_ADV_TracingAngle_degree & 0xFF);		
			PathTracingInfo[5]  = (U8)(CAN_RX_ADV_TracingAngle_degree>>8)&0xFF;
			PathTracingInfo[6]  = 0;
			PathTracingInfo[7]  = 0;
			
			PathTracingInfo[8]  = 0;
			PathTracingInfo[9]  = 0;	
			PathTracingInfo[10] = Slot_Predicted; 
			
			Delay_SendSPI_45C2_Counter ++;
			if(Delay_SendSPI_45C2_Counter >= 8)		//8 * 5ms = 40ms
			{
				Delay_SendSPI_45C2_Counter = 0;
				if(PathTracingInfo_bak[0] != PathTracingInfo[0] || PathTracingInfo_bak[1] != PathTracingInfo[1]
				|| PathTracingInfo_bak[2] != PathTracingInfo[2] || PathTracingInfo_bak[3] != PathTracingInfo[3]
				|| PathTracingInfo_bak[4] != PathTracingInfo[4] || PathTracingInfo_bak[5] != PathTracingInfo[5])
				{
					PathTracingInfo_bak[0] = PathTracingInfo[0];
					PathTracingInfo_bak[1] = PathTracingInfo[1];
					PathTracingInfo_bak[2] = PathTracingInfo[2];
					PathTracingInfo_bak[3] = PathTracingInfo[3];

					PathTracingInfo_bak[4] = PathTracingInfo[4];
					PathTracingInfo_bak[5] = PathTracingInfo[5];
					SocManager_SendMsg(HQ_CMD,TYPE_EVENT,CPU_NOTIFY_M3_APA_PREDICTED_PARK_PLACE,11,PathTracingInfo);
				}
			}
			else
			{
				//do nothing
			}
		}
	}	
}


/***********************************************************************
*  Name        : APA_ParkingActiveIn_ShadowOfTheVehicle_Receiver
*  Description : tenth:1/10
*  Parameter   :
*  Returns     : 
***********************************************************************/
void APA_ParkingActiveIn_BothSidesInfo_Receiver(void)
{
	U8 APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_EMPTY;
	if(APA_SlotInfo[0].APS_Slot1_ParkDirection == 0x0)	//right
	{
		switch(GetDownSlotSODStatus())
		{
			case 0x0:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x1:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_SOD_OR_UNKOWN;
				break;
			case 0x2:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x3:
				APS_Slot_BothSidesInfo = LEFT_SOD_OR_UNKOWN_RIGHT_EMPTY;
				break;
			case 0x4:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_EMPTY;
				break;
			case 0x5:
				APS_Slot_BothSidesInfo = LEFT_SOD_OR_UNKOWN_RIGHT_EMPTY;
				break;
			case 0x6:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x7:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_SOD_OR_UNKOWN;
				break;
			case 0x8:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			default:
				break;
		}
	}
	else if(APA_SlotInfo[0].APS_Slot1_ParkDirection == 0x1)	//left
	{
		switch(GetDownSlotSODStatus())
		{
			case 0x0:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x1:
				APS_Slot_BothSidesInfo = LEFT_SOD_OR_UNKOWN_RIGHT_EMPTY;
				break;
			case 0x2:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x3:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_SOD_OR_UNKOWN;
				break;
			case 0x4:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_EMPTY;
				break;
			case 0x5:
				APS_Slot_BothSidesInfo = LEFT_EMPTY_RIGHT_SOD_OR_UNKOWN;
				break;
			case 0x6:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			case 0x7:
				APS_Slot_BothSidesInfo = LEFT_SOD_OR_UNKOWN_RIGHT_EMPTY;
				break;
			case 0x8:
				APS_Slot_BothSidesInfo = LEFT_SOD_RIGHT_SOD;
				break;
			default:
				break;
		}

	}
	can_send_sig(APS_Slot1_BothSidesInfo, APS_Slot_BothSidesInfo);
}


