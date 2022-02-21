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
* 
*======================================================*/
#ifndef ULTRA_RADAR_OBJ_DETECT_H
#define ULTRA_RADAR_OBJ_DETECT_H

/**** Definition of constants ****/
#define WARN_OPEN   0x01
#define WARN_CLOSE  0x00

#define WARN_FZ_1HZ 0x00
#define WARN_FZ_2HZ 0x01
#define WARN_FZ_4HZ 0x03
#define WARN_FZ_LONG 0x02

typedef enum{
	OUT_OF_BOUNDS = 0,
	LEVEL_A,
	LEVEL_B,
	LEVEL_C,
	LEVEL_D	 
}USS_WARNNING_LEVEL;

typedef enum
{
   ULTRA_SNS_SEND=1,
   ULTRA_SNS_RECV=2,
   ULTRA_SNS_NONE=3
}ULTRA_SNS_WORK_MODE;

/**** Definition of macros ****/
#define GetPAsysWarnZone(sysType,region,zone)  (U8)((sysType<<7)|(region<<4)|zone)

/**** Declaration of constants ****/

/**** Declaration of variables ****/

/**** Declaration of functions ****/
void UltraRadarGetNearestObjDisMsg(void);
void UltraRadarDetectWarnZoneTask(void);
void UltraRadar_BuzzerAlarm_Cyclic_Task(void);
void UltraRadarSendSoftWareVersion(void);
void UltraRadarReadSnsConfigPara(void);


#endif /*ULTRA_RADAR_OBJ_DETECT_H*/
/****************************** END OF FILE ***************************/
