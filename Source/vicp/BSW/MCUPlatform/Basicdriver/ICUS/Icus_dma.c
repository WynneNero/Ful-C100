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
#include "icus.h"
#include "icus_dma.h"
#include "icus_dma_if.h"
#include "IRQ_IF.h"

static void Icus_DMA_Config_RD(DMA_TYPE dma,U32 srcaddr, U32 counter);
static void DMA_EnableInterrupt(DMA_TYPE dma);
static void DMA_DisableInterrupt(DMA_TYPE dma);
static U8 GetDMAIRQNumber(DMA_TYPE dma);


/***********************************************************************
*  Name        : PEGuard_Config
*  Description :PE Guard Area0~3 settings.
*  Parameter  : None
*  Returns     : None
***********************************************************************/
void Icus_DMA_PEGuard_Config(void)
{
	/** PE Guard Area0 settings **/
	/*PEGGnMK ¡ª PEG Area n Mask Setting Register (n = 0 to 3)
	31 to 12 GnMASK 
		0: Target bits are compared when determining the PE guard area.
		1: Target bits are not compared when determining the PE guard area.
	*/
	PEG_REG_PEGG0MK =0x0000f000; /* */
	/*PEGGnBA ¡ª PEG Area n Base Setting Register (n = 0 to 3)
	31 to 12 GnBASE Base address that specifies the range of PE guard protection area n.
	                       Base address is in Local RAM/Retetion RAM.
	7 GnSP3 	Access permission setting from SPID = 3 external master to PE guard
			protection area n.
		0: Not permit.
		1: Permit.										---set 0
	6 GnSP2 	Access permission setting from SPID = 2 external master to PE guard
			protection area n.
		0: Not permit.										---set 0
		1: Permit.
	5 GnSP1 	Access permission setting from SPID = 1 external master to PE guard
			protection area n.
		0: Not permit.										---set 1
		1: Permit.
	4 GnSP0 	Access permission setting from SPID = 0 external master to PE guard
			protection area n.
		0: Not permit.										---set 0
		1: Permit.
	2 GnWR 	Write access permission to PE guard protection area n.
		0: Write access is disabled.
		1: Write access is enabled.							---set
	1 GnRD 	Read access permission to PE guard protection area n.
		0: Read access is disabled.
		1: Read access is enabled.							---set
	0 GnEN 	Enables or Disables the setting for the access enable conditions to PE guard
		   	protection area n.
		0: Settings for access enable conditions are disabled.
		1: Settings for access enable conditions are enabled.		---set
	*/
	PEG_REG_PEGG0BA=0xFEBD0027;/*local ram 0xFEBD0000, permit SPID1, read/write/access enable */

	/*PEGSP ¡ª PEG SPID Control Register
	0 SPEN 	Access permission to external master with specified SPID.
		0: Not permit.
		1: Permit.		---set
	*/
	PEG_REG_PEGSP=0x01;
}


/***********************************************************************
*  Name        : Icus_DMA_Stop
*  Description : disable DMA operations.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void Icus_DMA_Stop(DMA_TYPE dma)
{
    DMA_REG_DCENm(dma) = 0;  

    DMA_DisableInterrupt(dma);
}

/***********************************************************************
*  Name        : Icus_DMA_Init
*  Description : Init DMA operations.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void Icus_DMA_Init(DMA_TYPE dma)
{
    Icus_DMA_PEGuard_Config();
    Icus_DMA_Stop(dma);

    /* Disable interrupt */
    DMA_REG_DM0iCM(dma) = DMAC_PE1_SETTING | DMAC_SPID1_SETTING | DMAC_SUPERVISON_MODE;
    DMA_REG_DDAm(dma) = (U32)&ICU_IDAT;
    DMA_REG_DTCTm(dma) = DMAC_CYCLES_EXECUTED | DMAC_TRANSFER_HARDWARE | 
             DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE | DMAC_CONTINUOUS_TRANSFER_DISABLE | 
             DMAC_RELOAD2_DISABLE | DMAC_RELOAD1_DISABLE | DMAC_DESTINATION_FIXED | 
             DMAC_SOURCE_INCREMENT | DMAC_TRANSFER_DATA_32BITS | DMAC_SINGLE_TRANSFER;
    DMA_REG_DTFRm(dma) = (25<<0x01)+0x01U; 
    
    // setup interrupt servicing
    DMA_EnableInterrupt(dma);
}

/***********************************************************************
*  Name        : Icus_DMA_ConfigBlock_RD
*  Description : Set the source address and the counter of the DMA for writing to the ICU-S.
*  Parameter   : dma is the DMA channel
                        srcaddr is the source data address
                        n is the data block size(4 bytes = 1 block)
*  Returns     :   null.
***********************************************************************/
void Icus_DMA_ConfigBlock_RD(DMA_TYPE dma,U32 srcaddr,U32  n)
{
    if(n >= DMA_MAXCTR)                                       
    {                                                               
        /* in order to allow tests with DMA_MAXCTR below 32768 */                        
        Icus_DMA_Config_RD(dma,srcaddr, DMA_MAXCTR & 0x7FFF);             
    }                                                               
    else                                                            
    {                                                               
        Icus_DMA_Config_RD(dma,srcaddr, n);                           
    }                                                               
}

/***********************************************************************
*  Name        : Icus_DMA_Start_RD
*  Description : Clear transfer request and start DMA for writing to the ICU-S.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void Icus_DMA_Start_RD(DMA_TYPE dma)
{
    DMA_REG_DTFRRQCm(dma) |= 0x01;  
    DMA_REG_DCSTCm(dma) |= 0x00000091;  /* clear all flags of status register */
    DMA_REG_DCENm(dma) |= 0x1;  
}

/***********************************************************************
*  Name        : Icus_DMA_Restart_RD
*  Description : Re-start DMA for reading from the ICU-S w/o clearing pending request.
*  Parameter   : dma is the DMA channel
*  Returns     :   null.
***********************************************************************/
void Icus_DMA_Restart_RD(DMA_TYPE dma)
{
    if(!DMA_REG_DCENm(dma))
    {}
    else
    { 
        DMA_REG_DCSTCm(dma) |= 0x00000091;  /* clear all flags of status register */
        DMA_REG_DCENm(dma) |= 0x1;  
    }
}

/***********************************************************************
*  Name        : Icus_DMA_Restart_RD
*  Description : Set the source address and the counter of the DMA for writing to the ICU-S.
*  Parameter   : dma is the DMA channel
                        srcaddr is the source data address
                        counter is the data block size(4 bytes = 1 block)
*  Returns     :   null.
***********************************************************************/
static void Icus_DMA_Config_RD(DMA_TYPE dma,U32 srcaddr, U32 counter)
{
    DMA_REG_DSAm(dma) = srcaddr; 
    DMA_REG_DTCm(dma)  = counter; 
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
static U8 GetDMAIRQNumber(DMA_TYPE dma)
{
  U8 IrqNo =0;

  IrqNo=60+(U8)dma;
  return IrqNo;  
}
