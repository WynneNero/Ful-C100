/* -----------------------------------------------------------------------------
  Filename:    il_par.c
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

/* -----------------------------------------------------------------------------
    &&&~ Misra  justifications
 ----------------------------------------------------------------------------- */

/* PRQA S 3458 EOF *//* MD_CBD_19.4 */
/* PRQA S 3408 EOF *//* MD_Il_8.8 */
/* PRQA S 3460 EOF *//* MD_CBD_19.4 */
/* PRQA S 3412 EOF *//* MD_CBD_19.4 */
/* PRQA S 3453 EOF *//* MD_CBD_19.7 */
/* PRQA S 2006 EOF *//* MD_CBD_14.7 */
/* PRQA S 0777 EOF *//* MD_Il_0777 */
/* PRQA S 0778 EOF *//* MD_Il_0778 */
/* PRQA S 0779 EOF *//* MD_Il_0779 */
/* PRQA S 3673 EOF *//* MD_Il_3673 */
/* PRQA S 0310 EOF *//* MD_Il_0310 */
/* PRQA S 0312 EOF *//* MD_Il_0312 */
/* PRQA S 0635 EOF *//* MD_Il_0635 */
/* PRQA S 0781 EOF *//* MD_Il_0781 */
/* PRQA S 3410 EOF *//* MD_Il_3410 */
/* PRQA S 1330 EOF *//* MD_Il_1330 */
/* PRQA S 0342 EOF *//* MD_Il_0342 */
/* PRQA S 0857 EOF *//* MD_CBD_1.1 */
/* PRQA S 3109 EOF *//* MD_CBD_14.3 */
/* PRQA S 0883 EOF *//* */


#include "il_inc.h"

/* -----------------------------------------------------------------------------
    &&&~ local variables
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_CYCLIC_EVENT)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Local function prototypes
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ IL internal rx message timeout indication functions
 ----------------------------------------------------------------------------- */

static void IlMsgSAS_1TimeoutIndication(void);
static void IlMsgTCU_3TimeoutIndication(void);




/* -----------------------------------------------------------------------------
    &&&~ Internal Get Tx Signal Access for signals smaller or equal 8bit
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                  PrivateCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxPrivateCanSta()        (Debug_CanStaInfo.Debug_CanStaInfo.PrivateCanSta)
#endif

/* Handle:    1,Name:                   PubuicCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxPubuicCanSta()         (Debug_CanStaInfo.Debug_CanStaInfo.PubuicCanSta)
#endif

/* Handle:   60,Name:                  USS_WORK_MODE,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxUSS_WORK_MODE()        (USS_DIAG_F.USS_DIAG_F.USS_WORK_MODE)
#endif

/* Handle:   88,Name:                      SysSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSysSt_PDC()            (PDC_1.PDC_1.SysSt_PDC)
#endif

/* Handle:   89,Name:                    ErrorSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxErrorSt_PDC()          (PDC_1.PDC_1.ErrorSt_PDC)
#endif

/* Handle:   90,Name:               RadarSysSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxRadarSysSt_Front()     (PDC_1.PDC_1.RadarSysSt_Front)
#endif

/* Handle:   91,Name:                RadarSysSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxRadarSysSt_Rear()      (PDC_1.PDC_1.RadarSysSt_Rear)
#endif

/* Handle:   92,Name:                  BuzeerCmd_PDC,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxBuzeerCmd_PDC()        (PDC_1.PDC_1.BuzeerCmd_PDC)
#endif

/* Handle:   97,Name:                 ObjectRange_RR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_RR()       (PDC_1.PDC_1.ObjectRange_RR)
#endif

/* Handle:   98,Name:               SensorErrorSt_RR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_RR()     (PDC_1.PDC_1.SensorErrorSt_RR)
#endif

/* Handle:   99,Name:                ObjectRange_RMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_RMR()      (PDC_1.PDC_1.ObjectRange_RMR)
#endif

/* Handle:  100,Name:              SensorErrorSt_RMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_RMR()    (PDC_1.PDC_1.SensorErrorSt_RMR)
#endif

/* Handle:  101,Name:                ObjectRange_RML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_RML()      (PDC_1.PDC_1.ObjectRange_RML)
#endif

/* Handle:  102,Name:              SensorErrorSt_RML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_RML()    (PDC_1.PDC_1.SensorErrorSt_RML)
#endif

/* Handle:  103,Name:                 ObjectRange_RL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_RL()       (PDC_1.PDC_1.ObjectRange_RL)
#endif

/* Handle:  104,Name:               SensorErrorSt_RL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_RL()     (PDC_1.PDC_1.SensorErrorSt_RL)
#endif

/* Handle:  105,Name:                 ObjectRange_FR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_FR()       (PDC_1.PDC_1.ObjectRange_FR)
#endif

/* Handle:  106,Name:               SensorErrorSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_FR()     (PDC_1.PDC_1.SensorErrorSt_FR)
#endif

/* Handle:  107,Name:                ObjectRange_FMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_FMR()      (PDC_1.PDC_1.ObjectRange_FMR)
#endif

/* Handle:  108,Name:              SensorErrorSt_FMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_FMR()    (PDC_1.PDC_1.SensorErrorSt_FMR)
#endif

/* Handle:  109,Name:                ObjectRange_FML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_FML()      (PDC_1.PDC_1.ObjectRange_FML)
#endif

/* Handle:  110,Name:              SensorErrorSt_FML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_FML()    (PDC_1.PDC_1.SensorErrorSt_FML)
#endif

/* Handle:  111,Name:                 ObjectRange_FL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxObjectRange_FL()       (PDC_1.PDC_1.ObjectRange_FL)
#endif

/* Handle:  112,Name:               SensorErrorSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSensorErrorSt_FL()     (PDC_1.PDC_1.SensorErrorSt_FL)
#endif

/* Handle:  118,Name:                          AVSSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSSt()                (AVS_1.AVS_1.AVSSt)
#endif

/* Handle:  119,Name:                     AVSErrorSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSErrorSt()           (AVS_1.AVS_1.AVSErrorSt)
#endif

/* Handle:  120,Name:                    AVSViewMode,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSViewMode()          (AVS_1.AVS_1.AVSViewMode)
#endif

/* Handle:  122,Name:         AVSCameraErrorSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSCameraErrorSt_Front() (AVS_1.AVS_1.AVSCameraErrorSt_Front)
#endif

/* Handle:  123,Name:          AVSCameraErrorSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSCameraErrorSt_Rear() (AVS_1.AVS_1.AVSCameraErrorSt_Rear)
#endif

/* Handle:  124,Name:          AVSCameraErrorSt_Left,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSCameraErrorSt_Left() (AVS_1.AVS_1.AVSCameraErrorSt_Left)
#endif

/* Handle:  125,Name:         AVSCameraErrorSt_Right,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxAVSCameraErrorSt_Right() (AVS_1.AVS_1.AVSCameraErrorSt_Right)
#endif

/* Handle:  126,Name:             LanguageTypeSt_AVS,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxLanguageTypeSt_AVS()   (AVS_1.AVS_1.LanguageTypeSt_AVS)
#endif

/* Handle:  127,Name:               DynamicPGSSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxDynamicPGSSt_AVS()     (AVS_1.AVS_1.DynamicPGSSt_AVS)
#endif

/* Handle:  128,Name:                      MODSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxMODSt_AVS()            (AVS_1.AVS_1.MODSt_AVS)
#endif

/* Handle:  129,Name:               MODWarning_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxMODWarning_Front()     (AVS_1.AVS_1.MODWarning_Front)
#endif

/* Handle:  130,Name:                MODWarning_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxMODWarning_Rear()      (AVS_1.AVS_1.MODWarning_Rear)
#endif

/* Handle:  132,Name:        SwitchScreenRequest_AVS,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxSwitchScreenRequest_AVS() (AVS_1.AVS_1.SwitchScreenRequest_AVS)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Internal Get Tx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:   20,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Cx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Cx();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Cx();
  return rc;
}


#endif

/* Handle:   21,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Cy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Cy();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Cy();
  return rc;
}


#endif

/* Handle:   22,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Dx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Dx();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Dx();
  return rc;
}


#endif

/* Handle:   23,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Dy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Dy();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Dy();
  return rc;
}


#endif

/* Handle:   24,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Ax(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Ax();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Ax();
  return rc;
}


#endif

/* Handle:   25,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Ay(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Ay();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Ay();
  return rc;
}


#endif

/* Handle:   26,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_Bx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Bx();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Bx();
  return rc;
}


#endif

/* Handle:   27,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_By(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_By();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_By();
  return rc;
}


#endif

/* Handle:   28,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Cx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Cx();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Cx();
  return rc;
}


#endif

/* Handle:   29,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Cy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Cy();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Cy();
  return rc;
}


#endif

/* Handle:   30,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Dx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Dx();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Dx();
  return rc;
}


#endif

/* Handle:   31,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Dy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Dy();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Dy();
  return rc;
}


#endif

/* Handle:   32,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Ax(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Ax();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Ax();
  return rc;
}


#endif

/* Handle:   33,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_AY(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_AY();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_AY();
  return rc;
}


#endif

/* Handle:   34,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_Bx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Bx();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Bx();
  return rc;
}


#endif

/* Handle:   35,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_By(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_By();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_By();
  return rc;
}


#endif

/* Handle:   36,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FLS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FLS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FLS_1) << 8;
  IlLeaveCriticalUSS_DE_FLS();
  return rc;
}


#endif

/* Handle:   37,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FRS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FRS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FRS_1) << 8;
  IlLeaveCriticalUSS_DE_FRS();
  return rc;
}


#endif

/* Handle:   38,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RLS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RLS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RLS_1) << 8;
  IlLeaveCriticalUSS_DE_RLS();
  return rc;
}


#endif

/* Handle:   39,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RRS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RRS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RRS_1) << 8;
  IlLeaveCriticalUSS_DE_RRS();
  return rc;
}


#endif

/* Handle:   40,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RL();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RL_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RL_1) << 8;
  IlLeaveCriticalUSS_DE_RL();
  return rc;
}


#endif

/* Handle:   41,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RML();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_1) << 3;
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_2) << 11;
  IlLeaveCriticalUSS_DE_RML();
  return rc;
}


#endif

/* Handle:   42,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RMR();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RMR_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RMR_1) << 6;
  IlLeaveCriticalUSS_DE_RMR();
  return rc;
}


#endif

/* Handle:   43,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_RR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RR();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_1) << 1;
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_2) << 9;
  IlLeaveCriticalUSS_DE_RR();
  return rc;
}


#endif

/* Handle:   44,Name:                      USS_DE_FL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FL();
  rc = ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FL_0);
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FL_1) << 8;
  IlLeaveCriticalUSS_DE_FL();
  return rc;
}


#endif

/* Handle:   45,Name:                     USS_DE_FML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FML();
  rc = ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FML_0);
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FML_1) << 3;
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FML_2) << 11;
  IlLeaveCriticalUSS_DE_FML();
  return rc;
}


#endif

/* Handle:   46,Name:                     USS_DE_FMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FMR();
  rc = ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FMR_0);
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FMR_1) << 6;
  IlLeaveCriticalUSS_DE_FMR();
  return rc;
}


#endif

/* Handle:   47,Name:                      USS_DE_FR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DE_FR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FR();
  rc = ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FR_0);
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FR_1) << 1;
  rc |= ((vuint16) USS_DE_F.USS_DE_F.USS_DE_FR_2) << 9;
  IlLeaveCriticalUSS_DE_FR();
  return rc;
}


#endif

/* Handle:   48,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RL();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_1) << 8;
  IlLeaveCriticalUSS_DIAG_RL();
  return rc;
}


#endif

/* Handle:   49,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RLS();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_1) << 6;
  IlLeaveCriticalUSS_DIAG_RLS();
  return rc;
}


#endif

/* Handle:   50,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RML();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_1) << 4;
  IlLeaveCriticalUSS_DIAG_RML();
  return rc;
}


#endif

/* Handle:   51,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RMR();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_1) << 2;
  IlLeaveCriticalUSS_DIAG_RMR();
  return rc;
}


#endif

/* Handle:   52,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RR();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_1) << 8;
  IlLeaveCriticalUSS_DIAG_RR();
  return rc;
}


#endif

/* Handle:   53,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_RRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RRS();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_1) << 6;
  IlLeaveCriticalUSS_DIAG_RRS();
  return rc;
}


#endif

/* Handle:   54,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FL();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_1) << 8;
  IlLeaveCriticalUSS_DIAG_FL();
  return rc;
}


#endif

/* Handle:   55,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FLS();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_1) << 6;
  IlLeaveCriticalUSS_DIAG_FLS();
  return rc;
}


#endif

/* Handle:   56,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FML();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_1) << 4;
  IlLeaveCriticalUSS_DIAG_FML();
  return rc;
}


#endif

/* Handle:   57,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FMR();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_1) << 2;
  IlLeaveCriticalUSS_DIAG_FMR();
  return rc;
}


#endif

/* Handle:   58,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FR();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_1) << 8;
  IlLeaveCriticalUSS_DIAG_FR();
  return rc;
}


#endif

/* Handle:   59,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_DIAG_FRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FRS();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_1) << 6;
  IlLeaveCriticalUSS_DIAG_FRS();
  return rc;
}


#endif

/* Handle:   62,Name:               USS_SLOT_L_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_L_DEPTH(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_DEPTH();
  rc = ((vuint16) DR_2.DR_2.USS_SLOT_L_DEPTH_0);
  rc |= ((vuint16) DR_2.DR_2.USS_SLOT_L_DEPTH_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_DEPTH();
  return rc;
}


#endif

/* Handle:   63,Name:               USS_SLOT_R_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
vuint16 IlPrivateGetTxUSS_SLOT_R_DEPTH(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_DEPTH();
  rc = ((vuint16) DR_2.DR_2.USS_SLOT_R_DEPTH_0);
  rc |= ((vuint16) DR_2.DR_2.USS_SLOT_R_DEPTH_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_DEPTH();
  return rc;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Internal Timer Handles
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
#define IlParHndRxSAS_1                      0
#define IlParHndRxTCU_3                      1
#endif



#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 IlTxTimeoutIndirection[kIlNumberOfTxObjects] = 
{
  kIlNoTxToutIndirection /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kIlNoTxToutIndirection /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_FAST_ON_START)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxFastOnStartDuration[kIlNumberOfTxObjects] = 
{
  kIlNoFastOnStartDuration /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_FAST_ON_START) && defined(IL_ENABLE_TX_MODE_SIGNALS)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxFastOnStartMuxDelay[kIlNumberOfTxObjects] = 
{
  0 /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  0 /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  0 /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  0 /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  0 /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  0 /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  0 /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  0 /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  0 /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  0 /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  0 /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  0 /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  0 /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  0 /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  0 /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  0 /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  0 /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  0 /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  0 /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  0 /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  0 /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  0 /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  0 /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  0 /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  0 /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  0 /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  0 /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  0 /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  0 /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  0 /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  0 /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  0 /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  0 /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  0 /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  0 /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  0 /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  0 /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  0 /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  0 /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  0 /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  0 /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  0 /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  0 /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  0 /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxStartCycles[kIlNumberOfTxObjects] = 
{
  kIlNoCycleTime /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kIlNoCycleTime /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kIlNoCycleTime /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kIlNoCycleTime /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kIlNoCycleTime /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kIlNoCycleTime /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kIlNoCycleTime /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kIlNoCycleTime /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kIlNoCycleTime /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxUpdateCounter V_MEMROM2 IlTxUpdateCycles[kIlNumberOfTxObjects] = 
{
  kIlNoDelayTime /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoDelayTime /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoDelayTime /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoDelayTime /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kIlNoDelayTime /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kIlNoDelayTime /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kIlNoDelayTime /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kIlNoDelayTime /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kIlNoDelayTime /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kIlNoDelayTime /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kIlNoDelayTime /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kIlNoDelayTime /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kIlNoDelayTime /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kIlNoDelayTime /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxCyclicCycles[kIlNumberOfTxObjects] = 
{
  kIlNoCycleTime /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoCycleTime /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  10 /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  10 /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  10 /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  5 /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  5 /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  5 /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  5 /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  5 /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  5 /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  5 /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  5 /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  5 /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  5 /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  5 /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  5 /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  10 /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  10 /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  10 /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  10 /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  10 /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  10 /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  10 /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  10 /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  10 /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  20 /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  20 /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  20 /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  20 /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  10 /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX) && (defined(IL_ENABLE_TX_CYCLIC_EVENT) || defined(IL_ENABLE_TX_SECURE_EVENT) || defined(IL_ENABLE_TX_FAST_ON_START))
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxEventCycles[kIlNumberOfTxObjects] = 
{
  kIlNoCycleTimeFast /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kIlNoCycleTimeFast /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_POLLING)
V_MEMROM0 V_MEMROM1 IlConfirmationFct V_MEMROM2 IlTxConfirmationFctPtr[kIlNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  V_NULL /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  V_NULL /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  V_NULL /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  V_NULL /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  V_NULL /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  V_NULL /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  V_NULL /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  V_NULL /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  V_NULL /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  V_NULL /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  V_NULL /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  V_NULL /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  V_NULL /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  V_NULL /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  V_NULL /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  V_NULL /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  V_NULL /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  V_NULL /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  V_NULL /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  V_NULL /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  V_NULL /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  V_NULL /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  V_NULL /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  V_NULL /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  V_NULL /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  V_NULL /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  V_NULL /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  V_NULL /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  V_NULL /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  V_NULL /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  V_NULL /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  V_NULL /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  V_NULL /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  V_NULL /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  V_NULL /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  V_NULL /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  V_NULL /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  V_NULL /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  V_NULL /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  V_NULL /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  V_NULL /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  V_NULL /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT) && defined(C_MULTIPLE_RECEIVE_CHANNEL) && defined(IL_ENABLE_TX_VARYING_TIMEOUT) && (kIlNumberOfChannels > 1)
V_MEMROM0 V_MEMROM1 IltTxTimeoutCounter V_MEMROM2 IlTxTimeout[kIlNumberOfChannels] = 
{
  0, 
  0
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_SECURE_EVENT) && defined(IL_ENABLE_TX_VARYING_REPETITION) && (kIlNumberOfTxObjects > 1)
V_MEMROM0 V_MEMROM1 IltTxRepetitionCounter V_MEMROM2 IlTxRepetitionCounters[kIlNumberOfTxObjects] = 
{
  0 /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  0 /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  0 /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  0 /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  0 /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  0 /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  0 /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  0 /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  0 /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  0 /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  0 /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  0 /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  0 /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  0 /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  0 /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  0 /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  0 /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  0 /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  0 /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  0 /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  0 /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  0 /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  0 /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  0 /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  0 /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  0 /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  0 /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  0 /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  0 /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  0 /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  0 /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  0 /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  0 /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  0 /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  0 /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  0 /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  0 /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  0 /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  0 /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  0 /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  0 /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  0 /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  0 /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  0 /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  0 /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ Rx Timeout Table
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
V_MEMROM0 V_MEMROM1 IltRxTimeoutCounter V_MEMROM2 IlRxTimeoutTbl[kIlNumberOfRxTimeoutCounters] = 
{
  50 /* ID: 0x000000d0, SAS_1 [FC] */, 
  100 /* ID: 0x000000b4, TCU_3 [FC] */
};
#endif




#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
V_MEMROM0 V_MEMROM1 IlTimeoutIndicationFct V_MEMROM2 IlRxTimeoutFctPtr[kIlNumberOfRxTimeoutCounters] = 
{
  IlMsgSAS_1TimeoutIndication /* ID: 0x000000d0, SAS_1 [FC] */, 
  IlMsgTCU_3TimeoutIndication /* ID: 0x000000b4, TCU_3 [FC] */
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_POLLING)
V_MEMROM0 V_MEMROM1 IlIndicationFct V_MEMROM2 IlCanRxIndicationFctPtr[kIlCanNumberOfRxObjects] = 
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
  V_NULL /* ID: 0x000000d0, Handle: 42, SAS_1 [FC] */, 
  V_NULL /* ID: 0x000000c2, Handle: 43, ABS_2 [FC] */, 
  V_NULL /* ID: 0x000000c0, Handle: 44, ABS_1 [FC] */, 
  V_NULL /* ID: 0x000000b4, Handle: 45, TCU_3 [FC] */, 
  V_NULL /* ID: 0x00000094, Handle: 46, EMS_3 [FC] */, 
  V_NULL /* ID: 0x000001c0, Handle: 47, ADV_P1 [BC] */
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ TxDefaultInitValue Message Tables
 ----------------------------------------------------------------------------- */

V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot6IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot5IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot4IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot3IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot2IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Slot1IlTxDefaultInitValue[8] = 
{
  0xE8, 
  0x43, 
  0x1F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Replan_2IlTxDefaultInitValue[8] = 
{
  0xFC, 
  0xEF, 
  0x7F, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 APS_Replan_1IlTxDefaultInitValue[8] = 
{
  0xFC, 
  0xEF, 
  0x7F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 RightCurbInfoIlTxDefaultInitValue[8] = 
{
  0xFC, 
  0xEF, 
  0x7F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0xC0, 
  0xFF
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 LeftCurbInfoIlTxDefaultInitValue[8] = 
{
  0xFC, 
  0xEF, 
  0x7F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0xC0, 
  0xFF
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace11_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace10_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace9_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace8_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace7_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace6_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace5_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace4_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace3_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace2_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace1_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 Freespace0_ObstacleInfoIlTxDefaultInitValue[8] = 
{
  0xFE, 
  0xF7, 
  0x3F, 
  0xFE, 
  0xF7, 
  0x3F, 
  0x00, 
  0x00
};


/* -----------------------------------------------------------------------------
    &&&~ RxDefaultInitValue Message Tables
 ----------------------------------------------------------------------------- */

V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 HU_20IlRxDefaultInitValue[7] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 GPS_1IlRxDefaultInitValue[6] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x01, 
  0x01, 
  0x01
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 HU_6IlRxDefaultInitValue[8] = 
{
  0xE8, 
  0x83, 
  0x3E, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 BCM1_7IlRxDefaultInitValue[4] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ATC_2IlRxDefaultInitValue[4] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x50
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ADV_TargetTracingIlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ADV_PathTracingIlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ESC_3IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x9C, 
  0x68, 
  0x63, 
  0x00, 
  0x00, 
  0x1B, 
  0x03
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ABS_3IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 SAS_1IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x01
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ABS_2IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 ABS_1IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 TCU_3IlRxDefaultInitValue[8] = 
{
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};


/* -----------------------------------------------------------------------------
    &&&~ TxDefaultInitValue
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_DEFAULTVALUE)
V_MEMROM0 IL_MEMROM1 vuint8 IL_MEMROM2 IL_MEMROM3 *V_MEMROM1 V_MEMROM2  IlTxDefaultInitValue[kIlNumberOfTxObjects] =
{
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  V_NULL,
  APS_Slot6IlTxDefaultInitValue,
  APS_Slot5IlTxDefaultInitValue,
  APS_Slot4IlTxDefaultInitValue,
  APS_Slot3IlTxDefaultInitValue,
  APS_Slot2IlTxDefaultInitValue,
  APS_Slot1IlTxDefaultInitValue,
  V_NULL,
  APS_Replan_2IlTxDefaultInitValue,
  APS_Replan_1IlTxDefaultInitValue,
  RightCurbInfoIlTxDefaultInitValue,
  LeftCurbInfoIlTxDefaultInitValue,
  Freespace11_ObstacleInfoIlTxDefaultInitValue,
  Freespace10_ObstacleInfoIlTxDefaultInitValue,
  Freespace9_ObstacleInfoIlTxDefaultInitValue,
  Freespace8_ObstacleInfoIlTxDefaultInitValue,
  Freespace7_ObstacleInfoIlTxDefaultInitValue,
  Freespace6_ObstacleInfoIlTxDefaultInitValue,
  Freespace5_ObstacleInfoIlTxDefaultInitValue,
  Freespace4_ObstacleInfoIlTxDefaultInitValue,
  Freespace3_ObstacleInfoIlTxDefaultInitValue,
  Freespace2_ObstacleInfoIlTxDefaultInitValue,
  Freespace1_ObstacleInfoIlTxDefaultInitValue,
  Freespace0_ObstacleInfoIlTxDefaultInitValue,
  V_NULL
};
#endif



/* -----------------------------------------------------------------------------
    &&&~ RxDefaultInitValue
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_DEFAULTVALUE)
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3* V_MEMROM1 V_MEMROM2 IlRxDefaultInitValue[kIlNumberOfRxObjects] = 
{
  V_NULL, 
  V_NULL, 
  V_NULL, 
  HU_20IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  GPS_1IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  HU_6IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  BCM1_7IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL, 
  V_NULL, 
  ATC_2IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL, 
  ADV_TargetTracingIlRxDefaultInitValue, 
  ADV_PathTracingIlRxDefaultInitValue, 
  ESC_3IlRxDefaultInitValue, 
  V_NULL, 
  ABS_3IlRxDefaultInitValue, 
  SAS_1IlRxDefaultInitValue, 
  ABS_2IlRxDefaultInitValue, 
  ABS_1IlRxDefaultInitValue, 
  TCU_3IlRxDefaultInitValue, 
  V_NULL, 
  V_NULL
};
#endif



/* -----------------------------------------------------------------------------
    &&&~ StartIndex Tables
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IlTransmitHandle V_MEMROM2 IlTxMsgStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  38, 
  55
};
#endif



#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_CONFIRMATION_FLAG)
V_MEMROM0 V_MEMROM1 IlTransmitHandle V_MEMROM2 IlTxConfirmationFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT_FLAG)
V_MEMROM0 V_MEMROM1 IlTransmitHandle V_MEMROM2 IlTxTimeoutFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
V_MEMROM0 V_MEMROM1 IlTransmitHandle V_MEMROM2 IlTxTimeoutCntStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_RX)
V_MEMROM0 V_MEMROM1 IlReceiveHandle V_MEMROM2 IlRxMsgStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  47, 
  48
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_POLLING)
V_MEMROM0 V_MEMROM1 CanReceiveHandle V_MEMROM2 IlCanRxMsgStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  47, 
  48
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_INDICATION_FLAG)
V_MEMROM0 V_MEMROM1 IltRxIndicationOffset V_MEMROM2 IlRxIndicationFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_FIRSTVALUE_FLAG)
V_MEMROM0 V_MEMROM1 IlReceiveHandle V_MEMROM2 IlRxFirstvalueFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT_FLAG)
V_MEMROM0 V_MEMROM1 IlReceiveHandle V_MEMROM2 IlRxTimeoutFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  1, 
  1
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_DATACHANGED_FLAG)
V_MEMROM0 V_MEMROM1 IlRxDataChangedFlagHandle V_MEMROM2 IlRxDataChangedFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  0, 
  0
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
V_MEMROM0 V_MEMROM1 IlReceiveHandle V_MEMROM2 IlRxTimeoutCntStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  2, 
  2
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_TIMEOUT)
V_MEMROM0 V_MEMROM1 IlReceiveHandle V_MEMROM2 IlRxTimerFlagsStartIndex[kIlNumberOfChannels+1] = 
{
  0, 
  1, 
  1
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ Implementation of Precopy Functions
 ----------------------------------------------------------------------------- */

#ifdef IL_ENABLE_RX
vuint8 IlMsgSAS_1PreCopy(CanRxInfoStructPtr rxStruct)
{
  rxStruct = rxStruct;
  IlEnterCriticalFlagAccess();
  ilRxTimerFlags[0] |= (vuint8) 0x01;
  IlLeaveCriticalFlagAccess();
  return kCanCopyData;
}


#endif

#ifdef IL_ENABLE_RX
vuint8 IlMsgTCU_3PreCopy(CanRxInfoStructPtr rxStruct)
{
  rxStruct = rxStruct;
  IlEnterCriticalFlagAccess();
  ilRxTimerFlags[0] |= (vuint8) 0x02;
  IlLeaveCriticalFlagAccess();
  return kCanCopyData;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation of Indication Functions
 ----------------------------------------------------------------------------- */

void IlMsgSAS_1Indication(CanReceiveHandle rxObject)
{
  rxObject = rxObject;
  IlEnterCriticalFlagAccess();
  ilRxTimeoutFlags[0] &= (vuint8) 0xFC;
  IlLeaveCriticalFlagAccess();
}


void IlMsgTCU_3Indication(CanReceiveHandle rxObject)
{
  rxObject = rxObject;
  IlEnterCriticalFlagAccess();
  ilRxTimeoutFlags[0] &= (vuint8) 0xFB;
  IlLeaveCriticalFlagAccess();
}




/* -----------------------------------------------------------------------------
    &&&~ Implementation Rx Timeout Indication Functions
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && (defined(IL_ENABLE_RX_TIMEOUT) || defined(IL_ENABLE_RX_EXT_TIMEOUT))
static void IlMsgSAS_1TimeoutIndication(void)
{
  CanGlobalInterruptDisable();
  ilRxTimeoutFlags[0] |= (vuint8) 0x03;
  CanGlobalInterruptRestore();
}


#endif

#if defined(IL_ENABLE_RX) && (defined(IL_ENABLE_RX_TIMEOUT) || defined(IL_ENABLE_RX_EXT_TIMEOUT))
static void IlMsgTCU_3TimeoutIndication(void)
{
  CanGlobalInterruptDisable();
  ilRxTimeoutFlags[0] |= (vuint8) 0x04;
  CanGlobalInterruptRestore();
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Declaration checking macro for signals OnChange or OnChangeWithRepetition with size < 32bit
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
#define PrivateCanStaValueChanged(sigData)   (((sigData) != (IlPrivateGetTxPrivateCanSta())))
#endif

#if defined(IL_ENABLE_TX)
#define PubuicCanStaValueChanged(sigData)    (((sigData) != (IlPrivateGetTxPubuicCanSta())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_CxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Cx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_CyValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Cy())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_DxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Dx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_DyValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Dy())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_AxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Ax())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_AyValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Ay())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_BxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_Bx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_ByValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_R_By())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_CxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Cx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_CyValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Cy())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_DxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Dx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_DyValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Dy())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_AxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Ax())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_AYValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_AY())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_BxValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_Bx())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_ByValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_SLOT_L_By())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FLSValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_FLS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FRSValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_FRS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RLSValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_RLS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RRSValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_RRS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RLValueChanged(sigData)       (((sigData) != (IlPrivateGetTxUSS_DE_RL())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RMLValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_RML())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RMRValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_RMR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_RRValueChanged(sigData)       (((sigData) != (IlPrivateGetTxUSS_DE_RR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FLValueChanged(sigData)       (((sigData) != (IlPrivateGetTxUSS_DE_FL())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FMLValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_FML())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FMRValueChanged(sigData)      (((sigData) != (IlPrivateGetTxUSS_DE_FMR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DE_FRValueChanged(sigData)       (((sigData) != (IlPrivateGetTxUSS_DE_FR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RLValueChanged(sigData)     (((sigData) != (IlPrivateGetTxUSS_DIAG_RL())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RLSValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_RLS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RMLValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_RML())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RMRValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_RMR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RRValueChanged(sigData)     (((sigData) != (IlPrivateGetTxUSS_DIAG_RR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_RRSValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_RRS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FLValueChanged(sigData)     (((sigData) != (IlPrivateGetTxUSS_DIAG_FL())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FLSValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_FLS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FMLValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_FML())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FMRValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_FMR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FRValueChanged(sigData)     (((sigData) != (IlPrivateGetTxUSS_DIAG_FR())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_DIAG_FRSValueChanged(sigData)    (((sigData) != (IlPrivateGetTxUSS_DIAG_FRS())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_WORK_MODEValueChanged(sigData)   (((sigData) != (IlPrivateGetTxUSS_WORK_MODE())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_L_DEPTHValueChanged(sigData) (((sigData) != (IlPrivateGetTxUSS_SLOT_L_DEPTH())))
#endif

#if defined(IL_ENABLE_TX)
#define USS_SLOT_R_DEPTHValueChanged(sigData) (((sigData) != (IlPrivateGetTxUSS_SLOT_R_DEPTH())))
#endif

#if defined(IL_ENABLE_TX)
#define SysSt_PDCValueChanged(sigData)       (((sigData) != (IlPrivateGetTxSysSt_PDC())))
#endif

#if defined(IL_ENABLE_TX)
#define ErrorSt_PDCValueChanged(sigData)     (((sigData) != (IlPrivateGetTxErrorSt_PDC())))
#endif

#if defined(IL_ENABLE_TX)
#define RadarSysSt_FrontValueChanged(sigData) (((sigData) != (IlPrivateGetTxRadarSysSt_Front())))
#endif

#if defined(IL_ENABLE_TX)
#define RadarSysSt_RearValueChanged(sigData) (((sigData) != (IlPrivateGetTxRadarSysSt_Rear())))
#endif

#if defined(IL_ENABLE_TX)
#define BuzeerCmd_PDCValueChanged(sigData)   (((sigData) != (IlPrivateGetTxBuzeerCmd_PDC())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_RRValueChanged(sigData)  (((sigData) != (IlPrivateGetTxObjectRange_RR())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_RRValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_RR())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_RMRValueChanged(sigData) (((sigData) != (IlPrivateGetTxObjectRange_RMR())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_RMRValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_RMR())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_RMLValueChanged(sigData) (((sigData) != (IlPrivateGetTxObjectRange_RML())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_RMLValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_RML())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_RLValueChanged(sigData)  (((sigData) != (IlPrivateGetTxObjectRange_RL())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_RLValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_RL())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_FRValueChanged(sigData)  (((sigData) != (IlPrivateGetTxObjectRange_FR())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_FRValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_FR())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_FMRValueChanged(sigData) (((sigData) != (IlPrivateGetTxObjectRange_FMR())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_FMRValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_FMR())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_FMLValueChanged(sigData) (((sigData) != (IlPrivateGetTxObjectRange_FML())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_FMLValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_FML())))
#endif

#if defined(IL_ENABLE_TX)
#define ObjectRange_FLValueChanged(sigData)  (((sigData) != (IlPrivateGetTxObjectRange_FL())))
#endif

#if defined(IL_ENABLE_TX)
#define SensorErrorSt_FLValueChanged(sigData) (((sigData) != (IlPrivateGetTxSensorErrorSt_FL())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSStValueChanged(sigData)           (((sigData) != (IlPrivateGetTxAVSSt())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSErrorStValueChanged(sigData)      (((sigData) != (IlPrivateGetTxAVSErrorSt())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSViewModeValueChanged(sigData)     (((sigData) != (IlPrivateGetTxAVSViewMode())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSCameraErrorSt_FrontValueChanged(sigData) (((sigData) != (IlPrivateGetTxAVSCameraErrorSt_Front())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSCameraErrorSt_RearValueChanged(sigData) (((sigData) != (IlPrivateGetTxAVSCameraErrorSt_Rear())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSCameraErrorSt_LeftValueChanged(sigData) (((sigData) != (IlPrivateGetTxAVSCameraErrorSt_Left())))
#endif

#if defined(IL_ENABLE_TX)
#define AVSCameraErrorSt_RightValueChanged(sigData) (((sigData) != (IlPrivateGetTxAVSCameraErrorSt_Right())))
#endif

#if defined(IL_ENABLE_TX)
#define LanguageTypeSt_AVSValueChanged(sigData) (((sigData) != (IlPrivateGetTxLanguageTypeSt_AVS())))
#endif

#if defined(IL_ENABLE_TX)
#define DynamicPGSSt_AVSValueChanged(sigData) (((sigData) != (IlPrivateGetTxDynamicPGSSt_AVS())))
#endif

#if defined(IL_ENABLE_TX)
#define MODSt_AVSValueChanged(sigData)       (((sigData) != (IlPrivateGetTxMODSt_AVS())))
#endif

#if defined(IL_ENABLE_TX)
#define MODWarning_FrontValueChanged(sigData) (((sigData) != (IlPrivateGetTxMODWarning_Front())))
#endif

#if defined(IL_ENABLE_TX)
#define MODWarning_RearValueChanged(sigData) (((sigData) != (IlPrivateGetTxMODWarning_Rear())))
#endif

#if defined(IL_ENABLE_TX)
#define SwitchScreenRequest_AVSValueChanged(sigData) (((sigData) != (IlPrivateGetTxSwitchScreenRequest_AVS())))
#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation of a function to check IfActive flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_SYS_TX_SIGNALS_ARE_ACTIVE_FCT)
Il_Boolean IlTxSignalsAreActive(CanChannelHandle channel)
{
  channel = channel;
  return IL_FALSE;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation function to reset indication flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_POLLING)
void IlResetCanIndicationFlags(CanChannelHandle channel)
{
  CanGlobalInterruptDisable();
  if(channel == 0)
  {
  }
  if(channel == 1)
  {
  }
  CanGlobalInterruptRestore();
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation function to reset confirmation flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
void IlResetCanConfirmationFlags(CanChannelHandle channel)
{
  CanGlobalInterruptDisable();
  if(channel == 0)
  {
    IlGetTxConfirmationFlags(0) &= (vuint8) 0x01;
    IlGetTxConfirmationFlags(1) &= (vuint8) 0x00;
    IlGetTxConfirmationFlags(2) &= (vuint8) 0x00;
    IlGetTxConfirmationFlags(3) &= (vuint8) 0x00;
    IlGetTxConfirmationFlags(4) &= (vuint8) 0x80;
  }
  if(channel == 1)
  {
    IlGetTxConfirmationFlags(5) &= (vuint8) 0x00;
    IlGetTxConfirmationFlags(6) &= (vuint8) 0x00;
    IlGetTxConfirmationFlags(7) &= (vuint8) 0xFE;
  }
  CanGlobalInterruptRestore();
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:              alpha_USS_FL_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FL_long(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FL_long();
  rc = ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_FL_long_0);
  rc |= ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_FL_long_1) << 8;
  IlLeaveCriticalalpha_USS_FL_long();
  return rc;
}


#endif

/* Handle:    1,Name:              alpha_USS_FR_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FR_long(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FR_long();
  rc = ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_FR_long_0);
  rc |= ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_FR_long_1) << 8;
  IlLeaveCriticalalpha_USS_FR_long();
  return rc;
}


#endif

/* Handle:    2,Name:              alpha_USS_RL_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RL_long(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RL_long();
  rc = ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_RL_long_0);
  rc |= ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_RL_long_1) << 8;
  IlLeaveCriticalalpha_USS_RL_long();
  return rc;
}


#endif

/* Handle:    3,Name:              alpha_USS_RR_long,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RR_long(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RR_long();
  rc = ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_RR_long_0);
  rc |= ((vuint16) alpha_distance_Long.alpha_distance_Long.alpha_USS_RR_long_1) << 8;
  IlLeaveCriticalalpha_USS_RR_long();
  return rc;
}


#endif

/* Handle:    4,Name:                   alpha_USS_RL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RL(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RL();
  rc = ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RL_0);
  rc |= ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RL_1) << 8;
  IlLeaveCriticalalpha_USS_RL();
  return rc;
}


#endif

/* Handle:    5,Name:                  alpha_USS_RML,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RML(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RML();
  rc = ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RML_0);
  rc |= ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RML_1) << 8;
  IlLeaveCriticalalpha_USS_RML();
  return rc;
}


#endif

/* Handle:    6,Name:                  alpha_USS_RMR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RMR(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RMR();
  rc = ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RMR_0);
  rc |= ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RMR_1) << 8;
  IlLeaveCriticalalpha_USS_RMR();
  return rc;
}


#endif

/* Handle:    7,Name:                   alpha_USS_RR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_RR(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_RR();
  rc = ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RR_0);
  rc |= ((vuint16) alpha_distance_R.alpha_distance_R.alpha_USS_RR_1) << 8;
  IlLeaveCriticalalpha_USS_RR();
  return rc;
}


#endif

/* Handle:    8,Name:                   alpha_USS_FL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FL(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FL();
  rc = ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FL_0);
  rc |= ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FL_1) << 8;
  IlLeaveCriticalalpha_USS_FL();
  return rc;
}


#endif

/* Handle:    9,Name:                  alpha_USS_FML,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FML(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FML();
  rc = ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FML_0);
  rc |= ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FML_1) << 8;
  IlLeaveCriticalalpha_USS_FML();
  return rc;
}


#endif

/* Handle:   10,Name:                  alpha_USS_FMR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FMR(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FMR();
  rc = ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FMR_0);
  rc |= ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FMR_1) << 8;
  IlLeaveCriticalalpha_USS_FMR();
  return rc;
}


#endif

/* Handle:   11,Name:                   alpha_USS_FR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxalpha_USS_FR(void)
{
  vuint16 rc;
  IlEnterCriticalalpha_USS_FR();
  rc = ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FR_0);
  rc |= ((vuint16) alpha_distance_F.alpha_distance_F.alpha_USS_FR_1) << 8;
  IlLeaveCriticalalpha_USS_FR();
  return rc;
}


#endif

/* Handle:   12,Name:         ScreenPressPosition_X1,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxScreenPressPosition_X1(void)
{
  vuint16 rc;
  IlEnterCriticalScreenPressPosition_X1();
  rc = ((vuint16) HU_20.HU_20.ScreenPressPosition_X1_0);
  rc |= ((vuint16) HU_20.HU_20.ScreenPressPosition_X1_1) << 8;
  IlLeaveCriticalScreenPressPosition_X1();
  return rc;
}


#endif

/* Handle:   13,Name:         ScreenPressPosition_Y1,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxScreenPressPosition_Y1(void)
{
  vuint16 rc;
  IlEnterCriticalScreenPressPosition_Y1();
  rc = ((vuint16) HU_20.HU_20.ScreenPressPosition_Y1_0);
  rc |= ((vuint16) HU_20.HU_20.ScreenPressPosition_Y1_1) << 4;
  IlLeaveCriticalScreenPressPosition_Y1();
  return rc;
}


#endif

/* Handle:   14,Name:         ScreenPressPosition_X2,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxScreenPressPosition_X2(void)
{
  vuint16 rc;
  IlEnterCriticalScreenPressPosition_X2();
  rc = ((vuint16) HU_20.HU_20.ScreenPressPosition_X2_0);
  rc |= ((vuint16) HU_20.HU_20.ScreenPressPosition_X2_1) << 8;
  IlLeaveCriticalScreenPressPosition_X2();
  return rc;
}


#endif

/* Handle:   15,Name:         ScreenPressPosition_Y2,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxScreenPressPosition_Y2(void)
{
  vuint16 rc;
  IlEnterCriticalScreenPressPosition_Y2();
  rc = ((vuint16) HU_20.HU_20.ScreenPressPosition_Y2_0);
  rc |= ((vuint16) HU_20.HU_20.ScreenPressPosition_Y2_1) << 4;
  IlLeaveCriticalScreenPressPosition_Y2();
  return rc;
}


#endif

/* Handle:   18,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Cx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Cx();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Cx();
  return rc;
}


#endif

/* Handle:   19,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Cy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Cy();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Cy();
  return rc;
}


#endif

/* Handle:   20,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Dx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Dx();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Dx();
  return rc;
}


#endif

/* Handle:   21,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Dy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Dy();
  rc = ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_0);
  rc |= ((vuint16) USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Dy();
  return rc;
}


#endif

/* Handle:   22,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Ax(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Ax();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Ax();
  return rc;
}


#endif

/* Handle:   23,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Ay(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Ay();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Ay();
  return rc;
}


#endif

/* Handle:   24,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_Bx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_Bx();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_Bx();
  return rc;
}


#endif

/* Handle:   25,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_R_By(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_R_By();
  rc = ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_0);
  rc |= ((vuint16) USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_1) << 8;
  IlLeaveCriticalUSS_SLOT_R_By();
  return rc;
}


#endif

/* Handle:   26,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Cx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Cx();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Cx();
  return rc;
}


#endif

/* Handle:   27,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Cy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Cy();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Cy();
  return rc;
}


#endif

/* Handle:   28,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Dx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Dx();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Dx();
  return rc;
}


#endif

/* Handle:   29,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Dy(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Dy();
  rc = ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_0);
  rc |= ((vuint16) USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Dy();
  return rc;
}


#endif

/* Handle:   30,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Ax(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Ax();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Ax();
  return rc;
}


#endif

/* Handle:   31,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_AY(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_AY();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_AY();
  return rc;
}


#endif

/* Handle:   32,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_Bx(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_Bx();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_Bx();
  return rc;
}


#endif

/* Handle:   33,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_SLOT_L_By(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_SLOT_L_By();
  rc = ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_0);
  rc |= ((vuint16) USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_1) << 8;
  IlLeaveCriticalUSS_SLOT_L_By();
  return rc;
}


#endif

/* Handle:   34,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_FLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FLS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FLS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FLS_1) << 8;
  IlLeaveCriticalUSS_DE_FLS();
  return rc;
}


#endif

/* Handle:   35,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_FRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_FRS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FRS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_FRS_1) << 8;
  IlLeaveCriticalUSS_DE_FRS();
  return rc;
}


#endif

/* Handle:   36,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RLS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RLS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RLS_1) << 8;
  IlLeaveCriticalUSS_DE_RLS();
  return rc;
}


#endif

/* Handle:   37,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RRS();
  rc = ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RRS_0);
  rc |= ((vuint16) USS_DE_S.USS_DE_S.USS_DE_RRS_1) << 8;
  IlLeaveCriticalUSS_DE_RRS();
  return rc;
}


#endif

/* Handle:   38,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RL();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RL_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RL_1) << 8;
  IlLeaveCriticalUSS_DE_RL();
  return rc;
}


#endif

/* Handle:   39,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RML();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_1) << 3;
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RML_2) << 11;
  IlLeaveCriticalUSS_DE_RML();
  return rc;
}


#endif

/* Handle:   40,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RMR();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RMR_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RMR_1) << 6;
  IlLeaveCriticalUSS_DE_RMR();
  return rc;
}


#endif

/* Handle:   41,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DE_RR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DE_RR();
  rc = ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_0);
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_1) << 1;
  rc |= ((vuint16) USS_DE_R.USS_DE_R.USS_DE_RR_2) << 9;
  IlLeaveCriticalUSS_DE_RR();
  return rc;
}


#endif

/* Handle:   42,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RL();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_1) << 8;
  IlLeaveCriticalUSS_DIAG_RL();
  return rc;
}


#endif

/* Handle:   43,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RLS();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_1) << 6;
  IlLeaveCriticalUSS_DIAG_RLS();
  return rc;
}


#endif

/* Handle:   44,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RML();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_1) << 4;
  IlLeaveCriticalUSS_DIAG_RML();
  return rc;
}


#endif

/* Handle:   45,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RMR();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_1) << 2;
  IlLeaveCriticalUSS_DIAG_RMR();
  return rc;
}


#endif

/* Handle:   46,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RR();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_1) << 8;
  IlLeaveCriticalUSS_DIAG_RR();
  return rc;
}


#endif

/* Handle:   47,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_RRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_RRS();
  rc = ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_0);
  rc |= ((vuint16) USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_1) << 6;
  IlLeaveCriticalUSS_DIAG_RRS();
  return rc;
}


#endif

/* Handle:   48,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FL(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FL();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_1) << 8;
  IlLeaveCriticalUSS_DIAG_FL();
  return rc;
}


#endif

/* Handle:   49,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FLS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FLS();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_1) << 6;
  IlLeaveCriticalUSS_DIAG_FLS();
  return rc;
}


#endif

/* Handle:   50,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FML(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FML();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_1) << 4;
  IlLeaveCriticalUSS_DIAG_FML();
  return rc;
}


#endif

/* Handle:   51,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FMR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FMR();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_1) << 2;
  IlLeaveCriticalUSS_DIAG_FMR();
  return rc;
}


#endif

/* Handle:   52,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FR(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FR();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_1) << 8;
  IlLeaveCriticalUSS_DIAG_FR();
  return rc;
}


#endif

/* Handle:   53,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxUSS_DIAG_FRS(void)
{
  vuint16 rc;
  IlEnterCriticalUSS_DIAG_FRS();
  rc = ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_0);
  rc |= ((vuint16) USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_1) << 6;
  IlLeaveCriticalUSS_DIAG_FRS();
  return rc;
}


#endif

/* Handle:   72,Name:                  OdometerValue,Size: 25,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_RX
vuint32 IlGetRxOdometerValue(void)
{
  vuint32 rc;
  IlEnterCriticalOdometerValue();
  rc = ((vuint32) IC_1.IC_1.OdometerValue_0);
  rc |= ((vuint32) IC_1.IC_1.OdometerValue_1) << 8;
  rc |= ((vuint32) IC_1.IC_1.OdometerValue_2) << 16;
  rc |= ((vuint32) IC_1.IC_1.OdometerValue_3) << 24;
  IlLeaveCriticalOdometerValue();
  return rc;
}


#endif

/* Handle:   78,Name:        TargetSelectionCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxTargetSelectionCenter_X(void)
{
  vuint16 rc;
  IlEnterCriticalTargetSelectionCenter_X();
  rc = ((vuint16) HU_6.HU_6.TargetSelectionCenter_X_0);
  rc |= ((vuint16) HU_6.HU_6.TargetSelectionCenter_X_1) << 8;
  IlLeaveCriticalTargetSelectionCenter_X();
  return rc;
}


#endif

/* Handle:   80,Name:        TargetSelectionCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxTargetSelectionCenter_Y(void)
{
  vuint16 rc;
  IlEnterCriticalTargetSelectionCenter_Y();
  rc = ((vuint16) HU_6.HU_6.TargetSelectionCenter_Y_0);
  rc |= ((vuint16) HU_6.HU_6.TargetSelectionCenter_Y_1) << 4;
  IlLeaveCriticalTargetSelectionCenter_Y();
  return rc;
}


#endif

/* Handle:   81,Name:    TargetSelectionCenter_Angle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxTargetSelectionCenter_Angle(void)
{
  vuint16 rc;
  IlEnterCriticalTargetSelectionCenter_Angle();
  rc = ((vuint16) HU_6.HU_6.TargetSelectionCenter_Angle_0);
  rc |= ((vuint16) HU_6.HU_6.TargetSelectionCenter_Angle_1) << 8;
  IlLeaveCriticalTargetSelectionCenter_Angle();
  return rc;
}


#endif

/* Handle:   84,Name:      TargetSelection_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxTargetSelection_LineAngle(void)
{
  vuint16 rc;
  IlEnterCriticalTargetSelection_LineAngle();
  rc = ((vuint16) HU_6.HU_6.TargetSelection_LineAngle_0);
  rc |= ((vuint16) HU_6.HU_6.TargetSelection_LineAngle_1) << 8;
  IlLeaveCriticalTargetSelection_LineAngle();
  return rc;
}


#endif

/* Handle:  132,Name:                   Brightness_H,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxBrightness_H(void)
{
  vuint16 rc;
  IlEnterCriticalBrightness_H();
  rc = ((vuint16) BCM1_7.BCM1_7.Brightness_H_0);
  rc |= ((vuint16) BCM1_7.BCM1_7.Brightness_H_1) << 8;
  IlLeaveCriticalBrightness_H();
  return rc;
}


#endif

/* Handle:  149,Name:      ADV_TargetTracingCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_TargetTracingCenter_X(void)
{
  vuint16 rc;
  IlEnterCriticalADV_TargetTracingCenter_X();
  rc = ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingCenter_X_0);
  rc |= ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingCenter_X_1) << 8;
  IlLeaveCriticalADV_TargetTracingCenter_X();
  return rc;
}


#endif

/* Handle:  150,Name:      ADV_TargetTracingCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_TargetTracingCenter_Y(void)
{
  vuint16 rc;
  IlEnterCriticalADV_TargetTracingCenter_Y();
  rc = ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingCenter_Y_0);
  rc |= ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingCenter_Y_1) << 4;
  IlLeaveCriticalADV_TargetTracingCenter_Y();
  return rc;
}


#endif

/* Handle:  151,Name:         ADV_TargetTracingAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_TargetTracingAngle(void)
{
  vuint16 rc;
  IlEnterCriticalADV_TargetTracingAngle();
  rc = ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingAngle_0);
  rc |= ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingAngle_1) << 8;
  IlLeaveCriticalADV_TargetTracingAngle();
  return rc;
}


#endif

/* Handle:  152,Name:        ADV_TargetTracingLength,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_TargetTracingLength(void)
{
  vuint16 rc;
  IlEnterCriticalADV_TargetTracingLength();
  rc = ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingLength_0);
  rc |= ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingLength_1) << 5;
  IlLeaveCriticalADV_TargetTracingLength();
  return rc;
}


#endif

/* Handle:  153,Name:         ADV_TargetTracingWidth,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_TargetTracingWidth(void)
{
  vuint16 rc;
  IlEnterCriticalADV_TargetTracingWidth();
  rc = ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingWidth_0);
  rc |= ((vuint16) ADV_TargetTracing.ADV_TargetTracing.ADV_TargetTracingWidth_1) << 8;
  IlLeaveCriticalADV_TargetTracingWidth();
  return rc;
}


#endif

/* Handle:  156,Name:        ADV_PathTracingCenter_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_PathTracingCenter_X(void)
{
  vuint16 rc;
  IlEnterCriticalADV_PathTracingCenter_X();
  rc = ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingCenter_X_0);
  rc |= ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingCenter_X_1) << 8;
  IlLeaveCriticalADV_PathTracingCenter_X();
  return rc;
}


#endif

/* Handle:  157,Name:        ADV_PathTracingCenter_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_PathTracingCenter_Y(void)
{
  vuint16 rc;
  IlEnterCriticalADV_PathTracingCenter_Y();
  rc = ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingCenter_Y_0);
  rc |= ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingCenter_Y_1) << 4;
  IlLeaveCriticalADV_PathTracingCenter_Y();
  return rc;
}


#endif

/* Handle:  158,Name:           ADV_PathTracingAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_PathTracingAngle(void)
{
  vuint16 rc;
  IlEnterCriticalADV_PathTracingAngle();
  rc = ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingAngle_0);
  rc |= ((vuint16) ADV_PathTracing.ADV_PathTracing.ADV_PathTracingAngle_1) << 8;
  IlLeaveCriticalADV_PathTracingAngle();
  return rc;
}


#endif

/* Handle:  166,Name:                        YawRate,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxYawRate(void)
{
  vuint16 rc;
  IlEnterCriticalYawRate();
  rc = ((vuint16) ESC_3.ESC_3.YawRate_0);
  rc |= ((vuint16) ESC_3.ESC_3.YawRate_1) << 8;
  IlLeaveCriticalYawRate();
  return rc;
}


#endif

/* Handle:  168,Name:                 Acceleration_X,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxAcceleration_X(void)
{
  vuint16 rc;
  IlEnterCriticalAcceleration_X();
  rc = ((vuint16) ESC_3.ESC_3.Acceleration_X_0);
  rc |= ((vuint16) ESC_3.ESC_3.Acceleration_X_1) << 3;
  IlLeaveCriticalAcceleration_X();
  return rc;
}


#endif

/* Handle:  169,Name:                 Acceleration_Y,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxAcceleration_Y(void)
{
  vuint16 rc;
  IlEnterCriticalAcceleration_Y();
  rc = ((vuint16) ESC_3.ESC_3.Acceleration_Y_0);
  rc |= ((vuint16) ESC_3.ESC_3.Acceleration_Y_1) << 8;
  IlLeaveCriticalAcceleration_Y();
  return rc;
}


#endif

/* Handle:  186,Name:             SteeringWheelAngle,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxSteeringWheelAngle(void)
{
  vuint16 rc;
  IlEnterCriticalSteeringWheelAngle();
  rc = ((vuint16) SAS_1.SAS_1.SteeringWheelAngle_0);
  rc |= ((vuint16) SAS_1.SAS_1.SteeringWheelAngle_1) << 8;
  IlLeaveCriticalSteeringWheelAngle();
  return rc;
}


#endif

/* Handle:  191,Name:                  WheelSpeed_RL,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxWheelSpeed_RL(void)
{
  vuint16 rc;
  IlEnterCriticalWheelSpeed_RL();
  rc = ((vuint16) ABS_2.ABS_2.WheelSpeed_RL_0);
  rc |= ((vuint16) ABS_2.ABS_2.WheelSpeed_RL_1) << 8;
  IlLeaveCriticalWheelSpeed_RL();
  return rc;
}


#endif

/* Handle:  192,Name:                  WheelSpeed_RR,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxWheelSpeed_RR(void)
{
  vuint16 rc;
  IlEnterCriticalWheelSpeed_RR();
  rc = ((vuint16) ABS_2.ABS_2.WheelSpeed_RR_0);
  rc |= ((vuint16) ABS_2.ABS_2.WheelSpeed_RR_1) << 8;
  IlLeaveCriticalWheelSpeed_RR();
  return rc;
}


#endif

/* Handle:  195,Name:                  WheelSpeed_FL,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxWheelSpeed_FL(void)
{
  vuint16 rc;
  IlEnterCriticalWheelSpeed_FL();
  rc = ((vuint16) ABS_1.ABS_1.WheelSpeed_FL_0);
  rc |= ((vuint16) ABS_1.ABS_1.WheelSpeed_FL_1) << 8;
  IlLeaveCriticalWheelSpeed_FL();
  return rc;
}


#endif

/* Handle:  196,Name:                  WheelSpeed_FR,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxWheelSpeed_FR(void)
{
  vuint16 rc;
  IlEnterCriticalWheelSpeed_FR();
  rc = ((vuint16) ABS_1.ABS_1.WheelSpeed_FR_0);
  rc |= ((vuint16) ABS_1.ABS_1.WheelSpeed_FR_1) << 8;
  IlLeaveCriticalWheelSpeed_FR();
  return rc;
}


#endif

/* Handle:  197,Name:                   VehicleSpeed,Size: 15,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxVehicleSpeed(void)
{
  vuint16 rc;
  IlEnterCriticalVehicleSpeed();
  rc = ((vuint16) ABS_1.ABS_1.VehicleSpeed_0);
  rc |= ((vuint16) ABS_1.ABS_1.VehicleSpeed_1) << 8;
  IlLeaveCriticalVehicleSpeed();
  return rc;
}


#endif

/* Handle:  206,Name:                     ADV_Pose_X,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_Pose_X(void)
{
  vuint16 rc;
  IlEnterCriticalADV_Pose_X();
  rc = ((vuint16) ADV_P1.ADV_P1.ADV_Pose_X_0);
  rc |= ((vuint16) ADV_P1.ADV_P1.ADV_Pose_X_1) << 8;
  IlLeaveCriticalADV_Pose_X();
  return rc;
}


#endif

/* Handle:  207,Name:                     ADV_Pose_Y,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_Pose_Y(void)
{
  vuint16 rc;
  IlEnterCriticalADV_Pose_Y();
  rc = ((vuint16) ADV_P1.ADV_P1.ADV_Pose_Y_0);
  rc |= ((vuint16) ADV_P1.ADV_P1.ADV_Pose_Y_1) << 4;
  IlLeaveCriticalADV_Pose_Y();
  return rc;
}


#endif

/* Handle:  208,Name:                 ADV_Pose_Angle,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxADV_Pose_Angle(void)
{
  vuint16 rc;
  IlEnterCriticalADV_Pose_Angle();
  rc = ((vuint16) ADV_P1.ADV_P1.ADV_Pose_Angle_0);
  rc |= ((vuint16) ADV_P1.ADV_P1.ADV_Pose_Angle_1) << 8;
  IlLeaveCriticalADV_Pose_Angle();
  return rc;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access 
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                  PrivateCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxPrivateCanSta(vuint8 sigData)
{
  if(PrivateCanStaValueChanged(sigData))
  {
    IlEnterCriticalPrivateCanSta();
    Debug_CanStaInfo.Debug_CanStaInfo.PrivateCanSta = ((vuint8) sigData);
    IlSetEvent(IlTxSigHndPrivateCanSta);
    IlLeaveCriticalPrivateCanSta();
  }
}


#endif

/* Handle:    1,Name:                   PubuicCanSta,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxPubuicCanSta(vuint8 sigData)
{
  if(PubuicCanStaValueChanged(sigData))
  {
    IlEnterCriticalPubuicCanSta();
    Debug_CanStaInfo.Debug_CanStaInfo.PubuicCanSta = ((vuint8) sigData);
    IlSetEvent(IlTxSigHndPubuicCanSta);
    IlLeaveCriticalPubuicCanSta();
  }
}


#endif

/* Handle:    2,Name:                   CanTaskAlive,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCanTaskAlive(vuint16 sigData)
{
  IlEnterCriticalCanTaskAlive();
  Debug_CanStaInfo.Debug_CanStaInfo.CanTaskAlive_0 = ((vuint8) sigData);
  Debug_CanStaInfo.Debug_CanStaInfo.CanTaskAlive_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndCanTaskAlive);
  IlLeaveCriticalCanTaskAlive();
}


#endif

/* Handle:    3,Name:         Debug_ReloatDistance_R,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatDistance_R(vuint16 sigData)
{
  IlEnterCriticalDebug_ReloatDistance_R();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatDistance_R_0 = ((vuint8) sigData);
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatDistance_R_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndDebug_ReloatDistance_R);
  IlLeaveCriticalDebug_ReloatDistance_R();
}


#endif

/* Handle:    4,Name:            Debug_ReloatTheta_R,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatTheta_R(vuint16 sigData)
{
  IlEnterCriticalDebug_ReloatTheta_R();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatTheta_R_0 = ((vuint8) sigData);
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatTheta_R_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
  IlSetEvent(IlTxSigHndDebug_ReloatTheta_R);
  IlLeaveCriticalDebug_ReloatTheta_R();
}


#endif

/* Handle:    5,Name:            Debug_ReloatValid_R,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatValid_R(vuint8 sigData)
{
  IlEnterCriticalDebug_ReloatValid_R();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatValid_R = ((vuint8) (sigData & (vuint8) 0x07));
  IlSetEvent(IlTxSigHndDebug_ReloatValid_R);
  IlLeaveCriticalDebug_ReloatValid_R();
}


#endif

/* Handle:    6,Name:         Debug_ReloatDistance_L,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatDistance_L(vuint16 sigData)
{
  IlEnterCriticalDebug_ReloatDistance_L();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatDistance_L_0 = ((vuint8) sigData);
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatDistance_L_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndDebug_ReloatDistance_L);
  IlLeaveCriticalDebug_ReloatDistance_L();
}


#endif

/* Handle:    7,Name:            Debug_ReloatTheta_L,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatTheta_L(vuint16 sigData)
{
  IlEnterCriticalDebug_ReloatTheta_L();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatTheta_L_0 = ((vuint8) sigData);
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatTheta_L_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
  IlSetEvent(IlTxSigHndDebug_ReloatTheta_L);
  IlLeaveCriticalDebug_ReloatTheta_L();
}


#endif

/* Handle:    8,Name:            Debug_ReloatValid_L,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDebug_ReloatValid_L(vuint8 sigData)
{
  IlEnterCriticalDebug_ReloatValid_L();
  Debug_ReloatInfo.Debug_ReloatInfo.Debug_ReloatValid_L = ((vuint8) (sigData & (vuint8) 0x07));
  IlSetEvent(IlTxSigHndDebug_ReloatValid_L);
  IlLeaveCriticalDebug_ReloatValid_L();
}


#endif

/* Handle:    9,Name:           FV_TargetPoint_Angle,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFV_TargetPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalFV_TargetPoint_Angle();
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_Angle_0 = ((vuint8) sigData);
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_Angle_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndFV_TargetPoint_Angle);
  IlLeaveCriticalFV_TargetPoint_Angle();
}


#endif

/* Handle:   10,Name:               FV_TargetPoint_X,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFV_TargetPoint_X(vuint16 sigData)
{
  IlEnterCriticalFV_TargetPoint_X();
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_X_0 = ((vuint8) sigData);
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_X_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndFV_TargetPoint_X);
  IlLeaveCriticalFV_TargetPoint_X();
}


#endif

/* Handle:   11,Name:               FV_TargetPoint_Y,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFV_TargetPoint_Y(vuint16 sigData)
{
  IlEnterCriticalFV_TargetPoint_Y();
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_Y_0 = ((vuint8) sigData);
  TargetPointInfo.TargetPointInfo.FV_TargetPoint_Y_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndFV_TargetPoint_Y);
  IlLeaveCriticalFV_TargetPoint_Y();
}


#endif

/* Handle:   12,Name:                  TargetSlot_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Cx(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Cx();
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Cx_0 = ((vuint8) sigData);
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Cx_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Cx);
  IlLeaveCriticalTargetSlot_Cx();
}


#endif

/* Handle:   13,Name:                  TargetSlot_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Cy(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Cy();
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Cy_0 = ((vuint8) sigData);
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Cy_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Cy);
  IlLeaveCriticalTargetSlot_Cy();
}


#endif

/* Handle:   14,Name:                  TargetSlot_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Dx(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Dx();
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Dx_0 = ((vuint8) sigData);
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Dx_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Dx);
  IlLeaveCriticalTargetSlot_Dx();
}


#endif

/* Handle:   15,Name:                  TargetSlot_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Dy(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Dy();
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Dy_0 = ((vuint8) sigData);
  TargetSlot_CD.TargetSlot_CD.TargetSlot_Dy_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Dy);
  IlLeaveCriticalTargetSlot_Dy();
}


#endif

/* Handle:   16,Name:                  TargetSlot_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Ax(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Ax();
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Ax_0 = ((vuint8) sigData);
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Ax_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Ax);
  IlLeaveCriticalTargetSlot_Ax();
}


#endif

/* Handle:   17,Name:                  TargetSlot_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Ay(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Ay();
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Ay_0 = ((vuint8) sigData);
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Ay_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Ay);
  IlLeaveCriticalTargetSlot_Ay();
}


#endif

/* Handle:   18,Name:                  TargetSlot_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_Bx(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_Bx();
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Bx_0 = ((vuint8) sigData);
  TargetSlot_AB.TargetSlot_AB.TargetSlot_Bx_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_Bx);
  IlLeaveCriticalTargetSlot_Bx();
}


#endif

/* Handle:   19,Name:                  TargetSlot_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTargetSlot_By(vuint16 sigData)
{
  IlEnterCriticalTargetSlot_By();
  TargetSlot_AB.TargetSlot_AB.TargetSlot_By_0 = ((vuint8) sigData);
  TargetSlot_AB.TargetSlot_AB.TargetSlot_By_1 = ((vuint8) (sigData >> 8));
  IlSetEvent(IlTxSigHndTargetSlot_By);
  IlLeaveCriticalTargetSlot_By();
}


#endif

/* Handle:   20,Name:                  USS_SLOT_R_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Cx(vuint16 sigData)
{
  if(USS_SLOT_R_CxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Cx();
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_0 = ((vuint8) sigData);
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Cx);
    IlLeaveCriticalUSS_SLOT_R_Cx();
  }
}


#endif

/* Handle:   21,Name:                  USS_SLOT_R_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Cy(vuint16 sigData)
{
  if(USS_SLOT_R_CyValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Cy();
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_0 = ((vuint8) sigData);
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Cy_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Cy);
    IlLeaveCriticalUSS_SLOT_R_Cy();
  }
}


#endif

/* Handle:   22,Name:                  USS_SLOT_R_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Dx(vuint16 sigData)
{
  if(USS_SLOT_R_DxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Dx();
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_0 = ((vuint8) sigData);
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Dx);
    IlLeaveCriticalUSS_SLOT_R_Dx();
  }
}


#endif

/* Handle:   23,Name:                  USS_SLOT_R_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Dy(vuint16 sigData)
{
  if(USS_SLOT_R_DyValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Dy();
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_0 = ((vuint8) sigData);
    USS_SLOT_R_CD.USS_SLOT_R_CD.USS_SLOT_R_Dy_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Dy);
    IlLeaveCriticalUSS_SLOT_R_Dy();
  }
}


#endif

/* Handle:   24,Name:                  USS_SLOT_R_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Ax(vuint16 sigData)
{
  if(USS_SLOT_R_AxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Ax();
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_0 = ((vuint8) sigData);
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ax_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Ax);
    IlLeaveCriticalUSS_SLOT_R_Ax();
  }
}


#endif

/* Handle:   25,Name:                  USS_SLOT_R_Ay,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Ay(vuint16 sigData)
{
  if(USS_SLOT_R_AyValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Ay();
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_0 = ((vuint8) sigData);
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Ay_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Ay);
    IlLeaveCriticalUSS_SLOT_R_Ay();
  }
}


#endif

/* Handle:   26,Name:                  USS_SLOT_R_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_Bx(vuint16 sigData)
{
  if(USS_SLOT_R_BxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_Bx();
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_0 = ((vuint8) sigData);
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_Bx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_Bx);
    IlLeaveCriticalUSS_SLOT_R_Bx();
  }
}


#endif

/* Handle:   27,Name:                  USS_SLOT_R_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_By(vuint16 sigData)
{
  if(USS_SLOT_R_ByValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_By();
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_0 = ((vuint8) sigData);
    USS_SLOT_R_AB.USS_SLOT_R_AB.USS_SLOT_R_By_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_By);
    IlLeaveCriticalUSS_SLOT_R_By();
  }
}


#endif

/* Handle:   28,Name:                  USS_SLOT_L_Cx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Cx(vuint16 sigData)
{
  if(USS_SLOT_L_CxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Cx();
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_0 = ((vuint8) sigData);
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Cx);
    IlLeaveCriticalUSS_SLOT_L_Cx();
  }
}


#endif

/* Handle:   29,Name:                  USS_SLOT_L_Cy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Cy(vuint16 sigData)
{
  if(USS_SLOT_L_CyValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Cy();
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_0 = ((vuint8) sigData);
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Cy_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Cy);
    IlLeaveCriticalUSS_SLOT_L_Cy();
  }
}


#endif

/* Handle:   30,Name:                  USS_SLOT_L_Dx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Dx(vuint16 sigData)
{
  if(USS_SLOT_L_DxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Dx();
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_0 = ((vuint8) sigData);
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Dx);
    IlLeaveCriticalUSS_SLOT_L_Dx();
  }
}


#endif

/* Handle:   31,Name:                  USS_SLOT_L_Dy,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Dy(vuint16 sigData)
{
  if(USS_SLOT_L_DyValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Dy();
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_0 = ((vuint8) sigData);
    USS_SLOT_L_CD.USS_SLOT_L_CD.USS_SLOT_L_Dy_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Dy);
    IlLeaveCriticalUSS_SLOT_L_Dy();
  }
}


#endif

/* Handle:   32,Name:                  USS_SLOT_L_Ax,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Ax(vuint16 sigData)
{
  if(USS_SLOT_L_AxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Ax();
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_0 = ((vuint8) sigData);
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Ax_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Ax);
    IlLeaveCriticalUSS_SLOT_L_Ax();
  }
}


#endif

/* Handle:   33,Name:                  USS_SLOT_L_AY,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_AY(vuint16 sigData)
{
  if(USS_SLOT_L_AYValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_AY();
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_0 = ((vuint8) sigData);
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_AY_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_AY);
    IlLeaveCriticalUSS_SLOT_L_AY();
  }
}


#endif

/* Handle:   34,Name:                  USS_SLOT_L_Bx,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_Bx(vuint16 sigData)
{
  if(USS_SLOT_L_BxValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_Bx();
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_0 = ((vuint8) sigData);
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_Bx_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_Bx);
    IlLeaveCriticalUSS_SLOT_L_Bx();
  }
}


#endif

/* Handle:   35,Name:                  USS_SLOT_L_By,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_By(vuint16 sigData)
{
  if(USS_SLOT_L_ByValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_By();
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_0 = ((vuint8) sigData);
    USS_SLOT_L_AB.USS_SLOT_L_AB.USS_SLOT_L_By_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_By);
    IlLeaveCriticalUSS_SLOT_L_By();
  }
}


#endif

/* Handle:   36,Name:                     USS_DE_FLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FLS(vuint16 sigData)
{
  if(USS_DE_FLSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FLS();
    USS_DE_S.USS_DE_S.USS_DE_FLS_0 = ((vuint8) sigData);
    USS_DE_S.USS_DE_S.USS_DE_FLS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_FLS);
    IlLeaveCriticalUSS_DE_FLS();
  }
}


#endif

/* Handle:   37,Name:                     USS_DE_FRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FRS(vuint16 sigData)
{
  if(USS_DE_FRSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FRS();
    USS_DE_S.USS_DE_S.USS_DE_FRS_0 = ((vuint8) sigData);
    USS_DE_S.USS_DE_S.USS_DE_FRS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_FRS);
    IlLeaveCriticalUSS_DE_FRS();
  }
}


#endif

/* Handle:   38,Name:                     USS_DE_RLS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RLS(vuint16 sigData)
{
  if(USS_DE_RLSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RLS();
    USS_DE_S.USS_DE_S.USS_DE_RLS_0 = ((vuint8) sigData);
    USS_DE_S.USS_DE_S.USS_DE_RLS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_RLS);
    IlLeaveCriticalUSS_DE_RLS();
  }
}


#endif

/* Handle:   39,Name:                     USS_DE_RRS,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RRS(vuint16 sigData)
{
  if(USS_DE_RRSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RRS();
    USS_DE_S.USS_DE_S.USS_DE_RRS_0 = ((vuint8) sigData);
    USS_DE_S.USS_DE_S.USS_DE_RRS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_RRS);
    IlLeaveCriticalUSS_DE_RRS();
  }
}


#endif

/* Handle:   40,Name:                      USS_DE_RL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RL(vuint16 sigData)
{
  if(USS_DE_RLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RL();
    USS_DE_R.USS_DE_R.USS_DE_RL_0 = ((vuint8) sigData);
    USS_DE_R.USS_DE_R.USS_DE_RL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_RL);
    IlLeaveCriticalUSS_DE_RL();
  }
}


#endif

/* Handle:   41,Name:                     USS_DE_RML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RML(vuint16 sigData)
{
  if(USS_DE_RMLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RML();
    USS_DE_R.USS_DE_R.USS_DE_RML_0 = ((vuint8) (sigData & (vuint8) 0x07));
    USS_DE_R.USS_DE_R.USS_DE_RML_1 = ((vuint8) (sigData >> 3));
    USS_DE_R.USS_DE_R.USS_DE_RML_2 = ((vuint8) ((sigData >> 11) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DE_RML);
    IlLeaveCriticalUSS_DE_RML();
  }
}


#endif

/* Handle:   42,Name:                     USS_DE_RMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RMR(vuint16 sigData)
{
  if(USS_DE_RMRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RMR();
    USS_DE_R.USS_DE_R.USS_DE_RMR_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DE_R.USS_DE_R.USS_DE_RMR_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x7F));
    IlSetEvent(IlTxSigHndUSS_DE_RMR);
    IlLeaveCriticalUSS_DE_RMR();
  }
}


#endif

/* Handle:   43,Name:                      USS_DE_RR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_RR(vuint16 sigData)
{
  if(USS_DE_RRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_RR();
    USS_DE_R.USS_DE_R.USS_DE_RR_0 = ((vuint8) (sigData & (vuint8) 0x01));
    USS_DE_R.USS_DE_R.USS_DE_RR_1 = ((vuint8) (sigData >> 1));
    USS_DE_R.USS_DE_R.USS_DE_RR_2 = ((vuint8) ((sigData >> 9) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DE_RR);
    IlLeaveCriticalUSS_DE_RR();
  }
}


#endif

/* Handle:   44,Name:                      USS_DE_FL,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FL(vuint16 sigData)
{
  if(USS_DE_FLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FL();
    USS_DE_F.USS_DE_F.USS_DE_FL_0 = ((vuint8) sigData);
    USS_DE_F.USS_DE_F.USS_DE_FL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
    IlSetEvent(IlTxSigHndUSS_DE_FL);
    IlLeaveCriticalUSS_DE_FL();
  }
}


#endif

/* Handle:   45,Name:                     USS_DE_FML,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FML(vuint16 sigData)
{
  if(USS_DE_FMLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FML();
    USS_DE_F.USS_DE_F.USS_DE_FML_0 = ((vuint8) (sigData & (vuint8) 0x07));
    USS_DE_F.USS_DE_F.USS_DE_FML_1 = ((vuint8) (sigData >> 3));
    USS_DE_F.USS_DE_F.USS_DE_FML_2 = ((vuint8) ((sigData >> 11) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DE_FML);
    IlLeaveCriticalUSS_DE_FML();
  }
}


#endif

/* Handle:   46,Name:                     USS_DE_FMR,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FMR(vuint16 sigData)
{
  if(USS_DE_FMRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FMR();
    USS_DE_F.USS_DE_F.USS_DE_FMR_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DE_F.USS_DE_F.USS_DE_FMR_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x7F));
    IlSetEvent(IlTxSigHndUSS_DE_FMR);
    IlLeaveCriticalUSS_DE_FMR();
  }
}


#endif

/* Handle:   47,Name:                      USS_DE_FR,Size: 13,UsedBytes:  3,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DE_FR(vuint16 sigData)
{
  if(USS_DE_FRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DE_FR();
    USS_DE_F.USS_DE_F.USS_DE_FR_0 = ((vuint8) (sigData & (vuint8) 0x01));
    USS_DE_F.USS_DE_F.USS_DE_FR_1 = ((vuint8) (sigData >> 1));
    USS_DE_F.USS_DE_F.USS_DE_FR_2 = ((vuint8) ((sigData >> 9) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DE_FR);
    IlLeaveCriticalUSS_DE_FR();
  }
}


#endif

/* Handle:   48,Name:                    USS_DIAG_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RL(vuint16 sigData)
{
  if(USS_DIAG_RLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RL();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_0 = ((vuint8) sigData);
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DIAG_RL);
    IlLeaveCriticalUSS_DIAG_RL();
  }
}


#endif

/* Handle:   49,Name:                   USS_DIAG_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RLS(vuint16 sigData)
{
  if(USS_DIAG_RLSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RLS();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RLS_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DIAG_RLS);
    IlLeaveCriticalUSS_DIAG_RLS();
  }
}


#endif

/* Handle:   50,Name:                   USS_DIAG_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RML(vuint16 sigData)
{
  if(USS_DIAG_RMLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RML();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_0 = ((vuint8) (sigData & (vuint8) 0x0F));
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RML_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x3F));
    IlSetEvent(IlTxSigHndUSS_DIAG_RML);
    IlLeaveCriticalUSS_DIAG_RML();
  }
}


#endif

/* Handle:   51,Name:                   USS_DIAG_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RMR(vuint16 sigData)
{
  if(USS_DIAG_RMRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RMR();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_0 = ((vuint8) (sigData & (vuint8) 0x03));
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RMR_1 = ((vuint8) (sigData >> 2));
    IlSetEvent(IlTxSigHndUSS_DIAG_RMR);
    IlLeaveCriticalUSS_DIAG_RMR();
  }
}


#endif

/* Handle:   52,Name:                    USS_DIAG_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RR(vuint16 sigData)
{
  if(USS_DIAG_RRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RR();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_0 = ((vuint8) sigData);
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RR_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DIAG_RR);
    IlLeaveCriticalUSS_DIAG_RR();
  }
}


#endif

/* Handle:   53,Name:                   USS_DIAG_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_RRS(vuint16 sigData)
{
  if(USS_DIAG_RRSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_RRS();
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DIAG_R.USS_DIAG_R.USS_DIAG_RRS_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DIAG_RRS);
    IlLeaveCriticalUSS_DIAG_RRS();
  }
}


#endif

/* Handle:   54,Name:                    USS_DIAG_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FL(vuint16 sigData)
{
  if(USS_DIAG_FLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FL();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_0 = ((vuint8) sigData);
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DIAG_FL);
    IlLeaveCriticalUSS_DIAG_FL();
  }
}


#endif

/* Handle:   55,Name:                   USS_DIAG_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FLS(vuint16 sigData)
{
  if(USS_DIAG_FLSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FLS();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FLS_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DIAG_FLS);
    IlLeaveCriticalUSS_DIAG_FLS();
  }
}


#endif

/* Handle:   56,Name:                   USS_DIAG_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FML(vuint16 sigData)
{
  if(USS_DIAG_FMLValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FML();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_0 = ((vuint8) (sigData & (vuint8) 0x0F));
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FML_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x3F));
    IlSetEvent(IlTxSigHndUSS_DIAG_FML);
    IlLeaveCriticalUSS_DIAG_FML();
  }
}


#endif

/* Handle:   57,Name:                   USS_DIAG_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FMR(vuint16 sigData)
{
  if(USS_DIAG_FMRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FMR();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_0 = ((vuint8) (sigData & (vuint8) 0x03));
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FMR_1 = ((vuint8) (sigData >> 2));
    IlSetEvent(IlTxSigHndUSS_DIAG_FMR);
    IlLeaveCriticalUSS_DIAG_FMR();
  }
}


#endif

/* Handle:   58,Name:                    USS_DIAG_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FR(vuint16 sigData)
{
  if(USS_DIAG_FRValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FR();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_0 = ((vuint8) sigData);
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FR_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndUSS_DIAG_FR);
    IlLeaveCriticalUSS_DIAG_FR();
  }
}


#endif

/* Handle:   59,Name:                   USS_DIAG_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_DIAG_FRS(vuint16 sigData)
{
  if(USS_DIAG_FRSValueChanged(sigData))
  {
    IlEnterCriticalUSS_DIAG_FRS();
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_0 = ((vuint8) (sigData & (vuint8) 0x3F));
    USS_DIAG_F.USS_DIAG_F.USS_DIAG_FRS_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndUSS_DIAG_FRS);
    IlLeaveCriticalUSS_DIAG_FRS();
  }
}


#endif

/* Handle:   60,Name:                  USS_WORK_MODE,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_WORK_MODE(vuint8 sigData)
{
  if(USS_WORK_MODEValueChanged(sigData))
  {
    IlEnterCriticalUSS_WORK_MODE();
    USS_DIAG_F.USS_DIAG_F.USS_WORK_MODE = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndUSS_WORK_MODE);
    IlLeaveCriticalUSS_WORK_MODE();
  }
}


#endif

/* Handle:   61,Name:                         DR_RAW,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDR_RAW(vuint32 sigData)
{
  IlEnterCriticalDR_RAW();
  DR_2.DR_2.DR_RAW_0 = ((vuint8) sigData);
  DR_2.DR_2.DR_RAW_1 = ((vuint8) (sigData >> 8));
  DR_2.DR_2.DR_RAW_2 = ((vuint8) (sigData >> 16));
  DR_2.DR_2.DR_RAW_3 = ((vuint8) (sigData >> 24));
  IlSetEvent(IlTxSigHndDR_RAW);
  IlLeaveCriticalDR_RAW();
}


#endif

/* Handle:   62,Name:               USS_SLOT_L_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_L_DEPTH(vuint16 sigData)
{
  if(USS_SLOT_L_DEPTHValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_L_DEPTH();
    DR_2.DR_2.USS_SLOT_L_DEPTH_0 = ((vuint8) sigData);
    DR_2.DR_2.USS_SLOT_L_DEPTH_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_L_DEPTH);
    IlLeaveCriticalUSS_SLOT_L_DEPTH();
  }
}


#endif

/* Handle:   63,Name:               USS_SLOT_R_DEPTH,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxUSS_SLOT_R_DEPTH(vuint16 sigData)
{
  if(USS_SLOT_R_DEPTHValueChanged(sigData))
  {
    IlEnterCriticalUSS_SLOT_R_DEPTH();
    DR_2.DR_2.USS_SLOT_R_DEPTH_0 = ((vuint8) sigData);
    DR_2.DR_2.USS_SLOT_R_DEPTH_1 = ((vuint8) (sigData >> 8));
    IlSetEvent(IlTxSigHndUSS_SLOT_R_DEPTH);
    IlLeaveCriticalUSS_SLOT_R_DEPTH();
  }
}


#endif

/* Handle:   64,Name:                           DR_X,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDR_X(vuint32 sigData)
{
  IlEnterCriticalDR_X();
  DR_1.DR_1.DR_X_0 = ((vuint8) sigData);
  DR_1.DR_1.DR_X_1 = ((vuint8) (sigData >> 8));
  DR_1.DR_1.DR_X_2 = ((vuint8) (sigData >> 16));
  DR_1.DR_1.DR_X_3 = ((vuint8) (sigData >> 24));
  IlSetEvent(IlTxSigHndDR_X);
  IlLeaveCriticalDR_X();
}


#endif

/* Handle:   65,Name:                           DR_Y,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDR_Y(vuint32 sigData)
{
  IlEnterCriticalDR_Y();
  DR_1.DR_1.DR_Y_0 = ((vuint8) sigData);
  DR_1.DR_1.DR_Y_1 = ((vuint8) (sigData >> 8));
  DR_1.DR_1.DR_Y_2 = ((vuint8) (sigData >> 16));
  DR_1.DR_1.DR_Y_3 = ((vuint8) (sigData >> 24));
  IlSetEvent(IlTxSigHndDR_Y);
  IlLeaveCriticalDR_Y();
}


#endif

/* Handle:   86,Name:         ParkingSlotDegree_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxParkingSlotDegree_Left(vuint16 sigData)
{
  IlEnterCriticalParkingSlotDegree_Left();
  PDC_2.PDC_2.ParkingSlotDegree_Left_0 = ((vuint8) sigData);
  PDC_2.PDC_2.ParkingSlotDegree_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x0F));
  IlLeaveCriticalParkingSlotDegree_Left();
}


#endif

/* Handle:   87,Name:        ParkingSlotDegree_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxParkingSlotDegree_Right(vuint16 sigData)
{
  IlEnterCriticalParkingSlotDegree_Right();
  PDC_2.PDC_2.ParkingSlotDegree_Right_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_2.PDC_2.ParkingSlotDegree_Right_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalParkingSlotDegree_Right();
}


#endif

/* Handle:   88,Name:                      SysSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSysSt_PDC(vuint8 sigData)
{
  if(SysSt_PDCValueChanged(sigData))
  {
    IlEnterCriticalSysSt_PDC();
    PDC_1.PDC_1.SysSt_PDC = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSysSt_PDC);
    IlLeaveCriticalSysSt_PDC();
  }
}


#endif

/* Handle:   89,Name:                    ErrorSt_PDC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxErrorSt_PDC(vuint8 sigData)
{
  if(ErrorSt_PDCValueChanged(sigData))
  {
    IlEnterCriticalErrorSt_PDC();
    PDC_1.PDC_1.ErrorSt_PDC = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndErrorSt_PDC);
    IlLeaveCriticalErrorSt_PDC();
  }
}


#endif

/* Handle:   90,Name:               RadarSysSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRadarSysSt_Front(vuint8 sigData)
{
  if(RadarSysSt_FrontValueChanged(sigData))
  {
    IlEnterCriticalRadarSysSt_Front();
    PDC_1.PDC_1.RadarSysSt_Front = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndRadarSysSt_Front);
    IlLeaveCriticalRadarSysSt_Front();
  }
}


#endif

/* Handle:   91,Name:                RadarSysSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRadarSysSt_Rear(vuint8 sigData)
{
  if(RadarSysSt_RearValueChanged(sigData))
  {
    IlEnterCriticalRadarSysSt_Rear();
    PDC_1.PDC_1.RadarSysSt_Rear = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndRadarSysSt_Rear);
    IlLeaveCriticalRadarSysSt_Rear();
  }
}


#endif

/* Handle:   92,Name:                  BuzeerCmd_PDC,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxBuzeerCmd_PDC(vuint8 sigData)
{
  if(BuzeerCmd_PDCValueChanged(sigData))
  {
    IlEnterCriticalBuzeerCmd_PDC();
    PDC_1.PDC_1.BuzeerCmd_PDC = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndBuzeerCmd_PDC);
    IlLeaveCriticalBuzeerCmd_PDC();
  }
}


#endif

/* Handle:   97,Name:                 ObjectRange_RR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_RR(vuint8 sigData)
{
  if(ObjectRange_RRValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_RR();
    PDC_1.PDC_1.ObjectRange_RR = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_RR);
    IlLeaveCriticalObjectRange_RR();
  }
}


#endif

/* Handle:   98,Name:               SensorErrorSt_RR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_RR(vuint8 sigData)
{
  if(SensorErrorSt_RRValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_RR();
    PDC_1.PDC_1.SensorErrorSt_RR = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_RR);
    IlLeaveCriticalSensorErrorSt_RR();
  }
}


#endif

/* Handle:   99,Name:                ObjectRange_RMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_RMR(vuint8 sigData)
{
  if(ObjectRange_RMRValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_RMR();
    PDC_1.PDC_1.ObjectRange_RMR = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_RMR);
    IlLeaveCriticalObjectRange_RMR();
  }
}


#endif

/* Handle:  100,Name:              SensorErrorSt_RMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_RMR(vuint8 sigData)
{
  if(SensorErrorSt_RMRValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_RMR();
    PDC_1.PDC_1.SensorErrorSt_RMR = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_RMR);
    IlLeaveCriticalSensorErrorSt_RMR();
  }
}


#endif

/* Handle:  101,Name:                ObjectRange_RML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_RML(vuint8 sigData)
{
  if(ObjectRange_RMLValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_RML();
    PDC_1.PDC_1.ObjectRange_RML = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_RML);
    IlLeaveCriticalObjectRange_RML();
  }
}


#endif

/* Handle:  102,Name:              SensorErrorSt_RML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_RML(vuint8 sigData)
{
  if(SensorErrorSt_RMLValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_RML();
    PDC_1.PDC_1.SensorErrorSt_RML = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_RML);
    IlLeaveCriticalSensorErrorSt_RML();
  }
}


#endif

/* Handle:  103,Name:                 ObjectRange_RL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_RL(vuint8 sigData)
{
  if(ObjectRange_RLValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_RL();
    PDC_1.PDC_1.ObjectRange_RL = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_RL);
    IlLeaveCriticalObjectRange_RL();
  }
}


#endif

/* Handle:  104,Name:               SensorErrorSt_RL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_RL(vuint8 sigData)
{
  if(SensorErrorSt_RLValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_RL();
    PDC_1.PDC_1.SensorErrorSt_RL = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_RL);
    IlLeaveCriticalSensorErrorSt_RL();
  }
}


#endif

/* Handle:  105,Name:                 ObjectRange_FR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_FR(vuint8 sigData)
{
  if(ObjectRange_FRValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_FR();
    PDC_1.PDC_1.ObjectRange_FR = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_FR);
    IlLeaveCriticalObjectRange_FR();
  }
}


#endif

/* Handle:  106,Name:               SensorErrorSt_FR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_FR(vuint8 sigData)
{
  if(SensorErrorSt_FRValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_FR();
    PDC_1.PDC_1.SensorErrorSt_FR = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_FR);
    IlLeaveCriticalSensorErrorSt_FR();
  }
}


#endif

/* Handle:  107,Name:                ObjectRange_FMR,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_FMR(vuint8 sigData)
{
  if(ObjectRange_FMRValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_FMR();
    PDC_1.PDC_1.ObjectRange_FMR = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_FMR);
    IlLeaveCriticalObjectRange_FMR();
  }
}


#endif

/* Handle:  108,Name:              SensorErrorSt_FMR,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_FMR(vuint8 sigData)
{
  if(SensorErrorSt_FMRValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_FMR();
    PDC_1.PDC_1.SensorErrorSt_FMR = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_FMR);
    IlLeaveCriticalSensorErrorSt_FMR();
  }
}


#endif

/* Handle:  109,Name:                ObjectRange_FML,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_FML(vuint8 sigData)
{
  if(ObjectRange_FMLValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_FML();
    PDC_1.PDC_1.ObjectRange_FML = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_FML);
    IlLeaveCriticalObjectRange_FML();
  }
}


#endif

/* Handle:  110,Name:              SensorErrorSt_FML,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_FML(vuint8 sigData)
{
  if(SensorErrorSt_FMLValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_FML();
    PDC_1.PDC_1.SensorErrorSt_FML = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_FML);
    IlLeaveCriticalSensorErrorSt_FML();
  }
}


#endif

/* Handle:  111,Name:                 ObjectRange_FL,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxObjectRange_FL(vuint8 sigData)
{
  if(ObjectRange_FLValueChanged(sigData))
  {
    IlEnterCriticalObjectRange_FL();
    PDC_1.PDC_1.ObjectRange_FL = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndObjectRange_FL);
    IlLeaveCriticalObjectRange_FL();
  }
}


#endif

/* Handle:  112,Name:               SensorErrorSt_FL,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSensorErrorSt_FL(vuint8 sigData)
{
  if(SensorErrorSt_FLValueChanged(sigData))
  {
    IlEnterCriticalSensorErrorSt_FL();
    PDC_1.PDC_1.SensorErrorSt_FL = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndSensorErrorSt_FL);
    IlLeaveCriticalSensorErrorSt_FL();
  }
}


#endif

/* Handle:  118,Name:                          AVSSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSSt(vuint8 sigData)
{
  if(AVSStValueChanged(sigData))
  {
    IlEnterCriticalAVSSt();
    AVS_1.AVS_1.AVSSt = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSSt);
    IlLeaveCriticalAVSSt();
  }
}


#endif

/* Handle:  119,Name:                     AVSErrorSt,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSErrorSt(vuint8 sigData)
{
  if(AVSErrorStValueChanged(sigData))
  {
    IlEnterCriticalAVSErrorSt();
    AVS_1.AVS_1.AVSErrorSt = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSErrorSt);
    IlLeaveCriticalAVSErrorSt();
  }
}


#endif

/* Handle:  120,Name:                    AVSViewMode,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSViewMode(vuint8 sigData)
{
  if(AVSViewModeValueChanged(sigData))
  {
    IlEnterCriticalAVSViewMode();
    AVS_1.AVS_1.AVSViewMode = ((vuint8) (sigData & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndAVSViewMode);
    IlLeaveCriticalAVSViewMode();
  }
}


#endif

/* Handle:  122,Name:         AVSCameraErrorSt_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSCameraErrorSt_Front(vuint8 sigData)
{
  if(AVSCameraErrorSt_FrontValueChanged(sigData))
  {
    IlEnterCriticalAVSCameraErrorSt_Front();
    AVS_1.AVS_1.AVSCameraErrorSt_Front = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSCameraErrorSt_Front);
    IlLeaveCriticalAVSCameraErrorSt_Front();
  }
}


#endif

/* Handle:  123,Name:          AVSCameraErrorSt_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSCameraErrorSt_Rear(vuint8 sigData)
{
  if(AVSCameraErrorSt_RearValueChanged(sigData))
  {
    IlEnterCriticalAVSCameraErrorSt_Rear();
    AVS_1.AVS_1.AVSCameraErrorSt_Rear = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSCameraErrorSt_Rear);
    IlLeaveCriticalAVSCameraErrorSt_Rear();
  }
}


#endif

/* Handle:  124,Name:          AVSCameraErrorSt_Left,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSCameraErrorSt_Left(vuint8 sigData)
{
  if(AVSCameraErrorSt_LeftValueChanged(sigData))
  {
    IlEnterCriticalAVSCameraErrorSt_Left();
    AVS_1.AVS_1.AVSCameraErrorSt_Left = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSCameraErrorSt_Left);
    IlLeaveCriticalAVSCameraErrorSt_Left();
  }
}


#endif

/* Handle:  125,Name:         AVSCameraErrorSt_Right,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAVSCameraErrorSt_Right(vuint8 sigData)
{
  if(AVSCameraErrorSt_RightValueChanged(sigData))
  {
    IlEnterCriticalAVSCameraErrorSt_Right();
    AVS_1.AVS_1.AVSCameraErrorSt_Right = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndAVSCameraErrorSt_Right);
    IlLeaveCriticalAVSCameraErrorSt_Right();
  }
}


#endif

/* Handle:  126,Name:             LanguageTypeSt_AVS,Size:  4,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLanguageTypeSt_AVS(vuint8 sigData)
{
  if(LanguageTypeSt_AVSValueChanged(sigData))
  {
    IlEnterCriticalLanguageTypeSt_AVS();
    AVS_1.AVS_1.LanguageTypeSt_AVS = ((vuint8) (sigData & (vuint8) 0x0F));
    IlSetEvent(IlTxSigHndLanguageTypeSt_AVS);
    IlLeaveCriticalLanguageTypeSt_AVS();
  }
}


#endif

/* Handle:  127,Name:               DynamicPGSSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDynamicPGSSt_AVS(vuint8 sigData)
{
  if(DynamicPGSSt_AVSValueChanged(sigData))
  {
    IlEnterCriticalDynamicPGSSt_AVS();
    AVS_1.AVS_1.DynamicPGSSt_AVS = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndDynamicPGSSt_AVS);
    IlLeaveCriticalDynamicPGSSt_AVS();
  }
}


#endif

/* Handle:  128,Name:                      MODSt_AVS,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxMODSt_AVS(vuint8 sigData)
{
  if(MODSt_AVSValueChanged(sigData))
  {
    IlEnterCriticalMODSt_AVS();
    AVS_1.AVS_1.MODSt_AVS = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndMODSt_AVS);
    IlLeaveCriticalMODSt_AVS();
  }
}


#endif

/* Handle:  129,Name:               MODWarning_Front,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxMODWarning_Front(vuint8 sigData)
{
  if(MODWarning_FrontValueChanged(sigData))
  {
    IlEnterCriticalMODWarning_Front();
    AVS_1.AVS_1.MODWarning_Front = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndMODWarning_Front);
    IlLeaveCriticalMODWarning_Front();
  }
}


#endif

/* Handle:  130,Name:                MODWarning_Rear,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxMODWarning_Rear(vuint8 sigData)
{
  if(MODWarning_RearValueChanged(sigData))
  {
    IlEnterCriticalMODWarning_Rear();
    AVS_1.AVS_1.MODWarning_Rear = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndMODWarning_Rear);
    IlLeaveCriticalMODWarning_Rear();
  }
}


#endif

/* Handle:  132,Name:        SwitchScreenRequest_AVS,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSwitchScreenRequest_AVS(vuint8 sigData)
{
  if(SwitchScreenRequest_AVSValueChanged(sigData))
  {
    IlEnterCriticalSwitchScreenRequest_AVS();
    AVS_1.AVS_1.SwitchScreenRequest_AVS = ((vuint8) (sigData & (vuint8) 0x03));
    IlSetEvent(IlTxSigHndSwitchScreenRequest_AVS);
    IlLeaveCriticalSwitchScreenRequest_AVS();
  }
}


#endif

/* Handle:  152,Name:             VehicleCoordinateX,Size: 13,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxVehicleCoordinateX(vuint16 sigData)
{
  IlEnterCriticalVehicleCoordinateX();
  PDC_14.PDC_14.VehicleCoordinateX_0 = ((vuint8) sigData);
  PDC_14.PDC_14.VehicleCoordinateX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x1F));
  IlLeaveCriticalVehicleCoordinateX();
}


#endif

/* Handle:  153,Name:             VehicleCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxVehicleCoordinateY(vuint16 sigData)
{
  IlEnterCriticalVehicleCoordinateY();
  PDC_14.PDC_14.VehicleCoordinateY_0 = ((vuint8) sigData);
  PDC_14.PDC_14.VehicleCoordinateY_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x0F));
  IlLeaveCriticalVehicleCoordinateY();
}


#endif

/* Handle:  157,Name:             CCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCCoordinateY_Right(vuint16 sigData)
{
  IlEnterCriticalCCoordinateY_Right();
  PDC_13.PDC_13.CCoordinateY_Right_0 = ((vuint8) sigData);
  PDC_13.PDC_13.CCoordinateY_Right_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalCCoordinateY_Right();
}


#endif

/* Handle:  158,Name:             CCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCCoordinateX_Right(vuint16 sigData)
{
  IlEnterCriticalCCoordinateX_Right();
  PDC_13.PDC_13.CCoordinateX_Right_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_13.PDC_13.CCoordinateX_Right_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalCCoordinateX_Right();
}


#endif

/* Handle:  159,Name:             DCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDCoordinateY_Right(vuint16 sigData)
{
  IlEnterCriticalDCoordinateY_Right();
  PDC_13.PDC_13.DCoordinateY_Right_0 = ((vuint8) sigData);
  PDC_13.PDC_13.DCoordinateY_Right_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDCoordinateY_Right();
}


#endif

/* Handle:  160,Name:             DCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDCoordinateX_Right(vuint16 sigData)
{
  IlEnterCriticalDCoordinateX_Right();
  PDC_13.PDC_13.DCoordinateX_Right_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_13.PDC_13.DCoordinateX_Right_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalDCoordinateX_Right();
}


#endif

/* Handle:  163,Name:             ACoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxACoordinateY_Right(vuint16 sigData)
{
  IlEnterCriticalACoordinateY_Right();
  PDC_12.PDC_12.ACoordinateY_Right_0 = ((vuint8) sigData);
  PDC_12.PDC_12.ACoordinateY_Right_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalACoordinateY_Right();
}


#endif

/* Handle:  164,Name:             ACoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxACoordinateX_Right(vuint16 sigData)
{
  IlEnterCriticalACoordinateX_Right();
  PDC_12.PDC_12.ACoordinateX_Right_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_12.PDC_12.ACoordinateX_Right_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalACoordinateX_Right();
}


#endif

/* Handle:  165,Name:             BCoordinateY_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxBCoordinateY_Right(vuint16 sigData)
{
  IlEnterCriticalBCoordinateY_Right();
  PDC_12.PDC_12.BCoordinateY_Right_0 = ((vuint8) sigData);
  PDC_12.PDC_12.BCoordinateY_Right_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalBCoordinateY_Right();
}


#endif

/* Handle:  166,Name:             BCoordinateX_Right,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxBCoordinateX_Right(vuint16 sigData)
{
  IlEnterCriticalBCoordinateX_Right();
  PDC_12.PDC_12.BCoordinateX_Right_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_12.PDC_12.BCoordinateX_Right_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalBCoordinateX_Right();
}


#endif

/* Handle:  169,Name:              CCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCCoordinateY_Left(vuint16 sigData)
{
  IlEnterCriticalCCoordinateY_Left();
  PDC_11.PDC_11.CCoordinateY_Left_0 = ((vuint8) sigData);
  PDC_11.PDC_11.CCoordinateY_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalCCoordinateY_Left();
}


#endif

/* Handle:  170,Name:              CCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCCoordinateX_Left(vuint16 sigData)
{
  IlEnterCriticalCCoordinateX_Left();
  PDC_11.PDC_11.CCoordinateX_Left_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_11.PDC_11.CCoordinateX_Left_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalCCoordinateX_Left();
}


#endif

/* Handle:  171,Name:              DCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDCoordinateY_Left(vuint16 sigData)
{
  IlEnterCriticalDCoordinateY_Left();
  PDC_11.PDC_11.DCoordinateY_Left_0 = ((vuint8) sigData);
  PDC_11.PDC_11.DCoordinateY_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDCoordinateY_Left();
}


#endif

/* Handle:  172,Name:              DCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDCoordinateX_Left(vuint16 sigData)
{
  IlEnterCriticalDCoordinateX_Left();
  PDC_11.PDC_11.DCoordinateX_Left_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_11.PDC_11.DCoordinateX_Left_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalDCoordinateX_Left();
}


#endif

/* Handle:  175,Name:              DistanceValue_RLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_RLS(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_RLS();
  PDC_10.PDC_10.DistanceValue_RLS_0 = ((vuint8) sigData);
  PDC_10.PDC_10.DistanceValue_RLS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDistanceValue_RLS();
}


#endif

/* Handle:  176,Name:              DistanceValue_RRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_RRS(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_RRS();
  PDC_10.PDC_10.DistanceValue_RRS_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_10.PDC_10.DistanceValue_RRS_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDistanceValue_RRS();
}


#endif

/* Handle:  177,Name:              TimeStamp_RLS_RRS,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_RLS_RRS(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_RLS_RRS();
  PDC_10.PDC_10.TimeStamp_RLS_RRS_0 = ((vuint8) sigData);
  PDC_10.PDC_10.TimeStamp_RLS_RRS_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_RLS_RRS();
}


#endif

/* Handle:  178,Name:         ParkingSlotDepth_Right,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxParkingSlotDepth_Right(vuint16 sigData)
{
  IlEnterCriticalParkingSlotDepth_Right();
  PDC_10.PDC_10.ParkingSlotDepth_Right_0 = ((vuint8) sigData);
  PDC_10.PDC_10.ParkingSlotDepth_Right_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalParkingSlotDepth_Right();
}


#endif

/* Handle:  181,Name:              DistanceValue_FLS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FLS(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FLS();
  PDC_9.PDC_9.DistanceValue_FLS_0 = ((vuint8) sigData);
  PDC_9.PDC_9.DistanceValue_FLS_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDistanceValue_FLS();
}


#endif

/* Handle:  182,Name:              DistanceValue_FRS,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FRS(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FRS();
  PDC_9.PDC_9.DistanceValue_FRS_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_9.PDC_9.DistanceValue_FRS_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDistanceValue_FRS();
}


#endif

/* Handle:  183,Name:              TimeStamp_FLS_FRS,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_FLS_FRS(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_FLS_FRS();
  PDC_9.PDC_9.TimeStamp_FLS_FRS_0 = ((vuint8) sigData);
  PDC_9.PDC_9.TimeStamp_FLS_FRS_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_FLS_FRS();
}


#endif

/* Handle:  184,Name:          ParkingSoltDepth_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxParkingSoltDepth_Left(vuint16 sigData)
{
  IlEnterCriticalParkingSoltDepth_Left();
  PDC_9.PDC_9.ParkingSoltDepth_Left_0 = ((vuint8) sigData);
  PDC_9.PDC_9.ParkingSoltDepth_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalParkingSoltDepth_Left();
}


#endif

/* Handle:  187,Name:               DistanceValue_RR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_RR(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_RR();
  PDC_8.PDC_8.DistanceValue_RR_0 = ((vuint8) sigData);
  PDC_8.PDC_8.DistanceValue_RR_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDistanceValue_RR();
}


#endif

/* Handle:  188,Name:              DistanceValue_RMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_RMR(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_RMR();
  PDC_8.PDC_8.DistanceValue_RMR_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_8.PDC_8.DistanceValue_RMR_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDistanceValue_RMR();
}


#endif

/* Handle:  189,Name:               TimeStamp_RMR_RR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_RMR_RR(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_RMR_RR();
  PDC_8.PDC_8.TimeStamp_RMR_RR_0 = ((vuint8) sigData);
  PDC_8.PDC_8.TimeStamp_RMR_RR_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_RMR_RR();
}


#endif

/* Handle:  194,Name:              DisstanceValue_RL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDisstanceValue_RL(vuint16 sigData)
{
  IlEnterCriticalDisstanceValue_RL();
  PDC_7.PDC_7.DisstanceValue_RL_0 = ((vuint8) sigData);
  PDC_7.PDC_7.DisstanceValue_RL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDisstanceValue_RL();
}


#endif

/* Handle:  195,Name:             DisstanceValue_RML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDisstanceValue_RML(vuint16 sigData)
{
  IlEnterCriticalDisstanceValue_RML();
  PDC_7.PDC_7.DisstanceValue_RML_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_7.PDC_7.DisstanceValue_RML_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDisstanceValue_RML();
}


#endif

/* Handle:  196,Name:               TimeStamp_RML_RL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_RML_RL(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_RML_RL();
  PDC_7.PDC_7.TimeStamp_RML_RL_0 = ((vuint8) sigData);
  PDC_7.PDC_7.TimeStamp_RML_RL_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_RML_RL();
}


#endif

/* Handle:  201,Name:               DistanceValue_FR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FR(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FR();
  PDC_6.PDC_6.DistanceValue_FR_0 = ((vuint8) sigData);
  PDC_6.PDC_6.DistanceValue_FR_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDistanceValue_FR();
}


#endif

/* Handle:  202,Name:              DistanceValue_FMR,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FMR(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FMR();
  PDC_6.PDC_6.DistanceValue_FMR_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_6.PDC_6.DistanceValue_FMR_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDistanceValue_FMR();
}


#endif

/* Handle:  203,Name:               TimeStamp_FMR_FR,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_FMR_FR(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_FMR_FR();
  PDC_6.PDC_6.TimeStamp_FMR_FR_0 = ((vuint8) sigData);
  PDC_6.PDC_6.TimeStamp_FMR_FR_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_FMR_FR();
}


#endif

/* Handle:  208,Name:               DistanceValue_FL,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FL(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FL();
  PDC_5.PDC_5.DistanceValue_FL_0 = ((vuint8) sigData);
  PDC_5.PDC_5.DistanceValue_FL_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalDistanceValue_FL();
}


#endif

/* Handle:  209,Name:              DistanceValue_FML,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDistanceValue_FML(vuint16 sigData)
{
  IlEnterCriticalDistanceValue_FML();
  PDC_5.PDC_5.DistanceValue_FML_0 = ((vuint8) (sigData & (vuint8) 0x03));
  PDC_5.PDC_5.DistanceValue_FML_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalDistanceValue_FML();
}


#endif

/* Handle:  210,Name:               TimeStamp_FML_FL,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxTimeStamp_FML_FL(vuint16 sigData)
{
  IlEnterCriticalTimeStamp_FML_FL();
  PDC_5.PDC_5.TimeStamp_FML_FL_0 = ((vuint8) sigData);
  PDC_5.PDC_5.TimeStamp_FML_FL_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalTimeStamp_FML_FL();
}


#endif

/* Handle:  215,Name:            FrontObjCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFrontObjCoordinateY(vuint16 sigData)
{
  IlEnterCriticalFrontObjCoordinateY();
  PDC_4.PDC_4.FrontObjCoordinateY_0 = ((vuint8) sigData);
  PDC_4.PDC_4.FrontObjCoordinateY_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x0F));
  IlLeaveCriticalFrontObjCoordinateY();
}


#endif

/* Handle:  216,Name:            FrontObjCoordinateX,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFrontObjCoordinateX(vuint16 sigData)
{
  IlEnterCriticalFrontObjCoordinateX();
  PDC_4.PDC_4.FrontObjCoordinateX_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_4.PDC_4.FrontObjCoordinateX_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalFrontObjCoordinateX();
}


#endif

/* Handle:  217,Name:             RearObjCoordinateY,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRearObjCoordinateY(vuint16 sigData)
{
  IlEnterCriticalRearObjCoordinateY();
  PDC_4.PDC_4.RearObjCoordinateY_0 = ((vuint8) sigData);
  PDC_4.PDC_4.RearObjCoordinateY_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x0F));
  IlLeaveCriticalRearObjCoordinateY();
}


#endif

/* Handle:  218,Name:             RearObjCoordinateX,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRearObjCoordinateX(vuint16 sigData)
{
  IlEnterCriticalRearObjCoordinateX();
  PDC_4.PDC_4.RearObjCoordinateX_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_4.PDC_4.RearObjCoordinateX_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalRearObjCoordinateX();
}


#endif

/* Handle:  221,Name:              ACoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxACoordinateY_Left(vuint16 sigData)
{
  IlEnterCriticalACoordinateY_Left();
  PDC_3.PDC_3.ACoordinateY_Left_0 = ((vuint8) sigData);
  PDC_3.PDC_3.ACoordinateY_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalACoordinateY_Left();
}


#endif

/* Handle:  222,Name:              ACoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxACoordinateX_Left(vuint16 sigData)
{
  IlEnterCriticalACoordinateX_Left();
  PDC_3.PDC_3.ACoordinateX_Left_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_3.PDC_3.ACoordinateX_Left_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalACoordinateX_Left();
}


#endif

/* Handle:  223,Name:              BCoordinateY_Left,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxBCoordinateY_Left(vuint16 sigData)
{
  IlEnterCriticalBCoordinateY_Left();
  PDC_3.PDC_3.BCoordinateY_Left_0 = ((vuint8) sigData);
  PDC_3.PDC_3.BCoordinateY_Left_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalBCoordinateY_Left();
}


#endif

/* Handle:  224,Name:              BCoordinateX_Left,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxBCoordinateX_Left(vuint16 sigData)
{
  IlEnterCriticalBCoordinateX_Left();
  PDC_3.PDC_3.BCoordinateX_Left_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  PDC_3.PDC_3.BCoordinateX_Left_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalBCoordinateX_Left();
}


#endif

/* Handle:  226,Name:        APS_Slot6CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6CenterPoint_X1();
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot6CenterPoint_X1();
}


#endif

/* Handle:  227,Name:        APS_Slot6CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6CenterPoint_Y1();
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot6CenterPoint_Y1();
}


#endif

/* Handle:  228,Name:            APS_Slot6_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6_LineAngle();
  APS_Slot6.APS_Slot6.APS_Slot6_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot6.APS_Slot6.APS_Slot6_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot6_LineAngle();
}


#endif

/* Handle:  229,Name:               APS_Slot6_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6_Length();
  APS_Slot6.APS_Slot6.APS_Slot6_Length_0 = ((vuint8) sigData);
  APS_Slot6.APS_Slot6.APS_Slot6_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot6_Length();
}


#endif

/* Handle:  230,Name:                APS_Slot6_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6_Width();
  APS_Slot6.APS_Slot6.APS_Slot6_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot6.APS_Slot6.APS_Slot6_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot6_Width();
}


#endif

/* Handle:  231,Name:     APS_Slot6CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot6CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot6CenterPoint_Angle();
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot6.APS_Slot6.APS_Slot6CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot6CenterPoint_Angle();
}


#endif

/* Handle:  232,Name:        APS_Slot5CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5CenterPoint_X1();
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot5CenterPoint_X1();
}


#endif

/* Handle:  233,Name:        APS_Slot5CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5CenterPoint_Y1();
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot5CenterPoint_Y1();
}


#endif

/* Handle:  234,Name:            APS_Slot5_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5_LineAngle();
  APS_Slot5.APS_Slot5.APS_Slot5_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot5.APS_Slot5.APS_Slot5_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot5_LineAngle();
}


#endif

/* Handle:  235,Name:               APS_Slot5_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5_Length();
  APS_Slot5.APS_Slot5.APS_Slot5_Length_0 = ((vuint8) sigData);
  APS_Slot5.APS_Slot5.APS_Slot5_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot5_Length();
}


#endif

/* Handle:  236,Name:                APS_Slot5_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5_Width();
  APS_Slot5.APS_Slot5.APS_Slot5_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot5.APS_Slot5.APS_Slot5_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot5_Width();
}


#endif

/* Handle:  237,Name:     APS_Slot5CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot5CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot5CenterPoint_Angle();
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot5.APS_Slot5.APS_Slot5CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot5CenterPoint_Angle();
}


#endif

/* Handle:  238,Name:        APS_Slot4CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4CenterPoint_X1();
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot4CenterPoint_X1();
}


#endif

/* Handle:  239,Name:        APS_Slot4CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4CenterPoint_Y1();
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot4CenterPoint_Y1();
}


#endif

/* Handle:  240,Name:            APS_Slot4_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4_LineAngle();
  APS_Slot4.APS_Slot4.APS_Slot4_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot4.APS_Slot4.APS_Slot4_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot4_LineAngle();
}


#endif

/* Handle:  241,Name:               APS_Slot4_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4_Length();
  APS_Slot4.APS_Slot4.APS_Slot4_Length_0 = ((vuint8) sigData);
  APS_Slot4.APS_Slot4.APS_Slot4_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot4_Length();
}


#endif

/* Handle:  242,Name:                APS_Slot4_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4_Width();
  APS_Slot4.APS_Slot4.APS_Slot4_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot4.APS_Slot4.APS_Slot4_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot4_Width();
}


#endif

/* Handle:  243,Name:     APS_Slot4CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot4CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot4CenterPoint_Angle();
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot4.APS_Slot4.APS_Slot4CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot4CenterPoint_Angle();
}


#endif

/* Handle:  244,Name:        APS_Slot3CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3CenterPoint_X1();
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot3CenterPoint_X1();
}


#endif

/* Handle:  245,Name:        APS_Slot3CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3CenterPoint_Y1();
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot3CenterPoint_Y1();
}


#endif

/* Handle:  246,Name:            APS_Slot3_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3_LineAngle();
  APS_Slot3.APS_Slot3.APS_Slot3_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot3.APS_Slot3.APS_Slot3_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot3_LineAngle();
}


#endif

/* Handle:  247,Name:               APS_Slot3_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3_Length();
  APS_Slot3.APS_Slot3.APS_Slot3_Length_0 = ((vuint8) sigData);
  APS_Slot3.APS_Slot3.APS_Slot3_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot3_Length();
}


#endif

/* Handle:  248,Name:                APS_Slot3_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3_Width();
  APS_Slot3.APS_Slot3.APS_Slot3_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot3.APS_Slot3.APS_Slot3_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot3_Width();
}


#endif

/* Handle:  249,Name:     APS_Slot3CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot3CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot3CenterPoint_Angle();
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot3.APS_Slot3.APS_Slot3CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot3CenterPoint_Angle();
}


#endif

/* Handle:  250,Name:        APS_Slot2CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2CenterPoint_X1();
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot2CenterPoint_X1();
}


#endif

/* Handle:  251,Name:        APS_Slot2CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2CenterPoint_Y1();
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot2CenterPoint_Y1();
}


#endif

/* Handle:  252,Name:            APS_Slot2_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2_LineAngle();
  APS_Slot2.APS_Slot2.APS_Slot2_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot2.APS_Slot2.APS_Slot2_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot2_LineAngle();
}


#endif

/* Handle:  253,Name:               APS_Slot2_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2_Length();
  APS_Slot2.APS_Slot2.APS_Slot2_Length_0 = ((vuint8) sigData);
  APS_Slot2.APS_Slot2.APS_Slot2_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot2_Length();
}


#endif

/* Handle:  254,Name:                APS_Slot2_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2_Width();
  APS_Slot2.APS_Slot2.APS_Slot2_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot2.APS_Slot2.APS_Slot2_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot2_Width();
}


#endif

/* Handle:  255,Name:     APS_Slot2CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot2CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot2CenterPoint_Angle();
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot2.APS_Slot2.APS_Slot2CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot2CenterPoint_Angle();
}


#endif

/* Handle:  256,Name:        APS_Slot1CenterPoint_X1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1CenterPoint_X1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1CenterPoint_X1();
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_X1_0 = ((vuint8) sigData);
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_X1_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Slot1CenterPoint_X1();
}


#endif

/* Handle:  257,Name:        APS_Slot1CenterPoint_Y1,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1CenterPoint_Y1(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1CenterPoint_Y1();
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_Y1_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_Y1_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Slot1CenterPoint_Y1();
}


#endif

/* Handle:  258,Name:            APS_Slot1_LineAngle,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1_LineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1_LineAngle();
  APS_Slot1.APS_Slot1.APS_Slot1_LineAngle_0 = ((vuint8) (sigData & (vuint8) 0x03));
  APS_Slot1.APS_Slot1.APS_Slot1_LineAngle_1 = ((vuint8) (sigData >> 2));
  IlLeaveCriticalAPS_Slot1_LineAngle();
}


#endif

/* Handle:  259,Name:               APS_Slot1_Length,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1_Length(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1_Length();
  APS_Slot1.APS_Slot1.APS_Slot1_Length_0 = ((vuint8) sigData);
  APS_Slot1.APS_Slot1.APS_Slot1_Length_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x03));
  IlLeaveCriticalAPS_Slot1_Length();
}


#endif

/* Handle:  260,Name:                APS_Slot1_Width,Size: 10,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1_Width(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1_Width();
  APS_Slot1.APS_Slot1.APS_Slot1_Width_0 = ((vuint8) (sigData & (vuint8) 0x3F));
  APS_Slot1.APS_Slot1.APS_Slot1_Width_1 = ((vuint8) ((sigData >> 6) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Slot1_Width();
}


#endif

/* Handle:  261,Name:     APS_Slot1CenterPoint_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Slot1CenterPoint_Angle(vuint16 sigData)
{
  IlEnterCriticalAPS_Slot1CenterPoint_Angle();
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_Angle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Slot1.APS_Slot1.APS_Slot1CenterPoint_Angle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Slot1CenterPoint_Angle();
}


#endif

/* Handle:  294,Name:   APS_Replan_UpperLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_UpperLineDistance(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_UpperLineDistance();
  APS_Replan_2.APS_Replan_2.APS_Replan_UpperLineDistance_0 = ((vuint8) (sigData & (vuint8) 0x7F));
  APS_Replan_2.APS_Replan_2.APS_Replan_UpperLineDistance_1 = ((vuint8) ((sigData >> 7) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Replan_UpperLineDistance();
}


#endif

/* Handle:  295,Name:      APS_Replan_UpperLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_UpperLineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_UpperLineAngle();
  APS_Replan_2.APS_Replan_2.APS_Replan_UpperLineAngle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Replan_2.APS_Replan_2.APS_Replan_UpperLineAngle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Replan_UpperLineAngle();
}


#endif

/* Handle:  297,Name:    APS_Replan_LeftLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_LeftLineDistance(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_LeftLineDistance();
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftLineDistance_0 = ((vuint8) (sigData & (vuint8) 0x7F));
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftLineDistance_1 = ((vuint8) ((sigData >> 7) & (vuint8) 0x0F));
  IlLeaveCriticalAPS_Replan_LeftLineDistance();
}


#endif

/* Handle:  298,Name:       APS_Replan_LeftLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_LeftLineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_LeftLineAngle();
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftLineAngle_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  APS_Replan_1.APS_Replan_1.APS_Replan_LeftLineAngle_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalAPS_Replan_LeftLineAngle();
}


#endif

/* Handle:  300,Name:   APS_Replan_RightLineDistance,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_RightLineDistance(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_RightLineDistance();
  APS_Replan_1.APS_Replan_1.APS_Replan_RightLineDistance_0 = ((vuint8) sigData);
  APS_Replan_1.APS_Replan_1.APS_Replan_RightLineDistance_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalAPS_Replan_RightLineDistance();
}


#endif

/* Handle:  301,Name:      APS_Replan_RightLineAngle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxAPS_Replan_RightLineAngle(vuint16 sigData)
{
  IlEnterCriticalAPS_Replan_RightLineAngle();
  APS_Replan_1.APS_Replan_1.APS_Replan_RightLineAngle_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  APS_Replan_1.APS_Replan_1.APS_Replan_RightLineAngle_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalAPS_Replan_RightLineAngle();
}


#endif

/* Handle:  305,Name:          RightCurb_StartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRightCurb_StartPointX(vuint16 sigData)
{
  IlEnterCriticalRightCurb_StartPointX();
  RightCurbInfo.RightCurbInfo.RightCurb_StartPointX_0 = ((vuint8) (sigData & (vuint8) 0x7F));
  RightCurbInfo.RightCurbInfo.RightCurb_StartPointX_1 = ((vuint8) ((sigData >> 7) & (vuint8) 0x0F));
  IlLeaveCriticalRightCurb_StartPointX();
}


#endif

/* Handle:  306,Name:          RightCurb_StartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRightCurb_StartPointY(vuint16 sigData)
{
  IlEnterCriticalRightCurb_StartPointY();
  RightCurbInfo.RightCurbInfo.RightCurb_StartPointY_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  RightCurbInfo.RightCurbInfo.RightCurb_StartPointY_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalRightCurb_StartPointY();
}


#endif

/* Handle:  308,Name:            RightCurb_EndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRightCurb_EndPointX(vuint16 sigData)
{
  IlEnterCriticalRightCurb_EndPointX();
  RightCurbInfo.RightCurbInfo.RightCurb_EndPointX_0 = ((vuint8) sigData);
  RightCurbInfo.RightCurbInfo.RightCurb_EndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalRightCurb_EndPointX();
}


#endif

/* Handle:  309,Name:            RightCurb_EndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRightCurb_EndPointY(vuint16 sigData)
{
  IlEnterCriticalRightCurb_EndPointY();
  RightCurbInfo.RightCurbInfo.RightCurb_EndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  RightCurbInfo.RightCurbInfo.RightCurb_EndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalRightCurb_EndPointY();
}


#endif

/* Handle:  314,Name:                RightCurb_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxRightCurb_Angle(vuint16 sigData)
{
  IlEnterCriticalRightCurb_Angle();
  RightCurbInfo.RightCurbInfo.RightCurb_Angle_0 = ((vuint8) (sigData & (vuint8) 0x07));
  RightCurbInfo.RightCurbInfo.RightCurb_Angle_1 = ((vuint8) (sigData >> 3));
  IlLeaveCriticalRightCurb_Angle();
}


#endif

/* Handle:  316,Name:           LeftCurb_StartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLeftCurb_StartPointX(vuint16 sigData)
{
  IlEnterCriticalLeftCurb_StartPointX();
  LeftCurbInfo.LeftCurbInfo.LeftCurb_StartPointX_0 = ((vuint8) (sigData & (vuint8) 0x7F));
  LeftCurbInfo.LeftCurbInfo.LeftCurb_StartPointX_1 = ((vuint8) ((sigData >> 7) & (vuint8) 0x0F));
  IlLeaveCriticalLeftCurb_StartPointX();
}


#endif

/* Handle:  317,Name:           LeftCurb_StartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLeftCurb_StartPointY(vuint16 sigData)
{
  IlEnterCriticalLeftCurb_StartPointY();
  LeftCurbInfo.LeftCurbInfo.LeftCurb_StartPointY_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  LeftCurbInfo.LeftCurbInfo.LeftCurb_StartPointY_1 = ((vuint8) ((sigData >> 4) & (vuint8) 0x7F));
  IlLeaveCriticalLeftCurb_StartPointY();
}


#endif

/* Handle:  319,Name:             LeftCurb_EndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLeftCurb_EndPointX(vuint16 sigData)
{
  IlEnterCriticalLeftCurb_EndPointX();
  LeftCurbInfo.LeftCurbInfo.LeftCurb_EndPointX_0 = ((vuint8) sigData);
  LeftCurbInfo.LeftCurbInfo.LeftCurb_EndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalLeftCurb_EndPointX();
}


#endif

/* Handle:  320,Name:             LeftCurb_EndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLeftCurb_EndPointY(vuint16 sigData)
{
  IlEnterCriticalLeftCurb_EndPointY();
  LeftCurbInfo.LeftCurbInfo.LeftCurb_EndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  LeftCurbInfo.LeftCurbInfo.LeftCurb_EndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalLeftCurb_EndPointY();
}


#endif

/* Handle:  325,Name:                 LeftCurb_Angle,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxLeftCurb_Angle(vuint16 sigData)
{
  IlEnterCriticalLeftCurb_Angle();
  LeftCurbInfo.LeftCurbInfo.LeftCurb_Angle_0 = ((vuint8) (sigData & (vuint8) 0x07));
  LeftCurbInfo.LeftCurbInfo.LeftCurb_Angle_1 = ((vuint8) (sigData >> 3));
  IlLeaveCriticalLeftCurb_Angle();
}


#endif

/* Handle:  326,Name: Freespace11_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace11_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace11_ObstacleStartPointX();
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace11_ObstacleStartPointX();
}


#endif

/* Handle:  327,Name: Freespace11_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace11_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace11_ObstacleStartPointY();
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace11_ObstacleStartPointY();
}


#endif

/* Handle:  329,Name:  Freespace11_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace11_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace11_ObstacleEndPointX();
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace11_ObstacleEndPointX();
}


#endif

/* Handle:  330,Name:  Freespace11_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace11_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace11_ObstacleEndPointY();
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace11_ObstacleInfo.Freespace11_ObstacleInfo.Freespace11_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace11_ObstacleEndPointY();
}


#endif

/* Handle:  335,Name: Freespace10_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace10_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace10_ObstacleStartPointX();
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace10_ObstacleStartPointX();
}


#endif

/* Handle:  336,Name: Freespace10_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace10_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace10_ObstacleStartPointY();
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace10_ObstacleStartPointY();
}


#endif

/* Handle:  338,Name:  Freespace10_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace10_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace10_ObstacleEndPointX();
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace10_ObstacleEndPointX();
}


#endif

/* Handle:  339,Name:  Freespace10_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace10_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace10_ObstacleEndPointY();
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace10_ObstacleInfo.Freespace10_ObstacleInfo.Freespace10_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace10_ObstacleEndPointY();
}


#endif

/* Handle:  344,Name: Freespace9_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace9_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace9_ObstacleStartPointX();
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace9_ObstacleStartPointX();
}


#endif

/* Handle:  345,Name: Freespace9_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace9_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace9_ObstacleStartPointY();
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace9_ObstacleStartPointY();
}


#endif

/* Handle:  347,Name:   Freespace9_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace9_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace9_ObstacleEndPointX();
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace9_ObstacleEndPointX();
}


#endif

/* Handle:  348,Name:   Freespace9_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace9_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace9_ObstacleEndPointY();
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace9_ObstacleInfo.Freespace9_ObstacleInfo.Freespace9_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace9_ObstacleEndPointY();
}


#endif

/* Handle:  353,Name: Freespace8_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace8_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace8_ObstacleStartPointX();
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace8_ObstacleStartPointX();
}


#endif

/* Handle:  354,Name: Freespace8_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace8_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace8_ObstacleStartPointY();
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace8_ObstacleStartPointY();
}


#endif

/* Handle:  356,Name:   Freespace8_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace8_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace8_ObstacleEndPointX();
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace8_ObstacleEndPointX();
}


#endif

/* Handle:  357,Name:   Freespace8_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace8_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace8_ObstacleEndPointY();
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace8_ObstacleInfo.Freespace8_ObstacleInfo.Freespace8_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace8_ObstacleEndPointY();
}


#endif

/* Handle:  362,Name: Freespace7_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace7_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace7_ObstacleStartPointX();
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace7_ObstacleStartPointX();
}


#endif

/* Handle:  363,Name: Freespace7_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace7_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace7_ObstacleStartPointY();
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace7_ObstacleStartPointY();
}


#endif

/* Handle:  365,Name:   Freespace7_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace7_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace7_ObstacleEndPointX();
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace7_ObstacleEndPointX();
}


#endif

/* Handle:  366,Name:   Freespace7_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace7_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace7_ObstacleEndPointY();
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace7_ObstacleInfo.Freespace7_ObstacleInfo.Freespace7_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace7_ObstacleEndPointY();
}


#endif

/* Handle:  371,Name: Freespace6_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace6_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace6_ObstacleStartPointX();
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace6_ObstacleStartPointX();
}


#endif

/* Handle:  372,Name: Freespace6_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace6_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace6_ObstacleStartPointY();
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace6_ObstacleStartPointY();
}


#endif

/* Handle:  374,Name:   Freespace6_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace6_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace6_ObstacleEndPointX();
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace6_ObstacleEndPointX();
}


#endif

/* Handle:  375,Name:   Freespace6_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace6_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace6_ObstacleEndPointY();
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace6_ObstacleInfo.Freespace6_ObstacleInfo.Freespace6_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace6_ObstacleEndPointY();
}


#endif

/* Handle:  380,Name: Freespace5_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace5_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace5_ObstacleStartPointX();
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace5_ObstacleStartPointX();
}


#endif

/* Handle:  381,Name: Freespace5_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace5_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace5_ObstacleStartPointY();
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace5_ObstacleStartPointY();
}


#endif

/* Handle:  383,Name:   Freespace5_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace5_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace5_ObstacleEndPointX();
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace5_ObstacleEndPointX();
}


#endif

/* Handle:  384,Name:   Freespace5_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace5_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace5_ObstacleEndPointY();
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace5_ObstacleInfo.Freespace5_ObstacleInfo.Freespace5_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace5_ObstacleEndPointY();
}


#endif

/* Handle:  389,Name: Freespace4_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace4_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace4_ObstacleStartPointX();
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace4_ObstacleStartPointX();
}


#endif

/* Handle:  390,Name: Freespace4_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace4_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace4_ObstacleStartPointY();
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace4_ObstacleStartPointY();
}


#endif

/* Handle:  392,Name:   Freespace4_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace4_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace4_ObstacleEndPointX();
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace4_ObstacleEndPointX();
}


#endif

/* Handle:  393,Name:   Freespace4_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace4_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace4_ObstacleEndPointY();
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace4_ObstacleInfo.Freespace4_ObstacleInfo.Freespace4_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace4_ObstacleEndPointY();
}


#endif

/* Handle:  398,Name: Freespace3_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace3_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace3_ObstacleStartPointX();
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace3_ObstacleStartPointX();
}


#endif

/* Handle:  399,Name: Freespace3_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace3_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace3_ObstacleStartPointY();
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace3_ObstacleStartPointY();
}


#endif

/* Handle:  401,Name:   Freespace3_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace3_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace3_ObstacleEndPointX();
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace3_ObstacleEndPointX();
}


#endif

/* Handle:  402,Name:   Freespace3_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace3_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace3_ObstacleEndPointY();
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace3_ObstacleInfo.Freespace3_ObstacleInfo.Freespace3_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace3_ObstacleEndPointY();
}


#endif

/* Handle:  407,Name: Freespace2_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace2_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace2_ObstacleStartPointX();
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace2_ObstacleStartPointX();
}


#endif

/* Handle:  408,Name: Freespace2_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace2_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace2_ObstacleStartPointY();
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace2_ObstacleStartPointY();
}


#endif

/* Handle:  410,Name:   Freespace2_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace2_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace2_ObstacleEndPointX();
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace2_ObstacleEndPointX();
}


#endif

/* Handle:  411,Name:   Freespace2_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace2_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace2_ObstacleEndPointY();
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace2_ObstacleInfo.Freespace2_ObstacleInfo.Freespace2_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace2_ObstacleEndPointY();
}


#endif

/* Handle:  416,Name: Freespace1_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace1_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace1_ObstacleStartPointX();
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace1_ObstacleStartPointX();
}


#endif

/* Handle:  417,Name: Freespace1_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace1_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace1_ObstacleStartPointY();
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace1_ObstacleStartPointY();
}


#endif

/* Handle:  419,Name:   Freespace1_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace1_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace1_ObstacleEndPointX();
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace1_ObstacleEndPointX();
}


#endif

/* Handle:  420,Name:   Freespace1_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace1_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace1_ObstacleEndPointY();
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace1_ObstacleInfo.Freespace1_ObstacleInfo.Freespace1_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace1_ObstacleEndPointY();
}


#endif

/* Handle:  425,Name: Freespace0_ObstacleStartPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace0_ObstacleStartPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace0_ObstacleStartPointX();
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStartPointX_0 = ((vuint8) sigData);
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStartPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace0_ObstacleStartPointX();
}


#endif

/* Handle:  426,Name: Freespace0_ObstacleStartPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace0_ObstacleStartPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace0_ObstacleStartPointY();
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStartPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleStartPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace0_ObstacleStartPointY();
}


#endif

/* Handle:  428,Name:   Freespace0_ObstacleEndPointX,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace0_ObstacleEndPointX(vuint16 sigData)
{
  IlEnterCriticalFreespace0_ObstacleEndPointX();
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleEndPointX_0 = ((vuint8) sigData);
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleEndPointX_1 = ((vuint8) ((sigData >> 8) & (vuint8) 0x07));
  IlLeaveCriticalFreespace0_ObstacleEndPointX();
}


#endif

/* Handle:  429,Name:   Freespace0_ObstacleEndPointY,Size: 11,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFreespace0_ObstacleEndPointY(vuint16 sigData)
{
  IlEnterCriticalFreespace0_ObstacleEndPointY();
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleEndPointY_0 = ((vuint8) (sigData & (vuint8) 0x1F));
  Freespace0_ObstacleInfo.Freespace0_ObstacleInfo.Freespace0_ObstacleEndPointY_1 = ((vuint8) ((sigData >> 5) & (vuint8) 0x3F));
  IlLeaveCriticalFreespace0_ObstacleEndPointY();
}


#endif



#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 IlTxIndirection[kIlNumberOfTxObjects] = 
{
  1 /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  2 /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  3 /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  4 /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  5 /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  6 /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  7 /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  8 /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  9 /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  10 /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  11 /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  12 /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  13 /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  14 /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  15 /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  16 /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  17 /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  18 /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  19 /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  20 /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  21 /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  22 /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  23 /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  24 /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  25 /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  26 /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  27 /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  28 /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  29 /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  30 /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  31 /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  32 /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  33 /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  34 /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  35 /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  36 /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  37 /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  38 /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  40 /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  41 /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  42 /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  43 /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  44 /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  45 /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  46 /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  47 /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  48 /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  49 /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  50 /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  51 /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  52 /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  53 /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  54 /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  55 /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  56 /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ CAN handle to Il start stop handle
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(C_ENABLE_CAN_CANCEL_NOTIFICATION)
V_MEMROM0 V_MEMROM1 IlStartStopHnd V_MEMROM2 IlCanHndToIlHnd[kIlCanNumberOfTxObjects] = 
{
  { 0, 0 } /* no Il message */, 
  { 0, 1 } /* start - stop  ID: 0x000002ef, Debug_CanStaInfo [BC] */, 
  { 1, 2 } /* start - stop  ID: 0x000002ee, Debug_ReloatInfo [BC] */, 
  { 2, 3 } /* start - stop  ID: 0x000002ed, TargetPointInfo [BC] */, 
  { 3, 4 } /* start - stop  ID: 0x000002ec, TargetSlot_CD [BC] */, 
  { 4, 5 } /* start - stop  ID: 0x000002eb, TargetSlot_AB [BC] */, 
  { 5, 6 } /* start - stop  ID: 0x000002ea, USS_SLOT_R_CD [BC] */, 
  { 6, 7 } /* start - stop  ID: 0x000002e9, USS_SLOT_R_AB [BC] */, 
  { 7, 8 } /* start - stop  ID: 0x000002e8, USS_SLOT_L_CD [BC] */, 
  { 8, 9 } /* start - stop  ID: 0x000002e7, USS_SLOT_L_AB [BC] */, 
  { 9, 10 } /* start - stop  ID: 0x000002e6, USS_DE_S [BC] */, 
  { 10, 11 } /* start - stop  ID: 0x000002e5, USS_DE_R [BC] */, 
  { 11, 12 } /* start - stop  ID: 0x000002e4, USS_DE_F [BC] */, 
  { 12, 13 } /* start - stop  ID: 0x000002e3, USS_DIAG_R [BC] */, 
  { 13, 14 } /* start - stop  ID: 0x000002e2, USS_DIAG_F [BC] */, 
  { 14, 15 } /* start - stop  ID: 0x000002e1, DR_2 [BC] */, 
  { 15, 16 } /* start - stop  ID: 0x000002e0, DR_1 [BC] */, 
  { 16, 17 } /* start - stop  ID: 0x0000025d, PDC_2 [BC] */, 
  { 17, 18 } /* start - stop  ID: 0x0000025c, PDC_1 [BC] */, 
  { 18, 19 } /* start - stop  ID: 0x00000258, AVS_1 [BC] */, 
  { 19, 20 } /* start - stop  ID: 0x000001cb, PDC_14 [BC] */, 
  { 20, 21 } /* start - stop  ID: 0x000001ca, PDC_13 [BC] */, 
  { 21, 22 } /* start - stop  ID: 0x000001c9, PDC_12 [BC] */, 
  { 22, 23 } /* start - stop  ID: 0x000001c8, PDC_11 [BC] */, 
  { 23, 24 } /* start - stop  ID: 0x000001c7, PDC_10 [BC] */, 
  { 24, 25 } /* start - stop  ID: 0x000001c6, PDC_9 [BC] */, 
  { 25, 26 } /* start - stop  ID: 0x000001c5, PDC_8 [BC] */, 
  { 26, 27 } /* start - stop  ID: 0x000001c4, PDC_7 [BC] */, 
  { 27, 28 } /* start - stop  ID: 0x000001c3, PDC_6 [BC] */, 
  { 28, 29 } /* start - stop  ID: 0x000001c2, PDC_5 [BC] */, 
  { 29, 30 } /* start - stop  ID: 0x000001c1, PDC_4 [BC] */, 
  { 30, 31 } /* start - stop  ID: 0x000001c0, PDC_3 [BC] */, 
  { 31, 32 } /* start - stop  ID: 0x0000018b, APS_Slot6 [BC] */, 
  { 32, 33 } /* start - stop  ID: 0x0000018a, APS_Slot5 [BC] */, 
  { 33, 34 } /* start - stop  ID: 0x00000189, APS_Slot4 [BC] */, 
  { 34, 35 } /* start - stop  ID: 0x00000188, APS_Slot3 [BC] */, 
  { 35, 36 } /* start - stop  ID: 0x00000187, APS_Slot2 [BC] */, 
  { 36, 37 } /* start - stop  ID: 0x00000186, APS_Slot1 [BC] */, 
  { 37, 38 } /* start - stop  ID: 0x00000184, APS_PSD [BC] */, 
  { 0, 0 } /* no Il message */, 
  { 38, 39 } /* start - stop  ID: 0x000002d3, APS_Replan_2 [BC] */, 
  { 39, 40 } /* start - stop  ID: 0x000002d2, APS_Replan_1 [BC] */, 
  { 40, 41 } /* start - stop  ID: 0x000002d1, RightCurbInfo [BC] */, 
  { 41, 42 } /* start - stop  ID: 0x000002d0, LeftCurbInfo [BC] */, 
  { 42, 43 } /* start - stop  ID: 0x000002cc, Freespace11_ObstacleInfo [BC] */, 
  { 43, 44 } /* start - stop  ID: 0x000002cb, Freespace10_ObstacleInfo [BC] */, 
  { 44, 45 } /* start - stop  ID: 0x000002ca, Freespace9_ObstacleInfo [BC] */, 
  { 45, 46 } /* start - stop  ID: 0x000002c9, Freespace8_ObstacleInfo [BC] */, 
  { 46, 47 } /* start - stop  ID: 0x000002c8, Freespace7_ObstacleInfo [BC] */, 
  { 47, 48 } /* start - stop  ID: 0x000002c7, Freespace6_ObstacleInfo [BC] */, 
  { 48, 49 } /* start - stop  ID: 0x000002c6, Freespace5_ObstacleInfo [BC] */, 
  { 49, 50 } /* start - stop  ID: 0x000002c5, Freespace4_ObstacleInfo [BC] */, 
  { 50, 51 } /* start - stop  ID: 0x000002c4, Freespace3_ObstacleInfo [BC] */, 
  { 51, 52 } /* start - stop  ID: 0x000002c3, Freespace2_ObstacleInfo [BC] */, 
  { 52, 53 } /* start - stop  ID: 0x000002c2, Freespace1_ObstacleInfo [BC] */, 
  { 53, 54 } /* start - stop  ID: 0x000002c1, Freespace0_ObstacleInfo [BC] */, 
  { 54, 55 } /* start - stop  ID: 0x000001a1, APS_1 [BC] */
};
#endif




/* -----------------------------------------------------------------------------
    &&&~ TxTypes for interaction layer tx messages 
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 IlTxType[kIlNumberOfTxObjects] = 
{
  kTxNoTxType /* ID: 0x000002ef, Handle: 0, Debug_CanStaInfo [BC] */, 
  kTxNoTxType /* ID: 0x000002ee, Handle: 1, Debug_ReloatInfo [BC] */, 
  kTxNoTxType /* ID: 0x000002ed, Handle: 2, TargetPointInfo [BC] */, 
  kTxNoTxType /* ID: 0x000002ec, Handle: 3, TargetSlot_CD [BC] */, 
  kTxNoTxType /* ID: 0x000002eb, Handle: 4, TargetSlot_AB [BC] */, 
  kTxNoTxType /* ID: 0x000002ea, Handle: 5, USS_SLOT_R_CD [BC] */, 
  kTxNoTxType /* ID: 0x000002e9, Handle: 6, USS_SLOT_R_AB [BC] */, 
  kTxNoTxType /* ID: 0x000002e8, Handle: 7, USS_SLOT_L_CD [BC] */, 
  kTxNoTxType /* ID: 0x000002e7, Handle: 8, USS_SLOT_L_AB [BC] */, 
  kTxNoTxType /* ID: 0x000002e6, Handle: 9, USS_DE_S [BC] */, 
  kTxNoTxType /* ID: 0x000002e5, Handle: 10, USS_DE_R [BC] */, 
  kTxNoTxType /* ID: 0x000002e4, Handle: 11, USS_DE_F [BC] */, 
  kTxNoTxType /* ID: 0x000002e3, Handle: 12, USS_DIAG_R [BC] */, 
  kTxNoTxType /* ID: 0x000002e2, Handle: 13, USS_DIAG_F [BC] */, 
  kTxNoTxType /* ID: 0x000002e1, Handle: 14, DR_2 [BC] */, 
  kTxNoTxType /* ID: 0x000002e0, Handle: 15, DR_1 [BC] */, 
  kTxSendCyclic /* ID: 0x0000025d, Handle: 16, PDC_2 [BC] */, 
  kTxSendCyclic /* ID: 0x0000025c, Handle: 17, PDC_1 [BC] */, 
  kTxSendCyclic /* ID: 0x00000258, Handle: 18, AVS_1 [BC] */, 
  kTxSendCyclic /* ID: 0x000001cb, Handle: 19, PDC_14 [BC] */, 
  kTxSendCyclic /* ID: 0x000001ca, Handle: 20, PDC_13 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c9, Handle: 21, PDC_12 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c8, Handle: 22, PDC_11 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c7, Handle: 23, PDC_10 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c6, Handle: 24, PDC_9 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c5, Handle: 25, PDC_8 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c4, Handle: 26, PDC_7 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c3, Handle: 27, PDC_6 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c2, Handle: 28, PDC_5 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c1, Handle: 29, PDC_4 [BC] */, 
  kTxSendCyclic /* ID: 0x000001c0, Handle: 30, PDC_3 [BC] */, 
  kTxSendCyclic /* ID: 0x0000018b, Handle: 31, APS_Slot6 [BC] */, 
  kTxSendCyclic /* ID: 0x0000018a, Handle: 32, APS_Slot5 [BC] */, 
  kTxSendCyclic /* ID: 0x00000189, Handle: 33, APS_Slot4 [BC] */, 
  kTxSendCyclic /* ID: 0x00000188, Handle: 34, APS_Slot3 [BC] */, 
  kTxSendCyclic /* ID: 0x00000187, Handle: 35, APS_Slot2 [BC] */, 
  kTxSendCyclic /* ID: 0x00000186, Handle: 36, APS_Slot1 [BC] */, 
  kTxSendCyclic /* ID: 0x00000184, Handle: 37, APS_PSD [BC] */, 
  kTxSendCyclic /* ID: 0x000002d3, Handle: 38, APS_Replan_2 [BC] */, 
  kTxSendCyclic /* ID: 0x000002d2, Handle: 39, APS_Replan_1 [BC] */, 
  kTxSendCyclic /* ID: 0x000002d1, Handle: 40, RightCurbInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002d0, Handle: 41, LeftCurbInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002cc, Handle: 42, Freespace11_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002cb, Handle: 43, Freespace10_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002ca, Handle: 44, Freespace9_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c9, Handle: 45, Freespace8_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c8, Handle: 46, Freespace7_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c7, Handle: 47, Freespace6_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c6, Handle: 48, Freespace5_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c5, Handle: 49, Freespace4_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c4, Handle: 50, Freespace3_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c3, Handle: 51, Freespace2_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c2, Handle: 52, Freespace1_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000002c1, Handle: 53, Freespace0_ObstacleInfo [BC] */, 
  kTxSendCyclic /* ID: 0x000001a1, Handle: 54, APS_1 [BC] */
};
#endif




/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\il_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\il_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

