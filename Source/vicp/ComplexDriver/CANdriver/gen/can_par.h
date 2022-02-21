/* -----------------------------------------------------------------------------
  Filename:    can_par.h
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
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

#if !defined(__CAN_PAR_H__)
#define __CAN_PAR_H__

#include "can_cfg.h"
#include "v_inc.h"
#include "drv_par.h"

/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of callback functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 4 START */

extern void CbdWrpBusOff(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

extern void ApplCanBusOff(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */

extern void ApplCanWakeUp(CanChannelHandle channel);

/* CODE CATEGORY 4 END */


#if defined(C_MULTIPLE_RECEIVE_CHANNEL) || defined(C_SINGLE_RECEIVE_CHANNEL)
/* CODE CATEGORY 1 START */
extern vuint8 PDC_14_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_13_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_12_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_11_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_10_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_9_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_8_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_7_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_6_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_5_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_4_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_3_TxPretransmit(CanTxInfoStruct ctis);
/* CODE CATEGORY 1 END */

#else
/* CODE CATEGORY 1 START */
extern vuint8 PDC_14_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_13_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_12_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_11_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_10_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_9_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_8_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_7_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_6_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_5_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_4_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 PDC_3_TxPretransmit(CanChipDataPtr txObject);
/* CODE CATEGORY 1 END */

#endif

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgSAS_1PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 IlMsgTCU_3PreCopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpPrecopyNormalDiagFunc(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpPrecopyNormalDiagPhys(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 TpPrecopyExtendedDiagPhys(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern vuint8 CanNm_NmMsgPrecopy(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */


/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of confirmation functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern void CanNm_NmMsgConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void TpDrvConfirmation(CanTransmitHandle txObject);
/* CODE CATEGORY 1 END */



/* -----------------------------------------------------------------------------
    &&&~ Extern declarations of indication functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern void HU_20_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void GW_Config_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void GPS_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void IC_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void HU_Speech_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void HU_6_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void HU_5_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void PDC_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ADV_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void RRDCU_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void RLDCU_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void PDCU_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void DDCU_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void PLG_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void BCM1_2_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void BCM1_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void AIC_2_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void DMS_2_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void MCP_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ADV_TargetTracing_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ADV_PathTracing_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ESP_3_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ESP_2_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ABS_3_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void SAS_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void CanRxSAS_1IndicationFct(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 1 START */
extern void IlMsgSAS_1Indication(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ABS_2_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void ABS_1_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void TCU_3_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

extern void CanRxTCU_3IndicationFct(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 START */
extern void IlMsgTCU_3Indication(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */

/* CODE CATEGORY 1 START */
extern void EMS_3_Received(CanReceiveHandle rcvObject);
/* CODE CATEGORY 1 END */



/* -----------------------------------------------------------------------------
    &&&~ Multiple Callback Functions
 ----------------------------------------------------------------------------- */

/* CODE CATEGORY 1 START */
extern C_CALLBACK_1 vuint8 C_CALLBACK_2 ApplCanMsgReceived(CanRxInfoStructPtr rxStruct);
/* CODE CATEGORY 1 END */
/* CODE CATEGORY 3 START */
extern C_CALLBACK_1 void C_CALLBACK_2 IlCanCancelNotification(CanTransmitHandle txHandle);
/* CODE CATEGORY 3 END */


/* -----------------------------------------------------------------------------
    &&&~ Extern declarations Hw specififc
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_0[1];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_1[1];
/* ROM CATEGORY 4 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 extern  V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_0[2];
V_MEMROM0 extern  V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_1[2];
/* ROM CATEGORY 4 END */





/* -----------------------------------------------------------------------------
    &&&~ Handles of send objects
 ----------------------------------------------------------------------------- */

#define CanTxAVM_NM                          0
#define CanTxDebug_CanStaInfo                1
#define CanTxDebug_ReloatInfo                2
#define CanTxTargetPointInfo                 3
#define CanTxTargetSlot_CD                   4
#define CanTxTargetSlot_AB                   5
#define CanTxUSS_SLOT_R_CD                   6
#define CanTxUSS_SLOT_R_AB                   7
#define CanTxUSS_SLOT_L_CD                   8
#define CanTxUSS_SLOT_L_AB                   9
#define CanTxUSS_DE_S                        10
#define CanTxUSS_DE_R                        11
#define CanTxUSS_DE_F                        12
#define CanTxUSS_DIAG_R                      13
#define CanTxUSS_DIAG_F                      14
#define CanTxDR_2                            15
#define CanTxDR_1                            16
#define CanTxPDC_2                           17
#define CanTxPDC_1                           18
#define CanTxAVS_1                           19
#define CanTxPDC_14                          20
#define CanTxPDC_13                          21
#define CanTxPDC_12                          22
#define CanTxPDC_11                          23
#define CanTxPDC_10                          24
#define CanTxPDC_9                           25
#define CanTxPDC_8                           26
#define CanTxPDC_7                           27
#define CanTxPDC_6                           28
#define CanTxPDC_5                           29
#define CanTxPDC_4                           30
#define CanTxPDC_3                           31
#define CanTxAPS_Slot6                       32
#define CanTxAPS_Slot5                       33
#define CanTxAPS_Slot4                       34
#define CanTxAPS_Slot3                       35
#define CanTxAPS_Slot2                       36
#define CanTxAPS_Slot1                       37
#define CanTxAPS_PSD                         38
#define CanTxTxDynamicMsg0                   39
#define CanTxAPS_Replan_2                    40
#define CanTxAPS_Replan_1                    41
#define CanTxRightCurbInfo                   42
#define CanTxLeftCurbInfo                    43
#define CanTxFreespace11_ObstacleInfo        44
#define CanTxFreespace10_ObstacleInfo        45
#define CanTxFreespace9_ObstacleInfo         46
#define CanTxFreespace8_ObstacleInfo         47
#define CanTxFreespace7_ObstacleInfo         48
#define CanTxFreespace6_ObstacleInfo         49
#define CanTxFreespace5_ObstacleInfo         50
#define CanTxFreespace4_ObstacleInfo         51
#define CanTxFreespace3_ObstacleInfo         52
#define CanTxFreespace2_ObstacleInfo         53
#define CanTxFreespace1_ObstacleInfo         54
#define CanTxFreespace0_ObstacleInfo         55
#define CanTxAPS_1                           56


/* -----------------------------------------------------------------------------
    &&&~ Access to confirmation flags
 ----------------------------------------------------------------------------- */

#define AVM_NM_conf_b                        (CanConfirmationFlags.w[0].b0)
#define CanWriteSyncAVM_NM_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  AVM_NM_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Debug_CanStaInfo_conf_b              (CanConfirmationFlags.w[0].b1)
#define CanWriteSyncDebug_CanStaInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Debug_CanStaInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Debug_ReloatInfo_conf_b              (CanConfirmationFlags.w[0].b2)
#define CanWriteSyncDebug_ReloatInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Debug_ReloatInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define TargetPointInfo_conf_b               (CanConfirmationFlags.w[0].b3)
#define CanWriteSyncTargetPointInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  TargetPointInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define TargetSlot_CD_conf_b                 (CanConfirmationFlags.w[0].b4)
#define CanWriteSyncTargetSlot_CD_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  TargetSlot_CD_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define TargetSlot_AB_conf_b                 (CanConfirmationFlags.w[0].b5)
#define CanWriteSyncTargetSlot_AB_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  TargetSlot_AB_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_SLOT_R_CD_conf_b                 (CanConfirmationFlags.w[0].b6)
#define CanWriteSyncUSS_SLOT_R_CD_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_SLOT_R_CD_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_SLOT_R_AB_conf_b                 (CanConfirmationFlags.w[0].b7)
#define CanWriteSyncUSS_SLOT_R_AB_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_SLOT_R_AB_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_SLOT_L_CD_conf_b                 (CanConfirmationFlags.w[0].b10)
#define CanWriteSyncUSS_SLOT_L_CD_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_SLOT_L_CD_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_SLOT_L_AB_conf_b                 (CanConfirmationFlags.w[0].b11)
#define CanWriteSyncUSS_SLOT_L_AB_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_SLOT_L_AB_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_DE_S_conf_b                      (CanConfirmationFlags.w[0].b12)
#define CanWriteSyncUSS_DE_S_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_DE_S_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_DE_R_conf_b                      (CanConfirmationFlags.w[0].b13)
#define CanWriteSyncUSS_DE_R_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_DE_R_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_DE_F_conf_b                      (CanConfirmationFlags.w[0].b14)
#define CanWriteSyncUSS_DE_F_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_DE_F_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_DIAG_R_conf_b                    (CanConfirmationFlags.w[0].b15)
#define CanWriteSyncUSS_DIAG_R_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_DIAG_R_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define USS_DIAG_F_conf_b                    (CanConfirmationFlags.w[0].b16)
#define CanWriteSyncUSS_DIAG_F_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  USS_DIAG_F_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define DR_2_conf_b                          (CanConfirmationFlags.w[0].b17)
#define CanWriteSyncDR_2_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  DR_2_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define DR_1_conf_b                          (CanConfirmationFlags.w[0].b20)
#define CanWriteSyncDR_1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  DR_1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_2_conf_b                         (CanConfirmationFlags.w[0].b21)
#define CanWriteSyncPDC_2_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_2_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_1_conf_b                         (CanConfirmationFlags.w[0].b22)
#define CanWriteSyncPDC_1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define AVS_1_conf_b                         (CanConfirmationFlags.w[0].b23)
#define CanWriteSyncAVS_1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  AVS_1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_14_conf_b                        (CanConfirmationFlags.w[0].b24)
#define CanWriteSyncPDC_14_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_14_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_13_conf_b                        (CanConfirmationFlags.w[0].b25)
#define CanWriteSyncPDC_13_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_13_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_12_conf_b                        (CanConfirmationFlags.w[0].b26)
#define CanWriteSyncPDC_12_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_12_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_11_conf_b                        (CanConfirmationFlags.w[0].b27)
#define CanWriteSyncPDC_11_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_11_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_10_conf_b                        (CanConfirmationFlags.w[0].b30)
#define CanWriteSyncPDC_10_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_10_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_9_conf_b                         (CanConfirmationFlags.w[0].b31)
#define CanWriteSyncPDC_9_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_9_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_8_conf_b                         (CanConfirmationFlags.w[0].b32)
#define CanWriteSyncPDC_8_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_8_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_7_conf_b                         (CanConfirmationFlags.w[0].b33)
#define CanWriteSyncPDC_7_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_7_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_6_conf_b                         (CanConfirmationFlags.w[0].b34)
#define CanWriteSyncPDC_6_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_6_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_5_conf_b                         (CanConfirmationFlags.w[0].b35)
#define CanWriteSyncPDC_5_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_5_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_4_conf_b                         (CanConfirmationFlags.w[0].b36)
#define CanWriteSyncPDC_4_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_4_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define PDC_3_conf_b                         (CanConfirmationFlags.w[0].b37)
#define CanWriteSyncPDC_3_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  PDC_3_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot6_conf_b                     (CanConfirmationFlags.w[1].b0)
#define CanWriteSyncAPS_Slot6_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot6_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot5_conf_b                     (CanConfirmationFlags.w[1].b1)
#define CanWriteSyncAPS_Slot5_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot5_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot4_conf_b                     (CanConfirmationFlags.w[1].b2)
#define CanWriteSyncAPS_Slot4_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot4_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot3_conf_b                     (CanConfirmationFlags.w[1].b3)
#define CanWriteSyncAPS_Slot3_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot3_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot2_conf_b                     (CanConfirmationFlags.w[1].b4)
#define CanWriteSyncAPS_Slot2_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot2_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Slot1_conf_b                     (CanConfirmationFlags.w[1].b5)
#define CanWriteSyncAPS_Slot1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Slot1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_PSD_conf_b                       (CanConfirmationFlags.w[1].b6)
#define CanWriteSyncAPS_PSD_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_PSD_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define TxDynamicMsg0_conf_b                 (CanConfirmationFlags.w[1].b7)
#define CanWriteSyncTxDynamicMsg0_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  TxDynamicMsg0_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Replan_2_conf_b                  (CanConfirmationFlags.w[1].b10)
#define CanWriteSyncAPS_Replan_2_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Replan_2_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_Replan_1_conf_b                  (CanConfirmationFlags.w[1].b11)
#define CanWriteSyncAPS_Replan_1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_Replan_1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define RightCurbInfo_conf_b                 (CanConfirmationFlags.w[1].b12)
#define CanWriteSyncRightCurbInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  RightCurbInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define LeftCurbInfo_conf_b                  (CanConfirmationFlags.w[1].b13)
#define CanWriteSyncLeftCurbInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  LeftCurbInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace11_ObstacleInfo_conf_b      (CanConfirmationFlags.w[1].b14)
#define CanWriteSyncFreespace11_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace11_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace10_ObstacleInfo_conf_b      (CanConfirmationFlags.w[1].b15)
#define CanWriteSyncFreespace10_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace10_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace9_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b16)
#define CanWriteSyncFreespace9_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace9_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace8_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b17)
#define CanWriteSyncFreespace8_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace8_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace7_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b20)
#define CanWriteSyncFreespace7_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace7_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace6_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b21)
#define CanWriteSyncFreespace6_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace6_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace5_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b22)
#define CanWriteSyncFreespace5_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace5_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace4_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b23)
#define CanWriteSyncFreespace4_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace4_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace3_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b24)
#define CanWriteSyncFreespace3_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace3_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace2_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b25)
#define CanWriteSyncFreespace2_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace2_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace1_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b26)
#define CanWriteSyncFreespace1_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace1_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define Freespace0_ObstacleInfo_conf_b       (CanConfirmationFlags.w[1].b27)
#define CanWriteSyncFreespace0_ObstacleInfo_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  Freespace0_ObstacleInfo_conf_b = (x); \
  CanEndFlagWriteSync(); \
}
#define APS_1_conf_b                         (CanConfirmationFlags.w[1].b30)
#define CanWriteSyncAPS_1_conf_b(x) \
{ \
  CanStartFlagWriteSync(); \
  APS_1_conf_b = (x); \
  CanEndFlagWriteSync(); \
}


/* -----------------------------------------------------------------------------
    &&&~ Handles of receive objects
 ----------------------------------------------------------------------------- */

#define CanRxalpha_distance_Long             0
#define CanRxalpha_distance_R                1
#define CanRxalpha_distance_F                2
#define CanRxHU_20                           3
#define CanRxUSS_SLOT_R_CD                   4
#define CanRxUSS_SLOT_R_AB                   5
#define CanRxUSS_SLOT_L_CD                   6
#define CanRxUSS_SLOT_L_AB                   7
#define CanRxUSS_DE_S                        8
#define CanRxUSS_DE_R                        9
#define CanRxUSS_DIAG_R                      10
#define CanRxUSS_DIAG_F                      11
#define CanRxGW_Config                       12
#define CanRxGPS_1                           13
#define CanRxTBOX_1                          14
#define CanRxHU_10                           15
#define CanRxHU_14                           16
#define CanRxIC_1                            17
#define CanRxHU_Speech_1                     18
#define CanRxHU_6                            19
#define CanRxHU_5                            20
#define CanRxHU_18                           21
#define CanRxPDC_1                           22
#define CanRxADV_4                           23
#define CanRxADV_1                           24
#define CanRxRRDCU_1                         25
#define CanRxRLDCU_1                         26
#define CanRxPDCU_1                          27
#define CanRxDDCU_1                          28
#define CanRxPLG_1                           29
#define CanRxBCM1_7                          30
#define CanRxBCM1_3                          31
#define CanRxBCM1_2                          32
#define CanRxBCM1_1                          33
#define CanRxATC_2                           34
#define CanRxDMS_2                           35
#define CanRxMCP_1                           36
#define CanRxADV_TargetTracing               37
#define CanRxADV_PathTracing                 38
#define CanRxESC_3                           39
#define CanRxESC_2                           40
#define CanRxABS_3                           41
#define CanRxSAS_1                           42
#define CanRxABS_2                           43
#define CanRxABS_1                           44
#define CanRxTCU_3                           45
#define CanRxEMS_3                           46
#define CanRxADV_P1                          47
#define CanRxDiag_Fun_Req                    48
#define CanRxAVM_Phy_Req                     49


/* -----------------------------------------------------------------------------
    &&&~ Access to signals
 ----------------------------------------------------------------------------- */

#define b_Wakeup_reason_c                    (AVM_NM.AVM_NM.Wakeup_reason)
#define b_Stay_awake_reason_c                (AVM_NM.AVM_NM.Stay_awake_reason)
#define b_Extension_information_c            (AVM_NM.AVM_NM.Extension_information)


/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Rx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */
#define c1_alpha_distance_Long_c             (alpha_distance_Long._c[0])
#define c2_alpha_distance_Long_c             (alpha_distance_Long._c[1])
#define c3_alpha_distance_Long_c             (alpha_distance_Long._c[2])
#define c4_alpha_distance_Long_c             (alpha_distance_Long._c[3])
#define c5_alpha_distance_Long_c             (alpha_distance_Long._c[4])
#define c6_alpha_distance_Long_c             (alpha_distance_Long._c[5])
#define c7_alpha_distance_Long_c             (alpha_distance_Long._c[6])
#define c8_alpha_distance_Long_c             (alpha_distance_Long._c[7])

/* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */
#define c1_alpha_distance_R_c                (alpha_distance_R._c[0])
#define c2_alpha_distance_R_c                (alpha_distance_R._c[1])
#define c3_alpha_distance_R_c                (alpha_distance_R._c[2])
#define c4_alpha_distance_R_c                (alpha_distance_R._c[3])
#define c5_alpha_distance_R_c                (alpha_distance_R._c[4])
#define c6_alpha_distance_R_c                (alpha_distance_R._c[5])
#define c7_alpha_distance_R_c                (alpha_distance_R._c[6])
#define c8_alpha_distance_R_c                (alpha_distance_R._c[7])

/* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */
#define c1_alpha_distance_F_c                (alpha_distance_F._c[0])
#define c2_alpha_distance_F_c                (alpha_distance_F._c[1])
#define c3_alpha_distance_F_c                (alpha_distance_F._c[2])
#define c4_alpha_distance_F_c                (alpha_distance_F._c[3])
#define c5_alpha_distance_F_c                (alpha_distance_F._c[4])
#define c6_alpha_distance_F_c                (alpha_distance_F._c[5])
#define c7_alpha_distance_F_c                (alpha_distance_F._c[6])
#define c8_alpha_distance_F_c                (alpha_distance_F._c[7])

/* ID: 0x00000381, Handle: 3, HU_20 [FC] */
#define c1_HU_20_c                           (HU_20._c[0])
#define c2_HU_20_c                           (HU_20._c[1])
#define c3_HU_20_c                           (HU_20._c[2])
#define c4_HU_20_c                           (HU_20._c[3])
#define c5_HU_20_c                           (HU_20._c[4])
#define c6_HU_20_c                           (HU_20._c[5])
#define c7_HU_20_c                           (HU_20._c[6])

/* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */
#define c1_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[0])
#define c2_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[1])
#define c3_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[2])
#define c4_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[3])
#define c5_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[4])
#define c6_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[5])
#define c7_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[6])
#define c8_USS_SLOT_R_CD_c                   (USS_SLOT_R_CD._c[7])

/* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */
#define c1_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[0])
#define c2_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[1])
#define c3_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[2])
#define c4_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[3])
#define c5_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[4])
#define c6_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[5])
#define c7_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[6])
#define c8_USS_SLOT_R_AB_c                   (USS_SLOT_R_AB._c[7])

/* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */
#define c1_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[0])
#define c2_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[1])
#define c3_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[2])
#define c4_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[3])
#define c5_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[4])
#define c6_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[5])
#define c7_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[6])
#define c8_USS_SLOT_L_CD_c                   (USS_SLOT_L_CD._c[7])

/* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */
#define c1_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[0])
#define c2_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[1])
#define c3_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[2])
#define c4_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[3])
#define c5_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[4])
#define c6_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[5])
#define c7_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[6])
#define c8_USS_SLOT_L_AB_c                   (USS_SLOT_L_AB._c[7])

/* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */
#define c1_USS_DE_S_c                        (USS_DE_S._c[0])
#define c2_USS_DE_S_c                        (USS_DE_S._c[1])
#define c3_USS_DE_S_c                        (USS_DE_S._c[2])
#define c4_USS_DE_S_c                        (USS_DE_S._c[3])
#define c5_USS_DE_S_c                        (USS_DE_S._c[4])
#define c6_USS_DE_S_c                        (USS_DE_S._c[5])
#define c7_USS_DE_S_c                        (USS_DE_S._c[6])
#define c8_USS_DE_S_c                        (USS_DE_S._c[7])

/* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */
#define c1_USS_DE_R_c                        (USS_DE_R._c[0])
#define c2_USS_DE_R_c                        (USS_DE_R._c[1])
#define c3_USS_DE_R_c                        (USS_DE_R._c[2])
#define c4_USS_DE_R_c                        (USS_DE_R._c[3])
#define c5_USS_DE_R_c                        (USS_DE_R._c[4])
#define c6_USS_DE_R_c                        (USS_DE_R._c[5])
#define c7_USS_DE_R_c                        (USS_DE_R._c[6])
#define c8_USS_DE_R_c                        (USS_DE_R._c[7])

/* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */
#define c1_USS_DIAG_R_c                      (USS_DIAG_R._c[0])
#define c2_USS_DIAG_R_c                      (USS_DIAG_R._c[1])
#define c3_USS_DIAG_R_c                      (USS_DIAG_R._c[2])
#define c4_USS_DIAG_R_c                      (USS_DIAG_R._c[3])
#define c5_USS_DIAG_R_c                      (USS_DIAG_R._c[4])
#define c6_USS_DIAG_R_c                      (USS_DIAG_R._c[5])
#define c7_USS_DIAG_R_c                      (USS_DIAG_R._c[6])
#define c8_USS_DIAG_R_c                      (USS_DIAG_R._c[7])

/* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */
#define c1_USS_DIAG_F_c                      (USS_DIAG_F._c[0])
#define c2_USS_DIAG_F_c                      (USS_DIAG_F._c[1])
#define c3_USS_DIAG_F_c                      (USS_DIAG_F._c[2])
#define c4_USS_DIAG_F_c                      (USS_DIAG_F._c[3])
#define c5_USS_DIAG_F_c                      (USS_DIAG_F._c[4])
#define c6_USS_DIAG_F_c                      (USS_DIAG_F._c[5])
#define c7_USS_DIAG_F_c                      (USS_DIAG_F._c[6])
#define c8_USS_DIAG_F_c                      (USS_DIAG_F._c[7])

/* ID: 0x000002b0, Handle: 12, GW_Config [FC] */
#define c1_GW_Config_c                       (GW_Config._c[0])
#define c2_GW_Config_c                       (GW_Config._c[1])
#define c3_GW_Config_c                       (GW_Config._c[2])

/* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */
#define c1_GPS_1_c                           (GPS_1._c[0])
#define c2_GPS_1_c                           (GPS_1._c[1])
#define c3_GPS_1_c                           (GPS_1._c[2])
#define c4_GPS_1_c                           (GPS_1._c[3])
#define c5_GPS_1_c                           (GPS_1._c[4])
#define c6_GPS_1_c                           (GPS_1._c[5])

/* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */
#define c1_TBOX_1_c                          (TBOX_1._c[0])
#define c2_TBOX_1_c                          (TBOX_1._c[1])
#define c3_TBOX_1_c                          (TBOX_1._c[2])
#define c4_TBOX_1_c                          (TBOX_1._c[3])
#define c5_TBOX_1_c                          (TBOX_1._c[4])
#define c6_TBOX_1_c                          (TBOX_1._c[5])
#define c7_TBOX_1_c                          (TBOX_1._c[6])
#define c8_TBOX_1_c                          (TBOX_1._c[7])

/* ID: 0x0000029b, Handle: 15, HU_10 [FC] */
#define c1_HU_10_c                           (HU_10._c[0])
#define c2_HU_10_c                           (HU_10._c[1])
#define c3_HU_10_c                           (HU_10._c[2])
#define c4_HU_10_c                           (HU_10._c[3])
#define c5_HU_10_c                           (HU_10._c[4])
#define c6_HU_10_c                           (HU_10._c[5])
#define c7_HU_10_c                           (HU_10._c[6])
#define c8_HU_10_c                           (HU_10._c[7])

/* ID: 0x00000291, Handle: 16, HU_14 [FC] */
#define c1_HU_14_c                           (HU_14._c[0])
#define c2_HU_14_c                           (HU_14._c[1])
#define c3_HU_14_c                           (HU_14._c[2])
#define c4_HU_14_c                           (HU_14._c[3])

/* ID: 0x00000290, Handle: 17, IC_1 [FC] */
#define c1_IC_1_c                            (IC_1._c[0])
#define c2_IC_1_c                            (IC_1._c[1])
#define c3_IC_1_c                            (IC_1._c[2])
#define c4_IC_1_c                            (IC_1._c[3])
#define c5_IC_1_c                            (IC_1._c[4])
#define c6_IC_1_c                            (IC_1._c[5])
#define c7_IC_1_c                            (IC_1._c[6])

/* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */
#define c1_HU_Speech_1_c                     (HU_Speech_1._c[0])
#define c2_HU_Speech_1_c                     (HU_Speech_1._c[1])
#define c3_HU_Speech_1_c                     (HU_Speech_1._c[2])
#define c4_HU_Speech_1_c                     (HU_Speech_1._c[3])
#define c5_HU_Speech_1_c                     (HU_Speech_1._c[4])
#define c6_HU_Speech_1_c                     (HU_Speech_1._c[5])
#define c7_HU_Speech_1_c                     (HU_Speech_1._c[6])
#define c8_HU_Speech_1_c                     (HU_Speech_1._c[7])

/* ID: 0x0000028a, Handle: 19, HU_6 [FC] */
#define c1_HU_6_c                            (HU_6._c[0])
#define c2_HU_6_c                            (HU_6._c[1])
#define c3_HU_6_c                            (HU_6._c[2])
#define c4_HU_6_c                            (HU_6._c[3])
#define c5_HU_6_c                            (HU_6._c[4])
#define c6_HU_6_c                            (HU_6._c[5])
#define c7_HU_6_c                            (HU_6._c[6])
#define c8_HU_6_c                            (HU_6._c[7])

/* ID: 0x00000288, Handle: 20, HU_5 [FC] */
#define c1_HU_5_c                            (HU_5._c[0])
#define c2_HU_5_c                            (HU_5._c[1])
#define c3_HU_5_c                            (HU_5._c[2])
#define c4_HU_5_c                            (HU_5._c[3])
#define c5_HU_5_c                            (HU_5._c[4])
#define c6_HU_5_c                            (HU_5._c[5])
#define c7_HU_5_c                            (HU_5._c[6])
#define c8_HU_5_c                            (HU_5._c[7])

/* ID: 0x00000283, Handle: 21, HU_18 [FC] */
#define c1_HU_18_c                           (HU_18._c[0])
#define c2_HU_18_c                           (HU_18._c[1])
#define c3_HU_18_c                           (HU_18._c[2])
#define c4_HU_18_c                           (HU_18._c[3])
#define c5_HU_18_c                           (HU_18._c[4])
#define c6_HU_18_c                           (HU_18._c[5])
#define c7_HU_18_c                           (HU_18._c[6])
#define c8_HU_18_c                           (HU_18._c[7])

/* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */
#define c1_PDC_1_c                           (PDC_1._c[0])
#define c2_PDC_1_c                           (PDC_1._c[1])
#define c3_PDC_1_c                           (PDC_1._c[2])
#define c4_PDC_1_c                           (PDC_1._c[3])
#define c5_PDC_1_c                           (PDC_1._c[4])
#define c6_PDC_1_c                           (PDC_1._c[5])
#define c7_PDC_1_c                           (PDC_1._c[6])
#define c8_PDC_1_c                           (PDC_1._c[7])

/* ID: 0x00000251, Handle: 23, ADV_4 [FC] */
#define c1_ADV_4_c                           (ADV_4._c[0])
#define c2_ADV_4_c                           (ADV_4._c[1])
#define c3_ADV_4_c                           (ADV_4._c[2])
#define c4_ADV_4_c                           (ADV_4._c[3])
#define c5_ADV_4_c                           (ADV_4._c[4])
#define c6_ADV_4_c                           (ADV_4._c[5])
#define c7_ADV_4_c                           (ADV_4._c[6])
#define c8_ADV_4_c                           (ADV_4._c[7])

/* ID: 0x00000250, Handle: 24, ADV_1 [FC] */
#define c1_ADV_1_c                           (ADV_1._c[0])
#define c2_ADV_1_c                           (ADV_1._c[1])
#define c3_ADV_1_c                           (ADV_1._c[2])
#define c4_ADV_1_c                           (ADV_1._c[3])
#define c5_ADV_1_c                           (ADV_1._c[4])
#define c6_ADV_1_c                           (ADV_1._c[5])
#define c7_ADV_1_c                           (ADV_1._c[6])
#define c8_ADV_1_c                           (ADV_1._c[7])

/* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */
#define c1_RRDCU_1_c                         (RRDCU_1._c[0])

/* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */
#define c1_RLDCU_1_c                         (RLDCU_1._c[0])

/* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */
#define c1_PDCU_1_c                          (PDCU_1._c[0])
#define c2_PDCU_1_c                          (PDCU_1._c[1])
#define c3_PDCU_1_c                          (PDCU_1._c[2])
#define c4_PDCU_1_c                          (PDCU_1._c[3])
#define c5_PDCU_1_c                          (PDCU_1._c[4])

/* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */
#define c1_DDCU_1_c                          (DDCU_1._c[0])
#define c2_DDCU_1_c                          (DDCU_1._c[1])
#define c3_DDCU_1_c                          (DDCU_1._c[2])
#define c4_DDCU_1_c                          (DDCU_1._c[3])
#define c5_DDCU_1_c                          (DDCU_1._c[4])

/* ID: 0x00000242, Handle: 29, PLG_1 [FC] */
#define c1_PLG_1_c                           (PLG_1._c[0])

/* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */
#define c1_BCM1_7_c                          (BCM1_7._c[0])
#define c2_BCM1_7_c                          (BCM1_7._c[1])
#define c3_BCM1_7_c                          (BCM1_7._c[2])
#define c4_BCM1_7_c                          (BCM1_7._c[3])

/* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */
#define c1_BCM1_3_c                          (BCM1_3._c[0])
#define c2_BCM1_3_c                          (BCM1_3._c[1])

/* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */
#define c1_BCM1_2_c                          (BCM1_2._c[0])

/* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */
#define c1_BCM1_1_c                          (BCM1_1._c[0])
#define c2_BCM1_1_c                          (BCM1_1._c[1])
#define c3_BCM1_1_c                          (BCM1_1._c[2])
#define c4_BCM1_1_c                          (BCM1_1._c[3])
#define c5_BCM1_1_c                          (BCM1_1._c[4])

/* ID: 0x00000222, Handle: 34, ATC_2 [FC] */
#define c1_ATC_2_c                           (ATC_2._c[0])
#define c2_ATC_2_c                           (ATC_2._c[1])
#define c3_ATC_2_c                           (ATC_2._c[2])
#define c4_ATC_2_c                           (ATC_2._c[3])

/* ID: 0x00000216, Handle: 35, DMS_2 [FC] */
#define c1_DMS_2_c                           (DMS_2._c[0])
#define c2_DMS_2_c                           (DMS_2._c[1])

/* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */
#define c1_MCP_1_c                           (MCP_1._c[0])
#define c2_MCP_1_c                           (MCP_1._c[1])
#define c3_MCP_1_c                           (MCP_1._c[2])
#define c4_MCP_1_c                           (MCP_1._c[3])

/* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */
#define c1_ADV_TargetTracing_c               (ADV_TargetTracing._c[0])
#define c2_ADV_TargetTracing_c               (ADV_TargetTracing._c[1])
#define c3_ADV_TargetTracing_c               (ADV_TargetTracing._c[2])
#define c4_ADV_TargetTracing_c               (ADV_TargetTracing._c[3])
#define c5_ADV_TargetTracing_c               (ADV_TargetTracing._c[4])
#define c6_ADV_TargetTracing_c               (ADV_TargetTracing._c[5])
#define c7_ADV_TargetTracing_c               (ADV_TargetTracing._c[6])
#define c8_ADV_TargetTracing_c               (ADV_TargetTracing._c[7])

/* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */
#define c1_ADV_PathTracing_c                 (ADV_PathTracing._c[0])
#define c2_ADV_PathTracing_c                 (ADV_PathTracing._c[1])
#define c3_ADV_PathTracing_c                 (ADV_PathTracing._c[2])
#define c4_ADV_PathTracing_c                 (ADV_PathTracing._c[3])
#define c5_ADV_PathTracing_c                 (ADV_PathTracing._c[4])
#define c6_ADV_PathTracing_c                 (ADV_PathTracing._c[5])
#define c7_ADV_PathTracing_c                 (ADV_PathTracing._c[6])
#define c8_ADV_PathTracing_c                 (ADV_PathTracing._c[7])

/* ID: 0x00000134, Handle: 39, ESC_3 [FC] */
#define c1_ESC_3_c                           (ESC_3._c[0])
#define c2_ESC_3_c                           (ESC_3._c[1])
#define c3_ESC_3_c                           (ESC_3._c[2])
#define c4_ESC_3_c                           (ESC_3._c[3])
#define c5_ESC_3_c                           (ESC_3._c[4])
#define c6_ESC_3_c                           (ESC_3._c[5])
#define c7_ESC_3_c                           (ESC_3._c[6])
#define c8_ESC_3_c                           (ESC_3._c[7])

/* ID: 0x00000132, Handle: 40, ESC_2 [FC] */
#define c1_ESC_2_c                           (ESC_2._c[0])
#define c2_ESC_2_c                           (ESC_2._c[1])
#define c3_ESC_2_c                           (ESC_2._c[2])
#define c4_ESC_2_c                           (ESC_2._c[3])
#define c5_ESC_2_c                           (ESC_2._c[4])
#define c6_ESC_2_c                           (ESC_2._c[5])
#define c7_ESC_2_c                           (ESC_2._c[6])
#define c8_ESC_2_c                           (ESC_2._c[7])

/* ID: 0x00000130, Handle: 41, ABS_3 [FC] */
#define c1_ABS_3_c                           (ABS_3._c[0])
#define c2_ABS_3_c                           (ABS_3._c[1])
#define c3_ABS_3_c                           (ABS_3._c[2])
#define c4_ABS_3_c                           (ABS_3._c[3])
#define c5_ABS_3_c                           (ABS_3._c[4])
#define c6_ABS_3_c                           (ABS_3._c[5])
#define c7_ABS_3_c                           (ABS_3._c[6])
#define c8_ABS_3_c                           (ABS_3._c[7])

/* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */
#define c1_SAS_1_c                           (SAS_1._c[0])
#define c2_SAS_1_c                           (SAS_1._c[1])
#define c3_SAS_1_c                           (SAS_1._c[2])
#define c4_SAS_1_c                           (SAS_1._c[3])
#define c5_SAS_1_c                           (SAS_1._c[4])
#define c6_SAS_1_c                           (SAS_1._c[5])
#define c7_SAS_1_c                           (SAS_1._c[6])
#define c8_SAS_1_c                           (SAS_1._c[7])

/* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */
#define c1_ABS_2_c                           (ABS_2._c[0])
#define c2_ABS_2_c                           (ABS_2._c[1])
#define c3_ABS_2_c                           (ABS_2._c[2])
#define c4_ABS_2_c                           (ABS_2._c[3])
#define c5_ABS_2_c                           (ABS_2._c[4])
#define c6_ABS_2_c                           (ABS_2._c[5])
#define c7_ABS_2_c                           (ABS_2._c[6])
#define c8_ABS_2_c                           (ABS_2._c[7])

/* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */
#define c1_ABS_1_c                           (ABS_1._c[0])
#define c2_ABS_1_c                           (ABS_1._c[1])
#define c3_ABS_1_c                           (ABS_1._c[2])
#define c4_ABS_1_c                           (ABS_1._c[3])
#define c5_ABS_1_c                           (ABS_1._c[4])
#define c6_ABS_1_c                           (ABS_1._c[5])
#define c7_ABS_1_c                           (ABS_1._c[6])
#define c8_ABS_1_c                           (ABS_1._c[7])

/* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */
#define c1_TCU_3_c                           (TCU_3._c[0])
#define c2_TCU_3_c                           (TCU_3._c[1])
#define c3_TCU_3_c                           (TCU_3._c[2])
#define c4_TCU_3_c                           (TCU_3._c[3])
#define c5_TCU_3_c                           (TCU_3._c[4])
#define c6_TCU_3_c                           (TCU_3._c[5])
#define c7_TCU_3_c                           (TCU_3._c[6])
#define c8_TCU_3_c                           (TCU_3._c[7])

/* ID: 0x00000094, Handle: 46, EMS_3 [FC] */
#define c1_EMS_3_c                           (EMS_3._c[0])
#define c2_EMS_3_c                           (EMS_3._c[1])
#define c3_EMS_3_c                           (EMS_3._c[2])
#define c4_EMS_3_c                           (EMS_3._c[3])
#define c5_EMS_3_c                           (EMS_3._c[4])
#define c6_EMS_3_c                           (EMS_3._c[5])
#define c7_EMS_3_c                           (EMS_3._c[6])
#define c8_EMS_3_c                           (EMS_3._c[7])

/* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */
#define c1_ADV_P1_c                          (ADV_P1._c[0])
#define c2_ADV_P1_c                          (ADV_P1._c[1])
#define c3_ADV_P1_c                          (ADV_P1._c[2])
#define c4_ADV_P1_c                          (ADV_P1._c[3])
#define c5_ADV_P1_c                          (ADV_P1._c[4])
#define c6_ADV_P1_c                          (ADV_P1._c[5])



/* -----------------------------------------------------------------------------
    &&&~ Access to data bytes of Tx messages
 ----------------------------------------------------------------------------- */

/* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */
#define c1_AVM_NM_c                          (AVM_NM._c[0])
#define c2_AVM_NM_c                          (AVM_NM._c[1])
#define c3_AVM_NM_c                          (AVM_NM._c[2])
#define c4_AVM_NM_c                          (AVM_NM._c[3])
#define c5_AVM_NM_c                          (AVM_NM._c[4])
#define c6_AVM_NM_c                          (AVM_NM._c[5])
#define c7_AVM_NM_c                          (AVM_NM._c[6])
#define c8_AVM_NM_c                          (AVM_NM._c[7])

/* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */
#define c1_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[0])
#define c2_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[1])
#define c3_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[2])
#define c4_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[3])
#define c5_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[4])
#define c6_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[5])
#define c7_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[6])
#define c8_Debug_CanStaInfo_c                (Debug_CanStaInfo._c[7])

/* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */
#define c1_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[0])
#define c2_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[1])
#define c3_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[2])
#define c4_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[3])
#define c5_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[4])
#define c6_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[5])
#define c7_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[6])
#define c8_Debug_ReloatInfo_c                (Debug_ReloatInfo._c[7])

/* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */
#define c1_TargetPointInfo_c                 (TargetPointInfo._c[0])
#define c2_TargetPointInfo_c                 (TargetPointInfo._c[1])
#define c3_TargetPointInfo_c                 (TargetPointInfo._c[2])
#define c4_TargetPointInfo_c                 (TargetPointInfo._c[3])
#define c5_TargetPointInfo_c                 (TargetPointInfo._c[4])
#define c6_TargetPointInfo_c                 (TargetPointInfo._c[5])
#define c7_TargetPointInfo_c                 (TargetPointInfo._c[6])
#define c8_TargetPointInfo_c                 (TargetPointInfo._c[7])

/* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */
#define c1_TargetSlot_CD_c                   (TargetSlot_CD._c[0])
#define c2_TargetSlot_CD_c                   (TargetSlot_CD._c[1])
#define c3_TargetSlot_CD_c                   (TargetSlot_CD._c[2])
#define c4_TargetSlot_CD_c                   (TargetSlot_CD._c[3])
#define c5_TargetSlot_CD_c                   (TargetSlot_CD._c[4])
#define c6_TargetSlot_CD_c                   (TargetSlot_CD._c[5])
#define c7_TargetSlot_CD_c                   (TargetSlot_CD._c[6])
#define c8_TargetSlot_CD_c                   (TargetSlot_CD._c[7])

/* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */
#define c1_TargetSlot_AB_c                   (TargetSlot_AB._c[0])
#define c2_TargetSlot_AB_c                   (TargetSlot_AB._c[1])
#define c3_TargetSlot_AB_c                   (TargetSlot_AB._c[2])
#define c4_TargetSlot_AB_c                   (TargetSlot_AB._c[3])
#define c5_TargetSlot_AB_c                   (TargetSlot_AB._c[4])
#define c6_TargetSlot_AB_c                   (TargetSlot_AB._c[5])
#define c7_TargetSlot_AB_c                   (TargetSlot_AB._c[6])
#define c8_TargetSlot_AB_c                   (TargetSlot_AB._c[7])

/* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */
#define c1_USS_DE_F_c                        (USS_DE_F._c[0])
#define c2_USS_DE_F_c                        (USS_DE_F._c[1])
#define c3_USS_DE_F_c                        (USS_DE_F._c[2])
#define c4_USS_DE_F_c                        (USS_DE_F._c[3])
#define c5_USS_DE_F_c                        (USS_DE_F._c[4])
#define c6_USS_DE_F_c                        (USS_DE_F._c[5])
#define c7_USS_DE_F_c                        (USS_DE_F._c[6])
#define c8_USS_DE_F_c                        (USS_DE_F._c[7])

/* ID: 0x000002e1, Handle: 15, DR_2 [BC] */
#define c1_DR_2_c                            (DR_2._c[0])
#define c2_DR_2_c                            (DR_2._c[1])
#define c3_DR_2_c                            (DR_2._c[2])
#define c4_DR_2_c                            (DR_2._c[3])
#define c5_DR_2_c                            (DR_2._c[4])
#define c6_DR_2_c                            (DR_2._c[5])
#define c7_DR_2_c                            (DR_2._c[6])
#define c8_DR_2_c                            (DR_2._c[7])

/* ID: 0x000002e0, Handle: 16, DR_1 [BC] */
#define c1_DR_1_c                            (DR_1._c[0])
#define c2_DR_1_c                            (DR_1._c[1])
#define c3_DR_1_c                            (DR_1._c[2])
#define c4_DR_1_c                            (DR_1._c[3])
#define c5_DR_1_c                            (DR_1._c[4])
#define c6_DR_1_c                            (DR_1._c[5])
#define c7_DR_1_c                            (DR_1._c[6])
#define c8_DR_1_c                            (DR_1._c[7])

/* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */
#define c1_PDC_2_c                           (PDC_2._c[0])
#define c2_PDC_2_c                           (PDC_2._c[1])
#define c3_PDC_2_c                           (PDC_2._c[2])
#define c4_PDC_2_c                           (PDC_2._c[3])
#define c5_PDC_2_c                           (PDC_2._c[4])
#define c6_PDC_2_c                           (PDC_2._c[5])
#define c7_PDC_2_c                           (PDC_2._c[6])
#define c8_PDC_2_c                           (PDC_2._c[7])

/* ID: 0x00000258, Handle: 19, AVS_1 [BC] */
#define c1_AVS_1_c                           (AVS_1._c[0])
#define c2_AVS_1_c                           (AVS_1._c[1])
#define c3_AVS_1_c                           (AVS_1._c[2])
#define c4_AVS_1_c                           (AVS_1._c[3])
#define c5_AVS_1_c                           (AVS_1._c[4])
#define c6_AVS_1_c                           (AVS_1._c[5])
#define c7_AVS_1_c                           (AVS_1._c[6])
#define c8_AVS_1_c                           (AVS_1._c[7])

/* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */
#define c1_PDC_14_c                          (PDC_14._c[0])
#define c2_PDC_14_c                          (PDC_14._c[1])
#define c3_PDC_14_c                          (PDC_14._c[2])
#define c4_PDC_14_c                          (PDC_14._c[3])
#define c5_PDC_14_c                          (PDC_14._c[4])
#define c6_PDC_14_c                          (PDC_14._c[5])
#define c7_PDC_14_c                          (PDC_14._c[6])
#define c8_PDC_14_c                          (PDC_14._c[7])

/* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */
#define c1_PDC_13_c                          (PDC_13._c[0])
#define c2_PDC_13_c                          (PDC_13._c[1])
#define c3_PDC_13_c                          (PDC_13._c[2])
#define c4_PDC_13_c                          (PDC_13._c[3])
#define c5_PDC_13_c                          (PDC_13._c[4])
#define c6_PDC_13_c                          (PDC_13._c[5])
#define c7_PDC_13_c                          (PDC_13._c[6])
#define c8_PDC_13_c                          (PDC_13._c[7])

/* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */
#define c1_PDC_12_c                          (PDC_12._c[0])
#define c2_PDC_12_c                          (PDC_12._c[1])
#define c3_PDC_12_c                          (PDC_12._c[2])
#define c4_PDC_12_c                          (PDC_12._c[3])
#define c5_PDC_12_c                          (PDC_12._c[4])
#define c6_PDC_12_c                          (PDC_12._c[5])
#define c7_PDC_12_c                          (PDC_12._c[6])
#define c8_PDC_12_c                          (PDC_12._c[7])

/* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */
#define c1_PDC_11_c                          (PDC_11._c[0])
#define c2_PDC_11_c                          (PDC_11._c[1])
#define c3_PDC_11_c                          (PDC_11._c[2])
#define c4_PDC_11_c                          (PDC_11._c[3])
#define c5_PDC_11_c                          (PDC_11._c[4])
#define c6_PDC_11_c                          (PDC_11._c[5])
#define c7_PDC_11_c                          (PDC_11._c[6])
#define c8_PDC_11_c                          (PDC_11._c[7])

/* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */
#define c1_PDC_10_c                          (PDC_10._c[0])
#define c2_PDC_10_c                          (PDC_10._c[1])
#define c3_PDC_10_c                          (PDC_10._c[2])
#define c4_PDC_10_c                          (PDC_10._c[3])
#define c5_PDC_10_c                          (PDC_10._c[4])
#define c6_PDC_10_c                          (PDC_10._c[5])
#define c7_PDC_10_c                          (PDC_10._c[6])
#define c8_PDC_10_c                          (PDC_10._c[7])

/* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */
#define c1_PDC_9_c                           (PDC_9._c[0])
#define c2_PDC_9_c                           (PDC_9._c[1])
#define c3_PDC_9_c                           (PDC_9._c[2])
#define c4_PDC_9_c                           (PDC_9._c[3])
#define c5_PDC_9_c                           (PDC_9._c[4])
#define c6_PDC_9_c                           (PDC_9._c[5])
#define c7_PDC_9_c                           (PDC_9._c[6])
#define c8_PDC_9_c                           (PDC_9._c[7])

/* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */
#define c1_PDC_8_c                           (PDC_8._c[0])
#define c2_PDC_8_c                           (PDC_8._c[1])
#define c3_PDC_8_c                           (PDC_8._c[2])
#define c4_PDC_8_c                           (PDC_8._c[3])
#define c5_PDC_8_c                           (PDC_8._c[4])
#define c6_PDC_8_c                           (PDC_8._c[5])
#define c7_PDC_8_c                           (PDC_8._c[6])
#define c8_PDC_8_c                           (PDC_8._c[7])

/* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */
#define c1_PDC_7_c                           (PDC_7._c[0])
#define c2_PDC_7_c                           (PDC_7._c[1])
#define c3_PDC_7_c                           (PDC_7._c[2])
#define c4_PDC_7_c                           (PDC_7._c[3])
#define c5_PDC_7_c                           (PDC_7._c[4])
#define c6_PDC_7_c                           (PDC_7._c[5])
#define c7_PDC_7_c                           (PDC_7._c[6])
#define c8_PDC_7_c                           (PDC_7._c[7])

/* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */
#define c1_PDC_6_c                           (PDC_6._c[0])
#define c2_PDC_6_c                           (PDC_6._c[1])
#define c3_PDC_6_c                           (PDC_6._c[2])
#define c4_PDC_6_c                           (PDC_6._c[3])
#define c5_PDC_6_c                           (PDC_6._c[4])
#define c6_PDC_6_c                           (PDC_6._c[5])
#define c7_PDC_6_c                           (PDC_6._c[6])
#define c8_PDC_6_c                           (PDC_6._c[7])

/* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */
#define c1_PDC_5_c                           (PDC_5._c[0])
#define c2_PDC_5_c                           (PDC_5._c[1])
#define c3_PDC_5_c                           (PDC_5._c[2])
#define c4_PDC_5_c                           (PDC_5._c[3])
#define c5_PDC_5_c                           (PDC_5._c[4])
#define c6_PDC_5_c                           (PDC_5._c[5])
#define c7_PDC_5_c                           (PDC_5._c[6])
#define c8_PDC_5_c                           (PDC_5._c[7])

/* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */
#define c1_PDC_4_c                           (PDC_4._c[0])
#define c2_PDC_4_c                           (PDC_4._c[1])
#define c3_PDC_4_c                           (PDC_4._c[2])
#define c4_PDC_4_c                           (PDC_4._c[3])
#define c5_PDC_4_c                           (PDC_4._c[4])
#define c6_PDC_4_c                           (PDC_4._c[5])
#define c7_PDC_4_c                           (PDC_4._c[6])
#define c8_PDC_4_c                           (PDC_4._c[7])

/* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */
#define c1_PDC_3_c                           (PDC_3._c[0])
#define c2_PDC_3_c                           (PDC_3._c[1])
#define c3_PDC_3_c                           (PDC_3._c[2])
#define c4_PDC_3_c                           (PDC_3._c[3])
#define c5_PDC_3_c                           (PDC_3._c[4])
#define c6_PDC_3_c                           (PDC_3._c[5])
#define c7_PDC_3_c                           (PDC_3._c[6])
#define c8_PDC_3_c                           (PDC_3._c[7])

/* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */
#define c1_APS_Slot6_c                       (APS_Slot6._c[0])
#define c2_APS_Slot6_c                       (APS_Slot6._c[1])
#define c3_APS_Slot6_c                       (APS_Slot6._c[2])
#define c4_APS_Slot6_c                       (APS_Slot6._c[3])
#define c5_APS_Slot6_c                       (APS_Slot6._c[4])
#define c6_APS_Slot6_c                       (APS_Slot6._c[5])
#define c7_APS_Slot6_c                       (APS_Slot6._c[6])
#define c8_APS_Slot6_c                       (APS_Slot6._c[7])

/* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */
#define c1_APS_Slot5_c                       (APS_Slot5._c[0])
#define c2_APS_Slot5_c                       (APS_Slot5._c[1])
#define c3_APS_Slot5_c                       (APS_Slot5._c[2])
#define c4_APS_Slot5_c                       (APS_Slot5._c[3])
#define c5_APS_Slot5_c                       (APS_Slot5._c[4])
#define c6_APS_Slot5_c                       (APS_Slot5._c[5])
#define c7_APS_Slot5_c                       (APS_Slot5._c[6])
#define c8_APS_Slot5_c                       (APS_Slot5._c[7])

/* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */
#define c1_APS_Slot4_c                       (APS_Slot4._c[0])
#define c2_APS_Slot4_c                       (APS_Slot4._c[1])
#define c3_APS_Slot4_c                       (APS_Slot4._c[2])
#define c4_APS_Slot4_c                       (APS_Slot4._c[3])
#define c5_APS_Slot4_c                       (APS_Slot4._c[4])
#define c6_APS_Slot4_c                       (APS_Slot4._c[5])
#define c7_APS_Slot4_c                       (APS_Slot4._c[6])
#define c8_APS_Slot4_c                       (APS_Slot4._c[7])

/* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */
#define c1_APS_Slot3_c                       (APS_Slot3._c[0])
#define c2_APS_Slot3_c                       (APS_Slot3._c[1])
#define c3_APS_Slot3_c                       (APS_Slot3._c[2])
#define c4_APS_Slot3_c                       (APS_Slot3._c[3])
#define c5_APS_Slot3_c                       (APS_Slot3._c[4])
#define c6_APS_Slot3_c                       (APS_Slot3._c[5])
#define c7_APS_Slot3_c                       (APS_Slot3._c[6])
#define c8_APS_Slot3_c                       (APS_Slot3._c[7])

/* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */
#define c1_APS_Slot2_c                       (APS_Slot2._c[0])
#define c2_APS_Slot2_c                       (APS_Slot2._c[1])
#define c3_APS_Slot2_c                       (APS_Slot2._c[2])
#define c4_APS_Slot2_c                       (APS_Slot2._c[3])
#define c5_APS_Slot2_c                       (APS_Slot2._c[4])
#define c6_APS_Slot2_c                       (APS_Slot2._c[5])
#define c7_APS_Slot2_c                       (APS_Slot2._c[6])
#define c8_APS_Slot2_c                       (APS_Slot2._c[7])

/* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */
#define c1_APS_Slot1_c                       (APS_Slot1._c[0])
#define c2_APS_Slot1_c                       (APS_Slot1._c[1])
#define c3_APS_Slot1_c                       (APS_Slot1._c[2])
#define c4_APS_Slot1_c                       (APS_Slot1._c[3])
#define c5_APS_Slot1_c                       (APS_Slot1._c[4])
#define c6_APS_Slot1_c                       (APS_Slot1._c[5])
#define c7_APS_Slot1_c                       (APS_Slot1._c[6])
#define c8_APS_Slot1_c                       (APS_Slot1._c[7])

/* ID: 0x00000184, Handle: 38, APS_PSD [BC] */
#define c1_APS_PSD_c                         (APS_PSD._c[0])
#define c2_APS_PSD_c                         (APS_PSD._c[1])
#define c3_APS_PSD_c                         (APS_PSD._c[2])
#define c4_APS_PSD_c                         (APS_PSD._c[3])
#define c5_APS_PSD_c                         (APS_PSD._c[4])
#define c6_APS_PSD_c                         (APS_PSD._c[5])
#define c7_APS_PSD_c                         (APS_PSD._c[6])
#define c8_APS_PSD_c                         (APS_PSD._c[7])

/* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */
#define c1_TxDynamicMsg0_c                   (TxDynamicMsg0._c[0])
#define c2_TxDynamicMsg0_c                   (TxDynamicMsg0._c[1])
#define c3_TxDynamicMsg0_c                   (TxDynamicMsg0._c[2])
#define c4_TxDynamicMsg0_c                   (TxDynamicMsg0._c[3])
#define c5_TxDynamicMsg0_c                   (TxDynamicMsg0._c[4])
#define c6_TxDynamicMsg0_c                   (TxDynamicMsg0._c[5])
#define c7_TxDynamicMsg0_c                   (TxDynamicMsg0._c[6])
#define c8_TxDynamicMsg0_c                   (TxDynamicMsg0._c[7])

/* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */
#define c1_APS_Replan_2_c                    (APS_Replan_2._c[0])
#define c2_APS_Replan_2_c                    (APS_Replan_2._c[1])
#define c3_APS_Replan_2_c                    (APS_Replan_2._c[2])
#define c4_APS_Replan_2_c                    (APS_Replan_2._c[3])
#define c5_APS_Replan_2_c                    (APS_Replan_2._c[4])
#define c6_APS_Replan_2_c                    (APS_Replan_2._c[5])
#define c7_APS_Replan_2_c                    (APS_Replan_2._c[6])
#define c8_APS_Replan_2_c                    (APS_Replan_2._c[7])

/* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */
#define c1_APS_Replan_1_c                    (APS_Replan_1._c[0])
#define c2_APS_Replan_1_c                    (APS_Replan_1._c[1])
#define c3_APS_Replan_1_c                    (APS_Replan_1._c[2])
#define c4_APS_Replan_1_c                    (APS_Replan_1._c[3])
#define c5_APS_Replan_1_c                    (APS_Replan_1._c[4])
#define c6_APS_Replan_1_c                    (APS_Replan_1._c[5])
#define c7_APS_Replan_1_c                    (APS_Replan_1._c[6])
#define c8_APS_Replan_1_c                    (APS_Replan_1._c[7])

/* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */
#define c1_RightCurbInfo_c                   (RightCurbInfo._c[0])
#define c2_RightCurbInfo_c                   (RightCurbInfo._c[1])
#define c3_RightCurbInfo_c                   (RightCurbInfo._c[2])
#define c4_RightCurbInfo_c                   (RightCurbInfo._c[3])
#define c5_RightCurbInfo_c                   (RightCurbInfo._c[4])
#define c6_RightCurbInfo_c                   (RightCurbInfo._c[5])
#define c7_RightCurbInfo_c                   (RightCurbInfo._c[6])
#define c8_RightCurbInfo_c                   (RightCurbInfo._c[7])

/* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */
#define c1_LeftCurbInfo_c                    (LeftCurbInfo._c[0])
#define c2_LeftCurbInfo_c                    (LeftCurbInfo._c[1])
#define c3_LeftCurbInfo_c                    (LeftCurbInfo._c[2])
#define c4_LeftCurbInfo_c                    (LeftCurbInfo._c[3])
#define c5_LeftCurbInfo_c                    (LeftCurbInfo._c[4])
#define c6_LeftCurbInfo_c                    (LeftCurbInfo._c[5])
#define c7_LeftCurbInfo_c                    (LeftCurbInfo._c[6])
#define c8_LeftCurbInfo_c                    (LeftCurbInfo._c[7])

/* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */
#define c1_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[0])
#define c2_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[1])
#define c3_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[2])
#define c4_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[3])
#define c5_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[4])
#define c6_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[5])
#define c7_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[6])
#define c8_Freespace11_ObstacleInfo_c        (Freespace11_ObstacleInfo._c[7])

/* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */
#define c1_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[0])
#define c2_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[1])
#define c3_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[2])
#define c4_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[3])
#define c5_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[4])
#define c6_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[5])
#define c7_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[6])
#define c8_Freespace10_ObstacleInfo_c        (Freespace10_ObstacleInfo._c[7])

/* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */
#define c1_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[0])
#define c2_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[1])
#define c3_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[2])
#define c4_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[3])
#define c5_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[4])
#define c6_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[5])
#define c7_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[6])
#define c8_Freespace9_ObstacleInfo_c         (Freespace9_ObstacleInfo._c[7])

/* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */
#define c1_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[0])
#define c2_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[1])
#define c3_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[2])
#define c4_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[3])
#define c5_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[4])
#define c6_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[5])
#define c7_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[6])
#define c8_Freespace8_ObstacleInfo_c         (Freespace8_ObstacleInfo._c[7])

/* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */
#define c1_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[0])
#define c2_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[1])
#define c3_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[2])
#define c4_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[3])
#define c5_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[4])
#define c6_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[5])
#define c7_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[6])
#define c8_Freespace7_ObstacleInfo_c         (Freespace7_ObstacleInfo._c[7])

/* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */
#define c1_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[0])
#define c2_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[1])
#define c3_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[2])
#define c4_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[3])
#define c5_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[4])
#define c6_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[5])
#define c7_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[6])
#define c8_Freespace6_ObstacleInfo_c         (Freespace6_ObstacleInfo._c[7])

/* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */
#define c1_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[0])
#define c2_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[1])
#define c3_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[2])
#define c4_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[3])
#define c5_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[4])
#define c6_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[5])
#define c7_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[6])
#define c8_Freespace5_ObstacleInfo_c         (Freespace5_ObstacleInfo._c[7])

/* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */
#define c1_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[0])
#define c2_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[1])
#define c3_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[2])
#define c4_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[3])
#define c5_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[4])
#define c6_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[5])
#define c7_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[6])
#define c8_Freespace4_ObstacleInfo_c         (Freespace4_ObstacleInfo._c[7])

/* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */
#define c1_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[0])
#define c2_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[1])
#define c3_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[2])
#define c4_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[3])
#define c5_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[4])
#define c6_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[5])
#define c7_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[6])
#define c8_Freespace3_ObstacleInfo_c         (Freespace3_ObstacleInfo._c[7])

/* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */
#define c1_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[0])
#define c2_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[1])
#define c3_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[2])
#define c4_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[3])
#define c5_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[4])
#define c6_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[5])
#define c7_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[6])
#define c8_Freespace2_ObstacleInfo_c         (Freespace2_ObstacleInfo._c[7])

/* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */
#define c1_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[0])
#define c2_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[1])
#define c3_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[2])
#define c4_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[3])
#define c5_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[4])
#define c6_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[5])
#define c7_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[6])
#define c8_Freespace1_ObstacleInfo_c         (Freespace1_ObstacleInfo._c[7])

/* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */
#define c1_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[0])
#define c2_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[1])
#define c3_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[2])
#define c4_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[3])
#define c5_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[4])
#define c6_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[5])
#define c7_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[6])
#define c8_Freespace0_ObstacleInfo_c         (Freespace0_ObstacleInfo._c[7])

/* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
#define c1_APS_1_c                           (APS_1._c[0])
#define c2_APS_1_c                           (APS_1._c[1])
#define c3_APS_1_c                           (APS_1._c[2])
#define c4_APS_1_c                           (APS_1._c[3])
#define c5_APS_1_c                           (APS_1._c[4])
#define c6_APS_1_c                           (APS_1._c[5])
#define c7_APS_1_c                           (APS_1._c[6])
#define c8_APS_1_c                           (APS_1._c[7])



/* -----------------------------------------------------------------------------
    &&&~ RDS Access
 ----------------------------------------------------------------------------- */

typedef struct _c_PDC_1_RDS_msgTypeTag
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
} _c_PDC_1_RDS_msgType;

#define b_CAN_Wakeup_reason_c                (RDSTx_0.AVM_NM.Wakeup_reason)
#define b_CAN_Stay_awake_reason_c            (RDSTx_0.AVM_NM.Stay_awake_reason)
#define b_CAN_Extension_information_c        (RDSTx_0.AVM_NM.Extension_information)

typedef struct _c_AVM_NM_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype Wakeup_reason : 8;
  vbittype Stay_awake_reason : 8;
  vbittype Extension_information : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
  vbittype unused4 : 8;
} _c_AVM_NM_RDS_msgType;

typedef struct _c_PDC_2_RDS_msgTypeTag
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
} _c_PDC_2_RDS_msgType;

typedef struct _c_APS_Slot6_RDS_msgTypeTag
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
} _c_APS_Slot6_RDS_msgType;

typedef struct _c_APS_Slot5_RDS_msgTypeTag
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
} _c_APS_Slot5_RDS_msgType;

typedef struct _c_APS_Slot4_RDS_msgTypeTag
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
} _c_APS_Slot4_RDS_msgType;

typedef struct _c_APS_Slot3_RDS_msgTypeTag
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
} _c_APS_Slot3_RDS_msgType;

typedef struct _c_APS_Slot2_RDS_msgTypeTag
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
} _c_APS_Slot2_RDS_msgType;

typedef struct _c_APS_Slot1_RDS_msgTypeTag
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
} _c_APS_Slot1_RDS_msgType;

typedef struct _c_APS_PSD_RDS_msgTypeTag
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
} _c_APS_PSD_RDS_msgType;

typedef struct _c_AVS_1_RDS_msgTypeTag
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
} _c_AVS_1_RDS_msgType;

typedef struct _c_Debug_ReloatInfo_RDS_msgTypeTag
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
} _c_Debug_ReloatInfo_RDS_msgType;

typedef struct _c_Debug_CanStaInfo_RDS_msgTypeTag
{
  vbittype PrivateCanSta : 8;
  vbittype PubuicCanSta : 8;
  vbittype CanTaskAlive_0 : 8;
  vbittype CanTaskAlive_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 8;
} _c_Debug_CanStaInfo_RDS_msgType;

typedef struct _c_PDC_9_RDS_msgTypeTag
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
} _c_PDC_9_RDS_msgType;

typedef struct _c_PDC_8_RDS_msgTypeTag
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
} _c_PDC_8_RDS_msgType;

typedef struct _c_PDC_7_RDS_msgTypeTag
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
} _c_PDC_7_RDS_msgType;

typedef struct _c_PDC_6_RDS_msgTypeTag
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
} _c_PDC_6_RDS_msgType;

typedef struct _c_PDC_5_RDS_msgTypeTag
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
} _c_PDC_5_RDS_msgType;

typedef struct _c_PDC_4_RDS_msgTypeTag
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
} _c_PDC_4_RDS_msgType;

typedef struct _c_PDC_3_RDS_msgTypeTag
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
} _c_PDC_3_RDS_msgType;

typedef struct _c_PDC_14_RDS_msgTypeTag
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
} _c_PDC_14_RDS_msgType;

typedef struct _c_PDC_13_RDS_msgTypeTag
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
} _c_PDC_13_RDS_msgType;

typedef struct _c_PDC_12_RDS_msgTypeTag
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
} _c_PDC_12_RDS_msgType;

typedef struct _c_PDC_11_RDS_msgTypeTag
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
} _c_PDC_11_RDS_msgType;

typedef struct _c_PDC_10_RDS_msgTypeTag
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
} _c_PDC_10_RDS_msgType;

typedef struct _c_TargetSlot_AB_RDS_msgTypeTag
{
  vbittype TargetSlot_Ax_0 : 8;
  vbittype TargetSlot_Ax_1 : 8;
  vbittype TargetSlot_Ay_0 : 8;
  vbittype TargetSlot_Ay_1 : 8;
  vbittype TargetSlot_Bx_0 : 8;
  vbittype TargetSlot_Bx_1 : 8;
  vbittype TargetSlot_By_0 : 8;
  vbittype TargetSlot_By_1 : 8;
} _c_TargetSlot_AB_RDS_msgType;

typedef struct _c_TargetPointInfo_RDS_msgTypeTag
{
  vbittype FV_TargetPoint_Angle_0 : 8;
  vbittype FV_TargetPoint_Angle_1 : 8;
  vbittype FV_TargetPoint_X_0 : 8;
  vbittype FV_TargetPoint_X_1 : 8;
  vbittype FV_TargetPoint_Y_0 : 8;
  vbittype FV_TargetPoint_Y_1 : 8;
  vbittype unused0 : 8;
  vbittype unused1 : 8;
} _c_TargetPointInfo_RDS_msgType;

typedef struct _c_TargetSlot_CD_RDS_msgTypeTag
{
  vbittype TargetSlot_Cx_0 : 8;
  vbittype TargetSlot_Cx_1 : 8;
  vbittype TargetSlot_Cy_0 : 8;
  vbittype TargetSlot_Cy_1 : 8;
  vbittype TargetSlot_Dx_0 : 8;
  vbittype TargetSlot_Dx_1 : 8;
  vbittype TargetSlot_Dy_0 : 8;
  vbittype TargetSlot_Dy_1 : 8;
} _c_TargetSlot_CD_RDS_msgType;

typedef struct _c_DR_2_RDS_msgTypeTag
{
  vbittype DR_RAW_0 : 8;
  vbittype DR_RAW_1 : 8;
  vbittype DR_RAW_2 : 8;
  vbittype DR_RAW_3 : 8;
  vbittype USS_SLOT_L_DEPTH_0 : 8;
  vbittype USS_SLOT_L_DEPTH_1 : 8;
  vbittype USS_SLOT_R_DEPTH_0 : 8;
  vbittype USS_SLOT_R_DEPTH_1 : 8;
} _c_DR_2_RDS_msgType;

typedef struct _c_DR_1_RDS_msgTypeTag
{
  vbittype DR_X_0 : 8;
  vbittype DR_X_1 : 8;
  vbittype DR_X_2 : 8;
  vbittype DR_X_3 : 8;
  vbittype DR_Y_0 : 8;
  vbittype DR_Y_1 : 8;
  vbittype DR_Y_2 : 8;
  vbittype DR_Y_3 : 8;
} _c_DR_1_RDS_msgType;

typedef struct _c_USS_SLOT_R_CD_RDS_msgTypeTag
{
  vbittype USS_SLOT_R_Cx_0 : 8;
  vbittype USS_SLOT_R_Cx_1 : 8;
  vbittype USS_SLOT_R_Cy_0 : 8;
  vbittype USS_SLOT_R_Cy_1 : 8;
  vbittype USS_SLOT_R_Dx_0 : 8;
  vbittype USS_SLOT_R_Dx_1 : 8;
  vbittype USS_SLOT_R_Dy_0 : 8;
  vbittype USS_SLOT_R_Dy_1 : 8;
} _c_USS_SLOT_R_CD_RDS_msgType;

typedef struct _c_USS_SLOT_R_AB_RDS_msgTypeTag
{
  vbittype USS_SLOT_R_Ax_0 : 8;
  vbittype USS_SLOT_R_Ax_1 : 8;
  vbittype USS_SLOT_R_Ay_0 : 8;
  vbittype USS_SLOT_R_Ay_1 : 8;
  vbittype USS_SLOT_R_Bx_0 : 8;
  vbittype USS_SLOT_R_Bx_1 : 8;
  vbittype USS_SLOT_R_By_0 : 8;
  vbittype USS_SLOT_R_By_1 : 8;
} _c_USS_SLOT_R_AB_RDS_msgType;

typedef struct _c_USS_SLOT_L_CD_RDS_msgTypeTag
{
  vbittype USS_SLOT_L_Cx_0 : 8;
  vbittype USS_SLOT_L_Cx_1 : 8;
  vbittype USS_SLOT_L_Cy_0 : 8;
  vbittype USS_SLOT_L_Cy_1 : 8;
  vbittype USS_SLOT_L_Dx_0 : 8;
  vbittype USS_SLOT_L_Dx_1 : 8;
  vbittype USS_SLOT_L_Dy_0 : 8;
  vbittype USS_SLOT_L_Dy_1 : 8;
} _c_USS_SLOT_L_CD_RDS_msgType;

typedef struct _c_USS_SLOT_L_AB_RDS_msgTypeTag
{
  vbittype USS_SLOT_L_Ax_0 : 8;
  vbittype USS_SLOT_L_Ax_1 : 8;
  vbittype USS_SLOT_L_AY_0 : 8;
  vbittype USS_SLOT_L_AY_1 : 8;
  vbittype USS_SLOT_L_Bx_0 : 8;
  vbittype USS_SLOT_L_Bx_1 : 8;
  vbittype USS_SLOT_L_By_0 : 8;
  vbittype USS_SLOT_L_By_1 : 8;
} _c_USS_SLOT_L_AB_RDS_msgType;

typedef struct _c_USS_DIAG_R_RDS_msgTypeTag
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
} _c_USS_DIAG_R_RDS_msgType;

typedef struct _c_USS_DIAG_F_RDS_msgTypeTag
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
} _c_USS_DIAG_F_RDS_msgType;

typedef struct _c_USS_DE_S_RDS_msgTypeTag
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
} _c_USS_DE_S_RDS_msgType;

typedef struct _c_USS_DE_R_RDS_msgTypeTag
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
} _c_USS_DE_R_RDS_msgType;

typedef struct _c_USS_DE_F_RDS_msgTypeTag
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
} _c_USS_DE_F_RDS_msgType;

typedef struct _c_Diag_Fun_Req_RDS_msgTypeTag
{
  vbittype Diag_Fun_Req_0 : 8;
  vbittype Diag_Fun_Req_1 : 8;
  vbittype Diag_Fun_Req_2 : 8;
  vbittype Diag_Fun_Req_3 : 8;
  vbittype Diag_Fun_Req_4 : 8;
  vbittype Diag_Fun_Req_5 : 8;
  vbittype Diag_Fun_Req_6 : 8;
  vbittype Diag_Fun_Req_7 : 8;
} _c_Diag_Fun_Req_RDS_msgType;

typedef struct _c_AVM_Phy_Req_RDS_msgTypeTag
{
  vbittype AVM_Phy_Req_0 : 8;
  vbittype AVM_Phy_Req_1 : 8;
  vbittype AVM_Phy_Req_2 : 8;
  vbittype AVM_Phy_Req_3 : 8;
  vbittype AVM_Phy_Req_4 : 8;
  vbittype AVM_Phy_Req_5 : 8;
  vbittype AVM_Phy_Req_6 : 8;
  vbittype AVM_Phy_Req_7 : 8;
} _c_AVM_Phy_Req_RDS_msgType;

typedef struct _c_alpha_distance_Long_RDS_msgTypeTag
{
  vbittype alpha_USS_FL_long_0 : 8;
  vbittype alpha_USS_FL_long_1 : 8;
  vbittype alpha_USS_FR_long_0 : 8;
  vbittype alpha_USS_FR_long_1 : 8;
  vbittype alpha_USS_RL_long_0 : 8;
  vbittype alpha_USS_RL_long_1 : 8;
  vbittype alpha_USS_RR_long_0 : 8;
  vbittype alpha_USS_RR_long_1 : 8;
} _c_alpha_distance_Long_RDS_msgType;

typedef struct _c_alpha_distance_R_RDS_msgTypeTag
{
  vbittype alpha_USS_RL_0 : 8;
  vbittype alpha_USS_RL_1 : 8;
  vbittype alpha_USS_RML_0 : 8;
  vbittype alpha_USS_RML_1 : 8;
  vbittype alpha_USS_RMR_0 : 8;
  vbittype alpha_USS_RMR_1 : 8;
  vbittype alpha_USS_RR_0 : 8;
  vbittype alpha_USS_RR_1 : 8;
} _c_alpha_distance_R_RDS_msgType;

typedef struct _c_alpha_distance_F_RDS_msgTypeTag
{
  vbittype alpha_USS_FL_0 : 8;
  vbittype alpha_USS_FL_1 : 8;
  vbittype alpha_USS_FML_0 : 8;
  vbittype alpha_USS_FML_1 : 8;
  vbittype alpha_USS_FMR_0 : 8;
  vbittype alpha_USS_FMR_1 : 8;
  vbittype alpha_USS_FR_0 : 8;
  vbittype alpha_USS_FR_1 : 8;
} _c_alpha_distance_F_RDS_msgType;

typedef struct _c_HU_20_RDS_msgTypeTag
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
} _c_HU_20_RDS_msgType;

typedef struct _c_GW_Config_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 4;
  vbittype GW_RemoteVehicleMode : 1;
  vbittype unused2 : 3;
  vbittype GW_OTAMode : 3;
  vbittype unused3 : 5;
} _c_GW_Config_RDS_msgType;

typedef struct _c_GPS_1_RDS_msgTypeTag
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
} _c_GPS_1_RDS_msgType;

typedef struct _c_TBOX_1_RDS_msgTypeTag
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
} _c_TBOX_1_RDS_msgType;

typedef struct _c_HU_10_RDS_msgTypeTag
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
} _c_HU_10_RDS_msgType;

typedef struct _c_HU_14_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype DisplayTheme : 3;
  vbittype unused3 : 5;
} _c_HU_14_RDS_msgType;

typedef struct _c_IC_1_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype OdometerValue_0 : 8;
  vbittype OdometerValue_1 : 8;
  vbittype OdometerValue_2 : 8;
  vbittype OdometerValue_3 : 1;
  vbittype unused3 : 7;
} _c_IC_1_RDS_msgType;

typedef struct _c_HU_Speech_1_RDS_msgTypeTag
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
} _c_HU_Speech_1_RDS_msgType;

typedef struct _c_HU_6_RDS_msgTypeTag
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
} _c_HU_6_RDS_msgType;

typedef struct _c_HU_5_RDS_msgTypeTag
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
} _c_HU_5_RDS_msgType;

typedef struct _c_HU_18_RDS_msgTypeTag
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
} _c_HU_18_RDS_msgType;

typedef struct _c_ADV_4_RDS_msgTypeTag
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
} _c_ADV_4_RDS_msgType;

typedef struct _c_ADV_1_RDS_msgTypeTag
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
} _c_ADV_1_RDS_msgType;

typedef struct _c_RRDCU_1_RDS_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_RR : 1;
  vbittype unused1 : 5;
} _c_RRDCU_1_RDS_msgType;

typedef struct _c_RLDCU_1_RDS_msgTypeTag
{
  vbittype unused0 : 2;
  vbittype DoorSt_RL : 1;
  vbittype unused1 : 5;
} _c_RLDCU_1_RDS_msgType;

typedef struct _c_PDCU_1_RDS_msgTypeTag
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
} _c_PDCU_1_RDS_msgType;

typedef struct _c_DDCU_1_RDS_msgTypeTag
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
} _c_DDCU_1_RDS_msgType;

typedef struct _c_PLG_1_RDS_msgTypeTag
{
  vbittype LuggageDoorSt : 1;
  vbittype unused0 : 7;
} _c_PLG_1_RDS_msgType;

typedef struct _c_BCM1_7_RDS_msgTypeTag
{
  vbittype Rainlntensity : 4;
  vbittype unused0 : 4;
  vbittype Brightness_L : 8;
  vbittype Brightness_H_0 : 8;
  vbittype Brightness_H_1 : 2;
  vbittype unused1 : 6;
} _c_BCM1_7_RDS_msgType;

typedef struct _c_BCM1_3_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 4;
  vbittype EngineHoodSt : 1;
  vbittype unused2 : 3;
} _c_BCM1_3_RDS_msgType;

typedef struct _c_BCM1_2_RDS_msgTypeTag
{
  vbittype unused0 : 4;
  vbittype PowerMode : 4;
} _c_BCM1_2_RDS_msgType;

typedef struct _c_BCM1_1_RDS_msgTypeTag
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
} _c_BCM1_1_RDS_msgType;

typedef struct _c_ATC_2_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype AmbientTemp : 8;
} _c_ATC_2_RDS_msgType;

typedef struct _c_DMS_2_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype DMS_VehicleModeinfo : 4;
  vbittype unused1 : 4;
} _c_DMS_2_RDS_msgType;

typedef struct _c_MCP_1_RDS_msgTypeTag
{
  vbittype unused0 : 8;
  vbittype unused1 : 8;
  vbittype unused2 : 8;
  vbittype unused3 : 1;
  vbittype MCP_AVSandFRadarSwitch : 1;
  vbittype unused4 : 6;
} _c_MCP_1_RDS_msgType;

typedef struct _c_ADV_TargetTracing_RDS_msgTypeTag
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
} _c_ADV_TargetTracing_RDS_msgType;

typedef struct _c_ADV_PathTracing_RDS_msgTypeTag
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
} _c_ADV_PathTracing_RDS_msgType;

typedef struct _c_ESC_3_RDS_msgTypeTag
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
} _c_ESC_3_RDS_msgType;

typedef struct _c_ESC_2_RDS_msgTypeTag
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
} _c_ESC_2_RDS_msgType;

typedef struct _c_ABS_3_RDS_msgTypeTag
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
} _c_ABS_3_RDS_msgType;

typedef struct _c_SAS_1_RDS_msgTypeTag
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
} _c_SAS_1_RDS_msgType;

typedef struct _c_ABS_2_RDS_msgTypeTag
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
} _c_ABS_2_RDS_msgType;

typedef struct _c_ABS_1_RDS_msgTypeTag
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
} _c_ABS_1_RDS_msgType;

typedef struct _c_TCU_3_RDS_msgTypeTag
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
} _c_TCU_3_RDS_msgType;

typedef struct _c_EMS_3_RDS_msgTypeTag
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
} _c_EMS_3_RDS_msgType;

typedef union _c_RDS_Tx_buf_0Tag
{
  vuint8 _c[8];
  _c_PDC_1_RDS_msgType PDC_1;
  _c_AVM_NM_RDS_msgType AVM_NM;
  _c_PDC_2_RDS_msgType PDC_2;
  _c_APS_Slot6_RDS_msgType APS_Slot6;
  _c_APS_Slot5_RDS_msgType APS_Slot5;
  _c_APS_Slot4_RDS_msgType APS_Slot4;
  _c_APS_Slot3_RDS_msgType APS_Slot3;
  _c_APS_Slot2_RDS_msgType APS_Slot2;
  _c_APS_Slot1_RDS_msgType APS_Slot1;
  _c_APS_PSD_RDS_msgType APS_PSD;
  _c_AVS_1_RDS_msgType AVS_1;
  _c_Debug_ReloatInfo_RDS_msgType Debug_ReloatInfo;
  _c_Debug_CanStaInfo_RDS_msgType Debug_CanStaInfo;
  _c_PDC_9_RDS_msgType PDC_9;
  _c_PDC_8_RDS_msgType PDC_8;
  _c_PDC_7_RDS_msgType PDC_7;
  _c_PDC_6_RDS_msgType PDC_6;
  _c_PDC_5_RDS_msgType PDC_5;
  _c_PDC_4_RDS_msgType PDC_4;
  _c_PDC_3_RDS_msgType PDC_3;
  _c_PDC_14_RDS_msgType PDC_14;
  _c_PDC_13_RDS_msgType PDC_13;
  _c_PDC_12_RDS_msgType PDC_12;
  _c_PDC_11_RDS_msgType PDC_11;
  _c_PDC_10_RDS_msgType PDC_10;
  _c_TargetSlot_AB_RDS_msgType TargetSlot_AB;
  _c_TargetPointInfo_RDS_msgType TargetPointInfo;
  _c_TargetSlot_CD_RDS_msgType TargetSlot_CD;
  _c_DR_2_RDS_msgType DR_2;
  _c_DR_1_RDS_msgType DR_1;
  _c_USS_SLOT_R_CD_RDS_msgType USS_SLOT_R_CD;
  _c_USS_SLOT_R_AB_RDS_msgType USS_SLOT_R_AB;
  _c_USS_SLOT_L_CD_RDS_msgType USS_SLOT_L_CD;
  _c_USS_SLOT_L_AB_RDS_msgType USS_SLOT_L_AB;
  _c_USS_DIAG_R_RDS_msgType USS_DIAG_R;
  _c_USS_DIAG_F_RDS_msgType USS_DIAG_F;
  _c_USS_DE_S_RDS_msgType USS_DE_S;
  _c_USS_DE_R_RDS_msgType USS_DE_R;
  _c_USS_DE_F_RDS_msgType USS_DE_F;
} _c_RDS_Tx_buf_0;
typedef union _c_RDS0_bufTag
{
  vuint8 _c[8];
  _c_Diag_Fun_Req_RDS_msgType Diag_Fun_Req;
} _c_RDS0_buf;
typedef union _c_RDS1_bufTag
{
  vuint8 _c[8];
  _c_AVM_Phy_Req_RDS_msgType AVM_Phy_Req;
} _c_RDS1_buf;
typedef union _c_RDS2_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_Long_RDS_msgType alpha_distance_Long;
} _c_RDS2_buf;
typedef union _c_RDS3_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_R_RDS_msgType alpha_distance_R;
} _c_RDS3_buf;
typedef union _c_RDS4_bufTag
{
  vuint8 _c[8];
  _c_alpha_distance_F_RDS_msgType alpha_distance_F;
} _c_RDS4_buf;
typedef union _c_RDS5_bufTag
{
  vuint8 _c[7];
  _c_HU_20_RDS_msgType HU_20;
} _c_RDS5_buf;
typedef union _c_RDS6_bufTag
{
  vuint8 _c[8];
  _c_USS_SLOT_R_CD_RDS_msgType USS_SLOT_R_CD;
} _c_RDS6_buf;
typedef union _c_RDS7_bufTag
{
  vuint8 _c[3];
  _c_GW_Config_RDS_msgType GW_Config;
} _c_RDS7_buf;
typedef union _c_RDS8_bufTag
{
  vuint8 _c[6];
  _c_GPS_1_RDS_msgType GPS_1;
} _c_RDS8_buf;
typedef union _c_RDS9_bufTag
{
  vuint8 _c[8];
  _c_TBOX_1_RDS_msgType TBOX_1;
} _c_RDS9_buf;
typedef union _c_RDS10_bufTag
{
  vuint8 _c[8];
  _c_HU_10_RDS_msgType HU_10;
} _c_RDS10_buf;
typedef union _c_RDS11_bufTag
{
  vuint8 _c[4];
  _c_HU_14_RDS_msgType HU_14;
} _c_RDS11_buf;
typedef union _c_RDS12_bufTag
{
  vuint8 _c[7];
  _c_IC_1_RDS_msgType IC_1;
} _c_RDS12_buf;
typedef union _c_RDS13_bufTag
{
  vuint8 _c[8];
  _c_HU_Speech_1_RDS_msgType HU_Speech_1;
} _c_RDS13_buf;
typedef union _c_RDS14_bufTag
{
  vuint8 _c[8];
  _c_HU_6_RDS_msgType HU_6;
} _c_RDS14_buf;
typedef union _c_RDS15_bufTag
{
  vuint8 _c[8];
  _c_HU_5_RDS_msgType HU_5;
} _c_RDS15_buf;
typedef union _c_RDS16_bufTag
{
  vuint8 _c[8];
  _c_HU_18_RDS_msgType HU_18;
} _c_RDS16_buf;
typedef union _c_RDS17_bufTag
{
  vuint8 _c[8];
  _c_PDC_1_RDS_msgType PDC_1;
} _c_RDS17_buf;
typedef union _c_RDS18_bufTag
{
  vuint8 _c[8];
  _c_ADV_4_RDS_msgType ADV_4;
} _c_RDS18_buf;
typedef union _c_RDS19_bufTag
{
  vuint8 _c[8];
  _c_ADV_1_RDS_msgType ADV_1;
} _c_RDS19_buf;
typedef union _c_RDS20_bufTag
{
  vuint8 _c[1];
  _c_RRDCU_1_RDS_msgType RRDCU_1;
} _c_RDS20_buf;
typedef union _c_RDS21_bufTag
{
  vuint8 _c[1];
  _c_RLDCU_1_RDS_msgType RLDCU_1;
} _c_RDS21_buf;
typedef union _c_RDS22_bufTag
{
  vuint8 _c[5];
  _c_PDCU_1_RDS_msgType PDCU_1;
} _c_RDS22_buf;
typedef union _c_RDS23_bufTag
{
  vuint8 _c[5];
  _c_DDCU_1_RDS_msgType DDCU_1;
} _c_RDS23_buf;
typedef union _c_RDS24_bufTag
{
  vuint8 _c[1];
  _c_PLG_1_RDS_msgType PLG_1;
} _c_RDS24_buf;
typedef union _c_RDS25_bufTag
{
  vuint8 _c[4];
  _c_BCM1_7_RDS_msgType BCM1_7;
} _c_RDS25_buf;
typedef union _c_RDS26_bufTag
{
  vuint8 _c[2];
  _c_BCM1_3_RDS_msgType BCM1_3;
} _c_RDS26_buf;
typedef union _c_RDS27_bufTag
{
  vuint8 _c[1];
  _c_BCM1_2_RDS_msgType BCM1_2;
} _c_RDS27_buf;
typedef union _c_RDS28_bufTag
{
  vuint8 _c[5];
  _c_BCM1_1_RDS_msgType BCM1_1;
} _c_RDS28_buf;
typedef union _c_RDS29_bufTag
{
  vuint8 _c[4];
  _c_ATC_2_RDS_msgType ATC_2;
} _c_RDS29_buf;
typedef union _c_RDS30_bufTag
{
  vuint8 _c[2];
  _c_DMS_2_RDS_msgType DMS_2;
} _c_RDS30_buf;
typedef union _c_RDS31_bufTag
{
  vuint8 _c[4];
  _c_MCP_1_RDS_msgType MCP_1;
} _c_RDS31_buf;
typedef union _c_RDS32_bufTag
{
  vuint8 _c[8];
  _c_ADV_TargetTracing_RDS_msgType ADV_TargetTracing;
} _c_RDS32_buf;
typedef union _c_RDS33_bufTag
{
  vuint8 _c[8];
  _c_ADV_PathTracing_RDS_msgType ADV_PathTracing;
} _c_RDS33_buf;
typedef union _c_RDS34_bufTag
{
  vuint8 _c[8];
  _c_ESC_3_RDS_msgType ESC_3;
} _c_RDS34_buf;
typedef union _c_RDS35_bufTag
{
  vuint8 _c[8];
  _c_ESC_2_RDS_msgType ESC_2;
} _c_RDS35_buf;
typedef union _c_RDS36_bufTag
{
  vuint8 _c[8];
  _c_ABS_3_RDS_msgType ABS_3;
} _c_RDS36_buf;
typedef union _c_RDS37_bufTag
{
  vuint8 _c[8];
  _c_SAS_1_RDS_msgType SAS_1;
} _c_RDS37_buf;
typedef union _c_RDS38_bufTag
{
  vuint8 _c[8];
  _c_ABS_2_RDS_msgType ABS_2;
} _c_RDS38_buf;
typedef union _c_RDS39_bufTag
{
  vuint8 _c[8];
  _c_ABS_1_RDS_msgType ABS_1;
} _c_RDS39_buf;
typedef union _c_RDS40_bufTag
{
  vuint8 _c[8];
  _c_TCU_3_RDS_msgType TCU_3;
} _c_RDS40_buf;
typedef union _c_RDS41_bufTag
{
  vuint8 _c[8];
  _c_EMS_3_RDS_msgType EMS_3;
} _c_RDS41_buf;
typedef union _c_RDSBasic_buf_0Tag
{
  vuint8 _c[8];
  _c_USS_SLOT_R_AB_RDS_msgType USS_SLOT_R_AB;
  _c_USS_SLOT_L_CD_RDS_msgType USS_SLOT_L_CD;
  _c_USS_SLOT_L_AB_RDS_msgType USS_SLOT_L_AB;
  _c_USS_DIAG_R_RDS_msgType USS_DIAG_R;
  _c_USS_DIAG_F_RDS_msgType USS_DIAG_F;
  _c_USS_DE_S_RDS_msgType USS_DE_S;
  _c_USS_DE_R_RDS_msgType USS_DE_R;
} _c_RDSBasic_buf_0;


#define RDSTx_0                              ((* ((_c_RDS_Tx_buf_0 MEMORY_NORMAL *)(0xffd00000 + 0x608 + 0xb00))))
#define RDS0                                 ((* ((_c_RDS0_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS1                                 ((* ((_c_RDS1_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS2                                 ((* ((_c_RDS2_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS3                                 ((* ((_c_RDS3_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS4                                 ((* ((_c_RDS4_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS5                                 ((* ((_c_RDS5_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS6                                 ((* ((_c_RDS6_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS7                                 ((* ((_c_RDS7_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS8                                 ((* ((_c_RDS8_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS9                                 ((* ((_c_RDS9_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS10                                ((* ((_c_RDS10_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS11                                ((* ((_c_RDS11_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS12                                ((* ((_c_RDS12_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS13                                ((* ((_c_RDS13_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS14                                ((* ((_c_RDS14_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS15                                ((* ((_c_RDS15_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS16                                ((* ((_c_RDS16_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS17                                ((* ((_c_RDS17_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS18                                ((* ((_c_RDS18_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS19                                ((* ((_c_RDS19_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS20                                ((* ((_c_RDS20_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS21                                ((* ((_c_RDS21_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS22                                ((* ((_c_RDS22_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS23                                ((* ((_c_RDS23_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS24                                ((* ((_c_RDS24_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS25                                ((* ((_c_RDS25_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS26                                ((* ((_c_RDS26_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS27                                ((* ((_c_RDS27_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS28                                ((* ((_c_RDS28_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS29                                ((* ((_c_RDS29_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS30                                ((* ((_c_RDS30_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS31                                ((* ((_c_RDS31_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS32                                ((* ((_c_RDS32_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS33                                ((* ((_c_RDS33_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS34                                ((* ((_c_RDS34_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS35                                ((* ((_c_RDS35_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS36                                ((* ((_c_RDS36_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS37                                ((* ((_c_RDS37_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS38                                ((* ((_c_RDS38_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS39                                ((* ((_c_RDS39_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS40                                ((* ((_c_RDS40_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDS41                                ((* ((_c_RDS41_buf MEMORY_NORMAL *)(canRDSRxPtr[0]))))
#define RDSBasic_0                           ((* ((_c_RDSBasic_buf_0 MEMORY_NORMAL *)(canRDSRxPtr[0]))))

typedef struct _c_APS_1_RDS_msgTypeTag
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
} _c_APS_1_RDS_msgType;

typedef struct _c_RightCurbInfo_RDS_msgTypeTag
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
} _c_RightCurbInfo_RDS_msgType;

typedef struct _c_LeftCurbInfo_RDS_msgTypeTag
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
} _c_LeftCurbInfo_RDS_msgType;

typedef struct _c_Freespace9_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace9_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace8_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace8_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace7_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace7_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace6_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace6_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace5_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace5_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace4_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace4_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace3_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace3_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace2_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace2_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace1_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace1_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace11_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace11_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace10_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace10_ObstacleInfo_RDS_msgType;

typedef struct _c_Freespace0_ObstacleInfo_RDS_msgTypeTag
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
} _c_Freespace0_ObstacleInfo_RDS_msgType;

typedef struct _c_APS_Replan_2_RDS_msgTypeTag
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
} _c_APS_Replan_2_RDS_msgType;

typedef struct _c_APS_Replan_1_RDS_msgTypeTag
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
} _c_APS_Replan_1_RDS_msgType;

typedef struct _c_ADV_P1_RDS_msgTypeTag
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
} _c_ADV_P1_RDS_msgType;

typedef union _c_RDS_Tx_buf_1Tag
{
  vuint8 _c[8];
  _c_APS_1_RDS_msgType APS_1;
  _c_RightCurbInfo_RDS_msgType RightCurbInfo;
  _c_LeftCurbInfo_RDS_msgType LeftCurbInfo;
  _c_Freespace9_ObstacleInfo_RDS_msgType Freespace9_ObstacleInfo;
  _c_Freespace8_ObstacleInfo_RDS_msgType Freespace8_ObstacleInfo;
  _c_Freespace7_ObstacleInfo_RDS_msgType Freespace7_ObstacleInfo;
  _c_Freespace6_ObstacleInfo_RDS_msgType Freespace6_ObstacleInfo;
  _c_Freespace5_ObstacleInfo_RDS_msgType Freespace5_ObstacleInfo;
  _c_Freespace4_ObstacleInfo_RDS_msgType Freespace4_ObstacleInfo;
  _c_Freespace3_ObstacleInfo_RDS_msgType Freespace3_ObstacleInfo;
  _c_Freespace2_ObstacleInfo_RDS_msgType Freespace2_ObstacleInfo;
  _c_Freespace1_ObstacleInfo_RDS_msgType Freespace1_ObstacleInfo;
  _c_Freespace11_ObstacleInfo_RDS_msgType Freespace11_ObstacleInfo;
  _c_Freespace10_ObstacleInfo_RDS_msgType Freespace10_ObstacleInfo;
  _c_Freespace0_ObstacleInfo_RDS_msgType Freespace0_ObstacleInfo;
  _c_APS_Replan_2_RDS_msgType APS_Replan_2;
  _c_APS_Replan_1_RDS_msgType APS_Replan_1;
} _c_RDS_Tx_buf_1;
typedef union _c_RDSBasic_buf_1Tag
{
  vuint8 _c[6];
  _c_ADV_P1_RDS_msgType ADV_P1;
} _c_RDSBasic_buf_1;


#define RDSTx_1                              ((* ((_c_RDS_Tx_buf_1 MEMORY_NORMAL *)(0xffd00000 + 0x608 + 0xa00))))
#define RDSBasic_1                           ((* ((_c_RDSBasic_buf_1 MEMORY_NORMAL *)(canRDSRxPtr[1]))))



#define C_TX_NORMAL_0_HW_OBJ                 176
#define C_TX_NORMAL_0_HW_CHANNEL             0
#define CanRxDiag_Fun_Req_HW_OBJ             0
#define CanRxDiag_Fun_Req_HW_CHANNEL         0
#define CanRxAVM_Phy_Req_HW_OBJ              1
#define CanRxAVM_Phy_Req_HW_CHANNEL          0
#define CanRxalpha_distance_Long_HW_OBJ      2
#define CanRxalpha_distance_Long_HW_CHANNEL  0
#define CanRxalpha_distance_R_HW_OBJ         3
#define CanRxalpha_distance_R_HW_CHANNEL     0
#define CanRxalpha_distance_F_HW_OBJ         4
#define CanRxalpha_distance_F_HW_CHANNEL     0
#define CanRxHU_20_HW_OBJ                    5
#define CanRxHU_20_HW_CHANNEL                0
#define CanRxUSS_SLOT_R_CD_HW_OBJ            6
#define CanRxUSS_SLOT_R_CD_HW_CHANNEL        0
#define CanRxGW_Config_HW_OBJ                7
#define CanRxGW_Config_HW_CHANNEL            0
#define CanRxGPS_1_HW_OBJ                    8
#define CanRxGPS_1_HW_CHANNEL                0
#define CanRxTBOX_1_HW_OBJ                   9
#define CanRxTBOX_1_HW_CHANNEL               0
#define CanRxHU_10_HW_OBJ                    10
#define CanRxHU_10_HW_CHANNEL                0
#define CanRxHU_14_HW_OBJ                    11
#define CanRxHU_14_HW_CHANNEL                0
#define CanRxIC_1_HW_OBJ                     12
#define CanRxIC_1_HW_CHANNEL                 0
#define CanRxHU_Speech_1_HW_OBJ              13
#define CanRxHU_Speech_1_HW_CHANNEL          0
#define CanRxHU_6_HW_OBJ                     14
#define CanRxHU_6_HW_CHANNEL                 0
#define CanRxHU_5_HW_OBJ                     15
#define CanRxHU_5_HW_CHANNEL                 0
#define CanRxHU_18_HW_OBJ                    16
#define CanRxHU_18_HW_CHANNEL                0
#define CanRxPDC_1_HW_OBJ                    17
#define CanRxPDC_1_HW_CHANNEL                0
#define CanRxADV_4_HW_OBJ                    18
#define CanRxADV_4_HW_CHANNEL                0
#define CanRxADV_1_HW_OBJ                    19
#define CanRxADV_1_HW_CHANNEL                0
#define CanRxRRDCU_1_HW_OBJ                  20
#define CanRxRRDCU_1_HW_CHANNEL              0
#define CanRxRLDCU_1_HW_OBJ                  21
#define CanRxRLDCU_1_HW_CHANNEL              0
#define CanRxPDCU_1_HW_OBJ                   22
#define CanRxPDCU_1_HW_CHANNEL               0
#define CanRxDDCU_1_HW_OBJ                   23
#define CanRxDDCU_1_HW_CHANNEL               0
#define CanRxPLG_1_HW_OBJ                    24
#define CanRxPLG_1_HW_CHANNEL                0
#define CanRxBCM1_7_HW_OBJ                   25
#define CanRxBCM1_7_HW_CHANNEL               0
#define CanRxBCM1_3_HW_OBJ                   26
#define CanRxBCM1_3_HW_CHANNEL               0
#define CanRxBCM1_2_HW_OBJ                   27
#define CanRxBCM1_2_HW_CHANNEL               0
#define CanRxBCM1_1_HW_OBJ                   28
#define CanRxBCM1_1_HW_CHANNEL               0
#define CanRxATC_2_HW_OBJ                    29
#define CanRxATC_2_HW_CHANNEL                0
#define CanRxDMS_2_HW_OBJ                    30
#define CanRxDMS_2_HW_CHANNEL                0
#define CanRxMCP_1_HW_OBJ                    31
#define CanRxMCP_1_HW_CHANNEL                0
#define CanRxADV_TargetTracing_HW_OBJ        32
#define CanRxADV_TargetTracing_HW_CHANNEL    0
#define CanRxADV_PathTracing_HW_OBJ          33
#define CanRxADV_PathTracing_HW_CHANNEL      0
#define CanRxESC_3_HW_OBJ                    34
#define CanRxESC_3_HW_CHANNEL                0
#define CanRxESC_2_HW_OBJ                    35
#define CanRxESC_2_HW_CHANNEL                0
#define CanRxABS_3_HW_OBJ                    36
#define CanRxABS_3_HW_CHANNEL                0
#define CanRxSAS_1_HW_OBJ                    37
#define CanRxSAS_1_HW_CHANNEL                0
#define CanRxABS_2_HW_OBJ                    38
#define CanRxABS_2_HW_CHANNEL                0
#define CanRxABS_1_HW_OBJ                    39
#define CanRxABS_1_HW_CHANNEL                0
#define CanRxTCU_3_HW_OBJ                    40
#define CanRxTCU_3_HW_CHANNEL                0
#define CanRxEMS_3_HW_OBJ                    41
#define CanRxEMS_3_HW_CHANNEL                0
#define C_BASIC0_0_HW_OBJ                    129
#define C_BASIC0_0_HW_CHANNEL                0

#define C_TX_NORMAL_1_HW_OBJ                 160
#define C_TX_NORMAL_1_HW_CHANNEL             1
#define C_BASIC0_1_HW_OBJ                    128
#define C_BASIC0_1_HW_CHANNEL                1




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\can_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 390049630
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CAN_PAR_H__ */
