/* -----------------------------------------------------------------------------
  Filename:    drv_par.c
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
                       Node:         AVMwithUSS

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

#include "v_inc.h"
#include "can_inc.h"

#include "drv_par.h"
/* -----------------------------------------------------------------------------
    &&&~ Message Buffers
 ----------------------------------------------------------------------------- */

/* RAM CATEGORY 2 START */
/* PRQA  S 0759 QAC_Can_0759 */ /* MD_Can_0759 */
V_MEMRAM0 V_MEMRAM1 _c_ABS_1_buf V_MEMRAM2 ABS_1;
V_MEMRAM0 V_MEMRAM1 _c_TxDynamicMsg0_buf V_MEMRAM2 TxDynamicMsg0;
V_MEMRAM0 V_MEMRAM1 _c_HU_5_buf V_MEMRAM2 HU_5;
V_MEMRAM0 V_MEMRAM1 _c_TCU_3_buf V_MEMRAM2 TCU_3;
V_MEMRAM0 V_MEMRAM1 _c_SAS_1_buf V_MEMRAM2 SAS_1;
V_MEMRAM0 V_MEMRAM1 _c_PDC_1_buf V_MEMRAM2 PDC_1;
V_MEMRAM0 V_MEMRAM1 _c_EMS_3_buf V_MEMRAM2 EMS_3;
V_MEMRAM0 V_MEMRAM1 _c_HU_Speech_1_buf V_MEMRAM2 HU_Speech_1;
V_MEMRAM0 V_MEMRAM1 _c_ABS_2_buf V_MEMRAM2 ABS_2;
V_MEMRAM0 V_MEMRAM1 _c_BCM1_2_buf V_MEMRAM2 BCM1_2;
V_MEMRAM0 V_MEMRAM1 _c_AVM_NM_buf V_MEMRAM2 AVM_NM;
V_MEMRAM0 V_MEMRAM1 _c_ADV_1_buf V_MEMRAM2 ADV_1;
V_MEMRAM0 V_MEMRAM1 _c_PDC_2_buf V_MEMRAM2 PDC_2;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot6_buf V_MEMRAM2 APS_Slot6;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot5_buf V_MEMRAM2 APS_Slot5;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot4_buf V_MEMRAM2 APS_Slot4;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot3_buf V_MEMRAM2 APS_Slot3;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot2_buf V_MEMRAM2 APS_Slot2;
V_MEMRAM0 V_MEMRAM1 _c_APS_Slot1_buf V_MEMRAM2 APS_Slot1;
V_MEMRAM0 V_MEMRAM1 _c_APS_PSD_buf V_MEMRAM2 APS_PSD;
V_MEMRAM0 V_MEMRAM1 _c_PLG_1_buf V_MEMRAM2 PLG_1;
V_MEMRAM0 V_MEMRAM1 _c_PDCU_1_buf V_MEMRAM2 PDCU_1;
V_MEMRAM0 V_MEMRAM1 _c_IC_1_buf V_MEMRAM2 IC_1;
V_MEMRAM0 V_MEMRAM1 _c_ESC_3_buf V_MEMRAM2 ESC_3;
V_MEMRAM0 V_MEMRAM1 _c_ESC_2_buf V_MEMRAM2 ESC_2;
V_MEMRAM0 V_MEMRAM1 _c_DDCU_1_buf V_MEMRAM2 DDCU_1;
V_MEMRAM0 V_MEMRAM1 _c_BCM1_1_buf V_MEMRAM2 BCM1_1;
V_MEMRAM0 V_MEMRAM1 _c_ATC_2_buf V_MEMRAM2 ATC_2;
V_MEMRAM0 V_MEMRAM1 _c_HU_6_buf V_MEMRAM2 HU_6;
V_MEMRAM0 V_MEMRAM1 _c_GPS_1_buf V_MEMRAM2 GPS_1;
V_MEMRAM0 V_MEMRAM1 _c_ABS_3_buf V_MEMRAM2 ABS_3;
V_MEMRAM0 V_MEMRAM1 _c_AVS_1_buf V_MEMRAM2 AVS_1;
V_MEMRAM0 V_MEMRAM1 _c_Debug_ReloatInfo_buf V_MEMRAM2 Debug_ReloatInfo;
V_MEMRAM0 V_MEMRAM1 _c_Debug_CanStaInfo_buf V_MEMRAM2 Debug_CanStaInfo;
V_MEMRAM0 V_MEMRAM1 _c_ADV_TargetTracing_buf V_MEMRAM2 ADV_TargetTracing;
V_MEMRAM0 V_MEMRAM1 _c_ADV_PathTracing_buf V_MEMRAM2 ADV_PathTracing;
V_MEMRAM0 V_MEMRAM1 _c_ADV_4_buf V_MEMRAM2 ADV_4;
V_MEMRAM0 V_MEMRAM1 _c_TBOX_1_buf V_MEMRAM2 TBOX_1;
V_MEMRAM0 V_MEMRAM1 _c_RRDCU_1_buf V_MEMRAM2 RRDCU_1;
V_MEMRAM0 V_MEMRAM1 _c_RLDCU_1_buf V_MEMRAM2 RLDCU_1;
V_MEMRAM0 V_MEMRAM1 _c_MCP_1_buf V_MEMRAM2 MCP_1;
V_MEMRAM0 V_MEMRAM1 _c_HU_18_buf V_MEMRAM2 HU_18;
V_MEMRAM0 V_MEMRAM1 _c_HU_14_buf V_MEMRAM2 HU_14;
V_MEMRAM0 V_MEMRAM1 _c_HU_10_buf V_MEMRAM2 HU_10;
V_MEMRAM0 V_MEMRAM1 _c_GW_Config_buf V_MEMRAM2 GW_Config;
V_MEMRAM0 V_MEMRAM1 _c_DMS_2_buf V_MEMRAM2 DMS_2;
V_MEMRAM0 V_MEMRAM1 _c_BCM1_7_buf V_MEMRAM2 BCM1_7;
V_MEMRAM0 V_MEMRAM1 _c_BCM1_3_buf V_MEMRAM2 BCM1_3;
V_MEMRAM0 V_MEMRAM1 _c_PDC_9_buf V_MEMRAM2 PDC_9;
V_MEMRAM0 V_MEMRAM1 _c_PDC_8_buf V_MEMRAM2 PDC_8;
V_MEMRAM0 V_MEMRAM1 _c_PDC_7_buf V_MEMRAM2 PDC_7;
V_MEMRAM0 V_MEMRAM1 _c_PDC_6_buf V_MEMRAM2 PDC_6;
V_MEMRAM0 V_MEMRAM1 _c_PDC_5_buf V_MEMRAM2 PDC_5;
V_MEMRAM0 V_MEMRAM1 _c_PDC_4_buf V_MEMRAM2 PDC_4;
V_MEMRAM0 V_MEMRAM1 _c_PDC_3_buf V_MEMRAM2 PDC_3;
V_MEMRAM0 V_MEMRAM1 _c_PDC_14_buf V_MEMRAM2 PDC_14;
V_MEMRAM0 V_MEMRAM1 _c_PDC_13_buf V_MEMRAM2 PDC_13;
V_MEMRAM0 V_MEMRAM1 _c_PDC_12_buf V_MEMRAM2 PDC_12;
V_MEMRAM0 V_MEMRAM1 _c_PDC_11_buf V_MEMRAM2 PDC_11;
V_MEMRAM0 V_MEMRAM1 _c_PDC_10_buf V_MEMRAM2 PDC_10;
V_MEMRAM0 V_MEMRAM1 _c_HU_20_buf V_MEMRAM2 HU_20;
V_MEMRAM0 V_MEMRAM1 _c_TargetSlot_AB_buf V_MEMRAM2 TargetSlot_AB;
V_MEMRAM0 V_MEMRAM1 _c_TargetPointInfo_buf V_MEMRAM2 TargetPointInfo;
V_MEMRAM0 V_MEMRAM1 _c_TargetSlot_CD_buf V_MEMRAM2 TargetSlot_CD;
V_MEMRAM0 V_MEMRAM1 _c_DR_2_buf V_MEMRAM2 DR_2;
V_MEMRAM0 V_MEMRAM1 _c_DR_1_buf V_MEMRAM2 DR_1;
V_MEMRAM0 V_MEMRAM1 _c_USS_SLOT_R_CD_buf V_MEMRAM2 USS_SLOT_R_CD;
V_MEMRAM0 V_MEMRAM1 _c_USS_SLOT_R_AB_buf V_MEMRAM2 USS_SLOT_R_AB;
V_MEMRAM0 V_MEMRAM1 _c_USS_SLOT_L_CD_buf V_MEMRAM2 USS_SLOT_L_CD;
V_MEMRAM0 V_MEMRAM1 _c_USS_SLOT_L_AB_buf V_MEMRAM2 USS_SLOT_L_AB;
V_MEMRAM0 V_MEMRAM1 _c_USS_DIAG_R_buf V_MEMRAM2 USS_DIAG_R;
V_MEMRAM0 V_MEMRAM1 _c_USS_DIAG_F_buf V_MEMRAM2 USS_DIAG_F;
V_MEMRAM0 V_MEMRAM1 _c_USS_DE_S_buf V_MEMRAM2 USS_DE_S;
V_MEMRAM0 V_MEMRAM1 _c_USS_DE_R_buf V_MEMRAM2 USS_DE_R;
V_MEMRAM0 V_MEMRAM1 _c_USS_DE_F_buf V_MEMRAM2 USS_DE_F;
V_MEMRAM0 V_MEMRAM1 _c_alpha_distance_R_buf V_MEMRAM2 alpha_distance_R;
V_MEMRAM0 V_MEMRAM1 _c_alpha_distance_Long_buf V_MEMRAM2 alpha_distance_Long;
V_MEMRAM0 V_MEMRAM1 _c_alpha_distance_F_buf V_MEMRAM2 alpha_distance_F;
V_MEMRAM0 V_MEMRAM1 _c_ADV_P1_buf V_MEMRAM2 ADV_P1;
V_MEMRAM0 V_MEMRAM1 _c_APS_1_buf V_MEMRAM2 APS_1;
V_MEMRAM0 V_MEMRAM1 _c_RightCurbInfo_buf V_MEMRAM2 RightCurbInfo;
V_MEMRAM0 V_MEMRAM1 _c_LeftCurbInfo_buf V_MEMRAM2 LeftCurbInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace9_ObstacleInfo_buf V_MEMRAM2 Freespace9_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace8_ObstacleInfo_buf V_MEMRAM2 Freespace8_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace7_ObstacleInfo_buf V_MEMRAM2 Freespace7_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace6_ObstacleInfo_buf V_MEMRAM2 Freespace6_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace5_ObstacleInfo_buf V_MEMRAM2 Freespace5_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace4_ObstacleInfo_buf V_MEMRAM2 Freespace4_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace3_ObstacleInfo_buf V_MEMRAM2 Freespace3_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace2_ObstacleInfo_buf V_MEMRAM2 Freespace2_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace1_ObstacleInfo_buf V_MEMRAM2 Freespace1_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace11_ObstacleInfo_buf V_MEMRAM2 Freespace11_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace10_ObstacleInfo_buf V_MEMRAM2 Freespace10_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_Freespace0_ObstacleInfo_buf V_MEMRAM2 Freespace0_ObstacleInfo;
V_MEMRAM0 V_MEMRAM1 _c_APS_Replan_2_buf V_MEMRAM2 APS_Replan_2;
V_MEMRAM0 V_MEMRAM1 _c_APS_Replan_1_buf V_MEMRAM2 APS_Replan_1;
/* PRQA  L:QAC_Can_0759 */

/* RAM CATEGORY 2 END */





/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\drv_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\drv_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

