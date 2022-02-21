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
* File Name    : r_cg_dmac_user.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for DMA module.
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
#include "r_cg_dmac.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
unsigned int ussDmaDestinationAddr[12];
unsigned int ussDmaCount[12];
void ussDmaUserInit(void)
{
    unsigned char i = 0;
    for(i=0;i<12;i++)
    {
        ussDmaDestinationAddr[i] = 0;
        ussDmaCount[i] = 0;
    }  
    /*
    R_DMAC00_Create();
    R_DMAC01_Create();
    R_DMAC14_Create();
    R_DMAC15_Create();
    R_DMAC04_Create();
    R_DMAC05_Create();
    R_DMAC07_Create();
    R_DMAC10_Create();
    R_DMAC16_Create();
    R_DMAC12_Create();
    R_DMAC13_Create();
    */
}
void setUssDmaDestinationAddr(unsigned char index,unsigned int addr)
{
    ussDmaDestinationAddr[index] = addr;
}
void setUssDmaCounter(unsigned char index,unsigned int counter)
{
    ussDmaCount[index] = counter;
}

/* End user code. Do not edit comment generated here */


/* Start user code for adding. Do not edit comment generated here */
extern void ISR_INTDMA0_CAT2_func(void);
extern void ISR_INTDMA1_CAT2_func(void);
extern void ISR_INTDMA2_CAT2_func(void);
extern void ISR_INTDMA3_CAT2_func(void);
extern void ISR_INTDMA4_CAT2_func(void);
extern void ISR_INTDMA5_CAT2_func(void);
extern void ISR_INTDMA6_CAT2_func(void);
extern void ISR_INTDMA7_CAT2_func(void);
extern void ISR_INTDMA8_CAT2_func(void);
extern void ISR_INTDMA9_CAT2_func(void);
extern void ISR_INTDMA10_CAT2_func(void);
extern void ISR_INTDMA11_CAT2_func(void);
extern void ISR_INTDMA12_CAT2_func(void);
extern void ISR_INTDMA13_CAT2_func(void);
extern void ISR_INTDMA14_CAT2_func(void);
extern void ISR_INTDMA15_CAT2_func(void);

 void ISR_INTDMA0_CAT2_func(void)
 {
    R_DMAC00_Stop();
    DMACDCSTC0 |= (1<<7)+(1<<4);
    
 }
 void ISR_INTDMA1_CAT2_func(void)
 {
    R_DMAC01_Stop();
    DMACDCSTC1 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA2_CAT2_func(void)
 {
    R_DMAC02_Stop();    
    DMACDCSTC2 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA3_CAT2_func(void)
 {
    R_DMAC03_Stop();    
    DMACDCSTC3 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA4_CAT2_func(void)
 {
     R_DMAC04_Stop();   
     DMACDCSTC4 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA5_CAT2_func(void)
 {
     R_DMAC05_Stop();
     DMACDCSTC5 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA6_CAT2_func(void)
 {
     R_DMAC06_Stop();
     
     DMACDCSTC6 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA7_CAT2_func(void)
 {
     R_DMAC07_Stop();
     DMACDCSTC7 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA8_CAT2_func(void)
 {
     R_DMAC10_Stop();
     DMACDCSTC8 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA9_CAT2_func(void)
 {
     R_DMAC11_Stop();
     DMACDCSTC9 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA10_CAT2_func(void)
 {
    R_DMAC12_Stop();
    DMACDCSTC10 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA11_CAT2_func(void)
 {
    R_DMAC13_Stop();
    DMACDCSTC11 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA12_CAT2_func(void)
 {
    R_DMAC14_Stop();
    DMACDCSTC12 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA13_CAT2_func(void)
 {
    R_DMAC15_Stop();
    DMACDCSTC13 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA14_CAT2_func(void)
 {
    R_DMAC16_Stop();
    DMACDCSTC14 |= (1<<7)+(1<<4);
 }
 void ISR_INTDMA15_CAT2_func(void)
 {
 }
 /* End user code. Do not edit comment generated here */
