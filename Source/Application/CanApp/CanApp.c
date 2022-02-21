
/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
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

#include "CanApp.h"
#include "Can_App_il.h"
#include "CanSig_Def.h"
#include "CanSig_cfg.h"
#include "can_cfg.h"
#include "can_def.h"
#include "Cansig_cfg_if.h"
#include "iodefine.h"
#include "APSAPP.h"
#include "SocCommunicator.H"
#include "il_inc.h"
#include "il_par.h"
#include "Sig_Combine.H"
#include "Signal_IF.H"
#include "NaviApp.h"

#include "GPIO_IF.h"
#include "SocManager.h"
#include "Crc.h"
#include "candiagdtc.h"
#include "candiagdtccfg.h"
#include "CanMacroDefine.h"
#include "M4MsgHandler_IF.h"
#include "ComplexDrvier_Globaldef_IF.h"
#include "UssInfoMsg.h"
#include "UssInfo_Msg_IF.h"
#include "eol_app.h"
#include "ApsCanAPP.h"
#include "pdcCtrl.h"

#include "can_par.h"
#include "Dem_IntErrId.h"
#include "stdio.h"
#include "sw_timer.h"
#include "EEPDriver_IF.h"

#define VCU_CONGIGED 0x20

extern U8 get_gear_status(void);
extern diagnosticTypedef USSFailureStatus_Info_called[12];

BOOL bReqToSendLeverInfoSignal = FALSE;
BOOL bReqToSendTurnSignal = FALSE;
BOOL bReqToSendSpeedSignal = FALSE;
BOOL bReqToSendIGNstatus = FALSE;
BOOL bReqToSendSteerWheelAngleSignal = FALSE;
BOOL bReqToSenddoortatus = FALSE;
BOOL bReqToSendRearviewMirrorSt = FALSE;
BOOL bReqToSendSpeechReqSignal = FALSE;
BOOL bReqToSendViewModeReqSignal = FALSE;
BOOL bReqToSendDynamicReqSignal = FALSE;
BOOL bReqToSendLanguageSetReqSignal = FALSE;
BOOL bReqToSendVehicleStandsitllSts = FALSE;
BOOL bReqToSendSystemDate = FALSE;


BOOL SVP_SUCCEED_FLAG = FALSE; // wait for svp start notice

BOOL bReqReportcamerafault = FALSE;

BOOL PEPS_LOST_FLAG = FALSE;
BOOL bReqToSendRadarlevels = FALSE;
BOOL bOpenWatchDog = FALSE;
BOOL bReqUssStatus = FALSE;
BOOL AVM_ENTER_FLAG = FALSE;
U8 can_softkey_req;
U8 AVM_Speech_Req = 0;
U8 uAVSViewMode;
U8 uAVSSt;
U8 AVM_CurSta = SK_EXIT;
U8 AVM_Speech_view_Req = 0;
U8 uAVSCalibrationSta;
U8 ModWarning = 0;
U8 PdWarning = 0;


U8 EolUpdateFlag = FALSE;
U8 GW_OTAMode_fun = 0x00;
U8 ETH_status = 0x00;
U8 MmiTouchDebugFlag = 0;
#define EEP_INVALID_ADDRESS     0xFFFFFFFF
#define EEP_INVALID_LENGTH      0x0

extern BOOL bJ6_start_complete;
extern BOOL bPowerOnDtcEnd;
extern BOOL Request_Enter_AVM_Once;

U8 uDeviceFault[2] = {0};
DTC_SNAPSHOT_RECORD_IDENTIFIERS Signal_Snapshot_Data;

BOOL b_Way_Point_Feedback_1_Triger = FALSE;// can rcvhandle triger
BOOL b_Way_Point_Feedback_2_Triger = FALSE;
extern DOIP_FRAME doip_frame;
extern CAN_EEP_RETRY_STRUCT EepWriteControl;
static void SOC_EEP_RewriteHandler(DescMsgContext* pMsgContext);
void CanAppGetEngStatus(U8* data);

void SocCan_20ms_Entry(void)
{	
	// uidq1364:it can not send spi message when eol update 
	if(EolUpdateFlag == FALSE) 
	{
		can_acckey_rxhandler();
		can_avm_act_req_rxhandler();
		can_vehiclespeed_rxhandler();
		can_LeverInfo_rxhandler();
		can_steering_angle_rxhandler();
		can_coordinate_rxhandler();
		can_VehicleOdometer_rxhandler();
		CAN_CarDoorStaus_rxhandler();
		CAN_CarRearviewMirrorSt_rxhandler();
		can_turnlamp_rxhandler();
		can_SetLanguage_rxhandler();
		can_AVM_ViewModeControl_rxhandler();
		can_DynamicPGS_rxhandler();
		can_FactoryModeReq_rxhandler();
		can_OTAMode_rxhandler();
		can_datetime_rxhandler();
		
		can_AVSErrorSt_txhandler();
		can_CameraErrorSt_txhandler();
        Can_ModWarning_txhandler();
		Can_PDWarning_txhandler();
		can_PDCAutoOnFun_txhandler();
		can_AVSCalibrationStatus_txhandler();
	}
}

void can_sig_init(void)
{
	bReqToSendTurnSignal = FALSE;
	bReqToSendSpeedSignal = FALSE;
	bReqToSendIGNstatus = FALSE;
	bReqReportcamerafault = FALSE;
	bReqToSendVehicleStandsitllSts = FALSE;
	bReqToSenddoortatus = FALSE;
	bReqToSendLeverInfoSignal = FALSE;
	bReqToSendSpeechReqSignal = FALSE;
	bReqToSendViewModeReqSignal = FALSE;
	bReqToSendDynamicReqSignal = FALSE;
	bReqToSendLanguageSetReqSignal = FALSE;
	bReqToSendSteerWheelAngleSignal = FALSE;
	bReqToSendRearviewMirrorSt = FALSE;
	SVP_SUCCEED_FLAG = FALSE;	
	bReqToSendSystemDate = FALSE;
	//bJ6_start_complete = FALSE;
}

BOOL GetNMTimeOutFlag(U8 nodeindex)
{
    return(bMessageTimeOutStatus[nodeindex]);
}

BOOL GetMessageTimeOutFlag(U8 nodeindex)
{
    return(bMessageLostStaForGWNodeLost[nodeindex]);
}

BOOL GetADVMessageTimeOutFlag(U8 nodeindex)
{
    return(bMessageLostStaForADVNodeLost[nodeindex]);
}


U16 can_vehiclespeed_backup=0;
void can_vehiclespeed_rxhandler(void)
{
	U32 spd_cal;
	static U16 can_vehiclespeed,phy_vehiclespeed=0;
	U8 arg[2];

	/* The Vehicle speed message missing: 0x8000 */
	if(GetMessageTimeOutFlag(ABS_1_MESSAGE))
	{	
		if(EolApp_IsEolActivated() == FALSE)
		{
			can_vehiclespeed = SPEED_MISSING_VALUE;	
		}else{
			can_vehiclespeed = 0;
		}
		phy_vehiclespeed = 0;
	}
	else
	{
		can_vehiclespeed = can_receive_sig(VehicleSpeed);
		/* Bus value range:0x0000-0x7FFE */
		if(can_vehiclespeed >= SPEED_ERROR_VALUE) //error value
		{
			can_vehiclespeed = SPEED_ERROR_VALUE;
		}
		phy_vehiclespeed = can_vehiclespeed;
	}
	
	Signal_Snapshot_Data.Snapshot0100_VehicleSpeed = can_vehiclespeed;	

	/* Formula: Physical value = 0.01*bus value */
	phy_vehiclespeed = (U16)(phy_vehiclespeed/100); //x*0.01 = km/h  

	if(phy_vehiclespeed!=can_vehiclespeed_backup)
	{
		can_vehiclespeed_backup = phy_vehiclespeed;
		arg[0] = (U8)(phy_vehiclespeed>>8);
		arg[1] = (U8)(phy_vehiclespeed&0xFF);
		SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_SPEED_DATA,2,arg);
	}
	
	if(bReqToSendSpeedSignal)
	{
		bReqToSendSpeedSignal = FALSE;
		can_vehiclespeed_backup = phy_vehiclespeed;
		arg[0] = (U8)(phy_vehiclespeed>>8);
		arg[1] = (U8)(phy_vehiclespeed&0xFF);
		SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_SPEED_DATA,2,arg);
	}

}

static void CanAppAvmSteeringAngleSmallChange(U16 steeringAngle, U8 steeringDirection)
{
	U8 steeringWheelDir =0;
	static U8 steeringWheelDir_backup =0;

	/**/
	if(steeringAngle <= 5)
 	{
 		steeringWheelDir = steeringWheelDir_center;	
	}
	else if(steeringDirection==STEERING_DIRECT_RIGHT)
	{
		steeringWheelDir = steeringWheelDir_right;
	}
	else if(steeringDirection == STEERING_DIRECT_LEFT)
	{
		steeringWheelDir = steeringWheelDir_left;		
	}	 
	else 
	{
		/*do nothing */
	}		
		 
	if((steeringWheelDir_backup != steeringWheelDir) || bReqToSendSteerWheelAngleSignal)
	{
		steeringWheelDir_backup = steeringWheelDir;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT, RADIO_NOTIFY_STEERING_WHEEL_DIRECTION, 1, &steeringWheelDir); //443F
	}
}

/***********************************************************************
*  Name 	   : can_steering_angle_rxhandler 
*  Description : Get the angle from SAS  
*  Parameter   : 0x7FFF: Invalid   
*  Callby	   : SocCan_20ms_Entry
*  Protocol    : 4404 
*  Returns	   : None	
***********************************************************************/
void can_steering_angle_rxhandler(void)
{
	U8 arg[3];
	static U8 steering_angle_dir = 0;
	static U8 steering_angle_dir_backup = 0xFF; //invalid
	static U16 steering_angle_value = 0;
	static U16 wheel_angle_value = 0;
	static U16 wheel_angle_value_backup = 0;

	if(IlGetSteeringWheelAngleRxTimeout()||IlGetSteeringWheelAngleSignRxTimeout())
	{
		IlClrSteeringWheelAngleRxTimeout();
		IlClrSteeringWheelAngleSignRxTimeout();
		return;
	}
	
	steering_angle_value = can_receive_sig(SteeringWheelAngle);
	steering_angle_dir = can_receive_sig(SteeringWheelAngleSign);

	if(steering_angle_value>=ERROR_VALUE_RANGE) 
	{
		return;
	}
	steering_angle_value = steering_angle_value * 0.04357 ;
//	steering_angle_value = (U16)((steering_angle_value * ANGLE_DATA_MAX) / CAN_ANGLE_DATA_RANGE_HIGH);
	
	wheel_angle_value = steering_angle_value/16;

	if(wheel_angle_value>40) 
	{
		return;
	}
	
	if((steering_angle_dir!=steering_angle_dir_backup)||(wheel_angle_value!=wheel_angle_value_backup))
	{
		steering_angle_dir_backup = steering_angle_dir;
		wheel_angle_value_backup = wheel_angle_value;
		arg[0] = (U8)(wheel_angle_value >> 8);
		arg[1] = (U8)wheel_angle_value;
		arg[2] = steering_angle_dir;
		CanAppAvmSteeringAngleSmallChange(steering_angle_value,steering_angle_dir);
	    SocManager_SendMsg(HQ_CMD,TYPE_EVENT, RADIO_NOTIFY_STEERING_WHEEL_DATA, 3, &arg[0]);	  
	}
	
	if(bReqToSendSteerWheelAngleSignal)
	{
		arg[0] = (U8)(wheel_angle_value >> 8);
	    arg[1] = (U8)wheel_angle_value;
	    arg[2] = steering_angle_dir;
		CanAppAvmSteeringAngleSmallChange(steering_angle_value,steering_angle_dir);
	    SocManager_SendMsg(HQ_CMD,TYPE_EVENT, RADIO_NOTIFY_STEERING_WHEEL_DATA, 3, &arg[0]);
		bReqToSendSteerWheelAngleSignal = FALSE;
	}
}


void CAN_CarDoorStaus_rxhandler(void)
{
 
    U8 index;
	U8 ValidValue = 0;
	static U8 uRecvCanMsg[8];
	static U8 uVehicleDoorMsg_Backup[E_VEHICLE_DOOR_NUM];

    for(index= 0;index<E_VEHICLE_DOOR_NUM;index++)
    {  
   
		if(E_DRIVER_DOOR == index)
		{
            if(can_receive_sig(DoorSt_FL))
            {
                uRecvCanMsg[0] = E_DOOR_OPEN;   //open
            }
            else 
            {
                uRecvCanMsg[0] = E_DOOR_CLOSE;  //close
            }			
		}
		else if(E_PSNG_DOOR == index)
		{
			if(can_receive_sig(DoorSt_FR))
			{
				uRecvCanMsg[1] = E_DOOR_OPEN;
			}
			else 
			{
				uRecvCanMsg[1] = E_DOOR_CLOSE;
			}	
		}

		else if(E_RR_DOOR == index)
		{
            if(can_receive_sig(DoorSt_RR))
            {
                uRecvCanMsg[2] = E_DOOR_OPEN;
            }
            else 
            {
                uRecvCanMsg[2] = E_DOOR_CLOSE;
            }			
		}

		else if(E_LR_DOOR == index)
		{
            if(can_receive_sig(DoorSt_RL))
            {
                uRecvCanMsg[3] = E_DOOR_OPEN;
            }
            else 
            {
                uRecvCanMsg[3] = E_DOOR_CLOSE;
            }			
		}
		else if(E_TRUNK_DOOR == index)
		{
            if(can_receive_sig(LuggageDoorSt))
            {
                uRecvCanMsg[4] = E_DOOR_OPEN;
            }
            else 
            {
                uRecvCanMsg[4] = E_DOOR_CLOSE;
            }			
		}
    }


    if(_memcmp(uRecvCanMsg, uVehicleDoorMsg_Backup,E_VEHICLE_DOOR_NUM))
    {
        _memcpy(uVehicleDoorMsg_Backup, uRecvCanMsg,E_VEHICLE_DOOR_NUM);
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT, RADIO_NOTIFY_DOORS_INFO, E_VEHICLE_DOOR_NUM, uRecvCanMsg); 
    }

	if(bReqToSenddoortatus)
	{
		bReqToSenddoortatus = FALSE;
		_memcpy(uVehicleDoorMsg_Backup, uRecvCanMsg,E_VEHICLE_DOOR_NUM);		
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT, RADIO_NOTIFY_DOORS_INFO, E_VEHICLE_DOOR_NUM, uRecvCanMsg); 
	}
}

void CAN_CarRearviewMirrorSt_rxhandler(void)
{
	static U8 arg[8] = {0};
	U8 left_mirror_st = 0;
	U8 right_mirror_st = 0;
	static U8 left_mirror_st_backup = 0;
	static U8 right_mirror_st_backup = 0;

	left_mirror_st = can_receive_sig(MirrorFoldSt_FL);
	right_mirror_st = can_receive_sig(MirrorFoldSt_FR);
	
	if((left_mirror_st != left_mirror_st_backup)||(right_mirror_st != right_mirror_st_backup))
	{
		left_mirror_st_backup = left_mirror_st;
		right_mirror_st_backup = right_mirror_st;
		arg[0] = left_mirror_st_backup;
		arg[1] = right_mirror_st_backup;
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_REARVIEW_MIRROR_STATUS, 2, arg);
	}	
	
	if(bReqToSendRearviewMirrorSt)
	{
		bReqToSendRearviewMirrorSt = FALSE;
		arg[0] = left_mirror_st_backup;
		arg[1] = right_mirror_st_backup;
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_REARVIEW_MIRROR_STATUS, 2, arg);
	}

}

/***********************************************************************
*  Name 	   : can_acckey_rxhandler 
*  Description : CAN ACC
*  Parameter   : PEPS_PowerModeValidity  { 0:not available 0x01:invalid,0x02:valid }
				 BCM_KeySt          { 0:OFF,1:ACC,2:ON,3:Crank} 
*  Protocol    : 440D
*  Returns	   : None	
***********************************************************************/
void can_acckey_rxhandler(void)
{
	U8 ign;
	static BOOL ignmsg_accstatus=FALSE;
	static BOOL ignmsg_accstatus_backup=FALSE;
	static BOOL can_accon_flag=FALSE;
	static BOOL can_accon_flag_backup=FALSE;
	static U8 can_acc_status=0;
	
	CS_SIG_SyncReceive(SIG_ACCSTATUS, &ignmsg_accstatus);  //ACC and CAN
    if(ignmsg_accstatus_backup!=ignmsg_accstatus)
   	{
   		ignmsg_accstatus_backup = ignmsg_accstatus;
		if(ignmsg_accstatus)
	    {
			ign=2;
		}
		else
		{
			ign=0;
		}
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_IGN_KEY_STATUS,1,&ign);//440D
	}

	if(bReqToSendIGNstatus)
	{
		bReqToSendIGNstatus = FALSE;
		if(ignmsg_accstatus)
	    {
			ign=2;
		}
		else
		{
			ign=0;
		}
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_IGN_KEY_STATUS,1,&ign);//440D
	}

	can_acc_status = can_receive_sig(PowerMode);

	if(can_acc_status >= IgnitionOn)
	{
		can_accon_flag = TRUE;
	}
	else
	{	
		can_accon_flag = FALSE;
	}

	if(can_accon_flag!=can_accon_flag_backup)
	{
		can_accon_flag_backup = can_accon_flag;
		
	}

	CS_SIG_SyncSend(SIG_ACC_CAN_IN_STATUS, &can_accon_flag);

}

void can_LeverInfo_rxhandler(void)
{
	static U8 rec_LeverInfo_status = 0;
	static U8 rec_LeverInfo_status_backup = 0;
	static U8 rec_LeverInfo_sig_backup = 0;
	static U8 LeverInfoCnt; 
    U8 canGear = Can_LeverInfo_Invalid;

	if(IlGetLeverInfoRxTimeout())
	{
		IlClrLeverInfoRxTimeout();
		rec_LeverInfo_status = SPI_LeverInfo_P; //time out send P level info
		rec_LeverInfo_sig_backup = 0;
		rec_LeverInfo_status_backup = 0;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_GEAR_DISPLAY_STATUS,1,&rec_LeverInfo_status);
		return;
	}

	canGear = can_receive_sig(LeverInfo);
	if((canGear > Can_LeverInfo_D) && (canGear <=Can_LeverInfo_B) )
    {
		canGear = Can_LeverInfo_D;
    }

	switch(canGear)
	{
		case Can_LeverInfo_P: rec_LeverInfo_status = SPI_LeverInfo_P; break;
		case Can_LeverInfo_R: rec_LeverInfo_status = SPI_LeverInfo_R; break;
		case Can_LeverInfo_N: rec_LeverInfo_status = SPI_LeverInfo_N; break;
		case Can_LeverInfo_D: rec_LeverInfo_status = SPI_LeverInfo_D; break;
		default: break;
	}	

	if(rec_LeverInfo_sig_backup != rec_LeverInfo_status)
	{
		rec_LeverInfo_sig_backup = rec_LeverInfo_status;
		LeverInfoCnt = 0;
	}

	if(rec_LeverInfo_status_backup != rec_LeverInfo_status)
	{
		LeverInfoCnt++;
		if(LeverInfoCnt > LEVERINFO_DEBUNCE_TIME)
		{
			LeverInfoCnt = 0;
			rec_LeverInfo_status_backup = rec_LeverInfo_status;		
			SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_GEAR_DISPLAY_STATUS,1,&rec_LeverInfo_status);
		}
	}
	else
	{
		LeverInfoCnt = 0;
	}
	
	if((bReqToSendLeverInfoSignal)&&(EolApp_IsEolActivated() == FALSE))
	{
		bReqToSendLeverInfoSignal = FALSE;	
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_GEAR_DISPLAY_STATUS,1,&rec_LeverInfo_status);
	}

}


void can_coordinate_rxhandler(void)
{
	U8 arg[5];
	U8 ScreenPressType = 0x00;
	static COORDINATE_DATA_DEF coordinate_data;
	static COORDINATE_DATA_DEF coordinate_data_backup;
	static U8 PreTouchEvt = NOT_TOUCH;
	static U8 TouchEvtSendStep = TOUCH_STEP1;
	static U8 Delay_Send_Cnt;
	static U8 ScreenPressType_backup = 0x00;
	//if(IlGetHU_ScreenPressPosition_XRxTimeout()||IlGetHU_ScreenPressPosition_YRxTimeout())
	//{
	//	IlClrHU_ScreenPressPosition_XRxTimeout();
	//	IlClrHU_ScreenPressPosition_YRxTimeout();
	//	return;
	//}
	
	/*2021/06/10, Create this by uidq3099_colin*/	
	coordinate_data.x1_val = can_receive_sig(ScreenPressPosition_X1);
    coordinate_data.y1_val = can_receive_sig(ScreenPressPosition_Y1);
	coordinate_data.PressType = can_receive_sig(ScreenPressType1);
	/*if((coordinate_data.x1_val!=coordinate_data_backup.x1_val)||(coordinate_data.y1_val!=coordinate_data_backup.y1_val))
	{
		coordinate_data_backup.x1_val=coordinate_data.x1_val;
		coordinate_data_backup.y1_val=coordinate_data.y1_val;

		if(((CAN_FACTROY_MODE == uAVSViewMode)||(CAN_CALIBRATION_MODE == uAVSViewMode))&&(TOUCH_STEP1 == TouchEvtSendStep))
		{
			Delay_Send_Cnt = 0;
			TouchEvtSendStep = TOUCH_STEP2;
			arg[0]=TOUCH_PEN_DOWN;
			arg[1]=(U8)(coordinate_data.y1_val>>8);
			arg[2]=(U8)coordinate_data.y1_val;
			arg[3]=(U8)(coordinate_data.x1_val>>8);
			arg[4]=(U8)coordinate_data.x1_val;
			SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_COORDINATE_DATA,5,arg);
		}
		else
		{
			if((0x7FE == coordinate_data.x1_val)&&(0x7FE == coordinate_data.y1_val))
			{
				if(TOUCH_PEN_DOWN == PreTouchEvt)
				{
					arg[0] = TOUCH_PEN_UP;
				}
			}else{
				arg[0] = TOUCH_PEN_DOWN;
			}
				
			PreTouchEvt = arg[0];
			arg[1]=(U8)(coordinate_data.y1_val>>8);
			arg[2]=(U8)coordinate_data.y1_val;
			arg[3]=(U8)(coordinate_data.x1_val>>8);
			arg[4]=(U8)coordinate_data.x1_val;
			SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_COORDINATE_DATA,5,arg);
		}
	}

	if(TOUCH_STEP2 == TouchEvtSendStep)
	{	
		Delay_Send_Cnt++;
		if(Delay_Send_Cnt >= 15)
		{
			Delay_Send_Cnt = 0;
			TouchEvtSendStep = TOUCH_STEP1;
			arg[0] = TOUCH_PEN_UP;
			SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_COORDINATE_DATA,5,arg);
		}
	}
	*/

	if((coordinate_data.x1_val!=coordinate_data_backup.x1_val)||
		(coordinate_data.y1_val!=coordinate_data_backup.y1_val) ||
		(coordinate_data.PressType != coordinate_data_backup.PressType))
	{
		coordinate_data_backup.x1_val=coordinate_data.x1_val;
		coordinate_data_backup.y1_val=coordinate_data.y1_val;

//		if(((CAN_FACTROY_MODE == uAVSViewMode)||(CAN_CALIBRATION_MODE == uAVSViewMode))&&(coordinate_data.PressType != coordinate_data_backup.PressType))
		{
			coordinate_data_backup.PressType = coordinate_data.PressType;
			arg[0]=coordinate_data.PressType;
			arg[1]=(U8)(coordinate_data.x1_val>>8);
			arg[2]=(U8)coordinate_data.x1_val;
			arg[3]=(U8)(coordinate_data.y1_val>>8);
			arg[4]=(U8)coordinate_data.y1_val;
			SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_COORDINATE_DATA,5,arg);
		}
	}
}


void can_VehicleOdometer_rxhandler(void)
{
	U32 spd_cal;
	static U32 can_vehicleOdometer=0;

	/* The Odometer message missing: 0x02000000 */
	//if(GetNMTimeOutFlag(MESSAGE_Gateway_Config_LOST_INDEX))
	//{
	//	can_vehicleOdometer = ODOMETER_MISSING_VALUE;
	//	Signal_Snapshot_Data.Snapshot0101_Odometer = can_vehicleOdometer;
	//	return;
	//}
	//else
	//{
		can_vehicleOdometer = can_receive_sig(OdometerValue);
	//}
	/* Bus value range:0x00000000-0x01FFFFFE */
	if(can_vehicleOdometer>=ODOMETER_ERROR_VALUE)
	{
		can_vehicleOdometer = ODOMETER_ERROR_VALUE;
	}

	Signal_Snapshot_Data.Snapshot0101_Odometer = can_vehicleOdometer;
}

void can_AVM_ViewModeControl_rxhandler(void)
{
	static U8 arg[8] = {0};
	static U8 can_view_req=0;
	static U8 can_view_req_backup=0;	

	can_view_req = can_receive_sig(AVSViewModeReq);

	if(can_view_req >= CAN_INVALID_VALUE)
		return;

	switch(can_view_req)
	{
		case CAN_SCREEN_DRAGGED_3D_VIEW: can_view_req = 0x08; break; //SPI_3D_VIEW = 0x08
		default: break;
	}
		
	if(can_view_req!=can_view_req_backup)
	{
		can_view_req_backup = can_view_req;
		arg[0] = can_view_req_backup;
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_VIEW_MODE_ANGLE, 1, arg);
	}

	if(bReqToSendViewModeReqSignal)
	{
		bReqToSendViewModeReqSignal = FALSE;
		arg[0] = can_view_req_backup;
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_VIEW_MODE_ANGLE, 1, arg);
	}
}

void can_DynamicPGS_rxhandler(void)
{
	static U8 arg[11] = {0};
	static U8 can_dynamic_req=0;
	static U8 can_dynamic_req_backup=0;
    static U8 can_mod_req=0;
	static U8 can_mod_req_backup=0;
	
	can_dynamic_req = can_receive_sig(DynamicPGSReq);
	can_mod_req = can_receive_sig(MODReq);
	
	if(can_dynamic_req!=can_dynamic_req_backup)
	{
		can_dynamic_req_backup = can_dynamic_req;
		if(can_dynamic_req == 0x02)  //On
		{
			arg[2] = F_ON_AND_R_ON;
		}
		else if(can_dynamic_req == 0x01)  //Off
		{
			arg[2] = F_OFF_AND_R_OFF;
		}
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_SET_STATUS, 11, arg);
	}

    if(can_mod_req!=can_mod_req_backup)
	{
		can_mod_req_backup = can_mod_req;
		arg[7] = can_mod_req;
		/*
		if(can_mod_req == E_MOD_ON)
		{
			arg[3] = 2;//active
		}
		else if(can_mod_req == E_MOD_OFF)
		{
			arg[3] = 1;//deactive
		}
		*/
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_SET_STATUS, 11, arg);
	}

	if(bReqToSendDynamicReqSignal)
	{
		bReqToSendDynamicReqSignal = FALSE;
		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_SET_STATUS, 4, arg);
	}
}

void can_FactoryModeReq_rxhandler()
{
	static U8 can_calibration_req=0;
	static U8 can_calibration_backup=0;	
	static U8 arg[3];
	
	can_calibration_req = can_receive_sig(AVSViewModeReq);

	if(can_calibration_req != can_calibration_backup)
	{
		can_calibration_backup = can_calibration_req;

		if(can_calibration_req == CAN_FACTROY_MODE)
		{
			arg[0] = CAN_SOFTKEY_TYPE;
			arg[1] = CAN_CALIBRATION_TYPE;
			arg[2] = 0x01;
			SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
		}
	}
}

void can_SetLanguage_rxhandler()
{
	static U8 uSetLanguage = 0;
	static U8 uSetLanguage_backup = 0;
	U8 uCanRecLanguage = 0;
	
	switch(can_receive_sig(LanguageSet))
	{
		case Inactive: break;
		case Can_Simplified_Chinese: uSetLanguage = SPI_Chinese; break;
		case Can_Traditional_Chinese: break;
		case Can_English: uSetLanguage = SPI_English; break;
		case Can_French: break;
		case Can_Arabic: break;
		case Can_Russian: break;
		default: break;
	}
	
	if(uSetLanguage!= uSetLanguage_backup)
	{
		uSetLanguage_backup = uSetLanguage;			
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_LANGIAGE_SET,1,&uSetLanguage); //442A
	}
	
	if(bReqToSendLanguageSetReqSignal)
	{
		bReqToSendLanguageSetReqSignal = FALSE;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_LANGIAGE_SET,1,&uSetLanguage_backup); //442A
	}	
}

void can_turnlamp_rxhandler(void)
{
	static U8 can_rx_turnlamp_status = CAN_TURNLAMP_MAX_DATA;
	static U8 uRightTurnLamp = 0;
	static U8 uHazardTurnLamp = 0;
	static U8 uLeftTurnLamp = 0;
	static U8 turnLampStatus_backup = 0;
    static U8 HazardTurnLampStatus_backup = 0;
	static U8 can_turnlamp_count =0;
	
	uRightTurnLamp = can_receive_sig(TurningSt_right);
	uLeftTurnLamp = can_receive_sig(TurningSt_Left); 
	uHazardTurnLamp = can_receive_sig(HazardWarningSt);

    if((!uRightTurnLamp)&&(uLeftTurnLamp))
	{
	   can_rx_turnlamp_status = CAN_TURNLAMP_LEFT;
	   can_turnlamp_count = 0;
	}
    else if((uRightTurnLamp)&&(!uLeftTurnLamp))
	{
	   can_rx_turnlamp_status = CAN_TURNLAMP_RIGHT;
	   can_turnlamp_count = 0;
	}
	else
	{
	    can_turnlamp_count++;
        if(38 == can_turnlamp_count)  //Synchronous LG steering reversal filtering time
        {
            can_rx_turnlamp_status = CAN_TURNLAM_OFF;
            can_turnlamp_count = 0;
        }
	}

	if((can_rx_turnlamp_status<CAN_TURNLAMP_MAX_DATA)&&(can_rx_turnlamp_status != turnLampStatus_backup))
	{
		turnLampStatus_backup = can_rx_turnlamp_status;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_TURNING_SIGNAL,1,&can_rx_turnlamp_status);
	}
	
	if(uHazardTurnLamp != HazardTurnLampStatus_backup)
	{
	   HazardTurnLampStatus_backup = uHazardTurnLamp;
	   SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_HAZARD_TURNING_SIGNAL,1,&uHazardTurnLamp);
	}

	if(bReqToSendTurnSignal)
	{
		bReqToSendTurnSignal = FALSE;
		if(can_rx_turnlamp_status < CAN_TURNLAMP_MAX_DATA)
		{
			SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_TURNING_SIGNAL,1,&can_rx_turnlamp_status);
		}
		 SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_HAZARD_TURNING_SIGNAL,1,&uHazardTurnLamp);
	}
}

void can_avm_act_req_rxhandler(void)
{
	can_AVS_switch_rxhandler();
	can_avm_hu_req_exit_rxhandler();
	can_avm_enter_exit_speech_rxhandler();

	apscan_ESC_FrontWheelSpeedsKPH();
	apscan_ESC_WheelSpeedsRC();
	can_avm_enter_exit_rxhandler();
}

void can_avm_hu_req_exit_rxhandler(void)
{
	U8 arg[3];
	static U8 can_softkey_req=0;
	static U8 can_softkey_req_backup=0;
	can_softkey_req = can_receive_sig(AVSFunctionExitReq);        
	
	if(can_softkey_req!=can_softkey_req_backup)
	{
		can_softkey_req_backup = can_softkey_req;
		if(can_softkey_req)
		{
			arg[0] = CAN_SOFTKEY_TYPE;
			arg[1] = AVM_ENTER_EXIT_SWITCH;
			arg[2] = 0x02;//AVM Exit Request
			SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
		}
	}
}

void can_avm_enter_exit_speech_rxhandler(void)
{
	U8 arg[3];
	static U8 can_speech_req=0;
	static U8 can_speech_req_backup=0;	
	static U8 power_on = 0x01;
	can_speech_req = can_receive_sig(HU_SpeechReq_AVS); 

	if(can_speech_req == 0x01)  //AVM Speech off      
	{
		can_speech_req = AVM_EXIT_REQUEST;
	}
	else if(can_speech_req == 0x02)  //AVM Speech on
	{
		can_speech_req = AVM_ENTER_REQUEST; 
	}
	
	if(can_speech_req!=can_speech_req_backup)
	{
		can_speech_req_backup = can_speech_req;

		if(can_speech_req == AVM_EXIT_REQUEST)
		{
			AVM_Speech_Req = AVM_EXIT_REQUEST;
		}
		else if(can_speech_req == AVM_ENTER_REQUEST)
		{
			AVM_Speech_Req = AVM_ENTER_REQUEST;
		}
		
		arg[0] = CAN_SOFTKEY_TYPE;
		arg[1] = AVM_ENTER_EXIT_SWITCH;
		arg[2] = can_speech_req;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
	}
	
 	if((bReqToSendSpeechReqSignal) && (power_on))
	{
		power_on = 0x00;
		bReqToSendSpeechReqSignal = FALSE;
		arg[0] = CAN_SOFTKEY_TYPE;
		arg[1] = AVM_ENTER_EXIT_SWITCH;
		arg[2] = can_speech_req;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
	}	
}

void can_avm_enter_exit_rxhandler(void)
{
	U8 arg[3];
	static U8 can_AVSFun_req=0;
	static U8 can_AVSFun_req_backup=0;	
	
	can_AVSFun_req = can_receive_sig(AVSFunctionReq); 

	if(can_AVSFun_req == 0x01)  //AVM Speech off      
	{
		can_AVSFun_req = AVM_EXIT_REQUEST;
	}
	else if(can_AVSFun_req == 0x02)  //AVM Speech on
	{
		can_AVSFun_req = AVM_ENTER_REQUEST; 
	}
	
	if(can_AVSFun_req!=can_AVSFun_req_backup)
	{
		can_AVSFun_req_backup = can_AVSFun_req;
		
		arg[0] = CAN_SOFTKEY_TYPE;
		arg[1] = AVM_ENTER_EXIT_SWITCH;
		arg[2] = can_AVSFun_req;
		SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
	}
}


void can_AVS_switch_rxhandler(void)
{
	U8 AVS_switch_Sta = 0;
	static BOOL switch_pending_flag = FALSE;
	U8 arg[3];
	
	AVS_switch_Sta = can_receive_sig(MCP_AVSandFRadarSwitch);

	if(AVS_switch_Sta)
	{
		if(!switch_pending_flag)
		{
			switch_pending_flag = TRUE;
			arg[0] = CAN_HARDKEY_TYPE;
			arg[1] = 0x0;
			arg[2] = 0x0;
			SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
		}
	}
	else
	{
		switch_pending_flag = FALSE;
	}
}

typedef struct
{
	U8 second;
	U8 minute;
	U8 hour;
	U8 day;
	U8 month;
	U8 year;
}DATE_TIME_DEF;

DATE_TIME_DEF can_dvd_datetime;
DATE_TIME_DEF can_dvd_datetime_backup = {0,0,0,0,0,0,};

void can_datetime_rxhandler(void)
{
	U8 arg[6];

	can_dvd_datetime.year = can_receive_sig(GPSTime_Year);
	can_dvd_datetime.month = can_receive_sig(GPSTime_Month);
	can_dvd_datetime.day = can_receive_sig(GPSTime_Day);
	can_dvd_datetime.hour = can_receive_sig(GPSTime_Hour);
	can_dvd_datetime.minute = can_receive_sig(GPSTime_Minute);
	can_dvd_datetime.second = can_receive_sig(GPSTime_Second);
	if((bReqToSendSystemDate==TRUE)&&((can_dvd_datetime.year!=can_dvd_datetime_backup.year)||(can_dvd_datetime.month!=can_dvd_datetime_backup.month)||(can_dvd_datetime.day!=can_dvd_datetime_backup.day)
		||(can_dvd_datetime.hour!=can_dvd_datetime_backup.hour)||(can_dvd_datetime.minute!=can_dvd_datetime_backup.minute)||(can_dvd_datetime.second!=can_dvd_datetime_backup.second)))
	{	
		arg[0]=can_dvd_datetime.second;
		arg[1]=can_dvd_datetime.minute;
		arg[2]=can_dvd_datetime.hour;
		arg[3]=can_dvd_datetime.day + 1;
		arg[4]=can_dvd_datetime.month + 1;
		arg[5]=can_dvd_datetime.year;		
		SocManager_SendMsg(LQ_CMD,TYPE_EVENT,RADIO_NOTIFY_CURRENT_DATE_TIME,6,arg);
		_memcpy(&can_dvd_datetime_backup,&can_dvd_datetime,6);
		bReqToSendSystemDate = FALSE;
	}

}


extern APS_MODULE_STATUS GetAPSCurrentStatus(void);

void CanApp_ReportDeviceDtc(U8 camerafault,U8 ledfault,U8 bsdfault)
{

}
void CanApp_ReportDeviceDtcToCpu(U16 fault)
{        
        uDeviceFault[0] = fault>>8;
        uDeviceFault[1] = fault&0xff;
		if(EolUpdateFlag == FALSE)
		{
			SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_ALERT_INFO, 2, uDeviceFault);
		}
}

void CanAppGetEngStatus(U8* data)
{

}

/**************************************************************************************************/

U8 Soc_AVM_FACTORY_MODE[2];
BOOL Get_Soc_AVM_FACTORY_MODE(void)
{
	if((Soc_AVM_FACTORY_MODE[0]==AVM_FACTORY_MODE) && (Soc_AVM_FACTORY_MODE[1]==FACTOR_MODE))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void can_AVSErrorSt_txhandler(void)
{
	 static U8 Dtc_AVM_Error_Sta = 0;
	 static U8 Dtc_AVM_Error_Sta_Backup = 0;
	 Dtc_AVM_Error_Sta = dtc_status_record[DTC_AVM_SYSTEM_ERROR].dtc_status.status_bits.testFailed;
	 if(Dtc_AVM_Error_Sta != Dtc_AVM_Error_Sta_Backup)
	 {
	 	Dtc_AVM_Error_Sta_Backup = Dtc_AVM_Error_Sta;
		if(Dtc_AVM_Error_Sta)
		{
			can_send_sig(AVSErrorSt,0x01);
		}
		else
		{
			can_send_sig(AVSErrorSt,0x00);
		}
	 }
}

/******************************************************************************
* Name:    can_AVSErrorSt_txhandler 
*
* Desc:    
* Param:   
* Return:  
* Global:  
* Note:    
* Author:  uidq3099_colin
* -------------------------------------
* Log:    2021/08/06, Create this function by uidq3099_colin
 ******************************************************************************/
void can_PDCAutoOnFun_txhandler(void)
{
	 U8 PDCAutoOnFun = 0;
	 U8 arg[11] ={0x00};

	 static U8 PDCAutoOnFun_Backup = 0;
//	U8 VehicleSpeed[2];
//	canGear = can_receive_sig(TCU_LeverInfo);


//	CanAppGetSpeed(&VehicleSpeed);	
//	if((((VehicleSpeed[0]*0x100+VehicleSpeed[1]) < 0x10)) && (canGear == GEAR_D))   // Speed must be smaller than 10 km/h
//	{

//	if
//	}

	 PDCAutoOnFun = can_receive_sig(HU_PDCAutoOnFunctionReq);
	   
	 if(PDCAutoOnFun != PDCAutoOnFun_Backup)
	 {
	 	PDCAutoOnFun_Backup = PDCAutoOnFun;
		/*if(PDCAutoOnFun == 0x01)
		{
			can_send_sig(PDCAutoOnFunctionInd,0x00);
		}
		else if(PDCAutoOnFun == 0x02)
		{
			can_send_sig(PDCAutoOnFunctionInd,0x01);
		}
		*/
		arg[10] = PDCAutoOnFun;

		SocManager_SendMsg(TX_HQ,TYPE_EVENT, RADIO_NOTIFY_SET_STATUS, 11, arg);
	 }
}


void can_CameraErrorSt_txhandler(void)
{

	U8 Index;
	static U8 camera_error_st[4];
	static U8 camera_error_st_backup[4];

	if((dtc_status_record[DTC_FRONT_CAMERA_OPEN_CIRCUIT].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_FRONT_CAMERA_SHORT_GND].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_FRONT_CAMERA_SHORT_BAT].dtc_status.status_bits.testFailed))
	{
		camera_error_st[FRONT_CAMERA_INDEX] = TRUE;
	}
	else
	{
		camera_error_st[FRONT_CAMERA_INDEX] = FALSE;
	}

	if((dtc_status_record[DTC_LEFT_CAMERA_OPEN_CIRCUIT].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_LEFT_CAMERA_SHORT_GND].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_LEFT_CAMERA_SHORT_BAT].dtc_status.status_bits.testFailed))
	{
		camera_error_st[LEFT_CAMERA_INDEX] = TRUE;
	}
	else
	{
		camera_error_st[LEFT_CAMERA_INDEX] = FALSE;
	}

	if((dtc_status_record[DTC_BACK_CAMERA_OPEN_CIRCUIT].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_BACK_CAMERA_SHORT_GND].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_BACK_CAMERA_SHORT_BAT].dtc_status.status_bits.testFailed))
	{
		camera_error_st[REAR_CAMERA_INDEX] = TRUE;
	}
	else
	{
		camera_error_st[REAR_CAMERA_INDEX] = FALSE;
	}

	if((dtc_status_record[DTC_RIGHT_CAMERA_OPEN_CIRCUIT].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_RIGHT_CAMERA_SHORT_GND].dtc_status.status_bits.testFailed)||
		(dtc_status_record[DTC_RIGHT_CAMERA_SHORT_BAT].dtc_status.status_bits.testFailed))
	{
		camera_error_st[RIGHT_CAMERA_INDEX] = TRUE;
	}
	else
	{
		camera_error_st[RIGHT_CAMERA_INDEX] = FALSE;
	}	
	
	for(Index = 0;Index < CAMERA_INDEX_MAX;Index++)
	{
		if(camera_error_st[Index] != camera_error_st_backup[Index])	
		{															
			camera_error_st_backup[Index] = camera_error_st[Index];

			if(camera_error_st[Index])
			{
				if(Index == FRONT_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Front,0x01); //Error
				if(Index == LEFT_CAMERA_INDEX)  can_send_sig(AVSCameraErrorSt_Left, 0x01);	
				if(Index == REAR_CAMERA_INDEX)  can_send_sig(AVSCameraErrorSt_Rear, 0x01);
				if(Index == RIGHT_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Right,0x01);
			}
			else
			{	
				if(Index == FRONT_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Front,0x00); //No Error
				if(Index == LEFT_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Left, 0x00);	
				if(Index == REAR_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Rear, 0x00);
				if(Index == RIGHT_CAMERA_INDEX) can_send_sig(AVSCameraErrorSt_Right,0x00);				
			}
		}
	}
}

void Can_ModWarning_txhandler(void)
{
    static U8 ModWarning_back = 0;
    if(ModWarning != ModWarning_back)
    {
        ModWarning_back = ModWarning;
        if(ModWarning == 0x1)
        {
            can_send_sig(MODWarning_Front, 0x1);        //warning
            can_send_sig(MODWarning_Rear, 0x0);         //no warning
        }
        else if(ModWarning == 0x2)                    
        {
            can_send_sig(MODWarning_Front, 0x0);        //no warning
            can_send_sig(MODWarning_Rear, 0x1);         //warning
        }
        else
        {
            can_send_sig(MODWarning_Front, 0x0);        //no warning
            can_send_sig(MODWarning_Rear, 0x0);         //no warning
        }
    }
}

void Can_PDWarning_txhandler(void)
{
    static U8 pdWarning_back = 0;
    if(PdWarning != pdWarning_back)
    {
        pdWarning_back = PdWarning;
        if(PdWarning == 0x1)
        {
            can_send_sig(AVS_PDWarning_Front, 0x1);        //warning
            can_send_sig(AVS_PDWarning_Rear, 0x0);         //no warning
        }
        else if(PdWarning == 0x2)                    
        {
            can_send_sig(AVS_PDWarning_Front, 0x0);        //no warning
            can_send_sig(AVS_PDWarning_Rear, 0x1);         //warning
        }
        else
        {
            can_send_sig(AVS_PDWarning_Front, 0x0);        //no warning
            can_send_sig(AVS_PDWarning_Rear, 0x0);         //no warning
        }
    }
}

void can_OTAMode_rxhandler(void)
{
	U8 mode = 0;
	static U8 mode_bk = 0;

	mode = can_receive_sig(GW_OTAMode);

	if(mode != mode_bk)
	{
		mode_bk = mode;
		GW_OTAMode_fun = mode;
	}
}


void can_AVSCalibrationStatus_txhandler(void)
{
	if(ManualcalibProcess == 0x01)
	{
		can_send_sig(AVS_CalibrationSt,CALIBRATING);
	}
	else 
	{
		if((EED_Calibration == 1))
	    {
			can_send_sig(AVS_CalibrationSt,CALIBRATED);
		}
		else
		{
			can_send_sig(AVS_CalibrationSt,NOT_CALIBRATED);
		}
	}
}


U8 SocSetModStatus = 0;
U8 SocSetBlindpaddingStatus = 0;
U8 Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS;
U8 AVM_Ctl_PDC_Req = SK_EXIT;
extern U8 StartCalibrationResult;
extern U8 SCalibrationResult;
extern U8 SEnterCalibrationResult;
extern U8 Calibration_enterSuccess;
void CanApp_recvnavimsg_handler(U16 commandid, U8* data)
{  
	U8 AVM_TurnOn_flag = 0;
    switch (commandid)
    {
        case CPU_NOTIFY_M3_AVM_DISPLAY_STATUS : //4410
        	switch(data[0])
    		{

				case AVM_CONTROL_REQ: //00
			
				if(1 == data[1] || 2 == data[1] || 5 == data[1])
                {
					can_send_sig(AVSSt,SK_OPEN_AVM);
					uAVSSt = 1;
					if(AVM_Speech_Req == AVM_ENTER_REQUEST)
					{
						AVM_Speech_Req = 0;
						can_send_sig(AVS_SpeechControlFeedback,0x03); //On Success
						can_send_sig(PDC_SpeechControlFeedback,0x03); //On Success
					}						
					AVM_Ctl_PDC_Req = SK_OPEN_AVM;
					can_send_sig(SwitchScreenRequest_AVS,0x01);//AVS Enter Request


                }
                else if(3 == data[1] || 4 == data[1] || 0 == data[1])
                {
					can_send_sig(AVSSt,SK_EXIT);
					uAVSSt = 0;
					if(AVM_Speech_Req == AVM_EXIT_REQUEST)
					{
						AVM_Speech_Req = 0;
						can_send_sig(AVS_SpeechControlFeedback,0x01); //Off Success
						can_send_sig(PDC_SpeechControlFeedback,0x01); //Off Success
					}						
					AVM_Ctl_PDC_Req = SK_EXIT;					
					Request_Enter_AVM_Once = FALSE;
					can_send_sig(SwitchScreenRequest_AVS,0x02);//AVS Exit Request


                }				
				break;

				
    			case AVM_SOFTKEY_RESP:
					if (data[1]==0)
					{
						can_send_sig(AVSSt,SK_OPEN_AVM);
						uAVSSt = 1;
						if(AVM_Speech_Req == AVM_ENTER_REQUEST)
						{
							AVM_Speech_Req = 0;
							can_send_sig(AVS_SpeechControlFeedback,0x03); //On Success
							can_send_sig(PDC_SpeechControlFeedback,0x03); //On Success
						}						
						AVM_Ctl_PDC_Req = SK_OPEN_AVM;
						can_send_sig(SwitchScreenRequest_AVS,0x01);//AVS Enter Request
					}
					else if(data[1]==1)
					{
						can_send_sig(AVSSt,SK_EXIT);
						uAVSSt = 0;
						if(AVM_Speech_Req == AVM_EXIT_REQUEST)
						{
							AVM_Speech_Req = 0;
							can_send_sig(AVS_SpeechControlFeedback,0x01); //Off Success
							can_send_sig(PDC_SpeechControlFeedback,0x01); //Off Success
						}						
						AVM_Ctl_PDC_Req = SK_EXIT;
						Request_Enter_AVM_Once = FALSE;
						can_send_sig(SwitchScreenRequest_AVS,0x02);//AVS Exit Request
					}
					break;	
				case AVM_FACTORY_MODE:
					if (data[1]==1)
					{
						//can_send_sig(AVSWorkingMode,SK_UPDATE_AVM); 
					}

					
					break;	
				default:
					break;
    		}
        	break;    
    	case SOC_REQ_SOFT_VERSION: //4201
            if(data[0] == MCU_VERSION_NUMBER)
			{
				bJ6RequestM3Version = TRUE;
			}
			else if(data[0] == USS_VERSION_NUMBER)
			{
				bJ6RequestUSSVersion = TRUE;
			}
			else if(data[0] == ALG_VERSION_NUMBER)
			{
				bJ6RequestALGVersion = TRUE;
			}
            bJ6RequestUssVersionNumber_SS=TRUE;
			bJ6RequestUssVersionNumber_OD=TRUE;
			break;
			
    	case SOC_REQ_RESEND_IMPORTANT_MESSAGE://4202
			bReqToSendSteerWheelAngleSignal = TRUE;
			bReqToSendLeverInfoSignal = TRUE;
			bReqToSendIGNstatus = TRUE;
			//bReqToSendViewModeReqSignal = TRUE;
			//bReqToSendDynamicReqSignal = TRUE;
			bReqToSendLanguageSetReqSignal = TRUE;
			//bReqToSendTurnSignal = TRUE;
			bReqToSendSpeechReqSignal = TRUE;
			bReqToSendSpeedSignal = TRUE;
			bReqToSenddoortatus = TRUE;
			bReqToSendRearviewMirrorSt = TRUE;
			bReqToSendVehicleStandsitllSts = TRUE;			
        	bReqToSendSystemDate = TRUE;

			SVP_SUCCEED_FLAG = TRUE;
			bReqReportcamerafault = TRUE;
			bJ6_start_complete = TRUE;
			bReqToSendRadarlevels=TRUE;
			bOpenWatchDog = TRUE;
			updatePdcStatusToAvm();
			
            /* Enable SOC heart beat detection */
            SocManager_HeartBeatUpdate(TRUE);

            if(0xA5 == EED_DEBUG_MmiTouchDebugFlag)  //default: 0xA5 
			{
				MmiTouchDebugFlag = 0;
			}
			else 
			{
				MmiTouchDebugFlag = EED_DEBUG_MmiTouchDebugFlag;
			}
        	break;

		case CPU_NOTIFY_M3_AVM_SETTING_RESULT://4411 
			uAVSCarModelColor = data[0];

			if(data[1] == 0x00)  //Chinsese
			{
				can_send_sig(LanguageTypeSt_AVS,0x00); 
			}else if(data[1] == 0x01){ //English
				can_send_sig(LanguageTypeSt_AVS,0x02); 
			}
		
			if(data[2] == 0x00)  //Off
			{
				can_send_sig(DynamicPGSSt_AVS,0x00);  
			}else if(data[2] == 0x01)  //On
			{
				can_send_sig(DynamicPGSSt_AVS,0x01); 
			}

			if(data[5]==0x00)
			{
				can_send_sig(MODSt_AVS,0x00);   //Off
			}
			else if(data[5]==0x01)
			{
				can_send_sig(MODSt_AVS,0x01);   //On
			}

			if(data[8] <= 0x01)
			{
			can_send_sig(PDCAutoOnFunctionInd,data[8]);
			}

        	break;		
			
		case CPU_NOTIFY_M3_OnRoadCalib_STATUS: //441F
			Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS = data[0];
			break;

		case CPU_NOTIFY_M3_PCS_SingleViewInd : //442D
			if(data[0] == 0x08){
				uAVSViewMode = CAN_SCREEN_DRAGGED_3D_VIEW;  //SPI VALUE->CAN VALUE
			}
			else if(data[0] == 0x0E){
				uAVSViewMode = CAN_FACTROY_MODE;
			}
			else{
				uAVSViewMode = data[0];
			}
			can_send_sig(AVSViewMode,uAVSViewMode);
    		break;
				
		case CPU_NOTIFY_M3_DVR_COMMAND_LIST_RESP: //4430

			break;
			
		case CPU_NOTIFY_M3_CALIBRATION_SUCCESS://4433
			ManualcalibProcess = 0x02;
			SCalibrationResult = data[0];
			StartCalibrationResult = 0x1;
			EED_LockDataBlock(EED_nEOLConfig);
			EED_Calibration = data[0];
			EED_u8SocCalibrationDoneFlag = data[0];
			EED_UnlockAndSavDataBlock(EED_nEOLConfig);	
			uAVSCalibrationSta= data[0];
			/* Clear all DTC after successful calibration */
			if(EED_Calibration == 1)
			{
				ClearDiagDtcData();
			}
			break;

		case CPU_NOTIFY_MMI_Beep://4435
			break;

		case RADIO_SYNC_TIME_TO_APP://443C
			bReqToSendSystemDate = TRUE;
			break;
		
		case SOC_NOTIFY_MCU_BLINDPADDING_STATUS://4443
			if(data[0] == 0x00)
			{
				SocSetBlindpaddingStatus = FALSE;
			}
			else if(data[0] == 0x01)
			{
				SocSetBlindpaddingStatus = TRUE;
			}
			break;

		case SOC_NOTIFY_MCU_ENTER_CALIBRATION_STATUS_RESULT://44F1
			SEnterCalibrationResult = 1;
			if(data[0] == 0)//enter calibration mode succefully
			{
				Calibration_enterSuccess = 0x01;
			}
			else if(data[0] == 0x01)
			{
				Calibration_enterSuccess = 0x00;
			}
			break;
			
		case SOC_NOTIFY_MCU_CALIBRATION_RESULT://44F3
			if(data[0] == 0)//enter calibration mode succefully
			{
				SCalibrationResult = 0x01;
			}
			else if(data[0] == 0x01)
			{
				SCalibrationResult = 0x00;
			}
			ManualcalibProcess = 0x02;
			EED_LockDataBlock(EED_nEOLConfig);
			EED_Calibration = SCalibrationResult;
			EED_UnlockAndSavDataBlock(EED_nEOLConfig);	
			
				break;

		case CPU_NOTIFY_RESULT_OF_CELIBRATION://44F4
			EED_LockDataBlock(EED_nDiagCalibrationReason);
			_memcpy(EED_Clibration_FailReason,data,4);
			EED_UnlockAndSavDataBlock(EED_nDiagCalibrationReason);
			break;
					
		case SOC_NOTIFY_AVM_SYNCCELIBRATION_RESULT: //44F7
			EED_LockDataBlock(EED_nEOLConfig);
			EED_Calibration = data[0];
			EED_UnlockAndSavDataBlock(EED_nEOLConfig);	
			break;
		
		case SOC_SET_MCU_CAN_DEBUG_MESSAGE://44E9
			if(data[0] == 0x00)
			{
				MmiTouchDebugFlag = FALSE;
			}
			else
			{
				MmiTouchDebugFlag = data[0];
			}
			EED_LockDataBlock(EED_nEOLConfig);
			EED_DEBUG_MmiTouchDebugFlag = MmiTouchDebugFlag;
			EED_UnlockAndSavDataBlock(EED_nEOLConfig);
        break;

        case SOC_NOTIFY_MCU_MOD_STATUS:    //4453
        	if(data[0] == 0x00) //mod
        	{
            	ModWarning = data[1];
        	}
			else if(data[0] == 0x01) //pd
			{
				PdWarning = data[1];

			}
			break;

		case SOC_NOTIFY_ETH_STATUS:  //8311
			ETH_status = data[0];
			break;
		
        default:
			break;
    }
}	

void Doip_recvnavimsg_handler(U16 commandid, U8* data)
{  
	U8 doipdata[256] = {0x00};
	U8 buf[256] = {0x00};
	U32 diag_cmd=0x00;
	U8 RET = ERR_FAULT;

    switch (commandid)
    {
        case DOIP_DIAG_REQ_CMD : //0205

//			_memcpy(&doip_frame,&data[0],DOIP_DATALEN);
			_memcpy(&buf[0], &data[0], DOIP_DATALEN);

		    doip_frame.sourceid = ((U16)data[SOURCEID_INDEX] << 8) | (U16)data[SOURCEID_INDEX + 1];
			doip_frame.targetid = ((U16)data[TARGETID_INDEX] << 8) | (U16)data[TARGETID_INDEX + 1];
			doip_frame.cmdtype  = ((U16)data[CMDTYPE_INDEX] << 8) | (U16)data[CMDTYPE_INDEX + 1];
			doip_frame.sn = data[SN_INDEX];
			doip_frame.datalenth = ((U16)data[DATALENTH_INDEX] << 8) | (U16)data[DATALENTH_INDEX + 1];
				
			buf[SOURCEID_INDEX] = (doip_frame.targetid>>8) & 0xFF;
			buf[SOURCEID_INDEX + 1] = doip_frame.targetid & 0xFF;
			buf[TARGETID_INDEX] = (doip_frame.sourceid>>8) & 0xFF;
			buf[TARGETID_INDEX + 1] = doip_frame.sourceid & 0xFF;
			if(doip_frame.datalenth <= 256)
			{
			_memcpy(doipdata,&data[DATA_INDEX],doip_frame.datalenth);
			}
        	switch(doipdata[0])
    		{
	    		case ClearDiagnosticInformation: //service 14
					diag_cmd = (U32)doipdata[1] << 16 | (U32)doipdata[2] << 8 | (U32)doipdata[3];
					if(diag_cmd == DTC_GRP_ALL)
					{
					CanDiagDtc_desc_delay_set_sig(DESC_DELAY_SIG_1);
					CanDiagDtc_sv14_clear_start();
					buf[DATA_INDEX] = 0x54;
					_memcpy(&buf[DATA_INDEX +1], &doipdata[1], (doip_frame.datalenth -1));
		            SocManager_SendMsg(TX_HQ,TYPE_EVENT, DOIP_DIAG_RES_CMD, (doip_frame.datalenth + DOIP_DATALEN), buf);
					}
				
				break;

				case WriteDataByIdentifier: //service 2E
					diag_cmd = (U32)doipdata[1] << 8 | (U32)doipdata[2];
					switch(diag_cmd)
					{
						case 0xF198:
						RET = FDLDriver_Write(F198_STORE_ADDRESS,&doipdata[3],4);
				        if(ERR_OK != RET)
				        {
				            /* Write Error, need retry! */
				            EepWriteControl.uEepRetryAddr = F198_STORE_ADDRESS;
				            EepWriteControl.uEepRetryWordNum = 4;
				            EepWriteControl.uEepRetryByte = 10;
				            DescStartRepeatedServiceCall(&SOC_EEP_RewriteHandler);
				        }	
						else
				        {
				        	buf[DATA_INDEX] = 0x6E;
							_memcpy(&buf[DATA_INDEX +1], &doipdata[1], (doip_frame.datalenth -1));
				            SocManager_SendMsg(TX_HQ,TYPE_EVENT, DOIP_DIAG_RES_CMD, (doip_frame.datalenth + DOIP_DATALEN), buf);
				        }
						break;
						
						case 0xF199:
						RET = FDLDriver_Write(F199_STORE_ADDRESS,&doipdata[3],1);
				        if(ERR_OK != RET)
				        {
				            /* Write Error, need retry! */
				            EepWriteControl.uEepRetryAddr = F199_STORE_ADDRESS;
				            EepWriteControl.uEepRetryWordNum = 1;
				            EepWriteControl.uEepRetryByte = 4;
				            DescStartRepeatedServiceCall(&SOC_EEP_RewriteHandler);
				        }	
						else
				        {
				        	buf[DATA_INDEX] = 0x6E;
							_memcpy(&buf[DATA_INDEX +1], &doipdata[1], (doip_frame.datalenth -1));
				            SocManager_SendMsg(TX_HQ,TYPE_EVENT, DOIP_DIAG_RES_CMD, (doip_frame.datalenth + DOIP_DATALEN), buf);
				        }
						break;

						default:break;

					}

					
				break;
					
				case CommunicationControl: //service 28
					if(((doipdata[1]& 0x0F)== 0x00))
					{
						DescEnableCommunication();
					}
					else if(((doipdata[1]& 0x0F) == 0x03))
					{
						DescDisableCommunication();
					}
				break;

				case ControlDTCSetting: //service 85

					if(((doipdata[1]& 0x0F) == 0x01))
					{
						can_diag_control_dtc_setting_on();
					}
					else if(((doipdata[1]& 0x0F) == 0x02))
					{
						can_diag_control_dtc_setting_off();
					}
					
				break;

				
				


				
				default:
				break;
    		
        	}
			break;
			
		default:
				break;
    }
}


U8 GetMmiTouchDebugFlag(void)
{	
	return MmiTouchDebugFlag;
}

U8 GetModStatus(void)
{
	return SocSetModStatus;
}

U8 GetBlindPaddingStatus(void)
{
	return SocSetBlindpaddingStatus;
}

BOOL Get_Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS(void)
{
	if(Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS==0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;//FALSE;
	}
}

void CanAppGetSpeed(U8* data)
{
   data[0] = can_vehiclespeed_backup >>8 ;
   data[1] = can_vehiclespeed_backup &0xFF; 	 
}

vuint8 Way_Point_Info_2_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ¡­XOR byteN-1, N = message length
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//	CalcuChecksum = c2_Way_Point_Info_2_c^ \
//					c3_Way_Point_Info_2_c^ \
//					c4_Way_Point_Info_2_c^ \
//					c5_Way_Point_Info_2_c^ \
//					c6_Way_Point_Info_2_c^ \
//					c7_Way_Point_Info_2_c^ \
//					c8_Way_Point_Info_2_c;
/*2021/07/09, DBC change/remove, resulting in no this signal*/
//	can_send_sig(Checksum_WPI2,CalcuChecksum); 	
}

vuint8 Way_Point_Info_1_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ¡­XOR byteN-1, N = message length
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//	CalcuChecksum = c2_Way_Point_Info_1_c^ \
//					c3_Way_Point_Info_1_c^ \
//					c4_Way_Point_Info_1_c^ \
//					c5_Way_Point_Info_1_c^ \
//					c6_Way_Point_Info_1_c^ \
//					c7_Way_Point_Info_1_c^ \
//					c8_Way_Point_Info_1_c;
/*2021/07/09, DBC change/remove, resulting in no this signal*/
//	can_send_sig(Checksum_WPI1,CalcuChecksum); 	
}

void ApplGetRxBrake_Apply_Information_CEMsg(Appl_Brake_Apply_Information_CE_msgType* getVehInfo)
{
/*
	U8 InfoValue[2];
	S8 vehbrkpdlposgrad = 0;
	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlPos, (U8*)InfoValue, 1);
	getVehInfo->BrkPdlPos = (float)((InfoValue[0]&0xFF)*0.392157);

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlPosGrad, (U8*)&vehbrkpdlposgrad, 1);
	getVehInfo->BrkPdlPosGrad = (S16)(vehbrkpdlposgrad*40);

	CanSig_CANGetValue(RX_SIG_GET_ID_WhlRotStatTmstmpRes, (U8*)InfoValue, 2);
	getVehInfo->WhlRotStatTmstmpRes = (float)((((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF))*0.002);

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdDrvAPrsStaPVal, (U8*)InfoValue, 2);
	getVehInfo->BrkPdDrvAPrsStaPVal = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdDrvAppPrsAlRC, (U8*)InfoValue, 1);
	getVehInfo->BrkPdDrvAppPrsAlRC = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_ABSAtv, (U8*)InfoValue, 1);
	getVehInfo->ABSAtv = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_ABSFld, (U8*)InfoValue, 1);
	getVehInfo->ABSFld = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlModTrvl, (U8*)InfoValue, 1);
	getVehInfo->BrkPdlModTrvl = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlModTrvlV, (U8*)InfoValue, 1);
	getVehInfo->BrkPdlModTrvlV = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkAppSnsrHmPosLrnd, (U8*)InfoValue, 1);
	getVehInfo->BrkAppSnsrHmPosLrnd = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BPDAPS_BkPDrvApPV, (U8*)InfoValue, 1);
	getVehInfo->BPDAPS_BkPDrvApPV = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BPDAPS_BkPDrvApP, (U8*)InfoValue, 1);
	getVehInfo->BPDAPS_BkPDrvApP = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_PrplsnSysAtv, (U8*)InfoValue, 1);
	getVehInfo->PrplsnSysAtv = InfoValue[0]&0xFF;

	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPedPosAlvRolngCnt, (U8*)InfoValue, 1);
	getVehInfo->BrkPedPosAlvRolngCnt = InfoValue[0]&0xFF;
	*/
}

/***********************************************************************
* FUNCTION    : ApplGetRxAutomatic_Braking_Status_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxAutomatic_Braking_Status_CEMsg(Appl_Automatic_Braking_Status_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_VehMvngStat, (U8*)InfoValue[0], 1);
//	getVehInfo->VehMvngStat = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxDriven_Wheel_Grnd_Velocity_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxDriven_Wheel_Grnd_Velocity_CEMsg(Appl_Driven_Wheel_Grnd_Velocity_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyLftDrvn, (U8*)InfoValue, 2);
//	getVehInfo->WhlGrndVlctyLftDrvn = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyRtDrvn, (U8*)InfoValue, 2);
//	getVehInfo->WhlGrndVlctyRtDrvn = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));
}

/***********************************************************************
* FUNCTION    : ApplGetRxNonDriven_Wheel_Grnd_Velocity_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxNonDriven_Wheel_Grnd_Velocity_CEMsg(Appl_NonDriven_Wheel_Grnd_Velocity_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyLftNnDrvn, (U8*)InfoValue, 2);
//	getVehInfo->WhlGrndVlctyLftNnDrvn = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyRtNnDrvn, (U8*)InfoValue, 2);
//	getVehInfo->WhlGrndVlctyRtNnDrvn = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));
}

/***********************************************************************
* FUNCTION    : ApplGetRxPPEI_Chassis_General_Status_1_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxPPEI_Chassis_General_Status_1_CEMsg(Appl_PPEI_Chassis_General_Status_1_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	S16 VehYawRate = 0;
//	S16 VehLatAcc = 0;
//	CanSig_CANGetValue(RX_SIG_GET_ID_VehDynYawRate, (U8*)&VehYawRate, 2);
//	getVehInfo->VehDynYawRate = (float)(VehYawRate*0.0625);

//	CanSig_CANGetValue(RX_SIG_GET_ID_VSELatAcc, (U8*)&VehLatAcc, 2);
//	getVehInfo->VSELatAcc = (float)(VehLatAcc*0.015625);

//	CanSig_CANGetValue(RX_SIG_GET_ID_TCSysEnbld, (U8*)InfoValue, 1);
//	getVehInfo->TCSysEnbld = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TCSysAtv, (U8*)InfoValue, 1);
//	getVehInfo->TCSysAtv = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlDrvAppPrsDetcdV, (U8*)InfoValue, 1);
//	getVehInfo->BrkPdlDrvAppPrsDetcdV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_BrkPdlDrvAppPrsDetcd, (U8*)InfoValue, 1);
//	getVehInfo->BrkPdlDrvAppPrsDetcd = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_SprTireSt, (U8*)InfoValue, 1);
//	getVehInfo->SprTireSt = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_VehDynYawRateV, (U8*)InfoValue, 1);
//	getVehInfo->VehDynYawRateV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_VhDynCntlSysSt, (U8*)InfoValue, 1);
//	getVehInfo->VhDynCntlSysSt = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_VSELatAccV, (U8*)InfoValue, 1);
//	getVehInfo->VSELatAccV = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxPPEI_Vehicle_Speed_Status_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxPPEI_Vehicle_Speed_Status_CEMsg(Appl_PPEI_Vehicle_Speed_Status_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_VehSpdAvgDrvn, (U8*)InfoValue, 2);
//	getVehInfo->VehSpdAvgDrvn = (float)((((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF))*0.015625);

//	CanSig_CANGetValue(RX_SIG_GET_ID_VehSpdAvgDrvnV, (U8*)InfoValue, 1);
//	getVehInfo->VehSpdAvgDrvnV = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxNonDrivn_Whl_Rotationl_Stat_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxNonDrivn_Whl_Rotationl_Stat_CEMsg(Appl_NonDrivn_Whl_Rotationl_Stat_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_WRSLNDWhlDistPCntr, (U8*)InfoValue, 2);
//	getVehInfo->WRSLNDWhlDistPCntr = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_WRSRNDWhlDistPCntr, (U8*)InfoValue, 2);
//	getVehInfo->WRSRNDWhlDistPCntr = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));
}

/***********************************************************************
* FUNCTION    : ApplGetRxDriven_Whl_Rotational_Stat_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxDriven_Whl_Rotational_Stat_CEMsg(Appl_Driven_Whl_Rotational_Stat_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_WRSLDWhlDistPlsCntr, (U8*)InfoValue, 2);
//	getVehInfo->WRSLDWhlDistPlsCntr = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_WRSRDWhlDistPlsCntr, (U8*)InfoValue, 2);
//	getVehInfo->WRSRDWhlDistPlsCntr = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));
}

/***********************************************************************
* FUNCTION    : ApplGetRxPPEI_Steering_Wheel_Angle_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxPPEI_Steering_Wheel_Angle_CEMsg(Appl_PPEI_Steering_Wheel_Angle_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	S16 vehstrwhang = 0;
//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAng, (U8*)&vehstrwhang, 2);
//	getVehInfo->StrWhAng = (float)(vehstrwhang*0.0625);

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAngGrd, (U8*)InfoValue, 2);
//	getVehInfo->StrWhAngGrd = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrAngSnsChksm, (U8*)InfoValue, 2);
//	getVehInfo->StrAngSnsChksm = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAngMsk, (U8*)InfoValue, 1);
//	getVehInfo->StrWhAngMsk = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhlAngSenTyp, (U8*)InfoValue, 1);
//	getVehInfo->StrWhlAngSenTyp = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhlAngSenCalStat, (U8*)InfoValue, 1);
//	getVehInfo->StrWhlAngSenCalStat = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAngV, (U8*)InfoValue, 1);
//	getVehInfo->StrWhAngV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAngGrdMsk, (U8*)InfoValue, 1);
//	getVehInfo->StrWhAngGrdMsk = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StWhlAngAliveRollCnt, (U8*)InfoValue, 1);
//	getVehInfo->StWhlAngAliveRollCnt = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAngGrdV, (U8*)InfoValue, 1);
//	getVehInfo->StrWhAngGrdV = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxTrans_General_Status_2_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxTrans_General_Status_2_CEMsg(Appl_Trans_General_Status_2_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_TransTUDMdStat, (U8*)InfoValue, 1);
//	getVehInfo->TransTUDMdStat = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TransEstGear, (U8*)InfoValue, 1);
//	getVehInfo->TransEstGear = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TransEstGearV, (U8*)InfoValue, 1);
//	getVehInfo->TransEstGearV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TrnsShftLvrPosV, (U8*)InfoValue, 1);
//	getVehInfo->TrnsShftLvrPosV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TrnsSftMdStat, (U8*)InfoValue, 1);
//	getVehInfo->TrnsSftMdStat = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TrnShftPtrnActStat, (U8*)InfoValue, 1);
//	getVehInfo->TrnShftPtrnActStat = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_TrnsShftLvrPos, (U8*)InfoValue, 1);
//	getVehInfo->TrnsShftLvrPos = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxElectric_Power_Steering_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxElectric_Power_Steering_CEMsg(Appl_Electric_Power_Steering_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_GET_ID_ElecPwrStrAvalStat, (U8*)InfoValue, 1);
//	getVehInfo->ElecPwrStrAvalStat = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_DrvStrIntfrDtcdV, (U8*)InfoValue, 1);
//	getVehInfo->DrvStrIntfrDtcdV = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_DrvStrIntfrDtcd, (U8*)InfoValue, 1);
//	getVehInfo->DrvStrIntfrDtcd = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_DrvStrIntfrDetARC, (U8*)InfoValue, 1);
//	getVehInfo->DrvStrIntfrDetARC = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_DrvStrIntfrDetPrtVal, (U8*)InfoValue, 1);
//	getVehInfo->DrvStrIntfrDetPrtVal = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_ElcPwrStrAvalStatARC, (U8*)InfoValue, 1);
//	getVehInfo->ElcPwrStrAvalStatARC = InfoValue[0]&0xFF;

//	CanSig_CANGetValue(RX_SIG_GET_ID_ElcPwrStrAvalStatPVal, (U8*)InfoValue, 1);
//	getVehInfo->ElcPwrStrAvalStatPVal = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplGetRxOutside_Air_Temp_Status_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxOutside_Air_Temp_Status_CEMsg(Appl_Outside_Air_Temp_Status_CE_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	S8 otsairtmpcrval = 0;
//	CanSig_CANGetValue(RX_SIG_GET_ID_OtsAirTmpCrVal, (U8*)&otsairtmpcrval, 1);
//	getVehInfo->OtsAirTmpCrVal = (float)(otsairtmpcrval*0.5);

//	//CanSig_CANGetValue(RX_SIG_GET_ID_OtsAirTmpCrValV, (U8*)InfoValue, 1);
//	getVehInfo->OtsAirTmpCrValV = InfoValue[0]&0xFF;

//	//CanSig_CANGetValue(RX_SIG_GET_ID_OtsAirTmpCrValMsk, (U8*)InfoValue, 1);
//	getVehInfo->OtsAirTmpCrValMsk = InfoValue[0]&0xFF;

//	//CanSig_CANGetValue(RX_SIG_GET_ID_OutAirTempVDA, (U8*)InfoValue, 1);
//	getVehInfo->OutAirTempVDA = InfoValue[0]&0xFF;
}

/***********************************************************************
* FUNCTION    : ApplPutTxPark_Assist_Parallel_CEMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxPark_Assist_Parallel_CEMsg(Appl_Park_Assist_Parallel_CE_msgType setVehInfo)
{
//	S16 Trgsteeringwheelang = 0;
//	Trgsteeringwheelang = (S16)(setVehInfo.SWAR_TrgtAng/0.0625);
	//CanSig_CANSendValue(TX_SIG_SET_ID_SWAR_TrgtAng, (U8*)&Trgsteeringwheelang, 2);

	//CanSig_CANSendValue(TX_SIG_SET_ID_StrWhlAngReqPrtVal, (U8*)&setVehInfo.StrWhlAngReqPrtVal, 4);

	//CanSig_CANSendValue(TX_SIG_SET_ID_StrWhlTctlFdbkReqActRC, (U8*)&setVehInfo.StrWhlTctlFdbkReqActRC, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_StrWhlTctlFdbkReqAct, (U8*)&setVehInfo.StrWhlTctlFdbkReqAct, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_StrWhlTctlFdbkReqActProtVal, (U8*)&setVehInfo.StrWhlTctlFdbkReqActProtVal, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_SWAR_ReqActV, (U8*)&setVehInfo.SWAR_ReqActV, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_SWAR_ReqAct, (U8*)&setVehInfo.SWAR_ReqAct, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_StrWhlAngReqARC, (U8*)&setVehInfo.StrWhlAngReqARC, 1);
}

/***********************************************************************
* FUNCTION    : ApplPutTxDis_Long_EchoHeightMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxDis_Long_EchoHeightMsg(Appl_Dis_Long_EchoHeight_msgType setVehInfo)
{
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FLL_Echo_Height, (U8*)&setVehInfo.Dis_FLL_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FRL_Echo_Height, (U8*)&setVehInfo.Dis_FRL_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RLL_Echo_Height, (U8*)&setVehInfo.Dis_RLL_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RRL_Echo_Height, (U8*)&setVehInfo.Dis_RRL_Echo_Height, 1);
}

/***********************************************************************
* FUNCTION    : ApplPutTxDis_Short_EchoHeightMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxDis_Short_EchoHeightMsg(Appl_Dis_Short_EchoHeight_msgType setVehInfo)
{
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FL_Echo_Height, (U8*)&setVehInfo.Dis_FL_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FR_Echo_Height, (U8*)&setVehInfo.Dis_FR_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FML_Echo_Height, (U8*)&setVehInfo.Dis_FML_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FMR_Echo_Height, (U8*)&setVehInfo.Dis_FMR_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RL_Echo_Height, (U8*)&setVehInfo.Dis_RL_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RR_Echo_Height, (U8*)&setVehInfo.Dis_RR_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RML_Echo_Height, (U8*)&setVehInfo.Dis_RML_Echo_Height, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RMR_Echo_Height, (U8*)&setVehInfo.Dis_RMR_Echo_Height, 1);
}

/***********************************************************************
* FUNCTION    : ApplPutTxDis_ShortSensorsMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxDis_ShortSensorsMsg(Appl_Dis_ShortSensors_msgType setVehInfo)
{
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FL_16U, (U8*)setVehInfo.Dis_Front_FL_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FR_16U, (U8*)setVehInfo.Dis_Front_FR_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FML_16U, (U8*)setVehInfo.Dis_Front_FML_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FMR_16U, (U8*)setVehInfo.Dis_Front_FMR_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RL_16U, (U8*)setVehInfo.Dis_Rear_RL_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RR_16U, (U8*)setVehInfo.Dis_Rear_RR_16U, 2);
//
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RML_16U, (U8*)setVehInfo.Dis_Rear_RML_16U, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RMR_16U, (U8*)setVehInfo.Dis_Rear_RMR_16U, 2);

}

/***********************************************************************
* FUNCTION    : ApplPutTxDis_Sensors_StatusMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxDis_Sensors_StatusMsg(Appl_Dis_Sensors_Status_msgType setVehInfo)
{
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sensors_StatusValid_16U, (U8*)&setVehInfo.Dis_Sensors_StatusValid_16U, 2);
}

/***********************************************************************
* FUNCTION    : ApplPutTxDis_SidesSensorsMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxDis_SidesSensorsMsg(Appl_Dis_SidesSensors_msgType setVehInfo)
{
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_FLL_16U, (U8*)&setVehInfo.Dis_Sides_FLL_16U, 2);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_FRL_16U, (U8*)&setVehInfo.Dis_Sides_FRL_16U, 2);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_RLL_16U, (U8*)&setVehInfo.Dis_Sides_RLL_16U, 2);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_RRL_16U, (U8*)&setVehInfo.Dis_Sides_RRL_16U, 2);
}

/***********************************************************************
* FUNCTION    : ApplPutTxUSS_Slot_Outline_InfoMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxUSS_Slot_Outline_InfoMsg(Appl_USS_Slot_Outline_Info_msgType setVehInfo)
{
//	CanSig_CANSendValue(TX_SIG_SET_ID_Uss_Slot_Outline_X, (U8*)&setVehInfo.Uss_Slot_Outline_X, 2);
//	CanSig_CANSendValue(TX_SIG_SET_ID_Uss_Slot_Outline_Y, (U8*)&setVehInfo.Uss_Slot_Outline_Y, 2);
//	can_send_sig(reserve_1_U16,setVehInfo.Uss_Slot_Outline_X);
//	can_send_sig(reserve_2_U16,setVehInfo.Uss_Slot_Outline_Y);
}

#ifdef APA_Slot_Searching_Replay
/***********************************************************************
* FUNCTION    : ApplGetRxUSS_APA_NonHandler_DisMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplGetRxUSS_APA_NonHandler_DisMsg(Appl_USS_APA_NonHandler_Dis_msgType* getVehInfo)
{
//	U8 InfoValue[2];
//	CanSig_CANGetValue(RX_SIG_SET_ID_FrsNonHandlerObjDis, (U8*)InfoValue, 2);
//	getVehInfo->FrsNonHandlerObjDis = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));

//	CanSig_CANGetValue(RX_SIG_SET_ID_FlsNonHandlerObjDis, (U8*)InfoValue, 2);
//	getVehInfo->FlsNonHandlerObjDis = (U16)(((InfoValue[1]<<8)&0xFF00)|(InfoValue[0]&0xFF));
}
#else
/***********************************************************************
* FUNCTION    : ApplPutTxUSS_APA_NonHandler_DisMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxUSS_APA_NonHandler_DisMsg(Appl_USS_APA_NonHandler_Dis_msgType setVehInfo)
{
//	CanSig_CANSendValue(TX_SIG_SET_ID_FrsNonHandlerObjDis, (U8*)&setVehInfo.FrsNonHandlerObjDis, 2);

//	CanSig_CANSendValue(TX_SIG_SET_ID_FlsNonHandlerObjDis, (U8*)&setVehInfo.FlsNonHandlerObjDis, 2);
}
#endif

/***********************************************************************
* FUNCTION    : ApplPutTxWarningboard_RxMsg
* DESCRIPTION :
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void ApplPutTxWarningboard_RxMsg(Appl_Warningboard_Rx_msgType setVehInfo)
{
	//CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_Switch, (U8*)&setVehInfo.Warningboard_Switch, 1);

	//CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_FZ, (U8*)&setVehInfo.Warningboard_FZ, 1);
}

void SOC_EEP_RewriteHandler(DescMsgContext* pMsgContext)
{
    static U8 write_counter = 0;
    static U8 write_timer = 0;
    U8 i = 0;
    U8 ret = ERR_FAULT;
	static U8 u8_write_arg[64] = {0x0};
	static U8 u8_read_arg[64] = {0x0};

    /* The max retry times are 5 */
    if((write_counter < 5)&&
    (EEP_INVALID_ADDRESS != EepWriteControl.uEepRetryAddr)&&(EEP_INVALID_LENGTH != EepWriteControl.uEepRetryWordNum))
    {
        /* retry per 50ms */
        if(write_timer >= 4)
        {
            if(0 == write_counter)
            {
                /* Get data */
                for(i=0; i<EepWriteControl.uEepRetryByte; i++)
                {
                    u8_write_arg[i] = pMsgContext->reqData[i];
                }
            }
            write_timer = 0;
            write_counter++;
            /* write data */
            ret = FDLDriver_Write(EepWriteControl.uEepRetryAddr, u8_write_arg, EepWriteControl.uEepRetryWordNum);
            if(ERR_OK == ret)
            {
                /* write successfully */
//                SendDiagResponse(E_POSITIVE_DIAG_RESPONSE);
                write_counter = 0;
                write_timer = 0;
                /* End */
            }
            else
            {
                /* write failed */
            }
        }
        else
        {
            write_timer++;
        }
    }
    else
    {
        /* write failed in 5 times */
//		DescSetNegResponse(kDescNrcGeneralProgrammingFailure);
//        DescProcessingDone();
        write_counter = 0;
        write_timer = 0;
        /* End */
    }
}

/* CODE CATEGORY 1 START */
vuint8 PDC_14_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_14,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_14_c^ \
					c3_PDC_14_c^ \
					c4_PDC_14_c^ \
					c5_PDC_14_c^ \
					c6_PDC_14_c^ \
					c7_PDC_14_c^ \
					c8_PDC_14_c;
	can_send_sig(Checksum_PDC_14,CalcuChecksum); 	


}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_13_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_13,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_13_c^ \
					c3_PDC_13_c^ \
					c4_PDC_13_c^ \
					c5_PDC_13_c^ \
					c6_PDC_13_c^ \
					c7_PDC_13_c^ \
					c8_PDC_13_c;
	can_send_sig(Checksum_PDC_13,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_12_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_12,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length

	CalcuChecksum = c2_PDC_12_c^ \
					c3_PDC_12_c^ \
					c4_PDC_12_c^ \
					c5_PDC_12_c^ \
					c6_PDC_12_c^ \
					c7_PDC_12_c^ \
					c8_PDC_12_c;

	can_send_sig(Checksum_PDC_12,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_11_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_11,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_11_c^ \
					c3_PDC_11_c^ \
					c4_PDC_11_c^ \
					c5_PDC_11_c^ \
					c6_PDC_11_c^ \
					c7_PDC_11_c^ \
					c8_PDC_11_c;

	can_send_sig(Checksum_PDC_11,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_10_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_10,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_10_c^ \
					c3_PDC_10_c^ \
					c4_PDC_10_c^ \
					c5_PDC_10_c^ \
					c6_PDC_10_c^ \
					c7_PDC_10_c^ \
					c8_PDC_10_c;

	can_send_sig(Checksum_PDC_10,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_9_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_9,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_9_c^ \
					c3_PDC_9_c^ \
					c4_PDC_9_c^ \
					c5_PDC_9_c^ \
					c6_PDC_9_c^ \
					c7_PDC_9_c^ \
					c8_PDC_9_c;

	can_send_sig(Checksum_PDC_9,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_8_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_8,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_8_c ^ \
					c3_PDC_8_c ^ \
					c4_PDC_8_c ^ \
					c5_PDC_8_c ^ \
					c6_PDC_8_c ^ \
					c7_PDC_8_c ^ \
					c8_PDC_8_c ;

	can_send_sig(Checksum_PDC_8,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_7_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_7,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_7_c ^ \
					c3_PDC_7_c ^ \
					c4_PDC_7_c ^ \
					c5_PDC_7_c ^ \
					c6_PDC_7_c ^ \
					c7_PDC_7_c ^ \
					c8_PDC_7_c ;

	can_send_sig(Checksum_PDC_7,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_6_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_6,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_6_c^ \
					c3_PDC_6_c^ \
					c4_PDC_6_c^ \
					c5_PDC_6_c^ \
					c6_PDC_6_c^ \
					c7_PDC_6_c^ \
					c8_PDC_6_c;
	can_send_sig(Checksum_PDC_6,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_5_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_5,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_5_c^ \
					c3_PDC_5_c^ \
					c4_PDC_5_c^ \
					c5_PDC_5_c^ \
					c6_PDC_5_c^ \
					c7_PDC_5_c^ \
					c8_PDC_5_c;
	can_send_sig(Checksum_PDC_5,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_4_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_4,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_4_c^ \
					c3_PDC_4_c^ \
					c4_PDC_4_c^ \
					c5_PDC_4_c^ \
					c6_PDC_4_c^ \
					c7_PDC_4_c^ \
					c8_PDC_4_c;
	can_send_sig(Checksum_PDC_4,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
vuint8 PDC_3_TxPretransmit(CanTxInfoStruct ctis)
{
	U8 CalcuChecksum;
	static U8 liveconuter = 0x00;
	
	can_send_sig(LiveCounter_PDC_3,liveconuter++); 
	if(liveconuter > 15)
	{
		liveconuter = 0x00;
	}
	
	//Checksum (byte0) = byte1 XOR byte2 XOR byte3 XOR byte4 ï¿½ï¿½XOR byteN-1, N = message length
	CalcuChecksum = c2_PDC_3_c^ \
					c3_PDC_3_c^ \
					c4_PDC_3_c^ \
					c5_PDC_3_c^ \
					c6_PDC_3_c^ \
					c7_PDC_3_c^ \
					c8_PDC_3_c;
	can_send_sig(Checksum_PDC_3,CalcuChecksum); 	

}
/* CODE CATEGORY 1 END */


