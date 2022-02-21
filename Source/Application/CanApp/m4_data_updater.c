/*------------------------------------------------------------------------------

    File Name: m4_data_updater.c

    Updates vehicle datas to M4 core.
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


#include "m4_data_updater.h"


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelSpeed_FL
    Descriptions:
        Updates the front left wheel speed data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelSpeed_FL(void)
{
    float32 wheelSpeed = 0;

    if(fpGetWheelSpeed_FL(&wheelSpeed))
    {
        M4Msg_Update(E_M4_FLWheelSpeed_U16, wheelSpeed);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelSpeed_FR
    Descriptions:
        Updates the front right wheel speed data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelSpeed_FR(void)
{
    float32 wheelSpeed = 0;

    if(fpGetWheelSpeed_FR(&wheelSpeed))
    {
        M4Msg_Update(E_M4_FRwheelSpeed_U16, wheelSpeed);
    }
}

/*------------------------------------------------------------------------------
    Function:
        UpdateWheelSpeed_RL
    Descriptions:
        Updates the rear left wheel speed data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/

void UpdateWheelSpeed_RL(void)
{
    float32 wheelSpeed = 0;

    if(fpGetWheelSpeed_RL(&wheelSpeed))
    {
        M4Msg_Update(E_M4_RLwheelSpeed_U16, wheelSpeed);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelSpeed_RR
    Descriptions:
        Updates the rear right wheel speed data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelSpeed_RR(void)
{
    float32 wheelSpeed = 0;

    if(fpGetWheelSpeed_RR(&wheelSpeed))
    {
        M4Msg_Update(E_M4_RRwheelSpeed_U16, wheelSpeed);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelPulseCnt_FL
    Descriptions:
        Updates the front left pulse count data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelPulseCnt_FL(void)
{
    float32 pulseCnt = 0;

    if(fpGetWheelPulseCnt_FL(&pulseCnt))
    {
        M4Msg_Update(E_M4_FLWheelSpeed_PULSE_U16, pulseCnt);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelPulseCnt_FR
    Descriptions:
        Updates the front right pulse count data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelPulseCnt_FR(void)
{
    float32 pulseCnt = 0;

    if(fpGetWheelPulseCnt_FR(&pulseCnt))
    {
        M4Msg_Update(E_M4_FRwheelSpeed_PULSE_U16, pulseCnt);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelPulseCnt_RL
    Descriptions:
        Updates the rear left pulse count data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelPulseCnt_RL(void)
{
    float32 pulseCnt = 0;

    if(fpGetWheelPulseCnt_RL(&pulseCnt))
    {
        M4Msg_Update(E_M4_RLwheelSpeed_PULSE_U16, pulseCnt);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateWheelPulseCnt_RR
    Descriptions:
        Updates the rear right pulse count data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateWheelPulseCnt_RR(void)
{
    float32 pulseCnt = 0;

    if(fpGetWheelPulseCnt_RR(&pulseCnt))
    {
        M4Msg_Update(E_M4_RRwheelSpeed_PULSE_U16, pulseCnt);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_L_FL
    Descriptions:
        Updates the front left long range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_L_FL(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_L_FL(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Long_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_L_FR
    Descriptions:
        Updates the front right long range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_L_FR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_L_FR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Long_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_L_RL
    Descriptions:
        Updates the rear left long range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_L_RL(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_L_RL(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Long_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_L_RR
    Descriptions:
        Updates the rear right long range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_L_RR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_L_RR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Long_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_FL
    Descriptions:
        Updates the front left short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_FL(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_FL(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontLeft_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_FML
    Descriptions:
        Updates the front middle left short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_FML(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_FML(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleLeft_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_FMR
    Descriptions:
        Updates the front middle right short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_FMR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_FMR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontMiddleRight_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_FR
    Descriptions:
        Updates the front right short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_FR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_FR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_FrontRight_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_RL
    Descriptions:
        Updates the rear left short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_RL(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_RL(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearLeft_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_RML
    Descriptions:
        Updates the rear middle left short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_RML(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_RML(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleLeft_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_RMR
    Descriptions:
        Updates the rear middle right short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_RMR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_RMR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearMiddleRight_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateObstacleDist_S_RR
    Descriptions:
        Updates the rear right short range ultra sonic sonar detected
        obstacle distance data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateObstacleDist_S_RR(void)
{
    float32 distanceVal = 0;

    if(fpGetObstacleDist_S_RR(&distanceVal))
    {
        M4Msg_Update(E_M4_Radar_Sensor_Distance_RearRight_Short_U8, distanceVal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateCurrentVehicleSpeed
    Descriptions:
        Updates the current vehicle speed data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateCurrentVehicleSpeed(void)
{
    float32 vehicleSpeed = 0;

    if(fpGetVehicleSpeed(&vehicleSpeed))
    {
        M4Msg_Update(E_M4_VehicleSpeed_U16, vehicleSpeed);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateCurrentGear
    Descriptions:
        Updates the current gear status data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateCurrentGear(void)
{
    U8  currentGear = 0;

    if(fpGetCurrentGear(&currentGear))
    {
        M4Msg_Update(E_M4_GearStatus_U8, currentGear);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateSteerWheelDirection
    Descriptions:
        Updates the steering wheel direction data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateSteerWheelDirection(void)
{
    float32 steerWheelAngle = 0;

    if(fpGetSteerWheelAngle(&steerWheelAngle))
    {
        if((steerWheelAngle*10) & 0x8000)
            {
                //steering_angle_dir = 1; //right
                M4Msg_Update(E_M4_SteerWheelDirection_U8, 2);//in the UART protocol,2 means right
            }
        else
            {
                //steering_angle_dir = 0; //right
                M4Msg_Update(E_M4_SteerWheelDirection_U8, 1);//in the UART protocol,1 means left
            }
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateSteerWheelAngle
    Descriptions:
        Updates the steering wheel angle data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateSteerWheelAngle(void)
{
    float32 steerWheelAngle = 0;

    if(fpGetSteerWheelAngle(&steerWheelAngle))
    {
        M4Msg_Update(E_M4_SteerWheelAngle_Multiple1H_U16, steerWheelAngle);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateYawRateDirection
    Descriptions:
        Updates the yaw rate direction data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateYawRateDirection(void) //this parm not be used yet
{/*
    U8  YawRateDirection = 0;

    if(fpGetCurrentGear(&YawRateDirection))
    {
        M4Msg_Update(E_M4_YawRateDirection_U8,YawRateDirection);
    }
    */
}


/*------------------------------------------------------------------------------
    Function:
        UpdateYawRate
    Descriptions:
        Updates the yaw rate data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateYawRate(void)
{
    float32 yawRate = 0;

    if(fpGetYawRate(&yawRate))
    {
        M4Msg_Update(E_M4_YawRate_Multiple1K_U32, yawRate);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateLongitAccel
    Descriptions:
        Updates the longitudinal acceleration data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateLongitAccel(void)
{
    float32 longitAccel = 0;

    if(fpGetLongitudinalAccel(&longitAccel))
    {
        M4Msg_Update(E_M4_LongitAcce_Multiple1K_U16, longitAccel);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateLateralAccel
    Descriptions:
        Updates the lateral acceleration data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateLateralAccel(void)
{
    float32 lateralAccel = 0;

    if(fpGetLateralAccel(&lateralAccel))
    {
        M4Msg_Update(E_M4_LateralAcce_Multiple1K_U16, lateralAccel);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateCurrentPowerStatus
    Descriptions:
        Updates the current power mode data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateCurrentPowerStatus(void)
{
    BOOL accstatus;
    U8 ign;
    CS_SIG_SyncReceive(SIG_ACCSTATUS, &accstatus);
    if(accstatus)
    {
        ign = 2;
        M4Msg_Update(E_M4_PowerStatus_U8,ign);
    }
    else
    {
        ign = 0;
        M4Msg_Update(E_M4_PowerStatus_U8,ign);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateTurnSignal
    Descriptions:
        Updates the turn indicator status data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateTurnSignal(void)
{
    U8 turnSignal = 0;

    if(fpGetTurnIndicationAct(&turnSignal))
    {
        M4Msg_Update(E_M4_TurnSignal_U8, turnSignal);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateDrvSeatBeltBuckleStatus
    Descriptions:
        Updates the driver seat belt buckle status data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateDrvSeatBeltBuckleStatus(void)
{
    U8 buckleStatus = 0;

    if(fpGetDrvSeatbeltSts(&buckleStatus))
    {
        M4Msg_Update(E_M4_DrvSeatbeltBuckleStatus_U8, buckleStatus);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateBrakePedalStatus
    Descriptions:
        Updates the brake pedal switch status data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateBrakePedalStatus(void)
{
    U8 brakeStatus = 0;

    if(fpGetBrakePedalStatus(&brakeStatus))
    {
        M4Msg_Update(E_M4_BrakePedalSwitchStatus_U8, brakeStatus ? 
            PEDAL_STATUS_PRESSED : PEDAL_STATUS_RELEASED);
    }
    else
    {
        M4Msg_Update(E_M4_BrakePedalSwitchStatus_U8, PEDAL_STATUS_INVALID);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateEPBStatus
    Descriptions:
        Updates the EPB (Electronic Parking Brake) status data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateEPBStatus(void)
{
    U8 brakeStatus = 0;

    if(fpGetEPBStatus(&brakeStatus))
    {
        M4Msg_Update(E_M4_EPBStatus_U8, brakeStatus);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateAccelPedalPosition
    Descriptions:
        Updates the acceleration pedal position data to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateAccelPedalPosition(void)
{
    float32  accelPedalPos = 0;

    if(fpGetAccelPedalPosition(&accelPedalPos))
    {
        M4Msg_Update(E_M4_AccelPedalPosition_U8, accelPedalPos ? 
            PEDAL_STATUS_PRESSED : PEDAL_STATUS_RELEASED);
    }
    else
    {
        M4Msg_Update(E_M4_AccelPedalPosition_U8, PEDAL_STATUS_INVALID);
    }
}


/*------------------------------------------------------------------------------
    Function:
        UpdateLampStatus
    Descriptions:
        Updates the lamp status to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateLampStatus(void)
{
    U16 singleLampStatus = 0;
    U16 lampStatus = 0;

    if (fpGetTurnIndicatorLeft(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_LEFT_TRUN_SHIFT_CNT;
    }

    if (fpGetTurnIndicatorRight(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_RIGHT_TURN_SHIFT_CNT;
    }

    if (fpGetLowBeamSts(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_LOW_BEAM_SHIFT_CNT;
    }

    if (fpGetHighBeamSts(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_HIGH_BEAM_SHIFT_CNT;
    }

    if (fpGetPositionLightSts(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_POSITION_SHIFT_CNT;
    }

    if (fpGetFrontFogLightSts(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_FRONT_FOG_SHIFT_CNT;
    }

    if (fpGetRearFogLightSts(&singleLampStatus))
    {
        lampStatus |= (singleLampStatus & 0x01) << LAMP_STATUS_REAR_FOG_SHIFT_CNT;
    }

    M4Msg_Update(E_M4_AllBeamStatus_ByBit_U16, lampStatus);
}


/*------------------------------------------------------------------------------
    Function:
        UpdateDoorsStatus
    Descriptions:
        Updates the door open status to M4.
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void UpdateDoorsStatus(void)
{
    U8 singleDoorStatus = 0;
    U8 doorStatus = 0;

    if (fpGetDoorAjarStatus_FL(&singleDoorStatus))
    {
        doorStatus |= (singleDoorStatus & 0x01) << DOOR_AJAR_STATUS_FL_SHIFT_CNT;
    }

    if (fpGetDoorAjarStatus_FR(&singleDoorStatus))
    {
        doorStatus |= (singleDoorStatus & 0x01) << DOOR_AJAR_STATUS_FR_SHIFT_CNT;
    }

    if (fpGetDoorAjarStatus_RL(&singleDoorStatus))
    {
        doorStatus |= (singleDoorStatus & 0x01) << DOOR_AJAR_STATUS_RL_SHIFT_CNT;
    }

    if(fpGetDoorAjarStatus_RR(&singleDoorStatus))
    {
        doorStatus |= (singleDoorStatus & 0x01) << DOOR_AJAR_STATUS_RR_SHIFT_CNT;
    }

    M4Msg_Update(E_M4_AllDoorStatus_ByBit_U16, doorStatus);
}



