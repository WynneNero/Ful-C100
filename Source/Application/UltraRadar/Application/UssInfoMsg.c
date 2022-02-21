/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : IDA SW1    									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :  
* Module        :
* Instance      :
* Description   : This file use to communicate with USS ALG
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Ver  Date         Name       Changes and comments
*----------------------------------------------------------------------
* 0.1  Nov.6th		Lin			FirstVersion
*=====================================================================*/

#include "UssInfoMsg.h"
#include "ObjDetect_Pub.h"
#include "UssInfo_Msg_IF.h"
#include "CanApp.h"
#include "SlotParaCfg.h"
#include "SlotSearching_Pub.h"
#include "il_inc.h"
#include "InputSignalProc.h"
#include "ApsCanAPP.h"
#include "InteractiveInterfaceDefine.h"
#include "APSAPP.h"
#include "ComplexDrvier_Globaldef_IF.H"
#include "UltraRadarDriver.h"
#include "UssObjDetInterface.h"
#include "UltraSensorObjDetect_DataFilter.h"
#include "ussLibAdapt.h"
#include "xprintf.h"
#include "eol_APP_IF.H"
#include "socManager.h"

#define MAX_USS_DISTANCE 5000
#define HALF_USS_DISTANCE 2500

STK_USS_Slot_Search stk_uss_slot_search;
P_STK_USS_Slot_Search p_stk_uss_slot_search = 0;
USSDistanceResultStruct USS_Distance_Info;
USS_PDC_Struct USS_PDC_raw_distance_Unit_mm;
USS_PDC_Struct_Unit_cm USS_PDC_distance_Unit_cm;

S16 USS_Slot_OutLine_X_Value = 0;
S16 USS_Slot_OutLine_Y_Value = 0;
USS_SlotType UssSlotType;
char UssSlotSearchingAlgSoftVersion[19];
char UssObjectDetectAlgSoftVersion[19];

SlotSearchingResultDataType ParkingSlotInfo_End;

extern SlotSearchingResultDataType SlotLeftNearestInformation;
extern SlotSearchingResultDataType SlotRightNearestInformation;
extern APS_MODULE_STATUS SocCurrentParkingStatus;

U8 USSFailureStatus_Info[12] = {0};
USSDistanceResultStruct USS_Distance_Information_USSInfoMsg;

U8 EOL_Switch_Status;
U8 bSatisfiedUssSearch;
extern unsigned char SlotSearchingFuctionSwitch;
extern SlotSearchingResultDataType SlotLeftInformation[1];
extern SlotSearchingResultDataType SlotRightInformation[1];
extern U16 FLS_point_DistanceMin ,FRS_point_DistanceMin;

extern void UltraRadarSlotSearchingSlotOutLineMsg(void);
/*************************************************************
    * Function Name: StkUssInfoInit
    * Description  : init the data of USS
    * Parameters   : None
    * Return Value : None
*****************************************************************/
extern void UltraRadarCyclicTaskInit(void);

void StkUssInfoInit(void)			
{
	p_stk_uss_slot_search = &stk_uss_slot_search;
	stk_uss_slot_search.USS_Searching_Side = Searching_Both_Side;
	stk_uss_slot_search.CurrentGear = 0;
	stk_uss_slot_search.APS_Searching_Type = 0;
	stk_uss_slot_search.USS_AX_L = 0;
	stk_uss_slot_search.USS_AY_L = 0;
	stk_uss_slot_search.USS_BX_L = 0;
	stk_uss_slot_search.USS_BY_L = 0;
    
	stk_uss_slot_search.USS_CX_L = 0;
	stk_uss_slot_search.USS_CY_L = 0;    
	stk_uss_slot_search.USS_DX_L = 0;
	stk_uss_slot_search.USS_DY_L = 0;
    
	stk_uss_slot_search.USS_AX_R = 0;
	stk_uss_slot_search.USS_AY_R = 0;
	stk_uss_slot_search.USS_BX_R = 0;
	stk_uss_slot_search.USS_BY_R = 0;
    
	stk_uss_slot_search.USS_CX_R = 0;
	stk_uss_slot_search.USS_CY_R = 0;
	stk_uss_slot_search.USS_DX_R = 0;
	stk_uss_slot_search.USS_DY_R = 0;
       
	stk_uss_slot_search.USS_SLOT_DEPTH_L = 0;
    stk_uss_slot_search.USS_SLOT_DEPTH_R = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.SlotType = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.SlotDepth = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.SlotLength = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.bSlotCalConfirmed = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.bSlotisWithCurb = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.bIsPointBObjectExist = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.bIsPointCObjectExist = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.fSlotAngle = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y = 0;
   
	stk_uss_slot_search.ParkingSlotInfo_R.SlotType = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.SlotDepth = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.SlotLength = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.bSlotCalConfirmed = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.bSlotisWithCurb = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.bIsPointBObjectExist = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.bIsPointCObjectExist = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.fSlotAngle = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x = 0;
	stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y = 0;

    ParkingSlotInfo_End.SlotType = 0;
	ParkingSlotInfo_End.SlotDepth = 0;
	ParkingSlotInfo_End.SlotLength = 0;
	ParkingSlotInfo_End.bSlotCalConfirmed = 0;
	ParkingSlotInfo_End.bSlotisWithCurb = 0;
	ParkingSlotInfo_End.bIsPointBObjectExist = 0;
	ParkingSlotInfo_End.bIsPointCObjectExist = 0;
	ParkingSlotInfo_End.fSlotAngle = 0;
	ParkingSlotInfo_End.Point_A_Coordinate.x = 0;
	ParkingSlotInfo_End.Point_A_Coordinate.y = 0;
	ParkingSlotInfo_End.Point_B_Coordinate.x = 0;
	ParkingSlotInfo_End.Point_B_Coordinate.y = 0;
	ParkingSlotInfo_End.Point_C_Coordinate.x = 0;
	ParkingSlotInfo_End.Point_C_Coordinate.y = 0;
	ParkingSlotInfo_End.Point_D_Coordinate.x = 0;
	ParkingSlotInfo_End.Point_D_Coordinate.y = 0;	

	USS_ALG_version_number_SS();
	USS_ALG_version_number_OD();
	UltraRadarCyclicTaskInit();
}

/***********************************************************************************************************************
    * Function Name: USS_FailureStatus_handler
    * Description  : get ultra sonic sensors' failure status
    * Parameters   : None
    * Return Value : None
    * the corresponded sensor :
    	USSFailureStatus_Info_called[0] = RRS;
    	USSFailureStatus_Info_called[1] = RR;
    	USSFailureStatus_Info_called[2] = RRM;
    	USSFailureStatus_Info_called[3] = RLM;
    	USSFailureStatus_Info_called[4] = RL;
    	USSFailureStatus_Info_called[5] = RLS;
    	USSFailureStatus_Info_called[6] = FRS;
    	USSFailureStatus_Info_called[7] = FR;
    	USSFailureStatus_Info_called[8] = FRM;
    	USSFailureStatus_Info_called[9] = FLM;
    	USSFailureStatus_Info_called[10] = FL;
    	USSFailureStatus_Info_called[11] = FLS;

***********************************************************************************************************************/
diagnosticTypedef USSFailureStatus_Info_called[SENSOR_TOTAL_INDEX] = {0};
diagnosticTypedef USSFailureStatus_Info_called_CAN[SENSOR_TOTAL_INDEX] = {0};

void USS_FailureStatus_Handler_CANBK(void)
{
	U8 VehicleKeyStatus = 0;
	FV_diagnosticTypedef FV_diagnostic[12];
	_memset(FV_diagnostic,0,12*sizeof(FV_diagnosticTypedef));
	
	VehicleKeyStatus = can_receive_sig(PowerMode);
	g_FV_getSnsDiagnosticResult(FV_diagnostic);

	if(VehicleKeyStatus == KEY_ACC_ON)
	{
		if(GetMmiTouchDebugFlag()!=0)
		{
			USSFailureStatus_Info_called_CAN[SENSOR_RRS].allStatus = FV_diagnostic[6].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_RR].allStatus = FV_diagnostic[7].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_RRM].allStatus = FV_diagnostic[8].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_RLM].allStatus = FV_diagnostic[9].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_RL].allStatus = FV_diagnostic[10].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_RLS].allStatus = FV_diagnostic[11].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FRS].allStatus = FV_diagnostic[5].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FR].allStatus = FV_diagnostic[4].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FRM].allStatus = FV_diagnostic[3].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FLM].allStatus = FV_diagnostic[2].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FL].allStatus = FV_diagnostic[1].allStatus;
			USSFailureStatus_Info_called_CAN[SENSOR_FLS].allStatus = FV_diagnostic[0].allStatus;
		}
	}
	else
	{
		USSFailureStatus_Info_called_CAN[SENSOR_RRS].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_RR].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_RRM].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_RLM].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_RL].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_RLS].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FRS].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FR].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FRM].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FLM].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FL].allStatus = 0;
		USSFailureStatus_Info_called_CAN[SENSOR_FLS].allStatus = 0;
	}

	if(GetMmiTouchDebugFlag()!=0)
	{
		can_send_sig(USS_DIAG_RRS ,USSFailureStatus_Info_called_CAN[SENSOR_RRS].allStatus);
		can_send_sig(USS_DIAG_RR ,USSFailureStatus_Info_called_CAN[SENSOR_RR].allStatus);
		can_send_sig(USS_DIAG_RMR ,USSFailureStatus_Info_called_CAN[SENSOR_RRM].allStatus);
		can_send_sig(USS_DIAG_RML ,USSFailureStatus_Info_called_CAN[SENSOR_RLM].allStatus);
		
		can_send_sig(USS_DIAG_RL ,USSFailureStatus_Info_called_CAN[SENSOR_RL].allStatus);
		can_send_sig(USS_DIAG_RLS ,USSFailureStatus_Info_called_CAN[SENSOR_RLS].allStatus);
		can_send_sig(USS_DIAG_FRS ,USSFailureStatus_Info_called_CAN[SENSOR_FRS].allStatus);
		can_send_sig(USS_DIAG_FR ,USSFailureStatus_Info_called_CAN[SENSOR_FR].allStatus);
		
		can_send_sig(USS_DIAG_FMR ,USSFailureStatus_Info_called_CAN[SENSOR_FRM].allStatus);
		can_send_sig(USS_DIAG_FML ,USSFailureStatus_Info_called_CAN[SENSOR_FLM].allStatus);
		can_send_sig(USS_DIAG_FL ,USSFailureStatus_Info_called_CAN[SENSOR_FL].allStatus);
		can_send_sig(USS_DIAG_FLS  ,USSFailureStatus_Info_called_CAN[SENSOR_FLS].allStatus);
	}
}

DtcTypedef USSFailureDtcInfo[SENSOR_TOTAL_INDEX];
typedef union
{
	U16 allStatus;
	struct
	{
		unsigned char mainTaskBgFlg			    :1;
		unsigned char seqEmitWaveReq			:1;
		unsigned char seqWaitForNextEmit		:1;
		unsigned char seqProcess2				:1;
		
		unsigned char recTimeOut				:1;
		unsigned char seqRxDat					:1;
		unsigned char seqEmitReqWait			:1;
		unsigned char seqIdle					:1;
		
		unsigned char seqDelayToInit			:1;
		unsigned char seqParaInit				:1;
		unsigned char sendSeqTXcmd		    	:1;
		unsigned char resetFlg					:1;
		
		unsigned char frontSnsPower				:1;
		unsigned char rearSnsPower				:1;
		unsigned char reverse					:2;
	}status;
}UssSystemStatusTypedef;
static UssSystemStatusTypedef ussSystemStatus; 
static U8 rader_fault_backup[12];
static U8 rader_isBlocked_backup[12];
extern BOOL EolApp_GetEolStatus(void);

void USS_FailureStatus_CanSender(void)
{
	static BOOL USSFailureStatus_ToAPP[SENSOR_TOTAL_INDEX] = {0};
    if(USSFailureStatus_Info_called[SENSOR_RR].allStatus)
    {
        can_send_sig(SensorErrorSt_RR, SENSOR_ERROR);
		USSFailureStatus_ToAPP[SENSOR_RR] = TRUE;
    }
    else
    {
        can_send_sig(SensorErrorSt_RR, SENSOR_NOERROR);		
		USSFailureStatus_ToAPP[SENSOR_RR] = FALSE;
    }

    if(USSFailureStatus_Info_called[SENSOR_RRM].allStatus)
    {

        can_send_sig(SensorErrorSt_RMR, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_RMR, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_RLM].allStatus)
    {
        can_send_sig(SensorErrorSt_RML, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_RML, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_RL].allStatus)
    {
        can_send_sig(SensorErrorSt_RL, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_RL, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FR].allStatus)
    {
        can_send_sig(SensorErrorSt_FR, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FR, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FRM].allStatus)
    {
        can_send_sig(SensorErrorSt_FMR, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FMR, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FLM].allStatus)
    {
        can_send_sig(SensorErrorSt_FML, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FML, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FL].allStatus)
    {
        can_send_sig(SensorErrorSt_FL, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FL, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FRS].allStatus)
    {
        can_send_sig(SensorErrorSt_FRS, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FRS, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_FLS].allStatus)
    {
        can_send_sig(SensorErrorSt_FLS, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_FLS, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_RRS].allStatus)
    {
        can_send_sig(SensorErrorSt_RRS, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_RRS, SENSOR_NOERROR);
    }

    if(USSFailureStatus_Info_called[SENSOR_RLS].allStatus)
    {
        can_send_sig(SensorErrorSt_RLS, SENSOR_ERROR);
    }
    else
    {
        can_send_sig(SensorErrorSt_RLS, SENSOR_NOERROR);
    }


    if( USSFailureStatus_Info_called[SENSOR_RR].allStatus || USSFailureStatus_Info_called[SENSOR_RRM].allStatus 
    || USSFailureStatus_Info_called[SENSOR_RLM].allStatus || USSFailureStatus_Info_called[SENSOR_RL].allStatus  
    || USSFailureStatus_Info_called[SENSOR_FRS].allStatus || USSFailureStatus_Info_called[SENSOR_FR].allStatus 
    || USSFailureStatus_Info_called[SENSOR_FRM].allStatus || USSFailureStatus_Info_called[SENSOR_FLM].allStatus
    || USSFailureStatus_Info_called[SENSOR_FL].allStatus  || USSFailureStatus_Info_called[SENSOR_FLS].allStatus    
	|| USSFailureStatus_Info_called[SENSOR_RRS].allStatus || USSFailureStatus_Info_called[SENSOR_RLS].allStatus 
     )
    {
        can_send_sig(ErrorSt_PDC, 0x1); //error
    }
    else
    {
        can_send_sig(ErrorSt_PDC, 0x0); //no error
    }
}


void USS_FailureStatus_handler(void)
{
	U8 CurrentSensor;
	U8 BitMaskQuantity;
	U8 VehicleKeyStatus = 0;	
	U8 rader_fault[12] = {0};
	U8 rader_isblocked[12] = {0};
    
	U8 i;
	VehicleKeyStatus = can_receive_sig(PowerMode);
    FV_diagnosticTypedef FV_diagnostic[12];
    _memset(FV_diagnostic,0,12*sizeof(FV_diagnosticTypedef));
    
	if((VehicleKeyStatus == KEY_ACC_ON)/*||(VehicleKeyStatus == KEY_ACC_CRANK)*/)
	{
        g_FV_getSnsDiagnosticResult(FV_diagnostic);//(FV_diagnosticTypedef*)USSFailureStatus_Info_called);//USSFailureStatus_Info_called);
        for(i=0;i<12;i++)
        {		
            FV_diagnostic[i].item.isBlocked = 0;
            FV_diagnostic[i].item.ringTimeTooShort = 0;
            FV_diagnostic[i].item.ringTimeTooLong = 0;
            FV_diagnostic[i].item.signalDisturbed = 0;		
            FV_diagnostic[i].item.signalError = 0;
            FV_diagnostic[i].item.initFail = 0;
        }
        USSFailureStatus_Info_called[SENSOR_RRS].allStatus  = FV_diagnostic[6].allStatus;
		USSFailureStatus_Info_called[SENSOR_RR].allStatus   = FV_diagnostic[7].allStatus;
		USSFailureStatus_Info_called[SENSOR_RRM].allStatus  = FV_diagnostic[8].allStatus;
		USSFailureStatus_Info_called[SENSOR_RLM].allStatus  = FV_diagnostic[9].allStatus;
		USSFailureStatus_Info_called[SENSOR_RL].allStatus   = FV_diagnostic[10].allStatus;
		USSFailureStatus_Info_called[SENSOR_RLS].allStatus  = FV_diagnostic[11].allStatus;
		USSFailureStatus_Info_called[SENSOR_FRS].allStatus  = FV_diagnostic[5].allStatus;
		USSFailureStatus_Info_called[SENSOR_FR].allStatus   = FV_diagnostic[4].allStatus;
		USSFailureStatus_Info_called[SENSOR_FRM].allStatus  = FV_diagnostic[3].allStatus;
		USSFailureStatus_Info_called[SENSOR_FLM].allStatus  = FV_diagnostic[2].allStatus;
		USSFailureStatus_Info_called[SENSOR_FL].allStatus   = FV_diagnostic[1].allStatus;
		USSFailureStatus_Info_called[SENSOR_FLS].allStatus  = FV_diagnostic[0].allStatus;
	}
	else
	{
		USSFailureStatus_Info_called[SENSOR_RRS].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_RR].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_RRM].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_RLM].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_RL].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_RLS].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FRS].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FR].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FRM].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FLM].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FL].allStatus = 0;
		USSFailureStatus_Info_called[SENSOR_FLS].allStatus = 0;
	}

	for(CurrentSensor=0;CurrentSensor<SENSOR_TOTAL_INDEX;CurrentSensor++)
	{
		for(BitMaskQuantity=0;BitMaskQuantity<16;BitMaskQuantity++)
		{
			if((USSFailureStatus_Info_called[CurrentSensor].allStatus>>BitMaskQuantity)&USS_DIAGREASON_BIT_MASK)
			{
				switch(BitMaskQuantity)
				{
					case SHORT_TO_BATTERY:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= (1u<<USS_SENSOR_SHORT_TO_BAT);
						break;
					
					case SHORT_TO_GND:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= (1u<<USS_SENSOR_SHORT_TO_GND);
						break;
					
					case BE_BLOCK:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_SIGNAL_ERROR));
						break;
					
					case RING_TIME_TOO_SHORT:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_RING_TIME_ERROR));
						break;
					
					case RING_TIME_TOO_LONG:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_RING_TIME_ERROR));
						break;
					
					case SIGNAL_DISTURBED:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_SIGNAL_INVALID));
						break;
					
					case SIGNAL_ERROR:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_SIGNAL_ERROR));
						break;
					
					case INIT_FAIL:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= ((1u<<USS_COMPNENT_ERROR));
						break;
					
					case DISCONNECTED:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= (1u<<USS_NO_SIGNAL);
						break;

					case MISMATCH:
						USSFailureDtcInfo[CurrentSensor].DtcByte |= (1u<<USS_SENSOR_MISS_MATCH);
						break;
					
					default:
						break;		
				}
			}
			else
			{
				//do nothing
			}
		}
	}

	for(CurrentSensor=0;CurrentSensor<SENSOR_TOTAL_INDEX;CurrentSensor++)//uss failure recover
	{
		if(!USSFailureStatus_Info_called[CurrentSensor].item.shortToGND)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssSensorShortToGnd = 0;
		}
		else
		{
			//do nothing
		}

		if(!USSFailureStatus_Info_called[CurrentSensor].item.shortToBattery)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssSensorShortToBattery = 0;
		}
		else
		{
			//do nothing
		}

		if(!USSFailureStatus_Info_called[CurrentSensor].item.signalDisturbed)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssSignalInvalid = 0;
		}
		else
		{
			//do nothing
		}

		if((!USSFailureStatus_Info_called[CurrentSensor].item.signalError)&&(!USSFailureStatus_Info_called[CurrentSensor].item.isBlocked))
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssSignalError = 0;
		}
		else
		{
			//do nothing
		}

		if(!USSFailureStatus_Info_called[CurrentSensor].item.initFail)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssCompnentError = 0;
		}
		else
		{
			//do nothing
		}

		if((!USSFailureStatus_Info_called[CurrentSensor].item.ringTimeTooShort)&&(!USSFailureStatus_Info_called[CurrentSensor].item.ringTimeTooLong))
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssRingTimeError = 0;
		}
		else
		{
			//do nothing
		}

		if(!USSFailureStatus_Info_called[CurrentSensor].item.typeIncorrect)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssSensorMissMatch = 0;
		}
		else
		{
			//do nothing
		}
	
		if(!USSFailureStatus_Info_called[CurrentSensor].item.disconnected)
		{
			USSFailureDtcInfo[CurrentSensor].DtcItem.UssNoSignal = 0;
		}
		else
		{
			//do nothing
		}
	}
	
	// fault.
	for(i=0;i<SENSOR_TOTAL_INDEX;i++)
    {
        if(USSFailureStatus_Info_called[i].item.isBlocked == 1)
        {        
			rader_fault[i] = 0; 		
			rader_isblocked[i] = 1;			
        }
		else if(USSFailureStatus_Info_called[i].allStatus != 0)
		{
			rader_fault[i] = 1;	
			rader_isblocked[i] = 0;
		}
        else
        {
            rader_fault[i] = 0;			
			rader_isblocked[i] = 0;
        }
    }

    if(_memcmp(rader_fault,rader_fault_backup,SENSOR_TOTAL_INDEX))
    {
        _memcpy(rader_fault_backup,rader_fault,NUMBER_OF_SENSOR);
        SocManager_SendMsg(TX_HQ,TYPE_EVENT, M3_NOTIFY_RADIO_RADAR_STATUS, SENSOR_TOTAL_INDEX, rader_fault);
    }

	if(_memcmp(rader_isblocked,rader_isBlocked_backup,SENSOR_TOTAL_INDEX))
    {
        _memcpy(rader_isBlocked_backup,rader_isblocked,NUMBER_OF_SENSOR);
//        SocManager_SendMsg(TX_HQ,TYPE_EVENT, M3_NOTIFY_RADIO_RADAR_ISBLOCKED, SENSOR_TOTAL_INDEX, rader_isblocked);
    }
	
    USS_FailureStatus_CanSender();
}

void updatePdcStatusToAvm(void)
{
	SocManager_SendMsg(TX_HQ,TYPE_EVENT, M3_NOTIFY_RADIO_RADAR_STATUS, SENSOR_TOTAL_INDEX, rader_fault_backup);
//	SocManager_SendMsg(TX_HQ,TYPE_EVENT, M3_NOTIFY_RADIO_RADAR_ISBLOCKED, SENSOR_TOTAL_INDEX, rader_isBlocked_backup);
}

/***************************************************
    * Function Name: USS_ALG_version_number
    * Description  : get USS alglorithm version number
    * Parameters   : None
    * Return Value : None
***************************************************/
void USS_ALG_version_number(void)
{

}


/***********************************************************************************************************************
    * Function Name: USS_INFO_Handler
    * Description  : main logic of USS module (20ms cyclic)
    * Parameters   : None
    * Return Value : None
***********************************************************************************************************************/
void USS_INFO_Handler(void)
{
	USS_Slot_Search();
	USS_FailureStatus_handler();
	USS_FailureStatus_Handler_CANBK();
	USS_Slot_M4_Convert_Handler();
	RadarInfoSendToAPP();
}



/*************************************************************
    * Function Name: USS_Slot_Search
    * Description  : the main logic of USS slot search
    * Parameters   : None
    * Return Value : None
*****************************************************************/
U8 search_direction_bak = Turn_Init;
U8 search_Gear_bak = GEAR_P;
U8 replay_clear_flag = 0;
U8 replay_clear_flag_bak = 0;
U8 slotsearchdirection = 3;
extern BOOL AVM_ENTER_FLAG;

void USS_Slot_Search(void)
{
	USSParkingSlotSearching(SearchingDoubleSideMode);
}


/*************************************************************
    * Function Name: RadarInfoSendToAPP
    * Description  : send the radar massage to service from M4
    * functional adaption: USS slot SOD
    * Parameters   : None
    * Return Value : None
*****************************************************************/
void RadarInfoSendToAPP(void)
{
	//Send Radar Send Radar Distance Info To APP
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_A_X_U16,p_stk_uss_slot_search->USS_AX_L);
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_A_Y_U16,p_stk_uss_slot_search->USS_AY_L);
	
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_B_X_U16,p_stk_uss_slot_search->USS_BX_L);
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_B_Y_U16,p_stk_uss_slot_search->USS_BY_L);
	
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_C_X_U16,p_stk_uss_slot_search->USS_CX_L);
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_C_Y_U16,p_stk_uss_slot_search->USS_CY_L);
	
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_D_X_U16,p_stk_uss_slot_search->USS_DX_L);
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_D_Y_U16,p_stk_uss_slot_search->USS_DY_L);
	
	M4Msg_Update(E_M4_Left_PAS_COORDINATE_DEPTH_U16,p_stk_uss_slot_search->USS_SLOT_DEPTH_L);

    M4Msg_Update(E_M4_Right_PAS_COORDINATE_A_X_U16,p_stk_uss_slot_search->USS_AX_R);
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_A_Y_U16,p_stk_uss_slot_search->USS_AY_R);
	                                                                       
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_B_X_U16,p_stk_uss_slot_search->USS_BX_R);
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_B_Y_U16,p_stk_uss_slot_search->USS_BY_R);
	                                                                       
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_C_X_U16,p_stk_uss_slot_search->USS_CX_R);
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_C_Y_U16,p_stk_uss_slot_search->USS_CY_R);
	                                                                       
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_D_X_U16,p_stk_uss_slot_search->USS_DX_R);
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_D_Y_U16,p_stk_uss_slot_search->USS_DY_R);
	
	M4Msg_Update(E_M4_Right_PAS_COORDINATE_DEPTH_U16,p_stk_uss_slot_search->USS_SLOT_DEPTH_R);

	if(GetMmiTouchDebugFlag()==1)
	{	 
		can_send_sig(USS_SLOT_L_Ax,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x));
		can_send_sig(USS_SLOT_L_AY,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y));
		can_send_sig(USS_SLOT_L_Bx,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x));
		can_send_sig(USS_SLOT_L_By,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y));
        
		can_send_sig(USS_SLOT_L_Cx,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x));
		can_send_sig(USS_SLOT_L_Cy,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y));
		can_send_sig(USS_SLOT_L_Dx,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x));
		can_send_sig(USS_SLOT_L_Dy,(S16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y));

        can_send_sig(USS_SLOT_R_Ax,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x));
		can_send_sig(USS_SLOT_R_Ay,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y));
		can_send_sig(USS_SLOT_R_Bx,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x));
		can_send_sig(USS_SLOT_R_By,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y));
        
		can_send_sig(USS_SLOT_R_Cx,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x));
		can_send_sig(USS_SLOT_R_Cy,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y));
		can_send_sig(USS_SLOT_R_Dx,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x));
		can_send_sig(USS_SLOT_R_Dy,(S16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y));

		can_send_sig(USS_SLOT_L_DEPTH,stk_uss_slot_search.ParkingSlotInfo_L.SlotDepth);
		can_send_sig(USS_SLOT_R_DEPTH,stk_uss_slot_search.ParkingSlotInfo_R.SlotDepth);
	}
}

/*************************************************************
    * Function Name: USS_Slot_M4_Convert_Handler
    * Description  : convert the data, from USS alg to M4 service
    * functional adaption: 
    * Parameters   : None
    * Return Value : None
*****************************************************************/
void USS_Slot_M4_Convert_Handler(void)
{
    /*****************************************************uss left***************************************************************/
	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x >= 0)	//Ax
	{
		p_stk_uss_slot_search->USS_AX_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x/10);
		p_stk_uss_slot_search->USS_AX_L = (U16)(p_stk_uss_slot_search->USS_AX_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_AX_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_AX_L = (U16)(p_stk_uss_slot_search->USS_AX_L | 0x8000);
	}

	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y >= 0)	//Ay
	{
		p_stk_uss_slot_search->USS_AY_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y/10);
		p_stk_uss_slot_search->USS_AY_L = (U16)(p_stk_uss_slot_search->USS_AY_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_AY_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_AY_L = (U16)(p_stk_uss_slot_search->USS_AY_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x >= 0)	//Bx
	{
		p_stk_uss_slot_search->USS_BX_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x/10);
		p_stk_uss_slot_search->USS_BX_L = (U16)(p_stk_uss_slot_search->USS_BX_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_BX_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_BX_L = (U16)(p_stk_uss_slot_search->USS_BX_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y >= 0)	//By
	{
		p_stk_uss_slot_search->USS_BY_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y/10);
		p_stk_uss_slot_search->USS_BY_L = (U16)(p_stk_uss_slot_search->USS_BY_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_BY_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_BY_L = (U16)(p_stk_uss_slot_search->USS_BY_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x >= 0)	//Cx
	{
		p_stk_uss_slot_search->USS_CX_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x/10);
		p_stk_uss_slot_search->USS_CX_L = (U16)(p_stk_uss_slot_search->USS_CX_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_CX_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_CX_L = (U16)(p_stk_uss_slot_search->USS_CX_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y >= 0)	//Cy
	{
		p_stk_uss_slot_search->USS_CY_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y/10);
		p_stk_uss_slot_search->USS_CY_L = (U16)(p_stk_uss_slot_search->USS_CY_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_CY_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_CY_L = (U16)(p_stk_uss_slot_search->USS_CY_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x >= 0)	//Dx
	{
		p_stk_uss_slot_search->USS_DX_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x/10);
		p_stk_uss_slot_search->USS_DX_L = (U16)(p_stk_uss_slot_search->USS_DX_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_DX_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_DX_L = (U16)(p_stk_uss_slot_search->USS_DX_L | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y >= 0)	//Dy
	{
		p_stk_uss_slot_search->USS_DY_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y/10);
		p_stk_uss_slot_search->USS_DY_L = (U16)(p_stk_uss_slot_search->USS_DY_L & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_DY_L = (U16)((stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_DY_L = (U16)(p_stk_uss_slot_search->USS_DY_L | 0x8000);
	}

	p_stk_uss_slot_search->USS_SLOT_DEPTH_L = (U16)(stk_uss_slot_search.ParkingSlotInfo_L.SlotDepth/10);
	p_stk_uss_slot_search->USS_SLOT_DEPTH_L = (U16)(p_stk_uss_slot_search->USS_SLOT_DEPTH_L & 0x7FFF);

    
    /***************************************************uss right***************************************************************/   
    if(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x >= 0)	//Ax
	{
		p_stk_uss_slot_search->USS_AX_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x/10);
		p_stk_uss_slot_search->USS_AX_R = (U16)(p_stk_uss_slot_search->USS_AX_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_AX_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_AX_R = (U16)(p_stk_uss_slot_search->USS_AX_R | 0x8000);
	}

	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y >= 0)	//Ay
	{
		p_stk_uss_slot_search->USS_AY_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y/10);
		p_stk_uss_slot_search->USS_AY_R = (U16)(p_stk_uss_slot_search->USS_AY_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_AY_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_AY_R = (U16)(p_stk_uss_slot_search->USS_AY_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x >= 0)	//Bx
	{
		p_stk_uss_slot_search->USS_BX_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x/10);
		p_stk_uss_slot_search->USS_BX_R = (U16)(p_stk_uss_slot_search->USS_BX_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_BX_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_BX_R = (U16)(p_stk_uss_slot_search->USS_BX_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y >= 0)	//By
	{
		p_stk_uss_slot_search->USS_BY_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y/10);
		p_stk_uss_slot_search->USS_BY_R = (U16)(p_stk_uss_slot_search->USS_BY_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_BY_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_BY_R = (U16)(p_stk_uss_slot_search->USS_BY_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x >= 0)	//Cx
	{
		p_stk_uss_slot_search->USS_CX_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x/10);
		p_stk_uss_slot_search->USS_CX_R = (U16)(p_stk_uss_slot_search->USS_CX_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_CX_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_CX_R = (U16)(p_stk_uss_slot_search->USS_CX_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y >= 0)	//Cy
	{
		p_stk_uss_slot_search->USS_CY_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y/10);
		p_stk_uss_slot_search->USS_CY_R = (U16)(p_stk_uss_slot_search->USS_CY_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_CY_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_CY_R = (U16)(p_stk_uss_slot_search->USS_CY_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x >= 0)	//Dx
	{
		p_stk_uss_slot_search->USS_DX_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x/10);
		p_stk_uss_slot_search->USS_DX_R = (U16)(p_stk_uss_slot_search->USS_DX_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_DX_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x * (-1))/10);
		p_stk_uss_slot_search->USS_DX_R = (U16)(p_stk_uss_slot_search->USS_DX_R | 0x8000);
	}


	if(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y >= 0)	//Dy
	{
		p_stk_uss_slot_search->USS_DY_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y/10);
		p_stk_uss_slot_search->USS_DY_R = (U16)(p_stk_uss_slot_search->USS_DY_R & 0x7FFF);
	}
	else
	{
		p_stk_uss_slot_search->USS_DY_R = (U16)((stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y * (-1))/10);
		p_stk_uss_slot_search->USS_DY_R = (U16)(p_stk_uss_slot_search->USS_DY_R | 0x8000);
	}

	p_stk_uss_slot_search->USS_SLOT_DEPTH_R = (U16)(stk_uss_slot_search.ParkingSlotInfo_R.SlotDepth/10);
	p_stk_uss_slot_search->USS_SLOT_DEPTH_R = (U16)(p_stk_uss_slot_search->USS_SLOT_DEPTH_R & 0x7FFF);

}


/*************************************************************
    * Function Name: Get_App_USS_System_Failure_Status
    * Description  : notify the uss system status to APP module
    * functional adaption: Radar shield
    * Parameters   : void
    * Return Value : 0x00 : normal  0x01: USS_F_FAILURE  0x2: USS_R_FAILURE
*****************************************************************/
unsigned int Get_App_USS_System_Failure_Status    (void)
{
    if((USSFailureStatus_Info_called[0].allStatus||USSFailureStatus_Info_called[1].allStatus||USSFailureStatus_Info_called[2].allStatus
		||USSFailureStatus_Info_called[3].allStatus||USSFailureStatus_Info_called[4].allStatus||USSFailureStatus_Info_called[5].allStatus)
		&& (USSFailureStatus_Info_called[6].allStatus||USSFailureStatus_Info_called[7].allStatus||USSFailureStatus_Info_called[8].allStatus
		||USSFailureStatus_Info_called[9].allStatus||USSFailureStatus_Info_called[10].allStatus||USSFailureStatus_Info_called[11].allStatus))
    {
        return USS_FR_FAILURE;
    }
	else if(USSFailureStatus_Info_called[0].allStatus||USSFailureStatus_Info_called[1].allStatus||USSFailureStatus_Info_called[2].allStatus
		||USSFailureStatus_Info_called[3].allStatus||USSFailureStatus_Info_called[4].allStatus||USSFailureStatus_Info_called[5].allStatus)
	{
		return USS_R_FAILURE;
	}
	else if(USSFailureStatus_Info_called[6].allStatus||USSFailureStatus_Info_called[7].allStatus||USSFailureStatus_Info_called[8].allStatus
		||USSFailureStatus_Info_called[9].allStatus||USSFailureStatus_Info_called[10].allStatus||USSFailureStatus_Info_called[11].allStatus)
	{
		return USS_F_FAILURE;
	}
    else 
    {
        return USS_NO_FAILURE;
    }
}

/*************************************************************
    * Function Name: Get_USS_Slot_Type
    * Description  : get the USS slot whose type is vertical or parallel from SOC 
    * functional adaption: USS slot search
    * Parameters   : U8 VerticalOrParallelSlot (0x00:none slot 0x01:parallel slot  0x02:vertical slot)
    				 U8 AvmOrUssSlot (0x00:AVM slot 0x01:USS slot)
    * Return Value : void
*****************************************************************/
void Get_USS_Slot_Type(U8 VerticalOrParallelSlot, U8 AvmOrUssSlot)
{

	if(AvmOrUssSlot == 0x01)
	{
		if(VerticalOrParallelSlot == 0x01)
		{
			UssSlotType = USS_Vertical_Slot;
		}
		else if(VerticalOrParallelSlot == 0x02)
		{
			UssSlotType =  USS_Parallel_Slot;
		}
		else
		{
			UssSlotType = The_Other_Slot;
		}
	}
	else
	{
		UssSlotType = The_Other_Slot;
	}

}


/***********************************************************************************************************************
    * Function Name: USS_ALG_version_number_SS
    * Description  : get USS SS(Slot Searching) alglorithm version number
    * Parameters   : None
    * Return Value : None
***********************************************************************************************************************/
void USS_ALG_version_number_SS(void)
{
	U8 i;
	char USS_ALG_SoftVersion_Slot_Searching[19];
	if(!GetUssSlotSearchingLibVer(USS_ALG_SoftVersion_Slot_Searching))
	{
		for(i=0;i<19;i++)
		{
			UssSlotSearchingAlgSoftVersion[i]=USS_ALG_SoftVersion_Slot_Searching[i];
		}	
	}
	else
	{
		return;
	}
}


/***********************************************************************************************************************
    * Function Name: USS_ALG_version_number_OD
    * Description  : get USS OD(Object Detect) alglorithm version number
    * Parameters   : None
    * Return Value : None
***********************************************************************************************************************/
extern U8 USS_ALG_SoftVersion[22];
void USS_ALG_version_number_OD(void)
{
#if 0
	U8 i;
	char USS_ALG_SoftVersion_Object_Detect[19];
	if(!GetUssObjectDetectLibVer(USS_ALG_SoftVersion_Object_Detect))
	{
		for(i=0;i<19;i++)
		{
			UssObjectDetectAlgSoftVersion[i]=USS_ALG_SoftVersion_Object_Detect[i];
		}	
	}
	else
	{
		return;
	}
#endif
    
    _memset(USS_ALG_SoftVersion,0,sizeof(USS_ALG_SoftVersion));
	//g_FV_adiGetUSSSWVer_bl(UssObjectDetectAlgSoftVersion);
	g_FV_adiGetUSSSWVer_bl(USS_ALG_SoftVersion);

}


/***********************************************************************************************************************
    * Function Name: getUssParaType
    * Description  : get USS OD(Object Detect) alglorithm version number
    * Parameters   : None
    * Return Value : None

	typedef union 
	{
		 uchar cState;
		 struct 
		 {
		  uchar SnsThresholdDataReqSent   :1;
		  uchar SnsEEPROMDataReqSent    :1;
		  uchar SnsMeasurementConfigDataReqSent :1;
		  uchar Reserved       :5;
		 } Bits;
	} tSnsOperatingDataSendStateType;

	#define SNS_OP_DATA_SEND_STATE_ALL_REQ_MASK						0x05
***********************************************************************************************************************/
unsigned char getUssParaType(void)
{
	return 0x05;
}

/*************************************************************
    * Function Name: unsigned char DiagGetUssSenorDistanceValue(PASysSnsIndexType Sensor)
    * Description  : Diagnostic get the USS distance value use for $22
    * functional adaption: diagnostic
    * Parameters   : PASysSnsIndexType Sensor (PASysSnsIndexType indicate the number of sensors)
    * Return Value : unsigned char (0x00~0xFF indicate the distance  unit:cm)
*****************************************************************/
unsigned short USS_Distance_DiagInfo;
unsigned short DiagGetUssSenorDistanceValue(PASysSnsIndexType Sensor)
{
    switch(Sensor)
    {
        case RRS_SNS_INDEX:		
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm;	
            break;
        case RR_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm;	
            break;
        case RRM_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm;	
            break;
        case RLM_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm;	
            break;
        case RL_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm;	
            break;
        case RLS_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm;	
            break;
        case FRS_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm;	
			break;
        case FR_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm;	
            break;
        case FRM_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm;	
            break;
        case FLM_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm;	
            break;
        case FL_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm;	
            break;
        case FLS_SNS_INDEX:
			USS_Distance_DiagInfo = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm;	
            break;
        default:
			break;
    }
    return USS_Distance_DiagInfo;
}

/*************************************************************
    * Function Name: VehiclePdcWorkingState DiagGetUssWorkingState(void)
    * Description  : Diagnostic get the USS working state use for $22
    * functional adaption: diagnostic
    * Parameters   : void
    * Return Value : VehiclePdcWorkingState
    PDC_OFF_STATE,
	PDC_STANDBY_STATUS,
	PDC_STANDBY_AND_FRONT_FAILURE,
	PDC_STANDBY_AND_REAR_FAILURE,
	PDC_FRONT_ACTIVE,
	PDC_FRONT_ACTIVE_AND_REAR_FAILURE,
	PDC_REAR_ACTIVE,
	PDC_REAR_ACTIVE_AND_FRONT_FAILURE,
	PDC_FRONT_REAR_ACTIVE,
	PDC_SYSTEM_FAILURE,
	PDC_FRONT_FAILURE_AND_REAR_INACTIVE,
	PDC_REAR_FAILURE_AND_FRONT_INACTIVE,
*****************************************************************/
VehiclePdcWorkingState DiagGetUssWorkingState(void)
{
	return GetUssWorkingState();
}

PAS_Work_Status DiagGetPasWorkingState(void)
{
	return GetPasWorkingState();
}

PAS_Warning_Tone DiagGetPasWarningState(void)
{
	return GetPasWarningState();
}

/***********************************************************************************************************************
    * Function Name: RadarPowerManagementHandler_5msEntry
    * Description  : Power Management of ultra radar
    * Parameters   : None
    * Return Value : None
***********************************************************************************************************************/

void RadarPowerManagementHandler_5msEntry(void)
{
	static U8 VehicleKeyRawStatus = 0;
	static U8 VehicleKeyStatus = 0;
	static U8 VehicleKeyStatusBak = 0;
	static U8 bGpioOpenDelayFlag = 0;
	static U8 GpioOpenDelayCounter = 0;
	if(eEolState != E_EOL_NORMAL)
	{
		
		//VehicleKeyRawStatus = can_receive_sig(BCM_KeySt);
		if((VehicleKeyRawStatus == KEY_ACC_ON)/*||(VehicleKeyRawStatus == KEY_ACC_CRANK)*/)
		{
			VehicleKeyStatus = USS_POWER_ON;
		}
		else
		{
			VehicleKeyStatus = USS_POWER_OFF;
		}
		if(VehicleKeyStatus != VehicleKeyStatusBak)
		{
			if(VehicleKeyStatus == USS_POWER_ON)
			{
				F_RADAR_EN_ON();
				R_RADAR_EN_ON();
				bGpioOpenDelayFlag = TRUE;
			}
			else
			{
				F_RADAR_EN_OFF();
				R_RADAR_EN_OFF();
			}
		}

		VehicleKeyStatusBak = VehicleKeyStatus;
	}
}


