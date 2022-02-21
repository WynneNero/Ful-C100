/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Shao Guangxian										   *
************************************************************************
* Object        : Complex driver.h
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:  0.1
* Date: 2011-11-24
* Author: Shao Guangxian
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*
*=====================================================================*/
#ifndef _COMPLEXDRIVER_GLOBALDEF_IF_H
#define _COMPLEXDRIVER_GLOBALDEF_IF_H

#include "CONFIG.H"
#include "GPIO_IF.H"

/************GPIO DEFINE ****************/

//#define CHECK_POWER_CAMERA_EABLE_FLAG     GPIO_GetVal(GPIO_PORT_11,GPIO_PIN_0)      
#define CHECK_LM53601_RESET_PIN_FLAG() 	  GPIO_GetVal(AP_PORT_0, GPIO_PIN_7)
#define Soc_Menual_Udata()				  GPIO_SetInputMode(GPIO_PORT_8,GPIO_PIN_6,0)//for test trun SOC UDDATA
#define SOC_CAMERA_PWM_STATUS() 	    GPIO_GetVal(GPIO_PORT_1,GPIO_PIN_B)		//uP2NAV_RVC Request soc control cammer status

#define POWER_CAMERA_ALL_ON() 	     GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_0, TRUE)
#define POWER_CAMERA_ALL_OFF() 	     GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_0, FALSE)

#define POWER_CAMERA_F_ON() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_5, TRUE)
#define POWER_CAMERA_F_OFF() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_5, FALSE)

#define POWER_CAMERA_B_ON() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_F, TRUE)
#define POWER_CAMERA_B_OFF() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_F, FALSE)

#define POWER_CAMERA_R_ON() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_4, TRUE)
#define POWER_CAMERA_R_OFF() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_4, FALSE)

#define POWER_CAMERA_L_ON() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_3, TRUE)
#define POWER_CAMERA_L_OFF() 	     GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_3, FALSE)

//#define POWER_CAMERA_DVR_ON() 	     GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_0, TRUE)
//#define POWER_CAMERA_DVR_OFF() 	     GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_0, FALSE)

#define POWER_BUZZER_ON() 	         GPIO_SetVal(GPIO_PORT_0, GPIO_PIN_5, TRUE)
#define POWER_BUZZER_OFF() 	         GPIO_SetVal(GPIO_PORT_0, GPIO_PIN_5, FALSE)

#define POWER_5V0_ON() 	             GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_A, TRUE)
#define POWER_5V0_OFF() 	         GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_A, FALSE)

#define ACC_POWER_STATUS 	             	GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_4)

//#define MAX9286_PWDN_INACTIVE()        GPIO_SetVal(GPIO_PORT_0, GPIO_PIN_A, TRUE)
//#define MAX9286_PWDN_ACTIVE()          GPIO_SetVal(GPIO_PORT_0, GPIO_PIN_A, FALSE)

#define POWER_ISP_LVDS_1V8_ON() 	 GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_1, TRUE)
#define POWER_ISP_LVDS_1V8_OFF() 	 GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_1, FALSE)

#define POWER_ISP_LVDS_3V3_ON() 	 GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_0, TRUE)
#define POWER_ISP_LVDS_3V3_OFF() 	 GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_0, FALSE)

#define POWER_FPD_LINK_1V1_ON() 	 GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_4, TRUE)
#define POWER_FPD_LINK_1V1_OFF() 	 GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_4, FALSE)

#define POWER_FPD_LINK_1V8_ON() 	 GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_3, TRUE)
#define POWER_FPD_LINK_1V8_OFF() 	 GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_3, FALSE)

#define Get_POWER_PMIC_STATUS()	     GPIO_GetVal(GPIO_PORT_10, GPIO_PIN_2)
#define POWER_PMIC_ON()	             GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_2, TRUE)
#define POWER_PMIC_OFF()	         GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_2, FALSE)

#define POWER_SOC_LOW_STATUS()		 GPIO_GetVal(GPIO_PORT_1,GPIO_PIN_9)	
#define POWER_SOC_LOW_ON()	         GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_9, TRUE)  //higth is on
#define POWER_SOC_LOW_OFF()	         GPIO_SetVal(GPIO_PORT_1, GPIO_PIN_9, FALSE)
 
#define UPDATE_OS_START()	         GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_6, TRUE)
#define UPDATE_OS_STOP()	         GPIO_SetVal(GPIO_PORT_8, GPIO_PIN_6, FALSE)

#define Get_SLC_STATUS  			GPIO_GetVal(GPIO_PORT_1,GPIO_PIN_3)
#define SOC2up_SLC_EN()  			GPIO_SetVal(GPIO_PORT_1,GPIO_PIN_3,TRUE)
#define SOC2up_SLC_STOP()  			GPIO_SetVal(GPIO_PORT_1,GPIO_PIN_3,FALSE)

#define F_RADAR_EN_ON() 			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_8, TRUE)   
#define F_RADAR_EN_OFF() 			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_8, FALSE)

#define R_RADAR_EN_ON()				GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_9, TRUE)
#define R_RADAR_EN_OFF()			GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_9, FALSE)

//#define POWER_SVA_Warn_LED_ON()  			GPIO_SetVal(GPIO_PORT_11,GPIO_PIN_D, TRUE)
//#define POWER_SVA_Warn_LED_OFF()  			GPIO_SetVal(GPIO_PORT_11,GPIO_PIN_D, FALSE)

#define GET_CAN0_CANINH_STS()    GPIO_GetVal(GPIO_PORT_10, GPIO_PIN_9) 
#define GET_CAN0_CANERR_STS()    GPIO_GetVal(GPIO_PORT_11, GPIO_PIN_3)

/*********************************CAN0 driver  Chassic CAN  PriteCan********************************************/
#define CAN0_SET_WAKE()  {GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_F, 0, 0);GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_F, TRUE);}
#define CAN0_CLR_WAKE() 	{GPIO_SetOutputMode(GPIO_PORT_11, GPIO_PIN_F, 0, 0 );GPIO_SetVal(GPIO_PORT_11, GPIO_PIN_F, FALSE);}

#define CAN0_SET_STB()	GPIO_SetVal(GPIO_PORT_12, GPIO_PIN_0, TRUE)
#define CAN0_CLR_STB()	GPIO_SetVal(GPIO_PORT_12, GPIO_PIN_0, FALSE)

#define CAN0_SET_EN()	GPIO_SetVal(GPIO_PORT_12, GPIO_PIN_1, TRUE)
#define CAN0_CLR_EN()	GPIO_SetVal(GPIO_PORT_12, GPIO_PIN_1, FALSE)

#define CAN0_GET_ERR()    GPIO_GetVal(GPIO_PORT_12,GPIO_PIN_2)

#define CAN0_GET_INH()    GPIO_GetVal(GPIO_PORT_11,GPIO_PIN_7)

/*********************************CAN1 driver  Information CAN  PublicCan********************************************/
#define CAN1_SET_WAKE() 	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_A, TRUE)
#define CAN1_CLR_WAKE() 	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_A, FALSE)

#define CAN1_SET_STB()	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_B, TRUE)
#define CAN1_CLR_STB()	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_B, FALSE)

#define CAN1_SET_EN()	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_C, TRUE)
#define CAN1_CLR_EN()	GPIO_SetVal(GPIO_PORT_10, GPIO_PIN_C, FALSE)

#define CAN1_GET_ERR()    GPIO_GetVal(GPIO_PORT_11,GPIO_PIN_3)

#define CAN1_GET_INH()    GPIO_GetVal(GPIO_PORT_10,GPIO_PIN_9)
#define UART4_RX_ALT()  GPIO_SetAlterMode(GPIO_PORT_1,GPIO_PIN_9,E_ALTERFUNC_1,GPIO_OPT_OUT_STRTH40M)
#define UART4_TX_ALT()  GPIO_SetAlterMode(GPIO_PORT_1,GPIO_PIN_8,E_ALTERFUNC_1,GPIO_OPT_INPUT)



#endif /*_COMPLEXDRIVER_GLOBALDEF_H*/
