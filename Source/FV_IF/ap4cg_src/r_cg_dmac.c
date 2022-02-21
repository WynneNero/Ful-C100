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
* File Name    : r_cg_dmac.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for DMA module.
* Creation Date: 2020-8-3
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
extern volatile uint32_t g_cg_sync_read;
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_DMAC0_Create
* Description  : This function initializes the DMAC0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC0_Create(void)
{
    R_DMAC00_Create();
    R_DMAC01_Create();
    R_DMAC02_Create();
    R_DMAC03_Create();
    R_DMAC04_Create();
    R_DMAC05_Create();
    R_DMAC06_Create();
    R_DMAC07_Create();
}
/***********************************************************************************************************************
* Function Name: R_DMAC_Suspend
* Description  : This function Suspends the DMAC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC_Suspend(void)
{
    DMAC.TL = _DMAC_SUSPEND_REQUEST;
}
/***********************************************************************************************************************
* Function Name: R_DMAC_Resume
* Description  : This function Resumes the DMAC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC_Resume(void)
{
    DMAC.TL = _DMAC_SUSPEND_CLEARED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Create
* Description  : This function initializes DMAC00 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Create(void)
{
    /* Disable DMAC00 operation */
    DMAC.DCEN0 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC00 operation and clear request */
    INTC2.ICDMA0.BIT.MKDMA0 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA0.BIT.RFDMA0 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC00 interrupt setting */
    INTC2.ICDMA0.BIT.TBDMA0 = _INT_TABLE_VECTOR;
    INTC2.ICDMA0.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC00 global setting */
    DMAC.DM00CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC00 transfer setting */
    DMAC.DSA0 = _DMAC0_SOURCE_ADDRESS;
    DMAC.DDA0 = _DMAC0_DESTINATION_ADDRESS;
    DMAC.DTC0 = _DMAC0_ADDRESS_RELOAD_COUNT | _DMAC0_TRANSFER_COUNT;
    DMAC.DTCT0 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR0 = _DMAC_TRIGGER_SOURCE_40 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT0;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Start
* Description  : This function enable DMAC00 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Start(void)
{
    /* Clear DMAC00 request and enable operation */
    INTC2.ICDMA0.BIT.RFDMA0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA0.BIT.MKDMA0 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC00 operation */
    DMAC.DTFR0 = _DMAC_TRIGGER_SOURCE_40 |_DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN0 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Stop
* Description  : This function disable DMAC00 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Stop(void)
{
    /* Disable DMAC00 operation */
    DMAC.DTFR0 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN0 = _DMAC_CHANNEL_OPERATION_DISABLED;    
    /* Disable DMAC00 operation and clear request */
    INTC2.ICDMA0.BIT.MKDMA0 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA0.BIT.RFDMA0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN0;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Set_SoftwareTrigger
* Description  : This function set DMAC00 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Set_SoftwareTrigger(void)
{
    /* Set DMAC00 software trigger */
    DMAC.DCSTS0 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Suspend
* Description  : This function Suspends DMAC00 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Suspend(void)
{
    /* Enable DMAC00 operation */
    DMAC.DCEN0 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC00_Resume
* Description  : This function Resumes DMAC00 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC00_Resume(void)
{
    /* Disable DMAC00 operation */ 
    DMAC.DCEN0 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Create
* Description  : This function initializes DMAC01 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Create(void)
{
    /* Disable DMAC01 operation */
    DMAC.DCEN1 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC01 operation and clear request */
    INTC2.ICDMA1.BIT.MKDMA1 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA1.BIT.RFDMA1 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC01 interrupt setting */
    INTC2.ICDMA1.BIT.TBDMA1 = _INT_TABLE_VECTOR;
    INTC2.ICDMA1.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC01 global setting */
    DMAC.DM01CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC01 transfer setting */
    DMAC.DSA1 = _DMAC1_SOURCE_ADDRESS;
    DMAC.DDA1 = _DMAC1_DESTINATION_ADDRESS;
    DMAC.DTC1 = _DMAC1_ADDRESS_RELOAD_COUNT | _DMAC1_TRANSFER_COUNT;
    DMAC.DTCT1 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR1 = _DMAC_TRIGGER_SOURCE_96 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT1;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Start
* Description  : This function enable DMAC01 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Start(void)
{
    /* Clear DMAC01 request and enable operation */
    INTC2.ICDMA1.BIT.RFDMA1 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA1.BIT.MKDMA1 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC01 operation */
    DMAC.DTFR1 = _DMAC_TRIGGER_SOURCE_96 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN1 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Stop
* Description  : This function disable DMAC01 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Stop(void)
{
    /* Disable DMAC01 operation */
    DMAC.DTFR1 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN1 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC01 operation and clear request */
    INTC2.ICDMA1.BIT.MKDMA1 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA1.BIT.RFDMA1 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN1;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Set_SoftwareTrigger
* Description  : This function set DMAC01 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Set_SoftwareTrigger(void)
{
    /* Set DMAC01 software trigger */
    DMAC.DCSTS1 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Suspend
* Description  : This function Suspends DMAC01 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Suspend(void)
{
    /* Enable DMAC01 operation */
    DMAC.DCEN1 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC01_Resume
* Description  : This function Resumes DMAC01 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC01_Resume(void)
{
    /* Disable DMAC01 operation */ 
    DMAC.DCEN1 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Create
* Description  : This function initializes DMAC02 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Create(void)
{
    /* Disable DMAC02 operation */
    DMAC.DCEN2 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC02 operation and clear request */
    INTC2.ICDMA2.BIT.MKDMA2 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA2.BIT.RFDMA2 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC02 global setting */
    DMAC.DM02CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC02 transfer setting */
    DMAC.DSA2 = _DMAC2_SOURCE_ADDRESS;
    DMAC.DDA2 = _DMAC2_DESTINATION_ADDRESS;
    DMAC.DTC2 = _DMAC2_ADDRESS_RELOAD_COUNT | _DMAC2_TRANSFER_COUNT;
    DMAC.DTCT2 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_DISABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_FIXED | _DMAC_SOURCE_INCREMENT | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR2 = _DMAC_TRIGGER_SOURCE_50 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT2;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Start
* Description  : This function enable DMAC02 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Start(void)
{
    /* Enable DMAC02 operation */
    DMAC.DTFR2 = _DMAC_TRIGGER_SOURCE_50 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN2 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Stop
* Description  : This function disable DMAC02 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Stop(void)
{
    /* Disable DMAC02 operation */
    DMAC.DTFR2 =  _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN2 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN2;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Set_SoftwareTrigger
* Description  : This function set DMAC02 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Set_SoftwareTrigger(void)
{
    /* Set DMAC02 software trigger */
    DMAC.DCSTS2 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Suspend
* Description  : This function Suspends DMAC02 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Suspend(void)
{
    /* Enable DMAC02 operation */
    DMAC.DCEN2 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC02_Resume
* Description  : This function Resumes DMAC02 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC02_Resume(void)
{
    /* Disable DMAC02 operation */ 
    DMAC.DCEN2 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Create
* Description  : This function initializes DMAC03 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Create(void)
{
    /* Disable DMAC03 operation */
    DMAC.DCEN3 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC03 operation and clear request */
    INTC2.ICDMA3.BIT.MKDMA3 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA3.BIT.RFDMA3 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC03 global setting */
    DMAC.DM03CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC03 transfer setting */
    DMAC.DSA3 = _DMAC3_SOURCE_ADDRESS;
    DMAC.DDA3 = _DMAC3_DESTINATION_ADDRESS;
    DMAC.DTC3 = _DMAC3_ADDRESS_RELOAD_COUNT | _DMAC3_TRANSFER_COUNT;
    DMAC.DTCT3 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_DISABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_FIXED | _DMAC_SOURCE_INCREMENT | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR3 = _DMAC_TRIGGER_SOURCE_111 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT3;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Start
* Description  : This function enable DMAC03 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Start(void)
{
    /* Enable DMAC03 operation */
    DMAC.DTFR3 = _DMAC_TRIGGER_SOURCE_111 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN3 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Stop
* Description  : This function disable DMAC03 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Stop(void)
{
    /* Disable DMAC03 operation */
    DMAC.DTFR3 =  _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN3 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN3;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Set_SoftwareTrigger
* Description  : This function set DMAC03 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Set_SoftwareTrigger(void)
{
    /* Set DMAC03 software trigger */
    DMAC.DCSTS3 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Suspend
* Description  : This function Suspends DMAC03 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Suspend(void)
{
    /* Enable DMAC03 operation */
    DMAC.DCEN3 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC03_Resume
* Description  : This function Resumes DMAC03 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC03_Resume(void)
{
    /* Disable DMAC03 operation */ 
    DMAC.DCEN3 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Create
* Description  : This function initializes DMAC04 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Create(void)
{
    /* Disable DMAC04 operation */
    DMAC.DCEN4 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC04 operation and clear request */
    INTC2.ICDMA4.BIT.MKDMA4 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA4.BIT.RFDMA4 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC04 interrupt setting */
    INTC2.ICDMA4.BIT.TBDMA4 = _INT_TABLE_VECTOR;
    INTC2.ICDMA4.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC04 global setting */
    DMAC.DM04CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC04 transfer setting */
    DMAC.DSA4 = _DMAC4_SOURCE_ADDRESS;
    DMAC.DDA4 = _DMAC4_DESTINATION_ADDRESS;
    DMAC.DTC4 = _DMAC4_ADDRESS_RELOAD_COUNT | _DMAC4_TRANSFER_COUNT;
    DMAC.DTCT4 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR4 = _DMAC_TRIGGER_SOURCE_99 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT4;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Start
* Description  : This function enable DMAC04 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Start(void)
{
    /* Clear DMAC04 request and enable operation */
    INTC2.ICDMA4.BIT.RFDMA4 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA4.BIT.MKDMA4 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC04 operation */
    DMAC.DTFR4 = _DMAC_TRIGGER_SOURCE_99 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN4 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Stop
* Description  : This function disable DMAC04 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Stop(void)
{
    /* Disable DMAC04 operation */
    DMAC.DTFR4 =  _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN4 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC04 operation and clear request */
    INTC2.ICDMA4.BIT.MKDMA4 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA4.BIT.RFDMA4 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN4;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Set_SoftwareTrigger
* Description  : This function set DMAC04 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Set_SoftwareTrigger(void)
{
    /* Set DMAC04 software trigger */
    DMAC.DCSTS4 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Suspend
* Description  : This function Suspends DMAC04 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Suspend(void)
{
    /* Enable DMAC04 operation */
    DMAC.DCEN4 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC04_Resume
* Description  : This function Resumes DMAC04 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC04_Resume(void)
{
    /* Disable DMAC04 operation */ 
    DMAC.DCEN4 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Create
* Description  : This function initializes DMAC05 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Create(void)
{
    /* Disable DMAC05 operation */
    DMAC.DCEN5 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC05 operation and clear request */
    INTC2.ICDMA5.BIT.MKDMA5 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA5.BIT.RFDMA5 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC05 interrupt setting */
    INTC2.ICDMA5.BIT.TBDMA5 = _INT_TABLE_VECTOR;
    INTC2.ICDMA5.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC05 global setting */
    DMAC.DM05CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC05 transfer setting */
    DMAC.DSA5 = _DMAC5_SOURCE_ADDRESS;
    DMAC.DDA5 = _DMAC5_DESTINATION_ADDRESS;
    DMAC.DTC5 = _DMAC5_ADDRESS_RELOAD_COUNT | _DMAC5_TRANSFER_COUNT;
    DMAC.DTCT5 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR5 = _DMAC_TRIGGER_SOURCE_39 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT5;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Start
* Description  : This function enable DMAC05 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Start(void)
{
    /* Clear DMAC05 request and enable operation */
    INTC2.ICDMA5.BIT.RFDMA5 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA5.BIT.MKDMA5 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC05 operation */
    DMAC.DTFR5 = _DMAC_TRIGGER_SOURCE_39 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN5 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Stop
* Description  : This function disable DMAC05 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Stop(void)
{
    /* Disable DMAC05 operation */
    DMAC.DTFR5 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN5 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC05 operation and clear request */
    INTC2.ICDMA5.BIT.MKDMA5 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA5.BIT.RFDMA5 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN5;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Set_SoftwareTrigger
* Description  : This function set DMAC05 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Set_SoftwareTrigger(void)
{
    /* Set DMAC05 software trigger */
    DMAC.DCSTS5 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Suspend
* Description  : This function Suspends DMAC05 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Suspend(void)
{
    /* Enable DMAC05 operation */
    DMAC.DCEN5 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC05_Resume
* Description  : This function Resumes DMAC05 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC05_Resume(void)
{
    /* Disable DMAC05 operation */ 
    DMAC.DCEN5 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Create
* Description  : This function initializes DMAC06 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Create(void)
{
    /* Disable DMAC06 operation */
    DMAC.DCEN6 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC06 operation and clear request */
    INTC2.ICDMA6.BIT.MKDMA6 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA6.BIT.RFDMA6 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC06 interrupt setting */
    INTC2.ICDMA6.BIT.TBDMA6 = _INT_TABLE_VECTOR;
    INTC2.ICDMA6.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC06 global setting */
    DMAC.DM06CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC06 transfer setting */
    DMAC.DSA6 = _DMAC6_SOURCE_ADDRESS;
    DMAC.DDA6 = _DMAC6_DESTINATION_ADDRESS;
    DMAC.DTC6 = _DMAC6_ADDRESS_RELOAD_COUNT | _DMAC6_TRANSFER_COUNT;
    DMAC.DTCT6 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR6 = _DMAC_TRIGGER_SOURCE_95 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT6;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Start
* Description  : This function enable DMAC06 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Start(void)
{
    /* Clear DMAC06 request and enable operation */
    INTC2.ICDMA6.BIT.RFDMA6 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA6.BIT.MKDMA6 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC06 operation */
    DMAC.DTFR6 = _DMAC_TRIGGER_SOURCE_95 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN6 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Stop
* Description  : This function disable DMAC06 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Stop(void)
{
    /* Disable DMAC06 operation */
    DMAC.DTFR6 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN6 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC06 operation and clear request */
    INTC2.ICDMA6.BIT.MKDMA6 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA6.BIT.RFDMA6 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN6;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Set_SoftwareTrigger
* Description  : This function set DMAC06 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Set_SoftwareTrigger(void)
{
    /* Set DMAC06 software trigger */
    DMAC.DCSTS6 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Suspend
* Description  : This function Suspends DMAC06 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Suspend(void)
{
    /* Enable DMAC06 operation */
    DMAC.DCEN6 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC06_Resume
* Description  : This function Resumes DMAC06 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC06_Resume(void)
{
    /* Disable DMAC06 operation */ 
    DMAC.DCEN6 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Create
* Description  : This function initializes DMAC07 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Create(void)
{
    /* Disable DMAC07 operation */
    DMAC.DCEN7 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC07 operation and clear request */
    INTC2.ICDMA7.BIT.MKDMA7 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA7.BIT.RFDMA7 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC07 interrupt setting */
    INTC2.ICDMA7.BIT.TBDMA7 = _INT_TABLE_VECTOR;
    INTC2.ICDMA7.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC07 global setting */
    DMAC.DM07CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC07 transfer setting */
    DMAC.DSA7 = _DMAC7_SOURCE_ADDRESS;
    DMAC.DDA7 = _DMAC7_DESTINATION_ADDRESS;
    DMAC.DTC7 = _DMAC7_ADDRESS_RELOAD_COUNT | _DMAC7_TRANSFER_COUNT;
    DMAC.DTCT7 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR7 = _DMAC_TRIGGER_SOURCE_36 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT7;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Start
* Description  : This function enable DMAC07 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Start(void)
{
    /* Clear DMAC07 request and enable operation */
    INTC2.ICDMA7.BIT.RFDMA7 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA7.BIT.MKDMA7 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC07 operation */
    DMAC.DTFR7 = _DMAC_TRIGGER_SOURCE_36 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN7 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Stop
* Description  : This function disable DMAC07 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Stop(void)
{
    /* Disable DMAC07 operation */   
    DMAC.DTFR7 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN7 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC07 operation and clear request */
    INTC2.ICDMA7.BIT.MKDMA7 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA7.BIT.RFDMA7 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN7;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Set_SoftwareTrigger
* Description  : This function set DMAC07 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Set_SoftwareTrigger(void)
{
    /* Set DMAC07 software trigger */
    DMAC.DCSTS7 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Suspend
* Description  : This function Suspends DMAC07 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Suspend(void)
{
    /* Enable DMAC07 operation */
    DMAC.DCEN7 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC07_Resume
* Description  : This function Resumes DMAC07 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC07_Resume(void)
{
    /* Disable DMAC07 operation */ 
    DMAC.DCEN7 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC1_Create
* Description  : This function initializes the DMAC1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC1_Create(void)
{
    R_DMAC10_Create();
    R_DMAC11_Create();
    R_DMAC12_Create();
    R_DMAC13_Create();
    R_DMAC14_Create();
    R_DMAC15_Create();
    R_DMAC16_Create();
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Create
* Description  : This function initializes DMAC10 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Create(void)
{
    /* Disable DMAC10 operation */
    DMAC.DCEN8 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC10 operation and clear request */
    INTC2.ICDMA8.BIT.MKDMA8 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA8.BIT.RFDMA8 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC10 interrupt setting */
    INTC2.ICDMA8.BIT.TBDMA8 = _INT_TABLE_VECTOR;
    INTC2.ICDMA8.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC10 global setting */
    DMAC.DM10CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC10 transfer setting */
    DMAC.DSA8 = _DMAC8_SOURCE_ADDRESS;
    DMAC.DDA8 = _DMAC8_DESTINATION_ADDRESS;
    DMAC.DTC8 = _DMAC8_ADDRESS_RELOAD_COUNT | _DMAC8_TRANSFER_COUNT;
    DMAC.DTCT8 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR8 = _DMAC_TRIGGER_SOURCE_35 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT8;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Start
* Description  : This function enable DMAC10 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Start(void)
{
    /* Clear DMAC10 request and enable operation */
    INTC2.ICDMA8.BIT.RFDMA8 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA8.BIT.MKDMA8 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC10 operation */
    DMAC.DTFR8 = _DMAC_TRIGGER_SOURCE_35 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN8 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Stop
* Description  : This function disable DMAC10 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Stop(void)
{
    /* Disable DMAC10 operation */
    DMAC.DTFR8 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN8 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC10 operation and clear request */
    INTC2.ICDMA8.BIT.MKDMA8 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA8.BIT.RFDMA8 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN8;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Set_SoftwareTrigger
* Description  : This function set DMAC10 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Set_SoftwareTrigger(void)
{
    /* Set DMAC10 software trigger */
    DMAC.DCSTS8 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Suspend
* Description  : This function Suspends DMAC10 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Suspend(void)
{
    /* Enable DMAC10 operation */
    DMAC.DCEN8 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC10_Resume
* Description  : This function Resumes DMAC10 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC10_Resume(void)
{
    /* Disable DMAC10 operation */ 
    DMAC.DCEN8 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Create
* Description  : This function initializes DMAC11 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Create(void)
{
    /* Disable DMAC11 operation */
    DMAC.DCEN9 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC11 operation and clear request */
    INTC2.ICDMA9.BIT.MKDMA9 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA9.BIT.RFDMA9 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC11 global setting */
    DMAC.DM11CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC11 transfer setting */
    DMAC.DSA9 = _DMAC9_SOURCE_ADDRESS;
    DMAC.DDA9 = _DMAC9_DESTINATION_ADDRESS;
    DMAC.DTC9 = _DMAC9_ADDRESS_RELOAD_COUNT | _DMAC9_TRANSFER_COUNT;
    DMAC.DTCT9 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                 _DMAC_TRANSFER_COMPLETION_INTERRUPT_DISABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                 _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                 _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR9 = _DMAC_TRIGGER_SOURCE_51 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT9;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Start
* Description  : This function enable DMAC11 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Start(void)
{
    /* Enable DMAC11 operation */
    DMAC.DTFR9 = _DMAC_TRIGGER_SOURCE_51 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN9 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Stop
* Description  : This function disable DMAC11 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Stop(void)
{
    /* Disable DMAC11 operation */
    DMAC.DTFR9 =  _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN9 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN9;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Set_SoftwareTrigger
* Description  : This function set DMAC11 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Set_SoftwareTrigger(void)
{
    /* Set DMAC11 software trigger */
    DMAC.DCSTS9 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Suspend
* Description  : This function Suspends DMAC11 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Suspend(void)
{
    /* Enable DMAC11 operation */
    DMAC.DCEN9 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC11_Resume
* Description  : This function Resumes DMAC11 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC11_Resume(void)
{
    /* Disable DMAC11 operation */ 
    DMAC.DCEN9 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Create
* Description  : This function initializes DMAC12 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Create(void)
{
    /* Disable DMAC12 operation */
    DMAC.DCEN10 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC12 operation and clear request */
    INTC2.ICDMA10.BIT.MKDMA10 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA10.BIT.RFDMA10 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC12 interrupt setting */
    INTC2.ICDMA10.BIT.TBDMA10 = _INT_TABLE_VECTOR;
    INTC2.ICDMA10.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC12 global setting */
    DMAC.DM12CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC12 transfer setting */
    DMAC.DSA10 = _DMAC10_SOURCE_ADDRESS;
    DMAC.DDA10 = _DMAC10_DESTINATION_ADDRESS;
    DMAC.DTC10 = _DMAC10_ADDRESS_RELOAD_COUNT | _DMAC10_TRANSFER_COUNT;
    DMAC.DTCT10 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                  _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                  _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                  _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR10 = _DMAC_TRIGGER_SOURCE_33 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT10;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Start
* Description  : This function enable DMAC12 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Start(void)
{
    /* Clear DMAC12 request and enable operation */
    INTC2.ICDMA10.BIT.RFDMA10 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA10.BIT.MKDMA10 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC12 operation */
    DMAC.DTFR10 = _DMAC_TRIGGER_SOURCE_33 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN10 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Stop
* Description  : This function disable DMAC12 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Stop(void)
{
    /* Disable DMAC12 operation */
    DMAC.DTFR10 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN10 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC12 operation and clear request */
    INTC2.ICDMA10.BIT.MKDMA10 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA10.BIT.RFDMA10 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN10;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Set_SoftwareTrigger
* Description  : This function set DMAC12 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Set_SoftwareTrigger(void)
{
    /* Set DMAC12 software trigger */
    DMAC.DCSTS10 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Suspend
* Description  : This function Suspends DMAC12 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Suspend(void)
{
    /* Enable DMAC12 operation */
    DMAC.DCEN10 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC12_Resume
* Description  : This function Resumes DMAC12 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC12_Resume(void)
{
    /* Disable DMAC12 operation */ 
    DMAC.DCEN10 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Create
* Description  : This function initializes DMAC13 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Create(void)
{
    /* Disable DMAC13 operation */
    DMAC.DCEN11 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC13 operation and clear request */
    INTC2.ICDMA11.BIT.MKDMA11 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA11.BIT.RFDMA11 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC13 interrupt setting */
    INTC2.ICDMA11.BIT.TBDMA11 = _INT_TABLE_VECTOR;
    INTC2.ICDMA11.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC13 global setting */
    DMAC.DM13CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC13 transfer setting */
    DMAC.DSA11 = _DMAC11_SOURCE_ADDRESS;
    DMAC.DDA11 = _DMAC11_DESTINATION_ADDRESS;
    DMAC.DTC11 = _DMAC11_ADDRESS_RELOAD_COUNT | _DMAC11_TRANSFER_COUNT;
    DMAC.DTCT11 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                  _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                  _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                  _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR11 = _DMAC_TRIGGER_SOURCE_94 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT11;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Start
* Description  : This function enable DMAC13 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Start(void)
{
    /* Clear DMAC13 request and enable operation */
    INTC2.ICDMA11.BIT.RFDMA11 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA11.BIT.MKDMA11 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC13 operation */
    DMAC.DTFR11 = _DMAC_TRIGGER_SOURCE_94 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN11 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Stop
* Description  : This function disable DMAC13 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Stop(void)
{
    /* Disable DMAC13 operation */
    DMAC.DTFR11 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN11 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC13 operation and clear request */
    INTC2.ICDMA11.BIT.MKDMA11 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA11.BIT.RFDMA11 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN11;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Set_SoftwareTrigger
* Description  : This function set DMAC13 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Set_SoftwareTrigger(void)
{
    /* Set DMAC13 software trigger */
    DMAC.DCSTS11 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Suspend
* Description  : This function Suspends DMAC13 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Suspend(void)
{
    /* Enable DMAC13 operation */
    DMAC.DCEN11 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC13_Resume
* Description  : This function Resumes DMAC13 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC13_Resume(void)
{
    /* Disable DMAC13 operation */ 
    DMAC.DCEN11 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Create
* Description  : This function initializes DMAC14 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Create(void)
{
    /* Disable DMAC14 operation */
    DMAC.DCEN12 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC14 operation and clear request */
    INTC2.ICDMA12.BIT.MKDMA12 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA12.BIT.RFDMA12 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC14 interrupt setting */
    INTC2.ICDMA12.BIT.TBDMA12 = _INT_TABLE_VECTOR;
    INTC2.ICDMA12.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC14 global setting */
    DMAC.DM14CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC14 transfer setting */
    DMAC.DSA12 = _DMAC12_SOURCE_ADDRESS;
    DMAC.DDA12 = _DMAC12_DESTINATION_ADDRESS;
    DMAC.DTC12 = _DMAC12_ADDRESS_RELOAD_COUNT | _DMAC12_TRANSFER_COUNT;
    DMAC.DTCT12 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                  _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                  _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                  _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR12 = _DMAC_TRIGGER_SOURCE_97 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT12;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Start
* Description  : This function enable DMAC14 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Start(void)
{
    /* Clear DMAC14 request and enable operation */
    INTC2.ICDMA12.BIT.RFDMA12 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA12.BIT.MKDMA12 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC14 operation */
    DMAC.DTFR12 = _DMAC_TRIGGER_SOURCE_97 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN12 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Stop
* Description  : This function disable DMAC14 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Stop(void)
{
    /* Disable DMAC14 operation */
    DMAC.DTFR12 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN12 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC14 operation and clear request */
    INTC2.ICDMA12.BIT.MKDMA12 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA12.BIT.RFDMA12 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN12;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Set_SoftwareTrigger
* Description  : This function set DMAC14 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Set_SoftwareTrigger(void)
{
    /* Set DMAC14 software trigger */
    DMAC.DCSTS12 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Suspend
* Description  : This function Suspends DMAC14 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Suspend(void)
{
    /* Enable DMAC14 operation */
    DMAC.DCEN12 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC14_Resume
* Description  : This function Resumes DMAC14 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC14_Resume(void)
{
    /* Disable DMAC14 operation */ 
    DMAC.DCEN12 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Create
* Description  : This function initializes DMAC15 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Create(void)
{
    /* Disable DMAC15 operation */
    DMAC.DCEN13 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC15 operation and clear request */
    INTC2.ICDMA13.BIT.MKDMA13 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA13.BIT.RFDMA13 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC15 interrupt setting */
    INTC2.ICDMA13.BIT.TBDMA13 = _INT_TABLE_VECTOR;
    INTC2.ICDMA13.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC15 global setting */
    DMAC.DM15CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC15 transfer setting */
    DMAC.DSA13 = _DMAC13_SOURCE_ADDRESS;
    DMAC.DDA13 = _DMAC13_DESTINATION_ADDRESS;
    DMAC.DTC13 = _DMAC13_ADDRESS_RELOAD_COUNT | _DMAC13_TRANSFER_COUNT;
    DMAC.DTCT13 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                  _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                  _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                  _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR13 = _DMAC_TRIGGER_SOURCE_98 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT13;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Start
* Description  : This function enable DMAC15 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Start(void)
{
    /* Clear DMAC15 request and enable operation */
    INTC2.ICDMA13.BIT.RFDMA13 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA13.BIT.MKDMA13 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC15 operation */
    DMAC.DTFR13 = _DMAC_TRIGGER_SOURCE_98 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN13 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Stop
* Description  : This function disable DMAC15 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Stop(void)
{
    /* Disable DMAC15 operation */
    DMAC.DTFR13 =  _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN13 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC15 operation and clear request */
    INTC2.ICDMA13.BIT.MKDMA13 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA13.BIT.RFDMA13 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN13;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Set_SoftwareTrigger
* Description  : This function set DMAC15 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Set_SoftwareTrigger(void)
{
    /* Set DMAC15 software trigger */
    DMAC.DCSTS13 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Suspend
* Description  : This function Suspends DMAC15 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Suspend(void)
{
    /* Enable DMAC15 operation */
    DMAC.DCEN13 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC15_Resume
* Description  : This function Resumes DMAC15 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC15_Resume(void)
{
    /* Disable DMAC15 operation */ 
    DMAC.DCEN13 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Create
* Description  : This function initializes DMAC16 channel.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Create(void)
{
    /* Disable DMAC16 operation */
    DMAC.DCEN14 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC16 operation and clear request */
    INTC2.ICDMA14.BIT.MKDMA14 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA14.BIT.RFDMA14 = _INT_REQUEST_NOT_OCCUR;
    /* Set DMAC16 interrupt setting */
    INTC2.ICDMA14.BIT.TBDMA14 = _INT_TABLE_VECTOR;
    INTC2.ICDMA14.UINT16 &= _INT_PRIORITY_LEVEL2;
    /* Set DMAC16 global setting */
    DMAC.DM16CM = _DMAC_PE1_SETTING | _DMAC_SPID1_SETTING | _DMAC_SUPERVISON_MODE;
    /* Set DMAC16 transfer setting */
    DMAC.DSA14 = _DMAC14_SOURCE_ADDRESS;
    DMAC.DDA14 = _DMAC14_DESTINATION_ADDRESS;
    DMAC.DTC14 = _DMAC14_ADDRESS_RELOAD_COUNT | _DMAC14_TRANSFER_COUNT;
    DMAC.DTCT14 = _DMAC_CYCLES_EXECUTED | _DMAC_TRANSFER_HARDWARE | _DMAC_CHAIN_DISABLE | 
                  _DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | _DMAC_CONTINUOUS_TRANSFER_DISABLE | 
                  _DMAC_RELOAD2_DISABLE | _DMAC_RELOAD1_DISABLE | _DMAC_DESTINATION_INCREMENT | _DMAC_SOURCE_FIXED | 
                  _DMAC_TRANSFER_DATA_16BITS | _DMAC_SINGLE_TRANSFER;
    //DMAC.DTFR14 = _DMAC_TRIGGER_SOURCE_34 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DTCT14;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Start
* Description  : This function enable DMAC16 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Start(void)
{
    /* Clear DMAC16 request and enable operation */
    INTC2.ICDMA14.BIT.RFDMA14 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICDMA14.BIT.MKDMA14 = _INT_PROCESSING_ENABLED;    
    /* Enable DMAC16 operation */
    DMAC.DTFR14 = _DMAC_TRIGGER_SOURCE_34 | _DMAC_HARDWARE_TRIGGER_ENABLE;
    DMAC.DCEN14 = _DMAC_CHANNEL_OPERATION_ENABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Stop
* Description  : This function disable DMAC16 activation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Stop(void)
{
    /* Disable DMAC16 operation */
    DMAC.DTFR14 = _DMAC_HARDWARE_TRIGGER_DISABLE;
    DMAC.DCEN14 = _DMAC_CHANNEL_OPERATION_DISABLED;
    /* Disable DMAC16 operation and clear request */
    INTC2.ICDMA14.BIT.MKDMA14 = _INT_PROCESSING_DISABLED;
    INTC2.ICDMA14.BIT.RFDMA14 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = DMAC.DCEN14;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Set_SoftwareTrigger
* Description  : This function set DMAC16 software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Set_SoftwareTrigger(void)
{
    /* Set DMAC16 software trigger */
    DMAC.DCSTS14 = _DMAC_SET_REQUEST_FLAG;
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Suspend
* Description  : This function Suspends DMAC16 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Suspend(void)
{
    /* Enable DMAC16 operation */
    DMAC.DCEN14 = _DMAC_CHANNEL_OPERATION_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_DMAC16_Resume
* Description  : This function Resumes DMAC16 channel operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DMAC16_Resume(void)
{
    /* Disable DMAC16 operation */ 
    DMAC.DCEN14 = _DMAC_CHANNEL_OPERATION_ENABLED;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
