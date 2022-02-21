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
* File Name    : r_cg_taub.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for TAUB module.
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
#include "r_cg_taub.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
    /* For TAUB[#n]_ch0 pulse measurement */
extern volatile uint32_t g_taub0_ch0_width;
    /* For TAUB[#n]_ch2 pulse measurement */
extern volatile uint32_t g_taub0_ch2_width;
    /* For TAUB[#n]_ch4 pulse measurement */
extern volatile uint32_t g_taub0_ch4_width;
    /* For TAUB[#n]_ch5 pulse measurement */
extern volatile uint32_t g_taub0_ch5_width;
    /* For TAUB[#n]_ch6 pulse measurement */
extern volatile uint32_t g_taub0_ch6_width;
    /* For TAUB[#n]_ch7 pulse measurement */
extern volatile uint32_t g_taub0_ch7_width;
    /* For TAUB[#n]_ch8 pulse measurement */
extern volatile uint32_t g_taub0_ch8_width;
    /* For TAUB[#n]_ch10 pulse measurement */
extern volatile uint32_t g_taub0_ch10_width;
    /* For TAUB[#n]_ch12 pulse measurement */
extern volatile uint32_t g_taub0_ch12_width;
    /* For TAUB[#n]_ch13 pulse measurement */
extern volatile uint32_t g_taub0_ch13_width;
    /* For TAUB[#n]_ch14 pulse measurement */
extern volatile uint32_t g_taub0_ch14_width;
    /* For TAUB[#n]_ch15 pulse measurement */
extern volatile uint32_t g_taub0_ch15_width;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TAUB0_Create
* Description  : This function initializes the TAUB0 Bus Interface.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Create(void)
{
    /* Disable channel0 counter operation */
    TAUB0.TT = _TAUB_CHANNEL15_COUNTER_STOP | _TAUB_CHANNEL14_COUNTER_STOP | _TAUB_CHANNEL13_COUNTER_STOP | 
               _TAUB_CHANNEL12_COUNTER_STOP | _TAUB_CHANNEL11_COUNTER_STOP | _TAUB_CHANNEL10_COUNTER_STOP | 
               _TAUB_CHANNEL9_COUNTER_STOP | _TAUB_CHANNEL8_COUNTER_STOP | _TAUB_CHANNEL7_COUNTER_STOP | 
               _TAUB_CHANNEL6_COUNTER_STOP | _TAUB_CHANNEL5_COUNTER_STOP | _TAUB_CHANNEL4_COUNTER_STOP | 
               _TAUB_CHANNEL3_COUNTER_STOP | _TAUB_CHANNEL2_COUNTER_STOP | _TAUB_CHANNEL1_COUNTER_STOP | 
               _TAUB_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUB0I0 operation and clear request */
    INTC2.ICTAUB0I0.BIT.MKTAUB0I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I0.BIT.RFTAUB0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I2 operation and clear request */
    INTC2.ICTAUB0I2.BIT.MKTAUB0I2 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I2.BIT.RFTAUB0I2 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I4 operation and clear request */
    INTC2.ICTAUB0I4.BIT.MKTAUB0I4 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I4.BIT.RFTAUB0I4 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I5 operation and clear request */
    INTC2.ICTAUB0I5.BIT.MKTAUB0I5 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I5.BIT.RFTAUB0I5 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I6 operation and clear request */
    INTC2.ICTAUB0I6.BIT.MKTAUB0I6 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I6.BIT.RFTAUB0I6 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I7 operation and clear request */
    INTC2.ICTAUB0I7.BIT.MKTAUB0I7 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I7.BIT.RFTAUB0I7 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I8 operation and clear request */
    INTC2.ICTAUB0I8.BIT.MKTAUB0I8 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I8.BIT.RFTAUB0I8 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I10 operation and clear request */
    INTC2.ICTAUB0I10.BIT.MKTAUB0I10 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I10.BIT.RFTAUB0I10 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I12 operation and clear request */
    INTC2.ICTAUB0I12.BIT.MKTAUB0I12 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I12.BIT.RFTAUB0I12 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I13 operation and clear request */
    INTC2.ICTAUB0I13.BIT.MKTAUB0I13 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I13.BIT.RFTAUB0I13 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I14 operation and clear request */
    INTC2.ICTAUB0I14.BIT.MKTAUB0I14 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I14.BIT.RFTAUB0I14 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I15 operation and clear request */
    INTC2.ICTAUB0I15.BIT.MKTAUB0I15 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I15.BIT.RFTAUB0I15 = _INT_REQUEST_NOT_OCCUR;
    TAUB0.TPS = _TAUB_CK3_PRE_PCLK_5 | _TAUB_CK2_PRE_PCLK_2 | _TAUB_CK1_PRE_PCLK_1 | _TAUB_CK0_PRE_PCLK_0;
    /* Set channel 0 setting */
    TAUB0.CMOR0 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR0 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 2 setting */
    TAUB0.CMOR2 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR2 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 4 setting */
    TAUB0.CMOR4 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR4 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 5 setting */
    TAUB0.CMOR5 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR5 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 6 setting */
    TAUB0.CMOR6 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR6 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 7 setting */
    TAUB0.CMOR7 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR7 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 8 setting */
    TAUB0.CMOR8 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                  _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                  _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR8 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 10 setting */
    TAUB0.CMOR10 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                   _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                   _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR10 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 12 setting */
    TAUB0.CMOR12 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                   _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                   _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR12 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 13 setting */
    TAUB0.CMOR13 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                   _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                   _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR13 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 14 setting */
    TAUB0.CMOR14 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                   _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                   _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR14 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set channel 15 setting */
    TAUB0.CMOR15 = _TAUB_SELECTION_CK3 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | 
                   _TAUB_VALID_EDGE_SOFTWARE | _TAUB_OVERFLOW_MANUAL_CLEAR | _TAUB_COUNT_CAPTURE_MODE | 
                   _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR15 = _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW;
    /* Set output mode setting */
    TAUB0.TOE = _TAUB_CHANNEL15_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL14_DISABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL13_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL12_DISABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL10_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL8_DISABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL7_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL6_DISABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL5_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL4_DISABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL2_DISABLES_OUTPUT_MODE | _TAUB_CHANNEL0_DISABLES_OUTPUT_MODE;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TPS;
    __syncp();

    /* Set TAUB0I0 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT7;
    PORT.PBDC0 &= _PORT_CLEAR_BIT7;
    PORT.PM0 |= _PORT_SET_BIT7;  
    PORT.PMC0 &= _PORT_CLEAR_BIT7;
    PORT.PFC0 |= _PORT_SET_BIT7;  
    PORT.PFCE0 |= _PORT_SET_BIT7;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT7;
    PORT.PMC0 |= _PORT_SET_BIT7;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL0 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I2 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT8;
    PORT.PBDC0 &= _PORT_CLEAR_BIT8;
    PORT.PM0 |= _PORT_SET_BIT8;  
    PORT.PMC0 &= _PORT_CLEAR_BIT8;
    PORT.PFC0 |= _PORT_SET_BIT8;  
    PORT.PFCE0 |= _PORT_SET_BIT8;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT8;
    PORT.PMC0 |= _PORT_SET_BIT8;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL2 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I4 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT9;
    PORT.PBDC0 &= _PORT_CLEAR_BIT9;
    PORT.PM0 |= _PORT_SET_BIT9;  
    PORT.PMC0 &= _PORT_CLEAR_BIT9;
    PORT.PFC0 |= _PORT_SET_BIT9;  
    PORT.PFCE0 |= _PORT_SET_BIT9;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT9;
    PORT.PMC0 |= _PORT_SET_BIT9;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL4 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I5 pin */
    PORT.PIBC10 &= _PORT_CLEAR_BIT13;
    PORT.PBDC10 &= _PORT_CLEAR_BIT13;
    PORT.PM10 |= _PORT_SET_BIT13;  
    PORT.PMC10 &= _PORT_CLEAR_BIT13;
    PORT.PFC10 |= _PORT_SET_BIT13;  
    PORT.PFCE10 |= _PORT_SET_BIT13;  
    PORT.PFCAE10 &= _PORT_CLEAR_BIT13;
    PORT.PMC10 |= _PORT_SET_BIT13;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL5 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I6 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT10;
    PORT.PBDC0 &= _PORT_CLEAR_BIT10;
    PORT.PM0 |= _PORT_SET_BIT10;  
    PORT.PMC0 &= _PORT_CLEAR_BIT10;
    PORT.PFC0 |= _PORT_SET_BIT10;  
    PORT.PFCE0 |= _PORT_SET_BIT10;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT10;
    PORT.PMC0 |= _PORT_SET_BIT10;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL6 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I7 pin */
    PORT.PIBC10 &= _PORT_CLEAR_BIT14;
    PORT.PBDC10 &= _PORT_CLEAR_BIT14;
    PORT.PM10 |= _PORT_SET_BIT14;  
    PORT.PMC10 &= _PORT_CLEAR_BIT14;
    PORT.PFC10 |= _PORT_SET_BIT14;  
    PORT.PFCE10 |= _PORT_SET_BIT14;  
    PORT.PMC10 |= _PORT_SET_BIT14;  
    DNF.ATAUB0IENL.BIT.ATAUB0IENL7 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I8 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT11;
    PORT.PBDC0 &= _PORT_CLEAR_BIT11;
    PORT.PM0 |= _PORT_SET_BIT11;  
    PORT.PMC0 &= _PORT_CLEAR_BIT11;
    PORT.PFC0 &= _PORT_CLEAR_BIT11;
    PORT.PFCE0 |= _PORT_SET_BIT11;  
    PORT.PMC0 |= _PORT_SET_BIT11;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH0 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I10 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT12;
    PORT.PBDC0 &= _PORT_CLEAR_BIT12;
    PORT.PM0 |= _PORT_SET_BIT12;  
    PORT.PMC0 &= _PORT_CLEAR_BIT12;
    PORT.PFC0 &= _PORT_CLEAR_BIT12;
    PORT.PFCE0 |= _PORT_SET_BIT12;  
    PORT.PMC0 |= _PORT_SET_BIT12;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH2 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I12 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT13;
    PORT.PBDC0 &= _PORT_CLEAR_BIT13;
    PORT.PM0 |= _PORT_SET_BIT13;  
    PORT.PMC0 &= _PORT_CLEAR_BIT13;
    PORT.PIPC0 &= _PORT_CLEAR_BIT13;
    PORT.PFC0 &= _PORT_CLEAR_BIT13;
    PORT.PFCE0 |= _PORT_SET_BIT13;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT13;
    PORT.PMC0 |= _PORT_SET_BIT13;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH4 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I13 pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT1;
    PORT.PBDC11 &= _PORT_CLEAR_BIT1;
    PORT.PM11 |= _PORT_SET_BIT1;  
    PORT.PMC11 &= _PORT_CLEAR_BIT1;
    PORT.PFC11 |= _PORT_SET_BIT1;  
    PORT.PFCE11 |= _PORT_SET_BIT1;  
    PORT.PMC11 |= _PORT_SET_BIT1;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH5 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I14 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT14;
    PORT.PBDC0 &= _PORT_CLEAR_BIT14;
    PORT.PM0 |= _PORT_SET_BIT14;  
    PORT.PMC0 &= _PORT_CLEAR_BIT14;
    PORT.PIPC0 &= _PORT_CLEAR_BIT14;
    PORT.PFC0 &= _PORT_CLEAR_BIT14;
    PORT.PFCE0 |= _PORT_SET_BIT14;  
    PORT.PFCAE0 &= _PORT_CLEAR_BIT14;
    PORT.PMC0 |= _PORT_SET_BIT14;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH6 = _TAUB_FILTER_ENABLED;
    /* Set TAUB0I15 pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT2;
    PORT.PBDC11 &= _PORT_CLEAR_BIT2;
    PORT.PM11 |= _PORT_SET_BIT2;  
    PORT.PMC11 &= _PORT_CLEAR_BIT2;
    PORT.PIPC11 &= _PORT_CLEAR_BIT2;
    PORT.PFC11 |= _PORT_SET_BIT2;  
    PORT.PFCE11 |= _PORT_SET_BIT2;  
    PORT.PFCAE11 &= _PORT_CLEAR_BIT2;
    PORT.PMC11 |= _PORT_SET_BIT2;  
    DNF.ATAUB0IENH.BIT.ATAUB0IENH7 = _TAUB_FILTER_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel0_Start
* Description  : This function clears TAUB00 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel0_Start(void)
{
    /* Disable channel0 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL0_COUNTER_STOP;

    /* Enable channel0 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL0_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel0_Stop
* Description  : This function disables TAUB00 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel0_Stop(void)
{
    /* Disable channel0 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL0_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel0_Get_PulseWidth
* Description  : This function measures TAUB0 channel 0 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel0_Get_PulseWidth(uint32_t * const width)
{
    /* For channel0 pulse measurement */
    *width = g_taub0_ch0_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel2_Start
* Description  : This function clears TAUB02 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel2_Start(void)
{
    /* Disable channel2 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL2_COUNTER_STOP;

    /* Enable channel2 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL2_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel2_Stop
* Description  : This function disables TAUB02 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel2_Stop(void)
{
    /* Disable channel2 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL2_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel2_Get_PulseWidth
* Description  : This function measures TAUB0 channel 2 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel2_Get_PulseWidth(uint32_t * const width)
{
    /* For channel2 pulse measurement */
    *width = g_taub0_ch2_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel4_Start
* Description  : This function clears TAUB04 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel4_Start(void)
{
    /* Disable channel4 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL4_COUNTER_STOP;

    /* Enable channel4 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL4_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel4_Stop
* Description  : This function disables TAUB04 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel4_Stop(void)
{
    /* Disable channel4 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL4_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel4_Get_PulseWidth
* Description  : This function measures TAUB0 channel 4 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel4_Get_PulseWidth(uint32_t * const width)
{
    /* For channel4 pulse measurement */
    *width = g_taub0_ch4_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel5_Start
* Description  : This function clears TAUB05 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel5_Start(void)
{
    /* Disable channel5 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL5_COUNTER_STOP;

    /* Enable channel5 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL5_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel5_Stop
* Description  : This function disables TAUB05 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel5_Stop(void)
{
    /* Disable channel5 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL5_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel5_Get_PulseWidth
* Description  : This function measures TAUB0 channel 5 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel5_Get_PulseWidth(uint32_t * const width)
{
    /* For channel5 pulse measurement */
    *width = g_taub0_ch5_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel6_Start
* Description  : This function clears TAUB06 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel6_Start(void)
{
    /* Disable channel6 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL6_COUNTER_STOP;

    /* Enable channel6 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL6_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel6_Stop
* Description  : This function disables TAUB06 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel6_Stop(void)
{
    /* Disable channel6 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL6_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel6_Get_PulseWidth
* Description  : This function measures TAUB0 channel 6 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel6_Get_PulseWidth(uint32_t * const width)
{
    /* For channel6 pulse measurement */
    *width = g_taub0_ch6_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel7_Start
* Description  : This function clears TAUB07 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel7_Start(void)
{
    /* Disable channel7 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL7_COUNTER_STOP;

    /* Enable channel7 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL7_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel7_Stop
* Description  : This function disables TAUB07 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel7_Stop(void)
{
    /* Disable channel7 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL7_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel7_Get_PulseWidth
* Description  : This function measures TAUB0 channel 7 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel7_Get_PulseWidth(uint32_t * const width)
{
    /* For channel7 pulse measurement */
    *width = g_taub0_ch7_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel8_Start
* Description  : This function clears TAUB08 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel8_Start(void)
{
    /* Disable channel8 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL8_COUNTER_STOP;

    /* Enable channel8 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL8_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel8_Stop
* Description  : This function disables TAUB08 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel8_Stop(void)
{
    /* Disable channel8 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL8_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel8_Get_PulseWidth
* Description  : This function measures TAUB0 channel 8 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel8_Get_PulseWidth(uint32_t * const width)
{
    /* For channel8 pulse measurement */
    *width = g_taub0_ch8_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel10_Start
* Description  : This function clears TAUB010 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel10_Start(void)
{
    /* Disable channel10 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL10_COUNTER_STOP;

    /* Enable channel10 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL10_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel10_Stop
* Description  : This function disables TAUB010 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel10_Stop(void)
{
    /* Disable channel10 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL10_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel10_Get_PulseWidth
* Description  : This function measures TAUB0 channel 10 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel10_Get_PulseWidth(uint32_t * const width)
{
    /* For channel10 pulse measurement */
    *width = g_taub0_ch10_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel12_Start
* Description  : This function clears TAUB012 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel12_Start(void)
{
    /* Disable channel12 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL12_COUNTER_STOP;

    /* Enable channel12 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL12_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel12_Stop
* Description  : This function disables TAUB012 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel12_Stop(void)
{
    /* Disable channel12 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL12_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel12_Get_PulseWidth
* Description  : This function measures TAUB0 channel 12 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel12_Get_PulseWidth(uint32_t * const width)
{
    /* For channel12 pulse measurement */
    *width = g_taub0_ch12_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel13_Start
* Description  : This function clears TAUB013 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel13_Start(void)
{
    /* Disable channel13 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL13_COUNTER_STOP;

    /* Enable channel13 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL13_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel13_Stop
* Description  : This function disables TAUB013 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel13_Stop(void)
{
    /* Disable channel13 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL13_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel13_Get_PulseWidth
* Description  : This function measures TAUB0 channel 13 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel13_Get_PulseWidth(uint32_t * const width)
{
    /* For channel13 pulse measurement */
    *width = g_taub0_ch13_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel14_Start
* Description  : This function clears TAUB014 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel14_Start(void)
{
    /* Disable channel14 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL14_COUNTER_STOP;

    /* Enable channel14 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL14_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel14_Stop
* Description  : This function disables TAUB014 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel14_Stop(void)
{
    /* Disable channel14 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL14_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel14_Get_PulseWidth
* Description  : This function measures TAUB0 channel 14 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel14_Get_PulseWidth(uint32_t * const width)
{
    /* For channel14 pulse measurement */
    *width = g_taub0_ch14_width;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel15_Start
* Description  : This function clears TAUB015 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel15_Start(void)
{
    /* Disable channel15 counter operation */
    //TAUB0.TT |= _TAUB_CHANNEL15_COUNTER_STOP;

    /* Enable channel15 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL15_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel15_Stop
* Description  : This function disables TAUB015 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel15_Stop(void)
{
    /* Disable channel15 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL15_COUNTER_STOP;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel15_Get_PulseWidth
* Description  : This function measures TAUB0 channel 15 input pulse width.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel15_Get_PulseWidth(uint32_t * const width)
{
    /* For channel15 pulse measurement */
    *width = g_taub0_ch15_width;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
