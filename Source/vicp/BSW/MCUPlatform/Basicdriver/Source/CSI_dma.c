/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department : CT AD                                                 *
*   AUTHOR     :                                                       *
************************************************************************
* Object        :
* Module        :	DMA
* Instance      :
* Description   :	DMA opertaion
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
*------------------------------------------------------------------------
* 0.1	   Sep 01,2017   ZhangJie  Initial version
*------------------------------------------------------------------------
* 0.2	   Sep 08,2017   ZhangJie  Remove unused include head file
*=====================================================================*/

/*============================================================================
 Includes
============================================================================*/
#include "Config.h"
#include "CSI_dma.h"
#include "CSI_dma_if.h"
#include "IRQ_IF.h"
//#include "SocDriver.h"

extern const U32 DMAChannel_Cfg[DMA_MAX][3] ;
extern const Func_Void_Proc DMA_Isr_callback[DMA_MAX];

static void DMA_EnableInterrupt(DMA_TYPE dma);
static void DMA_DisableInterrupt(DMA_TYPE dma);
static U16 GetDMAIRQNumber(DMA_TYPE dma);

/***********************************************************************
*  Name        : DMA_Start
*  Description : Clear transfer request and start DMA for writing to the ICU-S.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Start(DMA_TYPE dma)
{
    DMA_REG_DTFRRQCm(dma) |= 0x01;  
    DMA_REG_DCSTCm(dma) |= 0x00000091u;  /* clear all flags of status register */
    DMA_REG_DCENm(dma) |= 0x1;  
}

/***********************************************************************
*  Name        : DMA_Stop
*  Description : disable DMA operations.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Stop(DMA_TYPE dma)
{
    DMA_REG_DCENm(dma) = 0;  
}

/***********************************************************************
*  Name        : DMA_Deinit
*  Description : disable DMA operations.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Deinit(DMA_TYPE dma)
{
    DMA_REG_DCENm(dma) = 0;  

    DMA_DisableInterrupt(dma);
}

/***********************************************************************
*  Name        : DMA_Init_SpiTx
*  Description : Init DMA operations. DMA of CSIHxIC
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Init_SpiTx(DMA_TYPE dma) 
{
    DMA_Stop(dma);

    if(dma>DMA_7) 
      DMA_REG_DM1iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID1_SETTING | DMAC_SUPERVISON_MODE;
    else
      DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID1_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DDAm(dma) = DMAChannel_Cfg[dma][1];
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | 
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_DISABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DISABLE | DMAC_DESTINATION_FIXED | 
             DMAC_SOURCE_INCREMENT | DMAC_TRANSFER_DATA_8BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = ((DMAChannel_Cfg[dma][2])<<0x01)+0x01U; 
    
    // setup interrupt servicing
    DMA_EnableInterrupt(dma);
}

/***********************************************************************
*  Name        : DMA_Init_SpiTx
*  Description : Init DMA operations. DMA of CSIHxIR
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Init_SpiRx(DMA_TYPE dma) 
{
    DMA_Stop(dma);
    if(dma>DMA_7) 
      DMA_REG_DM1iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID1_SETTING | DMAC_SUPERVISON_MODE;
    else
      DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID1_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DSAm(dma) = DMAChannel_Cfg[dma][0];
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | 
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_DISABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DISABLE | DMAC_DESTINATION_INCREMENT | 
             DMAC_SOURCE_FIXED | DMAC_TRANSFER_DATA_8BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = ((DMAChannel_Cfg[dma][2])<<0x01)+0x01U; 
    
    // setup interrupt servicing
    DMA_EnableInterrupt(dma);
}


/***********************************************************************
*  Name        : DMA_Init_UartTx
*  Description : Init DMA operations. DMA of CSIHxIC
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Init_UartTx(DMA_TYPE dma) 
{
    DMA_Stop(dma);

    if(dma>DMA_7) 
        DMA_REG_DM1iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    else
        DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DDAm(dma) = DMAChannel_Cfg[dma][1];
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | 
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_DISABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DISABLE | DMAC_DESTINATION_FIXED | 
             DMAC_SOURCE_INCREMENT | DMAC_TRANSFER_DATA_8BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = ((DMAChannel_Cfg[dma][2])<<0x01)+0x01U; 
    
    // setup interrupt servicing
      //DMA_EnableInterrupt(dma);
}

/***********************************************************************
*  Name        : DMA_Init_UartTx
*  Description : Init DMA operations. DMA of CSIHxIC
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Init_UartTx_No_Int(DMA_TYPE dma) 
{
    DMA_Stop(dma);

    if(dma>DMA_7) 
          DMA_REG_DM1iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    else
          DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DDAm(dma) = DMAChannel_Cfg[dma][1];
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | 
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_DISABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DISABLE | DMAC_DESTINATION_FIXED | 
             DMAC_SOURCE_INCREMENT | DMAC_TRANSFER_DATA_8BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = ((DMAChannel_Cfg[dma][2])<<0x01)+0x01U; 
    
    // setup interrupt servicing
    //DMA_EnableInterrupt(dma);
}

/***********************************************************************
*  Name        : DMA_Init_UartRx
*  Description : Init DMA operations. DMA of CSIHxIC
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void DMA_Init_UartRx(DMA_TYPE dma) 
{
    DMA_Stop(dma);
    if(dma>DMA_7) 
      DMA_REG_DM1iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    else
      DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID3_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DSAm(dma) = DMAChannel_Cfg[dma][0];
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | DMAC_CHAIN_DISABLE |
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_ENABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DESTINATION_CONTROL | DMAC_DESTINATION_INCREMENT | 
             DMAC_SOURCE_FIXED | DMAC_TRANSFER_DATA_8BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = ((DMAChannel_Cfg[dma][2])<<0x01)+0x01U; 
    //DMA_REG_DRSAm(dma) = DMAChannel_Cfg[dma][0];
    // setup interrupt servicing
    //DMA_EnableInterrupt(dma);


}


/***********************************************************************
*  Name        : DMA_Config_SpiTx
*  Description : Set the source address and the counter of the DMA for writing to the ICU-S.
*  Parameter   : dma is the DMA channel
                        srcaddr is the source data address
                        counter is the data block size(4 bytes = 1 block)
*  Returns     :   null.
***********************************************************************/
void DMA_Config_SpiTx(DMA_TYPE dma,U32 srcaddr, U32 counter)
{
    DMA_REG_DSAm(dma) = srcaddr; 
    DMA_REG_DTCm(dma)  = counter; 
}

void DMA_Config_SpiRx(DMA_TYPE dma,U32 destaddr, U32 counter)
{
    DMA_REG_DDAm(dma) = destaddr; 
    DMA_REG_DTCm(dma)  = counter; 
}

void DMA_Config_UartTx(DMA_TYPE dma,U32 srcaddr, U32 counter)
{
    DMA_REG_DSAm(dma) = srcaddr; 
    DMA_REG_DTCm(dma)  = counter; 
}

void DMA_Config_UartRx(DMA_TYPE dma,U32 destaddr, U32 counter)
{
    DMA_REG_DDAm(dma) = destaddr; 
    DMA_REG_DTCm(dma)  = counter; 
}

void DMA_Config_SpiReloadRx(DMA_TYPE dma,U32 destaddr, U32 counter)
{
    DMA_REG_DRDAm(dma) = destaddr; 
    DMA_REG_DRTCm(dma)  = counter; 
}


void Os_Isr_ISR_DMAC0_Handler(void)
{
    if(DMA_Isr_callback[DMA_0]!=NULL)
        DMA_Isr_callback[DMA_0]();
}

void Os_Isr_ISR_DMAC8_Handler(void) 
{
    if(DMA_Isr_callback[DMA_8]!=NULL)
        DMA_Isr_callback[DMA_8]();
}


void Os_Isr_ISR_DMAC1_Handler(void)
{
    if(DMA_Isr_callback[DMA_1]!=NULL)
        DMA_Isr_callback[DMA_1]();
}

void Os_Isr_ISR_DMAC9_Handler(void)
{
    if(DMA_Isr_callback[DMA_9]!=NULL)
        DMA_Isr_callback[DMA_9]();
}

void Os_Isr_ISR_DMAC2_Handler(void)
{
    if(DMA_Isr_callback[DMA_2]!=NULL)
        DMA_Isr_callback[DMA_2]();
}


/***********************************************************************
*  Name        : DMA_EnableInterrupt
*  Description : Enable DMA interrupt
*  Parameter   : dma - dma channel
*  Returns     : None
***********************************************************************/
static void DMA_EnableInterrupt(DMA_TYPE dma )
{
    IRQ_IntClr(GetDMAIRQNumber(dma));
    IRQ_IntEn(GetDMAIRQNumber(dma));
}

/***********************************************************************
*  Name        : DMA_DisableInterrupt
*  Description : Disable DMA interrupt
*  Parameter   : dma - dma channel
*  Returns     : None
***********************************************************************/
static void DMA_DisableInterrupt(DMA_TYPE dma)
{
   IRQ_IntDis(GetDMAIRQNumber(dma));
   IRQ_IntClr(GetDMAIRQNumber(dma));
}

/***********************************************************************
*  Name        : GetDMAIRQNumber
*  Description : get interrupt channel ID
*  Parameter   : dma - dma channel
*  Returns     : None
***********************************************************************/
static U16 GetDMAIRQNumber(DMA_TYPE dma)
{
  U16 IrqNo =0;

  IrqNo=INTDMA0+(U16)dma;
  return IrqNo;  
}
