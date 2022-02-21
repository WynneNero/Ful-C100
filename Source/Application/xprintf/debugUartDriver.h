/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW2      									   *
*   AUTHOR	   : Qing Xiaohui										   *
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
#ifndef _DEBUG_UART_DRIVER_H_
#define _DEBUG_UART_DRIVER_H_ 

#include "Define.h"
#include "Hal_if.h"

U8 debugUartDrvOpen(void);   				
U8 debugUartDrvClose(void);
U16 debugUartDrvRead(U8 *buff,U16 Len);
U8 debugUartDrvWrite(U8 *buff,U16 Len);
U8 debugUartDrvIoControl(U8 type,void *buff);
U8 debugUartDrvPowerControl(U8 type);
U8 debugUartDrvPowerStatus(void);


#endif /*_DEBUG_UART_DRIVER_H_*/

/****************************** END OF FILE ***************************/

