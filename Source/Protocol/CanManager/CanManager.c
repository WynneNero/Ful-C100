/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ      									   *
*   AUTHOR	   :            										   *
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
* Version       Date        Name                  Changes and comments
*----------------------------------------------------------------------
*  0.1  Feb 20,2017       ZhangJie               Init Version.
*=====================================================================*/

/**** System include files ****/
#include "Can_App_il.h"
#include "CanSig_Def.h"
#include "CanSig_cfg.h"
#include "can_cfg.h"
#include "can_def.h"
#include "Cansig_cfg_if.h"
#include "Hal_if.h"
#include "CanApp.h"
#include "CanNm.h"
#include "ccl.h"
#include "ccl_inc.h"
#include "can_par.h"
#include "CanDiagDtc.h"
#include "Signal_if.h"
#include "CanManager.h"
#include "IL_INC.h"
#include "tpmc.h"
#include "Desc.h"
#include "Candriver_if.h"
#include "ComplexDrvier_Globaldef_IF.h" 
#include "UssInfoMsg.h"

#define CAN_DIAG_TIME_OUT 60*100//Haima UDS specific 60S
#define ACC_WAKEUP_VALUE 0x05
#define PDU_WAKEUP_VALUE 0x02
#define IN_REPEAT_STATE 0x00
#define IN_NORMAL_STATE 0x01
#define STAYAWAKE_REASON_OF_ACC 0x10
#define STAYAWAKE_REASON_OF_ACCOFF15S 0x08
#define STAYAWAKE_REASON_OF_DIAG 0x40
#define TWait_DiagReq 500

/* BYTE2:Wakeup reason */
#define LOCAL_WAKEUP_REASON    0x01
#define CAN_WAKEUP_REASON      0x02

/* BYTE3:Stay awake reason */
#define LOCAL_STAY_AWAKE_REASON  0x01
#define CAN_STAY_AWAKE_REASON    0x02
#define TIMER_NOT_EXPIRED        0x04

/***********************Calibration*****************************/
#define DELAY_3MIN_CNT 18000 

static Nm_StateType gubNmState;  
static Nm_ModeType gubNmMode;
static Nm_StateType  LastNmState=NM_STATE_UNINIT;
static Nm_StateType  LastNmStateBk=NM_STATE_UNINIT;
static CAN_STATE sCanState=E_CAN_NORMAL;
static CAN_STATE PrivateCanState=E_CAN_POWERON;
static U8 can_nm_accstatus=0;									//HW ACC status 
static U8 nm_userdata[6]={0x0,0x0,0x0,0x0,0x0,0x0};				//accodring oem define
static BOOL can_nm_active_status;
static U16	Twait_McuOffCnt;
static BOOL PrivateCanBusBusoff = FALSE;	
static BOOL PublicCanBusBusoff = FALSE;					
static U8   uCanTimerCnt = 0;
static U8   PrivateCanBusOffCnt;
static U8   FristPowerON = TRUE;
static BOOL ReleaseNM = FALSE;
BOOL bApplicationSleepAllowSig;
BOOL bCanOffRecover;
BOOL bCANisOnFlag=FALSE;
static U8  SystemVol = 0;
static U16  HOLD_SOC_POWER_TIMEOUT_Value=1500;
static U32 uSeedCnt;
static U8 ReceAnyMessageFlag = FALSE;
extern U8 dtc_public_bus_off_counter;
extern U8 dtc_private_bus_off_counter;

CAN_STATE GetCanstate(void);
void CanManager_Init(void);
vuint8 ApplCanMsgReceived(CanRxInfoStructPtr rxStruct);
void can_nm_handler(void);
void CanManager_10ms_Entry(void);
void check_can_rx_msg_flag(void);
void CanMsgControlWithVoltage(void);
BOOL CheckNetworkState(void);
void ApplSleep(void);
void  ApplCanInit(vuint8 channel);
void ApplCanBusOff( vuint8 channel);
void ApplCanSetTransciverToNormal(vuint8 channel);
void PrivateCanManager(void);
void PublicCanPassiveHandle(void);
void PrivateCanPassiveHandle(void);
void CanDebugTest(void);

/**********************************************************************************
*  Name        : GetCanstate
*  Description : XCP task polling accodring network state 
*  Called By   : XcpCycleTask
*  Parameter   : sCanState 
				 E_CAN_NORMAL:XCP working
*  Returns	   : 
***********************************************************************************/
CAN_STATE GetCanstate(void)
{
    return sCanState;
}
U32 CanDriver_GetSeed(void)
{
    return uSeedCnt;
}

/**********************************************************************************
*  Name        : CanManager_Init
*  Description : can init when MCU reset 
*  Called By   : SysState_apResetContainer
*  Parameter   : 
*  Returns	   : 
***********************************************************************************/
void CanManager_Init(void)
{
    ApplCanSetTransciverToNormal(CAN_Public); 
	ApplCanSetTransciverToNormal(CAN_Private); 

	PrivateCanBusOffCnt = 0;
    ApplCanInit(CAN_Public);   							
    ApplCanInit(CAN_Private);
	
    sCanState = E_CAN_POWERON;
	POWER_5V0_ON();
}

/***********************************************************************************
*  Name 	   : ApplCanMsgReceived 
*  Description : if massages communication will enter and received diag service
*  Parameter   : 
*  Protocol    : 
*  Returns	   : 1 or 0	
***********************************************************************************/
vuint8 ApplCanMsgReceived(CanRxInfoStructPtr rxStruct)
{
	vuint16 rx_id = CanRxActualId(rxStruct);
	U8 can_nm_accstatus;
	CS_SIG_SyncReceive(SIG_ACCSTATUS,&can_nm_accstatus);

	if((rx_id >= 0x580)&&(rx_id <= 0x5FF))	
	{
		if((can_nm_accstatus == FALSE )&&((gubNmState == NM_STATE_BUS_SLEEP)||(gubNmState == NM_STATE_PREPARE_BUS_SLEEP)))			
		{
			if(gubNmState == NM_STATE_BUS_SLEEP)
			{
				nm_userdata[0] = CAN_WAKEUP_REASON; 		
			}
			nm_userdata[1] = CAN_STAY_AWAKE_REASON|TIMER_NOT_EXPIRED;	
			CanNm_SetUserData(0,nm_userdata);	
		}
	}

	if(gubNmState == NM_STATE_BUS_SLEEP)
	{
		ReceAnyMessageFlag = TRUE;
		nm_userdata[1] = CAN_STAY_AWAKE_REASON|TIMER_NOT_EXPIRED;	
		CanNm_SetUserData(0,nm_userdata);	
	}

	return kCanCopyData; 
}
/***********************************************************************
*  Name        : can_nm_handler
*  Description : manager nm status and request nm
*  Called By   : CanManager_10ms_Entry
*  Parameter   : gubNmState
					NM_STATE_UNINIT 				= 0u  Uninitialized State
					NM_STATE_BUS_SLEEP				= 1u  Bus-Sleep State
					NM_STATE_PREPARE_BUS_SLEEP		= 2u  Prepare Bus-Sleep State
					NM_STATE_READY_SLEEP			= 3u  Ready Sleep State
					NM_STATE_NORMAL_OPERATION		= 4u  Normal Operation State
					NM_STATE_REPEAT_MESSAGE 		= 5u  Repeat Message State
					NM_STATE_SYNCHRONIZE			= 6u  Synchronized State
					NM_STATE_WAIT_CHECK_ACTIVATION	= 7u  Wait Check Activation
					NM_STATE_WAIT_NETWORK_STARTUP	= 8u  Wait Network Startup
					NM_STATE_BUS_OFF				= 9u  BusOff
				gubNmMode
					NM_MODE_BUS_SLEEP           = 0u,  Bus-Sleep Mode
					NM_MODE_PREPARE_BUS_SLEEP   = 1u,  Prepare Bus-Sleep Mode
					NM_MODE_SYNCHRONIZE         = 2u,  Synchronized Mode
					NM_MODE_NETWORK             = 3u   Network Mode
*  Returns     : None
***********************************************************************/
void can_nm_handler(void)
{
	CclScheduleTask();														//NM Task must to be called 
	CclPollingTask();														//NM Task must to be called 
	Nm_GetState (CAN_Public , &gubNmState, &gubNmMode );
    if(LastNmState!=gubNmState)
    {
        LastNmStateBk=LastNmState;
        LastNmState=gubNmState;
		CS_SIG_SyncSend(SIG_CAN_PRE_NM_STATE, &LastNmStateBk);
		CS_SIG_SyncSend(SIG_CAN_CUR_NM_STATE, &LastNmState);
    }		
	
	switch(gubNmState)
	{
	  case NM_STATE_UNINIT:
	  	ReceAnyMessageFlag = FALSE;
		if(can_nm_accstatus == TRUE)
		  {
			nm_userdata[0] = LOCAL_WAKEUP_REASON;
			nm_userdata[1] = LOCAL_STAY_AWAKE_REASON; 
			CanNm_SetUserData(CAN_Public,nm_userdata);
			CanNm_NetworkRequest(CAN_Public);	
		    FristPowerON = FALSE;
		  }
		 break;
	  
	  case NM_STATE_BUS_SLEEP:  /* FAW NM Staus: NMBusSleep */ 
	  		if(ReceAnyMessageFlag)
	  		{
				ReceAnyMessageFlag = FALSE;
				nm_userdata[0] = CAN_WAKEUP_REASON;
				CanNm_SetUserData(CAN_Public,nm_userdata);
				CanNm_NetworkRequest(CAN_Public);
			}
	  
			if(((V_L_ABNORMAL == SystemVol)||(V_H_ABNORMAL == SystemVol)||(V_INIT==SystemVol))&&(FristPowerON==TRUE))
			{
				if(can_nm_accstatus == FALSE)
				{
					FristPowerON = TRUE;	
				}
			}
			else 
			{
				if(can_nm_accstatus == TRUE)
				{
					nm_userdata[0] = LOCAL_WAKEUP_REASON;
					nm_userdata[1] = LOCAL_STAY_AWAKE_REASON;
					CanNm_SetUserData(CAN_Public,nm_userdata);
					CanNm_NetworkRequest(CAN_Public);
					FristPowerON = FALSE;
				} 
				if((LastNmStateBk==NM_STATE_PREPARE_BUS_SLEEP)&&(LastNmState==NM_STATE_BUS_SLEEP))//from PREPARE_BUS_SLEE to BUS_SLEEP
			    {
				    ReleaseNM = TRUE;	
					Twait_McuOffCnt=0;//release nm from PREPARE_BUS_SLEE to BUS_SLEEP
				    LastNmState=NM_STATE_UNINIT;
			    } 
			}
		  break;
	  case NM_STATE_REPEAT_MESSAGE:  /* FAW NM Staus: NMStart */
	  	  ReceAnyMessageFlag = FALSE; 
		  CanNm_NetworkRequest(CAN_Public);
		  if(can_nm_accstatus == TRUE) 
		  {
		  	//local sleep condition not satisfied(e.g. IG On).
			nm_userdata[1] = LOCAL_STAY_AWAKE_REASON;
		  }
		  else
		  {
		  	//local sleep condition satisfied but TActive_Min(500ms) not expired
			nm_userdata[1] |= TIMER_NOT_EXPIRED; 
			nm_userdata[1] |= CAN_STAY_AWAKE_REASON; 
			nm_userdata[1] &= (~LOCAL_STAY_AWAKE_REASON);
		  }
		  CanNm_SetUserData(CAN_Public,nm_userdata);
		  FristPowerON = FALSE;
		  break;
	  case NM_STATE_NORMAL_OPERATION: /* FAW NM Staus: NMNormal */ 	
			if(can_nm_accstatus)
			{
				CanNm_NetworkRequest(CAN_Public);
				nm_userdata[1] = LOCAL_STAY_AWAKE_REASON;			 
			}
			else
			{
				CanNm_NetworkRelease(CAN_Public);
				//nm_userdata[1] &= (~LOCAL_STAY_AWAKE_REASON);		
			}
			CanNm_SetUserData(CAN_Public,nm_userdata);
			FristPowerON = FALSE;
		  break;
	  case NM_STATE_READY_SLEEP:      /* FAW NM Staus: NMNormalPresleep */ 		
			if(can_nm_accstatus == TRUE)
			{
				nm_userdata[1] = LOCAL_STAY_AWAKE_REASON;	
				CanNm_NetworkRequest(CAN_Public);
			}
			CanNm_SetUserData(CAN_Public,nm_userdata);
		   break;
	 case NM_STATE_PREPARE_BUS_SLEEP:   /* FAW NM Staus: NMWaitBusSleep */ 		
		  if(can_nm_accstatus == TRUE)
		  {
		  	nm_userdata[1] = LOCAL_STAY_AWAKE_REASON;		
			CanNm_NetworkRequest(CAN_Public);
		  }

		  CanNm_SetUserData(CAN_Public,nm_userdata);		
		  break;
	  
	  default:
	  break;
	}

}

/***********************************************************************
*  Name        : PrivateCanManager
*  Description : detect Private can IGN state
*  Called By   : can_nm_handler
*  Parameter   : none
*  Returns     : None
***********************************************************************/
void PrivateCanManager(void)
{
	static Nm_StateType PrivateNmState,PrivateNmStateBk;
	PrivateNmState = gubNmState;
	if(PrivateNmState != PrivateNmStateBk)
	{
		switch(PrivateNmState)
		{
			case NM_STATE_UNINIT: PrivateCanState = E_CAN_SLEEP; break;
			case NM_STATE_BUS_SLEEP: PrivateCanState = E_CAN_SLEEP; break;
			case NM_STATE_REPEAT_MESSAGE: PrivateCanState = E_CAN_POWERON; break; 		//need IlTxStart
			case NM_STATE_NORMAL_OPERATION: PrivateCanState = E_CAN_POWERON; break;      //need IlTxStart
			case NM_STATE_READY_SLEEP: PrivateCanState = E_CAN_POWERON; break;           //need IlTxStart
			case NM_STATE_PREPARE_BUS_SLEEP: PrivateCanState = E_CAN_SLEEP; break;
			default:break;
		}
		PrivateNmStateBk = PrivateNmState;
	}
	switch(PrivateCanState)
	{
		case E_CAN_IDIT:
		break;
		
		case E_CAN_POWERON:
	        IlTxStart(CAN_Private);
	        IlRxStart(CAN_Private);
			PrivateCanState = E_CAN_NORMAL;
			uCanTimerCnt =0;
	    break;
		
		case E_CAN_NORMAL:
			if(PrivateCanBusBusoff == TRUE)
		    {
		        IlTxStop(CAN_Private);
				PrivateCanState = E_CAN_EER;
				uCanTimerCnt =0;
		    }
		break;
			
		case E_CAN_SLEEP:
	        IlTxStop(CAN_Private);
	        IlRxStop(CAN_Private);
	        PrivateCanState = E_CAN_IDIT;
	    break;
		
		case E_CAN_EER:
	        if(PrivateCanBusOffCnt<=BUS_OFF_ENTER_QUICK_RECOVER_MODE_TIME_CNT)
	        {
	            if(uCanTimerCnt++>(LOW_POWER_OFF_RECOVER_TIME))
	            {
	            	PrivateCanState = E_CAN_NORMAL;
	                IlTxStart(CAN_Private);
					PrivateCanBusBusoff = FALSE;
	                uCanTimerCnt =0;
	                PrivateCanBusOffCnt ++;
	                if(PrivateCanBusOffCnt>250)		PrivateCanBusOffCnt = 250;
	            }
	        }
	        else
	        {
	            if(uCanTimerCnt++>(QUICK_POWER_OFF_RECOVER_TIME))
	            {
	            	PrivateCanState = E_CAN_NORMAL;
	                IlTxStart(CAN_Private);
					PrivateCanBusBusoff = FALSE;
	                uCanTimerCnt =0;
	                PrivateCanBusOffCnt ++;
	                if(PrivateCanBusOffCnt>250)		PrivateCanBusOffCnt = 250;
	            }
	        }
	   break;
	   default:
	   break;
	}
}

/***********************************************************************
*  Name        : CanManager_10ms_Entry
*  Description : manager  NM handler  and transceiver,soc,mcu wakeup and sleep
*  Called By   : S0 S2 S3
*  Parameter   : 
*  Returns     : None
***********************************************************************/
void CanManager_10ms_Entry(void)
{
	U8 can_rx_data;
	U8 bI_CANOff=FALSE;
	static U8 is_reset_cnt = 0;
	U16 calibrationDoneCntTime = 0;
	static U16	WaitNMsleeptimeout_cnt;
	static U16  delay3minCnt;
    CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &SystemVol);
    SystemVol = (E_SYSTEM_VOLTAGE_STATUS)SystemVol;
    CS_SIG_SyncReceive(SIG_ACCSTATUS, &can_nm_accstatus);
	
	if(PublicCanBusBusoff)
	{
		can_diag_increase_public_bus_off_counter(); 
	}	

	if(PrivateCanBusBusoff)
	{
		can_diag_increase_private_bus_off_counter(); 
	}

	if(GetMmiTouchDebugFlag()==1)
	{
		CanDebugTest();
	}

	switch(sCanState)
	{
		case E_CAN_IDIT:
			if((CAN1_GET_INH() == FALSE))
			{
				sCanState = E_CAN_POWERON;
				FristPowerON = TRUE;
			}	
			if(can_nm_accstatus == TRUE)
			{
			    sCanState = E_CAN_POWERON;
			}
			else
			{
				if(WaitNMsleeptimeout_cnt++>400)
				{
					sCanState = E_CAN_SLEEP ;
					WaitNMsleeptimeout_cnt = 0;
				}
			}			
		break;
		case E_CAN_POWERON:
			ApplCanInit(CAN_Public); 
			ApplCanInit(CAN_Private);  
   			ApplCanSetTransciverToNormal(CAN_Public); 
			ApplCanSetTransciverToNormal(CAN_Private); 		
			bApplicationSleepAllowSig = FALSE;
			IlTxStart(CAN_Private);
	        IlRxStart(CAN_Private);
			sCanState = E_CAN_NORMAL;
			//not add break; in order to enter Normal at once
			
		case E_CAN_NORMAL:
			can_nm_handler();
			PrivateCanManager();
			if(TRUE == can_ack_detect_nm_enable_check()){
				PublicCanPassiveHandle();
				PrivateCanPassiveHandle();
			}
 		  	if(EED_u8SocCalibrationDoneFlag == TRUE)
			{
				bApplicationSleepAllowSig = FALSE;			/*hold soc */
				delay3minCnt++;
				if(delay3minCnt > DELAY_3MIN_CNT)
				{
					EED_LockDataBlock(EED_nEOLConfig);
					EED_u8SocCalibrationDoneFlag = 0x00;
					EED_UnlockAndSavDataBlock(EED_nEOLConfig);
					delay3minCnt=0;
				}
			}
			else
			{
				if(ReleaseNM == TRUE)
				{
					 sCanState = E_CAN_SLEEP;
					 ReleaseNM = FALSE;
				}
				else if((FristPowerON==TRUE))
			    {
				    if(Twait_McuOffCnt++ >100)					//first power ON wait 1000ms to  ensure valid wakeup event
				    {		
				      Twait_McuOffCnt=0; 
					  sCanState = E_CAN_SLEEP;
				    }
			    }
			}
			break;
		case E_CAN_SLEEP:
			ApplSleep();
	    	bApplicationSleepAllowSig = TRUE;
			if(can_nm_accstatus == TRUE)
			{
			    sCanState = E_CAN_POWERON;
			}
			else
			{
				sCanState = E_CAN_IDIT;
			}
			break;
		default:
			break;
	}
	CanMsgControlWithVoltage();							//voltage detect
	
	if( uSeedCnt++>0xFFFFFFF0)
	{
		 uSeedCnt = 0x0123;
	}
}

/***********************************************************************
*  Name        : ApplCanSetTransciverToNormal
*  Description : turn the transceiver to Normal mode
*  Called By   : CanManager_10ms_Entry\CanManager_Init
*  Parameter   : NONE
*  Returns     : NONE
***********************************************************************/
void ApplCanSetTransciverToNormal(vuint8 channel)
{
	if(channel == CAN_Public)
	{ 	
		CAN1_SET_WAKE();
	    delay_us(100);
	    CAN1_CLR_WAKE();
	    CAN1_SET_EN();
	    CAN1_SET_STB();
	}
	else if(channel == CAN_Private)
	{
	    CAN0_SET_WAKE();
	    delay_us(100);
	    CAN0_CLR_WAKE();
	    CAN0_SET_EN();
	    CAN0_SET_STB();		
	}
}
/***********************************************************************
*  Name        : ApplCanInit
*  Description : turn the transceiver to Normal mode
*  Called By   : CanManager_Init
*  Parameter   : NONE
*  Returns     : NONE
***********************************************************************/
void  ApplCanInit(vuint8 channel   )
{
	if(channel == CAN_Public)
	{
		U8 i = 0;
		CanInitPowerOn();
		IlInitPowerOn();
		TpInitPowerOn();
		CclInitPowerOn();
		CclEnableCommunication(CAN_Public);
		DescInitPowerOn(CAN_Public);

		for(i=0;i<6;i++)
		{
			nm_userdata[i] = 0x0;
		}

		CanNm_SetUserData(CAN_Public,nm_userdata);		
	}
	else if(channel == CAN_Private)
	{
		CanInitPowerOn();
		IlInitPowerOn();
		TpInitPowerOn();
		DescInitPowerOn(CAN_Private);
		
		//CclInitPowerOn();
		CclEnableCommunication(CAN_Private);
	}
}
/***********************************************************************
*  Name        : ApplSleep
*  Description : Turn off 5V and set transceiver to sleep
*  CALLED BY:    CanManager_10ms_Entry
*  Parameter   : NONE
*  Returns     : None
***********************************************************************/
void ApplSleep(void)
{
	if(CAN1_GET_ERR() == FALSE)							//aviod (because of CANEER go to sleep)
	{
		ApplCanSetTransciverToNormal(CAN_Public);
		ApplCanSetTransciverToNormal(CAN_Private);
		delay_us(100);
	}
	delay_us(2000);
	CAN0_CLR_STB();
	CAN1_CLR_STB();
	CAN0_SET_EN();
	CAN1_SET_EN();
	delay_us(110);
	CAN0_CLR_EN();
	CAN1_CLR_EN();
	delay_us(60000);
	POWER_5V0_OFF();
}

void PublicCanPassiveHandle(void)
{
	static U8 uPublicCanPassiveNoACKTimerCnt = 0;
	static U8 uPublicCanPassivePauseTimerCnt = 0;
	static BOOL PublicCanPassivePaused = FALSE;

	if((V_L_ABNORMAL == SystemVol)||(V_H_ABNORMAL == SystemVol))
		return;
	
	if(CanGetStatus(CAN_Public)== 0x25)
	{
		uPublicCanPassiveNoACKTimerCnt++;
		if(uPublicCanPassiveNoACKTimerCnt >= TNoACK)
		{
			CanOffline(CAN_Public);		
		    CanInit(CAN_Public,0);
			uPublicCanPassiveNoACKTimerCnt = 0;
			PublicCanPassivePaused = TRUE;
		}
	}
	else if(PublicCanPassivePaused)
	{
		uPublicCanPassivePauseTimerCnt++;
		if(uPublicCanPassivePauseTimerCnt >= TPause)
		{
		   CanOnline(CAN_Public);
		   uPublicCanPassivePauseTimerCnt = 0;
		   uPublicCanPassiveNoACKTimerCnt = 0;
	       PublicCanPassivePaused = FALSE;
		}
	}
    else 
    {
	    uPublicCanPassiveNoACKTimerCnt = 0;	
    }
}

void PrivateCanPassiveHandle(void)
{
	static U8 uPrivateCanPassiveNoACKTimerCnt = 0;
	static U8 uPrivateCanPassivePauseTimerCnt = 0;
	static BOOL PrivateCanPassivePaused = FALSE;

	if((V_L_ABNORMAL == SystemVol)||(V_H_ABNORMAL == SystemVol))
		return;
	
	if(CanGetStatus(CAN_Private)== 0x25)
	{
		uPrivateCanPassiveNoACKTimerCnt++;
		if(uPrivateCanPassiveNoACKTimerCnt >= TNoACK)
		{
			CanOffline(CAN_Private);			
			CanInit(CAN_Private,0);
			uPrivateCanPassiveNoACKTimerCnt = 0;
			PrivateCanPassivePaused = TRUE;
		}
	}
	else if(PrivateCanPassivePaused)
	{
		uPrivateCanPassivePauseTimerCnt++;
		if(uPrivateCanPassivePauseTimerCnt >= TPause)
		{
		   CanOnline(CAN_Private);
		   uPrivateCanPassivePauseTimerCnt = 0;
		   uPrivateCanPassiveNoACKTimerCnt = 0;
	       PrivateCanPassivePaused = FALSE;
		}
	}
    else 
    {
	    uPrivateCanPassiveNoACKTimerCnt = 0;	
    }

}

/***********************************************************************
*  Name 	   : ApplCclComStart
*  Description : The can bus start( NM request will be called)
*  Parameter   : can_nm_active_status 1: Enter Normal mode from bus sleep
*  Called By   : CclComStart
*  Returns	   : None
***********************************************************************/
void ApplCclComStart(vuint8 channel)
{
    if(channel==CAN_Public)
    {
        ReleaseNM = FALSE;
		ReceAnyMessageFlag = FALSE;
		FristPowerON = TRUE;
		Twait_McuOffCnt=0;
		can_nm_active_status = TRUE;
		can_sig_init();	
    }
    else if(channel==CAN_Private)
    {
        IlTxStart(CAN_Private);
        //IlRxStart(CAN_Private);
    }
}

/***********************************************************************
*  Name 	   : ApplCclComStop
*  Description : The can bus stop( NM enter bus sleep mode will be called)
				 NOTE:first power on will called at a time 
				 From NM PrepareSleep to BusSleep mode(active before ApplCclCanStandby() function)
				 
*  Parameter   : can_nm_active_status 0: Enter bus sleep mode
*  Called By   : CclComStart
*  Returns	   : None
***********************************************************************/
void ApplCclComStop(vuint8 channel) // From NM PrepareSleep to BusSleep mode(active before ApplCclCanStandby() function)
{
    if(channel==CAN_Public)
    {
     	can_nm_active_status = FALSE;
    }
    else if(channel==CAN_Private)
    {
		IlTxStop(CAN_Private);
    }
}

vuint8 ApplCclCanStandby(vuint8 channel,vuint8 sleepResult)// IN BusSleep mode ,CCL will set CAN controller to Sleep mode
{
    return 1;
}

void ApplCclInit ( CanChannelHandle channel ){}
void ApplCclInitTrcv  ( CanChannelHandle channel ){}  // Init Transciver to
void ApplCclWakeUpTrcv  ( CanChannelHandle channel ){} // Set Transciver to normal mode
void ApplCclSleepTrcv  ( CanChannelHandle channel ){} // Set Transciver to Sleep mode
void ApplCclNmStateChange(vuint8 channel,vuint8 activeState, vuint8 targetState){}
void ApplCclStandbyTrcv  ( CanChannelHandle channel ){} // Set Transciver to standby mode
void ApplCclComWait  ( CanChannelHandle channel ){} //From NM ReadytoSleep to PrepareSleep mode
void ApplCclComResume  ( CanChannelHandle channel ){} //From NM PrepareSleep to RepeatMessage mode

/***********************************************************************
*  Name 	   : ApplCclBusOffEnd
*  Description : Try to recover busoff at a time will be called 	 
*  Parameter   : gubCANBusOffFlag  0: bus off had recover for once
*  Called By   : 
*  Returns	   : None
***********************************************************************/
void ApplCclBusOffEnd (vuint8 channel) //Busoff end indication
{
    if(channel==CAN_Public)
    {
		PublicCanBusBusoff = FALSE;
    }
    else if(channel==CAN_Private)
    {

    }	
}
/***********************************************************************
*  Name 	   : ApplCclBusOffStart
*  Description : busoff had occurred in the bus, will be called 	 
*  Parameter   : gubCANBusOffFlag  0: bus off had recover for once
*  Called By   : 
*  Returns	   : None
***********************************************************************/
void ApplCclBusOffStart (vuint8 channel) 
{
    if(channel==CAN_Public)
    {
		PublicCanBusBusoff = TRUE;	
    }
    else if(channel==CAN_Private)
    {
    
    }	
}

/***********************************************************************
*  Name 	   : ApplCanTxConfirmation
*  Description : whichever massage had sent successfully will be called
*  Parameter   : gubCANBusOffFlag  0: bus off had been recovered in the buss
*  Called By   : uk
*  Returns	   : None
***********************************************************************/

void ApplCanTxConfirmation(CanTxInfoStructPtr txStruct)
{
    if(txStruct->Channel==CAN_Public)
    {
		if(PublicCanBusBusoff)
		{
			PublicCanBusBusoff = FALSE;
		}
		
		if(dtc_public_bus_off_counter != 0)
		{
			dtc_public_bus_off_counter = 0;
		}	
    }
    else if(txStruct->Channel==CAN_Private)
    {
		if(PrivateCanBusBusoff)
		{
			PrivateCanBusBusoff = FALSE;
		}
		PrivateCanBusOffCnt = 0;
		if(dtc_private_bus_off_counter != 0)
		{
			dtc_private_bus_off_counter = 0;
		}
    }
}

/***********************************************************************
*  Name        : CanMsgControlWithVoltage
*  Description : control can transmission accodring the voltage
*  Called By   : CanManager_10ms_Entry
*  Parameter   : SystemVol
	  				V_L_ABNORMAL:  3.3~6.5V
	  				V_H_ABNORMAL:  18.5V~
	  				V_INIT      ï¼?init
*  Returns     : NONE
***********************************************************************/
void CanMsgControlWithVoltage(void)
{
	static U8 bstopflag = FALSE;
	static U8 SystemVol_backup;
	if(SystemVol_backup!=SystemVol)
	{
	   if((V_L_ABNORMAL == SystemVol)||(V_H_ABNORMAL == SystemVol))
	   {
			CanOffline(CAN_Public);
			CanOffline(CAN_Private);
			bstopflag = TRUE;
			
	   }else{
			if(bstopflag)
			{
				CanOnline(CAN_Public);
				CanOnline(CAN_Private);
				bstopflag =FALSE;
			}	
	   }
		SystemVol_backup=SystemVol;
	}	
}

/***********************************************************************
*  Name        : CheckNetworkState
*  Description : whether turn of SOC accodring network status 
*  Called By   : SocManager_5ms_Entry
*  Parameter   : can_nm_active_status 
				    TRUE:   NM in normal mode
				    FALSE:  NM enter bussleep mode
*  Returns     : FALSE: Turnoff SOC  
    			 TRUE:  Stay SOC ON
***********************************************************************/
BOOL CheckNetworkState(void) 
{
	U16 acc_status_for_sleep_used=0;
	BOOL _ret = TRUE;
	CS_SIG_SyncReceive(SIG_ACCSTATUS,&acc_status_for_sleep_used);
	
	if((0x0==acc_status_for_sleep_used)&&(FALSE==can_nm_active_status)&&(EED_u8SocCalibrationDoneFlag==FALSE))
	{
		_ret = FALSE;
	}
	return _ret;
}

void ApplCanBusOff( vuint8 channel)
{
	if(channel==CAN_Private)
    { 
    	CanInit(CAN_Private,0);
        PrivateCanBusBusoff = TRUE;
    }
}

void ApplCanOverrun(vuint8 channel)
{

}
void set_fast_powerdown(U16 timeout)
{
	HOLD_SOC_POWER_TIMEOUT_Value = timeout;//500=5S
}
BOOL GetApplicationSleepAllowSig(void)
{
	return bApplicationSleepAllowSig;
}


void CanDebugTest(void)
{
	U8 UesrCanSta[2];
	static U16 CanTaskAlvieCnt;
	static U8 Cnt_500MS;
	UesrCanSta[CAN_Public] = CanGetStatus(CAN_Public);
	UesrCanSta[CAN_Private] = CanGetStatus(CAN_Private);

	can_send_sig(PubuicCanSta,UesrCanSta[CAN_Public]);
	can_send_sig(PrivateCanSta,UesrCanSta[CAN_Private]);
	
	Cnt_500MS++;
	if(Cnt_500MS >= 25)
	{
		Cnt_500MS = 0;
		CanTaskAlvieCnt++;
		can_send_sig(CanTaskAlive,CanTaskAlvieCnt);
		if(CanTaskAlvieCnt >= 20) //10s
		{
			CanTaskAlvieCnt = 0;
		}
	}
}
