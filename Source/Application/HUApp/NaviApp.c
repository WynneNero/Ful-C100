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
* ----------------------------------------------------------------------
* 0.1  Mar 01,2013  NI Rujin    Initial version
* ----------------------------------------------------------------------
* 0.2  Jul 10,2013  SHANG Qiuju Add Navi event handler
* ----------------------------------------------------------------------
* 0.3  Aug 06,2013  NI Rujin    Update code to get GPS info
-----------------------------------------------------------------------
* 0.4  Sep 22,2013 ShangQiuju Remove Navi event handler
-----------------------------------------------------------------------
* 0.5  Feb 20,2014 LIU Chenxi Update version information for CHB022
-----------------------------------------------------------------------
* 0.6  May 20,2014 WANG Yong  Add firmware update feature
-----------------------------------------------------------------------
* 0.7  May 29,2014 LIU Chenxi  Fix overflow issue in HB message
-----------------------------------------------------------------------
* 0.8  May 30,2014 ShangQiuju  Add new service related with debug mode and
       fix issues found during code review.
-----------------------------------------------------------------------
* 0.9  Jul 29,2014 LIU Chenxi  Check modem manager regist status before
       Open USB channel.
-----------------------------------------------------------------------
* 1.0  Nov 13,2014 LIU Chenxi  Merge HZH code: Get O2 encrypted GPS data
       from HU side.
*=====================================================================*/

#include "TYPES.H"
#include "NaviApp.h"
#include "SocCommunicator.H"
#include "SocManager.h" 
#include "UssInfoMsg.h"



extern void navi_req_sw_version(void);


#define C095_HW
#pragma ghs section rodata = ".myconst"

#ifdef C095_HW
const U8 SoftVersion[24]={"C100-SA_M220216_000028"};
const U8 APA_ALG_SoftVersion[24]={"C100-SA_U220125_000001"};
const U8 GACECUSoftwareVersionNumber[17]={"HW001210629"};//zwy diag Ecu ver
U8 HardVersion[16]={"HW001210629"};
U8 PartNum[16]={"3785250-HF03    "};

U8 USS_ALG_SoftVersion[22]= {"C100-SA_U220125_000001"};
U8 SW_VERSION_LEN =22;
U8 SW_VERSION_ALG_LEN = 22;
U8 USS_ALG_SOFT_VERSION_LEN1 = 22;


U8 HW_VERSION_LEN = 16;
U8 GACECU_SW_VERSION_LEN = 16;
#endif 

#pragma ghs section rodata = default



void SocNavi_20ms_Entry(void)
{
	navi_req_sw_version();
}


BOOL bJ6RequestM3Version=FALSE;
BOOL bJ6RequestUSSVersion=FALSE;
BOOL bJ6RequestALGVersion=FALSE;
BOOL bJ6RequestUssVersionNumber_SS=FALSE;
BOOL bJ6RequestUssVersionNumber_OD=FALSE;

extern char UssSlotSearchingAlgSoftVersion[19];
extern char UssObjectDetectAlgSoftVersion[19];
void navi_req_sw_version(void)
{
  	U8 i;
	U8 j;
	U8 k;
	U8 SPI_SoftVersion_MCU[27] = {0};
	U8 SPI_SpftVersion_USS[27] = {0};
	U8 SPI_SpftVersion_ALG[27] = {0};
    U8 SPI_UssSoftVerionSS[27] = {0};
	U8 SPI_UssSoftVerionOD[27] = {0};
    if(bJ6RequestM3Version)
    {
        bJ6RequestM3Version = FALSE;
		SPI_SoftVersion_MCU[0] = SW_VERSION_LEN;//length
		SPI_SoftVersion_MCU[1] = 0x00;//type mcu
		for(i=0; i< SW_VERSION_LEN;i++)
		{
			SPI_SoftVersion_MCU[i+2] = SoftVersion[i];
		}		
		SocManager_SendMsg(LQ_CMD,TYPE_RESPONSE,SEND_SOFT_VERSION_TO_SOC, SW_VERSION_LEN+2,SPI_SoftVersion_MCU);
	}
	if(bJ6RequestUSSVersion)
	{
		bJ6RequestUSSVersion = FALSE;
		SPI_SpftVersion_USS[0] = USS_ALG_SOFT_VERSION_LEN1;//length
		SPI_SpftVersion_USS[1] = 0x01;//type uss
		for(j=0; j< USS_ALG_SOFT_VERSION_LEN1;j++)
		{
			SPI_SpftVersion_USS[j+2] = USS_ALG_SoftVersion[j];
		}	
		SocManager_SendMsg(LQ_CMD,TYPE_RESPONSE,SEND_SOFT_VERSION_TO_SOC, USS_ALG_SOFT_VERSION_LEN1+2,SPI_SpftVersion_USS);
	}
	if(bJ6RequestALGVersion)
	{
		bJ6RequestALGVersion = FALSE;
		SPI_SpftVersion_ALG[0] = SW_VERSION_ALG_LEN;//length
		SPI_SpftVersion_ALG[1] = 0x02;//type ALG
		for(k=0; k< SW_VERSION_ALG_LEN;k++)
		{
			SPI_SpftVersion_ALG[k+2] = APA_ALG_SoftVersion[k];
		}	
		SocManager_SendMsg(LQ_CMD,TYPE_RESPONSE,SEND_SOFT_VERSION_TO_SOC, SW_VERSION_ALG_LEN+2,SPI_SpftVersion_ALG);
	}
	if(bJ6RequestUssVersionNumber_OD)
    {
        bJ6RequestUssVersionNumber_OD = FALSE;    
    	SPI_UssSoftVerionOD[0] = SW_VERSION_LEN;
		SPI_UssSoftVerionOD[1] = 0x03;
		for(j=0; j<19;j++)
		{
			SPI_UssSoftVerionOD[j+2] = UssObjectDetectAlgSoftVersion[j];
		}
		SocManager_SendMsg(LQ_CMD,TYPE_RESPONSE,SEND_SOFT_VERSION_TO_SOC, SW_VERSION_LEN+1,SPI_UssSoftVerionOD);
	}
	if(bJ6RequestUssVersionNumber_SS)
    {
        bJ6RequestUssVersionNumber_SS = FALSE;    
    	SPI_UssSoftVerionSS[0] = SW_VERSION_LEN;
		SPI_UssSoftVerionSS[1] = 0x05;
		for(j=0; j<19;j++)
		{
			SPI_UssSoftVerionSS[j+2] = UssSlotSearchingAlgSoftVersion[j];
		}
		SocManager_SendMsg(LQ_CMD,TYPE_RESPONSE,SEND_SOFT_VERSION_TO_SOC, SW_VERSION_LEN+1,SPI_UssSoftVerionSS);
	}
}
void NaviApp_GetM3SoftVersion(U8* version)
{
    _memcpy(version ,(U8*)SoftVersion,SW_VERSION_LEN);
}


void NaviApp_GetM3HardVersion(U8* version)
{
    _memcpy(version ,(U8*)HardVersion,HW_VERSION_LEN);
}

void NaviApp_GetM3GACSoftVersion(U8* version)
{
    _memcpy(version ,(U8*)GACECUSoftwareVersionNumber,GACECU_SW_VERSION_LEN);
}




/**************** END OF FILE *****************************************/

