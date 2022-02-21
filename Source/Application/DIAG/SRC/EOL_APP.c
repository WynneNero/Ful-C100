/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ     									   *
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
* Version       Date           Name            Changes and comments
* 0.1    	2015-12-15	ShangQiuju		Initial
*=====================================================================*/
/**** System include files ****/

#include "config.h"
#include "TYPES.H"
#include "TOOLS.H"
#include "eol_app.h"
#include "eol_app_if.h"
#include "eoluartdriver_if.h"
//#include "StringParser.h"
//#include "NaviService.h"
#include "SocManager.h"
//#include "dtc.h"
#include "EEP_DtcData.h"
#include "CanDiagDtc.h"
#include "CanDiagDtcCfg.h"
//#include "CanDataStruct.H"
#include "Signal_if.h"  
#include "naviapp.h"
#include "EEP_ECUSerialNumber.h"
#include "EEP_EOLconfig.h"
#include "SocDriver_IF.H"
#include "ComplexDrvier_Globaldef_IF.h"
#include "SocDriver.H"
#include "UssInfoMsg.h"
#include "CanApp.h"
#include "UltraRadarDriver.h"
#include "ussLibIf.h"
#include "ussLibAdapt.h"
#include "Dem_IntErrId.h"
#include "UssInfo_Msg_IF.h"

/*---Public include files---------------------------------------------*/

/*===VARIABLES========================================================*/

/*---Global-----------------------------------------------------------*/

/*---Private----------------------------------------------------------*/
typedef void (*EolAppFuncType)(void);
#ifdef SX5_HW
#define SOFTWARE_VERSION_LEN (NaviApp_GetM3SWVersionLen())
#define VEHICLE_INFO_NUM (NaviApp_GetM3VehicleInfo())
#else				
#define SOFTWARE_VERSION_LEN 22
#endif	

#define HardWare_VERSION_LEN 17
#define GACSOFTWare_VERSION_LEN        17

BOOL bEolEnterReq;
BOOL bEolExistReq;
BOOL bJ6EnterDiagFlag;
BOOL bSentJ6enterEolevent;
BOOL bJ6selfDiagResultRec;
BOOL uUpgradeResult;
BOOL bJ6RequestEolStatus;

U8 returnCode;
U8 uPowerLevel;
U8 sResultCode;
U8 sRespLen;
U8 uJ6selfDiagResult[2];
U8 ReqMsgData[REQMSG_MAX_DATALEN];
U8* sRespPstr;
U8 sReqLen;
U8 eolStatus;
U8 m3Dtc[DTC_CODE_MAX_NUM] = {0};

U8 soc_powerdown_delay=0;
U8 delay_flag = 0;
U64 TAUBdataBK=0;
U64 TAUBDiffdatavalue=0;


#ifdef SX5_HW
U8 m3version[22];
#else	
U8 m3version[SOFTWARE_VERSION_LEN];
#endif
U8 m3HwVersion[HardWare_VERSION_LEN];
U8 m3GACSwVersion[GACSOFTWare_VERSION_LEN];

E_QUERY_J6_LICENSE_STRUCT reqJ6Data;
extern const U8 can_diag_system_supplier_ecu_software_number[2];
extern U8 EolUpdateFlag;

extern void reset_soc_power(void);


U16 uPowerOnTimeCnt;
U16 uEolExistTimeCnt;

E_EOL_STATE eEolState;
E_MSGTYPE sReqType;
#define IS_REQTYPE_VALID()  (sReqType<E_MSGTYPE_NUM)

U8 eepData[2];
BOOL bEOLWaitEEPwriteResp;
U16 uEOLWaitEEPwriteCnt;
E_DATASEND_RESULT bEolConfigEepSendResult; 
 static U8 uBadResp = 0x00;
 static U8 uOkResp = 0X01;
 static U8 HighLevel = 0X02;

 #define E_NAVI_CLOSE_TIME_OUT 35
BOOL bNaviIsClosed;
U16 uNaviCloseTimeCnt;
#define LEN_OF_SERIAL_NUMBER 14
#define LEN_OF_MANUFACTURING_DATA 4


 const static REQSTATICMSQ Req_msg_table[E_MSGTYPE_NUM]=
{  
    E_MSGID_ENTER_EOL,5,//00
    E_MSGID_J6_START_FROM_SD,5,
    E_MSGID_EXIST_EOL,5,
    E_MSGID_READ_BOOT_VERSION,5,
    E_MSGID_READ_HARDWARE_VERSION,5,
    E_MSGID_READ_J6OS_VERSION,5,
    E_MSGID_READ_J6SVP_VERSION,5,
    E_MSGID_WRITE_SERIAL_NUMBER,LEN_OF_SERIAL_NUMBER+5,
    E_MSGID_READ_SERIAL_NUMBER,5,
    E_MSGID_READ_M3_DTC,5,
    E_MSGID_CLEAR_DTC,5,
    E_MSGID_READ_SOFTWARE_VERSION,5,
    E_MSGID_ENTER_REVERSE_MODE,6,
    E_MSGID_READ_POWER_DET,5,
    E_MSGID_READ_CAN_POWER_DET,5,
    E_MSGID_READ_IGN,    5,    
    E_MSGID_CTL_CAMERA,6,
    E_MSGID_READ_REVERSE_SIGNAL,5,
	E_MSGID_SET_ECU_MANUFACTURING_DATE,9,
	E_MSGID_GET_ECU_MANUFACTURING_DATE,5, 
    E_MSGID_READ_AVM_HW_IN,5,
    E_MSGID_READ_USB_INTERFACE_STATUS,5,
	E_MSGID_READ_SDCARD_INTERFACE_STATUS,5,
    E_MSGID_CTL_AVM_SHUT_DOWN_TIME,7,
    E_MSGID_CTL_DTCSETTING_OFF,5, 
    E_MSGID_CTL_AVM_LED,6,
  	E_MSGID_CTL_APS_LED,6,
  	E_MSGID_CTL_BSD_LLED,6,
  	E_MSGID_CTL_BSD_RLED,6,
  	E_MSGID_CTL_AVM_HARDKEY,5,
  	E_MSGID_CTL_APS_HARDKEY,5,
  	E_MSGID_CTL_PDC_LED,5,
  	E_MSGID_CTL_PDC_HARDKEY,5,
    E_MSGID_RADAR_HW_DET,6,
	E_MSGID_RADAR_SEND_DATA,6,
	E_MSGID_REQ_J6_ENTER_SELF_DIAG,5,
};

E_QUERY_J6_LICENSE_STRUCT licenseData;

void set_fast_powerdown(U16 timeout);
void EolEntryReqHandler(void);
void ReadVersionReqHandler(void);
void WriteSerialNumberReqHandler(void);
void ReadSerialNumberReqHandler(void);
void WriteManufacturingDataReqHandler(void);
void ReadManufacturingDataReqHandler(void);
void PowerDetReqHandler(void);
void CANPowerDetReqHandler(void);
void ReadM3DTCReqHandler(void);
void ClearDtcReqHandler(void);
void EolReqJ6StartFromSDHandler(void);
void ReadignReqHandler(void);
void EnterReverseReqHandler(void);
void ControlCameraHandler(void);
void ReadReverseHwSignalHandler(void);
void ReadAVMHwSignalHandler(void);
void ReadUSBinterfaceStatusHandler(void);
void ReadSDCARDinterfaceStatusHandler(void);
void QuickShotDownHandler(void);
void J6licenseHandler(void);
BOOL EolApp_GetEolStatus(void);
void DTCSettingOffHandler(void);

void AVMLedControlHandler(void);
void APSLedControlHandler(void);
void BSDLLedControlHandler(void);
void BSDRLedControlHandler(void);
void AVMHardKeyTestHandler(void);
void APSHardKeyTestHandler(void);
void RadarHWDetHandler(void);
void RadarSendDataHandler(void);
void PDCLedControlHandler(void);
void PDCHardKeyTestHandler(void);
void Request_j6_enter_self_diag(void);


EolAppFuncType EolAppFunc[E_MSGTYPE_NUM]={
    EolEntryReqHandler,//00
    EolReqJ6StartFromSDHandler,
    EolEntryReqHandler,
    ReadVersionReqHandler,
    ReadVersionReqHandler,
    ReadVersionReqHandler,    
    ReadVersionReqHandler,
    WriteSerialNumberReqHandler,
    ReadSerialNumberReqHandler,
    ReadM3DTCReqHandler,
    ClearDtcReqHandler,
    ReadVersionReqHandler,
    EnterReverseReqHandler,
    PowerDetReqHandler,
    CANPowerDetReqHandler,
    ReadignReqHandler,
    ControlCameraHandler,
    ReadReverseHwSignalHandler,
	WriteManufacturingDataReqHandler,
	ReadManufacturingDataReqHandler,
    ReadAVMHwSignalHandler,
    ReadUSBinterfaceStatusHandler,
    ReadSDCARDinterfaceStatusHandler,
    QuickShotDownHandler,
    DTCSettingOffHandler,
    AVMLedControlHandler,
   	APSLedControlHandler,
	BSDLLedControlHandler,
	BSDRLedControlHandler,
	AVMHardKeyTestHandler,
	APSHardKeyTestHandler,
	PDCLedControlHandler,
	PDCHardKeyTestHandler,
	RadarHWDetHandler,
	RadarSendDataHandler,
	Request_j6_enter_self_diag,
};

/*===FUNCTIONS========================================================*/

void HandleBootVersion(void);
void HandleEolReq(void);
void HandleForwardMsg(void);
BOOL IsReqFormatOK(U8 type);
BOOL IsAllowForwardMsg(void);
void SendStartEOLReq(void);
/*---Global-----------------------------------------------------------*/
/***********************************************************************
* FUNCTION    : eol_task
* DESCRIPTION :
* INPUTS      : void
* RETURN      : void
***********************************************************************/
#define testused_for_enter_eol

void EOLInit(void)
{
    U8 sig = 0;
    eEolState = E_EOL_INIT;
    uPowerOnTimeCnt = E_POWER_ON_TIMEOUT;
#ifdef testused_for_enter_eol
    bEolEnterReq = TRUE;
#else
    bEolEnterReq = FALSE;
#endif
    bEolExistReq = FALSE;
    reqJ6Data.data.bReqSent = FALSE;
    reqJ6Data.data.bRespReceived = FALSE;
    reqJ6Data.data.recvDatatime = 0;
    reqJ6Data.data.uRecvDatalen = 0;
    reqJ6Data.type = E_MSGID_INVALID;
    licenseData.type = E_MSGID_INVALID;
    licenseData.data.bReqSent = FALSE;
    licenseData.data.bRespReceived = FALSE;
    licenseData.data.recvDatatime = 0;
    licenseData.data.uRecvDatalen = 0;    
   	bJ6EnterDiagFlag = FALSE;
    bJ6selfDiagResultRec = FALSE;
    CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);
    bJ6RequestEolStatus= FALSE;
	bEolConfigEepSendResult = E_NORESULT;	
	bEOLWaitEEPwriteResp = FALSE;
}

void EOL_S1S2Init(void)
{
    U8 sig = 0;
    CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);    
    eEolState = E_EOL_IDLE;
}



void EOL_Main(void)
{
    U8 sig = 0;
    switch(eEolState)
    {
        case E_EOL_INIT:
            eEolState = E_EOL_SEND_CONNECT_REQ;
            sig = 0;
            CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);    
        break;
        case E_EOL_SEND_CONNECT_REQ:
            SendStartEOLReq();
            uPowerOnTimeCnt = E_POWER_ON_TIMEOUT;
            bEolEnterReq = FALSE;
            eEolState = E_EOL_WAIT_CONNNECT_RESP;
            sig = 0;
            CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);    
        break;
        case E_EOL_WAIT_CONNNECT_RESP:
            if(0==uPowerOnTimeCnt)
            {
                eEolState = E_EOL_EXIT;
                uEolExistTimeCnt = 0;
                sig = 0;
                CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);    
                break;
            }      
            uPowerOnTimeCnt--;
            if(bEolEnterReq)
            {
                bEolEnterReq = FALSE;
                eEolState = E_EOL_NORMAL;
                sig = 1;
                CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);    
            }            
        break;
        case E_EOL_NORMAL:
            //HandleBootVersion();
            //soc_slc_handler();
            HandleForwardMsg();
            HandleEolReq();
			reset_soc_power();
            if(bEolExistReq)
            {
                bEolExistReq = FALSE;
                eEolState = E_EOL_EXIT;
                uEolExistTimeCnt = E_EXIST_EOL_TIMEOUT;
                
            }
            if(bNaviIsClosed)
            {
                if(uNaviCloseTimeCnt++>E_NAVI_CLOSE_TIME_OUT)
                {
                    U8 naviPower = 1;
                    uNaviCloseTimeCnt = 0;
					Open_SOC_Power();
					POWER_PMIC_ON();
					soc_startup_from_sd();  
                    bNaviIsClosed = FALSE;
                    CS_SIG_SyncSend(SIG_B_SOC_POWER_ON, &naviPower);
                }
            }
        break;
        case E_EOL_EXIT:        
            if(0==uEolExistTimeCnt)
            {
                eEolState = E_EOL_IDLE;     
                sig = 0;
                CS_SIG_SyncSend(SIG_EOL_ACTIVE_STATUS,&sig);       
                EolService_DeInit();        
                break;
            }    
            uEolExistTimeCnt--;
        break;
        case E_EOL_IDLE:           
        break;
        default:break;
    }
}

BOOL EolApp_IsEolActivated(void)
{
    if((E_EOL_NORMAL == eEolState)
        ||(E_EOL_EXIT == eEolState))
        {
            return TRUE;
        }
    else return FALSE;
}


void SendStartEOLReq(void)
{
     EolService_SendMsg(E_MSDID_START_EOL,NULL,0);
}


/***********************************************************************
*  Name        : HandleEolReq
*  Description : DeInit eol msg handler        
*  Parameter   : None
*  Returns     : None
***********************************************************************/
 void  HandleEolReq(void)
{    
        if(IS_REQTYPE_VALID())
        {                
            if(IsReqFormatOK(sReqType) == FALSE)
            {
                sResultCode=E_NEGATIVE_BAD_REQUEST;
                sRespPstr = &uBadResp;
                sRespLen = 1;
            }
            else
            {
                EolAppFunc[sReqType]();
            }  
            
            if(sResultCode!=E_NOT_SENT_RESULT)
                EolService_SendMsg(Req_msg_table[sReqType].msgid,sRespPstr,sRespLen); 
                
            sReqType = E_MSGTYPE_NUM;
            sRespPstr = NULL;
            sRespLen = 0;
        }  
}

void HandleForwardMsg(void)
{
    if(reqJ6Data.data.bReqSent)
    {
        if(reqJ6Data.data.recvDatatime++>WAIT_J6_RESP_TIME)
        {
            reqJ6Data.data.bReqSent= FALSE;
			bEOLWaitEEPwriteResp = FALSE; 			
            EolService_SendMsg(reqJ6Data.type,&uBadResp,1); 
        }
		 if(bEOLWaitEEPwriteResp == TRUE) //Only Check EEP write status of vehicle infomation flag for E_MSGID_SET_VEHICLE_CONFIG service
		 {
		 	  if((uEOLWaitEEPwriteCnt++>E_WAIT_EEP_WRITE_EOL_RESULT_TIME)
					||(E_SENTFAIL == bEolConfigEepSendResult))
		 	  {
		 	  			reqJ6Data.data.bReqSent= FALSE;
						bEOLWaitEEPwriteResp = FALSE;	
						//If EEP write failed for vehicle infomation flag, send negtive response
						EolService_SendMsg(reqJ6Data.type,&uBadResp,1);	
		 	  }
		 }
        if(reqJ6Data.data.bRespReceived)
        {
        	 if(TRUE == bEOLWaitEEPwriteResp) //Only for E_MSGID_SET_VEHICLE_CONFIG service 
        	 {
        	 		if(E_SENTOK  == bEolConfigEepSendResult)
        	 		{
        	 			bEOLWaitEEPwriteResp = FALSE;
        	 			EolService_SendMsg(reqJ6Data.type,reqJ6Data.data.uRecvData,reqJ6Data.data.uRecvDatalen); 
	            		reqJ6Data.data.bReqSent= FALSE;
        	 		}
        	 }
			 else
			 {
	            EolService_SendMsg(reqJ6Data.type,reqJ6Data.data.uRecvData,reqJ6Data.data.uRecvDatalen); 
	            reqJ6Data.data.bReqSent= FALSE;
			 }
        }
    }

    if(bJ6RequestEolStatus)
    {
        U8 data[2];
        data[0] = 0x03;
        data[1] = EolApp_GetEolStatus();
        if(SocManager_SendMsg(TX_LQ, TYPE_EVENT,NAVI_RESP_EVENT,2,&data[0]))
            bJ6RequestEolStatus = FALSE;
    }
    
    if(bJ6EnterDiagFlag)
    {
        if(bSentJ6enterEolevent)
        {
            EolService_SendMsg(E_MSGID_REPORT_J6_DTC_START,NULL,0); 
            bSentJ6enterEolevent = FALSE;
        }        

		if(bJ6selfDiagResultRec)
		{
			delay_flag ++;
			  if(delay_flag >= 5)
			  {
				bJ6selfDiagResultRec = FALSE;
				EolService_SendMsg(E_MSGID_REPORT_J6_DTC_RESULT, uJ6selfDiagResult,2);
				delay_flag = 0;
			  }
		}
    }    
}

void EolEntryReqHandler(void)
{    
    eolStatus = ReqMsgData[0];
    sResultCode=E_POSITIVE;
    sRespPstr = &uOkResp;
    sRespLen = 1;
}

void ReadVersionReqHandler(void)
{
	U8 version;
    switch(ReqMsgData[2])
    {
        case E_M3_BOOT_VERSION:    
                NaviApp_GetM3SoftVersion(m3version);
                sResultCode=E_POSITIVE;
                sRespPstr = m3version;
                sRespLen = SOFTWARE_VERSION_LEN;

        break;
		case E_M3_HW_VERSION:    
				NaviApp_GetM3HardVersion(m3HwVersion);
	            sResultCode=E_POSITIVE;
	            sRespPstr = m3HwVersion;
	            sRespLen = HardWare_VERSION_LEN;
        break;
        
        case E_J6_OS_VERSION:
			    version = 0x01;
			    SocManager_SendMsg(TX_LQ,TYPE_EVENT, RADIO_QUERY_ENG_SW_VERSION, 1, &version);
			    sResultCode = E_NOT_SENT_RESULT;	
				//sResultCode = E_POSITIVE;		
			    reqJ6Data.data.bReqSent = TRUE;
			    reqJ6Data.data.recvDatatime = 0;
			    reqJ6Data.data.uRecvDatalen = 0;
			    reqJ6Data.type = E_MSGID_READ_J6OS_VERSION;
			    reqJ6Data.data.bRespReceived = FALSE;
        break;

        case E_J6_SVP_VERSION:
            version = 0x02;
            SocManager_SendMsg(TX_LQ,TYPE_EVENT, RADIO_QUERY_ENG_SW_VERSION, 1, &version);  
            sResultCode = E_NOT_SENT_RESULT;
			//sResultCode = E_POSITIVE;     		
            reqJ6Data.data.bReqSent = TRUE;
            reqJ6Data.data.recvDatatime = 0;
            reqJ6Data.data.uRecvDatalen = 0;
            reqJ6Data.data.bRespReceived = FALSE;	
            reqJ6Data.type = E_MSGID_READ_J6SVP_VERSION;			
        break;
        
        case E_SOFT_VERSION:
			NaviApp_GetM3GACSoftVersion(m3GACSwVersion);
			sResultCode=E_POSITIVE;
			sRespPstr = m3GACSwVersion;
			sRespLen = GACSOFTWare_VERSION_LEN; 
		break;
		
        default:
                sResultCode=E_NEGATIVE_BAD_REQUEST;
                sRespPstr = NULL;
                sRespLen = 0;
        break;
    }
}


void WriteSerialNumberReqHandler(void)
{    
    U8 i;
    
    EED_LockDataBlock(EED_nECUSerialNumber);
    for(i=0;i<LEN_OF_SERIAL_NUMBER;i++)
    {
        EED_u8EcuSerialNumber[i] = ReqMsgData[5+i];
    }
    EED_UnlockAndSavDataBlock(EED_nECUSerialNumber);	
	SysJob_StartJob(JOB_EEPRW);
    sResultCode=E_POSITIVE;
    sRespPstr =&uOkResp ;
    sRespLen = 1;        
}

void ReadSerialNumberReqHandler(void)
{
    sResultCode=E_POSITIVE;
    sRespPstr = EED_u8EcuSerialNumber;
    sRespLen = LEN_OF_SERIAL_NUMBER;
}

//addition

void WriteManufacturingDataReqHandler(void)
{    
    U8 i;
    
    EED_LockDataBlock(EED_nDiagData0);
    for(i=0;i<LEN_OF_MANUFACTURING_DATA;i++)
    {
        EED_ECUManufacturingDate[i] = ReqMsgData[5+i];
    }
    EED_UnlockAndSavDataBlock(EED_nDiagData0);	
	SysJob_StartJob(JOB_EEPRW);
    sResultCode=E_POSITIVE;
    sRespPstr =&uOkResp ;
    sRespLen = 1;        
}

void ReadManufacturingDataReqHandler(void)
{
    sResultCode=E_POSITIVE;
    sRespPstr = EED_ECUManufacturingDate;
    sRespLen = LEN_OF_MANUFACTURING_DATA;
}


void PowerDetReqHandler(void)
{
/*    U16 power;
   CS_SIG_SyncReceive(SIG_ACC_DI_STATUS ,&power);
    uPowerLevel = power&0x01;
    
    sResultCode=E_POSITIVE;
    sRespPstr = &uPowerLevel;
    sRespLen = 1;
*/
	U8 eol_vol_status;
	CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &eol_vol_status);  
	eol_vol_status = (E_SYSTEM_VOLTAGE_STATUS)eol_vol_status;

	if(eol_vol_status==V_NORMAL)
	{
		sResultCode=E_POSITIVE;
		uPowerLevel = 0x01;
		sRespPstr = &uPowerLevel;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_POSITIVE;
		uPowerLevel = 0x00;
		sRespPstr = &uPowerLevel;
		sRespLen = 1;

	}
	
}

void CANPowerDetReqHandler(void)
{
   /*U16 power;
    CS_SIG_SyncReceive(SIG_ACCSTATUS ,&power);
    uPowerLevel = power&0x01;
    
    sResultCode=E_POSITIVE;
    sRespPstr = &uPowerLevel;
    sRespLen = 1;
	*/
	U8 eol_vol_status;
	CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &eol_vol_status);  
	eol_vol_status = (E_SYSTEM_VOLTAGE_STATUS)eol_vol_status;

	if((eol_vol_status==V_LOW)||(eol_vol_status==V_NORMAL)||(eol_vol_status==V_HIGH))
	{
		sResultCode=E_POSITIVE;
		uPowerLevel = 0x01;
		sRespPstr = &uPowerLevel;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_POSITIVE;
		uPowerLevel = 0x00;
		sRespPstr = &uPowerLevel;
		sRespLen = 1;
	}

}

void ReadM3DTCReqHandler(void)
{
	U8 i;	
	U8 MSG[DTC_CODE_MAX_NUM];
	
	_memcpy(MSG, EED_CANDTC, DTC_BIT30);

	for(i=0;i<DTC_BIT30;i++)
    {
        MSG[i+DTC_BIT30] = EED_CANDTC1[i];
    } 
	
	for(i=0;i<(DTC_CODE_MAX_NUM-(2*DTC_BIT30));i++)
    {
        MSG[i+(2*DTC_BIT30)] = EED_CANDTC2[i];
    } 

	 _memcpy(m3Dtc, MSG, DTC_CODE_MAX_NUM);

    sResultCode=E_POSITIVE;
    sRespPstr = m3Dtc;
    sRespLen = DTC_CODE_MAX_NUM;
}

void ClearDtcReqHandler(void)
{
/*******************************DTC Record***********************************/
    EED_LockDataBlock(EED_nDTCrecord);
    _memset(EED_CANDTC,0,DTC_BIT30);
    EED_UnlockDataBlock(EED_nDTCrecord);

	EED_LockDataBlock(EED_nDTCrecord1);
    _memset(EED_CANDTC1,0,DTC_BIT30);
    EED_UnlockDataBlock(EED_nDTCrecord1);

	EED_LockDataBlock(EED_nDTCrecord2);
    _memset(EED_CANDTC2,0,DTC_CODE_MAX_NUM1);
    EED_UnlockDataBlock(EED_nDTCrecord2);

#ifdef DTC_AGING_COUNTER
/*******************************DTC Aging***********************************/
    EED_LockDataBlock(EED_nDTCAgingCount);
    _memset(EED_CANDTC_AGING_CNT,0,DTC_BIT30);
    EED_UnlockDataBlock(EED_nDTCAgingCount);

	EED_LockDataBlock(EED_nDTCAgingCount1);
    _memset(EED_CANDTC_AGING_CNT1,0,DTC_BIT30);
    EED_UnlockDataBlock(EED_nDTCAgingCount1);

	EED_LockDataBlock(EED_nDTCAgingCount2);
    _memset(EED_CANDTC_AGING_CNT2,0,DTC_CODE_MAX_NUM1);
    EED_UnlockDataBlock(EED_nDTCAgingCount2);	

/*******************************DTC Aged************************************/
	EED_LockDataBlock(EED_nDTCAgedCount);
	_memset(EED_CANDTC_AGED_CNT,0,DTC_BIT30);
	EED_UnlockDataBlock(EED_nDTCAgedCount);

	EED_LockDataBlock(EED_nDTCAgedCount1);
	_memset(EED_CANDTC_AGED_CNT1,0,DTC_BIT30);
	EED_UnlockDataBlock(EED_nDTCAgedCount1);

	EED_LockDataBlock(EED_nDTCAgedCount2);
	_memset(EED_CANDTC_AGED_CNT2,0,DTC_CODE_MAX_NUM1);
	EED_UnlockDataBlock(EED_nDTCAgedCount2);	

/*******************************DTC Occurrence******************************/
	EED_LockDataBlock(EED_nDTCOccurrenceCount);
	_memset(EED_CANDTC_OCCURRENCE_CNT,0,DTC_BIT30);
	EED_UnlockDataBlock(EED_nDTCOccurrenceCount);

	EED_LockDataBlock(EED_nDTCOccurrenceCount1);
	_memset(EED_CANDTC_OCCURRENCE_CNT1,0,DTC_BIT30);
	EED_UnlockDataBlock(EED_nDTCOccurrenceCount1);

	EED_LockDataBlock(EED_nDTCOccurrenceCount2);
	_memset(EED_CANDTC_OCCURRENCE_CNT2,0,DTC_CODE_MAX_NUM1);
	EED_UnlockDataBlock(EED_nDTCOccurrenceCount2);
#endif

	ClearDtcFidDataRecord();

	ClearDtcSnapshotDataRecord();	
	
	SysJob_StartJob(JOB_EEPRW);
	CanDiagDtc_desc_delay_set_sig(DESC_DELAY_SIG_1);
    CanDiagDtc_sv14_clear_start();
    sResultCode=E_POSITIVE;
    sRespPstr = &uOkResp;
    sRespLen = 1;
}

extern BOOL eol_shultdown_cpu_watchdog;
void EolReqJ6StartFromSDHandler(void)
{
        U8 naviPower = 0;
        sResultCode=E_POSITIVE;
        sRespPstr = &uOkResp;
        sRespLen = 1;
		Close_SOC_Power();
		Close_CAM_Power();	
		EolUpdateFlag = TRUE;
		UPDATE_OS_START();
        CS_SIG_SyncSend(SIG_B_SOC_POWER_ON, &naviPower);
        uNaviCloseTimeCnt = 0;
        bNaviIsClosed = TRUE;
}

#ifdef AB01_HW
void EolReqJ6EnterFailSafeHandler(void)
{
        SocManager_SendMsg(TX_LQ,TYPE_EVENT, RADIO_REQUEST_A6_ENTER_FAIL_SAFE_MODE, 0, NULL);
        reqJ6Data.data.bReqSent = TRUE;
        reqJ6Data.data.recvDatatime = 0;
        reqJ6Data.data.uRecvDatalen = 0;
        reqJ6Data.data.bRespReceived = FALSE;
        reqJ6Data.type = E_MSGID_ENTER_FAILSAFE_MODE;
        sResultCode = E_NOT_SENT_RESULT;   
}
#endif

void ReadignReqHandler(void)
{
    U16 power = 0;
//  CS_SIG_SyncReceive(SIG_ACC_DI_STATUS ,&power);
//	power = GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_0);
    sResultCode = E_POSITIVE;
    uPowerLevel = power&0x01;
    sRespPstr = &uPowerLevel;
    sRespLen = 1;
}

void EnterReverseReqHandler(void)
{
	U8 reverse;
	switch(ReqMsgData[5])
	{
		case 0x01:
					reverse = 0x02;
					sResultCode=E_POSITIVE;
					sRespPstr = &uOkResp;
					sRespLen = 1;		 
					SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_GEAR_DISPLAY_STATUS,1,&reverse);//4405
		break;

		case 0x00:
					reverse = 0x04;
					sResultCode=E_POSITIVE;
					sRespPstr = &uOkResp;
					sRespLen = 1;		 
					SocManager_SendMsg(HQ_CMD,TYPE_EVENT,RADIO_NOTIFY_GEAR_DISPLAY_STATUS,1,&reverse);//4405
		break;


		default:
					sResultCode=E_NEGATIVE_BAD_REQUEST;
					sRespPstr = &uBadResp;
					sRespLen = 1;
		break;
	}
}

void ControlCameraHandler(void)
{
    if(ReqMsgData[5]<=4)
    {
        U8 data[7] = {0};
        sResultCode=E_POSITIVE;
        sRespPstr = &uOkResp;
        sRespLen = 1;
        data[0] = ReqMsgData[5];
        SocManager_SendMsg(TX_LQ,TYPE_EVENT, M3_SEND_RESP_OF_CAMERA_STATUS, 2, data);
    }
    else
    {
        sResultCode=E_NEGATIVE_BAD_REQUEST;
        sRespPstr = &uBadResp;
        sRespLen = 1;
   }
}

void ReadReverseHwSignalHandler(void)
{    
    U16 sig = 0;
    //CS_SIG_SyncReceive(SIG_REVERSE_DI_STATUS ,&sig);
    sResultCode=E_POSITIVE;
    uPowerLevel = sig&0x01;
    sRespPstr = &uPowerLevel;
    sRespLen = 1;
}

void DTCSettingOffHandler(void)
{
    eolStatus = ReqMsgData[0];
    sResultCode=E_POSITIVE;
    can_diag_control_dtc_setting_off();
    sRespPstr = &uOkResp;
    sRespLen = 1;
}

/***************************************************************************
*
*  \details: 	eol get radar hardware dectect response
*
*  \param[in]:  None
*
*  \return: 	None
*          
*  \since:  	v00.00.02
*
*****************************************************************************/
static U8 radarCnt50ms = 0;
U8 IsrEnteryFlag = FALSE;
void getRadarHwDectFlag(void)
{
	if(IsrEnteryFlag)
	{
		sResultCode=E_POSITIVE;
        sRespPstr = &uOkResp;
        sRespLen = 1;
	}
	else 
	{
		sResultCode=E_NEGATIVE_BAD_REQUEST;
		sRespPstr = &uBadResp;
		sRespLen = 1;
	}
	radarEolStartFlag.uRadarEolStartFlag = 0;
	IsrEnteryFlag = 0;
}

/***************************************************************************
*
*  \details: 	eol radar hardware dectect request
*
*  \param[in]:  None
*
*  \return: 	None
*          
*  \since:  	
*
*****************************************************************************/
extern diagnosticTypedef USSFailureStatus_Info_called[];
void RadarHWDetHandler(void)
{	
	F_RADAR_EN_ON(); 
	R_RADAR_EN_ON();
	switch(ReqMsgData[5])
	{
		case Radar_RRS:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RRS);	
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRRS = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_RR:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RR);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRR = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_RRM:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RRM);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRRM = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_RLM:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RLM);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRLM = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_RL:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RL);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRL = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_RLS:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_RLS);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRLS = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FRS:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FRS);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFRS = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FR:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FR);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFR = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FRM:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FRM);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFRM = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FLM:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FLM);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFLM = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FL:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FL);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFL = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
		case Radar_FLS:
			TAUD_SysTime_start();
			SnsIntp_EnableInt(Radar_FLS);
			radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFLS = TRUE;
			delay_us(5000);
			getRadarHwDectFlag();
		break;
	}

}
/***************************************************************************
*
*  \details: 	eol radar hardware dectect request: verify the sending circuit
*
*  \param[in]:  None
*
*  \return: 	None
*          
*  \since:  	
*
*****************************************************************************/
void RadarSendDataHandler(void)
{
	U8 RadarLevel = 0;
	F_RADAR_EN_ON(); 
	R_RADAR_EN_ON();
	SnsIntp_DisableAllInt();
	switch(ReqMsgData[5])	//DATA1
	{
		case Radar_RRS:
		GPIO_SetOutputMode(GPIO_PORT_18, GPIO_PIN_3, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_18, GPIO_PIN_3, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_18, GPIO_PIN_3);
		break;
		
		case Radar_RR:
		GPIO_SetOutputMode(GPIO_PORT_8, GPIO_PIN_2, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_2, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_2);
		break;
		
		case Radar_RRM:
		GPIO_SetOutputMode(GPIO_PORT_8, GPIO_PIN_A, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_A, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_A);
		break;
		
		case Radar_RLM:
		GPIO_SetOutputMode(GPIO_PORT_8, GPIO_PIN_B, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_B, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_B);
		break;
		
		case Radar_RL:
		GPIO_SetOutputMode(GPIO_PORT_8, GPIO_PIN_C, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_C, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_C);
		break;
		
		case Radar_RLS:
		GPIO_SetOutputMode(GPIO_PORT_18, GPIO_PIN_2, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_18, GPIO_PIN_2, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_18, GPIO_PIN_2);
		break;
		
		case Radar_FRS:
		GPIO_SetOutputMode(GPIO_PORT_18, GPIO_PIN_1, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_18, GPIO_PIN_1, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_18, GPIO_PIN_1);
		break;
		
		case Radar_FR:
		GPIO_SetOutputMode(GPIO_PORT_1, GPIO_PIN_7, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_7, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_1, GPIO_PIN_7);
		break;
		
		case Radar_FRM:
		GPIO_SetOutputMode(GPIO_PORT_1, GPIO_PIN_6, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_6, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_1, GPIO_PIN_6);
		break;
		
		case Radar_FLM:
		GPIO_SetOutputMode(GPIO_PORT_1, GPIO_PIN_5, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_5, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_1, GPIO_PIN_5);
		break;
		
		case Radar_FL:
		GPIO_SetOutputMode(GPIO_PORT_1, GPIO_PIN_4, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_4, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_1, GPIO_PIN_4);
		break;
		
		case Radar_FLS:
		GPIO_SetOutputMode(GPIO_PORT_18, GPIO_PIN_0, GPIO_OPT_INIT, GPIO_OPT_INIT);
		GPIO_SetVal(GPIO_PORT_18, GPIO_PIN_0, TRUE);	
		RadarLevel = GPIO_GetVal(GPIO_PORT_18, GPIO_PIN_0);
		break;
	}
	if(RadarLevel)
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &uOkResp;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_NEGATIVE_BAD_REQUEST;
		sRespPstr = &uBadResp;
		sRespLen = 1;
	}
}


void ReadAVMHwSignalHandler(void)
{
    U16 sig = 0;
	#ifdef USE_IO_FOR_AVM_HW
    CS_SIG_SyncReceive(SIG_AVM_HW_IN_STATUS ,&sig);
	#endif
    sResultCode=E_POSITIVE;
    uPowerLevel = sig&0x01;
    sRespPstr = &uPowerLevel;
    sRespLen = 1;
}

void ReadUSBinterfaceStatusHandler(void)
{
	U8 data=0x00;
    SocManager_SendMsg(TX_LQ,TYPE_EVENT, REQ_SOC_TO_SEND_REMOVABLE_DEVICE_STATUS, 1, &data);
    reqJ6Data.data.bReqSent = TRUE;
    reqJ6Data.data.recvDatatime = 0;
    reqJ6Data.data.uRecvDatalen = 0;
    reqJ6Data.data.bRespReceived = FALSE;
    reqJ6Data.type = E_MSGID_READ_USB_INTERFACE_STATUS;
	sResultCode = E_NOT_SENT_RESULT;  
}

void ReadSDCARDinterfaceStatusHandler(void)
{
	U8 data=0x01;
	SocManager_SendMsg(TX_LQ,TYPE_EVENT, REQ_SOC_TO_SEND_REMOVABLE_DEVICE_STATUS, 1, &data);
	reqJ6Data.data.bReqSent = TRUE;
	reqJ6Data.data.recvDatatime = 0;
	reqJ6Data.data.uRecvDatalen = 0;
	reqJ6Data.data.bRespReceived = FALSE;
	reqJ6Data.type =E_MSGID_READ_SDCARD_INTERFACE_STATUS;
	sResultCode = E_NOT_SENT_RESULT;
}


void QuickShotDownHandler(void)
{
		U16 temp_timer=500;
		temp_timer =ReqMsgData[6]+ReqMsgData[5]*0x100;
		set_fast_powerdown(temp_timer);//5s
		sResultCode=E_POSITIVE;
        sRespPstr = &uOkResp;
        sRespLen = 1; 
}



/***********************************************************************
*  Name        : IsReqFormatOK
*  Description : DeInit Navi msg handler        
*  Parameter   : None
*  Returns     : None
***********************************************************************/
BOOL IsReqFormatOK(U8 type)
{
    if(type<E_MSGTYPE_NUM)
    {
        if((NOT_NEEDED_CHECK_LEN == Req_msg_table[type].Reqdatalen)||(sReqLen==Req_msg_table[type].Reqdatalen))
        {
            return TRUE;
        }
        else			
        {
            return FALSE;
        }
    }
    return FALSE;
}



void Eol_DISPATCHERREQMSG(U8 msgid, U8* data, U8 len)
{
    U8 index;    
    for(index=0;index<E_MSGTYPE_NUM;index++)
    {
        if(msgid==Req_msg_table[index].msgid)
        {
            if(len)
            {
                if(len>REQMSG_MAX_DATALEN)
                {
                    len = REQMSG_MAX_DATALEN;
                }
                _memcpy(ReqMsgData,data,len);
            }
            sReqType = (E_MSGTYPE)index;
            sReqLen = len;
            if(sReqType == E_MSGTYPE_ENTER_EOL)
            {
                    bEolEnterReq = TRUE;
                    bEolExistReq = FALSE;
            }
            else if(sReqType == E_MSGTYPE_EXIST_EOL)
                {
                    bEolExistReq = TRUE;
                    bEolEnterReq = FALSE;
                }
            break;
        }
    }
}

void Eol_DISPATCHERACK(U8 msgid, BOOL isSent)
{

}


void Eol_DISPATCHERREPMSG(U8 msgid, U8 Result, U8* data, U8 len)
{
}

void EOL_DISPATCHERSPIMSG(U16 commandid, U8* data)
{      
    switch (commandid)
    {
        case J6_SEND_RESPONSE_OF_VERSION:
        if(((reqJ6Data.data.bReqSent)&&(reqJ6Data.type == E_MSGID_READ_J6OS_VERSION)&&(0x01 == data[0]))//os
            ||((reqJ6Data.data.bReqSent)&&(reqJ6Data.type == E_MSGID_READ_J6SVP_VERSION)&&(0x02 == data[0])))//svp
        {
            reqJ6Data.data.uRecvDatalen = data[1];
            if(reqJ6Data.data.uRecvDatalen>RESPMSG_MAX_DATALEN)
            {
                reqJ6Data.data.uRecvDatalen = RESPMSG_MAX_DATALEN;
            }					
            _memcpy(reqJ6Data.data.uRecvData, &data[2], reqJ6Data.data.uRecvDatalen);	
            reqJ6Data.data.bRespReceived = TRUE;
			 
        }
        break;
     
        case SOC_SEND_RESP_OF_REMOVABLE_DEVICE_STATUS:
        if(((reqJ6Data.data.bReqSent)&&(reqJ6Data.type == E_MSGID_READ_USB_INTERFACE_STATUS))
			||((reqJ6Data.data.bReqSent)&&(reqJ6Data.type == E_MSGID_READ_SDCARD_INTERFACE_STATUS)))
        {
            reqJ6Data.data.uRecvDatalen = 1;
            reqJ6Data.data.uRecvData[0] = data[0];
            reqJ6Data.data.bRespReceived = TRUE;
			
        }
        break;
        
		
		case J6_SEND_RESPONSE_OF_SET_J6_CONFIG_DATA:
        break;
				
		case J6_SEND_RESPONSE_OF_GET_J6_CONFIG_DATA:
        break;

        case FORWARD_START_UPGRADE_LICENSE_RESP_TO_PC:
            licenseData.data.bRespReceived = TRUE;
            licenseData.data.uRecvDatalen = 1;
            licenseData.data.uRecvData[0] = data[0];
        break;
        
        case FORWARD_SEND_LICENSE_HW_INFO_RESP_TO_PC:
            licenseData.data.bRespReceived = TRUE;
            if(0 == data[0])
            {
                licenseData.data.uRecvDatalen = 1;
                licenseData.data.uRecvData[0] = data[0];
            }
            else
            {
                if(data[2]>RESPMSG_MAX_DATALEN)
                {
                    licenseData.data.uRecvDatalen = RESPMSG_MAX_DATALEN;
                }
                else
                    licenseData.data.uRecvDatalen = data[2]+2;
                    
                licenseData.data.uRecvData[0] = data[0];
                licenseData.data.uRecvData[1] = data[1];
                _memcpy(licenseData.data.uRecvData+2, data+3, licenseData.data.uRecvDatalen);
            }
        break;

        case FORWARD_LICENSE_TRANSMIT_REQ_RESP_TO_PC:
                licenseData.data.bRespReceived = TRUE;
                licenseData.data.uRecvDatalen = 1;
                licenseData.data.uRecvData[0] = data[1];
            
        break;

        case FORWARD_LICENSE_TRANSMIT_DATA_RESP_TO_PC:
                licenseData.data.bRespReceived = TRUE;
                licenseData.data.uRecvDatalen = 1;
                licenseData.data.uRecvData[0] = data[1];
        break;

        case J6_NOTIFY_M3_SELFTEST_RESULT:
            bJ6selfDiagResultRec = TRUE;
            uJ6selfDiagResult[0] = data[0];
            uJ6selfDiagResult[1] = data[1];
        break;

        case J6_RESP_OF_ENTER_SELF_DIAG_STATUS: //0x830E
				reqJ6Data.data.uRecvDatalen = 1;
				reqJ6Data.data.uRecvData[0] = data[0];
				reqJ6Data.data.bRespReceived = TRUE;
		break;
        default:break;
    }
}


BOOL EolApp_GetEolStatus(void)
{
    return (E_EOL_NORMAL == eEolState);
}

/***********************************************************************
*  Name        : NaviApp_EEPWrite_CallBack
*  Description : DeInit Navi msg handler        
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void EolConfig_EEPWrite_CallBack (ERR_TYPE type)
{
    if(type == ERR_OK)
    {
        bEolConfigEepSendResult = E_SENTOK;
    }
    else
    {
        bEolConfigEepSendResult = E_SENTFAIL;
    }
}



void AVMLedControlHandler(void)	//not found
{
	U8 LevelFlag;
	
 	if(ReqMsgData[5]<=1)//valid
	{      
		switch (ReqMsgData[5])
		{
		
			case 0:
				GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_E, GPIO_OPT_INIT, GPIO_OPT_INIT);
				GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_E, FALSE);
				LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_E);
				if(!LevelFlag)
				{
					sResultCode=E_POSITIVE;
			        sRespPstr = &uOkResp;
			        sRespLen = 1;
				}
				else
				{
					sResultCode=E_NEGATIVE_BAD_REQUEST;
	        		sRespPstr = &uBadResp;
	        		sRespLen = 1;
				}
				break;
			case 1:
				GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_E, GPIO_OPT_INIT, GPIO_OPT_INIT);
				GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_E, TRUE);
				LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_E);
				if(LevelFlag)
				{
					sResultCode=E_POSITIVE;
			        sRespPstr = &HighLevel;
			        sRespLen = 1;
				}
				else
				{
					sResultCode=E_NEGATIVE_BAD_REQUEST;
	        		sRespPstr = &uBadResp;
	        		sRespLen = 1;
				}
				break;
			default:
				break;
		}		
    }
    else //invalid
    {
        sResultCode=E_NEGATIVE_BAD_REQUEST;
        sRespPstr = &uBadResp;
        sRespLen = 1;
    }
}

void APSLedControlHandler(void)	// 
{
    /*
	U8 LevelFlag;
	
	if(ReqMsgData[5]<=1)//valid
    {      
    
	switch (ReqMsgData[5])
		{
		case 0:
			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_A, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_A, FALSE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_A);
			if(!LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &uOkResp;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		case 1:		

			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_A, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_A, TRUE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_A);
			if(LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &HighLevel;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		default:
			break;
		}		
    }
    else //invalid
    {
        sResultCode=E_NEGATIVE_BAD_REQUEST;
        sRespPstr = &uBadResp;
        sRespLen = 1;
    }
    */
}

void PDCLedControlHandler(void)
{
    /*
	U8 LevelFlag;
	
	if(ReqMsgData[5]<=1)//valid
    {      
    
		switch (ReqMsgData[5])
		{
		case 0:
			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_D, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_D, FALSE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_D);
			if(!LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &uOkResp;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		case 1:		

			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_D, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_D, TRUE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_D);
			if(LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &HighLevel;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		default:
			break;
		}		
    }
    else //invalid
    {
        sResultCode=E_NEGATIVE_BAD_REQUEST;
        sRespPstr = &uBadResp;
        sRespLen = 1;
    }
    */
}


void BSDLLedControlHandler(void)
{
    /*
	U8 LevelFlag;
	if(ReqMsgData[5]<=1)//valid
    {      
	switch (ReqMsgData[5])
		{
		
		case 0:
			//APS_BSD_LEFT_LED_OFF();
			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_B, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_B, FALSE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_B);
			if(!LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &uOkResp;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		case 1:			
			//APS_BSD_LEFT_LED_ON();
			GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_B, GPIO_OPT_INIT, GPIO_OPT_INIT);
			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_B, TRUE);
			LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_B);
			if(LevelFlag)
			{
				sResultCode=E_POSITIVE;
		        sRespPstr = &HighLevel;
		        sRespLen = 1;
			}
			else
			{
				sResultCode=E_NEGATIVE_BAD_REQUEST;
        		sRespPstr = &uBadResp;
        		sRespLen = 1;
			}
			break;
		default:
			break;
		}		
    }
    else //invalid
    {
        sResultCode=E_NEGATIVE_BAD_REQUEST;
        sRespPstr = &uBadResp;
        sRespLen = 1;
    }
    */
}

void BSDRLedControlHandler(void)
{
    /*
	U8 LevelFlag;
		if(ReqMsgData[5]<=1)//valid
		{	   
		switch (ReqMsgData[5])
			{
			
			case 0:
				GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_C, GPIO_OPT_INIT, GPIO_OPT_INIT);
				GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_C, FALSE);
				LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_C);
				if(!LevelFlag)
				{
					sResultCode=E_POSITIVE;
					sRespPstr = &uOkResp;
					sRespLen = 1;
				}
				else
				{
					sResultCode=E_NEGATIVE_BAD_REQUEST;
					sRespPstr = &uBadResp;
					sRespLen = 1;
				}
				break;
			case 1: 		
				//APS_BSD_RIGHT_LED_ON();
				GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_C, GPIO_OPT_INIT, GPIO_OPT_INIT);
				GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_C, TRUE);
				LevelFlag = GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_C);
				if(LevelFlag)
				{
					sResultCode=E_POSITIVE;
					sRespPstr = &HighLevel;
					sRespLen = 1;
				}
				else
				{
					sResultCode=E_NEGATIVE_BAD_REQUEST;
					sRespPstr = &uBadResp;
					sRespLen = 1;
				}
				break;
			default:
				break;
			}		
		}
		else //invalid
		{
			sResultCode=E_NEGATIVE_BAD_REQUEST;
			sRespPstr = &uBadResp;
			sRespLen = 1;
		}
*/
}

void AVMHardKeyTestHandler(void)
{
	U8 AVMLedFlag;
	AVMLedFlag = GPIO_GetVal(GPIO_PORT_9, GPIO_PIN_3);		
	
	if(AVMLedFlag)
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &HighLevel;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &uOkResp;
		sRespLen = 1;
	}
}

void APSHardKeyTestHandler(void)
{
	U8 APSLedFlag;
	APSLedFlag = GPIO_GetVal(GPIO_PORT_20, GPIO_PIN_4);		
	
	if(APSLedFlag)
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &HighLevel;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &uOkResp;
		sRespLen = 1;
	}
}

void PDCHardKeyTestHandler(void)
{
    /*
	U8 PDCLedFlag;
	PDCLedFlag = GPIO_GetVal(GPIO_PORT_20, GPIO_PIN_5);		
	
	if(PDCLedFlag)
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &HighLevel;
		sRespLen = 1;
	}
	else
	{
		sResultCode=E_POSITIVE;
		sRespPstr = &uOkResp;
		sRespLen = 1;
	}
	*/
}

void reset_soc_power(void)
{
		if(GPIO_GetVal(GPIO_PORT_1,GPIO_PIN_3)&&(soc_powerdown_delay==0))//detect reset emmc sig
		{
				GPIO_SetVal(GPIO_PORT_10,GPIO_PIN_2,FALSE);//LOW 
				soc_powerdown_delay=1;
		}
		if(soc_powerdown_delay)
		{
				soc_powerdown_delay++;
				if(soc_powerdown_delay>=26)//(26-1)*20ms=500ms
				{
					  GPIO_SetVal(GPIO_PORT_10,GPIO_PIN_2,TRUE);;//HIGH 
						soc_powerdown_delay=0;
				}
		}
}

void J6SelfDiagFlagHandler(void)
{
		bJ6RequestEolStatus = TRUE;               
		bJ6EnterDiagFlag = TRUE;
		bSentJ6enterEolevent = TRUE;           
}

void  Request_j6_enter_self_diag(void)//REQ_J6_ENTER_SELF_DIAG
{
	U8 uAction = 0x01;
   	
	EolUpdateFlag = TRUE;
    SocManager_SendMsg(TX_LQ,TYPE_EVENT, M3_REQ_J6_ENTER_SELF_DIAG, 1, &uAction);  //0x820D
    reqJ6Data.data.bReqSent = TRUE;
    reqJ6Data.data.recvDatatime = 0;
    reqJ6Data.data.uRecvDatalen = 0;
    reqJ6Data.type = E_MSGID_REQ_J6_ENTER_SELF_DIAG ;
	sResultCode = E_NOT_SENT_RESULT;	
    reqJ6Data.data.bRespReceived = FALSE;

    EolUpdateFlag = TRUE;
}


/**************** END OF FILE *****************************************/
