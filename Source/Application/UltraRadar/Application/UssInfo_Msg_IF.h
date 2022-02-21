
/*------------------------------------------------------------------------------

    File Name: RadarMsg_IF.h

    Interface to USS algorithm.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    LinFeng       uidp5358       Desay SV HZH / IDA R&D

--------------------------------------------------------------------------------
                      R E V I S I O N   H I S T O R Y
--------------------------------------------------------------------------------
    Date           Ver       Author      Description
    ----------     ---       ------      --------------------------------------------
	2019-08-014    1.0      uidp5358     first version 
--------------------------------------------------------------------------------
                           C O P Y R I G H T
--------------------------------------------------------------------------------
         Copyright (c) 2019 by Huizhou Desay SV Automotive Co., Ltd.
                          All rights reserved.
------------------------------------------------------------------------------*/
#ifndef _USS_INFO_MSG_IF_H_
#define _USS_INFO_MSG_IF_H_

#include "ObjDetectCommonDefine.h"
#include "UltraRadarDriver.h"
#include "UssInfoMsg.h"



/*********************************************************************
enum UssFailureStatus

USS_ISR_TRIGGER_FAILURE: include short to battery or short to ground or sensor open
USS_INITIALIZE_FAILURE: means initialize failure
USS_RING_TIMER_ABNORMAL: ring time too long or too short
USS_OTHER_FAILURE: include sensors be blocked or signal error or signal disturbed

*********************************************************************/
typedef enum
{
	USS_SENSOR_SHORT_TO_GND,
	USS_SENSOR_SHORT_TO_BAT,
	USS_SIGNAL_INVALID,
	USS_NO_SIGNAL,
	USS_SIGNAL_ERROR,
	USS_COMPNENT_ERROR,
	USS_RING_TIME_ERROR,
	USS_SENSOR_MISS_MATCH,
//	USS_DISCONNECTED,
	USS_DIAG_RESERVE
}UssFailureStatus;


typedef struct
{
	unsigned short UssSensorShortToGnd :1;
	unsigned short UssSensorShortToBattery :1;
	unsigned short UssSignalInvalid :1;
	unsigned short UssNoSignal :1;
	unsigned short UssSignalError :1;
	unsigned short UssCompnentError :1;
	unsigned short UssRingTimeError :1;
	unsigned short UssSensorMissMatch :1;
//    unsigned short UssDisconnected :1;
	unsigned short UssDiagReserve :8;
}DtcItem;

typedef union
{
	unsigned short DtcByte;
	struct
	{
		unsigned short UssSensorShortToGnd :1;
		unsigned short UssSensorShortToBattery :1;
		unsigned short UssSignalInvalid :1;
		unsigned short UssNoSignal :1;
		unsigned short UssSignalError :1;
		unsigned short UssCompnentError :1;
		unsigned short UssRingTimeError :1;
		unsigned short UssSensorMissMatch :1;
//        unsigned short UssDisconnected :1;
		unsigned short UssDiagReserve :8;
	}DtcItem;
}DtcTypedef;

enum
{	
	SENSOR_RRS, 
	SENSOR_RR,
	SENSOR_RRM,
	SENSOR_RLM,
	SENSOR_RL,
	SENSOR_RLS,
	SENSOR_FRS,
	SENSOR_FR,
	SENSOR_FRM,
	SENSOR_FLM,
	SENSOR_FL,
	SENSOR_FLS,
	SENSOR_TOTAL_INDEX
};




/*************************************************************
    * Function Name: unsigned char DiagGetUssSenorDistanceValue(PASysSnsIndexType Sensor)
    * Description  : Diagnostic get the USS distance value use for $22
    * functional adaption: diagnostic
    * Parameters   : PASysSnsIndexType Sensor (PASysSnsIndexType indicate the number of sensors)
    * Return Value : unsigned char (0x00~0xFF indicate the distance  unit:cm)
*****************************************************************/
extern unsigned short DiagGetUssSenorDistanceValue(PASysSnsIndexType Sensor);

/*************************************************************
    * Function Name: VehiclePdcWorkingState DiagGetUssWorkingState(void)
    * Description  : Diagnostic get the USS working state use for $22
    * functional adaption: diagnostic
    * Parameters   : void
    * Return Value : VehiclePdcWorkingState
*****************************************************************/
extern VehiclePdcWorkingState DiagGetUssWorkingState(void);
extern PAS_Work_Status DiagGetPasWorkingState(void);
extern PAS_Warning_Tone DiagGetPasWarningState(void);




#endif

