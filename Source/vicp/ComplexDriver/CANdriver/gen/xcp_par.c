/* -----------------------------------------------------------------------------
  Filename:    xcp_par.c
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Xcp
               
               Configuration   : D:\uidq0572\Desktop\AM8_APA\20200910\GAC_AM8_APA_MCU\Source\vicp\ComplexDriver\CANdriver\tool\CBD1700979_AM8_SA_ ChassisCAN0_BodyCAN1_20191119.gny
               
               ECU: 
                       TargetSystem: Hw_Rh850Cpu
                       Compiler:     GreenHills
                       Derivates:    F1K
               
               Channel "Channel1":
                       Databasefile: D:\uidq0572\Desktop\AM8_APA\20200910\GAC_AM8_APA_MCU\Source\vicp\ComplexDriver\CANdriver\tool\AM8project_PT0_FAPA_CMX_V1.0ACAN_20200910.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         FAPA
               Channel "Channel0":
                       Databasefile: D:\uidq0572\Desktop\AM8_APA\20200309\GAC_AM8_APA_MCU\Source\vicp\ComplexDriver\CANdriver\tool\AM8project_PT0_FAPA_CMX_V1.0BCAN_20200305.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         FAPA

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

#if !defined(__XCP_PAR_C__)
#define __XCP_PAR_C__

#include "v_inc.h"
#include "XcpProf.h"
#include "drv_par.h"

/* Events */
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 kXcpEventName_0[] = "5msEvent";
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 kXcpEventName_1[] = "10msEvent";
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 kXcpEventName_2[] = "20msEvent";
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 kXcpEventName_3[] = "50msEvent";
V_MEMROM0 V_MEMROM1 XcpCharType V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[] = 
{
  &kXcpEventName_0[0], 
  &kXcpEventName_1[0], 
  &kXcpEventName_2[0], 
  &kXcpEventName_3[0]
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[] = 
{
  (vuint8) 8, 
  (vuint8) 9, 
  (vuint8) 9, 
  (vuint8) 9
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[] = 
{
  (vuint8) 5, 
  (vuint8) 10, 
  (vuint8) 20, 
  (vuint8) 50
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[] = 
{
  (vuint8) DAQ_TIMESTAMP_UNIT_1MS, 
  (vuint8) DAQ_TIMESTAMP_UNIT_1MS, 
  (vuint8) DAQ_TIMESTAMP_UNIT_1MS, 
  (vuint8) DAQ_TIMESTAMP_UNIT_1MS
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[] = 
{
  (vuint8) DAQ_EVENT_DIRECTION_DAQ, 
  (vuint8) DAQ_EVENT_DIRECTION_DAQ, 
  (vuint8) DAQ_EVENT_DIRECTION_DAQ, 
  (vuint8) DAQ_EVENT_DIRECTION_DAQ
};
/* Online calibration */
/* Flash programming */
/* Transport Layer */
/*  */

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 359294492
      #error "The magic number of the generated file <D:\uidq0572\Desktop\AM8_APA\20200910\GAC_AM8_APA_MCU\Source\vicp\ComplexDriver\CANdriver\tool\gen979\xcp_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 359294492
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_PAR_C__ */
