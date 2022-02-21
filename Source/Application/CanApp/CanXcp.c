/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : IDA     									   *
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
* Ver  Date         Name       Changes and comments
*----------------------------------------------------------------------
*  0.1 Sep 12,2018 	Xie Jieying		init version.
*----------------------------------------------------------------------
*=====================================================================*/
#include "XcpProf.h"
#include "CanXcp.h"
#include "CanManager.h"
#ifdef  XCP_DEBUG
#include "VX1000if.h"
#endif


/*******************************************************************************
*
* NAME:              XcpCycleTask
*
* CALLED BY:         SysCycle_apS3FastT5msContainer
* PRECONDITIONS:     Test_vesion
*
* PARAMETER:         NONE
* RETURN VALUE:      NONE
* DESCRIPTION:       XCP call period
*
*******************************************************************************/
static U16 u8XcpCyckeTaskCnt = 0;
void XcpCycleTask(void)
{
	U8 XcpStatus;
	CAN_STATE  can_status;
	can_status = GetCanstate();
	if(can_status !=E_CAN_NORMAL)
		return;
	
	if(u8XcpCyckeTaskCnt >= 20)
    {
        u8XcpCyckeTaskCnt = 0;
    }

	#ifdef  XCP_DEBUG
		VX1000If_Event(0x1);
    #endif
		//XcpEvent(0);    /* Call every 5ms */
	
	if((u8XcpCyckeTaskCnt % 2) == 0u)   /* Call every 10ms */
	{
		//XcpEvent(1);
		#ifdef  XCP_DEBUG
		VX1000If_Event(0x2);
        #endif	 
	}

	if((u8XcpCyckeTaskCnt % 4) == 0u) /* Call every 20ms */
	{
		//XcpEvent(2);	
		//XcpEvent(7);
		#ifdef  XCP_DEBUG
		VX1000If_Event(0x3);
    	#endif   
	}


	if((u8XcpCyckeTaskCnt % 10) == 0u)  /* Call every 50ms */
	{
		
	}

	if((u8XcpCyckeTaskCnt % 20) == 0u)  /* Call every 100ms */
	{
		//XcpEvent(3);    
		//XcpEvent(8);    
	}

	if((u8XcpCyckeTaskCnt % 40) == 0u) /* Call every 200ms */
	{
   		//XcpEvent(4);     
	}
	
	if((u8XcpCyckeTaskCnt % 100) == 0u) /* Call every 500ms */
	{
		
		//XcpEvent(5);    
	}
	
	if((u8XcpCyckeTaskCnt % 200) == 0u)/* Call every 1000ms */
	{
		//XcpEvent(6);    
	}


	u8XcpCyckeTaskCnt++;
	
 
	//XcpStatus = XcpGetState();



}


