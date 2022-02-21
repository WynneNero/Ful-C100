/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_taud.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for TAUD module.
* Creation Date: 2020-7-2
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_taud.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t  g_cg_sync_read;  
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAUD0_Create
* Description  : This function initializes the TAUD0 Bus Interface.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUD0_Create(void)
{
    /* Disable channel0 counter operation */
    TAUD0.TT = _TAUD_CHANNEL15_COUNTER_STOP | _TAUD_CHANNEL14_COUNTER_STOP | _TAUD_CHANNEL13_COUNTER_STOP | 
               _TAUD_CHANNEL12_COUNTER_STOP | _TAUD_CHANNEL11_COUNTER_STOP | _TAUD_CHANNEL10_COUNTER_STOP | 
               _TAUD_CHANNEL9_COUNTER_STOP | _TAUD_CHANNEL8_COUNTER_STOP | _TAUD_CHANNEL7_COUNTER_STOP | 
               _TAUD_CHANNEL6_COUNTER_STOP | _TAUD_CHANNEL5_COUNTER_STOP | _TAUD_CHANNEL4_COUNTER_STOP | 
               _TAUD_CHANNEL3_COUNTER_STOP | _TAUD_CHANNEL2_COUNTER_STOP | _TAUD_CHANNEL1_COUNTER_STOP | 
               _TAUD_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUD0I0 operation and clear request */
    INTC1.ICTAUD0I0.BIT.MKTAUD0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICTAUD0I0.BIT.RFTAUD0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTTAUD0I0 setting */
    INTC1.ICTAUD0I0.BIT.TBTAUD0I0 = _INT_TABLE_VECTOR;
    INTC1.ICTAUD0I0.UINT16 &= _INT_PRIORITY_LEVEL4;
    TAUD0.TPS = _TAUD_CK3_PRE_PCLK_4 | _TAUD_CK2_PRE_PCLK_2 | _TAUD_CK1_PRE_PCLK_1 | _TAUD_CK0_PRE_PCLK_0;
    TAUD0.BRS = _TAUD0_CK3_PRE_CLOCK_DIVISION;
    /* Set channel 0 setting */
    TAUD0.CMOR0 = _TAUD_SELECTION_CK3 | _TAUD_COUNT_CLOCK_PCLK | _TAUD_INDEPENDENT_CHANNEL | 
                  _TAUD_START_TRIGGER_SOFTWARE | _TAUD_OVERFLOW_AUTO_CLEAR | _TAUD_INTERVAL_TIMER_MODE | 
                  _TAUD_START_INT_NOT_GENERATED;
    TAUD0.CMUR0 = _TAUD_INPUT_EDGE_UNUSED;
    TAUD0.CDR0 = _TAUD0_CHANNEL0_COMPARE_VALUE;
    /* Set output mode setting */
    TAUD0.TOE = _TAUD_CHANNEL0_ENABLES_OUTPUT_FUNCTION;
    TAUD0.TOM = _TAUD_CHANNEL0_INDEPENDENT_OPERATION;
    TAUD0.TOC = _TAUD_CHANNEL0_OPERATION_MODE1;
    TAUD0.TOL = _TAUD_CHANNEL0_POSITIVE_LOGIC;
    TAUD0.TDE = _TAUD_CHANNEL0_DISABLES_DEAD_TIME_OPERATION;
    TAUD0.TDM = _TAUD_CHANNEL0_DETECTING_DUTY_CYCLE;
    TAUD0.TDL = _TAUD_CHANNEL0_NORMAL_PHASE;
    TAUD0.TRE = _TAUD_CHANNEL0_REAL_TIME_OUTPUT_DISABLES;
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TPS;
    __syncp();

    SL_TAUD0.SELB_TAUD0I = _TAUD_NO_CHANGE_INPUT_SIGNAL;
    /* Set TAUD0O0 pin */
    PORT.PIBC9 &= _PORT_CLEAR_BIT0;
    PORT.PBDC9 &= _PORT_CLEAR_BIT0;
    PORT.PM9 |= _PORT_SET_BIT0;  
    PORT.PMC9 &= _PORT_CLEAR_BIT0;
    PORT.PFC9 |= _PORT_SET_BIT0;  
    PORT.PFCE9 &= _PORT_CLEAR_BIT0;
    PORT.PMC9 |= _PORT_SET_BIT0;  
    PORT.PM9 &= _PORT_CLEAR_BIT0;
}
/***********************************************************************************************************************
* Function Name: R_TAUD0_Channel0_Start
* Description  : This function clears TAUD00 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUD0_Channel0_Start(void)
{
    /* Clear INTTAUD0I0 request and enable operation */
    INTC1.ICTAUD0I0.BIT.RFTAUD0I0 = _INT_REQUEST_NOT_OCCUR;
    INTC1.ICTAUD0I0.BIT.MKTAUD0I0 = _INT_PROCESSING_ENABLED;    
    /* Enable channel0 counter operation */
    TAUD0.TS |= _TAUD_CHANNEL0_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUD0_Channel0_Stop
* Description  : This function disables TAUD00 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUD0_Channel0_Stop(void)
{
    /* Disable channel0 counter operation */
    TAUD0.TT |= _TAUD_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUD0I0 operation and clear request */
    INTC1.ICTAUD0I0.BIT.MKTAUD0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICTAUD0I0.BIT.RFTAUD0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUD0.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
