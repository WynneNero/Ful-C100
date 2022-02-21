/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :	PEGuard and DMA
* Instance      :
* Description   :	
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date        Name               Changes and comments
*    0.1	  2017-10-23	RenWeimin		Init version
*=====================================================================*/
#include "Iodefine.h"
#include "CSI_dma_if.h"
#include "Cpu.h"

extern void Uart1_RxIsr_DMA_callback(void);

/* Register Address used */
#define  CSIH0TX0H_ADDR    ((CPU_REG32)(0xffd8100c))
#define  CSIH0RX0H_ADDR    ((CPU_REG32)(0xffd81014)) 

#define RLIN33UR0_ADDR 	   ((CPU_REG32)(&RLN33LUTDR))
#define RLIN32UR1_ADDR 		 ((CPU_REG32)(&RLN32LURDR))
#define RLIN32UR0_ADDR     ((CPU_REG32)(&RLN32LUTDR))
#define RLIN33UR1_ADDR     ((CPU_REG32)(&RLN33LURDR))

#define RLIN34UR0_ADDR     ((CPU_REG32)(&RLN34LUTDR))
#define RLIN34UR1_ADDR     ((CPU_REG32)(&RLN34LURDR))

#define UART4_TX_DMA 2
#define UART4_RX_DMA 9

#define TAUB0I_15_ADDR  ((CPU_REG32)(&TAUB0CDR15))
#define TAUB0I_8_ADDR  ((CPU_REG32)(&TAUB0CDR8))
#define TAUB0I_14_ADDR  ((CPU_REG32)(&TAUB0CDR14))
#define TAUB0I_13_ADDR  ((CPU_REG32)(&TAUB0CDR13))
#define TAUB0I_7_ADDR  ((CPU_REG32)(&TAUB0CDR7))
#define TAUB0I_6_ADDR  ((CPU_REG32)(&TAUB0CDR6))
#define TAUB0I_4_ADDR  ((CPU_REG32)(&TAUB0CDR4))
#define TAUB0I_0_ADDR  ((CPU_REG32)(&TAUB0CDR0))
#define TAUB0I_5_ADDR  ((CPU_REG32)(&TAUB0CDR5))
#define TAUB0I_10_ADDR  ((CPU_REG32)(&TAUB0CDR10))
#define TAUB0I_12_ADDR  ((CPU_REG32)(&TAUB0CDR12))
#define TAUB0I_2_ADDR  ((CPU_REG32)(&TAUB0CDR2))
//const U32 DMAChannel_Cfg[DMA_MAX][3] =
//{ /* DSA: sourde data addr,      DDA:destination data addr,  DMA trigger ID */
// {0,        (U32)CSIH0TX0H_ADDR,  70},  /*DMA0 -CSIH0TX */
// {0,        (U32)RLIN33UR0_ADDR, 111},  /*DMA1 */  // {0,        0,  0},  /*DMA1 */  
// {0,        (U32)RLIN32UR0_ADDR, 44},  /* UART2 TX */
// {0,        0,  0},  /*DMA3 */
// {0,        0,  0},  /*DMA4 */
// {0,        0,  0},  /*DMA5 */
// {0,        0,  0},  /*DMA6 */
// {0,        0,  0},  /*DMA7 */
// {(U32)CSIH0RX0H_ADDR,        0,  71},  /*DMA8 -CSIH0RX */
// {(U32)RLIN32UR1_ADDR,       0,  45},  /*UART2 RX */  /*DMA9 */
// {0,        0,  0},  /*DMA10 */
// {0,        0,  0},  /*DMA11 */
// {0,        0,  0},  /*DMA12 */
// {0,        0,  0},  /*DMA13 */
// {0,        0,  0},  /*DMA14 */
// {0,        0,  0}   /*DMA15 */
//};

const U32 DMAChannel_Cfg[DMA_MAX][3] =
{ /* DSA: sourde data addr,      DDA:destination data addr,  DMA trigger ID */
 {TAUB0I_15_ADDR,        0,  40},  /*DMA0  */
 {TAUB0I_8_ADDR,        0,  96},  /*DMA1 */  // {0,        0,  0},  /*DMA1 */  
 {0,        (U32)RLIN34UR0_ADDR, 50},  /* UART4 TX  DMA2*/
 {0,       (U32)RLIN33UR0_ADDR,  111},  /*DMA3 */
 {TAUB0I_14_ADDR,        0,  99},  /*DMA4 */
 {TAUB0I_13_ADDR,        0,  39},  /*DMA5 */
 {TAUB0I_7_ADDR,        0,  95},  /*DMA6 */
 {TAUB0I_6_ADDR,        0,  36},  /*DMA7 */
 {TAUB0I_4_ADDR,        0,  35},  /*DMA8 -CSIH0RX */
 {(U32)RLIN34UR1_ADDR, 0, 51},  /*UART4 RX */  /*DMA9 */
 {TAUB0I_0_ADDR,        0,  33},  /*DMA10 */
 {TAUB0I_5_ADDR,        0,  94},  /*DMA11 */
 {TAUB0I_10_ADDR,        0,  97},  /*DMA12 */
 {TAUB0I_12_ADDR,        0,  98},  /*DMA13 */
 {TAUB0I_2_ADDR,        0,  34},  /*DMA14 */
 {0,        0,  0}   /*DMA15 */
};

//extern void SocDriver_RxIsr_DMA_callback(void);
//extern void SocDriver_TxIsr_DMA_callback(void);
//extern void Uart3_TxIsr_DMA_callback(void);
//extern void Uart2_RxIsr_DMA_callback(void);
//extern void Uart2_TxIsr_DMA_callback(void);
//extern void Uart3_RxIsr_DMA_callback(void);


const Func_Void_Proc DMA_Isr_callback[DMA_MAX]=
{
  NULL,//SocDriver_RxIsr_DMA_callback,
  NULL,//Uart3_TxIsr_DMA_callback,
  NULL,//Uart2_TxIsr_DMA_callback,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
 NULL,// SocDriver_TxIsr_DMA_callback, 
  NULL,//Uart2_RxIsr_DMA_callback,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};




