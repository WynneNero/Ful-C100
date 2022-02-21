/*------------------------------------------------------------------------------

    File Name: m4_data_updater.h

    Interface for SOC M4 protocol data handler.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    Sun Yilin       uida3867        Desay SV HZH / IDA R&D
    Lin Feng        uidp5358        Desay SV HZH / IDA R&D

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


#ifndef _M4_DATA_UPDATER_H_
#define _M4_DATA_UPDATER_H_


/* Macros */
/*----------------------------------------------------------------------------*/

/* used by acceleration pedal status and brake pedal status */
#define PEDAL_STATUS_INVALID                0
#define PEDAL_STATUS_RELEASED               1
#define PEDAL_STATUS_PRESSED                2

/* bit field shift count */
#define LAMP_STATUS_LEFT_TRUN_SHIFT_CNT     0
#define LAMP_STATUS_RIGHT_TURN_SHIFT_CNT    1
#define LAMP_STATUS_LOW_BEAM_SHIFT_CNT      2
#define LAMP_STATUS_HIGH_BEAM_SHIFT_CNT     3
#define LAMP_STATUS_POSITION_SHIFT_CNT      4
#define LAMP_STATUS_FRONT_FOG_SHIFT_CNT     5
#define LAMP_STATUS_REAR_FOG_SHIFT_CNT      6

#define DOOR_AJAR_STATUS_FL_SHIFT_CNT       0
#define DOOR_AJAR_STATUS_FR_SHIFT_CNT       1
#define DOOR_AJAR_STATUS_RL_SHIFT_CNT       2
#define DOOR_AJAR_STATUS_RR_SHIFT_CNT       3


/* Functions */
/*----------------------------------------------------------------------------*/

void UpdateWheelSpeed_FL(void);
void UpdateWheelSpeed_FR(void);
void UpdateWheelSpeed_RL(void);
void UpdateWheelSpeed_RR(void);

void UpdateWheelPulseCnt_FL(void);
void UpdateWheelPulseCnt_FR(void);
void UpdateWheelPulseCnt_RL(void);
void UpdateWheelPulseCnt_RR(void);

void UpdateObstacleDist_L_FL(void);
void UpdateObstacleDist_L_FR(void);
void UpdateObstacleDist_L_RL(void);
void UpdateObstacleDist_L_RR(void);

void UpdateObstacleDist_S_FL(void);
void UpdateObstacleDist_S_FML(void);
void UpdateObstacleDist_S_FMR(void);
void UpdateObstacleDist_S_FR(void);
void UpdateObstacleDist_S_RL(void);
void UpdateObstacleDist_S_RML(void);
void UpdateObstacleDist_S_RMR(void);
void UpdateObstacleDist_S_RR(void);

void UpdateYawRateDirection(void);
void UpdateYawRate(void);
void UpdateLateralAccel(void);
void UpdateLongitAccel(void);


void UpdateCurrentVehicleSpeed(void);
void UpdateCurrentGear(void);
void UpdateSteerWheelDirection(void);
void UpdateSteerWheelAngle(void);
/*DR
void E_M4_ABSOLUTE_DELTA_X_update(void);
void E_M4_ABSOLUTE_DELTA_Y_update(void);
void E_M4_ABSOLUTE_DELTA_ANGLE_update(void);
void E_M4_RELATIVE_DELTA_X_update(void);
void E_M4_RELATIVE_DELTA_Y_update(void);
void E_M4_RELATIVE_DELTA_ANGLE_update(void);
void E_M4_PAS_COORDINATE_A_X_update(void);
void E_M4_PAS_COORDINATE_A_Y_update(void);
void E_M4_PAS_COORDINATE_B_X_update(void);
void E_M4_PAS_COORDINATE_B_Y_update(void);
void E_M4_PAS_COORDINATE_C_X_update(void);
void E_M4_PAS_COORDINATE_C_Y_update(void);
void E_M4_PAS_COORDINATE_DEPTH_update(void);
void E_M4_RESET_POSITION_REQ_update(void);
*/

void UpdateCurrentPowerStatus(void);
void UpdateTurnSignal(void);
void UpdateDrvSeatBeltBuckleStatus(void);
void UpdateBrakePedalStatus(void);
void UpdateEPBStatus(void);
void UpdateAccelPedalPosition(void);

void UpdateLampStatus(void);

void UpdateDoorsStatus(void);
/*
void E_M4_RadarWorkingSatus_ByBit_update(void);
void E_M4_RadarDis_FrontLeft_update(void);
void E_M4_RadarDis_FrontMidLeft_update(void);
void E_M4_RadarDis_FrontMidRight_update(void);
void E_M4_RadarDis_FrontRight_update(void);
void E_M4_RadarDis_LeftFront_update(void);
void E_M4_RadarDis_LeftBack_update(void);
void E_M4_RadarDis_BackLeft_update(void);
void E_M4_RadarDis_BackMidLeft_update(void);
void E_M4_RadarDis_BackMidRight_update(void);
void E_M4_RadarDis_BackRight_update(void);
void E_M4_RadarDis_RightFront_update(void);
void E_M4_RadarDis_RightBack_update(void);
*/


#endif  /* _M4_DATA_UPDATER_H_ */



