/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   		   *
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
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 0.1    	2017/8/28   Zheng Xiaolei    Initial version
*=====================================================================*/
#ifndef APS_APP_H
#define APS_APP_H
#include "UssInfoMsg.h"


#define APS_ECU_HK_TIMEOUT		100	/* 500 ms */
#define APS_ECU_HK_INVALID_TIME     300		/* 6 s */
#define SAFETY_REASON_BITMASK 0x01

#define DEFAULT_PARK_IN  0x05
#define DEFAULT_PARK_OUT 0x06

#define DOOR_OPEN	0x1
#define DOOR_CLOSED	0x0
#define SEATBELT_OPEN 0x1
#define SEATBELT_CLOSED   0x0
#define EPB_RELEASE  0x0
#define EPB_CLOSED   0x1 
#define BrakePedal_NO_ACTIVE  0x0
#define BrakePedal_ACTIVE   0x1 

#define SLOTOFFSET 1000
#define ANGELOFFSET 900

/**************Car Paramer*****************/
#define  CAR_REAR_AXLE_TO_CENTER_UNIT_CM 138.6
#define OBSTACLEHEIGHTTHRESHOLDVALUE 30	//cm


/**** Definition of types ****/
typedef void (*APS_EventCallback_t)(void);

typedef enum
{
    APS_PARKING_INIT,  			//0	
	APS_PARKING_STANDBY,		//1
	APS_PARKING_SEARCH_PARKIN,	//2
	APS_PARKING_SEARCH_PARKOUT,	//3
	APS_PARKING_MAP_UPDATE,		//4
	APS_PARKING_ACTIVE_PARKIN,	//5
	APS_PARKING_ACTIVE_PARKOUT,	//6	
	APS_PARKING_AVMMODE,		//7
	APS_STATUS_MAX
}APS_MODULE_STATUS;

typedef enum
{
	VehicleStoped,
	VehicleForward,
	VehicleBackward
}APAVehicleDirection;

typedef struct {
	float x;
	float y;
	float theta;
} APA_VehiclePositionFloat;


typedef enum
{
	PASSelectedNone,
	PASSelectedLeft,
	PASSelectedRight
}PAS_SELECTED_SIDE;

typedef enum
{
	PASInitNoRequest,
	PASInitRequest
}PAS_COORDINATE_INIT_REQ;

typedef enum
{
	ParkingOutCueNone,
	ParkingOutCueDirecSelect,
	ParkingOutCueReleaseEPB,
	ParkingOutCueWaitStart
}ParkingOutCueType;

typedef enum
{
	SEARCH_DEFAULT,
	SEARCH_PARKOUT_DirecSelect,
	SEARCH_DOOR_OPEN,
	SEARCH_SEATBELT_OPEN,
	SEARCH_EPB_CLOSE,
	SEARCH_HK_LONG_PRESS,
	SEARCH_BRAKE_PEDAL_CLOSE,
	SEARCH_TRUNK_OPEN,
	SEARCH_HOOD_OPEN,
	SAFETY_MIRROR_OPEN,
	SAFETY_FACTOR_MAX
}CHECK_CAR_SAFETY_FACTOR_Type;

typedef enum
{
	AVM_SLOT_TYPE,
	ULTRA_SLOT_TYPE,
	AVM_ULTRA_FUSION_SLOT_TYPE,
	MANUAL_SLOT_TYPE,
	SLOT_TYPE_MAX
}ParkingPlace_Info_Type;

typedef enum
{
	NO_PARKING_PLACE_TYPE,
	AVM_PARKING_PLACE_TYPE,
	USS_PARKING_PLACE_TYPE,
	PARKING_OUT_TYPE,
}PLACE_TYPE;
	
typedef enum
{
	ParkingType_INACTIVE,
    ParkingType_PARALLEL, 
	ParkingType_PERPENDICULAR,
	ParkingType_OBLIQUE,
}PARKING_SLOT_TYPE;

typedef enum
{
    SearchMode_AUTO,
	SearchMode_MANUAL,
}SEARCHING_MODE;


typedef enum
{
	APA_AlgInit,
	APA_AlgActive,
	APA_AlgComplete, 
	APA_AlgFailure
}APA_AlgorithmStatus;

typedef enum
{
	DataValidFlag_INACTIVE,
	DataValidFlag_ACTIVE,	
}TOADV_DataValidFlag;

typedef enum
{
	ObstacleHeight_Unknown,
	ObstacleHeight_High,
	ObstacleHeight_Low,
}FreespaceObstacleHeightInfo;

typedef enum
{
	Slot_Predicted,		
	Slot_Target
}Slot_Type;

enum
{
	UPSIDE_UNKOWN_BOTTOM_UNKOWN,
	UPSIDE_UNKOWN_BOTTOM_EMPTY,
	UPSIDE_UNKOWN_BOTTOM_SOD,
	UPSIDE_EMPTY_BOTTOM_UNKOWN,
	UPSIDE_EMPTY_BOTTOM_EMPTY,
	UPSIDE_EMPTY_BOTTOM_SOD,	
	UPSIDE_SOD_BOTTOM_UNKOWN,
	UPSIDE_SOD_BOTTOM_EMPTY,
	UPSIDE_SOD_BOTTOM_SOD,
}DOWN_SLOT_SOD_PARKPLACE_INFO;

typedef enum
{
	LEFT_EMPTY_RIGHT_EMPTY,
	LEFT_SOD_OR_UNKOWN_RIGHT_EMPTY,
	LEFT_EMPTY_RIGHT_SOD_OR_UNKOWN,
	LEFT_SOD_RIGHT_SOD
}APS_Slot1_BothSidesInfo_Msg;

extern U8 ESC_APA_LC_State;
extern P_STK_USS_Slot_Search p_stk_uss_slot_search;

void APS_Init_Handler(void);
extern void APSProcessBarMessageSend(U8 DelayTime);
void APASlotRelocationMessageHandler(void);
U16 VehiclePositionSendToSocUnitExchange(float VehPosition);

APS_MODULE_STATUS GetAPSCurrentStatus(void);

BOOL APSModuleStsChangeToInitByAcc(void);


extern U8 get_EPB_SysSt(void);

#endif /*_APS_APP_H_*/
