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
* File Name    : r_cg_taub_user.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for TAUB module.
* Creation Date: 2020-6-16
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
/* For TAU0_ch0 pulse measurement */
volatile uint32_t g_taub0_ch0_width = 0U;
/* For TAU0_ch2 pulse measurement */
volatile uint32_t g_taub0_ch2_width = 0U;
/* For TAU0_ch4 pulse measurement */
volatile uint32_t g_taub0_ch4_width = 0U;
/* For TAU0_ch5 pulse measurement */
volatile uint32_t g_taub0_ch5_width = 0U;
/* For TAU0_ch6 pulse measurement */
volatile uint32_t g_taub0_ch6_width = 0U;
/* For TAU0_ch7 pulse measurement */
volatile uint32_t g_taub0_ch7_width = 0U;
/* For TAU0_ch8 pulse measurement */
volatile uint32_t g_taub0_ch8_width = 0U;
/* For TAU0_ch10 pulse measurement */
volatile uint32_t g_taub0_ch10_width = 0U;
/* For TAU0_ch12 pulse measurement */
volatile uint32_t g_taub0_ch12_width = 0U;
/* For TAU0_ch13 pulse measurement */
volatile uint32_t g_taub0_ch13_width = 0U;
/* For TAU0_ch14 pulse measurement */
volatile uint32_t g_taub0_ch14_width = 0U;
/* For TAU0_ch15 pulse measurement */
volatile uint32_t g_taub0_ch15_width = 0U;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
