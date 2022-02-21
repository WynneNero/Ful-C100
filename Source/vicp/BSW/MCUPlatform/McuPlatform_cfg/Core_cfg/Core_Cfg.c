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
*------------------------------------------------------------------------
* 0.1          Jun 11,2016            Init version.
*------------------------------------------------------------------------
* 0.2         Jan 24,2017  ZhangJie  Fix Coverity warning.
*----------------------------------------------------------------------
* 0.3        Mar 07,2017  PEI Jingli   Fix headfile included.
*=====================================================================*/

/**** System include files ****/
#include "Define.h"
#include "OSAPIDef.h"
/*---Public include files---------------------------------------------*/

/*---Private include files--------------------------------------------*/
#include "CORE_CFG.H"

/*===VARIABLES========================================================*/


/*---Private----------------------------------------------------------*/


/*---Global-----------------------------------------------------------*/




/*---Private----------------------------------------------------------*/

/*---Global-----------------------------------------------------------*/
extern void SysSwitch_HighTaskEntry(void);
extern void SysCycle_FastTaskEntry(void);
extern void SysEvt_TaskEntry(void);
extern void SysCycle_SlowTaskEntry(void);
extern void SysJob_TaskEntry(void);
extern void SysSwitch_LowTaskEntry(void);
extern void UltraRadarFastTaskEntry(void);
extern void UltraRadarSlowTaskEntry(void);

//task config
//task stack
/* All task stack             */
/*
#if(OSAPI_HIGHSWITCHTASK_EN==1u)
OSADP_STK OSCfg_astHSTaskStk[128];    // stack size = 512
#endif
OSADP_STK OSCfg_astFCTaskStk[128];    // stack size = 512
OSADP_STK OSCfg_astEVTaskStk[128];    // stack size = 512
OSADP_STK OSCfg_astSCTaskStk[128];    // stack size = 512
OSADP_STK OSCfg_astSJTaskStk[128];    // stack size = 512
OSADP_STK OSCfg_astLSTaskStk[128];    // stack size = 512
*/

/*task config*/
const OSAPI_TaskCfgType OSCfg_astAllTask[OSAPI_TASKNUM] =
{
		{OSAPI_SYSTEMSWITCHHIGH, 	FALSE,	OSAPI_SYSTEMSWITCHHIGH_PRIO,			SysSwitch_HighTaskEntry},
		{OSAPI_FASTCYCLIC, 		FALSE,	OSAPI_FASTCYCLIC_PRIO,			SysCycle_FastTaskEntry},
		{OSAPI_EVENTTASK, 		FALSE,	OSAPI_EVENTTASK_PRIO,		SysEvt_TaskEntry},			
		{OSAPI_SLOWCYCLIC, 		FALSE,	OSAPI_SLOWCYCLIC_PRIO,		SysCycle_SlowTaskEntry},
		{OSAPI_SLOWJOBTASK, 		FALSE,	OSAPI_SLOWJOBTASK_PRIO,	SysJob_TaskEntry},	
		{OSAPI_SYSTEMSWITCHLOW, 	FALSE,	OSAPI_SYSTEMSWITCHLOW_PRIO,		SysSwitch_LowTaskEntry},				
		{OSAPI_ULTRARADARFASTTASK, 		FALSE,	OSAPI_ULTRARADARFASTTASK_PRIO,		UltraRadarFastTaskEntry},	
		{OSAPI_ULTRARADARSLOWTASK, 	FALSE,	OSAPI_ULTRARADARSLOWTASK_PRIO,		UltraRadarSlowTaskEntry},
};

/*The table must follwo high priority task--> low priority task*/
#if (TASKMONITOR_EN ==1u)
const OSAPI_WdgCfgType OSCfg_astAllWdg[OSAPI_TASKNUM]=
{
  	{OSAPI_SYSTEMSWITCHHIGH, 	OSAPI_INTERNAL_WDG, 	(400U)*2.5,	TRUE, 	NULL },		
  	{OSAPI_FASTCYCLIC, 		OSAPI_INTERNAL_WDG, 	(400U)*2.5,	TRUE, 	NULL },
  	{OSAPI_EVENTTASK, 		OSAPI_INTERNAL_WDG, 	(8000U)*2.5,	TRUE, 	NULL },	
  	{OSAPI_SLOWCYCLIC, 		OSAPI_INTERNAL_WDG, 	(400U)*2.5,	TRUE, 	NULL },	  
  	{OSAPI_SLOWJOBTASK, 		OSAPI_INTERNAL_WDG, 	(800U)*2.5,	TRUE, 	NULL },	
  	{OSAPI_SYSTEMSWITCHLOW, 	OSAPI_INTERNAL_WDG, 	(200U)*2.5,	TRUE, 	NULL },
  	{OSAPI_ULTRARADARFASTTASK, 	OSAPI_INTERNAL_WDG, 	(1200U)*2.5,	TRUE, 	NULL },	
  	{OSAPI_ULTRARADARSLOWTASK, 	OSAPI_INTERNAL_WDG, 	(1200U)*2.5,	TRUE, 	NULL },	  	
};
#endif
/**************** END OF FILE *****************************************/
