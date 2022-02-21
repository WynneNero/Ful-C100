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
#ifndef _APACALCULATECARPOS_H_
#define _APACALCULATECARPOS_H_     

#include "SlotParaCfg.h"

typedef enum {
	APACalCarPosEquipBiDirectionWhlSpdSnsChk_None = 0,
	APACalCarPosEquipBiDirectionWhlSpdSnsChk_NonDriven,
	APACalCarPosEquipBiDirectionWhlSpdSnsChk_Driven,
	APACalCarPosEquipBiDirectionWhlSpdSnsChk_Both
}APACalCarPosEquipBiDirectionWhlSpdSnsChk;

typedef enum{
	APACalCarPosDrivenWheelCheck_FrontDriven = 0,
	APACalCarPosDrivenWheelCheck_RearOrAllDriven
}APACalCarPosDrivenWheelCheck;

typedef enum{
	APACalCarPosAxisDriveDirection_RemainLastDirState = 0,
	APACalCarPosAxisDriveDirection_Disable,
	APACalCarPosAxisDriveDirection_RigthtAndLeftConflict,
	APACalCarPosAxisDriveDirection_Forward,
	APACalCarPosAxisDriveDirection_Reverse
}APACalCarPosAxisDriveDirection;


void APAResetCarPosition(void);

void APACalculateCarPosTask_T10(void);

APA_ANGLE_CAL_FLOAT_TYPE APACalcualteCarAngleDeltaValue(
	APA_DISTANCE_TYPE LenBetweenFRAxis,
	APA_ANGLE_CAL_FLOAT_TYPE CurrentCarSpeed, 
	APA_ANGLE_CAL_FLOAT_TYPE CurrentSteeringWheelAngleTangentValue);

void APACalCarRunDisByTireRotatCnt(void);

BOOLEAN APACarCarPosDependOnGearInfo(void);
BOOLEAN APACarCarPosCheckVehicleDirection(void);
void APACalCarPosCoordinate(void);
APALineIsVerticalOrHorizontalType SlotSearching_VehicleDrivingDirection(
APA_ANGLE_TYPE CarAng);

#endif

