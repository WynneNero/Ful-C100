/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				*
*				  All Rights Reserved.          			*
*   Department : ITC R&D NKG      						*
*   AUTHOR	   : 					*
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :  Head file
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
#ifndef _ICUS_DMA_H_
#define _ICUS_DMA_H_

/*============================================================================
 Includes
============================================================================*/
#include "Icus_define.h"

/*===========================================================================
  DMA MACRO Definitions
===========================================================================*/  
#define DMA_BASE_ADDRESS                       ( (CPU_INT32U )0xFFFF8000u)    /* Base Address */

#define  DMA_REG_DSAm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0400+(0x40*ch)))
#define  DMA_REG_DDAm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0404+(0x40*ch)))
#define  DMA_REG_DTCm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0408+(0x40*ch)))
#define  DMA_REG_DTCTm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x040C+(0x40*ch)))
#define  DMA_REG_DRSAm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0410+(0x40*ch)))
#define  DMA_REG_DRDAm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0414+(0x40*ch)))
#define  DMA_REG_DRTCm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0418+(0x40*ch)))
#define  DMA_REG_DCENm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0420+(0x40*ch)))
#define  DMA_REG_DCSTm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0424+(0x40*ch)))
#define  DMA_REG_DCSTSm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0428+(0x40*ch)))
#define  DMA_REG_DCSTCm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x042C+(0x40*ch)))
#define  DMA_REG_DTFRm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0430+(0x40*ch)))
#define  DMA_REG_DTFRRQm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0434+(0x40*ch)))
#define  DMA_REG_DTFRRQCm(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0438+(0x40*ch)))

#define  DMA_REG_DM0iCM(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0100+(0x4*ch)))
#define  DMA_REG_DM1iCM(ch)   (*(CPU_REG32 *)(DMA_BASE_ADDRESS + 0x0120+(0x4*(ch-0x08))))

#define  PEG_BASE_ADDRESS                       ( (CPU_INT32U )0xFFFEE600u) 
#define  PEG_REG_PEGSP                              (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x000C))
#define  PEG_REG_PEGG0MK                          (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0080))
#define  PEG_REG_PEGG0BA                          (*(CPU_REG32 *)(PEG_BASE_ADDRESS + 0x0084))

/*
    DMAC Transfer Control Register n (DTCTn)
*/
/* Transfer error case DMA transfer disable setting (ESE) */
#define DMAC_CYCLES_EXECUTED                               (0x00000000U) /* DMA cycles are executed */
#define DMAC_CYCLES_NOT_EXECUTED                           (0x08000000U) /* DMA cycles are not executed */
/* DMA transfer request selection assignment (DRS) */
#define DMAC_TRANSFER_SOFTWARE                             (0x00000000U) /* Software DMA transfer request */
#define DMAC_TRANSFER_HARDWARE                             (0x04000000U) /* Hardware DMA transfer request */
/* Next channel in the chain (CHNSEL[2-0]) */
#define DMAC_SELECT_CHAIN_0                                (0x00000000U) /* chain 0 */
#define DMAC_SELECT_CHAIN_1                                (0x00040000U) /* chain 1 */
#define DMAC_SELECT_CHAIN_2                                (0x00080000U) /* chain 2 */
#define DMAC_SELECT_CHAIN_3                                (0x000C0000U) /* chain 3 */
#define DMAC_SELECT_CHAIN_4                                (0x00100000U) /* chain 4 */
#define DMAC_SELECT_CHAIN_5                                (0x00140000U) /* chain 5 */
#define DMAC_SELECT_CHAIN_6                                (0x00180000U) /* chain 6 */
#define DMAC_SELECT_CHAIN_7                                (0x001C0000U) /* chain 7 */
/* Chain enable (CHNEL[1-0]) */
#define DMAC_CHAIN_DISABLE                                 (0x00000000U) /* chain function disabled */
#define DMAC_CHAIN_LAST_TRANFER                            (0x00010000U) /* Chain at the last transfer */
#define DMAC_ALWAYS_CHAIN                                  (0x00030000U) /* Always chain */
/* Transfer count match interrupt enable (CCE) */
#define DMAC_TRANSFER_COUNT_INTERRUPT_DISABLE              (0x00000000U) /* Transfer count match interrupt disable */
#define DMAC_TRANSFER_COUNT_INTERRUPT_ENABLE               (0x00008000U) /* Transfer count match interrupt enable */
/* Transfer completion interrupt enable (TCE) */
#define DMAC_TRANSFER_COMPLETION_INTERRUPT_DISABLE         (0x00000000U) /* Transfer completion interrupt disable */
#define DMAC_TRANSFER_COMPLETION_INTERRUPT_ENABLE          (0x00004000U) /* Transfer completion interrupt enable */
/* Continuous transfer enable (MLE) */
#define DMAC_CONTINUOUS_TRANSFER_ENABLE                    (0x00002000U) /* DTE bit is cleared */
#define DMAC_CONTINUOUS_TRANSFER_DISABLE                   (0x00000000U) /* DTE bit is not cleared */
/* Reload function 2 setting (RLD2M[1-0]) */
#define DMAC_RELOAD2_DISABLE                               (0x00000000U) /* Reload function 2 is disabled */
#define DMAC_RELOAD2_SOURCE_CONTROL                        (0x00000800U) /* Reload function 2 is enabled source */
#define DMAC_RELOAD2_DESTINATION_CONTROL                   (0x00001000U) /* Reload function 2 is enabled destination */
#define DMAC_RELOAD2_ALL_CONTROL                           (0x00001800U) /* Reload function 2 is enabled all */
/* Reload function 1 setting (RLD1M[1-0]) */
#define DMAC_RELOAD1_DISABLE                               (0x00000000U) /* Reload function 1 is disabled */
#define DMAC_RELOAD1_SOURCE_CONTROL                        (0x00000200U) /* Reload function 1 is enabled source */
#define DMAC_RELOAD1_DESTINATION_CONTROL                   (0x00000400U) /* Reload function 1 is enabled destination */
#define DMAC_RELOAD1_ALL_CONTROL                           (0x00000600U) /* Reload function 1 is enabled all */
/* Destination address count direction (DACM[1-0]) */
#define DMAC_DESTINATION_INCREMENT                         (0x00000000U) /* Increment mode */
#define DMAC_DESTINATION_DECREMENT                         (0x00000080U) /* Decrement mode */
#define DMAC_DESTINATION_FIXED                             (0x00000100U) /* fixed */
/* Source address count direction (SACM[1-0]) */
#define DMAC_SOURCE_INCREMENT                              (0x00000000U) /* Increment mode */
#define DMAC_SOURCE_DECREMENT                              (0x00000020U) /* Decrement mode */
#define DMAC_SOURCE_FIXED                                  (0x00000040U) /* fixed */
/* Transfer data size (DS[2-0]) */
#define DMAC_TRANSFER_DATA_8BITS                           (0x00000000U) /* transfer data size 8 bits */
#define DMAC_TRANSFER_DATA_16BITS                          (0x00000004U) /* transfer data size 16 bits */
#define DMAC_TRANSFER_DATA_32BITS                          (0x00000008U) /* transfer data size 32 bits */
#define DMAC_TRANSFER_DATA_64BITS                          (0x0000000CU) /* transfer data size 64 bits */
#define DMAC_TRANSFER_DATA_128BITS                         (0x00000010U) /* transfer data size 128 bits */
/* Transfer mode (TRM[1-0]) */
#define DMAC_SINGLE_TRANSFER                               (0x00000000U) /* Single transfer */
#define DMAC_BOLCK_TRANSFER_1                              (0x00000001U) /* Block transfer 1 */
#define DMAC_BOLCK_TRANSFER_2                              (0x00000002U) /* Block transfer 2 */

/*
    DMAC Channel Master Setting Register n  (DMnmCM)
*/
/* Channel master UM setting (UM) (UM) */
#define DMAC_SUPERVISON_MODE                               (0x00000000U) /* Supervison mode */
#define DMAC_USER_MODE                                     (0x00000002U) /* User mode */
/* Channel master PEID setting  (PEID[2-0]) */
#define DMAC_PE1_SETTING                                   (0x00000010U) /* PE1 */
#define DMAC_PE2_SETTING                                   (0x00000030U) /* PE2 */
/* Channel master PEID setting  (SPID1,SPID0) */
#define DMAC_SPID0_SETTING                                 (0x00000000U) /* SPID0 */
#define DMAC_SPID1_SETTING                                 (0x00000004U) /* SPID1 */
#define DMAC_SPID2_SETTING                                 (0x00000008U) /* SPID2 */
#define DMAC_SPID3_SETTING                                 (0x0000000CU) /* SPID3 */



#endif  /* End of module include.  */