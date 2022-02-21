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
* File Name    : r_cg_tauj.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for TAUJ module.
* Creation Date: 2020-7-6
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
#include "r_cg_tauj.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAUJ1_Create
* Description  : This function initializes the TAUJ1 Bus Interface.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUJ1_Create(void)
{
    /* Disable channel1 counter operation */
    TAUJ1.TT = _TAUJ_CHANNEL3_COUNTER_STOP | _TAUJ_CHANNEL2_COUNTER_STOP | _TAUJ_CHANNEL1_COUNTER_STOP | 
               _TAUJ_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUJ1I0 operation and clear request */
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUJ1I1 operation and clear request */
    INTC2.ICTAUJ1I1.BIT.MKTAUJ1I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I1.BIT.RFTAUJ1I1 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTTAUJ1I0 setting */
    INTC2.ICTAUJ1I0.BIT.TBTAUJ1I0 = _INT_TABLE_VECTOR;
    INTC2.ICTAUJ1I0.UINT16 &= _INT_PRIORITY_LEVEL3;
    /* Set INTTAUJ1I1 setting */
    INTC2.ICTAUJ1I1.BIT.TBTAUJ1I1 = _INT_TABLE_VECTOR;
    INTC2.ICTAUJ1I1.UINT16 &= _INT_PRIORITY_LEVEL3;
    TAUJ1.TPS = _TAUJ_CK3_PRE_PCLK_3 | _TAUJ_CK2_PRE_PCLK_2 | _TAUJ_CK1_PRE_PCLK_1 | _TAUJ_CK0_PRE_PCLK_0;
    TAUJ1.BRS = _TAUJ1_CK3_PRE_CLOCK_DIVISION;
    /* Set channel 0 setting */
    TAUJ1.CMOR0 = _TAUJ_SELECTION_CK3 | _TAUJ_COUNT_CLOCK_PCLK | _TAUJ_INDEPENDENT_CHANNEL | 
                  _TAUJ_START_TRIGGER_SOFTWARE | _TAUJ_OVERFLOW_AUTO_CLEAR | _TAUJ_INTERVAL_TIMER_MODE | 
                  _TAUJ_START_INT_NOT_GENERATED;
    TAUJ1.CMUR0 = _TAUJ_INPUT_EDGE_UNUSED;
    TAUJ1.CDR0 = _TAUJ1_CHANNEL0_COMPARE_VALUE;
    /* Set channel 1 setting */
    TAUJ1.CMOR1 = _TAUJ_SELECTION_CK3 | _TAUJ_COUNT_CLOCK_PCLK | _TAUJ_INDEPENDENT_CHANNEL | 
                  _TAUJ_START_TRIGGER_SOFTWARE | _TAUJ_OVERFLOW_AUTO_CLEAR | _TAUJ_INTERVAL_TIMER_MODE | 
                  _TAUJ_START_INT_NOT_GENERATED;
    TAUJ1.CMUR1 = _TAUJ_INPUT_EDGE_UNUSED;
    TAUJ1.CDR1 = _TAUJ1_CHANNEL1_COMPARE_VALUE;
    /* Set output mode setting */
    TAUJ1.TOE = _TAUJ_CHANNEL1_ENABLES_OUTPUT_FUNCTION | _TAUJ_CHANNEL0_ENABLES_OUTPUT_FUNCTION;
    TAUJ1.TOM = _TAUJ_CHANNEL1_INDEPENDENT_OPERATION | _TAUJ_CHANNEL0_INDEPENDENT_OPERATION;
    TAUJ1.TOC = _TAUJ_CHANNEL1_OPERATION_MODE1 | _TAUJ_CHANNEL0_OPERATION_MODE1;
    TAUJ1.TOL = _TAUJ_CHANNEL1_POSITIVE_LOGIC | _TAUJ_CHANNEL0_POSITIVE_LOGIC;
    /* Synchronization processing */
    g_cg_sync_read = TAUJ1.TPS;
    __syncp();
    /* Set TAUJ1O0 pin */
    PORT.PIBC9 &= _PORT_CLEAR_BIT4;
    PORT.PBDC9 &= _PORT_CLEAR_BIT4;
    PORT.PM9 |= _PORT_SET_BIT4;  
    PORT.PMC9 &= _PORT_CLEAR_BIT4;
    PORT.PFC9 &= _PORT_CLEAR_BIT4;
    PORT.PFCE9 |= _PORT_SET_BIT4;  
    PORT.PMC9 |= _PORT_SET_BIT4;  
    PORT.PM9 &= _PORT_CLEAR_BIT4;
    /* Set TAUJ1O1 pin */
    PORT.PIBC9 &= _PORT_CLEAR_BIT5;
    PORT.PBDC9 &= _PORT_CLEAR_BIT5;
    PORT.PM9 |= _PORT_SET_BIT5;  
    PORT.PMC9 &= _PORT_CLEAR_BIT5;
    PORT.PFC9 &= _PORT_CLEAR_BIT5;
    PORT.PFCE9 |= _PORT_SET_BIT5;  
    PORT.PMC9 |= _PORT_SET_BIT5;  
    PORT.PM9 &= _PORT_CLEAR_BIT5;
}
/***********************************************************************************************************************
* Function Name: R_TAUJ1_Channel0_Start
* Description  : This function clears TAUJ10 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUJ1_Channel0_Start(void)
{
    /* Clear INTTAUJ1I0 request and enable operation */
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_ENABLED;    
    /* Enable channel0 counter operation */
    TAUJ1.TS |= _TAUJ_CHANNEL0_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUJ1_Channel0_Stop
* Description  : This function disables TAUJ10 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUJ1_Channel0_Stop(void)
{
    /* Disable channel0 counter operation */
    TAUJ1.TT |= _TAUJ_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUJ1I0 operation and clear request */
    INTC2.ICTAUJ1I0.BIT.MKTAUJ1I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I0.BIT.RFTAUJ1I0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUJ1.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUJ1_Channel1_Start
* Description  : This function clears TAUJ11 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUJ1_Channel1_Start(void)
{
    /* Clear INTTAUJ1I1 request and enable operation */
    INTC2.ICTAUJ1I1.BIT.RFTAUJ1I1 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUJ1I1.BIT.MKTAUJ1I1 = _INT_PROCESSING_ENABLED;    
    /* Enable channel1 counter operation */
    TAUJ1.TS |= _TAUJ_CHANNEL1_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUJ1_Channel1_Stop
* Description  : This function disables TAUJ11 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUJ1_Channel1_Stop(void)
{
    /* Disable channel1 counter operation */
    TAUJ1.TT |= _TAUJ_CHANNEL1_COUNTER_STOP;
    /* Disable INTTAUJ1I1 operation and clear request */
    INTC2.ICTAUJ1I1.BIT.MKTAUJ1I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUJ1I1.BIT.RFTAUJ1I1 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUJ1.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
