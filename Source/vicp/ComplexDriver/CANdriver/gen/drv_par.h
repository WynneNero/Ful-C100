/* -----------------------------------------------------------------------------
  Filename:    drv_par.h
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: GenTool_GenyDriverBase
               
               Configuration   : D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\CBD1700979 D00 Rh850 GreenHills FAW C100 APA.gny
               
               ECU: 
                       TargetSystem: Hw_Rh850Cpu
                       Compiler:     GreenHills
                       Derivates:    F1K
               
               Channel "Channel0":
                       Databasefile: D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\AB02_979_C100_APA_PublicCAN_V0.1_20210609.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         APA
               Channel "Channel1":
                       Databasefile: D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\AB02_979_C235_APA_PrivateCAN_V0.4_20210520.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         APA

 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2015 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#if !defined(__DRV_PAR_H__)
#define __DRV_PAR_H__

/* -----------------------------------------------------------------------------
    &&&~ Signal Structures
 ----------------------------------------------------------------------------- */

typedef struct _c_ABS_1_msgTypeTag
{
  vbittype Checksum_ABS_1 : 8;
  vbittype WheelSpeed_FL_0 : 8;
  vbittype WheelSpeed_FL_1 : 7;
  vbittype unused0 : 1;
  vbittype WheelSpeed_FR_0 : 8;
  vbittype WheelSpeed_FR_1 : 7;
  vbittype unused1 : 1;
  vbittype VehicleSpeed_0 : 8;
  vbittype VehicleSpeed_1 : 7;
  vbittype unused2 : 1;
  vbittype DrivingDirection : 2;
  vbittype unused3 : 2;
  vbittype LiveCounter_ABS_1 : 4;
} _c_ABS_1_msgType;
typedef struct _c_HU_5_msgTypeTag
{
  vbittype CheckSum_HU_5 : 8;
  vbittype AVSFunctionReq : 2;
  vbittype AVSViewModeReq : 4;
  vbittype AVSFunctionExitReq : 1;
  vbittype AVSMonitoringVideoModeReq : 1;
  vbittype DynamicPGSReq : 2;
  vbittype MODReq : 2;
  vbittype LanguageSet : 4;
  vbittype SwitchScreenResponse_AVS : 2;
  vbittype unused0 : 6;
  vbittype AVSTurnFollowUpFunctionReq : 2;
  vbittype unused1 : 6;
  vbittype unused2 : 8;
  vbittype AVSViewtypeReq : 2;
  vbittype unused3 : 6;
  vbittype unused4 : 4;
  vbittype LiveCounter_HU_5 : 4;
} _c_HU_5_msgType;
typedef struct _c_TCU_3_msgTypeTag
{
  vbittype Checksum_TCU_3 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype LeverInfo : 4;
  vbittype LiveCounter_TCU_3 : 4;
} _c_TCU_3_msgType;
typedef struct _c_SAS_1_msgTypeTag
{
  vbittype Checksum_SAS_1 : 8;
  vbittype SteeringWheelAngle_0 : 8;
  vbittype SteeringWheelAngle_1 : 7;
  vbittype SteeringWheelAngleSign : 1;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype SAS_St : 2;
  vbittype unused4 : 2;
  vbittype LiveCounter_SAS_1 : 4;
} _c_SAS_1_msgType;
typedef struct _c_PDC_1_msgTypeTag
{
  vbittype SysSt_PDC : 1;
  vbittype ErrorSt_PDC : 1;
  vbittype RadarSysSt_Front : 1;
  vbittype RadarSysSt_Rear : 1;
  vbittype unused0 : 1;
  vbittype BuzeerCmd_PDC : 3;
  vbittype BuzzerAlarmPosition : 3;
  vbittype RadarSysSt_FrontSide : 1;
  vbittype RadarSysSt_RearSide : 1;
  vbittype BuzzerSwitchSt : 1;
  vbittype unused1 : 2;
  vbittype ObjectRange_RR : 3;
  vbittype SensorErrorSt_RR : 1;
  vbittype ObjectRange_RMR : 3;
  vbittype SensorErrorSt_RMR : 1;
  vbittype ObjectRange_RML : 3;
  vbittype SensorErrorSt_RML : 1;
  vbittype ObjectRange_RL : 3;
  vbittype SensorErrorSt_RL : 1;
  vbittype ObjectRange_FR : 3;
  vbittype SensorErrorSt_FR : 1;
  vbittype ObjectRange_FMR : 3;
  vbittype SensorErrorSt_FMR : 1;
  vbittype ObjectRange_FML : 3;
  vbittype SensorErrorSt_FML : 1;
  vbittype ObjectRange_FL : 3;
  vbittype SensorErrorSt_FL : 1;
  vbittype unused2 : 5;
  vbittype PDCAutoOnFunctionInd : 1;
  vbittype SwitchScreenRequest_PDC : 2;
  vbittype PDC_SpeechControlFeedback : 3;
  vbittype PDC_SearchingSlotPosition : 2;
  vbittype PDC_FunctionTip : 3;
} _c_PDC_1_msgType;
typedef struct _c_EMS_3_msgTypeTag
{
  vbittype Checksum_EMS_3 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 3;
  vbittype BrakePedalSt : 2;
  vbittype unused4 : 3;
  vbittype unused5 : 8;
  vbittype unused6 : 8;
  vbittype unused7 : 4;
  vbittype LiveCounter_EMS_3 : 4;
} _c_EMS_3_msgType;
typedef struct _c_HU_Speech_1_msgTypeTag
{
  vbittype Checksum_HU_Speech_1 : 8;
  vbittype unused0 : 6;
  vbittype HU_SpeechReq_AVS : 2;
  vbittype HU_SpeechReq_AVSViewMode : 2;
  vbittype unused1 : 2;
  vbittype HU_SpeechReq_PDC : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype unused6 : 8;
  vbittype unused7 : 4;
  vbittype LiveCounter_HU_Speech_1 : 4;
} _c_HU_Speech_1_msgType;
typedef struct _c_ABS_2_msgTypeTag
{
  vbittype Checksum_ABS_2 : 8;
  vbittype WheelSpeed_RL_0 : 8;
  vbittype WheelSpeed_RL_1 : 7;
  vbittype unused0 : 1;
  vbittype WheelSpeed_RR_0 : 8;
  vbittype WheelSpeed_RR_1 : 7;
  vbittype unused1 : 1;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 4;
  vbittype LiveCounter_ABS_2 : 4;
} _c_ABS_2_msgType;
typedef struct _c_BCM1_2_msgTypeTag
{
  vbittype unused0 : 4;
  vbittype PowerMode : 4;
} _c_BCM1_2_msgType;
typedef struct _c_AVM_NM_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype Wakeup_reason : 8;
  vbittype Stay_awake_reason : 8;
  vbittype Extension_information : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
} _c_AVM_NM_msgType;
typedef struct _c_ADV_1_msgTypeTag
{
  vbittype Checksum_ADV_1 : 8;
  vbittype ADV_ParkType : 3;
  vbittype ADV_ParkInSlotSearchMode : 1;
  vbittype ADV_ParkStatus : 4;
  vbittype unused0 : 5;
  vbittype ADV_ParkOutDirection : 3;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype ADV_FunctionAbnormalTip : 6;
  vbittype unused3 : 2;
  vbittype unused4 : 8;
  vbittype unused5 : 4;
  vbittype LiveCounter_ADV_1 : 4;
} _c_ADV_1_msgType;
typedef struct _c_PDC_2_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype SensorBlockageSt_RR : 1;
  vbittype SensorBlockageSt_RMR : 1;
  vbittype SensorBlockageSt_RML : 1;
  vbittype SensorBlockageSt_RL : 1;
  vbittype SensorBlockageSt_FR : 1;
  vbittype SensorBlockageSt_FMR : 1;
  vbittype SensorBlockageSt_FML : 1;
  vbittype SensorBlockageSt_FL : 1;
  vbittype unused1 : 2;
  vbittype SensorBlockageSt_FLS : 1;
  vbittype SensorBlockageSt_FRS : 1;
  vbittype SensorBlockageSt_RLS : 1;
  vbittype SensorBlockageSt_RRS : 1;
  vbittype unused2 : 2;
  vbittype ObjectRange_FLS : 3;
  vbittype SensorErrorSt_FLS : 1;
  vbittype ObjectRange_FRS : 3;
  vbittype SensorErrorSt_FRS : 1;
  vbittype ObjectRange_RLS : 3;
  vbittype SensorErrorSt_RLS : 1;
  vbittype ObjectRange_RRS : 3;
  vbittype SensorErrorSt_RRS : 1;
  vbittype ParkingSlotDegree_Left_0 : 8;
  vbittype ParkingSlotDegree_Left_1 : 4;
  vbittype ParkingSlotDegree_Right_0 : 4;
  vbittype ParkingSlotDegree_Right_1 : 8;
} _c_PDC_2_msgType;
typedef struct _c_APS_Slot6_msgTypeTag
{
  vbittype APS_Slot6CenterPoint_X1_0 : 8;
  vbittype APS_Slot6CenterPoint_X1_1 : 3;
  vbittype APS_Slot6CenterPoint_Y1_0 : 5;
  vbittype APS_Slot6CenterPoint_Y1_1 : 6;
  vbittype APS_Slot6_LineAngle_0 : 2;
  vbittype APS_Slot6_LineAngle_1 : 8;
  vbittype APS_Slot6_Length_0 : 8;
  vbittype APS_Slot6_Length_1 : 2;
  vbittype APS_Slot6_Width_0 : 6;
  vbittype APS_Slot6_Width_1 : 4;
  vbittype APS_Slot6CenterPoint_Angle_0 : 4;
  vbittype APS_Slot6CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot6_msgType;
typedef struct _c_APS_Slot5_msgTypeTag
{
  vbittype APS_Slot5CenterPoint_X1_0 : 8;
  vbittype APS_Slot5CenterPoint_X1_1 : 3;
  vbittype APS_Slot5CenterPoint_Y1_0 : 5;
  vbittype APS_Slot5CenterPoint_Y1_1 : 6;
  vbittype APS_Slot5_LineAngle_0 : 2;
  vbittype APS_Slot5_LineAngle_1 : 8;
  vbittype APS_Slot5_Length_0 : 8;
  vbittype APS_Slot5_Length_1 : 2;
  vbittype APS_Slot5_Width_0 : 6;
  vbittype APS_Slot5_Width_1 : 4;
  vbittype APS_Slot5CenterPoint_Angle_0 : 4;
  vbittype APS_Slot5CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot5_msgType;
typedef struct _c_APS_Slot4_msgTypeTag
{
  vbittype APS_Slot4CenterPoint_X1_0 : 8;
  vbittype APS_Slot4CenterPoint_X1_1 : 3;
  vbittype APS_Slot4CenterPoint_Y1_0 : 5;
  vbittype APS_Slot4CenterPoint_Y1_1 : 6;
  vbittype APS_Slot4_LineAngle_0 : 2;
  vbittype APS_Slot4_LineAngle_1 : 8;
  vbittype APS_Slot4_Length_0 : 8;
  vbittype APS_Slot4_Length_1 : 2;
  vbittype APS_Slot4_Width_0 : 6;
  vbittype APS_Slot4_Width_1 : 4;
  vbittype APS_Slot4CenterPoint_Angle_0 : 4;
  vbittype APS_Slot4CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot4_msgType;
typedef struct _c_APS_Slot3_msgTypeTag
{
  vbittype APS_Slot3CenterPoint_X1_0 : 8;
  vbittype APS_Slot3CenterPoint_X1_1 : 3;
  vbittype APS_Slot3CenterPoint_Y1_0 : 5;
  vbittype APS_Slot3CenterPoint_Y1_1 : 6;
  vbittype APS_Slot3_LineAngle_0 : 2;
  vbittype APS_Slot3_LineAngle_1 : 8;
  vbittype APS_Slot3_Length_0 : 8;
  vbittype APS_Slot3_Length_1 : 2;
  vbittype APS_Slot3_Width_0 : 6;
  vbittype APS_Slot3_Width_1 : 4;
  vbittype APS_Slot3CenterPoint_Angle_0 : 4;
  vbittype APS_Slot3CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot3_msgType;
typedef struct _c_APS_Slot2_msgTypeTag
{
  vbittype APS_Slot2CenterPoint_X1_0 : 8;
  vbittype APS_Slot2CenterPoint_X1_1 : 3;
  vbittype APS_Slot2CenterPoint_Y1_0 : 5;
  vbittype APS_Slot2CenterPoint_Y1_1 : 6;
  vbittype APS_Slot2_LineAngle_0 : 2;
  vbittype APS_Slot2_LineAngle_1 : 8;
  vbittype APS_Slot2_Length_0 : 8;
  vbittype APS_Slot2_Length_1 : 2;
  vbittype APS_Slot2_Width_0 : 6;
  vbittype APS_Slot2_Width_1 : 4;
  vbittype APS_Slot2CenterPoint_Angle_0 : 4;
  vbittype APS_Slot2CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot2_msgType;
typedef struct _c_APS_Slot1_msgTypeTag
{
  vbittype APS_Slot1CenterPoint_X1_0 : 8;
  vbittype APS_Slot1CenterPoint_X1_1 : 3;
  vbittype APS_Slot1CenterPoint_Y1_0 : 5;
  vbittype APS_Slot1CenterPoint_Y1_1 : 6;
  vbittype APS_Slot1_LineAngle_0 : 2;
  vbittype APS_Slot1_LineAngle_1 : 8;
  vbittype APS_Slot1_Length_0 : 8;
  vbittype APS_Slot1_Length_1 : 2;
  vbittype APS_Slot1_Width_0 : 6;
  vbittype APS_Slot1_Width_1 : 4;
  vbittype APS_Slot1CenterPoint_Angle_0 : 4;
  vbittype APS_Slot1CenterPoint_Angle_1 : 7;
  vbittype unused0 : 1;
} _c_APS_Slot1_msgType;
typedef struct _c_APS_PSD_msgTypeTag
{
  vbittype APS_Slot1_DetectStatus : 2;
  vbittype APS_Slot1_Info : 2;
  vbittype APS_Slot1_ParkType : 2;
  vbittype APS_Slot1_ParkDirection : 1;
  vbittype unused0 : 1;
  vbittype APS_Slot2_DetectStatus : 2;
  vbittype APS_Slot2_Info : 2;
  vbittype APS_Slot2_ParkType : 2;
  vbittype APS_Slot2_ParkDirection : 1;
  vbittype unused1 : 1;
  vbittype APS_Slot3_DetectStatus : 2;
  vbittype APS_Slot3_Info : 2;
  vbittype APS_Slot3_ParkType : 2;
  vbittype APS_Slot3_ParkDirection : 1;
  vbittype unused2 : 1;
  vbittype APS_Slot4_DetectStatus : 2;
  vbittype APS_Slot4_Info : 2;
  vbittype APS_Slot4_ParkType : 2;
  vbittype APS_Slot4_ParkDirection : 1;
  vbittype unused3 : 1;
  vbittype APS_Slot5_DetectStatus : 2;
  vbittype APS_Slot5_Info : 2;
  vbittype APS_Slot5_ParkType : 2;
  vbittype APS_Slot5_ParkDirection : 1;
  vbittype unused4 : 1;
  vbittype APS_Slot6_DetectStatus : 2;
  vbittype APS_Slot6_Info : 2;
  vbittype APS_Slot6_ParkType : 2;
  vbittype APS_Slot6_ParkDirection : 1;
  vbittype unused5 : 1;
  vbittype APS_Slot1_BothSidesInfo : 2;
  vbittype APS_Slot2_BothSidesInfo : 2;
  vbittype APS_Slot3_BothSidesInfo : 2;
  vbittype APS_Slot4_BothSidesInfo : 2;
  vbittype APS_Slot5_BothSidesInfo : 2;
  vbittype APS_Slot6_BothSidesInfo : 2;
  vbittype unused6 : 3;
  vbittype APS_ParkingSlotAvailability : 1;
} _c_APS_PSD_msgType;
typedef struct _c_PLG_1_msgTypeTag
{
  vbittype LuggageDoorSt : 1;
  vbittype unused0 : 7;
} _c_PLG_1_msgType;
typedef struct _c_PDCU_1_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_FR : 1;
  vbittype unused1 : 5;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 2;
  vbittype MirrorFoldSt_FR : 2;
  vbittype unused6 : 4;
} _c_PDCU_1_msgType;
typedef struct _c_IC_1_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype OdometerValue_0 : 8;
  vbittype OdometerValue_1 : 8;
  vbittype OdometerValue_2 : 8;
  vbittype OdometerValue_3 : 1;
  vbittype unused3 : 7;
} _c_IC_1_msgType;
typedef struct _c_ESC_3_msgTypeTag
{
  vbittype Checksum_ESC_3 : 8;
  vbittype YawRate_0 : 8;
  vbittype YawRate_1 : 4;
  vbittype YRSSt : 1;
  vbittype Acceleration_X_0 : 3;
  vbittype Acceleration_X_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype Acceleration_Y_0 : 8;
  vbittype Acceleration_Y_1 : 3;
  vbittype ErrorSt_YRS : 1;
  vbittype LiveCounter_ESC_3 : 4;
} _c_ESC_3_msgType;
typedef struct _c_ESC_2_msgTypeTag
{
  vbittype Checksum_ESC_2 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype WorkingSt_EPB : 2;
  vbittype unused5 : 6;
  vbittype unused6 : 4;
  vbittype LiveCounter_ESC_2 : 4;
} _c_ESC_2_msgType;
typedef struct _c_DDCU_1_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_FL : 1;
  vbittype unused1 : 5;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 2;
  vbittype MirrorFoldSt_FL : 2;
  vbittype unused6 : 4;
} _c_DDCU_1_msgType;
typedef struct _c_BCM1_1_msgTypeTag
{
  vbittype unused0 : 7;
  vbittype LowBeamSt_FL : 1;
  vbittype LowBeamSt_FR : 1;
  vbittype unused1 : 1;
  vbittype HighBeamSt_FL : 1;
  vbittype HighBeamSt_FR : 1;
  vbittype AutoLightMode : 1;
  vbittype unused2 : 1;
  vbittype FogLightSt_FL : 1;
  vbittype FogLightSt_FR : 1;
  vbittype TurningSt_Left : 1;
  vbittype TurningSt_right : 1;
  vbittype unused3 : 4;
  vbittype HazardWarningSt : 1;
  vbittype unused4 : 1;
  vbittype unused5 : 8;
  vbittype unused6 : 5;
  vbittype WiperSt_Front : 3;
} _c_BCM1_1_msgType;
typedef struct _c_ATC_2_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype AmbientTemp : 8;
} _c_ATC_2_msgType;
typedef struct _c_HU_6_msgTypeTag
{
  vbittype TargetSelectionCenter_X_0 : 8;
  vbittype TargetSelectionCenter_X_1 : 3;
  vbittype TargetSelection_Area : 1;
  vbittype TargetSelectionCenter_Y_0 : 4;
  vbittype TargetSelectionCenter_Y_1 : 7;
  vbittype unused0 : 1;
  vbittype TargetSelectionCenter_Angle_0 : 8;
  vbittype TargetSelectionCenter_Angle_1 : 2;
  vbittype unused1 : 1;
  vbittype TargetSelection_ParkType : 3;
  vbittype TargetSelection_ParkDirection : 2;
  vbittype TargetSelection_LineAngle_0 : 8;
  vbittype TargetSelection_LineAngle_1 : 2;
  vbittype TargetSelection_ConfirmReq : 1;
  vbittype unused2 : 3;
  vbittype ParkInSlotSearchModeSet : 2;
  vbittype ParkOutDirection : 4;
  vbittype unused3 : 4;
} _c_HU_6_msgType;
typedef struct _c_GPS_1_msgTypeTag
{
  vbittype GPSTime_Hour : 5;
  vbittype unused0 : 3;
  vbittype GPSTime_Minute : 6;
  vbittype unused1 : 2;
  vbittype GPSTime_Second : 6;
  vbittype unused2 : 2;
  vbittype GPSTime_Year : 7;
  vbittype unused3 : 1;
  vbittype GPSTime_Month : 4;
  vbittype unused4 : 4;
  vbittype GPSTime_Day : 7;
  vbittype unused5 : 1;
} _c_GPS_1_msgType;
typedef struct _c_ABS_3_msgTypeTag
{
  vbittype Checksum_ABS_3 : 8;
  vbittype WheelPulse_FL : 8;
  vbittype WheelPulse_FR : 8;
  vbittype WheelPulse_RL : 8;
  vbittype WheelPulse_RR : 8;
  vbittype WheelSpeedDirection_FL : 2;
  vbittype WheelSpeedDirection_FR : 2;
  vbittype WheelSpeedDirection_RL : 2;
  vbittype WheelSpeedDirection_RR : 2;
  vbittype unused0 : 8;
  vbittype unused1 : 4;
  vbittype LiveCounter_ABS_3 : 4;
} _c_ABS_3_msgType;
typedef struct _c_AVS_1_msgTypeTag
{
  vbittype AVSSt : 1;
  vbittype AVSErrorSt : 1;
  vbittype AVSViewMode : 4;
  vbittype AVSViewtype : 2;
  vbittype AVSCameraErrorSt_Front : 1;
  vbittype AVSCameraErrorSt_Rear : 1;
  vbittype AVSCameraErrorSt_Left : 1;
  vbittype AVSCameraErrorSt_Right : 1;
  vbittype LanguageTypeSt_AVS : 4;
  vbittype DynamicPGSSt_AVS : 1;
  vbittype MODSt_AVS : 1;
  vbittype MODWarning_Front : 1;
  vbittype MODWarning_Rear : 1;
  vbittype AVSTurnLightFollowupFunctionSt : 1;
  vbittype unused0 : 3;
  vbittype SwitchScreenRequest_AVS : 2;
  vbittype BlindSpotFilledFunctionInd : 1;
  vbittype FoundSlotBuzzerTip : 1;
  vbittype unused1 : 4;
  vbittype AVS_SpeechControlFeedback : 5;
  vbittype AVSCameraBlockageSt_Front : 1;
  vbittype AVSCameraBlockageSt_Rear : 1;
  vbittype AVSCameraBlockageSt_Left : 1;
  vbittype AVSCameraBlockageSt_Right : 1;
  vbittype AVS_AbnormalTip : 3;
  vbittype AVS_CalibrationSt : 2;
  vbittype AVS_PDWarning_Front : 1;
  vbittype AVS_PDWarning_Rear : 1;
  vbittype AVS_RemoteMonitorigFeedback : 3;
  vbittype AVS_RemoteSharpnessFeedback : 3;
  vbittype RemoteMonitoringSharpnessSt_AVS : 1;
  vbittype RemoteMonitoringSt_AVS : 1;
  vbittype RemoteMonitoringModeSt_AVS : 1;
  vbittype TurnFollowUpFunctionInd : 1;
  vbittype unused2 : 1;
  vbittype AVS_RemoteViewModeFeedback : 5;
} _c_AVS_1_msgType;
typedef struct _c_Debug_ReloatInfo_msgTypeTag
{
  vbittype Debug_ReloatDistance_R_0 : 8;
  vbittype Debug_ReloatDistance_R_1 : 8;
  vbittype Debug_ReloatTheta_R_0 : 8;
  vbittype Debug_ReloatTheta_R_1 : 5;
  vbittype Debug_ReloatValid_R : 3;
  vbittype Debug_ReloatDistance_L_0 : 8;
  vbittype Debug_ReloatDistance_L_1 : 8;
  vbittype Debug_ReloatTheta_L_0 : 8;
  vbittype Debug_ReloatTheta_L_1 : 5;
  vbittype Debug_ReloatValid_L : 3;
} _c_Debug_ReloatInfo_msgType;
typedef struct _c_Debug_CanStaInfo_msgTypeTag
{
  vbittype PrivateCanSta : 8;
  vbittype PubuicCanSta : 8;
  vbittype CanTaskAlive_0 : 8;
  vbittype CanTaskAlive_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
} _c_Debug_CanStaInfo_msgType;
typedef struct _c_ADV_TargetTracing_msgTypeTag
{
  vbittype ADV_TargetTracingCenter_X_0 : 8;
  vbittype ADV_TargetTracingCenter_X_1 : 3;
  vbittype unused0 : 1;
  vbittype ADV_TargetTracingCenter_Y_0 : 4;
  vbittype ADV_TargetTracingCenter_Y_1 : 7;
  vbittype unused1 : 1;
  vbittype ADV_TargetTracingAngle_0 : 8;
  vbittype ADV_TargetTracingAngle_1 : 2;
  vbittype unused2 : 1;
  vbittype ADV_TargetTracingLength_0 : 5;
  vbittype ADV_TargetTracingLength_1 : 6;
  vbittype unused3 : 2;
  vbittype ADV_TargetTracingWidth_0 : 8;
  vbittype ADV_TargetTracingWidth_1 : 3;
  vbittype ADV_DebugEnabled : 1;
  vbittype ADV_TargetTracingAvaialble : 1;
  vbittype unused4 : 3;
} _c_ADV_TargetTracing_msgType;
typedef struct _c_ADV_PathTracing_msgTypeTag
{
  vbittype ADV_PathTracingCenter_X_0 : 8;
  vbittype ADV_PathTracingCenter_X_1 : 3;
  vbittype unused0 : 1;
  vbittype ADV_PathTracingCenter_Y_0 : 4;
  vbittype ADV_PathTracingCenter_Y_1 : 7;
  vbittype unused1 : 1;
  vbittype ADV_PathTracingAngle_0 : 8;
  vbittype ADV_PathTracingAngle_1 : 2;
  vbittype unused2 : 1;
  vbittype ADV_PathTracingAvaialble : 1;
  vbittype unused3 : 4;
  vbittype ADV_ShortestDistance : 8;
  vbittype ADV_TotalPathNumber : 4;
  vbittype ADV_CurrentPathNumber : 4;
  vbittype ADV_CurrentDirection : 1;
  vbittype ADV_RemainingDistance : 7;
} _c_ADV_PathTracing_msgType;
typedef struct _c_ADV_4_msgTypeTag
{
  vbittype Checksum_ADV_4 : 8;
  vbittype unused0 : 4;
  vbittype ADV_LeftSlotSearchType : 2;
  vbittype ADV_RightSlotSearchType : 2;
  vbittype ADV_PDCSchedule : 2;
  vbittype ADV_Alarm_Position_Front_Left : 2;
  vbittype unused1 : 4;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype ADV_SearchTimeoutCounter : 6;
  vbittype ADV_Alarm_Position_Front_Right : 2;
  vbittype unused4 : 8;
  vbittype ADV_Alarm_Position_Rear_Left : 2;
  vbittype ADV_Alarm_Position_Rear_Right : 2;
  vbittype LiveCounter_ADV_4 : 4;
} _c_ADV_4_msgType;
typedef struct _c_TBOX_1_msgTypeTag
{
  vbittype CheckSum_TBOX_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype RemoteMonitoringReq : 2;
  vbittype unused5 : 3;
  vbittype RemoteAVSSharpnessReq : 2;
  vbittype unused6 : 1;
  vbittype RemoteAVSViewModeReq : 4;
  vbittype LiveCounter_TBOX_1 : 4;
} _c_TBOX_1_msgType;
typedef struct _c_RRDCU_1_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_RR : 1;
  vbittype unused1 : 5;
} _c_RRDCU_1_msgType;
typedef struct _c_RLDCU_1_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_RL : 1;
  vbittype unused1 : 5;
} _c_RLDCU_1_msgType;
typedef struct _c_MCP_1_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 1;
  vbittype MCP_AVSandFRadarSwitch : 1;
  vbittype unused4 : 6;
} _c_MCP_1_msgType;
typedef struct _c_HU_18_msgTypeTag
{
  vbittype Checksum_HU_18 : 8;
  vbittype HU_BlindSpotFilledFunctionReq : 2;
  vbittype unused0 : 6;
  vbittype unused1 : 2;
  vbittype HU_PDCAutoOnFunctionReq : 2;
  vbittype unused2 : 4;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype unused6 : 8;
  vbittype unused7 : 4;
  vbittype LiveCounter_HU_18 : 4;
} _c_HU_18_msgType;
typedef struct _c_HU_14_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype DisplayTheme : 3;
  vbittype unused3 : 5;
} _c_HU_14_msgType;
typedef struct _c_HU_10_msgTypeTag
{
  vbittype Checksum_HU_10 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 6;
  vbittype HU_PDCBuzzerReq : 2;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype unused6 : 4;
  vbittype LiveCounter_HU_10 : 4;
} _c_HU_10_msgType;
typedef struct _c_GW_Config_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 4;
  vbittype GW_RemoteVehicleMode : 1;
  vbittype unused2 : 3;
  vbittype GW_OTAMode : 3;
  vbittype unused3 : 5;
} _c_GW_Config_msgType;
typedef struct _c_DMS_2_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype DMS_VehicleModeinfo : 4;
  vbittype unused1 : 4;
} _c_DMS_2_msgType;
typedef struct _c_BCM1_7_msgTypeTag
{
  vbittype Rainlntensity : 4;
  vbittype unused0 : 4;
  vbittype Brightness_L : 8;
  vbittype Brightness_H_0 : 8;
  vbittype Brightness_H_1 : 2;
  vbittype unused1 : 6;
} _c_BCM1_7_msgType;
typedef struct _c_BCM1_3_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 4;
  vbittype EngineHoodSt : 1;
  vbittype unused2 : 3;
} _c_BCM1_3_msgType;
typedef struct _c_PDC_9_msgTypeTag
{
  vbittype Checksum_PDC_9 : 8;
  vbittype DistanceValue_FLS_0 : 8;
  vbittype DistanceValue_FLS_1 : 2;
  vbittype unused0 : 4;
  vbittype DistanceValue_FRS_0 : 2;
  vbittype DistanceValue_FRS_1 : 8;
  vbittype TimeStamp_FLS_FRS_0 : 8;
  vbittype TimeStamp_FLS_FRS_1 : 8;
  vbittype ParkingSoltDepth_Left_0 : 8;
  vbittype ParkingSoltDepth_Left_1 : 2;
  vbittype unused1 : 2;
  vbittype LiveCounter_PDC_9 : 4;
} _c_PDC_9_msgType;
typedef struct _c_PDC_8_msgTypeTag
{
  vbittype Checksum_PDC_8 : 8;
  vbittype DistanceValue_RR_0 : 8;
  vbittype DistanceValue_RR_1 : 2;
  vbittype unused0 : 4;
  vbittype DistanceValue_RMR_0 : 2;
  vbittype DistanceValue_RMR_1 : 8;
  vbittype TimeStamp_RMR_RR_0 : 8;
  vbittype TimeStamp_RMR_RR_1 : 8;
  vbittype TxRxSt_RR : 2;
  vbittype TxRxSt_RMR : 2;
  vbittype unused1 : 4;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_8 : 4;
} _c_PDC_8_msgType;
typedef struct _c_PDC_7_msgTypeTag
{
  vbittype Checksum_PDC_7 : 8;
  vbittype DisstanceValue_RL_0 : 8;
  vbittype DisstanceValue_RL_1 : 2;
  vbittype unused0 : 4;
  vbittype DisstanceValue_RML_0 : 2;
  vbittype DisstanceValue_RML_1 : 8;
  vbittype TimeStamp_RML_RL_0 : 8;
  vbittype TimeStamp_RML_RL_1 : 8;
  vbittype TxRxSt_RL : 2;
  vbittype TxRxSt_RML : 2;
  vbittype unused1 : 4;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_7 : 4;
} _c_PDC_7_msgType;
typedef struct _c_PDC_6_msgTypeTag
{
  vbittype Checksum_PDC_6 : 8;
  vbittype DistanceValue_FR_0 : 8;
  vbittype DistanceValue_FR_1 : 2;
  vbittype unused0 : 4;
  vbittype DistanceValue_FMR_0 : 2;
  vbittype DistanceValue_FMR_1 : 8;
  vbittype TimeStamp_FMR_FR_0 : 8;
  vbittype TimeStamp_FMR_FR_1 : 8;
  vbittype TxRxSt_FR : 2;
  vbittype TxRxSt_FMR : 2;
  vbittype unused1 : 4;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_6 : 4;
} _c_PDC_6_msgType;
typedef struct _c_PDC_5_msgTypeTag
{
  vbittype Checksum_PDC_5 : 8;
  vbittype DistanceValue_FL_0 : 8;
  vbittype DistanceValue_FL_1 : 2;
  vbittype unused0 : 4;
  vbittype DistanceValue_FML_0 : 2;
  vbittype DistanceValue_FML_1 : 8;
  vbittype TimeStamp_FML_FL_0 : 8;
  vbittype TimeStamp_FML_FL_1 : 8;
  vbittype TxRxSt_FL : 2;
  vbittype TxRxSt_FML : 2;
  vbittype unused1 : 4;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_5 : 4;
} _c_PDC_5_msgType;
typedef struct _c_PDC_4_msgTypeTag
{
  vbittype Checksum_PDC_4 : 8;
  vbittype FrontObjCoordinateY_0 : 8;
  vbittype FrontObjCoordinateY_1 : 4;
  vbittype FrontObjCoordinateX_0 : 4;
  vbittype FrontObjCoordinateX_1 : 8;
  vbittype RearObjCoordinateY_0 : 8;
  vbittype RearObjCoordinateY_1 : 4;
  vbittype RearObjCoordinateX_0 : 4;
  vbittype RearObjCoordinateX_1 : 8;
  vbittype unused0 : 4;
  vbittype LiveCounter_PDC_4 : 4;
} _c_PDC_4_msgType;
typedef struct _c_PDC_3_msgTypeTag
{
  vbittype Checksum_PDC_3 : 8;
  vbittype ACoordinateY_Left_0 : 8;
  vbittype ACoordinateY_Left_1 : 2;
  vbittype unused0 : 2;
  vbittype ACoordinateX_Left_0 : 4;
  vbittype ACoordinateX_Left_1 : 8;
  vbittype BCoordinateY_Left_0 : 8;
  vbittype BCoordinateY_Left_1 : 2;
  vbittype unused1 : 2;
  vbittype BCoordinateX_Left_0 : 4;
  vbittype BCoordinateX_Left_1 : 8;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_3 : 4;
} _c_PDC_3_msgType;
typedef struct _c_PDC_14_msgTypeTag
{
  vbittype Checksum_PDC_14 : 8;
  vbittype VehicleCoordinateX_0 : 8;
  vbittype VehicleCoordinateX_1 : 5;
  vbittype unused0 : 3;
  vbittype VehicleCoordinateY_0 : 8;
  vbittype VehicleCoordinateY_1 : 4;
  vbittype unused1 : 4;
  vbittype VehicleAngle : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 4;
  vbittype LiveCounter_PDC_14 : 4;
} _c_PDC_14_msgType;
typedef struct _c_PDC_13_msgTypeTag
{
  vbittype Checksum_PDC_13 : 8;
  vbittype CCoordinateY_Right_0 : 8;
  vbittype CCoordinateY_Right_1 : 2;
  vbittype unused0 : 2;
  vbittype CCoordinateX_Right_0 : 4;
  vbittype CCoordinateX_Right_1 : 8;
  vbittype DCoordinateY_Right_0 : 8;
  vbittype DCoordinateY_Right_1 : 2;
  vbittype unused1 : 2;
  vbittype DCoordinateX_Right_0 : 4;
  vbittype DCoordinateX_Right_1 : 8;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_13 : 4;
} _c_PDC_13_msgType;
typedef struct _c_PDC_12_msgTypeTag
{
  vbittype Checksum_PDC_12 : 8;
  vbittype ACoordinateY_Right_0 : 8;
  vbittype ACoordinateY_Right_1 : 2;
  vbittype unused0 : 2;
  vbittype ACoordinateX_Right_0 : 4;
  vbittype ACoordinateX_Right_1 : 8;
  vbittype BCoordinateY_Right_0 : 8;
  vbittype BCoordinateY_Right_1 : 2;
  vbittype unused1 : 2;
  vbittype BCoordinateX_Right_0 : 4;
  vbittype BCoordinateX_Right_1 : 8;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_12 : 4;
} _c_PDC_12_msgType;
typedef struct _c_PDC_11_msgTypeTag
{
  vbittype Checksum_PDC_11 : 8;
  vbittype CCoordinateY_Left_0 : 8;
  vbittype CCoordinateY_Left_1 : 2;
  vbittype unused0 : 2;
  vbittype CCoordinateX_Left_0 : 4;
  vbittype CCoordinateX_Left_1 : 8;
  vbittype DCoordinateY_Left_0 : 8;
  vbittype DCoordinateY_Left_1 : 2;
  vbittype unused1 : 2;
  vbittype DCoordinateX_Left_0 : 4;
  vbittype DCoordinateX_Left_1 : 8;
  vbittype unused2 : 4;
  vbittype LiveCounter_PDC_11 : 4;
} _c_PDC_11_msgType;
typedef struct _c_PDC_10_msgTypeTag
{
  vbittype Checksum_PDC_10 : 8;
  vbittype DistanceValue_RLS_0 : 8;
  vbittype DistanceValue_RLS_1 : 2;
  vbittype unused0 : 4;
  vbittype DistanceValue_RRS_0 : 2;
  vbittype DistanceValue_RRS_1 : 8;
  vbittype TimeStamp_RLS_RRS_0 : 8;
  vbittype TimeStamp_RLS_RRS_1 : 8;
  vbittype ParkingSlotDepth_Right_0 : 8;
  vbittype ParkingSlotDepth_Right_1 : 2;
  vbittype unused1 : 2;
  vbittype LiveCounter_PDC_10 : 4;
} _c_PDC_10_msgType;
typedef struct _c_HU_20_msgTypeTag
{
  vbittype ScreenPressPosition_X1_0 : 8;
  vbittype ScreenPressPosition_X1_1 : 4;
  vbittype ScreenPressPosition_Y1_0 : 4;
  vbittype ScreenPressPosition_Y1_1 : 8;
  vbittype ScreenPressPosition_X2_0 : 8;
  vbittype ScreenPressPosition_X2_1 : 4;
  vbittype ScreenPressPosition_Y2_0 : 4;
  vbittype ScreenPressPosition_Y2_1 : 8;
  vbittype ScreenPressType1 : 2;
  vbittype ScreenPressType2 : 2;
  vbittype unused0 : 4;
} _c_HU_20_msgType;
typedef struct _c_TargetSlot_AB_msgTypeTag
{
  vbittype TargetSlot_Ax_0 : 8;
  vbittype TargetSlot_Ax_1 : 8;
  vbittype TargetSlot_Ay_0 : 8;
  vbittype TargetSlot_Ay_1 : 8;
  vbittype TargetSlot_Bx_0 : 8;
  vbittype TargetSlot_Bx_1 : 8;
  vbittype TargetSlot_By_0 : 8;
  vbittype TargetSlot_By_1 : 8;
} _c_TargetSlot_AB_msgType;
typedef struct _c_TargetPointInfo_msgTypeTag
{
  vbittype FV_TargetPoint_Angle_0 : 8;
  vbittype FV_TargetPoint_Angle_1 : 8;
  vbittype FV_TargetPoint_X_0 : 8;
  vbittype FV_TargetPoint_X_1 : 8;
  vbittype FV_TargetPoint_Y_0 : 8;
  vbittype FV_TargetPoint_Y_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
} _c_TargetPointInfo_msgType;
typedef struct _c_TargetSlot_CD_msgTypeTag
{
  vbittype TargetSlot_Cx_0 : 8;
  vbittype TargetSlot_Cx_1 : 8;
  vbittype TargetSlot_Cy_0 : 8;
  vbittype TargetSlot_Cy_1 : 8;
  vbittype TargetSlot_Dx_0 : 8;
  vbittype TargetSlot_Dx_1 : 8;
  vbittype TargetSlot_Dy_0 : 8;
  vbittype TargetSlot_Dy_1 : 8;
} _c_TargetSlot_CD_msgType;
typedef struct _c_DR_2_msgTypeTag
{
  vbittype DR_RAW_0 : 8;
  vbittype DR_RAW_1 : 8;
  vbittype DR_RAW_2 : 8;
  vbittype DR_RAW_3 : 8;
  vbittype USS_SLOT_L_DEPTH_0 : 8;
  vbittype USS_SLOT_L_DEPTH_1 : 8;
  vbittype USS_SLOT_R_DEPTH_0 : 8;
  vbittype USS_SLOT_R_DEPTH_1 : 8;
} _c_DR_2_msgType;
typedef struct _c_DR_1_msgTypeTag
{
  vbittype DR_X_0 : 8;
  vbittype DR_X_1 : 8;
  vbittype DR_X_2 : 8;
  vbittype DR_X_3 : 8;
  vbittype DR_Y_0 : 8;
  vbittype DR_Y_1 : 8;
  vbittype DR_Y_2 : 8;
  vbittype DR_Y_3 : 8;
} _c_DR_1_msgType;
typedef struct _c_USS_SLOT_R_CD_msgTypeTag
{
  vbittype USS_SLOT_R_Cx_0 : 8;
  vbittype USS_SLOT_R_Cx_1 : 8;
  vbittype USS_SLOT_R_Cy_0 : 8;
  vbittype USS_SLOT_R_Cy_1 : 8;
  vbittype USS_SLOT_R_Dx_0 : 8;
  vbittype USS_SLOT_R_Dx_1 : 8;
  vbittype USS_SLOT_R_Dy_0 : 8;
  vbittype USS_SLOT_R_Dy_1 : 8;
} _c_USS_SLOT_R_CD_msgType;
typedef struct _c_USS_SLOT_R_AB_msgTypeTag
{
  vbittype USS_SLOT_R_Ax_0 : 8;
  vbittype USS_SLOT_R_Ax_1 : 8;
  vbittype USS_SLOT_R_Ay_0 : 8;
  vbittype USS_SLOT_R_Ay_1 : 8;
  vbittype USS_SLOT_R_Bx_0 : 8;
  vbittype USS_SLOT_R_Bx_1 : 8;
  vbittype USS_SLOT_R_By_0 : 8;
  vbittype USS_SLOT_R_By_1 : 8;
} _c_USS_SLOT_R_AB_msgType;
typedef struct _c_USS_SLOT_L_CD_msgTypeTag
{
  vbittype USS_SLOT_L_Cx_0 : 8;
  vbittype USS_SLOT_L_Cx_1 : 8;
  vbittype USS_SLOT_L_Cy_0 : 8;
  vbittype USS_SLOT_L_Cy_1 : 8;
  vbittype USS_SLOT_L_Dx_0 : 8;
  vbittype USS_SLOT_L_Dx_1 : 8;
  vbittype USS_SLOT_L_Dy_0 : 8;
  vbittype USS_SLOT_L_Dy_1 : 8;
} _c_USS_SLOT_L_CD_msgType;
typedef struct _c_USS_SLOT_L_AB_msgTypeTag
{
  vbittype USS_SLOT_L_Ax_0 : 8;
  vbittype USS_SLOT_L_Ax_1 : 8;
  vbittype USS_SLOT_L_AY_0 : 8;
  vbittype USS_SLOT_L_AY_1 : 8;
  vbittype USS_SLOT_L_Bx_0 : 8;
  vbittype USS_SLOT_L_Bx_1 : 8;
  vbittype USS_SLOT_L_By_0 : 8;
  vbittype USS_SLOT_L_By_1 : 8;
} _c_USS_SLOT_L_AB_msgType;
typedef struct _c_USS_DIAG_R_msgTypeTag
{
  vbittype USS_DIAG_RL_0 : 8;
  vbittype USS_DIAG_RL_1 : 2;
  vbittype USS_DIAG_RLS_0 : 6;
  vbittype USS_DIAG_RLS_1 : 4;
  vbittype USS_DIAG_RML_0 : 4;
  vbittype USS_DIAG_RML_1 : 6;
  vbittype USS_DIAG_RMR_0 : 2;
  vbittype USS_DIAG_RMR_1 : 8;
  vbittype USS_DIAG_RR_0 : 8;
  vbittype USS_DIAG_RR_1 : 2;
  vbittype USS_DIAG_RRS_0 : 6;
  vbittype USS_DIAG_RRS_1 : 4;
  vbittype unused0 : 4;
} _c_USS_DIAG_R_msgType;
typedef struct _c_USS_DIAG_F_msgTypeTag
{
  vbittype USS_DIAG_FL_0 : 8;
  vbittype USS_DIAG_FL_1 : 2;
  vbittype USS_DIAG_FLS_0 : 6;
  vbittype USS_DIAG_FLS_1 : 4;
  vbittype USS_DIAG_FML_0 : 4;
  vbittype USS_DIAG_FML_1 : 6;
  vbittype USS_DIAG_FMR_0 : 2;
  vbittype USS_DIAG_FMR_1 : 8;
  vbittype USS_DIAG_FR_0 : 8;
  vbittype USS_DIAG_FR_1 : 2;
  vbittype USS_DIAG_FRS_0 : 6;
  vbittype USS_DIAG_FRS_1 : 4;
  vbittype USS_WORK_MODE : 3;
  vbittype unused0 : 1;
} _c_USS_DIAG_F_msgType;
typedef struct _c_USS_DE_S_msgTypeTag
{
  vbittype USS_DE_FLS_0 : 8;
  vbittype USS_DE_FLS_1 : 5;
  vbittype unused0 : 3;
  vbittype USS_DE_FRS_0 : 8;
  vbittype USS_DE_FRS_1 : 5;
  vbittype unused1 : 3;
  vbittype USS_DE_RLS_0 : 8;
  vbittype USS_DE_RLS_1 : 5;
  vbittype unused2 : 3;
  vbittype USS_DE_RRS_0 : 8;
  vbittype USS_DE_RRS_1 : 5;
  vbittype unused3 : 3;
} _c_USS_DE_S_msgType;
typedef struct _c_USS_DE_R_msgTypeTag
{
  vbittype USS_DE_RL_0 : 8;
  vbittype USS_DE_RL_1 : 5;
  vbittype USS_DE_RML_0 : 3;
  vbittype USS_DE_RML_1 : 8;
  vbittype USS_DE_RML_2 : 2;
  vbittype USS_DE_RMR_0 : 6;
  vbittype USS_DE_RMR_1 : 7;
  vbittype USS_DE_RR_0 : 1;
  vbittype USS_DE_RR_1 : 8;
  vbittype USS_DE_RR_2 : 4;
  vbittype unused0 : 4;
  vbittype unused1 : 8;
} _c_USS_DE_R_msgType;
typedef struct _c_USS_DE_F_msgTypeTag
{
  vbittype USS_DE_FL_0 : 8;
  vbittype USS_DE_FL_1 : 5;
  vbittype USS_DE_FML_0 : 3;
  vbittype USS_DE_FML_1 : 8;
  vbittype USS_DE_FML_2 : 2;
  vbittype USS_DE_FMR_0 : 6;
  vbittype USS_DE_FMR_1 : 7;
  vbittype USS_DE_FR_0 : 1;
  vbittype USS_DE_FR_1 : 8;
  vbittype USS_DE_FR_2 : 4;
  vbittype unused0 : 4;
  vbittype unused1 : 8;
} _c_USS_DE_F_msgType;
typedef struct _c_alpha_distance_R_msgTypeTag
{
  vbittype alpha_USS_RL_0 : 8;
  vbittype alpha_USS_RL_1 : 8;
  vbittype alpha_USS_RML_0 : 8;
  vbittype alpha_USS_RML_1 : 8;
  vbittype alpha_USS_RMR_0 : 8;
  vbittype alpha_USS_RMR_1 : 8;
  vbittype alpha_USS_RR_0 : 8;
  vbittype alpha_USS_RR_1 : 8;
} _c_alpha_distance_R_msgType;
typedef struct _c_alpha_distance_Long_msgTypeTag
{
  vbittype alpha_USS_FL_long_0 : 8;
  vbittype alpha_USS_FL_long_1 : 8;
  vbittype alpha_USS_FR_long_0 : 8;
  vbittype alpha_USS_FR_long_1 : 8;
  vbittype alpha_USS_RL_long_0 : 8;
  vbittype alpha_USS_RL_long_1 : 8;
  vbittype alpha_USS_RR_long_0 : 8;
  vbittype alpha_USS_RR_long_1 : 8;
} _c_alpha_distance_Long_msgType;
typedef struct _c_alpha_distance_F_msgTypeTag
{
  vbittype alpha_USS_FL_0 : 8;
  vbittype alpha_USS_FL_1 : 8;
  vbittype alpha_USS_FML_0 : 8;
  vbittype alpha_USS_FML_1 : 8;
  vbittype alpha_USS_FMR_0 : 8;
  vbittype alpha_USS_FMR_1 : 8;
  vbittype alpha_USS_FR_0 : 8;
  vbittype alpha_USS_FR_1 : 8;
} _c_alpha_distance_F_msgType;
typedef struct _c_ADV_P1_msgTypeTag
{
  vbittype ADV_Pose_X_0 : 8;
  vbittype ADV_Pose_X_1 : 4;
  vbittype ADV_Pose_Y_0 : 4;
  vbittype ADV_Pose_Y_1 : 8;
  vbittype ADV_Pose_Angle_0 : 8;
  vbittype ADV_Pose_Angle_1 : 4;
  vbittype unused0 : 4;
  vbittype ADV_ReplanMode : 2;
  vbittype ADV_ReplanWayPoint : 2;
  vbittype ADV_RealignMode : 2;
  vbittype ADV_RealignWayPoint : 2;
} _c_ADV_P1_msgType;
typedef struct _c_APS_1_msgTypeTag
{
  vbittype APS_Status : 4;
  vbittype APS_ReplanResult : 2;
  vbittype unused0 : 2;
  vbittype APS_RealignResult : 2;
  vbittype APS_CloseLoopDetection : 1;
  vbittype APS_ReplanType : 3;
  vbittype unused1 : 2;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
  vbittype unused6 : 8;
  vbittype unused7 : 8;
} _c_APS_1_msgType;
typedef struct _c_RightCurbInfo_msgTypeTag
{
  vbittype RightCurb_StartPointFlag : 1;
  vbittype RightCurb_StartPointX_0 : 7;
  vbittype RightCurb_StartPointX_1 : 4;
  vbittype RightCurb_StartPointY_0 : 4;
  vbittype RightCurb_StartPointY_1 : 7;
  vbittype RightCurb_EndPointFlag : 1;
  vbittype RightCurb_EndPointX_0 : 8;
  vbittype RightCurb_EndPointX_1 : 3;
  vbittype RightCurb_EndPointY_0 : 5;
  vbittype RightCurb_EndPointY_1 : 6;
  vbittype RightCurb_Height : 2;
  vbittype RightCurb_Status : 3;
  vbittype RightCurb_Direction : 1;
  vbittype RightCurb_AngleFlag : 1;
  vbittype RightCurb_Angle_0 : 3;
  vbittype RightCurb_Angle_1 : 8;
} _c_RightCurbInfo_msgType;
typedef struct _c_LeftCurbInfo_msgTypeTag
{
  vbittype LeftCurb_StartPointFlag : 1;
  vbittype LeftCurb_StartPointX_0 : 7;
  vbittype LeftCurb_StartPointX_1 : 4;
  vbittype LeftCurb_StartPointY_0 : 4;
  vbittype LeftCurb_StartPointY_1 : 7;
  vbittype LeftCurb_EndPointFlag : 1;
  vbittype LeftCurb_EndPointX_0 : 8;
  vbittype LeftCurb_EndPointX_1 : 3;
  vbittype LeftCurb_EndPointY_0 : 5;
  vbittype LeftCurb_EndPointY_1 : 6;
  vbittype LeftCurb_Height : 2;
  vbittype LeftCurb_Status : 3;
  vbittype LeftCurb_Direction : 1;
  vbittype LeftCurb_AngleFlag : 1;
  vbittype LeftCurb_Angle_0 : 3;
  vbittype LeftCurb_Angle_1 : 8;
} _c_LeftCurbInfo_msgType;
typedef struct _c_Freespace9_ObstacleInfo_msgTypeTag
{
  vbittype Freespace9_ObstacleStartPointX_0 : 8;
  vbittype Freespace9_ObstacleStartPointX_1 : 3;
  vbittype Freespace9_ObstacleStartPointY_0 : 5;
  vbittype Freespace9_ObstacleStartPointY_1 : 6;
  vbittype Freespace9_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace9_ObstacleEndPointX_0 : 8;
  vbittype Freespace9_ObstacleEndPointX_1 : 3;
  vbittype Freespace9_ObstacleEndPointY_0 : 5;
  vbittype Freespace9_ObstacleEndPointY_1 : 6;
  vbittype Freespace9_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace9_ObstacleStatus : 3;
  vbittype Freespace9_ObstacleProperty : 1;
  vbittype Freespace9_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace9_ObstacleInfo_msgType;
typedef struct _c_Freespace8_ObstacleInfo_msgTypeTag
{
  vbittype Freespace8_ObstacleStartPointX_0 : 8;
  vbittype Freespace8_ObstacleStartPointX_1 : 3;
  vbittype Freespace8_ObstacleStartPointY_0 : 5;
  vbittype Freespace8_ObstacleStartPointY_1 : 6;
  vbittype Freespace8_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace8_ObstacleEndPointX_0 : 8;
  vbittype Freespace8_ObstacleEndPointX_1 : 3;
  vbittype Freespace8_ObstacleEndPointY_0 : 5;
  vbittype Freespace8_ObstacleEndPointY_1 : 6;
  vbittype Freespace8_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace8_ObstacleStatus : 3;
  vbittype Freespace8_ObstacleProperty : 1;
  vbittype Freespace8_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace8_ObstacleInfo_msgType;
typedef struct _c_Freespace7_ObstacleInfo_msgTypeTag
{
  vbittype Freespace7_ObstacleStartPointX_0 : 8;
  vbittype Freespace7_ObstacleStartPointX_1 : 3;
  vbittype Freespace7_ObstacleStartPointY_0 : 5;
  vbittype Freespace7_ObstacleStartPointY_1 : 6;
  vbittype Freespace7_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace7_ObstacleEndPointX_0 : 8;
  vbittype Freespace7_ObstacleEndPointX_1 : 3;
  vbittype Freespace7_ObstacleEndPointY_0 : 5;
  vbittype Freespace7_ObstacleEndPointY_1 : 6;
  vbittype Freespace7_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace7_ObstacleStatus : 3;
  vbittype Freespace7_ObstacleProperty : 1;
  vbittype Freespace7_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace7_ObstacleInfo_msgType;
typedef struct _c_Freespace6_ObstacleInfo_msgTypeTag
{
  vbittype Freespace6_ObstacleStartPointX_0 : 8;
  vbittype Freespace6_ObstacleStartPointX_1 : 3;
  vbittype Freespace6_ObstacleStartPointY_0 : 5;
  vbittype Freespace6_ObstacleStartPointY_1 : 6;
  vbittype Freespace6_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace6_ObstacleEndPointX_0 : 8;
  vbittype Freespace6_ObstacleEndPointX_1 : 3;
  vbittype Freespace6_ObstacleEndPointY_0 : 5;
  vbittype Freespace6_ObstacleEndPointY_1 : 6;
  vbittype Freespace6_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace6_ObstacleStatus : 3;
  vbittype Freespace6_ObstacleProperty : 1;
  vbittype Freespace6_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace6_ObstacleInfo_msgType;
typedef struct _c_Freespace5_ObstacleInfo_msgTypeTag
{
  vbittype Freespace5_ObstacleStartPointX_0 : 8;
  vbittype Freespace5_ObstacleStartPointX_1 : 3;
  vbittype Freespace5_ObstacleStartPointY_0 : 5;
  vbittype Freespace5_ObstacleStartPointY_1 : 6;
  vbittype Freespace5_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace5_ObstacleEndPointX_0 : 8;
  vbittype Freespace5_ObstacleEndPointX_1 : 3;
  vbittype Freespace5_ObstacleEndPointY_0 : 5;
  vbittype Freespace5_ObstacleEndPointY_1 : 6;
  vbittype Freespace5_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace5_ObstacleStatus : 3;
  vbittype Freespace5_ObstacleProperty : 1;
  vbittype Freespace5_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace5_ObstacleInfo_msgType;
typedef struct _c_Freespace4_ObstacleInfo_msgTypeTag
{
  vbittype Freespace4_ObstacleStartPointX_0 : 8;
  vbittype Freespace4_ObstacleStartPointX_1 : 3;
  vbittype Freespace4_ObstacleStartPointY_0 : 5;
  vbittype Freespace4_ObstacleStartPointY_1 : 6;
  vbittype Freespace4_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace4_ObstacleEndPointX_0 : 8;
  vbittype Freespace4_ObstacleEndPointX_1 : 3;
  vbittype Freespace4_ObstacleEndPointY_0 : 5;
  vbittype Freespace4_ObstacleEndPointY_1 : 6;
  vbittype Freespace4_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace4_ObstacleStatus : 3;
  vbittype Freespace4_ObstacleProperty : 1;
  vbittype Freespace4_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace4_ObstacleInfo_msgType;
typedef struct _c_Freespace3_ObstacleInfo_msgTypeTag
{
  vbittype Freespace3_ObstacleStartPointX_0 : 8;
  vbittype Freespace3_ObstacleStartPointX_1 : 3;
  vbittype Freespace3_ObstacleStartPointY_0 : 5;
  vbittype Freespace3_ObstacleStartPointY_1 : 6;
  vbittype Freespace3_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace3_ObstacleEndPointX_0 : 8;
  vbittype Freespace3_ObstacleEndPointX_1 : 3;
  vbittype Freespace3_ObstacleEndPointY_0 : 5;
  vbittype Freespace3_ObstacleEndPointY_1 : 6;
  vbittype Freespace3_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace3_ObstacleStatus : 3;
  vbittype Freespace3_ObstacleProperty : 1;
  vbittype Freespace3_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace3_ObstacleInfo_msgType;
typedef struct _c_Freespace2_ObstacleInfo_msgTypeTag
{
  vbittype Freespace2_ObstacleStartPointX_0 : 8;
  vbittype Freespace2_ObstacleStartPointX_1 : 3;
  vbittype Freespace2_ObstacleStartPointY_0 : 5;
  vbittype Freespace2_ObstacleStartPointY_1 : 6;
  vbittype Freespace2_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace2_ObstacleEndPointX_0 : 8;
  vbittype Freespace2_ObstacleEndPointX_1 : 3;
  vbittype Freespace2_ObstacleEndPointY_0 : 5;
  vbittype Freespace2_ObstacleEndPointY_1 : 6;
  vbittype Freespace2_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace2_ObstacleStatus : 3;
  vbittype Freespace2_ObstacleProperty : 1;
  vbittype Freespace2_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace2_ObstacleInfo_msgType;
typedef struct _c_Freespace1_ObstacleInfo_msgTypeTag
{
  vbittype Freespace1_ObstacleStartPointX_0 : 8;
  vbittype Freespace1_ObstacleStartPointX_1 : 3;
  vbittype Freespace1_ObstacleStartPointY_0 : 5;
  vbittype Freespace1_ObstacleStartPointY_1 : 6;
  vbittype Freespace1_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace1_ObstacleEndPointX_0 : 8;
  vbittype Freespace1_ObstacleEndPointX_1 : 3;
  vbittype Freespace1_ObstacleEndPointY_0 : 5;
  vbittype Freespace1_ObstacleEndPointY_1 : 6;
  vbittype Freespace1_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace1_ObstacleStatus : 3;
  vbittype Freespace1_ObstacleProperty : 1;
  vbittype Freespace1_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace1_ObstacleInfo_msgType;
typedef struct _c_Freespace11_ObstacleInfo_msgTypeTag
{
  vbittype Freespace11_ObstacleStartPointX_0 : 8;
  vbittype Freespace11_ObstacleStartPointX_1 : 3;
  vbittype Freespace11_ObstacleStartPointY_0 : 5;
  vbittype Freespace11_ObstacleStartPointY_1 : 6;
  vbittype Freespace11_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace11_ObstacleEndPointX_0 : 8;
  vbittype Freespace11_ObstacleEndPointX_1 : 3;
  vbittype Freespace11_ObstacleEndPointY_0 : 5;
  vbittype Freespace11_ObstacleEndPointY_1 : 6;
  vbittype Freespace11_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace11_ObstacleStatus : 3;
  vbittype Freespace11_ObstacleProperty : 1;
  vbittype Freespace11_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace11_ObstacleInfo_msgType;
typedef struct _c_Freespace10_ObstacleInfo_msgTypeTag
{
  vbittype Freespace10_ObstacleStartPointX_0 : 8;
  vbittype Freespace10_ObstacleStartPointX_1 : 3;
  vbittype Freespace10_ObstacleStartPointY_0 : 5;
  vbittype Freespace10_ObstacleStartPointY_1 : 6;
  vbittype Freespace10_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace10_ObstacleEndPointX_0 : 8;
  vbittype Freespace10_ObstacleEndPointX_1 : 3;
  vbittype Freespace10_ObstacleEndPointY_0 : 5;
  vbittype Freespace10_ObstacleEndPointY_1 : 6;
  vbittype Freespace10_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace10_ObstacleStatus : 3;
  vbittype Freespace10_ObstacleProperty : 1;
  vbittype Freespace10_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace10_ObstacleInfo_msgType;
typedef struct _c_Freespace0_ObstacleInfo_msgTypeTag
{
  vbittype Freespace0_ObstacleStartPointX_0 : 8;
  vbittype Freespace0_ObstacleStartPointX_1 : 3;
  vbittype Freespace0_ObstacleStartPointY_0 : 5;
  vbittype Freespace0_ObstacleStartPointY_1 : 6;
  vbittype Freespace0_ObstacleStartPointFlag : 1;
  vbittype unused0 : 1;
  vbittype Freespace0_ObstacleEndPointX_0 : 8;
  vbittype Freespace0_ObstacleEndPointX_1 : 3;
  vbittype Freespace0_ObstacleEndPointY_0 : 5;
  vbittype Freespace0_ObstacleEndPointY_1 : 6;
  vbittype Freespace0_ObstacleEndPointFlag : 1;
  vbittype unused1 : 1;
  vbittype Freespace0_ObstacleStatus : 3;
  vbittype Freespace0_ObstacleProperty : 1;
  vbittype Freespace0_ObstacleHeight : 2;
  vbittype unused2 : 2;
  vbittype unused3 : 8;
} _c_Freespace0_ObstacleInfo_msgType;
typedef struct _c_APS_Replan_2_msgTypeTag
{
  vbittype APS_Replan_UpperLineFlag : 1;
  vbittype APS_Replan_UpperLineDistance_0 : 7;
  vbittype APS_Replan_UpperLineDistance_1 : 4;
  vbittype APS_Replan_UpperLineAngle_0 : 4;
  vbittype APS_Replan_UpperLineAngle_1 : 7;
  vbittype unused0 : 1;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
  vbittype unused5 : 8;
} _c_APS_Replan_2_msgType;
typedef struct _c_APS_Replan_1_msgTypeTag
{
  vbittype APS_Replan_LeftLineFlag : 1;
  vbittype APS_Replan_LeftLineDistance_0 : 7;
  vbittype APS_Replan_LeftLineDistance_1 : 4;
  vbittype APS_Replan_LeftLineAngle_0 : 4;
  vbittype APS_Replan_LeftLineAngle_1 : 7;
  vbittype APS_Replan_RightLineFlag : 1;
  vbittype APS_Replan_RightLineDistance_0 : 8;
  vbittype APS_Replan_RightLineDistance_1 : 3;
  vbittype APS_Replan_RightLineAngle_0 : 5;
  vbittype APS_Replan_RightLineAngle_1 : 6;
  vbittype APS_Replan_LeftStatus : 2;
  vbittype APS_Replan_RightStatus : 2;
  vbittype unused0 : 6;
  vbittype unused1 : 8;
} _c_APS_Replan_1_msgType;


/* -----------------------------------------------------------------------------
    &&&~ Signal value names
 ----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
    &&&~ Message Unions
 ----------------------------------------------------------------------------- */

typedef union _c_ABS_1_bufTag
{
  vuint8 _c[8];
  _c_ABS_1_msgType ABS_1;
} _c_ABS_1_buf;
typedef union _c_TxDynamicMsg0_bufTag
{
  vuint8 _c[8];
} _c_TxDynamicMsg0_buf;
typedef union _c_HU_5_bufTag
{
  vuint8 _c[8];
  _c_HU_5_msgType HU_5;
} _c_HU_5_buf;
typedef union _c_TCU_3_bufTag
{
  vuint8 _c[8];
  _c_TCU_3_msgType TCU_3;
} _c_TCU_3_buf;
typedef union _c_SAS_1_bufTag
{
  vuint8 _c[8];
  _c_SAS_1_msgType SAS_1;
} _c_SAS_1_buf;
typedef union _c_PDC_1_bufTag
{
  vuint8 _c[8];
  _c_PDC_1_msgType PDC_1;
} _c_PDC_1_buf;
typedef union _c_EMS_3_bufTag
{
  vuint8 _c[8];
  _c_EMS_3_msgType EMS_3;
} _c_EMS_3_buf;
typedef union _c_HU_Speech_1_bufTag
{
  vuint8 _c[8];
  _c_HU_Speech_1_msgType HU_Speech_1;
} _c_HU_Speech_1_buf;
typedef union _c_ABS_2_bufTag
{
  vuint8 _c[8];
  _c_ABS_2_msgType ABS_2;
} _c_ABS_2_buf;
typedef union _c_BCM1_2_bufTag
{
  vuint8 _c[1];
  _c_BCM1_2_msgType BCM1_2;
} _c_BCM1_2_buf;
typedef union _c_AVM_NM_bufTag
{
  vuint8 _c[8];
  _c_AVM_NM_msgType AVM_NM;
} _c_AVM_NM_buf;
typedef union _c_ADV_1_bufTag
{
  vuint8 _c[8];
  _c_ADV_1_msgType ADV_1;
} _c_ADV_1_buf;
typedef union _c_PDC_2_bufTag
{
  vuint8 _c[8];
  _c_PDC_2_msgType PDC_2;
} _c_PDC_2_buf;
typedef union _c_APS_Slot6_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot6_msgType APS_Slot6;
} _c_APS_Slot6_buf;
typedef union _c_APS_Slot5_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot5_msgType APS_Slot5;
} _c_APS_Slot5_buf;
typedef union _c_APS_Slot4_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot4_msgType APS_Slot4;
} _c_APS_Slot4_buf;
typedef union _c_APS_Slot3_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot3_msgType APS_Slot3;
} _c_APS_Slot3_buf;
typedef union _c_APS_Slot2_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot2_msgType APS_Slot2;
} _c_APS_Slot2_buf;
typedef union _c_APS_Slot1_bufTag
{
  vuint8 _c[8];
  _c_APS_Slot1_msgType APS_Slot1;
} _c_APS_Slot1_buf;
typedef union _c_APS_PSD_bufTag
{
  vuint8 _c[8];
  _c_APS_PSD_msgType APS_PSD;
} _c_APS_PSD_buf;
typedef union _c_PLG_1_bufTag
{
  vuint8 _c[1];
  _c_PLG_1_msgType PLG_1;
} _c_PLG_1_buf;
typedef union _c_PDCU_1_bufTag
{
  vuint8 _c[5];
  _c_PDCU_1_msgType PDCU_1;
} _c_PDCU_1_buf;
typedef union _c_IC_1_bufTag
{
  vuint8 _c[7];
  _c_IC_1_msgType IC_1;
} _c_IC_1_buf;
typedef union _c_ESC_3_bufTag
{
  vuint8 _c[8];
  _c_ESC_3_msgType ESC_3;
} _c_ESC_3_buf;
typedef union _c_ESC_2_bufTag
{
  vuint8 _c[8];
  _c_ESC_2_msgType ESC_2;
} _c_ESC_2_buf;
typedef union _c_DDCU_1_bufTag
{
  vuint8 _c[5];
  _c_DDCU_1_msgType DDCU_1;
} _c_DDCU_1_buf;
typedef union _c_BCM1_1_bufTag
{
  vuint8 _c[5];
  _c_BCM1_1_msgType BCM1_1;
} _c_BCM1_1_buf;
typedef union _c_ATC_2_bufTag
{
  vuint8 _c[4];
  _c_ATC_2_msgType ATC_2;
} _c_ATC_2_buf;
typedef union _c_HU_6_bufTag
{
  vuint8 _c[8];
  _c_HU_6_msgType HU_6;
} _c_HU_6_buf;
typedef union _c_GPS_1_bufTag
{
  vuint8 _c[6];
  _c_GPS_1_msgType GPS_1;
} _c_GPS_1_buf;
typedef union _c_ABS_3_bufTag
{
  vuint8 _c[8];
  _c_ABS_3_msgType ABS_3;
} _c_ABS_3_buf;
typedef union _c_AVS_1_bufTag
{
  vuint8 _c[8];
  _c_AVS_1_msgType AVS_1;
} _c_AVS_1_buf;
typedef union _c_Debug_ReloatInfo_bufTag
{
  vuint8 _c[8];
  _c_Debug_ReloatInfo_msgType Debug_ReloatInfo;
} _c_Debug_ReloatInfo_buf;
typedef union _c_Debug_CanStaInfo_bufTag
{
  vuint8 _c[8];
  _c_Debug_CanStaInfo_msgType Debug_CanStaInfo;
} _c_Debug_CanStaInfo_buf;
typedef union _c_ADV_TargetTracing_bufTag
{
  vuint8 _c[8];
  _c_ADV_TargetTracing_msgType ADV_TargetTracing;
} _c_ADV_TargetTracing_buf;
typedef union _c_ADV_PathTracing_bufTag
{
  vuint8 _c[8];
  _c_ADV_PathTracing_msgType ADV_PathTracing;
} _c_ADV_PathTracing_buf;
typedef union _c_ADV_4_bufTag
{
  vuint8 _c[8];
  _c_ADV_4_msgType ADV_4;
} _c_ADV_4_buf;
typedef union _c_TBOX_1_bufTag
{
  vuint8 _c[8];
  _c_TBOX_1_msgType TBOX_1;
} _c_TBOX_1_buf;
typedef union _c_RRDCU_1_bufTag
{
  vuint8 _c[1];
  _c_RRDCU_1_msgType RRDCU_1;
} _c_RRDCU_1_buf;
typedef union _c_RLDCU_1_bufTag
{
  vuint8 _c[1];
  _c_RLDCU_1_msgType RLDCU_1;
} _c_RLDCU_1_buf;
typedef union _c_MCP_1_bufTag
{
  vuint8 _c[4];
  _c_MCP_1_msgType MCP_1;
} _c_MCP_1_buf;
typedef union _c_HU_18_bufTag
{
  vuint8 _c[8];
  _c_HU_18_msgType HU_18;
} _c_HU_18_buf;
typedef union _c_HU_14_bufTag
{
  vuint8 _c[4];
  _c_HU_14_msgType HU_14;
} _c_HU_14_buf;
typedef union _c_HU_10_bufTag
{
  vuint8 _c[8];
  _c_HU_10_msgType HU_10;
} _c_HU_10_buf;
typedef union _c_GW_Config_bufTag
{
  vuint8 _c[3];
  _c_GW_Config_msgType GW_Config;
} _c_GW_Config_buf;
typedef union _c_DMS_2_bufTag
{
  vuint8 _c[2];
  _c_DMS_2_msgType DMS_2;
} _c_DMS_2_buf;
typedef union _c_BCM1_7_bufTag
{
  vuint8 _c[4];
  _c_BCM1_7_msgType BCM1_7;
} _c_BCM1_7_buf;
typedef union _c_BCM1_3_bufTag
{
  vuint8 _c[2];
  _c_BCM1_3_msgType BCM1_3;
} _c_BCM1_3_buf;
typedef union _c_PDC_9_bufTag
{
  vuint8 _c[8];
  _c_PDC_9_msgType PDC_9;
} _c_PDC_9_buf;
typedef union _c_PDC_8_bufTag
{
  vuint8 _c[8];
  _c_PDC_8_msgType PDC_8;
} _c_PDC_8_buf;
typedef union _c_PDC_7_bufTag
{
  vuint8 _c[8];
  _c_PDC_7_msgType PDC_7;
} _c_PDC_7_buf;
typedef union _c_PDC_6_bufTag
{
  vuint8 _c[8];
  _c_PDC_6_msgType PDC_6;
} _c_PDC_6_buf;
typedef union _c_PDC_5_bufTag
{
  vuint8 _c[8];
  _c_PDC_5_msgType PDC_5;
} _c_PDC_5_buf;
typedef union _c_PDC_4_bufTag
{
  vuint8 _c[8];
  _c_PDC_4_msgType PDC_4;
} _c_PDC_4_buf;
typedef union _c_PDC_3_bufTag
{
  vuint8 _c[8];
  _c_PDC_3_msgType PDC_3;
} _c_PDC_3_buf;
typedef union _c_PDC_14_bufTag
{
  vuint8 _c[8];
  _c_PDC_14_msgType PDC_14;
} _c_PDC_14_buf;
typedef union _c_PDC_13_bufTag
{
  vuint8 _c[8];
  _c_PDC_13_msgType PDC_13;
} _c_PDC_13_buf;
typedef union _c_PDC_12_bufTag
{
  vuint8 _c[8];
  _c_PDC_12_msgType PDC_12;
} _c_PDC_12_buf;
typedef union _c_PDC_11_bufTag
{
  vuint8 _c[8];
  _c_PDC_11_msgType PDC_11;
} _c_PDC_11_buf;
typedef union _c_PDC_10_bufTag
{
  vuint8 _c[8];
  _c_PDC_10_msgType PDC_10;
} _c_PDC_10_buf;
typedef union _c_HU_20_bufTag
{
  vuint8 _c[7];
  _c_HU_20_msgType HU_20;
} _c_HU_20_buf;
typedef union _c_TargetSlot_AB_bufTag
{
  vuint8 _c[8];
  _c_TargetSlot_AB_msgType TargetSlot_AB;
} _c_TargetSlot_AB_buf;
typedef union _c_TargetPointInfo_bufTag
{
  vuint8 _c[8];
  _c_TargetPointInfo_msgType TargetPointInfo;
} _c_TargetPointInfo_buf;
typedef union _c_TargetSlot_CD_bufTag
{
  vuint8 _c[8];
  _c_TargetSlot_CD_msgType TargetSlot_CD;
} _c_TargetSlot_CD_buf;
typedef union _c_DR_2_bufTag
{
  vuint8 _c[8];
  _c_DR_2_msgType DR_2;
} _c_DR_2_buf;
typedef union _c_DR_1_bufTag
{
  vuint8 _c[8];
  _c_DR_1_msgType DR_1;
} _c_DR_1_buf;
typedef union _c_USS_SLOT_R_CD_bufTag
{
  vuint8 _c[8];
  _c_USS_SLOT_R_CD_msgType USS_SLOT_R_CD;
} _c_USS_SLOT_R_CD_buf;
typedef union _c_USS_SLOT_R_AB_bufTag
{
  vuint8 _c[8];
  _c_USS_SLOT_R_AB_msgType USS_SLOT_R_AB;
} _c_USS_SLOT_R_AB_buf;
typedef union _c_USS_SLOT_L_CD_bufTag
{
  vuint8 _c[8];
  _c_USS_SLOT_L_CD_msgType USS_SLOT_L_CD;
} _c_USS_SLOT_L_CD_buf;
typedef union _c_USS_SLOT_L_AB_bufTag
{
  vuint8 _c[8];
  _c_USS_SLOT_L_AB_msgType USS_SLOT_L_AB;
} _c_USS_SLOT_L_AB_buf;
typedef union _c_USS_DIAG_R_bufTag
{
  vuint8 _c[8];
  _c_USS_DIAG_R_msgType USS_DIAG_R;
} _c_USS_DIAG_R_buf;
typedef union _c_USS_DIAG_F_bufTag
{
  vuint8 _c[8];
  _c_USS_DIAG_F_msgType USS_DIAG_F;
} _c_USS_DIAG_F_buf;
typedef union _c_USS_DE_S_bufTag
{
  vuint8 _c[8];
  _c_USS_DE_S_msgType USS_DE_S;
} _c_USS_DE_S_buf;
typedef union _c_USS_DE_R_bufTag
{
  vuint8 _c[8];
  _c_USS_DE_R_msgType USS_DE_R;
} _c_USS_DE_R_buf;
typedef union _c_USS_DE_F_bufTag
{
  vuint8 _c[8];
  _c_USS_DE_F_msgType USS_DE_F;
} _c_USS_DE_F_buf;
typedef union _c_alpha_distance_R_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_R_msgType alpha_distance_R;
} _c_alpha_distance_R_buf;
typedef union _c_alpha_distance_Long_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_Long_msgType alpha_distance_Long;
} _c_alpha_distance_Long_buf;
typedef union _c_alpha_distance_F_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_F_msgType alpha_distance_F;
} _c_alpha_distance_F_buf;
typedef union _c_ADV_P1_bufTag
{
  vuint8 _c[6];
  _c_ADV_P1_msgType ADV_P1;
} _c_ADV_P1_buf;
typedef union _c_APS_1_bufTag
{
  vuint8 _c[8];
  _c_APS_1_msgType APS_1;
} _c_APS_1_buf;
typedef union _c_RightCurbInfo_bufTag
{
  vuint8 _c[8];
  _c_RightCurbInfo_msgType RightCurbInfo;
} _c_RightCurbInfo_buf;
typedef union _c_LeftCurbInfo_bufTag
{
  vuint8 _c[8];
  _c_LeftCurbInfo_msgType LeftCurbInfo;
} _c_LeftCurbInfo_buf;
typedef union _c_Freespace9_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace9_ObstacleInfo_msgType Freespace9_ObstacleInfo;
} _c_Freespace9_ObstacleInfo_buf;
typedef union _c_Freespace8_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace8_ObstacleInfo_msgType Freespace8_ObstacleInfo;
} _c_Freespace8_ObstacleInfo_buf;
typedef union _c_Freespace7_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace7_ObstacleInfo_msgType Freespace7_ObstacleInfo;
} _c_Freespace7_ObstacleInfo_buf;
typedef union _c_Freespace6_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace6_ObstacleInfo_msgType Freespace6_ObstacleInfo;
} _c_Freespace6_ObstacleInfo_buf;
typedef union _c_Freespace5_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace5_ObstacleInfo_msgType Freespace5_ObstacleInfo;
} _c_Freespace5_ObstacleInfo_buf;
typedef union _c_Freespace4_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace4_ObstacleInfo_msgType Freespace4_ObstacleInfo;
} _c_Freespace4_ObstacleInfo_buf;
typedef union _c_Freespace3_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace3_ObstacleInfo_msgType Freespace3_ObstacleInfo;
} _c_Freespace3_ObstacleInfo_buf;
typedef union _c_Freespace2_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace2_ObstacleInfo_msgType Freespace2_ObstacleInfo;
} _c_Freespace2_ObstacleInfo_buf;
typedef union _c_Freespace1_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace1_ObstacleInfo_msgType Freespace1_ObstacleInfo;
} _c_Freespace1_ObstacleInfo_buf;
typedef union _c_Freespace11_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace11_ObstacleInfo_msgType Freespace11_ObstacleInfo;
} _c_Freespace11_ObstacleInfo_buf;
typedef union _c_Freespace10_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace10_ObstacleInfo_msgType Freespace10_ObstacleInfo;
} _c_Freespace10_ObstacleInfo_buf;
typedef union _c_Freespace0_ObstacleInfo_bufTag
{
  vuint8 _c[8];
  _c_Freespace0_ObstacleInfo_msgType Freespace0_ObstacleInfo;
} _c_Freespace0_ObstacleInfo_buf;
typedef union _c_APS_Replan_2_bufTag
{
  vuint8 _c[8];
  _c_APS_Replan_2_msgType APS_Replan_2;
} _c_APS_Replan_2_buf;
typedef union _c_APS_Replan_1_bufTag
{
  vuint8 _c[8];
  _c_APS_Replan_1_msgType APS_Replan_1;
} _c_APS_Replan_1_buf;


/* -----------------------------------------------------------------------------
    &&&~ Message Buffers
 ----------------------------------------------------------------------------- */

/* RAM CATEGORY 2 START */
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ABS_1_buf V_MEMRAM2 ABS_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TxDynamicMsg0_buf V_MEMRAM2 TxDynamicMsg0;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_5_buf V_MEMRAM2 HU_5;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TCU_3_buf V_MEMRAM2 TCU_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_SAS_1_buf V_MEMRAM2 SAS_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_1_buf V_MEMRAM2 PDC_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_EMS_3_buf V_MEMRAM2 EMS_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_Speech_1_buf V_MEMRAM2 HU_Speech_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ABS_2_buf V_MEMRAM2 ABS_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_BCM1_2_buf V_MEMRAM2 BCM1_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_AVM_NM_buf V_MEMRAM2 AVM_NM;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ADV_1_buf V_MEMRAM2 ADV_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_2_buf V_MEMRAM2 PDC_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot6_buf V_MEMRAM2 APS_Slot6;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot5_buf V_MEMRAM2 APS_Slot5;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot4_buf V_MEMRAM2 APS_Slot4;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot3_buf V_MEMRAM2 APS_Slot3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot2_buf V_MEMRAM2 APS_Slot2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Slot1_buf V_MEMRAM2 APS_Slot1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_PSD_buf V_MEMRAM2 APS_PSD;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PLG_1_buf V_MEMRAM2 PLG_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDCU_1_buf V_MEMRAM2 PDCU_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_IC_1_buf V_MEMRAM2 IC_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ESC_3_buf V_MEMRAM2 ESC_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ESC_2_buf V_MEMRAM2 ESC_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_DDCU_1_buf V_MEMRAM2 DDCU_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_BCM1_1_buf V_MEMRAM2 BCM1_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ATC_2_buf V_MEMRAM2 ATC_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_6_buf V_MEMRAM2 HU_6;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_GPS_1_buf V_MEMRAM2 GPS_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ABS_3_buf V_MEMRAM2 ABS_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_AVS_1_buf V_MEMRAM2 AVS_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Debug_ReloatInfo_buf V_MEMRAM2 Debug_ReloatInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Debug_CanStaInfo_buf V_MEMRAM2 Debug_CanStaInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ADV_TargetTracing_buf V_MEMRAM2 ADV_TargetTracing;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ADV_PathTracing_buf V_MEMRAM2 ADV_PathTracing;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ADV_4_buf V_MEMRAM2 ADV_4;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TBOX_1_buf V_MEMRAM2 TBOX_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_RRDCU_1_buf V_MEMRAM2 RRDCU_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_RLDCU_1_buf V_MEMRAM2 RLDCU_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_MCP_1_buf V_MEMRAM2 MCP_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_18_buf V_MEMRAM2 HU_18;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_14_buf V_MEMRAM2 HU_14;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_10_buf V_MEMRAM2 HU_10;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_GW_Config_buf V_MEMRAM2 GW_Config;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_DMS_2_buf V_MEMRAM2 DMS_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_BCM1_7_buf V_MEMRAM2 BCM1_7;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_BCM1_3_buf V_MEMRAM2 BCM1_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_9_buf V_MEMRAM2 PDC_9;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_8_buf V_MEMRAM2 PDC_8;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_7_buf V_MEMRAM2 PDC_7;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_6_buf V_MEMRAM2 PDC_6;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_5_buf V_MEMRAM2 PDC_5;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_4_buf V_MEMRAM2 PDC_4;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_3_buf V_MEMRAM2 PDC_3;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_14_buf V_MEMRAM2 PDC_14;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_13_buf V_MEMRAM2 PDC_13;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_12_buf V_MEMRAM2 PDC_12;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_11_buf V_MEMRAM2 PDC_11;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_PDC_10_buf V_MEMRAM2 PDC_10;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_HU_20_buf V_MEMRAM2 HU_20;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TargetSlot_AB_buf V_MEMRAM2 TargetSlot_AB;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TargetPointInfo_buf V_MEMRAM2 TargetPointInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_TargetSlot_CD_buf V_MEMRAM2 TargetSlot_CD;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_DR_2_buf V_MEMRAM2 DR_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_DR_1_buf V_MEMRAM2 DR_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_SLOT_R_CD_buf V_MEMRAM2 USS_SLOT_R_CD;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_SLOT_R_AB_buf V_MEMRAM2 USS_SLOT_R_AB;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_SLOT_L_CD_buf V_MEMRAM2 USS_SLOT_L_CD;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_SLOT_L_AB_buf V_MEMRAM2 USS_SLOT_L_AB;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_DIAG_R_buf V_MEMRAM2 USS_DIAG_R;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_DIAG_F_buf V_MEMRAM2 USS_DIAG_F;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_DE_S_buf V_MEMRAM2 USS_DE_S;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_DE_R_buf V_MEMRAM2 USS_DE_R;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_USS_DE_F_buf V_MEMRAM2 USS_DE_F;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_alpha_distance_R_buf V_MEMRAM2 alpha_distance_R;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_alpha_distance_Long_buf V_MEMRAM2 alpha_distance_Long;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_alpha_distance_F_buf V_MEMRAM2 alpha_distance_F;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_ADV_P1_buf V_MEMRAM2 ADV_P1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_1_buf V_MEMRAM2 APS_1;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_RightCurbInfo_buf V_MEMRAM2 RightCurbInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_LeftCurbInfo_buf V_MEMRAM2 LeftCurbInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace9_ObstacleInfo_buf V_MEMRAM2 Freespace9_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace8_ObstacleInfo_buf V_MEMRAM2 Freespace8_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace7_ObstacleInfo_buf V_MEMRAM2 Freespace7_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace6_ObstacleInfo_buf V_MEMRAM2 Freespace6_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace5_ObstacleInfo_buf V_MEMRAM2 Freespace5_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace4_ObstacleInfo_buf V_MEMRAM2 Freespace4_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace3_ObstacleInfo_buf V_MEMRAM2 Freespace3_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace2_ObstacleInfo_buf V_MEMRAM2 Freespace2_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace1_ObstacleInfo_buf V_MEMRAM2 Freespace1_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace11_ObstacleInfo_buf V_MEMRAM2 Freespace11_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace10_ObstacleInfo_buf V_MEMRAM2 Freespace10_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_Freespace0_ObstacleInfo_buf V_MEMRAM2 Freespace0_ObstacleInfo;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Replan_2_buf V_MEMRAM2 APS_Replan_2;
/* RAM CATEGORY 2 END */

/* RAM CATEGORY 2 START */
V_MEMRAM0 extern  V_MEMRAM1 _c_APS_Replan_1_buf V_MEMRAM2 APS_Replan_1;
/* RAM CATEGORY 2 END */






/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\drv_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 390049630
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __DRV_PAR_H__ */
