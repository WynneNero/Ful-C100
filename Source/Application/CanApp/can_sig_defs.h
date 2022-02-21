/*------------------------------------------------------------------------------

    File Name: can_sig_defs.h

    CAN signal definitions.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    Sun Yilin       uida3867        Desay SV HZH / IDA R&D

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


#ifndef _CAN_SIG_DEFS_H_
#define _CAN_SIG_DEFS_H_


/* 0x84 - EMS_EngRelateTrqSts */
/*----------------------------------------------------------------------------*/

#if 0
/* EMS_CruiseControlSts */
#define EMS_CruiseControlSts_factor     1
#define EMS_CruiseControlSts_offset     0
#define EMS_CruiseControlSts_signed     0
#define EMS_CruiseControlSts_bitlen     3
#endif

/* EMS_GasPedalActPstVD */
#define EMS_GasPedalActPstVD_factor     1
#define EMS_GasPedalActPstVD_offset     0
#define EMS_GasPedalActPstVD_signed     0
#define EMS_GasPedalActPstVD_bitlen     1

#if 0
/* EMS_ClutchPedalTopPosSwitch */
#define EMS_ClutchPedalTopPosSwitch_factor     1
#define EMS_ClutchPedalTopPosSwitch_offset     0
#define EMS_ClutchPedalTopPosSwitch_signed     0
#define EMS_ClutchPedalTopPosSwitch_bitlen     1
#endif

/* EMS_GasPedalActPst */
#define EMS_GasPedalActPst_factor     0.392
#define EMS_GasPedalActPst_offset     0
#define EMS_GasPedalActPst_signed     0
#define EMS_GasPedalActPst_bitlen     8

#if 0
/* EMS_N_GearInfo */
#define EMS_N_GearInfo_factor     1
#define EMS_N_GearInfo_offset     0
#define EMS_N_GearInfo_signed     0
#define EMS_N_GearInfo_bitlen     1

/* EMS_RespondedTorqueType */
#define EMS_RespondedTorqueType_factor     1
#define EMS_RespondedTorqueType_offset     0
#define EMS_RespondedTorqueType_signed     0
#define EMS_RespondedTorqueType_bitlen     3

/* EMS_MinEngTorque */
#define EMS_MinEngTorque_factor     0.5
#define EMS_MinEngTorque_offset     -1000
#define EMS_MinEngTorque_signed     0
#define EMS_MinEngTorque_bitlen     12

/* EMS_EngRelateTrqSts_AliveCounter */
#define EMS_EngRelateTrqSts_AliveCounter_factor     1
#define EMS_EngRelateTrqSts_AliveCounter_offset     0
#define EMS_EngRelateTrqSts_AliveCounter_signed     0
#define EMS_EngRelateTrqSts_AliveCounter_bitlen     4

/* EMS_MaxEngTorque */
#define EMS_MaxEngTorque_factor     0.5
#define EMS_MaxEngTorque_offset     -1000
#define EMS_MaxEngTorque_signed     0
#define EMS_MaxEngTorque_bitlen     12

/* EMS_EngRelateTrqSts_Checksum */
#define EMS_EngRelateTrqSts_Checksum_factor     1
#define EMS_EngRelateTrqSts_Checksum_offset     0
#define EMS_EngRelateTrqSts_Checksum_signed     0
#define EMS_EngRelateTrqSts_Checksum_bitlen     8
#endif


/* 0x85 - EMS_EngineRPM */
/*----------------------------------------------------------------------------*/

#if 0
/* EMS_ClutchPedalPosition_Reserved */
#define EMS_ClutchPedalPosition_Reserved_factor     0.4
#define EMS_ClutchPedalPosition_Reserved_offset     0
#define EMS_ClutchPedalPosition_Reserved_signed     0
#define EMS_ClutchPedalPosition_Reserved_bitlen     8

/* EMS_EngineSpeedRPM */
#define EMS_EngineSpeedRPM_factor     0.25
#define EMS_EngineSpeedRPM_offset     0
#define EMS_EngineSpeedRPM_signed     0
#define EMS_EngineSpeedRPM_bitlen     16

/* EMS_EngineRPM_Checksum */
#define EMS_EngineRPM_Checksum_factor     1
#define EMS_EngineRPM_Checksum_offset     0
#define EMS_EngineRPM_Checksum_signed     0
#define EMS_EngineRPM_Checksum_bitlen     8
#endif

/* EMS_SSMStatus */
#define EMS_SSMStatus_factor     1
#define EMS_SSMStatus_offset     0
#define EMS_SSMStatus_signed     0
#define EMS_SSMStatus_bitlen     3

#if 0
/* EMS_EngineSpeedRPMInvalid */
#define EMS_EngineSpeedRPMInvalid_factor     1
#define EMS_EngineSpeedRPMInvalid_offset     0
#define EMS_EngineSpeedRPMInvalid_signed     0
#define EMS_EngineSpeedRPMInvalid_bitlen     1
#endif

/* EMS_EngSt */
#define EMS_EngSt_factor     1
#define EMS_EngSt_offset     0
#define EMS_EngSt_signed     0
#define EMS_EngSt_bitlen     1

#if 0
/* EMS_AccelPedalPosition */
#define EMS_AccelPedalPosition_factor     0.4
#define EMS_AccelPedalPosition_offset     0
#define EMS_AccelPedalPosition_signed     0
#define EMS_AccelPedalPosition_bitlen     8

/* EMS_AccelPedalPositionInvalid */
#define EMS_AccelPedalPositionInvalid_factor     1
#define EMS_AccelPedalPositionInvalid_offset     0
#define EMS_AccelPedalPositionInvalid_signed     0
#define EMS_AccelPedalPositionInvalid_bitlen     1

/* EMS_EngineRPM_AliveCounter */
#define EMS_EngineRPM_AliveCounter_factor     1
#define EMS_EngineRPM_AliveCounter_offset     0
#define EMS_EngineRPM_AliveCounter_signed     0
#define EMS_EngineRPM_AliveCounter_bitlen     4
#endif


/* 0xE0 - SAS_Status */
/*----------------------------------------------------------------------------*/

/* SAS_SteeringAngle */
#define SAS_SteeringAngle_factor     0.1
#define SAS_SteeringAngle_offset    -780
#define SAS_SteeringAngle_signed     1
#define SAS_SteeringAngle_bitlen     16

#if 0
/* SAS_SteerWheelRotSpd */
#define SAS_SteerWheelRotSpd_factor     4
#define SAS_SteerWheelRotSpd_offset     0
#define SAS_SteerWheelRotSpd_signed     0
#define SAS_SteerWheelRotSpd_bitlen     8

/* SAS_TrimmingSts */
#define SAS_TrimmingSts_factor     1
#define SAS_TrimmingSts_offset     0
#define SAS_TrimmingSts_signed     0
#define SAS_TrimmingSts_bitlen     1
#endif

/* SAS_CalibrationSts */
#define SAS_CalibrationSts_factor     1
#define SAS_CalibrationSts_offset     0
#define SAS_CalibrationSts_signed     0
#define SAS_CalibrationSts_bitlen     1

/* SAS_SteeringAngleVD */
#define SAS_SteeringAngleVD_factor     1
#define SAS_SteeringAngleVD_offset     0
#define SAS_SteeringAngleVD_signed     0
#define SAS_SteeringAngleVD_bitlen     1

/* TCM_SteeringWheel_rotation_flag */
#define TCM_SteeringWheel_rotation_flag_factor     1
#define TCM_SteeringWheel_rotation_flag_offset     0
#define TCM_SteeringWheel_rotation_flag_signed     0
#define TCM_SteeringWheel_rotation_flag_bitlen     1

/* SAS_Status_AliveCounter */
#define SAS_Status_AliveCounter_factor     1
#define SAS_Status_AliveCounter_offset     0
#define SAS_Status_AliveCounter_signed     0
#define SAS_Status_AliveCounter_bitlen     4

/* SAS_Status_Checksum */
#define SAS_Status_Checksum_factor     1
#define SAS_Status_Checksum_offset     0
#define SAS_Status_Checksum_signed     0
#define SAS_Status_Checksum_bitlen     8


/* 0x113 - TCU_Status */
/*----------------------------------------------------------------------------*/

#if 0
/* TCU_GearShiftInProgress */
#define TCU_GearShiftInProgress_factor     1
#define TCU_GearShiftInProgress_offset     0
#define TCU_GearShiftInProgress_signed     0
#define TCU_GearShiftInProgress_bitlen     1

/* TCU_ShiftGarageActive */
#define TCU_ShiftGarageActive_factor     1
#define TCU_ShiftGarageActive_offset     0
#define TCU_ShiftGarageActive_signed     0
#define TCU_ShiftGarageActive_bitlen     1

/* TCU_ClutchState */
#define TCU_ClutchState_factor     1
#define TCU_ClutchState_offset     0
#define TCU_ClutchState_signed     0
#define TCU_ClutchState_bitlen     3

/* TCU_ClutchOddState */
#define TCU_ClutchOddState_factor     1
#define TCU_ClutchOddState_offset     0
#define TCU_ClutchOddState_signed     0
#define TCU_ClutchOddState_bitlen     2

/* TCU_ClutchEvenState */
#define TCU_ClutchEvenState_factor     1
#define TCU_ClutchEvenState_offset     0
#define TCU_ClutchEvenState_signed     0
#define TCU_ClutchEvenState_bitlen     2
#endif

/* TCU_ESC_DriverGearAbort */
#define TCU_ESC_DriverGearAbort_factor     1
#define TCU_ESC_DriverGearAbort_offset     0
#define TCU_ESC_DriverGearAbort_signed     0
#define TCU_ESC_DriverGearAbort_bitlen     1

#if 0
/* TCU_TargetGearReq */
#define TCU_TargetGearReq_factor     1
#define TCU_TargetGearReq_offset     0
#define TCU_TargetGearReq_signed     0
#define TCU_TargetGearReq_bitlen     4

/* TCU_CurrentGearPosition */
#define TCU_CurrentGearPosition_factor     1
#define TCU_CurrentGearPosition_offset     0
#define TCU_CurrentGearPosition_signed     0
#define TCU_CurrentGearPosition_bitlen     4
#endif

/* TCU_CurrentGearSt */
#define TCU_CurrentGearSt_factor     1
#define TCU_CurrentGearSt_offset     0
#define TCU_CurrentGearSt_signed     0
#define TCU_CurrentGearSt_bitlen     4

#if 0
/* TCU_Status_AliveCounter */
#define TCU_Status_AliveCounter_factor     1
#define TCU_Status_AliveCounter_offset     0
#define TCU_Status_AliveCounter_signed     0
#define TCU_Status_AliveCounter_bitlen     4

/* TCU_Status_Checksum */
#define TCU_Status_Checksum_factor     1
#define TCU_Status_Checksum_offset     0
#define TCU_Status_Checksum_signed     0
#define TCU_Status_Checksum_bitlen     8
#endif


/* 0x121 - ESC_VLC_TorqueRequest */
/*----------------------------------------------------------------------------*/

#if 0
/* ESC_VLC_CDD_available */
#define ESC_VLC_CDD_available_factor     1
#define ESC_VLC_CDD_available_offset     0
#define ESC_VLC_CDD_available_signed     0
#define ESC_VLC_CDD_available_bitlen     1

/* ESC_VLC_CDD_active */
#define ESC_VLC_CDD_active_factor     1
#define ESC_VLC_CDD_active_offset     0
#define ESC_VLC_CDD_active_signed     0
#define ESC_VLC_CDD_active_bitlen     1

/* ESC_VLC_EngTrqReqActive */
#define ESC_VLC_EngTrqReqActive_factor     1
#define ESC_VLC_EngTrqReqActive_offset     0
#define ESC_VLC_EngTrqReqActive_signed     0
#define ESC_VLC_EngTrqReqActive_bitlen     1

/* ESC_VLC_EngTrqReq */
#define ESC_VLC_EngTrqReq_factor     0.5
#define ESC_VLC_EngTrqReq_offset     -1000
#define ESC_VLC_EngTrqReq_signed     0
#define ESC_VLC_EngTrqReq_bitlen     12

/* ESC_VLC_Active */
#define ESC_VLC_Active_factor     1
#define ESC_VLC_Active_offset     0
#define ESC_VLC_Active_signed     0
#define ESC_VLC_Active_bitlen     1

/* ESC_VLC_Available */
#define ESC_VLC_Available_factor     1
#define ESC_VLC_Available_offset     0
#define ESC_VLC_Available_signed     0
#define ESC_VLC_Available_bitlen     1

/* ESC_VLC_Fail */
#define ESC_VLC_Fail_factor     1
#define ESC_VLC_Fail_offset     0
#define ESC_VLC_Fail_signed     0
#define ESC_VLC_Fail_bitlen     2
#endif

/* ESC_VLC_InternalTargetACCeleration */
#define ESC_VLC_InternalTargetACCeleration_factor     0.05
#define ESC_VLC_InternalTargetACCeleration_offset     -7
#define ESC_VLC_InternalTargetACCeleration_signed     0
#define ESC_VLC_InternalTargetACCeleration_bitlen     8

#if 0
/* ESC_VLC_PTTrqReq */
#define ESC_VLC_PTTrqReq_factor     1
#define ESC_VLC_PTTrqReq_offset     -6000
#define ESC_VLC_PTTrqReq_signed     0
#define ESC_VLC_PTTrqReq_bitlen     16
#endif

/* ESC_VLC_TorqueRequest_AliveCounter */
#define ESC_VLC_TorqueRequest_AliveCounter_factor     1
#define ESC_VLC_TorqueRequest_AliveCounter_offset     0
#define ESC_VLC_TorqueRequest_AliveCounter_signed     0
#define ESC_VLC_TorqueRequest_AliveCounter_bitlen     4

#if 0
/* ESC_VLC_PTTrqReqActive */
#define ESC_VLC_PTTrqReqActive_factor     1
#define ESC_VLC_PTTrqReqActive_offset     0
#define ESC_VLC_PTTrqReqActive_signed     0
#define ESC_VLC_PTTrqReqActive_bitlen     1
#endif

/* ESC_VLC_TorqueRequest_Checksum */
#define ESC_VLC_TorqueRequest_Checksum_factor     1
#define ESC_VLC_TorqueRequest_Checksum_offset     0
#define ESC_VLC_TorqueRequest_Checksum_signed     0
#define ESC_VLC_TorqueRequest_Checksum_bitlen     8


/* 0x122 - ESC_FrontWheelSpeedsKPH */
/*----------------------------------------------------------------------------*/

/* BCS_FLWheelSpdVD */
#define BCS_FLWheelSpdVD_factor     1
#define BCS_FLWheelSpdVD_offset     0
#define BCS_FLWheelSpdVD_signed     0
#define BCS_FLWheelSpdVD_bitlen     1

/* ESC_FLWheelDirection */
#define ESC_FLWheelDirection_factor     1
#define ESC_FLWheelDirection_offset     0
#define ESC_FLWheelDirection_signed     0
#define ESC_FLWheelDirection_bitlen     2

/* BCS_FLWheelSpd */
#define BCS_FLWheelSpd_factor     0.05625
#define BCS_FLWheelSpd_offset     0
#define BCS_FLWheelSpd_signed     0
#define BCS_FLWheelSpd_bitlen     13

/* BCS_FRWheelSpdVD */
#define BCS_FRWheelSpdVD_factor     1
#define BCS_FRWheelSpdVD_offset     0
#define BCS_FRWheelSpdVD_signed     0
#define BCS_FRWheelSpdVD_bitlen     1

/* ESC_FRWheelDirection */
#define ESC_FRWheelDirection_factor     1
#define ESC_FRWheelDirection_offset     0
#define ESC_FRWheelDirection_signed     0
#define ESC_FRWheelDirection_bitlen     2

/* BCS_FRWheelSpd */
#define BCS_FRWheelSpd_factor     0.05625
#define BCS_FRWheelSpd_offset     0
#define BCS_FRWheelSpd_signed     0
#define BCS_FRWheelSpd_bitlen     13

#if 0
/* ESC_Mcylinder_Pressure */
#define ESC_Mcylinder_Pressure_factor     1
#define ESC_Mcylinder_Pressure_offset     0
#define ESC_Mcylinder_Pressure_signed     0
#define ESC_Mcylinder_Pressure_bitlen     8

/* ESC_VirtualMcylinderPressure */
#define ESC_VirtualMcylinderPressure_factor     1
#define ESC_VirtualMcylinderPressure_offset     0
#define ESC_VirtualMcylinderPressure_signed     0
#define ESC_VirtualMcylinderPressure_bitlen     8
#endif

/* ESC_FrontWheelSpeedsKPH_AliveCounter */
#define ESC_FrontWheelSpeedsKPH_AliveCounter_factor     1
#define ESC_FrontWheelSpeedsKPH_AliveCounter_offset     0
#define ESC_FrontWheelSpeedsKPH_AliveCounter_signed     0
#define ESC_FrontWheelSpeedsKPH_AliveCounter_bitlen     4

#if 0
/* ESC_Mcylinder_PressureInvalid */
#define ESC_Mcylinder_PressureInvalid_factor     1
#define ESC_Mcylinder_PressureInvalid_offset     0
#define ESC_Mcylinder_PressureInvalid_signed     0
#define ESC_Mcylinder_PressureInvalid_bitlen     1

/* ESC_VirtualMcylinderPressureInvalid */
#define ESC_VirtualMcylinderPressureInvalid_factor     1
#define ESC_VirtualMcylinderPressureInvalid_offset     0
#define ESC_VirtualMcylinderPressureInvalid_signed     0
#define ESC_VirtualMcylinderPressureInvalid_bitlen     1
#endif

/* ESC_FrontWheelSpeedsKPH_Checksum */
#define ESC_FrontWheelSpeedsKPH_Checksum_factor     1
#define ESC_FrontWheelSpeedsKPH_Checksum_offset     0
#define ESC_FrontWheelSpeedsKPH_Checksum_signed     0
#define ESC_FrontWheelSpeedsKPH_Checksum_bitlen     8


/* 0x123 - ESC_RearWheelSpeedsKPH */
/*----------------------------------------------------------------------------*/

/* BCS_RLWheelSpdVD */
#define BCS_RLWheelSpdVD_factor     1
#define BCS_RLWheelSpdVD_offset     0
#define BCS_RLWheelSpdVD_signed     0
#define BCS_RLWheelSpdVD_bitlen     1

/* BCS_RLWheelRotatedDirectionAPA */
#define BCS_RLWheelRotatedDirectionAPA_factor     1
#define BCS_RLWheelRotatedDirectionAPA_offset     0
#define BCS_RLWheelRotatedDirectionAPA_signed     0
#define BCS_RLWheelRotatedDirectionAPA_bitlen     2

/* BCS_RLWheelSpd */
#define BCS_RLWheelSpd_factor     0.05625
#define BCS_RLWheelSpd_offset     0
#define BCS_RLWheelSpd_signed     0
#define BCS_RLWheelSpd_bitlen     13

/* BCS_RRWheelSpdVD */
#define BCS_RRWheelSpdVD_factor     1
#define BCS_RRWheelSpdVD_offset     0
#define BCS_RRWheelSpdVD_signed     0
#define BCS_RRWheelSpdVD_bitlen     1

/* BCS_RRWheelRotatedDirectionAPA */
#define BCS_RRWheelRotatedDirectionAPA_factor     1
#define BCS_RRWheelRotatedDirectionAPA_offset     0
#define BCS_RRWheelRotatedDirectionAPA_signed     0
#define BCS_RRWheelRotatedDirectionAPA_bitlen     2

/* BCS_RRWheelSpd */
#define BCS_RRWheelSpd_factor     0.05625
#define BCS_RRWheelSpd_offset     0
#define BCS_RRWheelSpd_signed     0
#define BCS_RRWheelSpd_bitlen     13

#if 0
/* ESC_BrkFricTqTotAtWhlsInvalid */
#define ESC_BrkFricTqTotAtWhlsInvalid_factor     1
#define ESC_BrkFricTqTotAtWhlsInvalid_offset     0
#define ESC_BrkFricTqTotAtWhlsInvalid_signed     0
#define ESC_BrkFricTqTotAtWhlsInvalid_bitlen     1

/* ESC_BrkFricTqTotAtWhls */
#define ESC_BrkFricTqTotAtWhls_factor     1
#define ESC_BrkFricTqTotAtWhls_offset     0
#define ESC_BrkFricTqTotAtWhls_signed     0
#define ESC_BrkFricTqTotAtWhls_bitlen     14
#endif

/* ESC_RearWheelSpeedsKPH_AliveCounter */
#define ESC_RearWheelSpeedsKPH_AliveCounter_factor     1
#define ESC_RearWheelSpeedsKPH_AliveCounter_offset     0
#define ESC_RearWheelSpeedsKPH_AliveCounter_signed     0
#define ESC_RearWheelSpeedsKPH_AliveCounter_bitlen     4

/* ESC_RearWheelSpeedsKPH_Checksum */
#define ESC_RearWheelSpeedsKPH_Checksum_factor     1
#define ESC_RearWheelSpeedsKPH_Checksum_offset     0
#define ESC_RearWheelSpeedsKPH_Checksum_signed     0
#define ESC_RearWheelSpeedsKPH_Checksum_bitlen     8


/* 0x124 - ESC_WheelSpeedsRC */
/*----------------------------------------------------------------------------*/

/* ESC_FLWheelSpeedRC */
#define ESC_FLWheelSpeedRC_factor     1
#define ESC_FLWheelSpeedRC_offset     0
#define ESC_FLWheelSpeedRC_signed     0
#define ESC_FLWheelSpeedRC_bitlen     12

/* ESC_FRWheelSpeedRC */
#define ESC_FRWheelSpeedRC_factor     1
#define ESC_FRWheelSpeedRC_offset     0
#define ESC_FRWheelSpeedRC_signed     0
#define ESC_FRWheelSpeedRC_bitlen     12

/* ESC_RLWheelSpeedRC */
#define ESC_RLWheelSpeedRC_factor     1
#define ESC_RLWheelSpeedRC_offset     0
#define ESC_RLWheelSpeedRC_signed     0
#define ESC_RLWheelSpeedRC_bitlen     12

/* ESC_RRWheelSpeedRC */
#define ESC_RRWheelSpeedRC_factor     1
#define ESC_RRWheelSpeedRC_offset     0
#define ESC_RRWheelSpeedRC_signed     0
#define ESC_RRWheelSpeedRC_bitlen     12

/* ESC_FLWheelSpeedRCSts */
#define ESC_FLWheelSpeedRCSts_factor     1
#define ESC_FLWheelSpeedRCSts_offset     0
#define ESC_FLWheelSpeedRCSts_signed     0
#define ESC_FLWheelSpeedRCSts_bitlen     1

/* ESC_FRWheelSpeedRCSts */
#define ESC_FRWheelSpeedRCSts_factor     1
#define ESC_FRWheelSpeedRCSts_offset     0
#define ESC_FRWheelSpeedRCSts_signed     0
#define ESC_FRWheelSpeedRCSts_bitlen     1

/* ESC_RLWheelSpeedRCSts */
#define ESC_RLWheelSpeedRCSts_factor     1
#define ESC_RLWheelSpeedRCSts_offset     0
#define ESC_RLWheelSpeedRCSts_signed     0
#define ESC_RLWheelSpeedRCSts_bitlen     1

/* ESC_RRWheelSpeedRCSts */
#define ESC_RRWheelSpeedRCSts_factor     1
#define ESC_RRWheelSpeedRCSts_offset     0
#define ESC_RRWheelSpeedRCSts_signed     0
#define ESC_RRWheelSpeedRCSts_bitlen     1

/* ESC_WheelSpeedsRC_AliveCounter */
#define ESC_WheelSpeedsRC_AliveCounter_factor     1
#define ESC_WheelSpeedsRC_AliveCounter_offset     0
#define ESC_WheelSpeedsRC_AliveCounter_signed     0
#define ESC_WheelSpeedsRC_AliveCounter_bitlen     4

/* ESC_WheelSpeedsRC_Checksum */
#define ESC_WheelSpeedsRC_Checksum_factor     1
#define ESC_WheelSpeedsRC_Checksum_offset     0
#define ESC_WheelSpeedsRC_Checksum_signed     0
#define ESC_WheelSpeedsRC_Checksum_bitlen     8


/* 0x125 - ESC_Status */
/*----------------------------------------------------------------------------*/

/* ESC_ABSActive */
#define ESC_ABSActive_factor     1
#define ESC_ABSActive_offset     0
#define ESC_ABSActive_signed     0
#define ESC_ABSActive_bitlen     1

/* EMS_BrakePedalSt */
#define EMS_BrakePedalSt_factor     1
#define EMS_BrakePedalSt_offset     0
#define EMS_BrakePedalSt_signed     0
#define EMS_BrakePedalSt_bitlen     1

/* BCS_EBDFaultSt */
#define BCS_EBDFaultSt_factor     1
#define BCS_EBDFaultSt_offset     0
#define BCS_EBDFaultSt_signed     0
#define BCS_EBDFaultSt_bitlen     1

/* BCS_ABSFaultSt */
#define BCS_ABSFaultSt_factor     1
#define BCS_ABSFaultSt_offset     0
#define BCS_ABSFaultSt_signed     0
#define BCS_ABSFaultSt_bitlen     1

/* BCS_TCSActiveSt */
#define BCS_TCSActiveSt_factor     1
#define BCS_TCSActiveSt_offset     0
#define BCS_TCSActiveSt_signed     0
#define BCS_TCSActiveSt_bitlen     1

/* ESC_ESPActive */
#define ESC_ESPActive_factor     1
#define ESC_ESPActive_offset     0
#define ESC_ESPActive_signed     0
#define ESC_ESPActive_bitlen     1

/* ESC_TCSFailed */
#define ESC_TCSFailed_factor     1
#define ESC_TCSFailed_offset     0
#define ESC_TCSFailed_signed     0
#define ESC_TCSFailed_bitlen     1

/* ESC_ESPFailed */
#define ESC_ESPFailed_factor     1
#define ESC_ESPFailed_offset     0
#define ESC_ESPFailed_signed     0
#define ESC_ESPFailed_bitlen     1

#if 0
/* ESC_PATAResponse */
#define ESC_PATAResponse_factor     1
#define ESC_PATAResponse_offset     0
#define ESC_PATAResponse_signed     0
#define ESC_PATAResponse_bitlen     1

/* ESC_LampInfo */
#define ESC_LampInfo_factor     1
#define ESC_LampInfo_offset     0
#define ESC_LampInfo_signed     0
#define ESC_LampInfo_bitlen     1
#endif

/* BCS_VehSpdVD */
#define BCS_VehSpdVD_factor     1
#define BCS_VehSpdVD_offset     0
#define BCS_VehSpdVD_signed     0
#define BCS_VehSpdVD_bitlen     1

/* BCS_VehSpd */
#define BCS_VehSpd_factor     0.05625
#define BCS_VehSpd_offset     0
#define BCS_VehSpd_signed     0
#define BCS_VehSpd_bitlen     13

#if 0
/* ESC_LdmBLC */
#define ESC_LdmBLC_factor     1
#define ESC_LdmBLC_offset     0
#define ESC_LdmBLC_signed     0
#define ESC_LdmBLC_bitlen     1

/* ESC_AVHStatus */
#define ESC_AVHStatus_factor     1
#define ESC_AVHStatus_offset     0
#define ESC_AVHStatus_signed     0
#define ESC_AVHStatus_bitlen     2
#endif

/* EPB_SysSt */
#define EPB_SysSt_factor     1
#define EPB_SysSt_offset     0
#define EPB_SysSt_signed     0
#define EPB_SysSt_bitlen     3

/* ESC_EPBErrorStatus */
#define ESC_EPBErrorStatus_factor     1
#define ESC_EPBErrorStatus_offset     0
#define ESC_EPBErrorStatus_signed     0
#define ESC_EPBErrorStatus_bitlen     1

/* EMS_BrakePedalStVD */
#define EMS_BrakePedalStVD_factor     1
#define EMS_BrakePedalStVD_offset     0
#define EMS_BrakePedalStVD_signed     0
#define EMS_BrakePedalStVD_bitlen     1

/* ESC_GearShiftInhibit */
#define ESC_GearShiftInhibit_factor     1
#define ESC_GearShiftInhibit_offset     0
#define ESC_GearShiftInhibit_signed     0
#define ESC_GearShiftInhibit_bitlen     1

#if 0
/* ESC_BrakePedalPosition */
#define ESC_BrakePedalPosition_factor     0.4
#define ESC_BrakePedalPosition_offset     0
#define ESC_BrakePedalPosition_signed     0
#define ESC_BrakePedalPosition_bitlen     8
#endif

/* ESC_HHCActive */
#define ESC_HHCActive_factor     1
#define ESC_HHCActive_offset     0
#define ESC_HHCActive_signed     0
#define ESC_HHCActive_bitlen     1

#if 0
/* ESC_HHC_ErrorStatus */
#define ESC_HHC_ErrorStatus_factor     1
#define ESC_HHC_ErrorStatus_offset     0
#define ESC_HHC_ErrorStatus_signed     0
#define ESC_HHC_ErrorStatus_bitlen     1

/* ESC_HDC_ErrorStatus */
#define ESC_HDC_ErrorStatus_factor     1
#define ESC_HDC_ErrorStatus_offset     0
#define ESC_HDC_ErrorStatus_signed     0
#define ESC_HDC_ErrorStatus_bitlen     1

/* ESC_HDC_Active */
#define ESC_HDC_Active_factor     1
#define ESC_HDC_Active_offset     0
#define ESC_HDC_Active_signed     0
#define ESC_HDC_Active_bitlen     2

/* ESC_DM_ShiftAllowed */
#define ESC_DM_ShiftAllowed_factor     1
#define ESC_DM_ShiftAllowed_offset     0
#define ESC_DM_ShiftAllowed_signed     0
#define ESC_DM_ShiftAllowed_bitlen     1

/* ESC_BrakePedalPositionInvalid */
#define ESC_BrakePedalPositionInvalid_factor     1
#define ESC_BrakePedalPositionInvalid_offset     0
#define ESC_BrakePedalPositionInvalid_signed     0
#define ESC_BrakePedalPositionInvalid_bitlen     1
#endif

/* ESC_Status_AliveCounter */
#define ESC_Status_AliveCounter_factor     1
#define ESC_Status_AliveCounter_offset     0
#define ESC_Status_AliveCounter_signed     0
#define ESC_Status_AliveCounter_bitlen     4

#if 0
/* ESC_HAZActive */
#define ESC_HAZActive_factor     1
#define ESC_HAZActive_offset     0
#define ESC_HAZActive_signed     0
#define ESC_HAZActive_bitlen     1
#endif

/* ESC_HBB_Interv */
#define ESC_HBB_Interv_factor     1
#define ESC_HBB_Interv_offset     0
#define ESC_HBB_Interv_signed     0
#define ESC_HBB_Interv_bitlen     1

#if 0
/* ESC_HBB_Sts */
#define ESC_HBB_Sts_factor     1
#define ESC_HBB_Sts_offset     0
#define ESC_HBB_Sts_signed     0
#define ESC_HBB_Sts_bitlen     2
#endif

/* ESC_Status_Checksum */
#define ESC_Status_Checksum_factor     1
#define ESC_Status_Checksum_offset     0
#define ESC_Status_Checksum_signed     0
#define ESC_Status_Checksum_bitlen     8


/* 0x126 - ESC_DA_MESSAGE */
/*----------------------------------------------------------------------------*/

#if 0
/* ESC_NoBrakeForce */
#define ESC_NoBrakeForce_factor     1
#define ESC_NoBrakeForce_offset     0
#define ESC_NoBrakeForce_signed     0
#define ESC_NoBrakeForce_bitlen     1
#endif

/* ESC_DiagExtModSts */
#define ESC_DiagExtModSts_factor     1
#define ESC_DiagExtModSts_offset     0
#define ESC_DiagExtModSts_signed     0
#define ESC_DiagExtModSts_bitlen     1

#if 0
/* ESC_ABP_available */
#define ESC_ABP_available_factor     1
#define ESC_ABP_available_offset     0
#define ESC_ABP_available_signed     0
#define ESC_ABP_available_bitlen     1

/* ESC_ABP_active */
#define ESC_ABP_active_factor     1
#define ESC_ABP_active_offset     0
#define ESC_ABP_active_signed     0
#define ESC_ABP_active_bitlen     1

/* ESC_AEB_active */
#define ESC_AEB_active_factor     1
#define ESC_AEB_active_offset     0
#define ESC_AEB_active_signed     0
#define ESC_AEB_active_bitlen     1

/* ESC_AEB_available */
#define ESC_AEB_available_factor     1
#define ESC_AEB_available_offset     0
#define ESC_AEB_available_signed     0
#define ESC_AEB_available_bitlen     1

/* ESC_ABA_active */
#define ESC_ABA_active_factor     1
#define ESC_ABA_active_offset     0
#define ESC_ABA_active_signed     0
#define ESC_ABA_active_bitlen     1

/* ESC_ABA_available */
#define ESC_ABA_available_factor     1
#define ESC_ABA_available_offset     0
#define ESC_ABA_available_signed     0
#define ESC_ABA_available_bitlen     1

/* ESC_AWB_active */
#define ESC_AWB_active_factor     1
#define ESC_AWB_active_offset     0
#define ESC_AWB_active_signed     0
#define ESC_AWB_active_bitlen     1

/* ESC_AWB_available */
#define ESC_AWB_available_factor     1
#define ESC_AWB_available_offset     0
#define ESC_AWB_available_signed     0
#define ESC_AWB_available_bitlen     1
#endif

/* ESC_Vehiclestandstill */
#define ESC_Vehiclestandstill_factor     1
#define ESC_Vehiclestandstill_offset     0
#define ESC_Vehiclestandstill_signed     0
#define ESC_Vehiclestandstill_bitlen     2

#if 0
/* ESC_DTC_Active */
#define ESC_DTC_Active_factor     1
#define ESC_DTC_Active_offset     0
#define ESC_DTC_Active_signed     0
#define ESC_DTC_Active_bitlen     1

/* ESC_BrakeTempTooHigh */
#define ESC_BrakeTempTooHigh_factor     1
#define ESC_BrakeTempTooHigh_offset     0
#define ESC_BrakeTempTooHigh_signed     0
#define ESC_BrakeTempTooHigh_bitlen     1

/* ESC_QDCFRS */
#define ESC_QDCFRS_factor     1
#define ESC_QDCFRS_offset     0
#define ESC_QDCFRS_signed     0
#define ESC_QDCFRS_bitlen     1

/* ESC_DA_MESSAGE_AliveCounter */
#define ESC_DA_MESSAGE_AliveCounter_factor     1
#define ESC_DA_MESSAGE_AliveCounter_offset     0
#define ESC_DA_MESSAGE_AliveCounter_signed     0
#define ESC_DA_MESSAGE_AliveCounter_bitlen     4

/* ESC_DA_MESSAGE_Checksum */
#define ESC_DA_MESSAGE_Checksum_factor     1
#define ESC_DA_MESSAGE_Checksum_offset     0
#define ESC_DA_MESSAGE_Checksum_signed     0
#define ESC_DA_MESSAGE_Checksum_bitlen     8
#endif


/* 0x127 - ESC_InformSts */
/*----------------------------------------------------------------------------*/

/* ESC_APA_Available */
#define ESC_APA_Available_factor     1
#define ESC_APA_Available_offset     0
#define ESC_APA_Available_signed     0
#define ESC_APA_Available_bitlen     1

/* ESC_APA_Active */
#define ESC_APA_Active_factor     1
#define ESC_APA_Active_offset     0
#define ESC_APA_Active_signed     0
#define ESC_APA_Active_bitlen     1

#if 0
/* ESC_PAS_Park_Status */
#define ESC_PAS_Park_Status_factor     1
#define ESC_PAS_Park_Status_offset     0
#define ESC_PAS_Park_Status_signed     0
#define ESC_PAS_Park_Status_bitlen     4
#endif

/* ESC_APA_CDD_available */
#define ESC_APA_CDD_available_factor     1
#define ESC_APA_CDD_available_offset     0
#define ESC_APA_CDD_available_signed     0
#define ESC_APA_CDD_available_bitlen     1

/* ESC_APA_LC_Status */
#define ESC_APA_LC_Status_factor     1
#define ESC_APA_LC_Status_offset     0
#define ESC_APA_LC_Status_signed     0
#define ESC_APA_LC_Status_bitlen     4

/* ESC_APA_LC_FailureSts */
#define ESC_APA_LC_FailureSts_factor     1
#define ESC_APA_LC_FailureSts_offset     0
#define ESC_APA_LC_FailureSts_signed     0
#define ESC_APA_LC_FailureSts_bitlen     3

/* ESC_APA_CDD_active */
#define ESC_APA_CDD_active_factor     1
#define ESC_APA_CDD_active_offset     0
#define ESC_APA_CDD_active_signed     0
#define ESC_APA_CDD_active_bitlen     1

/* ESC_APA_LC_Availability */
#define ESC_APA_LC_Availability_factor     1
#define ESC_APA_LC_Availability_offset     0
#define ESC_APA_LC_Availability_signed     0
#define ESC_APA_LC_Availability_bitlen     8

#if 0
/* ESC_APA_Fail */
#define ESC_APA_Fail_factor     1
#define ESC_APA_Fail_offset     0
#define ESC_APA_Fail_signed     0
#define ESC_APA_Fail_bitlen     2
#endif

/* ESC_InformSts_AliveCounter */
#define ESC_InformSts_AliveCounter_factor     1
#define ESC_InformSts_AliveCounter_offset     0
#define ESC_InformSts_AliveCounter_signed     0
#define ESC_InformSts_AliveCounter_bitlen     4

/* ESC_InformSts_Checksum */
#define ESC_InformSts_Checksum_factor     1
#define ESC_InformSts_Checksum_offset     0
#define ESC_InformSts_Checksum_signed     0
#define ESC_InformSts_Checksum_bitlen     8


/* 0x130 - YRS1 */
/*----------------------------------------------------------------------------*/

/* YRS1_Checksum */
#define YRS1_Checksum_factor     1
#define YRS1_Checksum_offset     0
#define YRS1_Checksum_signed     0
#define YRS1_Checksum_bitlen     8

#if 0
/* YRS_CalibrationState */
#define YRS_CalibrationState_factor     1
#define YRS_CalibrationState_offset     0
#define YRS_CalibrationState_signed     0
#define YRS_CalibrationState_bitlen     1
#endif

/* BCS_YawRateSt */
#define BCS_YawRateSt_factor     1
#define BCS_YawRateSt_offset     0
#define BCS_YawRateSt_signed     0
#define BCS_YawRateSt_bitlen     1

/* BCS_ActVehLaltrlAccelVD */
#define BCS_ActVehLaltrlAccelVD_factor     1
#define BCS_ActVehLaltrlAccelVD_offset     0
#define BCS_ActVehLaltrlAccelVD_signed     0
#define BCS_ActVehLaltrlAccelVD_bitlen     1

/* BCS_ActVehLaltrlAccel */
#define BCS_ActVehLaltrlAccel_factor  	 0.027126736
#define BCS_ActVehLaltrlAccel_offset     -21.593
#define BCS_ActVehLaltrlAccel_signed  	 1
#define BCS_ActVehLaltrlAccel_bitlen     12

/* BCS_YawRate */
#define BCS_YawRate_factor     0.0009765625
#define BCS_YawRate_offset     -2.0943
#define BCS_YawRate_signed     1
#define BCS_YawRate_bitlen     12

/* YRS1_AliveCounter */
#define YRS1_AliveCounter_factor     1
#define YRS1_AliveCounter_offset     0
#define YRS1_AliveCounter_signed     0
#define YRS1_AliveCounter_bitlen     4


/* 0x131 - YRS2 */
/*----------------------------------------------------------------------------*/

/* YRS2_Checksum */
#define YRS2_Checksum_factor     1
#define YRS2_Checksum_offset     0
#define YRS2_Checksum_signed     0
#define YRS2_Checksum_bitlen     8

/* BCS_ActVehLongAccelVD */
#define BCS_ActVehLongAccelVD_factor     1
#define BCS_ActVehLongAccelVD_offset     0
#define BCS_ActVehLongAccelVD_signed     0
#define BCS_ActVehLongAccelVD_bitlen     1

/* BCS_ActVehLongAccel */
#define BCS_ActVehLongAccel_factor    	0.027126736
#define BCS_ActVehLongAccel_offset     -21.593
#define BCS_ActVehLongAccel_signed    	1
#define BCS_ActVehLongAccel_bitlen     12

/* YRS2_AliveCounter */
#define YRS2_AliveCounter_factor     1
#define YRS2_AliveCounter_offset     0
#define YRS2_AliveCounter_signed     0
#define YRS2_AliveCounter_bitlen     4


/* 0x135 - AVM_APA_LCControl1 */
/*----------------------------------------------------------------------------*/

/* AVM_APA_VLCAxTarAim */
#define AVM_APA_VLCAxTarAim_factor     0.05
#define AVM_APA_VLCAxTarAim_offset     -5
#define AVM_APA_VLCAxTarAim_signed     0
#define AVM_APA_VLCAxTarAim_bitlen     8

/* AVM_APA_VLCAxTarUpperComfBand */
#define AVM_APA_VLCAxTarUpperComfBand_factor     0.05
#define AVM_APA_VLCAxTarUpperComfBand_offset     -7
#define AVM_APA_VLCAxTarUpperComfBand_signed     0
#define AVM_APA_VLCAxTarUpperComfBand_bitlen     8

/* AVM_APA_VLCAxTarLowerComfBand */
#define AVM_APA_VLCAxTarLowerComfBand_factor     0.05
#define AVM_APA_VLCAxTarLowerComfBand_offset     -7
#define AVM_APA_VLCAxTarLowerComfBand_signed     0
#define AVM_APA_VLCAxTarLowerComfBand_bitlen     8

/* AVM_APA_StopDistance */
#define AVM_APA_StopDistance_factor     1
#define AVM_APA_StopDistance_offset     0
#define AVM_APA_StopDistance_signed     0
#define AVM_APA_StopDistance_bitlen     8

/* AVM_APA_VLCdAxTarUpperLimit */
#define AVM_APA_VLCdAxTarUpperLimit_factor     0.2
#define AVM_APA_VLCdAxTarUpperLimit_offset     0
#define AVM_APA_VLCdAxTarUpperLimit_signed     0
#define AVM_APA_VLCdAxTarUpperLimit_bitlen     7

/* AVM_APA_BrakePreferred */
#define AVM_APA_BrakePreferred_factor     1
#define AVM_APA_BrakePreferred_offset     0
#define AVM_APA_BrakePreferred_signed     0
#define AVM_APA_BrakePreferred_bitlen     1

/* AVM_APA_VLCdAxTarLowerLimit */
#define AVM_APA_VLCdAxTarLowerLimit_factor     0.2
#define AVM_APA_VLCdAxTarLowerLimit_offset     -25.4
#define AVM_APA_VLCdAxTarLowerLimit_signed     0
#define AVM_APA_VLCdAxTarLowerLimit_bitlen     7

/* AVM_APA_DriverOffReq */
#define AVM_APA_DriverOffReq_factor     1
#define AVM_APA_DriverOffReq_offset     0
#define AVM_APA_DriverOffReq_signed     0
#define AVM_APA_DriverOffReq_bitlen     1

/* AVM_APA_LCControl1_AliveCounter */
#define AVM_APA_LCControl1_AliveCounter_factor     1
#define AVM_APA_LCControl1_AliveCounter_offset     0
#define AVM_APA_LCControl1_AliveCounter_signed     0
#define AVM_APA_LCControl1_AliveCounter_bitlen     4

/* AVM_APA_LCControl1_Checksum */
#define AVM_APA_LCControl1_Checksum_factor     1
#define AVM_APA_LCControl1_Checksum_offset     0
#define AVM_APA_LCControl1_Checksum_signed     0
#define AVM_APA_LCControl1_Checksum_bitlen     8


/* 0x136 - AVM_APA_LCControl2 */
/*----------------------------------------------------------------------------*/

/* AVM_APA_VLCModeReq */
#define AVM_APA_VLCModeReq_factor     1
#define AVM_APA_VLCModeReq_offset     0
#define AVM_APA_VLCModeReq_signed     0
#define AVM_APA_VLCModeReq_bitlen     3

/* AVM_APA_StandstillReq */
#define AVM_APA_StandstillReq_factor     1
#define AVM_APA_StandstillReq_offset     0
#define AVM_APA_StandstillReq_signed     0
#define AVM_APA_StandstillReq_bitlen     1

/* AVM_APA_HandshakingReq */
#define AVM_APA_HandshakingReq_factor     1
#define AVM_APA_HandshakingReq_offset     0
#define AVM_APA_HandshakingReq_signed     0
#define AVM_APA_HandshakingReq_bitlen     3

/* AVM_APA_EmergencyBrakeReq */
#define AVM_APA_EmergencyBrakeReq_factor     1
#define AVM_APA_EmergencyBrakeReq_offset     0
#define AVM_APA_EmergencyBrakeReq_signed     0
#define AVM_APA_EmergencyBrakeReq_bitlen     1

/* AVM_APA_VLCShutdownReq */
#define AVM_APA_VLCShutdownReq_factor     1
#define AVM_APA_VLCShutdownReq_offset     0
#define AVM_APA_VLCShutdownReq_signed     0
#define AVM_APA_VLCShutdownReq_bitlen     2

/* AVM_APA_GearRequest */
#define AVM_APA_GearRequest_factor     1
#define AVM_APA_GearRequest_offset     0
#define AVM_APA_GearRequest_signed     0
#define AVM_APA_GearRequest_bitlen     3

/* AVM_APA_GearBoxEnable */
#define AVM_APA_GearBoxEnable_factor     1
#define AVM_APA_GearBoxEnable_offset     0
#define AVM_APA_GearBoxEnable_signed     0
#define AVM_APA_GearBoxEnable_bitlen     2

/* AVM_APA_LCControl2_AliveCounter */
#define AVM_APA_LCControl2_AliveCounter_factor     1
#define AVM_APA_LCControl2_AliveCounter_offset     0
#define AVM_APA_LCControl2_AliveCounter_signed     0
#define AVM_APA_LCControl2_AliveCounter_bitlen     4

/* AVM_APA_LCControl2_Checksum */
#define AVM_APA_LCControl2_Checksum_factor     1
#define AVM_APA_LCControl2_Checksum_offset     0
#define AVM_APA_LCControl2_Checksum_signed     0
#define AVM_APA_LCControl2_Checksum_bitlen     8


/* 0x150 - EPS_InformSts */
/*----------------------------------------------------------------------------*/

#if 0
/* EPS_SteeringTorque */
#define EPS_SteeringTorque_factor     0.1794
#define EPS_SteeringTorque_offset     -22.78
#define EPS_SteeringTorque_signed     0
#define EPS_SteeringTorque_bitlen     8

/* EPS_ElectPowerConsumption */
#define EPS_ElectPowerConsumption_factor     0.5
#define EPS_ElectPowerConsumption_offset     0
#define EPS_ElectPowerConsumption_signed     0
#define EPS_ElectPowerConsumption_bitlen     8

/* EPS_EpasFailed */
#define EPS_EpasFailed_factor     1
#define EPS_EpasFailed_offset     0
#define EPS_EpasFailed_signed     0
#define EPS_EpasFailed_bitlen     1

/* EPS_ModSetInhibit */
#define EPS_ModSetInhibit_factor     1
#define EPS_ModSetInhibit_offset     0
#define EPS_ModSetInhibit_signed     0
#define EPS_ModSetInhibit_bitlen     1

/* EPS_ModSts */
#define EPS_ModSts_factor     1
#define EPS_ModSts_offset     0
#define EPS_ModSts_signed     0
#define EPS_ModSts_bitlen     2
#endif

/* EPS_TorsionBarTorqueDir */
#define EPS_TorsionBarTorqueDir_factor     1
#define EPS_TorsionBarTorqueDir_offset     0
#define EPS_TorsionBarTorqueDir_signed     0
#define EPS_TorsionBarTorqueDir_bitlen     1

#if 0
/* EPS_TorsionBarTorqueValid */
#define EPS_TorsionBarTorqueValid_factor     1
#define EPS_TorsionBarTorqueValid_offset     0
#define EPS_TorsionBarTorqueValid_signed     0
#define EPS_TorsionBarTorqueValid_bitlen     1

/* EPS_LDW_ControlSts */
#define EPS_LDW_ControlSts_factor     1
#define EPS_LDW_ControlSts_offset     0
#define EPS_LDW_ControlSts_signed     0
#define EPS_LDW_ControlSts_bitlen     3
#endif

/* EPS_TorsionBarTorque */
#define EPS_TorsionBarTorque_factor     0.01
#define EPS_TorsionBarTorque_offset     0
#define EPS_TorsionBarTorque_signed     0
#define EPS_TorsionBarTorque_bitlen     10

#if 0
/* EPS_LKS_ControlSts */
#define EPS_LKS_ControlSts_factor     1
#define EPS_LKS_ControlSts_offset     0
#define EPS_LKS_ControlSts_signed     0
#define EPS_LKS_ControlSts_bitlen     3

/* EPS_InformSts_AliveCounter */
#define EPS_InformSts_AliveCounter_factor     1
#define EPS_InformSts_AliveCounter_offset     0
#define EPS_InformSts_AliveCounter_signed     0
#define EPS_InformSts_AliveCounter_bitlen     4

/* EPS_InformSts_Checksum */
#define EPS_InformSts_Checksum_factor     1
#define EPS_InformSts_Checksum_offset     0
#define EPS_InformSts_Checksum_signed     0
#define EPS_InformSts_Checksum_bitlen     8
#endif


/* 0x165 - VCU_ModeControl */
/*----------------------------------------------------------------------------*/

/* VCU_ModeGearDisplaySts */
#define VCU_ModeGearDisplaySts_factor     1
#define VCU_ModeGearDisplaySts_offset     0
#define VCU_ModeGearDisplaySts_signed     0
#define VCU_ModeGearDisplaySts_bitlen     5

/* VCU_ePTReady */
#define VCU_ePTReady_factor     1
#define VCU_ePTReady_offset     0
#define VCU_ePTReady_signed     0
#define VCU_ePTReady_bitlen     1


/* 0x167 - EPS_SystemSts */
/*----------------------------------------------------------------------------*/

/* EPS_PinionAngleValue */
#define EPS_PinionAngleValue_factor     0.1
#define EPS_PinionAngleValue_offset     0
#define EPS_PinionAngleValue_signed     1
#define EPS_PinionAngleValue_bitlen     16

#if 0
/* EPS_ALAD_SystemStatus */
#define EPS_ALAD_SystemStatus_factor     1
#define EPS_ALAD_SystemStatus_offset     0
#define EPS_ALAD_SystemStatus_signed     0
#define EPS_ALAD_SystemStatus_bitlen     3

/* EPS_ALAD_ControlModeFBK */
#define EPS_ALAD_ControlModeFBK_factor     1
#define EPS_ALAD_ControlModeFBK_offset     0
#define EPS_ALAD_ControlModeFBK_signed     0
#define EPS_ALAD_ControlModeFBK_bitlen     2

/* EPS_ALAD_FaultStatus */
#define EPS_ALAD_FaultStatus_factor     1
#define EPS_ALAD_FaultStatus_offset     0
#define EPS_ALAD_FaultStatus_signed     0
#define EPS_ALAD_FaultStatus_bitlen     2
#endif

/* EPS_PinionAngleValueInvalid */
#define EPS_PinionAngleValueInvalid_factor     1
#define EPS_PinionAngleValueInvalid_offset     0
#define EPS_PinionAngleValueInvalid_signed     0
#define EPS_PinionAngleValueInvalid_bitlen     1

/* EPS_APA_SystemStatus */
#define EPS_APA_SystemStatus_factor     1
#define EPS_APA_SystemStatus_offset     0
#define EPS_APA_SystemStatus_signed     0
#define EPS_APA_SystemStatus_bitlen     3

/* EPS_APA_FaultStatus */
#define EPS_APA_FaultStatus_factor     1
#define EPS_APA_FaultStatus_offset     0
#define EPS_APA_FaultStatus_signed     0
#define EPS_APA_FaultStatus_bitlen     3

/* EPS_SystemSts_AliveCounter */
#define EPS_SystemSts_AliveCounter_factor     1
#define EPS_SystemSts_AliveCounter_offset     0
#define EPS_SystemSts_AliveCounter_signed     0
#define EPS_SystemSts_AliveCounter_bitlen     4

/* EPS_SystemSts_Checksum */
#define EPS_SystemSts_Checksum_factor     1
#define EPS_SystemSts_Checksum_offset     0
#define EPS_SystemSts_Checksum_signed     0
#define EPS_SystemSts_Checksum_bitlen     8


/* 0x190 - AVM_APA_ControlSts */
/*----------------------------------------------------------------------------*/

/* AVM_APA_EPS_Control_Request */
#define AVM_APA_EPS_Control_Request_factor     1
#define AVM_APA_EPS_Control_Request_offset     0
#define AVM_APA_EPS_Control_Request_signed     0
#define AVM_APA_EPS_Control_Request_bitlen     2

/* AVM_APA_SetSteeringWheelAng */
#define AVM_APA_SetSteeringWheelAng_factor     0.1
#define AVM_APA_SetSteeringWheelAng_offset     0
#define AVM_APA_SetSteeringWheelAng_signed     1
#define AVM_APA_SetSteeringWheelAng_bitlen     16

/* AVM_APA_ControlSts_Alivecounter */
#define AVM_APA_ControlSts_Alivecounter_factor     1
#define AVM_APA_ControlSts_Alivecounter_offset     0
#define AVM_APA_ControlSts_Alivecounter_signed     0
#define AVM_APA_ControlSts_Alivecounter_bitlen     4

/* AVM_APA_ControlSts_Checksum */
#define AVM_APA_ControlSts_Checksum_factor     1
#define AVM_APA_ControlSts_Checksum_offset     0
#define AVM_APA_ControlSts_Checksum_signed     0
#define AVM_APA_ControlSts_Checksum_bitlen     8


/* 0x191 - PAS_SVA_APA_Status */
/*----------------------------------------------------------------------------*/

/* PAS_SVA_Mode */
#define PAS_SVA_Mode_factor     1
#define PAS_SVA_Mode_offset     0
#define PAS_SVA_Mode_signed     0
#define PAS_SVA_Mode_bitlen     3

/* PAS_SVA_WarningInd_Left */
#define PAS_SVA_WarningInd_Left_factor     1
#define PAS_SVA_WarningInd_Left_offset     0
#define PAS_SVA_WarningInd_Left_signed     0
#define PAS_SVA_WarningInd_Left_bitlen     2

/* PAS_SVA_WarningInd_Right */
#define PAS_SVA_WarningInd_Right_factor     1
#define PAS_SVA_WarningInd_Right_offset     0
#define PAS_SVA_WarningInd_Right_signed     0
#define PAS_SVA_WarningInd_Right_bitlen     2

/* PAS_SVA_Status */
#define PAS_SVA_Status_factor     1
#define PAS_SVA_Status_offset     0
#define PAS_SVA_Status_signed     0
#define PAS_SVA_Status_bitlen     1

/* PAS_APA_SelectedSide */
#define PAS_APA_SelectedSide_factor     1
#define PAS_APA_SelectedSide_offset     0
#define PAS_APA_SelectedSide_signed     0
#define PAS_APA_SelectedSide_bitlen     2

/* PAS_SVA_APA_Status_AliveCounter */
#define PAS_SVA_APA_Status_AliveCounter_factor     1
#define PAS_SVA_APA_Status_AliveCounter_offset     0
#define PAS_SVA_APA_Status_AliveCounter_signed     0
#define PAS_SVA_APA_Status_AliveCounter_bitlen     4

/* PAS_SVA_APA_Status_Checksum */
#define PAS_SVA_APA_Status_Checksum_factor     1
#define PAS_SVA_APA_Status_Checksum_offset     0
#define PAS_SVA_APA_Status_Checksum_signed     0
#define PAS_SVA_APA_Status_Checksum_bitlen     8


/* 0x192 - PAS_APA_ParkingMarkAB */
/*----------------------------------------------------------------------------*/

/* PAS_APA_ParkingDepth */
#define PAS_APA_ParkingDepth_factor     2
#define PAS_APA_ParkingDepth_offset     0
#define PAS_APA_ParkingDepth_signed     0
#define PAS_APA_ParkingDepth_bitlen     8

/* PAS_APA_ACoordinateY */
#define PAS_APA_ACoordinateY_factor     2
#define PAS_APA_ACoordinateY_offset     0
#define PAS_APA_ACoordinateY_signed     0
#define PAS_APA_ACoordinateY_bitlen     8

/* PAS_APA_BCoordinateY */
#define PAS_APA_BCoordinateY_factor     2
#define PAS_APA_BCoordinateY_offset     0
#define PAS_APA_BCoordinateY_signed     0
#define PAS_APA_BCoordinateY_bitlen     8

/* PAS_APA_ACoordinateX */
#define PAS_APA_ACoordinateX_factor     2
#define PAS_APA_ACoordinateX_offset     0
#define PAS_APA_ACoordinateX_signed     0
#define PAS_APA_ACoordinateX_bitlen     11

/* PAS_APA_BCoordinateX */
#define PAS_APA_BCoordinateX_factor     2
#define PAS_APA_BCoordinateX_offset     0
#define PAS_APA_BCoordinateX_signed     0
#define PAS_APA_BCoordinateX_bitlen     11

/* PAS_APA_ParkingMarkAB_AliveCounter */
#define PAS_APA_ParkingMarkAB_AliveCounter_factor     1
#define PAS_APA_ParkingMarkAB_AliveCounter_offset     0
#define PAS_APA_ParkingMarkAB_AliveCounter_signed     0
#define PAS_APA_ParkingMarkAB_AliveCounter_bitlen     4

/* PAS_APA_ParkingMarkAB_Checksum */
#define PAS_APA_ParkingMarkAB_Checksum_factor     1
#define PAS_APA_ParkingMarkAB_Checksum_offset     0
#define PAS_APA_ParkingMarkAB_Checksum_signed     0
#define PAS_APA_ParkingMarkAB_Checksum_bitlen     8


/* 0x193 - PAS_APA_ParkingMarkCD */
/*----------------------------------------------------------------------------*/

/* PAS_APA_CCoordinateY */
#define PAS_APA_CCoordinateY_factor     2
#define PAS_APA_CCoordinateY_offset     0
#define PAS_APA_CCoordinateY_signed     0
#define PAS_APA_CCoordinateY_bitlen     8

/* PAS_APA_DCoordinateY */
#define PAS_APA_DCoordinateY_factor     2
#define PAS_APA_DCoordinateY_offset     0
#define PAS_APA_DCoordinateY_signed     0
#define PAS_APA_DCoordinateY_bitlen     8

/* PAS_APA_CCoordinateX */
#define PAS_APA_CCoordinateX_factor     2
#define PAS_APA_CCoordinateX_offset     0
#define PAS_APA_CCoordinateX_signed     0
#define PAS_APA_CCoordinateX_bitlen     11

/* PAS_APA_DCoordinateX */
#define PAS_APA_DCoordinateX_factor     2
#define PAS_APA_DCoordinateX_offset     0
#define PAS_APA_DCoordinateX_signed     0
#define PAS_APA_DCoordinateX_bitlen     11

/* PAS_APA_ParkingMarkCD_AliveCounter */
#define PAS_APA_ParkingMarkCD_AliveCounter_factor     1
#define PAS_APA_ParkingMarkCD_AliveCounter_offset     0
#define PAS_APA_ParkingMarkCD_AliveCounter_signed     0
#define PAS_APA_ParkingMarkCD_AliveCounter_bitlen     4

/* PAS_APA_ParkingMarkCD_Checksum */
#define PAS_APA_ParkingMarkCD_Checksum_factor     1
#define PAS_APA_ParkingMarkCD_Checksum_offset     0
#define PAS_APA_ParkingMarkCD_Checksum_signed     0
#define PAS_APA_ParkingMarkCD_Checksum_bitlen     8


/* 0x194 - PAS_APA_DistValueFront */
/*----------------------------------------------------------------------------*/

/* PAS_APA_DistanceValueLR_FL */
#define PAS_APA_DistanceValueLR_FL_factor     2
#define PAS_APA_DistanceValueLR_FL_offset     0
#define PAS_APA_DistanceValueLR_FL_signed     0
#define PAS_APA_DistanceValueLR_FL_bitlen     8

/* PAS_APA_DistanceValueLR_FR */
#define PAS_APA_DistanceValueLR_FR_factor     2
#define PAS_APA_DistanceValueLR_FR_offset     0
#define PAS_APA_DistanceValueLR_FR_signed     0
#define PAS_APA_DistanceValueLR_FR_bitlen     8

/* PAS_APA_DistanceValueSR_FL */
#define PAS_APA_DistanceValueSR_FL_factor     2
#define PAS_APA_DistanceValueSR_FL_offset     0
#define PAS_APA_DistanceValueSR_FL_signed     0
#define PAS_APA_DistanceValueSR_FL_bitlen     7

/* PAS_APA_DistanceValueSR_FML */
#define PAS_APA_DistanceValueSR_FML_factor     2
#define PAS_APA_DistanceValueSR_FML_offset     0
#define PAS_APA_DistanceValueSR_FML_signed     0
#define PAS_APA_DistanceValueSR_FML_bitlen     7

/* PAS_APA_DistanceValueSR_FMR */
#define PAS_APA_DistanceValueSR_FMR_factor     2
#define PAS_APA_DistanceValueSR_FMR_offset     0
#define PAS_APA_DistanceValueSR_FMR_signed     0
#define PAS_APA_DistanceValueSR_FMR_bitlen     7

/* PAS_APA_DistanceValueSR_FR */
#define PAS_APA_DistanceValueSR_FR_factor     2
#define PAS_APA_DistanceValueSR_FR_offset     0
#define PAS_APA_DistanceValueSR_FR_signed     0
#define PAS_APA_DistanceValueSR_FR_bitlen     7

/* PAS_APA_DistValueFront_AliveCounter */
#define PAS_APA_DistValueFront_AliveCounter_factor     1
#define PAS_APA_DistValueFront_AliveCounter_offset     0
#define PAS_APA_DistValueFront_AliveCounter_signed     0
#define PAS_APA_DistValueFront_AliveCounter_bitlen     4

/* PAS_APA_DistValueFront_Checksum */
#define PAS_APA_DistValueFront_Checksum_factor     1
#define PAS_APA_DistValueFront_Checksum_offset     0
#define PAS_APA_DistValueFront_Checksum_signed     0
#define PAS_APA_DistValueFront_Checksum_bitlen     8


/* 0x195 - PAS_APA_DistValueRear */
/*----------------------------------------------------------------------------*/

/* PAS_APA_DistanceValueLR_RL */
#define PAS_APA_DistanceValueLR_RL_factor     2
#define PAS_APA_DistanceValueLR_RL_offset     0
#define PAS_APA_DistanceValueLR_RL_signed     0
#define PAS_APA_DistanceValueLR_RL_bitlen     8

/* PAS_APA_DistanceValueLR_RR */
#define PAS_APA_DistanceValueLR_RR_factor     2
#define PAS_APA_DistanceValueLR_RR_offset     0
#define PAS_APA_DistanceValueLR_RR_signed     0
#define PAS_APA_DistanceValueLR_RR_bitlen     8

/* PAS_APA_DistanceValueSR_RL */
#define PAS_APA_DistanceValueSR_RL_factor     2
#define PAS_APA_DistanceValueSR_RL_offset     0
#define PAS_APA_DistanceValueSR_RL_signed     0
#define PAS_APA_DistanceValueSR_RL_bitlen     7

/* PAS_APA_DistanceValueSR_RML */
#define PAS_APA_DistanceValueSR_RML_factor     2
#define PAS_APA_DistanceValueSR_RML_offset     0
#define PAS_APA_DistanceValueSR_RML_signed     0
#define PAS_APA_DistanceValueSR_RML_bitlen     7

/* PAS_APA_DistanceValueSR_RMR */
#define PAS_APA_DistanceValueSR_RMR_factor     2
#define PAS_APA_DistanceValueSR_RMR_offset     0
#define PAS_APA_DistanceValueSR_RMR_signed     0
#define PAS_APA_DistanceValueSR_RMR_bitlen     7

/* PAS_APA_DistanceValueSR_RR */
#define PAS_APA_DistanceValueSR_RR_factor     2
#define PAS_APA_DistanceValueSR_RR_offset     0
#define PAS_APA_DistanceValueSR_RR_signed     0
#define PAS_APA_DistanceValueSR_RR_bitlen     7

/* PAS_APA_DistValueRear_AliveCounter */
#define PAS_APA_DistValueRear_AliveCounter_factor     1
#define PAS_APA_DistValueRear_AliveCounter_offset     0
#define PAS_APA_DistValueRear_AliveCounter_signed     0
#define PAS_APA_DistValueRear_AliveCounter_bitlen     4

/* PAS_APA_DistValueRear_Checksum */
#define PAS_APA_DistValueRear_Checksum_factor     1
#define PAS_APA_DistValueRear_Checksum_offset     0
#define PAS_APA_DistValueRear_Checksum_signed     0
#define PAS_APA_DistValueRear_Checksum_bitlen     8


/* 0x196 - PAS_APA_ParkingMarkSts */
/*----------------------------------------------------------------------------*/

/* PAS_APA_StoppedCx */
#define PAS_APA_StoppedCx_factor     2
#define PAS_APA_StoppedCx_offset     -4000
#define PAS_APA_StoppedCx_signed     0
#define PAS_APA_StoppedCx_bitlen     12

/* PAS_APA_StoppedCy */
#define PAS_APA_StoppedCy_factor     2
#define PAS_APA_StoppedCy_offset     -4000
#define PAS_APA_StoppedCy_signed     0
#define PAS_APA_StoppedCy_bitlen     12

/* PAS_APA_StoppedAngle */
#define PAS_APA_StoppedAngle_factor     0.1
#define PAS_APA_StoppedAngle_offset     -5
#define PAS_APA_StoppedAngle_signed     0
#define PAS_APA_StoppedAngle_bitlen     7

/* PAS_APA_CoordinateInitReq */
#define PAS_APA_CoordinateInitReq_factor     1
#define PAS_APA_CoordinateInitReq_offset     0
#define PAS_APA_CoordinateInitReq_signed     0
#define PAS_APA_CoordinateInitReq_bitlen     1

/* PAS_APA_RoadblockTypeF */
#define PAS_APA_RoadblockTypeF_factor     1
#define PAS_APA_RoadblockTypeF_offset     0
#define PAS_APA_RoadblockTypeF_signed     0
#define PAS_APA_RoadblockTypeF_bitlen     3

/* PAS_APA_RoadblockTypeR */
#define PAS_APA_RoadblockTypeR_factor     1
#define PAS_APA_RoadblockTypeR_offset     0
#define PAS_APA_RoadblockTypeR_signed     0
#define PAS_APA_RoadblockTypeR_bitlen     3

/* PAS_SensorErrorFlag */
#define PAS_SensorErrorFlag_factor     1
#define PAS_SensorErrorFlag_offset     0
#define PAS_SensorErrorFlag_signed     0
#define PAS_SensorErrorFlag_bitlen     1

/* PAS_APA_ParkingMarkSts_AliveCounter */
#define PAS_APA_ParkingMarkSts_AliveCounter_factor     1
#define PAS_APA_ParkingMarkSts_AliveCounter_offset     0
#define PAS_APA_ParkingMarkSts_AliveCounter_signed     0
#define PAS_APA_ParkingMarkSts_AliveCounter_bitlen     4

/* PAS_APA_ParkingMarkSts_Checksum */
#define PAS_APA_ParkingMarkSts_Checksum_factor     1
#define PAS_APA_ParkingMarkSts_Checksum_offset     0
#define PAS_APA_ParkingMarkSts_Checksum_signed     0
#define PAS_APA_ParkingMarkSts_Checksum_bitlen     8



/* 0x1A5 - VCU_CSControl1 */
/*----------------------------------------------------------------------------*/

/* VCU_StartActive */
#define VCU_StartActive_factor     1
#define VCU_StartActive_offset     0
#define VCU_StartActive_signed     0
#define VCU_StartActive_bitlen     1


/* 0x1A3 - FRS_Display */
/*----------------------------------------------------------------------------*/

#if 0
/* FRS_ALOD_SpeedSetDisp */
#define FRS_ALOD_SpeedSetDisp_factor     1
#define FRS_ALOD_SpeedSetDisp_offset     0
#define FRS_ALOD_SpeedSetDisp_signed     0
#define FRS_ALOD_SpeedSetDisp_bitlen     8

/* FRS_ALOD_TimeGap */
#define FRS_ALOD_TimeGap_factor     1
#define FRS_ALOD_TimeGap_offset     0
#define FRS_ALOD_TimeGap_signed     0
#define FRS_ALOD_TimeGap_bitlen     3

/* FRS_ALOD_TimeGapDisp */
#define FRS_ALOD_TimeGapDisp_factor     1
#define FRS_ALOD_TimeGapDisp_offset     0
#define FRS_ALOD_TimeGapDisp_signed     0
#define FRS_ALOD_TimeGapDisp_bitlen     1
#endif

/* FRS_ALOD_Status */
#define FRS_ALOD_Status_factor     1
#define FRS_ALOD_Status_offset     0
#define FRS_ALOD_Status_signed     0
#define FRS_ALOD_Status_bitlen     4

#if 0
/* FRS_ALOD_ControlType */
#define FRS_ALOD_ControlType_factor     1
#define FRS_ALOD_ControlType_offset     0
#define FRS_ALOD_ControlType_signed     0
#define FRS_ALOD_ControlType_bitlen     3

/* FRS_ALOD_Warning */
#define FRS_ALOD_Warning_factor     1
#define FRS_ALOD_Warning_offset     0
#define FRS_ALOD_Warning_signed     0
#define FRS_ALOD_Warning_bitlen     3

/* FRS_FRS_Status */
#define FRS_FRS_Status_factor     1
#define FRS_FRS_Status_offset     0
#define FRS_FRS_Status_signed     0
#define FRS_FRS_Status_bitlen     2

/* FRS_ALOD_dxTarObj */
#define FRS_ALOD_dxTarObj_factor     1
#define FRS_ALOD_dxTarObj_offset     0
#define FRS_ALOD_dxTarObj_signed     0
#define FRS_ALOD_dxTarObj_bitlen     3

/* FRS_ALOD_Info */
#define FRS_ALOD_Info_factor     1
#define FRS_ALOD_Info_offset     0
#define FRS_ALOD_Info_signed     0
#define FRS_ALOD_Info_bitlen     5

/* FRS_Display_AliveCounter */
#define FRS_Display_AliveCounter_factor     1
#define FRS_Display_AliveCounter_offset     0
#define FRS_Display_AliveCounter_signed     0
#define FRS_Display_AliveCounter_bitlen     4

/* FRS_Display_Checksum */
#define FRS_Display_Checksum_factor     1
#define FRS_Display_Checksum_offset     0
#define FRS_Display_Checksum_signed     0
#define FRS_Display_Checksum_bitlen     8
#endif


/* 0x1E2 - PEPS_Message_Sts */
/*----------------------------------------------------------------------------*/

/* PEPS_PowerModeValidity */
#define PEPS_PowerModeValidity_factor     1
#define PEPS_PowerModeValidity_offset     0
#define PEPS_PowerModeValidity_signed     0
#define PEPS_PowerModeValidity_bitlen     2

/* BCM_KeySt */
#define BCM_KeySt_factor     1
#define BCM_KeySt_offset     0
#define BCM_KeySt_signed     0
#define BCM_KeySt_bitlen     2

#if 0
/* PEPS_Message_Sts_AliveCounter */
#define PEPS_Message_Sts_AliveCounter_factor     1
#define PEPS_Message_Sts_AliveCounter_offset     0
#define PEPS_Message_Sts_AliveCounter_signed     0
#define PEPS_Message_Sts_AliveCounter_bitlen     4

/* PEPS_Message_Sts_Checksum */
#define PEPS_Message_Sts_Checksum_factor     1
#define PEPS_Message_Sts_Checksum_offset     0
#define PEPS_Message_Sts_Checksum_signed     0
#define PEPS_Message_Sts_Checksum_bitlen     8
#endif


/* 0x1F0 - BCM_LightChimeReq */
/*----------------------------------------------------------------------------*/

/* BCM_LeftTurnLampSt */
#define BCM_LeftTurnLampSt_factor     1
#define BCM_LeftTurnLampSt_offset     0
#define BCM_LeftTurnLampSt_signed     0
#define BCM_LeftTurnLampSt_bitlen     1

/* BCM_RightTurnLampSt */
#define BCM_RightTurnLampSt_factor     1
#define BCM_RightTurnLampSt_offset     0
#define BCM_RightTurnLampSt_signed     0
#define BCM_RightTurnLampSt_bitlen     1

#if 0
/* BCM_HighBeamRelayFailSts */
#define BCM_HighBeamRelayFailSts_factor     1
#define BCM_HighBeamRelayFailSts_offset     0
#define BCM_HighBeamRelayFailSts_signed     0
#define BCM_HighBeamRelayFailSts_bitlen     1
#endif

/* BCM_LowBeamSt */
#define BCM_LowBeamSt_factor     1
#define BCM_LowBeamSt_offset     0
#define BCM_LowBeamSt_signed     0
#define BCM_LowBeamSt_bitlen     1

#if 0
/* BCM_AutoLightSts */
#define BCM_AutoLightSts_factor     1
#define BCM_AutoLightSts_offset     0
#define BCM_AutoLightSts_signed     0
#define BCM_AutoLightSts_bitlen     1
#endif

/* BCM_HighBeamSt */
#define BCM_HighBeamSt_factor     1
#define BCM_HighBeamSt_offset     0
#define BCM_HighBeamSt_signed     0
#define BCM_HighBeamSt_bitlen     1

/* BCM_PositionLightSts */
#define BCM_PositionLightSts_factor     1
#define BCM_PositionLightSts_offset     0
#define BCM_PositionLightSts_signed     0
#define BCM_PositionLightSts_bitlen     1

/* BCM_FrontFogLightSts */
#define BCM_FrontFogLightSts_factor     1
#define BCM_FrontFogLightSts_offset     0
#define BCM_FrontFogLightSts_signed     0
#define BCM_FrontFogLightSts_bitlen     1

/* BCM_RearFogLightSts */
#define BCM_RearFogLightSts_factor     1
#define BCM_RearFogLightSts_offset     0
#define BCM_RearFogLightSts_signed     0
#define BCM_RearFogLightSts_bitlen     1

#if 0
/* BCM_HazardSts */
#define BCM_HazardSts_factor     1
#define BCM_HazardSts_offset     0
#define BCM_HazardSts_signed     0
#define BCM_HazardSts_bitlen     1
#endif


/* 0x1F1 - TPMS_TyreWarn */
/*----------------------------------------------------------------------------*/

/* TPMS_FLTyreWarn */
#define TPMS_FLTyreWarn_factor     1
#define TPMS_FLTyreWarn_offset     0
#define TPMS_FLTyreWarn_signed     0
#define TPMS_FLTyreWarn_bitlen     2

/* TPMS_FLTyre_Sensor_Failure */
#define TPMS_FLTyre_Sensor_Failure_factor     1
#define TPMS_FLTyre_Sensor_Failure_offset     0
#define TPMS_FLTyre_Sensor_Failure_signed     0
#define TPMS_FLTyre_Sensor_Failure_bitlen     1

/* TPMS_FRTyreWarn */
#define TPMS_FRTyreWarn_factor     1
#define TPMS_FRTyreWarn_offset     0
#define TPMS_FRTyreWarn_signed     0
#define TPMS_FRTyreWarn_bitlen     2

/* TPMS_FRTyre_Sensor_Failure */
#define TPMS_FRTyre_Sensor_Failure_factor     1
#define TPMS_FRTyre_Sensor_Failure_offset     0
#define TPMS_FRTyre_Sensor_Failure_signed     0
#define TPMS_FRTyre_Sensor_Failure_bitlen     1

/* TPMS_RLTyreWarn */
#define TPMS_RLTyreWarn_factor     1
#define TPMS_RLTyreWarn_offset     0
#define TPMS_RLTyreWarn_signed     0
#define TPMS_RLTyreWarn_bitlen     2

/* TPMS_RLTyre_Sensor_Failure */
#define TPMS_RLTyre_Sensor_Failure_factor     1
#define TPMS_RLTyre_Sensor_Failure_offset     0
#define TPMS_RLTyre_Sensor_Failure_signed     0
#define TPMS_RLTyre_Sensor_Failure_bitlen     1

/* TPMS_RRTyreWarn */
#define TPMS_RRTyreWarn_factor     1
#define TPMS_RRTyreWarn_offset     0
#define TPMS_RRTyreWarn_signed     0
#define TPMS_RRTyreWarn_bitlen     2

/* TPMS_RRTyre_Sensor_Failure */
#define TPMS_RRTyre_Sensor_Failure_factor     1
#define TPMS_RRTyre_Sensor_Failure_offset     0
#define TPMS_RRTyre_Sensor_Failure_signed     0
#define TPMS_RRTyre_Sensor_Failure_bitlen     1

/* TPMS_SystemSt */
#define TPMS_SystemSt_factor     1
#define TPMS_SystemSt_offset     0
#define TPMS_SystemSt_signed     0
#define TPMS_SystemSt_bitlen     2


/* 0x218 - TCU_Info */
/*----------------------------------------------------------------------------*/

/* TCU_WarningMsgRed */
#define TCU_WarningMsgRed_factor     1
#define TCU_WarningMsgRed_offset     0
#define TCU_WarningMsgRed_signed     0
#define TCU_WarningMsgRed_bitlen     1

/* TCU_WarningMsgYellow */
#define TCU_WarningMsgYellow_factor     1
#define TCU_WarningMsgYellow_offset     0
#define TCU_WarningMsgYellow_signed     0
#define TCU_WarningMsgYellow_bitlen     1

#if 0
/* TCU_WarningMsgGearboxOvertemp */
#define TCU_WarningMsgGearboxOvertemp_factor     1
#define TCU_WarningMsgGearboxOvertemp_offset     0
#define TCU_WarningMsgGearboxOvertemp_signed     0
#define TCU_WarningMsgGearboxOvertemp_bitlen     1

/* TCU_NIC_Status */
#define TCU_NIC_Status_factor     1
#define TCU_NIC_Status_offset     0
#define TCU_NIC_Status_signed     0
#define TCU_NIC_Status_bitlen     2

/* TCU_Info_AliveCounter */
#define TCU_Info_AliveCounter_factor     1
#define TCU_Info_AliveCounter_offset     0
#define TCU_Info_AliveCounter_signed     0
#define TCU_Info_AliveCounter_bitlen     4

/* TCU_Info_Checksum */
#define TCU_Info_Checksum_factor     1
#define TCU_Info_Checksum_offset     0
#define TCU_Info_Checksum_signed     0
#define TCU_Info_Checksum_bitlen     8
#endif


/* 0x260 - IPK_SettingRequest */
/*----------------------------------------------------------------------------*/

#if 0
/* IPK_AEB_FCWStateReq */
#define IPK_AEB_FCWStateReq_factor     1
#define IPK_AEB_FCWStateReq_offset     0
#define IPK_AEB_FCWStateReq_signed     0
#define IPK_AEB_FCWStateReq_bitlen     2

/* IPK_AEB_AEBStateReq */
#define IPK_AEB_AEBStateReq_factor     1
#define IPK_AEB_AEBStateReq_offset     0
#define IPK_AEB_AEBStateReq_signed     0
#define IPK_AEB_AEBStateReq_bitlen     2
#endif

/* IPK_DOW_EnableStatus */
#define IPK_DOW_EnableStatus_factor     1
#define IPK_DOW_EnableStatus_offset     0
#define IPK_DOW_EnableStatus_signed     0
#define IPK_DOW_EnableStatus_bitlen     2

#if 0
/* IPK_ALOD_ControlTypeReq */
#define IPK_ALOD_ControlTypeReq_factor     1
#define IPK_ALOD_ControlTypeReq_offset     0
#define IPK_ALOD_ControlTypeReq_signed     0
#define IPK_ALOD_ControlTypeReq_bitlen     2
#endif

/* IPK_LCA_EnableStatus */
#define IPK_LCA_EnableStatus_factor     1
#define IPK_LCA_EnableStatus_offset     0
#define IPK_LCA_EnableStatus_signed     0
#define IPK_LCA_EnableStatus_bitlen     2

/* IPK_RCTA_EnableStatus */
#define IPK_RCTA_EnableStatus_factor     1
#define IPK_RCTA_EnableStatus_offset     0
#define IPK_RCTA_EnableStatus_signed     0
#define IPK_RCTA_EnableStatus_bitlen     2

/* IPK_RCW_EnableStatus */
#define IPK_RCW_EnableStatus_factor     1
#define IPK_RCW_EnableStatus_offset     0
#define IPK_RCW_EnableStatus_signed     0
#define IPK_RCW_EnableStatus_bitlen     2

#if 0
/* IPK_AEB_FCWSenlevel */
#define IPK_AEB_FCWSenlevel_factor     1
#define IPK_AEB_FCWSenlevel_offset     0
#define IPK_AEB_FCWSenlevel_signed     0
#define IPK_AEB_FCWSenlevel_bitlen     2

/* IPK_LKS_LaneAssistTypeReq */
#define IPK_LKS_LaneAssistTypeReq_factor     1
#define IPK_LKS_LaneAssistTypeReq_offset     0
#define IPK_LKS_LaneAssistTypeReq_signed     0
#define IPK_LKS_LaneAssistTypeReq_bitlen     3

/* IPK_LDW_WarningTypeSetting */
#define IPK_LDW_WarningTypeSetting_factor     1
#define IPK_LDW_WarningTypeSetting_offset     0
#define IPK_LDW_WarningTypeSetting_signed     0
#define IPK_LDW_WarningTypeSetting_bitlen     2

/* IPK_SLIF_MenuReq */
#define IPK_SLIF_MenuReq_factor     1
#define IPK_SLIF_MenuReq_offset     0
#define IPK_SLIF_MenuReq_signed     0
#define IPK_SLIF_MenuReq_bitlen     2
#endif


/* 0x26D - IPK_STS */
/*----------------------------------------------------------------------------*/

#if 0
/* IPK_AirbagUnitLEDSts */
#define IPK_AirbagUnitLEDSts_factor     1
#define IPK_AirbagUnitLEDSts_offset     0
#define IPK_AirbagUnitLEDSts_signed     0
#define IPK_AirbagUnitLEDSts_bitlen     2

/* IPK_Fail */
#define IPK_Fail_factor     1
#define IPK_Fail_offset     0
#define IPK_Fail_signed     0
#define IPK_Fail_bitlen     1

/* IPK_QDashALODFail */
#define IPK_QDashALODFail_factor     1
#define IPK_QDashALODFail_offset     0
#define IPK_QDashALODFail_signed     0
#define IPK_QDashALODFail_bitlen     2
#endif

/* ACU_LanguageTypeSet */
#define ACU_LanguageTypeSet_factor     1
#define ACU_LanguageTypeSet_offset     0
#define ACU_LanguageTypeSet_signed     0
#define ACU_LanguageTypeSet_bitlen     6

#if 0
/* IPK_EPS_ModSetSelection */
#define IPK_EPS_ModSetSelection_factor     1
#define IPK_EPS_ModSetSelection_offset     0
#define IPK_EPS_ModSetSelection_signed     0
#define IPK_EPS_ModSetSelection_bitlen     2
#endif

/* IPK_Backlightadjust */
#define IPK_Backlightadjust_factor     1
#define IPK_Backlightadjust_offset     0
#define IPK_Backlightadjust_signed     0
#define IPK_Backlightadjust_bitlen     5

#if 0
/* IPK_vDisplay */
#define IPK_vDisplay_factor     0.05625
#define IPK_vDisplay_offset     0
#define IPK_vDisplay_signed     0
#define IPK_vDisplay_bitlen     13
#endif


/* 0x281 - TCM_IntegrationSwtCtrl */
/*----------------------------------------------------------------------------*/

#if 0
/* TCM_SW_RWasherSts */
#define TCM_SW_RWasherSts_factor     1
#define TCM_SW_RWasherSts_offset     0
#define TCM_SW_RWasherSts_signed     0
#define TCM_SW_RWasherSts_bitlen     1

/* TCM_SW_RWasherStsInvalid */
#define TCM_SW_RWasherStsInvalid_factor     1
#define TCM_SW_RWasherStsInvalid_offset     0
#define TCM_SW_RWasherStsInvalid_signed     0
#define TCM_SW_RWasherStsInvalid_bitlen     1

/* TCM_SW_FWasherSts */
#define TCM_SW_FWasherSts_factor     1
#define TCM_SW_FWasherSts_offset     0
#define TCM_SW_FWasherSts_signed     0
#define TCM_SW_FWasherSts_bitlen     1

/* TCM_SW_FWasherStsInvalid */
#define TCM_SW_FWasherStsInvalid_factor     1
#define TCM_SW_FWasherStsInvalid_offset     0
#define TCM_SW_FWasherStsInvalid_signed     0
#define TCM_SW_FWasherStsInvalid_bitlen     1

/* TCM_SW_LowBeam */
#define TCM_SW_LowBeam_factor     1
#define TCM_SW_LowBeam_offset     0
#define TCM_SW_LowBeam_signed     0
#define TCM_SW_LowBeam_bitlen     1

/* TCM_SW_LowBeamInvalid */
#define TCM_SW_LowBeamInvalid_factor     1
#define TCM_SW_LowBeamInvalid_offset     0
#define TCM_SW_LowBeamInvalid_signed     0
#define TCM_SW_LowBeamInvalid_bitlen     1

/* TCM_SW_HighBeam */
#define TCM_SW_HighBeam_factor     1
#define TCM_SW_HighBeam_offset     0
#define TCM_SW_HighBeam_signed     0
#define TCM_SW_HighBeam_bitlen     1

/* TCM_SW_HighBeamInvalid */
#define TCM_SW_HighBeamInvalid_factor     1
#define TCM_SW_HighBeamInvalid_offset     0
#define TCM_SW_HighBeamInvalid_signed     0
#define TCM_SW_HighBeamInvalid_bitlen     1

/* TCM_WipingInterval_Sensitvity */
#define TCM_WipingInterval_Sensitvity_factor     1
#define TCM_WipingInterval_Sensitvity_offset     0
#define TCM_WipingInterval_Sensitvity_signed     0
#define TCM_WipingInterval_Sensitvity_bitlen     3

/* TCM_FrontWipingMode */
#define TCM_FrontWipingMode_factor     1
#define TCM_FrontWipingMode_offset     0
#define TCM_FrontWipingMode_signed     0
#define TCM_FrontWipingMode_bitlen     3

/* TCM_SW_FlashLightSts */
#define TCM_SW_FlashLightSts_factor     1
#define TCM_SW_FlashLightSts_offset     0
#define TCM_SW_FlashLightSts_signed     0
#define TCM_SW_FlashLightSts_bitlen     1

/* TCM_SW_FlashLightStsInvalid */
#define TCM_SW_FlashLightStsInvalid_factor     1
#define TCM_SW_FlashLightStsInvalid_offset     0
#define TCM_SW_FlashLightStsInvalid_signed     0
#define TCM_SW_FlashLightStsInvalid_bitlen     1
#endif

/* TCM_Req_TurnIndicationAct */
#define TCM_Req_TurnIndicationAct_factor     1
#define TCM_Req_TurnIndicationAct_offset     0
#define TCM_Req_TurnIndicationAct_signed     0
#define TCM_Req_TurnIndicationAct_bitlen     2

#if 0
/* TCM_RearWipingMode */
#define TCM_RearWipingMode_factor     1
#define TCM_RearWipingMode_offset     0
#define TCM_RearWipingMode_signed     0
#define TCM_RearWipingMode_bitlen     2

/* TCM_SW_FrontFogLight */
#define TCM_SW_FrontFogLight_factor     1
#define TCM_SW_FrontFogLight_offset     0
#define TCM_SW_FrontFogLight_signed     0
#define TCM_SW_FrontFogLight_bitlen     1

/* TCM_SW_FrontFogLightInvalid */
#define TCM_SW_FrontFogLightInvalid_factor     1
#define TCM_SW_FrontFogLightInvalid_offset     0
#define TCM_SW_FrontFogLightInvalid_signed     0
#define TCM_SW_FrontFogLightInvalid_bitlen     1

/* TCM_SW_RearFogLight */
#define TCM_SW_RearFogLight_factor     1
#define TCM_SW_RearFogLight_offset     0
#define TCM_SW_RearFogLight_signed     0
#define TCM_SW_RearFogLight_bitlen     1

/* TCM_SW_RearFogLightInvalid */
#define TCM_SW_RearFogLightInvalid_factor     1
#define TCM_SW_RearFogLightInvalid_offset     0
#define TCM_SW_RearFogLightInvalid_signed     0
#define TCM_SW_RearFogLightInvalid_bitlen     1

/* TCM_SW_PositionLight */
#define TCM_SW_PositionLight_factor     1
#define TCM_SW_PositionLight_offset     0
#define TCM_SW_PositionLight_signed     0
#define TCM_SW_PositionLight_bitlen     1

/* TCM_SW_PositionLightInvalid */
#define TCM_SW_PositionLightInvalid_factor     1
#define TCM_SW_PositionLightInvalid_offset     0
#define TCM_SW_PositionLightInvalid_signed     0
#define TCM_SW_PositionLightInvalid_bitlen     1

/* TCM_SW_AutoLight */
#define TCM_SW_AutoLight_factor     1
#define TCM_SW_AutoLight_offset     0
#define TCM_SW_AutoLight_signed     0
#define TCM_SW_AutoLight_bitlen     1

/* TCM_SW_AutoLightInvalid */
#define TCM_SW_AutoLightInvalid_factor     1
#define TCM_SW_AutoLightInvalid_offset     0
#define TCM_SW_AutoLightInvalid_signed     0
#define TCM_SW_AutoLightInvalid_bitlen     1

/* TCM_SW_Trip */
#define TCM_SW_Trip_factor     1
#define TCM_SW_Trip_offset     0
#define TCM_SW_Trip_signed     0
#define TCM_SW_Trip_bitlen     2

/* TCM_IHBC_MenuReq */
#define TCM_IHBC_MenuReq_factor     1
#define TCM_IHBC_MenuReq_offset     0
#define TCM_IHBC_MenuReq_signed     0
#define TCM_IHBC_MenuReq_bitlen     1

/* TCM_IHBC_MenuReqInvalid */
#define TCM_IHBC_MenuReqInvalid_factor     1
#define TCM_IHBC_MenuReqInvalid_offset     0
#define TCM_IHBC_MenuReqInvalid_signed     0
#define TCM_IHBC_MenuReqInvalid_bitlen     1

/* TCM_IntegrationSwtCtrl_AliveCounter */
#define TCM_IntegrationSwtCtrl_AliveCounter_factor     1
#define TCM_IntegrationSwtCtrl_AliveCounter_offset     0
#define TCM_IntegrationSwtCtrl_AliveCounter_signed     0
#define TCM_IntegrationSwtCtrl_AliveCounter_bitlen     4

/* TCM_Checksum */
#define TCM_Checksum_factor     1
#define TCM_Checksum_offset     0
#define TCM_Checksum_signed     0
#define TCM_Checksum_bitlen     8
#endif


/* 0x283 - BCM_ACCinfor */
/*----------------------------------------------------------------------------*/

#if 0
/* BCM_CruiseSwInvalidSts */
#define BCM_CruiseSwInvalidSts_factor     1
#define BCM_CruiseSwInvalidSts_offset     0
#define BCM_CruiseSwInvalidSts_signed     0
#define BCM_CruiseSwInvalidSts_bitlen     2

/* BCM_ACCCancel_Reserved */
#define BCM_ACCCancel_Reserved_factor     1
#define BCM_ACCCancel_Reserved_offset     0
#define BCM_ACCCancel_Reserved_signed     0
#define BCM_ACCCancel_Reserved_bitlen     1

/* BCM_ACCvPlus_Resume */
#define BCM_ACCvPlus_Resume_factor     1
#define BCM_ACCvPlus_Resume_offset     0
#define BCM_ACCvPlus_Resume_signed     0
#define BCM_ACCvPlus_Resume_bitlen     1

/* BCM_ACCvMinus_Set */
#define BCM_ACCvMinus_Set_factor     1
#define BCM_ACCvMinus_Set_offset     0
#define BCM_ACCvMinus_Set_signed     0
#define BCM_ACCvMinus_Set_bitlen     1

/* BCM_ACCtauGapSetPlus */
#define BCM_ACCtauGapSetPlus_factor     1
#define BCM_ACCtauGapSetPlus_offset     0
#define BCM_ACCtauGapSetPlus_signed     0
#define BCM_ACCtauGapSetPlus_bitlen     1

/* BCM_ACCtauGapSetMinus */
#define BCM_ACCtauGapSetMinus_factor     1
#define BCM_ACCtauGapSetMinus_offset     0
#define BCM_ACCtauGapSetMinus_signed     0
#define BCM_ACCtauGapSetMinus_bitlen     1

/* BCM_Set_ResumeSwInvalidSts */
#define BCM_Set_ResumeSwInvalidSts_factor     1
#define BCM_Set_ResumeSwInvalidSts_offset     0
#define BCM_Set_ResumeSwInvalidSts_signed     0
#define BCM_Set_ResumeSwInvalidSts_bitlen     2

/* BCM_ACCMainSwitchSts */
#define BCM_ACCMainSwitchSts_factor     1
#define BCM_ACCMainSwitchSts_offset     0
#define BCM_ACCMainSwitchSts_signed     0
#define BCM_ACCMainSwitchSts_bitlen     1
#endif

/* BCM_DM_TargetModeReq */
#define BCM_DM_TargetModeReq_factor     1
#define BCM_DM_TargetModeReq_offset     0
#define BCM_DM_TargetModeReq_signed     0
#define BCM_DM_TargetModeReq_bitlen     3

#if 0
/* BCM_DM_SwitchModeSts */
#define BCM_DM_SwitchModeSts_factor     1
#define BCM_DM_SwitchModeSts_offset     0
#define BCM_DM_SwitchModeSts_signed     0
#define BCM_DM_SwitchModeSts_bitlen     3

/* BCM_DMSVehicleMode */
#define BCM_DMSVehicleMode_factor     1
#define BCM_DMSVehicleMode_offset     0
#define BCM_DMSVehicleMode_signed     0
#define BCM_DMSVehicleMode_bitlen     2

/* BCM_LIMMainSwitchSts */
#define BCM_LIMMainSwitchSts_factor     1
#define BCM_LIMMainSwitchSts_offset     0
#define BCM_LIMMainSwitchSts_signed     0
#define BCM_LIMMainSwitchSts_bitlen     1

/* BCM_LIMvPlus_Resume */
#define BCM_LIMvPlus_Resume_factor     1
#define BCM_LIMvPlus_Resume_offset     0
#define BCM_LIMvPlus_Resume_signed     0
#define BCM_LIMvPlus_Resume_bitlen     1

/* BCM_LIMvMinus_Set */
#define BCM_LIMvMinus_Set_factor     1
#define BCM_LIMvMinus_Set_offset     0
#define BCM_LIMvMinus_Set_signed     0
#define BCM_LIMvMinus_Set_bitlen     1

/* BCM_ACCinfor_AliveCounter */
#define BCM_ACCinfor_AliveCounter_factor     1
#define BCM_ACCinfor_AliveCounter_offset     0
#define BCM_ACCinfor_AliveCounter_signed     0
#define BCM_ACCinfor_AliveCounter_bitlen     4

/* BCM_ACCinfor_Checksum */
#define BCM_ACCinfor_Checksum_factor     1
#define BCM_ACCinfor_Checksum_offset     0
#define BCM_ACCinfor_Checksum_signed     0
#define BCM_ACCinfor_Checksum_bitlen     8
#endif


/* 0x284 - BCM_StateUpdate */
/*----------------------------------------------------------------------------*/

#if 0
/* BCM_WiperSts */
#define BCM_WiperSts_factor     1
#define BCM_WiperSts_offset     0
#define BCM_WiperSts_signed     0
#define BCM_WiperSts_bitlen     3

/* BCM_HoodAjarStatus */
#define BCM_HoodAjarStatus_factor     1
#define BCM_HoodAjarStatus_offset     0
#define BCM_HoodAjarStatus_signed     0
#define BCM_HoodAjarStatus_bitlen     2
#endif

/* BCM_TrunkAjarSt */
#define BCM_TrunkAjarSt_factor     1
#define BCM_TrunkAjarSt_offset     0
#define BCM_TrunkAjarSt_signed     0
#define BCM_TrunkAjarSt_bitlen     1

#if 0
/* BCM_ATWS_St */
#define BCM_ATWS_St_factor     1
#define BCM_ATWS_St_offset     0
#define BCM_ATWS_St_signed     0
#define BCM_ATWS_St_bitlen     3
#endif

/* BCM_ReverseGearInfo */
#define BCM_ReverseGearInfo_factor     1
#define BCM_ReverseGearInfo_offset     0
#define BCM_ReverseGearInfo_signed     0
#define BCM_ReverseGearInfo_bitlen     1


/* 0x285 - DDM_LDoorWindowState */
/*----------------------------------------------------------------------------*/

/* DDM_FrontLeftDoorAjarStatus */
#define DDM_FrontLeftDoorAjarStatus_factor     1
#define DDM_FrontLeftDoorAjarStatus_offset     0
#define DDM_FrontLeftDoorAjarStatus_signed     0
#define DDM_FrontLeftDoorAjarStatus_bitlen     1

/* DDM_RearLeftDoorAjarStatus */
#define DDM_RearLeftDoorAjarStatus_factor     1
#define DDM_RearLeftDoorAjarStatus_offset     0
#define DDM_RearLeftDoorAjarStatus_signed     0
#define DDM_RearLeftDoorAjarStatus_bitlen     1


/* 0x286 - PDM_RDoorWindowState */
/*----------------------------------------------------------------------------*/

/* PDM_FrontRightDoorAjarStatus */
#define PDM_FrontRightDoorAjarStatus_factor     1
#define PDM_FrontRightDoorAjarStatus_offset     0
#define PDM_FrontRightDoorAjarStatus_signed     0
#define PDM_FrontRightDoorAjarStatus_bitlen     1

/* PDM_RearRightDoorAjarStatus */
#define PDM_RearRightDoorAjarStatus_factor     1
#define PDM_RearRightDoorAjarStatus_offset     0
#define PDM_RearRightDoorAjarStatus_signed     0
#define PDM_RearRightDoorAjarStatus_bitlen     1


/* 0x294 - AVM_APAStatus */
/*----------------------------------------------------------------------------*/

/* AVM_APA_SystemSts */
#define AVM_APA_SystemSts_factor     1
#define AVM_APA_SystemSts_offset     0
#define AVM_APA_SystemSts_signed     0
#define AVM_APA_SystemSts_bitlen     3

/* AVM_APA_AutoSearchSts */
#define AVM_APA_AutoSearchSts_factor     1
#define AVM_APA_AutoSearchSts_offset     0
#define AVM_APA_AutoSearchSts_signed     0
#define AVM_APA_AutoSearchSts_bitlen     3

/* AVM_APA_ParkOutChkResult */
#define AVM_APA_ParkOutChkResult_factor     1
#define AVM_APA_ParkOutChkResult_offset     0
#define AVM_APA_ParkOutChkResult_signed     0
#define AVM_APA_ParkOutChkResult_bitlen     1

/* AVM_APA_CurrentPathNum */
#define AVM_APA_CurrentPathNum_factor     1
#define AVM_APA_CurrentPathNum_offset     0
#define AVM_APA_CurrentPathNum_signed     0
#define AVM_APA_CurrentPathNum_bitlen     4

/* AVM_APA_TotalPathNum */
#define AVM_APA_TotalPathNum_factor     1
#define AVM_APA_TotalPathNum_offset     0
#define AVM_APA_TotalPathNum_signed     0
#define AVM_APA_TotalPathNum_bitlen     4

/* AVM_APA_SuspendedReason */
#define AVM_APA_SuspendedReason_factor     1
#define AVM_APA_SuspendedReason_offset     0
#define AVM_APA_SuspendedReason_signed     0
#define AVM_APA_SuspendedReason_bitlen     3

/* AVM_APA_AbortReason */
#define AVM_APA_AbortReason_factor     1
#define AVM_APA_AbortReason_offset     0
#define AVM_APA_AbortReason_signed     0
#define AVM_APA_AbortReason_bitlen     5

/* AVM_APA_CurrentParkType */
#define AVM_APA_CurrentParkType_factor     1
#define AVM_APA_CurrentParkType_offset     0
#define AVM_APA_CurrentParkType_signed     0
#define AVM_APA_CurrentParkType_bitlen     3

/* AVM_APA_OverrideReason */
#define AVM_APA_OverrideReason_factor     1
#define AVM_APA_OverrideReason_offset     0
#define AVM_APA_OverrideReason_signed     0
#define AVM_APA_OverrideReason_bitlen     3

/* AVM_APA_VehicleDirection */
#define AVM_APA_VehicleDirection_factor     1
#define AVM_APA_VehicleDirection_offset     0
#define AVM_APA_VehicleDirection_signed     0
#define AVM_APA_VehicleDirection_bitlen     2

/* AVM_APA_CurrentStepNum */
#define AVM_APA_CurrentStepNum_factor     1
#define AVM_APA_CurrentStepNum_offset     0
#define AVM_APA_CurrentStepNum_signed     0
#define AVM_APA_CurrentStepNum_bitlen     4

/* AVM_APA_TerminatedType */
#define AVM_APA_TerminatedType_factor     1
#define AVM_APA_TerminatedType_offset     0
#define AVM_APA_TerminatedType_signed     0
#define AVM_APA_TerminatedType_bitlen     2

/* AVM_APA_ParkOutSystemStatus */
#define AVM_APA_ParkOutSystemStatus_factor     1
#define AVM_APA_ParkOutSystemStatus_offset     0
#define AVM_APA_ParkOutSystemStatus_signed     0
#define AVM_APA_ParkOutSystemStatus_bitlen     1


/* 0x2A7 - MMI_Configuration_Info */
/*----------------------------------------------------------------------------*/

/* MMI_OnroadCalibReq */
#define MMI_OnroadCalibReq_factor     1
#define MMI_OnroadCalibReq_offset     0
#define MMI_OnroadCalibReq_signed     0
#define MMI_OnroadCalibReq_bitlen     2

/* MMI_CarIconTransparentReq */
#define MMI_CarIconTransparentReq_factor     1
#define MMI_CarIconTransparentReq_offset     0
#define MMI_CarIconTransparentReq_signed     0
#define MMI_CarIconTransparentReq_bitlen     2


/* 0x2A8 - MMI_Safety_Info */
/*----------------------------------------------------------------------------*/

#if 0
/* MMI_Nav_SpeedLimit */
#define MMI_Nav_SpeedLimit_factor     1
#define MMI_Nav_SpeedLimit_offset     0
#define MMI_Nav_SpeedLimit_signed     0
#define MMI_Nav_SpeedLimit_bitlen     8

/* MMI_Nav_RampSts */
#define MMI_Nav_RampSts_factor     1
#define MMI_Nav_RampSts_offset     0
#define MMI_Nav_RampSts_signed     0
#define MMI_Nav_RampSts_bitlen     3

/* MMI_Nav_CurrRoadType */
#define MMI_Nav_CurrRoadType_factor     1
#define MMI_Nav_CurrRoadType_offset     0
#define MMI_Nav_CurrRoadType_signed     0
#define MMI_Nav_CurrRoadType_bitlen     3

/* MMI_Nav_status */
#define MMI_Nav_status_factor     1
#define MMI_Nav_status_offset     0
#define MMI_Nav_status_signed     0
#define MMI_Nav_status_bitlen     2

/* MMI_Nav_CountryID */
#define MMI_Nav_CountryID_factor     1
#define MMI_Nav_CountryID_offset     0
#define MMI_Nav_CountryID_signed     0
#define MMI_Nav_CountryID_bitlen     4
#endif

/* MMI_APA_Function_Select */
#define MMI_APA_Function_Select_factor     1
#define MMI_APA_Function_Select_offset     0
#define MMI_APA_Function_Select_signed     0
#define MMI_APA_Function_Select_bitlen     2

#if 0
/* MMI_RML_Function_Select */
#define MMI_RML_Function_Select_factor     1
#define MMI_RML_Function_Select_offset     0
#define MMI_RML_Function_Select_signed     0
#define MMI_RML_Function_Select_bitlen     1
#endif

/* MMI_APA_ConfirmButton */
#define MMI_APA_ConfirmButton_factor     1
#define MMI_APA_ConfirmButton_offset     0
#define MMI_APA_ConfirmButton_signed     0
#define MMI_APA_ConfirmButton_bitlen     2

/* MMI_PSC_Function_Select */
#define MMI_PSC_Function_Select_factor     1
#define MMI_PSC_Function_Select_offset     0
#define MMI_PSC_Function_Select_signed     0
#define MMI_PSC_Function_Select_bitlen     2

#if 0
/* MMI_SUM_ModSetSelection */
#define MMI_SUM_ModSetSelection_factor     1
#define MMI_SUM_ModSetSelection_offset     0
#define MMI_SUM_ModSetSelection_signed     0
#define MMI_SUM_ModSetSelection_bitlen     2

/* MMI_SUM_DMCorrelativeMode */
#define MMI_SUM_DMCorrelativeMode_factor     1
#define MMI_SUM_DMCorrelativeMode_offset     0
#define MMI_SUM_DMCorrelativeMode_signed     0
#define MMI_SUM_DMCorrelativeMode_bitlen     2

/* MMI_IBBrakeModeSet */
#define MMI_IBBrakeModeSet_factor     1
#define MMI_IBBrakeModeSet_offset     0
#define MMI_IBBrakeModeSet_signed     0
#define MMI_IBBrakeModeSet_bitlen     2
#endif

/* MMI_APA_AutoDetect */
#define MMI_APA_AutoDetect_factor     1
#define MMI_APA_AutoDetect_offset     0
#define MMI_APA_AutoDetect_signed     0
#define MMI_APA_AutoDetect_bitlen     1

/* MMI_APA_PopWindowsButton */
#define MMI_APA_PopWindowsButton_factor     1
#define MMI_APA_PopWindowsButton_offset     0
#define MMI_APA_PopWindowsButton_signed     0
#define MMI_APA_PopWindowsButton_bitlen     2

/* MMI_APA_MechanicalPark */
#define MMI_APA_MechanicalPark_factor     1
#define MMI_APA_MechanicalPark_offset     0
#define MMI_APA_MechanicalPark_signed     0
#define MMI_APA_MechanicalPark_bitlen     1


/* 0x2AB - AVM_ResponseCode */
/*----------------------------------------------------------------------------*/

/* AVM_MMI_Failure */
#define AVM_MMI_Failure_factor     1
#define AVM_MMI_Failure_offset     0
#define AVM_MMI_Failure_signed     0
#define AVM_MMI_Failure_bitlen     1

/* PCS_SingleViewInd */
#define PCS_SingleViewInd_factor     1
#define PCS_SingleViewInd_offset     0
#define PCS_SingleViewInd_signed     0
#define PCS_SingleViewInd_bitlen     4

/* AVM_BSDLeftWaring */
#define AVM_BSDLeftWaring_factor     1
#define AVM_BSDLeftWaring_offset     0
#define AVM_BSDLeftWaring_signed     0
#define AVM_BSDLeftWaring_bitlen     2

/* AVM_BSDRightWaring */
#define AVM_BSDRightWaring_factor     1
#define AVM_BSDRightWaring_offset     0
#define AVM_BSDRightWaring_signed     0
#define AVM_BSDRightWaring_bitlen     2

/* AVM_CarIconColorResp */
#define AVM_CarIconColorResp_factor     1
#define AVM_CarIconColorResp_offset     0
#define AVM_CarIconColorResp_signed     0
#define AVM_CarIconColorResp_bitlen     3

/* AVM_TrunningEnterAVMFuncResp */
#define AVM_TrunningEnterAVMFuncResp_factor     1
#define AVM_TrunningEnterAVMFuncResp_offset     0
#define AVM_TrunningEnterAVMFuncResp_signed     0
#define AVM_TrunningEnterAVMFuncResp_bitlen     1

/* PCS_ACU_DisplayReq */
#define PCS_ACU_DisplayReq_factor     1
#define PCS_ACU_DisplayReq_offset     0
#define PCS_ACU_DisplayReq_signed     0
#define PCS_ACU_DisplayReq_bitlen     1

/* AVM_CarIconTransparentResp */
#define AVM_CarIconTransparentResp_factor     1
#define AVM_CarIconTransparentResp_offset     0
#define AVM_CarIconTransparentResp_signed     0
#define AVM_CarIconTransparentResp_bitlen     1

/* AVM_HighTrunningEnterAVMFuncResp */
#define AVM_HighTrunningEnterAVMFuncResp_factor     1
#define AVM_HighTrunningEnterAVMFuncResp_offset     0
#define AVM_HighTrunningEnterAVMFuncResp_signed     0
#define AVM_HighTrunningEnterAVMFuncResp_bitlen     1


/* AVM_OnroadCalibResp */
#define AVM_OnroadCalibResp_factor     1
#define AVM_OnroadCalibResp_offset     0
#define AVM_OnroadCalibResp_signed     0
#define AVM_OnroadCalibResp_bitlen     1

/* AVM_BSD_FaultState */
#define AVM_BSD_FaultState_factor     1
#define AVM_BSD_FaultState_offset     0
#define AVM_BSD_FaultState_signed     0
#define AVM_BSD_FaultState_bitlen     1

/* AVM_DynamicPGS_Resp */
#define AVM_DynamicPGS_Resp_factor     1
#define AVM_DynamicPGS_Resp_offset     0
#define AVM_DynamicPGS_Resp_signed     0
#define AVM_DynamicPGS_Resp_bitlen     1

/* AVM_SoftKeyResponse */
#define AVM_SoftKeyResponse_factor     1
#define AVM_SoftKeyResponse_offset     0
#define AVM_SoftKeyResponse_signed     0
#define AVM_SoftKeyResponse_bitlen     1

/* AVM_FactoryMode */
#define AVM_FactoryMode_factor     1
#define AVM_FactoryMode_offset     0
#define AVM_FactoryMode_signed     0
#define AVM_FactoryMode_bitlen     1

/* AVM_BSD_StateResp */
#define AVM_BSD_StateResp_factor     1
#define AVM_BSD_StateResp_offset     0
#define AVM_BSD_StateResp_signed     0
#define AVM_BSD_StateResp_bitlen     1

/* AVM_MODEnableResp */
#define AVM_MODEnableResp_factor     1
#define AVM_MODEnableResp_offset     0
#define AVM_MODEnableResp_signed     0
#define AVM_MODEnableResp_bitlen     1

/* AVM_PDEnableResp */
#define AVM_PDEnableResp_factor     1
#define AVM_PDEnableResp_offset     0
#define AVM_PDEnableResp_signed     0
#define AVM_PDEnableResp_bitlen     1

/* AVM_ViewModeRespExtend */
#define AVM_ViewModeRespExtend_factor     1
#define AVM_ViewModeRespExtend_offset     0
#define AVM_ViewModeRespExtend_signed     0
#define AVM_ViewModeRespExtend_bitlen     4


/* 0x2AE - MMI_HUD_Msg */
/*----------------------------------------------------------------------------*/

/* MMI_AVM_TurnONSetResponse */
#define MMI_AVM_TurnONSetResponse_factor     1
#define MMI_AVM_TurnONSetResponse_offset     0
#define MMI_AVM_TurnONSetResponse_signed     0
#define MMI_AVM_TurnONSetResponse_bitlen     1

/* MMI_AVMViewAngleSwitch */
#define MMI_AVMViewAngleSwitch_factor     1
#define MMI_AVMViewAngleSwitch_offset     0
#define MMI_AVMViewAngleSwitch_signed     0
#define MMI_AVMViewAngleSwitch_bitlen     3

#if 0
/* MMI_AVMcPSCReturn_Reserved */
#define MMI_AVMcPSCReturn_Reserved_factor     1
#define MMI_AVMcPSCReturn_Reserved_offset     0
#define MMI_AVMcPSCReturn_Reserved_signed     0
#define MMI_AVMcPSCReturn_Reserved_bitlen     1

/* MMI_AVM_BSD */
#define MMI_AVM_BSD_factor     1
#define MMI_AVM_BSD_offset     0
#define MMI_AVM_BSD_signed     0
#define MMI_AVM_BSD_bitlen     1
#endif

/* MMI_AVMViewModeSwitch */
#define MMI_AVMViewModeSwitch_factor     1
#define MMI_AVMViewModeSwitch_offset     0
#define MMI_AVMViewModeSwitch_signed     0
#define MMI_AVMViewModeSwitch_bitlen     3

/* MMI_AVMViewModeSwitch_1 */
#define MMI_AVMViewModeSwitch_1_factor     1
#define MMI_AVMViewModeSwitch_1_offset     0
#define MMI_AVMViewModeSwitch_1_signed     0
#define MMI_AVMViewModeSwitch_1_bitlen     4

/* MMI_DynamicPGSRequest */
#define MMI_DynamicPGSRequest_factor     1
#define MMI_DynamicPGSRequest_offset     0
#define MMI_DynamicPGSRequest_signed     0
#define MMI_DynamicPGSRequest_bitlen     2

/* MMI_AVMMODEnableRequest */
#define MMI_AVMMODEnableRequest_factor     1
#define MMI_AVMMODEnableRequest_offset     0
#define MMI_AVMMODEnableRequest_signed     0
#define MMI_AVMMODEnableRequest_bitlen     2

/* MMI_AVMPDEnableRequest */
#define MMI_AVMPDEnableRequest_factor     1
#define MMI_AVMPDEnableRequest_offset     0
#define MMI_AVMPDEnableRequest_signed     0
#define MMI_AVMPDEnableRequest_bitlen     2

/* MMI_AVM_SoftKeyRequest */
#define MMI_AVM_SoftKeyRequest_factor     1
#define MMI_AVM_SoftKeyRequest_offset     0
#define MMI_AVM_SoftKeyRequest_signed     0
#define MMI_AVM_SoftKeyRequest_bitlen     2

/* MMI_AVM_Xcoordinate_Reserved */
#define MMI_AVM_Xcoordinate_Reserved_factor     1
#define MMI_AVM_Xcoordinate_Reserved_offset     0
#define MMI_AVM_Xcoordinate_Reserved_signed     0
#define MMI_AVM_Xcoordinate_Reserved_bitlen     12

/* MMI_AVM_Ycoordinate_Reserved */
#define MMI_AVM_Ycoordinate_Reserved_factor     1
#define MMI_AVM_Ycoordinate_Reserved_offset     0
#define MMI_AVM_Ycoordinate_Reserved_signed     0
#define MMI_AVM_Ycoordinate_Reserved_bitlen     11

/* MMI_AVM_TouchEventType_Reserved */
#define MMI_AVM_TouchEventType_Reserved_factor     1
#define MMI_AVM_TouchEventType_Reserved_offset     0
#define MMI_AVM_TouchEventType_Reserved_signed     0
#define MMI_AVM_TouchEventType_Reserved_bitlen     2

/* MMI_AVM_CarIconColorSet */
#define MMI_AVM_CarIconColorSet_factor     1
#define MMI_AVM_CarIconColorSet_offset     0
#define MMI_AVM_CarIconColorSet_signed     0
#define MMI_AVM_CarIconColorSet_bitlen     3

/* MMI_AVM_TrunningEnterAVMFuncSet */
#define MMI_AVM_TrunningEnterAVMFuncSet_factor     1
#define MMI_AVM_TrunningEnterAVMFuncSet_offset     0
#define MMI_AVM_TrunningEnterAVMFuncSet_signed     0
#define MMI_AVM_TrunningEnterAVMFuncSet_bitlen     2


/* 0x2E4 - RSRS_InformStatus */
/*----------------------------------------------------------------------------*/

#if 0
/* RSRS_SystemStatus */
#define RSRS_SystemStatus_factor     1
#define RSRS_SystemStatus_offset     0
#define RSRS_SystemStatus_signed     0
#define RSRS_SystemStatus_bitlen     2

/* RSRS_LCA_Status */
#define RSRS_LCA_Status_factor     1
#define RSRS_LCA_Status_offset     0
#define RSRS_LCA_Status_signed     0
#define RSRS_LCA_Status_bitlen     2

/* RSRS_RCTA_Status */
#define RSRS_RCTA_Status_factor     1
#define RSRS_RCTA_Status_offset     0
#define RSRS_RCTA_Status_signed     0
#define RSRS_RCTA_Status_bitlen     2

/* RSRS_RCW_Status */
#define RSRS_RCW_Status_factor     1
#define RSRS_RCW_Status_offset     0
#define RSRS_RCW_Status_signed     0
#define RSRS_RCW_Status_bitlen     2
#endif

/* RSRS_LCA_WarningLeft */
#define RSRS_LCA_WarningLeft_factor     1
#define RSRS_LCA_WarningLeft_offset     0
#define RSRS_LCA_WarningLeft_signed     0
#define RSRS_LCA_WarningLeft_bitlen     2

/* RSRS_LCA_WarningRight */
#define RSRS_LCA_WarningRight_factor     1
#define RSRS_LCA_WarningRight_offset     0
#define RSRS_LCA_WarningRight_signed     0
#define RSRS_LCA_WarningRight_bitlen     2

/* RSRS_RCTA_WarningLeft */
#define RSRS_RCTA_WarningLeft_factor     1
#define RSRS_RCTA_WarningLeft_offset     0
#define RSRS_RCTA_WarningLeft_signed     0
#define RSRS_RCTA_WarningLeft_bitlen     1

/* RSRS_RCTA_WarningRight */
#define RSRS_RCTA_WarningRight_factor     1
#define RSRS_RCTA_WarningRight_offset     0
#define RSRS_RCTA_WarningRight_signed     0
#define RSRS_RCTA_WarningRight_bitlen     1

#if 0
/* RSRS_RCW_Warning */
#define RSRS_RCW_Warning_factor     1
#define RSRS_RCW_Warning_offset     0
#define RSRS_RCW_Warning_signed     0
#define RSRS_RCW_Warning_bitlen     2

/* RSRS_DOW_State */
#define RSRS_DOW_State_factor     1
#define RSRS_DOW_State_offset     0
#define RSRS_DOW_State_signed     0
#define RSRS_DOW_State_bitlen     2
#endif

/* RSRS_DOW_WarningLeft */
#define RSRS_DOW_WarningLeft_factor     1
#define RSRS_DOW_WarningLeft_offset     0
#define RSRS_DOW_WarningLeft_signed     0
#define RSRS_DOW_WarningLeft_bitlen     2

/* RSRS_DOW_WarningRight */
#define RSRS_DOW_WarningRight_factor     1
#define RSRS_DOW_WarningRight_offset     0
#define RSRS_DOW_WarningRight_signed     0
#define RSRS_DOW_WarningRight_bitlen     2

#if 0
/* RSRS_InformStatus_AliveCounter */
#define RSRS_InformStatus_AliveCounter_factor     1
#define RSRS_InformStatus_AliveCounter_offset     0
#define RSRS_InformStatus_AliveCounter_signed     0
#define RSRS_InformStatus_AliveCounter_bitlen     4

/* RSRS_InformStatus_Checksum */
#define RSRS_InformStatus_Checksum_factor     1
#define RSRS_InformStatus_Checksum_offset     0
#define RSRS_InformStatus_Checksum_signed     0
#define RSRS_InformStatus_Checksum_bitlen     8
#endif


/* 0x380 - ACU_ChimeTelltaleReq */
/*----------------------------------------------------------------------------*/

/* SRS_DriverSeatBeltSt */
#define SRS_DriverSeatBeltSt_factor     1
#define SRS_DriverSeatBeltSt_offset     0
#define SRS_DriverSeatBeltSt_signed     0
#define SRS_DriverSeatBeltSt_bitlen     2

#if 0
/* ACU_PassSeatbeltWarning */
#define ACU_PassSeatbeltWarning_factor     1
#define ACU_PassSeatbeltWarning_offset     0
#define ACU_PassSeatbeltWarning_signed     0
#define ACU_PassSeatbeltWarning_bitlen     1

/* ACU_PassSeatOccupantSensorStat */
#define ACU_PassSeatOccupantSensorStat_factor     1
#define ACU_PassSeatOccupantSensorStat_offset     0
#define ACU_PassSeatOccupantSensorStat_signed     0
#define ACU_PassSeatOccupantSensorStat_bitlen     1

/* ACU_2nd_RSeatbeltBucklestatus */
#define ACU_2nd_RSeatbeltBucklestatus_factor     1
#define ACU_2nd_RSeatbeltBucklestatus_offset     0
#define ACU_2nd_RSeatbeltBucklestatus_signed     0
#define ACU_2nd_RSeatbeltBucklestatus_bitlen     1

/* ACU_PassengerAirbagStatus */
#define ACU_PassengerAirbagStatus_factor     1
#define ACU_PassengerAirbagStatus_offset     0
#define ACU_PassengerAirbagStatus_signed     0
#define ACU_PassengerAirbagStatus_bitlen     1

/* ACU_AirbagWarningStatus */
#define ACU_AirbagWarningStatus_factor     1
#define ACU_AirbagWarningStatus_offset     0
#define ACU_AirbagWarningStatus_signed     0
#define ACU_AirbagWarningStatus_bitlen     2

/* ACU_EPP_DTC_IndicatorSts */
#define ACU_EPP_DTC_IndicatorSts_factor     1
#define ACU_EPP_DTC_IndicatorSts_offset     0
#define ACU_EPP_DTC_IndicatorSts_signed     0
#define ACU_EPP_DTC_IndicatorSts_bitlen     1
#endif

/* ACU_DrvSeatbeltBuckleInvalid */
#define ACU_DrvSeatbeltBuckleInvalid_factor     1
#define ACU_DrvSeatbeltBuckleInvalid_offset     0
#define ACU_DrvSeatbeltBuckleInvalid_signed     0
#define ACU_DrvSeatbeltBuckleInvalid_bitlen     1

#if 0
/* ACU_PassSeatbeltBuckleInvalid */
#define ACU_PassSeatbeltBuckleInvalid_factor     1
#define ACU_PassSeatbeltBuckleInvalid_offset     0
#define ACU_PassSeatbeltBuckleInvalid_signed     0
#define ACU_PassSeatbeltBuckleInvalid_bitlen     1

/* ACU_2nd_LSeatbeltBucklestatus */
#define ACU_2nd_LSeatbeltBucklestatus_factor     1
#define ACU_2nd_LSeatbeltBucklestatus_offset     0
#define ACU_2nd_LSeatbeltBucklestatus_signed     0
#define ACU_2nd_LSeatbeltBucklestatus_bitlen     1

/* ACU_2nd_MSeatbeltBucklestatus */
#define ACU_2nd_MSeatbeltBucklestatus_factor     1
#define ACU_2nd_MSeatbeltBucklestatus_offset     0
#define ACU_2nd_MSeatbeltBucklestatus_signed     0
#define ACU_2nd_MSeatbeltBucklestatus_bitlen     1

/* ACU_ChimeTelltaleReq_AliveCounter */
#define ACU_ChimeTelltaleReq_AliveCounter_factor     1
#define ACU_ChimeTelltaleReq_AliveCounter_offset     0
#define ACU_ChimeTelltaleReq_AliveCounter_signed     0
#define ACU_ChimeTelltaleReq_AliveCounter_bitlen     4

/* ACU_ChimeTelltaleReq_Checksum */
#define ACU_ChimeTelltaleReq_Checksum_factor     1
#define ACU_ChimeTelltaleReq_Checksum_offset     0
#define ACU_ChimeTelltaleReq_Checksum_signed     0
#define ACU_ChimeTelltaleReq_Checksum_bitlen     8

/* ACU_CrashOutputSts */
#define ACU_CrashOutputSts_factor     1
#define ACU_CrashOutputSts_offset     0
#define ACU_CrashOutputSts_signed     0
#define ACU_CrashOutputSts_bitlen     8
#endif


/* 0x390 - PAS_PDC_Status */
/*----------------------------------------------------------------------------*/

/* PAS_Buzzer_Alarm_Pattern */
#define PAS_Buzzer_Alarm_Pattern_factor     1
#define PAS_Buzzer_Alarm_Pattern_offset     0
#define PAS_Buzzer_Alarm_Pattern_signed     0
#define PAS_Buzzer_Alarm_Pattern_bitlen     3

/* PAS_PDC_MODE */
#define PAS_PDC_MODE_factor     1
#define PAS_PDC_MODE_offset     0
#define PAS_PDC_MODE_signed     0
#define PAS_PDC_MODE_bitlen     3

/* PAS_PDC_ButtonPress */
#define PAS_PDC_ButtonPress_factor     1
#define PAS_PDC_ButtonPress_offset     0
#define PAS_PDC_ButtonPress_signed     0
#define PAS_PDC_ButtonPress_bitlen     1

/* PAS_PDC_DISTANCE_FL */
#define PAS_PDC_DISTANCE_FL_factor     1
#define PAS_PDC_DISTANCE_FL_offset     0
#define PAS_PDC_DISTANCE_FL_signed     0
#define PAS_PDC_DISTANCE_FL_bitlen     3

/* PAS_PDC_DISTANCE_FML */
#define PAS_PDC_DISTANCE_FML_factor     1
#define PAS_PDC_DISTANCE_FML_offset     0
#define PAS_PDC_DISTANCE_FML_signed     0
#define PAS_PDC_DISTANCE_FML_bitlen     3

/* PAS_PDC_DISTANCE_FMR */
#define PAS_PDC_DISTANCE_FMR_factor     1
#define PAS_PDC_DISTANCE_FMR_offset     0
#define PAS_PDC_DISTANCE_FMR_signed     0
#define PAS_PDC_DISTANCE_FMR_bitlen     3

/* PAS_PDC_DISTANCE_FR */
#define PAS_PDC_DISTANCE_FR_factor     1
#define PAS_PDC_DISTANCE_FR_offset     0
#define PAS_PDC_DISTANCE_FR_signed     0
#define PAS_PDC_DISTANCE_FR_bitlen     3

/* PAS_PDC_DISTANCE_RL */
#define PAS_PDC_DISTANCE_RL_factor     1
#define PAS_PDC_DISTANCE_RL_offset     0
#define PAS_PDC_DISTANCE_RL_signed     0
#define PAS_PDC_DISTANCE_RL_bitlen     3

/* PAS_PDC_DISTANCE_RML */
#define PAS_PDC_DISTANCE_RML_factor     1
#define PAS_PDC_DISTANCE_RML_offset     0
#define PAS_PDC_DISTANCE_RML_signed     0
#define PAS_PDC_DISTANCE_RML_bitlen     3

/* PAS_PDC_DISTANCE_RMR */
#define PAS_PDC_DISTANCE_RMR_factor     1
#define PAS_PDC_DISTANCE_RMR_offset     0
#define PAS_PDC_DISTANCE_RMR_signed     0
#define PAS_PDC_DISTANCE_RMR_bitlen     3

/* PAS_PDC_DISTANCE_RR */
#define PAS_PDC_DISTANCE_RR_factor     1
#define PAS_PDC_DISTANCE_RR_offset     0
#define PAS_PDC_DISTANCE_RR_signed     0
#define PAS_PDC_DISTANCE_RR_bitlen     3

/* PAS_PDC_DISTANCE_LSF */
#define PAS_PDC_DISTANCE_LSF_factor     1
#define PAS_PDC_DISTANCE_LSF_offset     0
#define PAS_PDC_DISTANCE_LSF_signed     0
#define PAS_PDC_DISTANCE_LSF_bitlen     3

/* PAS_PDC_DISTANCE_RSF */
#define PAS_PDC_DISTANCE_RSF_factor     1
#define PAS_PDC_DISTANCE_RSF_offset     0
#define PAS_PDC_DISTANCE_RSF_signed     0
#define PAS_PDC_DISTANCE_RSF_bitlen     3

/* PAS_PDC_DISTANCE_LSR */
#define PAS_PDC_DISTANCE_LSR_factor     1
#define PAS_PDC_DISTANCE_LSR_offset     0
#define PAS_PDC_DISTANCE_LSR_signed     0
#define PAS_PDC_DISTANCE_LSR_bitlen     3

/* PAS_PDC_DISTANCE_RSR */
#define PAS_PDC_DISTANCE_RSR_factor     1
#define PAS_PDC_DISTANCE_RSR_offset     0
#define PAS_PDC_DISTANCE_RSR_signed     0
#define PAS_PDC_DISTANCE_RSR_bitlen     3


/* 0x3F0 - IPK_DateTime_Info */
/*----------------------------------------------------------------------------*/

/* IPK_Second */
#define IPK_Second_factor     1
#define IPK_Second_offset     0
#define IPK_Second_signed     0
#define IPK_Second_bitlen     6

/* IPK_Minute */
#define IPK_Minute_factor     1
#define IPK_Minute_offset     0
#define IPK_Minute_signed     0
#define IPK_Minute_bitlen     6

/* IPK_Hour */
#define IPK_Hour_factor     1
#define IPK_Hour_offset     0
#define IPK_Hour_signed     0
#define IPK_Hour_bitlen     5

/* IPK_Day */
#define IPK_Day_factor     1
#define IPK_Day_offset     0
#define IPK_Day_signed     0
#define IPK_Day_bitlen     5

/* IPK_Month */
#define IPK_Month_factor     1
#define IPK_Month_offset     0
#define IPK_Month_signed     0
#define IPK_Month_bitlen     4

/* ACU_Time_Year */
#define ACU_Time_Year_factor     1
#define ACU_Time_Year_offset     2000
#define ACU_Time_Year_signed     0
#define ACU_Time_Year_bitlen     8

#if 0
/* IPK_VehicleStopTime */
#define IPK_VehicleStopTime_factor     1
#define IPK_VehicleStopTime_offset     0
#define IPK_VehicleStopTime_signed     0
#define IPK_VehicleStopTime_bitlen     12
#endif


#endif  /* _CAN_SIG_DEFS_H_ */


