#include "config.h"
#include "SlotParaCfg.h"
#include "InteractiveInterfaceDefine.h"
#include "ussLibIf.h"
#include "ussLibAdapt.h"
#include "UssInfoMsg.h"

extern STK_USS_Slot_Search stk_uss_slot_search;



/*****************************************************************************
** Function:    SlotSearching_ParameterInit()
** Description: This function slot searching parameters, 
                it should be called at startup
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void SlotSearching_ParameterInit(void)
{
}

/*****************************************************************************
** Function:    SlotSearching_GetLeftSideSlotInfo()
** Description: This function provide left side slot infor
** Parameter:   slotIndex: slot index, 0,1,2
** Return:         typedef struct  
                   {
                   	APA_ENUM_TYPE SlotType;
                   	APA_DISTANCE_TYPE SlotDepth;
                   	APA_DISTANCE_TYPE SlotLength;
                   	BOOLEAN bSlotCalConfirmed;
                   	APACarCoordinateDataCalFloatType CurrentVehicleCoordinate;
                   	APACoordinateDataCalFloatType Point_B_Coordinate;
                   	APACoordinateDataCalFloatType Point_C_Coordinate;
                   
                   } SlotSearchingResultDataType;
**              
******************************************************************************/
void SlotSearching_GetLeftSideSlotInfo(SlotSearchingResultDataType *slotSeachingResult, unsigned char slotIndex)
{
}

/*****************************************************************************
** Function:    SlotSearching_GetRightSideSlotInfo()
** Description: This function provide right side slot infor
** Parameter:   slotIndex: slot index, 0,1,2
** Return:      
                   typedef struct  
                   {
                   	APA_ENUM_TYPE SlotType;
                   	APA_DISTANCE_TYPE SlotDepth;
                   	APA_DISTANCE_TYPE SlotLength;
                   	BOOLEAN bSlotCalConfirmed;
                   	APACarCoordinateDataCalFloatType CurrentVehicleCoordinate;
                   	APACoordinateDataCalFloatType Point_B_Coordinate;
                   	APACoordinateDataCalFloatType Point_C_Coordinate;
                   
                   } SlotSearchingResultDataType;
**              
******************************************************************************/
void SlotSearching_GetRightSideSlotInfo(SlotSearchingResultDataType *slotSeachingResult, unsigned char slotIndex)
{
}

/*****************************************************************************
** Function:    SlotSearching_GetSlotOutlineInfo()
** Description: This function provide slot Outline information
** Parameter:   CurrentProcessSlotIndex: 0,1
** Return:      
	typedef struct {
		APACoordinateDataType CarCenterPoint[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
		APA_DISTANCE_TYPE DisFromCarToObj[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM]; 
		APACoordinateDataType ObjPt[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
		APA_ANGLE_TYPE CarAng[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
		APA_ENUM_TYPE ObjType[APA_SLOT_SUPPORT_MAX_SAMPLE_POINT_NUM];
		UCHAR WrIndex;
		APA_ENUM_TYPE ObjPtCnt;   
	} APASlotOutlineCoordinateDataType;        
**              
******************************************************************************/
extern APASlotOutlineCoordinateDataType SlotSearching_GetSlotOutlineInfo(unsigned char CurrentProcessSlotIndex)
{
}

/*Back ground Functions Start*/

/*****************************************************************************
** Function:    SlotSearchingMain_BG()
** Description: This function should be called by back ground task and 1ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
BOOLEAN SlotSearchingMain_BG(void)
{
}


/*****************************************************************************
** Function:    APADetermineStatusTask()
** Description: This function should be called by 10 ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void APADetermineStatusTask(void)
{
}

/**** Declaration of variables ****/
extern char VersionNum[USS_ALG_SOFT_VERSION_LEN];

/**** Declaration of functions ****/
/***********************************************************************
*  Name        : ApaStatMachine_GetApaState
*  Description : This funtion returns to the State of SlotSearching function
*  Parameter   :
*  Returns     : 0x0 SlotDect_STATE_OFF  = 0,
				 0x1 SlotDect_STATE_STANDBY_ENABLE,
	    		 0x2 SlotDect_STATE_ENABLE,
***********************************************************************/
extern signed char ApaStatMachine_GetApaState(void)
{
}



FV_SlotInformationType	SV_Get_slot[2];
extern FV_SlotInformationType FV_slot_raw[2][2];


/***********************************************************************
*  Name        : USSParkingSlotSearching(unsigned char)
*  Description : This function support switch the SlotSearching Mode by parameter
*  Parameter   :
				0x00��Searching Left Slot Mode
		  		0x01��Searching Right Slot Mode
		  		0x02��Searching Double Side Mode
		  		0x03: Searching None
*  Returns     : None
***********************************************************************/
unsigned char USSParkingSlotSearching(unsigned char data)
{
	USSParkingSlotSearch ParkingSlotSearch;	
	
	switch(data)
		{
		case SearchingLeftSlotMode:
			ParkingSlotSearch = LeftSearch_enm;
			break;
		case SearchingRightSlotMode:
			ParkingSlotSearch = RightSearch_enm;
			break;
		case SearchingDoubleSideMode:
			ParkingSlotSearch = LeftRightSearch_enm;			
			break;
		case Searching_OFF:
			ParkingSlotSearch = NOSearch_enm;
			break;
		default:
			break;		
		}
    
	g_FV_adiSetUSSParkingSlotSearching_bl(ParkingSlotSearch);
	
    _memset(SV_Get_slot,0,2*sizeof(FV_SlotInformationType));
    stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x = SV_Get_slot[0].SlotLocationAx;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y = SV_Get_slot[0].SlotLocationAy;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x = SV_Get_slot[0].SlotLocationBx;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y = SV_Get_slot[0].SlotLocationBy;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x = SV_Get_slot[0].SlotLocationCx;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y = SV_Get_slot[0].SlotLocationCy;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x = SV_Get_slot[0].SlotLocationDx;     
    stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y = SV_Get_slot[0].SlotLocationDy;
    stk_uss_slot_search.ParkingSlotInfo_L.SlotDepth = SV_Get_slot[0].SlotDepth;
    
    stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x = SV_Get_slot[1].SlotLocationAx;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y = SV_Get_slot[1].SlotLocationAy;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x = SV_Get_slot[1].SlotLocationBx;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y = SV_Get_slot[1].SlotLocationBy;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x = SV_Get_slot[1].SlotLocationCx;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y = SV_Get_slot[1].SlotLocationCy;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x = SV_Get_slot[1].SlotLocationDx;     
    stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y = SV_Get_slot[1].SlotLocationDy;
    stk_uss_slot_search.ParkingSlotInfo_R.SlotDepth = SV_Get_slot[1].SlotDepth;

	if(0 != fill_AD_point(ParkingSlotSearch, &SV_Get_slot))
	{		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.x = SV_Get_slot[0].SlotLocationAx;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_A_Coordinate.y = SV_Get_slot[0].SlotLocationAy;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.x = SV_Get_slot[0].SlotLocationBx;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_B_Coordinate.y = SV_Get_slot[0].SlotLocationBy;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.x = SV_Get_slot[0].SlotLocationCx;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_C_Coordinate.y = SV_Get_slot[0].SlotLocationCy;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.x = SV_Get_slot[0].SlotLocationDx;		
		stk_uss_slot_search.ParkingSlotInfo_L.Point_D_Coordinate.y = SV_Get_slot[0].SlotLocationDy;
		stk_uss_slot_search.ParkingSlotInfo_L.SlotDepth = SV_Get_slot[0].SlotDepth;

		stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.x = SV_Get_slot[1].SlotLocationAx;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_A_Coordinate.y = SV_Get_slot[1].SlotLocationAy;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.x = SV_Get_slot[1].SlotLocationBx;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_B_Coordinate.y = SV_Get_slot[1].SlotLocationBy;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.x = SV_Get_slot[1].SlotLocationCx;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_C_Coordinate.y = SV_Get_slot[1].SlotLocationCy;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.x = SV_Get_slot[1].SlotLocationDx;		
		stk_uss_slot_search.ParkingSlotInfo_R.Point_D_Coordinate.y = SV_Get_slot[1].SlotLocationDy;
		stk_uss_slot_search.ParkingSlotInfo_R.SlotDepth = SV_Get_slot[1].SlotDepth;

	}	

}

/***********************************************************************
*  Name        : USSParkingSlotSearching(unsigned char)
*  Description : This function genrate the Number of SlotSearching lib version
*  Parameter   :
*  Returns     : None
***********************************************************************/
extern unsigned char GetUssSlotSearchingLibVer(char *soft_ver)
{
}
extern void ApaStateMachine_Init(void)
{

}

/*Back ground Functions End*/
