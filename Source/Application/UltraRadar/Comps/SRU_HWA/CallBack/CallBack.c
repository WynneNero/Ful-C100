#include <SRU_hwa_Adaptor.h>
#include <SRU_hwa_Controller.h>
#include "SlotParaCfg.h"
#include "ObjDetectCommonDefine.h"
#include "Powermanager.h"
#include "APSAPP.h"

extern void ApaTrjPlanningMain_BG(void);
extern unsigned char SlotSearchingMain_BG(void) ;
extern void ObjectProcessMainTask_Bg(void); 
extern unsigned char Apa_IsTrjPlanningStatusRequestCalc(void);
unsigned int iTauj1msCount;
//extern E_OPEN_SOC_POWER_STEP eOpenPowerStep;
extern APS_MODULE_STATUS APSModuleCurrentStatus;

unsigned int HWA_Get1msCount(void)
{
    return iTauj1msCount;
}

void HWA_Set1msCount(unsigned int count)
{
    iTauj1msCount = count;
}

#if 1
/*****************************************************************************
** Function:    APA_TaskBGLoop()
** Description: This function includes the object detect/Slotsearching/trajectory 
   functions, it should be called by the background task, and it should running 
   in a endless loopp
** Parameter:   none
** Return:      None
**              
******************************************************************************/
U8 APATaskActiveStatus = FALSE;
U8 UPATaskActiveStatus = FALSE;

void APA_TaskBGLoop(void)
{
    	OSAPI_LockSchedule();
	APATaskActiveStatus = TRUE;
	OSAPI_UnlockSchedule();
	
	SlotSearchingMain_BG();
	
	OSAPI_LockSchedule();
	APATaskActiveStatus = FALSE;
	OSAPI_UnlockSchedule();
	if(APSModuleCurrentStatus != APS_PARKING_SEARCH_PARKIN)
	{
		if(FALSE == UPATaskActiveStatus)
		{
			OSAPI_IsrActiveTask((U8)OSAPI_ULTRARADARFASTTASK);
		}
	}
}

/*****************************************************************************
** Function:    UPA_Tauj_Task()
** Description: This function runs the UPA task, should be called by the 1 ms 
   cyclic task
** Parameter:   none
** Return:      None
**              
******************************************************************************/
void UPA_Tauj_Task(void)
{
    	OSAPI_LockSchedule();
	UPATaskActiveStatus = TRUE;
	OSAPI_UnlockSchedule();
	
	ObjectProcessMainTask_Bg();
	
    	OSAPI_LockSchedule();
	UPATaskActiveStatus = FALSE;
	OSAPI_UnlockSchedule();
	if(APATaskActiveStatus == FALSE)
	{
		OSAPI_IsrActiveTask((U8)OSAPI_ULTRARADARSLOWTASK);
	}
}

#else

/*****************************************************************************
** Function:    APA_TaskBGLoop()
** Description: This function includes the object detect/Slotsearching/trajectory 
   functions, it should be called by the background task, and it should running 
   in a endless loopp
** Parameter:   none
** Return:      None
**              
******************************************************************************/
void APA_TaskBGLoop(void)
{
	unsigned int iLoop = 0;

    for(;;) 
	{

	
		do
		{
		    for(iLoop = 0; iLoop < 10; iLoop++)
            {
    			DisableInterrupts;
    			bObjDetectTaskStart = TRUE; 	
    			EnableInterrupts;
    			ObjectProcessMainTask_Bg();
    			DisableInterrupts;
    			bObjDetectTaskStart = FALSE;		
    			EnableInterrupts;
		    }

		}while(TRUE != bAPATrajectoryCalTaskActivated);
    
    	DisableInterrupts;
    	bAPATrajectoryCalTaskActivated = TRUE;
    	bApaTaskStart = TRUE; 	
    	EnableInterrupts;
    	//APA_TRAJECTORY_CAL_TASK_TEST_PIN_HIGH;
    			
    
    	SlotSearchingMain_BG();  // Parallel In: max 80ms, Perpendicular in: max 250ms.

    
    	DisableInterrupts;
    	if(APACarPar.TrajCalAPATrajectoryCalStatus != APATrajCalStatus_REQUESTCAL) 
		{
    		bAPATrajectoryCalTaskActivated = FALSE;
    	}
    	bApaTaskStart = FALSE;		
    	EnableInterrupts;



  
    }
}

void UPA_Tauj_Task(void)
{
	unsigned int iLoop = 0;

    if(FALSE == bObjDetectTaskStart)
    {
        for(iLoop = 0; iLoop < 10; iLoop++)
        {
        	DisableInterrupts;
        	bObjDetectTaskStart = TRUE; 	
        	EnableInterrupts;
        	ObjectProcessMainTask_Bg();
        	DisableInterrupts;
        	bObjDetectTaskStart = FALSE;		
        	EnableInterrupts;
        }
    }

	iTauj1msCount++;

}
#endif

				   
