/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ    	 								   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:0.1
* Date:20151014
* Author:Shang Qiuju
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1  Oct 14,2015  SHANG Qiuju Initial version
* 0.2  Mar 17,2017  ZhangJie Add can task and fifo task, add io control funcrtion.
*-----------------------------------------------------------------------
* 0.3  Apr 01,2017   PEI Jingli  Fix headfiles.
* ----------------------------------------------------------------------
=====================================================================*/
/**** System include files ****/
#include "CONFIG.H"
//#include "TYPES.H" 
#include "define.h"
#include "IRQ_if.h"
#include "GPIO_if.h"
#include "Driver_if.h"

/*---Private include files--------------------------------------------*/
#include "can_cfg.h"
#include "can_def.h"
#include "IL_INC.H"
//#include "nm_osek.h"
#include "CanDriver.h"
#include "CanDriver_if.h"

#include "tpmc.h"
#include "Desc.h"
#include "ComplexDrvier_Globaldef_IF.h" 
//CanDiagFuncCallBackType CanDiagAppCallBack = NULL;
/*===VARIABLES========================================================*/
/*---Global-----------------------------------------------------------*/
/*---Private----------------------------------------------------------*/

/*===FUNCTIONS========================================================*/

E_DEV_POWER eCanWorkingState = E_DEV_MAX_TYPE;
BOOL bCanBusoff = FALSE;
BOOL bCanAccOn = FALSE;
BOOL bCanIsWorking = FALSE;

void can_transceiver_init(void);
void can_transceiver_to_sleep(void);
void can_transceiver_to_normal(void);
void can_transceiver_to_standby(void);
void can_transceiver_to_power_on_standby(void);

/*---Global-----------------------------------------------------------*/
ERR_TYPE CanDriver_Open(void)
{
    can_irq_disable();
    can_transceiver_init();
    eCanWorkingState = E_DEV_POWERON;
    bCanBusoff = FALSE;
    CanInitPowerOn();
    IlInitPowerOn();
    TpInitPowerOn();
    DescInitPowerOn(0);

    IlRxStart(0);    
    IlTxStart(0);
	
	IlRxStart(1);    
    IlTxStart(1);

    can_irq_enable();
    return ERR_OK;
}

ERR_TYPE CanDriver_Close(void)
{
	IlTxStop(0);
	IlRxStop(0); 
	IlTxStop(1);
	IlRxStop(1);   
	
    can_transceiver_to_sleep();
    eCanWorkingState = E_DEV_SLEEP;
    bCanBusoff = FALSE;
    return (ERR_TYPE)ERR_OK;
}

void CanDriver_Init(void)
{
    eCanWorkingState = E_DEV_SLEEP;
}

void CanDriver_DeInit(void)
{
}

void CanDriver_10ms_Entry(void)
{
    if((E_DEV_POWERON == eCanWorkingState)
        ||(E_DEV_WAKEUP== eCanWorkingState))
        {
            CanTask();
            IlRxTask(0); 
            IlTxTask(0);         ///when all node off ,diag is OK   
           IlRxTask(1); 
           IlTxTask(1);  
            DescTask();    
        }
}

U8 CanDriver_Control(U8 type, void* buffer)
{
    ERR_TYPE bRet=ERR_OK;

    if(buffer==NULL)
    {
        bRet =  ERR_VALUE;
    }
    else
    {
        switch(type)
        {
            case E_REGISTER_CALLBACK:
          //      CanDiagAppCallBack =(CanDiagFuncCallBackType)buffer;
                break;
            default:break;
        }
    }
    return bRet;
}

void CanDriver_powercontrol(E_DEV_POWER type)
{
    switch(type)
    {
        case E_DEV_POWERON:
            can_transceiver_init();
            bCanBusoff = FALSE;
        break;
        case E_DEV_POWEROFF:
            can_transceiver_to_sleep();
        break;
        case E_DEV_WAKEUP:
            bCanBusoff = FALSE;
            can_transceiver_to_power_on_standby();
        break;
        case E_DEV_SLEEP:
            can_transceiver_to_sleep();
        default:
        break;
    }
    eCanWorkingState = type;
}

U8 CanDriver_GetpowerStatus(void)
{
    U8 ret = 0u;
    ret =  eCanWorkingState;
    return ret;
}


/***********************************************************************
* FUNCTION    : void can_irq_enable(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_irq_enable(void)
{
    IRQ_IntClr(CAN_IRQ_GERR_MASK);
    IRQ_IntEn(CAN_IRQ_GERR_MASK);

    IRQ_IntClr(CAN_IRQ_GERR_MASK+1u);
    IRQ_IntEn(CAN_IRQ_GERR_MASK+1u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM2);
        IRQ_IntEn(CAN_IRQ_MASK_NUM2);

        IRQ_IntClr(CAN_IRQ_MASK_NUM2+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM2+2u);
    if(kCanNumberOfPhysChannels == 1)
    {
        IRQ_IntClr(CAN_IRQ_MASK_NUM1);
        IRQ_IntEn(CAN_IRQ_MASK_NUM1);

        IRQ_IntClr(CAN_IRQ_MASK_NUM1+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM1+2u);
    }
    else if (kCanNumberOfPhysChannels == 2)
    {
        IRQ_IntClr(CAN_IRQ_MASK_NUM2);
        IRQ_IntEn(CAN_IRQ_MASK_NUM2);

        IRQ_IntClr(CAN_IRQ_MASK_NUM2+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM2+2u);
    }
    else if (kCanNumberOfPhysChannels == 3)
    {
        IRQ_IntClr(CAN_IRQ_MASK_NUM3);
        IRQ_IntEn(CAN_IRQ_MASK_NUM3);

        IRQ_IntClr(CAN_IRQ_MASK_NUM3+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM3+2u);
    }
	else if (kCanNumberOfPhysChannels == 4)
    {
        IRQ_IntClr(CAN_IRQ_MASK_NUM4);
        IRQ_IntEn(CAN_IRQ_MASK_NUM4);

        IRQ_IntClr(CAN_IRQ_MASK_NUM4+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM4+2u);
    }
    else if (kCanNumberOfPhysChannels == 5)
    {
        IRQ_IntClr(CAN_IRQ_MASK_NUM5);
        IRQ_IntEn(CAN_IRQ_MASK_NUM5);

        IRQ_IntClr(CAN_IRQ_MASK_NUM5+2u);
        IRQ_IntEn(CAN_IRQ_MASK_NUM5+2u);
    }
}

/***********************************************************************
* FUNCTION    : void can_irq_disable(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_irq_disable(void)
{
    IRQ_IntDis(CAN_IRQ_GERR_MASK);
    IRQ_IntClr(CAN_IRQ_GERR_MASK);

    IRQ_IntDis(CAN_IRQ_GERR_MASK+1u);
    IRQ_IntClr(CAN_IRQ_GERR_MASK+1u);
        IRQ_IntDis(CAN_IRQ_MASK_NUM2);
        IRQ_IntClr(CAN_IRQ_MASK_NUM2);

        IRQ_IntDis(CAN_IRQ_MASK_NUM2+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM2+2u);
    if(kCanNumberOfPhysChannels == 1)
    {
        IRQ_IntDis(CAN_IRQ_MASK_NUM1);
        IRQ_IntClr(CAN_IRQ_MASK_NUM1);

        IRQ_IntDis(CAN_IRQ_MASK_NUM1+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM1+2u);
    }
    else if (kCanNumberOfPhysChannels == 2)
    {
        IRQ_IntDis(CAN_IRQ_MASK_NUM2);
        IRQ_IntClr(CAN_IRQ_MASK_NUM2);

        IRQ_IntDis(CAN_IRQ_MASK_NUM2+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM2+2u);
    }
    else if (kCanNumberOfPhysChannels == 3)
    {
        IRQ_IntDis(CAN_IRQ_MASK_NUM3);
        IRQ_IntClr(CAN_IRQ_MASK_NUM3);

        IRQ_IntDis(CAN_IRQ_MASK_NUM3+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM3+2u);
    }
	else if (kCanNumberOfPhysChannels == 4)
    {
        IRQ_IntDis(CAN_IRQ_MASK_NUM4);
        IRQ_IntClr(CAN_IRQ_MASK_NUM4);

        IRQ_IntDis(CAN_IRQ_MASK_NUM4+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM4+2u);
    }
    else if (kCanNumberOfPhysChannels == 5)
    {
        IRQ_IntDis(CAN_IRQ_MASK_NUM5);
        IRQ_IntClr(CAN_IRQ_MASK_NUM5);

        IRQ_IntDis(CAN_IRQ_MASK_NUM5+2u);
        IRQ_IntClr(CAN_IRQ_MASK_NUM5+2u);
    }
}

/***********************************************************************
* FUNCTION    : void can_tja1041_init(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_transceiver_init(void)
{
    can_transceiver_to_normal();
}


/***********************************************************************
* FUNCTION    : void can_tja1041_to_standby(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_transceiver_to_standby(void)
{
    CAN0_CLR_STB();
    CAN0_CLR_EN();	

    CAN1_CLR_STB();
    CAN1_CLR_EN();
}

/***********************************************************************
* FUNCTION    : void can_tja1041_to_sleep(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_transceiver_to_sleep(void)
{
	CAN0_CLR_STB();
	CAN0_SET_EN();
	delay_us(100);
	CAN0_CLR_EN();

	CAN1_CLR_STB();
	CAN1_SET_EN();
	delay_us(100);
	CAN1_CLR_EN();	
}

/***********************************************************************
* FUNCTION    : void can_tja1041_to_power_on_standby(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_transceiver_to_power_on_standby(void)
{
    CAN0_SET_STB();
    CAN0_CLR_EN();
	
    CAN1_SET_STB();
    CAN1_CLR_EN();
}

/***********************************************************************
* FUNCTION    : void can_tja1041_to_normal(void)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void can_transceiver_to_normal(void)
{
	CAN0_SET_WAKE();
	delay_100us();
	CAN0_CLR_WAKE();
	CAN0_SET_EN();
	CAN0_SET_STB();

	CAN1_SET_WAKE();
	delay_100us();
	CAN1_CLR_WAKE();
	CAN1_SET_EN();
	CAN1_SET_STB(); 
}

/***********************************************************************
* FUNCTION    : void CanDriver_SetBusOffState(BOOL bBusOff)
* DESCRIPTION : 
* INPUTS      : none
* RETURN      : none
***********************************************************************/
void CanDriver_SetBusOffState(BOOL bBusOff)
{
    bCanBusoff = bBusOff;
}

void CanDriver_SetACCon(void)
{
    bCanAccOn = TRUE;
}

void CanDriver_SetACCoff(void)
{
    bCanAccOn = FALSE;
}


/*---Private----------------------------------------------------------*/

