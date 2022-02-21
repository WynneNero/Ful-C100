/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department :CT AD NJ                                           *
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
*=====================================================================*/

#ifndef _DTC_H_
#define _DTC_H_
#include "config.h"
#include "EEPTable.h"
#include "canDiagDtcCfg.h"



/**** Definition of constants ****/
#define AD_CAMERA_OPEN_VALUE   		124 	/* =0.1*4096/3.3 */
#define AD_CAMERA_NORMAL_MINM	   	372 	/* =0.145*4096/3.3 */
#define AD_CAMERA_NORMAL_MIN	   	745 	/* =0.6*4096/3.3 */
#define AD_CAMERA_NORMAL_MAX	   	1862    /* =1.5*4096/3.3 */
#define AD_CAMERA_SHORT_GND_MIN   	2979    /* =2.4*4096/3.3 */
#define AD_CAMERA_SHORT_GND_MAX   	3289    /* =2.65*4096/3.3 */
#define AD_CAMERA_SHORT_BAT_MIN   	3786    /* =3.05*4096/3.3 */
#define AD_CAMERA_SHORT_BAT_MAX   	4096    /* =3.3*4096/3.3 */

#define AD_LED_SHORT_TO_GND_VALUE		    180		/* AD:0.1V 		*/
#define AD_APS_LED_SHORT_TO_BAT_VALUE		1241	/* =1.0*4096/3.3 */
#define AD_PDC_LED_SHORT_TO_BAT_VALUE		1241	/* =1.0*4096/3.3 */

/*
LED Normal ： 0.12V~0.5V
LED short to bat ：大于1V
LED short to and ：小于 0.05V
*/
#define AD_APS_LED_NORMAL_MIN	    220//149		/* =0.12*4096/3.3 */
#define AD_APS_LED_NORMAL_MAX	    620 	/* =0.50*4096/3.3 */

/*
LED Normal ： 0.12V~0.5V
LED short to bat ：大于1V
LED short to and ：小于 0.05V
*/
#define AD_PDC_LED_NORMAL_MIN	    149		/* =0.12*4096/3.3 */
#define AD_PDC_LED_NORMAL_MAX	    620 	/* =0.50*4096/3.3 */

#define BSD_LED_NORMAL_MAX   2590
#define BSD_LED_NORMAL_MIN   1200

#define DTC_LED_RECOVER_TIME 5	//100ms
#define DTC_LED_SET_TIME 	25	//500ms

/*
BSD:
LED Normal ： 0.994V ~ 2.48V
LED short to bat ：大于2.48V
LED short to and ：小于 0.1V
*/
#define AD_BSD_LED_NORMAL_MAX             3820      /* =2.48*4096/3.3 */
#define AD_BSD_LED_NORMAL_MIN			  1233		/* =0.994*4096/3.3 */

#define AD_BSD_LED_SHORT_TO_BAT_VALUE	  3820		/* =2.48*4096/3.3 */
#define AD_BSD_LED_SHORT_TO_GND_VALUE	  124       /* =0.1*4096/3.3 */

#define POWER_ON_HK_CHECK_TIMES 750//t=750*20ms


enum 
{
    DTC_FRONT_CAMERA,
    DTC_LEFT_CAMERA,
    DTC_REAR_CAMERA,
    DTC_RIGHT_CAMERA,
    DTC_BSD_RLED_STATUS,
	DTC_BSD_LLED_STATUS,
    DTC_FRONT_CAMERA_VIDEO_STREAM,
    DTC_LEFT_CAMERA_VIDEO_STREAM,
    DTC_REAR_CAMERA_VIDEO_STREAM,
    DTC_RIGHT_CAMERA_VIDEO_STREAM,
	DTC_APS_LED_STATUS,
	DTC_PDC_LED_STATUS,
	
    DTC_MAX_NUM,
};

typedef struct 
{
    U8 dtc_create_cnt;
    U8 dtc_recover_cnt;
    BOOL berr;
}E_DTC_RECORD_STRUCT;

enum 
{
    DEVICE_NORMAL,
    DEVICE_OPEN,
	DEVICE_SHORT_TO_BAT,
	DEVICE_SHORT_TO_GND,
};

enum
{
	CAMERA_VIDEO_NORMAL,
	CAMERA_VIDEO_INNORMAL,
};

enum
{
	BSD_DEVICE_NORMAL,
	BSD_DEVICE_INNORMAL,
};

enum
{
	TEMP_NORMAL = DEVICE_NORMAL,
	TEMP_TOO_LOW = DEVICE_OPEN,
	TEMP_TOO_HOT=DEVICE_SHORT_TO_GND,
};

enum
{
	AVM_SW_KEYSTA, 	
	APS_SW_KEYSTA, 	
	PDC_SW_KEYSTA, 	
};

enum
{
	USS_FAILURE_NORMAL = 0x0,
	USS_FAILURE_SIGNAL_SHORT_TO_POWER,
	USS_FAILURE_SIGNAL_SHORT_TO_GND,
	USS_FAILURE_INTERNAL_FAULT,
	USS_FAILURE_AFTERSHOCK_TOO_SHORT,
	USS_FAILURE_AFTERSHOCK_TOO_LONG,
};

typedef struct _ALERT_STRUCT
{
    union
    {
        U16 faultu;
        struct
        {
            U16 front:2;
            U16 left:2;
            U16 rear:2;
            U16 right:2;
            U16 buzz:2;
            U16 led1:2;
            U16 led2:2;
            U16 unsed:2;            
        }faultb;
    }s2NaviDtc;
    
    union
    {
        U8 cameraf;
        struct
        {
            U8 front:1;
            U8 rear:1;
            U8 left:1;
            U8 right:1;    
            U8 unsed:4;                 
        }camerab;
    }s2CanDtc1;
    
    union
    {
        U8 ledf;
        struct
        {
            U8 led1:1;
            U8 led2:1;
            U8 unsed:6;                 
        }ledb;
    }s2CanDtc2;

	union
	{
		U8 bsdf;
		struct
		{
			U8 bsdleft:1;
			U8 bsdright:1;
			U8 unsed:6;
		}bsdb;
	}s2CanDtc3;
//----zwy--
	union
	{
		U8 Radaf;
		struct
		{
			U8 RadaFront:1;
			U8 RadaRear:1;
			U8 unsed:6;
		}Radab;
	}s2CanDtc4;
	U8 canDiagDtcData0[6];// Front & Rear
//---end---
    #ifdef CAN_DIAG_OPTION
    U8 canDiagDtcData[CANDTC_CIRCUIT_CHECK_TYPE_NUMBER];  
    #endif
	
}ALERT_STRUCT;
	





/**** Definition of types ****/
extern void Dtc_Init(void);
extern void Dtc_Main(void);
extern void CanApp_ReportDeviceDtc(U8 camerafault,U8 ledfault,U8 bsdfault);
extern void CanApp_ReportDeviceDtcToCpu(U16 fault);
#ifdef CAN_DIAG_OPTION
extern BOOL Dtc_GetCanDiagDeviceDtc(U8* dtc);
extern BOOL Dtc_GetCanDiagTempDtc(U8* dtc);
extern BOOL Dtc_GetCanDiagSensors_PowerDtc(U8* dtc);
#endif
#ifdef EOL_OPTION
extern BOOL Dtc_GetNaviDiagResult(U8* dtc);
#endif
#define Report_DeviceDTCtoCan(camerafault,ledfault,bsdfault)  CanApp_ReportDeviceDtc(camerafault,ledfault,bsdfault)
#define Report_DeviceDTCtoCPU(fault) CanApp_ReportDeviceDtcToCpu(fault)
extern U16 uDtcSig[DTC_MAX_NUM];
extern ALERT_STRUCT alertData;

#endif /*_DTC_H_*/


