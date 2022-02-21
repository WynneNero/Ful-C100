#ifndef _OBJDETECT_PUB_H_
#define _OBJDETECT_PUB_H_

/* Determine driver information output */

#include "DataTypeDef.h"


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
void ObjDetectCommonParaInit(void);

/*****************************************************************************
** Function:    ObjDetect_InfoOutParInit()
** Description: This function should be called by Initial function at startup
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjDetect_InfoOutParInit(void);



/*Init Functions End*/



/*Cyclic Functions Start*/

/*****************************************************************************
** Function:    ObjectDetect_DataProcess_Main_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjectDetectStateMachine_T10(void);

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
void ApaSwitch_Main_T10(void);



/*****************************************************************************
** Function:    ElmosStateMachine_T10()
** Description: This function should be called by 10ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ElmosStateMachine_T10(void);

/*Cyclic Functions End*/


/*Interrupt Service Functions Start*/

/*****************************************************************************
** Function:    ElmosCtl_TimerInterrupt()
** Description: This function should be called by Timer interrupt 
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ElmosCtl_TimerInterrupt(void);

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
void ElmosCtl_SensorInputInterrupt(unsigned char index);

/*Interrupt Service Functions End*/


/*Back ground Functions Start*/

/*****************************************************************************
** Function:    ObjectProcessMainTask_Bg()
** Description: This function should be called by back ground task and 1ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjectProcessMainTask_Bg(void);




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
uchar ObjDetect_GetNearestZone(unsigned char cSysType);


/*****************************************************************************
** Function:    ObjDetect_GetNearestZone()
** Description: This function provide Nearest distance  of all front regions or rear regions
** Parameter:   cSysType: 0 - Rear;  1 - Front
** Return:      Distance; unit£ºmm
**              
******************************************************************************/
uchar ObjDetect_GetNearestZone(unsigned char cSysType);


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
unsigned char ObjDetect_GetZoneByRegion(unsigned char cSysType, unsigned char region);

/*****************************************************************************
** Function:    ObjDetect_GetRlsNearestObjDis()
** Description: This function provide Nearest object distance of rear left side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRlsNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetRrsNearestObjDis()
** Description: This function provide Nearest object distance of rear right side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRrsNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFlsNearestObjDis()
** Description: This function provide Nearest object distance of front left side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFlsNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFrsNearestObjDis()
** Description: This function provide Nearest object distance of front right side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFrsNearestObjDis(void);


/*****************************************************************************
** Function:    ObjDetect_GetRlsNearestObjDis_AddCoefficient()
** Description: This function provide Nearest object distance with coefficient of rear left side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRlsNearestObjDis_AddCoefficient(void);


/*****************************************************************************
** Function:    ObjDetect_GetRrsNearestObjDis_AddCoefficient()
** Description: This function provide Nearest object distance with coefficient of rear right side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRrsNearestObjDis_AddCoefficient(void);


/*****************************************************************************
** Function:    ObjDetect_GetFlsNearestObjDis_AddCoefficient()
** Description: This function provide Nearest object distance with coefficient of front left side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFlsNearestObjDis_AddCoefficient(void);


/*****************************************************************************
** Function:    ObjDetect_GetFrsNearestObjDis_AddCoefficient()
** Description: This function provide Nearest object distance with coefficient of front right side sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFrsNearestObjDis_AddCoefficient(void);



/*****************************************************************************
** Function:    ObjDetect_GetRlNearestObjDis()
** Description: This function provide Nearest object distance of rear left corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRlNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetRrNearestObjDis()
** Description: This function provide Nearest object distance of rear right corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRrNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFlNearestObjDis()
** Description: This function provide Nearest object distance of front left corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFlNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFrNearestObjDis()
** Description: This function provide Nearest object distance of front right corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFrNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetRrmNearestObjDis()
** Description: This function provide Nearest object distance of rear right middle corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRrmNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetRlmNearestObjDis()
** Description: This function provide Nearest object distance of rear left middle corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRlmNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFrmNearestObjDis()
** Description: This function provide Nearest object distance of front right middle corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFrmNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFlmNearestObjDis()
** Description: This function provide Nearest object distance of front left middle corner sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFlmNearestObjDis(void);


/*****************************************************************************
** Function:    ObjDetect_GetRmidNearestObjDis()
** Description: This function provide Nearest object distance of Rear middle sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetRmidNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetFmidNearestObjDis()
** Description: This function provide Nearest object distance of front middle sensor
** Parameter:   none
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetFmidNearestObjDis(void);

/*****************************************************************************
** Function:    ObjDetect_GetApaSensorDetectedDistance()
** Description: This function provide APA sensor detected Distance
** Parameter:   typedef enum {
	                          OBJ_PROC_FRS_INDEX = 0,
	                          OBJ_PROC_FLS_INDEX,
	                          OBJ_PROC_RRS_INDEX,
	                          OBJ_PROC_RLS_INDEX
                             } ObjectProcApaSensorIndex;
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetApaSensorDetectedDistance(ObjectProcApaSensorIndex index);

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
 unsigned char ObjDetect_GetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index);

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
void ObjDetect_SetApaSensorDetectedDistanceStatus(ObjectProcApaSensorIndex index, unsigned char setValue);

/*****************************************************************************
** Function:    unsigned int ObjDetect_GetApaSensorDetectedDistanceDebugReplay(ObjectProcApaSensorIndex index)
** Description: This function provide APA sensor detected Distance, for slot search data replay
** Parameter:   
			OBJ_PROC_FRS_INDEX = 0,
			OBJ_PROC_FLS_INDEX = 1,
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetApaSensorDetectedDistanceDebugReplay(ObjectProcApaSensorIndex index);



/*****************************************************************************
** Function:    ObjDetect_GetNearestApaSensorDetectedDistance()
** Description: This function provide nearest APA sensor detected Distance
** Parameter:   cSysType: 0 - Rear;  1 - Front 
                cSnsIndex: 0 - Right side sensor; 1 - Left side sensor
** Return:      Distance unit: mm
**              
******************************************************************************/
unsigned int ObjDetect_GetNearestApaSensorDetectedDistance(unsigned char cSysType, unsigned char cSnsIndex);


/*****************************************************************************
** Function:    ObjDetect_ClearParkingSwitchPressedFlag()
** Description: This function clear the parking switch button pressed flag
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void ObjDetect_ClearParkingSwitchPressedFlag(void);

/*****************************************************************************
** Function:    ObjDetect_GetParkingSwitchPressedFlag()
** Description: This function get the parking switch button pressed flag
** Parameter:   bool: false - no pressed; true - pressed
** Return:      none
**              
******************************************************************************/
unsigned char ObjDetect_GetParkingSwitchPressedFlag(void);

/*****************************************************************************
** Function:    unsigned long long ObjDetect_GetObjdetectLibVersion(void)
** Description: get Objdetect Lib Version
** Parameter:   none
** Return:      version : Length 8 bytes
**              
** -History--------------------------------------------------------------
** Version  Date   	 Name        Changes and comments
** ----------------------------------------------------------------------
** 0.1	   03,13,2019   Hechunhong  Initial version
** =====================================================================
******************************************************************************/
unsigned long long ObjDetect_GetObjdetectLibVersion(void);

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
uchar SnsBkSig_GetSnsBkStatus(uchar cChannelIndex,uchar sysType,uchar *wSnsMask,word *wBkStatus );

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
BOOLEAN SnsBkSig_GetSnsBkStatusAnalysisFinish(uchar cChannelIndex);

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
void SnsBkSig_SnsFrameInfoClear(uchar cChannelIndex);

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
word SnsBkSig_GetFirstEchoTime(uchar cChannelIndex);

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
word SnsBkSig_GetFirstEchoTime(uchar cChannelIndex);


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
void SnsBkSig_DealSnsFrameDataT10(void);

/******************************************************************************
** Function:   void ObjDetectSetEnableSnsRegsReadCmdFlag(BOOLEAN bool)
** Description: 
** Parameter:              
** Return: 
**      
** History--------------------------------------------------------------
** Version       	Date    			Name    			Changes and comments
** ----------------------------------------------------------------------
** 0.1    		2019.03.03           Hechunhong          initversion
**=============================================================================
******************************************************************************/
void ObjDetectSetEnableSnsRegsReadCmdFlag(BOOLEAN bool);

/*****************************************************************************
** Function:   BOOLEAN ObjDetectGetEnableSnsRegsReadCmdFlag(void)
** Description: 
** Parameter:              
** Return: 
**      
** History--------------------------------------------------------------
** Version       	Date    			Name    			Changes and comments
** ----------------------------------------------------------------------
** 0.1    		2019.03.05           Hechunhong          init version
**=============================================================================
******************************************************************************/
BOOLEAN ObjDetectGetEnableSnsRegsReadCmdFlag(void);

/*****************************************************************************
** Function:  void ObjDetectReadSnsRegs(SnsRegsReadCmdType RegsReadCmd,BOOLEAN bChangeStatFlag)
** Description: 
** Parameter:   
** Return: 
**      
** History--------------------------------------------------------------
** Version       	Date    			Name    			Changes and comments
** ----------------------------------------------------------------------
** 0.1    		2019.03.03           Hechunhong          initversion
**=============================================================================
******************************************************************************/
void ObjDetectReadSnsRegs(SnsRegsReadCmdType RegsReadCmd,BOOLEAN bChangeStatFlag);

/*****************************************************************************
** Function: SnsRegsReadCmdType ObjDetectGetSnsRegsReadCmdType(void)
** Description: 
** Parameter:   
** Return: 
**      
** History--------------------------------------------------------------
** Version       	Date    			Name    			Changes and comments
** ----------------------------------------------------------------------
** 0.1    		2019.03.03           Hechunhong          initversion
**=============================================================================
******************************************************************************/
SnsRegsReadCmdType ObjDetectGetSnsRegsReadCmdType(void);

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
extern unsigned int getDisOfWarnZone(PASysType sysType, uchar region);


#endif		 
