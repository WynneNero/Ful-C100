#ifndef _OBJDETECTSTATEMACHINE_H_
#define _OBJDETECTSTATEMACHINE_H_

#include "DataTypeDef.h"
#include "ObjDetectCommonDefine.h"

/* Process the driver inputs and determine the PA operating state */
typedef enum 
{
	PA_STATE_OFF = 0,												/* 0 */
	PA_STATE_DISABLE,												/* 1 */
	PA_STATE_FRONT_DISABLE_AND_REAR_ACTIVE,	/* 2 */
	PA_STATE_FRONT_ACTIVE_AND_REAR_DISABLE,	/* 3 */
	PA_STATE_ACTIVE_FRONT_AND_REAR,					/* 4 */
	PA_STATE_ACTIVE_FRONT,									/* 5 */
	PA_STATE_STANDBY_ENABLE,								/* 6 */
	PA_STATE_ACTIVE,												/* 7 */
	PA_IS_NOT_ENALBED,											/* 8 */
	PA_ENABLED_BY_RV_SPD_TOO_HIGH,					/* 9 */
	PA_ENABLED_BY_FRD_SPD_TOO_HIGH					/* 10 */
} tPAStateType;

typedef enum
{
	PA_IS_NOT_ACTIVE = 0,
	PA_ACTIVE_BY_VEHICLE_RV,
	PA_ACTIVE_BY_VEHICLE_FWD
} tPAActiveCausesType;

typedef enum
{
	VEHICLE_STATIC = 0,
	VEHICLE_DRIVEN_FORWARD,
	VEHICLE_DRIVEN_REVERSE
} tVehicleRunningStateType;


typedef enum
{
	PA_IS_NOT_DISABLED_INDEX = 0,
	PA_DISABLED_BY_PHY_SW_INDEX,          /* 1 */
	PA_DISABLED_BY_PRK_BRK_SW_INDEX,			/* 2 */
	PA_DISABLED_BY_CAO_INDEX,							/* 3 */
	PA_DISABLED_BY_REVERSE_OVER_SPEED_INDEX,		/* 4 */
	PA_DISABLED_BY_SIG_INVLD_INDEX,				/* 5 */
	PA_DISABLED_BY_SNS_DSTB_INDEX,				/* 6 */
	PA_DISABLED_BY_SNS_BLK_INDEX,					/* 7 */
	PA_DISABLED_BY_SNS_RING_TIME_TOO_LONG_INDEX,/* 8 */
	PA_DISABLED_BY_PA_FAIL_INDEX,					/* 9 */
	PA_DISABLED_BY_TRNS_POS_UNDEFINED_INDEX,/* 10 */
	PA_DISABLED_BY_VOLTAGE_ABNORMAL_INDEX,	/* 11 */
	PA_DISABLED_BY_DISABLE_NORMAL_COM_INDEX,/* 12 */
	PA_DISABLED_BY_UPA_INITIAL_STATE_OFF_INDEX,/* 13 */
	PA_DISABLED_BY_VEHICLE_MENU_INDEX, /* 14 */
	PA_DISABLED_BY_ESS_CONTROLLER_INHIBIT_REQ_INDEX /* 15 */

} tPADisableCausesIndexType;

#define DISABLE_CAUSES_NUM                                    17

#define GMLAN_SIGNALS_NUM																		16

typedef enum{
	TrnsShftLvrPosIndex = 0,
	SysPwrMdIndex,            /*1*/
	SysPwrMdVIndex,           /*2*/
	SysBkupPwrMdEnIndex,      /*3*/
	SysBackupPowerModeIndex,  /*4*/
	SysBackupPowerModeVIndex, /*5*/
	TrnsShftLvrPosVIndex,     /*6*/
	VehSpdAvgNDrvnVIndex,     /*7*/
	TrlrHtchSwAtvIndex,       /*8*/
	PrkBrkSwAtvIndex,         /*9*/
	TrnsVDAIndex,							/*10*/
	PrkBrkVDAIndex,			/*11*/
	EngCtrlVDAIndex,					/*12*/
	VehMovementStateIndex,      /*13*/
	RrEndCrrStatIndex,		 /*14*/
	VehSpdAvgNDrvnIndex     /* 15 */
} tGMLANSignalsValueIndexType;

#define PA_NO_FAILURE															0
#define PA_FAIL																	1
#define PA_FAIL_SENSOR_RING_TIME_TOO_LONG										2
extern    uchar cPAState;
extern    uchar cPADisableCauses;
extern    uchar cPAStandbyEnableCauses;
extern    uchar cPAActiveCauses;
extern    uchar cVehRunningState;
extern    uchar cPAFail;
extern    uchar cPADisableHistoryBuf[PA_DISABLE_HISTORY_BUF_SIZE];
extern    word wVehSpdAvgNDrvn;
extern    word wPAShutDownDelayTimer;
extern    word wPADeactiveDelayTime;
extern    uchar cUPAODIOption;
extern    uchar cUPAInitialState;
void ObjectDetectStateMachine_T10(void);
void SetParToDefaultValue(void);


#endif