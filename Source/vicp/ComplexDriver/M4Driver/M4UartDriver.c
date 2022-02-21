/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:1.0
* Date: 2017/10/11
* Author: TanPeng
*=====================================================================*/

#include "M4UartDriver.h"
#include "irq_if.h"
#include "tools.h"
#include "Uart_if.h"
#include "Driver_if.h"
#include "Uart_if.h"
#include "Uart.h"
#include "CSI_dma_if.h"
#include "CSI_dma.h"
#include "ComplexDrvier_Globaldef_IF.h" 
#include "FIFO_IF.H"
#include "config.h"

#define M4_UART  UART_4
#define UART4_TX_DMA 2
#define UART4_RX_DMA 9

#define APP_CMD_HEAD					0xA55A
#define PHY_UART_HEAD_SIZE  4
#define SYNC_HEAD_SIZE 3
#define NOT_USER_DATA_SIZE 1//2

#define	USART4_TX_FIFO_SIZE		  512
#define	USART4_RX_FIFO_SIZE		  512
#define	USART4_TX_DMA_BUF_SIZE  52
#define	USART4_RX_DMA_BUF_SIZE	512
#define	USART4_Pack_MinLen					7
#define	USART4_Pack_MaxLen					200

typedef struct
{
  BOOL openFlag;
  U8 USART2_Sendcont;
  U8 DMA_Rx_First_Flag;
  U16 Last_DMA_Rx_count;
  U8 SOC_Uart_Send_End_Flag;
}socUartDrvCtrlType;
static socUartDrvCtrlType m_socUartDrvCtrl;

static  U8 Dma_Write_buffer[USART4_RX_DMA_BUF_SIZE];
static  U8 Dma_Read_buffer[USART4_RX_DMA_BUF_SIZE];
static  U8 soc_uart_driver_in_buff[USART4_RX_FIFO_SIZE];
static  U8 soc_uart_driver_out_buff[USART4_TX_FIFO_SIZE];
U8 DMA_Rx_First_Flag = 0;
U16 Last_DMA_Rx_count;
FIFO_TYPE soc_uart_comm_in_fifo,soc_uart_comm_out_fifo;

static U8 GetSocToMcuData( U8 *pdata );
static void Get_DMA_UART4_Rx_Handle(void);
static void Get_DMA_UART4_Tx_Handle(void);



void M4UartDriver_5ms_Entry()
{
	if(m_socUartDrvCtrl.openFlag)
	{
	  Get_DMA_UART4_Rx_Handle();  
	  Get_DMA_UART4_Tx_Handle();  
	}

}
U8 M4UartDriver_Open(void)
{
	UART4_RX_ALT();
	UART4_TX_ALT();
	DMA_Rx_First_Flag =0;
    fifo_init(&soc_uart_comm_out_fifo, soc_uart_driver_out_buff, USART4_TX_FIFO_SIZE);
    fifo_init(&soc_uart_comm_in_fifo, soc_uart_driver_in_buff, USART4_RX_FIFO_SIZE);
	
    UART_DMA_Start(M4_UART,UART_BAUDRATE_115200);//,UARTE_LENGTH_8|UARTE_PARITY_NONE|UARTE_STOPLENGTH_1BIT|UARTE_TRANSFDIR_LSB,DFILTERTYPE_BYPASS);
    DMA_Init_UartTx_No_Int(UART4_TX_DMA);//Add DMA Init 	
    DMA_Init_UartRx(DMA_9);
  	DMA_Config_SpiRx(DMA_9,(U32)Dma_Read_buffer,USART4_RX_DMA_BUF_SIZE);
  	DMA_Config_SpiReloadRx(DMA_9,(U32)Dma_Read_buffer,USART4_RX_DMA_BUF_SIZE);
    DMA_Start(DMA_9);

	m_socUartDrvCtrl.SOC_Uart_Send_End_Flag = 1;
	m_socUartDrvCtrl.DMA_Rx_First_Flag = 0;
	m_socUartDrvCtrl.openFlag = TRUE;
	
    return 0;
}

U8 M4UartDriver_Close(void)
{
    UART_Stop(M4_UART);
	m_socUartDrvCtrl.SOC_Uart_Send_End_Flag = 1;
	m_socUartDrvCtrl.DMA_Rx_First_Flag = 0;
	m_socUartDrvCtrl.openFlag = FALSE;
    return 0;
}
U8 M4UartDriver_Read( U8* buffer, U16 Len)
{
    return (1 == GetSocToMcuData(buffer));
}

U8 M4UartDriver_Control(U8 type, void* buffer)
{
    return 0;
}

U8 M4UartDriver_Write( U8* buffer, U16 Len)
{
	U8 j = 0;
    BOOL bRet = TRUE;
	U8 CheckSum=0x00;
	U16 dataIndex = 0;
	U8 uartTxHeadBuff[PHY_UART_HEAD_SIZE];
    if(m_socUartDrvCtrl.openFlag)
    {
    	uartTxHeadBuff[dataIndex++]=(0xFF);
    	uartTxHeadBuff[dataIndex++]=(0xA5);
    	uartTxHeadBuff[dataIndex++]=(0x5A);
      
    	uartTxHeadBuff[dataIndex++]= Len+2;		//֡����	
    	fifo_input_block(&soc_uart_comm_out_fifo,&(uartTxHeadBuff[0]),PHY_UART_HEAD_SIZE);//�����

    	fifo_input_block(&soc_uart_comm_out_fifo,buffer,Len);//�����

    	// m_socUartDrvCtrl.USART2_Sendcont ���������������ȡ���У��
    	CheckSum = Len+2;
        for(j=0; j<Len; j++)
    	{
    		CheckSum ^= *(buffer+j);
    	}
        //CheckSum ^= m_socUartDrvCtrl.USART2_Sendcont;
        bRet = fifo_input_block(&soc_uart_comm_out_fifo,&CheckSum,1);//�����
    }
	 return bRet;

}



static U8 GetSocToMcuData( U8 *pdata )
  {
           BOOL isFindFlag = FALSE;
           U8 ret = 0;
           U16 Length = 0;
           U16 tmpHead = 0;
           U16 i = 0;
           U16 ChkSum = 0;
           U16 MCU_RxDataCnt = 0;
           MCU_RxDataCnt= fifo_current_length(&soc_uart_comm_in_fifo); 
  
           while( MCU_RxDataCnt >= USART4_Pack_MinLen)
           {                 
                     tmpHead = soc_uart_comm_in_fifo.mFIFOHead;
                     if(0xFF == soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead])
                     {
                              tmpHead++;
                              if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize)                           
                              {
                                tmpHead =0;
                              }                 
                              if(0xA5 == soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead])
                              {
                                       tmpHead++;
                                       if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize)                           
                                       {
                                         tmpHead =0;
                                       }
                                       if(0x5A == soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead])
                                       {
                                                 isFindFlag = TRUE;
                                                 //xprintf("len=%d\n",MCU_RxDataCnt);
                                                 break;
                                       }
                              }
                     }
                     soc_uart_comm_in_fifo.mFIFOHead++;
                     if(soc_uart_comm_in_fifo.mFIFOHead >= soc_uart_comm_in_fifo.mFIFOSize)                       
                     {
                              soc_uart_comm_in_fifo.mFIFOHead =0;
                     }
                     MCU_RxDataCnt--;
           }
  
           if(!isFindFlag)
           {                    
                     ret = 0;
           }
           else
           {

             {
                    /*
                       tmpHead++; 
                       if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize)           
                       {
                                tmpHead =0;
                       }
                       ChkSum = soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead]; 
                    */
                       
                       tmpHead++;
                       if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize )
                       {
                                tmpHead =0; 
                       }
    
                       Length = soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead];
                       //ChkSum = Length;
                         
                     if( Length >  USART4_Pack_MaxLen)//USART2_Pack_MaxLen  
                     {
                              ret = 3;                 
                     }
        
                       else if( Length+NOT_USER_DATA_SIZE > MCU_RxDataCnt )           //receive pack is not complete
                       {
                                ret = 0;
                       }
                       else
                        {
                                //------------------------- 
                                ChkSum ^= soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead];      //LEN
    
                                for(i=0; i<Length-1; i++)
                                {
                                         tmpHead++;
                                         if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize ) 
                                         {
                                                   tmpHead =0; 
                                         }
                                         ChkSum ^= soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead];
                                }   
                                tmpHead++;
                                if(tmpHead >= soc_uart_comm_in_fifo.mFIFOSize ) 
                                {
                                         tmpHead =0; 
                                }
                                if(ChkSum != soc_uart_comm_in_fifo.mpFIFOBuffer[tmpHead])       
                                {
                                         ret = 2;
                                }
                                else
                                {        
                                         ret = 1;
                                }
                       }
             }
           }
           switch(ret)
           {
                     case 0:
                              break;
                     case 1:
                              fifo_output_block(&soc_uart_comm_in_fifo,pdata,SYNC_HEAD_SIZE+1); 
                              //xprintf("len-%d,fifoLen-%d\n",soc_uart_comm_in_fifo.mFIFOLength,fifo_current_length(&soc_uart_comm_in_fifo));
                              fifo_output_block(&soc_uart_comm_in_fifo,pdata,Length); 
                              break;
                     case 2:  // sync head is right, but checksum err, we need skip SYNC_HEAD_SIZE bytes.
                              fifo_output_block(&soc_uart_comm_in_fifo,pdata,SYNC_HEAD_SIZE); 
                              break;
                     case 3:
                              break;
                     default:
                              break;
           }
           return ret;
  }
  


static void Get_DMA_UART4_Rx_Handle(void)
{
    U8 err_type = 0;
	U16 count = 0;
	U16 count_temp = 0;

    err_type = UART_REG_RLN3nLEST(GetUartBaseAddress(M4_UART));
	if(err_type > 0)
	{
      UART_REG_RLN3nLURDR(GetUartBaseAddress(M4_UART));
      UART_REG_RLN3nLEST(GetUartBaseAddress(M4_UART)) = 0x00u;/* clear error bits */
    }
    else
    {
        count = DMA_REG_DTCm(UART4_RX_DMA);
    	if(!m_socUartDrvCtrl.DMA_Rx_First_Flag)//first packet
    	{  		
    		if(count != sizeof(Dma_Read_buffer) && count != 0)
    		{

    			count_temp = sizeof(Dma_Read_buffer) - count;
    			fifo_input_block(&soc_uart_comm_in_fifo,&Dma_Read_buffer[0],count_temp);

    			m_socUartDrvCtrl.Last_DMA_Rx_count = count;
    			m_socUartDrvCtrl.DMA_Rx_First_Flag = 1;
    		}
    		else
    		{
    		
    		}
    	}
    	else//after packet
    	{
    		if(count > m_socUartDrvCtrl.Last_DMA_Rx_count)
    		{
    			
    			count_temp = USART4_RX_DMA_BUF_SIZE - count;
    			fifo_input_block(&soc_uart_comm_in_fifo,&Dma_Read_buffer[USART4_RX_DMA_BUF_SIZE - m_socUartDrvCtrl.Last_DMA_Rx_count],m_socUartDrvCtrl.Last_DMA_Rx_count);//Խ��֮ǰ
    			fifo_input_block(&soc_uart_comm_in_fifo,&Dma_Read_buffer[0],count_temp);

    			m_socUartDrvCtrl.Last_DMA_Rx_count = count;
    			
    		}
    		else if(count < m_socUartDrvCtrl.Last_DMA_Rx_count && count != 0)//û�г���buf
    		{
    			
    			count_temp = m_socUartDrvCtrl.Last_DMA_Rx_count - count;//��ַ������count�ݼ�
    			fifo_input_block(&soc_uart_comm_in_fifo,&Dma_Read_buffer[USART4_RX_DMA_BUF_SIZE - m_socUartDrvCtrl.Last_DMA_Rx_count],count_temp);

    			m_socUartDrvCtrl.Last_DMA_Rx_count = count;	
    		}
    		else
    		{
    		  if(count == 0)
    		  {
                M4UartDriver_Open();
              }
    		}
    	}
	}
}

static void Get_DMA_UART4_Tx_Handle(void)
{
	//��UART�޸���ѯ����
	U16 waitLen;
	U32 DMASendComplete = 0;
	
	waitLen = fifo_current_length(&soc_uart_comm_out_fifo);
	DMASendComplete = DMA_REG_DCSTm(UART4_TX_DMA)&0x00000010;
  if(DMASendComplete)
  {
    m_socUartDrvCtrl.SOC_Uart_Send_End_Flag = 1;
  }
  if(m_socUartDrvCtrl.SOC_Uart_Send_End_Flag && waitLen)
  {
    m_socUartDrvCtrl.SOC_Uart_Send_End_Flag = 0;
    if(waitLen > USART4_TX_DMA_BUF_SIZE)
  	{
        waitLen = USART4_TX_DMA_BUF_SIZE;
    }
	 fifo_output_block(&soc_uart_comm_out_fifo, Dma_Write_buffer,waitLen);
    //UartDma_trigger_sending(M4_UART,UART4_TX_DMA,Dma_Write_buffer,waitLen);

	if(waitLen > 1)
	{
	   DMA_Config_SpiTx(UART4_TX_DMA, (U32)(&Dma_Write_buffer[1]), waitLen-1);		
	   DMA_Start(UART4_TX_DMA); 
       UART_REG_RLN3nLUTDR(GetUartBaseAddress(M4_UART)) =  Dma_Write_buffer[0];
	}
	else
	{
        UART_REG_RLN3nLUTDR(GetUartBaseAddress(M4_UART)) =  Dma_Write_buffer[0];
	}
  }
}


/*********interrupt************/
void M4UartDriver_ReceiveIsr(U8 data)
{
 
}
void M4UartDriver_SendIsr(void) // one frame send end enter sendIsr
{
}



/**************** END OF FILE *****************************************/

