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
* File Name    : r_cg_uart.c
* Version      : Applilet4 for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701583(LQFP144pin)
* Tool-Chain   : GHSRH
* Description  : This file implements device driver for UART module.
* Creation Date: 2020-6-17
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
#include "r_cg_uart.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
volatile uint8_t  * gp_uart3_tx_address;       /* uart3 transmit data address */
volatile uint16_t   g_uart3_tx_count;          /* uart3 transmit data number */
volatile uint8_t  * gp_uart3_rx_address;       /* uart3 receive data address */
volatile uint16_t   g_uart3_rx_count;          /* uart3 receive data number */
volatile uint16_t   g_uart3_rx_length;         /* uart3 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_UART3_Create
* Description  : This function initializes the UART3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Create(void)
{
    /* Set LIN reset mode */
    RLN33.LCUC = _UART_LIN_RESET_MODE_CAUSED;
    /* Disable ICRLIN33UR0 operation and clear request */
    INTC2.ICRLIN33UR0.BIT.MKRLIN33UR0 = _INT_PROCESSING_DISABLED;
    INTC2.ICRLIN33UR0.BIT.RFRLIN33UR0 = _INT_REQUEST_NOT_OCCUR;
    /* Set ICRLIN33UR0 table method */
    INTC2.ICRLIN33UR0.BIT.TBRLIN33UR0 = _INT_TABLE_VECTOR;
    /* Set ICRLIN33UR0 priority */
    INTC2.ICRLIN33UR0.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set UART3 setting */
    RLN33.LWBR = _UART_7_SAMPLING | _UART_PRESCALER_CLOCK_SELECT_2;
    RLN33.LBRP01.UINT16 = _UART3_BAUD_RATE_PRESCALER;
    RLN33.LMD = _UART_MODE_SELECT;
    RLN33.LEDE = _UART_FRAMING_ERROR_DETECTED | _UART_OVERRUN_ERROR_DETECTED | _UART_BIT_ERROR_DETECTED;
    RLN33.LBFC = _UART_TRANSMISSION_NORMAL | _UART_PARITY_PROHIBITED | _UART_STOP_BIT_1 | _UART_LSB | _UART_LENGTH_8;
    RLN33.LCUC = _UART_LIN_RESET_MODE_CANCELED;
    /* Synchronization processing */
    g_cg_sync_read = RLN33.LCUC;
    __syncp();
    /* Set RLIN33TX pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT5;
    PORT.PBDC11 &= _PORT_CLEAR_BIT5;
    PORT.PM11 |= _PORT_SET_BIT5;  
    PORT.PMC11 &= _PORT_CLEAR_BIT5;
    PORT.PFC11 &= _PORT_CLEAR_BIT5;
    PORT.PFCE11 &= _PORT_CLEAR_BIT5;
    PORT.PFCAE11 &= _PORT_CLEAR_BIT5;
    PORT.PMC11 |= _PORT_SET_BIT5;  
    PORT.PM11 &= _PORT_CLEAR_BIT5;
}
/***********************************************************************************************************************
* Function Name: R_UART3_Start
* Description  : This function starts the UART3 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Start(void)
{
    /* Enable UART3 operation */
    RLN33.LUOER |= _UART_TRABSMISSION_ENABLED;
    /* Clear ICRLIN33UR0 request and enable operation */
    INTC2.ICRLIN33UR0.BIT.RFRLIN33UR0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICRLIN33UR0.BIT.MKRLIN33UR0 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_UART3_Stop
* Description  : This function stops the UART3 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Stop(void)
{
    /* Disable ICRLIN33UR0 operation */
    INTC2.ICRLIN33UR0.BIT.MKRLIN33UR0 = _INT_PROCESSING_DISABLED;
    /* Disable UART3 operation */
    RLN33.LUOER &= (uint8_t) ~_UART_TRABSMISSION_ENABLED;
    /* Synchronization processing */
    g_cg_sync_read = RLN33.LCUC;
    __syncp(); 
    /* Clear ICRLIN33UR0 request */
    INTC2.ICRLIN33UR0.BIT.RFRLIN33UR0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = RLN33.LCUC;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_UART3_Send
* Description  : This function sends UART3 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR or MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_UART3_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart3_tx_address = tx_buf;
        g_uart3_tx_count = tx_num;       

        if ((RLN33.LST & _UART_TRANSMISSION_OPERATED) == 0U)
        {
            /* Clear ICRLIN33UR0 request and Disable operation */
            INTC2.ICRLIN33UR0.BIT.MKRLIN33UR0 = _INT_PROCESSING_DISABLED;
            INTC2.ICRLIN33UR0.BIT.RFRLIN33UR0 = _INT_REQUEST_NOT_OCCUR;
            RLN33.LUTDR.UINT16 = *gp_uart3_tx_address;
            gp_uart3_tx_address++;
            g_uart3_tx_count--;
            /* Clear ICRLIN33UR0 requestt and enable operation */
            INTC2.ICRLIN33UR0.BIT.RFRLIN33UR0 = _INT_REQUEST_NOT_OCCUR;
            INTC2.ICRLIN33UR0.BIT.MKRLIN33UR0 = _INT_PROCESSING_ENABLED;	
        }
        else
        {
            status = MD_ERROR;
        }
    }
    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
