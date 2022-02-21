/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				                   *
*				  All Rights Reserved.          					                          *
*   Department   	: CT AD     									   		     *
*   AUTHOR	    	: 									                                 *
************************************************************************
* Object            	:
* Module           	:
* Instance         	:
* Description      	:
*-----------------------------------------------------------------------
* Version			:
* Date			:
* Author			:
***********************************************************************/
/*-History---------------------------------------------------------------
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 
*======================================================*/
#ifndef _SLOTSEARCHING_PUB_H_
#define _SLOTSEARCHING_PUB_H_

#include "SlotParaCfg.h"

/*****************************************************************************
** Function:    SlotSearching_ParameterInit()
** Description: This function slot searching parameters, 
                it should be called at startup
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void SlotSearching_ParameterInit(void);

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
extern void SlotSearching_GetLeftSideSlotInfo(SlotSearchingResultDataType *slotSeachingResult, unsigned char slotIndex);

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
extern void SlotSearching_GetRightSideSlotInfo(SlotSearchingResultDataType *slotSeachingResult, unsigned char slotIndex);

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
extern APASlotOutlineCoordinateDataType SlotSearching_GetSlotOutlineInfo(unsigned char CurrentProcessSlotIndex);

/*Back ground Functions Start*/

/*****************************************************************************
** Function:    SlotSearchingMain_BG()
** Description: This function should be called by back ground task and 1ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
BOOLEAN SlotSearchingMain_BG(void);


/*****************************************************************************
** Function:    APADetermineStatusTask()
** Description: This function should be called by 10 ms cyclic task
** Parameter:   none
** Return:      none
**              
******************************************************************************/
void APADetermineStatusTask(void);


/*Back ground Functions End*/


#endif
