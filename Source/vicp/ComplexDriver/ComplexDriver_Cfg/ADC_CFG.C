/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Shao Guangxian										   *
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
* 0.1    Feb 10,2013    NI Rujin    Initial version
* ----------------------------------------------------------------------
* 0.2    JUN 6,2015    Shang Qiuju  Add signal configuration
*------------------------------------------------------------------------
* 0.3    Jan 24,2017  ZhangJie  Update for Coverity warnings.
*=====================================================================*/
#include "ADC_CFG.H"
#include "Config.h" 

const Sig_ADChannelConfigType Sig_AD0Config[SIG_AD0_NUM]=
{
	{FALSE, 0,E_AD},// ,SIG_AD0_PWR_VALUE 	
	{FALSE, 8,E_AD},// ,SIG_AD0_TEMP		8
	{FALSE, 5,E_AD},//SIG_AD_CAMERA_B_PWR,
	{FALSE, 6,E_AD},//SIG_AD_CAMERA_F_PWR,
	{FALSE, 3,E_AD},//SIG_AD_CAMERA_R_PWR,
	{FALSE, 4,E_AD},//SIG_AD_CAMERA_L_PWR,
	{FALSE, 1,E_AD},//SIG_AD_RADAR_F_PWR,
	{FALSE, 2,E_AD},//SIG_AD_RADAR_R_PWR,


};

#if (MCU_PIN > PIN100)
const Sig_ADChannelConfigType Sig_AD1Config[SIG_AD1_NUM]=
{
	{FALSE,0,E_AD}, //SIG_AD_BSD_Right
	{FALSE,1,E_AD}, //SIG_AD_BSD_Left
	{FALSE,2,E_AD}, //SIG_AD_APA_LED
	{FALSE,3,E_AD}, //SIG_AD_PDC_LED
	{FALSE,4,E_AD}, //SIG_AD_BSD_LED
	{TRUE,0,E_AD},
	{TRUE,0,E_AD},
	{TRUE,0,E_AD},

};
#endif
 


/**************** END OF FILE *****************************************/
