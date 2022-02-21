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
#include "Define.h"
#include "CanApp.h"
#include "Can_App_il.h"
#include "CanSig_Def.h"
#include "CanSig_cfg.h"
#include "can_cfg.h"
#include "can_def.h"
#include "Cansig_cfg_if.h"
#include "CanAppUltraRadar.h"
#include "CanAppUltraRadar_IF.h"

/*---Global-------------------------------------------------------------*/

/*===FUNCTIONS===========================================*/


/***********************************************************************
* FUNCTION    : CanAppUltraRadar_Init
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void CanAppUltraRadar_Init(void)
{

}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void CanAppUltraRadar_DeInit(void)
{ 

}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FL(U16 flDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FL_16U, (U8*)&flDistance, 2);
	return ret;
	
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FR(U16 frDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FR_16U, (U8*)&frDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FLM(U16 flmDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FML_16U, (U8*)&flmDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FRM(U16 frmDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_FMR_16U, (U8*)&frmDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RL(U16 rlDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RL_16U, (U8*)&rlDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RR(U16 rrDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RR_16U, (U8*)&rrDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RLM(U16 rlmDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RML_16U, (U8*)&rlmDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RRM(U16 rrmDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_RMR_16U, (U8*)&rrmDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FSL(U16 fslDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_FLL_16U, (U8*)&fslDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FSR(U16 fsrDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_FRL_16U, (U8*)&fsrDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RSL(U16 rslDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_RLL_16U, (U8*)&rslDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RSR(U16 rsrDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sides_RRL_16U, (U8*)&rsrDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FrontMid
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FrontMid(U16 frontMidDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Front_Mid_16U, (U8*)&frontMidDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RearMid
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RearMid(U16 rearMidDistance)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Rear_Mid_16U, (U8*)&rearMidDistance, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_MessageReserveOne
* DESCRIPTION : For test
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_MessageReserveOne(U16 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_MessageReserveOne, (U8*)&data, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_MessageReserveTwo
* DESCRIPTION : For test
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_MessageReserveTwo(U16 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_MessageReserveTwo, (U8*)&data, 2);
	return ret;
}


/***********************************************************************
* FUNCTION    : CanAppUltraRadar_DeInit
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SensorsStatus(U8 status)
{
	U8 ret = 0;
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_Sensors_StatusValid_16U, (U8*)&status, 2);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FR_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FR_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FR_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FML_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FML_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FML_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FMR_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FMR_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FMR_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RR_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RR_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RR_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RML_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RML_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RML_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RMR_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RMR_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RMR_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FLL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FLL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FLL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_FRL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FRL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_FRL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RLL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RLL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
	//CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RLL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : Appl_AVMDVR_Send_RRL_EchoHeight
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RRL_EchoHeight(U8 echoheight)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Dis_RRL_Echo_Height, (U8*)&echoheight, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FL_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FL_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FL_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FL_WarnZone_2(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FL_WarnZone_2(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FL_WarnZone_8U_2, (U8*)&zone, 1);
	return ret;
}
/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FML_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FML_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FML_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FMR_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FMR_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FMR_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FR_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FR_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FR_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_FR_WarnZone_2(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_FR_WarnZone_2(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_FR_WarnZone_8U_2, (U8*)&zone, 1);
	return ret;
}
/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_Fmid_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_Fmid_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_Fmid_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RL_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RL_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RL_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RL_WarnZone_2(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RL_WarnZone_2(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RL_WarnZone_8U_2, (U8*)&zone, 1);
	return ret;
}
/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RML_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RML_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RML_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RMR_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RMR_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RMR_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RR_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RR_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RR_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_RR_WarnZone_2(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_RR_WarnZone_2(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_RR_WarnZone_8U_2, (U8*)&zone, 1);
	return ret;
}
/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_Rmid_WarnZone(U8 zone)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_Rmid_WarnZone(U8 zone)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_USS_Rmid_WarnZone_8U, (U8*)&zone, 1);
	return ret;
}
/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_WarnControl(U8 Warning_Switch)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/

U8 Appl_AVMDVR_Send_WarnControl(U8 Warning_Switch)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_Switch, (U8*)&Warning_Switch, 1);	
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_WarnFz(U8 Warning_FZ)
* DESCRIPTION : Drive Buzzer with different frequence,according to Warning Level
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_WarnFz(U8 Warning_FZ)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_FZ, (U8*)&Warning_FZ, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    :U8 Appl_AVMDVR_Send_SoftVersionByte0(U8 data)
* DESCRIPTION : send software version byte0
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte0(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte0, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte1(U8 data)
* DESCRIPTION : send software version byte1
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte1(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte1, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte2(U8 data)
* DESCRIPTION : send software version byte2
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte2(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte2, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte3(U8 data)
* DESCRIPTION : send software version byte3
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte3(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte3, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte4(U8 data)
* DESCRIPTION : send software version byte4
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte4(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte4, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte5(U8 data)
* DESCRIPTION : send software version byte5
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte5(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte5, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte6(U8 data)
* DESCRIPTION : send software version byte6
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte6(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte6, (U8*)&data, 1);
	return ret;
}

/***********************************************************************
* FUNCTION    : U8 Appl_AVMDVR_Send_SoftVersionByte7(U8 data)
* DESCRIPTION : send software version byte7
* INPUTS      : none
* RETURN      : none
***********************************************************************/
U8 Appl_AVMDVR_Send_SoftVersionByte7(U8 data)
{
	U8 ret = 0;
//	CanSig_CANSendValue(TX_SIG_SET_ID_SoftVersionByte7, (U8*)&data, 1);
	return ret;
}


/***********************************************************************
* FUNCTION    : WarningBoardTest
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void WarningBoardTest(void)
{
	static U16 WarningBoardCount;
	static U8 Warning_Switch;
	static U8 Warning_FZ;

	WarningBoardCount++;
	switch(WarningBoardCount)
	{
		case 20:
			//open warning board
			Warning_Switch = 0x01;			
			//Freq =1 Hz
			Warning_FZ = 0x00;
			// Recv message from Warning board
			break;
		case 40:
			//open warning board
			Warning_Switch = 0x01;			
			//Freq =2 Hz
			Warning_FZ = 0x00;
			break;
		case 60:
			//open warning board
			Warning_Switch = 0x01;			
			//Freq =3 Hz
			Warning_FZ = 0x02;
			break;
		case 80:
			//open warning board
			Warning_Switch = 0x01;			
			//Freq =4 Hz
			Warning_FZ = 0x03;
			break;
		case 100:
			//close warning board
			WarningBoardCount=0;
			Warning_Switch = 0x00;
			break;
		default:
			break;
		
	}
	//CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_Switch, (U8*)&Warning_Switch, 1);	
	//CanSig_CANSendValue(TX_SIG_SET_ID_Warningboard_FZ, (U8*)&Warning_FZ, 1);
}

