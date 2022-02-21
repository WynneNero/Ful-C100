/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   :            										   *
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
* Version       Date                Name            Changes and comments
* 0.1           2015/12/22    ShangQiiuju       init version
*=====================================================================*/
#ifndef _CAN_DIAG_DTC_DIAG_H_
#define _CAN_DIAG_DTC_DIAG_H_
#include "config.h"
//#ifdef CAN_DIAG_OPTION
/**** Definition of constants ****/

#include "CanDiagDtc.h"

#define DIAG_NM_TIMEOUT_NOT_USE_IL_TIMEOUT_FLAG
#define DIAG_INNER_COMMUNICATION
#define DIAG_AVM_CALIBRATION
#define USE_AD_CHECK_POWER
#define DTC_AGING_COUNTER
//#define NOT_DIAG_SYS_POWER
//#define NOT_DIAG_CAN_BUSOFF

#define DTC_STATUS_AGING_CNT_HEALING      39
#define DTC_STATUS_AGING_CNT_RESET        0
#define DTC_STATUS_OCCURRENCE_CNT_MAX     255
#define DTC_STATUS_OCCURRENCE_CNT_RESET   0
#define DTC_STATUS_AGED_CNT_MAX           255
#define DTC_STATUS_AGED_CNT_RESET         0

#define DTC_LOST_EMS_NUM	0
#define DTC_LOST_TCU_NUM	3
#define DTC_LOST_ACU_NUM	4
#define DTC_LOST_ESC_NUM	5
#define DTC_LOST_MMI_NUM	8
#define DTC_LOST_VCU_NUM	9
#define DTC_LOST_EPS_NUM	10

#define DTC_aging_AND_aged				0x07
#define DTC_aging_ADD					0x01
#define DTC_aged_ADD					0x02
#define DTC_Snapshoot_ADD				0x04
/**** Definition of types ****/ 
typedef enum DTC_CODE_NUM_TYPE_TAG
{
	DTC_FRONT_CAMERA_OPEN_CIRCUIT, 					   //B1A8113 
	DTC_LEFT_CAMERA_OPEN_CIRCUIT,					   //B1A8213
	DTC_RIGHT_CAMERA_OPEN_CIRCUIT, 					   //B1A8313
	DTC_BACK_CAMERA_OPEN_CIRCUIT,					   //B1A8413 
	DTC_FRONT_CAMERA_SHORT_GND,						   //B1A8511
	DTC_FRONT_CAMERA_SHORT_BAT,						   //B1A8512
	DTC_BACK_CAMERA_SHORT_GND, 						   //B1A8611
	DTC_BACK_CAMERA_SHORT_BAT, 						   //B1A8612
	DTC_LEFT_CAMERA_SHORT_GND, 						   //B1A8711
	DTC_LEFT_CAMERA_SHORT_BAT, 						   //B1A8712
	DTC_RIGHT_CAMERA_SHORT_GND,						   //B1A8811
	DTC_RIGHT_CAMERA_SHORT_BAT,						   //B1A8812   //12

	DTC_WORK_OVER_VOLTAGE, 							   //B1A8017
	DTC_WORK_BELOW_VOLTAGE,							   //B1A8016  
	DTC_AVM_CALIBRATION_TROUBLE,					   //B1A8948 
	DTC_AVM_SYSTEM_ERROR,							   //B1A8A1C   //16

	DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_FAULT,      //B1A4C02  
	DTC_REAR_RIGHT_LATERAL_UT_SENSOA_FAULT,            //B1A4D02    
	DTC_REAR_RIGHT_UT_SENSOA_FAULT,                    //B1A4E02    
	DTC_REAR_LEFT_UT_SENSOA_FAULT,                     //B1A4F02    
	DTC_REAR_LEFT_LATERAL_UT_SENSOA_FAULT,             //B1A5002    
	DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_FAULT,       //B1A5102    
	DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_FAULT,     //B1A5202    
	DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_FAULT,           //B1A5302    
	DTC_FRONT_RIGHT_UT_SENSOA_FAULT,                   //B1A5402    
	DTC_FRONT_LEFT_UT_SENSOA_FAULT,                    //B1A5502    
	DTC_FRONT_LEFT_LATERAL_UT_SENSOA_FAULT,            //B1A5602    
	DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_FAULT,      //B1A5702  //27

	DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_INVALID, //B1A4C53
	DTC_REAR_RIGHT_LATERAL_UT_SENSOA_INVALID,       //B1A4D53
	DTC_REAR_RIGHT_UT_SENSOA_INVALID, 				//B1A4E53              
	DTC_REAR_LEFT_UT_SENSOA_INVALID,      			//B1A4F53          
	DTC_REAR_LEFT_LATERAL_UT_SENSOA_INVALID, 		//B1A5053       
	DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_INVALID,  //B1A5153
	DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_INVALID,//B1A5253
	DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_INVALID,      //B1A5353   
	DTC_FRONT_RIGHT_UT_SENSOA_INVALID,    			//B1A5453          
	DTC_FRONT_LEFT_UT_SENSOA_INVALID,     			//B1A5553          
	DTC_FRONT_LEFT_LATERAL_UT_SENSOA_INVALID,		//B1A5653   
	DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_INVALID, //B1A5753  //39
	
	DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT, //B1A4C56  
	DTC_REAR_RIGHT_LATERAL_UT_SENSOA_TYPE_FAULT,       //B1A4D56  
	DTC_REAR_RIGHT_UT_SENSOA_TYPE_FAULT,               //B1A4E56  
	DTC_REAR_LEFT_UT_SENSOA_TYPE_FAULT,                //B1A4F56  
	DTC_REAR_LEFT_LATERAL_UT_SENSOA_TYPE_FAULT,        //B1A5056  
	DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT,  //B1A5156  
	DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT,//B1A5256  
	DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_TYPE_FAULT,      //B1A5356  
	DTC_FRONT_RIGHT_UT_SENSOA_TYPE_FAULT,              //B1A5456  
	DTC_FRONT_LEFT_UT_SENSOA_TYPE_FAULT,               //B1A5556  
	DTC_FRONT_LEFT_LATERAL_UT_SENSOA_TYPE_FAULT,       //B1A5656  
	DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT, //B1A5756  //51

	
	DTC_PUBLILC_CAN_BUS_ERROR, 	    				   //U003788
	DTC_PRIVATE_CAN_BUS_ERROR, 	    				   //U007788
	DTC_LOST_HU_MESSAGE,							   //U124587  
	DTC_LOST_ADV_NODE,							   		//U024387   //61
	DTC_LOST_GW_NODE,								   //U014687  
	DTC_LOST_ESP_WITCH_APB_MESAGE,					   //U112187   //50
	DTC_LOST_BCM1_1_MESSAGE,						   //U114087  
	
	DTC_LOST_ATC_2_MESSAGE,							   //U116487  
	DTC_LOST_DDCU_1_MESSAGE,						   //U119987  
	DTC_LOST_PDCU_1_MESSAGE,						   //U120087
	DTC_LOST_RLDCU_1_MESSAGE,						   //U120187  
	DTC_LOST_RRDCU_1_MESSAGE,						   //U120287  
	//DTC_LOST_PDC_1_MESSAGE,							   //U015987  
//	DTC_LOST_DP_1_MESSAGE,							   //U114687  
	DTC_LOST_SAS_1_MESSAGE,							   //U113187 
//	DTC_LOST_PLG_1_MESSAGE,							   //U114187 
	DTC_LOST_IC_1_MESAGE,							   //U115587   //60
	DTC_LOST_TCU_MESAGE,							   //U110187   //59
	DTC_LOST_DMS_MESAGE,								//U113887
	DTC_LOST_EMS_MESAGE,								//U113887


	DTC_ESP_MESSAGE_LIVECOUNTER_ERROR,   			   //U041582  
	DTC_ESP_MESSAGE_CHECKSUM_ERROR,	  				   //U041583
	DTC_ESP_MESSAGE_SIGNAL_INVALID,	  				   //U041586
	DTC_SAS_MESSAGE_LIVECOUNTER_ERROR,   			   //U042082 	
	DTC_SAS_MESSAGE_CHECKSUM_ERROR,	  				   //U042083
	DTC_SAS_MESSAGE_SIGNAL_INVALID,	  				   //U042086  //67
	DTC_APA_ETH_1_NO_Link,	  				   		   //U144C8A  //68

	DTC_CODE_MAX_NUM,
} DTC_CODE_NUM_TYPE;

enum DTC_MESSAGE_NUM_TAG
{
	DTC_LOST_HU_MESSAGE_INDEX,      //U124587
	DTC_LOST_GW_NODE_INDEX,  		//U014687 
	DTC_LOST_ESP_MESAGE_INDEX,  	//U112187

	DTC_LOST_ATC_2_MESSAGE_INDEX,	//U116487  
//	DTC_LOST_BCM1_1_MESSAGE_INDEX,	//U114087  
	DTC_LOST_DDCU_1_MESSAGE_INDEX,	//U119987  
	DTC_LOST_PDCU_1_MESSAGE_INDEX,	//U120087  
	DTC_LOST_RLDCU_1_MESSAGE_INDEX,	//U120187  
	DTC_LOST_RRDCU_1_MESSAGE_INDEX,	//U120287  	
	//DTC_LOST_PDC_1_MESSAGE_INDEX,	//U015987  
//	DTC_LOST_DP_1_MESSAGE_INDEX,	//U114687  
	DTC_LOST_SAS_1_MESSAGE_INDEX,	//U112687 
//	DTC_LOST_PLG_1_MESSAGE_INDEX,	//U114187
	DTC_LOST_IC_1_MESSAGE_INDEX,	//U115587
	DTC_LOST_TCU_MESAGE_INDEX,		//U110187  

	DTC_MAX_NUM_INDEX,
} ;

enum MESSAGE_NUM_TYPE_TAG
{			    
	MESSAGE_ATC_2_LOST_INDEX,  	
//	MESSAGE_BCM1_1_LOST_INDEX,  					
	MESSAGE_DDCU_1_LOST_INDEX,	
	MESSAGE_PDCU_1_LOST_INDEX,	
	MESSAGE_RLDCU_1_LOST_INDEX,	
	MESSAGE_RRDCU_1_LOST_INDEX,
	//MESSAGE_PDC_1_LOST_INDEX,	
//	MESSAGE_DP_1_LOST_INDEX,	
	MESSAGE_SAS_1_LOST_INDEX,  
//	MESSAGE_PLG_1_LOST_INDEX,
	MESSAGE_IC_1_LOST_INDEX,
	MESSAGE_TCU_LOST_INDEX,  
	MESSAGE_DMS_LOST_INDEX,
	MESSAGE_EMS_LOST_INDEX,
    MESSAGE_TIMEOUT_TYPE_NUMBER,
};
	
enum MESSAGE_TIMEOUT_FOR_GW_NODE_LOST
{
	ABS_1_MESSAGE,   
	ABS_2_MESSAGE, 
	ESP_2_MESSAGE, 
	ATC_2_MESSAGE, 
//	DP_1_MESSAGE, 	
	BCM1_1_MESSAGE,  
	BCM1_2_MESSAGE,
	DDCU_1_MESSAGE, 
	DMS_2_MESSAGE,    
	EMS_3_MESSAGE,
	GW_CONFIG_MESSAGE,
	MCP_1_MESSAGE,
	HU_5_MESSAGE, 
	HU_6_MESSAGE,
	HU_20_MESSAGE,
	HU_Speech1_MESSAGE,
	IC_1_MESSAGE, 
	PDCU_1_MESSAGE, 
	PLG_1_MESSAGE,
	RLDCU_1_MESSAGE,
	RRDCU_1_MESSAGE,      
	SAS_1_MESSAGE,      
	TCU_3_MESSAGE, 
	GW_MESSAGE_MONITOR_MAX,
};


enum MESSAGE_TIMEOUT_FOR_ADV_NODE_LOST
{
	ADV_1_MESSAGE,   
	ADV_PathTracing_MESSAGE, 
	ADV_TargetTracing_MESSAGE, 
	ADV_MESSAGE_MONITOR_MAX,
};


enum MESSAGE_TIMEOUT_FOR_BCM1_NODE_LOST
{
	BCM1_1_MESSAGE_BCM1,  
	BCM1_2_MESSAGE_BCM1,
	PLG_1_MESSAGE_BCM1,
	BCM1_MESSAGE_MONITOR_MAX,
};


enum FID_DEFINITION_TYPE
{
	ABS_1_MESSAGE_MISSING_FID_INDEX,
	ABS_2_MESSAGE_MISSING_FID_INDEX,
	ESP_2_MESSAGE_MISSING_FID_INDEX,
	HU_5_MESSAGE_MISSING_FID_INDEX,
	IC_1_MESSAGE_MISSING_FID_INDEX,
	ABS_1_LIVECOUNTER_ERR_FID_INDEX,
	ABS_2_LIVECOUNTER_ERR_FID_INDEX,
	ESP_2_LIVECOUNTER_ERR_FID_INDEX,
	ABS_1_CHECKSUM_ERR_FID_INDEX,
	ABS_2_CHECKSUM_ERR_FID_INDEX,
	ESP_2_CHECKSUM_ERR_FID_INDEX,
	WHEEL_FL_INVALID_FID_INDEX,
	WHEEL_FR_INVALID_FID_INDEX,
	WHEEL_RL_INVALID_FID_INDEX,	
	WHEEL_RR_INVALID_FID_INDEX,
	VEHICLE_SPPED_INVALID_FID_INDEX,
	FID_DEFINITION_MAX_INDEX,
};


enum MESSAGE_TIMEOUT_FOR_ESP_MESSAGE_LOST
{
	ABS_1_MESSAGE_1,
	ABS_2_MESSAGE_1,
	ESP_2_MESSAGE_1,
	ESP_MESSAGE_MONITOR_MAX,
};

enum MESSAGE_TIMEOUT_FOR_HU_MESSAGE_LOST
{
	HU_5_MESSAGE_1, 
	HU_6_MESSAGE_1,
	HU_20_MESSAGE_1,
	HU_Speech1_MESSAGE_1,
	HU_MESSAGE_MONITOR_MAX,
};

enum MESSAGE_CONTENT_FAULT
{
	ABS_1_MESSAGE_CONTENT_FAULT_INDEX,
	ABS_2_MESSAGE_CONTENT_FAULT_INDEX,
	ESP_2_MESSAGE_CONTENT_FAULT_INDEX,
	SAS_1_MESSAGE_CONTENT_FAULT_INDEX,
	MESSAGE_CONTENT_FAULT_MAX,
};

enum
{
	NUM_DTC_USS_FAILURE_RRS,  
	NUM_DTC_USS_FAILURE_RR,  
	NUM_DTC_USS_FAILURE_RRM, 
	NUM_DTC_USS_FAILURE_RLM, 
	NUM_DTC_USS_FAILURE_RL,
	NUM_DTC_USS_FAILURE_RLS, 
	NUM_DTC_USS_FAILURE_FRS, 
	NUM_DTC_USS_FAILURE_FR,  
	NUM_DTC_USS_FAILURE_FRM,  
	NUM_DTC_USS_FAILURE_FLM,  
	NUM_DTC_USS_FAILURE_FL, 
	NUM_DTC_USS_FAILURE_FLS, 
	NUM_DTC_USS_FAILURE_MAX,
};

#define DTC_BIT30					30
#define DTC_CODE_MAX_NUM1			(DTC_CODE_MAX_NUM - (DTC_BIT30 * 2))

#define VEHICLESPEED_DTC_SNAPSHOT_DATAIDENTIFIER      0x0100
#define ODOMETER_DTC_SNAPSHOT_DATAIDENTIFIER          0x0101
#define SUPPLYVOLTAGE_DTC_SNAPSHOT_DATAIDENTIFIER     0x0102

#define DTC_OCCURRENCE_CNT        0x01
#define DTC_AGING_CNT			  0x02	
#define DTC_AGED_CNT              0x03
#define DTC_FID                   0x04
#define ALL_EXTENDED_DATA_RECORDS 0xFF

#define DTC_SNAPSHOT_RECORD_NUMBER 0x01
#define DTC_SNAPSHOT_RECORD_NUMBER_OF_IDENTIFIERS 0x03
#define DTC_SNAPSHOT_RECORD_NUMBER_LEN 19

#define CANDTC_CIRCUIT_CHECK_START_INDEX 	DTC_FRONT_CAMERA_OPEN_CIRCUIT
#define CANDTC_CIRCUIT_CHECK_END_INDEX 		DTC_WORK_OVER_VOLTAGE
#define CANDTC_CIRCUIT_CHECK_TYPE_NUMBER 	(CANDTC_CIRCUIT_CHECK_END_INDEX+1-CANDTC_CIRCUIT_CHECK_START_INDEX)

#define USS_FAILURE_SENSOA_FAULT_START_INDEX        DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_FAULT
#define USS_FAILURE_SENSOA_INVALID_START_INDEX  	DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_INVALID
#define USS_FAILURE_SENSOA_TYPE_FAULT_START_INDEX   DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT


#define NM_TIMEOUT_START_INDEX  DTC_LOST_ATC_2_MESSAGE

#define DTC_LIVECOUNTER_SAME_COUNTERS_ERROR_NUM  4  //same counts are received
#define DTC_LIVECOUNTER_GREATER_THAN2_COUNTERS_ERROR_NUM  3  //Two consecutive cycles counter values are greater than 2
#define DTC_LIVECOUNTER_RECOVER_NUM 2
#define DTC_CHECKSUM_ERROR_NUM  3

#define BUS_OFF_CONFIRM_TIMES  14 //bus-off continuous 3 times are detected(150MS)
/**** Definition of macros ****/
/*
Bit0  testFailed                            M 
Bit1  testFailedThisOperationCycle          U     /    M for aging
Bit2  pendingDTC                            U 
Bit3  confirmedDTC                          M 
Bit4  testNotCompletedSinceLastClear        U
Bit5  testFailedSinceLastClear              U 
Bit6  testNotCompletedThisOperationCycle    U     /    M for aging
Bit7  WarningIndicator                      U
*/
#define DTC_STATUS_AVAILABILITY_MASK    (DTC_STATUS_BIT0_MASK_TF|DTC_STATUS_BIT3_MASK_CDTC|DTC_STATUS_BIT6_MASK_TNCTOC)///0x49
#define DTC_FORMAT_INDENTIFIER 0x00     //ISO15031-6DTC format

/**** Declaration of constants ****/
#define DTC_STATUS_SVC14_CLEAR_FINISHED (DTC_CODE_MAX_NUM+1)
#define DTC_STATUS_SVC14_CLEAR_START 0
#define DTC_NETWORK_GRP_START   DTC_PUBLILC_CAN_BUS_ERROR 

/* ECU operation Voltage low:7~9v */
/* Monitor cycle: 10ms. It means checking the volt for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_OP_VOLT_LOW 1 /*10ms = 10*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_OP_VOLT_LOW_CNT_MAX 42
#define DTC_CLR_OP_VOLT_LOW_CNT_MAX 42

/* ECU operation Voltage high:16~18v */
/* Monitor cycle: 10ms. It means checking the volt for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_OP_VOLT_HIGH 1 /*10ms = 1s*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_OP_VOLT_HIGH_CNT_MAX 42
#define DTC_CLR_OP_VOLT_HIGH_CNT_MAX 42


/* transceiver error monitor */
/* Monitor cycle: 10ms. It means checking for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_TRANSCEIVER_ERR 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_TRANSCEIVER_ERR_CNT_MAX 10
#define DTC_CLR_TRANSCEIVER_ERR_CNT_MAX 10

#ifdef DIAG_INNER_COMMUNICATION
#define DTC_CHECK_MONITOR_CYCLE_INNERCOMMU_ERR 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_INNERCOMMU_ERR_CNT_MAX 10
#define DTC_CLR_INNERCOMMU_ERR_CNT_MAX 10
#endif

#ifdef DIAG_AVM_CALIBRATION
#define DTC_CHECK_MONITOR_CYCLE_AVM_CALIBRATION_ERR 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_AVM_CALIBRATION_ERR_CNT_MAX 10
#define DTC_CLR_AVM_CALIBRATION_ERR_CNT_MAX 10
#endif

/* bus off monitor */
/* Monitor cycle: 10ms. It means checking for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_BUS_OFF 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_BUS_OFF_CNT_MAX 1   //bus-off continuous 3 times are detected(150MS)
#define DTC_CLR_BUS_OFF_CNT_MAX 1

/* camera fault monitor */
/* Monitor cycle: 10ms. It means checking for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_CIRCUIT_FAULT 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_CIRCUIT_FAULT_CNT_MAX      10
#define DTC_CLR_CIRCUIT_FAULT_CNT_MAX      10
#define DTC_SET_CIRCUIT_SHORT_CNT_MAX 	    5	/*100ms=5*20ms*/
#define DTC_CLR_CIRCUIT_SHORT_CNT_MAX 	    5
#define DTC_SET_CIRCUIT_OPEN_CNT_MAX 	    50	/*1000ms=50*20ms*/
#define DTC_CLR_CIRCUIT_OPEN_CNT_MAX 	    50
#define DTC_SET_VIDEO_STREAM_FAULT_CNT_MAX 	5	/*100ms=5*20ms*/
#define DTC_CLR_VIDEO_STREAM_FAULT_CNT_MAX 	5

/* hardkey fault monitor */
/* Monitor cycle: 20ms. It means checking for each 10ms */
/* Set condition max checking counter:20 */
/* Clear condition max checking counter:20 */
#define DTC_CHECK_MONITOR_CYCLE_ONOFF_KEY_ERR 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_ONOFF_KEY_ERR_CNT_MAX 10
#define DTC_CLR_ONOFF_KEY_ERR_CNT_MAX 10

/* LED fault monitor */
/* Monitor cycle: 20ms. It means checking for each 10ms */
/* Set condition max checking counter:20 */
/* Clear condition max checking counter:20 */
#define DTC_CHECK_MONITOR_CYCLE_LED_ERR 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_LED_ERR_CNT_MAX 	25
#define DTC_CLR_LED_ERR_CNT_MAX 	5

/* temp status monitor */
/* Monitor cycle: 10ms. It means checking for each 10ms */
/* Set condition max checking counter:10 */
/* Clear condition max checking counter:10 */
#define DTC_CHECK_MONITOR_CYCLE_TEMP_FAULT 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_TEMP_FAULT_CNT_MAX 10
#define DTC_CLR_TEMP_FAULT_CNT_MAX 10

/* Lost Communications with other nodes */
/* Monitor cycle: 10ms. It means checking the timeout flag from IL for each 10ms, jus the same as task-clycle */
/* Set condition max checking counter:1 */
/* Clear condition max checking counter:1 */
#define DTC_CHECK_MONITOR_CYCLE_LOST_COMM 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_LOST_COMM_CNT_MAX 1
#define DTC_CLR_LOST_COMM_CNT_MAX 1

#define DTC_CHECK_MONITOR_CYCLE_USS_FAILURE 1 /*10ms = 1*CAN_DIAG_TASK_SCHEDULE_TIME */
#define DTC_SET_SENSOR_FAULT_CNT_MAX 1
#define DTC_CLR_SENSOR_FAULT_CNT_MAX 30

#define DTC_SET_SENSOR_TYPE_FAULT_CNT_MAX 1
#define DTC_CLR_SENSOR_TYPE_FAULT_CNT_MAX 9

#define DTC_SET_SENSOR_NO_EFFICACY_CNT_MAX 1
#define DTC_CLR_SENSOR_NO_EFFICACY_CNT_MAX 30

#define DTC_SET_ETH_NO_LINK_CNT_MAX 25  //500MS
#define DTC_CLR_ETH_NO_LINK_CNT_MAX 1    


/**** Declaration of constants ****/
#define CAN_DIAG_TASK_SCHEDULE_TIME 10 /* 10ms */

/* All dtc diag delay */
#define CAN_DIAG_INIT_DELAY_TIME    25 /* 500ms = 50*CAN_DIAG_TASK_SCHEDULE_TIME */
#define CAN_DIAG_INIT_DELAY_TIMEOUT 0

/* Network related dtc diag delay */
#define CAN_DIAG_NM_INIT_DELAY_TIME    250 /* 5000ms = 150*CAN_DIAG_TASK_SCHEDULE_TIME */
#define CAN_DIAG_NM_INIT_DELAY_TIMEOUT 0

/* Cemra Video Reset dtc diag delay */
#define CAN_DIAG_DTC_CEMEAR_DELAY_TIME    25 /* 500ms = 50*CAN_DIAG_TASK_SCHEDULE_TIME */
#define CAN_DIAG_DTC_CEMEAR_DELAY_TIMEOUT 0

/*Network ign on related dtc diag delay*/
#define CAN_DIAG_NM_IGN_ON_DELAY_TIME    82   /* 1700ms */
#define CAN_DIAG_NM_IGN_ON_DELAY_TIMEOUT 0

 /*Network wake up related dtc diag delay*/
#define CAN_DIAG_WAKE_UP_DELAY_TIME     82   /* 1700ms */
#define CAN_DIAG_WAKE_UP_DELAY_TIMEOUT  0

#define CAN_DIAG_BAT_VOLT_RECOVER_DELAY_TIME    35    /*voltage threshold recover delay, 700ms = 35*20ms */
#define CAN_DIAG_BAT_VOLT_RECOVER_DELAY_TIMEOUT  0

#define CAN_DIAG_BUSOFF_RECOVER_DELAY_TIME   50  /* about 1s */
#define CAN_DIAG_BUSOFF_RECOVER_DELAY_TIMEOUT 0

#define CAN_DIAG_ETHNOTLINK_DELAY_TIME   500  /* 10s */
#define CAN_DIAG_ETHNOTLINK_DELAY_TIMEOUT 0


#define VOLTAGE_DET_9V   1538//1599   //9V
#define VOLTAGE_DET_9V5  1638//1700   //9.5V
#define VOLTAGE_DET_16V  2919   //16V 
#define VOLTAGE_DET_15V5 2825   //15.5v

 typedef  struct
{
	U8  Snapshot0102_SupplyVoltage;
	U16 Snapshot0100_VehicleSpeed;
	U32 Snapshot0101_Odometer;
}DTC_SNAPSHOT_RECORD_IDENTIFIERS;


/**** Declaration of functions ****/
extern const DTC_CODE_DATA_TYPE dtc_code_data[DTC_CODE_MAX_NUM];
extern DTC_RECORD_TYPE dtc_status_record[DTC_CODE_MAX_NUM];
extern DTC_RECORD_CNT_TYPE dtc_status_record_cnt[DTC_CODE_MAX_NUM];
extern BOOL bSetClearHistoryFaultCntFlag[DTC_CODE_MAX_NUM];
extern U8 dtc_status_occurrence_cnt[DTC_CODE_MAX_NUM];
extern U8 dtc_status_aging_cnt[DTC_CODE_MAX_NUM];
extern U8 dtc_status_aged_cnt[DTC_CODE_MAX_NUM];
extern DTC_SNAPSHOT_RECORD_IDENTIFIERS dtc_snapshot_record[DTC_CODE_MAX_NUM];
extern DTC_SNAPSHOT_RECORD_IDENTIFIERS Signal_Snapshot_Data;

extern  DTC_USS_FAILURE USS_FailureSta[NUM_DTC_USS_FAILURE_MAX];

extern BOOL bMessageLostStaForGWNodeLost[GW_MESSAGE_MONITOR_MAX];
extern U8 uMessageTimeOutCntForGWNodeLost[GW_MESSAGE_MONITOR_MAX];
extern BOOL bMessageLostStaForADVNodeLost[ADV_MESSAGE_MONITOR_MAX];
extern U8 uMessageTimeOutCntForADVNodeLost[ADV_MESSAGE_MONITOR_MAX];

extern BOOL bMessageLostForESPMissing[ESP_MESSAGE_MONITOR_MAX];
extern U8 uMessageTimeOutCntForESPMissing[ESP_MESSAGE_MONITOR_MAX];
extern BOOL bMessageLostForHUMissing[HU_MESSAGE_MONITOR_MAX];
extern U8 uMessageTimeOutCntForHUMissing[HU_MESSAGE_MONITOR_MAX];
extern BOOL bMessageTimeOutStatus[MESSAGE_TIMEOUT_TYPE_NUMBER];
extern U16 uMessageTimeOutCnt[MESSAGE_TIMEOUT_TYPE_NUMBER];
extern U16 uMessageTimeoutStartTime[MESSAGE_TIMEOUT_TYPE_NUMBER];
extern DTC_MESSAGE_CONTENT_FAULT tagMessageContentFault[MESSAGE_CONTENT_FAULT_MAX];
extern U8 FID_Definition[FID_DEFINITION_MAX_INDEX];
extern U8 dtc_status_fid_data[DTC_CODE_MAX_NUM];
extern BOOL bMessageLostForBCM1Missing[BCM1_MESSAGE_MONITOR_MAX];
extern U8 uMessageTimeOutCntForBCM1Missing[BCM1_MESSAGE_MONITOR_MAX];
#endif
