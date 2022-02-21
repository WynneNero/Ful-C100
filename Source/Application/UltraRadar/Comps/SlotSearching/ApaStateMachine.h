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
* Author			:
***********************************************************************/
/*-History---------------------------------------------------------------
* Version   Date        Name             Changes and comments
* ----------------------------------------------------------------------
* 
*======================================================*/
#ifndef _APA_STATE_MACHINE_H_
#define _APA_STATE_MACHINE_H_

#include "DataTypeDef.h"

typedef  enum{
	 SlotDect_STATE_OFF = 0,
	 SlotDect_STATE_STANDBY_ENABLE,
	 SlotDect_STATE_ENABLE,
}tAPAOperationState;
/*******************DIAG TRACE TEST ***************************/

void APADetermineStatusTask(void);

/*****************************************************************************
** Function:    ApaStatMachine_GetApaState()
** Description: This function provide the APA state value
** Parameter:   none
** Return:      typedef  enum
                {
            	 APA_STATE_OFF = 0,
            	 APA_STATE_DISABLE,
            	 APA_STATE_STANDBY_ENABLE,
            	 APA_STATE_ENABLE,
            	 APA_STATE_ACTIVE
                }tAPAOperationState;
**              
******************************************************************************/
signed char ApaStatMachine_GetApaState(void);

/*****************************************************************************
** Function:    ApaSlotSearching_EnablePressedFlag()
** Description: This function provide a interface of SlotSearching block enable 
** Parameter:   none
** Return:      TRUE
******************************************************************************/            

BOOLEAN ApaSlotSearching_EnablePressedFlag(void);

/*****************************************************************************
** Function:    ApaSlotSearching_DisablePressedFlag()
** Description: This function provide a interface of SlotSearching block disable 
** Parameter:   none
** Return:      TRUE
******************************************************************************/

BOOLEAN ApaSlotSearching_DisablePressedFlag(void);



#endif
