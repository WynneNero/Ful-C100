
#include "define.h"
#include "ApsCanAPP.h"
#include "pdcCtrl.h"
#include "sw_timer.h"
#include "ObjDetect_Pub.h"
#include "SocManager.h"

#include "ComplexDrvier_Globaldef_IF.H"
#include "stdio.h"
#include "il_inc.h"

#include "CanApp.h"
#include "il_par.h"
#include "UssInfoMsg.h"
#include "Dem_IntErrId.h"
#include "UltraRadarDriver.h"
#include "UssObjDetInterface.h"
#include "UssInfo_Msg_IF.h"
#include "ussLibIf.h"
#include "ussLibAdapt.h"
#include "xprintf.h"
#include "APSAPP.h"
#include "UssInfoMsg.h"

extern APS_MODULE_STATUS SocCurrentParkingStatus;
extern APS_MODULE_STATUS APSModuleCurrentStatus;

#define DISTANCE_AWAY_VALUE 100
#define DISTANCE_CLOSE_VALUE 50
#define PDC_FORCE_ON_UNKNOW 0xFF

typedef enum 
{
	EPB_SYS_STATUS_RELEASE = 0,
	EPB_SYS_STATUS_APPLY,
	EPB_SYS_STATUS_RELEASING,
	EPB_SYS_STATUS_APPLAYING,
	EPB_SYS_STATUS_DISENGAGED,
}EPB_SYS_STATUS_TYPE;
typedef enum
{
	EPB_STATE_UNKNOW,
	EPB_STATE_NO_ACTIVE,
	EPB_STATE_ACTIVE,
}EPB_STATE_TYPE;
	
typedef enum 
{
	VEHICLE_SPEED_STATE_UNKNOW,
	VEHICLE_SPEED_STATE_H_15K,// High
	VEHICLE_SPEED_STATE_L_15K,//Low And Equal	
}VEHICLE_SPEED_STATE_TYPE;

typedef enum 
{
	ATTITUDE_GEAR_STATE_UNKNOW,
	ATTITUDE_GEAR_STATE_FRONT,
	ATTITUDE_GEAR_STATE_REAR,
	ATTITUDE_GEAR_STATE_STILL,
	ATTITUDE_GEAR_STATE_MOVE_UNKNOW,
}ATTITUDE_GEAR_STATE_TYPE;

typedef enum 
{
	PDC_AutoOn_Switch_Unkonw,
	PDC_AutoOn_Switch_On,
    PDC_AutoOn_Switch_Off,
}PDC_AUTOON_SWITCH;

typedef struct
{   
	//F101_RADAR_TYPE_TAG radarConfig;    // F4, R4, F4R4	
	PDC_RADAR_ACTIVE_MODE_TYPE pdcRadarActiveMode;    			
	PDC_DISTANCE_SEND_MODE  reqPdcDistanceSendMode;        // F4, R4, F4R4	
	PDC_DISTANCE_SEND_MODE  pdcDistanceSendWorkingMode;        // F4, R4, F4R4
	E_APA_PDCMode_Status pdcWorkMode;
	APS_MODULE_STATUS APSModuleStatus;
    
	U8 radar_distance_value_backup[12];	
	U8 ecuFault;		
    U8 pdcFunctionSwEnableFlagBak;
    
	U8 frontRadarFaultFlag;
	U8 rearRadarFaultFlag;

	U8 curGear;
	U32 vehicleSpeed;
	U8 accStatus;
	VEHICLE_SPEED_STATE_TYPE vehicleSpeedState;

	U16 radar_distance_nearest_bck;

	U8 front_warnning_flag;
	U8 rear_warnning_flag;
	U8 uss_self_detect_warning_flag;
    VehiclePdcWorkingState VehiclePdcState;
    PAS_Work_Status VehiclePasWorkState;
    PAS_Warning_Tone VehiclePasWarningState;

    U8 pdcSwitchFlag;
    U8 AVSFunctionFlag;
}pdcCtrl_type;
static pdcCtrl_type pdcCtrl;

static void pdcDetectRunnable(void *p);
static void pdcStatusJudge(void);
static void pdcAlarmLevel(U8 level);
static void pdcWarningLevel(U8 distance[]);
static void clearWarningLevel(void);

static void pdcCanDebugSender(void);
static BOOL Set_PDC_Mute_Status(U8 distance[]);
static U16 getNearestDistance(void);

static void ussFailWarnTimeoutCb(void *p);
static void warnning_3S(void);
void Set_PDCMode(E_APA_PDCMode_Status PDCMode_Status);
void PDCBuzzerHandler(void);


U8 Voice_uss;
U8 CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Off;
S8 pdcAlarmCnt = 0;
BOOL pdcMuteFlag = FALSE;

BOOL pdcDetectStartFlag = FALSE;
BOOL Request_Enter_AVM_Once = FALSE;
BOOL HaveEnterAVMByRadarAutoStartOnce = FALSE;

static E_APA_PDCMode_Status PDCMode_Status_Cur;

/************extern variable declare****************/
extern diagnosticTypedef USSFailureStatus_Info_called[12];
extern DtcTypedef USSFailureDtcInfo[SENSOR_TOTAL_INDEX];
extern BOOL bReqToSendRadarlevels;
extern BOOL Gear_D_USS_AllAutoOn = FALSE;

extern U8 AVM_Ctl_PDC_Req;
extern U16 can_vehiclespeed;
extern BOOL AVM_ENTER_FLAG;



void pdcCtrlOpen(void)
{
	pdcCtrl.ecuFault = FALSE;
	pdcCtrl.frontRadarFaultFlag = FALSE;
	pdcCtrl.rearRadarFaultFlag = FALSE;

	pdcCtrl.curGear = GEAR_INVALID;
	pdcCtrl.vehicleSpeedState = VEHICLE_SPEED_STATE_UNKNOW;

	SwTmrMgr_Open();

    pdcCtrl.pdcDistanceSendWorkingMode = PDC_DISTANCE_SEND_MODE_STANDBY;
	Set_PDCMode(PDC_Standby_enm);
	g_SV_SetUbattStatus_bl(UbattStsValid);
    SetUssWorkingState(0);
	
    pdcCtrl.front_warnning_flag = 0;
    pdcCtrl.rear_warnning_flag = 0;
    pdcCtrl.uss_self_detect_warning_flag = 0;
    pdcCtrl.VehiclePdcState = PDC_OFF_STATE;
    pdcCtrl.VehiclePasWorkState = PAS_Work_OFF_STATE;
    pdcCtrl.VehiclePasWarningState = Not_active_tone;
}
void pdcCtrlTask5ms(void)
{	
	pdcStatusJudge();
	SwTmrMgr_Proc();
	pdcCanDebugSender();
	PDCBuzzerHandler();
	pdcSystemStatusUpdate(pdcCtrl.pdcWorkMode);
}


void pdcCanDebugSender(void)
{
	if(GetMmiTouchDebugFlag()==1)
	{
		can_send_sig(USS_WORK_MODE,pdcCtrl.pdcWorkMode);
	}
}

void pdcDetectStart(void)
{
	SwTmrMgr_Start(PDC_DETECT_TMR,20,pdcDetectRunnable,NULL,TRUE);

}
void pdcDetectStop(void)
{
	U8 radar_distance_invalid[12] = {0xFF,0XFF,0XFF,0xFF,0XFF,0XFF,0xFF,0XFF,0XFF,0xFF,0XFF,0XFF};
	SwTmrMgr_Stop(PDC_DETECT_TMR);
	pdcAlarmLevel(INACTIVE);
	clearWarningLevel();
	SocManager_SendMsg(TX_HQ,TYPE_EVENT,RADIO_NOTIFY_RADAR_SENSOR_INFO,NUMBER_OF_SENSOR,radar_distance_invalid);
}

/****************************************************************************
*  Name			: pdcSoftSwitch
*  Description	: pdc funtion switch flag
*  Parameter	: SoftSwitchEvent
*  Returns		: FALSE : pdc off ; TRUE: pdc off
****************************************************************************/
void PDCBuzzerHandler(void)
{	
    static U8 CAN_TX_BuzzerSwitchSt = 0;
    U8 CAN_RX_PDCBuzzerReq = can_receive_sig(HU_PDCBuzzerReq);      //0:Inactive 1:off 2:on
	
    if(CAN_RX_PDCBuzzerReq != 0x0)
    {
    	if(CAN_RX_PDCBuzzerReq == 0x2)
    	{
			CAN_TX_BuzzerSwitchSt = 0x1;	//on
		}
		else
		{
			CAN_TX_BuzzerSwitchSt = 0x0;	//off
		}
    }	
	can_send_sig(BuzzerSwitchSt, CAN_TX_BuzzerSwitchSt);	//0:off 1:on
}


/****************************************************************************
*  Name			: Set_PDCMode_AutoOn
*  Description	: set PDC work mode in auto on mode
*  Parameter	: 
*  Returns		: 
****************************************************************************/
void Set_PDCMode_AutoOn(void)
{
	U8 arg[3];
	
	if(pdcCtrl.pdcWorkMode == PDC_Standby_enm)
	{
		pdcCtrl.pdcWorkMode = PDC_FrontRearActive_enm;
		Set_PDCMode(PDC_FrontRearActive_enm);
	}
	else if(pdcCtrl.pdcWorkMode == PDC_FrontRearActive_enm)
	{
		if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm  <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm <= 80
		|| USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm  <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm <= 80		
		|| USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm  <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm <= 80
		|| USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm  <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm <= 80
		|| USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm <= 80
		|| USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm <= 80 || USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm <= 80)
		{	
			if(FALSE == Request_Enter_AVM_Once)
			{				
				arg[0] = CAN_SOFTKEY_TYPE;
				arg[1] = 0x1;
				arg[2] = 0x1;
				SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_KEY_STATUS,3,arg);
				
				Request_Enter_AVM_Once = TRUE;
				HaveEnterAVMByRadarAutoStartOnce = TRUE;
			}
		}	
	}
}


void Set_PDCMode(E_APA_PDCMode_Status PDCMode_Status)
{
    static E_APA_PDCMode_Status PDCMode_Status_Cur;
   
    if(PDCMode_Status_Cur !=  PDCMode_Status)
    {
        if(PDCMode_Status_Cur == PDC_Standby_enm && PDCMode_Status > PDC_Standby_enm)
        {
            Voice_uss = SELFCHECKOKTONE;		
			pdcAlarmCnt = 10;	//stay with 200ms
        }
		
        PDCMode_Status_Cur = PDCMode_Status;
        g_FV_adiSetPDCModeStatus_bl(PDCMode_Status_Cur);
		pdcCtrl.pdcWorkMode = PDCMode_Status_Cur;
        
        if(PDCMode_Status_Cur > PDC_Standby_enm)
        {            
            pdcDetectStart();
			can_send_sig(SysSt_PDC, 0x1); //on
        }
        else
        {
            pdcDetectStop();
			can_send_sig(SysSt_PDC, 0x0); //off
        }       
    }    		
}

static void pdcStatusJudge(void)
{	
	
    U8 curGear = GEAR_INVALID; 
	U32 vehicleSpeed = 0;	
    U8 accStatus = can_receive_sig(PowerMode);	
	U8 pdcAutoOnSta = can_receive_sig(HU_PDCAutoOnFunctionReq); 	
	static U8 pdcAutoOnFlag = FALSE;   
	
	static BOOL RememberpdcAutoOnFlag = FALSE;	
	static BOOL PDCAutoOn_Pending_Flag = FALSE;
	
	static VEHICLE_SPEED_STATE_TYPE vehicleSpeedState;
    APS_MODULE_STATUS APSCurrentStatus = GetAPSCurrentStatus();
	static U8 AVM_Ctl_PDC_Req_bak = 0;
    
    if((accStatus != pdcCtrl.accStatus))
	{
        #ifdef PDC_DEBUG
		printf("KEY_ACC_ON\n");
        #endif
        if((KEY_ACC_ON == accStatus))
        {
            pdcCtrl.APSModuleStatus = APS_PARKING_INIT;
            pdcCtrl.frontRadarFaultFlag = FALSE;
            pdcCtrl.rearRadarFaultFlag = FALSE;                
            pdcCtrl.curGear = GEAR_INVALID;
            
            pdcCtrl.vehicleSpeedState = VEHICLE_SPEED_STATE_UNKNOW;
            pdcCtrl.front_warnning_flag = 0;
            pdcCtrl.rear_warnning_flag = 0;
            
            pdcCtrl.uss_self_detect_warning_flag = 0;
            clrUssPdcLockBits();                    		
    		pdcCtrl.frontRadarFaultFlag = 0;                
    		pdcCtrl.rear_warnning_flag = 0;
			Set_PDCMode(PDC_Standby_enm);
		}
		else 
    	{
			Set_PDCMode(PDC_Standby_enm);    	    
			SetUssWorkingState(0);
    	}

		if((accStatus == KEY_ACC_ON) && (pdcCtrl.accStatus == KEY_ACC_OFF))
		{
			if(0xA5 == EED_RememberPDCAutoOnFlag) //default:0xA5
			{
				RememberpdcAutoOnFlag = FALSE;
			}
			else
			{
				RememberpdcAutoOnFlag = EED_RememberPDCAutoOnFlag;
				pdcAutoOnFlag = RememberpdcAutoOnFlag;
			}
		}

		if((KEY_ACC_OFF == accStatus))
		{
			HaveEnterAVMByRadarAutoStartOnce = FALSE;
		}
	}

	pdcCtrl.accStatus = accStatus; 	
	curGear = get_ActGear();
	vehicleSpeed = get_VehSpd();

	if(pdcAutoOnSta)
	{
		if(!PDCAutoOn_Pending_Flag)
		{
			PDCAutoOn_Pending_Flag = TRUE;
			pdcAutoOnFlag = !pdcAutoOnFlag;
			RememberpdcAutoOnFlag = pdcAutoOnFlag;
			EED_LockDataBlock(EED_nEOLConfig);
			EED_RememberPDCAutoOnFlag = RememberpdcAutoOnFlag;
			EED_UnlockAndSavDataBlock(EED_nEOLConfig);
		}
	}
	else
	{
		PDCAutoOn_Pending_Flag = FALSE;
	}


	if(pdcAutoOnFlag)
	{
		can_send_sig(PDCAutoOnFunctionInd, 0x1); //on
	}
	else
	{
		can_send_sig(PDCAutoOnFunctionInd, 0x0); //off		
	}

	if(vehicleSpeed >= 15)
	{
		vehicleSpeedState = VEHICLE_SPEED_STATE_H_15K;
	}
	else
    {
        if(vehicleSpeedState == VEHICLE_SPEED_STATE_UNKNOW)
        {
            vehicleSpeedState = VEHICLE_SPEED_STATE_L_15K;
        }
        else if(vehicleSpeedState == VEHICLE_SPEED_STATE_H_15K && vehicleSpeed <= 10)
        {
            vehicleSpeedState = VEHICLE_SPEED_STATE_L_15K;
        }            
    } 
	
    if(APSCurrentStatus != pdcCtrl.APSModuleStatus)
    {           
 //       if(APSCurrentStatus == APS_PARKING_SEARCH_PARKIN)
 //       {
 //           Set_PDCMode(PDC_FrontActiveRearOff_enm);
 //       }
         if(APSCurrentStatus >= APS_PARKING_SEARCH_PARKIN)
        {
            Set_PDCMode(PDC_FrontRearActive_enm);
        }

		pdcCtrl.APSModuleStatus = APSCurrentStatus; 
		
		AVM_Ctl_PDC_Req_bak = SK_MAX;        
		pdcCtrl.vehicleSpeedState = VEHICLE_SPEED_STATE_UNKNOW;
    }
    else if(APSCurrentStatus < APS_PARKING_SEARCH_PARKIN)
    {
    	if(vehicleSpeedState != pdcCtrl.vehicleSpeedState)
    	{
			if(vehicleSpeedState == VEHICLE_SPEED_STATE_H_15K)
			{
				Set_PDCMode(PDC_Standby_enm);
			}  
			AVM_Ctl_PDC_Req_bak = SK_MAX;
			pdcCtrl.vehicleSpeedState = vehicleSpeedState;
		}
		else if(vehicleSpeedState == VEHICLE_SPEED_STATE_L_15K)
		{
			if(AVM_Ctl_PDC_Req_bak != AVM_Ctl_PDC_Req)
			{
				if(AVM_Ctl_PDC_Req)
				{				
					Set_PDCMode(PDC_FrontRearActive_enm);					
				}
				else
				{
					Set_PDCMode(PDC_Standby_enm);
				}
				AVM_Ctl_PDC_Req_bak = AVM_Ctl_PDC_Req;	
			}
			else if(AVM_Ctl_PDC_Req == SK_EXIT && curGear == GEAR_D && pdcAutoOnFlag == TRUE && HaveEnterAVMByRadarAutoStartOnce == FALSE)
			{
				Set_PDCMode_AutoOn();
			}
			else if(AVM_Ctl_PDC_Req == SK_EXIT && curGear == GEAR_P)
			{
				if(pdcCtrl.pdcWorkMode != PDC_Standby_enm)
				{
					Set_PDCMode(PDC_Standby_enm);
				}
			}
		}
    }
}

static void pdcDetectRunnable(void *p)
{
	U16 distance[12];
	U8 CAN_RX_Gear = get_ActGear();
	U8 CAN_RX_DrivingDirection = can_receive_sig(DrivingDirection);
	U8 BuzzerAlarmLevel_Rear,BuzzerAlarmLevel_Front;

    distance[0] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm;       
	distance[1] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm; 
    distance[2] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm;       
	distance[3] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm; 
    
	distance[4] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm;      
	distance[5] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm;        
	distance[6] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm;      
	distance[7] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm;

	distance[8] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm;      
	distance[9] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm;        
	distance[10] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm;      
	distance[11] = USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm;

    pdcWarningLevel(distance);
    
	if(Voice_uss == SELFCHECKOKTONE)
	{  
		pdcAlarmCnt --;
		if(0 > pdcAlarmCnt)
		{			
			Voice_uss = INACTIVE;
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_SelfCheck;
		}
		pdcAlarmLevel(SELFCHECKOKTONE);
		return;
	}

    if((distance[0] <= 40) || (distance[1] <= 40) || (distance[4] <= 40) 
	|| (distance[5] <= 40) || (distance[8] <= 30) || (distance[9] <= 30))
    {
		BuzzerAlarmLevel_Front = LEVEL1; 	
	}
	else if((distance[0] <= 60) || (distance[1] <= 60) || (distance[4] <= 60) 
		 || (distance[5] <= 60) || (distance[8] <= 60) || (distance[9] <= 60))
	{
		BuzzerAlarmLevel_Front = LEVEL2;
	}
	else if(CAN_RX_Gear == GEAR_P || CAN_RX_Gear == GEAR_D || (CAN_RX_Gear == GEAR_N && CAN_RX_DrivingDirection == Forward))
	{
		if((distance[4] <= 80) || (distance[5] <= 80))
		{
			BuzzerAlarmLevel_Front = LEVEL3; 	
		}
		else if((distance[4] <= 100) || (distance[5] <= 100))
		{
			BuzzerAlarmLevel_Front = LEVEL4; 	
		}
		else if((distance[4] <= 120) || (distance[5] <= 120))
		{
			BuzzerAlarmLevel_Front = LEVEL5; 	
		}
		else
		{		
			BuzzerAlarmLevel_Front = INACTIVE;	
		}
	}
	else
	{		
		BuzzerAlarmLevel_Front = INACTIVE;	
	}

    if((distance[2] <= 40) || (distance[3] <= 40) || (distance[6] <= 40) 
	|| (distance[7] <= 40) || (distance[10] <= 30) || (distance[11] <= 30))
    {
		BuzzerAlarmLevel_Rear = LEVEL1; 	
	}
	else if((distance[2] <= 60) || (distance[3] <= 60) || (distance[6] <= 60) 
		 || (distance[7] <= 60) || (distance[10] <= 60) || (distance[11] <= 60))
	{
		BuzzerAlarmLevel_Rear = LEVEL2;
	}
	else if(CAN_RX_Gear == GEAR_P || CAN_RX_Gear == GEAR_R || (CAN_RX_Gear == GEAR_N && CAN_RX_DrivingDirection == Backward))
	{
		if((distance[6] <= 80) || (distance[7] <= 80))
		{
			BuzzerAlarmLevel_Rear = LEVEL3; 	
		}
		else if((distance[6] <= 100) || (distance[7] <= 100))
		{
			BuzzerAlarmLevel_Rear = LEVEL4; 	
		}
		else if((distance[6] <= 150) || (distance[7] <= 150))
		{
			BuzzerAlarmLevel_Rear = LEVEL5; 	
		}
		else
		{
			BuzzerAlarmLevel_Rear = INACTIVE;	
		}
	}
	else
	{		
		BuzzerAlarmLevel_Rear = INACTIVE;	
	}


	if(BuzzerAlarmLevel_Rear == BuzzerAlarmLevel_Front)
	{
		if(BuzzerAlarmLevel_Rear != INACTIVE && BuzzerAlarmLevel_Front != INACTIVE)
		{
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_FrontRear;
		}
		else
		{
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Off;
		}		
		Voice_uss = BuzzerAlarmLevel_Front;
	}
	else if(BuzzerAlarmLevel_Rear > BuzzerAlarmLevel_Front)
	{
		if(BuzzerAlarmLevel_Front != INACTIVE)
		{
			Voice_uss = BuzzerAlarmLevel_Front;
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Front;
		}
		else
		{
			Voice_uss = BuzzerAlarmLevel_Rear;
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Rear;
		}
	}
	else if(BuzzerAlarmLevel_Rear < BuzzerAlarmLevel_Front)
	{
		if(BuzzerAlarmLevel_Rear != INACTIVE)
		{
			Voice_uss = BuzzerAlarmLevel_Rear;
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Rear;
		}
		else
		{
			Voice_uss = BuzzerAlarmLevel_Front;
			CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Front;
		}
	}

    if(Set_PDC_Mute_Status(distance))   //In a constant distance keep after 10 s, turn off the pdc alarm sound
    {    
		CAN_TX_BuzzerAlarmPosition = BuzzerAlarmPosition_Off;
        pdcAlarmLevel(INACTIVE);
    }
    else
    {   
        pdcAlarmLevel(Voice_uss);
    }
    
	pdcDistanceUpdate(pdcCtrl.pdcWorkMode);
}

void pdcSystemStatusUpdate(E_APA_PDCMode_Status mode)
{
	switch(mode)
	{
		case PDC_FrontRearActive_enm:
			can_send_sig(RadarSysSt_Front, 0x1);     //On
			can_send_sig(RadarSysSt_FrontSide, 0x1); //On			
			can_send_sig(RadarSysSt_Rear, 0x1);      //On			
			can_send_sig(RadarSysSt_RearSide, 0x1);  //On
			break;
			
		case PDC_FrontActiveRearOff_enm:
			can_send_sig(RadarSysSt_Front, 0x1);     //On
			can_send_sig(RadarSysSt_FrontSide, 0x1); //On			
			can_send_sig(RadarSysSt_Rear, 0x0);      //Off			
			can_send_sig(RadarSysSt_RearSide, 0x0);  //Off
			break;
			
		case PDC_FrontOffRearActive_enm:
			can_send_sig(RadarSysSt_Front, 0x0);     //Off
			can_send_sig(RadarSysSt_FrontSide, 0x0); //Off
			can_send_sig(RadarSysSt_Rear, 0x1);      //On			
			can_send_sig(RadarSysSt_RearSide, 0x1);  //On
			break;

		default :
			can_send_sig(RadarSysSt_Front, 0x0);     //Off
			can_send_sig(RadarSysSt_Rear, 0x0);      //Off			
			can_send_sig(RadarSysSt_FrontSide, 0x0); //Off
			can_send_sig(RadarSysSt_RearSide, 0x0);  //Off
			break;
	}
}


static  gType_PSLPoint_st pslPoint[50];
static  gType_PSLPoint_st pslWaitProcessPoint[50];

static U8 f_num_pui8_fls,f_num_pui8_frs;
static  gType_VehPos_st l_VehPosOdo_st; 
S32 FLS_point_DistanceMin = 5000,FRS_point_DistanceMin = 5000;
S8 FLS_Point_KeepCount = 0,FRS_Point_KeepCount = 0;


#define VECHICHE_WHEEL_BASE 3402
#define VECHICHE_WHEEL_Y 926

static U16 FOV_LIMIT_X  = 1000;// 450;   // 200 mm

void pdcDistanceUpdate(E_APA_PDCMode_Status mode)
{
    U8 i = 0;
	U8 radar_distance_value[12];
	
    if((APS_PARKING_SEARCH_PARKIN == GetSocCurrentAPSStatus())||(TRUE == AVM_ENTER_FLAG))
    {      
                //if((APS_PARKING_SEARCH == GetSocCurrentAPSStatus())||(TRUE == AVM_ENTER_FLAG))
                {
                     U8 f_num_pui8_fls,f_num_pui8_frs,i;
                     S32 yDistance = 5000;
                     S32 xDifference = 0;
                    
                     if(FLS_Point_KeepCount <= 0)
                     {			                     	
						 FLS_Point_KeepCount = 0;
	                     FLS_point_DistanceMin = 5000;
					 }
					 else
					 {
						FLS_Point_KeepCount --;
					 }
					 
					 if(FRS_Point_KeepCount <= 0)
					 {	
					 	FRS_Point_KeepCount = 0;
	                    FRS_point_DistanceMin = 5000;
					 }
					 else
					 {
						FRS_Point_KeepCount --;
					 }

                     
                     g_FV_adiGetUSSInterData_bl(pslPoint,&f_num_pui8_fls,0);
                
                     if(f_num_pui8_fls > 0)
                     {
                         //xprintf("LN:%d\n",f_num_pui8_fls);
                         for(i=0;i<f_num_pui8_fls;i++)
                         {
                             //if((pslPoint[i].X_si32 > l_VehPosOdo_st.XPosMM_si32+VECHICHE_WHEEL_BASE-FOV_LIMIT_X)&&(pslPoint[i].X_si32 < l_VehPosOdo_st.XPosMM_si32+VECHICHE_WHEEL_BASE+FOV_LIMIT_X))
                             {   
                                if(pslPoint[i].Y_si32 > 0)
                                {
                                    yDistance = pslPoint[i].Y_si32;
                                }
                                else 
                                {
                                    yDistance = - pslPoint[i].Y_si32;
                
                                }
                                if(pslPoint[i].X_si32 > 0)
                                {
                                    xDifference = pslPoint[i].X_si32;
                                 }
                                 else 
                                 {
                                     xDifference =  - pslPoint[i].X_si32;
                                 }
                           
                                 if(FLS_point_DistanceMin > yDistance - VECHICHE_WHEEL_Y)
                                 {
                                     FLS_point_DistanceMin = yDistance-VECHICHE_WHEEL_Y;
                                 }
                             }
                             /*
                             xprintf("%d-pX-Y:(%d,%d)=%d=%d\n",
                             i,
                             pslPoint[i].X_si32,
                             pslPoint[i].Y_si32,
                             xDifference-VECHICHE_WHEEL_BASE,
                             FLS_point_DistanceMin);
                             */
                         }						 
						 FLS_Point_KeepCount = 5;
                     }
                    
                    g_FV_adiGetUSSInterData_bl(pslPoint,&f_num_pui8_frs,1);
                     if(f_num_pui8_frs > 0)
                     {       
                        //xprintf("RN:%d\n",f_num_pui8_frs);
                        for(i=0;i<f_num_pui8_frs;i++)
                        {            
                             //if((pslPoint[i].X_si32 > l_VehPosOdo_st.XPosMM_si32+VECHICHE_WHEEL_BASE-FOV_LIMIT_X)&&(pslPoint[i].X_si32 < l_VehPosOdo_st.XPosMM_si32+VECHICHE_WHEEL_BASE+FOV_LIMIT_X))
                             {
                                if(pslPoint[i].Y_si32 > 0)
                                {
                                    yDistance = pslPoint[i].Y_si32;
                                 }
                                 else 
                                 {
                                     yDistance = - pslPoint[i].Y_si32;
                                 }
                
                                 if(pslPoint[i].X_si32 > 0)
                                 {
                                    xDifference = pslPoint[i].X_si32;
                                 }
                                 else 
                                 {
                                     xDifference =  - pslPoint[i].X_si32;
                                 }
                         
                                 if(FRS_point_DistanceMin > yDistance - VECHICHE_WHEEL_Y)
                                 {
                                     FRS_point_DistanceMin = yDistance - VECHICHE_WHEEL_Y;
                                 }
                             }
                             /*
                             xprintf("%d-pX-Y:(%d,%d)=%d=%d\n",
                             i,
                             pslPoint[i].X_si32,
                             pslPoint[i].Y_si32,
                            xDifference-VECHICHE_WHEEL_BASE,
                            FRS_point_DistanceMin);
                            */
                         }						
						 FRS_Point_KeepCount = 5;
                     }        
                }       	
        if(can_receive_sig(DrivingDirection) == 0x0) //stop
        {
            radar_distance_value[0] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm/2);
            radar_distance_value[5] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm/2);
        }
		else if (can_receive_sig(DrivingDirection) == 0x2) //backward
		{
			radar_distance_value[0] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm/2);
			radar_distance_value[5] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm/2);

			if(radar_distance_value[0] >= 127)
			{
				radar_distance_value[0] = 250;
			}

			if(radar_distance_value[5] >= 127)
			{
				radar_distance_value[5] = 250;
			}
		}
        else 
        {
            radar_distance_value[0] = (U8)(FLS_point_DistanceMin/20);
            radar_distance_value[5] = (U8)(FRS_point_DistanceMin/20);
        }
    }
    else 
    {
        radar_distance_value[0] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm/2);
        radar_distance_value[5] = (U8)(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm/2);
    }
	
	/******************************************************************************************************
	* Strategy :If the remainder of the value obtained after dividing the value by 2 is not 0, the result + 1
	* eg: if distance = 60 , so (distance + 1)/ 2 = 30 ,then 30 * 2 = 60   
	*     if distance = 61 , so (distance + 1)/ 2 = 31 ,then 31 * 2 = 62
	* Purpose  :Solve the problem that when the radar distance is 61cm, 
	* the distance to the APP is 60cm,and the color does not change
	********************************************************************************************************/
	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm == 45)
	{
	 	radar_distance_value[1]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[1]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm  + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm == 45)
	{
		radar_distance_value[2]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[2]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm == 45)
	{
		radar_distance_value[3]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[3]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm == 45)
	{
		radar_distance_value[4]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{	
		radar_distance_value[4]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm  + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm == 45)
	{
		radar_distance_value[6]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[6]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm == 45)
	{
		radar_distance_value[7]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm )/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[7]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm  + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm == 45)
	{
		radar_distance_value[8]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm )/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[8]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm == 45)
	{
		radar_distance_value[9]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm )/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[9]  = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm == 45)
	{
		radar_distance_value[10] = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm )/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[10] = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm  + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	if(USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm == 45)
	{
		radar_distance_value[11] = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm )/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}
	else
	{
		radar_distance_value[11] = (U8)((USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm + 1)/(USS_SPI_FACTOR*USS_UNIT_CONVERT));
	}

	switch(mode)
	{
		case PDC_FrontRearActive_enm:
			if(0 != _memcmp(radar_distance_value,pdcCtrl.radar_distance_value_backup,12) || TRUE == bReqToSendRadarlevels)
			{
				bReqToSendRadarlevels = FALSE;
				_memcpy(pdcCtrl.radar_distance_value_backup,radar_distance_value,NUMBER_OF_SENSOR);
				SocManager_SendMsg(TX_HQ,TYPE_EVENT,RADIO_NOTIFY_RADAR_SENSOR_INFO,NUMBER_OF_SENSOR,radar_distance_value);

                M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Long_U8,radar_distance_value[0]);        
                M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Short_U8,radar_distance_value[1]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleLeft_Short_U8,radar_distance_value[2]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleRight_Short_U8,radar_distance_value[3]);
				
                M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Short_U8,radar_distance_value[4]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Long_U8,radar_distance_value[5]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Long_U8,radar_distance_value[6]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Short_U8,radar_distance_value[7]);
				
                M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleLeft_Short_U8,radar_distance_value[8]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleRight_Short_U8,radar_distance_value[9]);
                M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Short_U8,radar_distance_value[10]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Long_U8,radar_distance_value[11]);
            }
		break;

		case PDC_FrontActiveRearOff_enm:
			_memset(&radar_distance_value[6], 0x7f, 6);
			if(0 != _memcmp(radar_distance_value,pdcCtrl.radar_distance_value_backup,12) || TRUE == bReqToSendRadarlevels || FLS_Point_KeepCount > 0 || FRS_Point_KeepCount > 0)
			{
				bReqToSendRadarlevels = FALSE;
				_memcpy(pdcCtrl.radar_distance_value_backup,radar_distance_value,12);
				SocManager_SendMsg(TX_HQ,TYPE_EVENT,RADIO_NOTIFY_RADAR_SENSOR_INFO,NUMBER_OF_SENSOR,radar_distance_value);

				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Long_U8,radar_distance_value[0]); 	   
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Short_U8,radar_distance_value[1]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleLeft_Short_U8,radar_distance_value[2]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleRight_Short_U8,radar_distance_value[3]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Short_U8,radar_distance_value[4]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Long_U8,radar_distance_value[5]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Long_U8,radar_distance_value[6]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Short_U8,radar_distance_value[7]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleLeft_Short_U8,radar_distance_value[8]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleRight_Short_U8,radar_distance_value[9]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Short_U8,radar_distance_value[10]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Long_U8,radar_distance_value[11]);
        	}
  
		break;
		case PDC_FrontOffRearActive_enm:
			_memset(&radar_distance_value[0], 0x7f, 6);
			if(0 != _memcmp(&radar_distance_value,&pdcCtrl.radar_distance_value_backup,12) || TRUE == bReqToSendRadarlevels)
			{			
				bReqToSendRadarlevels = FALSE;
				_memcpy(pdcCtrl.radar_distance_value_backup,radar_distance_value,12);
				SocManager_SendMsg(TX_HQ,TYPE_EVENT,RADIO_NOTIFY_RADAR_SENSOR_INFO,NUMBER_OF_SENSOR,radar_distance_value);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Long_U8,radar_distance_value[0]); 	   
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Short_U8,radar_distance_value[1]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleLeft_Short_U8,radar_distance_value[2]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleRight_Short_U8,radar_distance_value[3]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Short_U8,radar_distance_value[4]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Long_U8,radar_distance_value[5]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Long_U8,radar_distance_value[6]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Short_U8,radar_distance_value[7]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleLeft_Short_U8,radar_distance_value[8]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleRight_Short_U8,radar_distance_value[9]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Short_U8,radar_distance_value[10]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Long_U8,radar_distance_value[11]);

        	}
		break;
		default:
            _memset(&radar_distance_value[0], 0x7f,12);           
			if(_memcmp(&radar_distance_value,&pdcCtrl.radar_distance_value_backup,12) || TRUE == bReqToSendRadarlevels)
			{
				bReqToSendRadarlevels = FALSE;
                _memcpy(pdcCtrl.radar_distance_value_backup,radar_distance_value,12);
                SocManager_SendMsg(TX_HQ,TYPE_EVENT,RADIO_NOTIFY_RADAR_SENSOR_INFO,NUMBER_OF_SENSOR,radar_distance_value);
                
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Long_U8,radar_distance_value[0]); 	   
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Short_U8,radar_distance_value[1]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleLeft_Short_U8,radar_distance_value[2]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleRight_Short_U8,radar_distance_value[3]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Short_U8,radar_distance_value[4]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Long_U8,radar_distance_value[5]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Long_U8,radar_distance_value[6]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Short_U8,radar_distance_value[7]);
				
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleLeft_Short_U8,radar_distance_value[8]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleRight_Short_U8,radar_distance_value[9]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Short_U8,radar_distance_value[10]);
				M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Long_U8,radar_distance_value[11]);

            }
		break;
	}
}


static void pdcAlarmLevel(U8 level)
{
    U8 pdcFunctionEnableFlag = 0;
    U8 epbStatus = get_EPB_SysSt();   
    U8 GearStatus = get_ActGear();

	U8 RadarFaultFlag = USSFailureStatus_Info_called[SENSOR_FRS].allStatus || USSFailureStatus_Info_called[SENSOR_FR].allStatus || USSFailureStatus_Info_called[SENSOR_FRM].allStatus
				 || USSFailureStatus_Info_called[SENSOR_FLM].allStatus || USSFailureStatus_Info_called[SENSOR_FL].allStatus || USSFailureStatus_Info_called[SENSOR_FLS].allStatus
				 || USSFailureStatus_Info_called[SENSOR_RRS].allStatus || USSFailureStatus_Info_called[SENSOR_RR].allStatus || USSFailureStatus_Info_called[SENSOR_RRM].allStatus
				 || USSFailureStatus_Info_called[SENSOR_RLM].allStatus || USSFailureStatus_Info_called[SENSOR_RL].allStatus || USSFailureStatus_Info_called[SENSOR_RLS].allStatus;

    if(level == SELFCHECKOKTONE)
    {
        if(RadarFaultFlag)
        {
            level = SELFCHECKERRORTONE;
        }
    }
    can_send_sig(BuzeerCmd_PDC, level);	
	can_send_sig(BuzzerAlarmPosition, CAN_TX_BuzzerAlarmPosition);
}



/***********************************************************************
*  Name 	   : Set_PDC_Mute_Status
*  Description : Mute Warning voice when the distance is same in 10s
*  Parameter   : uss distance
*  Returns	   : TRUE:Mute FALSE:Not Mute
***********************************************************************/
BOOL Set_PDC_Mute_Status(U8 distance[])
{
    static U16 distance_bak[12];
    static U16 distance_same_count = 0;

    if(distance_bak[0] != distance[0] || distance_bak[1] != distance[1] || distance_bak[2] != distance[2] || distance_bak[3] != distance[3]
     ||distance_bak[4] != distance[4] || distance_bak[5] != distance[5] || distance_bak[6] != distance[6] || distance_bak[7] != distance[7]
     ||distance_bak[8] != distance[8] || distance_bak[9] != distance[9] || distance_bak[10] != distance[10] || distance_bak[11] != distance[11])
    {
        distance_bak[0] = distance[0];
        distance_bak[1] = distance[1];
        distance_bak[2] = distance[2]; 
        distance_bak[3] = distance[3];

        distance_bak[4] = distance[4]; 
        distance_bak[5] = distance[5]; 
        distance_bak[6] = distance[6]; 
        distance_bak[7] = distance[7]; 

		distance_bak[8]  = distance[8]; 
        distance_bak[9]  = distance[9]; 
        distance_bak[10] = distance[10]; 
        distance_bak[11] = distance[11];
		
        distance_same_count = 0;
        return FALSE;
    }
    else
    {
        distance_same_count ++ ;
        if(distance_same_count > 500)  //500 * 20 = 10s
        {
            return TRUE;
        }
    }
    
    return FALSE;
}


/***********************************************************************
*  Name 	   : pdcWarningLevel
*  Description : Set Warning voice Level , Send CAN signal to HU
*  Parameter   : uss distance  -- 0:FL 	 1:FR   2:RL    3:RR
               :	           -- 4:FML  5:FMR 	6:RML 	7:RMR
*  Returns	   : 
***********************************************************************/
static void pdcWarningLevel(U8 distance[])
{
    U8 warningLevel[12];

    //0:FL 	 1:FR   2:RL    3:RR
    for(U8 k = 0;k <= 3;k ++)
    {
        if     (distance[k] <= 40)  warningLevel[k] =  1;
        else if(distance[k] <= 60)  warningLevel[k] =  2;
        else                        warningLevel[k] =  0;
    }
 
   //FML
   if     (distance[4] <= 40)   warningLevel[4] =  1;
   else if(distance[4] <= 60)   warningLevel[4] =  2;
   else if(distance[4] <= 80)   warningLevel[4] =  3;
   else if(distance[4] <= 100)  warningLevel[4] =  4;
   else if(distance[4] <= 120)  warningLevel[4] =  5;
   else                         warningLevel[4] =  0;
   
   //FMR
   if     (distance[5] <= 40)   warningLevel[5] =  1;
   else if(distance[5] <= 60)   warningLevel[5] =  2;
   else if(distance[5] <= 80)   warningLevel[5] =  3;
   else if(distance[5] <= 100)  warningLevel[5] =  4;
   else if(distance[5] <= 120)  warningLevel[5] =  5;
   else                         warningLevel[5] =  0;

   //RML
   if     (distance[6] <= 40)   warningLevel[6] =  1;
   else if(distance[6] <= 60)   warningLevel[6] =  2;
   else if(distance[6] <= 80)   warningLevel[6] =  3;
   else if(distance[6] <= 100)  warningLevel[6] =  4;
   else if(distance[6] <= 120)  warningLevel[6] =  5;
   else if(distance[6] <= 150)  warningLevel[6] =  6;
   else                         warningLevel[6] =  0;

   //RMR
   if     (distance[7] <= 40)   warningLevel[7] =  1;
   else if(distance[7] <= 60)   warningLevel[7] =  2;
   else if(distance[7] <= 80)   warningLevel[7] =  3;
   else if(distance[7] <= 100)  warningLevel[7] =  4;
   else if(distance[7] <= 120)  warningLevel[7] =  5;
   else if(distance[7] <= 150)  warningLevel[7] =  6;
   else                         warningLevel[7] =  0;

   //8:FLS 	9:FRS	10:RLS	11:RRS
   for (U8 i = 8; i <= 11; i++)
	{
	   if     (distance[i] <= 30)   warningLevel[i] = 1;
	   else if(distance[i] <= 60)   warningLevel[i] = 2;
	   else 						warningLevel[i] = 0;
	}
   
    //0:inactive N(1~3):levelN 7:invalid
    can_send_sig(ObjectRange_FL, warningLevel[0]);
    can_send_sig(ObjectRange_FR, warningLevel[1]);
    can_send_sig(ObjectRange_RL, warningLevel[2]);
    can_send_sig(ObjectRange_RR, warningLevel[3]);

    can_send_sig(ObjectRange_FML, warningLevel[4]);
    can_send_sig(ObjectRange_FMR, warningLevel[5]);
    can_send_sig(ObjectRange_RML, warningLevel[6]);
    can_send_sig(ObjectRange_RMR, warningLevel[7]);

	can_send_sig(ObjectRange_FLS, warningLevel[8]);
    can_send_sig(ObjectRange_FRS, warningLevel[9]);
    can_send_sig(ObjectRange_RLS, warningLevel[10]);
    can_send_sig(ObjectRange_RRS, warningLevel[11]);
}


static void clearWarningLevel(void)
{
    can_send_sig(ObjectRange_FL, 0);
    can_send_sig(ObjectRange_FR, 0);
    can_send_sig(ObjectRange_RL, 0);
    can_send_sig(ObjectRange_RR, 0);

    can_send_sig(ObjectRange_FML, 0);
    can_send_sig(ObjectRange_FMR, 0);
    can_send_sig(ObjectRange_RML, 0);
    can_send_sig(ObjectRange_RMR, 0);

	can_send_sig(ObjectRange_FLS, 0);
    can_send_sig(ObjectRange_FRS, 0);
    can_send_sig(ObjectRange_RLS, 0);
    can_send_sig(ObjectRange_RRS, 0);
}

VehiclePdcWorkingState GetUssWorkingState(  void)
{
    return pdcCtrl.VehiclePdcState;
}

void SetUssWorkingState(  VehiclePdcWorkingState state)
{
    pdcCtrl.VehiclePdcState = state;
    if(0 == state)
    {
        SetPasWorkingState(PAS_Work_OFF_STATE);
    }
    else if(1 == state)
    {
        SetPasWorkingState(PAS_Work_STANDBY_STATUS);
    }
    else 
    {
        SetPasWorkingState(PAS_Work_On_STATE);
    }
}

PAS_Work_Status GetPasWorkingState(  void)
{
    return pdcCtrl.VehiclePasWorkState;
}
void SetPasWorkingState(  PAS_Work_Status state)
{
    pdcCtrl.VehiclePasWorkState = state;
}

PAS_Warning_Tone GetPasWarningState(  void)
{
    return pdcCtrl.VehiclePasWarningState;
}
void SetPasWarningState(  PAS_Warning_Tone state)
{
    pdcCtrl.VehiclePasWarningState = state;
}

void clrRadarFaultFlag(void)
{
    pdcCtrl.frontRadarFaultFlag = 0;
    pdcCtrl.rearRadarFaultFlag = 0;

}

static void ussFailWarnTimeoutCb(void *p)
{
    pdcCtrl.uss_self_detect_warning_flag = 0;
    SetPasWarningState(Not_active_tone);
}

static void warnning_3S(void)
{
    pdcCtrl.uss_self_detect_warning_flag = 1;
    SetPasWarningState(Continuous_tone);
    SwTmrMgr_Start(USS_SELF_DETECT_WARN_TMR, 3000, ussFailWarnTimeoutCb, NULL,FALSE);
}

