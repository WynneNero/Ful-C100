/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                			     *
*                 All Rights Reserved.                                 						     *
*   Department : CT_ITTI_HZ                                         						     *
*   AUTHOR     :                                       									     *
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
* Version       	Date    			Name    			Changes and comments
* ----------------------------------------------------------------------
* 0.1    		Aug 28,2018          Zheng Xiaolei 		init version
*======================================================*/
#include "CONFIG.H"
#include "TYPES.H"
#include <Tools.h>
#include "Cansig_cfg_if.h"
#include "Core_Cfg.h"
#include "UltraRadarBasicTask.h"
#include "CanAPPApa.h"
#include "com_cfg.h"
#include "InputSignalProc.h"
#include "CanAppUltraRadar_IF.h"
#include "ObjDetect_Pub.h"
#include "SlotParaCfg.h"
#include "eol_app.h"

#include "typeDefine.h"
#include "r_cg_userdefine.h"
#include "ussLibIf.h"
#include "ussLibAdapt.h"
#include "gpio_if.h"
/*---Global-----------------------------------------------------------*/
extern void APA_TaskBGLoop(void);
extern void UPA_Tauj_Task(void);
extern void TAUD_SysTime_start(void);
extern void ObjDetectCommonParaInit(void) ;
extern void ObjDetect_InfoOutParInit(void) ;
extern void ApaStateMachine_Init(void);
extern void InputSignal_ProcessInit(void);
extern void InputSignal_ProcessMain_T10(void);

/*---Global--variable-----------------------------------------------------------*/

/*---Local--variable-----------------------------------------------------------*/

//Objdetect Lib Version
unsigned long long ObjdetectLibVersion = 0;


/***********************************************************************
*  Name        : UltraRadarFastTaskEntry
*  Description :  
*  Parameter   : None
*  Returns     : None
***********************************************************************/
extern void delay_us(U16 period);
#include "xprintf.h"
#define UltraRadarFastTaskEntry_TIME_TEST	1
void UltraRadarFastTaskEntry(void)
{
#if FV_USS
	#if UltraRadarFastTaskEntry_TIME_TEST
	volatile U16 sysTick1 = OSAlarm_GetSystemTime();
	volatile U16 sysTick2;
	//xprintf("SG-%d\n",sysTick1);


	//GPIO_SetOutputMode(11,13, E_PUSH_PULL, E_LOW_10MHZ);
	//GPIO_SetVal(11,13,1);

    //delay_us(10000);
    #endif
	
	ussObjLibRunnable_Bg1ms();
	//GPIO_SetVal(11,13,0);
	#if UltraRadarFastTaskEntry_TIME_TEST
	sysTick2 = OSAlarm_GetSystemTime();
	if((sysTick2-sysTick1)>5)
	{
	}
	#endif
#else

	if(eEolState != E_EOL_NORMAL)
	{
		UPA_Tauj_Task();
	}
	else
	{

	}
#endif
}

/***********************************************************************
*  Name        : UltraRadarSlowTaskEntry
*  Description : 
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void UltraRadarSlowTaskEntry(void)
{
	APA_TaskBGLoop();
}

/***********************************************************************
*  Name        : UltraRadarCyclicTaskInit
*  Description :  
*  Parameter   : None
*  Returns     : None
***********************************************************************/
#include "config.h"
#include "GPIO_IF.H"
#include "gpioApp.h"
#include "r_cg_dmac.h"
#include "r_cg_taub.h"
#include "ussLibIf.h"
void UltraRadarCyclicTaskInit(void)
{
#ifdef FV_USS	
	ussDmaUserInit();
	R_MAIN_UserInit();	// capture timer ,io and dma cfg.

	// uss power ctrl IO cfg.
	GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_8,E_PUSH_PULL,E_LOW_10MHZ);
	GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_9,E_PUSH_PULL,E_LOW_10MHZ);

    g_setOutputPin_0();
    g_setOutputPin_1();
    g_setOutputPin_2();
    g_setOutputPin_3();
    g_setOutputPin_4();
    g_setOutputPin_5();
    g_setOutputPin_6();
    g_setOutputPin_7();
    g_setOutputPin_8();
    g_setOutputPin_9();
    g_setOutputPin_10();
    g_setOutputPin_11();
#if 0
	// all uss Tx IO cfg.
    GPIO_SetInputMode(USS_SNS_RRS_TX_PORT,USS_SNS_RRS_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_RR_TX_PORT,USS_SNS_RR_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_RRM_TX_PORT,USS_SNS_RRM_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_RLM_TX_PORT,USS_SNS_RLM_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_RL_TX_PORT,USS_SNS_RL_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_RLS_TX_PORT,USS_SNS_RLS_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FRS_TX_PORT,USS_SNS_FRS_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FR_TX_PORT,USS_SNS_FR_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FRM_TX_PORT,USS_SNS_FRM_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FLM_TX_PORT,USS_SNS_FLM_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FL_TX_PORT,USS_SNS_FL_TX_PIN,E_NO_MODE);
    GPIO_SetInputMode(USS_SNS_FLS_TX_PORT,USS_SNS_FLS_TX_PIN,E_NO_MODE);
#endif
/*


	g_setPortValue_vd_0(0);	
	g_setPortValue_vd_0(1);
	g_setPortValue_vd_1(0);	
	g_setPortValue_vd_1(1);	
	g_setPortValue_vd_2(0);	
	g_setPortValue_vd_2(1);	
	g_setPortValue_vd_3(0);	
	g_setPortValue_vd_3(1);	
	g_setPortValue_vd_4(0);	
	g_setPortValue_vd_4(1);	
	g_setPortValue_vd_5(0);	
	g_setPortValue_vd_5(1);	
	
	g_setPortValue_vd_6(0);	
	g_setPortValue_vd_6(1);
	g_setPortValue_vd_7(0);	
	g_setPortValue_vd_7(1);	
	g_setPortValue_vd_8(0);	
	g_setPortValue_vd_8(1);	
	g_setPortValue_vd_9(0);	
	g_setPortValue_vd_9(1);	
	g_setPortValue_vd_10(0);	
	g_setPortValue_vd_10(1);	
	g_setPortValue_vd_11(0);	
	g_setPortValue_vd_11(1);	
*/
	
	// uss timer capture IO cfg.
    GPIO_SetAlterMode(11,2,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,11,E_ALTERFUNC_3, GPIO_OPT_INPUT);   
    GPIO_SetAlterMode(0,12,E_ALTERFUNC_3, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,13,E_ALTERFUNC_3, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(11,1,E_ALTERFUNC_4, GPIO_OPT_INPUT);  // RLS 
    GPIO_SetAlterMode(0,14,E_ALTERFUNC_3, GPIO_OPT_INPUT);  // RL 
    GPIO_SetAlterMode(10,14,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,10,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,9,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,8,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(0,7,E_ALTERFUNC_4, GPIO_OPT_INPUT);
    GPIO_SetAlterMode(10,13,E_ALTERFUNC_4, GPIO_OPT_INPUT);
	
	ussLibDrvOpen();
	ussLibAdaptOpen();
#ifdef USS_LIB_STUB_TEST
extern	void ussLibDriverTest(void);
	ussLibDriverTest();
#endif
	
#else
	TAUD_SysTime_start();
	InputSignal_ProcessInit();    
	ObjDetectCommonParaInit();
	ObjDetect_InfoOutParInit();
	SlotSearching_ParameterInit();
	ApaStateMachine_Init();
	Timer_Start(OPEN_ULTRA_RADAR_CYCLIC_TASK, 10, TIMER_PERIODIC);
	Timer_Start(OPEN_APA_SLOT_SEARCHING, 10, TIMER_PERIODIC);
	//Objdetect Lib Version
#endif
}



/******************************************************************************
** Function:    Com_RxSignalSW
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
void Com_RxSignalSW( unsigned char SignalID_u8, signed short * SignalValue_ps16)
{
	switch(SignalID_u8)
	{
		case COM_SIGID_CE_StrWhAng:
			//CanSig_CANGetValue(RX_SIG_GET_ID_StrWhAng, (U8*)SignalValue_ps16, 2);
		break;
		default:
		break;
	}
}

/******************************************************************************
** Function:    Com_RxSignalUW
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
void Com_RxSignalUW( unsigned char SignalID_u8, unsigned short *SignalValue_pu16 )
{
	switch(SignalID_u8)
	{
		case COM_SIGID_CE_WhlDistPrRevDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlDistPrRevDrvn, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WhlDistPrRevNDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlDistPrRevNDrvn, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WhlGrndVlctyLftNnDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyLftNnDrvn, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WhlGrndVlctyRtNnDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyRtNnDrvn, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WRSLDWhlDistPlsCntr:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WRSLDWhlDistPlsCntr, (U8*)SignalValue_pu16, 2);
		break;		
		case COM_SIGID_CE_WRSRDWhlDistPlsCntr:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WRSRDWhlDistPlsCntr, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WRSLNDWhlDistPCntr:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WRSLNDWhlDistPCntr, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_CE_WRSRNDWhlDistPCntr:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WRSRNDWhlDistPCntr, (U8*)SignalValue_pu16, 2);
		break;
		case COM_SIGID_LS_VehSpdAvgDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_VehSpdAvgDrvn, (U8*)SignalValue_pu16, 2);
		break;
		default:
		break;
	}
}

/******************************************************************************
** Function:    Com_RxSignalUB
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
void Com_RxSignalUB( unsigned char SignalID_u8, unsigned char *SignalValue_pu8 )
{
	switch(SignalID_u8)
	{
		case COM_SIGID_LS_TrnSwAct:
			//CanSig_CANGetValue(RX_SIG_GET_ID_TrnSwAct, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_WhlPlsPerRevDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlPlsPerRevDrvn, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_WhlPlsPerRevNonDrvn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlPlsPerRevNonDrvn, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_WhlGrndVlctyLftNnDrvnV:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyLftNnDrvnV, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_WhlGrndVlctyRtNnDrvnV:
			//CanSig_CANGetValue(RX_SIG_GET_ID_WhlGrndVlctyRtNnDrvnV, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_TrnsShftLvrPosV:
			//CanSig_CANGetValue(RX_SIG_GET_ID_TrnsShftLvrPosV, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_CE_TrnsShftLvrPos:
			//CanSig_CANGetValue(RX_SIG_GET_ID_TrnsShftLvrPos, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_LS_OtsAirTmpCrVal:
			//CanSig_CANGetValue(RX_SIG_GET_ID_OtsAirTmpCrVal, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_LS_VehSpdAvgDrvnV:
			//CanSig_CANGetValue(RX_SIG_GET_ID_VehSpdAvgDrvnV, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_LS_SysBkupPwrMdEn:
			//CanSig_CANGetValue(RX_SIG_GET_ID_SysBkupPwrMdEn, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_LS_SysBkUpPwrMdV:

		break;
		case COM_SIGID_LS_SysBkUpPwrMd:
			//CanSig_CANGetValue(RX_SIG_GET_ID_SysBkUpPwrMd, (U8*)SignalValue_pu8, 1);
		break;
		case COM_SIGID_LS_SysPwrMdV:

		break;
		case COM_SIGID_LS_SysPwrMd:
			//CanSig_CANGetValue(RX_SIG_GET_ID_SysPwrMd, (U8*)SignalValue_pu8, 1);
		break;		
		default:
		break;
	}
}

unsigned char PerRevNonDrvnSigSts = FALSE;
/******************************************************************************
** Function:    ApplWhlPlsPerRevNonDrvnSigIndication
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
void ApplWhlPlsPerRevNonDrvnSigIndication(void)
{
	PerRevNonDrvnSigSts = TRUE;
}

/******************************************************************************
** Function:    IlGetWhlPlsPerRevNonDrvn_1Indication
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
unsigned char IlGetWhlPlsPerRevNonDrvn_1Indication(void)
{
	return PerRevNonDrvnSigSts;
}

/******************************************************************************
** Function:    IlClrWhlPlsPerRevNonDrvn_1Indication
** Description: 
** Parameter:   None
** Return:      
******************************************************************************/
void IlClrWhlPlsPerRevNonDrvn_1Indication(void)
{
	PerRevNonDrvnSigSts = FALSE;
}



/**************** END OF FILE *****************************************/
