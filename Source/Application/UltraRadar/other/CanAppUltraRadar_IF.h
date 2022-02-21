/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   		     *
*				  All Rights Reserved.          					                          *
*   Department 	: ITTI_HZ     									   		     *
*   AUTHOR	   	: 									                                 *
************************************************************************
* Object        		:
* Module        		:
* Instance      	:
* Description  		:
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 0.1    	2018/8/23   Zheng Xiaolei    Initial version
*======================================================*/
#ifndef CANAPP_ULTRA_RADAR_IF_H
#define CANAPP_ULTRA_RADAR_IF_H

#include "Define.h"

extern void CanAppUltraRadar_Init(void);
extern void CanAppUltraRadar_DeInit(void);
extern U8 Appl_AVMDVR_Send_FL(U16 flDistance);
extern U8 Appl_AVMDVR_Send_FR(U16 frDistance);
extern U8 Appl_AVMDVR_Send_FLM(U16 flmDistance);
extern U8 Appl_AVMDVR_Send_FRM(U16 frmDistance);
extern U8 Appl_AVMDVR_Send_RL(U16 rlDistance);
extern U8 Appl_AVMDVR_Send_RR(U16 rrDistance);
extern U8 Appl_AVMDVR_Send_RLM(U16 rlmDistance);
extern U8 Appl_AVMDVR_Send_RRM(U16 rrmDistance);
extern U8 Appl_AVMDVR_Send_FSL(U16 fslDistance);
extern U8 Appl_AVMDVR_Send_FSR(U16 fsrDistance);
extern U8 Appl_AVMDVR_Send_RSL(U16 rslDistance);
extern U8 Appl_AVMDVR_Send_RSR(U16 rsrDistance);
extern U8 Appl_AVMDVR_Send_FrontMid(U16 frontMidDistance);
extern U8 Appl_AVMDVR_Send_RearMid(U16 rearMidDistance);
extern U8 Appl_AVMDVR_Send_MessageReserveOne(U16 data);
extern U8 Appl_AVMDVR_Send_MessageReserveTwo(U16 data);

extern U8 Appl_AVMDVR_Send_FL_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_FML_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_FMR_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_FR_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_RL_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_RML_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_RMR_WarnZone(U8 zone);
extern U8 Appl_AVMDVR_Send_RR_WarnZone(U8 zone);

extern U8 Appl_AVMDVR_Send_SensorsStatus(U8 status);
extern U8 Appl_AVMDVR_Send_FL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_FR_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_FML_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_FMR_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RR_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RML_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RMR_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_FLL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_FRL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RLL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_RRL_EchoHeight(U8 echoheight);
extern U8 Appl_AVMDVR_Send_SoftVersionByte0(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte1(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte2(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte3(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte4(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte5(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte6(U8 data);
extern U8 Appl_AVMDVR_Send_SoftVersionByte7(U8 data);

U8 Appl_AVMDVR_Send_WarnControl(U8 Warning_Switch);
U8 Appl_AVMDVR_Send_WarnFz(U8 Warning_FZ);



extern void WarningBoardTest(void);

#endif/*CANAPP_IF_H*/
