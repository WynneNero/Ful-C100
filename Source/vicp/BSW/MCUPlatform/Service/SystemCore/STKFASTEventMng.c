/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									           *
*   AUTHOR	   : 									                   *
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
* Version          Date            Name            Changes and comments
* 0.1           2017-10-13         CDD                   Initialize
*=====================================================================*/
#include <Core_I.h>
#include <Service_HOOKS.h>
#include <Tools.h>
#include "STKFASTEVENTMNG.H"
#include "STKFASTEVENTMNG_CFGDEF.H"
#include "OSAPI.h"
#include "osek.h"

U8 GetRequestSTKFASTEvent(void);

#define STKFASTEVENT_PASS_2
#include "STKFASTEVENTMNG_DEF.H"

#define STKFASTEVENT_PASS_3
#include "STKFASTEVENTMNG_DEF.H"


//#define EVT_ACTIVE_TIMES   0x03

STATIC BOOL STKFASTEvt_abActive[STKFASTEVT_EVENT_MAX];//The last number for SWP TEST
STATIC BOOL STKFASTEvt_bEvtInited;


/***********************************************************************
*  Name        : STKFASTEvt_Init
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void STKFASTEvt_Init(void)
{

    U8 Index = 0u;
    STKFASTEvt_bEvtInited=TRUE;

    for(Index = 0u; Index < (U8)STKFASTEVT_EVENT_MAX; Index++)
    {
        STKFASTEvt_abActive[Index]= FALSE;
    }
}

/***********************************************************************
*  Name        : STKFASTEvt_Deinit
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void STKFASTEvt_Deinit(void)
{
    STKFASTEvt_bEvtInited=FALSE;

}
/***********************************************************************
*  Name        : STKFASTEvt_TaskEntry
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void STKFASTEvt_TaskEntry(void)
{	
    UPATask_Entry();
#if 0   
    for(;;)
    {
        U8 msgret=0u;
        U8 Evtid=STKFASTEVT_EVENT_MAX;
        Evtid = GetRequestSTKFASTEvent();

    #ifdef TRACE_ENABLE        
//        TraceOut_MsgWithNumbersWithOut0x("EIn ", &Evtid, 1);
	TraceOut_Msg("EI");
    #endif
	
        if(Evtid==STKFASTEVT_EVENT_MAX)
        {
            OSAPI_WaitingTask(OSAPI_STKFASTEVENTTASK,OSADP_WAIT_NOTIMEOUT,&msgret);

            if(msgret==OSAPI_TERMINATETASK)
            {
                break;
            }
            else
            {
                //do nothing
            }
        }
        else
        {
            if(STKFASTEvt_bEvtInited==TRUE)
            {
#if( SERVICE_HOOKS_EN==1u)
                SERVICE_EVENT_HOOK(Evtid);
#endif

#if (TASKMONITOR_EN ==1u)
                OSWDG_StartMonitor(OSAPI_STKFASTEVENTTASK);
#endif
                if(STKFASTEvt_apEventProc[Evtid]!=NULL)
                {  
                    //Lib_RunContainer((Func_Void_Proc *)&(STKFASTEvt_apEventProc[Evtid][0]));
                    STKFASTEvt_apEventProc[Evtid]();
                }
#if (TASKMONITOR_EN ==1u)
                OSWDG_StopMonitor(OSAPI_STKFASTEVENTTASK);
#endif
            }
            else
            {
                //do nothing
            }
	 	#ifdef TRACE_ENABLE        
//		 TraceOut_MsgWithNumbersWithOut0x("EOut ", &Evtid, 1);
		TraceOut_Msg("EO");
        #endif			
        }
    }
#endif
}
/***********************************************************************
*  Name        : STKFASTEvt_IsrSetEvent
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void STKFASTEvt_IsrSetEvent(U8 Evtid)
{
    if(Evtid<(U8)STKFASTEVT_EVENT_MAX)
    {
        STKFASTEvt_abActive[Evtid]=TRUE;
    }

    OSAPI_IsrActiveTask(OSAPI_STKFASTEVENTTASK);
}

/***********************************************************************
*  Name        : SysEvt_SetEvent
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void STKFASTEvt_SetEvent(U8 Evtid)
{
    OSAPI_LockSchedule();
    if(Evtid<STKFASTEVT_EVENT_MAX)
    {
        STKFASTEvt_abActive[Evtid]=TRUE;
    }
    else
    {
        //  TODO: Add error log
    }
    OSAPI_UnlockSchedule();
    OSAPI_ActiveTask(OSAPI_STKFASTEVENTTASK);
}


/***********************************************************************
*  Name        : GetRequestSTKFASTEvent
*  Description : None
*  Parameter   : None
*  Returns     : None
***********************************************************************/
U8 GetRequestSTKFASTEvent(void)
{
    U8 i=0u;
    U8 Evtid =STKFASTEVT_EVENT_MAX;

    OSAPI_LockSchedule();
    for(i=0u; i<STKFASTEVT_EVENT_MAX; i++)
    {
        if(STKFASTEvt_abActive[i]==TRUE)
        {
            Evtid=i;
            STKFASTEvt_abActive[i]=FALSE;
            break;
        }
    }
    OSAPI_UnlockSchedule();

    return Evtid;
}

/*****************************************************************************
******************the below os api for STK use*******************************
******************************************************************************/

/***********************************************************************
* FUNCTION    : SetEvent
* DESCRIPTION : This function will calls osSetEvent 
* INPUTS      : U8 taskIndex, U8 EventMaskType
* RETURN      : void
***********************************************************************/
void setEvent(U8 taskIndex, U8 EventMaskType)
{
    osSetEvent(taskIndex, EventMaskType);
}

/***********************************************************************
* FUNCTION    : ClearEvent
* DESCRIPTION : This function will calls osClearEvent
* INPUTS      : U8 EventMaskType
* RETURN      : void
***********************************************************************/
void clearEvent(U8 EventMaskType)
{
    osClearEvent(EventMaskType);
}

/***********************************************************************
* FUNCTION    : WaitEvent
* DESCRIPTION : This function will calls osWaitEvent
* INPUTS      : U8 EventMaskType
* RETURN      : void
***********************************************************************/
void waitEvent(U8 EventMaskType)
{
    osWaitEvent(EventMaskType);

}

/***********************************************************************
* FUNCTION    : osActivateTask
* DESCRIPTION : This function will calls osActivateTask
* INPUTS      : U8 taskIndex
* RETURN      : void
***********************************************************************/
void activateTask(U8 taskIndex)
{
    osActivateTask(taskIndex);

}


void osek_TaskTerminate(void)
{
	TerminateTask();
}

/**************** END OF FILE *****************************************/






































