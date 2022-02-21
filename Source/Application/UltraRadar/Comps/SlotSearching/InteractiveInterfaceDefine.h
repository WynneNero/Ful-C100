/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				                   *
*				  All Rights Reserved.          					                          *
*   Department   	: CT AD     									   		     *
*   AUTHOR	    	: 									                                 *
************************************************************************
* Object            	:
* Module           	:
* Instance         	:
* Description      	:
*-----------------------------------------------------------------------
* Version			:
* Date			:
* Author			:Zhao Yupeng
***********************************************************************/
/*-History---------------------------------------------------------------
* Version   		Date        		Name             Changes and comments
* ----------------------------------------------------------------------
* 	1.0   		17 Apr,2020			Zhao Yupeng				Init Version
*=======================================================================*/
#ifndef _INTERACTIVE_INTERFACE_DEFINE_H
#define _INTERACTIVE_INTERFACE_DEFINE_H
#include "DataTypeDef.h"
/**** Definition of constants ****/
/**** Definition of macros ****/
#define USS_ALG_SOFT_VERSION_LEN  		(19)
/**** Declaration of constants ****/
typedef enum
{
	ClearSlotMsg_Right = 0,
	ClearSlotMsg_Left,
	ClearSlotMsg_DoubleSide
}SlotClearMsgDirection;

typedef enum
{
	SearchingLeftSlotMode = 0,
	SearchingRightSlotMode,
	SearchingDoubleSideMode,
	Searching_OFF,
}SlotSearchingMode;


/**** Declaration of variables ****/
extern char VersionNum[USS_ALG_SOFT_VERSION_LEN];

/**** Declaration of functions ****/
/***********************************************************************
*  Name        : ApaStatMachine_GetApaState
*  Description : This funtion returns to the State of SlotSearching function
*  Parameter   :
*  Returns     : 0x0 SlotDect_STATE_OFF  = 0,
				 0x1 SlotDect_STATE_STANDBY_ENABLE,
	    		 0x2 SlotDect_STATE_ENABLE,
***********************************************************************/
extern signed char ApaStatMachine_GetApaState(void);

/***********************************************************************
*  Name        : UltraRadarSlotSearchingClearSlotMsg
*  Description : This funtion Clear the Slot Searching Result
*  Parameter   : SlotClearDir
*  Returns     : None
***********************************************************************/
extern unsigned char SlotDataClear(unsigned char SlotClearDir);

/***********************************************************************
*  Name        : USSParkingSlotSearching(unsigned char)
*  Description : This function support switch the SlotSearching Mode by parameter
*  Parameter   :
				0x00£ºSearching Left Slot Mode
		  		0x01£ºSearching Right Slot Mode
		  		0x02£ºSearching Double Side Mode
		  		0x03: Searching None
*  Returns     : None
***********************************************************************/
extern unsigned char USSParkingSlotSearching(unsigned char);

/***********************************************************************
*  Name        : USSParkingSlotSearching(unsigned char)
*  Description : This function genrate the Number of SlotSearching lib version
*  Parameter   :
*  Returns     : None
***********************************************************************/
extern unsigned char GetUssSlotSearchingLibVer(char *soft_ver);


#endif
