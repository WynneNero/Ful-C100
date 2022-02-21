/* Determine driver information output */

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"

/*Enum Define Start*/
typedef enum 
{
	OBJ_PROC_FRS_INDEX = 0,
	OBJ_PROC_FLS_INDEX,
	OBJ_PROC_RRS_INDEX,
	OBJ_PROC_RLS_INDEX
} ObjectProcApaSensorIndex;
/*Enum Define End*/


/*Init Functions Start*/
/*****************************************************************************
** Function:    ObjDetectCommonParaInit()
** Description: This function should be called by Initial function at startup
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjDetectCommonParaInit(void)
{
	
}


/*****************************************************************************
** Function:    ObjectDetect_DataProcess_Main_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjectDetectStateMachine_T10(void)
{
	
}

/*****************************************************************************
** Function:    ObjectDetect_DataProcess_Main_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjectDetect_DataProcess_Main_T10(void);


/*****************************************************************************
** Function:    ApaSwitch_Main_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ApaSwitch_Main_T10(void)
{
}



/*****************************************************************************
** Function:    ElmosStateMachine_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ElmosStateMachine_T10(void)
{
}

/*Cyclic Functions End*/


/*Interrupt Service Functions Start*/

/*****************************************************************************
** Function:    ElmosCtl_TimerInterrupt()
** Description: This function should be called by Timer interrupt 
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ElmosCtl_TimerInterrupt(void)
{
}

/*****************************************************************************
** Function:    ElmosCtl_SensorInputInterrupt()
** Description: This function should be called by untrasonic echo interrupt 
** Parameter:   index:typedef enum {
                                    	RRS = 0,
                                    	RR,
                                    	RRM,
                                    	RLM,
                                    	RL,
                                    	RLS,
                                    	FRS,
                                    	FR,
                                    	FRM,
                                    	FLM,
                                    	FL,
                                    	FLS
                                    } PortSensorType;
** Return:      none
**              
******************************************************************************/
void ElmosCtl_SensorInputInterrupt(unsigned char index)
{
}

/*Interrupt Service Functions End*/


/*Back ground Functions Start*/

/*****************************************************************************
** Function:    ObjectProcessMainTask_Bg()
** Description: This function should be called by back ground task and 1ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjectProcessMainTask_Bg(void)
{
}




/*Back ground Functions End*/


/*****************************************************************************
** Function:    ObjDetect_GetNearestZone()
** Description: This function provide Nearest zone value of all front regions or rear regions
** Parameter:   cSysType: 0 - Rear;  1 - Front
** Return:      Zone value: 0 - No object
                            1 - zone 1, nearest zone
                            2 - zone 2
                            3 - zone 3
                            4 - zone 4, Farest zone
**              
******************************************************************************/
uchar ObjDetect_GetNearestZone(unsigned char cSysType)
{
}


/*****************************************************************************
** Function:    ObjDetect_GetZoneByRegion()
** Description: This function provide zone value of a region
** Parameter:   cSysType: 0 - Rear;  1 - Front 
                region: 0 - right; 1 - middle; 2 - left

** Return:      Zone value: 0 - No object
                            1 - zone 1, nearest zone
                            2 - zone 2
                            3 - zone 3
                            4 - zone 4, Farest zone
**              
******************************************************************************/
unsigned char ObjDetect_GetZoneByRegion(unsigned char cSysType, unsigned char region)
{
}


/*****************************************************************************
** Function:    ObjDetect_GetApaSensorDetectedDistanceStatus()
** Description: This function provide APA sensor detected Distance Status
** Parameter:   typedef enum {
	                          OBJ_PROC_FRS_INDEX = 0,
	                          OBJ_PROC_FLS_INDEX,
	                          OBJ_PROC_RRS_INDEX,
	                          OBJ_PROC_RLS_INDEX
                             } ObjectProcApaSensorIndex;
** Return:      APA Sensor Detect Status
**              
******************************************************************************/
 unsigned char ObjDetect_GetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index)
 {
 }

/*****************************************************************************
** Function:    ObjDetect_SetApaSensorDetectedDistanceStatus()
** Description: This function set APA sensor detected Distance Status
** Parameter:   typedef enum {
	                          OBJ_PROC_FRS_INDEX = 0,
	                          OBJ_PROC_FLS_INDEX,
	                          OBJ_PROC_RRS_INDEX,
	                          OBJ_PROC_RLS_INDEX
                             } ObjectProcApaSensorIndex;
** Return:      none
**              
******************************************************************************/
void ObjDetect_SetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index, unsigned char setValue)
{
}

/*****************************************************************************
** Function:    unsigned int ObjDetect_GetApaSensorDetectedDistanceDebugReplay(ObjectProcApaSensorIndex index)
** Description: This function provide APA sensor detected Distance, for slot search data replay
** Parameter:   
			OBJ_PROC_FRS_INDEX = 0,
			OBJ_PROC_FLS_INDEX = 1,
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetApaSensorDetectedDistanceDebugReplay(ObjectProcApaSensorIndex index)
{
}



/*****************************************************************************
** Function:    ObjDetect_ClearParkingSwitchPressedFlag()
** Description: This function clear the parking switch button pressed flag
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjDetect_ClearParkingSwitchPressedFlag(void)
{
}

/*****************************************************************************
** Function:    ObjDetect_GetParkingSwitchPressedFlag()
** Description: This function get the parking switch button pressed flag
** Parameter:   bool: false - no pressed; true - pressed
** Return:      none
**              
******************************************************************************/
unsigned char ObjDetect_GetParkingSwitchPressedFlag(void)
{
}

/******************************************************************************
** Function:    uchar SnsBkSig_GetSnsBkStatus(uchar cChannelIndex,uchar wSnsMask,word wBkStatus )
** Description:  
** Parameter:   
** Return:
**   *wSnsMask:Sns Scheduling logic
** 	 *wBkStatus:status bits after sns objdetect  cmd
** History--------------------------------------------------------------
** Version      Date         Name           Changes and comments
** ----------------------------------------------------------------------
**  0.1         2019.04.01   Hechunhong     Init version.
** ----------------------------------------------------------------------
**  0.2         2019.04.15   Hechunhong     modify interfaces
** ----------------------------------------------------------------------
******************************************************************************/
uchar SnsBkSig_GetSnsBkStatus(uchar cChannelIndex,uchar sysType,uchar *wSnsMask,word *wBkStatus )
{
}

/******************************************************************************
** Function:   BOOLEAN SnsBkSig_GetSnsBkStatusAnalysisFinish(uchar cChannelIndex)
** Description:  when status bits has been analysised,
**				 then another cycle status bits  could be recorded
** Parameter:   
** Return:      
** 	  BOOLEAN wSnsBkStatusAnalysisFinish: 
** History--------------------------------------------------------------
** Version      Date         Name           Changes and comments
** ----------------------------------------------------------------------
**  0.1         2019.04.01   Hechunhong     Init version.
** ----------------------------------------------------------------------
******************************************************************************/
BOOLEAN SnsBkSig_GetSnsBkStatusAnalysisFinish(uchar cChannelIndex)
{
}

/******************************************************************************
** Function:    void SnsBkSig_SnsFrameInfoClear(uchar cChannelIndex)
** Description:  clear variable or flags after status info has been used by application
** Parameter:   
** Return:      
** History--------------------------------------------------------------
** Version      Date         Name           Changes and comments
** ----------------------------------------------------------------------
**  0.1         2019.04.01   Hechunhong     Init version.
** ----------------------------------------------------------------------
******************************************************************************/
void SnsBkSig_SnsFrameInfoClear(uchar cChannelIndex)
{
}

/******************************************************************************
** Function:  word SnsBkSig_GetFirstEchoTime(uchar cChannelIndex)
** Description:  get sns first echo time 
** Parameter:   
** Return:      
**	 wSnsBkFirstEchoTime
** History--------------------------------------------------------------
** Version      Date         Name           Changes and comments
** ----------------------------------------------------------------------
**  0.1         2019.04.17   Hechunhong     Init version.
** ----------------------------------------------------------------------
******************************************************************************/
word SnsBkSig_GetFirstEchoTime(uchar cChannelIndex)
{
}



/******************************************************************************
** Function:  void SnsBkSig_DealSnsFrameDataT10(void)
** Description:  analysis status bits in a cycle time 
** Parameter:   
** Return:      
**	 wSnsBkStatusAnalysisFinish[]: status bits data has been analysised finish
** History--------------------------------------------------------------
** Version      Date         Name           Changes and comments
** ----------------------------------------------------------------------
**  0.1         2019.04.01   Hechunhong     Init version.
** ----------------------------------------------------------------------
******************************************************************************/
void SnsBkSig_DealSnsFrameDataT10(void)
{
}

/*****************************************************************************
** Function name: getDisOfWarnZone
** Description: 
** Parameter:   
** Return: 
**      
** History--------------------------------------------------------------
** Version       	Date    			Name    			Changes and comments
** ----------------------------------------------------------------------
** 0.1    		2019.07.04           LiaoGanfang                    initversion
**=============================================================================
******************************************************************************/
extern unsigned int getDisOfWarnZone(PASysType sysType, uchar region)
{
}

unsigned char GetUssObjectDetectLibVer(char *soft_ver)
{

}

extern unsigned int getTriangleDisOf_Fmid(void)
{

}
extern unsigned int getTriangleDisOf_Rmid (void)
{

}



