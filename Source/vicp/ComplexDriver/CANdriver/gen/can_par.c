/* -----------------------------------------------------------------------------
  Filename:    can_par.c
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

#define C_DRV_INTERNAL
#include "can_inc.h"
#include "can_par.h"
#include "v_inc.h"

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanTxId0 V_MEMROM2 CanTxId0[kCanNumberOfTxObjects] = 
{
  MK_STDID0(0x58Eu) /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  MK_STDID0(0x2EFu) /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  MK_STDID0(0x2EEu) /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  MK_STDID0(0x2EDu) /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  MK_STDID0(0x2ECu) /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  MK_STDID0(0x2EBu) /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  MK_STDID0(0x2EAu) /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  MK_STDID0(0x2E9u) /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  MK_STDID0(0x2E8u) /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  MK_STDID0(0x2E7u) /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  MK_STDID0(0x2E6u) /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  MK_STDID0(0x2E5u) /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  MK_STDID0(0x2E4u) /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  MK_STDID0(0x2E3u) /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  MK_STDID0(0x2E2u) /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  MK_STDID0(0x2E1u) /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  MK_STDID0(0x2E0u) /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  MK_STDID0(0x25Du) /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  MK_STDID0(0x25Cu) /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  MK_STDID0(0x258u) /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  MK_STDID0(0x1CBu) /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  MK_STDID0(0x1CAu) /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  MK_STDID0(0x1C9u) /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  MK_STDID0(0x1C8u) /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  MK_STDID0(0x1C7u) /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  MK_STDID0(0x1C6u) /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  MK_STDID0(0x1C5u) /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  MK_STDID0(0x1C4u) /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  MK_STDID0(0x1C3u) /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  MK_STDID0(0x1C2u) /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  MK_STDID0(0x1C1u) /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  MK_STDID0(0x1C0u) /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  MK_STDID0(0x18Bu) /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  MK_STDID0(0x18Au) /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  MK_STDID0(0x189u) /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  MK_STDID0(0x188u) /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  MK_STDID0(0x187u) /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  MK_STDID0(0x186u) /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  MK_STDID0(0x184u) /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  MK_STDID0(0x7FFu) /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  MK_STDID0(0x2D3u) /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  MK_STDID0(0x2D2u) /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  MK_STDID0(0x2D1u) /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  MK_STDID0(0x2D0u) /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  MK_STDID0(0x2CCu) /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  MK_STDID0(0x2CBu) /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  MK_STDID0(0x2CAu) /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C9u) /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C8u) /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C7u) /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C6u) /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C5u) /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C4u) /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C3u) /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C2u) /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  MK_STDID0(0x2C1u) /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  MK_STDID0(0x1A1u) /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxDLC[kCanNumberOfTxObjects] = 
{
  MK_TX_DLC(8) /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  MK_TX_DLC(8) /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  MK_TX_DLC(8) /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_TX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 TxDataPtr V_MEMROM2 CanTxDataPtr[kCanNumberOfTxObjects] = 
{
  (TxDataPtr) AVM_NM._c /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  (TxDataPtr) Debug_CanStaInfo._c /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  (TxDataPtr) Debug_ReloatInfo._c /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  (TxDataPtr) TargetPointInfo._c /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  (TxDataPtr) TargetSlot_CD._c /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  (TxDataPtr) TargetSlot_AB._c /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  (TxDataPtr) USS_SLOT_R_CD._c /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  (TxDataPtr) USS_SLOT_R_AB._c /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  (TxDataPtr) USS_SLOT_L_CD._c /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  (TxDataPtr) USS_SLOT_L_AB._c /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  (TxDataPtr) USS_DE_S._c /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  (TxDataPtr) USS_DE_R._c /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  (TxDataPtr) USS_DE_F._c /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  (TxDataPtr) USS_DIAG_R._c /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  (TxDataPtr) USS_DIAG_F._c /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  (TxDataPtr) DR_2._c /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  (TxDataPtr) DR_1._c /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  (TxDataPtr) PDC_2._c /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  (TxDataPtr) PDC_1._c /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  (TxDataPtr) AVS_1._c /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  (TxDataPtr) PDC_14._c /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  (TxDataPtr) PDC_13._c /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  (TxDataPtr) PDC_12._c /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  (TxDataPtr) PDC_11._c /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  (TxDataPtr) PDC_10._c /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  (TxDataPtr) PDC_9._c /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  (TxDataPtr) PDC_8._c /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  (TxDataPtr) PDC_7._c /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  (TxDataPtr) PDC_6._c /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  (TxDataPtr) PDC_5._c /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  (TxDataPtr) PDC_4._c /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  (TxDataPtr) PDC_3._c /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  (TxDataPtr) APS_Slot6._c /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  (TxDataPtr) APS_Slot5._c /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  (TxDataPtr) APS_Slot4._c /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  (TxDataPtr) APS_Slot3._c /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  (TxDataPtr) APS_Slot2._c /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  (TxDataPtr) APS_Slot1._c /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  (TxDataPtr) APS_PSD._c /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  (TxDataPtr) TxDynamicMsg0._c /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  (TxDataPtr) APS_Replan_2._c /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  (TxDataPtr) APS_Replan_1._c /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  (TxDataPtr) RightCurbInfo._c /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  (TxDataPtr) LeftCurbInfo._c /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  (TxDataPtr) Freespace11_ObstacleInfo._c /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace10_ObstacleInfo._c /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace9_ObstacleInfo._c /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace8_ObstacleInfo._c /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace7_ObstacleInfo._c /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace6_ObstacleInfo._c /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace5_ObstacleInfo._c /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace4_ObstacleInfo._c /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace3_ObstacleInfo._c /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace2_ObstacleInfo._c /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace1_ObstacleInfo._c /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  (TxDataPtr) Freespace0_ObstacleInfo._c /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  (TxDataPtr) APS_1._c /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRETRANSMIT_FCT
/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 ApplPreTransmitFct V_MEMROM2 CanTxApplPreTransmitPtr[kCanNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  V_NULL /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  V_NULL /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  V_NULL /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  V_NULL /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  V_NULL /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  V_NULL /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  V_NULL /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  V_NULL /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  V_NULL /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  V_NULL /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  V_NULL /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  V_NULL /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  V_NULL /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  V_NULL /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  V_NULL /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  V_NULL /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  V_NULL /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  V_NULL /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  V_NULL /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  PDC_14_TxPretransmit /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  PDC_13_TxPretransmit /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  PDC_12_TxPretransmit /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  PDC_11_TxPretransmit /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  PDC_10_TxPretransmit /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  PDC_9_TxPretransmit /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  PDC_8_TxPretransmit /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  PDC_7_TxPretransmit /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  PDC_6_TxPretransmit /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  PDC_5_TxPretransmit /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  PDC_4_TxPretransmit /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  PDC_3_TxPretransmit /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  V_NULL /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  V_NULL /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  V_NULL /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  V_NULL /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  V_NULL /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  V_NULL /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  V_NULL /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  V_NULL /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  V_NULL /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  V_NULL /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  V_NULL /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FCT
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplConfirmationFct V_MEMROM2 CanTxApplConfirmationPtr[kCanNumberOfTxObjects] = 
{
  CanNm_NmMsgConfirmation /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  V_NULL /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  V_NULL /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  V_NULL /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  V_NULL /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  V_NULL /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  V_NULL /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  V_NULL /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  V_NULL /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  V_NULL /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  V_NULL /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  V_NULL /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  V_NULL /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  V_NULL /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  V_NULL /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  V_NULL /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  V_NULL /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  V_NULL /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  V_NULL /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  V_NULL /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  V_NULL /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  V_NULL /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  V_NULL /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  V_NULL /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  V_NULL /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  V_NULL /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  V_NULL /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  V_NULL /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  V_NULL /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  V_NULL /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  V_NULL /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  V_NULL /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  V_NULL /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  V_NULL /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  V_NULL /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  V_NULL /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  V_NULL /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  V_NULL /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  V_NULL /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  TpDrvConfirmation /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  V_NULL /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  V_NULL /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  V_NULL /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PART_OFFLINE
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxSendMask[kCanNumberOfTxObjects] = 
{
  (vuint8) C_SEND_GRP_NM /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  (vuint8) C_SEND_GRP_DIAG /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  (vuint8) C_SEND_GRP_IL /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};

/* ROM CATEGORY 2 END */

#endif


#ifdef C_ENABLE_CONFIRMATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationOffset[kCanNumberOfTxObjects] = 
{
  0 /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  0 /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  0 /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  0 /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  0 /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  0 /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  0 /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  0 /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  1 /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  1 /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  1 /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  1 /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  1 /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  1 /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  1 /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  1 /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  2 /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  2 /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  2 /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  2 /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  2 /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  2 /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  2 /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  2 /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  3 /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  3 /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  3 /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  3 /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  3 /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  3 /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  3 /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  3 /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  4 /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  4 /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  4 /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  4 /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  4 /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  4 /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  4 /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  4 /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  5 /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  5 /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  5 /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  5 /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  5 /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  5 /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  5 /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  5 /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  6 /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  7 /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanConfirmationMask[kCanNumberOfTxObjects] = 
{
  0x01u /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  0x02u /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  0x04u /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  0x08u /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  0x10u /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  0x20u /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  0x40u /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  0x80u /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  0x01u /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  0x02u /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  0x04u /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  0x08u /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  0x10u /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  0x20u /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  0x40u /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  0x80u /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  0x01u /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  0x02u /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  0x04u /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  0x08u /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  0x10u /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  0x20u /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  0x40u /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  0x80u /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  0x01u /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  0x02u /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  0x04u /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  0x08u /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  0x10u /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  0x20u /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  0x40u /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  0x80u /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  0x01u /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  0x02u /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  0x04u /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  0x08u /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  0x10u /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  0x20u /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  0x40u /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  0x80u /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  0x01u /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  0x02u /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  0x04u /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  0x08u /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  0x10u /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  0x20u /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  0x40u /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  0x80u /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  0x02u /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  0x04u /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  0x08u /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  0x10u /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  0x20u /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  0x40u /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  0x80u /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 1 END */


#endif




/* Id table depending on search algorithm */
/* Linear search */
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanRxId0 V_MEMROM2 CanRxId0[kCanNumberOfRxObjects] = 
{
  MK_STDID0(0x2E9u) /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  MK_STDID0(0x2E8u) /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  MK_STDID0(0x2E7u) /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  MK_STDID0(0x2E6u) /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  MK_STDID0(0x2E5u) /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  MK_STDID0(0x2E3u) /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  MK_STDID0(0x2E2u) /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  MK_STDID0(0x7DFu) /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  MK_STDID0(0x726u) /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */, 
  MK_STDID0(0x3E3u) /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  MK_STDID0(0x3E2u) /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  MK_STDID0(0x3E1u) /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  MK_STDID0(0x381u) /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  MK_STDID0(0x2EAu) /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  MK_STDID0(0x2B0u) /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  MK_STDID0(0x2A6u) /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  MK_STDID0(0x2A0u) /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  MK_STDID0(0x29Bu) /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  MK_STDID0(0x291u) /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  MK_STDID0(0x290u) /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  MK_STDID0(0x28Cu) /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  MK_STDID0(0x28Au) /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  MK_STDID0(0x288u) /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  MK_STDID0(0x283u) /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  MK_STDID0(0x25Cu) /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  MK_STDID0(0x251u) /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  MK_STDID0(0x250u) /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  MK_STDID0(0x24Fu) /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  MK_STDID0(0x24Eu) /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  MK_STDID0(0x24Cu) /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  MK_STDID0(0x24Au) /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  MK_STDID0(0x242u) /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  MK_STDID0(0x23Bu) /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  MK_STDID0(0x234u) /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  MK_STDID0(0x232u) /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  MK_STDID0(0x230u) /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  MK_STDID0(0x222u) /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  MK_STDID0(0x216u) /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  MK_STDID0(0x1A4u) /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  MK_STDID0(0x182u) /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  MK_STDID0(0x180u) /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  MK_STDID0(0x134u) /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  MK_STDID0(0x132u) /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  MK_STDID0(0x130u) /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  MK_STDID0(0x0D0u) /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  MK_STDID0(0x0C2u) /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  MK_STDID0(0x0C0u) /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  MK_STDID0(0x0B4u) /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  MK_STDID0(0x094u) /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  MK_STDID0(0x1C0u) /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxMsgIndirection[kCanNumberOfRxObjects] = 
{
  5 /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB */, 
  6 /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD */, 
  7 /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB */, 
  8 /* ID: 0x000002e6, Handle: 8, USS_DE_S */, 
  9 /* ID: 0x000002e5, Handle: 9, USS_DE_R */, 
  10 /* ID: 0x000002e3, Handle: 10, USS_DIAG_R */, 
  11 /* ID: 0x000002e2, Handle: 11, USS_DIAG_F */, 
  48 /* ID: 0x000007df, Handle: 48, Diag_Fun_Req */, 
  49 /* ID: 0x00000726, Handle: 49, AVM_Phy_Req */, 
  0 /* ID: 0x000003e3, Handle: 0, alpha_distance_Long */, 
  1 /* ID: 0x000003e2, Handle: 1, alpha_distance_R */, 
  2 /* ID: 0x000003e1, Handle: 2, alpha_distance_F */, 
  3 /* ID: 0x00000381, Handle: 3, HU_20 */, 
  4 /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD */, 
  12 /* ID: 0x000002b0, Handle: 12, GW_Config */, 
  13 /* ID: 0x000002a6, Handle: 13, GPS_1 */, 
  14 /* ID: 0x000002a0, Handle: 14, TBOX_1 */, 
  15 /* ID: 0x0000029b, Handle: 15, HU_10 */, 
  16 /* ID: 0x00000291, Handle: 16, HU_14 */, 
  17 /* ID: 0x00000290, Handle: 17, IC_1 */, 
  18 /* ID: 0x0000028c, Handle: 18, HU_Speech_1 */, 
  19 /* ID: 0x0000028a, Handle: 19, HU_6 */, 
  20 /* ID: 0x00000288, Handle: 20, HU_5 */, 
  21 /* ID: 0x00000283, Handle: 21, HU_18 */, 
  22 /* ID: 0x0000025c, Handle: 22, PDC_1 */, 
  23 /* ID: 0x00000251, Handle: 23, ADV_4 */, 
  24 /* ID: 0x00000250, Handle: 24, ADV_1 */, 
  25 /* ID: 0x0000024f, Handle: 25, RRDCU_1 */, 
  26 /* ID: 0x0000024e, Handle: 26, RLDCU_1 */, 
  27 /* ID: 0x0000024c, Handle: 27, PDCU_1 */, 
  28 /* ID: 0x0000024a, Handle: 28, DDCU_1 */, 
  29 /* ID: 0x00000242, Handle: 29, PLG_1 */, 
  30 /* ID: 0x0000023b, Handle: 30, BCM1_7 */, 
  31 /* ID: 0x00000234, Handle: 31, BCM1_3 */, 
  32 /* ID: 0x00000232, Handle: 32, BCM1_2 */, 
  33 /* ID: 0x00000230, Handle: 33, BCM1_1 */, 
  34 /* ID: 0x00000222, Handle: 34, ATC_2 */, 
  35 /* ID: 0x00000216, Handle: 35, DMS_2 */, 
  36 /* ID: 0x000001a4, Handle: 36, MCP_1 */, 
  37 /* ID: 0x00000182, Handle: 37, ADV_TargetTracing */, 
  38 /* ID: 0x00000180, Handle: 38, ADV_PathTracing */, 
  39 /* ID: 0x00000134, Handle: 39, ESC_3 */, 
  40 /* ID: 0x00000132, Handle: 40, ESC_2 */, 
  41 /* ID: 0x00000130, Handle: 41, ABS_3 */, 
  42 /* ID: 0x000000d0, Handle: 42, SAS_1 */, 
  43 /* ID: 0x000000c2, Handle: 43, ABS_2 */, 
  44 /* ID: 0x000000c0, Handle: 44, ABS_1 */, 
  45 /* ID: 0x000000b4, Handle: 45, TCU_3 */, 
  46 /* ID: 0x00000094, Handle: 46, EMS_3 */, 
  47 /* ID: 0x000001c0, Handle: 47, ADV_P1 */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxDataLen[kCanNumberOfRxObjects] = 
{
  8 /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  8 /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  8 /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  7 /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  8 /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  8 /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  8 /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  8 /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  8 /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  8 /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  8 /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  8 /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  3 /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  6 /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  8 /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  8 /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  4 /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  7 /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  8 /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  8 /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  8 /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  8 /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  8 /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  8 /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  8 /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  1 /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  1 /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  5 /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  5 /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  1 /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  4 /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  2 /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  1 /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  5 /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  4 /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  2 /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  4 /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  8 /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  8 /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  8 /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  8 /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  8 /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  8 /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  8 /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  8 /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  8 /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  8 /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  6 /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  0 /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  0 /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */


#ifdef C_ENABLE_COPY_RX_DATA
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 RxDataPtr V_MEMROM2 CanRxDataPtr[kCanNumberOfRxObjects] = 
{
  (RxDataPtr) alpha_distance_Long._c /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  (RxDataPtr) alpha_distance_R._c /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  (RxDataPtr) alpha_distance_F._c /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  (RxDataPtr) HU_20._c /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  (RxDataPtr) USS_SLOT_R_CD._c /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  (RxDataPtr) USS_SLOT_R_AB._c /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  (RxDataPtr) USS_SLOT_L_CD._c /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  (RxDataPtr) USS_SLOT_L_AB._c /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  (RxDataPtr) USS_DE_S._c /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  (RxDataPtr) USS_DE_R._c /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  (RxDataPtr) USS_DIAG_R._c /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  (RxDataPtr) USS_DIAG_F._c /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  (RxDataPtr) GW_Config._c /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  (RxDataPtr) GPS_1._c /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  (RxDataPtr) TBOX_1._c /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  (RxDataPtr) HU_10._c /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  (RxDataPtr) HU_14._c /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  (RxDataPtr) IC_1._c /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  (RxDataPtr) HU_Speech_1._c /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  (RxDataPtr) HU_6._c /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  (RxDataPtr) HU_5._c /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  (RxDataPtr) HU_18._c /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  (RxDataPtr) PDC_1._c /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  (RxDataPtr) ADV_4._c /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  (RxDataPtr) ADV_1._c /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  (RxDataPtr) RRDCU_1._c /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  (RxDataPtr) RLDCU_1._c /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  (RxDataPtr) PDCU_1._c /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  (RxDataPtr) DDCU_1._c /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  (RxDataPtr) PLG_1._c /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  (RxDataPtr) BCM1_7._c /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  (RxDataPtr) BCM1_3._c /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  (RxDataPtr) BCM1_2._c /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  (RxDataPtr) BCM1_1._c /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  (RxDataPtr) ATC_2._c /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  (RxDataPtr) DMS_2._c /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  (RxDataPtr) MCP_1._c /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  (RxDataPtr) ADV_TargetTracing._c /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  (RxDataPtr) ADV_PathTracing._c /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  (RxDataPtr) ESC_3._c /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  (RxDataPtr) ESC_2._c /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  (RxDataPtr) ABS_3._c /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  (RxDataPtr) SAS_1._c /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  (RxDataPtr) ABS_2._c /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  (RxDataPtr) ABS_1._c /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  (RxDataPtr) TCU_3._c /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  (RxDataPtr) EMS_3._c /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  (RxDataPtr) ADV_P1._c /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  (RxDataPtr) 0 /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  (RxDataPtr) 0 /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_PRECOPY_FCT
/* CODE CATEGORY 1 START */
/* CODE CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 ApplPrecopyFct V_MEMROM2 CanRxApplPrecopyPtr[kCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  V_NULL /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  V_NULL /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  V_NULL /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  V_NULL /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  V_NULL /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  V_NULL /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  V_NULL /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  V_NULL /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  V_NULL /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  V_NULL /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  V_NULL /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  V_NULL /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  V_NULL /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  V_NULL /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  V_NULL /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  V_NULL /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  V_NULL /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  V_NULL /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  V_NULL /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  V_NULL /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  V_NULL /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  V_NULL /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  V_NULL /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  V_NULL /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  V_NULL /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  V_NULL /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  V_NULL /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  V_NULL /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  V_NULL /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  V_NULL /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  V_NULL /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  V_NULL /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  V_NULL /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  V_NULL /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  V_NULL /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  V_NULL /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  V_NULL /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  V_NULL /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  V_NULL /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  V_NULL /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  V_NULL /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  IlMsgSAS_1PreCopy /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  V_NULL /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  V_NULL /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  IlMsgTCU_3PreCopy /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  V_NULL /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  V_NULL /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  TpPrecopyNormalDiagFunc /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  TpPrecopyNormalDiagPhys /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FCT
void CanRxSAS_1IndicationFct(CanReceiveHandle rcvObject)
{
  SAS_1_Received(rcvObject);
  IlMsgSAS_1Indication(rcvObject);
}


void CanRxTCU_3IndicationFct(CanReceiveHandle rcvObject)
{
  TCU_3_Received(rcvObject);
  IlMsgTCU_3Indication(rcvObject);
}


/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 ApplIndicationFct V_MEMROM2 CanRxApplIndicationPtr[kCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  V_NULL /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  V_NULL /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  HU_20_Received /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  V_NULL /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  V_NULL /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  V_NULL /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  V_NULL /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  V_NULL /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  V_NULL /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  V_NULL /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  V_NULL /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  GW_Config_Received /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  GPS_1_Received /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  V_NULL /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  V_NULL /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  V_NULL /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  IC_1_Received /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  HU_Speech_1_Received /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  HU_6_Received /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  HU_5_Received /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  V_NULL /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  PDC_1_Received /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  V_NULL /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  ADV_1_Received /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  RRDCU_1_Received /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  RLDCU_1_Received /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  PDCU_1_Received /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  DDCU_1_Received /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  PLG_1_Received /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  V_NULL /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  V_NULL /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  BCM1_2_Received /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  BCM1_1_Received /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  AIC_2_Received /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  DMS_2_Received /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  MCP_1_Received /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  ADV_TargetTracing_Received /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  ADV_PathTracing_Received /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  ESP_3_Received /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  ESP_2_Received /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  ABS_3_Received /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  CanRxSAS_1IndicationFct /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  ABS_2_Received /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  ABS_1_Received /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  CanRxTCU_3IndicationFct /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  EMS_3_Received /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  V_NULL /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  V_NULL /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  V_NULL /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#endif


#ifdef C_ENABLE_INDICATION_FLAG
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationOffset[kCanNumberOfRxObjects] = 
{
  0 /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  0 /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  0 /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  0 /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  0 /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  0 /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  0 /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  0 /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  0 /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  0 /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  0 /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  0 /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  0 /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  0 /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  0 /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  0 /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  0 /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  0 /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  0 /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  0 /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  0 /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  0 /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  0 /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  0 /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  0 /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  0 /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  0 /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  0 /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  0 /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  0 /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  0 /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  0 /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  0 /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  0 /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  0 /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  0 /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  0 /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  0 /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  0 /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  0 /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  0 /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  0 /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  0 /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  0 /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  0 /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  0 /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  0 /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  0 /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  0 /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  0 /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanIndicationMask[kCanNumberOfRxObjects] = 
{
  0x00u /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  0x00u /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  0x00u /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  0x00u /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  0x00u /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  0x00u /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  0x00u /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  0x00u /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  0x00u /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  0x00u /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  0x00u /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  0x00u /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  0x00u /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  0x00u /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  0x00u /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  0x00u /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  0x00u /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  0x00u /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  0x00u /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  0x00u /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  0x00u /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  0x00u /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  0x00u /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  0x00u /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  0x00u /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  0x00u /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  0x00u /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  0x00u /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  0x00u /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  0x00u /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  0x00u /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  0x00u /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  0x00u /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  0x00u /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  0x00u /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  0x00u /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  0x00u /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  0x00u /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  0x00u /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  0x00u /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  0x00u /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  0x00u /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  0x00u /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  0x00u /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  0x00u /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  0x00u /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  0x00u /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  0x00u /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  0x00u /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  0x00u /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */


#endif




/* -----------------------------------------------------------------------------
    &&&~ Init structures
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 4 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanInitObjectStartIndex[3] = 
{
  0, 
  1, 
  2
};

/* ROM CATEGORY 4 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_0[2] = 
{
  
  {
    0x0580u, 
    0x0780u
  }, 
  
  {
    0x0000u, 
    0x0500u
  }
};
V_MEMROM0 V_MEMROM1 tCanFilterRulesBc V_MEMROM2 CanFilterRulesBc_1[2] = 
{
  
  {
    0x01C0u, 
    0x07FFu
  }, 
  
  {
    0x0000u, 
    0x07FFu
  }
};
V_MEMROM0 V_MEMROM1 vuint32 V_MEMROM2 CanInitBCFG[2] = 
{
  0x033A0004u, 
  0x033A0004u
};
/* ROM CATEGORY 4 END */



/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxDynRomStartIndex[kCanNumberOfChannels] = 
{
  39, 
  57
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxDynRamStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  1, 
  1
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
/* PRQA  S 1334 QAC_Can_1334 */ /* MD_Can_1334 */
V_MEMROM0 V_MEMROM1 tCanChannelObject V_MEMROM2 CanChannelObject[kCanNumberOfChannels] = 
{
  
  {
    ApplCanWakeUp, 
    ApplCanMsgReceived, 
    
    {
      TpPrecopyExtendedDiagPhys, 
      CanNm_NmMsgPrecopy, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY
    }, 
    CbdWrpBusOff, 
    IlCanCancelNotification, 
    ApplCanChannelDummy, 
    
    {
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x7Fu), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u)
    }, 
    
    {
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x0580u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u)
    }, 
    0x03u, 
    
    {
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd
    }
  }, 
  
  {
    ApplCanWakeUp, 
    ApplCanMsgReceived, 
    
    {
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY, 
      CAN_RANGE_FCT_DUMMY
    }, 
    ApplCanBusOff, 
    IlCanCancelNotification, 
    ApplCanChannelDummy, 
    
    {
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u), 
      MK_RX_RANGE_MASK_IDSTD(0x00u)
    }, 
    
    {
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u), 
      MK_RX_RANGE_CODE_IDSTD(0x00u)
    }, 
    0x00u, 
    
    {
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd, 
      kCanIdTypeStd
    }
  }
};
/* PRQA  L:QAC_Can_1334 */

/* ROM CATEGORY 1 END */

#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanPhysToLogChannel[kVNumberOfIdentities][kCanNumberOfPhysChannels] = 
{
  
  {
    1, 
    0
  }
};
/* ROM CATEGORY 1 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_CONFIG)
/* ROM CATEGORY 2 START */

V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanChannelIdentityAssignment[kCanNumberOfChannels] = 
{
  0x01u, 
  0x01u
};

/* ROM CATEGORY 2 END */

#endif

#if defined(C_ENABLE_MULTI_ECU_PHYS)
/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanRxIdentityAssignment[kCanNumberOfRxObjects] = 
{
  0x01u /* ID: 0x000003e3, Handle: 0, alpha_distance_Long [FC] */, 
  0x01u /* ID: 0x000003e2, Handle: 1, alpha_distance_R [FC] */, 
  0x01u /* ID: 0x000003e1, Handle: 2, alpha_distance_F [FC] */, 
  0x01u /* ID: 0x00000381, Handle: 3, HU_20 [FC] */, 
  0x01u /* ID: 0x000002ea, Handle: 4, USS_SLOT_R_CD [FC] */, 
  0x01u /* ID: 0x000002e9, Handle: 5, USS_SLOT_R_AB [BC] */, 
  0x01u /* ID: 0x000002e8, Handle: 6, USS_SLOT_L_CD [BC] */, 
  0x01u /* ID: 0x000002e7, Handle: 7, USS_SLOT_L_AB [BC] */, 
  0x01u /* ID: 0x000002e6, Handle: 8, USS_DE_S [BC] */, 
  0x01u /* ID: 0x000002e5, Handle: 9, USS_DE_R [BC] */, 
  0x01u /* ID: 0x000002e3, Handle: 10, USS_DIAG_R [BC] */, 
  0x01u /* ID: 0x000002e2, Handle: 11, USS_DIAG_F [BC] */, 
  0x01u /* ID: 0x000002b0, Handle: 12, GW_Config [FC] */, 
  0x01u /* ID: 0x000002a6, Handle: 13, GPS_1 [FC] */, 
  0x01u /* ID: 0x000002a0, Handle: 14, TBOX_1 [FC] */, 
  0x01u /* ID: 0x0000029b, Handle: 15, HU_10 [FC] */, 
  0x01u /* ID: 0x00000291, Handle: 16, HU_14 [FC] */, 
  0x01u /* ID: 0x00000290, Handle: 17, IC_1 [FC] */, 
  0x01u /* ID: 0x0000028c, Handle: 18, HU_Speech_1 [FC] */, 
  0x01u /* ID: 0x0000028a, Handle: 19, HU_6 [FC] */, 
  0x01u /* ID: 0x00000288, Handle: 20, HU_5 [FC] */, 
  0x01u /* ID: 0x00000283, Handle: 21, HU_18 [FC] */, 
  0x01u /* ID: 0x0000025c, Handle: 22, PDC_1 [FC] */, 
  0x01u /* ID: 0x00000251, Handle: 23, ADV_4 [FC] */, 
  0x01u /* ID: 0x00000250, Handle: 24, ADV_1 [FC] */, 
  0x01u /* ID: 0x0000024f, Handle: 25, RRDCU_1 [FC] */, 
  0x01u /* ID: 0x0000024e, Handle: 26, RLDCU_1 [FC] */, 
  0x01u /* ID: 0x0000024c, Handle: 27, PDCU_1 [FC] */, 
  0x01u /* ID: 0x0000024a, Handle: 28, DDCU_1 [FC] */, 
  0x01u /* ID: 0x00000242, Handle: 29, PLG_1 [FC] */, 
  0x01u /* ID: 0x0000023b, Handle: 30, BCM1_7 [FC] */, 
  0x01u /* ID: 0x00000234, Handle: 31, BCM1_3 [FC] */, 
  0x01u /* ID: 0x00000232, Handle: 32, BCM1_2 [FC] */, 
  0x01u /* ID: 0x00000230, Handle: 33, BCM1_1 [FC] */, 
  0x01u /* ID: 0x00000222, Handle: 34, ATC_2 [FC] */, 
  0x01u /* ID: 0x00000216, Handle: 35, DMS_2 [FC] */, 
  0x01u /* ID: 0x000001a4, Handle: 36, MCP_1 [FC] */, 
  0x01u /* ID: 0x00000182, Handle: 37, ADV_TargetTracing [FC] */, 
  0x01u /* ID: 0x00000180, Handle: 38, ADV_PathTracing [FC] */, 
  0x01u /* ID: 0x00000134, Handle: 39, ESC_3 [FC] */, 
  0x01u /* ID: 0x00000132, Handle: 40, ESC_2 [FC] */, 
  0x01u /* ID: 0x00000130, Handle: 41, ABS_3 [FC] */, 
  0x01u /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  0x01u /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  0x01u /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  0x01u /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  0x01u /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  0x01u /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */, 
  0x01u /* ID: 0x000007df, Handle: 48, Diag_Fun_Req [FC] */, 
  0x01u /* ID: 0x00000726, Handle: 49, AVM_Phy_Req [FC] */
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 tVIdentityMsk V_MEMROM2 CanTxIdentityAssignment[kCanNumberOfTxObjects] = 
{
  0x01u /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  0x01u /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  0x01u /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  0x01u /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  0x01u /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  0x01u /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  0x01u /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  0x01u /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  0x01u /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  0x01u /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  0x01u /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  0x01u /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  0x01u /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  0x01u /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  0x01u /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  0x01u /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  0x01u /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  0x01u /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  0x01u /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  0x01u /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  0x01u /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  0x01u /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  0x01u /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  0x01u /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  0x01u /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  0x01u /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  0x01u /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  0x01u /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  0x01u /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  0x01u /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  0x01u /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  0x01u /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  0x01u /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  0x01u /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  0x01u /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  0x01u /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  0x01u /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  0x01u /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  0x01u /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  0x01u /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  0x01u /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  0x01u /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  0x01u /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  0x01u /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  0x01u /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  0x01u /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
/* ROM CATEGORY 4 END */

#endif


/* ROM CATEGORY 1 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxQueuePadBits[kCanNumberOfChannels] = 
{
  0, 
  24
};

/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
/* PRQA S 3408 1 */ /* MD_Can_3408_extLinkage */
V_MEMROM0 V_MEMROM1 CanSignedTxHandle V_MEMROM2 CanTxQueueStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  2, 
  3
};

/* ROM CATEGORY 1 END */

/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanChannelHandle V_MEMROM2 CanTxMsgHandleToChannel[kCanNumberOfTxObjects] = 
{
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1, 
  1
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 CanTxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  40, 
  57
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  49, 
  50
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxBasicStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  49, 
  50
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 CanRxFullStartIndex[kCanNumberOfChannels+1] = 
{
  7, 
  50, 
  50
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanLogHwTxStartIndex[kCanNumberOfChannels+1] = 
{
  0, 
  1, 
  2
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxStartIndex[kCanNumberOfChannels] = 
{
  176, 
  160
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxFullStartIndex[kCanNumberOfChannels] = 
{
  0, 
  128
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxBasicStartIndex[kCanNumberOfChannels] = 
{
  129, 
  128
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 4 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwUnusedStartIndex[kCanNumberOfChannels] = 
{
  1, 
  89
};

/* ROM CATEGORY 4 END */


/* ROM CATEGORY 2 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxStopIndex[kCanNumberOfChannels] = 
{
  177, 
  161
};
/* ROM CATEGORY 2 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxFullStopIndex[kCanNumberOfChannels] = 
{
  42, 
  128
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwRxBasicStopIndex[kCanNumberOfChannels] = 
{
  130, 
  129
};
/* ROM CATEGORY 1 END */


/* ROM CATEGORY 4 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwUnusedStopIndex[kCanNumberOfChannels] = 
{
  45, 
  175
};

/* ROM CATEGORY 4 END */


#ifdef C_ENABLE_TX_FULLCAN_OBJECTS
/* ROM CATEGORY 2 START */
#ifdef C_ENABLE_HW_OBJ_EXCEED_255_DRV
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanTxHwObj[kCanNumberOfTxObjects] = 
{
  0xB0 /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  0xB0 /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  0xB0 /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  0xB0 /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  0xB0 /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  0xB0 /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  0xB0 /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  0xB0 /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  0xB0 /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  0xB0 /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  0xB0 /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  0xB0 /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  0xB0 /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  0xB0 /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  0xB0 /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  0xB0 /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  0xB0 /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  0xB0 /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  0xB0 /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  0xB0 /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  0xB0 /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  0xB0 /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  0xB0 /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  0xB0 /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  0xB0 /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  0xB0 /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  0xB0 /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  0xB0 /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  0xB0 /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  0xB0 /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  0xB0 /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  0xB0 /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  0xB0 /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  0xB0 /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  0xB0 /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  0xB0 /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  0xB0 /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  0xB0 /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  0xB0 /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  0xB0 /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  0xA0 /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  0xA0 /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  0xA0 /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  0xA0 /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  0xA0 /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
#else
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanTxHwObj[kCanNumberOfTxObjects] = 
{
  0xB0 /* ID: 0x0000058e, Handle: 0, AVM_NM [BC] */, 
  0xB0 /* ID: 0x000002ef, Handle: 1, Debug_CanStaInfo [BC] */, 
  0xB0 /* ID: 0x000002ee, Handle: 2, Debug_ReloatInfo [BC] */, 
  0xB0 /* ID: 0x000002ed, Handle: 3, TargetPointInfo [BC] */, 
  0xB0 /* ID: 0x000002ec, Handle: 4, TargetSlot_CD [BC] */, 
  0xB0 /* ID: 0x000002eb, Handle: 5, TargetSlot_AB [BC] */, 
  0xB0 /* ID: 0x000002ea, Handle: 6, USS_SLOT_R_CD [FC] */, 
  0xB0 /* ID: 0x000002e9, Handle: 7, USS_SLOT_R_AB [BC] */, 
  0xB0 /* ID: 0x000002e8, Handle: 8, USS_SLOT_L_CD [BC] */, 
  0xB0 /* ID: 0x000002e7, Handle: 9, USS_SLOT_L_AB [BC] */, 
  0xB0 /* ID: 0x000002e6, Handle: 10, USS_DE_S [BC] */, 
  0xB0 /* ID: 0x000002e5, Handle: 11, USS_DE_R [BC] */, 
  0xB0 /* ID: 0x000002e4, Handle: 12, USS_DE_F [BC] */, 
  0xB0 /* ID: 0x000002e3, Handle: 13, USS_DIAG_R [BC] */, 
  0xB0 /* ID: 0x000002e2, Handle: 14, USS_DIAG_F [BC] */, 
  0xB0 /* ID: 0x000002e1, Handle: 15, DR_2 [BC] */, 
  0xB0 /* ID: 0x000002e0, Handle: 16, DR_1 [BC] */, 
  0xB0 /* ID: 0x0000025d, Handle: 17, PDC_2 [BC] */, 
  0xB0 /* ID: 0x0000025c, Handle: 18, PDC_1 [FC] */, 
  0xB0 /* ID: 0x00000258, Handle: 19, AVS_1 [BC] */, 
  0xB0 /* ID: 0x000001cb, Handle: 20, PDC_14 [BC] */, 
  0xB0 /* ID: 0x000001ca, Handle: 21, PDC_13 [BC] */, 
  0xB0 /* ID: 0x000001c9, Handle: 22, PDC_12 [BC] */, 
  0xB0 /* ID: 0x000001c8, Handle: 23, PDC_11 [BC] */, 
  0xB0 /* ID: 0x000001c7, Handle: 24, PDC_10 [BC] */, 
  0xB0 /* ID: 0x000001c6, Handle: 25, PDC_9 [BC] */, 
  0xB0 /* ID: 0x000001c5, Handle: 26, PDC_8 [BC] */, 
  0xB0 /* ID: 0x000001c4, Handle: 27, PDC_7 [BC] */, 
  0xB0 /* ID: 0x000001c3, Handle: 28, PDC_6 [BC] */, 
  0xB0 /* ID: 0x000001c2, Handle: 29, PDC_5 [BC] */, 
  0xB0 /* ID: 0x000001c1, Handle: 30, PDC_4 [BC] */, 
  0xB0 /* ID: 0x000001c0, Handle: 31, PDC_3 [BC] */, 
  0xB0 /* ID: 0x0000018b, Handle: 32, APS_Slot6 [BC] */, 
  0xB0 /* ID: 0x0000018a, Handle: 33, APS_Slot5 [BC] */, 
  0xB0 /* ID: 0x00000189, Handle: 34, APS_Slot4 [BC] */, 
  0xB0 /* ID: 0x00000188, Handle: 35, APS_Slot3 [BC] */, 
  0xB0 /* ID: 0x00000187, Handle: 36, APS_Slot2 [BC] */, 
  0xB0 /* ID: 0x00000186, Handle: 37, APS_Slot1 [BC] */, 
  0xB0 /* ID: 0x00000184, Handle: 38, APS_PSD [BC] */, 
  0xB0 /* ID: 0x000007ff, Handle: 39, TxDynamicMsg0 [BC] */, 
  0xA0 /* ID: 0x000002d3, Handle: 40, APS_Replan_2 [BC] */, 
  0xA0 /* ID: 0x000002d2, Handle: 41, APS_Replan_1 [BC] */, 
  0xA0 /* ID: 0x000002d1, Handle: 42, RightCurbInfo [BC] */, 
  0xA0 /* ID: 0x000002d0, Handle: 43, LeftCurbInfo [BC] */, 
  0xA0 /* ID: 0x000002cc, Handle: 44, Freespace11_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002cb, Handle: 45, Freespace10_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002ca, Handle: 46, Freespace9_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c9, Handle: 47, Freespace8_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c8, Handle: 48, Freespace7_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c7, Handle: 49, Freespace6_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c6, Handle: 50, Freespace5_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c5, Handle: 51, Freespace4_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c4, Handle: 52, Freespace3_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c3, Handle: 53, Freespace2_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c2, Handle: 54, Freespace1_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000002c1, Handle: 55, Freespace0_ObstacleInfo [BC] */, 
  0xA0 /* ID: 0x000001a1, Handle: 56, APS_1 [BC] */
};
#endif

/* ROM CATEGORY 2 END */

#endif



/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanHwTxNormalIndex[kCanNumberOfChannels] = 
{
  176, 
  160
};

/* ROM CATEGORY 1 END */


/* ROM CATEGORY 1 START */

V_MEMROM0 V_MEMROM1 vsintx V_MEMROM2 CanTxOffsetHwToLog[kCanNumberOfChannels] = 
{
  -176, 
  -159
};

/* ROM CATEGORY 1 END */



/* -----------------------------------------------------------------------------
    &&&~ Hw specific
 ----------------------------------------------------------------------------- */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanLogToPhys[kCanNumberOfHwChannels] = 
{
  1u, 
  0u
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 CanObjectHandle V_MEMROM2 CanTxBufOffset[kCanNumberOfHwChannels] = 
{
  kCanTxBufOffset_1, 
  kCanTxBufOffset_0
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 tCanChannelData V_MEMROM2 CanChannelData[kCanNumberOfHwChannels] = 
{
  
  {
    CanRxFifoDepth_0 /* CanRxFifoDepth */, 
    CanFilterRulesBc_0 /* CanFilterRulesBc */, 
    0xFFFFB0E6u /* CanIntcChTxBaseAdr */, 
    0xFFFFB0E2u /* CanIntcChErrorBaseAdr */, 
    0xFFFFB04Cu /* CanIntcChWakeupBaseAdr */, 
    { 0xFFFFFFFFu, 0x000003FFu } /* CanRxFcMask */, 
    0x0001u /* CanTxIntMask */, 
    2u /* CanFilterRulesStartIndex */, 
    0x2Cu /* CanFilterRulesTotalCount */, 
    2u /* CanFilterRulesBcCount */, 
    0x02u /* CanRxBcMask */, 
    0x08u /* CanRxBcMsgProcessCount */, 
    1u /* CanRxBcStartIndex */, 
    2u /* CanRxBcStopIndex */, 
    3u /* CanIntPrio */
  }, 
  
  {
    CanRxFifoDepth_1 /* CanRxFifoDepth */, 
    CanFilterRulesBc_1 /* CanFilterRulesBc */, 
    0xFFFEEA34u /* CanIntcChTxBaseAdr */, 
    0xFFFEEA30u /* CanIntcChErrorBaseAdr */, 
    0xFFFFB04Au /* CanIntcChWakeupBaseAdr */, 
    { 0x00000000u, 0x00000000u } /* CanRxFcMask */, 
    0x0001u /* CanTxIntMask */, 
    0u /* CanFilterRulesStartIndex */, 
    0x02u /* CanFilterRulesTotalCount */, 
    2u /* CanFilterRulesBcCount */, 
    0x01u /* CanRxBcMask */, 
    0x08u /* CanRxBcMsgProcessCount */, 
    0u /* CanRxBcStartIndex */, 
    1u /* CanRxBcStopIndex */, 
    3u /* CanIntPrio */
  }
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 1 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanFifoToLogChannel[kVNumberOfIdentities][kCanNumberOfRxFifos] = 
{
  
  {
    1, 
    0
  }
};
/* ROM CATEGORY 1 END */

/* ROM CATEGORY 4 START */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_0[1] = 
{
  0x01u
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 CanRxFifoDepth_1[1] = 
{
  0x01u
};
/* ROM CATEGORY 4 END */





/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\can_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\can_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

