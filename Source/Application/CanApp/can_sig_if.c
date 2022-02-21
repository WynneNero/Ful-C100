/*------------------------------------------------------------------------------

    File Name: can_sig_if.c

    Interface implementations for accessing CAN signals.
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


#include "can_sig_defs.h"
#include "can_sig_ops.h"
#include "can_sig_if.h"
#include "il_inc.h"
#include "il_par.h"



/*------------------------------------------------------------------------------
    Function:
        can_sig_if_init
    Descriptions:
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
void can_sig_if_init(void)  //by zhaoyu. not used
{
    fpGetWheelSpeed_FL      = Get_BCS_FLWheelSpd;
    fpGetWheelSpeed_FR      = Get_BCS_FRWheelSpd;
    fpGetWheelSpeed_RL      = Get_BCS_RLWheelSpd;
    fpGetWheelSpeed_RR      = Get_BCS_RRWheelSpd;

    fpGetWheelPulseCnt_FL   = Get_ESC_FLWheelSpeedRC;
    fpGetWheelPulseCnt_FR   = Get_ESC_FRWheelSpeedRC;
    fpGetWheelPulseCnt_RL   = Get_ESC_RLWheelSpeedRC;
    fpGetWheelPulseCnt_RR   = Get_ESC_RRWheelSpeedRC;

    fpGetVehicleSpeed       = Get_BCS_VehSpd;
    fpGetEMS_BrakePedalSt	= Get_EMS_BrakePedalSt;
    fpGetStandstillStatus   = Get_ESC_Vehiclestandstill;
    fpGetEPB_SysSt         = Get_EPB_SysSt;

    fpGetEMS_GasPedalActPst = Get_EMS_GasPedalActPst;

    fpGetTCU_CurrentGearSt  = Get_TCU_CurrentGearSt;

    fpGetObstacleDist_L_FL  = Get_PAS_APA_DistanceValueLR_FL;
    fpGetObstacleDist_L_FR  = Get_PAS_APA_DistanceValueLR_FR;
    fpGetObstacleDist_L_RL  = Get_PAS_APA_DistanceValueLR_RL;
    fpGetObstacleDist_L_RR  = Get_PAS_APA_DistanceValueLR_RR;

    fpGetObstacleDist_S_FL  = Get_PAS_APA_DistanceValueSR_FL;
    fpGetObstacleDist_S_FML = Get_PAS_APA_DistanceValueSR_FML;
    fpGetObstacleDist_S_FMR = Get_PAS_APA_DistanceValueSR_FMR;
    fpGetObstacleDist_S_FR  = Get_PAS_APA_DistanceValueSR_FR;
    fpGetObstacleDist_S_RL  = Get_PAS_APA_DistanceValueSR_RL;
    fpGetObstacleDist_S_RML = Get_PAS_APA_DistanceValueSR_RML;
    fpGetObstacleDist_S_RMR = Get_PAS_APA_DistanceValueSR_RMR;
    fpGetObstacleDist_S_RR  = Get_PAS_APA_DistanceValueSR_RR;

    fpGetBCS_ActVehLongAccel  = Get_BCS_ActVehLongAccel;
    fpGetBCS_ActVehLaltrlAccel       = Get_BCS_ActVehLaltrlAccel;
    fpGetYawRate            = Get_BCS_YawRate;

    fpGetSAS_SteeringAngle    = Get_SAS_SteeringAngle;
    fpGetTurnIndicationAct  = Get_TCM_Req_TurnIndicationAct;

    fpGetSRS_DriverSeatBeltSt     = Get_SRS_DriverSeatBeltSt;

    fpGetBCM_RightTurnLampSt  = Get_BCM_LeftTurnLampSt;
    fpGetBCM_RightTurnLampSt = Get_BCM_RightTurnLampSt;
    fpGetLowBeamSt         = Get_BCM_LowBeamSt;
    fpGetHighBeamSt        = Get_BCM_HighBeamSt;
    fpGetPositionLightSts   = Get_BCM_PositionLightSts;
    fpGetFrontFogLightSts   = Get_BCM_FrontFogLightSts;
    fpGetRearFogLightSts    = Get_BCM_RearFogLightSts;

    fpGetDoorAjarStatus_FL  = Get_DDM_FrontLeftDoorAjarStatus;
    fpGetDoorAjarStatus_FR  = Get_PDM_FrontRightDoorAjarStatus;
    fpGetDoorAjarStatus_RL  = Get_DDM_RearLeftDoorAjarStatus;
    fpGetDoorAjarStatus_RR  = Get_PDM_RearRightDoorAjarStatus;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_FLWheelSpd
    Descriptions:
        BCS_FLWheelSpd
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_FLWheelSpd(float *wheelSpeed)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(BCS_FRWheelSpdVD)) && (get_sig_value_raw(BCS_FLWheelSpd) != 0x1FFF))
    {
        *wheelSpeed = get_sig_value_phy(BCS_FLWheelSpd);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_FRWheelSpd
    Descriptions:
        BCS_FRWheelSpd
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_FRWheelSpd(float *wheelSpeed)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(BCS_FRWheelSpdVD)) && (get_sig_value_raw(BCS_FRWheelSpd) != 0x1FFF))
    {
        *wheelSpeed = get_sig_value_phy(BCS_FRWheelSpd);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_RLWheelSpd
    Descriptions:
        BCS_RLWheelSpd
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_RLWheelSpd(float *wheelSpeed)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(BCS_RLWheelSpdVD)) && (get_sig_value_raw(BCS_RLWheelSpd) != 0x1FFF))
    {
        *wheelSpeed = get_sig_value_phy(BCS_RLWheelSpd);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_RRWheelSpd
    Descriptions:
        BCS_RRWheelSpd
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_RRWheelSpd(float *wheelSpeed)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(BCS_RRWheelSpdVD)) && (get_sig_value_raw(BCS_RRWheelSpd) != 0x1FFF))
    {
        *wheelSpeed = get_sig_value_phy(BCS_RRWheelSpd);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_ESC_FLWheelSpeedRC
    Descriptions:
        ESC_FLWheelSpeedRC
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_ESC_FLWheelSpeedRC(float *pulseCnt)
{
    unsigned char ret = FALSE;

    if((!get_sig_value_raw(ESC_FLWheelSpeedRCSts)))
    {
        *pulseCnt = get_sig_value_raw(ESC_FLWheelSpeedRC);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_ESC_FRWheelSpeedRC
    Descriptions:
        ESC_FRWheelSpeedRC
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_ESC_FRWheelSpeedRC(float *pulseCnt)
{
    unsigned char ret = FALSE;

    if((!get_sig_value_raw(ESC_FRWheelSpeedRCSts)))
    {
        *pulseCnt = get_sig_value_raw(ESC_FRWheelSpeedRC);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_ESC_RLWheelSpeedRC
    Descriptions:
        ESC_RLWheelSpeedRC
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_ESC_RLWheelSpeedRC(float *pulseCnt)
{
    unsigned char ret = FALSE;

    if((!get_sig_value_raw(ESC_RLWheelSpeedRCSts)))
    {
        *pulseCnt = get_sig_value_raw(ESC_RLWheelSpeedRC);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_ESC_RRWheelSpeedRC
    Descriptions:
        ESC_RRWheelSpeedRC
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_ESC_RRWheelSpeedRC(float *pulseCnt)
{
    unsigned char ret = FALSE;

    if((!get_sig_value_raw(ESC_RRWheelSpeedRCSts)))
    {
        *pulseCnt = get_sig_value_raw(ESC_RRWheelSpeedRC);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_VehSpd
    Descriptions:
        BCS_VehSpd
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_VehSpd(float *vehicleSpeed)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(BCS_VehSpdVD)))
    {
        *vehicleSpeed = get_sig_value_phy(BCS_VehSpd);//ESC_VehicleSpeed
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_EMS_BrakePedalSt
    Descriptions:
        EMS_BrakePedalSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_EMS_BrakePedalSt(unsigned char *brakeStatus)
{

    *brakeStatus = get_sig_value_raw(EMS_BrakePedalSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_ESC_Vehiclestandstill
    Descriptions:
        ESC_Vehiclestandstill
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_ESC_Vehiclestandstill(unsigned char *standstillStatus)
{
    unsigned char ret = FALSE;

    *standstillStatus = get_sig_value_raw(ESC_Vehiclestandstill);

    if(*standstillStatus != 0x2)
    {
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_EPB_SysSt
    Descriptions:
        EPB_SysSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_EPB_SysSt(unsigned char *brakeStatus)
{

    *brakeStatus = get_sig_value_raw(EPB_SysSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_EMS_GasPedalActPst
    Descriptions:
        EMS_GasPedalActPst
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_EMS_GasPedalActPst(float *pedalPos)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(EMS_GasPedalActPstVD) && (get_sig_value_raw(EMS_GasPedalActPst) < 0xFB))
    {
        *pedalPos = get_sig_value_phy(EMS_GasPedalActPst);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_TCU_CurrentGearSt
    Descriptions:
        TCU_CurrentGearSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_TCU_CurrentGearSt(unsigned char *currentGear)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(TCU_CurrentGearSt) != 0x0)
    {
        *currentGear = get_sig_value_raw(TCU_CurrentGearSt);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueLR_FL
    Descriptions:
        PAS_APA_DistanceValueLR_FL
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueLR_FL(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueLR_FL) != 0xFF)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueLR_FL);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueLR_FR
    Descriptions:
        PAS_APA_DistanceValueLR_FR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueLR_FR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueLR_FR) != 0xFF)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueLR_FR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueLR_RL
    Descriptions:
        PAS_APA_DistanceValueLR_RL
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueLR_RL(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueLR_RL) != 0xFF)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueLR_RL);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueLR_RR
    Descriptions:
        PAS_APA_DistanceValueLR_RR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueLR_RR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueLR_RR) != 0xFF)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueLR_RR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_FL
    Descriptions:
        PAS_APA_DistanceValueSR_FL
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_FL(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_FL) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_FL);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_FML
    Descriptions:
        PAS_APA_DistanceValueSR_FML
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_FML(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_FML) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_FML);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_FMR
    Descriptions:
        PAS_APA_DistanceValueSR_FMR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_FMR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_FMR) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_FMR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_FR
    Descriptions:
        PAS_APA_DistanceValueSR_FR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_FR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_FR) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_FR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_RL
    Descriptions:
        PAS_APA_DistanceValueSR_RL
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_RL(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_RL) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_RL);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_RML
    Descriptions:
        PAS_APA_DistanceValueSR_RML
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_RML(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_RML) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_RML);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_RMR
    Descriptions:
        PAS_APA_DistanceValueSR_RMR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_RMR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_RMR) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_RMR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PAS_APA_DistanceValueSR_RR
    Descriptions:
        PAS_APA_DistanceValueSR_RR
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PAS_APA_DistanceValueSR_RR(float *distanceVal)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(PAS_APA_DistanceValueSR_RR) != 0x7F)
    {
        *distanceVal = get_sig_value_phy(PAS_APA_DistanceValueSR_RR);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_ActVehLongAccel
    Descriptions:
        BCS_ActVehLongAccel
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_ActVehLongAccel(float *longitAccel)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(BCS_ActVehLongAccel) < 0x0FA1)
    {
        *longitAccel = get_sig_value_phy(BCS_ActVehLongAccel);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_ActVehLaltrlAccel
    Descriptions:
        BCS_ActVehLaltrlAccel
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_ActVehLaltrlAccel(float *lateralAccel)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(BCS_ActVehLaltrlAccel) < 0x0FA1)
    {
        *lateralAccel = get_sig_value_phy(BCS_ActVehLaltrlAccel);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCS_YawRate
    Descriptions:
        BCS_YawRate
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCS_YawRate(float *yawRate)
{
    unsigned char ret = FALSE;

    if(get_sig_value_raw(BCS_YawRate) < 0x8CA1)
    {
        *yawRate = get_sig_value_phy(BCS_YawRate);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_SAS_SteeringAngle
    Descriptions:
        SAS_SteeringAngle
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_SAS_SteeringAngle(float *steerAngle)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(SAS_SteeringAngleVD)))
    {
        *steerAngle = get_sig_value_phy(SAS_SteeringAngle);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_TCM_Req_TurnIndicationAct
    Descriptions:
        TCM_Req_TurnIndicationAct
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_TCM_Req_TurnIndicationAct(unsigned char *turnInd)
{
    unsigned char ret = FALSE;

    if((get_sig_value_raw(TCM_Req_TurnIndicationAct) != 0x3))
    {
        *turnInd = get_sig_value_raw(TCM_Req_TurnIndicationAct);
        ret = TRUE;
    }

    return ret;
}


/*------------------------------------------------------------------------------
    Function:
        Get_SRS_DriverSeatBeltSt
    Descriptions:
        SRS_DriverSeatBeltSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_SRS_DriverSeatBeltSt(unsigned char *buckleStatus)
{

    *buckleStatus = get_sig_value_raw(SRS_DriverSeatBeltSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_LeftTurnLampSt
    Descriptions:
        BCM_LeftTurnLampSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_LeftTurnLampSt(unsigned char *turnInd)
{

    *turnInd = get_sig_value_raw(BCM_LeftTurnLampSt);

    return TRUE;
}

/*------------------------------------------------------------------------------
    Function:
        Get_BCM_RightTurnLampSt
    Descriptions:
        BCM_RightTurnLampSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_RightTurnLampSt(unsigned char *turnInd)
{

    *turnInd = get_sig_value_raw(BCM_RightTurnLampSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_LowBeamSt
    Descriptions:
        BCM_LowBeamSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_LowBeamSt(unsigned char *lightStatus)
{

    *lightStatus = get_sig_value_raw(BCM_LowBeamSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_HighBeamSt
    Descriptions:
        BCM_HighBeamSt
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_HighBeamSt(unsigned char *lightStatus)
{

    *lightStatus = get_sig_value_raw(BCM_HighBeamSt);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_PositionLightSts
    Descriptions:
        BCM_PositionLightSts
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_PositionLightSts(unsigned char *lightStatus)
{

    *lightStatus = get_sig_value_raw(BCM_PositionLightSts);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_FrontFogLightSts
    Descriptions:
        BCM_FrontFogLightSts
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_FrontFogLightSts(unsigned char *lightStatus)
{

    *lightStatus = get_sig_value_raw(BCM_FrontFogLightSts);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_BCM_RearFogLightSts
    Descriptions:
        BCM_RearFogLightSts
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_BCM_RearFogLightSts(unsigned char *lightStatus)
{

    *lightStatus = get_sig_value_raw(BCM_RearFogLightSts);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_DDM_FrontLeftDoorAjarStatus
    Descriptions:
        DDM_FrontLeftDoorAjarStatus
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_DDM_FrontLeftDoorAjarStatus(unsigned char *FLDoorAjarSts)
{

    *FLDoorAjarSts = get_sig_value_raw(DDM_FrontLeftDoorAjarStatus);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_DDM_RearLeftDoorAjarStatus
    Descriptions:
        DDM_RearLeftDoorAjarStatus
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_DDM_RearLeftDoorAjarStatus(unsigned char *doorStatus)
{

    *doorStatus = get_sig_value_raw(DDM_RearLeftDoorAjarStatus);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PDM_FrontRightDoorAjarStatus
    Descriptions:
        PDM_FrontRightDoorAjarStatus
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PDM_FrontRightDoorAjarStatus(unsigned char *doorStatus)
{

    *doorStatus = get_sig_value_raw(PDM_FrontRightDoorAjarStatus);

    return TRUE;
}


/*------------------------------------------------------------------------------
    Function:
        Get_PDM_RearRightDoorAjarStatus
    Descriptions:
        PDM_RearRightDoorAjarStatus
    Parameters:
    Return:
-------------------------------------------------------------------------------*/
unsigned char Get_PDM_RearRightDoorAjarStatus(unsigned char *doorStatus)
{

    *doorStatus = get_sig_value_raw(PDM_RearRightDoorAjarStatus);

    return TRUE;
}



