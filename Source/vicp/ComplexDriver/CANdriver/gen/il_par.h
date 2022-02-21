/* -----------------------------------------------------------------------------
  Filename:    il_par.h
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Il_Vector
               
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

#if !defined(__IL_PAR_H__)
#define __IL_PAR_H__

/* -----------------------------------------------------------------------------
    &&&~ Typedefs
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
typedef vuint8 IltTxCounter;
#endif

#if defined(IL_ENABLE_TX)
typedef vuint8 IltTxUpdateCounter;
#endif

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
typedef vuint8 IltTxTimeoutCounter;
#endif

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
typedef vuint8 IltRxTimeoutCounter;
#endif

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_SECURE_EVENT)
typedef vuint8 IltTxRepetitionCounter;
#endif



/* -----------------------------------------------------------------------------
    &&&~ Message Handles
 ----------------------------------------------------------------------------- */

#define IlRxMsgHndalpha_distance_Long        0
#define IlRxMsgHndalpha_distance_R           1
#define IlRxMsgHndalpha_distance_F           2
#define IlRxMsgHndHU_20                      3
#define IlRxMsgHndUSS_SLOT_R_CD              4
#define IlRxMsgHndUSS_SLOT_R_AB              5
#define IlRxMsgHndUSS_SLOT_L_CD              6
#define IlRxMsgHndUSS_SLOT_L_AB              7
#define IlRxMsgHndUSS_DE_S                   8
#define IlRxMsgHndUSS_DE_R                   9
#define IlRxMsgHndUSS_DIAG_R                 10
#define IlRxMsgHndUSS_DIAG_F                 11
#define IlRxMsgHndGW_Config                  12
#define IlRxMsgHndGPS_1                      13
#define IlRxMsgHndTBOX_1                     14
#define IlRxMsgHndHU_10                      15
#define IlRxMsgHndHU_14                      16
#define IlRxMsgHndIC_1                       17
#define IlRxMsgHndHU_Speech_1                18
#define IlRxMsgHndHU_6                       19
#define IlRxMsgHndHU_5                       20
#define IlRxMsgHndHU_18                      21
#define IlRxMsgHndPDC_1                      22
#define IlRxMsgHndADV_4                      23
#define IlRxMsgHndADV_1                      24
#define IlRxMsgHndRRDCU_1                    25
#define IlRxMsgHndRLDCU_1                    26
#define IlRxMsgHndPDCU_1                     27
#define IlRxMsgHndDDCU_1                     28
#define IlRxMsgHndPLG_1                      29
#define IlRxMsgHndBCM1_7                     30
#define IlRxMsgHndBCM1_3                     31
#define IlRxMsgHndBCM1_2                     32
#define IlRxMsgHndBCM1_1                     33
#define IlRxMsgHndATC_2                      34
#define IlRxMsgHndDMS_2                      35
#define IlRxMsgHndMCP_1                      36
#define IlRxMsgHndADV_TargetTracing          37
#define IlRxMsgHndADV_PathTracing            38
#define IlRxMsgHndESC_3                      39
#define IlRxMsgHndESC_2                      40
#define IlRxMsgHndABS_3                      41
#define IlRxMsgHndSAS_1                      42
#define IlRxMsgHndABS_2                      43
#define IlRxMsgHndABS_1                      44
#define IlRxMsgHndTCU_3                      45
#define IlRxMsgHndEMS_3                      46
#define IlRxMsgHndADV_P1                     47
#define IlTxMsgHndDebug_CanStaInfo           0
#define IlTxMsgHndDebug_ReloatInfo           1
#define IlTxMsgHndTargetPointInfo            2
#define IlTxMsgHndTargetSlot_CD              3
#define IlTxMsgHndTargetSlot_AB              4
#define IlTxMsgHndUSS_SLOT_R_CD              5
#define IlTxMsgHndUSS_SLOT_R_AB              6
#define IlTxMsgHndUSS_SLOT_L_CD              7
#define IlTxMsgHndUSS_SLOT_L_AB              8
#define IlTxMsgHndUSS_DE_S                   9
#define IlTxMsgHndUSS_DE_R                   10
#define IlTxMsgHndUSS_DE_F                   11
#define IlTxMsgHndUSS_DIAG_R                 12
#define IlTxMsgHndUSS_DIAG_F                 13
#define IlTxMsgHndDR_2                       14
#define IlTxMsgHndDR_1                       15
#define IlTxMsgHndPDC_2                      16
#define IlTxMsgHndPDC_1                      17
#define IlTxMsgHndAVS_1                      18
#define IlTxMsgHndPDC_14                     19
#define IlTxMsgHndPDC_13                     20
#define IlTxMsgHndPDC_12                     21
#define IlTxMsgHndPDC_11                     22
#define IlTxMsgHndPDC_10                     23
#define IlTxMsgHndPDC_9                      24
#define IlTxMsgHndPDC_8                      25
#define IlTxMsgHndPDC_7                      26
#define IlTxMsgHndPDC_6                      27
#define IlTxMsgHndPDC_5                      28
#define IlTxMsgHndPDC_4                      29
#define IlTxMsgHndPDC_3                      30
#define IlTxMsgHndAPS_Slot6                  31
#define IlTxMsgHndAPS_Slot5                  32
#define IlTxMsgHndAPS_Slot4                  33
#define IlTxMsgHndAPS_Slot3                  34
#define IlTxMsgHndAPS_Slot2                  35
#define IlTxMsgHndAPS_Slot1                  36
#define IlTxMsgHndAPS_PSD                    37
#define IlTxMsgHndAPS_Replan_2               38
#define IlTxMsgHndAPS_Replan_1               39
#define IlTxMsgHndRightCurbInfo              40
#define IlTxMsgHndLeftCurbInfo               41
#define IlTxMsgHndFreespace11_ObstacleInfo   42
#define IlTxMsgHndFreespace10_ObstacleInfo   43
#define IlTxMsgHndFreespace9_ObstacleInfo    44
#define IlTxMsgHndFreespace8_ObstacleInfo    45
#define IlTxMsgHndFreespace7_ObstacleInfo    46
#define IlTxMsgHndFreespace6_ObstacleInfo    47
#define IlTxMsgHndFreespace5_ObstacleInfo    48
#define IlTxMsgHndFreespace4_ObstacleInfo    49
#define IlTxMsgHndFreespace3_ObstacleInfo    50
#define IlTxMsgHndFreespace2_ObstacleInfo    51
#define IlTxMsgHndFreespace1_ObstacleInfo    52
#define IlTxMsgHndFreespace0_ObstacleInfo    53
#define IlTxMsgHndAPS_1                      54


/* -----------------------------------------------------------------------------
    &&&~ Signal Handles
 ----------------------------------------------------------------------------- */

#define IlRxSigHndalpha_USS_FL_long          IlRxMsgHndalpha_distance_Long
#define IlRxSigHndalpha_USS_FR_long          IlRxMsgHndalpha_distance_Long
#define IlRxSigHndalpha_USS_RL_long          IlRxMsgHndalpha_distance_Long
#define IlRxSigHndalpha_USS_RR_long          IlRxMsgHndalpha_distance_Long
#define IlRxSigHndalpha_USS_RL               IlRxMsgHndalpha_distance_R
#define IlRxSigHndalpha_USS_RML              IlRxMsgHndalpha_distance_R
#define IlRxSigHndalpha_USS_RMR              IlRxMsgHndalpha_distance_R
#define IlRxSigHndalpha_USS_RR               IlRxMsgHndalpha_distance_R
#define IlRxSigHndalpha_USS_FL               IlRxMsgHndalpha_distance_F
#define IlRxSigHndalpha_USS_FML              IlRxMsgHndalpha_distance_F
#define IlRxSigHndalpha_USS_FMR              IlRxMsgHndalpha_distance_F
#define IlRxSigHndalpha_USS_FR               IlRxMsgHndalpha_distance_F
#define IlRxSigHndScreenPressPosition_X1     IlRxMsgHndHU_20
#define IlRxSigHndScreenPressPosition_Y1     IlRxMsgHndHU_20
#define IlRxSigHndScreenPressPosition_X2     IlRxMsgHndHU_20
#define IlRxSigHndScreenPressPosition_Y2     IlRxMsgHndHU_20
#define IlRxSigHndScreenPressType1           IlRxMsgHndHU_20
#define IlRxSigHndScreenPressType2           IlRxMsgHndHU_20
#define IlRxSigHndUSS_SLOT_R_Cx              IlRxMsgHndUSS_SLOT_R_CD
#define IlRxSigHndUSS_SLOT_R_Cy              IlRxMsgHndUSS_SLOT_R_CD
#define IlRxSigHndUSS_SLOT_R_Dx              IlRxMsgHndUSS_SLOT_R_CD
#define IlRxSigHndUSS_SLOT_R_Dy              IlRxMsgHndUSS_SLOT_R_CD
#define IlRxSigHndUSS_SLOT_R_Ax              IlRxMsgHndUSS_SLOT_R_AB
#define IlRxSigHndUSS_SLOT_R_Ay              IlRxMsgHndUSS_SLOT_R_AB
#define IlRxSigHndUSS_SLOT_R_Bx              IlRxMsgHndUSS_SLOT_R_AB
#define IlRxSigHndUSS_SLOT_R_By              IlRxMsgHndUSS_SLOT_R_AB
#define IlRxSigHndUSS_SLOT_L_Cx              IlRxMsgHndUSS_SLOT_L_CD
#define IlRxSigHndUSS_SLOT_L_Cy              IlRxMsgHndUSS_SLOT_L_CD
#define IlRxSigHndUSS_SLOT_L_Dx              IlRxMsgHndUSS_SLOT_L_CD
#define IlRxSigHndUSS_SLOT_L_Dy              IlRxMsgHndUSS_SLOT_L_CD
#define IlRxSigHndUSS_SLOT_L_Ax              IlRxMsgHndUSS_SLOT_L_AB
#define IlRxSigHndUSS_SLOT_L_AY              IlRxMsgHndUSS_SLOT_L_AB
#define IlRxSigHndUSS_SLOT_L_Bx              IlRxMsgHndUSS_SLOT_L_AB
#define IlRxSigHndUSS_SLOT_L_By              IlRxMsgHndUSS_SLOT_L_AB
#define IlRxSigHndUSS_DE_FLS                 IlRxMsgHndUSS_DE_S
#define IlRxSigHndUSS_DE_FRS                 IlRxMsgHndUSS_DE_S
#define IlRxSigHndUSS_DE_RLS                 IlRxMsgHndUSS_DE_S
#define IlRxSigHndUSS_DE_RRS                 IlRxMsgHndUSS_DE_S
#define IlRxSigHndUSS_DE_RL                  IlRxMsgHndUSS_DE_R
#define IlRxSigHndUSS_DE_RML                 IlRxMsgHndUSS_DE_R
#define IlRxSigHndUSS_DE_RMR                 IlRxMsgHndUSS_DE_R
#define IlRxSigHndUSS_DE_RR                  IlRxMsgHndUSS_DE_R
#define IlRxSigHndUSS_DIAG_RL                IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_RLS               IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_RML               IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_RMR               IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_RR                IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_RRS               IlRxMsgHndUSS_DIAG_R
#define IlRxSigHndUSS_DIAG_FL                IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_DIAG_FLS               IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_DIAG_FML               IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_DIAG_FMR               IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_DIAG_FR                IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_DIAG_FRS               IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndUSS_WORK_MODE              IlRxMsgHndUSS_DIAG_F
#define IlRxSigHndGW_RemoteVehicleMode       IlRxMsgHndGW_Config
#define IlRxSigHndGW_OTAMode                 IlRxMsgHndGW_Config
#define IlRxSigHndGPSTime_Hour               IlRxMsgHndGPS_1
#define IlRxSigHndGPSTime_Minute             IlRxMsgHndGPS_1
#define IlRxSigHndGPSTime_Second             IlRxMsgHndGPS_1
#define IlRxSigHndGPSTime_Year               IlRxMsgHndGPS_1
#define IlRxSigHndGPSTime_Month              IlRxMsgHndGPS_1
#define IlRxSigHndGPSTime_Day                IlRxMsgHndGPS_1
#define IlRxSigHndCheckSum_TBOX_1            IlRxMsgHndTBOX_1
#define IlRxSigHndRemoteMonitoringReq        IlRxMsgHndTBOX_1
#define IlRxSigHndRemoteAVSSharpnessReq      IlRxMsgHndTBOX_1
#define IlRxSigHndRemoteAVSViewModeReq       IlRxMsgHndTBOX_1
#define IlRxSigHndLiveCounter_TBOX_1         IlRxMsgHndTBOX_1
#define IlRxSigHndChecksum_HU_10             IlRxMsgHndHU_10
#define IlRxSigHndHU_PDCBuzzerReq            IlRxMsgHndHU_10
#define IlRxSigHndLiveCounter_HU_10          IlRxMsgHndHU_10
#define IlRxSigHndDisplayTheme               IlRxMsgHndHU_14
#define IlRxSigHndOdometerValue              IlRxMsgHndIC_1
#define IlRxSigHndChecksum_HU_Speech_1       IlRxMsgHndHU_Speech_1
#define IlRxSigHndHU_SpeechReq_AVS           IlRxMsgHndHU_Speech_1
#define IlRxSigHndHU_SpeechReq_AVSViewMode   IlRxMsgHndHU_Speech_1
#define IlRxSigHndHU_SpeechReq_PDC           IlRxMsgHndHU_Speech_1
#define IlRxSigHndLiveCounter_HU_Speech_1    IlRxMsgHndHU_Speech_1
#define IlRxSigHndTargetSelectionCenter_X    IlRxMsgHndHU_6
#define IlRxSigHndTargetSelection_Area       IlRxMsgHndHU_6
#define IlRxSigHndTargetSelectionCenter_Y    IlRxMsgHndHU_6
#define IlRxSigHndTargetSelectionCenter_Angle IlRxMsgHndHU_6
#define IlRxSigHndTargetSelection_ParkType   IlRxMsgHndHU_6
#define IlRxSigHndTargetSelection_ParkDirection IlRxMsgHndHU_6
#define IlRxSigHndTargetSelection_LineAngle  IlRxMsgHndHU_6
#define IlRxSigHndTargetSelection_ConfirmReq IlRxMsgHndHU_6
#define IlRxSigHndParkInSlotSearchModeSet    IlRxMsgHndHU_6
#define IlRxSigHndParkOutDirection           IlRxMsgHndHU_6
#define IlRxSigHndCheckSum_HU_5              IlRxMsgHndHU_5
#define IlRxSigHndAVSFunctionReq             IlRxMsgHndHU_5
#define IlRxSigHndAVSViewModeReq             IlRxMsgHndHU_5
#define IlRxSigHndAVSFunctionExitReq         IlRxMsgHndHU_5
#define IlRxSigHndAVSMonitoringVideoModeReq  IlRxMsgHndHU_5
#define IlRxSigHndDynamicPGSReq              IlRxMsgHndHU_5
#define IlRxSigHndMODReq                     IlRxMsgHndHU_5
#define IlRxSigHndLanguageSet                IlRxMsgHndHU_5
#define IlRxSigHndSwitchScreenResponse_AVS   IlRxMsgHndHU_5
#define IlRxSigHndAVSTurnFollowUpFunctionReq IlRxMsgHndHU_5
#define IlRxSigHndAVSViewtypeReq             IlRxMsgHndHU_5
#define IlRxSigHndLiveCounter_HU_5           IlRxMsgHndHU_5
#define IlRxSigHndChecksum_HU_18             IlRxMsgHndHU_18
#define IlRxSigHndHU_BlindSpotFilledFunctionReq IlRxMsgHndHU_18
#define IlRxSigHndHU_PDCAutoOnFunctionReq    IlRxMsgHndHU_18
#define IlRxSigHndLiveCounter_HU_18          IlRxMsgHndHU_18
#define IlRxSigHndSysSt_PDC                  IlRxMsgHndPDC_1
#define IlRxSigHndErrorSt_PDC                IlRxMsgHndPDC_1
#define IlRxSigHndChecksum_ADV_4             IlRxMsgHndADV_4
#define IlRxSigHndADV_LeftSlotSearchType     IlRxMsgHndADV_4
#define IlRxSigHndADV_RightSlotSearchType    IlRxMsgHndADV_4
#define IlRxSigHndADV_PDCSchedule            IlRxMsgHndADV_4
#define IlRxSigHndADV_Alarm_Position_Front_Left IlRxMsgHndADV_4
#define IlRxSigHndADV_SearchTimeoutCounter   IlRxMsgHndADV_4
#define IlRxSigHndADV_Alarm_Position_Front_Right IlRxMsgHndADV_4
#define IlRxSigHndADV_Alarm_Position_Rear_Left IlRxMsgHndADV_4
#define IlRxSigHndADV_Alarm_Position_Rear_Right IlRxMsgHndADV_4
#define IlRxSigHndLiveCounter_ADV_4          IlRxMsgHndADV_4
#define IlRxSigHndChecksum_ADV_1             IlRxMsgHndADV_1
#define IlRxSigHndADV_ParkType               IlRxMsgHndADV_1
#define IlRxSigHndADV_ParkInSlotSearchMode   IlRxMsgHndADV_1
#define IlRxSigHndADV_ParkStatus             IlRxMsgHndADV_1
#define IlRxSigHndADV_ParkOutDirection       IlRxMsgHndADV_1
#define IlRxSigHndADV_FunctionAbnormalTip    IlRxMsgHndADV_1
#define IlRxSigHndLiveCounter_ADV_1          IlRxMsgHndADV_1
#define IlRxSigHndDoorSt_RR                  IlRxMsgHndRRDCU_1
#define IlRxSigHndDoorSt_RL                  IlRxMsgHndRLDCU_1
#define IlRxSigHndDoorSt_FR                  IlRxMsgHndPDCU_1
#define IlRxSigHndMirrorFoldSt_FR            IlRxMsgHndPDCU_1
#define IlRxSigHndDoorSt_FL                  IlRxMsgHndDDCU_1
#define IlRxSigHndMirrorFoldSt_FL            IlRxMsgHndDDCU_1
#define IlRxSigHndLuggageDoorSt              IlRxMsgHndPLG_1
#define IlRxSigHndRainlntensity              IlRxMsgHndBCM1_7
#define IlRxSigHndBrightness_L               IlRxMsgHndBCM1_7
#define IlRxSigHndBrightness_H               IlRxMsgHndBCM1_7
#define IlRxSigHndEngineHoodSt               IlRxMsgHndBCM1_3
#define IlRxSigHndPowerMode                  IlRxMsgHndBCM1_2
#define IlRxSigHndLowBeamSt_FL               IlRxMsgHndBCM1_1
#define IlRxSigHndLowBeamSt_FR               IlRxMsgHndBCM1_1
#define IlRxSigHndHighBeamSt_FL              IlRxMsgHndBCM1_1
#define IlRxSigHndHighBeamSt_FR              IlRxMsgHndBCM1_1
#define IlRxSigHndAutoLightMode              IlRxMsgHndBCM1_1
#define IlRxSigHndFogLightSt_FL              IlRxMsgHndBCM1_1
#define IlRxSigHndFogLightSt_FR              IlRxMsgHndBCM1_1
#define IlRxSigHndTurningSt_Left             IlRxMsgHndBCM1_1
#define IlRxSigHndTurningSt_right            IlRxMsgHndBCM1_1
#define IlRxSigHndHazardWarningSt            IlRxMsgHndBCM1_1
#define IlRxSigHndWiperSt_Front              IlRxMsgHndBCM1_1
#define IlRxSigHndAmbientTemp                IlRxMsgHndATC_2
#define IlRxSigHndDMS_VehicleModeinfo        IlRxMsgHndDMS_2
#define IlRxSigHndMCP_AVSandFRadarSwitch     IlRxMsgHndMCP_1
#define IlRxSigHndADV_TargetTracingCenter_X  IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_TargetTracingCenter_Y  IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_TargetTracingAngle     IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_TargetTracingLength    IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_TargetTracingWidth     IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_DebugEnabled           IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_TargetTracingAvaialble IlRxMsgHndADV_TargetTracing
#define IlRxSigHndADV_PathTracingCenter_X    IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_PathTracingCenter_Y    IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_PathTracingAngle       IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_PathTracingAvaialble   IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_ShortestDistance       IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_TotalPathNumber        IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_CurrentPathNumber      IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_CurrentDirection       IlRxMsgHndADV_PathTracing
#define IlRxSigHndADV_RemainingDistance      IlRxMsgHndADV_PathTracing
#define IlRxSigHndChecksum_ESC_3             IlRxMsgHndESC_3
#define IlRxSigHndYawRate                    IlRxMsgHndESC_3
#define IlRxSigHndYRSSt                      IlRxMsgHndESC_3
#define IlRxSigHndAcceleration_X             IlRxMsgHndESC_3
#define IlRxSigHndAcceleration_Y             IlRxMsgHndESC_3
#define IlRxSigHndErrorSt_YRS                IlRxMsgHndESC_3
#define IlRxSigHndLiveCounter_ESC_3          IlRxMsgHndESC_3
#define IlRxSigHndChecksum_ESC_2             IlRxMsgHndESC_2
#define IlRxSigHndWorkingSt_EPB              IlRxMsgHndESC_2
#define IlRxSigHndLiveCounter_ESC_2          IlRxMsgHndESC_2
#define IlRxSigHndChecksum_ABS_3             IlRxMsgHndABS_3
#define IlRxSigHndWheelPulse_FL              IlRxMsgHndABS_3
#define IlRxSigHndWheelPulse_FR              IlRxMsgHndABS_3
#define IlRxSigHndWheelPulse_RL              IlRxMsgHndABS_3
#define IlRxSigHndWheelPulse_RR              IlRxMsgHndABS_3
#define IlRxSigHndWheelSpeedDirection_FL     IlRxMsgHndABS_3
#define IlRxSigHndWheelSpeedDirection_FR     IlRxMsgHndABS_3
#define IlRxSigHndWheelSpeedDirection_RL     IlRxMsgHndABS_3
#define IlRxSigHndWheelSpeedDirection_RR     IlRxMsgHndABS_3
#define IlRxSigHndLiveCounter_ABS_3          IlRxMsgHndABS_3
#define IlRxSigHndChecksum_SAS_1             IlRxMsgHndSAS_1
#define IlRxSigHndSteeringWheelAngle         IlRxMsgHndSAS_1
#define IlRxSigHndSteeringWheelAngleSign     IlRxMsgHndSAS_1
#define IlRxSigHndSAS_St                     IlRxMsgHndSAS_1
#define IlRxSigHndLiveCounter_SAS_1          IlRxMsgHndSAS_1
#define IlRxSigHndChecksum_ABS_2             IlRxMsgHndABS_2
#define IlRxSigHndWheelSpeed_RL              IlRxMsgHndABS_2
#define IlRxSigHndWheelSpeed_RR              IlRxMsgHndABS_2
#define IlRxSigHndLiveCounter_ABS_2          IlRxMsgHndABS_2
#define IlRxSigHndChecksum_ABS_1             IlRxMsgHndABS_1
#define IlRxSigHndWheelSpeed_FL              IlRxMsgHndABS_1
#define IlRxSigHndWheelSpeed_FR              IlRxMsgHndABS_1
#define IlRxSigHndVehicleSpeed               IlRxMsgHndABS_1
#define IlRxSigHndDrivingDirection           IlRxMsgHndABS_1
#define IlRxSigHndLiveCounter_ABS_1          IlRxMsgHndABS_1
#define IlRxSigHndChecksum_TCU_3             IlRxMsgHndTCU_3
#define IlRxSigHndLeverInfo                  IlRxMsgHndTCU_3
#define IlRxSigHndLiveCounter_TCU_3          IlRxMsgHndTCU_3
#define IlRxSigHndChecksum_EMS_3             IlRxMsgHndEMS_3
#define IlRxSigHndBrakePedalSt               IlRxMsgHndEMS_3
#define IlRxSigHndLiveCounter_EMS_3          IlRxMsgHndEMS_3
#define IlRxSigHndADV_Pose_X                 IlRxMsgHndADV_P1
#define IlRxSigHndADV_Pose_Y                 IlRxMsgHndADV_P1
#define IlRxSigHndADV_Pose_Angle             IlRxMsgHndADV_P1
#define IlRxSigHndADV_ReplanMode             IlRxMsgHndADV_P1
#define IlRxSigHndADV_ReplanWayPoint         IlRxMsgHndADV_P1
#define IlRxSigHndADV_RealignMode            IlRxMsgHndADV_P1
#define IlRxSigHndADV_RealignWayPoint        IlRxMsgHndADV_P1
#define IlTxSigHndPrivateCanSta              IlTxMsgHndDebug_CanStaInfo
#define IlTxSigHndPubuicCanSta               IlTxMsgHndDebug_CanStaInfo
#define IlTxSigHndCanTaskAlive               IlTxMsgHndDebug_CanStaInfo
#define IlTxSigHndDebug_ReloatDistance_R     IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndDebug_ReloatTheta_R        IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndDebug_ReloatValid_R        IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndDebug_ReloatDistance_L     IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndDebug_ReloatTheta_L        IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndDebug_ReloatValid_L        IlTxMsgHndDebug_ReloatInfo
#define IlTxSigHndFV_TargetPoint_Angle       IlTxMsgHndTargetPointInfo
#define IlTxSigHndFV_TargetPoint_X           IlTxMsgHndTargetPointInfo
#define IlTxSigHndFV_TargetPoint_Y           IlTxMsgHndTargetPointInfo
#define IlTxSigHndTargetSlot_Cx              IlTxMsgHndTargetSlot_CD
#define IlTxSigHndTargetSlot_Cy              IlTxMsgHndTargetSlot_CD
#define IlTxSigHndTargetSlot_Dx              IlTxMsgHndTargetSlot_CD
#define IlTxSigHndTargetSlot_Dy              IlTxMsgHndTargetSlot_CD
#define IlTxSigHndTargetSlot_Ax              IlTxMsgHndTargetSlot_AB
#define IlTxSigHndTargetSlot_Ay              IlTxMsgHndTargetSlot_AB
#define IlTxSigHndTargetSlot_Bx              IlTxMsgHndTargetSlot_AB
#define IlTxSigHndTargetSlot_By              IlTxMsgHndTargetSlot_AB
#define IlTxSigHndUSS_SLOT_R_Cx              IlTxMsgHndUSS_SLOT_R_CD
#define IlTxSigHndUSS_SLOT_R_Cy              IlTxMsgHndUSS_SLOT_R_CD
#define IlTxSigHndUSS_SLOT_R_Dx              IlTxMsgHndUSS_SLOT_R_CD
#define IlTxSigHndUSS_SLOT_R_Dy              IlTxMsgHndUSS_SLOT_R_CD
#define IlTxSigHndUSS_SLOT_R_Ax              IlTxMsgHndUSS_SLOT_R_AB
#define IlTxSigHndUSS_SLOT_R_Ay              IlTxMsgHndUSS_SLOT_R_AB
#define IlTxSigHndUSS_SLOT_R_Bx              IlTxMsgHndUSS_SLOT_R_AB
#define IlTxSigHndUSS_SLOT_R_By              IlTxMsgHndUSS_SLOT_R_AB
#define IlTxSigHndUSS_SLOT_L_Cx              IlTxMsgHndUSS_SLOT_L_CD
#define IlTxSigHndUSS_SLOT_L_Cy              IlTxMsgHndUSS_SLOT_L_CD
#define IlTxSigHndUSS_SLOT_L_Dx              IlTxMsgHndUSS_SLOT_L_CD
#define IlTxSigHndUSS_SLOT_L_Dy              IlTxMsgHndUSS_SLOT_L_CD
#define IlTxSigHndUSS_SLOT_L_Ax              IlTxMsgHndUSS_SLOT_L_AB
#define IlTxSigHndUSS_SLOT_L_AY              IlTxMsgHndUSS_SLOT_L_AB
#define IlTxSigHndUSS_SLOT_L_Bx              IlTxMsgHndUSS_SLOT_L_AB
#define IlTxSigHndUSS_SLOT_L_By              IlTxMsgHndUSS_SLOT_L_AB
#define IlTxSigHndUSS_DE_FLS                 IlTxMsgHndUSS_DE_S
#define IlTxSigHndUSS_DE_FRS                 IlTxMsgHndUSS_DE_S
#define IlTxSigHndUSS_DE_RLS                 IlTxMsgHndUSS_DE_S
#define IlTxSigHndUSS_DE_RRS                 IlTxMsgHndUSS_DE_S
#define IlTxSigHndUSS_DE_RL                  IlTxMsgHndUSS_DE_R
#define IlTxSigHndUSS_DE_RML                 IlTxMsgHndUSS_DE_R
#define IlTxSigHndUSS_DE_RMR                 IlTxMsgHndUSS_DE_R
#define IlTxSigHndUSS_DE_RR                  IlTxMsgHndUSS_DE_R
#define IlTxSigHndUSS_DE_FL                  IlTxMsgHndUSS_DE_F
#define IlTxSigHndUSS_DE_FML                 IlTxMsgHndUSS_DE_F
#define IlTxSigHndUSS_DE_FMR                 IlTxMsgHndUSS_DE_F
#define IlTxSigHndUSS_DE_FR                  IlTxMsgHndUSS_DE_F
#define IlTxSigHndUSS_DIAG_RL                IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_RLS               IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_RML               IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_RMR               IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_RR                IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_RRS               IlTxMsgHndUSS_DIAG_R
#define IlTxSigHndUSS_DIAG_FL                IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_DIAG_FLS               IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_DIAG_FML               IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_DIAG_FMR               IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_DIAG_FR                IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_DIAG_FRS               IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndUSS_WORK_MODE              IlTxMsgHndUSS_DIAG_F
#define IlTxSigHndDR_RAW                     IlTxMsgHndDR_2
#define IlTxSigHndUSS_SLOT_L_DEPTH           IlTxMsgHndDR_2
#define IlTxSigHndUSS_SLOT_R_DEPTH           IlTxMsgHndDR_2
#define IlTxSigHndDR_X                       IlTxMsgHndDR_1
#define IlTxSigHndDR_Y                       IlTxMsgHndDR_1
#define IlTxSigHndSensorBlockageSt_RR        IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_RMR       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_RML       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_RL        IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FR        IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FMR       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FML       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FL        IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FLS       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_FRS       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_RLS       IlTxMsgHndPDC_2
#define IlTxSigHndSensorBlockageSt_RRS       IlTxMsgHndPDC_2
#define IlTxSigHndObjectRange_FLS            IlTxMsgHndPDC_2
#define IlTxSigHndSensorErrorSt_FLS          IlTxMsgHndPDC_2
#define IlTxSigHndObjectRange_FRS            IlTxMsgHndPDC_2
#define IlTxSigHndSensorErrorSt_FRS          IlTxMsgHndPDC_2
#define IlTxSigHndObjectRange_RLS            IlTxMsgHndPDC_2
#define IlTxSigHndSensorErrorSt_RLS          IlTxMsgHndPDC_2
#define IlTxSigHndObjectRange_RRS            IlTxMsgHndPDC_2
#define IlTxSigHndSensorErrorSt_RRS          IlTxMsgHndPDC_2
#define IlTxSigHndParkingSlotDegree_Left     IlTxMsgHndPDC_2
#define IlTxSigHndParkingSlotDegree_Right    IlTxMsgHndPDC_2
#define IlTxSigHndSysSt_PDC                  IlTxMsgHndPDC_1
#define IlTxSigHndErrorSt_PDC                IlTxMsgHndPDC_1
#define IlTxSigHndRadarSysSt_Front           IlTxMsgHndPDC_1
#define IlTxSigHndRadarSysSt_Rear            IlTxMsgHndPDC_1
#define IlTxSigHndBuzeerCmd_PDC              IlTxMsgHndPDC_1
#define IlTxSigHndBuzzerAlarmPosition        IlTxMsgHndPDC_1
#define IlTxSigHndRadarSysSt_FrontSide       IlTxMsgHndPDC_1
#define IlTxSigHndRadarSysSt_RearSide        IlTxMsgHndPDC_1
#define IlTxSigHndBuzzerSwitchSt             IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_RR             IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_RR           IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_RMR            IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_RMR          IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_RML            IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_RML          IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_RL             IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_RL           IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_FR             IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_FR           IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_FMR            IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_FMR          IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_FML            IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_FML          IlTxMsgHndPDC_1
#define IlTxSigHndObjectRange_FL             IlTxMsgHndPDC_1
#define IlTxSigHndSensorErrorSt_FL           IlTxMsgHndPDC_1
#define IlTxSigHndPDCAutoOnFunctionInd       IlTxMsgHndPDC_1
#define IlTxSigHndSwitchScreenRequest_PDC    IlTxMsgHndPDC_1
#define IlTxSigHndPDC_SpeechControlFeedback  IlTxMsgHndPDC_1
#define IlTxSigHndPDC_SearchingSlotPosition  IlTxMsgHndPDC_1
#define IlTxSigHndPDC_FunctionTip            IlTxMsgHndPDC_1
#define IlTxSigHndAVSSt                      IlTxMsgHndAVS_1
#define IlTxSigHndAVSErrorSt                 IlTxMsgHndAVS_1
#define IlTxSigHndAVSViewMode                IlTxMsgHndAVS_1
#define IlTxSigHndAVSViewtype                IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraErrorSt_Front     IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraErrorSt_Rear      IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraErrorSt_Left      IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraErrorSt_Right     IlTxMsgHndAVS_1
#define IlTxSigHndLanguageTypeSt_AVS         IlTxMsgHndAVS_1
#define IlTxSigHndDynamicPGSSt_AVS           IlTxMsgHndAVS_1
#define IlTxSigHndMODSt_AVS                  IlTxMsgHndAVS_1
#define IlTxSigHndMODWarning_Front           IlTxMsgHndAVS_1
#define IlTxSigHndMODWarning_Rear            IlTxMsgHndAVS_1
#define IlTxSigHndAVSTurnLightFollowupFunctionSt IlTxMsgHndAVS_1
#define IlTxSigHndSwitchScreenRequest_AVS    IlTxMsgHndAVS_1
#define IlTxSigHndBlindSpotFilledFunctionInd IlTxMsgHndAVS_1
#define IlTxSigHndFoundSlotBuzzerTip         IlTxMsgHndAVS_1
#define IlTxSigHndAVS_SpeechControlFeedback  IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraBlockageSt_Front  IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraBlockageSt_Rear   IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraBlockageSt_Left   IlTxMsgHndAVS_1
#define IlTxSigHndAVSCameraBlockageSt_Right  IlTxMsgHndAVS_1
#define IlTxSigHndAVS_AbnormalTip            IlTxMsgHndAVS_1
#define IlTxSigHndAVS_CalibrationSt          IlTxMsgHndAVS_1
#define IlTxSigHndAVS_PDWarning_Front        IlTxMsgHndAVS_1
#define IlTxSigHndAVS_PDWarning_Rear         IlTxMsgHndAVS_1
#define IlTxSigHndAVS_RemoteMonitorigFeedback IlTxMsgHndAVS_1
#define IlTxSigHndAVS_RemoteSharpnessFeedback IlTxMsgHndAVS_1
#define IlTxSigHndRemoteMonitoringSharpnessSt_AVS IlTxMsgHndAVS_1
#define IlTxSigHndRemoteMonitoringSt_AVS     IlTxMsgHndAVS_1
#define IlTxSigHndRemoteMonitoringModeSt_AVS IlTxMsgHndAVS_1
#define IlTxSigHndTurnFollowUpFunctionInd    IlTxMsgHndAVS_1
#define IlTxSigHndAVS_RemoteViewModeFeedback IlTxMsgHndAVS_1
#define IlTxSigHndChecksum_PDC_14            IlTxMsgHndPDC_14
#define IlTxSigHndVehicleCoordinateX         IlTxMsgHndPDC_14
#define IlTxSigHndVehicleCoordinateY         IlTxMsgHndPDC_14
#define IlTxSigHndVehicleAngle               IlTxMsgHndPDC_14
#define IlTxSigHndLiveCounter_PDC_14         IlTxMsgHndPDC_14
#define IlTxSigHndChecksum_PDC_13            IlTxMsgHndPDC_13
#define IlTxSigHndCCoordinateY_Right         IlTxMsgHndPDC_13
#define IlTxSigHndCCoordinateX_Right         IlTxMsgHndPDC_13
#define IlTxSigHndDCoordinateY_Right         IlTxMsgHndPDC_13
#define IlTxSigHndDCoordinateX_Right         IlTxMsgHndPDC_13
#define IlTxSigHndLiveCounter_PDC_13         IlTxMsgHndPDC_13
#define IlTxSigHndChecksum_PDC_12            IlTxMsgHndPDC_12
#define IlTxSigHndACoordinateY_Right         IlTxMsgHndPDC_12
#define IlTxSigHndACoordinateX_Right         IlTxMsgHndPDC_12
#define IlTxSigHndBCoordinateY_Right         IlTxMsgHndPDC_12
#define IlTxSigHndBCoordinateX_Right         IlTxMsgHndPDC_12
#define IlTxSigHndLiveCounter_PDC_12         IlTxMsgHndPDC_12
#define IlTxSigHndChecksum_PDC_11            IlTxMsgHndPDC_11
#define IlTxSigHndCCoordinateY_Left          IlTxMsgHndPDC_11
#define IlTxSigHndCCoordinateX_Left          IlTxMsgHndPDC_11
#define IlTxSigHndDCoordinateY_Left          IlTxMsgHndPDC_11
#define IlTxSigHndDCoordinateX_Left          IlTxMsgHndPDC_11
#define IlTxSigHndLiveCounter_PDC_11         IlTxMsgHndPDC_11
#define IlTxSigHndChecksum_PDC_10            IlTxMsgHndPDC_10
#define IlTxSigHndDistanceValue_RLS          IlTxMsgHndPDC_10
#define IlTxSigHndDistanceValue_RRS          IlTxMsgHndPDC_10
#define IlTxSigHndTimeStamp_RLS_RRS          IlTxMsgHndPDC_10
#define IlTxSigHndParkingSlotDepth_Right     IlTxMsgHndPDC_10
#define IlTxSigHndLiveCounter_PDC_10         IlTxMsgHndPDC_10
#define IlTxSigHndChecksum_PDC_9             IlTxMsgHndPDC_9
#define IlTxSigHndDistanceValue_FLS          IlTxMsgHndPDC_9
#define IlTxSigHndDistanceValue_FRS          IlTxMsgHndPDC_9
#define IlTxSigHndTimeStamp_FLS_FRS          IlTxMsgHndPDC_9
#define IlTxSigHndParkingSoltDepth_Left      IlTxMsgHndPDC_9
#define IlTxSigHndLiveCounter_PDC_9          IlTxMsgHndPDC_9
#define IlTxSigHndChecksum_PDC_8             IlTxMsgHndPDC_8
#define IlTxSigHndDistanceValue_RR           IlTxMsgHndPDC_8
#define IlTxSigHndDistanceValue_RMR          IlTxMsgHndPDC_8
#define IlTxSigHndTimeStamp_RMR_RR           IlTxMsgHndPDC_8
#define IlTxSigHndTxRxSt_RR                  IlTxMsgHndPDC_8
#define IlTxSigHndTxRxSt_RMR                 IlTxMsgHndPDC_8
#define IlTxSigHndLiveCounter_PDC_8          IlTxMsgHndPDC_8
#define IlTxSigHndChecksum_PDC_7             IlTxMsgHndPDC_7
#define IlTxSigHndDisstanceValue_RL          IlTxMsgHndPDC_7
#define IlTxSigHndDisstanceValue_RML         IlTxMsgHndPDC_7
#define IlTxSigHndTimeStamp_RML_RL           IlTxMsgHndPDC_7
#define IlTxSigHndTxRxSt_RL                  IlTxMsgHndPDC_7
#define IlTxSigHndTxRxSt_RML                 IlTxMsgHndPDC_7
#define IlTxSigHndLiveCounter_PDC_7          IlTxMsgHndPDC_7
#define IlTxSigHndChecksum_PDC_6             IlTxMsgHndPDC_6
#define IlTxSigHndDistanceValue_FR           IlTxMsgHndPDC_6
#define IlTxSigHndDistanceValue_FMR          IlTxMsgHndPDC_6
#define IlTxSigHndTimeStamp_FMR_FR           IlTxMsgHndPDC_6
#define IlTxSigHndTxRxSt_FR                  IlTxMsgHndPDC_6
#define IlTxSigHndTxRxSt_FMR                 IlTxMsgHndPDC_6
#define IlTxSigHndLiveCounter_PDC_6          IlTxMsgHndPDC_6
#define IlTxSigHndChecksum_PDC_5             IlTxMsgHndPDC_5
#define IlTxSigHndDistanceValue_FL           IlTxMsgHndPDC_5
#define IlTxSigHndDistanceValue_FML          IlTxMsgHndPDC_5
#define IlTxSigHndTimeStamp_FML_FL           IlTxMsgHndPDC_5
#define IlTxSigHndTxRxSt_FL                  IlTxMsgHndPDC_5
#define IlTxSigHndTxRxSt_FML                 IlTxMsgHndPDC_5
#define IlTxSigHndLiveCounter_PDC_5          IlTxMsgHndPDC_5
#define IlTxSigHndChecksum_PDC_4             IlTxMsgHndPDC_4
#define IlTxSigHndFrontObjCoordinateY        IlTxMsgHndPDC_4
#define IlTxSigHndFrontObjCoordinateX        IlTxMsgHndPDC_4
#define IlTxSigHndRearObjCoordinateY         IlTxMsgHndPDC_4
#define IlTxSigHndRearObjCoordinateX         IlTxMsgHndPDC_4
#define IlTxSigHndLiveCounter_PDC_4          IlTxMsgHndPDC_4
#define IlTxSigHndChecksum_PDC_3             IlTxMsgHndPDC_3
#define IlTxSigHndACoordinateY_Left          IlTxMsgHndPDC_3
#define IlTxSigHndACoordinateX_Left          IlTxMsgHndPDC_3
#define IlTxSigHndBCoordinateY_Left          IlTxMsgHndPDC_3
#define IlTxSigHndBCoordinateX_Left          IlTxMsgHndPDC_3
#define IlTxSigHndLiveCounter_PDC_3          IlTxMsgHndPDC_3
#define IlTxSigHndAPS_Slot6CenterPoint_X1    IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot6CenterPoint_Y1    IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot6_LineAngle        IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot6_Length           IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot6_Width            IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot6CenterPoint_Angle IlTxMsgHndAPS_Slot6
#define IlTxSigHndAPS_Slot5CenterPoint_X1    IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot5CenterPoint_Y1    IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot5_LineAngle        IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot5_Length           IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot5_Width            IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot5CenterPoint_Angle IlTxMsgHndAPS_Slot5
#define IlTxSigHndAPS_Slot4CenterPoint_X1    IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot4CenterPoint_Y1    IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot4_LineAngle        IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot4_Length           IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot4_Width            IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot4CenterPoint_Angle IlTxMsgHndAPS_Slot4
#define IlTxSigHndAPS_Slot3CenterPoint_X1    IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot3CenterPoint_Y1    IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot3_LineAngle        IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot3_Length           IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot3_Width            IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot3CenterPoint_Angle IlTxMsgHndAPS_Slot3
#define IlTxSigHndAPS_Slot2CenterPoint_X1    IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot2CenterPoint_Y1    IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot2_LineAngle        IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot2_Length           IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot2_Width            IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot2CenterPoint_Angle IlTxMsgHndAPS_Slot2
#define IlTxSigHndAPS_Slot1CenterPoint_X1    IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1CenterPoint_Y1    IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1_LineAngle        IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1_Length           IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1_Width            IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1CenterPoint_Angle IlTxMsgHndAPS_Slot1
#define IlTxSigHndAPS_Slot1_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot1_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot1_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot1_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot2_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot2_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot2_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot2_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot3_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot3_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot3_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot3_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot4_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot4_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot4_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot4_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot5_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot5_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot5_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot5_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot6_DetectStatus     IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot6_Info             IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot6_ParkType         IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot6_ParkDirection    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot1_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot2_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot3_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot4_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot5_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Slot6_BothSidesInfo    IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_ParkingSlotAvailability IlTxMsgHndAPS_PSD
#define IlTxSigHndAPS_Replan_UpperLineFlag   IlTxMsgHndAPS_Replan_2
#define IlTxSigHndAPS_Replan_UpperLineDistance IlTxMsgHndAPS_Replan_2
#define IlTxSigHndAPS_Replan_UpperLineAngle  IlTxMsgHndAPS_Replan_2
#define IlTxSigHndAPS_Replan_LeftLineFlag    IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_LeftLineDistance IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_LeftLineAngle   IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_RightLineFlag   IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_RightLineDistance IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_RightLineAngle  IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_LeftStatus      IlTxMsgHndAPS_Replan_1
#define IlTxSigHndAPS_Replan_RightStatus     IlTxMsgHndAPS_Replan_1
#define IlTxSigHndRightCurb_StartPointFlag   IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_StartPointX      IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_StartPointY      IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_EndPointFlag     IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_EndPointX        IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_EndPointY        IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_Height           IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_Status           IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_Direction        IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_AngleFlag        IlTxMsgHndRightCurbInfo
#define IlTxSigHndRightCurb_Angle            IlTxMsgHndRightCurbInfo
#define IlTxSigHndLeftCurb_StartPointFlag    IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_StartPointX       IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_StartPointY       IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_EndPointFlag      IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_EndPointX         IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_EndPointY         IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_Height            IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_Status            IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_Direction         IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_AngleFlag         IlTxMsgHndLeftCurbInfo
#define IlTxSigHndLeftCurb_Angle             IlTxMsgHndLeftCurbInfo
#define IlTxSigHndFreespace11_ObstacleStartPointX IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleStartPointY IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleStartPointFlag IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleEndPointX IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleEndPointY IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleEndPointFlag IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleStatus IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleProperty IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace11_ObstacleHeight IlTxMsgHndFreespace11_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleStartPointX IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleStartPointY IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleStartPointFlag IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleEndPointX IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleEndPointY IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleEndPointFlag IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleStatus IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleProperty IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace10_ObstacleHeight IlTxMsgHndFreespace10_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleStartPointX IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleStartPointY IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleStartPointFlag IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleEndPointX IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleEndPointY IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleEndPointFlag IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleStatus  IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleProperty IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace9_ObstacleHeight  IlTxMsgHndFreespace9_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleStartPointX IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleStartPointY IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleStartPointFlag IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleEndPointX IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleEndPointY IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleEndPointFlag IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleStatus  IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleProperty IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace8_ObstacleHeight  IlTxMsgHndFreespace8_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleStartPointX IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleStartPointY IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleStartPointFlag IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleEndPointX IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleEndPointY IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleEndPointFlag IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleStatus  IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleProperty IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace7_ObstacleHeight  IlTxMsgHndFreespace7_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleStartPointX IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleStartPointY IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleStartPointFlag IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleEndPointX IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleEndPointY IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleEndPointFlag IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleStatus  IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleProperty IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace6_ObstacleHeight  IlTxMsgHndFreespace6_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleStartPointX IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleStartPointY IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleStartPointFlag IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleEndPointX IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleEndPointY IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleEndPointFlag IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleStatus  IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleProperty IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace5_ObstacleHeight  IlTxMsgHndFreespace5_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleStartPointX IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleStartPointY IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleStartPointFlag IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleEndPointX IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleEndPointY IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleEndPointFlag IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleStatus  IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleProperty IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace4_ObstacleHeight  IlTxMsgHndFreespace4_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleStartPointX IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleStartPointY IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleStartPointFlag IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleEndPointX IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleEndPointY IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleEndPointFlag IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleStatus  IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleProperty IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace3_ObstacleHeight  IlTxMsgHndFreespace3_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleStartPointX IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleStartPointY IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleStartPointFlag IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleEndPointX IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleEndPointY IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleEndPointFlag IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleStatus  IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleProperty IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace2_ObstacleHeight  IlTxMsgHndFreespace2_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleStartPointX IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleStartPointY IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleStartPointFlag IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleEndPointX IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleEndPointY IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleEndPointFlag IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleStatus  IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleProperty IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace1_ObstacleHeight  IlTxMsgHndFreespace1_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleStartPointX IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleStartPointY IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleStartPointFlag IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleEndPointX IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleEndPointY IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleEndPointFlag IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleStatus  IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleProperty IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndFreespace0_ObstacleHeight  IlTxMsgHndFreespace0_ObstacleInfo
#define IlTxSigHndAPS_Status                 IlTxMsgHndAPS_1
#define IlTxSigHndAPS_ReplanResult           IlTxMsgHndAPS_1
#define IlTxSigHndAPS_RealignResult          IlTxMsgHndAPS_1
#define IlTxSigHndAPS_CloseLoopDetection     IlTxMsgHndAPS_1
#define IlTxSigHndAPS_ReplanType             IlTxMsgHndAPS_1


/* -----------------------------------------------------------------------------
    &&&~ Critical section macros for signals
 ----------------------------------------------------------------------------- */

#define IlEnterCriticalPrivateCanSta()       CanGlobalInterruptDisable()
#define IlLeaveCriticalPrivateCanSta()       CanGlobalInterruptRestore()
#define IlEnterCriticalPubuicCanSta()        CanGlobalInterruptDisable()
#define IlLeaveCriticalPubuicCanSta()        CanGlobalInterruptRestore()
#define IlEnterCriticalCanTaskAlive()        CanGlobalInterruptDisable()
#define IlLeaveCriticalCanTaskAlive()        CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatDistance_R() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatDistance_R() CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatTheta_R() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatTheta_R() CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatValid_R() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatValid_R() CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatDistance_L() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatDistance_L() CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatTheta_L() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatTheta_L() CanGlobalInterruptRestore()
#define IlEnterCriticalDebug_ReloatValid_L() CanGlobalInterruptDisable()
#define IlLeaveCriticalDebug_ReloatValid_L() CanGlobalInterruptRestore()
#define IlEnterCriticalFV_TargetPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalFV_TargetPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalFV_TargetPoint_X()    CanGlobalInterruptDisable()
#define IlLeaveCriticalFV_TargetPoint_X()    CanGlobalInterruptRestore()
#define IlEnterCriticalFV_TargetPoint_Y()    CanGlobalInterruptDisable()
#define IlLeaveCriticalFV_TargetPoint_Y()    CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Cx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Cx()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Cy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Cy()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Dx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Dx()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Dy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Dy()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Ax()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Ax()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Ay()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Ay()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_Bx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_Bx()       CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSlot_By()       CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSlot_By()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Cx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Cx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Cy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Cy()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Dx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Dx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Dy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Dy()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Ax()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Ax()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Ay()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Ay()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_Bx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_Bx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_By()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_By()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Cx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Cx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Cy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Cy()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Dx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Dx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Dy()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Dy()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Ax()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Ax()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_AY()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_AY()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_Bx()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_Bx()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_By()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_By()       CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FLS()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FLS()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FRS()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FRS()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RLS()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RLS()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RRS()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RRS()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RL()           CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RML()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RML()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RMR()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RMR()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_RR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_RR()           CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FL()           CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FML()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FML()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FMR()          CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FMR()          CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DE_FR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DE_FR()           CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RL()         CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RL()         CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RLS()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RLS()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RML()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RML()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RMR()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RMR()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RR()         CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RR()         CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_RRS()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_RRS()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FL()         CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FL()         CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FLS()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FLS()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FML()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FML()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FMR()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FMR()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FR()         CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FR()         CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_DIAG_FRS()        CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_DIAG_FRS()        CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_WORK_MODE()       CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_WORK_MODE()       CanGlobalInterruptRestore()
#define IlEnterCriticalDR_RAW()              CanGlobalInterruptDisable()
#define IlLeaveCriticalDR_RAW()              CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_L_DEPTH()    CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_L_DEPTH()    CanGlobalInterruptRestore()
#define IlEnterCriticalUSS_SLOT_R_DEPTH()    CanGlobalInterruptDisable()
#define IlLeaveCriticalUSS_SLOT_R_DEPTH()    CanGlobalInterruptRestore()
#define IlEnterCriticalDR_X()                CanGlobalInterruptDisable()
#define IlLeaveCriticalDR_X()                CanGlobalInterruptRestore()
#define IlEnterCriticalDR_Y()                CanGlobalInterruptDisable()
#define IlLeaveCriticalDR_Y()                CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RR() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RR() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RMR() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RMR() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RML() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RML() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RL() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RL() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FR() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FR() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FMR() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FMR() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FML() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FML() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FL() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FL() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FLS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FLS() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_FRS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_FRS() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RLS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RLS() CanGlobalInterruptRestore()
#define IlEnterCriticalSensorBlockageSt_RRS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorBlockageSt_RRS() CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FLS()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FLS()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FLS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FLS()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FRS()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FRS()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RLS()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RLS()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RLS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RLS()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RRS()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RRS()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalParkingSlotDegree_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalParkingSlotDegree_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalParkingSlotDegree_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalParkingSlotDegree_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalSysSt_PDC()           CanGlobalInterruptDisable()
#define IlLeaveCriticalSysSt_PDC()           CanGlobalInterruptRestore()
#define IlEnterCriticalErrorSt_PDC()         CanGlobalInterruptDisable()
#define IlLeaveCriticalErrorSt_PDC()         CanGlobalInterruptRestore()
#define IlEnterCriticalRadarSysSt_Front()    CanGlobalInterruptDisable()
#define IlLeaveCriticalRadarSysSt_Front()    CanGlobalInterruptRestore()
#define IlEnterCriticalRadarSysSt_Rear()     CanGlobalInterruptDisable()
#define IlLeaveCriticalRadarSysSt_Rear()     CanGlobalInterruptRestore()
#define IlEnterCriticalBuzeerCmd_PDC()       CanGlobalInterruptDisable()
#define IlLeaveCriticalBuzeerCmd_PDC()       CanGlobalInterruptRestore()
#define IlEnterCriticalBuzzerAlarmPosition() CanGlobalInterruptDisable()
#define IlLeaveCriticalBuzzerAlarmPosition() CanGlobalInterruptRestore()
#define IlEnterCriticalRadarSysSt_FrontSide() CanGlobalInterruptDisable()
#define IlLeaveCriticalRadarSysSt_FrontSide() CanGlobalInterruptRestore()
#define IlEnterCriticalRadarSysSt_RearSide() CanGlobalInterruptDisable()
#define IlLeaveCriticalRadarSysSt_RearSide() CanGlobalInterruptRestore()
#define IlEnterCriticalBuzzerSwitchSt()      CanGlobalInterruptDisable()
#define IlLeaveCriticalBuzzerSwitchSt()      CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RR()      CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RR()      CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RR()    CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RMR()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RMR()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RMR()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RMR()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RML()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RML()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RML()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RML()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_RL()      CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_RL()      CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_RL()    CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_RL()    CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FR()      CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FR()      CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FR()    CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FMR()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FMR()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FMR()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FMR()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FML()     CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FML()     CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FML()   CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FML()   CanGlobalInterruptRestore()
#define IlEnterCriticalObjectRange_FL()      CanGlobalInterruptDisable()
#define IlLeaveCriticalObjectRange_FL()      CanGlobalInterruptRestore()
#define IlEnterCriticalSensorErrorSt_FL()    CanGlobalInterruptDisable()
#define IlLeaveCriticalSensorErrorSt_FL()    CanGlobalInterruptRestore()
#define IlEnterCriticalPDCAutoOnFunctionInd() CanGlobalInterruptDisable()
#define IlLeaveCriticalPDCAutoOnFunctionInd() CanGlobalInterruptRestore()
#define IlEnterCriticalSwitchScreenRequest_PDC() CanGlobalInterruptDisable()
#define IlLeaveCriticalSwitchScreenRequest_PDC() CanGlobalInterruptRestore()
#define IlEnterCriticalPDC_SpeechControlFeedback() CanGlobalInterruptDisable()
#define IlLeaveCriticalPDC_SpeechControlFeedback() CanGlobalInterruptRestore()
#define IlEnterCriticalPDC_SearchingSlotPosition() CanGlobalInterruptDisable()
#define IlLeaveCriticalPDC_SearchingSlotPosition() CanGlobalInterruptRestore()
#define IlEnterCriticalPDC_FunctionTip()     CanGlobalInterruptDisable()
#define IlLeaveCriticalPDC_FunctionTip()     CanGlobalInterruptRestore()
#define IlEnterCriticalAVSSt()               CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSSt()               CanGlobalInterruptRestore()
#define IlEnterCriticalAVSErrorSt()          CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSErrorSt()          CanGlobalInterruptRestore()
#define IlEnterCriticalAVSViewMode()         CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSViewMode()         CanGlobalInterruptRestore()
#define IlEnterCriticalAVSViewtype()         CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSViewtype()         CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraErrorSt_Front() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraErrorSt_Front() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraErrorSt_Rear() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraErrorSt_Rear() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraErrorSt_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraErrorSt_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraErrorSt_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraErrorSt_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalLanguageTypeSt_AVS()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLanguageTypeSt_AVS()  CanGlobalInterruptRestore()
#define IlEnterCriticalDynamicPGSSt_AVS()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDynamicPGSSt_AVS()    CanGlobalInterruptRestore()
#define IlEnterCriticalMODSt_AVS()           CanGlobalInterruptDisable()
#define IlLeaveCriticalMODSt_AVS()           CanGlobalInterruptRestore()
#define IlEnterCriticalMODWarning_Front()    CanGlobalInterruptDisable()
#define IlLeaveCriticalMODWarning_Front()    CanGlobalInterruptRestore()
#define IlEnterCriticalMODWarning_Rear()     CanGlobalInterruptDisable()
#define IlLeaveCriticalMODWarning_Rear()     CanGlobalInterruptRestore()
#define IlEnterCriticalAVSTurnLightFollowupFunctionSt() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSTurnLightFollowupFunctionSt() CanGlobalInterruptRestore()
#define IlEnterCriticalSwitchScreenRequest_AVS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSwitchScreenRequest_AVS() CanGlobalInterruptRestore()
#define IlEnterCriticalBlindSpotFilledFunctionInd() CanGlobalInterruptDisable()
#define IlLeaveCriticalBlindSpotFilledFunctionInd() CanGlobalInterruptRestore()
#define IlEnterCriticalFoundSlotBuzzerTip()  CanGlobalInterruptDisable()
#define IlLeaveCriticalFoundSlotBuzzerTip()  CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_SpeechControlFeedback() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_SpeechControlFeedback() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraBlockageSt_Front() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraBlockageSt_Front() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraBlockageSt_Rear() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraBlockageSt_Rear() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraBlockageSt_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraBlockageSt_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSCameraBlockageSt_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSCameraBlockageSt_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_AbnormalTip()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_AbnormalTip()     CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_CalibrationSt()   CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_CalibrationSt()   CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_PDWarning_Front() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_PDWarning_Front() CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_PDWarning_Rear()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_PDWarning_Rear()  CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_RemoteMonitorigFeedback() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_RemoteMonitorigFeedback() CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_RemoteSharpnessFeedback() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_RemoteSharpnessFeedback() CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteMonitoringSharpnessSt_AVS() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteMonitoringSharpnessSt_AVS() CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteMonitoringSt_AVS() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteMonitoringSt_AVS() CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteMonitoringModeSt_AVS() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteMonitoringModeSt_AVS() CanGlobalInterruptRestore()
#define IlEnterCriticalTurnFollowUpFunctionInd() CanGlobalInterruptDisable()
#define IlLeaveCriticalTurnFollowUpFunctionInd() CanGlobalInterruptRestore()
#define IlEnterCriticalAVS_RemoteViewModeFeedback() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVS_RemoteViewModeFeedback() CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_14()     CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_14()     CanGlobalInterruptRestore()
#define IlEnterCriticalVehicleCoordinateX()  CanGlobalInterruptDisable()
#define IlLeaveCriticalVehicleCoordinateX()  CanGlobalInterruptRestore()
#define IlEnterCriticalVehicleCoordinateY()  CanGlobalInterruptDisable()
#define IlLeaveCriticalVehicleCoordinateY()  CanGlobalInterruptRestore()
#define IlEnterCriticalVehicleAngle()        CanGlobalInterruptDisable()
#define IlLeaveCriticalVehicleAngle()        CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_14()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_14()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_13()     CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_13()     CanGlobalInterruptRestore()
#define IlEnterCriticalCCoordinateY_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalCCoordinateY_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalCCoordinateX_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalCCoordinateX_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalDCoordinateY_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalDCoordinateY_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalDCoordinateX_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalDCoordinateX_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_13()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_13()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_12()     CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_12()     CanGlobalInterruptRestore()
#define IlEnterCriticalACoordinateY_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalACoordinateY_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalACoordinateX_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalACoordinateX_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalBCoordinateY_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalBCoordinateY_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalBCoordinateX_Right()  CanGlobalInterruptDisable()
#define IlLeaveCriticalBCoordinateX_Right()  CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_12()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_12()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_11()     CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_11()     CanGlobalInterruptRestore()
#define IlEnterCriticalCCoordinateY_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalCCoordinateY_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalCCoordinateX_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalCCoordinateX_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalDCoordinateY_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDCoordinateY_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalDCoordinateX_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDCoordinateX_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_11()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_11()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_10()     CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_10()     CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_RLS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_RLS()   CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_RRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_RRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_RLS_RRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_RLS_RRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalParkingSlotDepth_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalParkingSlotDepth_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_10()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_10()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_9()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_9()      CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FLS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FLS()   CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_FLS_FRS()   CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_FLS_FRS()   CanGlobalInterruptRestore()
#define IlEnterCriticalParkingSoltDepth_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalParkingSoltDepth_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_9()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_9()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_8()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_8()      CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_RR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_RR()    CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_RMR()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_RMR()   CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_RMR_RR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_RMR_RR()    CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_RR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_RR()           CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_RMR()          CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_RMR()          CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_8()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_8()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_7()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_7()      CanGlobalInterruptRestore()
#define IlEnterCriticalDisstanceValue_RL()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDisstanceValue_RL()   CanGlobalInterruptRestore()
#define IlEnterCriticalDisstanceValue_RML()  CanGlobalInterruptDisable()
#define IlLeaveCriticalDisstanceValue_RML()  CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_RML_RL()    CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_RML_RL()    CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_RL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_RL()           CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_RML()          CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_RML()          CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_7()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_7()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_6()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_6()      CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FR()    CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FMR()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FMR()   CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_FMR_FR()    CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_FMR_FR()    CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_FR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_FR()           CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_FMR()          CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_FMR()          CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_6()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_6()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_5()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_5()      CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FL()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FL()    CanGlobalInterruptRestore()
#define IlEnterCriticalDistanceValue_FML()   CanGlobalInterruptDisable()
#define IlLeaveCriticalDistanceValue_FML()   CanGlobalInterruptRestore()
#define IlEnterCriticalTimeStamp_FML_FL()    CanGlobalInterruptDisable()
#define IlLeaveCriticalTimeStamp_FML_FL()    CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_FL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_FL()           CanGlobalInterruptRestore()
#define IlEnterCriticalTxRxSt_FML()          CanGlobalInterruptDisable()
#define IlLeaveCriticalTxRxSt_FML()          CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_5()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_5()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_4()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_4()      CanGlobalInterruptRestore()
#define IlEnterCriticalFrontObjCoordinateY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFrontObjCoordinateY() CanGlobalInterruptRestore()
#define IlEnterCriticalFrontObjCoordinateX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFrontObjCoordinateX() CanGlobalInterruptRestore()
#define IlEnterCriticalRearObjCoordinateY()  CanGlobalInterruptDisable()
#define IlLeaveCriticalRearObjCoordinateY()  CanGlobalInterruptRestore()
#define IlEnterCriticalRearObjCoordinateX()  CanGlobalInterruptDisable()
#define IlLeaveCriticalRearObjCoordinateX()  CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_4()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_4()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_PDC_3()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_PDC_3()      CanGlobalInterruptRestore()
#define IlEnterCriticalACoordinateY_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalACoordinateY_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalACoordinateX_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalACoordinateX_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalBCoordinateY_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalBCoordinateY_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalBCoordinateX_Left()   CanGlobalInterruptDisable()
#define IlLeaveCriticalBCoordinateX_Left()   CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_PDC_3()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_PDC_3()   CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1CenterPoint_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1CenterPoint_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1CenterPoint_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1CenterPoint_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_Length()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_Length()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_Width()     CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_Width()     CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1CenterPoint_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1CenterPoint_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_DetectStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_DetectStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_Info()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_Info()      CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_ParkType()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_ParkType()  CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot1_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot1_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot2_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot2_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot3_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot3_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot4_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot4_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot5_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot5_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Slot6_BothSidesInfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Slot6_BothSidesInfo() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_ParkingSlotAvailability() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_ParkingSlotAvailability() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_UpperLineFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_UpperLineFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_UpperLineDistance() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_UpperLineDistance() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_UpperLineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_UpperLineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_LeftLineFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_LeftLineFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_LeftLineDistance() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_LeftLineDistance() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_LeftLineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_LeftLineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_RightLineFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_RightLineFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_RightLineDistance() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_RightLineDistance() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_RightLineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_RightLineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_LeftStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_LeftStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Replan_RightStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Replan_RightStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_StartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_StartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_StartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_StartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_StartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_StartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_EndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_EndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_EndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_EndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_EndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_EndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_Height()    CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_Height()    CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_Status()    CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_Status()    CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_Direction() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_Direction() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_AngleFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_AngleFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalRightCurb_Angle()     CanGlobalInterruptDisable()
#define IlLeaveCriticalRightCurb_Angle()     CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_StartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_StartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_StartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_StartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_StartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_StartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_EndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_EndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_EndPointX()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_EndPointX()  CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_EndPointY()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_EndPointY()  CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_Height()     CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_Height()     CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_Status()     CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_Status()     CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_Direction()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_Direction()  CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_AngleFlag()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_AngleFlag()  CanGlobalInterruptRestore()
#define IlEnterCriticalLeftCurb_Angle()      CanGlobalInterruptDisable()
#define IlLeaveCriticalLeftCurb_Angle()      CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace11_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace11_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace10_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace10_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace9_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace9_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace8_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace8_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace7_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace7_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace6_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace6_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace5_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace5_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace4_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace4_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace3_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace3_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace2_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace2_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace1_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace1_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleStartPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleStartPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleStartPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleStartPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleStartPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleStartPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleEndPointX() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleEndPointX() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleEndPointY() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleEndPointY() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleEndPointFlag() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleEndPointFlag() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleStatus() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleStatus() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleProperty() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleProperty() CanGlobalInterruptRestore()
#define IlEnterCriticalFreespace0_ObstacleHeight() CanGlobalInterruptDisable()
#define IlLeaveCriticalFreespace0_ObstacleHeight() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_Status()          CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_Status()          CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_ReplanResult()    CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_ReplanResult()    CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_RealignResult()   CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_RealignResult()   CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_CloseLoopDetection() CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_CloseLoopDetection() CanGlobalInterruptRestore()
#define IlEnterCriticalAPS_ReplanType()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAPS_ReplanType()      CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FL_long()   CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FL_long()   CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FR_long()   CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FR_long()   CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RL_long()   CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RL_long()   CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RR_long()   CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RR_long()   CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RL()        CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RL()        CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RML()       CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RML()       CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RMR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RMR()       CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_RR()        CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_RR()        CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FL()        CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FL()        CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FML()       CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FML()       CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FMR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FMR()       CanGlobalInterruptRestore()
#define IlEnterCriticalalpha_USS_FR()        CanGlobalInterruptDisable()
#define IlLeaveCriticalalpha_USS_FR()        CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressPosition_X1() CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressPosition_X1() CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressPosition_Y1() CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressPosition_Y1() CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressPosition_X2() CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressPosition_X2() CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressPosition_Y2() CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressPosition_Y2() CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressType1()    CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressType1()    CanGlobalInterruptRestore()
#define IlEnterCriticalScreenPressType2()    CanGlobalInterruptDisable()
#define IlLeaveCriticalScreenPressType2()    CanGlobalInterruptRestore()
#define IlEnterCriticalGW_RemoteVehicleMode() CanGlobalInterruptDisable()
#define IlLeaveCriticalGW_RemoteVehicleMode() CanGlobalInterruptRestore()
#define IlEnterCriticalGW_OTAMode()          CanGlobalInterruptDisable()
#define IlLeaveCriticalGW_OTAMode()          CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Hour()        CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Hour()        CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Minute()      CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Minute()      CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Second()      CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Second()      CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Year()        CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Year()        CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Month()       CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Month()       CanGlobalInterruptRestore()
#define IlEnterCriticalGPSTime_Day()         CanGlobalInterruptDisable()
#define IlLeaveCriticalGPSTime_Day()         CanGlobalInterruptRestore()
#define IlEnterCriticalCheckSum_TBOX_1()     CanGlobalInterruptDisable()
#define IlLeaveCriticalCheckSum_TBOX_1()     CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteMonitoringReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteMonitoringReq() CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteAVSSharpnessReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteAVSSharpnessReq() CanGlobalInterruptRestore()
#define IlEnterCriticalRemoteAVSViewModeReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalRemoteAVSViewModeReq() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_TBOX_1()  CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_TBOX_1()  CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_HU_10()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_HU_10()      CanGlobalInterruptRestore()
#define IlEnterCriticalHU_PDCBuzzerReq()     CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_PDCBuzzerReq()     CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_HU_10()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_HU_10()   CanGlobalInterruptRestore()
#define IlEnterCriticalDisplayTheme()        CanGlobalInterruptDisable()
#define IlLeaveCriticalDisplayTheme()        CanGlobalInterruptRestore()
#define IlEnterCriticalOdometerValue()       CanGlobalInterruptDisable()
#define IlLeaveCriticalOdometerValue()       CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_HU_Speech_1() CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_HU_Speech_1() CanGlobalInterruptRestore()
#define IlEnterCriticalHU_SpeechReq_AVS()    CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_SpeechReq_AVS()    CanGlobalInterruptRestore()
#define IlEnterCriticalHU_SpeechReq_AVSViewMode() CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_SpeechReq_AVSViewMode() CanGlobalInterruptRestore()
#define IlEnterCriticalHU_SpeechReq_PDC()    CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_SpeechReq_PDC()    CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_HU_Speech_1() CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_HU_Speech_1() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelectionCenter_X() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelectionCenter_X() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelection_Area() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelection_Area() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelectionCenter_Y() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelectionCenter_Y() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelectionCenter_Angle() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelectionCenter_Angle() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelection_ParkType() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelection_ParkType() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelection_ParkDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelection_ParkDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelection_LineAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelection_LineAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalTargetSelection_ConfirmReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalTargetSelection_ConfirmReq() CanGlobalInterruptRestore()
#define IlEnterCriticalParkInSlotSearchModeSet() CanGlobalInterruptDisable()
#define IlLeaveCriticalParkInSlotSearchModeSet() CanGlobalInterruptRestore()
#define IlEnterCriticalParkOutDirection()    CanGlobalInterruptDisable()
#define IlLeaveCriticalParkOutDirection()    CanGlobalInterruptRestore()
#define IlEnterCriticalCheckSum_HU_5()       CanGlobalInterruptDisable()
#define IlLeaveCriticalCheckSum_HU_5()       CanGlobalInterruptRestore()
#define IlEnterCriticalAVSFunctionReq()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSFunctionReq()      CanGlobalInterruptRestore()
#define IlEnterCriticalAVSViewModeReq()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSViewModeReq()      CanGlobalInterruptRestore()
#define IlEnterCriticalAVSFunctionExitReq()  CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSFunctionExitReq()  CanGlobalInterruptRestore()
#define IlEnterCriticalAVSMonitoringVideoModeReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSMonitoringVideoModeReq() CanGlobalInterruptRestore()
#define IlEnterCriticalDynamicPGSReq()       CanGlobalInterruptDisable()
#define IlLeaveCriticalDynamicPGSReq()       CanGlobalInterruptRestore()
#define IlEnterCriticalMODReq()              CanGlobalInterruptDisable()
#define IlLeaveCriticalMODReq()              CanGlobalInterruptRestore()
#define IlEnterCriticalLanguageSet()         CanGlobalInterruptDisable()
#define IlLeaveCriticalLanguageSet()         CanGlobalInterruptRestore()
#define IlEnterCriticalSwitchScreenResponse_AVS() CanGlobalInterruptDisable()
#define IlLeaveCriticalSwitchScreenResponse_AVS() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSTurnFollowUpFunctionReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSTurnFollowUpFunctionReq() CanGlobalInterruptRestore()
#define IlEnterCriticalAVSViewtypeReq()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAVSViewtypeReq()      CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_HU_5()    CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_HU_5()    CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_HU_18()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_HU_18()      CanGlobalInterruptRestore()
#define IlEnterCriticalHU_BlindSpotFilledFunctionReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_BlindSpotFilledFunctionReq() CanGlobalInterruptRestore()
#define IlEnterCriticalHU_PDCAutoOnFunctionReq() CanGlobalInterruptDisable()
#define IlLeaveCriticalHU_PDCAutoOnFunctionReq() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_HU_18()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_HU_18()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ADV_4()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ADV_4()      CanGlobalInterruptRestore()
#define IlEnterCriticalADV_LeftSlotSearchType() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_LeftSlotSearchType() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_RightSlotSearchType() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_RightSlotSearchType() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_PDCSchedule()     CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_PDCSchedule()     CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Alarm_Position_Front_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Alarm_Position_Front_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_SearchTimeoutCounter() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_SearchTimeoutCounter() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Alarm_Position_Front_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Alarm_Position_Front_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Alarm_Position_Rear_Left() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Alarm_Position_Rear_Left() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Alarm_Position_Rear_Right() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Alarm_Position_Rear_Right() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ADV_4()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ADV_4()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ADV_1()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ADV_1()      CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ParkType()        CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ParkType()        CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ParkInSlotSearchMode() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ParkInSlotSearchMode() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ParkStatus()      CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ParkStatus()      CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ParkOutDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ParkOutDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_FunctionAbnormalTip() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_FunctionAbnormalTip() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ADV_1()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ADV_1()   CanGlobalInterruptRestore()
#define IlEnterCriticalDoorSt_RR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalDoorSt_RR()           CanGlobalInterruptRestore()
#define IlEnterCriticalDoorSt_RL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalDoorSt_RL()           CanGlobalInterruptRestore()
#define IlEnterCriticalDoorSt_FR()           CanGlobalInterruptDisable()
#define IlLeaveCriticalDoorSt_FR()           CanGlobalInterruptRestore()
#define IlEnterCriticalMirrorFoldSt_FR()     CanGlobalInterruptDisable()
#define IlLeaveCriticalMirrorFoldSt_FR()     CanGlobalInterruptRestore()
#define IlEnterCriticalDoorSt_FL()           CanGlobalInterruptDisable()
#define IlLeaveCriticalDoorSt_FL()           CanGlobalInterruptRestore()
#define IlEnterCriticalMirrorFoldSt_FL()     CanGlobalInterruptDisable()
#define IlLeaveCriticalMirrorFoldSt_FL()     CanGlobalInterruptRestore()
#define IlEnterCriticalLuggageDoorSt()       CanGlobalInterruptDisable()
#define IlLeaveCriticalLuggageDoorSt()       CanGlobalInterruptRestore()
#define IlEnterCriticalRainlntensity()       CanGlobalInterruptDisable()
#define IlLeaveCriticalRainlntensity()       CanGlobalInterruptRestore()
#define IlEnterCriticalBrightness_L()        CanGlobalInterruptDisable()
#define IlLeaveCriticalBrightness_L()        CanGlobalInterruptRestore()
#define IlEnterCriticalBrightness_H()        CanGlobalInterruptDisable()
#define IlLeaveCriticalBrightness_H()        CanGlobalInterruptRestore()
#define IlEnterCriticalEngineHoodSt()        CanGlobalInterruptDisable()
#define IlLeaveCriticalEngineHoodSt()        CanGlobalInterruptRestore()
#define IlEnterCriticalPowerMode()           CanGlobalInterruptDisable()
#define IlLeaveCriticalPowerMode()           CanGlobalInterruptRestore()
#define IlEnterCriticalLowBeamSt_FL()        CanGlobalInterruptDisable()
#define IlLeaveCriticalLowBeamSt_FL()        CanGlobalInterruptRestore()
#define IlEnterCriticalLowBeamSt_FR()        CanGlobalInterruptDisable()
#define IlLeaveCriticalLowBeamSt_FR()        CanGlobalInterruptRestore()
#define IlEnterCriticalHighBeamSt_FL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalHighBeamSt_FL()       CanGlobalInterruptRestore()
#define IlEnterCriticalHighBeamSt_FR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalHighBeamSt_FR()       CanGlobalInterruptRestore()
#define IlEnterCriticalAutoLightMode()       CanGlobalInterruptDisable()
#define IlLeaveCriticalAutoLightMode()       CanGlobalInterruptRestore()
#define IlEnterCriticalFogLightSt_FL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalFogLightSt_FL()       CanGlobalInterruptRestore()
#define IlEnterCriticalFogLightSt_FR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalFogLightSt_FR()       CanGlobalInterruptRestore()
#define IlEnterCriticalTurningSt_Left()      CanGlobalInterruptDisable()
#define IlLeaveCriticalTurningSt_Left()      CanGlobalInterruptRestore()
#define IlEnterCriticalTurningSt_right()     CanGlobalInterruptDisable()
#define IlLeaveCriticalTurningSt_right()     CanGlobalInterruptRestore()
#define IlEnterCriticalHazardWarningSt()     CanGlobalInterruptDisable()
#define IlLeaveCriticalHazardWarningSt()     CanGlobalInterruptRestore()
#define IlEnterCriticalWiperSt_Front()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWiperSt_Front()       CanGlobalInterruptRestore()
#define IlEnterCriticalAmbientTemp()         CanGlobalInterruptDisable()
#define IlLeaveCriticalAmbientTemp()         CanGlobalInterruptRestore()
#define IlEnterCriticalDMS_VehicleModeinfo() CanGlobalInterruptDisable()
#define IlLeaveCriticalDMS_VehicleModeinfo() CanGlobalInterruptRestore()
#define IlEnterCriticalMCP_AVSandFRadarSwitch() CanGlobalInterruptDisable()
#define IlLeaveCriticalMCP_AVSandFRadarSwitch() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingCenter_X() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingCenter_X() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingCenter_Y() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingCenter_Y() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingLength() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingLength() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingWidth() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingWidth() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_DebugEnabled()    CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_DebugEnabled()    CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TargetTracingAvaialble() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TargetTracingAvaialble() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_PathTracingCenter_X() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_PathTracingCenter_X() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_PathTracingCenter_Y() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_PathTracingCenter_Y() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_PathTracingAngle() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_PathTracingAngle() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_PathTracingAvaialble() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_PathTracingAvaialble() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ShortestDistance() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ShortestDistance() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_TotalPathNumber() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_TotalPathNumber() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_CurrentPathNumber() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_CurrentPathNumber() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_CurrentDirection() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_CurrentDirection() CanGlobalInterruptRestore()
#define IlEnterCriticalADV_RemainingDistance() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_RemainingDistance() CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ESC_3()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ESC_3()      CanGlobalInterruptRestore()
#define IlEnterCriticalYawRate()             CanGlobalInterruptDisable()
#define IlLeaveCriticalYawRate()             CanGlobalInterruptRestore()
#define IlEnterCriticalYRSSt()               CanGlobalInterruptDisable()
#define IlLeaveCriticalYRSSt()               CanGlobalInterruptRestore()
#define IlEnterCriticalAcceleration_X()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAcceleration_X()      CanGlobalInterruptRestore()
#define IlEnterCriticalAcceleration_Y()      CanGlobalInterruptDisable()
#define IlLeaveCriticalAcceleration_Y()      CanGlobalInterruptRestore()
#define IlEnterCriticalErrorSt_YRS()         CanGlobalInterruptDisable()
#define IlLeaveCriticalErrorSt_YRS()         CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ESC_3()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ESC_3()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ESC_2()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ESC_2()      CanGlobalInterruptRestore()
#define IlEnterCriticalWorkingSt_EPB()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWorkingSt_EPB()       CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ESC_2()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ESC_2()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ABS_3()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ABS_3()      CanGlobalInterruptRestore()
#define IlEnterCriticalWheelPulse_FL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelPulse_FL()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelPulse_FR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelPulse_FR()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelPulse_RL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelPulse_RL()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelPulse_RR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelPulse_RR()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeedDirection_FL() CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeedDirection_FL() CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeedDirection_FR() CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeedDirection_FR() CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeedDirection_RL() CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeedDirection_RL() CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeedDirection_RR() CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeedDirection_RR() CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ABS_3()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ABS_3()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_SAS_1()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_SAS_1()      CanGlobalInterruptRestore()
#define IlEnterCriticalSteeringWheelAngle()  CanGlobalInterruptDisable()
#define IlLeaveCriticalSteeringWheelAngle()  CanGlobalInterruptRestore()
#define IlEnterCriticalSteeringWheelAngleSign() CanGlobalInterruptDisable()
#define IlLeaveCriticalSteeringWheelAngleSign() CanGlobalInterruptRestore()
#define IlEnterCriticalSAS_St()              CanGlobalInterruptDisable()
#define IlLeaveCriticalSAS_St()              CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_SAS_1()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_SAS_1()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ABS_2()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ABS_2()      CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeed_RL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeed_RL()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeed_RR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeed_RR()       CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ABS_2()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ABS_2()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_ABS_1()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_ABS_1()      CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeed_FL()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeed_FL()       CanGlobalInterruptRestore()
#define IlEnterCriticalWheelSpeed_FR()       CanGlobalInterruptDisable()
#define IlLeaveCriticalWheelSpeed_FR()       CanGlobalInterruptRestore()
#define IlEnterCriticalVehicleSpeed()        CanGlobalInterruptDisable()
#define IlLeaveCriticalVehicleSpeed()        CanGlobalInterruptRestore()
#define IlEnterCriticalDrivingDirection()    CanGlobalInterruptDisable()
#define IlLeaveCriticalDrivingDirection()    CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_ABS_1()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_ABS_1()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_TCU_3()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_TCU_3()      CanGlobalInterruptRestore()
#define IlEnterCriticalLeverInfo()           CanGlobalInterruptDisable()
#define IlLeaveCriticalLeverInfo()           CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_TCU_3()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_TCU_3()   CanGlobalInterruptRestore()
#define IlEnterCriticalChecksum_EMS_3()      CanGlobalInterruptDisable()
#define IlLeaveCriticalChecksum_EMS_3()      CanGlobalInterruptRestore()
#define IlEnterCriticalBrakePedalSt()        CanGlobalInterruptDisable()
#define IlLeaveCriticalBrakePedalSt()        CanGlobalInterruptRestore()
#define IlEnterCriticalLiveCounter_EMS_3()   CanGlobalInterruptDisable()
#define IlLeaveCriticalLiveCounter_EMS_3()   CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Pose_X()          CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Pose_X()          CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Pose_Y()          CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Pose_Y()          CanGlobalInterruptRestore()
#define IlEnterCriticalADV_Pose_Angle()      CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_Pose_Angle()      CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ReplanMode()      CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ReplanMode()      CanGlobalInterruptRestore()
#define IlEnterCriticalADV_ReplanWayPoint()  CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_ReplanWayPoint()  CanGlobalInterruptRestore()
#define IlEnterCriticalADV_RealignMode()     CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_RealignMode()     CanGlobalInterruptRestore()
#define IlEnterCriticalADV_RealignWayPoint() CanGlobalInterruptDisable()
#define IlLeaveCriticalADV_RealignWayPoint() CanGlobalInterruptRestore()


/* -----------------------------------------------------------------------------
    &&&~ Access to RxTimeout flags
 ----------------------------------------------------------------------------- */

#define IlGetSteeringWheelAngleRxTimeout()   (((vuint8) (ilRxTimeoutFlags[0] & (vuint8) 0x01)) != (vuint8) 0x00)
#define IlGetSteeringWheelAngleSignRxTimeout() (((vuint8) (ilRxTimeoutFlags[0] & (vuint8) 0x02)) != (vuint8) 0x00)
#define IlGetLeverInfoRxTimeout()            (((vuint8) (ilRxTimeoutFlags[0] & (vuint8) 0x04)) != (vuint8) 0x00)
#define IlSetSteeringWheelAngleRxTimeout()   (ilRxTimeoutFlags[0] |= (vuint8) 0x01)
#define IlSetSteeringWheelAngleSignRxTimeout() (ilRxTimeoutFlags[0] |= (vuint8) 0x02)
#define IlSetLeverInfoRxTimeout()            (ilRxTimeoutFlags[0] |= (vuint8) 0x04)
#define IlClrSteeringWheelAngleRxTimeout()   (ilRxTimeoutFlags[0] &= (vuint8) (0xFF & (vuint8) 0xFE))
#define IlClrSteeringWheelAngleSignRxTimeout() (ilRxTimeoutFlags[0] &= (vuint8) (0xFF & (vuint8) 0xFD))
#define IlClrLeverInfoRxTimeout()            (ilRxTimeoutFlags[0] &= (vuint8) (0xFF & (vuint8) 0xFB))


/* -----------------------------------------------------------------------------
    &&&~ Declaration Confirmation Functions
 ----------------------------------------------------------------------------- */

/* Application signal confirmation callback functions */


/* -----------------------------------------------------------------------------
    &&&~ Declaration Indication Functions
 ----------------------------------------------------------------------------- */

/* Application signal indication callback functions */


/* -----------------------------------------------------------------------------
    &&&~ Declaration User Timeout Functions
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
#endif



/* -----------------------------------------------------------------------------
    &&&~ ExternDecl Internal Get Tx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:   20,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Cx(void);
#endif

/* Handle:   21,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Cy(void);
#endif

/* Handle:   22,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Dx(void);
#endif

/* Handle:   23,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Dy(void);
#endif

/* Handle:   24,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Ax(void);
#endif

/* Handle:   25,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Ay(void);
#endif

/* Handle:   26,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_Bx(void);
#endif

/* Handle:   27,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_By(void);
#endif

/* Handle:   28,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Cx(void);
#endif

/* Handle:   29,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Cy(void);
#endif

/* Handle:   30,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Dx(void);
#endif

/* Handle:   31,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Dy(void);
#endif

/* Handle:   32,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Ax(void);
#endif

/* Handle:   33,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_AY(void);
#endif

/* Handle:   34,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_Bx(void);
#endif

/* Handle:   35,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_By(void);
#endif

/* Handle:   36,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FLS(void);
#endif

/* Handle:   37,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FRS(void);
#endif

/* Handle:   38,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RLS(void);
#endif

/* Handle:   39,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RRS(void);
#endif

/* Handle:   40,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RL(void);
#endif

/* Handle:   41,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RML(void);
#endif

/* Handle:   42,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RMR(void);
#endif

/* Handle:   43,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_RR(void);
#endif

/* Handle:   44,Name:                      USS_DE_FL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FL(void);
#endif

/* Handle:   45,Name:                     USS_DE_FML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FML(void);
#endif

/* Handle:   46,Name:                     USS_DE_FMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FMR(void);
#endif

/* Handle:   47,Name:                      USS_DE_FR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DE_FR(void);
#endif

/* Handle:   48,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RL(void);
#endif

/* Handle:   49,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RLS(void);
#endif

/* Handle:   50,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RML(void);
#endif

/* Handle:   51,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RMR(void);
#endif

/* Handle:   52,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RR(void);
#endif

/* Handle:   53,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_RRS(void);
#endif

/* Handle:   54,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FL(void);
#endif

/* Handle:   55,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FLS(void);
#endif

/* Handle:   56,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FML(void);
#endif

/* Handle:   57,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FMR(void);
#endif

/* Handle:   58,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FR(void);
#endif

/* Handle:   59,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_DIAG_FRS(void);
#endif

/* Handle:   62,Name:               USS_SLOT_L_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_L_DEPTH(void);
#endif

/* Handle:   63,Name:               USS_SLOT_R_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern vuint16 IlPrivateGetTxUSS_SLOT_R_DEPTH(void);
#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals smaller or equal 8bit
 ----------------------------------------------------------------------------- */

/* Handle:   16,Name:               ScreenPressType1,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxScreenPressType1()            (HU_20.HU_20.ScreenPressType1)
#endif

/* Handle:   17,Name:               ScreenPressType2,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxScreenPressType2()            (HU_20.HU_20.ScreenPressType2)
#endif

/* Handle:   54,Name:                  USS_WORK_MODE,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxUSS_WORK_MODE()               (USS_DIAG_F.USS_DIAG_F.USS_WORK_MODE)
#endif

/* Handle:   55,Name:           GW_RemoteVehicleMode,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGW_RemoteVehicleMode()        (GW_Config.GW_Config.GW_RemoteVehicleMode)
#endif

/* Handle:   56,Name:                     GW_OTAMode,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGW_OTAMode()                  (GW_Config.GW_Config.GW_OTAMode)
#endif

/* Handle:   57,Name:                   GPSTime_Hour,Size:  5,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Hour()                (GPS_1.GPS_1.GPSTime_Hour)
#endif

/* Handle:   58,Name:                 GPSTime_Minute,Size:  6,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Minute()              (GPS_1.GPS_1.GPSTime_Minute)
#endif

/* Handle:   59,Name:                 GPSTime_Second,Size:  6,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Second()              (GPS_1.GPS_1.GPSTime_Second)
#endif

/* Handle:   60,Name:                   GPSTime_Year,Size:  7,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Year()                (GPS_1.GPS_1.GPSTime_Year)
#endif

/* Handle:   61,Name:                  GPSTime_Month,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Month()               (GPS_1.GPS_1.GPSTime_Month)
#endif

/* Handle:   62,Name:                    GPSTime_Day,Size:  7,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxGPSTime_Day()                 (GPS_1.GPS_1.GPSTime_Day)
#endif

/* Handle:   63,Name:                CheckSum_TBOX_1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxCheckSum_TBOX_1()             (TBOX_1.TBOX_1.CheckSum_TBOX_1)
#endif

/* Handle:   64,Name:            RemoteMonitoringReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxRemoteMonitoringReq()         (TBOX_1.TBOX_1.RemoteMonitoringReq)
#endif

/* Handle:   65,Name:          RemoteAVSSharpnessReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxRemoteAVSSharpnessReq()       (TBOX_1.TBOX_1.RemoteAVSSharpnessReq)
#endif

/* Handle:   66,Name:           RemoteAVSViewModeReq,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxRemoteAVSViewModeReq()        (TBOX_1.TBOX_1.RemoteAVSViewModeReq)
#endif

/* Handle:   67,Name:             LiveCounter_TBOX_1,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_TBOX_1()          (TBOX_1.TBOX_1.LiveCounter_TBOX_1)
#endif

/* Handle:   68,Name:                 Checksum_HU_10,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_HU_10()              (HU_10.HU_10.Checksum_HU_10)
#endif

/* Handle:   69,Name:                HU_PDCBuzzerReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_PDCBuzzerReq()             (HU_10.HU_10.HU_PDCBuzzerReq)
#endif

/* Handle:   70,Name:              LiveCounter_HU_10,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_HU_10()           (HU_10.HU_10.LiveCounter_HU_10)
#endif

/* Handle:   71,Name:                   DisplayTheme,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDisplayTheme()                (HU_14.HU_14.DisplayTheme)
#endif

/* Handle:   73,Name:           Checksum_HU_Speech_1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_HU_Speech_1()        (HU_Speech_1.HU_Speech_1.Checksum_HU_Speech_1)
#endif

/* Handle:   74,Name:               HU_SpeechReq_AVS,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_SpeechReq_AVS()            (HU_Speech_1.HU_Speech_1.HU_SpeechReq_AVS)
#endif

/* Handle:   75,Name:       HU_SpeechReq_AVSViewMode,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_SpeechReq_AVSViewMode()    (HU_Speech_1.HU_Speech_1.HU_SpeechReq_AVSViewMode)
#endif

/* Handle:   76,Name:               HU_SpeechReq_PDC,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_SpeechReq_PDC()            (HU_Speech_1.HU_Speech_1.HU_SpeechReq_PDC)
#endif

/* Handle:   77,Name:        LiveCounter_HU_Speech_1,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_HU_Speech_1()     (HU_Speech_1.HU_Speech_1.LiveCounter_HU_Speech_1)
#endif

/* Handle:   79,Name:           TargetSelection_Area,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTargetSelection_Area()        (HU_6.HU_6.TargetSelection_Area)
#endif

/* Handle:   82,Name:       TargetSelection_ParkType,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTargetSelection_ParkType()    (HU_6.HU_6.TargetSelection_ParkType)
#endif

/* Handle:   83,Name:  TargetSelection_ParkDirection,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTargetSelection_ParkDirection() (HU_6.HU_6.TargetSelection_ParkDirection)
#endif

/* Handle:   85,Name:     TargetSelection_ConfirmReq,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTargetSelection_ConfirmReq()  (HU_6.HU_6.TargetSelection_ConfirmReq)
#endif

/* Handle:   86,Name:        ParkInSlotSearchModeSet,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxParkInSlotSearchModeSet()     (HU_6.HU_6.ParkInSlotSearchModeSet)
#endif

/* Handle:   87,Name:               ParkOutDirection,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxParkOutDirection()            (HU_6.HU_6.ParkOutDirection)
#endif

/* Handle:   88,Name:                  CheckSum_HU_5,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxCheckSum_HU_5()               (HU_5.HU_5.CheckSum_HU_5)
#endif

/* Handle:   89,Name:                 AVSFunctionReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSFunctionReq()              (HU_5.HU_5.AVSFunctionReq)
#endif

/* Handle:   90,Name:                 AVSViewModeReq,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSViewModeReq()              (HU_5.HU_5.AVSViewModeReq)
#endif

/* Handle:   91,Name:             AVSFunctionExitReq,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSFunctionExitReq()          (HU_5.HU_5.AVSFunctionExitReq)
#endif

/* Handle:   92,Name:      AVSMonitoringVideoModeReq,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSMonitoringVideoModeReq()   (HU_5.HU_5.AVSMonitoringVideoModeReq)
#endif

/* Handle:   93,Name:                  DynamicPGSReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDynamicPGSReq()               (HU_5.HU_5.DynamicPGSReq)
#endif

/* Handle:   94,Name:                         MODReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMODReq()                      (HU_5.HU_5.MODReq)
#endif

/* Handle:   95,Name:                    LanguageSet,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLanguageSet()                 (HU_5.HU_5.LanguageSet)
#endif

/* Handle:   96,Name:       SwitchScreenResponse_AVS,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxSwitchScreenResponse_AVS()    (HU_5.HU_5.SwitchScreenResponse_AVS)
#endif

/* Handle:   97,Name:     AVSTurnFollowUpFunctionReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSTurnFollowUpFunctionReq()  (HU_5.HU_5.AVSTurnFollowUpFunctionReq)
#endif

/* Handle:   98,Name:                 AVSViewtypeReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAVSViewtypeReq()              (HU_5.HU_5.AVSViewtypeReq)
#endif

/* Handle:   99,Name:               LiveCounter_HU_5,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_HU_5()            (HU_5.HU_5.LiveCounter_HU_5)
#endif

/* Handle:  100,Name:                 Checksum_HU_18,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_HU_18()              (HU_18.HU_18.Checksum_HU_18)
#endif

/* Handle:  101,Name:  HU_BlindSpotFilledFunctionReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_BlindSpotFilledFunctionReq() (HU_18.HU_18.HU_BlindSpotFilledFunctionReq)
#endif

/* Handle:  102,Name:        HU_PDCAutoOnFunctionReq,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHU_PDCAutoOnFunctionReq()     (HU_18.HU_18.HU_PDCAutoOnFunctionReq)
#endif

/* Handle:  103,Name:              LiveCounter_HU_18,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_HU_18()           (HU_18.HU_18.LiveCounter_HU_18)
#endif

/* Handle:  104,Name:                      SysSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxSysSt_PDC()                   (PDC_1.PDC_1.SysSt_PDC)
#endif

/* Handle:  105,Name:                    ErrorSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxErrorSt_PDC()                 (PDC_1.PDC_1.ErrorSt_PDC)
#endif

/* Handle:  106,Name:                 Checksum_ADV_4,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ADV_4()              (ADV_4.ADV_4.Checksum_ADV_4)
#endif

/* Handle:  107,Name:         ADV_LeftSlotSearchType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_LeftSlotSearchType()      (ADV_4.ADV_4.ADV_LeftSlotSearchType)
#endif

/* Handle:  108,Name:        ADV_RightSlotSearchType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_RightSlotSearchType()     (ADV_4.ADV_4.ADV_RightSlotSearchType)
#endif

/* Handle:  109,Name:                ADV_PDCSchedule,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_PDCSchedule()             (ADV_4.ADV_4.ADV_PDCSchedule)
#endif

/* Handle:  110,Name:  ADV_Alarm_Position_Front_Left,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_Alarm_Position_Front_Left() (ADV_4.ADV_4.ADV_Alarm_Position_Front_Left)
#endif

/* Handle:  111,Name:       ADV_SearchTimeoutCounter,Size:  6,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_SearchTimeoutCounter()    (ADV_4.ADV_4.ADV_SearchTimeoutCounter)
#endif

/* Handle:  112,Name: ADV_Alarm_Position_Front_Right,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_Alarm_Position_Front_Right() (ADV_4.ADV_4.ADV_Alarm_Position_Front_Right)
#endif

/* Handle:  113,Name:   ADV_Alarm_Position_Rear_Left,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_Alarm_Position_Rear_Left() (ADV_4.ADV_4.ADV_Alarm_Position_Rear_Left)
#endif

/* Handle:  114,Name:  ADV_Alarm_Position_Rear_Right,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_Alarm_Position_Rear_Right() (ADV_4.ADV_4.ADV_Alarm_Position_Rear_Right)
#endif

/* Handle:  115,Name:              LiveCounter_ADV_4,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ADV_4()           (ADV_4.ADV_4.LiveCounter_ADV_4)
#endif

/* Handle:  116,Name:                 Checksum_ADV_1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ADV_1()              (ADV_1.ADV_1.Checksum_ADV_1)
#endif

/* Handle:  117,Name:                   ADV_ParkType,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ParkType()                (ADV_1.ADV_1.ADV_ParkType)
#endif

/* Handle:  118,Name:       ADV_ParkInSlotSearchMode,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ParkInSlotSearchMode()    (ADV_1.ADV_1.ADV_ParkInSlotSearchMode)
#endif

/* Handle:  119,Name:                 ADV_ParkStatus,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ParkStatus()              (ADV_1.ADV_1.ADV_ParkStatus)
#endif

/* Handle:  120,Name:           ADV_ParkOutDirection,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ParkOutDirection()        (ADV_1.ADV_1.ADV_ParkOutDirection)
#endif

/* Handle:  121,Name:        ADV_FunctionAbnormalTip,Size:  6,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_FunctionAbnormalTip()     (ADV_1.ADV_1.ADV_FunctionAbnormalTip)
#endif

/* Handle:  122,Name:              LiveCounter_ADV_1,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ADV_1()           (ADV_1.ADV_1.LiveCounter_ADV_1)
#endif

/* Handle:  123,Name:                      DoorSt_RR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDoorSt_RR()                   (RRDCU_1.RRDCU_1.DoorSt_RR)
#endif

/* Handle:  124,Name:                      DoorSt_RL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDoorSt_RL()                   (RLDCU_1.RLDCU_1.DoorSt_RL)
#endif

/* Handle:  125,Name:                      DoorSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDoorSt_FR()                   (PDCU_1.PDCU_1.DoorSt_FR)
#endif

/* Handle:  126,Name:                MirrorFoldSt_FR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMirrorFoldSt_FR()             (PDCU_1.PDCU_1.MirrorFoldSt_FR)
#endif

/* Handle:  127,Name:                      DoorSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDoorSt_FL()                   (DDCU_1.DDCU_1.DoorSt_FL)
#endif

/* Handle:  128,Name:                MirrorFoldSt_FL,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMirrorFoldSt_FL()             (DDCU_1.DDCU_1.MirrorFoldSt_FL)
#endif

/* Handle:  129,Name:                  LuggageDoorSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLuggageDoorSt()               (PLG_1.PLG_1.LuggageDoorSt)
#endif

/* Handle:  130,Name:                  Rainlntensity,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxRainlntensity()               (BCM1_7.BCM1_7.Rainlntensity)
#endif

/* Handle:  131,Name:                   Brightness_L,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxBrightness_L()                (BCM1_7.BCM1_7.Brightness_L)
#endif

/* Handle:  133,Name:                   EngineHoodSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxEngineHoodSt()                (BCM1_3.BCM1_3.EngineHoodSt)
#endif

/* Handle:  134,Name:                      PowerMode,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxPowerMode()                   (BCM1_2.BCM1_2.PowerMode)
#endif

/* Handle:  135,Name:                   LowBeamSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLowBeamSt_FL()                (BCM1_1.BCM1_1.LowBeamSt_FL)
#endif

/* Handle:  136,Name:                   LowBeamSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLowBeamSt_FR()                (BCM1_1.BCM1_1.LowBeamSt_FR)
#endif

/* Handle:  137,Name:                  HighBeamSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHighBeamSt_FL()               (BCM1_1.BCM1_1.HighBeamSt_FL)
#endif

/* Handle:  138,Name:                  HighBeamSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHighBeamSt_FR()               (BCM1_1.BCM1_1.HighBeamSt_FR)
#endif

/* Handle:  139,Name:                  AutoLightMode,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAutoLightMode()               (BCM1_1.BCM1_1.AutoLightMode)
#endif

/* Handle:  140,Name:                  FogLightSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxFogLightSt_FL()               (BCM1_1.BCM1_1.FogLightSt_FL)
#endif

/* Handle:  141,Name:                  FogLightSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxFogLightSt_FR()               (BCM1_1.BCM1_1.FogLightSt_FR)
#endif

/* Handle:  142,Name:                 TurningSt_Left,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTurningSt_Left()              (BCM1_1.BCM1_1.TurningSt_Left)
#endif

/* Handle:  143,Name:                TurningSt_right,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxTurningSt_right()             (BCM1_1.BCM1_1.TurningSt_right)
#endif

/* Handle:  144,Name:                HazardWarningSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxHazardWarningSt()             (BCM1_1.BCM1_1.HazardWarningSt)
#endif

/* Handle:  145,Name:                  WiperSt_Front,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWiperSt_Front()               (BCM1_1.BCM1_1.WiperSt_Front)
#endif

/* Handle:  146,Name:                    AmbientTemp,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxAmbientTemp()                 (ATC_2.ATC_2.AmbientTemp)
#endif

/* Handle:  147,Name:            DMS_VehicleModeinfo,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDMS_VehicleModeinfo()         (DMS_2.DMS_2.DMS_VehicleModeinfo)
#endif

/* Handle:  148,Name:         MCP_AVSandFRadarSwitch,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxMCP_AVSandFRadarSwitch()      (MCP_1.MCP_1.MCP_AVSandFRadarSwitch)
#endif

/* Handle:  154,Name:               ADV_DebugEnabled,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_DebugEnabled()            (ADV_TargetTracing.ADV_TargetTracing.ADV_DebugEnabled)
#endif

/* Handle:  155,Name:     ADV_TargetTracingAvaialble,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_TargetTracingAvaialble()  (ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingAvaialble)
#endif

/* Handle:  159,Name:       ADV_PathTracingAvaialble,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_PathTracingAvaialble()    (ADV_PathTracing.ADV_PathTracing.ADV_PathTracingAvaialble)
#endif

/* Handle:  160,Name:           ADV_ShortestDistance,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ShortestDistance()        (ADV_PathTracing.ADV_PathTracing.ADV_ShortestDistance)
#endif

/* Handle:  161,Name:            ADV_TotalPathNumber,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_TotalPathNumber()         (ADV_PathTracing.ADV_PathTracing.ADV_TotalPathNumber)
#endif

/* Handle:  162,Name:          ADV_CurrentPathNumber,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_CurrentPathNumber()       (ADV_PathTracing.ADV_PathTracing.ADV_CurrentPathNumber)
#endif

/* Handle:  163,Name:           ADV_CurrentDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_CurrentDirection()        (ADV_PathTracing.ADV_PathTracing.ADV_CurrentDirection)
#endif

/* Handle:  164,Name:          ADV_RemainingDistance,Size:  7,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_RemainingDistance()       (ADV_PathTracing.ADV_PathTracing.ADV_RemainingDistance)
#endif

/* Handle:  165,Name:                 Checksum_ESC_3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ESC_3()              (ESC_3.ESC_3.Checksum_ESC_3)
#endif

/* Handle:  167,Name:                          YRSSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxYRSSt()                       (ESC_3.ESC_3.YRSSt)
#endif

/* Handle:  170,Name:                    ErrorSt_YRS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxErrorSt_YRS()                 (ESC_3.ESC_3.ErrorSt_YRS)
#endif

/* Handle:  171,Name:              LiveCounter_ESC_3,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ESC_3()           (ESC_3.ESC_3.LiveCounter_ESC_3)
#endif

/* Handle:  172,Name:                 Checksum_ESC_2,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ESC_2()              (ESC_2.ESC_2.Checksum_ESC_2)
#endif

/* Handle:  173,Name:                  WorkingSt_EPB,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWorkingSt_EPB()               (ESC_2.ESC_2.WorkingSt_EPB)
#endif

/* Handle:  174,Name:              LiveCounter_ESC_2,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ESC_2()           (ESC_2.ESC_2.LiveCounter_ESC_2)
#endif

/* Handle:  175,Name:                 Checksum_ABS_3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ABS_3()              (ABS_3.ABS_3.Checksum_ABS_3)
#endif

/* Handle:  176,Name:                  WheelPulse_FL,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelPulse_FL()               (ABS_3.ABS_3.WheelPulse_FL)
#endif

/* Handle:  177,Name:                  WheelPulse_FR,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelPulse_FR()               (ABS_3.ABS_3.WheelPulse_FR)
#endif

/* Handle:  178,Name:                  WheelPulse_RL,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelPulse_RL()               (ABS_3.ABS_3.WheelPulse_RL)
#endif

/* Handle:  179,Name:                  WheelPulse_RR,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelPulse_RR()               (ABS_3.ABS_3.WheelPulse_RR)
#endif

/* Handle:  180,Name:         WheelSpeedDirection_FL,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelSpeedDirection_FL()      (ABS_3.ABS_3.WheelSpeedDirection_FL)
#endif

/* Handle:  181,Name:         WheelSpeedDirection_FR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelSpeedDirection_FR()      (ABS_3.ABS_3.WheelSpeedDirection_FR)
#endif

/* Handle:  182,Name:         WheelSpeedDirection_RL,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelSpeedDirection_RL()      (ABS_3.ABS_3.WheelSpeedDirection_RL)
#endif

/* Handle:  183,Name:         WheelSpeedDirection_RR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxWheelSpeedDirection_RR()      (ABS_3.ABS_3.WheelSpeedDirection_RR)
#endif

/* Handle:  184,Name:              LiveCounter_ABS_3,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ABS_3()           (ABS_3.ABS_3.LiveCounter_ABS_3)
#endif

/* Handle:  185,Name:                 Checksum_SAS_1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_SAS_1()              (SAS_1.SAS_1.Checksum_SAS_1)
#endif

/* Handle:  187,Name:         SteeringWheelAngleSign,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxSteeringWheelAngleSign()      (SAS_1.SAS_1.SteeringWheelAngleSign)
#endif

/* Handle:  188,Name:                         SAS_St,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxSAS_St()                      (SAS_1.SAS_1.SAS_St)
#endif

/* Handle:  189,Name:              LiveCounter_SAS_1,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_SAS_1()           (SAS_1.SAS_1.LiveCounter_SAS_1)
#endif

/* Handle:  190,Name:                 Checksum_ABS_2,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ABS_2()              (ABS_2.ABS_2.Checksum_ABS_2)
#endif

/* Handle:  193,Name:              LiveCounter_ABS_2,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ABS_2()           (ABS_2.ABS_2.LiveCounter_ABS_2)
#endif

/* Handle:  194,Name:                 Checksum_ABS_1,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_ABS_1()              (ABS_1.ABS_1.Checksum_ABS_1)
#endif

/* Handle:  198,Name:               DrivingDirection,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxDrivingDirection()            (ABS_1.ABS_1.DrivingDirection)
#endif

/* Handle:  199,Name:              LiveCounter_ABS_1,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_ABS_1()           (ABS_1.ABS_1.LiveCounter_ABS_1)
#endif

/* Handle:  200,Name:                 Checksum_TCU_3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_TCU_3()              (TCU_3.TCU_3.Checksum_TCU_3)
#endif

/* Handle:  201,Name:                      LeverInfo,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLeverInfo()                   (TCU_3.TCU_3.LeverInfo)
#endif

/* Handle:  202,Name:              LiveCounter_TCU_3,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_TCU_3()           (TCU_3.TCU_3.LiveCounter_TCU_3)
#endif

/* Handle:  203,Name:                 Checksum_EMS_3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxChecksum_EMS_3()              (EMS_3.EMS_3.Checksum_EMS_3)
#endif

/* Handle:  204,Name:                   BrakePedalSt,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxBrakePedalSt()                (EMS_3.EMS_3.BrakePedalSt)
#endif

/* Handle:  205,Name:              LiveCounter_EMS_3,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxLiveCounter_EMS_3()           (EMS_3.EMS_3.LiveCounter_EMS_3)
#endif

/* Handle:  209,Name:                 ADV_ReplanMode,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ReplanMode()              (ADV_P1.ADV_P1.ADV_ReplanMode)
#endif

/* Handle:  210,Name:             ADV_ReplanWayPoint,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_ReplanWayPoint()          (ADV_P1.ADV_P1.ADV_ReplanWayPoint)
#endif

/* Handle:  211,Name:                ADV_RealignMode,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_RealignMode()             (ADV_P1.ADV_P1.ADV_RealignMode)
#endif

/* Handle:  212,Name:            ADV_RealignWayPoint,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_RX
#define IlGetRxADV_RealignWayPoint()         (ADV_P1.ADV_P1.ADV_RealignWayPoint)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:              alpha_USS_FL_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FL_long(void);
#endif

/* Handle:    1,Name:              alpha_USS_FR_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FR_long(void);
#endif

/* Handle:    2,Name:              alpha_USS_RL_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RL_long(void);
#endif

/* Handle:    3,Name:              alpha_USS_RR_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RR_long(void);
#endif

/* Handle:    4,Name:                   alpha_USS_RL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RL(void);
#endif

/* Handle:    5,Name:                  alpha_USS_RML,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RML(void);
#endif

/* Handle:    6,Name:                  alpha_USS_RMR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RMR(void);
#endif

/* Handle:    7,Name:                   alpha_USS_RR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_RR(void);
#endif

/* Handle:    8,Name:                   alpha_USS_FL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FL(void);
#endif

/* Handle:    9,Name:                  alpha_USS_FML,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FML(void);
#endif

/* Handle:   10,Name:                  alpha_USS_FMR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FMR(void);
#endif

/* Handle:   11,Name:                   alpha_USS_FR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxalpha_USS_FR(void);
#endif

/* Handle:   12,Name:         ScreenPressPosition_X1,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxScreenPressPosition_X1(void);
#endif

/* Handle:   13,Name:         ScreenPressPosition_Y1,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxScreenPressPosition_Y1(void);
#endif

/* Handle:   14,Name:         ScreenPressPosition_X2,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxScreenPressPosition_X2(void);
#endif

/* Handle:   15,Name:         ScreenPressPosition_Y2,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxScreenPressPosition_Y2(void);
#endif

/* Handle:   18,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Cx(void);
#endif

/* Handle:   19,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Cy(void);
#endif

/* Handle:   20,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Dx(void);
#endif

/* Handle:   21,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Dy(void);
#endif

/* Handle:   22,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Ax(void);
#endif

/* Handle:   23,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Ay(void);
#endif

/* Handle:   24,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_Bx(void);
#endif

/* Handle:   25,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_R_By(void);
#endif

/* Handle:   26,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Cx(void);
#endif

/* Handle:   27,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Cy(void);
#endif

/* Handle:   28,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Dx(void);
#endif

/* Handle:   29,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Dy(void);
#endif

/* Handle:   30,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Ax(void);
#endif

/* Handle:   31,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_AY(void);
#endif

/* Handle:   32,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_Bx(void);
#endif

/* Handle:   33,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_SLOT_L_By(void);
#endif

/* Handle:   34,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_FLS(void);
#endif

/* Handle:   35,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_FRS(void);
#endif

/* Handle:   36,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RLS(void);
#endif

/* Handle:   37,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RRS(void);
#endif

/* Handle:   38,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RL(void);
#endif

/* Handle:   39,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RML(void);
#endif

/* Handle:   40,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RMR(void);
#endif

/* Handle:   41,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DE_RR(void);
#endif

/* Handle:   42,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RL(void);
#endif

/* Handle:   43,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RLS(void);
#endif

/* Handle:   44,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RML(void);
#endif

/* Handle:   45,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RMR(void);
#endif

/* Handle:   46,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RR(void);
#endif

/* Handle:   47,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_RRS(void);
#endif

/* Handle:   48,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FL(void);
#endif

/* Handle:   49,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FLS(void);
#endif

/* Handle:   50,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FML(void);
#endif

/* Handle:   51,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FMR(void);
#endif

/* Handle:   52,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FR(void);
#endif

/* Handle:   53,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxUSS_DIAG_FRS(void);
#endif

/* Handle:   72,Name:                  OdometerValue,Size: 25,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint32 IlGetRxOdometerValue(void);
#endif

/* Handle:   78,Name:        TargetSelectionCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxTargetSelectionCenter_X(void);
#endif

/* Handle:   80,Name:        TargetSelectionCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxTargetSelectionCenter_Y(void);
#endif

/* Handle:   81,Name:    TargetSelectionCenter_Angle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxTargetSelectionCenter_Angle(void);
#endif

/* Handle:   84,Name:      TargetSelection_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxTargetSelection_LineAngle(void);
#endif

/* Handle:  132,Name:                   Brightness_H,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxBrightness_H(void);
#endif

/* Handle:  149,Name:      ADV_TargetTracingCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_TargetTracingCenter_X(void);
#endif

/* Handle:  150,Name:      ADV_TargetTracingCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_TargetTracingCenter_Y(void);
#endif

/* Handle:  151,Name:         ADV_TargetTracingAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_TargetTracingAngle(void);
#endif

/* Handle:  152,Name:        ADV_TargetTracingLength,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_TargetTracingLength(void);
#endif

/* Handle:  153,Name:         ADV_TargetTracingWidth,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_TargetTracingWidth(void);
#endif

/* Handle:  156,Name:        ADV_PathTracingCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_PathTracingCenter_X(void);
#endif

/* Handle:  157,Name:        ADV_PathTracingCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_PathTracingCenter_Y(void);
#endif

/* Handle:  158,Name:           ADV_PathTracingAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_PathTracingAngle(void);
#endif

/* Handle:  166,Name:                        YawRate,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxYawRate(void);
#endif

/* Handle:  168,Name:                 Acceleration_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxAcceleration_X(void);
#endif

/* Handle:  169,Name:                 Acceleration_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxAcceleration_Y(void);
#endif

/* Handle:  186,Name:             SteeringWheelAngle,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxSteeringWheelAngle(void);
#endif

/* Handle:  191,Name:                  WheelSpeed_RL,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxWheelSpeed_RL(void);
#endif

/* Handle:  192,Name:                  WheelSpeed_RR,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxWheelSpeed_RR(void);
#endif

/* Handle:  195,Name:                  WheelSpeed_FL,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxWheelSpeed_FL(void);
#endif

/* Handle:  196,Name:                  WheelSpeed_FR,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxWheelSpeed_FR(void);
#endif

/* Handle:  197,Name:                   VehicleSpeed,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxVehicleSpeed(void);
#endif

/* Handle:  206,Name:                     ADV_Pose_X,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_Pose_X(void);
#endif

/* Handle:  207,Name:                     ADV_Pose_Y,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_Pose_Y(void);
#endif

/* Handle:  208,Name:                 ADV_Pose_Angle,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
extern vuint16 IlGetRxADV_Pose_Angle(void);
#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access for signals smaller or equal 8bit, SendType cyclic or none
 ----------------------------------------------------------------------------- */

/* Handle:   66,Name:            SensorBlockageSt_RR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RR(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RR(); \
  PDC_2.PDC_2.SensorBlockageSt_RR = (c); \
  IlLeaveCriticalSensorBlockageSt_RR(); \
}
#endif

/* Handle:   67,Name:           SensorBlockageSt_RMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RMR(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RMR(); \
  PDC_2.PDC_2.SensorBlockageSt_RMR = (c); \
  IlLeaveCriticalSensorBlockageSt_RMR(); \
}
#endif

/* Handle:   68,Name:           SensorBlockageSt_RML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RML(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RML(); \
  PDC_2.PDC_2.SensorBlockageSt_RML = (c); \
  IlLeaveCriticalSensorBlockageSt_RML(); \
}
#endif

/* Handle:   69,Name:            SensorBlockageSt_RL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RL(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RL(); \
  PDC_2.PDC_2.SensorBlockageSt_RL = (c); \
  IlLeaveCriticalSensorBlockageSt_RL(); \
}
#endif

/* Handle:   70,Name:            SensorBlockageSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FR(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FR(); \
  PDC_2.PDC_2.SensorBlockageSt_FR = (c); \
  IlLeaveCriticalSensorBlockageSt_FR(); \
}
#endif

/* Handle:   71,Name:           SensorBlockageSt_FMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FMR(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FMR(); \
  PDC_2.PDC_2.SensorBlockageSt_FMR = (c); \
  IlLeaveCriticalSensorBlockageSt_FMR(); \
}
#endif

/* Handle:   72,Name:           SensorBlockageSt_FML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FML(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FML(); \
  PDC_2.PDC_2.SensorBlockageSt_FML = (c); \
  IlLeaveCriticalSensorBlockageSt_FML(); \
}
#endif

/* Handle:   73,Name:            SensorBlockageSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FL(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FL(); \
  PDC_2.PDC_2.SensorBlockageSt_FL = (c); \
  IlLeaveCriticalSensorBlockageSt_FL(); \
}
#endif

/* Handle:   74,Name:           SensorBlockageSt_FLS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FLS(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FLS(); \
  PDC_2.PDC_2.SensorBlockageSt_FLS = (c); \
  IlLeaveCriticalSensorBlockageSt_FLS(); \
}
#endif

/* Handle:   75,Name:           SensorBlockageSt_FRS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_FRS(c) \
{ \
  IlEnterCriticalSensorBlockageSt_FRS(); \
  PDC_2.PDC_2.SensorBlockageSt_FRS = (c); \
  IlLeaveCriticalSensorBlockageSt_FRS(); \
}
#endif

/* Handle:   76,Name:           SensorBlockageSt_RLS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RLS(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RLS(); \
  PDC_2.PDC_2.SensorBlockageSt_RLS = (c); \
  IlLeaveCriticalSensorBlockageSt_RLS(); \
}
#endif

/* Handle:   77,Name:           SensorBlockageSt_RRS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorBlockageSt_RRS(c) \
{ \
  IlEnterCriticalSensorBlockageSt_RRS(); \
  PDC_2.PDC_2.SensorBlockageSt_RRS = (c); \
  IlLeaveCriticalSensorBlockageSt_RRS(); \
}
#endif

/* Handle:   78,Name:                ObjectRange_FLS,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxObjectRange_FLS(c) \
{ \
  IlEnterCriticalObjectRange_FLS(); \
  PDC_2.PDC_2.ObjectRange_FLS = (c); \
  IlLeaveCriticalObjectRange_FLS(); \
}
#endif

/* Handle:   79,Name:              SensorErrorSt_FLS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorErrorSt_FLS(c) \
{ \
  IlEnterCriticalSensorErrorSt_FLS(); \
  PDC_2.PDC_2.SensorErrorSt_FLS = (c); \
  IlLeaveCriticalSensorErrorSt_FLS(); \
}
#endif

/* Handle:   80,Name:                ObjectRange_FRS,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxObjectRange_FRS(c) \
{ \
  IlEnterCriticalObjectRange_FRS(); \
  PDC_2.PDC_2.ObjectRange_FRS = (c); \
  IlLeaveCriticalObjectRange_FRS(); \
}
#endif

/* Handle:   81,Name:              SensorErrorSt_FRS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorErrorSt_FRS(c) \
{ \
  IlEnterCriticalSensorErrorSt_FRS(); \
  PDC_2.PDC_2.SensorErrorSt_FRS = (c); \
  IlLeaveCriticalSensorErrorSt_FRS(); \
}
#endif

/* Handle:   82,Name:                ObjectRange_RLS,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxObjectRange_RLS(c) \
{ \
  IlEnterCriticalObjectRange_RLS(); \
  PDC_2.PDC_2.ObjectRange_RLS = (c); \
  IlLeaveCriticalObjectRange_RLS(); \
}
#endif

/* Handle:   83,Name:              SensorErrorSt_RLS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorErrorSt_RLS(c) \
{ \
  IlEnterCriticalSensorErrorSt_RLS(); \
  PDC_2.PDC_2.SensorErrorSt_RLS = (c); \
  IlLeaveCriticalSensorErrorSt_RLS(); \
}
#endif

/* Handle:   84,Name:                ObjectRange_RRS,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxObjectRange_RRS(c) \
{ \
  IlEnterCriticalObjectRange_RRS(); \
  PDC_2.PDC_2.ObjectRange_RRS = (c); \
  IlLeaveCriticalObjectRange_RRS(); \
}
#endif

/* Handle:   85,Name:              SensorErrorSt_RRS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSensorErrorSt_RRS(c) \
{ \
  IlEnterCriticalSensorErrorSt_RRS(); \
  PDC_2.PDC_2.SensorErrorSt_RRS = (c); \
  IlLeaveCriticalSensorErrorSt_RRS(); \
}
#endif

/* Handle:   93,Name:            BuzzerAlarmPosition,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxBuzzerAlarmPosition(c) \
{ \
  IlEnterCriticalBuzzerAlarmPosition(); \
  PDC_1.PDC_1.BuzzerAlarmPosition = (c); \
  IlLeaveCriticalBuzzerAlarmPosition(); \
}
#endif

/* Handle:   94,Name:           RadarSysSt_FrontSide,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRadarSysSt_FrontSide(c) \
{ \
  IlEnterCriticalRadarSysSt_FrontSide(); \
  PDC_1.PDC_1.RadarSysSt_FrontSide = (c); \
  IlLeaveCriticalRadarSysSt_FrontSide(); \
}
#endif

/* Handle:   95,Name:            RadarSysSt_RearSide,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRadarSysSt_RearSide(c) \
{ \
  IlEnterCriticalRadarSysSt_RearSide(); \
  PDC_1.PDC_1.RadarSysSt_RearSide = (c); \
  IlLeaveCriticalRadarSysSt_RearSide(); \
}
#endif

/* Handle:   96,Name:                 BuzzerSwitchSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxBuzzerSwitchSt(c) \
{ \
  IlEnterCriticalBuzzerSwitchSt(); \
  PDC_1.PDC_1.BuzzerSwitchSt = (c); \
  IlLeaveCriticalBuzzerSwitchSt(); \
}
#endif

/* Handle:  113,Name:           PDCAutoOnFunctionInd,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxPDCAutoOnFunctionInd(c) \
{ \
  IlEnterCriticalPDCAutoOnFunctionInd(); \
  PDC_1.PDC_1.PDCAutoOnFunctionInd = (c); \
  IlLeaveCriticalPDCAutoOnFunctionInd(); \
}
#endif

/* Handle:  114,Name:        SwitchScreenRequest_PDC,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxSwitchScreenRequest_PDC(c) \
{ \
  IlEnterCriticalSwitchScreenRequest_PDC(); \
  PDC_1.PDC_1.SwitchScreenRequest_PDC = (c); \
  IlLeaveCriticalSwitchScreenRequest_PDC(); \
}
#endif

/* Handle:  115,Name:      PDC_SpeechControlFeedback,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxPDC_SpeechControlFeedback(c) \
{ \
  IlEnterCriticalPDC_SpeechControlFeedback(); \
  PDC_1.PDC_1.PDC_SpeechControlFeedback = (c); \
  IlLeaveCriticalPDC_SpeechControlFeedback(); \
}
#endif

/* Handle:  116,Name:      PDC_SearchingSlotPosition,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxPDC_SearchingSlotPosition(c) \
{ \
  IlEnterCriticalPDC_SearchingSlotPosition(); \
  PDC_1.PDC_1.PDC_SearchingSlotPosition = (c); \
  IlLeaveCriticalPDC_SearchingSlotPosition(); \
}
#endif

/* Handle:  117,Name:                PDC_FunctionTip,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxPDC_FunctionTip(c) \
{ \
  IlEnterCriticalPDC_FunctionTip(); \
  PDC_1.PDC_1.PDC_FunctionTip = (c); \
  IlLeaveCriticalPDC_FunctionTip(); \
}
#endif

/* Handle:  121,Name:                    AVSViewtype,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSViewtype(c) \
{ \
  IlEnterCriticalAVSViewtype(); \
  AVS_1.AVS_1.AVSViewtype = (c); \
  IlLeaveCriticalAVSViewtype(); \
}
#endif

/* Handle:  131,Name: AVSTurnLightFollowupFunctionSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSTurnLightFollowupFunctionSt(c) \
{ \
  IlEnterCriticalAVSTurnLightFollowupFunctionSt(); \
  AVS_1.AVS_1.AVSTurnLightFollowupFunctionSt = (c); \
  IlLeaveCriticalAVSTurnLightFollowupFunctionSt(); \
}
#endif

/* Handle:  133,Name:     BlindSpotFilledFunctionInd,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxBlindSpotFilledFunctionInd(c) \
{ \
  IlEnterCriticalBlindSpotFilledFunctionInd(); \
  AVS_1.AVS_1.BlindSpotFilledFunctionInd = (c); \
  IlLeaveCriticalBlindSpotFilledFunctionInd(); \
}
#endif

/* Handle:  134,Name:             FoundSlotBuzzerTip,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFoundSlotBuzzerTip(c) \
{ \
  IlEnterCriticalFoundSlotBuzzerTip(); \
  AVS_1.AVS_1.FoundSlotBuzzerTip = (c); \
  IlLeaveCriticalFoundSlotBuzzerTip(); \
}
#endif

/* Handle:  135,Name:      AVS_SpeechControlFeedback,Size:  5,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_SpeechControlFeedback(c) \
{ \
  IlEnterCriticalAVS_SpeechControlFeedback(); \
  AVS_1.AVS_1.AVS_SpeechControlFeedback = (c); \
  IlLeaveCriticalAVS_SpeechControlFeedback(); \
}
#endif

/* Handle:  136,Name:      AVSCameraBlockageSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSCameraBlockageSt_Front(c) \
{ \
  IlEnterCriticalAVSCameraBlockageSt_Front(); \
  AVS_1.AVS_1.AVSCameraBlockageSt_Front = (c); \
  IlLeaveCriticalAVSCameraBlockageSt_Front(); \
}
#endif

/* Handle:  137,Name:       AVSCameraBlockageSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSCameraBlockageSt_Rear(c) \
{ \
  IlEnterCriticalAVSCameraBlockageSt_Rear(); \
  AVS_1.AVS_1.AVSCameraBlockageSt_Rear = (c); \
  IlLeaveCriticalAVSCameraBlockageSt_Rear(); \
}
#endif

/* Handle:  138,Name:       AVSCameraBlockageSt_Left,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSCameraBlockageSt_Left(c) \
{ \
  IlEnterCriticalAVSCameraBlockageSt_Left(); \
  AVS_1.AVS_1.AVSCameraBlockageSt_Left = (c); \
  IlLeaveCriticalAVSCameraBlockageSt_Left(); \
}
#endif

/* Handle:  139,Name:      AVSCameraBlockageSt_Right,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVSCameraBlockageSt_Right(c) \
{ \
  IlEnterCriticalAVSCameraBlockageSt_Right(); \
  AVS_1.AVS_1.AVSCameraBlockageSt_Right = (c); \
  IlLeaveCriticalAVSCameraBlockageSt_Right(); \
}
#endif

/* Handle:  140,Name:                AVS_AbnormalTip,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_AbnormalTip(c) \
{ \
  IlEnterCriticalAVS_AbnormalTip(); \
  AVS_1.AVS_1.AVS_AbnormalTip = (c); \
  IlLeaveCriticalAVS_AbnormalTip(); \
}
#endif

/* Handle:  141,Name:              AVS_CalibrationSt,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_CalibrationSt(c) \
{ \
  IlEnterCriticalAVS_CalibrationSt(); \
  AVS_1.AVS_1.AVS_CalibrationSt = (c); \
  IlLeaveCriticalAVS_CalibrationSt(); \
}
#endif

/* Handle:  142,Name:            AVS_PDWarning_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_PDWarning_Front(c) \
{ \
  IlEnterCriticalAVS_PDWarning_Front(); \
  AVS_1.AVS_1.AVS_PDWarning_Front = (c); \
  IlLeaveCriticalAVS_PDWarning_Front(); \
}
#endif

/* Handle:  143,Name:             AVS_PDWarning_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_PDWarning_Rear(c) \
{ \
  IlEnterCriticalAVS_PDWarning_Rear(); \
  AVS_1.AVS_1.AVS_PDWarning_Rear = (c); \
  IlLeaveCriticalAVS_PDWarning_Rear(); \
}
#endif

/* Handle:  144,Name:    AVS_RemoteMonitorigFeedback,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_RemoteMonitorigFeedback(c) \
{ \
  IlEnterCriticalAVS_RemoteMonitorigFeedback(); \
  AVS_1.AVS_1.AVS_RemoteMonitorigFeedback = (c); \
  IlLeaveCriticalAVS_RemoteMonitorigFeedback(); \
}
#endif

/* Handle:  145,Name:    AVS_RemoteSharpnessFeedback,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_RemoteSharpnessFeedback(c) \
{ \
  IlEnterCriticalAVS_RemoteSharpnessFeedback(); \
  AVS_1.AVS_1.AVS_RemoteSharpnessFeedback = (c); \
  IlLeaveCriticalAVS_RemoteSharpnessFeedback(); \
}
#endif

/* Handle:  146,Name: RemoteMonitoringSharpnessSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRemoteMonitoringSharpnessSt_AVS(c) \
{ \
  IlEnterCriticalRemoteMonitoringSharpnessSt_AVS(); \
  AVS_1.AVS_1.RemoteMonitoringSharpnessSt_AVS = (c); \
  IlLeaveCriticalRemoteMonitoringSharpnessSt_AVS(); \
}
#endif

/* Handle:  147,Name:         RemoteMonitoringSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRemoteMonitoringSt_AVS(c) \
{ \
  IlEnterCriticalRemoteMonitoringSt_AVS(); \
  AVS_1.AVS_1.RemoteMonitoringSt_AVS = (c); \
  IlLeaveCriticalRemoteMonitoringSt_AVS(); \
}
#endif

/* Handle:  148,Name:     RemoteMonitoringModeSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRemoteMonitoringModeSt_AVS(c) \
{ \
  IlEnterCriticalRemoteMonitoringModeSt_AVS(); \
  AVS_1.AVS_1.RemoteMonitoringModeSt_AVS = (c); \
  IlLeaveCriticalRemoteMonitoringModeSt_AVS(); \
}
#endif

/* Handle:  149,Name:        TurnFollowUpFunctionInd,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTurnFollowUpFunctionInd(c) \
{ \
  IlEnterCriticalTurnFollowUpFunctionInd(); \
  AVS_1.AVS_1.TurnFollowUpFunctionInd = (c); \
  IlLeaveCriticalTurnFollowUpFunctionInd(); \
}
#endif

/* Handle:  150,Name:     AVS_RemoteViewModeFeedback,Size:  5,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAVS_RemoteViewModeFeedback(c) \
{ \
  IlEnterCriticalAVS_RemoteViewModeFeedback(); \
  AVS_1.AVS_1.AVS_RemoteViewModeFeedback = (c); \
  IlLeaveCriticalAVS_RemoteViewModeFeedback(); \
}
#endif

/* Handle:  151,Name:                Checksum_PDC_14,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_14(c) \
{ \
  IlEnterCriticalChecksum_PDC_14(); \
  PDC_14.PDC_14.Checksum_PDC_14 = (c); \
  IlLeaveCriticalChecksum_PDC_14(); \
}
#endif

/* Handle:  154,Name:                   VehicleAngle,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxVehicleAngle(c) \
{ \
  IlEnterCriticalVehicleAngle(); \
  PDC_14.PDC_14.VehicleAngle = (c); \
  IlLeaveCriticalVehicleAngle(); \
}
#endif

/* Handle:  155,Name:             LiveCounter_PDC_14,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_14(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_14(); \
  PDC_14.PDC_14.LiveCounter_PDC_14 = (c); \
  IlLeaveCriticalLiveCounter_PDC_14(); \
}
#endif

/* Handle:  156,Name:                Checksum_PDC_13,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_13(c) \
{ \
  IlEnterCriticalChecksum_PDC_13(); \
  PDC_13.PDC_13.Checksum_PDC_13 = (c); \
  IlLeaveCriticalChecksum_PDC_13(); \
}
#endif

/* Handle:  161,Name:             LiveCounter_PDC_13,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_13(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_13(); \
  PDC_13.PDC_13.LiveCounter_PDC_13 = (c); \
  IlLeaveCriticalLiveCounter_PDC_13(); \
}
#endif

/* Handle:  162,Name:                Checksum_PDC_12,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_12(c) \
{ \
  IlEnterCriticalChecksum_PDC_12(); \
  PDC_12.PDC_12.Checksum_PDC_12 = (c); \
  IlLeaveCriticalChecksum_PDC_12(); \
}
#endif

/* Handle:  167,Name:             LiveCounter_PDC_12,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_12(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_12(); \
  PDC_12.PDC_12.LiveCounter_PDC_12 = (c); \
  IlLeaveCriticalLiveCounter_PDC_12(); \
}
#endif

/* Handle:  168,Name:                Checksum_PDC_11,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_11(c) \
{ \
  IlEnterCriticalChecksum_PDC_11(); \
  PDC_11.PDC_11.Checksum_PDC_11 = (c); \
  IlLeaveCriticalChecksum_PDC_11(); \
}
#endif

/* Handle:  173,Name:             LiveCounter_PDC_11,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_11(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_11(); \
  PDC_11.PDC_11.LiveCounter_PDC_11 = (c); \
  IlLeaveCriticalLiveCounter_PDC_11(); \
}
#endif

/* Handle:  174,Name:                Checksum_PDC_10,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_10(c) \
{ \
  IlEnterCriticalChecksum_PDC_10(); \
  PDC_10.PDC_10.Checksum_PDC_10 = (c); \
  IlLeaveCriticalChecksum_PDC_10(); \
}
#endif

/* Handle:  179,Name:             LiveCounter_PDC_10,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_10(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_10(); \
  PDC_10.PDC_10.LiveCounter_PDC_10 = (c); \
  IlLeaveCriticalLiveCounter_PDC_10(); \
}
#endif

/* Handle:  180,Name:                 Checksum_PDC_9,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_9(c) \
{ \
  IlEnterCriticalChecksum_PDC_9(); \
  PDC_9.PDC_9.Checksum_PDC_9 = (c); \
  IlLeaveCriticalChecksum_PDC_9(); \
}
#endif

/* Handle:  185,Name:              LiveCounter_PDC_9,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_9(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_9(); \
  PDC_9.PDC_9.LiveCounter_PDC_9 = (c); \
  IlLeaveCriticalLiveCounter_PDC_9(); \
}
#endif

/* Handle:  186,Name:                 Checksum_PDC_8,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_8(c) \
{ \
  IlEnterCriticalChecksum_PDC_8(); \
  PDC_8.PDC_8.Checksum_PDC_8 = (c); \
  IlLeaveCriticalChecksum_PDC_8(); \
}
#endif

/* Handle:  190,Name:                      TxRxSt_RR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_RR(c) \
{ \
  IlEnterCriticalTxRxSt_RR(); \
  PDC_8.PDC_8.TxRxSt_RR = (c); \
  IlLeaveCriticalTxRxSt_RR(); \
}
#endif

/* Handle:  191,Name:                     TxRxSt_RMR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_RMR(c) \
{ \
  IlEnterCriticalTxRxSt_RMR(); \
  PDC_8.PDC_8.TxRxSt_RMR = (c); \
  IlLeaveCriticalTxRxSt_RMR(); \
}
#endif

/* Handle:  192,Name:              LiveCounter_PDC_8,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_8(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_8(); \
  PDC_8.PDC_8.LiveCounter_PDC_8 = (c); \
  IlLeaveCriticalLiveCounter_PDC_8(); \
}
#endif

/* Handle:  193,Name:                 Checksum_PDC_7,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_7(c) \
{ \
  IlEnterCriticalChecksum_PDC_7(); \
  PDC_7.PDC_7.Checksum_PDC_7 = (c); \
  IlLeaveCriticalChecksum_PDC_7(); \
}
#endif

/* Handle:  197,Name:                      TxRxSt_RL,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_RL(c) \
{ \
  IlEnterCriticalTxRxSt_RL(); \
  PDC_7.PDC_7.TxRxSt_RL = (c); \
  IlLeaveCriticalTxRxSt_RL(); \
}
#endif

/* Handle:  198,Name:                     TxRxSt_RML,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_RML(c) \
{ \
  IlEnterCriticalTxRxSt_RML(); \
  PDC_7.PDC_7.TxRxSt_RML = (c); \
  IlLeaveCriticalTxRxSt_RML(); \
}
#endif

/* Handle:  199,Name:              LiveCounter_PDC_7,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_7(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_7(); \
  PDC_7.PDC_7.LiveCounter_PDC_7 = (c); \
  IlLeaveCriticalLiveCounter_PDC_7(); \
}
#endif

/* Handle:  200,Name:                 Checksum_PDC_6,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_6(c) \
{ \
  IlEnterCriticalChecksum_PDC_6(); \
  PDC_6.PDC_6.Checksum_PDC_6 = (c); \
  IlLeaveCriticalChecksum_PDC_6(); \
}
#endif

/* Handle:  204,Name:                      TxRxSt_FR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_FR(c) \
{ \
  IlEnterCriticalTxRxSt_FR(); \
  PDC_6.PDC_6.TxRxSt_FR = (c); \
  IlLeaveCriticalTxRxSt_FR(); \
}
#endif

/* Handle:  205,Name:                     TxRxSt_FMR,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_FMR(c) \
{ \
  IlEnterCriticalTxRxSt_FMR(); \
  PDC_6.PDC_6.TxRxSt_FMR = (c); \
  IlLeaveCriticalTxRxSt_FMR(); \
}
#endif

/* Handle:  206,Name:              LiveCounter_PDC_6,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_6(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_6(); \
  PDC_6.PDC_6.LiveCounter_PDC_6 = (c); \
  IlLeaveCriticalLiveCounter_PDC_6(); \
}
#endif

/* Handle:  207,Name:                 Checksum_PDC_5,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_5(c) \
{ \
  IlEnterCriticalChecksum_PDC_5(); \
  PDC_5.PDC_5.Checksum_PDC_5 = (c); \
  IlLeaveCriticalChecksum_PDC_5(); \
}
#endif

/* Handle:  211,Name:                      TxRxSt_FL,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_FL(c) \
{ \
  IlEnterCriticalTxRxSt_FL(); \
  PDC_5.PDC_5.TxRxSt_FL = (c); \
  IlLeaveCriticalTxRxSt_FL(); \
}
#endif

/* Handle:  212,Name:                     TxRxSt_FML,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxTxRxSt_FML(c) \
{ \
  IlEnterCriticalTxRxSt_FML(); \
  PDC_5.PDC_5.TxRxSt_FML = (c); \
  IlLeaveCriticalTxRxSt_FML(); \
}
#endif

/* Handle:  213,Name:              LiveCounter_PDC_5,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_5(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_5(); \
  PDC_5.PDC_5.LiveCounter_PDC_5 = (c); \
  IlLeaveCriticalLiveCounter_PDC_5(); \
}
#endif

/* Handle:  214,Name:                 Checksum_PDC_4,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_4(c) \
{ \
  IlEnterCriticalChecksum_PDC_4(); \
  PDC_4.PDC_4.Checksum_PDC_4 = (c); \
  IlLeaveCriticalChecksum_PDC_4(); \
}
#endif

/* Handle:  219,Name:              LiveCounter_PDC_4,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_4(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_4(); \
  PDC_4.PDC_4.LiveCounter_PDC_4 = (c); \
  IlLeaveCriticalLiveCounter_PDC_4(); \
}
#endif

/* Handle:  220,Name:                 Checksum_PDC_3,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxChecksum_PDC_3(c) \
{ \
  IlEnterCriticalChecksum_PDC_3(); \
  PDC_3.PDC_3.Checksum_PDC_3 = (c); \
  IlLeaveCriticalChecksum_PDC_3(); \
}
#endif

/* Handle:  225,Name:              LiveCounter_PDC_3,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLiveCounter_PDC_3(c) \
{ \
  IlEnterCriticalLiveCounter_PDC_3(); \
  PDC_3.PDC_3.LiveCounter_PDC_3 = (c); \
  IlLeaveCriticalLiveCounter_PDC_3(); \
}
#endif

/* Handle:  262,Name:         APS_Slot1_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot1_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot1_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot1_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot1_DetectStatus(); \
}
#endif

/* Handle:  263,Name:                 APS_Slot1_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot1_Info(c) \
{ \
  IlEnterCriticalAPS_Slot1_Info(); \
  APS_PSD.APS_PSD.APS_Slot1_Info = (c); \
  IlLeaveCriticalAPS_Slot1_Info(); \
}
#endif

/* Handle:  264,Name:             APS_Slot1_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot1_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot1_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot1_ParkType = (c); \
  IlLeaveCriticalAPS_Slot1_ParkType(); \
}
#endif

/* Handle:  265,Name:        APS_Slot1_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot1_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot1_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot1_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot1_ParkDirection(); \
}
#endif

/* Handle:  266,Name:         APS_Slot2_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot2_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot2_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot2_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot2_DetectStatus(); \
}
#endif

/* Handle:  267,Name:                 APS_Slot2_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot2_Info(c) \
{ \
  IlEnterCriticalAPS_Slot2_Info(); \
  APS_PSD.APS_PSD.APS_Slot2_Info = (c); \
  IlLeaveCriticalAPS_Slot2_Info(); \
}
#endif

/* Handle:  268,Name:             APS_Slot2_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot2_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot2_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot2_ParkType = (c); \
  IlLeaveCriticalAPS_Slot2_ParkType(); \
}
#endif

/* Handle:  269,Name:        APS_Slot2_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot2_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot2_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot2_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot2_ParkDirection(); \
}
#endif

/* Handle:  270,Name:         APS_Slot3_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot3_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot3_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot3_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot3_DetectStatus(); \
}
#endif

/* Handle:  271,Name:                 APS_Slot3_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot3_Info(c) \
{ \
  IlEnterCriticalAPS_Slot3_Info(); \
  APS_PSD.APS_PSD.APS_Slot3_Info = (c); \
  IlLeaveCriticalAPS_Slot3_Info(); \
}
#endif

/* Handle:  272,Name:             APS_Slot3_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot3_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot3_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot3_ParkType = (c); \
  IlLeaveCriticalAPS_Slot3_ParkType(); \
}
#endif

/* Handle:  273,Name:        APS_Slot3_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot3_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot3_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot3_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot3_ParkDirection(); \
}
#endif

/* Handle:  274,Name:         APS_Slot4_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot4_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot4_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot4_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot4_DetectStatus(); \
}
#endif

/* Handle:  275,Name:                 APS_Slot4_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot4_Info(c) \
{ \
  IlEnterCriticalAPS_Slot4_Info(); \
  APS_PSD.APS_PSD.APS_Slot4_Info = (c); \
  IlLeaveCriticalAPS_Slot4_Info(); \
}
#endif

/* Handle:  276,Name:             APS_Slot4_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot4_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot4_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot4_ParkType = (c); \
  IlLeaveCriticalAPS_Slot4_ParkType(); \
}
#endif

/* Handle:  277,Name:        APS_Slot4_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot4_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot4_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot4_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot4_ParkDirection(); \
}
#endif

/* Handle:  278,Name:         APS_Slot5_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot5_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot5_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot5_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot5_DetectStatus(); \
}
#endif

/* Handle:  279,Name:                 APS_Slot5_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot5_Info(c) \
{ \
  IlEnterCriticalAPS_Slot5_Info(); \
  APS_PSD.APS_PSD.APS_Slot5_Info = (c); \
  IlLeaveCriticalAPS_Slot5_Info(); \
}
#endif

/* Handle:  280,Name:             APS_Slot5_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot5_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot5_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot5_ParkType = (c); \
  IlLeaveCriticalAPS_Slot5_ParkType(); \
}
#endif

/* Handle:  281,Name:        APS_Slot5_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot5_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot5_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot5_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot5_ParkDirection(); \
}
#endif

/* Handle:  282,Name:         APS_Slot6_DetectStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot6_DetectStatus(c) \
{ \
  IlEnterCriticalAPS_Slot6_DetectStatus(); \
  APS_PSD.APS_PSD.APS_Slot6_DetectStatus = (c); \
  IlLeaveCriticalAPS_Slot6_DetectStatus(); \
}
#endif

/* Handle:  283,Name:                 APS_Slot6_Info,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot6_Info(c) \
{ \
  IlEnterCriticalAPS_Slot6_Info(); \
  APS_PSD.APS_PSD.APS_Slot6_Info = (c); \
  IlLeaveCriticalAPS_Slot6_Info(); \
}
#endif

/* Handle:  284,Name:             APS_Slot6_ParkType,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot6_ParkType(c) \
{ \
  IlEnterCriticalAPS_Slot6_ParkType(); \
  APS_PSD.APS_PSD.APS_Slot6_ParkType = (c); \
  IlLeaveCriticalAPS_Slot6_ParkType(); \
}
#endif

/* Handle:  285,Name:        APS_Slot6_ParkDirection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot6_ParkDirection(c) \
{ \
  IlEnterCriticalAPS_Slot6_ParkDirection(); \
  APS_PSD.APS_PSD.APS_Slot6_ParkDirection = (c); \
  IlLeaveCriticalAPS_Slot6_ParkDirection(); \
}
#endif

/* Handle:  286,Name:        APS_Slot1_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot1_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot1_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot1_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot1_BothSidesInfo(); \
}
#endif

/* Handle:  287,Name:        APS_Slot2_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot2_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot2_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot2_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot2_BothSidesInfo(); \
}
#endif

/* Handle:  288,Name:        APS_Slot3_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot3_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot3_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot3_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot3_BothSidesInfo(); \
}
#endif

/* Handle:  289,Name:        APS_Slot4_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot4_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot4_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot4_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot4_BothSidesInfo(); \
}
#endif

/* Handle:  290,Name:        APS_Slot5_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot5_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot5_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot5_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot5_BothSidesInfo(); \
}
#endif

/* Handle:  291,Name:        APS_Slot6_BothSidesInfo,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Slot6_BothSidesInfo(c) \
{ \
  IlEnterCriticalAPS_Slot6_BothSidesInfo(); \
  APS_PSD.APS_PSD.APS_Slot6_BothSidesInfo = (c); \
  IlLeaveCriticalAPS_Slot6_BothSidesInfo(); \
}
#endif

/* Handle:  292,Name:    APS_ParkingSlotAvailability,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_ParkingSlotAvailability(c) \
{ \
  IlEnterCriticalAPS_ParkingSlotAvailability(); \
  APS_PSD.APS_PSD.APS_ParkingSlotAvailability = (c); \
  IlLeaveCriticalAPS_ParkingSlotAvailability(); \
}
#endif

/* Handle:  293,Name:       APS_Replan_UpperLineFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Replan_UpperLineFlag(c) \
{ \
  IlEnterCriticalAPS_Replan_UpperLineFlag(); \
  APS_Replan_2.APS_Replan_2.APS_Replan_UpperLineFlag = (c); \
  IlLeaveCriticalAPS_Replan_UpperLineFlag(); \
}
#endif

/* Handle:  296,Name:        APS_Replan_LeftLineFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Replan_LeftLineFlag(c) \
{ \
  IlEnterCriticalAPS_Replan_LeftLineFlag(); \
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftLineFlag = (c); \
  IlLeaveCriticalAPS_Replan_LeftLineFlag(); \
}
#endif

/* Handle:  299,Name:       APS_Replan_RightLineFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Replan_RightLineFlag(c) \
{ \
  IlEnterCriticalAPS_Replan_RightLineFlag(); \
  APS_Replan_1.APS_Replan_1.APS_Replan_RightLineFlag = (c); \
  IlLeaveCriticalAPS_Replan_RightLineFlag(); \
}
#endif

/* Handle:  302,Name:          APS_Replan_LeftStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Replan_LeftStatus(c) \
{ \
  IlEnterCriticalAPS_Replan_LeftStatus(); \
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftStatus = (c); \
  IlLeaveCriticalAPS_Replan_LeftStatus(); \
}
#endif

/* Handle:  303,Name:         APS_Replan_RightStatus,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Replan_RightStatus(c) \
{ \
  IlEnterCriticalAPS_Replan_RightStatus(); \
  APS_Replan_1.APS_Replan_1.APS_Replan_RightStatus = (c); \
  IlLeaveCriticalAPS_Replan_RightStatus(); \
}
#endif

/* Handle:  304,Name:       RightCurb_StartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_StartPointFlag(c) \
{ \
  IlEnterCriticalRightCurb_StartPointFlag(); \
  RightCurbInfo.RightCurbInfo.RightCurb_StartPointFlag = (c); \
  IlLeaveCriticalRightCurb_StartPointFlag(); \
}
#endif

/* Handle:  307,Name:         RightCurb_EndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_EndPointFlag(c) \
{ \
  IlEnterCriticalRightCurb_EndPointFlag(); \
  RightCurbInfo.RightCurbInfo.RightCurb_EndPointFlag = (c); \
  IlLeaveCriticalRightCurb_EndPointFlag(); \
}
#endif

/* Handle:  310,Name:               RightCurb_Height,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_Height(c) \
{ \
  IlEnterCriticalRightCurb_Height(); \
  RightCurbInfo.RightCurbInfo.RightCurb_Height = (c); \
  IlLeaveCriticalRightCurb_Height(); \
}
#endif

/* Handle:  311,Name:               RightCurb_Status,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_Status(c) \
{ \
  IlEnterCriticalRightCurb_Status(); \
  RightCurbInfo.RightCurbInfo.RightCurb_Status = (c); \
  IlLeaveCriticalRightCurb_Status(); \
}
#endif

/* Handle:  312,Name:            RightCurb_Direction,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_Direction(c) \
{ \
  IlEnterCriticalRightCurb_Direction(); \
  RightCurbInfo.RightCurbInfo.RightCurb_Direction = (c); \
  IlLeaveCriticalRightCurb_Direction(); \
}
#endif

/* Handle:  313,Name:            RightCurb_AngleFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxRightCurb_AngleFlag(c) \
{ \
  IlEnterCriticalRightCurb_AngleFlag(); \
  RightCurbInfo.RightCurbInfo.RightCurb_AngleFlag = (c); \
  IlLeaveCriticalRightCurb_AngleFlag(); \
}
#endif

/* Handle:  315,Name:        LeftCurb_StartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_StartPointFlag(c) \
{ \
  IlEnterCriticalLeftCurb_StartPointFlag(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_StartPointFlag = (c); \
  IlLeaveCriticalLeftCurb_StartPointFlag(); \
}
#endif

/* Handle:  318,Name:          LeftCurb_EndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_EndPointFlag(c) \
{ \
  IlEnterCriticalLeftCurb_EndPointFlag(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_EndPointFlag = (c); \
  IlLeaveCriticalLeftCurb_EndPointFlag(); \
}
#endif

/* Handle:  321,Name:                LeftCurb_Height,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_Height(c) \
{ \
  IlEnterCriticalLeftCurb_Height(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_Height = (c); \
  IlLeaveCriticalLeftCurb_Height(); \
}
#endif

/* Handle:  322,Name:                LeftCurb_Status,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_Status(c) \
{ \
  IlEnterCriticalLeftCurb_Status(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_Status = (c); \
  IlLeaveCriticalLeftCurb_Status(); \
}
#endif

/* Handle:  323,Name:             LeftCurb_Direction,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_Direction(c) \
{ \
  IlEnterCriticalLeftCurb_Direction(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_Direction = (c); \
  IlLeaveCriticalLeftCurb_Direction(); \
}
#endif

/* Handle:  324,Name:             LeftCurb_AngleFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxLeftCurb_AngleFlag(c) \
{ \
  IlEnterCriticalLeftCurb_AngleFlag(); \
  LeftCurbInfo.LeftCurbInfo.LeftCurb_AngleFlag = (c); \
  IlLeaveCriticalLeftCurb_AngleFlag(); \
}
#endif

/* Handle:  328,Name: Freespace11_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace11_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace11_ObstacleStartPointFlag(); \
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace11_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  331,Name: Freespace11_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace11_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace11_ObstacleEndPointFlag(); \
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace11_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  332,Name:     Freespace11_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace11_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace11_ObstacleStatus(); \
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace11_ObstacleStatus(); \
}
#endif

/* Handle:  333,Name:   Freespace11_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace11_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace11_ObstacleProperty(); \
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace11_ObstacleProperty(); \
}
#endif

/* Handle:  334,Name:     Freespace11_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace11_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace11_ObstacleHeight(); \
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace11_ObstacleHeight(); \
}
#endif

/* Handle:  337,Name: Freespace10_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace10_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace10_ObstacleStartPointFlag(); \
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace10_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  340,Name: Freespace10_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace10_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace10_ObstacleEndPointFlag(); \
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace10_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  341,Name:     Freespace10_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace10_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace10_ObstacleStatus(); \
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace10_ObstacleStatus(); \
}
#endif

/* Handle:  342,Name:   Freespace10_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace10_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace10_ObstacleProperty(); \
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace10_ObstacleProperty(); \
}
#endif

/* Handle:  343,Name:     Freespace10_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace10_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace10_ObstacleHeight(); \
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace10_ObstacleHeight(); \
}
#endif

/* Handle:  346,Name: Freespace9_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace9_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace9_ObstacleStartPointFlag(); \
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace9_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  349,Name: Freespace9_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace9_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace9_ObstacleEndPointFlag(); \
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace9_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  350,Name:      Freespace9_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace9_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace9_ObstacleStatus(); \
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace9_ObstacleStatus(); \
}
#endif

/* Handle:  351,Name:    Freespace9_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace9_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace9_ObstacleProperty(); \
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace9_ObstacleProperty(); \
}
#endif

/* Handle:  352,Name:      Freespace9_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace9_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace9_ObstacleHeight(); \
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace9_ObstacleHeight(); \
}
#endif

/* Handle:  355,Name: Freespace8_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace8_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace8_ObstacleStartPointFlag(); \
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace8_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  358,Name: Freespace8_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace8_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace8_ObstacleEndPointFlag(); \
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace8_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  359,Name:      Freespace8_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace8_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace8_ObstacleStatus(); \
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace8_ObstacleStatus(); \
}
#endif

/* Handle:  360,Name:    Freespace8_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace8_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace8_ObstacleProperty(); \
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace8_ObstacleProperty(); \
}
#endif

/* Handle:  361,Name:      Freespace8_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace8_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace8_ObstacleHeight(); \
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace8_ObstacleHeight(); \
}
#endif

/* Handle:  364,Name: Freespace7_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace7_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace7_ObstacleStartPointFlag(); \
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace7_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  367,Name: Freespace7_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace7_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace7_ObstacleEndPointFlag(); \
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace7_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  368,Name:      Freespace7_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace7_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace7_ObstacleStatus(); \
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace7_ObstacleStatus(); \
}
#endif

/* Handle:  369,Name:    Freespace7_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace7_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace7_ObstacleProperty(); \
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace7_ObstacleProperty(); \
}
#endif

/* Handle:  370,Name:      Freespace7_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace7_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace7_ObstacleHeight(); \
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace7_ObstacleHeight(); \
}
#endif

/* Handle:  373,Name: Freespace6_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace6_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace6_ObstacleStartPointFlag(); \
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace6_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  376,Name: Freespace6_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace6_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace6_ObstacleEndPointFlag(); \
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace6_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  377,Name:      Freespace6_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace6_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace6_ObstacleStatus(); \
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace6_ObstacleStatus(); \
}
#endif

/* Handle:  378,Name:    Freespace6_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace6_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace6_ObstacleProperty(); \
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace6_ObstacleProperty(); \
}
#endif

/* Handle:  379,Name:      Freespace6_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace6_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace6_ObstacleHeight(); \
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace6_ObstacleHeight(); \
}
#endif

/* Handle:  382,Name: Freespace5_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace5_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace5_ObstacleStartPointFlag(); \
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace5_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  385,Name: Freespace5_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace5_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace5_ObstacleEndPointFlag(); \
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace5_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  386,Name:      Freespace5_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace5_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace5_ObstacleStatus(); \
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace5_ObstacleStatus(); \
}
#endif

/* Handle:  387,Name:    Freespace5_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace5_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace5_ObstacleProperty(); \
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace5_ObstacleProperty(); \
}
#endif

/* Handle:  388,Name:      Freespace5_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace5_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace5_ObstacleHeight(); \
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace5_ObstacleHeight(); \
}
#endif

/* Handle:  391,Name: Freespace4_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace4_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace4_ObstacleStartPointFlag(); \
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace4_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  394,Name: Freespace4_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace4_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace4_ObstacleEndPointFlag(); \
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace4_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  395,Name:      Freespace4_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace4_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace4_ObstacleStatus(); \
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace4_ObstacleStatus(); \
}
#endif

/* Handle:  396,Name:    Freespace4_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace4_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace4_ObstacleProperty(); \
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace4_ObstacleProperty(); \
}
#endif

/* Handle:  397,Name:      Freespace4_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace4_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace4_ObstacleHeight(); \
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace4_ObstacleHeight(); \
}
#endif

/* Handle:  400,Name: Freespace3_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace3_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace3_ObstacleStartPointFlag(); \
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace3_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  403,Name: Freespace3_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace3_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace3_ObstacleEndPointFlag(); \
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace3_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  404,Name:      Freespace3_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace3_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace3_ObstacleStatus(); \
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace3_ObstacleStatus(); \
}
#endif

/* Handle:  405,Name:    Freespace3_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace3_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace3_ObstacleProperty(); \
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace3_ObstacleProperty(); \
}
#endif

/* Handle:  406,Name:      Freespace3_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace3_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace3_ObstacleHeight(); \
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace3_ObstacleHeight(); \
}
#endif

/* Handle:  409,Name: Freespace2_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace2_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace2_ObstacleStartPointFlag(); \
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace2_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  412,Name: Freespace2_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace2_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace2_ObstacleEndPointFlag(); \
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace2_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  413,Name:      Freespace2_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace2_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace2_ObstacleStatus(); \
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace2_ObstacleStatus(); \
}
#endif

/* Handle:  414,Name:    Freespace2_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace2_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace2_ObstacleProperty(); \
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace2_ObstacleProperty(); \
}
#endif

/* Handle:  415,Name:      Freespace2_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace2_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace2_ObstacleHeight(); \
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace2_ObstacleHeight(); \
}
#endif

/* Handle:  418,Name: Freespace1_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace1_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace1_ObstacleStartPointFlag(); \
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace1_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  421,Name: Freespace1_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace1_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace1_ObstacleEndPointFlag(); \
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace1_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  422,Name:      Freespace1_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace1_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace1_ObstacleStatus(); \
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace1_ObstacleStatus(); \
}
#endif

/* Handle:  423,Name:    Freespace1_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace1_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace1_ObstacleProperty(); \
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace1_ObstacleProperty(); \
}
#endif

/* Handle:  424,Name:      Freespace1_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace1_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace1_ObstacleHeight(); \
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace1_ObstacleHeight(); \
}
#endif

/* Handle:  427,Name: Freespace0_ObstacleStartPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace0_ObstacleStartPointFlag(c) \
{ \
  IlEnterCriticalFreespace0_ObstacleStartPointFlag(); \
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStartPointFlag = (c); \
  IlLeaveCriticalFreespace0_ObstacleStartPointFlag(); \
}
#endif

/* Handle:  430,Name: Freespace0_ObstacleEndPointFlag,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace0_ObstacleEndPointFlag(c) \
{ \
  IlEnterCriticalFreespace0_ObstacleEndPointFlag(); \
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleEndPointFlag = (c); \
  IlLeaveCriticalFreespace0_ObstacleEndPointFlag(); \
}
#endif

/* Handle:  431,Name:      Freespace0_ObstacleStatus,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace0_ObstacleStatus(c) \
{ \
  IlEnterCriticalFreespace0_ObstacleStatus(); \
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStatus = (c); \
  IlLeaveCriticalFreespace0_ObstacleStatus(); \
}
#endif

/* Handle:  432,Name:    Freespace0_ObstacleProperty,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace0_ObstacleProperty(c) \
{ \
  IlEnterCriticalFreespace0_ObstacleProperty(); \
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleProperty = (c); \
  IlLeaveCriticalFreespace0_ObstacleProperty(); \
}
#endif

/* Handle:  433,Name:      Freespace0_ObstacleHeight,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxFreespace0_ObstacleHeight(c) \
{ \
  IlEnterCriticalFreespace0_ObstacleHeight(); \
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleHeight = (c); \
  IlLeaveCriticalFreespace0_ObstacleHeight(); \
}
#endif

/* Handle:  434,Name:                     APS_Status,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_Status(c) \
{ \
  IlEnterCriticalAPS_Status(); \
  APS_1.APS_1.APS_Status = (c); \
  IlLeaveCriticalAPS_Status(); \
}
#endif

/* Handle:  435,Name:               APS_ReplanResult,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_ReplanResult(c) \
{ \
  IlEnterCriticalAPS_ReplanResult(); \
  APS_1.APS_1.APS_ReplanResult = (c); \
  IlLeaveCriticalAPS_ReplanResult(); \
}
#endif

/* Handle:  436,Name:              APS_RealignResult,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_RealignResult(c) \
{ \
  IlEnterCriticalAPS_RealignResult(); \
  APS_1.APS_1.APS_RealignResult = (c); \
  IlLeaveCriticalAPS_RealignResult(); \
}
#endif

/* Handle:  437,Name:         APS_CloseLoopDetection,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_CloseLoopDetection(c) \
{ \
  IlEnterCriticalAPS_CloseLoopDetection(); \
  APS_1.APS_1.APS_CloseLoopDetection = (c); \
  IlLeaveCriticalAPS_CloseLoopDetection(); \
}
#endif

/* Handle:  438,Name:                 APS_ReplanType,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPutTxAPS_ReplanType(c) \
{ \
  IlEnterCriticalAPS_ReplanType(); \
  APS_1.APS_1.APS_ReplanType = (c); \
  IlLeaveCriticalAPS_ReplanType(); \
}
#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access extern decl
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                  PrivateCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxPrivateCanSta(vuint8 sigData);
#endif

/* Handle:    1,Name:                   PubuicCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxPubuicCanSta(vuint8 sigData);
#endif

/* Handle:    2,Name:                   CanTaskAlive,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCanTaskAlive(vuint16 sigData);
#endif

/* Handle:    3,Name:         Debug_ReloatDistance_R,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatDistance_R(vuint16 sigData);
#endif

/* Handle:    4,Name:            Debug_ReloatTheta_R,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatTheta_R(vuint16 sigData);
#endif

/* Handle:    5,Name:            Debug_ReloatValid_R,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatValid_R(vuint8 sigData);
#endif

/* Handle:    6,Name:         Debug_ReloatDistance_L,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatDistance_L(vuint16 sigData);
#endif

/* Handle:    7,Name:            Debug_ReloatTheta_L,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatTheta_L(vuint16 sigData);
#endif

/* Handle:    8,Name:            Debug_ReloatValid_L,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDebug_ReloatValid_L(vuint8 sigData);
#endif

/* Handle:    9,Name:           FV_TargetPoint_Angle,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFV_TargetPoint_Angle(vuint16 sigData);
#endif

/* Handle:   10,Name:               FV_TargetPoint_X,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFV_TargetPoint_X(vuint16 sigData);
#endif

/* Handle:   11,Name:               FV_TargetPoint_Y,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFV_TargetPoint_Y(vuint16 sigData);
#endif

/* Handle:   12,Name:                  TargetSlot_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Cx(vuint16 sigData);
#endif

/* Handle:   13,Name:                  TargetSlot_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Cy(vuint16 sigData);
#endif

/* Handle:   14,Name:                  TargetSlot_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Dx(vuint16 sigData);
#endif

/* Handle:   15,Name:                  TargetSlot_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Dy(vuint16 sigData);
#endif

/* Handle:   16,Name:                  TargetSlot_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Ax(vuint16 sigData);
#endif

/* Handle:   17,Name:                  TargetSlot_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Ay(vuint16 sigData);
#endif

/* Handle:   18,Name:                  TargetSlot_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_Bx(vuint16 sigData);
#endif

/* Handle:   19,Name:                  TargetSlot_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTargetSlot_By(vuint16 sigData);
#endif

/* Handle:   20,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Cx(vuint16 sigData);
#endif

/* Handle:   21,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Cy(vuint16 sigData);
#endif

/* Handle:   22,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Dx(vuint16 sigData);
#endif

/* Handle:   23,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Dy(vuint16 sigData);
#endif

/* Handle:   24,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Ax(vuint16 sigData);
#endif

/* Handle:   25,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Ay(vuint16 sigData);
#endif

/* Handle:   26,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_Bx(vuint16 sigData);
#endif

/* Handle:   27,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_By(vuint16 sigData);
#endif

/* Handle:   28,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Cx(vuint16 sigData);
#endif

/* Handle:   29,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Cy(vuint16 sigData);
#endif

/* Handle:   30,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Dx(vuint16 sigData);
#endif

/* Handle:   31,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Dy(vuint16 sigData);
#endif

/* Handle:   32,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Ax(vuint16 sigData);
#endif

/* Handle:   33,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_AY(vuint16 sigData);
#endif

/* Handle:   34,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_Bx(vuint16 sigData);
#endif

/* Handle:   35,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_By(vuint16 sigData);
#endif

/* Handle:   36,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FLS(vuint16 sigData);
#endif

/* Handle:   37,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FRS(vuint16 sigData);
#endif

/* Handle:   38,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RLS(vuint16 sigData);
#endif

/* Handle:   39,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RRS(vuint16 sigData);
#endif

/* Handle:   40,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RL(vuint16 sigData);
#endif

/* Handle:   41,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RML(vuint16 sigData);
#endif

/* Handle:   42,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RMR(vuint16 sigData);
#endif

/* Handle:   43,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_RR(vuint16 sigData);
#endif

/* Handle:   44,Name:                      USS_DE_FL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FL(vuint16 sigData);
#endif

/* Handle:   45,Name:                     USS_DE_FML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FML(vuint16 sigData);
#endif

/* Handle:   46,Name:                     USS_DE_FMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FMR(vuint16 sigData);
#endif

/* Handle:   47,Name:                      USS_DE_FR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DE_FR(vuint16 sigData);
#endif

/* Handle:   48,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RL(vuint16 sigData);
#endif

/* Handle:   49,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RLS(vuint16 sigData);
#endif

/* Handle:   50,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RML(vuint16 sigData);
#endif

/* Handle:   51,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RMR(vuint16 sigData);
#endif

/* Handle:   52,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RR(vuint16 sigData);
#endif

/* Handle:   53,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_RRS(vuint16 sigData);
#endif

/* Handle:   54,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FL(vuint16 sigData);
#endif

/* Handle:   55,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FLS(vuint16 sigData);
#endif

/* Handle:   56,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FML(vuint16 sigData);
#endif

/* Handle:   57,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FMR(vuint16 sigData);
#endif

/* Handle:   58,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FR(vuint16 sigData);
#endif

/* Handle:   59,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_DIAG_FRS(vuint16 sigData);
#endif

/* Handle:   60,Name:                  USS_WORK_MODE,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_WORK_MODE(vuint8 sigData);
#endif

/* Handle:   61,Name:                         DR_RAW,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDR_RAW(vuint32 sigData);
#endif

/* Handle:   62,Name:               USS_SLOT_L_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_L_DEPTH(vuint16 sigData);
#endif

/* Handle:   63,Name:               USS_SLOT_R_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxUSS_SLOT_R_DEPTH(vuint16 sigData);
#endif

/* Handle:   64,Name:                           DR_X,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDR_X(vuint32 sigData);
#endif

/* Handle:   65,Name:                           DR_Y,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDR_Y(vuint32 sigData);
#endif

/* Handle:   86,Name:         ParkingSlotDegree_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxParkingSlotDegree_Left(vuint16 sigData);
#endif

/* Handle:   87,Name:        ParkingSlotDegree_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxParkingSlotDegree_Right(vuint16 sigData);
#endif

/* Handle:   88,Name:                      SysSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSysSt_PDC(vuint8 sigData);
#endif

/* Handle:   89,Name:                    ErrorSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxErrorSt_PDC(vuint8 sigData);
#endif

/* Handle:   90,Name:               RadarSysSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRadarSysSt_Front(vuint8 sigData);
#endif

/* Handle:   91,Name:                RadarSysSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRadarSysSt_Rear(vuint8 sigData);
#endif

/* Handle:   92,Name:                  BuzeerCmd_PDC,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxBuzeerCmd_PDC(vuint8 sigData);
#endif

/* Handle:   97,Name:                 ObjectRange_RR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_RR(vuint8 sigData);
#endif

/* Handle:   98,Name:               SensorErrorSt_RR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_RR(vuint8 sigData);
#endif

/* Handle:   99,Name:                ObjectRange_RMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_RMR(vuint8 sigData);
#endif

/* Handle:  100,Name:              SensorErrorSt_RMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_RMR(vuint8 sigData);
#endif

/* Handle:  101,Name:                ObjectRange_RML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_RML(vuint8 sigData);
#endif

/* Handle:  102,Name:              SensorErrorSt_RML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_RML(vuint8 sigData);
#endif

/* Handle:  103,Name:                 ObjectRange_RL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_RL(vuint8 sigData);
#endif

/* Handle:  104,Name:               SensorErrorSt_RL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_RL(vuint8 sigData);
#endif

/* Handle:  105,Name:                 ObjectRange_FR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_FR(vuint8 sigData);
#endif

/* Handle:  106,Name:               SensorErrorSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_FR(vuint8 sigData);
#endif

/* Handle:  107,Name:                ObjectRange_FMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_FMR(vuint8 sigData);
#endif

/* Handle:  108,Name:              SensorErrorSt_FMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_FMR(vuint8 sigData);
#endif

/* Handle:  109,Name:                ObjectRange_FML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_FML(vuint8 sigData);
#endif

/* Handle:  110,Name:              SensorErrorSt_FML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_FML(vuint8 sigData);
#endif

/* Handle:  111,Name:                 ObjectRange_FL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxObjectRange_FL(vuint8 sigData);
#endif

/* Handle:  112,Name:               SensorErrorSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSensorErrorSt_FL(vuint8 sigData);
#endif

/* Handle:  118,Name:                          AVSSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSSt(vuint8 sigData);
#endif

/* Handle:  119,Name:                     AVSErrorSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSErrorSt(vuint8 sigData);
#endif

/* Handle:  120,Name:                    AVSViewMode,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSViewMode(vuint8 sigData);
#endif

/* Handle:  122,Name:         AVSCameraErrorSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSCameraErrorSt_Front(vuint8 sigData);
#endif

/* Handle:  123,Name:          AVSCameraErrorSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSCameraErrorSt_Rear(vuint8 sigData);
#endif

/* Handle:  124,Name:          AVSCameraErrorSt_Left,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSCameraErrorSt_Left(vuint8 sigData);
#endif

/* Handle:  125,Name:         AVSCameraErrorSt_Right,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAVSCameraErrorSt_Right(vuint8 sigData);
#endif

/* Handle:  126,Name:             LanguageTypeSt_AVS,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLanguageTypeSt_AVS(vuint8 sigData);
#endif

/* Handle:  127,Name:               DynamicPGSSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDynamicPGSSt_AVS(vuint8 sigData);
#endif

/* Handle:  128,Name:                      MODSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxMODSt_AVS(vuint8 sigData);
#endif

/* Handle:  129,Name:               MODWarning_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxMODWarning_Front(vuint8 sigData);
#endif

/* Handle:  130,Name:                MODWarning_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxMODWarning_Rear(vuint8 sigData);
#endif

/* Handle:  132,Name:        SwitchScreenRequest_AVS,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxSwitchScreenRequest_AVS(vuint8 sigData);
#endif

/* Handle:  152,Name:             VehicleCoordinateX,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxVehicleCoordinateX(vuint16 sigData);
#endif

/* Handle:  153,Name:             VehicleCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxVehicleCoordinateY(vuint16 sigData);
#endif

/* Handle:  157,Name:             CCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCCoordinateY_Right(vuint16 sigData);
#endif

/* Handle:  158,Name:             CCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCCoordinateX_Right(vuint16 sigData);
#endif

/* Handle:  159,Name:             DCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDCoordinateY_Right(vuint16 sigData);
#endif

/* Handle:  160,Name:             DCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDCoordinateX_Right(vuint16 sigData);
#endif

/* Handle:  163,Name:             ACoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxACoordinateY_Right(vuint16 sigData);
#endif

/* Handle:  164,Name:             ACoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxACoordinateX_Right(vuint16 sigData);
#endif

/* Handle:  165,Name:             BCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxBCoordinateY_Right(vuint16 sigData);
#endif

/* Handle:  166,Name:             BCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxBCoordinateX_Right(vuint16 sigData);
#endif

/* Handle:  169,Name:              CCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCCoordinateY_Left(vuint16 sigData);
#endif

/* Handle:  170,Name:              CCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxCCoordinateX_Left(vuint16 sigData);
#endif

/* Handle:  171,Name:              DCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDCoordinateY_Left(vuint16 sigData);
#endif

/* Handle:  172,Name:              DCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDCoordinateX_Left(vuint16 sigData);
#endif

/* Handle:  175,Name:              DistanceValue_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_RLS(vuint16 sigData);
#endif

/* Handle:  176,Name:              DistanceValue_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_RRS(vuint16 sigData);
#endif

/* Handle:  177,Name:              TimeStamp_RLS_RRS,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_RLS_RRS(vuint16 sigData);
#endif

/* Handle:  178,Name:         ParkingSlotDepth_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxParkingSlotDepth_Right(vuint16 sigData);
#endif

/* Handle:  181,Name:              DistanceValue_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FLS(vuint16 sigData);
#endif

/* Handle:  182,Name:              DistanceValue_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FRS(vuint16 sigData);
#endif

/* Handle:  183,Name:              TimeStamp_FLS_FRS,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_FLS_FRS(vuint16 sigData);
#endif

/* Handle:  184,Name:          ParkingSoltDepth_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxParkingSoltDepth_Left(vuint16 sigData);
#endif

/* Handle:  187,Name:               DistanceValue_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_RR(vuint16 sigData);
#endif

/* Handle:  188,Name:              DistanceValue_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_RMR(vuint16 sigData);
#endif

/* Handle:  189,Name:               TimeStamp_RMR_RR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_RMR_RR(vuint16 sigData);
#endif

/* Handle:  194,Name:              DisstanceValue_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDisstanceValue_RL(vuint16 sigData);
#endif

/* Handle:  195,Name:             DisstanceValue_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDisstanceValue_RML(vuint16 sigData);
#endif

/* Handle:  196,Name:               TimeStamp_RML_RL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_RML_RL(vuint16 sigData);
#endif

/* Handle:  201,Name:               DistanceValue_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FR(vuint16 sigData);
#endif

/* Handle:  202,Name:              DistanceValue_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FMR(vuint16 sigData);
#endif

/* Handle:  203,Name:               TimeStamp_FMR_FR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_FMR_FR(vuint16 sigData);
#endif

/* Handle:  208,Name:               DistanceValue_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FL(vuint16 sigData);
#endif

/* Handle:  209,Name:              DistanceValue_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxDistanceValue_FML(vuint16 sigData);
#endif

/* Handle:  210,Name:               TimeStamp_FML_FL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxTimeStamp_FML_FL(vuint16 sigData);
#endif

/* Handle:  215,Name:            FrontObjCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFrontObjCoordinateY(vuint16 sigData);
#endif

/* Handle:  216,Name:            FrontObjCoordinateX,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFrontObjCoordinateX(vuint16 sigData);
#endif

/* Handle:  217,Name:             RearObjCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRearObjCoordinateY(vuint16 sigData);
#endif

/* Handle:  218,Name:             RearObjCoordinateX,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRearObjCoordinateX(vuint16 sigData);
#endif

/* Handle:  221,Name:              ACoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxACoordinateY_Left(vuint16 sigData);
#endif

/* Handle:  222,Name:              ACoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxACoordinateX_Left(vuint16 sigData);
#endif

/* Handle:  223,Name:              BCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxBCoordinateY_Left(vuint16 sigData);
#endif

/* Handle:  224,Name:              BCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxBCoordinateX_Left(vuint16 sigData);
#endif

/* Handle:  226,Name:        APS_Slot6CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  227,Name:        APS_Slot6CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  228,Name:            APS_Slot6_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6_LineAngle(vuint16 sigData);
#endif

/* Handle:  229,Name:               APS_Slot6_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6_Length(vuint16 sigData);
#endif

/* Handle:  230,Name:                APS_Slot6_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6_Width(vuint16 sigData);
#endif

/* Handle:  231,Name:     APS_Slot6CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot6CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  232,Name:        APS_Slot5CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  233,Name:        APS_Slot5CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  234,Name:            APS_Slot5_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5_LineAngle(vuint16 sigData);
#endif

/* Handle:  235,Name:               APS_Slot5_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5_Length(vuint16 sigData);
#endif

/* Handle:  236,Name:                APS_Slot5_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5_Width(vuint16 sigData);
#endif

/* Handle:  237,Name:     APS_Slot5CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot5CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  238,Name:        APS_Slot4CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  239,Name:        APS_Slot4CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  240,Name:            APS_Slot4_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4_LineAngle(vuint16 sigData);
#endif

/* Handle:  241,Name:               APS_Slot4_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4_Length(vuint16 sigData);
#endif

/* Handle:  242,Name:                APS_Slot4_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4_Width(vuint16 sigData);
#endif

/* Handle:  243,Name:     APS_Slot4CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot4CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  244,Name:        APS_Slot3CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  245,Name:        APS_Slot3CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  246,Name:            APS_Slot3_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3_LineAngle(vuint16 sigData);
#endif

/* Handle:  247,Name:               APS_Slot3_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3_Length(vuint16 sigData);
#endif

/* Handle:  248,Name:                APS_Slot3_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3_Width(vuint16 sigData);
#endif

/* Handle:  249,Name:     APS_Slot3CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot3CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  250,Name:        APS_Slot2CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  251,Name:        APS_Slot2CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  252,Name:            APS_Slot2_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2_LineAngle(vuint16 sigData);
#endif

/* Handle:  253,Name:               APS_Slot2_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2_Length(vuint16 sigData);
#endif

/* Handle:  254,Name:                APS_Slot2_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2_Width(vuint16 sigData);
#endif

/* Handle:  255,Name:     APS_Slot2CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot2CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  256,Name:        APS_Slot1CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1CenterPoint_X1(vuint16 sigData);
#endif

/* Handle:  257,Name:        APS_Slot1CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1CenterPoint_Y1(vuint16 sigData);
#endif

/* Handle:  258,Name:            APS_Slot1_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1_LineAngle(vuint16 sigData);
#endif

/* Handle:  259,Name:               APS_Slot1_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1_Length(vuint16 sigData);
#endif

/* Handle:  260,Name:                APS_Slot1_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1_Width(vuint16 sigData);
#endif

/* Handle:  261,Name:     APS_Slot1CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Slot1CenterPoint_Angle(vuint16 sigData);
#endif

/* Handle:  294,Name:   APS_Replan_UpperLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_UpperLineDistance(vuint16 sigData);
#endif

/* Handle:  295,Name:      APS_Replan_UpperLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_UpperLineAngle(vuint16 sigData);
#endif

/* Handle:  297,Name:    APS_Replan_LeftLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_LeftLineDistance(vuint16 sigData);
#endif

/* Handle:  298,Name:       APS_Replan_LeftLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_LeftLineAngle(vuint16 sigData);
#endif

/* Handle:  300,Name:   APS_Replan_RightLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_RightLineDistance(vuint16 sigData);
#endif

/* Handle:  301,Name:      APS_Replan_RightLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxAPS_Replan_RightLineAngle(vuint16 sigData);
#endif

/* Handle:  305,Name:          RightCurb_StartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRightCurb_StartPointX(vuint16 sigData);
#endif

/* Handle:  306,Name:          RightCurb_StartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRightCurb_StartPointY(vuint16 sigData);
#endif

/* Handle:  308,Name:            RightCurb_EndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRightCurb_EndPointX(vuint16 sigData);
#endif

/* Handle:  309,Name:            RightCurb_EndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRightCurb_EndPointY(vuint16 sigData);
#endif

/* Handle:  314,Name:                RightCurb_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxRightCurb_Angle(vuint16 sigData);
#endif

/* Handle:  316,Name:           LeftCurb_StartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLeftCurb_StartPointX(vuint16 sigData);
#endif

/* Handle:  317,Name:           LeftCurb_StartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLeftCurb_StartPointY(vuint16 sigData);
#endif

/* Handle:  319,Name:             LeftCurb_EndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLeftCurb_EndPointX(vuint16 sigData);
#endif

/* Handle:  320,Name:             LeftCurb_EndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLeftCurb_EndPointY(vuint16 sigData);
#endif

/* Handle:  325,Name:                 LeftCurb_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxLeftCurb_Angle(vuint16 sigData);
#endif

/* Handle:  326,Name: Freespace11_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace11_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  327,Name: Freespace11_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace11_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  329,Name:  Freespace11_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace11_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  330,Name:  Freespace11_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace11_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  335,Name: Freespace10_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace10_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  336,Name: Freespace10_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace10_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  338,Name:  Freespace10_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace10_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  339,Name:  Freespace10_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace10_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  344,Name: Freespace9_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace9_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  345,Name: Freespace9_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace9_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  347,Name:   Freespace9_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace9_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  348,Name:   Freespace9_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace9_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  353,Name: Freespace8_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace8_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  354,Name: Freespace8_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace8_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  356,Name:   Freespace8_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace8_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  357,Name:   Freespace8_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace8_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  362,Name: Freespace7_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace7_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  363,Name: Freespace7_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace7_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  365,Name:   Freespace7_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace7_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  366,Name:   Freespace7_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace7_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  371,Name: Freespace6_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace6_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  372,Name: Freespace6_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace6_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  374,Name:   Freespace6_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace6_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  375,Name:   Freespace6_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace6_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  380,Name: Freespace5_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace5_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  381,Name: Freespace5_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace5_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  383,Name:   Freespace5_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace5_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  384,Name:   Freespace5_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace5_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  389,Name: Freespace4_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace4_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  390,Name: Freespace4_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace4_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  392,Name:   Freespace4_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace4_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  393,Name:   Freespace4_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace4_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  398,Name: Freespace3_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace3_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  399,Name: Freespace3_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace3_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  401,Name:   Freespace3_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace3_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  402,Name:   Freespace3_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace3_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  407,Name: Freespace2_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace2_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  408,Name: Freespace2_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace2_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  410,Name:   Freespace2_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace2_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  411,Name:   Freespace2_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace2_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  416,Name: Freespace1_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace1_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  417,Name: Freespace1_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace1_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  419,Name:   Freespace1_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace1_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  420,Name:   Freespace1_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace1_ObstacleEndPointY(vuint16 sigData);
#endif

/* Handle:  425,Name: Freespace0_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace0_ObstacleStartPointX(vuint16 sigData);
#endif

/* Handle:  426,Name: Freespace0_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace0_ObstacleStartPointY(vuint16 sigData);
#endif

/* Handle:  428,Name:   Freespace0_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace0_ObstacleEndPointX(vuint16 sigData);
#endif

/* Handle:  429,Name:   Freespace0_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
extern void IlPutTxFreespace0_ObstacleEndPointY(vuint16 sigData);
#endif




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\il_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 390049630
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __IL_PAR_H__ */
