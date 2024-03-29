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
* Version       Date    Name    Changes and comments
* ------------------------------------------------------------------------
* 0.1	   Jun 26,2016                   Initial version
*----------------------------------------------------------------------
* 0.2          Jan 24,2017    ZhangJie     Fix Coverity warning.
*=====================================================================*/
#ifndef _FIFO_IF_H_
#define _FIFO_IF_H_ 
/**** Definition of constants ****/

#include "fifo.h"
#if 0
/**** Definition of types ****/ 
typedef struct 
{
    U8  *mpFIFOBuffer;
    U16  mFIFOHead;   
    U16  mFIFOTail;  
    //U16  mFIFOLength; /*888 to hold current length*/
    U16  mFIFOSize;
} FIFO_TYPE;

/**** Definition of macros ****/


/**** Declaration of constants ****/


/**** Declaration of variables ****/


/**** Declaration of functions ****/
extern void fifo_init( FIFO_TYPE *this, U8 *pBuf, U16 nSize);
extern BOOL fifo_input_frame( FIFO_TYPE *this , U8 *pFrame, U8 length);
extern BOOL fifo_output_frame( FIFO_TYPE *this, U8 *pFrame, U8 *pLength);
extern BOOL fifo_input_block( FIFO_TYPE *this , U8 *pFrame , U8 length);
extern BOOL fifo_output_block( FIFO_TYPE *this , U8 *pFrame , U8 length);
extern BOOL fifo_has_enough_space(FIFO_TYPE * this,U8 nBytes);
extern U16 fifo_current_length(FIFO_TYPE *this  );
extern BOOL Uartfifo_input_block( FIFO_TYPE *this , U8 *pFrame , U16 length); 
BOOL fifo_input_byte( FIFO_TYPE *this , unsigned char byte );
#endif

#endif /*_FIFO_IF_H_*/

/****************************** END OF FILE ***************************/
