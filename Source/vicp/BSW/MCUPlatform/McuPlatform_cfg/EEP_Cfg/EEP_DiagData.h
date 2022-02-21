/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department : CT AD                                         *
*   AUTHOR     :                                       *
************************************************************************
* Object        :EEP_DiagData.h
* Module        :
* Instance      :
* Description   : Implementation of the EEPROM Download Handler (EED)
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date            Name        Changes and comments
* 0.1    Jan 1. 2016       ShangQiuju      Initial Version
*=====================================================================*/
#ifndef _EEP_DIAG_DATA_FLAG_H_
#define _EEP_DIAG_DATA_FLAG_H_
#include "CONFIG.H"
#include "TYPES.H"
/*
* Warning: There is no check if the compiler supports
*          the assumed byte and bitorder !!!
* The following assumptions are made:
* - The byte order for words is defined through the corresponding Mapping Table switch
* - Bit 0 is the first bit in the bit union structure
* - A bitfield of 8 bits consumes only one byte of memory (also for the allignment)
*/

typedef struct _EED_tstDIAGDATA0
{
	U8 BackupConfigurationInformation_64[4];
	U8 AVM_FunctionConfiguration_F101[4];
	U8 SystemNameOrEngineType[8];
	U8 ECUManufacturingDate[4];
	U8 security_counter[1];
    U8 Unused[9]; /*default:0*/
	U8 EEPchecksum[2];
} EED_tstDIAGDATA0;

typedef struct _EED_tstDIAGDATA1
{
	U8 RepairShopCodeOrTesterSerialNumber[16];
//	U8 Vehilce_vcu_cfg;
	U8 ECUInstallationDate[4];
	U8 VehicleNetworkConfiguration_F110[8];
	U8 PDCBuzzerSwitch[1];
    U8 Unused[1]; /*default:0*/
	U8 EEPchecksum[2];
} EED_tstDIAGDATA1;

extern EED_tstDIAGDATA0 Ram_DiagData0;

extern const U8 Rom_DiagData0[];

#define EED_AVM_FunctionConfiguration_F101        Ram_DiagData0.AVM_FunctionConfiguration_F101
#define EED_SystemNameOrEngineType                Ram_DiagData0.SystemNameOrEngineType
#define EED_ECUManufacturingDate				  Ram_DiagData0.ECUManufacturingDate
#define EED_Security_Counter			  	      Ram_DiagData0.security_counter
#define EED_BackupConfigurationInformation_64     Ram_DiagData0.BackupConfigurationInformation_64

#endif /*_EEP_DIAG_DATA_FLAG_H_*/
/****************************** END OF FILE ***************************/
