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
/*** System include files **************************************************/
#include "iodefine.h"
#include "Os_Cpu.h"
#include "TimerUnit.h"
#include "TimerUnit_if.h"
#include "TimerUnit_cfg.h"
#include "GPIO_if.h"
#include "IRQ_if.h"

/*---Public include files--------------------------------------------------*/
#include "ULtraRadarDriver.h"
#include "SRU_hwa_InterfacesAccess.h"
#include "eol_app.h"
#include "ObjDetectCommonDefine.h"




/*===VARIABLES==========================================*/

/*---Global-----------------------------------------------------------*/
unsigned int iTauj1msCount = 0;
unsigned long TAUJ0I0_getcounter = 0;
unsigned long Intp_Init_Time_Point = 0;

/*---Private-----------------------------------------------------------*/

/*===FUNCTIONS==========================================*/

/*---Global-----------------------------------------------------------*/
extern void Port_Intp_Init(void);
extern unsigned long HWA_Get_Systime(void);
extern void ElmosCtl_SensorInputInterrupt(unsigned char index);
extern void ElmosCtl_TimerInterrupt(void);

/***********************************************************************
*  Name        	: SnsIntp_EnableInt
*  Description 	: enable capture interupt
*  Parameter  	: probe index
*  Returns     	: none
***********************************************************************/
void SnsIntp_EnableInt(unsigned char index)
{
	switch(index)
	{
		case RRS_SNS_INDEX:
			INTC2MKTAUB0I15 = 0;
		break;
		case RR_SNS_INDEX:
			INTC2MKTAUB0I8 = 0;
		break;

		case RRM_SNS_INDEX:
			INTC2MKTAUB0I10 = 0;
		break;

		case RLM_SNS_INDEX:
			INTC2MKTAUB0I12 = 0;
		break;

		case RL_SNS_INDEX:
			INTC2MKTAUB0I14 = 0;
		break;

		case RLS_SNS_INDEX:
			INTC2MKTAUB0I13 = 0;
		break;

		case FRS_SNS_INDEX:
			INTC2MKTAUB0I7 = 0;
		break;

		case FR_SNS_INDEX:
			INTC2MKTAUB0I6 = 0;
		break;

		case FRM_SNS_INDEX:
			INTC2MKTAUB0I4 = 0;
		break;

		case FLM_SNS_INDEX:
			INTC2MKTAUB0I2 = 0;
		break;

		case FL_SNS_INDEX:
			INTC2MKTAUB0I0 = 0;
		break;

		case FLS_SNS_INDEX:
			INTC2MKTAUB0I5 = 0;
		break;

		default:
		break;
	}
}

/***********************************************************************
*  Name        	: HWA_DisableElmosRxPinInt
*  Description 	: disable capture interupt
*  Parameter  	: probe index
*  Returns     	: none
***********************************************************************/
void HWA_DisableElmosRxPinInt(unsigned char index)
{
	switch(index)
	{
		case RRS_SNS_INDEX:
			INTC2MKTAUB0I15 = 1;
		break;

		case RR_SNS_INDEX:
			INTC2MKTAUB0I8 = 1;
		break;

		case RRM_SNS_INDEX:
			INTC2MKTAUB0I10 = 1;
		break;

		case RLM_SNS_INDEX:
			INTC2MKTAUB0I12 = 1;
		break;

		case RL_SNS_INDEX:
			INTC2MKTAUB0I14 = 1;
		break;

		case RLS_SNS_INDEX:
			INTC2MKTAUB0I13 = 1;
		break;

		case FRS_SNS_INDEX:
			INTC2MKTAUB0I7 = 1;
		break;

		case FR_SNS_INDEX:
			INTC2MKTAUB0I6 = 1;
		break;

		case FRM_SNS_INDEX:
			INTC2MKTAUB0I4 = 1;
		break;

		case FLM_SNS_INDEX:
			INTC2MKTAUB0I2 = 1;
		break;

		case FL_SNS_INDEX:
			INTC2MKTAUB0I0 = 1;
		break;

		case FLS_SNS_INDEX:
			INTC2MKTAUB0I5 = 1;
		break;

		default:
		break;
	}
}

/***********************************************************************
*  Name        	: SnsIntp_DisableAllInt
*  Description 	: disable all capture interupts
*  Parameter  	: none
*  Returns     	: none
***********************************************************************/
void SnsIntp_DisableAllInt(void)
{
	INTC2MKTAUB0I15 = 1; 	/*	RRS_SNS_INDEX	*/
	INTC2MKTAUB0I8 = 1;		/*	RR_SNS_INDEX	*/
	INTC2MKTAUB0I10 = 1;		/*	RRM_SNS_INDEX	*/
	INTC2MKTAUB0I12 = 1;		/*	RLM_SNS_INDEX	*/
	INTC2MKTAUB0I14 = 1;		/*	RL_SNS_INDEX	*/
	INTC2MKTAUB0I13 = 1;		/*	RLS_SNS_INDEX	*/
	INTC2MKTAUB0I7 = 1;		/*	FRS_SNS_INDEX	*/
	INTC2MKTAUB0I6 = 1;		/*	FR_SNS_INDEX	*/
	INTC2MKTAUB0I4 = 1;		/*	FRM_SNS_INDEX	*/
	INTC2MKTAUB0I2 = 1;		/*	FLM_SNS_INDEX	*/
	INTC2MKTAUB0I0 = 1;		/*	FL_SNS_INDEX	*/
	INTC2MKTAUB0I5 = 1;		/*	FLS_SNS_INDEX	*/
}

/***********************************************************************
*  Name        	: Intp_init
*  Description 	: disable all capture interupts and get system time
*  Parameter  	: none
*  Returns     	: none
***********************************************************************/
void Intp_init(void)
{
	/*RRS_SNS_INDEX*/
	INTC2MKTAUB0I15 = 1;
	INTC2RFTAUB0I15 = 0;

	/*RR_SNS_INDEX*/
	INTC2MKTAUB0I8 = 1;
	INTC2RFTAUB0I8 = 0;
	
	/*RRM_SNS_INDEX*/
	INTC2MKTAUB0I10 = 1;
	INTC2RFTAUB0I10 = 0;

	/*RLM_SNS_INDEX*/
	INTC2MKTAUB0I12 = 1;
	INTC2RFTAUB0I12 = 0;

	/*RL_SNS_INDEX*/
	INTC2MKTAUB0I14 = 1;
	INTC2RFTAUB0I14 = 0;

	/*RLS_SNS_INDEX*/
	INTC2MKTAUB0I13 = 1;
	INTC2RFTAUB0I13 = 0;

	/*FRS_SNS_INDEX	*/
	INTC2MKTAUB0I7 = 1;	
	INTC2RFTAUB0I7 = 0;

	/*FR_SNS_INDEX*/
	INTC2MKTAUB0I6 = 1;	
	INTC2RFTAUB0I6 = 0;

	/*FRM_SNS_INDEX*/
	INTC2MKTAUB0I4 = 1;	
	INTC2RFTAUB0I4 = 0;

	/*FLM_SNS_INDEX*/
	INTC2MKTAUB0I2 = 1;	
	INTC2RFTAUB0I2 = 0;

	/*FL_SNS_INDEX*/
	INTC2MKTAUB0I0 = 1;	
	INTC2RFTAUB0I0 = 0;

	/*FLS_SNS_INDEX*/
	INTC2MKTAUB0I5 = 1;	
	INTC2RFTAUB0I5 = 0;

	Intp_Init_Time_Point = HWA_Get_Systime();
}

/***********************************************************************
*  Name        : ISR_TAUB0I0func
*  Description : TAUB0I0 interruput isr 
*  Parameter   :
*  Returns     : None
***********************************************************************/
extern U8 IsrEnteryFlag;
void ISR_TAUB0I0func(void)
{ 
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFL)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I2func
*  Description : TAUB0I2 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I2func(void)   /*capture, P0_8*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFLM)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I4func
*  Description : TAUB0I4 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I4func(void)   /*capture, P0_9*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFRM)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I5func
*  Description : TAUB0I5 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I5func(void)   /*capture, P10_13*/
{

	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFLS)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I6func
*  Description : TAUB0I6 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I6func(void)   /*capture, P0_10*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFR)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I7func
*  Description : TAUB0I7 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I7func(void)   /*capture, P10_14*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagFRS)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I8func
*  Description : TAUB0I8 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I8func(void)   /*capture, P0_11*/
{

	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRR)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}
/***********************************************************************
*  Name		 : ISR_TAUB0I10func
*  Description : TAUB0I10 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I10func(void)	   /*capture, P0_12*/
{

	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRRM)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I12func
*  Description : TAUB0I12 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I12func(void)	   /*capture, P0_13*/
{

	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRLM)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}
/***********************************************************************
*  Name		 : ISR_TAUB0I13func
*  Description : TAUB0I13 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I13func(void)	   /*capture, P11_1*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRLS)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I14func
*  Description : TAUB0I14 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I14func(void)	   /*capture, P0_14*/
{
	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRL)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		 : ISR_TAUB0I15func
*  Description : TAUB0I15 interruput isr 
*  Parameter	 :
*  Returns	 : None
***********************************************************************/
void ISR_TAUB0I15func(void)	   /*capture, P11_2*/
{

	if(radarEolStartFlag.bRadarEolStartFlag.radarEolStartFlagRRS)
	{
		IsrEnteryFlag = TRUE;
	}
	else
	{
		//do nothing
	}
}

/***********************************************************************
*  Name		   : TAUJ0I0_Timer_GetCount
*  Description : to get TAUJ0I0 timer count number
*  Parameter   :
*  Returns	   : timer count number
***********************************************************************/
unsigned long TAUJ0I0_Timer_GetCount(void)
{ 	 
	return TAUJ0CNT0;
}

/***********************************************************************
*  Name		: TAUD0I1_Timer_callback
*  Description 	: TAUD0I1 1ms timer interrupt function
*  Parameter  	: none
*  Returns	: none
***********************************************************************/
void TAUD0I1_Timer_callback(void)
{
	iTauj1msCount++;
}

/***********************************************************************
*  Name		: ISR_TAUJ0I1func
*  Description 	: TAUB0I1 interruput isr 
*  Parameter	: none
*  Returns	: none
***********************************************************************/
void ISR_TAUJ0I1func(void) 
{
    unsigned char stay = 1;
    while(stay);

	ElmosCtl_TimerInterrupt();
}


/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUJ0_Channel0_start(void)
{
	TAU_REG_TAUJnCMOR(TAUJ0_REG_BASEADD, TAU_CH0) = (U16)(TAUB_CLOCK_SELECT_CK(tauChanlCfg[TAUJ0_U3][TAU_CH0])|(E_MODE_INTERVAL_TIMER|E_MD0_NOINT));
	TAU_REG_TAUJnCMUR(TAUJ0_REG_BASEADD, TAU_CH0) = (U8)E_TAUB_TIS_EDGE_FALLING;
	TAU_REG_TAUJnCDR(TAUJ0_REG_BASEADD, TAU_CH0) = 0xFFFFFFFF;
	TAU_REG_TAUJnTOE(TAUJ0_REG_BASEADD) |=(U8)(1u<<TAU_CH0);
	TAU_REG_TAUJnTOM(TAUJ0_REG_BASEADD) &=(U8)(~(1u<<TAU_CH0));
	TAU_REG_TAUJnTOC(TAUJ0_REG_BASEADD) &=(U8)(~(1u<<TAU_CH0));
	TAU_REG_TAUJnTOL(TAUJ0_REG_BASEADD) &=(U8)(~(1u<<TAU_CH0));
	TAU_REG_TAUJnTS(TAUJ0_REG_BASEADD) |=(U8)(1u<<TAU_CH0);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUD0_Channel1_start(void)
{
	TAU_Timer_Config_US(TAUD0_U2, TAU_CH1, 1000, FALSE, TRUE);
	TAU_Timer_Cmd(TAUD0_U2, TAU_CH1, ENABLE);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUJ0_Channel1_start(unsigned short tauj0_channel1_duty)
{
	unsigned long long temp = 5 * tauj0_channel1_duty;
	temp = temp/4;
	TAUJ0CDR1 = temp;
	TAUJ0TS  |=(U8)(1u<<TAU_CH1);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUD_SysTime_start(void)
{
	TAUJ0_Channel0_start();
	TAUD0_Channel1_start();

	TAUJ0CMOR1 = (U16)(TAUB_CLOCK_SELECT_CK(tauChanlCfg[TAUJ0_U3][TAU_CH1])|(E_MODE_INTERVAL_TIMER|E_MD0_NOINT));
	
	TAUJ0CMUR1 = (U8)E_TAUB_TIS_EDGE_FALLING;

	TAUJ0TOE |=(U8)(1u<<TAU_CH1);

	TAUJ0TOM &=(U8)(~(1u<<TAU_CH1));

	TAUJ0TOC &=(U8)(~(1u<<TAU_CH1));

	TAUJ0TOL &=(U8)(~(1u<<TAU_CH1));

	TAUJ0RDE &=(U8)(~(1u<<TAU_CH1));

	INTC2MKTAUJ0I1 = 0;

	TAU_Capture_Config(TAUB0_U0, TAU_CH5, E_CAP_ALL_EDGE_DETECT);/*FLS*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH5));
	TAU_Capture_Config(TAUB0_U0, TAU_CH2, E_CAP_ALL_EDGE_DETECT);/*FLM*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH2));
	TAU_Capture_Config(TAUB0_U0, TAU_CH4, E_CAP_ALL_EDGE_DETECT);/*FRM*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH4));
	TAU_Capture_Config(TAUB0_U0, TAU_CH7, E_CAP_ALL_EDGE_DETECT);/*FRS*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH7));
	TAU_Capture_Config(TAUB0_U0, TAU_CH15, E_CAP_ALL_EDGE_DETECT);/*RRS*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH15));
	TAU_Capture_Config(TAUB0_U0, TAU_CH10, E_CAP_ALL_EDGE_DETECT);/*RRM*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH10));
	TAU_Capture_Config(TAUB0_U0, TAU_CH12, E_CAP_ALL_EDGE_DETECT);/*RLM*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH12));
	TAU_Capture_Config(TAUB0_U0, TAU_CH13, E_CAP_ALL_EDGE_DETECT);/*RLS*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH13));
	TAU_Capture_Config(TAUB0_U0, TAU_CH0, E_CAP_ALL_EDGE_DETECT);/*FL*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH0));
	TAU_Capture_Config(TAUB0_U0, TAU_CH6, E_CAP_ALL_EDGE_DETECT);/*FR*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH6));
	TAU_Capture_Config(TAUB0_U0, TAU_CH14, E_CAP_ALL_EDGE_DETECT);/*RL*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH14));
	TAU_Capture_Config(TAUB0_U0, TAU_CH8, E_CAP_ALL_EDGE_DETECT);/*RR*/
	TAU_REG_TAUBnTS(TAUB0_REG_BASEADD) |=((U16)(1<<TAU_CH8));
}

/***********************************************************************
** Function:    TAU_LPS_stop
** Description: Stops the TAU output for the LPS scan trigger
** Parameter:   None
** Return:      None
***********************************************************************/
void TAUJ0_Channel0_stop(void)
{
	TAU_REG_TAUJnTT(TAUJ0_REG_BASEADD) |=(U8)(1u<<TAU_CH0);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUD0_Channel1_stop(void)
{
	TAU_Timer_Cmd(TAUD0_U2, TAU_CH1, DISABLE);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUJ0_Channel1_stop(void)
{
	TAUJ0TT  |=(U8)(1u<<TAU_CH1);
}

/***********************************************************************
** Function	: TAU_LPS_start
** Description	: Starts the TAU output for the LPS scan trigger
** Parameter	: None
** Return	: None
***********************************************************************/
void TAUD_SysTime_stop(void)
{
	TAUJ0_Channel0_stop();
	TAUD0_Channel1_stop();
}

/***********************************************************************
** Function:    HWA_Get_Systime
** Description: Get task time stamp
** Parameter:   None
** Return:      unit us , resolution 0.001(0.0008)
************************************************************************/
unsigned long HWA_Get_Systime(void)
{
    unsigned long long TAUJ0_getcounter;
    TAUJ0_getcounter=( 0XFFFFFFFF-TAUJ0I0_Timer_GetCount()+1)*4;
    return (unsigned long)TAUJ0_getcounter/5;
}

/***********************************************************************
** Function:    HWA_TimeDelay
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_TimeDelay(unsigned short wTime )/*UNIT: us*/
{
	unsigned int iLoop = 0;
	//Delay 1 us
    	iLoop = 20*wTime;
    	while(iLoop){iLoop--;}
	return;
}

/***********************************************************************
** Function:    HWA_Get_Intp_Init_Time_Point
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
unsigned long HWA_Get_Intp_Init_Time_Point(void)
{
	return Intp_Init_Time_Point;
}

/***********************************************************************
** Function:    HWA_SetRrSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrSensorHigh(void)
{
	PORTP8 &= ~(0x1<<GPIO_PIN_2);
}

/***********************************************************************
** Function:    HWA_SetRrSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrSensorLow(void)
{
	PORTP8 |= 0x1<<GPIO_PIN_2;
}

/***********************************************************************
** Function:    HWA_SetRlSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlSensorHigh(void)
{
	PORTP8 &= ~(0x1<<GPIO_PIN_C);
}

/***********************************************************************
** Function:    HWA_SetRlSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlSensorLow(void)
{
	PORTP8 |= 0x1<<GPIO_PIN_C;
}

/***********************************************************************
** Function:    HWA_SetRrmSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrmSensorHigh(void)
{
	PORTP8 &= ~(0x1<<GPIO_PIN_A);
}

/***********************************************************************
** Function:    HWA_SetRrmSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrmSensorLow(void)
{
	PORTP8 |= 0x1<<GPIO_PIN_A;
}

/***********************************************************************
** Function:    HWA_SetRlmSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlmSensorHigh(void)
{
	PORTP8 &= ~(0x1<<GPIO_PIN_B);
}

/***********************************************************************
** Function:    HWA_SetRlmSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlmSensorLow(void)
{
	PORTP8 |= 0x1<<GPIO_PIN_B;
}

/***********************************************************************
** Function:    HWA_SetRrsSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrsSensorHigh(void)
{
	PORTP18 &= ~(0x1<<GPIO_PIN_3);
}

/***********************************************************************
** Function:    HWA_SetRrsSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRrsSensorLow(void)
{
	PORTP18 |= 0x1<<GPIO_PIN_3;
}

/***********************************************************************
** Function:    HWA_SetRlsSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlsSensorHigh(void)
{
	PORTP18 &= ~(0x1<<GPIO_PIN_2);
}

/***********************************************************************
** Function:    HWA_SetRlsSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetRlsSensorLow(void)
{
	PORTP18 |= 0x1<<GPIO_PIN_2;
}

/***********************************************************************
** Function:    HWA_SetFrSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrSensorHigh(void)
{
	PORTP1 &= ~(0x1<<GPIO_PIN_7);
}

/***********************************************************************
** Function:    HWA_SetFrSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrSensorLow(void)
{
	PORTP1 |= 0x1<<GPIO_PIN_7;
}

/***********************************************************************
** Function:    HWA_SetFlSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlSensorHigh(void)
{
	PORTP1 &= ~(0x1<<GPIO_PIN_4);
}

/***********************************************************************
** Function:    HWA_SetFlSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlSensorLow(void)
{
	PORTP1 |= 0x1<<GPIO_PIN_4;
}

/***********************************************************************
** Function:    HWA_SetFrmSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrmSensorHigh(void)
{
	PORTP1 &= ~(0x1<<GPIO_PIN_6);
}

/***********************************************************************
** Function:    HWA_SetFrmSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrmSensorLow(void)
{
	PORTP1 |= 0x1<<GPIO_PIN_6;
}

/***********************************************************************
** Function:    HWA_SetFlmSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlmSensorHigh(void)
{
	PORTP1 &= ~(0x1<<GPIO_PIN_5);
}

/***********************************************************************
** Function:    HWA_SetFlmSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlmSensorLow(void)
{
	PORTP1 |= 0x1<<GPIO_PIN_5;
}

/***********************************************************************
** Function:    HWA_SetFrsSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrsSensorHigh(void)
{
	PORTP18 &= ~(0x1<<GPIO_PIN_1);
}

/***********************************************************************
** Function:    HWA_SetFrsSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFrsSensorLow(void)
{
	PORTP18 |= 0x1<<GPIO_PIN_1;
}

/***********************************************************************
** Function:    HWA_SetFlsSensorHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlsSensorHigh(void)
{
	PORTP18 &= ~(0x1<<GPIO_PIN_0);
}

/***********************************************************************
** Function:    HWA_SetFlsSensorLow
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetFlsSensorLow(void)
{
	PORTP18 |= 0x1<<GPIO_PIN_0;
}

/***********************************************************************
** Function:    HWA_GetSensorLineLevel
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
unsigned char HWA_GetSensorLineLevel(unsigned char index)
{
	unsigned char PortVal = FALSE;
	switch(index)
	{
		case RRS_SNS_INDEX:
			PortVal = ((PORTPPR11 & (0x1<<GPIO_PIN_2))>>GPIO_PIN_2);
		break;

		case RR_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_B))>>GPIO_PIN_B);
		break;

		case RRM_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_C))>>GPIO_PIN_C);
		break;

		case RLM_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_D))>>GPIO_PIN_D);
		break;

		case RL_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_E))>>GPIO_PIN_E);
		break;

		case RLS_SNS_INDEX:
			PortVal = ((PORTPPR11 & (0x1<<GPIO_PIN_1))>>GPIO_PIN_1);
		break;

		case FRS_SNS_INDEX:
			PortVal = ((PORTPPR10 & (0x1<<GPIO_PIN_E))>>GPIO_PIN_E);
		break;

		case FR_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_A))>>GPIO_PIN_A);
		break;

		case FRM_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_9))>>GPIO_PIN_9);
		break;

		case FLM_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_8))>>GPIO_PIN_8);
		break;

		case FL_SNS_INDEX:
			PortVal = ((PORTPPR0 & (0x1<<GPIO_PIN_7))>>GPIO_PIN_7);
		break;

		case FLS_SNS_INDEX:
			PortVal = ((PORTPPR10 & (0x1<<GPIO_PIN_D))>>GPIO_PIN_D);
		break;

		default:
		break;
	}
	return PortVal;
}

/***********************************************************************
** Function:    HWA_SetAllApaSensorLineHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetAllApaSensorLineHigh(void)
{
	HWA_SetRrsSensorHigh();
	
	HWA_SetRlsSensorHigh();
	
	HWA_SetFrsSensorHigh();

	HWA_SetFlsSensorHigh();
}

/***********************************************************************
** Function:    HWA_SetAllUpaSensorLineHigh
** Description: 
** Parameter:   None
** Return:      
***********************************************************************/
void HWA_SetAllUpaSensorLineHigh(void)
{
	 HWA_SetRrSensorHigh();
	 
	 HWA_SetRlSensorHigh();
	 
	 HWA_SetRrmSensorHigh();
	 
	 HWA_SetRlmSensorHigh();
	 
	 HWA_SetFrSensorHigh();
	 
	 HWA_SetFlSensorHigh();
	 
	 HWA_SetFrmSensorHigh();
	 
	 HWA_SetFlmSensorHigh();
}

/*********************************END OF FILE***************************/
