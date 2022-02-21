/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
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

#ifndef   _CANAPP_H
#define   _CANAPP_H
//#include "CanMgr.h"
#define CANTXSIG_PASS_1
#include "Cansig_def.h"
#define CANRXSIG_PASS_1
#include "Cansig_def.h"

#define FACTOR_MODE 1
#define USS_SPI_FACTOR  2
#define USS_UNIT_CONVERT 1

#define NUMBER_OF_SENSOR 12
#define RADAR_DISTANCE_INVALID -1

/* vehiclespeed define */
#define SPEED_ERROR_VALUE    0x7FFF
#define SPEED_MISSING_VALUE  0x8000

/* LeverInfo define */
#define LEVERINFO_DEBUNCE_TIME 30

/* steering angle define */
#define ANGLE_DATA_MAX 720 
#define CAN_ANGLE_DATA_RANGE_HIGH 780
#define ERROR_VALUE_RANGE 0x7FFF

/* VehicleOdometer define */
#define ODOMETER_ERROR_VALUE    0x01FFFFFF
#define ODOMETER_MISSING_VALUE  0x02000000

/* can signal send/receive interface */
#define can_send_sig(x,c)     IlPutTx##x(c)
#define can_receive_sig(x)    IlGetRx##x()

#define GEAR_DISPLAY_INVALID   0x00     // GearDisplaySts invlid
#define PI 3.1415

#define VCU_PTREADY_ACTIVE	0x1

enum
{
    ENGINE_STOP,
    ENGINE_CRANKING,
    ENGINE_STOPPING,
    ENGINE_RUNNING,
   	ENGINE_ABNORMAL = 0X06,
   	ENGINE_INVALID,
};
	
enum AVS_POWERMODE_IG_TYPE
{
	Off,
	IgnitionOn = 0x04,
};

enum 
{
	RESET,
	SSM_STANDBY,
	STOPPED,
	START_RESTART,
	ENGINE_RESTART,
	OPERATION,
	AUTO_STOPPING,
	RESERVE,
};

typedef enum CAN_TURNLAMP_STSTUS_DATA_TAG
{
    CAN_TURNLAM_OFF,
    CAN_TURNLAMP_LEFT,
    CAN_TURNLAMP_RIGHT,
    CAN_TURNLAMP_HAZRD,
    CAN_TURNLAMP_MAX_DATA,
} CAN_TURNLAMP_STSTUS_DATA;
	
typedef struct
{
	U16 x1_val;
	U16 y1_val;
	U8 PressType;
}COORDINATE_DATA_DEF;

enum AVM_DISPLAY_REQ
{
	AVM_CONTROL_REQ,
	AVM_SOFTKEY_RESP,
	AVM_FACTORY_MODE,
};

enum AVM_CONTROL
{
    AVM_CTRL_EXIT,
    AVM_CTRL_ENTER,
};

enum AVM_ONOFF_REQ
{
	AVM_NO_REQUEST,
	AVM_ENTER_REQUEST,
	AVM_EXIT_REQUEST,
};
	
enum AVM_ONOFF_RSP
{
	AVM_ENTER_RESPONE,
	AVM_EXIT_RESPONE,
};

enum SOFT_VERSION_TYPE
{
	MCU_VERSION_NUMBER,
	USS_VERSION_NUMBER,
	ALG_VERSION_NUMBER,
};

enum CAN_KEY_TYPE
{
	CAN_HARDKEY_TYPE=0x00,
    CAN_SOFTKEY_TYPE=0x01,
    CAN_CALIBRATION_TYPE=0x03,
};

enum CAN_SOFTKEY_TYPE_S
{
	AVM_ENTER_EXIT_SWITCH,
	AVM_VIEW_ANGLE_SWITCH,
	AVM_VIEW_MODE_SWITCH,
	CALIBRATION_REQ,
	DVR_HOME_REQ,
	DVR_SDFORMAT_REQ,
	DVR_RESTORE_FACTORY_REQ,
};

typedef enum STEERING_DIRECT_TAG
{
    STEERING_DIRECT_LEFT,
    STEERING_DIRECT_RIGHT,
} STEERING_DIRECT;

enum  steering_wheel_direction_Info 
{
	steeringWheelDir_center = 0,  
	steeringWheelDir_left,		    
	steeringWheelDir_right,		   
};

enum TOUCH_EVENT
{
	NOT_TOUCH = 0x00,
	TOUCH_PEN_DOWN,
	TOUCH_PEN_UP,
};
	
enum TOUCH_EVENT_STEP
{
	TOUCH_STEP1 = 0x00,
	TOUCH_STEP2,
};

enum AVM_SwitchScreen_STA_TYPE
{
	CAN_AVM_Enter_Request = 0x01,
	CAN_AVM_Exit_Request = 0x02,
	//SK_ENTER_CALIBRATION=3,
	//SK_UPDATE_AVM=4,
};

enum CAN_AVM_VIEW_MODE_TYPE
{
	CAN_ALL_TOP_VIEW = 0x01,
	CAN_TOP_VIEW_AND_FRONT_VIEW = 0x02,
	CAN_TOP_VIEW_AND_REAR_VIEW = 0x03,
	CAN_TOP_VIEW_AND_LEFT_VIEW = 0x04,
	CAN_TOP_VIEW_AND_RIGHT_VIEW = 0x05,
	CAN_FRONT_WIDE_VIEW = 0x06,
	CAN_REAR_WIDE_VIEW = 0x07,
	CAN_FRONT_RIM_VIEW = 0x09,
	CAN_REAR_RIM_VIEW = 0x0A,
	CAN_SCREEN_DRAGGED_3D_VIEW = 0x0B,
	CAN_FACTROY_MODE = 0x0D,
	CAN_CALIBRATION_MODE = 0x0E,
	CAN_INVALID_VALUE = 0x0F,
};

enum
{
    E_DRIVER_DOOR,
    E_PSNG_DOOR,
  	E_RR_DOOR,
  	E_LR_DOOR,
 	E_TRUNK_DOOR = 0x04,
    E_VEHICLE_DOOR_NUM,
};



enum 
{
	E_DOOR_CLOSE,
	E_DOOR_OPEN,
};

enum CAN_LANGUAGE_TYPE
{
	Inactive = 0x00,
	Can_Simplified_Chinese,
	Can_Traditional_Chinese,
	Can_English,
	Can_French,
	Can_Arabic,
	Can_Russian,
};

enum CAN_LEVERINFO_TYPE
{
	Can_LeverInfo_P = 0x0,
	Can_LeverInfo_R,
	Can_LeverInfo_N,
	Can_LeverInfo_D,
	Can_LeverInfo_S,
	Can_LeverInfo_M,
	Can_LeverInfo_W,
	Can_LeverInfo_E,
	Can_LeverInfo_B,
	Can_LeverInfo_Invalid = 0xFF,
};

enum SPI_LEVERINFO_TYPE
{
	SPI_LeverInfo_P = 0x1,
	SPI_LeverInfo_R,
	SPI_LeverInfo_N,
	SPI_LeverInfo_D,
	SPI_LeverInfo_M,
};

enum SPI_LANGUAGE_TYPE
{
	SPI_Chinese,
	SPI_English,
};

enum AVS_STA_TYPE
{
	SK_EXIT=0x00,
	SK_OPEN_AVM=0x01,
	SK_MAX = 0x02,
	//SK_ENTER_CALIBRATION=3,
	//SK_UPDATE_AVM=4,
};

enum CAN_DYNAMIC_PGL_TYPE
{
	F_OFF_AND_R_OFF = 0x01,
	F_OFF_AND_R_ON = 0x02,
	F_ON_AND_R_OFF = 0x03,
	F_ON_AND_R_ON = 0x04,	
};
	

enum CAN_Validity
{
	CAN_Invalid = 0x00,
	CAN_Valid = 0x01,
};
	
enum CAMERA_INDEX
{
	FRONT_CAMERA_INDEX,
	REAR_CAMERA_INDEX,  
	LEFT_CAMERA_INDEX, 
	RIGHT_CAMERA_INDEX, 
	CAMERA_INDEX_MAX,
};

enum CAM_MOD_REQ
{
	E_MOD_INACTIVE = 0x00,
	E_MOD_OFF,  
	E_MOD_ON, 
};


enum CAN_HMI_VIEW
{
	HMI_VIEW_MAIN_SCREEN = 0X00,
	HMI_VIEW_EOL,	
};


enum AVSCALIBRATION_STATUS
{
	NOT_CALIBRATED = 0x00,
    CALIBRATING,
	CALIBRATED,
};



extern void can_sig_init(void);
extern void CanApp_recvnavimsg_handler(U16 commandid, U8* data);
extern void Doip_recvnavimsg_handler(U16 commandid, U8* data);
extern void SocCan_20ms_Entry(void);
extern void can_turnlamp_rxhandler(void);
extern void can_avm_act_req_rxhandler(void);
extern void can_vehiclespeed_rxhandler(void);
extern void can_LeverInfo_rxhandler(void);
extern void can_AVS_switch_rxhandler(void);
void can_datetime_rxhandler(void);

extern void can_avm_hu_req_exit_rxhandler(void);
extern void can_acckey_rxhandler(void);
extern void can_steering_angle_rxhandler(void);
extern void can_coordinate_rxhandler(void);
extern void can_VehicleOdometer_rxhandler(void);
extern void CAN_CarDoorStaus_rxhandler(void);
extern void CAN_CarRearviewMirrorSt_rxhandler(void);
extern void can_msg_rx_attribute_handle(void);
extern void can_view_mode_angle_rxhandler(void);
extern void can_HUReqViewMode_rxhandler(void); 
extern void can_AVSErrorSt_txhandler(void);
extern void can_SetLanguage_rxhandler();
extern void can_avm_enter_exit_speech_rxhandler(void);
extern void can_avm_enter_exit_rxhandler(void);
extern void can_AVM_ViewModeControl_rxhandler(void);
extern void can_DynamicPGS_rxhandler(void);
extern void can_FactoryModeReq_rxhandler(void);
extern void can_OTAMode_rxhandler(void);
extern void can_PDCAutoOnFun_txhandler(void);
extern void can_CameraErrorSt_txhandler(void);
extern void Can_ModWarning_txhandler(void);
extern void Can_PDWarning_txhandler(void);
extern void apscan_ESC_FrontWheelSpeedsKPH(void);
extern void apscan_ESC_WheelSpeedsRC(void);
extern BOOL Get_Soc_AVM_FACTORY_MODE(void);
extern BOOL GetMmiTouchDebugFlag(void);
extern void can_AVSCalibrationStatus_txhandler(void);
extern void VehiclePositionInitRequest(BOOL InitReq);

extern void test_USS_interface(void);
extern void test_USS_distance(void);

extern U8 GetModStatus(void);
extern U8 GetBlindPaddingStatus(void);
extern BOOL Get_Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS(void);
extern U8 EolUpdateFlag;
extern U8 MmiTouchDebugFlag;
extern U8 GW_OTAMode_fun;

#define APSFULLY_BRIGHT()   PWMD_SetDuty(50,100,95)
#define APSHALF_BRIGHT()    PWMD_SetDuty(50,100,35)
#define APSOFF_BRIGHT()     PWMD_SetDuty(50,100,0)

enum CAN_SendThrice_TYPE
{
	bDVR_ControlRequest,
	bDVR_HomeResult,
	bDVR_CommandRespList,
	bDVR_CommandResult,
	bPCS_ACU_DisplayReq,
	bAVM_ViewTouchBeef,
	bAVM_APA_WarningTone,
	bAVM_APA_SpeedExit,
	bAVM_APA_ECU_Exit,
	bAVM_APA_ACC_Exit,
	bAVM_APA_FAILE_Exit,
	bAPA_SERACH_INTO,
	MAX_SendThrice,
};

//uidp5358 add
typedef struct Appl_Brake_Apply_Information_CE_msgTypeTag
{
  float BrkPdlPos;
  S16 BrkPdlPosGrad;
  float WhlRotStatTmstmpRes;
  U16 BrkPdDrvAPrsStaPVal : 9;
  U8 BrkPdDrvAppPrsAlRC : 2;
  U8 ABSAtv : 1;
  U8 ABSFld : 1;
  U8 BrkPdlModTrvl : 1;
  U8 BrkPdlModTrvlV : 1;
  U8 BrkAppSnsrHmPosLrnd : 1;
  U8 BPDAPS_BkPDrvApPV : 1;
  U8 BPDAPS_BkPDrvApP : 8;
  U8 PrplsnSysAtv : 1;
  U8 BrkPedPosAlvRolngCnt : 2;
} Appl_Brake_Apply_Information_CE_msgType;

typedef struct Appl_Park_Assist_Parallel_CE_msgTypeTag
{
  float SWAR_TrgtAng;
  U32 StrWhlAngReqPrtVal;
  U8 StrWhlTctlFdbkReqActRC;
  U8 StrWhlTctlFdbkReqAct;
  U8 StrWhlTctlFdbkReqActProtVal;
  U8 SWAR_ReqActV;
  U8 SWAR_ReqAct;
  U8 StrWhlAngReqARC;
} Appl_Park_Assist_Parallel_CE_msgType;

typedef struct Appl_Automatic_Braking_Status_CE_msgTypeTag
{
  U8 VehMvngStat : 1;
} Appl_Automatic_Braking_Status_CE_msgType;

typedef struct Appl_Driven_Wheel_Grnd_Velocity_CE_msgTypeTag
{
  U16 WhlGrndVlctyLftDrvn : 14;
  U16 WhlGrndVlctyRtDrvn : 14;
} Appl_Driven_Wheel_Grnd_Velocity_CE_msgType;

typedef struct Appl_NonDriven_Wheel_Grnd_Velocity_CE_msgTypeTag
{
  U16 WhlGrndVlctyLftNnDrvn : 14;
  U16 WhlGrndVlctyRtNnDrvn : 14;
} Appl_NonDriven_Wheel_Grnd_Velocity_CE_msgType;

typedef struct Appl_PPEI_Chassis_General_Status_1_CE_msgTypeTag
{
  float VehDynYawRate;
  float VSELatAcc;
  U8 TCSysEnbld : 1;
  U8 TCSysAtv : 1;
  U8 BrkPdlDrvAppPrsDetcdV : 1;
  U8 BrkPdlDrvAppPrsDetcd : 1;
  U8 SprTireSt : 3;
  U8 VehDynYawRateV : 1;
  U8 VhDynCntlSysSt : 3;
  U8 VSELatAccV : 1;
} Appl_PPEI_Chassis_General_Status_1_CE_msgType;

typedef struct Appl_PPEI_Vehicle_Speed_Status_CE_msgTypeTag
{
  float VehSpdAvgDrvn;
  U8 VehSpdAvgDrvnV;
} Appl_PPEI_Vehicle_Speed_Status_CE_msgType;

typedef struct Appl_Dis_Long_EchoHeight_msgTypeTag
{
  U8 Dis_FLL_Echo_Height;
  U8 Dis_FRL_Echo_Height;
  U8 Dis_RLL_Echo_Height;
  U8 Dis_RRL_Echo_Height;
} Appl_Dis_Long_EchoHeight_msgType;

typedef struct Appl_Dis_Short_EchoHeight_msgTypeTag
{
  U8 Dis_FL_Echo_Height;
  U8 Dis_FR_Echo_Height;
  U8 Dis_FML_Echo_Height;
  U8 Dis_FMR_Echo_Height;
  U8 Dis_RL_Echo_Height;
  U8 Dis_RR_Echo_Height;
  U8 Dis_RML_Echo_Height;
  U8 Dis_RMR_Echo_Height;
} Appl_Dis_Short_EchoHeight_msgType;

typedef struct Appl_Dis_ShortSensors_msgTypeTag
{
	U16 Dis_Front_FL_16U;
	U16 Dis_Front_FR_16U;
	U16 Dis_Front_FML_16U;
	U16 Dis_Front_FMR_16U;
	U16 Dis_Rear_RL_16U;
	U16 Dis_Rear_RR_16U;
	U16 Dis_Rear_RML_16U;
	U16 Dis_Rear_RMR_16U;
} Appl_Dis_ShortSensors_msgType;

typedef struct Appl_Warningboard_Rx_msgTypeTag
{
  U8 Warningboard_Switch;
  U8 Warningboard_FZ;
} Appl_Warningboard_Rx_msgType;

typedef struct Appl_Dis_Sensors_Status_msgTypeTag
{
  U16 Dis_Sensors_StatusValid_16U;
} Appl_Dis_Sensors_Status_msgType;

typedef struct Appl_Dis_SidesSensors_msgTypeTag
{
  U16 Dis_Sides_FLL_16U;
  U16 Dis_Sides_FRL_16U;
  U16 Dis_Sides_RLL_16U;
  U16 Dis_Sides_RRL_16U;
} Appl_Dis_SidesSensors_msgType;

typedef struct Appl_USS_Slot_Outline_Info_msgTypeTag
{
  S16 Uss_Slot_Outline_X;
  S16 Uss_Slot_Outline_Y;
} Appl_USS_Slot_Outline_Info_msgType;

typedef struct Appl_USS_APA_NonHandler_Dis_msgTypeTag
{
  S16 FrsNonHandlerObjDis;
  S16 FlsNonHandlerObjDis;
} Appl_USS_APA_NonHandler_Dis_msgType;

typedef struct Appl_NonDrivn_Whl_Rotationl_Stat_CE_msgTypeTag
{
  U16 WRSLNDWhlDistPCntr;
  U16 WRSRNDWhlDistPCntr;
} Appl_NonDrivn_Whl_Rotationl_Stat_CE_msgType;

typedef struct Appl_Driven_Whl_Rotational_Stat_CE_msgTypeTag
{
  U16 WRSLDWhlDistPlsCntr;
  U16 WRSRDWhlDistPlsCntr;
} Appl_Driven_Whl_Rotational_Stat_CE_msgType;

typedef struct Appl_PPEI_Steering_Wheel_Angle_CE_msgTypeTag
{
  float StrWhAng;
  U16 StrWhAngGrd : 12;
  U16 StrAngSnsChksm : 11;
  U8 StrWhAngMsk : 1;
  U8 StrWhlAngSenTyp : 2;
  U8 StrWhlAngSenCalStat : 2;
  U8 StrWhAngV : 1;
  U8 StrWhAngGrdMsk : 1;
  U8 StWhlAngAliveRollCnt : 2;
  U8 StrWhAngGrdV : 1;
} Appl_PPEI_Steering_Wheel_Angle_CE_msgType;

typedef struct Appl_Trans_General_Status_2_CE_msgTypeTag
{
  U8 TransTUDMdStat : 2;
  U8 TransEstGear : 4;
  U8 TransEstGearV : 1;
  U8 TrnsShftLvrPosV;
  U8 TrnsSftMdStat : 3;
  U8 TrnShftPtrnActStat : 3;
  U8 TrnsShftLvrPos;
} Appl_Trans_General_Status_2_CE_msgType;

typedef struct Appl_Electric_Power_Steering_CE_msgTypeTag
{
  U8 ElecPwrStrAvalStat : 2;
  U8 DrvStrIntfrDtcdV : 1;
  U8 DrvStrIntfrDtcd : 1;
  U8 DrvStrIntfrDetARC : 2;
  U8 DrvStrIntfrDetPrtVal : 2;
  U8 ElcPwrStrAvalStatARC : 2;
  U8 ElcPwrStrAvalStatPVal : 2;
} Appl_Electric_Power_Steering_CE_msgType;

typedef struct Appl_Outside_Air_Temp_Status_CE_msgTypeTag
{
  float OtsAirTmpCrVal;
  U8 OtsAirTmpCrValV : 1;
  U8 OtsAirTmpCrValMsk : 1;
  U8 OutAirTempVDA : 1;
} Appl_Outside_Air_Temp_Status_CE_msgType;

extern void ApplGetRxBrake_Apply_Information_CEMsg(Appl_Brake_Apply_Information_CE_msgType* getVehInfo);
extern void ApplGetRxAutomatic_Braking_Status_CEMsg(Appl_Automatic_Braking_Status_CE_msgType* getVehInfo);
extern void ApplGetRxDriven_Wheel_Grnd_Velocity_CEMsg(Appl_Driven_Wheel_Grnd_Velocity_CE_msgType* getVehInfo);
extern void ApplGetRxNonDriven_Wheel_Grnd_Velocity_CEMsg(Appl_NonDriven_Wheel_Grnd_Velocity_CE_msgType* getVehInfo);
extern void ApplGetRxPPEI_Chassis_General_Status_1_CEMsg(Appl_PPEI_Chassis_General_Status_1_CE_msgType* getVehInfo);
extern void ApplGetRxPPEI_Vehicle_Speed_Status_CEMsg(Appl_PPEI_Vehicle_Speed_Status_CE_msgType* getVehInfo);
extern void ApplGetRxNonDrivn_Whl_Rotationl_Stat_CEMsg(Appl_NonDrivn_Whl_Rotationl_Stat_CE_msgType* getVehInfo);
extern void ApplGetRxDriven_Whl_Rotational_Stat_CEMsg(Appl_Driven_Whl_Rotational_Stat_CE_msgType* getVehInfo);
extern void ApplGetRxPPEI_Steering_Wheel_Angle_CEMsg(Appl_PPEI_Steering_Wheel_Angle_CE_msgType* getVehInfo);
extern void ApplGetRxTrans_General_Status_2_CEMsg(Appl_Trans_General_Status_2_CE_msgType* getVehInfo);
extern void ApplGetRxElectric_Power_Steering_CEMsg(Appl_Electric_Power_Steering_CE_msgType* getVehInfo);
extern void ApplGetRxOutside_Air_Temp_Status_CEMsg(Appl_Outside_Air_Temp_Status_CE_msgType* getVehInfo);
extern void ApplPutTxPark_Assist_Parallel_CEMsg(Appl_Park_Assist_Parallel_CE_msgType setVehInfo);
extern void ApplPutTxDis_Long_EchoHeightMsg(Appl_Dis_Long_EchoHeight_msgType setVehInfo);
extern void ApplPutTxDis_Short_EchoHeightMsg(Appl_Dis_Short_EchoHeight_msgType setVehInfo);
extern void ApplPutTxDis_ShortSensorsMsg(Appl_Dis_ShortSensors_msgType setVehInfo);
extern void ApplPutTxDis_Sensors_StatusMsg(Appl_Dis_Sensors_Status_msgType setVehInfo);
extern void ApplPutTxDis_SidesSensorsMsg(Appl_Dis_SidesSensors_msgType setVehInfo);
extern void ApplPutTxUSS_Slot_Outline_InfoMsg(Appl_USS_Slot_Outline_Info_msgType setVehInfo);
#ifdef APA_Slot_Searching_Replay
extern void ApplGetRxUSS_APA_NonHandler_DisMsg(Appl_USS_APA_NonHandler_Dis_msgType* getVehInfo);
#endif
extern void ApplPutTxUSS_APA_NonHandler_DisMsg(Appl_USS_APA_NonHandler_Dis_msgType setVehInfo);
extern void ApplPutTxWarningboard_RxMsg(Appl_Warningboard_Rx_msgType setVehInfo);
//add for waypoint resend request
extern BOOL b_Way_Point_Feedback_1_Triger;
extern BOOL b_Way_Point_Feedback_2_Triger;
#endif/*_CANAPP_H*/

