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
#ifndef ULTRA_RADAR_BASIC_TASK_H
#define ULTRA_RADAR_BASIC_TASK_H

/**** Definition of constants ****/

/**** Definition of macros ****/

/**** Declaration of constants ****/

/**** Declaration of variables ****/

/**** Declaration of functions ****/
extern void UltraRadarFastTaskEntry(void);
extern void UltraRadarSlowTaskEntry(void);
extern void Com_RxSignalSW( unsigned char SignalID_u8, signed short * SignalValue_ps16);
extern void Com_RxSignalUW( unsigned char SignalID_u8, unsigned short *SignalValue_pu16 );
extern void Com_RxSignalUB( unsigned char SignalID_u8, unsigned char *SignalValue_pu8 );
extern unsigned char IlGetWhlPlsPerRevNonDrvn_1Indication(void);
extern void IlClrWhlPlsPerRevNonDrvn_1Indication(void);

#endif /*ULTRA_RADAR_BASIC_TASK_H*/
/****************************** END OF FILE ***************************/
