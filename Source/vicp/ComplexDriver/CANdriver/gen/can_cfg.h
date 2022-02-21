/* -----------------------------------------------------------------------------
  Filename:    can_cfg.h
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: DrvCan__base
               
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

#if !defined(__CAN_CFG_H__)
#define __CAN_CFG_H__

#include "v_cfg.h"
#define HW_SH2RSCANCPUCANDLL_VERSION         0x0212u
#define HW_SH2RSCANCPUCANDLL_RELEASE_VERSION 0x00u

#define HW__BASECPUCANDLL_VERSION            0x0300u
#define HW__BASECPUCANDLL_RELEASE_VERSION    0x01u

#define DRVCAN__BASEDLL_VERSION              0x0325u
#define DRVCAN__BASEDLL_RELEASE_VERSION      0x00u

#define DRVCAN__BASERI14DLL_VERSION          0x0209u
#define DRVCAN__BASERI14DLL_RELEASE_VERSION  0x01u

#define DRVCAN__BASERI15DLL_VERSION          0x0109u
#define DRVCAN__BASERI15DLL_RELEASE_VERSION  0x00u

#define DRVCAN__BASEHLLDLL_VERSION           0x0307u
#define DRVCAN__BASEHLLDLL_RELEASE_VERSION   0x00u

#define DRVCAN__BASERI14HLLDLL_VERSION       0x0208u
#define DRVCAN__BASERI14HLLDLL_RELEASE_VERSION 0x00u

#define DRVCAN__BASERI15HLLDLL_VERSION       0x0103u
#define DRVCAN__BASERI15HLLDLL_RELEASE_VERSION 0x00u


#define kCanNumberOfChannels                 2
#define kCanNumberOfHwChannels               2
#define kCanNumberOfPhysChannels             2
#define C_DISABLE_MEMCOPY_SUPPORT
#define C_ENABLE_OSEK_OS
#define C_DISABLE_VARIABLE_DLC
#define C_DISABLE_DLC_FAILED_FCT
#define C_DISABLE_VARIABLE_RX_DATALEN
#define C_DISABLE_MULTI_ECU_CONFIG
#define C_DISABLE_MULTI_ECU_PHYS
#define C_DISABLE_EXTENDED_ID
#define C_DISABLE_MIXED_ID
#define C_ENABLE_RECEIVE_FCT

#define C_DISABLE_ECU_SWITCH_PASS
#define C_ENABLE_TRANSMIT_QUEUE
#define C_ENABLE_OVERRUN
#define C_DISABLE_INTCTRL_BY_APPL
#define C_DISABLE_COMMON_CAN
#define C_DISABLE_USER_CHECK
#define C_DISABLE_HARDWARE_CHECK
#define C_DISABLE_GEN_CHECK
#define C_DISABLE_INTERNAL_CHECK
#define C_DISABLE_DYN_RX_OBJECTS
#define C_ENABLE_DYN_TX_OBJECTS
#define C_ENABLE_DYN_TX_ID
#define C_ENABLE_DYN_TX_DLC
#define C_DISABLE_DYN_TX_DATAPTR
#define C_DISABLE_DYN_TX_PRETRANS_FCT
#define C_DISABLE_DYN_TX_CONF_FCT
#define C_ENABLE_EXTENDED_STATUS
#define C_DISABLE_TX_OBSERVE
#define C_DISABLE_HW_LOOP_TIMER
#define C_DISABLE_NOT_MATCHED_FCT
#define C_SECURITY_LEVEL                     30

#define C_ENABLE_MULTICHANNEL_API
#define C_ENABLE_PART_OFFLINE
#define C_ENABLE_RANGE_0
#define C_ENABLE_RANGE_1
#define C_DISABLE_RANGE_2
#define C_DISABLE_RANGE_3
#define kCanNumberOfTxObjects                57
#define kCanNumberOfTxStatObjects            56
#define kCanNumberOfTxDynObjects             1
#define kCanNumberOfRxObjects                50
#define kCanNumberOfRxStatFullCANObjects     42
#define kCanNumberOfRxStatBasicCANObjects    8
#define kCanNumberOfRxDynFullCANObjects      0
#define kCanNumberOfRxDynBasicCANObjects     0
#define kCanNumberOfRxDynObjects             0
#define kCanNumberOfRxStatObjects            50
#define kCanNumberOfConfFlags                57
#define kCanNumberOfIndFlags                 0
#define kCanNumberOfConfirmationFlags        8
#define kCanNumberOfIndicationFlags          0
#define kCanNumberOfInitObjects              2
#define kCanExtNumberOfInitObjects           0
#define C_SEARCH_LINEAR

#define C_ENABLE_RX_MSG_INDIRECTION

#define C_ENABLE_CONFIRMATION_FLAG
#define C_DISABLE_INDICATION_FLAG
#define C_ENABLE_PRETRANSMIT_FCT
#define C_ENABLE_CONFIRMATION_FCT
#define C_ENABLE_INDICATION_FCT
#define C_ENABLE_PRECOPY_FCT
#define C_ENABLE_COPY_TX_DATA
#define C_ENABLE_COPY_RX_DATA
#define C_ENABLE_DLC_CHECK
#define C_DISABLE_DLC_CHECK_MIN_DATALEN

#define C_ENABLE_GENERIC_PRECOPY
#define APPL_CAN_GENERIC_PRECOPY             IlCanGenericPrecopy

#define C_SEND_GRP_NONE                      0x00u
#define C_SEND_GRP_ALL                       0xFFu
#define C_SEND_GRP_IL                        0x01u
#define C_SEND_GRP_NM                        0x02u
#define C_SEND_GRP_DIAG                      0x04u
#define C_SEND_GRP_USER3                     0x08u
#define C_SEND_GRP_USER4                     0x10u
#define C_SEND_GRP_USER5                     0x20u
#define C_SEND_GRP_USER6                     0x40u
#define C_SEND_GRP_USER7                     0x80u
#define C_ENABLE_CAN_CANCEL_NOTIFICATION

#define CANCHANNEL_0
#define CANCHANNEL_1
#define kCanIndex0                           0
#define kCanIndex1                           1
#define kCanPhysToLogChannelIndex_1          0
#define kCanPhysToLogChannelIndex_0          1
#define C_ENABLE_RX_FULLCAN_OBJECTS
#define C_ENABLE_RX_BASICCAN_OBJECTS
#define kCanNumberOfRxFullCANObjects         42

#define kCanNumberOfRxBasicCANObjects        8
#define kCanNumberOfUsedRxBasicCANObjects    2

#define kCanInitObj1                         0
#define C_DISABLE_TX_MASK_EXT_ID
#define C_DISABLE_RX_MASK_EXT_ID
#define C_MASK_EXT_ID                        0xFFFFFFFFu

#define C_ENABLE_CAN_CAN_INTERRUPT_CONTROL
#define C_DISABLE_CAN_TX_CONF_MSG_ACCESS
#define C_ENABLE_CAN_TX_CONF_FCT
#define APPL_CAN_TX_CONFIRMATION             ApplCanTxConfirmation

#define C_DISABLE_TX_POLLING
#define C_DISABLE_RX_BASICCAN_POLLING
#define C_ENABLE_RX_FULLCAN_POLLING
#define C_DISABLE_ERROR_POLLING
#define C_DISABLE_WAKEUP_POLLING
#define C_DISABLE_FULLCAN_OVERRUN
#define C_ENABLE_OSEK_OS_INTCAT2
#define C_DISABLE_COPY_RX_DATA_WITH_DLC
#define kCanTxQueueBytes                     12
#define kCanTxQueuePadBits                   39
#define kCanNumberOfMaxBasicCAN              2
#define kCanNumberOfHwObjPerBasicCan         1
#define C_DISABLE_CAN_RAM_CHECK
#define C_ENABLE_SLEEP_WAKEUP
#define C_DISABLE_CANCEL_IN_HW
#define C_DISABLE_ONLINE_OFFLINE_CALLBACK_FCT

#define kCanChannel_Channel0                 0
#define kCanChannel_Channel1                 1
#define C_DISABLE_INTCTRL_ADD_CAN_FCT
#if defined(C_SINGLE_RECEIVE_BUFFER) || defined(C_MULTIPLE_RECEIVE_BUFFER)
#error "DrvCan__baseRI1.5 doesn't support Single/Multiple Receive Buffer API for the callback 'ApplCanMsgReceived'!"
#endif

#define C_DISABLE_RETRANSMIT
#define kCanNumberOfUsedCanTxIdTables        1
#define kCanNumberOfUsedCanRxIdTables        1
#define kCanNumberOfUsedTxCANObjects         2

#define kCanNumberOfUnusedObjects            130

#define kCanNumberOfTxDirectObjects          0

#define C_DISABLE_TX_FULLCAN_OBJECTS


#define C_ENABLE_HW_OBJ_EXCEED_255_CFG

#define C_DISABLE_INDIVIDUAL_POLLING
#define kCanNumberOfHwObjIndivPolling        288u

/* -----------------------------------------------------------------------------
    &&&~ Hw specific defines
 ----------------------------------------------------------------------------- */

#define kCanBaseAdr                          0xFFD00000u
#define kCanIntcRxFifoBaseAdr                0xFFFEEA2Eu
#define kCanIntcGErrorBaseAdr                0xFFFEEA2Cu
#define kCanMaxPhysChannels                  4u
#define kCanRxBufOffset                      0u
#define kCanRxFifoOffset                     128u
#define kCanMaxRxFifos                       8u
#define kCanMaxTxFifos                       3u
#define kCanMaxTxBuf                         16u
#define kCanMaxRxBuf                         64u
#define kCanMaxHwObjects                     288u
#define kCanNumberOfRxFifos                  2u
#define kCanNumberOfFilterRules              46u
#define kCanFifoToLogChannelIndex_0          1u
#define kCanFifoToLogChannelIndex_1          0u
#define kCanNumberOfSharedReg16              2u
#define kCanMaxPoolBuf                       256u
#define kCanMaxRules                         256u
#define kCanTxBufOffset_0                    160u
#define kCanTxBufOffset_1                    176u
#define kCanTxBufOffset_2                    192u
#define kCanTxBufOffset_3                    208u
#define C_DISABLE_ALTERNATIVE_CLOCK_SOURCE
#define C_ENABLE_BUSWAKEUP_SUPPORT
#define C_ENABLE_IF_RSCAN





/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\can_cfg.h> is different. Please check time and date of generated files!"
  #endif
#else
  #define MAGIC_NUMBER 390049630
#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

#endif /* __CAN_CFG_H__ */
