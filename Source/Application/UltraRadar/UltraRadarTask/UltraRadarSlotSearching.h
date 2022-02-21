/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                			     *
*                 All Rights Reserved.                                 						     *
*   Department : CT_ITTI_HZ                                         						     *
*   AUTHOR     :                                       									     *
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
* Version       	Date    			Name    			Changes and comments
* ----------------------------------------------------------------------
* 0.1    		Aug 28,2018          Zheng Xiaolei 		init version
*======================================================*/
#ifndef ULTRA_RADAR_SLOT_SEARCHING_H
#define ULTRA_RADAR_SLOT_SEARCHING_H

/**** Definition of constants ****/
#define APACarPassTheSlotConfirmDis	6000	/* mm */ 

/**** Definition of macros ****/

/**** Declaration of constants ****/
typedef enum
{
	SlotSearching_None,
	SlotSearching_Left,
	SlotSearching_Right
}SlotSearchingDirection;

/**** Declaration of variables ****/

/**** Declaration of functions ****/
void UltraRadarSlotSearchingHandlerMsg(void);
extern void UltraRadarSlotSearchingSlotOutLineMsg(void);

#endif /*ULTRA_RADAR_SLOT_SEARCHING_H*/
/****************************** END OF FILE ***************************/
