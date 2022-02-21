#ifndef __PDC_CTRL_H
#define __PDC_CTRL_H

#include "ussLibIf.h"

#define PDC_ENABLE 	TRUE
#define PDC_DISABLE FALSE

typedef enum
{
    PDC_DISTANCE_SEND_MODE_STANDBY,
    PDC_DISTANCE_SEND_MODE_F6,
    PDC_DISTANCE_SEND_MODE_R6,
    PDC_DISTANCE_SEND_MODE_F6R6,
}PDC_DISTANCE_SEND_MODE;
    
typedef enum 
{
    PDC_RADAR_ACTIVE_MODE_UNKNOW,
    PDC_RADAR_ACTIVE_FORCE_ON,
    PDC_RADAR_FRONT_FAIL_REAR_ACTIVE,
    PDC_RADAR_FRONT_ACTIVE_REAR_FAIL,
    PDC_RADAR_FRONT_FAIL_REAR_FAIL,
    PDC_RADAR_FRONT_ACTIVE_REAR_ACTIVE,
}PDC_RADAR_ACTIVE_MODE_TYPE;

typedef enum
{
    PDC_WARNING_SOUND_AUTOON_MODE,
    PDC_DISTANCE_SEND_NORMAL_MODE,
}PDC_WARNING_SOUND_MODE;

enum CAN_PDC_BuzzerControl
{
	INACTIVE  = 0x0,
    LEVEL1,	
    LEVEL2, 
    LEVEL3,	
    SELFCHECKERRORTONE, 
    SELFCHECKOKTONE,
    LEVEL4,
    LEVEL5,
};

enum CAN_BuzzerAlarmPosition
{
	BuzzerAlarmPosition_Off,
	BuzzerAlarmPosition_Front,
	BuzzerAlarmPosition_Rear,
	BuzzerAlarmPosition_SelfCheck,
	BuzzerAlarmPosition_FrontRear,
	BuzzerAlarmPosition_Reserved,
};

typedef enum 
{
	PDC_Switch_Unkonw,
	PDC_Switch_On,
    PDC_Switch_Off,
}PDC_SWITCH;


void pdcCtrlOpen(void);
void pdcCtrlTask5ms(void);
void pdcDetectStart(void);
void pdcDetectStop(void);
void setPdcEnableFlag(U8 flag);

//extern unsigned int Get_App_USS_System_Failure_Status(void);
void pdcDistanceUpdate(E_APA_PDCMode_Status      mode);
void pdcSystemStatusUpdate(E_APA_PDCMode_Status mode);


void updatePdcStatusToAvm(void);
void clrRadarFaultFlag(void);

#endif

