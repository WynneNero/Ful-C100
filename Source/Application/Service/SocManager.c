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
/*-History--------------------------------------------------------------
* Version       Date            Name            Changes and comments
* ----------------------------------------------------------------------
*  0.1          2016/8/29   ShangQiuju      Init version
* ----------------------------------------------------------------------
*  0.2 	    2016/10/12  ShangQiuju      Add handler of Swdl status event.
* ----------------------------------------------------------------------
*  0.3 	    2016/12/26  ShangQiuju      Change OPEN_TEST include source.
* ----------------------------------------------------------------------
*  0.4 	    2017/1/3      ShangQiuju      Remove unued test code.
*----------------------------------------------------------------------
*  0.5          2017/1/6      ShangQiuju       Update CS_SIG_AsyncReceive according SIG module update.
*----------------------------------------------------------------------
*  0.6          2017/1/13    ShangQiuju       Fix recoverity warnings.
*----------------------------------------------------------------------
*  0.7          2017/2/10    ShangQiuju       Init parameters.
*----------------------------------------------------------------------
*  0.8          2017/2/13    ShangQiuju       Fix warnings.
*-----------------------------------------------------------------------
*  0.9          2017/3/7      ShangQiuju       Add Spi dual buffer communication test of eol.
*-----------------------------------------------------------------------
*  1.0          2017/3/13    ShangQiuju       Add eol spi upgrade test function.
*----------------------------------------------------------------------------------------------
*  1.1          2017/3/31    ZhangJie           Extend Uart date length.
*=====================================================================*/
#include "config.h"
#include "SocManager.h"
#include "SocCommunicator.h"
#include "TYPES.h"
#include "Signal_if.h"
#include "CanApp.h"
#include "CanManager.h"
#include "CanDiagService.h"
#include "ComplexDrvier_Globaldef_IF.H"
#include "SocDriver.H"
#include "SocMsg_Cfg.h"
#include "eol_app.h"
#include "xprintf.h"



E_SOC_STATE eSocState;

U8 uErrorTimer;
U16 uWaitNaviRespCnt;
U8 uNaviConnectedFailCnt;
U8 SendBuf[SOC_FRAME_MAXLENGTH];

//receive request
BOOL bFirstConnected;
BOOL bPowerUpOK;
BOOL bJ6RequestToReset;
U16 SentCommandid;
BOOL IsSent;
U8 uSentFailCount;
BOOL bSocConnectedStatus;
BOOL bComAllow; 
BOOL bPowerOnAllow;

SOC_CONNECTED_STATE sSocConnectedState;
BOOL watchDogIn=FALSE;
BOOL watchDogInPre=FALSE;
BOOL bSOCLostWDG=FALSE;
BOOL B_SOCCommError=FALSE;
BOOL SOC_WATCHDOG_SWITCH = TRUE;
BOOL SOC_WATCHDOG_SWITCH_Backup = TRUE;
U16 watchDogLostCnt=0;
U16 ClosePMICCnt=0;
BOOL eol_shultdown_cpu_watchdog=FALSE;
U8 VolSocNormalCnt = 0;
U8 VolSocLHCnt = 0;

/* SOC heart beat detection */
static BOOL socHeartBeat_UpdateSocSts = FALSE;
static BOOL socHeartBeat_Switch = FALSE;
static U16 socHeartBeat_Cnt = 0;
BOOL B_AppHeartBeatError=FALSE;         /* APP HeartBeat Error Flag */

STATIC void DataReset(void);
void DataHandler(void);
void GotoError(void);
void Dispatcher_RepMsg(U8 cmpt_id,U16 commandid, U8* data);
void Dispatcher_SentResult(U16 commandid, BOOL result);
void Monitor_CPU_WatchDog(void);
static void Monitor_CPU_HeartBeat(void);
/***********************************************************************
*  Name        : SocManager_Init
*  Description : Init driver manager        
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_Init(void)
{
  eSocState=E_SOC_IDLE;
  bSocConnectedStatus = FALSE;
  CS_SIG_SyncSend(SIG_B_SOC_CONNECTED,(U8*)&bSocConnectedStatus);
  sSocConnectedState = E_SOC_CONNECTED_STARTED;
  bJ6RequestToReset = FALSE;
  SOC_WATCHDOG_SWITCH = EED_u8SocWatchdogSwitch[0];
  DataReset();
}

/***********************************************************************
*  Name        : SocManager_DeInit
*  Description : DeInit driver manager        
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_DeInit(void)
{
    eSocState = E_SOC_IDLE;
}


/***********************************************************************
*  Name        : Monitor_headuint
*  Description : Get driver manager status
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Monitor_headuint(void)
{
  ///ADD SOC STATE MONITOR IF NEED TO SEND SIGNAL 
    if(sSocConnectedState !=E_SOC_CONNECTED_FINISHED)
    {
        bSocConnectedStatus = FALSE;
        CS_SIG_SyncSend(SIG_B_SOC_CONNECTED,(U8*)&bSocConnectedStatus);
    }
    else
    {
        bSocConnectedStatus = TRUE;
        CS_SIG_SyncSend(SIG_B_SOC_CONNECTED,(U8*)&bSocConnectedStatus);
    }
}

void ConnenctedHandler(void)
{
    U8 SocconnectError = 0;
    switch(sSocConnectedState)
    {
    case E_SOC_CONNECTED_STARTED:
        sSocConnectedState = E_SOC_CONNECTED_WAIT_FIRST_CONNECT_COMPLETE_EVENT; 
        uWaitNaviRespCnt = 0;
        bFirstConnected = FALSE;
    break;
    case E_SOC_CONNECTED_WAIT_FIRST_CONNECT_COMPLETE_EVENT:
        if(uWaitNaviRespCnt++>NAVI_FIRST_CONNECT_RESP_TIME)
        {
            sSocConnectedState = E_SOC_CONNECTED_ERROR;
        }
        if(bFirstConnected)
        {
            sSocConnectedState = E_SOC_CONNECTED_SEND_POWERUP_REQ;
        }
    break;
    case E_SOC_CONNECTED_SEND_POWERUP_REQ:
        uWaitNaviRespCnt = 0;
        sSocConnectedState = E_SOC_CONNECTED_WAIT_POWERUP_RESP;
    break;
    case E_SOC_CONNECTED_WAIT_POWERUP_RESP:
        if(uWaitNaviRespCnt++>NAVI_NORMAL_RESP_TIME)
        {
            sSocConnectedState = E_SOC_CONNECTED_ERROR;
        }
        if(bPowerUpOK)
        {
            sSocConnectedState = E_SOC_CONNECTED_FINISHED;
        }        
    break;
    case E_SOC_CONNECTED_FINISHED:
        //do nothing
    break;
    case E_SOC_CONNECTED_ERROR:
		SocconnectError = TRUE;
		CS_SIG_SyncSend(SIG_B_NAVICOMMERROR, (U8*)&SocconnectError);
        sSocConnectedState = E_SOC_CONNECTED_STARTED;	 
        uNaviConnectedFailCnt++;
        if(uNaviConnectedFailCnt>NAVI_CONNECTED_FAIL_TIMES)
        {
            uNaviConnectedFailCnt = 209;
	    sSocConnectedState = E_SOC_CONNECTED_FAILED;
        }        
    break;
    case E_SOC_CONNECTED_FAILED:
        ///TODO:OSWDG_SoftReset();
    break;
    default:break;
    }
}

/***********************************************************************
*  Name		   : SocCommConditionCheck
*  Description :		   
*  Parameter   : None
*  Returns	   : None
***********************************************************************/
void SocCommConditionCheck(void)
{

}

/***********************************************************************
*  Name		   : SocPowerOnAllowCheck
*  Description :		   
*  Parameter   : None
*  Returns	   : None
***********************************************************************/
//U16 bHoldSocPowerTimeCount=0;
//#define HOLD_SOC_POWER_TIME     9000//180S T=20ms*9000
void SocPowerOnAllowCheck(void)
{
   U8 AccStatus=0;
   U8 vol_status=0;
   CS_SIG_SyncReceive(SIG_ACCSTATUS, &AccStatus);
   CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &vol_status);   

   if(vol_status == V_NORMAL)  // LLF MASK
   {
   		VolSocNormalCnt++;
		VolSocLHCnt=0;
		if(VolSocNormalCnt > VOL_SOC_DOWN_CNT)
		{
			if((CheckNetworkState()==TRUE)&&(bSOCLostWDG == FALSE))  //network is allower to sleep 
			{
				bPowerOnAllow = TRUE;
				bComAllow = TRUE; 
				bCANisOnFlag = TRUE;
			}
			else
			{
				bPowerOnAllow = FALSE;
				bComAllow = FALSE; 
				bCANisOnFlag = FALSE;
			}
			VolSocNormalCnt = VOL_SOC_DOWN_CNT;
		}
   }
   else if((vol_status == V_L_ABNORMAL)||(vol_status == V_H_ABNORMAL)||(vol_status == V_LOW)||(vol_status == V_HIGH))
   {
   		VolSocLHCnt++;
		VolSocNormalCnt=0;
		if(VolSocLHCnt > VOL_SOC_UP_CNT)
		{
			bPowerOnAllow = FALSE;
			bComAllow = FALSE; 
			VolSocLHCnt=VOL_SOC_UP_CNT;
		}
		if(CheckNetworkState()&&(bSOCLostWDG == FALSE))  /*network is allower to sleep*/
		{
			bCANisOnFlag = TRUE; 
		}
		else 
		{
			bCANisOnFlag = FALSE;
		}
   }
}

/***********************************************************************
*  Name        : NaviService_20msEntry
*  Description :         
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_20msEntry(void)
{
    U8 SocconnectError = 0;
    Monitor_headuint();
    SocCommConditionCheck();
    SocPowerOnAllowCheck();
	CorlCameraStatus();
    switch(eSocState)
    {
        case E_SOC_IDLE:
        if(bPowerOnAllow)  
        {	
			SocMsg_ControlPower(E_DEV_POWERON);
			eSocState = E_SOC_POWER_ON;
        }
        else
        {
            DataHandler();
			if(TRUE==SocMsg_GetPower(E_DEV_POWERON))
			{
				eSocState=E_SOC_POWER_OFF;
			}
        }
        break;
        case E_SOC_POWER_ON:
            if(bPowerOnAllow)
            {
                if(bComAllow)
                {
                    SocMsg_ControlCommunication(TRUE);
                    eSocState=E_SOC_READY;
                }
            }
            else
            {
                eSocState=E_SOC_POWER_OFF;
            }
        break;
        case E_SOC_READY:
            if(!bPowerOnAllow)
            {
                eSocState=E_SOC_POWER_OFF;
            }
            else if(!bComAllow)
            {
                eSocState=E_SOC_POWER_ON;
            }
            else
            {
                //eSocState= E_SOC_CONNECTED;
                ConnenctedHandler();       
                DataHandler();                  
            }            
        break;
        case E_SOC_CONNECTED:
            if(!bPowerOnAllow)
            {
                eSocState=E_SOC_POWER_OFF;
            }
            else if(!bComAllow)
            {
                eSocState=E_SOC_POWER_ON;
            }
            else
            {
                DataHandler(); 
				SocconnectError = FALSE;
				CS_SIG_SyncSend(SIG_B_NAVICOMMERROR, (U8*)&SocconnectError);
                ///TODO: add condition to switch to E_SOC_ERROR_COMMUNICATOR,E_SOC_POWER_OFF
            }           
        break;
        case E_SOC_ERROR_COMMUNICATOR:
            uErrorTimer--;
            if(uErrorTimer==0)
            {
                DataReset();
                eSocState=E_SOC_POWER_ON;
            }
        break;
        case E_SOC_POWER_OFF:
			DataReset();
			SocMsg_ControlCommunication(FALSE);
			SocMsg_ControlPower(E_DEV_POWEROFF);
			eSocState = E_SOC_IDLE;
        break;
        default:
        break;
    }
}


/***********************************************************************
*  Name        : CorlCameraStatus
*  Description : Control Camera      
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void CorlCameraStatus(void)
{
	U8 camCtrlFlag = 0;
	U8 is_camera_power_on = FALSE;
	CS_SIG_SyncReceive(SIG_2F_CAMERA_CONTROL,&camCtrlFlag);
	if((bPowerOnAllow)&&(FALSE == camCtrlFlag))
	{
		SocControlCameraPower();
		CheckCameraPower(); 
	}
	else
	{
		is_camera_power_on = FALSE;
		CS_SIG_SyncSend(SIG_CAMERA_ONOFF, &is_camera_power_on);
		Camera2FHandler();
		
	}
}

BOOL SocManager_SendMsg(U8 q_type, U8 cmd_type, U16 service, U8 nArgs,U8 *pArg)
{
    if(eSocState!=E_SOC_CONNECTED)
    {
        if((service!=RADIO_DISPATCH_CHANGE_POWER_MODE)&&(service!=M3_RESPOND_J6_EOL_STATUS))return FALSE;
    }

	
	if(EolUpdateFlag == TRUE)//this is EOL Upgrade Mode
	{
		if(	(service == RADIO_DISPATCH_CHANGE_POWER_MODE)||(service == M3_RESPOND_J6_EOL_STATUS)||(service == M3_SEND_RESP_OF_J6SELFTEST)
			||(service == RADIO_QUERY_ENG_SW_VERSION)//||(service == RADIO_NOTIFY_VEHICLE_GEAR_STATUS)
			||(service == M3_SEND_RESP_OF_CAMERA_STATUS)||(service == REQ_SOC_TO_SEND_REMOVABLE_DEVICE_STATUS)||(service == NAVI_RESP_EVENT)
			||(service == M3_REQ_J6_ENTER_SELF_DIAG))
		{
			//do nothing
		}
		else
		{
			return FALSE;
		}
	}
	
#if XPRINTF_ENABLE
		int i;
		LOG(SOC_MESSAGE_TRACE,"Write cmd_type 0x%lx\r\n",service);
		LOG(DEFAULT_TRACE,"data: ");
		for(i = 0;i < nArgs;i++)
		{
			LOG(DEFAULT_TRACE,"0x%x ",pArg[i]);
	
		}
		LOG(DEFAULT_TRACE,"\r\n");
#endif

    _memset(SendBuf,0,nArgs+10);
    SendBuf[0] = q_type;
    SendBuf[1] = cmd_type;
    SendBuf[2] = service>>8;
    SendBuf[3] = service&0xff;
    SendBuf[4]= nArgs;
    _memcpy(SendBuf+5, pArg, nArgs);
    return(SocMsg_SendMessage(SendBuf,nArgs+5));
}

//private

void DataHandler(void)
{
	U8 SocPowerStatus;
	CS_SIG_SyncReceive(SIG_B_SOC_POWER_ON, &SocPowerStatus);
	if(bOpenWatchDog) 
	{
		SOC_WATCHDOG_SWITCH = TRUE;		//always openning watchdog after connected with SVP
		bOpenWatchDog = FALSE;
	}
	else
	{
		/*do nothing*/
	}
	if((SOC_WATCHDOG_SWITCH)&&(SocPowerStatus))
	{
		Monitor_CPU_WatchDog();
	}
	else
	{
		watchDogLostCnt= 0;
	}

	if(SOC_WATCHDOG_SWITCH_Backup !=SOC_WATCHDOG_SWITCH)
	{
		SOC_WATCHDOG_SWITCH_Backup = SOC_WATCHDOG_SWITCH;
		EED_LockDataBlock(EED_TestCfg);
		EED_u8SocWatchdogSwitch[0] = SOC_WATCHDOG_SWITCH;
	    EED_UnlockAndSavDataBlock(EED_TestCfg);
	}

    /* Soc Heart Beat Detection */
	Monitor_CPU_HeartBeat();
	
    switch(eSocState)
    { 
        case E_SOC_READY:
               if( E_SOC_CONNECTED_FINISHED == sSocConnectedState )	    eSocState=E_SOC_CONNECTED;   
        break;
        case E_SOC_CONNECTED:  
        break;
        default:break;
    }
}

void GotoError(void)
{
    uErrorTimer=NAVI_ERRORWAIT;	 
    eSocState=E_SOC_ERROR_COMMUNICATOR;	
    SocMsg_ControlCommunication(FALSE);
}

void Monitor_CPU_WatchDog(void)
{
	#ifdef SOC_WATCHDOG
    U8 sig = 0;
	U8 SystemVol = 0;
    CS_SIG_SyncReceive(SIG_SOCWDG_DI_STATUS, &sig);
	CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &SystemVol);
	
    watchDogInPre = watchDogIn;
    watchDogIn = sig&0x01;
    if(watchDogIn!=watchDogInPre)
    {
        watchDogLostCnt= 0;
		bSOCLostWDG=FALSE;
//        B_SOCCommError = FALSE;
//        CS_SIG_SyncSend(SIG_B_NAVICOMMERROR,(U8*)&B_SOCCommError);
    }

	if(eEolState != E_EOL_NORMAL)
	{
		if(SystemVol == V_NORMAL)
		{
			watchDogLostCnt++;
			if(watchDogLostCnt == WATCH_DOG_TIME_OUT_WARNNING)
			{
				B_SOCCommError = TRUE;
				CS_SIG_SyncSend(SIG_B_NAVICOMMERROR,(U8*)&B_SOCCommError);
			}
			
		    if(watchDogLostCnt>=WATCH_DOG_TIME_OUT)
		    {   
		    	bSOCLostWDG=TRUE;
			 	OSWDG_SoftReset();
		    } 
		}

	}
	#endif
}

/***********************************************************************
*  Name        : Monitor_CPU_HeartBeat
*  Description : 
*  Parameter   : None
*  Returns     : None
***********************************************************************/
static void Monitor_CPU_HeartBeat(void)
{
    BOOL eolSts = TRUE;
    U8 systemVol = 0;

    CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &systemVol);
    eolSts = EolApp_IsEolActivated();

    if((TRUE == socHeartBeat_Switch)&&
        (V_NORMAL == systemVol)&&
        (FALSE == eolSts)&&
        (FALSE == socHeartBeat_UpdateSocSts))
    {
        socHeartBeat_Cnt++;
        if(HEART_BEAT_TIME_OUT_WARNNING == socHeartBeat_Cnt)
        {
            B_AppHeartBeatError = TRUE;
            CS_SIG_SyncSend(SIG_B_NAVICOMMERROR, (U8*)&B_AppHeartBeatError);
        }
        else if(HEART_BEAT_TIME_OUT <= socHeartBeat_Cnt)
        {
            OSWDG_SoftReset();
        }
    }
    else
    {
        socHeartBeat_Cnt = 0;
    }

    /* If once again to receive HeartBeat, need to reset error info. */
    if((TRUE == B_AppHeartBeatError)&&(HEART_BEAT_TIME_OUT_WARNNING > socHeartBeat_Cnt))
    {
        B_AppHeartBeatError = FALSE;
        CS_SIG_SyncSend(SIG_B_NAVICOMMERROR, (U8*)&B_AppHeartBeatError);
    }
}

/***********************************************************************
*  Name        : SocManager_HeartBeatUpdate
*  Description : 
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_HeartBeatUpdate(BOOL heartBeatSetSts)
{
    socHeartBeat_Switch = heartBeatSetSts;
    socHeartBeat_Cnt = 0;
}

/***********************************************************************
*  Name        : SocManager_HeartBeatUpdate
*  Description : 
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_HeartBeatUpdateSocSts(BOOL updateSocSts)
{
    socHeartBeat_UpdateSocSts = updateSocSts;
}

/***********************************************************************
*  Name        : DataReset
*  Description :         
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void DataReset(void)
{
  uErrorTimer=0;
  watchDogLostCnt = 0;
  watchDogInPre = FALSE;
  watchDogIn = FALSE;
  /* Disable SOC heart beat */
  SocManager_HeartBeatUpdate(FALSE);
}

/***********************************************************************
*  Name        : Dispatcher_RepMsg
*  Description :         
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void SocManager_Dispatcher_Msg(U8 cmpt_id,U16 commandid, U8* data)
{    
	U8 EOL_STATUS = 0;
	if(CMPT_ID_OOM ==cmpt_id)
    {      
//    	Doip_recvnavimsg_handler(commandid,data);
        switch(commandid)
        {
            case NAVI_SHUT_DOWN_EVENT : // 0x5401
                if(NAVI_FIRST_CONNECT_COMPLETE == data[0])//03
                {
                    U8 navi_msg[2];
                    bFirstConnected = TRUE;        
                    bPowerUpOK= FALSE;
                    navi_msg[0] = TO_USER_ON;
                    navi_msg[1] = ON_OFF_NORMAL;                       
                    SocManager_SendMsg(HQ_CMD,TYPE_SERVICE,RADIO_DISPATCH_CHANGE_POWER_MODE,2,navi_msg);
                    break;
                }
                if(NAVI_POWER_UP == data[0])
                {
                    bPowerUpOK = TRUE;
                    break;
                }
            break;
	
            case J6_REQUEST_M3_EOL_STATUS : //5306
                if(eEolState == E_EOL_NORMAL)
                {
					EOL_STATUS = E_EOL_STATUS_ON;
				}
				else
				{
					EOL_STATUS = E_EOL_STATUS_OFF;
				}
                                      
                  SocManager_SendMsg(HQ_CMD,TYPE_RESPONSE,M3_RESPOND_J6_EOL_STATUS,1,&EOL_STATUS);//5307
             break;             
	
            case NAVI_REQ_TO_RESET_EVENT://0x5414
                bJ6RequestToReset = TRUE;
                ///TODO: used for upgrade test
                OSWDG_SoftReset();
	     break;

            case NAVI_SWDL_CONFIG_EVENT://0x5410
            case NAVI_SWDL_STATUS_EVENT://0x5413
                Notify_Upgrade_Req(commandid,data);
            break;

            case NAVI_GET_RADIO_STATUS://0x5201
              if(0x03 == data[0])  //EOL status
            {
                J6SelfDiagFlagHandler();
            }
        break;
           

			case NAVI_SELF_UPGRADE_RESULT_EVENT://0x5415
				EOLAPP_DISPATCHER_MSG(commandid,data);
            break;

            case J6_SEND_RESPONSE_OF_VERSION:
				CANDIA_DISPATCHER_MSG(commandid,data);
            break;
            
            default:
            break;
        }
    }
    else if(CMPT_ID_SYSTEM == cmpt_id)
    {
		CanApp_recvnavimsg_handler(commandid,data);
		ApsCanApp_recvnavimsg_handler(commandid,data);
//		Doip_recvnavimsg_handler(commandid,data);
	    CANDIA_DISPATCHER_MSG(commandid, data);

	   switch(commandid)
       {
			case SOC_NOTI_CAMERA_FAULT:
				{
					SOC_DISPATCHER_DTC_MSG(commandid,data);
				}
	       		break;
			case SOC_SEND_RESP_OF_REMOVABLE_DEVICE_STATUS:
				{
					EOLAPP_DISPATCHER_MSG(commandid,data);
				}
	        	break;
			default :
				break;
       }
    }
	else if(CMPT_ID_DIAG == cmpt_id)
	{
		CanApp_recvnavimsg_handler(commandid,data);
		Doip_recvnavimsg_handler(commandid,data);
	}
    else if(CMPT_ID_EOL == cmpt_id)
    {
     	EOLAPP_DISPATCHER_MSG(commandid, data);
		if(commandid == J6_NOTIFY_M3_SELFTEST_RESULT)
		{
			SocManager_SendMsg(HQ_CMD,TYPE_RESPONSE,M3_SEND_RESP_OF_J6SELFTEST,0,NULL);
		}
		else if(commandid == J6_SEND_RESPONSE_OF_VERSION)
        {
            CANDIA_DISPATCHER_MSG(commandid, data);		
        }
    }
    else if(CMPT_ID_COMMONINFO == cmpt_id)
    {
    }
	
}

/***********************************************************************
*  Name        : Dispatcher_SentResult
*  Description :
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Dispatcher_SentResult(U16 commandid, BOOL result)
{
    switch(commandid)
    {
        default:break;
    }
}


 void SocManager_Dispatcher_SentResult(U16 commandid, BOOL result)
{
    SentCommandid = commandid;
    IsSent = result;    
}
 
/**************** END OF FILE *****************************************/

