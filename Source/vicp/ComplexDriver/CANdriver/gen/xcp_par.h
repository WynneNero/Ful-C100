/* -----------------------------------------------------------------------------
  Filename:    xcp_par.h
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

#if !defined(__XCP_PAR_H__)
#define __XCP_PAR_H__

#include "v_inc.h"
/*  */
typedef unsigned char XcpCharType;
/*  */
/* Events */
V_MEMROM0 extern  V_MEMROM1 XcpCharType V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 kXcpEventName[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventNameLength[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventCycle[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventUnit[];
V_MEMROM0 extern  V_MEMROM1 vuint8 V_MEMROM2 kXcpEventDirection[];
#define XcpEventChannel_5msEvent_5           0u
#define XcpEventChannel_10msEvent_10         1u
#define XcpEventChannel_20msEvent_20         2u
#define XcpEventChannel_50msEvent_50         3u
/*  */
/* Online calibration */
/*  */
/* Flash programming */
/*  */
/* DAQ */
/*  */
/* Checksum */
/*  */
/* Transport Layer */
#define XcpGetCanTransmitHandle()            CanTxPAS_AVM_DevelopMessage_TX1
#define XcpGetCanTransmitDataPtr()           (PAS_AVM_DevelopMessage_TX1._c)
#define ApplXcpInterruptDisable()            CanInterruptDisable()
#define ApplXcpInterruptEnable()             CanInterruptRestore()
#define XcpTransmit()                        CanTransmit(XcpGetCanTransmitHandle())

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 359294492
      #error "The magic number of the generated file <D:\uidq0572\Desktop\AM8_APA\20200910\GAC_AM8_APA_MCU\Source\vicp\ComplexDriver\CANdriver\tool\gen979\xcp_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 359294492
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __XCP_PAR_H__ */
