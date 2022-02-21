/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : IDA R&D SW1      									   *
*   AUTHOR	   :            										   *
************************************************************************
* Object        : ApsCanAPP.h
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
* ----------------------------------------------------------------------
* 0.1    Oct 7,2017    Su Zhisheng    Initial version       
*=====================================================================*/

#ifndef _APSCANAPP_H
#define _APSCANAPP_H

//#include "CanMgr.h"
#include "StdType.h"
#include "CONFIG.H"
#include "APSAPP.h"

#define ESC_CAN_MATRIX_6_0_VERSION

#define get_RawCanSignal(x)	can_receive_sig(x)

#define APS_LED_ON() 	 APA_LED_Full_Power_ON();	//PWD_SetDuty(39,100)// GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_7, TRUE)
#define APS_LED_OFF()	 APA_LED_Power_OFF();		//PWD_SetDuty(39,0)//GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_7, FALSE)PDC_Power_ON()
#define PDC_LED_ON() 	 PDC_Power_ON();
#define PDC_LED_OFF()	 PDC_Power_OFF();

#define REAL_PEDAL_INTERVENTION	0x0A	//0x10*0.392% = 3.92%

#define CAR_STANDSTILL	0x1

#define PAS_OBSTACLE_0_3M	0x0F	//0x0F:15*2cm = 0.3m
#define PAS_OBSTACLE_0_8M	0x28	//0x28:40*2cm = 0.8m
#define PAS_OBSTACLE_1_2M	0x3C	//0x3C:60*2cm = 1.0m
#define PAS_OBSTACLE_1_5M	0x4B	//0x4B:75*2cm = 1.5m

#define U8_ZERO		0
#define ONE_KPH		18	//(18*0.05625 = 1.0125 km/h)
#define TIME_2S		200	//(200*10ms = 2s)
#define DISTANCE_2M	200	//(200*1cm = 2m)
#define PARKPLACEFACTOR 0.001
#define DEGREES_180		180
#define SASSTEERINGANGLE_FACTOR 0.1

#define REQUEST	0x1
#define NO_REQUEST	0x0

#define COMFBAND_INIT	0x8C
#define LIMIT_INIT		0x7F

#define LOWERLIMIT_MAX	0x34
#define UPPERLIMIT_MAX	0x4B

#define OFF_MODE		0x0
#define FINISHED_MODE	0x1
#define STANDBY_MODE	0x2
#define ON_MODE			0x3
#define BRAKE_MODE		0x4
#define SUSPEND_MODE	0x5
#define STANDSTILL_MODE	0x6

#define SOFT_OFF		0x1
#define FAST_OFF		0x2
#define IMMEDIATE_OFF	0x3

#define MANEUVER_FINISHED	0x4


#define CARGEAR_P	0X0D	
#define CARGEAR_R	0X0E
#define CARGEAR_N	0X0F
#define CARGEAR_D	0X0C

#define GEAR_P	0x00
#define GEAR_R	0x01
#define GEAR_N	0x02
#define GEAR_D	0x03
#define GEAR_S	0x04
#define GEAR_M	0x05
#define GEAR_W	0x06
#define GEAR_E	0x07
#define GEAR_B	0x08
#define GEAR_CONNECTION 0x0E
#define GEAR_INVALID	0x0F


#define STEERING_TURN_RIGHT_OFFSET 65536
#define ACCEL_COMFBAND_DELTA	40
#define VLCAXTARCOMFBAND_DELTA	2
#define UPPERCOMFBAND_DELTA		(ACCEL_COMFBAND_DELTA+VLCAXTARCOMFBAND_DELTA)
#define LOWERCOMFBAND_DELTA		(ACCEL_COMFBAND_DELTA-VLCAXTARCOMFBAND_DELTA)
#define VLCAXTARAIM_ZERO 		100
#define VLCAXTARAIM_MAX 		130


#define APS_NOT_TERMINATED	0x0
#define APS_DRIVER_OVERRIDE	0x1
#define APS_SUSPENDED	0x2
#define APS_ABORT		0x3

#define APS_SYSTEMSTS_ACTIVE		0x1
#define APS_SYSTEMSTS_FAILURE		0x3
#define APS_SYSTEMSTS_TERMINATED	0x4

#define HS_TIMEOUT	25	//Handshaking timeout: 3*10ms=30ms
#define EPS_TIMEOUT	HS_TIMEOUT
#define ESC_TIMEOUT	HS_TIMEOUT
#define TCU_TIMEOUT	HS_TIMEOUT
#define OVER_SPEED5 89	//444*0.05625=24.4km/h	SPI:0x4401(U16)
#define OVER_SPEED25 444	//444*0.05625=24.4km/h	SPI:0x4401(U16)
#define OVER_SPEED30 533	//444*0.05625=24.4km/h	SPI:0x4401(U16)

#define ESC_ACTIVE		0x1
#define ESC_NOT_ACTIVE	0x0

#define PARKOUT_SYSTEM_STATUS_JUDGING	0x0
#define PARKOUT_SYSTEM_STATUS_NORMAL	0x1

#define PARKOUT_CHK_RESULT_NOK	0x0
#define PARKOUT_CHK_RESULT_OK	0x1

/***************************************/

/****Get_SOC_Slot_Direction********/
#define SOC_Slot_Direction_None 0
#define SOC_Slot_Direction_Right 2
#define SOC_Slot_Direction_Left  1


extern U8 SocPositionSendStatus;
extern U8 SocParkTypeSendStatus;
extern U8 g_APA_park_fusion_type;
extern U8 can_ParkPlace_Type;
extern BOOL APA_IRReversible_SPACE_LIMIT;




typedef enum
{
	EPS_SYS_INITIALIZE,
	EPS_SYS_CLOSED,
	EPS_SYS_OPEN,
	EPS_SYS_ACTIVE,
	EPS_SYS_FAULT,
	EPS_SYS_RESERVED
}EPS_SYS_STATUS_TYPE;

typedef enum
{
	CAR_STOPPED=0x0,
	CAR_FORWARD,
	CAR_BACKWARD,
	CAR_RESERVED,
}CAR_DIRECTON_TYPE;

typedef struct
{						//new reload palce info, Only C100 + C095 use
	U8 L_Valid;			//left  or top
	U8 R_Valid;			//right or down
	float32 ThetaL;		//left  or top
	float32 ThetaR;		//right	or down
	S16 DistL;			//left  or top
	S16 DistR;			//right	or down
}APA_RELOAT_PLACE_INFO;

typedef enum
{
	None,
	System_fault_irreversible_interrupt,
	Driver_interference_irreversible_interrupt,
	Reversible_interrupt,
	Parkout_irreversible_interrupt,
}APA_QUIT_TYPE;

typedef enum
{
	LC_OFF,
	LC_STANDBY,
	ACTIVE_PARKCOMFORT_BRAKE,
	ACTIVE_PARKEMERGENCY_BRAKE,
	ACTIVE_AUTOMATIC_PARK,
	ACTIVE_SHORTDISTANCE_BRAKE, 
	ERROR = 0xA,
}APA_LC_TATUS;




typedef enum
{
	EPS_ERR_OK,
	EPS_ERR_RANGE,
}EPS_err_status_type;

typedef enum
{
	EPS_NO_ERROR,
	EPS_ERR0R,
}EPS_error_status;


typedef enum
{
	ESC_ERR_OK,
	ESC_ERR_RANGE,
	ESC_ERR_NOT_IN_CONTROL,
}ESC_err_status_type;

typedef enum
{
	TCU_ERR_OK,
	TCU_ERR_RANGE,
	TCU_ERR_TARGET_GEAR,
}TCU_err_status_type;

typedef struct
{
	EPS_err_status_type EPS_err_status;
	ESC_err_status_type ESC_err_status;
	TCU_err_status_type TCU_err_status;
}APS_THREE_MODULE_ERR_STATUS_TYPE;


typedef enum
{
	APS_INTERRUPT_NONE,
	APS_INTERRUPT_REVERSIBLE,
	APS_INTERRUPT_IRREVERSIBLE,
}APS_INTERRUPT_STATUS_TYPE;


typedef enum
{
	NOT_SUSPENDED=0x0,
	APS_SWITCH_RELEASE=0x1,
	OBSTACLE_ON_PATH=0x2,
	ANY_DOOR_OPEN=0x3,
	TRUNK_OPEN=0x4,
	SEAT_BELT_RELEASED=0x5,
	EPB_LOCKED=0x6,
	HOOD_OPEN=0x7,
	REMOTE_STOP=0x8,
	WING_MIRROR_OPEN_TIP=0x9,
	Voice_Suspended=0xA,
	Break_pressed_TIP=0x11, //17
	RCTBBrkReq_TIP = 0x12, //18
	APS_PAUSE_CONTINUE= 0x13, //19
	REVERSIBLE_MAX,

}APS_REVERSIBLE_INTERRUPT_STATUS_TYPE;


typedef enum
{
	IRR_NO_FAULT=0x0,
	IRR_EPS_FAILURE=0x01,
	IRR_ESC_FAILURE=0x02,
	IRR_TCU_FAILURE=0x03,
	IRR_USS_FAILURE=0x04,
	IRR_EMS_FAILURE=0x05,
	IRR_SAS_FAILURE=0x06,
	IRR_IHU_FAILURE=0x07,
	IRR_APS_INTERNAL_FAILURE=0x08,			//No feedback signal  
	IRR_ACC_ICC_ACTIVE=0x09,
	IRR_INVALID_WHEEL_PULSE=0x0A,	//10
	IRR_INVALID_WHEEL_SPEED=0x0B,	//11
	IRR_SAS_NOT_CALIBRATED=0x0C,	//12
	IRR_ESC_INACTVE_FAILURE=0x0D,	//13
	IRR_VEHICLE_SPEED_OVER_THRESHOLD=0x0E,//14
	IRR_APS_TIMER_OUT=0x0F,//15
	IRR_APS_STEP_THRESHOLD=0x10,//16
	IRR_INTERRUPT_NUMBER_THRESHOLD=0x11,//17
	IRR_VECHICHE_BLOCKED=0x12,//18
	IRR_UNEXPECTED_GEARPOSITION=0x13,//19
	IRR_UNEXPECTED_EPB_ACTION=0x14,//20
	IRR_ACU_FAILURE=0x15,//21
	IRR_INVALID_EMS_PEDAL=0x16,	//22
	IRR_INVALID_BREAK_PEDAL=0x17,//23
	IRR_REQ_QUIT_SPACE_LIMIT=0x18,//24
	IRR_REQ_QUIT_TRAJECTORY=0x19,//25
	IRR_MAIN_SEAT_BELT_RELEASED=0x1A,//26
	IRR_MAIN_DOOR_OPEN=0x1B,//27
	IRR_ECU_INTERNAL_FAILURE=0x1C,//28
	IRR_AEB_DEC_ACTIVE=0x1F,//31
	IRR_REQ_QUIT_RAMP_LIMIT=0x20,//32
	IRR_ASSOCIATED_SYSTEM_FAILUE=0x21,//33
	IRR_SEARVH_OVERTIME=0x24,
	IRR_Voice_Control_Exit=0x26,//38
	IRR_SOC_CANCEL=0x2A, //42
	IRR_INTERRUPT_OVERTIME=0x2B, //43
	IRREVERSIBLE_MAX,

}APS_IRREVERSIBLE_INTERRUPT_SYSTEM_TYPE;

typedef enum
{
	IRR_NOT_OVERRODE,
	IRR_OVERRODE_BY_STEER,
	IRR_OVERRODE_BY_VEHICLE_SPEED,
	IRR_OVERRODE_BY_GEAR_SHIFT,
	IRR_OVERRODE_BY_EPB,
	IRR_OVERRODE_BY_BREAK,
	IRR_OVERRODE_BY_APS_Switch_Pressed,
	IRR_OVERRODE_BY_SEAT_BELT_RELEASED,
	IRR_OVERRODE_BY_Trunk_Open,
	IRR_OVERRODE_MAX,

}APS_IRREVERSIBLE_INTERRUPT_OVERRODE_TYPE;
#define REASON_BITMASK 0x00000001
extern APS_INTERRUPT_STATUS_TYPE APS_Interrupt_status;

typedef enum
{
	EPS_RELEASE,
	CHECK_EPS_SYSTEM_STATUS_IS_OPEN,
	WEIT_EPS_RECOVER_REVERSIBLE_FAULT,
	CHECK_EPS_SYSTEM_STATUS_IS_ACTIVE,
	EPS_CONTROL,
	EPS_EXIT,
}EPS_run_step_type;

typedef enum
{
	ESC_RELEASE,
	CHECK_ESC_ENABLE_STATUS,
	CHECK_ESC_ACTIVE_STATUS,
	ESC_CONTROL,
	CHECK_ESC_INACTIVE_STATUS,
	ESC_EXIT,
}ESC_run_step_type;

typedef enum
{
	TCU_RELEASE,
	REQUEST_CONNECT_TCU,
	TCU_CONTROL,
	TCU_EXIT,
}TCU_run_step_type;


typedef enum
{
	Control_Disabled,
	Control_Enabled,
}EPS_Request_feedback;

typedef struct 
{
	U8 APA_function_select;
	U8 MMI_PSC_function_select;
	U8 APA_mechanicalpark;
	U8 APA_autodetect;
}MMI_APA_COMMOND_CAN;

typedef struct 
{
    U16 APS_Slot_Width;	
    U16 APS_Slot_Length;
 	S16 APS_SlotCenterPoint_X;
	S16 APS_SlotCenterPoint_Y;
	U16 APS_Slot_LineAngle; 
    
    U8 APS_Slot1_DetectStatus;      
    U8 APS_Slot1_ParkDirection;
    U8 APS_Slot1_ParkType;
    U8 APS_Slot1_Info;
}APA_SLOTINFO;

enum
{
    APA_FUNCTION_SELECT,
	MMI_PSC_FUNCTION_SELECT,
	APA_MECHANICALPARK,
	APA_AUTODETECT,
	APA_COMMOND_NUM,
};	
    
enum Gear_Status
{
	Gear_invaild=0,
	Gear_vaild,
};

enum TCM_Turn
{
	Unknow = 0,
	Left,
	Right,
	Reserve,
};

enum CAN_ABS_DrivingDirection
{
	Stop = 0x0,
	Forward,
	Backward,
	InvalidValue,
};

enum CAN_YRSErrorStatus
{
	NoError = 0x0,
    Error,
};

enum CAN_YRSStatus
{
	Calibrated  = 0x0,
    NotCalibrated,
};

enum CAN_SAS_Status
{
	SASCorrect  = 0x0,
    SASNotCalibrated,
    IntermittentError,
    PermanentError,
};

enum CAN_SAS_SteeringWheelAngleSign
{
	SteeringWheelAngleLeft  = 0x0,
    SteeringWheelAngleRight,
};

enum CAN_EPB_Status
{
	EPBRELEASED  = 0x0,
    EPBLOCKED,
    EPBRELEASING,
    EPBLOCKING,
    EPBUNKOWN,
    EPBRESERVED,
};

typedef enum
{
	Moving,
	Standstill,
	Vstatemax
}VehMoveState;

extern EPS_run_step_type EPS_run_step;
extern TCU_run_step_type TCU_run_step;

extern U8 can_ParkPlace_Type;
extern U8 can_APA_Function_Select;
extern U8 epb_active_cnt;
extern BOOL epb_timeout_flag;
extern U8 APA_Function_Select_Value;


extern U8 acceleration_value;
extern float vehical_current_speed;
extern U8 standstill_Sts;

extern void ESC_Standstill_StopDistance_DriverOff_Control(U8 StopDistance, U8 StandstillReq, U8 DriverOffReq);
extern ESC_err_status_type Vehicle_StartMoveOrAccelatation(double crc_target_acceleration, float VehCurrentSpeed, float DriveOffSpeed);
extern ESC_err_status_type Vehicle_Deceleration(double);
extern ESC_err_status_type Vehicle_Standstill(void);
extern ESC_err_status_type Vehicle_DecelatationAndStandstill(double);
extern void APS_Irreversible_Interrupt_Detect(void);
extern void APS_Reversible_Interrupt_Detect(void);
extern void set_AVM_APA_ParkOutChkResult(void);


extern float32 can_WheelAngleValue;
extern float32 can_VehicleSpeedValue;
extern U8 can_TCU_CurrentGearSt;
extern BOOL ParkingOutFlag;

extern void APS_sig_init(void);
extern U8 get_ESC_Standstill_status(void);
extern void APS_VehicleDirection_Indicate_Handle(void);
extern U8 GetDownSlotSODStatus(void);
extern void ClearDownSlotStatus(void);
extern U8 GetFacing_Space(void);
extern void ClearFacing_Space(void);


extern void SocApsCan_20ms_Entry(void);
extern void apscan_ESC_FrontWheelSpeedsKPH(void);
extern void apscan_ESC_status(void);
extern void apscan_ESC_Standstill_status(void);

extern void apscan_YRS_Status(void);
extern void apscan_SAS_SteeringAngleVD(void);
extern void apscan_ESC_WheelSpeedsRC(void);
extern void apscan_ESC_InformSts(void);

extern void apscan_PAS_SVA_APA_Status(void);
extern void ApsCanApp_recvnavimsg_handler(U16 commandid, U8* data);
extern BOOL aps_receive_camera_fault(void);

extern float32 get_VehicleSpeedValue(void);
extern float32 get_WheelAngleValue(void);
U8 get_can_ABS_DrivingDirection(void);
void apscan_TCU_ActGear(void);

extern float32 get_BCS_FLWheelSpd(void);
extern float32 get_BCS_FRWheelSpd(void);
extern float32 get_BCS_RLWheelSpd(void);
extern float32 get_BCS_RRWheelSpd(void);

extern U8 get_EMS_BrakePedalSt(void);
extern U8 get_EBDFFailed(void);
extern U8 get_ABSFailed(void);
extern U8 get_TCSActive(void);
extern U8 get_ESPActive(void);
extern U8 get_TCSFailed(void);
extern U8 get_ESCFailed(void);
extern U8 get_EPBStatus(void);
extern U8 get_EPB_FailSt(void);
extern U8 get_EMS_BrakePedalStVD(void);

extern U8 get_ActGear(void);
extern U16 get_StoppedCx(void);
extern U16 get_StoppedCy(void);
extern float32 get_StoppedAngle(void);
extern U8 get_CoordinateInitReq(void);
extern U8 get_RoadblockTypeF(void);
extern U8 get_RoadblockTypeR(void);
extern U8 get_SensorErrorFlag(void);
extern U8 get_SAS_CalibrationSts(void);


extern float32 get_ActVehLaltrlAccel(void);
extern float32 get_ActYawRate(void);
extern U8 get_LongitSensorState(void);
extern float32 get_ActVehLongAccel(void);
extern float32 get_VehSpd(void);
extern U8 get_IntegrationSwtCtrl(void);
extern U8 get_SAS_SteeringAngleVD(void);
extern float32 get_SAS_WheelSteerAngle(void);
extern S16 get_SAS_WheelSteerAngle_FV(void);


extern U8 get_WheelPulse_FL(void);
extern U8 get_WheelPulse_FR(void);
extern U8 get_WheelPulse_RL(void);
extern U8 get_WheelPulse_RR(void);
extern U8 get_PAS_SVA_WarningInd_Left(void);
extern U8 get_PAS_SVA_WarningInd_Right(void);



extern U8 get_CCoordinateY(void);
extern U8 get_DCoordinateY(void);
extern U8 get_CCoordinateX(void);
extern U8 get_DCoordinateX(void);

extern U8 get_TCU_CurrentGearSt(void);
extern U8 get_APA_FUNCTION_SELECT(void);
extern U8 get_APA_MECHANICALPARK(void);
extern U8 get_APA_CONFIRMBUTTON(void);
extern U8 get_APA_PopWindowsButton(void);
extern U8 get_MMI_PSC_FUNCTION_SELECT(void);
extern U8 get_APA_AUTODETECT(void);

void apscan_ABS_VehicleSpeed(void);
float32 apscan_AC_OutsideTemperature(void);
extern BOOL get_BCM_LeftTurnLampSt(void);
extern BOOL get_BCM_RightTurnLampSt(void);

extern BOOL get_BCM_LowBeamSt(void);
extern BOOL get_BCM_HighBeamSt(void);
extern BOOL get_BCM_PositionLightSts(void);
extern BOOL get_BCM_FrontFogLightSts(void);
extern BOOL get_BCM_RearFogLightSts(void);
extern U8 get_PAS_Buzzer_Alarm_Pattern(void);
extern U8 get_PDC_MODE_Sts(void);
extern U8 get_PAS_PDC_ButtonPress(void);
extern U8 get_PAS_PDC_DISTANCE_FL(void);
extern U8 get_PAS_PDC_DISTANCE_FML(void);
extern U8 get_PAS_PDC_DISTANCE_FMR(void);
extern U8 get_PAS_PDC_DISTANCE_FR(void);
extern U8 get_PAS_PDC_DISTANCE_RL(void);
extern U8 get_PAS_PDC_DISTANCE_RML(void);
extern U8 get_PAS_PDC_DISTANCE_RMR(void);
extern U8 get_PAS_PDC_DISTANCE_RR(void);
extern U8 get_PAS_PDC_DISTANCE_LSF(void);
extern U8 get_PAS_PDC_DISTANCE_RSF(void);
extern U8 get_PAS_PDC_DISTANCE_LSR(void);
extern U8 get_PAS_PDC_DISTANCE_RSR(void);


extern float32 get_ParkPlace_X_1(void);
extern float32 get_ParkPlace_Y_1(void);
extern float32 get_ParkPlace_X_2(void);
extern float32 get_ParkPlace_Y_2(void);

extern float32 get_ParkPlace_X_3(void);
extern float32 get_ParkPlace_Y_3(void);
extern float32 get_ParkPlace_X_4(void);
extern float32 get_ParkPlace_Y_4(void);

extern U8 get_ParkPlace_Type(void);
extern APS_MODULE_STATUS GetSocCurrentAPSStatus(void);
extern void ClrAPAHardKeyEvt(void);

//extern U8 get_EMS_BrakePedalSt(void); //repetion
extern U8 GetAPASlotType(void);
extern BOOL USS_FAIL(void);



int Get_SOC_Slot_Direction(void);

#endif/*_APSCANAPP_H*/



