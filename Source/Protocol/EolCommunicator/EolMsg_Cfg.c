/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*
*=====================================================================*/
#include "config.h"


#include "eOLMsg_Cfg.h"

const EOLMsgConfig EolMessageTable[E_MSGID_NUM] =
{
  //MsgValue
    {E_CMDTYPE_INVALID} ,
    {0x00},// E_MSDID_START_EOL,01
    {0x01},//  E_MSGID_ENTER_EOL,02
    {0x02},//  E_MSGID_J6_START_FROM_SD,03
    {0x05},//  E_MSGID_EXIST_EOL,04
    {0X30},//  E_MSGID_READ_BOOT_VERSION,05
    {0X31},//  E_MSGID_READ_HARDWARE_VERSION,06
    {0X32},//  E_MSGID_READ_J6OS_VERSION,07
    {0X33},//  E_MSGID_READ_J6SVP_VERSION,08
    {0x34},//  E_MSGID_WRITE_SERIAL_NUMBER,09
    {0x35},//  E_MSGID_READ_SERIAL_NUMBER,10
    {0x36},//  E_MSGID_READ_M3_DTC,11
    {0x37},//  E_MEGID_CLEAR_DTC,12
    {0x38},//  E_MSGID_READ_SOFTWARE_VERSION,13
    {0x40},//  E_MSGID_REPORT_J6_DTC_START,15
    {0x41},//  E_MSGID_REPORT_J6_DTC_RESULT,16
    {0x52},//  E_MSGID_ENTER_REVERSE_MODE,19 
    {0x60},//  E_MSGID_READ_POWER_DET,20
    {0x61},// E_MSGID_READ_CAN_POWER_DET,21
    {0x62},//  E_MSGID_READ_IGN,22    
    {0x55},//  E_MSGID_CTL_CAMERA,25
    {0x63},//  E_MSGID_READ_REVERSE_SIGNAL,26
    {0x66},//  E_MSGID_SET_ECU_MANUFACTURING_DATE      ,28
    {0x67},//  E_MSGID_GET_ECU_MANUFACTURING_DATE//E_MSGID_UPGRADE_J6_LICENSE_START,29
    {0x64},//  E_MSGID_READ_AVM_HW_IN,42
    {0x65},//  E_MSGID_READ_USB_INTERFACE_STATUS,43
    {0x57},//  E_MSGID_READ_SDCARD_INTERFACE_STATUS,47
	{0x56},//  E_MSGID_CTL_AVM_SHUT_DOWN_TIME,46
	{0x85},//  E_MSGID_CTL_DTCSETTING_OFF,50
	{0x86},//  E_MSGID_CTL_AVM_LED,49
  	{0x87},//  E_MSGID_CTL_APS_LED,50
  	{0x88},// E_MSGID_CTL_BSD_LLED,51
  	{0x89},// E_MSGID_CTL_BSD_RLED,52
  	{0x90},//E_MSGID_CTL_AVM_HARDKEY,53
  	{0x91},//E_MSGID_CTL_APS_HARDKEY,54
  	{0x94},//  E_MSGID_CTL_PDC_LED,57
	{0x95},//E_MSGID_CTL_PDC_HARDKEY,58
	{0x92},//  E_MSGID_RADAR_HW_DET,55	
	{0x93},//E_MSGID_RADAR_SEND_DATA,56
	{0x03},//  E_MSGID_REQ_J6_ENTER_SELF_DIAG,03
    
};

U8 GetEOLMessageIDValue(U8 MessageID)
{
    return EolMessageTable[MessageID].MsgIDVal;
}

U8 GetEOLMessageID(U8 val)
{
    U8 i = E_MSGID_INVALID;
    for(i = 0; i<E_MSGID_NUM;i++)
    {
        if(val == EolMessageTable[i].MsgIDVal)
        {
            return i;
        }
    }
    return (E_MSGID_INVALID);
}

/**************** END OF FILE *****************************************/

