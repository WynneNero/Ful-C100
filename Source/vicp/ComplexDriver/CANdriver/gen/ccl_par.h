/* -----------------------------------------------------------------------------
  Filename:    ccl_par.h
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Ccl__core
               
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
                       Databasefile: D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\AB02_979_C100_ADV_PrivateCAN_V0.1_20210629.dbc
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

#if !defined(__CCL_PAR_H__)
#define __CCL_PAR_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "v_cfg.h"
#include "v_def.h"
#include "can_inc.h"
#include "ccl_inc.h"

/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/
#ifndef NM_OK
  #define NM_OK 0
#endif

#if !defined ( DRV_API_CALLBACK_TYPE )
  #define DRV_API_CALLBACK_TYPE
#endif


#define CCL_DISABLE_WAKEUP_EV

#define CCL_DISABLE_SLEEP_COND

#define CCL_ENABLE_STOP_TIMEOUT
void CclNmPrepareSleepReqFct_0(void);
void CclNmPrepareSleepReqFct_1(void);
vuint8 CclNmActiveReqFct_0(vuint8 network);
vuint8 CclNmActiveReqFct_1(vuint8 network);
void CclNmSleepReqFct_0(vuint8 network);
void CclNmSleepReqFct_1(vuint8 network);
void CclInitTrcvFct_0(void);
void CclInitTrcvFct_1(void);
void CclWakeUpTrcvFct_0(void);
void CclWakeUpTrcvFct_1(void);
void CclSleepTrcvFct_0(void);
void CclSleepTrcvFct_1(void);
vuint8 CclGetTrcvErrorPortFct_0(void);
vuint8 CclGetTrcvErrorPortFct_1(void);
void CclInitFct_0(void);
void CclInitFct_1(void);
void CclSystemShutdownFct_0(void);
void CclSystemShutdownFct_1(void);
typedef void (*tCclNmSleepReqFctTbl) (vuint8 network);
typedef vuint8 (*tCclNmActiveReqFctTbl) (vuint8 network);
typedef void (*tCclNmPrepareSleepReqFctTbl) (void);
typedef void (*tCclInitTrcvFctTbl) (void);
typedef void (*tCclWakeUpTrcvFctTbl) (void);
typedef void (*tCclSleepTrcvFctTbl) (void);
typedef vuint8 (*tCclGetTrcvErrorPortFctTbl) (void);
typedef void (*tCclExtCanComReqFctTbl) (void);
typedef void (*tCclIntComReqFctTbl) (void);
typedef void (*tCclComRelFctTbl) (void);
typedef void (*tCclInitFctTbl) (void);
typedef void (*tCclSystemShutdownFctTbl) (void);
V_MEMROM0 extern V_MEMROM1 tCclNmSleepReqFctTbl V_MEMROM2 CclNmSleepReqFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclNmActiveReqFctTbl V_MEMROM2 CclNmActiveReqFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclNmPrepareSleepReqFctTbl V_MEMROM2 CclNmPrepareSleepReqFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclInitTrcvFctTbl V_MEMROM2 CclInitTrcvFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclWakeUpTrcvFctTbl V_MEMROM2 CclWakeUpTrcvFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclSleepTrcvFctTbl V_MEMROM2 CclSleepTrcvFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclGetTrcvErrorPortFctTbl V_MEMROM2 CclGetTrcvErrorPortFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclInitFctTbl V_MEMROM2 CclInitFctTbl[2];
V_MEMROM0 extern V_MEMROM1 tCclSystemShutdownFctTbl V_MEMROM2 CclSystemShutdownFctTbl[2];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclNmWakeUpAble;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclChannelWithoutNm;
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclStartIndex[2];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclStopIndex[2];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclUserOffset[kCclNumberOfUser];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclUserMask[kCclNumberOfUser];
V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 cclUserChannel[kCclNumberOfUser];
/*** prototypes ***/
extern void CclInitPowerOnFct(void);
extern void CCL_API_CALLBACK_TYPE ApplCclNmCanNormal( CanChannelHandle channel );
extern void CCL_API_CALLBACK_TYPE ApplCclNmCanPrepareSleep( CanChannelHandle channel );
extern void CCL_API_CALLBACK_TYPE ApplCclNmCanSleep( CanChannelHandle channel );
extern void DRV_API_CALLBACK_TYPE CanTask(void);


/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\ccl_par.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 390049630
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CCL_PAR_H__ */
