
#ifndef USS_LIB_IF_H
#define USS_LIB_IF_H

#include "typeDefine.h"


typedef signed char     SInt8;        //        -128 .. +127         ARREF:PLATFORM016
typedef  unsigned char   UInt8;        //           0 .. 255          ARREF:PLATFORM013
typedef signed short    SInt16;       //      -32768 .. +32767       ARREF:PLATFORM017
typedef unsigned short  UInt16;       //           0 .. 65535        ARREF:PLATFORM014
typedef signed long     SInt32;       // -2147483648 .. +2147483647  ARREF:PLATFORM018
typedef unsigned long   UInt32;       //           0 .. 4294967295   ARREF:PLATFORM015
typedef   unsigned char   Boolean;  


typedef enum 
{
    g_SideLeft_enm        = 0,  //鍧愪�?
    g_SideRight_enm       = 1,  //鍙充�?
    g_SideMax_enm        = 2   //涓や�?
} gType_Side_en;



typedef enum 
 {
   g_Park_enm,
   g_Reverse_enm,
   g_Neutral_enm,
   g_Drive_enm,
   g_NoSignal_enm
   // possibility to add additional project specific gear modes
} gType_Pos_en;


typedef struct
{
  SInt16 X_si16;      //!< x-coordinate or x-component of vector
  SInt16 Y_si16;      //!< y-coordinate or y-component of vector
}gType_Point_st;

typedef struct gT_mtlPoint_st
{
  SInt16 X_si16;      //!< x-coordinate or x-component of vector
  SInt16 Y_si16;      //!< y-coordinate or y-component of vector
} gType_mtlPoint_st;


typedef struct
{
  SInt32 X_si32;  //mm    //!< x-coordinate or x-component of vector
  SInt32 Y_si32;  //mm    //!< y-coordinate or y-component of vector
}gType_PSLPoint_st;


typedef enum
{                
    OBJ_NONE_enm               = 0,   //闅滅鐗╃被鍨嬫病鏈?
    OBJ_POINT_enm              = 1,   //闅滅鐗╃被鍨嬩负鐐?
    OBJ_STRAIGHT_0CORNER_enm   = 2,   //闅滅鐗╃被鍨嬫槸鏈夎緝闀垮害鐨勭墿浣擄紝鏃犵鐐?
    OBJ_STRAIGHT_1CORNER_enm   = 3,   //闅滅鐗╃被鍨嬫槸鏈変竴瀹氶暱搴︾墿浣擄紝鏈変竴涓鐐?
    OBJ_STRAIGHT_2CORNER_enm   = 4   //闅滅鐗╃被鍨嬫槸鏈夎緝鐭暱搴︾殑鐗╀綋锛屾湁涓や釜绔偣
}gType_ObjectType_en;

typedef enum
{                
    OBJ_HEIGHT_TRAVERSABLE_enm  = 0,    //楂樺害鍙彉�?
    OBJ_HEIGHT_LOW_enm          = 1,    //楂樺害涓轰綆�?
    OBJ_HEIGHT_HIGH_enm         = 2,    //楂樺害涓洪珮
    OBJ_HEIGHT_UNKNOWN_enm      = 3    //楂樺害涓嶇‘�?
}gType_ObjectHeight_en;
	typedef enum
	{
	  OBJECT_CAR_enm		  = 0,
	  OBJECT_CURBSTONE_enm	  = 1,
	  OBJECT_ROUND_OBJECT_enm = 2,
	  OBJECT_UNKNOWN_enm	  = 3,
	  OBJECT_DUMMY_enm		  = 4,	// contains start segment with minimum length 
	  OBJECT_NONE_enm		  = 5
	}
	gType_PSL_ObjectType_en;
	typedef enum
	{
	 PSLCLA_OBJECT_UNCLASSIFIED_enm, // object classification is in work	   
	 PSLCLA_OBJECT_COMPLETED_enm,	   // object classification has been done and the corner has been actualized
	 PSLCLA_OBJECT_FINISHED_enm	  // track for object has been finished, i.e.
	  // object classification done
	}
	gType_PSLCLA_ObjectStatus_en;

	typedef struct
{
    gType_Point_st CurbStartP_st;
    gType_Point_st CurbEndP_st;
    SInt16 CurbDeg_si16;
	Boolean CurbStartValid;
	Boolean CurbEndValid;
	Boolean CurbDegValid;
}gTye_CurbstoneInfo_st;

typedef struct
{
gType_mtlPoint_st       Obj1stCorner_st;
gType_mtlPoint_st       Obj2ndCorner_st;
gType_PSL_ObjectType_en  ObjectType_en;
Boolean                 ObjectValid_bl;
UInt8                   Height_ui8;
//gType_PSLCLA_ObjectStatus_en ObjectStatus_en;
Boolean                 StPointValid_bl;
Boolean                 EdPointValid_bl;
gType_ObjectHeight_en  HeightStatus_en;
Boolean                StPointConner_bl;
Boolean                EdPointConner_bl;


}gTye_SideObjectMessage_st ;





typedef enum
{
    USS_SNS_RRS = 0,
    USS_SNS_RR,
    USS_SNS_RRM,
    USS_SNS_RLM,
    USS_SNS_RL,
    USS_SNS_RLS,
    USS_SNS_FRS,
    USS_SNS_FR,
    USS_SNS_FRM,
    USS_SNS_FLM,
    USS_SNS_FL,
    USS_SNS_FLS
}USS_SNS_INDEX_TYPE;
	

// Driver Interface
typedef enum _DEV_PWR_OP_TYPE
{
	DEV_OP_UNKNOW,
	DEV_OP_OPEN,		 
	DEV_OP_PWR_ON,
	DEV_OP_PWR_WAKEUP,
	DEV_OP_PWR_SLEEP,
	DEV_OP_PWR_OFF,
	DEV_OP_CLOSE,
	DEV_OP_MAX,
}DEV_PWR_OP_TYPE;

typedef enum
{
	DEV_STATE_UNKNOW,
	DEV_OPEN_ING,  // open
	DEV_OPEN_ING_TIMEOUT,
	DEV_OPEN,

	DEV_ON_ING,	  // powerControl(DEV_OP_PWR_ON)
	DEV_ON_ING_TIMEOUT,
	DEV_ON,
	DEV_WAKE_ING,
	DEV_WAKE_ING_TIMEOUT,
	DEV_WAKE,
	DEV_SLEEP_ING, // powerControl(DEV_OP_PWR_SLEEP)
	DEV_SLEEP_ING_TIMEOUT,
	DEV_SLEEP,
	DEV_OFF_ING, // powerControl(DEV_OP_PWR_OFF)
	DEV_OFF_ING_TIMEOUT,
	DEV_OFF,
	  
	DEV_CLOSE_ING, // close
	DEV_CLOSE_ING_TIMEOUT,
	DEV_CLOSE,
}DEV_PWR_STATE_TYPE;
typedef struct
{
	unsigned short USS_Distance_RRS;/*Unit:mm.长距后右*/
	unsigned short USS_Distance_RR;/*Unit:mm.短距后左*/
	unsigned short USS_Distance_RRM;/*Unit:mm.短距后右*/
	unsigned short USS_Distance_RLM;/*Unit:mm.短距后中�*/
	unsigned short USS_Distance_RL;/*Unit:mm.短距后左*/
	unsigned short USS_Distance_RLS;/*Unit:mm.长距后左*/
	unsigned short USS_Distance_FRS;/*Unit:mm.长距前右*/
	unsigned short USS_Distance_FR;/*Unit:mm.短距前右*/
	unsigned short USS_Distance_FRM;/*Unit:mm.短距前中�*/
	unsigned short USS_Distance_FLM;/*Unit:mm.短距前中�*/
	unsigned short USS_Distance_FL;/*Unit:mm.短距前左*/
	unsigned short USS_Distance_FLS;/*Unit:mm.长距前左*/
}USSDistanceResultStructType;

typedef struct
{
	unsigned short USS_Distance_RR;
	unsigned short USS_Distance_RRM;
	unsigned short USS_Distance_RLM;
	unsigned short USS_Distance_RL;
	unsigned short USS_Distance_FR;
	unsigned short USS_Distance_FRM;
	unsigned short USS_Distance_FLM;
	unsigned short USS_Distance_FL;
}USSDirectDistanceResultStructType;

typedef struct{
	unsigned charPAS_Buzzer_Alarm_Pattern_sender;//蜂鸣�?
	unsigned charPAS_PDC_MODE_sender;//PDC状�?
	unsigned charPAS_PDC_DISTANCE_FL_sender;
	unsigned charPAS_PDC_DISTANCE_FML_sender;
	unsigned charPAS_PDC_DISTANCE_FMR_sender;
	unsigned charPAS_PDC_DISTANCE_FR_sender;
	unsigned charPAS_PDC_DISTANCE_RL_sender;
	unsigned charPAS_PDC_DISTANCE_RML_sender;
	unsigned charPAS_PDC_DISTANCE_RMR_sender;
	unsigned charPAS_PDC_DISTANCE_RR_sender;
	unsigned charPAS_PDC_DISTANCE_LSF_sender;
	unsigned charPAS_PDC_DISTANCE_RSF_sender;
	unsigned charPAS_PDC_DISTANCE_LSR_sender;
	unsigned charPAS_PDC_DISTANCE_RSR_sender;
}USS_PDC_StructType;//PDC报警区域，扇形区域，可由FV定义�?

typedef struct
{	
	USSDistanceResultStructType  USS_DistanceInfo;//雷达探头到障碍物的距�?
	USSDirectDistanceResultStructType  USS_DirectDistanceInfo;//三角定位的距�?
    USS_PDC_StructType   USS_PDC_Info;//PDC报警的扇形区域距离信息。可由FV提供该结构体定义�?
}USS_InfoStructType;

/*************************************************************
    * Function Name: unsigned char DiagGetUssSenorDistanceValue(PASysSnsIndexType Sensor)
    * Description  : Diagnostic get the USS distance value use for $22
    * functional adaption: diagnostic
    * Parameters   : PASysSnsIndexType Sensor (PASysSnsIndexType indicate the number of sensors)
    * Return Value : unsigned char (0x00~0xFF indicate the distance  unit:cm)
*****************************************************************/
extern unsigned char DiagGetUssSenorDistance(USS_SNS_INDEX_TYPE Sensor);


typedef enum
{
	USS_IO_CTRL_CMD_UNKNOW,
	USS_IO_CTRL_CMD_GET_OBJ_DIS,
}USS_IO_CTRL_CMD;

typedef struct
{
	float COORDINATE_X;
	float COORDINATE_Y;
} PAS_COORDINATE_POSITION;

typedef struct
{
	unsigned short sftc_FLWheelSpeedRC;
	unsigned char  sftc_FLWheelSpeedRCSts;
	unsigned short sftc_FRWheelSpeedRC;
	unsigned char  sftc_FRWheelSpeedRCSts;
	unsigned short sftc_RLWheelSpeedRC;
	unsigned char  sftc_RLWheelSpeedRCSts;
	unsigned short sftc_RRWheelSpeedRC;
	unsigned char  sftc_RRWheelSpeedRCSts;
	unsigned char  sftc_FLWheelDirection;
	unsigned char  sftc_FRWheelDirection;
	unsigned char  sftc_RLWheelDirection;
	unsigned char  sftc_RRWheelDirection;
	unsigned char  sftc_GearStatus;
	signed short   sftc_SteeringAngle;
	unsigned char  sftc_steeringAngleValidity;
	unsigned short sftc_FLWheelSpeed;
	unsigned char  sftc_FLWheelSpeedValidity;
	unsigned short sftc_FRWheelSpeed;
	unsigned char  sftc_FRWheelSpeedValidity;
	unsigned short sftc_RLWheelSpeed;
	unsigned char  sftc_RLWheelSpeedValidity;
	unsigned short sftc_RRWheelSpeed;
	unsigned char  sftc_RRWheelSpeedValidity;
	unsigned short sftc_VehicleSpeed;
	unsigned char  sftc_VehicleSpeedValidity;
	unsigned char  sftc_PEPS_PowerMode;
	unsigned char  sftc_PEPS_PowerModeValidity;
	unsigned char  sftc_EPBSwitchSts;
	unsigned char  sftc_EngineSts;
	unsigned short sftc_LateralAcce;
	unsigned short sftc_LateralAcceOffset;
	unsigned char  sftc_LateralSensorSts;
	unsigned short sftc_LongitAcce;
	unsigned short sftc_LongitAcceOffset;
	unsigned char  sftc_LongitSensorSts;
	unsigned short sftc_YRSYawRate;
	unsigned short sftc_YRSYawRateOffset;
	unsigned char  sftc_YRSYawRateSensorSts;
	unsigned short sftc_AC_AmbientTemperature;
	unsigned char  sftc_AC_AmbientTemperatureInvalid;//（初始值设�?，方便台架调试）
	//unsigned char sftc_TurnLight;
	unsigned char  sftc_TurnLight_Left;
	unsigned char  sftc_TurnLight_Right;
	unsigned char  sftc_SVA_Request;
	unsigned char  sftc_EMS_Pedal_Position;
	unsigned char  sftc_BCM_WiperSts;//（特殊项目限定）
	unsigned char  sftc_VCU_ePTReady; //（特殊项目限定）
	unsigned char  sftc_MMI_PDC_ButtonRelease; //（特殊项目限定）
	//unsigned char EPS_STS;

	unsigned short  WIC_FR_Tick_ui16;
	unsigned short  WIC_FL_Tick_ui16;
	unsigned short  WIC_RR_Tick_ui16;
	unsigned short  WIC_RL_Tick_ui16;	
} FV_USS_CAN_DATA_Type, * FV_USS_CAN_DATA_Handle;

typedef enum
{
	RadarPwrStsNotValid,
	RadarPwrStsValid,
	RadarPwrStsMax,
 
}E_APA_RadarPwr_Status;

typedef enum
{
	UbattStsNotValid,
	UbattStsValid,
	UbattStsMax,

}E_APA_Ubatt_Status;


typedef enum
{
	PLVOff_MODE_enm,
	PLVSEARCH_MODE_enm, 
}E_APA_WorkingMode_Status;


typedef enum
{
	NOReloadParameter,
	ReloadParameter
}E_APA_RequestReload;

typedef enum
{
	ReParNotfinish,
	ReloadParfinish
}E_APA_ReloadStatus;


typedef enum
{
	PDC_MODE_OFF_enm,
	PDC_MODE_Standby_enm,
	PDC_MODE_ON_enm,
    PDC_MODE_Active_enm,
    PDC_MODE_FrontActiveRearFail_enm, 
	PDC_MODE_RearActiveFrontFail_enm,	
	PDC_MODE_RearFailFrontFail_enm,
    PDC_MODE_MAX_enm
}E_APA_PDCRequestMode;


typedef enum
{
	PDC_Off_enm,
	PDC_Standby_enm,
	PDC_FrontActiveRearOff_enm, 
	PDC_FrontRearActive_enm,
	PDC_FrontOffRearActive_enm,
    PDC_MODE_STATUS_MAX_enm,
}E_APA_PDCMode_Status;


typedef enum
{
    g_NonePSType_enm     = 0,  //�?
    g_ParallelPSType_enm = 1,  //骞宠�?
    g_CrossPSType_enm    = 2  //鍨傜�?
} gType_TypePS_en;

//BSD interface
typedef enum
{
    BsdWorkMode_inActive = 0,
    BsdWorkMode_Active   = 1
} gType_setBsdMode_en;

typedef enum
{
    BsdOperatingMode_off     = 0,
    BsdOperatingMode_failure = 1,
    BsdOperatingMode_on      = 2,
    BsdOperationInhibit      = 3
} gType_getBsdMode_en;

typedef enum
{
    WarningLevel_no       = 0,
    WarningLevel_1        = 1,
    WarningLevel_2        = 2,
    WarningLevel_reserve  = 3

} gType_warningLevel_en;


 typedef struct {
     unsigned char  left_warnLevel;
     unsigned char  right_warnLevel;
} gType_warningInfo_st; 


typedef struct
{
	unsigned char SlotID;
	SInt32 SlotDepth;  /*Unit:mm*/ 
	SInt32 SlotLocationAx;  /*Unit:mm*/
	SInt32 SlotLocationAy;  /*Unit:mm*/
	SInt32 SlotLocationBx;  /*Unit:mm*/
	SInt32 SlotLocationBy;  /*Unit:mm*/
	SInt32 SlotLocationCx;  /*Unit:mm*/
	SInt32 SlotLocationCy;  /*Unit:mm*/
	SInt32 SlotLocationDx;  /*Unit:mm*/
	SInt32 SlotLocationDy;  /*Unit:mm*/
//	SInt16 SlotOrientation; 
	unsigned char	  virtual_ui8;   // 0:real    1: virtual
	unsigned char     Side_en;      // 0:left    1: right 
	unsigned char     PSType_en;	  // 0:none    1:parallel   2:cross
}FV_SlotInformationType;

typedef struct
{
	unsigned short USS_Distance_RRS;/*Unit:mm.长距后右*/
	unsigned short USS_Distance_RR;/*Unit:mm.短距后左*/
	unsigned short USS_Distance_RRM;/*Unit:mm.短距后右*/
	unsigned short USS_Distance_RLM;/*Unit:mm.短距后中�*/
	unsigned short USS_Distance_RL;/*Unit:mm.短距后左*/
	unsigned short USS_Distance_RLS;/*Unit:mm.长距后左*/
	unsigned short USS_Distance_FRS;/*Unit:mm.长距前右*/
	unsigned short USS_Distance_FR;/*Unit:mm.短距前右*/
	unsigned short USS_Distance_FRM;/*Unit:mm.短距前中�*/
	unsigned short USS_Distance_FLM;/*Unit:mm.短距前中�*/
	unsigned short USS_Distance_FL;/*Unit:mm.短距前左*/
	unsigned short USS_Distance_FLS;/*Unit:mm.长距前左*/
}FV_USSDistanceResultStruct;


typedef struct
{
	unsigned short PAS_PDC_DISTANCE_FLS_Zone;
	unsigned short PAS_PDC_DISTANCE_FL_Zone;
	unsigned short PAS_PDC_DISTANCE_FML_Zone;
	unsigned short PAS_PDC_DISTANCE_FMR_Zone;
	unsigned short PAS_PDC_DISTANCE_FR_Zone;
	unsigned short PAS_PDC_DISTANCE_FRS_Zone;
	unsigned short PAS_PDC_DISTANCE_RLS_Zone;
	unsigned short PAS_PDC_DISTANCE_RL_Zone;
	unsigned short PAS_PDC_DISTANCE_RML_Zone;
	unsigned short PAS_PDC_DISTANCE_RMR_Zone;
	unsigned short PAS_PDC_DISTANCE_RR_Zone;
	unsigned short PAS_PDC_DISTANCE_RRS_Zone;
}USS_PDC_Struct; 

typedef union
{
	unsigned short allStatus;
	struct
	{
		unsigned short shortToBattery		:1;
		unsigned short shortToGND		:1;
		unsigned short isBlocked			:1;
		unsigned short ringTimeTooShort	:1;
		
		unsigned short ringTimeTooLong	:1;
		unsigned short signalDisturbed		:1;
		unsigned short signalError			:1;
		unsigned short initFail			:1;

		unsigned short disconnected		:1;
		unsigned short typeIncorrect		:1;
		unsigned short reserve			:6;
	}item;
}FV_diagnosticTypedef;



typedef struct
{	
	FV_USSDistanceResultStruct  USS_DistanceInfo;//雷达探头到障碍物的距�?
 	USS_PDC_Struct   USS_PDC_Info;//PDC报警的扇形区域距离信息。可由FV提供该结构体定义�?
}USS_InfoStruct;

typedef struct 
{
	SInt32 SPosMM_si32;      // 后轴中心点走过的距离  单位mm                              
	SInt32 XPosMM_si32;      // 后轴中心点的全局坐标X 单位mm
	SInt32 YPosMM_si32;      // 后轴中心点的全局坐标Y 单位mm
	UInt32 YawAngle_ui32;     // 车辆的纵向与全局坐标系X的夹�?单位1/2^22 rad，范围（0-2PI�?
}gType_VehPos_st;

typedef enum
{
	NOSearch_enm=0,// 0x0：no slot
	LeftSearch_enm,// 0x1：搜索左侧车�?
	RightSearch_enm,//	0x2：搜索右侧车�?
	LeftRightSearch_enm//	0x3: 搜索双边车位
}USSParkingSlotSearch;

typedef struct
{
    gType_Point_st P1_st;   //障碍物的第一个点的坐标，单位mm
    gType_Point_st P2_st;   //障碍物的第二个点的坐标，单位mm
    UInt16   Dist_ui16;     //单位mm,到保险杠距离
    UInt16 Length_ui16;       //障碍物的长度，如果类型为point，则�?，单位mm
    UInt8 ExistProb_ui8;       //障碍物的出现概率值（0-255�?
    UInt8 HeightProb_ui8;      //障碍物的高度概率值（0-255�?
    gType_ObjectType_en Type_en;           //障碍物的类型
    gType_ObjectHeight_en HeightStatus_en;    //障碍物的可能的高�?
}gType_ObjectMessage_st;

typedef struct 
{
	 unsigned char  BCS_5_A_Timeout;
	 unsigned char  BCS_10_A_Timeout;
	 unsigned char  GW_TCU_1_A_Timeout;
	 unsigned char  BCS_SAS_1_A_Timeout;
	 unsigned char  BCS_9_A_Timeout;
	 unsigned char  BCS_EPB_1_A_Timeout;
	 unsigned char  GW_EMS_1_A_Timeout;
	 unsigned char  BCS_11_A_Timeout;
	 unsigned char  BCS_6_A_Timeout;
	 unsigned char  GW_ICM_HVAC_A_Timeout;
	 unsigned char  GW_BCM_2_A_Timeout;
}Message_TimeOut_Type, *Message_TimeOut_Handle;

// =>  for hongqi Prj
extern gType_ObjectHeight_en  HeightStatus_en;

extern Boolean g_SV_GetRadarControlSwitch_bl(void);
extern void  g_getFVInfo(void);

// =>  for hongqi Prj

Boolean g_SV_adiGetCAN_Data_bl(FV_USS_CAN_DATA_Type *can_signal);
Boolean g_SV_adiSetRadar_PwrCtrl_ON_bl(void);
Boolean g_SV_adiSetRadar_PwrCtrl_OFF_bl(void);
Boolean g_SV_adiGetRadarPwrStatus_bl(E_APA_RadarPwr_Status  *RadarPwr_Status);
Boolean g_SV_adiGetUbattStatus_bl(E_APA_Ubatt_Status  *Ubatt_Status);
unsigned char Get_Message_TimeOut(Message_TimeOut_Handle to_sts);
extern void xprintf (	/* Put a formatted string to the default device */
	  const char* fmt, /* Pointer to the format string */
	  ...	  /* Optional arguments */
	 );

//extern Boolean g_FV_adiGetBSD_Debug_Sig_bl(BSD_Debug_SIG_st *can_signal);
extern Boolean g_FV_adiSetBsdMode_bl(gType_setBsdMode_en f_BsdMode_en);
extern Boolean g_FV_adiGetBsdWorkMode_bl(gType_getBsdMode_en *f_BsdOperatingMode_en);
extern Boolean g_FV_adiGetBsdWarningInfo_bl(gType_warningInfo_st *f_BsdWarningInfo_pst);

extern Boolean g_FV_adiGetUSSInterData_bl(gType_PSLPoint_st *f_PSLPoint_pst,UInt8 *f_num_pui8,UInt8  f_SensorNr_ui8);
extern Boolean g_FV_adiReSetSlotPS_bl(void);
extern Boolean g_FV_adiGetUSSSWVer_bl(UInt8 *f_ver_pui8);
extern UInt16 OSAlarm_GetSystemTime(void);
extern Boolean g_FV_adiSetRadarParCfg_request_bl(E_APA_RequestReload  f_ParReload_en);
extern Boolean g_FV_adiGetUSSReconfigResult_bl(E_APA_ReloadStatus  *f_ParReload_en);
extern Boolean g_FV_adiSetPDCModeStatus_bl(E_APA_PDCMode_Status f_PDCModeStatus_en);
extern Boolean g_FV_adiGetPDCModeBackStatus_bl(E_APA_PDCMode_Status *f_PDCModeStatus_en );
extern Boolean g_FV_adiGetPDCDistance_bl(USS_PDC_Struct *f_distance_st);
extern Boolean g_FV_adiGetUssDistance_bl(FV_USSDistanceResultStruct *f_distance_st);
extern Boolean  g_FV_adiGetOLOObjectData_pst(UInt8 f_NumObj_ui8,gType_ObjectMessage_st *f_OLOObjData_pst);
extern Boolean g_FV_adiSetUSSParkingSlotSearching_bl(USSParkingSlotSearch f_SlotSearch_en);
extern UInt8 g_FV_adiGetSlotPSNum_ui8(gType_Side_en f_side_en);
extern Boolean g_FV_adiGetSlotPS_bl(gType_Side_en side, FV_SlotInformationType  *f_Slot_st,UInt8 f_PSNum_ui8);//第一个参数申请搜车位的方向，第二个参数是FV回的车位信息

extern Boolean g_FV_adiGetVehPosOdo_bl (gType_VehPos_st* f_VehPosOdo_pst);

extern Boolean g_FV_getSnsDiagnosticResult(FV_diagnosticTypedef DiagResult[12]);
extern Boolean g_FV_USS_ALG_version_number(unsigned char version[]);

extern Boolean g_FV_adiReSetSlotPS_bl(void);
extern Boolean g_FV_adiGetGear_bl (gType_Pos_en* f_Gear_pen);
extern Boolean g_FV_adiGetCurbstoneInfo_bl (gTye_CurbstoneInfo_st *f_curbInfo_pst,gType_Side_en f_side_en);
extern Boolean g_FV_adiGetPSLObjectDataInfo_bl (UInt8 f_NumObj_ui8,gTye_SideObjectMessage_st *f_PSLSideObjectMessage_pst,gType_Side_en f_side_en);



extern Boolean g_SV_adiGetCAN_Data_bl(FV_USS_CAN_DATA_Type *can_signal);

////////////////////test ,FV impl
uint8_t ussLibDrvOpen(void);
uint8_t ussLibDrvClose(void);
uint16_t ussLibDrvRead(uint8_t *buff,uint16_t Len);
uint16_t ussLibDrvWrite(uint8_t *buff,uint16_t Len);
uint8_t ussLibIoControl(uint8_t cmd, void *buff); 
uint8_t ussLibDrvPowerControl(uint8_t opCmd);// opCmd:DEV_PWR_OP_TYPE
uint8_t ussLibDrvPowerStatus(void);// return para: DEV_PWR_STATE_TYPE

///////////////////////////////////

void  g_IntervalTimer0_start_vd(void);
void  g_IntervalTimer0_stop_vd(void);
void  g_IntervalTimer0_setValue_vd(uint32_t  f_value_ui32);
void isrIntervalTimer0(void);

void  g_IntervalTimer1_start_vd(void);
void  g_IntervalTimer1_stop_vd(void);
void  g_IntervalTimer1_setValue_vd(uint32_t         f_value_ui32);
void isrIntervalTimer1(void);


////////开关捕获计数的接口
void  g_captureTimer0_start_vd(void);
void  g_captureTimer0_stop_vd(void);
void  g_captureTimer1_start_vd(void);
void  g_captureTimer1_stop_vd(void);
void  g_captureTimer2_start_vd(void);
void  g_captureTimer2_stop_vd(void);
void  g_captureTimer3_start_vd(void);
void  g_captureTimer3_stop_vd(void);
void  g_captureTimer4_start_vd(void);
void  g_captureTimer4_stop_vd(void);
void  g_captureTimer5_start_vd(void);
void  g_captureTimer5_stop_vd(void);


void  g_captureTimer6_start_vd(void);
void  g_captureTimer6_stop_vd(void);
void  g_captureTimer7_start_vd(void);
void  g_captureTimer7_stop_vd(void);
void  g_captureTimer8_start_vd(void);
void  g_captureTimer8_stop_vd(void);
void  g_captureTimer9_start_vd(void);
void  g_captureTimer9_stop_vd(void);
void  g_captureTimer10_start_vd(void);
void  g_captureTimer10_stop_vd(void);
void  g_captureTimer11_start_vd(void);
void  g_captureTimer11_stop_vd(void);
///////////////////////////////////////////////////////////

/////DMA计数的开关接�?
void g_DMAC_0_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_0_Stop_vd (void);
void g_DMAC_1_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_1_Stop_vd (void);
void g_DMAC_2_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_2_Stop_vd (void);
void g_DMAC_3_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_3_Stop_vd (void);
void g_DMAC_4_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_4_Stop_vd (void);
void g_DMAC_5_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_5_Stop_vd (void);
void g_DMAC_6_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_6_Stop_vd (void);
void g_DMAC_7_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_7_Stop_vd (void);
void g_DMAC_8_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_8_Stop_vd (void);
void g_DMAC_9_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_9_Stop_vd (void);
void g_DMAC_10_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_10_Stop_vd (void);
void g_DMAC_11_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32);
void g_DMAC_11_Stop_vd (void);

///设置输出电平+获取输出电平+获取输入电平
void        g_setPortValue_vd_0 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_0(void);
uint8_t     g_getInputValue_0(void);
void        g_setPortValue_vd_1 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_1(void);
uint8_t     g_getInputValue_1(void);
void        g_setPortValue_vd_2 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_2(void);
uint8_t     g_getInputValue_2(void);
void        g_setPortValue_vd_3 (  uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_3(void);
uint8_t     g_getInputValue_3(void);
void        g_setPortValue_vd_4 ( uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_4(void);
uint8_t     g_getInputValue_4(void);
void        g_setPortValue_vd_5 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_5(void);
uint8_t     g_getInputValue_5(void);
void        g_setPortValue_vd_6 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_6(void);
uint8_t     g_getInputValue_6(void);
void        g_setPortValue_vd_7 (  uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_7(void);
uint8_t     g_getInputValue_7(void);
void        g_setPortValue_vd_8 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_8(void);
uint8_t     g_getInputValue_8(void);
void        g_setPortValue_vd_9 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_9(void);
uint8_t     g_getInputValue_9(void);
void        g_setPortValue_vd_10 (  uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_10(void);
uint8_t     g_getInputValue_10(void);
void        g_setPortValue_vd_11 (uint8_t      f_value_ui8);
uint8_t     g_getOutputValue_11(void);
uint8_t     g_getInputValue_11(void);
/////////////////////////////////////


//设置对应GPIO pin脚的模式

void g_setOutputPin_0(void);
void g_setInputPin_0(void);
void g_setOutputPin_1(void);
void g_setInputPin_1(void);
void g_setOutputPin_2(void);
void g_setInputPin_2(void);
void g_setOutputPin_3(void);
void g_setInputPin_3(void);
void g_setOutputPin_4(void);
void g_setInputPin_4(void);
void g_setOutputPin_5(void);
void g_setInputPin_5(void);
void g_setOutputPin_6(void);
void g_setInputPin_6(void);
void g_setOutputPin_7(void);
void g_setInputPin_7(void);
void g_setOutputPin_8(void);
void g_setInputPin_8(void);
void g_setOutputPin_9(void);
void g_setInputPin_9(void);
void g_setOutputPin_10(void);
void g_setInputPin_10(void);
void g_setOutputPin_11(void);
void g_setInputPin_11(void);

// 1ms �?10ms的任务定时器

void ussObjLibRunnable_Bg1ms(void);           // 1ms. 低优先级，用系统剩余资源去跑车位搜索
void ussObjLibRunnable_Main10ms(void);           // 10ms. 高优先级，用来跑距离检�?

#endif


