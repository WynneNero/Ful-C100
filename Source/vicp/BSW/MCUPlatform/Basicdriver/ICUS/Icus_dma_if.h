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
* 0.2	   Sep 06,2017   ZhangJie  Update after code review
*------------------------------------------------------------------------
* 0.3	   Sep 08,2017   ZhangJie  Remove unused include head file
*=====================================================================*/
#ifndef _ICUS_DMA_IF_H_
#define _ICUS_DMA_IF_H_

/*============================================================================
 Includes
============================================================================*/
#include "Icus_define.h"

/*===========================================================================
  DMA MACRO Definitions
===========================================================================*/  
typedef enum
{
     DMA_0=0,                     
     DMA_1,                     
     DMA_2,                     
     DMA_3,
     DMA_4,
     DMA_5,                     
     DMA_6,                     
     DMA_7,
     DMA_8,
     DMA_9,                     
     DMA_10,                     
     DMA_11,
     DMA_12,
     DMA_13,                     
     DMA_14,                     
     DMA_15,
     DMA_MAX
}DMA_TYPE; 

#define DMA_SECUREBOOT DMA_1 //DMA_0

#define DMA_MAXCTR      65536  

extern void Icus_DMA_Init(DMA_TYPE dma);
extern void Icus_DMA_Stop(DMA_TYPE dma);
extern void Icus_DMA_ConfigBlock_RD(DMA_TYPE dma,U32 srcaddr,U32  n);
extern void Icus_DMA_Start_RD(DMA_TYPE dma);
extern void Icus_DMA_Restart_RD(DMA_TYPE dma);


#endif  /* End of module include.  */