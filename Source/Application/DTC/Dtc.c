/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department : CT AD NJ                                          *
*   AUTHOR     :                                                       *
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
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1  2014/4/11  Shang Qiuju      Initial version
* ----------------------------------------------------------------------
*=====================================================================*/

/**** System include files ****/
//#include <RTL.H>
//#include <string.h>
#include "CONFIG.H"
#include "TYPES.H"

/*---Public include files---------------------------------------------*/
#include "Signal_if.h"
#include "EEPData_IF.h"
#include "SocManager.h"
//#include "CanDataStruct.H"
#include "EEPTable.h"

/*---Private include files--------------------------------------------*/
#include "Dtc.h"
//#include "LED_Manager.h"

#include "ApsCanAPP.h" 
#include "GPIO.h"
#include "GPIO_IF.H"

#include "CONFIG.H"
#include "TYPES.H"
#include "il_inc.h"
#include "il_par.h"
#include "CanApp.h"



#define POWER_ON_CHECK_TIMES 150 //300MS
#define DTC_RECOVER_TIME 20
#define DTC_SET_TIME 20
#define DTC_STREAM_VIDEO_RECOVER_TIME 5
#define DTC_STREAM_VIDEO_SET_TIME 5
#define WAIT_AVM_TIME 1  //10s
#define BSD_RIGHT_INTurn 4
#define BSD_LEFT_INTurn 5

#define BSD_Recovertime  25
#define BSD_Settingtime  5
#define BSD_OK 1
#define BSD_ERROR 0


E_DTC_RECORD_STRUCT sDtcData[DTC_MAX_NUM];

ALERT_STRUCT alertData;
ALERT_STRUCT alertDataBackup;
U16 uCntForPoweroncheck;

U16 uCntForAVMpowerOn;
U16 bNaviPower;
U16 bNaviPowerBackup;
U16 uDtcSig[DTC_MAX_NUM]=
{             
    SIG_CAMERA_F_DI_STA,             
    SIG_CAMERA_L_DI_STA,                 
    SIG_CAMERA_B_DI_STA,               
    SIG_CAMERA_R_DI_STA,
    SIG_RADAR_F_DI_STA,//SIG_AD_BSD_RIGHT_STA
    SIG_RADAR_R_DI_STA,//SIG_AD_BSD_LEFT_STA
    SIG_FRONT_VIDEO_STREAM_STATUS,
	SIG_LEFT_VIDEO_STREAM_STATUS,
	SIG_REAR_VIDEO_STREAM_STATUS,
	SIG_RIGHT_VIDEO_STREAM_STATUS,
	SIG_AD_APA_LED_STA,
	SIG_AD_PDC_LED_STA,
    #ifdef SIG_CPU_TEMP_CHECK
    SIG_CPU_TEMP_CHECK,
    #endif
};

BOOL sbAppHeadUnitOK;
BOOL bCameraFaultFromJ6[4];
BOOL bPowerOnDtcEnd;
extern BOOL bReqReportcamerafault;

extern U8 rightled_work_flag;
extern U8 leftled_work_flag;

void ReportDtc(void);
void Diag_camera_handler(void);

void DtcRecord_SetNaviDtc(U8 dtcnum,U8 device_type);
void DtcRecordTimeHandler(U8 dtcNum,BOOL bError,U8 device_type,U16 recovertime,U16 settime);
U16 uPowerDownLedOpenTime;
#define OPEN_LED_POWER_DOWN_J6  20    //400ms
//extern void PowerOnSelfCheckControlPower(void);

/*===VARIABLES========================================================*/
/*---Global-----------------------------------------------------------*/
//
/* separate from dtc_status structure for EEPROM operation convenience */
/*---Private----------------------------------------------------------*/

void Dtc_Init(void)
{
    U8 i;
    bPowerOnDtcEnd = FALSE;
    uCntForAVMpowerOn = WAIT_AVM_TIME;
    alertData.s2NaviDtc.faultu = 0;
    alertData.s2CanDtc1.cameraf = 0;
    alertData.s2CanDtc2.ledf = 0;
    alertDataBackup.s2NaviDtc.faultu = 0;
    alertDataBackup.s2CanDtc1.cameraf = 0;
    alertDataBackup.s2CanDtc2.ledf = 0;
	alertDataBackup.s2CanDtc3.bsdf = 0;

	uCntForPoweroncheck = POWER_ON_CHECK_TIMES;

    for(i = 0;i<DTC_MAX_NUM;i++)
    {
        sDtcData[i].berr = FALSE;
        sDtcData[i].dtc_create_cnt = 0;
        sDtcData[i].dtc_recover_cnt = 0;
    }

	/*
    CS_SIG_SyncReceive(SIG_B_SOC_POWER_ON, &bNaviPower);
    bNaviPowerBackup = bNaviPower&0x01;    
    if(bNaviPowerBackup)
    {
        uCntForPoweroncheck = POWER_ON_CHECK_TIMES;
    }
    */
}

void DTC_recvnavimsg_handler(U16 commandid, U8* data)
{
    U16 camera_power;
     CS_SIG_AsyncReceive(SIG_CAMERA_DVR_DI_EN,&camera_power);
		 camera_power = camera_power&0x01;
     if(!camera_power)
     {  
        return;
     }
}

void PowerOnSelfCheckDtcHandler(void)
{
    CS_SIG_SyncReceive(SIG_B_SOC_POWER_ON, &bNaviPower);
    bNaviPower = bNaviPower&0x01;    
    if(bNaviPower!=bNaviPowerBackup)
    {
        if(bNaviPower)
        {
            uCntForPoweroncheck = POWER_ON_CHECK_TIMES;
        }
    }
    bNaviPowerBackup = bNaviPower;

	//HardkeyPowerOnSelfCheckHandle();
	if(!uCntForPoweroncheck)
	 {
		 return;
	 }
    //first time open power
    if(POWER_ON_CHECK_TIMES == uCntForPoweroncheck)
    {
		//AVM_LED_ON();
    }

    uCntForPoweroncheck--;
    //last time close power        
    if(0 == uCntForPoweroncheck)
    {
		//AVM_LED_OFF();		
        bPowerOnDtcEnd = TRUE; 
        return;
    }        

	if(uCntForPoweroncheck<50)
	{
	   //Diag_led_handler();
	}
}

void Dtc_Main(void)//20MS
{
	U8 AccStatus;
	U8 EngStatus;
    U8 bAppHeadUnitOK = 0;
    U8 SystemVol;
	U8 pwrValue;
    CS_SIG_SyncReceive(SIG_B_SOC_CONNECTED ,&bAppHeadUnitOK);
    sbAppHeadUnitOK = (BOOL)(bAppHeadUnitOK&0x01);
    
    CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &SystemVol);

	CS_SIG_SyncReceive(SIG_ACCSTATUS, (U16 *)&AccStatus);
	
    if(SystemVol!=V_NORMAL)
    {
        //PowerOnSelfCheckControlPower();
        return;
    }

    if(!sbAppHeadUnitOK)
    {
        _memset(bCameraFaultFromJ6 ,TRUE,4);
    }

	if(AccStatus)
	{
		PowerOnSelfCheckDtcHandler();
		Diag_camera_handler();
	}

    ReportDtc();
}

#ifdef CAN_DIAG_OPTION
BOOL Dtc_GetCanDiagDeviceDtc(U8* dtc)
{
    if(bPowerOnDtcEnd)
    {
        U8 i;
        for(i=0;i<CANDTC_CIRCUIT_CHECK_TYPE_NUMBER;i++)
        {
            dtc[i] = alertData.canDiagDtcData[i];
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif
BOOL Dtc_GetCanDiagSensors_PowerDtc(U8* dtc)
{
    if(bPowerOnDtcEnd)
    {
        U8 i;
        for(i=0;i<6;i++)
        {
            dtc[i] = alertData.canDiagDtcData0[i];
        }
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
BOOL Dtc_GetNaviDiagResult(U8* dtc)
{
    if(bPowerOnDtcEnd)
    {
        dtc[0] = alertData.s2NaviDtc.faultu>>8;
        dtc[1] = alertData.s2NaviDtc.faultu&0xff;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void ReportDtc(void)
{
    if(!sbAppHeadUnitOK) return;
    
    if((alertData.s2CanDtc1.cameraf!=alertDataBackup.s2CanDtc1.cameraf)
        ||(alertData.s2CanDtc2.ledf!=alertDataBackup.s2CanDtc2.ledf)
        ||(alertData.s2CanDtc3.bsdf != alertDataBackup.s2CanDtc3.bsdf))
        {    
            alertDataBackup.s2CanDtc1.cameraf = alertData.s2CanDtc1.cameraf;
            alertDataBackup.s2CanDtc2.ledf = alertData.s2CanDtc2.ledf;
			alertDataBackup.s2CanDtc3.bsdf = alertData.s2CanDtc3.bsdf;
            Report_DeviceDTCtoCan(alertData.s2CanDtc1.cameraf,alertData.s2CanDtc2.ledf,alertData.s2CanDtc3.bsdf); 
        }
    if(uCntForAVMpowerOn>0)
    {
        uCntForAVMpowerOn--;
        return;
    }
    
    if((alertData.s2NaviDtc.faultu!=alertDataBackup.s2NaviDtc.faultu)||(bReqReportcamerafault == TRUE))
    {
        alertDataBackup.s2NaviDtc.faultu = alertData.s2NaviDtc.faultu;
        Report_DeviceDTCtoCPU(alertDataBackup.s2NaviDtc.faultu);  
		bReqReportcamerafault = FALSE ;
    }

}

void Diag_camera_handler(void)
{
    U16 camera_status = 0;
    U8  camera_power = 0;
	U16 camera_videostream_status = 0;
    U8 i ;

    CS_SIG_AsyncReceive(SIG_CAMERA_DVR_DI_EN,&camera_power);
    camera_power = camera_power&0x01;
	if(!camera_power)
	{  
	   return;
	}
    /* check the camera status */
    for(i=0;i<4;i++)
    {
        CS_SIG_AsyncReceive(uDtcSig[i], &camera_status);
        /*open status*/
        if(camera_status<AD_CAMERA_OPEN_VALUE)
        {
             DtcRecordTimeHandler(i,TRUE,DEVICE_OPEN,DTC_RECOVER_TIME,DTC_SET_TIME); //open
        }
        /*short status*/
        else if((camera_status>=AD_CAMERA_SHORT_BAT_MIN)&&(camera_status<AD_CAMERA_SHORT_BAT_MAX))
        {
             DtcRecordTimeHandler(i,TRUE,DEVICE_SHORT_TO_BAT,DTC_RECOVER_TIME,DTC_SET_TIME); //short to BAT
        }
		else if((camera_status>=AD_CAMERA_SHORT_GND_MIN)&&(camera_status<AD_CAMERA_SHORT_GND_MAX))
        {
             DtcRecordTimeHandler(i,TRUE,DEVICE_SHORT_TO_GND,DTC_RECOVER_TIME,DTC_SET_TIME); //short to GND
        }
		/*normal status*/
        else if((camera_status>=AD_CAMERA_NORMAL_MINM) && (camera_status<AD_CAMERA_NORMAL_MAX))
        {
             DtcRecordTimeHandler(i,FALSE,DEVICE_NORMAL,DTC_RECOVER_TIME,DTC_SET_TIME); //normal
        }
    }
}

void DtcRecordTimeHandler(U8 dtcNum,BOOL bError,U8 device_type,U16 recovertime,U16 settime)
{
    if(bError)
    {
        sDtcData[dtcNum].dtc_create_cnt++;
        sDtcData[dtcNum].dtc_recover_cnt = 0;

        if(sDtcData[dtcNum].dtc_create_cnt >= settime)
        {            
            sDtcData[dtcNum].dtc_create_cnt = 0;
            sDtcData[dtcNum].berr = TRUE;
            DtcRecord_SetNaviDtc(dtcNum,device_type);
        }
    }
    else
    {
        sDtcData[dtcNum].dtc_create_cnt = 0;
        sDtcData[dtcNum].dtc_recover_cnt ++;

        if(sDtcData[dtcNum].dtc_recover_cnt >= recovertime)
        {            
            sDtcData[dtcNum].dtc_recover_cnt= 0;
            sDtcData[dtcNum].berr = FALSE;
            DtcRecord_SetNaviDtc(dtcNum,device_type);
        }
    }
}

void DtcRecord_SetNaviDtc(U8 dtcnum,U8 device_type)
{
    switch(dtcnum)
    {
        case DTC_FRONT_CAMERA:          
                if(DEVICE_NORMAL == device_type)
                {
				#ifdef CAN_DIAG_OPTION
					alertData.canDiagDtcData[DTC_FRONT_CAMERA_OPEN_CIRCUIT] = 0;
                    alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_GND] = 0;
					alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_BAT] = 0;
				#endif
                    alertData.s2CanDtc1.camerab.front = 0;
                }
                else
                {
				#ifdef CAN_DIAG_OPTION
                    if(DEVICE_OPEN== device_type)
                    {
                        alertData.canDiagDtcData[DTC_FRONT_CAMERA_OPEN_CIRCUIT] = 1;
                        alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_BAT] = 0;
                    }
                    else if(DEVICE_SHORT_TO_BAT == device_type)
					{
						alertData.canDiagDtcData[DTC_FRONT_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_BAT] = 1;	
					}
					else if(DEVICE_SHORT_TO_GND == device_type)
                    {
                        alertData.canDiagDtcData[DTC_FRONT_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_GND] = 1;
						alertData.canDiagDtcData[DTC_FRONT_CAMERA_SHORT_BAT] = 0;
                    }

				#endif
                    alertData.s2CanDtc1.camerab.front = 1;
                }
                alertData.s2NaviDtc.faultb.front = device_type;      
        break;
        case DTC_LEFT_CAMERA:
                if(DEVICE_NORMAL == device_type)
                {
				#ifdef CAN_DIAG_OPTION
                    alertData.canDiagDtcData[DTC_LEFT_CAMERA_OPEN_CIRCUIT] = 0;
                    alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_GND] = 0;
					alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_BAT] = 0;
				#endif
                    alertData.s2CanDtc1.camerab.left = 0;
                }
                else
                {    
				#ifdef CAN_DIAG_OPTION
                    if(DEVICE_OPEN == device_type)
                    {
                        alertData.canDiagDtcData[DTC_LEFT_CAMERA_OPEN_CIRCUIT] = 1;
                        alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_BAT] = 0;
                    }
                    else if(DEVICE_SHORT_TO_BAT == device_type)
					{
						alertData.canDiagDtcData[DTC_LEFT_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_BAT] = 1;	
					}
					else if(DEVICE_SHORT_TO_GND == device_type)
                    {
                        alertData.canDiagDtcData[DTC_LEFT_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_GND] = 1;
						alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_BAT] = 0;
                    }

				#endif
                    alertData.s2CanDtc1.camerab.left = 1;
                }
                alertData.s2NaviDtc.faultb.left = device_type;     
        break;
        case DTC_REAR_CAMERA:
                if(DEVICE_NORMAL == device_type)
                {    
			#ifdef CAN_DIAG_OPTION
					alertData.canDiagDtcData[DTC_BACK_CAMERA_OPEN_CIRCUIT] = 0;
					alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_GND] = 0;
					alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_BAT] = 0;
			#endif
                    alertData.s2CanDtc1.camerab.rear = 0;
                }
                else
                {
				#ifdef CAN_DIAG_OPTION
                    if(DEVICE_OPEN== device_type)
                    {
                        alertData.canDiagDtcData[DTC_BACK_CAMERA_OPEN_CIRCUIT] = 1;
                        alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_BAT] = 0;
                    }
                    else if(DEVICE_SHORT_TO_BAT == device_type)
					{
						alertData.canDiagDtcData[DTC_BACK_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_BAT] = 1;	
					}
					else if(DEVICE_SHORT_TO_GND == device_type)
                    {
                        alertData.canDiagDtcData[DTC_BACK_CAMERA_OPEN_CIRCUIT] = 0;
                        alertData.canDiagDtcData[DTC_BACK_CAMERA_SHORT_GND] = 1;
						alertData.canDiagDtcData[DTC_LEFT_CAMERA_SHORT_BAT] = 0;
                    }

				#endif
                    alertData.s2CanDtc1.camerab.rear = 1;
                }
                alertData.s2NaviDtc.faultb.rear = device_type;   
        break;
        case DTC_RIGHT_CAMERA:
                if(DEVICE_NORMAL == device_type)
                {    
			#ifdef CAN_DIAG_OPTION
					alertData.canDiagDtcData[DTC_RIGHT_CAMERA_OPEN_CIRCUIT] = 0;
					alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_GND] = 0;
					alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_BAT] = 0;
			#endif
                    alertData.s2CanDtc1.camerab.right = 0;
                }
                else
                {
			#ifdef CAN_DIAG_OPTION
					if(DEVICE_OPEN== device_type)
					{
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_OPEN_CIRCUIT] = 1;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_BAT] = 0;
					}
					else if(DEVICE_SHORT_TO_BAT == device_type)
					{
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_OPEN_CIRCUIT] = 0;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_GND] = 0;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_BAT] = 1;	
					}
					else if(DEVICE_SHORT_TO_GND == device_type)
					{
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_OPEN_CIRCUIT] = 0;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_GND] = 1;
						alertData.canDiagDtcData[DTC_RIGHT_CAMERA_SHORT_BAT] = 0;
					}
			#endif
                    alertData.s2CanDtc1.camerab.right = 1;
                }
                alertData.s2NaviDtc.faultb.right = device_type;     
        break;	
        default:break;
    }

}
/**************** END OF FILE *****************************************/

