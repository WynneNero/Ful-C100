/*------------------------------------------------------------------------------

    File Name: can_sig_if.h

    Interface for accessing CAN signals.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    Sun Yilin       uida3867        Desay SV HZH / IDA R&D
    Su Zhisheng     uidq0782        Desay SV HZH / IDA R&D

--------------------------------------------------------------------------------
                      R E V I S I O N   H I S T O R Y
--------------------------------------------------------------------------------
    Date        Ver     Author      Description
    ----------  ---     ------      --------------------------------------------
    2018-2-10   1.0     uida3867    Initial version.

--------------------------------------------------------------------------------
                           C O P Y R I G H T
--------------------------------------------------------------------------------
         Copyright (c) 2018 by Huizhou Desay SV Automotive Co., Ltd.
                          All rights reserved.
------------------------------------------------------------------------------*/


#ifndef _CAN_SIG_IF_H_
#define _CAN_SIG_IF_H_


void can_sig_if_init(void); //by zhaoyu. not used


/* Function Pointers */
/*----------------------------------------------------------------------------*/

unsigned char (*fpGetWheelSpeed_FL)(float *wheelSpeed);
unsigned char (*fpGetWheelSpeed_FR)(float *wheelSpeed);
unsigned char (*fpGetWheelSpeed_RL)(float *wheelSpeed);
unsigned char (*fpGetWheelSpeed_RR)(float *wheelSpeed);

unsigned char (*fpGetWheelPulseCnt_FL)(float *pulseCnt);
unsigned char (*fpGetWheelPulseCnt_FR)(float *pulseCnt);
unsigned char (*fpGetWheelPulseCnt_RL)(float *pulseCnt);
unsigned char (*fpGetWheelPulseCnt_RR)(float *pulseCnt);

unsigned char (*fpGetVehicleSpeed)(float *vehicleSpeed);
unsigned char (*fpGetEMS_BrakePedalSt)(unsigned char *brakeStatus);
unsigned char (*fpGetStandstillStatus)(unsigned char *standstillStatus);
unsigned char (*fpGetEPB_SysSt)(unsigned char *brakeStatus);

unsigned char (*fpGetEMS_GasPedalActPst)(float *pedalPos);

unsigned char (*fpGetTCU_CurrentGearSt)(unsigned char *currentGear);

unsigned char (*fpGetObstacleDist_L_FL)(float *distanceVal);
unsigned char (*fpGetObstacleDist_L_FR)(float *distanceVal);
unsigned char (*fpGetObstacleDist_L_RL)(float *distanceVal);
unsigned char (*fpGetObstacleDist_L_RR)(float *distanceVal);

unsigned char (*fpGetObstacleDist_S_FL)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_FML)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_FMR)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_FR)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_RL)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_RML)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_RMR)(float *distanceVal);
unsigned char (*fpGetObstacleDist_S_RR)(float *distanceVal);

unsigned char (*fpGetBCS_ActVehLongAccel)(float *longitAccel);
unsigned char (*fpGetBCS_ActVehLaltrlAccel)(float *lateralAccel);
unsigned char (*fpGetYawRate)(float *yawRate);



unsigned char (*fpGetSAS_SteeringAngle)(float *steerAngle);
unsigned char (*fpGetTurnIndicationAct)(unsigned char *turnInd);

unsigned char (*fpGetSRS_DriverSeatBeltSt)(unsigned char *buckleStatus);

unsigned char (*fpGetBCM_LeftTurnLampSt)(unsigned char *turnInd);
unsigned char (*fpGetBCM_RightTurnLampSt)(unsigned char *turnInd);
unsigned char (*fpGetLowBeamSt)(unsigned char *lightStatus);
unsigned char (*fpGetHighBeamSt)(unsigned char *lightStatus);
unsigned char (*fpGetPositionLightSts)(unsigned char *lightStatus);
unsigned char (*fpGetFrontFogLightSts)(unsigned char *lightStatus);
unsigned char (*fpGetRearFogLightSts)(unsigned char *lightStatus);

unsigned char (*fpGetDoorAjarStatus_FL)(unsigned char *doorStatus);
unsigned char (*fpGetDoorAjarStatus_FR)(unsigned char *doorStatus);
unsigned char (*fpGetDoorAjarStatus_RL)(unsigned char *doorStatus);
unsigned char (*fpGetDoorAjarStatus_RR)(unsigned char *doorStatus);


/* Function Definitions */
/*----------------------------------------------------------------------------*/

unsigned char Get_ESC_FLWheelSpeedKPH(float *wheelSpeed);
unsigned char Get_ESC_FRWheelSpeedKPH(float *wheelSpeed);
unsigned char Get_ESC_RLWheelSpeedKPH(float *wheelSpeed);
unsigned char Get_ESC_RRWheelSpeedKPH(float *wheelSpeed);

unsigned char Get_ESC_FLWheelSpeedRC(float *pulseCnt);
unsigned char Get_ESC_FRWheelSpeedRC(float *pulseCnt);
unsigned char Get_ESC_RLWheelSpeedRC(float *pulseCnt);
unsigned char Get_ESC_RRWheelSpeedRC(float *pulseCnt);

unsigned char get_VehSpd(float *vehicleSpeed);
unsigned char Get_EMS_BrakePedalSt(unsigned char *brakeStatus);
unsigned char Get_ESC_Vehiclestandstill(unsigned char *standstillStatus);
unsigned char Get_ESC_EPBStatus(unsigned char *brakeStatus);

unsigned char Get_EMS_GasPedalActPst(float *pedalPos);

unsigned char Get_TCU_CurrentGearSt(unsigned char *currentGear);

unsigned char Get_PAS_APA_DistanceValueLR_FL(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueLR_FR(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueLR_RL(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueLR_RR(float *distanceVal);

unsigned char Get_PAS_APA_DistanceValueSR_FL(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_FML(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_FMR(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_FR(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_RL(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_RML(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_RMR(float *distanceVal);
unsigned char Get_PAS_APA_DistanceValueSR_RR(float *distanceVal);

unsigned char Get_BCS_ActVehLongAccel(float *longitAccel);
unsigned char Get_BCS_ActVehLaltrlAccel(float *lateralAccel);
unsigned char Get_BCS_YawRate(float *yawRate);



unsigned char Get_SAS_SteeringAngle(float *steerAngle);
unsigned char Get_TCM_Req_TurnIndicationAct(unsigned char *turnInd);

unsigned char Get_SRS_DriverSeatBeltSt(unsigned char *buckleStatus);

unsigned char Get_BCM_LeftTurnLampSt(unsigned char *turnInd);  /* 0x1F0 - BCM_LightChimeReq */
unsigned char Get_BCM_RightTurnLampSt(unsigned char *turnInd);
unsigned char Get_BCM_LowBeamSt(unsigned char *lightStatus);
unsigned char Get_BCM_HighBeamSt(unsigned char *lightStatus);
unsigned char Get_BCM_PositionLightSts(unsigned char *lightStatus);
unsigned char Get_BCM_FrontFogLightSts(unsigned char *lightStatus);
unsigned char Get_BCM_RearFogLightSts(unsigned char *lightStatus);

unsigned char Get_DDM_FrontLeftDoorAjarStatus(unsigned char *doorStatus);    /* 0x285 - DDM_LDoorWindowState */
unsigned char Get_DDM_RearLeftDoorAjarStatus(unsigned char *doorStatus);
unsigned char Get_PDM_FrontRightDoorAjarStatus(unsigned char *doorStatus);   /* 0x286 - PDM_RDoorWindowState */
unsigned char Get_PDM_RearRightDoorAjarStatus(unsigned char *doorStatus);


#endif  /* _CAN_SIG_IF_H_ */


