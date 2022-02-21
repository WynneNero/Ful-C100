/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : IDA R&D SW1      									   *
*   AUTHOR	   :            										   *
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
* Version       Date                Name            Changes and comments
* 2.0           2017/9/26      LinFeng&Liao Lifen    
*----------------------------------------------------------------------
* 2.1           2017/11/7      LinFeng
*----------------------------------------------------------------------
* 2.2           2017/11/8      LinFeng
*----------------------------------------------------------------------
* 2.3           2017/11/9      LinFeng
*=====================================================================*/
#ifndef  _USSINFOMSG_H_
#define  _USSINFOMSG_H_

#include "Define.h"
#include "ussLibIf.h"
#include "M4MsgHandler_IF.h"
#include "eol_app.h"
#include "SlotParaCfg.h"


#define SW_VERSION_USS_LEN  21


#define USS_GET_INFO_OK    0
#define USS_GET_INFO_FAIL  1

#define T1C_REAR_SHORT_SENSOR_ERR 0x3F
#define T1C_FRONT_SHORT_SENSOR_ERR 0x1F
#define T1C_LONG_SENSOR_ERR 0x7F

#define PDC_ON  0x01
#define PDC_OFF 0x00

#define USS_SEARCH_OVER_SPEED 400	//400*0.0625=25 km/h	

#define SATISFIED 0x00
#define UNSATISFIED 0X01

#define USS_DIAGREASON_BIT_MASK 0x0001
#define USS_NORMAL_BIT_MASK 0x0000

#define USS_POWER_ON 0x01
#define USS_POWER_OFF 0x00

#define USS_NO_FAILURE 0x00
#define USS_F_FAILURE 0x01
#define USS_R_FAILURE 0x02
#define USS_FR_FAILURE 0x03

enum TCM_TurnLight
{
	Turn_Default,
	Turn_Left,
	Turn_Right,
	Turn_Invalid,
	Turn_Init,
};

enum USS_SearchingSide
{
	Searching_Left,
	Searching_Right,
	Searching_Both_Side,
	Searching_Close,
};
	
typedef enum
{
	None_Slot,
	USS_Vertical_Slot,
	USS_Parallel_Slot,
	The_Other_Slot,
}USS_SlotType;

typedef enum 
{
	KEY_ACC_OFF = 0x00,
//	KEY_ACC,
	KEY_ACC_ON = 0x4,
//	KEY_ACC_CRANK,
}VehiclePowerStatus;

typedef enum 
{
	PDC_OFF_STATE,
	PDC_STANDBY_STATUS,
	PDC_STANDBY_AND_FRONT_FAILURE,
	PDC_STANDBY_AND_REAR_FAILURE,
	PDC_FRONT_ACTIVE,
	PDC_FRONT_ACTIVE_AND_REAR_FAILURE,
	PDC_REAR_ACTIVE,
	PDC_REAR_ACTIVE_AND_FRONT_FAILURE,
	PDC_FRONT_REAR_ACTIVE,
	PDC_SYSTEM_FAILURE,
	PDC_FRONT_FAILURE_AND_REAR_INACTIVE,
	PDC_REAR_FAILURE_AND_FRONT_INACTIVE,
}VehiclePdcWorkingState;

typedef enum 
{
	PAS_Work_OFF_STATE,
	PAS_Work_STANDBY_STATUS,
	PAS_Work_On_STATE,
}PAS_Work_Status;

typedef enum 
{
	Not_active_tone,
    Continuous_tone,
    Fast_intermittent_tone,
    Medium_speed_internittent_tone,
    Slow_intermittent_tone,
    Mute_tone,
}PAS_Warning_Tone;

#if 0

typedef enum
{
	GEAR_INIT,
	GEAR_P,
	GEAR_R,
	GEAR_N,
	GEAR_D,
}ActualGear_T1C;

typedef enum
{
	PDC_HardKey_Invalid,
	PDC_HardKey_valid,
}PDC_HardKey_Status;

typedef enum
{
	SVA_HardKey_Invalid,
	SVA_HardKey_valid,
}SVA_HardKey_Status;

typedef enum
{
	PDC_KeyLamp_Disable,
	PDC_KeyLamp_Enable,
}PDC_KeyLamp_Status;

typedef enum
{
	PDC_KeyLamp_TurnOff,
	PDC_KeyLamp_TurnOn,
}PDC_KeyLamp_Switch;

typedef enum
{
	SVA_KeyLamp_Disable,
	SVA_KeyLamp_Enable,
}SVA_KeyLamp_Status;


typedef enum
{
	SVA_KeyLampLeft_TurnOff,
	SVA_KeyLampLeft_TurnOn,
}SVA_KeyLampLeft_Switch;

typedef enum
{
	SVA_KeyLampRight_TurnOff,
	SVA_KeyLampRight_TurnOn,
}SVA_KeyLampRight_Switch;

typedef enum
{
	NotClearData,
	ToClearData,
}DATACLEAR;

typedef enum 
{
	DIRECTION_INIT,
	DIRECTION_FORWARD,
	DIRECTION_BACKWARD,
	DIRECTION_STOP,
}WHEEL_DIRECTION;
#endif

enum USS_Searching_Type
{
	Other_Searing_Type,
	ParkInAutoSlot,
};


enum ParkingType_InSearch
{
	REQUEST_PARK_IN = 0x01,
	REQUEST_PARK_OUT,
};
	

enum SlotType_InSearch
{
	AUTO_SLOT = 0x01,
	MANUAL_SLOT,
};

enum PDC_SensorErrorStatus
{
    SENSOR_NOERROR,
    SENSOR_ERROR,
    SENSOR_BOLCKAGE,
};

#if 0

enum EOL_Distance_Check
{
	EOL_Switch_Off,
	EOL_Switch_On,	
};

#endif

typedef struct
{	
	unsigned int USS_Distance_RRS;	
	unsigned int USS_Distance_RR; 
	unsigned int USS_Distance_RRM;
	unsigned int USS_Distance_RLM;
	unsigned int USS_Distance_RL; 
	unsigned int USS_Distance_RLS;	
	unsigned int USS_Distance_FRS;
	unsigned int USS_Distance_FR; 
	unsigned int USS_Distance_FRM;
	unsigned int USS_Distance_FLM;
	unsigned int USS_Distance_FL; 
	unsigned int USS_Distance_FLS;
	unsigned int USS_Distance_RR_Self_Rx_Tx;
	unsigned int USS_Distance_RL_Self_Rx_Tx;
	unsigned int USS_Distance_FR_Self_Rx_Tx;
	unsigned int USS_Distance_FL_Self_Rx_Tx;
	unsigned int USS_Distance_Front_Triangle;
	unsigned int USS_Distance_Rear_Triangle;
}USSDistanceResultStruct;
#if 0
typedef struct
{	
	unsigned char USS_Failure_RRS;	
	unsigned char USS_Failure_RR;	
	unsigned char USS_Failure_RRM;	
	unsigned char USS_Failure_RLM;	
	unsigned char USS_Failure_RL;	
	unsigned char USS_Failure_RLS;	
	unsigned char USS_Failure_FRS;	
	unsigned char USS_Failure_FR;	
	unsigned char USS_Failure_FRM;	
	unsigned char USS_Failure_FLM;	
	unsigned char USS_Failure_FL;	
	unsigned char USS_Failure_FLS;
}USSFailureStatusStruct;
#endif

typedef enum
{
	SHORT_TO_BATTERY,
	SHORT_TO_GND,
	BE_BLOCK,
	RING_TIME_TOO_SHORT,
	RING_TIME_TOO_LONG,
	SIGNAL_DISTURBED,
	SIGNAL_ERROR,
	INIT_FAIL,
	DISCONNECTED,
	MISMATCH,
}USS_Detail_Failure_Information;
	
typedef struct
{	
	unsigned char SlotValid;//0:Invalid, 1:Valid	
	float SlotDepth;  //Unit:mm.	
	float SlotLocationAx;  //Unit:mm.	
	float SlotLocationAy;  //Unit:mm.	
	float SlotLocationBx;  //Unit:mm.	
	float SlotLocationBy;  //Unit:mm.	
	float SlotLocationCx;  //Unit:mm.	
	float SlotLocationCy;  //Unit:mm.	
	float SlotLocationDx;  //Unit:mm.	
	float SlotLocationDy;  //Unit:mm.
}SlotInformationType;

typedef struct
{
	U8 USS_Searching_Side;
	U8 CurrentGear;
	U8 APS_Searching_Type;
    
	U16 USS_AX_L;
	U16 USS_AY_L;
	U16 USS_BX_L;
	U16 USS_BY_L;
    
	U16 USS_CX_L;
	U16 USS_CY_L;
	U16 USS_DX_L;
	U16 USS_DY_L;
    U16 USS_SLOT_DEPTH_L; 
    
    U16 USS_AX_R;
    U16 USS_AY_R;
    U16 USS_BX_R;
    U16 USS_BY_R;
    
    U16 USS_CX_R;
    U16 USS_CY_R;
    U16 USS_DX_R;
    U16 USS_DY_R;
	U16 USS_SLOT_DEPTH_R;
    
	SlotSearchingResultDataType ParkingSlotInfo_L;
    SlotSearchingResultDataType ParkingSlotInfo_R;

} STK_USS_Slot_Search, *P_STK_USS_Slot_Search;

typedef struct
{
	unsigned short PAS_PDC_DISTANCE_FLS_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_FL_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_FML_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_FMR_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_FR_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_FRS_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RLS_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RL_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RML_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RMR_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RR_Zone_cm;
	unsigned short PAS_PDC_DISTANCE_RRS_Zone_cm;
}USS_PDC_Struct_Unit_cm; 

extern BOOL bPowerOnDtcEnd;
extern USSDistanceResultStruct USS_Distance_Info;
extern USS_PDC_Struct USS_PDC_raw_distance_Unit_mm;
extern USS_PDC_Struct_Unit_cm USS_PDC_distance_Unit_cm;

extern U8 USSFailureStatus_Info[12];

void USS_FailureStatus_handler(void);
//extern void USS_ALG_version_number(void);
void USS_INFO_Handler(void);
void USS_Slot_Search(void);
void RadarInfoSendToAPP(void);
void clear_USS_M4_slot_data(void);
void clear_USS_control_slot_data(void);
void USS_Slot_M4_Convert_Handler(void);

void Get_USS_Slot_Type(U8 VerticalOrParallelSlot, U8 AvmOrUssSlot);
void SlotCoordinationHandler(void);
void StkUssInfoInit(void);	
void USS_ALG_version_number_SS(void);
void USS_ALG_version_number_OD(void);
void RadarPowerManagementHandler_5msEntry(void);
unsigned int Get_App_USS_System_Failure_Status(void);
VehiclePdcWorkingState GetUssWorkingState(  void);
void SetUssWorkingState(  VehiclePdcWorkingState state);
PAS_Work_Status GetPasWorkingState(  void);
void SetPasWorkingState(  PAS_Work_Status state);
PAS_Warning_Tone GetPasWarningState(  void);
void SetPasWarningState(  PAS_Warning_Tone state);
void USS_FailureStatus_Handler_CANBK(void);

#endif

