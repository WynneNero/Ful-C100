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
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1  Apr 15,2016   Pei JL      Initial. clock hand in MCU work mode
------------------------------------------------------------------------
* 0.2  Jun 29,2016   LIU Chenxi  Correct errors during merging
* ----------------------------------------------------------------------
* 0.3  Aug 1,2016   PEI Jingli   add Sig_ADTick and Sig_DioTick
* ----------------------------------------------------------------------
* 0.4  Aug 31,2016               re-structure 
*-----------------------------------------------------------------------
* 0.5  Sep 13,2016  PEI Jingli add app initial and eep handler
* ----------------------------------------------------------------------
* 0.6  Jan 05,2017  ZhangJie  Delete test code for CAN_TEST/IIC_TEST 
*------------------------------------------------------------------------
* 0.7  Jan 11,2017  ZhangJie  Add u for constant value to avoid Coverity warning.
*-----------------------------------------------------------------------
* 0.8  Jan 24,2017   ZhangJie   Remove unused include file.
*-----------------------------------------------------------------------
* 0.9  Feb 10,2017   ZhangJie   Remove Application_SystemStateHandle from 5ms task.
*------------------------------------------------------------------------
* 1.0  Mar 08,2017  ZhangJie    Add  cpu usage rate cyclic task in 100ms container .
*-----------------------------------------------------------------------
* 1.1  Mar 08,2017   ZhangJie   Add stack check task in 100ms Container.
*----------------------------------------------------------------------
* 1.2  Mar 22,2017    ZhangJie    change stack usage task to 10ms.
*-----------------------------------------------------------------------
* 1.3  Apr 01,2017   PEI Jingli  Fix headfiles.
*=====================================================================*/
#include "config.h"
#include <Cyclicmng.h>
#include "CYCLICTASK_CFG.h"
#include "Core_Cfg.h"
#include "CanApp.h"
#include "CONFIG.H"  // LLF_MARK
#include "TYPES.H"
#include "M4MsgHandler.h"
#include "candiagdtc.h"
#include "NaviApp.h"
#include "CanDiagDtc.h"
#include "CanDiagService.h"
#include "Dtc.h"
#include "eol_app.h"
#include "ComplexDrvier_Globaldef_IF.H"
#include "ApsCanAPP.h"
#include "CanApp.h"
#include "UssInfoMsg.h"
#include "CanXcp.h"
#include "pdcCtrl.h"
#include "ussLibIf.h"
#include "ussLibAdapt.h"
#include "gpio_if.h"
#include "xprintf.h"
#include "FVAlgLibInterface.h"




//#include "SWP_Test.H"

/*---Global-----------------------------------------------------------*/
extern void Application_S0Init(void);
extern void Application_SystemStateHandle(void);
extern void CanDriver_10ms_Entry(void);
extern void CanManager_10ms_Entry(void);
extern void EED_Upload_entry(void);
extern void EED_Download_entry(void);
extern void EolUartDriver_10ms_Entry(void);
extern void EolMsg_20ms_Entry(void);
extern void EolService_20msEntry(void);
extern void M4UartDriver_5ms_Entry(void);
extern void M4Msg_40ms_Entry(void);
extern void illum_lcd_polling(void);
extern void PowerManager_5msEntry(void);
//extern void RvcTuner_PowerControl_5msEntry(void);
//extern void Sig_ADTick(void);
extern void Sig_ADG0Tick(void);
extern void Sig_ADG1Tick(void); 
extern void Sig_DioTick(void);
extern void SocDriver_Cyclic_Entry(void);
extern void SocMsg_20ms_Entry(void);
extern void SocManager_20msEntry(void);
extern void SocTransmitManager_10ms_Entry(void);
extern void APS_Track_Module_20ms_Entry(void);
//void TimerTask_5msEntry(void);
extern void APS_Module_Manager_5ms_Entry(void);
extern void UltraRadarSlotSearchingSlotOutLineMsg(void);

//extern void keyboard_scan(void);
//extern void eng_task_20msEntry(void);
#ifdef __DEBUG__
extern void CpuRate_100msEntry(void);
extern void StackRate_10msEntry(void);
#endif
//extern void Calendar_PowerOn_Handler(void);
//extern void Init_SystemVersion_EEP(void);
//extern void star_eep_job_handle(void);
/* 
* Pointers to the functions that are to be carried out within 25ms foreground loop. The 
* last entry in the array has to be NULL.
*/
U8 Switch_PAS_SVA_APA_Status = PAS_SVA_APA_Status_default_Switch;
U8 Switch_PAS_PDC_Status = PAS_PDC_Status_default_Switch;
U8 Switch_Test_1_To_A = Test_1_To_A_default_Switch;

void Message_PAS_SVA_APA_Status_Debug_Switch(unsigned char data)
{
	 Switch_PAS_SVA_APA_Status = data;
}

void Message_PAS_PDC_Status_Debug_Switch(unsigned char data)
{
	 Switch_PAS_PDC_Status = data;
}

void Message_Test_1_To_A_Debug_Switch(unsigned char data)
{
	Switch_Test_1_To_A = data;
}


void SysCycle_apS0FastT5msContainer(void)
{  
    /*AUTOGEN: Member*/
   Application_SystemStateHandle();
   Sig_DioTick();
   Sig_ADG0Tick();
   PowerManager_5msEntry();
   pdcCtrlTask5ms();
   xprintfLoop();
 
}

void SysCycle_apS1FastT5msContainer(void)
{
    /*AUTOGEN: Member*/
}

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 2u)
void  SysCycle_apS2FastT5msContainer(void)
{	
	Application_SystemStateHandle();
 	Sig_DioTick();
	Sig_ADG0Tick();
	PowerManager_5msEntry();   // LLF_MARK
	pdcCtrlTask5ms();
	xprintfLoop();
	
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 2) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 3u)
void SysCycle_apS3FastT5msContainer(void)
{  
#if 1
	M4UartDriver_5ms_Entry();

	Application_SystemStateHandle();
	Sig_DioTick();
	Sig_ADG0Tick();
	PowerManager_5msEntry();
//	RadarPowerManagementHandler_5msEntry();
    SocDriver_Cyclic_Entry();
	APS_Module_Manager_5ms_Entry();
	XcpCycleTask();
	pdcCtrlTask5ms();
	#endif
	xprintfLoop();
	//pdcCtrlTask5ms();
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 3) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 4u)
void SysCycle_apS4FastT5msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 4) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 5u)
void SysCycle_apS5FastT5msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 5) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 6u)
void SysCycle_apS6FastT5msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 6) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 7)
void SysCycle_apS7FastT5msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 7) */


/*
* Pointers to the functions that are to be carried out within 50ms phase1 foreground loop.
* The last entry in the array has to be NULL.
*/

void SysCycle_apS0FastT10msContainer(void)
{
// Sig_ADG0Tick();




  //  Sig_ADG1Tick(); //uidq1158
   CanManager_10ms_Entry();
}

void SysCycle_apS1FastT10msContainer(void)
{
    /*AUTOGEN: Member*/
}

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 2u)
void SysCycle_apS2FastT10msContainer(void)
{
    EED_Upload_entry();
    //Sig_ADTick();	    
//	Sig_ADG0Tick();
//	Sig_ADG1Tick(); //uidq1158
	//Init_SystemVersion_EEP();
    SocTransmitManager_10ms_Entry();
	CanManager_10ms_Entry();

    //Application_SystemStateHandle();
#ifdef IIC_TEST
	IIC_10ms_test();	//just for test, normally S2 should not last long
#endif

}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 2) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 3u)
#ifdef EEP_EEL_TEST
BOOL WR=TRUE;
extern void eel_eepWrite(void);
#endif
#ifdef EEP_DIRECT_FDL_TEST
void DataFlash_DirectRW_Test(void);
#endif

#define SysCycle_apS3FastT10msContainer_TIME_TEST 0
void SysCycle_apS3FastT10msContainer(void)
{
#if SysCycle_apS3FastT10msContainer_TIME_TEST
	volatile U16 sysTick1 = OSAlarm_GetSystemTime();
	volatile U16 sysTick2;
	xprintf("SM-%d\n",sysTick1);
#endif

#ifdef __DEBUG__
    StackRate_10msEntry();
#endif
	//GPIO_SetOutputMode(11,13, E_PUSH_PULL, E_LOW_10MHZ);
	//GPIO_SetVal(11,13,1);
    //Sig_ADTick();    
	ussObjLibRunnable_Main10ms();
	ObjDetectDistanceUpdateLoop();
    
	#if (MCU_PIN > PIN100)
 	Sig_ADG1Tick();
	#endif
    Sig_DioTick();
    EED_Download_entry();
	CanDriver_10ms_Entry();
    CanManager_10ms_Entry();
    EolUartDriver_10ms_Entry();

#ifdef IIC_TEST
	IIC_10ms_test();
#endif
#if SysCycle_apS3FastT10msContainer_TIME_TEST	
	sysTick2 = OSAlarm_GetSystemTime();
	if((sysTick2-sysTick1)>2)
	{
        xprintf("TM-%d\n",(sysTick2-sysTick1));
	}
#endif

	//GPIO_SetVal(11,13,0);	

#ifdef EEP_EEL_TEST
  if(WR)
  {
  eel_eepWrite();
    WR=FALSE;
  }
#endif
#ifdef EEP_DIRECT_FDL_TEST
  DataFlash_DirectRW_Test();
#endif

    APS_PathPlan_Module_10ms_Entry();

}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 3) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 4u)
void SysCycle_apS4FastT10msContainer(void)
{
    //Sig_ADTick();  
	Sig_ADG0Tick();
	//Sig_ADG1Tick(); //uidq1158
    EED_Upload_entry();
    Application_SystemStateHandle();
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 4) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 5u)
void SysCycle_apS5FastT10msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 5) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 6u)
void SysCycle_apS6FastT10msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 6) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 7u)
void SysCycle_apS7FastT10msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 7) */


/*
* Pointers to the functions that are to be carried out within 50ms phase2 foreground loop.
* The last entry in the array has to be NULL.
*/
void SysCycle_apS0FastT20msContainer(void)
{
    /*AUTOGEN: Member*/
}

void SysCycle_apS1FastT20msContainer(void)
{
    /*AUTOGEN: Member*/
}

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 2u)
void SysCycle_apS2FastT20msContainer(void)
{
    /* Button_Main();*/
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 2) */

U8 M4MsgSendCnt = 0;
U32 M4MsgSendCounter = 0;
U16 M4MsgSendChecksum = 0;

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 3u)
void SysCycle_apS3FastT20msContainer(void)
{	
	//M4_NotifyStart();
    SocMsg_20ms_Entry();	
    SocManager_20msEntry();
    //keyboard_scan();
	//illum_lcd_polling();
	//eng_task_20msEntry();
	SocNavi_20ms_Entry();
	SocCan_20ms_Entry();
	#ifdef CAN_DIAG_OPTION
    CanDiagDtc_20msEntry();
    CanDiagService_20msEntry();
	Dtc_Main();
	#endif
    EolMsg_20ms_Entry();
    EolService_20msEntry();
    EOL_Main();

	SocApsCan_20ms_Entry();
	USS_INFO_Handler();
	//UltraRadarSlotSearchingSlotOutLineMsg();
	M4MsgSendCnt++;
	if(M4MsgSendCnt > 1)
	{
		if(M4MsgSendCounter == 0xFFFF)
		{
			M4MsgSendCounter = 0;
		}
        
		M4Msg_Update(E_M4MSGCOUNTER_U16,M4MsgSendCounter);
		M4Msg_40ms_Entry();
		M4MsgSendCounter++;
		M4MsgSendCnt = 0;		
	}
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 3) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 4u)
void SysCycle_apS4FastT20msContainer(void)
{
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 4) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 5u)
void SysCycle_apS5FastT20msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 5) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 6u)
void SysCycle_apS6FastT20msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 6) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 7u)
void SysCycle_apS7FastT20msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 7) */


void SysCycle_apS0SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}


void  SysCycle_apS1SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 2u)
void SysCycle_apS2SlowT50msContainer(void)
{
   /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 2) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 3u)

void SysCycle_apS3SlowT50msContainer(void)
{

	if(Switch_Test_1_To_A)
		{
		}
/*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 3) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 4u)
void SysCycle_apS4SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 4) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 5u)
void SysCycle_apS5SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 5) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 6u)
void SysCycle_apS6SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 6) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 7u)
void SysCycle_apS7SlowT50msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 7) */


/*
* Pointers to the functions that are to be carried out within 100ms phase1 foreground loop.
* The last entry in the array has to be NULL.
*/
void SysCycle_apS0SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}


void SysCycle_apS1SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 2u)
void SysCycle_apS2SlowT100msContainer(void)
{

    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 2) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 3u)
void SysCycle_apS3SlowT100msContainer(void)
{
#ifdef __DEBUG__
    CpuRate_100msEntry();
#endif
	//Calendar_PowerOn_Handler();
    /*AUTOGEN: Member*/
	//star_eep_job_handle();
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 3) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 4u)
void SysCycle_apS4SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 4) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 5u)
void SysCycle_apS5SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 5) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 6u)
void SysCycle_apS6SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 6) */

#if (SYS_CFG_NO_OF_SYSTEM_STATES > 7u)
void SysCycle_apS7SlowT100msContainer(void)
{
    /*AUTOGEN: Member*/
}
#endif /* #if (SYS_CFG_NO_OF_SYSTEM_STATES > 7) */


/* alarm config*/
const SysCycle_CycleTaskDef  SysCycle_astFastAlarm[] =
{
    {1u,  0u}, /*5ms*/
    {2u,  1u}, /*10ms*/
    {4u,  2u} /*20ms*/
} ;

const Func_Void_Proc SysCycle_apFastTmsContainer[SYS_CFG_NO_OF_SYSTEM_STATES][SYSCYCLE_FASTCYCLE_COUNT]=
{
    /*5ms,  10ms, 20ms*/
    {SysCycle_apS0FastT5msContainer,  SysCycle_apS0FastT10msContainer,  SysCycle_apS0FastT20msContainer}, /*s0*/
    {SysCycle_apS1FastT5msContainer,  SysCycle_apS1FastT10msContainer,  SysCycle_apS1FastT20msContainer}, /*s1*/
    {SysCycle_apS2FastT5msContainer,  SysCycle_apS2FastT10msContainer,  SysCycle_apS2FastT20msContainer}, /*s2*/
    {SysCycle_apS3FastT5msContainer,  SysCycle_apS3FastT10msContainer,  SysCycle_apS3FastT20msContainer}, /*s3*/
    {SysCycle_apS4FastT5msContainer,  SysCycle_apS4FastT10msContainer,  SysCycle_apS4FastT20msContainer}, /*s4*/
    {SysCycle_apS5FastT5msContainer,  SysCycle_apS5FastT10msContainer,  SysCycle_apS5FastT20msContainer}, /*s5*/
    {SysCycle_apS6FastT5msContainer,  SysCycle_apS6FastT10msContainer,  SysCycle_apS6FastT20msContainer}, /*s6*/
    {SysCycle_apS7FastT5msContainer, SysCycle_apS7FastT10msContainer,  SysCycle_apS7FastT20msContainer}/*s7*/
};

const SysCycle_CycleTaskDef  SysCycle_astSlowAlarm[] =
{
    {2u,  1u},/*50ms*/
    {4u,  2u},/*100ms*/
};

const Func_Void_Proc SysCycle_apSlowTmsContainer[SYS_CFG_NO_OF_SYSTEM_STATES][SYSCYCLE_SLOWCYCLE_COUNT]=
{
    /*50,  100ms*/
    {SysCycle_apS0SlowT50msContainer,   SysCycle_apS0SlowT100msContainer}, /*s0*/
    {SysCycle_apS1SlowT50msContainer,   SysCycle_apS1SlowT100msContainer}, /*s1*/
    {SysCycle_apS2SlowT50msContainer,   SysCycle_apS2SlowT100msContainer}, /*s2*/
    {SysCycle_apS3SlowT50msContainer,   SysCycle_apS3SlowT100msContainer}, /*s3*/
    {SysCycle_apS4SlowT50msContainer,   SysCycle_apS4SlowT100msContainer}, /*s4*/
    {SysCycle_apS5SlowT50msContainer,   SysCycle_apS5SlowT100msContainer}, /*s5*/
    {SysCycle_apS6SlowT50msContainer,   SysCycle_apS6SlowT100msContainer},/*s6*/
    {SysCycle_apS7SlowT50msContainer,   SysCycle_apS7SlowT100msContainer}/*s7*/
};

void SysCycle_apTimerContainer(void)
{
	
}



/**************** END OF FILE *****************************************/

