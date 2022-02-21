/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW2      									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        : 
* Module        : 
* Instance      : 
* Description   : 
*-----------------------------------------------------------------------
* Version: 
* Date: 
* Author: 
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* 
*=====================================================================*/

/**** System include files ****/
#include "config.h"
#include "Define.h"
#include "SYS_ASSERT_IF.H"

/*---Public include files---------------------------------------------*/
#include "FIFO_IF.H"
#include "Startup.H"
#include "Mcu_if.h"

/*---Private include files--------------------------------------------*/
#include "DebugUartDriver_if.h"
#include "DebugUartDriver.h"   
#include "xprintf.h"
#include "Uart_if.h"
#include "uart.h"

#include "csi_Dma_if.h"
#include "CSI_dma.h"
#include "ComplexDrvier_Globaldef_IF.H"
#include "fifo_if.h"
#include "sw_Timer.h"

/**** Definition of constants ****/
#define UART_DEBUG            UART_3

#define DEBUG_UART_TX_DMA DMA_3

#define DEBUG_UART_DRIVER_OUT_BUF_SIZE 512      /* Output buffer size */
#define DEBUG_UART_OUT_BUFF_SIZE 52
#define UART_TX_DEBUG_PORT  11
#define UART_TX_DEBUG_PIN	5

typedef struct
{
  BOOL openFlag;
  U8 powerStatus;
}debugUartDrvCtrlType;
static debugUartDrvCtrlType m_debugUartDrvCtrl;
#if XPRINTF_ENABLE
static U8 Debug_uart_driver_out_buff[DEBUG_UART_DRIVER_OUT_BUF_SIZE];
static U8 DebugUartDmaOutBuf[DEBUG_UART_OUT_BUFF_SIZE];
static volatile U8 Debug_Uart_Send_End_Flag = 1;
static FIFO_TYPE Debug_uart_driver_out_fifo;
#endif
static void debugUartVarInit(void);
static void debugUartInit(void);
static void debugUartDeInit(void);
static void Debug_uart_send_polling(void);

static void debugPrintfCb(void *p)
{
	static U8 i = 0;
	xprintf("now:%d\n",i++);
}

U8 debugUartDrvOpen(void)
{
#if XPRINTF_ENABLE
  debugUartVarInit();
  debugUartInit();
  m_debugUartDrvCtrl.openFlag = TRUE;
  m_debugUartDrvCtrl.powerStatus = DEV_ON;
  
  SwTmrMgr_Start(DEBUG_TEST_TMR,1000, debugPrintfCb, NULL,1); // for test.
 #endif
  return DEV_ON;
}
U8 debugUartDrvClose(void)
{
#if XPRINTF_ENABLE
  m_debugUartDrvCtrl.openFlag = FALSE;
  m_debugUartDrvCtrl.powerStatus = DEV_OFF;
  debugUartDeInit();
#endif
  return DEV_OFF;
}
U16 debugUartDrvRead(U8 *buff,U16 Len)
{
	return 0;
}
U8 debugUartDrvWrite(U8 *buff,U16 Len)
{
#if XPRINTF_ENABLE
    if(1 == Len)
    {
      fifo_input_byte(&Debug_uart_driver_out_fifo, buff[0]);
    }
    else if(Len> 1)
    {
      fifo_input_block(&Debug_uart_driver_out_fifo, buff,Len);
    }
    else
    {

    }
#endif
  return 0;
}
U8 debugUartDrvIoControl(U8 type,void *buff)
{
	return 0;
}
U8 debugUartDrvPowerControl(U8 type)
{
#if XPRINTF_ENABLE
  switch(type)
  {
    case DEV_OP_PWR_ON:
      debugUartDrvOpen();
      break;
      
    case DEV_OP_PWR_WAKEUP:
      debugUartInit();
      Debug_Uart_Send_End_Flag = 1;
      m_debugUartDrvCtrl.powerStatus = DEV_ON;
      break;
        
    case DEV_OP_PWR_SLEEP:
      debugUartDeInit();
      m_debugUartDrvCtrl.powerStatus = DEV_SLEEP;
      break;
      
    case DEV_OP_PWR_OFF:
      debugUartDrvClose();
      break;
      
    default:
      break;
   }
   return m_debugUartDrvCtrl.powerStatus;
 #endif
}
U8 debugUartDrvPowerStatus(void)
{
	return 0;
}

void debugUartDrvTask(void)
{
#if XPRINTF_ENABLE    
  if(m_debugUartDrvCtrl.openFlag)
  {
    Debug_uart_send_polling();
  }
  else
  {

  }
#endif  
}

///////////////////////////
#if XPRINTF_ENABLE
static void debugUartVarInit(void)
{
  //init fifo 
  fifo_init(&Debug_uart_driver_out_fifo, Debug_uart_driver_out_buff, DEBUG_UART_DRIVER_OUT_BUF_SIZE);
  Debug_Uart_Send_End_Flag = 1;
}
static void debugUartInit(void)
{
  GPIO_SetAlterMode(UART_TX_DEBUG_PORT,UART_TX_DEBUG_PIN,E_ALTERFUNC_1,E_HIGH_40MHZ);

  //UART_Start(UART_DEBUG,115200);  
  UART_DMA_Start(UART_DEBUG,115200);  
  DMA_Init_UartTx(DEBUG_UART_TX_DMA);//Add DMA Init
}
static void debugUartDeInit(void)
{
  DMA_Stop(DEBUG_UART_TX_DMA);
  DMA_Deinit(DEBUG_UART_TX_DMA);
  UART_Stop(UART_DEBUG);

  GPIO_SetInputMode(UART_TX_DEBUG_PORT,UART_TX_DEBUG_PIN,E_INPUT_HIZ);
}


static void Debug_uart_send_polling(void)
{
    U16 waitLen = 0;
    U32 DMASendComplete = 0;
    if(DEV_ON == m_debugUartDrvCtrl.powerStatus)
    {
      waitLen = fifo_current_length(&Debug_uart_driver_out_fifo);
      
      DMASendComplete = DMA_REG_DCSTm(DEBUG_UART_TX_DMA)&0x00000010; // 刚初始化完成不为1
      if(DMASendComplete)
      {
        Debug_Uart_Send_End_Flag = 1;
      }
      if(Debug_Uart_Send_End_Flag && waitLen)
      {
        Debug_Uart_Send_End_Flag = 0;
        if(waitLen > DEBUG_UART_OUT_BUFF_SIZE)
        {
            waitLen = DEBUG_UART_OUT_BUFF_SIZE;
        }
        fifo_output_block( &Debug_uart_driver_out_fifo, DebugUartDmaOutBuf,waitLen) ;
        //UartDma_trigger_sending(UART_DEBUG,DEBUG_UART_TX_DMA,DebugUartDmaOutBuf,waitLen);
		if(waitLen > 1)
	{
	   DMA_Config_SpiTx(DEBUG_UART_TX_DMA, (U32)(&DebugUartDmaOutBuf[1]), waitLen-1);		
	   DMA_Start(DEBUG_UART_TX_DMA); 
	   UART_REG_RLN3nLUTDR(GetUartBaseAddress(UART_DEBUG)) =  DebugUartDmaOutBuf[0];
	}
	else
	{
        UART_REG_RLN3nLUTDR(GetUartBaseAddress(UART_DEBUG)) =  DebugUartDmaOutBuf[0];
	}
  	  }
	}
}
#endif


/**************** END OF FILE *****************************************/


