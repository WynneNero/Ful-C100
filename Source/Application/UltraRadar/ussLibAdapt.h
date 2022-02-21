#ifndef __USS_LIB_ADAPT_H
#define __USS_LIB_ADAPT_H

#include "ussLibIf.h"

void ussLibAdaptOpen(void);
void ObjDetectDistanceUpdateLoop(void);  // 10 ms

void Set_BCS_5_A_Timerout(U8 flag);
void Set_BCS_10_A_Timerout(U8 flag);
void Set_GW_TCU_1_A_Timerout(U8 flag);
void Set_BCS_SAS_1_A_Timerout(U8 flag);

void Set_BCS_9_A_Timerout(U8 flag);
void Set_BCS_EPB_1_A_Timerout(U8 flag);
void Set_GW_EMS_1_A_Timerout(U8 flag);
void Set_BCS_11_A_Timerout(U8 flag);

void Set_BCS_6_A_Timerout(U8 flag);
void Set_GW_ICM_HVAC_A_Timerout(U8 flag);
void Set_GW_BCM_2_A_Timerout(U8 flag);
void Set_BCS_SAS_1_A_Timerout(U8 flag);
void Set_GW_EMS_1_A_Timerout(U8 flag);

void Set_RadarControlSwitch_Status(Boolean RadarControlSwitch);


int fill_AD_point(USSParkingSlotSearch side, FV_SlotInformationType *SV_slot);
USSParkingSlotSearch Get_and_Save_FV_USS_Slot(USSParkingSlotSearch side, FV_SlotInformationType * FV_slot_backup);
void ussLibAdaptOpen(void);

Boolean g_SV_SetRadarPwrStatus_bl(E_APA_RadarPwr_Status              RadarPwr_Status);
Boolean g_SV_SetUbattStatus_bl(E_APA_Ubatt_Status             Ubatt_Status);
Boolean SetPDCModeStatus_bl(E_APA_PDCMode_Status f_PDCModeStatus_en);
void clrUssPdcLockBits(void);

/*
BCS_5_A
BCS_10_A
GW_TCU_1_A 
BCS_SAS_1_A
BCS_9_A
BCS_EPB_1_A
GW_EMS_1_A
BCS_11_A
BCS_6_A
GW_ICM_HVAC_A
GW_BCM_2_A
BCS_SAS_1_A
GW_EMS_1_A
*/

/******************extern***********************/
extern U16 get_ABS3_receive_timePoint(void);

#endif

