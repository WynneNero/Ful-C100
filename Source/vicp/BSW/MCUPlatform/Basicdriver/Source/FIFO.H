/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Zhang Jiacheng										   *
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
* Version       Date           Name    Changes and comments
*-----------------------------------------------------------------------
* 0.1	   Jun 02,2016                         Initial version
*----------------------------------------------------------------------
* 0.2         Jan 13,2017    ShangQiuju     Fix Coverity warning.
*----------------------------------------------------------------------
* 0.3         Apr 01,2017    Pei Jingli         Remove static interfaces.
*=====================================================================*/
#ifndef _FIFO_H_
#define _FIFO_H_ 
#include "Define.h"
/**** Definition of constants ****/
/**** Definition of types ****/ 
typedef struct 
{
    U8  *mpFIFOBuffer;
    volatile U16  mFIFOHead;   
    volatile U16  mFIFOTail;  
    U16  mFIFOSize;
} FIFO_TYPE;

/**** Definition of macros ****/


/**** Declaration of constants ****/


/**** Declaration of variables ****/


/**** Declaration of functions ****/
extern void fifo_init( FIFO_TYPE *this, U8 *pBuf, U16 nSize);
extern BOOL fifo_input_frame( FIFO_TYPE *this , U8 *pFrame, U8 length);
extern BOOL fifo_output_frame( FIFO_TYPE *this, U8 *pFrame, U8 *pLength);
extern BOOL fifo_input_block( FIFO_TYPE *this , U8 *pFrame , U16 length);
extern BOOL fifo_output_block( FIFO_TYPE *this , U8 *pFrame , U16 length);
extern BOOL fifo_has_enough_space(FIFO_TYPE * this,U16 nBytes);
extern U16 fifo_current_length(FIFO_TYPE *this  );
extern BOOL fifo_input_byte( FIFO_TYPE *this, U8 byte );
extern BOOL fifo_output_byte(FIFO_TYPE *this, U8 *pdata);

#endif /*_FIFO_IF_H_*/

/****************************** END OF FILE ***************************/
