/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									           *
*   AUTHOR	   : 									                   *
************************************************************************
* Object        :PowerManager.c
* Module        :PowerManager
* Instance      :
* Description   :Control the power
*-----------------------------------------------------------------------
* Version: 	0.6
* Date:		2017/8/18
* Author:	Zheng Xiaolei
***********************************************************************/
/*-History--------------------------------------------------------------
* Version	Date		 Name 			 Changes and comments
* 0.1		2017/6/29    Zheng Xiaolei	 Init version
* 0.2       2017/7/4     Zheng Xiaolei   Bug fix for state changed to emergency power
* 0.3       2017/7/29    Zheng Xiaolei   Change the TFT on&off control mode from EN to PWM.
* 0.4       2017/7/30    Zheng Xiaolei   Add RTC Config after power on.
* 0.5       2017/8/17    Zheng Xiaolei   Change the location of variable init when power up.
* 0.6       2017/8/18    Zheng Xiaolei   Add SOC watchdog handler.
*=====================================================================*/

#include "ComplexDrvier_Globaldef_IF.H"
#include "Sig_Combine.H"
#include "Signal_IF.H"
#include "PowerManager.h"
#include "PowerManager_IF.H"

#include "SocDriver.h"



BOOL bAccOnStatus;
U8 NaviPowerStatus;
BOOL bsysPowerOk = FALSE;
BOOL bsysCanPowerOk = FALSE; 
U8 uAccOnCnt = 0;
U8 uAccOffCnt = 0;
U8 VolDetCnt = 0;

BOOL WORK_BELOW_VOLTAGE_FLAG = FALSE;
BOOL WORK_OVER_VOLTAGE_FLAG = FALSE;

/***********************************************************************
*  Name        : PowerManager_Init_S0
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void PowerManager_Init_S0(void)
{
}

/***********************************************************************
*  Name        : PowerManager_Init_S3
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void PowerManager_Init_S3(void)
{
	GPIO_SetInputMode(GPIO_PORT_8, GPIO_PIN_4, E_NO_MODE); // acc 
	//GPIO_SetInputMode(GPIO_PORT_10, GPIO_PIN_5,  E_NO_MODE, TRUE);
	//PowerManager_PowerSwitchOn();
}

/***********************************************************************
*  Name        : PowerManager_DeInit
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
void PowerManager_DeInit(void)
{
}

/***********************************************************************
*  Name        : PowerManager_5msEntry
*  Description : 
*  Parameter   :
*  Returns     : 
***********************************************************************/
U8 LLF_MARK = 0;
E_SYSTEM_VOLTAGE_STATUS stk_radar_pwr_det = 0;


void PowerManager_5msEntry(void)
{

	E_SYSTEM_VOLTAGE_STATUS vol_status = GetPowerVoltageStatus();
	 stk_radar_pwr_det = GetPowerVoltageStatus();
	//update direct voltage  status
   	CS_SIG_SyncSend(SIG_VOLTAGEFAIL_STATUS, (U8*) &vol_status);
	//delay_100us();
	//CS_SIG_SyncReceive(SIG_VOLTAGEFAIL_STATUS, &LLF_MARK);  
	UpdateACCStatus();
}

/*******Define Voltage****AD Value****actual voltage******/
#define V_6_5_VALUE              1166        //6.6V   1138-1148           6.54  1169
#define V_6_4_VALUE              1148        //6.4V   1138-1148           6.54  1169
#define V_7_VALUE                1259        //7.0V	  1233-1243           7.01  1257
#define V_8_5_VALUE              1438
#define V_9_VALUE                1633        //8.9V-soc work status//consider camera load should be higher than 8.4    9.19  1667
#define V_9_5_VALUE              1720        //9.5V-soc not work //1546   9.51  1654
#define V_16_VALUE               2939        //16.0V soc not work status  16.0   2891
#define V_16_5_VALUE             3020        //16.4V soc work status      16.49  3032
#define V_18_VALUE               3330        //18.0V  3307-3308           17.98  3310
#define V_18_5_VALUE             3406        //18.5V  3401                18.49  3406
#define V_18_1_VALUE             3346        //18.1V  3318                18.49  3406
#define PW_Vol_CNT               59

#define AD_12BIT_MAX_VALUE 4096
#define AD_12BIT_MIN_VALUE 0

U8 pwVoltageStatus_backup;
U8 pwVoltageStatus_pre;
U8 pwVoltageStatus_Cnt;

#ifdef POWER_AD_DETECT_CALIBRATION
U16 ad_detect_calibration_val;
#endif //POWER_AD_DETECT_CALIBRATION
E_SYSTEM_VOLTAGE_STATUS pwVoltageStatus = V_INIT;
E_SYSTEM_VOLTAGE_STATUS GetPowerVoltageStatus(void)
{

    U16 pwrValue = 0;
	CS_SIG_AsyncReceive(SIG_APP_PWR,&pwrValue);
	if((pwrValue > AD_12BIT_MAX_VALUE)||(pwrValue==AD_12BIT_MIN_VALUE))
	{
		return V_L_ABNORMAL;
	}

#ifdef POWER_AD_DETECT_CALIBRATION
	ad_detect_calibration_val = pwrValue;
#endif //POWER_AD_DETECT_CALIBRATION

	if(pwrValue<V_7_VALUE)//7V
	{	
		WORK_BELOW_VOLTAGE_FLAG = TRUE;
	}
	if((pwrValue>=V_9_VALUE)&&WORK_BELOW_VOLTAGE_FLAG)//9V
	{
		WORK_BELOW_VOLTAGE_FLAG = FALSE;
	}
	if(pwrValue>V_18_VALUE)//DTC 18v  time 200ms
	{	
		WORK_OVER_VOLTAGE_FLAG = TRUE;
	}
	if((pwrValue<=V_16_VALUE)&&WORK_OVER_VOLTAGE_FLAG)
	{
		WORK_OVER_VOLTAGE_FLAG = FALSE;
	}

	if(V_INIT==pwVoltageStatus)
	{
		if(pwrValue<V_6_4_VALUE)
		{
			pwVoltageStatus = V_L_ABNORMAL;
		}
		else if((pwrValue>=V_6_4_VALUE)&&(pwrValue<V_9_VALUE))
		{
			pwVoltageStatus = V_LOW;
		}
		else if((pwrValue>=V_9_VALUE)&&(pwrValue<=V_16_5_VALUE))
		{
			pwVoltageStatus = V_NORMAL;
		}
		else if((pwrValue>V_16_5_VALUE)&&(pwrValue<=V_18_1_VALUE))
		{
			pwVoltageStatus = V_HIGH;
		}
		else if(pwrValue>V_18_1_VALUE)
		{
			pwVoltageStatus = V_H_ABNORMAL;
		}
	}
	else if(V_L_ABNORMAL==pwVoltageStatus)
	{
		if((pwrValue>=V_6_5_VALUE)&&(pwrValue<V_9_VALUE))
		{
			pwVoltageStatus = V_LOW;
		}
		else if((pwrValue>=V_9_VALUE)&&(pwrValue<=V_16_5_VALUE))
		{
			pwVoltageStatus = V_NORMAL;
		}
		else if((pwrValue>V_16_5_VALUE)&&(pwrValue<=V_18_1_VALUE))
		{
			pwVoltageStatus = V_HIGH;
		}
		else if(pwrValue>V_18_1_VALUE)
		{
			pwVoltageStatus = V_H_ABNORMAL;
		}
	}
	else if(V_H_ABNORMAL==pwVoltageStatus)
	{
		if((pwrValue> V_16_VALUE)&&(pwrValue<=V_18_VALUE))
		{
			pwVoltageStatus = V_HIGH;
		}
		else if((pwrValue>= V_8_5_VALUE)&&(pwrValue<= V_16_VALUE))
		{
			pwVoltageStatus = V_NORMAL;
		}
		else if((pwrValue>=V_6_4_VALUE)&&(pwrValue< V_8_5_VALUE))
		{
			pwVoltageStatus = V_LOW;
		}
		else if(pwrValue<V_6_4_VALUE)
		{
			pwVoltageStatus = V_L_ABNORMAL;
		}
	}
	else if(V_LOW==pwVoltageStatus)
	{
	    if(pwrValue<V_6_4_VALUE)
		{
			pwVoltageStatus = V_L_ABNORMAL;
		}
		else if((pwrValue>=V_9_VALUE)&&(pwrValue<=V_16_5_VALUE))
		{
			pwVoltageStatus = V_NORMAL;
		}
		else if((pwrValue>V_16_5_VALUE)&&(pwrValue<=V_18_1_VALUE))
		{
			pwVoltageStatus = V_HIGH;
		}
		else if(pwrValue>V_18_1_VALUE)
		{
			pwVoltageStatus = V_H_ABNORMAL;
		}
	}
	else if(V_NORMAL==pwVoltageStatus)
	{
		if((pwrValue>=V_6_4_VALUE)&&(pwrValue< V_8_5_VALUE))
		{
			pwVoltageStatus = V_LOW;
		}
		else if(pwrValue<V_6_4_VALUE)
		{
			pwVoltageStatus = V_L_ABNORMAL;
		}
		else if((pwrValue>V_16_5_VALUE)&&(pwrValue<=V_18_1_VALUE))
		{
			pwVoltageStatus = V_HIGH;
		}
		else if(pwrValue>V_18_1_VALUE)
		{
			pwVoltageStatus = V_H_ABNORMAL;
		}
	}
	else if(V_HIGH==pwVoltageStatus)
	{
		if((pwrValue>= V_8_5_VALUE)&&(pwrValue<= V_16_VALUE))
		{
			pwVoltageStatus = V_NORMAL;
		}
		else if((pwrValue>=V_6_4_VALUE)&&(pwrValue< V_8_5_VALUE))
		{
			pwVoltageStatus = V_LOW;
		}
		else if(pwrValue<V_6_4_VALUE)
		{
			pwVoltageStatus = V_L_ABNORMAL;
		}
		else if(pwrValue>V_18_1_VALUE)
		{
			pwVoltageStatus = V_H_ABNORMAL;
		}
	}

	return pwVoltageStatus;

/*
#ifdef POWER_AD_DETECT_CALIBRATION   
	pwVoltageStatus=V_NORMAL;
#endif //POWER_AD_DETECT_CALIBRATION


	if(pwVoltageStatus_backup == pwVoltageStatus)  
	{
		pwVoltageStatus_Cnt++;
		if(pwVoltageStatus_Cnt > PW_Vol_CNT)
		{
			pwVoltageStatus_Cnt = PW_Vol_CNT+1;
			pwVoltageStatus_pre = pwVoltageStatus;
			return  pwVoltageStatus;
		}
	}
	else
	{
		pwVoltageStatus_Cnt = 0;
		pwVoltageStatus_backup = pwVoltageStatus;
		return  pwVoltageStatus_pre;
	}
*/	

}


U8 hw_acc_value=0;
BOOL hw_accon_flag=FALSE;
BOOL accon_flag=FALSE;
BOOL accon_flag_backup=FALSE;
void UpdateACCStatus(void)
{
	BOOL acc_status_from_can=0;
	BOOL hw_acc_status=0;
	hw_acc_status = get_hw_ACC_status();
	acc_status_from_can = get_can_ACC_status();
	//if(hw_acc_status ||acc_status_from_can)
	if(hw_acc_status)
	{
		accon_flag = TRUE;
	}
	else
	{
		accon_flag = FALSE;
	}
	if(accon_flag_backup!=accon_flag)
	{
		accon_flag_backup = accon_flag;
	}
	CS_SIG_SyncSend(SIG_ACCSTATUS, &accon_flag);
}


U8 get_hw_ACC_status(void)
{
	//GPIO_SetInputMode( GPIO_PORT_8, GPIO_PIN_4,GPIO_OPT_INIT);
	hw_acc_value = ACC_POWER_STATUS;//GPIO_GetVal(GPIO_PORT_8, GPIO_PIN_4); //Detect ACC whether on  CS_SIG_SyncReceive(SIG_ACC_DI_STATUS,&hw_acc_value); 
	if((hw_acc_value&0x01) == 1) //acc on
	{
		uAccOnCnt++;
		uAccOffCnt = 0;
		if(uAccOnCnt>=ACC_MASK_ON_TIMES_DEBOUNCE)
		{
		    uAccOnCnt = ACC_MASK_ON_TIMES_DEBOUNCE;
		    hw_accon_flag = 1;
		}
	}
	else //acc off
	{
		uAccOnCnt=0;
		uAccOffCnt ++;
		if(uAccOffCnt>=ACC_MASK_OFF_TIMES_DEBOUNCE)
		{
		    uAccOffCnt = ACC_MASK_OFF_TIMES_DEBOUNCE;
		    hw_accon_flag = 0;   
		}
	}
	return hw_accon_flag;
}


U8 get_can_ACC_status(void)
{
	U8 accstatusfromcantemp = 0;
	CS_SIG_SyncReceive(SIG_ACC_CAN_IN_STATUS,&accstatusfromcantemp);
	return accstatusfromcantemp;
}

/******** TAUB0I11_timer_callback ************
*  Name        : TAUB0I11_timer_callback
*  Description :
*  Parameter   : None
*  Returns     : None
*****************************************************************************/
void TAUB0I11_timer_callback(U64 data)
{
//	SocWdgCapData = data;
}


/*****************************************************************
get voltage value: 
*FUNCTION : Get_System_Voltage_Val 
*DESCRIPTION : for a debug interface to STK
*PARAM : void
*RETURN : unsigned char
*******************************************************************/
E_SYSTEM_VOLTAGE_STATUS Get_System_Voltage_Val(void)
{
	return stk_radar_pwr_det;
}

