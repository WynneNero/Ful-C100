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
#include "config.h"
#include "candiagdtccfg.h"
#include "can_par.h"
#include "can_def.h"
#include "EEPTable.h"

/*---Private----------------------------------------------------------*/
const DTC_CODE_DATA_TYPE dtc_code_data[DTC_CODE_MAX_NUM] = 
{
	{0x9A, 0x81, 0x13},//	DTC_FRONT_CAMERA_OPEN_CIRCUIT, 					   //B1A8113 
	{0x9A, 0x82, 0x13},//	DTC_LEFT_CAMERA_OPEN_CIRCUIT,					   //B1A8213
	{0x9A, 0x83, 0x13},//	DTC_RIGHT_CAMERA_OPEN_CIRCUIT, 					   //B1A8313
	{0x9A, 0x84, 0x13},//	DTC_BACK_CAMERA_OPEN_CIRCUIT,					   //B1A8413 
	{0x9A, 0x85, 0x11},//	DTC_FRONT_CAMERA_SHORT_GND,						   //B1A8511
	{0x9A, 0x85, 0x12},//	DTC_FRONT_CAMERA_SHORT_BAT,						   //B1A8512
	{0x9A, 0x86, 0x11},//	DTC_BACK_CAMERA_SHORT_GND, 						   //B1A8611
	{0x9A, 0x86, 0x12},//	DTC_BACK_CAMERA_SHORT_BAT, 						   //B1A8612
	{0x9A, 0x87, 0x11},//	DTC_LEFT_CAMERA_SHORT_GND, 						   //B1A8711
	{0x9A, 0x87, 0x12},//	DTC_LEFT_CAMERA_SHORT_BAT, 						   //B1A8712
	{0x9A, 0x88, 0x11},//	DTC_RIGHT_CAMERA_SHORT_GND,						   //B1A8811
	{0x9A, 0x88, 0x12},//	DTC_RIGHT_CAMERA_SHORT_BAT,						   //B1A8812   //12


	{0x9A, 0x80, 0x17},//DTC_WORK_OVER_VOLTAGE, 							   //B1A8017
	{0x9A, 0x80, 0x16},//DTC_WORK_BELOW_VOLTAGE,							   //B1A8016  
	{0x9A, 0x89, 0x48},//	DTC_AVM_CALIBRATION_TROUBLE,					   //B1A8948 
	{0x9A, 0x8A, 0x1C},//	DTC_AVM_SYSTEM_ERROR,							   //B1A8A1C   //16



	{0x9A, 0x4C, 0x02},//DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_FAULT,      //B1A4C02  
	{0x9A, 0x4D, 0x02},//DTC_REAR_RIGHT_LATERAL_UT_SENSOA_FAULT,            //B1A4D02    
	{0x9A, 0x4E, 0x02},//DTC_REAR_RIGHT_UT_SENSOA_FAULT,                    //B1A4E02    
	{0x9A, 0x4F, 0x02},//DTC_REAR_LEFT_UT_SENSOA_FAULT,                     //B1A4F02    
	{0x9A, 0x50, 0x02},//DTC_REAR_LEFT_LATERAL_UT_SENSOA_FAULT,             //B1A5002    
	{0x9A, 0x51, 0x02},//DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_FAULT,       //B1A5102    
	{0x9A, 0x52, 0x02},//DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_FAULT,     //B1A5202    
	{0x9A, 0x53, 0x02},//DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_FAULT,           //B1A5302    
	{0x9A, 0x54, 0x02},//DTC_FRONT_RIGHT_UT_SENSOA_FAULT,                   //B1A5402    
	{0x9A, 0x55, 0x02},//DTC_FRONT_LEFT_UT_SENSOA_FAULT,                    //B1A5502    
	{0x9A, 0x56, 0x02},//DTC_FRONT_LEFT_LATERAL_UT_SENSOA_FAULT,            //B1A5602    
	{0x9A, 0x57, 0x02},//DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_FAULT,      //B1A5702  

	{0x9A, 0x4C, 0x53},//DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_INVALID,    //B1A4C53
	{0x9A, 0x4D, 0x53},//DTC_REAR_RIGHT_LATERAL_UT_SENSOA_INVALID,          //B1A4D53
	{0x9A, 0x4E, 0x53},//DTC_REAR_RIGHT_UT_SENSOA_INVALID, 			        //B1A4E53              
	{0x9A, 0x4F, 0x53},//DTC_REAR_LEFT_UT_SENSOA_INVALID,      		        //B1A4F53          
	{0x9A, 0x50, 0x53},//DTC_REAR_LEFT_LATERAL_UT_SENSOA_INVALID, 		    //B1A5053       
	{0x9A, 0x51, 0x53},//DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_INVALID,     //B1A5153
	{0x9A, 0x52, 0x53},//DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_INVALID,   //B1A5253
	{0x9A, 0x53, 0x53},//DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_INVALID,         //B1A5353   
	{0x9A, 0x54, 0x53},//DTC_FRONT_RIGHT_UT_SENSOA_INVALID,    		        //B1A5453          
	{0x9A, 0x55, 0x53},//DTC_FRONT_LEFT_UT_SENSOA_INVALID,     		        //B1A5553          
	{0x9A, 0x56, 0x53},//DTC_FRONT_LEFT_LATERAL_UT_SENSOA_INVALID,		    //B1A5653  
	{0x9A, 0x57, 0x53},//DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_INVALID,    //B1A5753  
	
	{0x9A, 0x4c, 0x56},//DTC_REAR_RIGHT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT, //B1A4C56  
	{0x9A, 0x4D, 0x56},//DTC_REAR_RIGHT_LATERAL_UT_SENSOA_TYPE_FAULT,       //B1A4D56  
	{0x9A, 0x4E, 0x56},//DTC_REAR_RIGHT_UT_SENSOA_TYPE_FAULT,               //B1A4E56  
	{0x9A, 0x4F, 0x56},//DTC_REAR_LEFT_UT_SENSOA_TYPE_FAULT,                //B1A4F56  
	{0x9A, 0x50, 0x56},//DTC_REAR_LEFT_LATERAL_UT_SENSOA_TYPE_FAULT,        //B1A5056  
	{0x9A, 0x51, 0x56},//DTC_REAR_LEFT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT,  //B1A5156  
	{0x9A, 0x52, 0x56},//DTC_FRONT_RIGHT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT,//B1A5256  
	{0x9A, 0x53, 0x56},//DTC_FRONT_RIGHT_LATERAL_UT_SENSOA_TYPE_FAULT,      //B1A5356  
	{0x9A, 0x54, 0x56},//DTC_FRONT_RIGHT_UT_SENSOA_TYPE_FAULT,              //B1A5456  
	{0x9A, 0x55, 0x56},//DTC_FRONT_LEFT_UT_SENSOA_TYPE_FAULT,               //B1A5556  
	{0x9A, 0x56, 0x56},//DTC_FRONT_LEFT_LATERAL_UT_SENSOA_TYPE_FAULT,       //B1A5656  
	{0x9A, 0x57, 0x56},//DTC_FRONT_LEFT_LONG_DISTANCE_UT_SENSOA_TYPE_FAULT, //B1A5756   
	
	{0xC0, 0x37, 0x88},//DTC_PUBLILC_CAN_BUS_ERROR, 	    //U003788
	{0xC0, 0x77, 0x88},//DTC_PRIVATE_CAN_BUS_ERROR, 	    //U007788
	{0xD2, 0x45, 0x87},//DTC_LOST_HU_MESSAGE,				//U124587 
	{0xC2, 0x43, 0x87},//DTC_LOST_ADV_NODE,					//U024387   //59
	{0xC1, 0x46, 0x87},//DTC_LOST_GW_NODE,					//U014687  
	{0xD1, 0x21, 0x87},//DTC_LOST_ESP_WITCH_APB_MESAGE,		//U112187  
	{0xD1, 0x40, 0x87},//DTC_LOST_BCM1_1_MESSAGE,			//U114087
	
	{0xD1, 0x64, 0x87},//DTC_LOST_ATC_MESSAGE,				//U116487  
	{0xD1, 0x99, 0x87},//DTC_LOST_DDCU_1_MESSAGE,			//U119987  
	{0xD2, 0x00, 0x87},//DTC_LOST_PDCU_1_MESSAGE,			//U120087
	{0xD2, 0x01, 0x87},//	DTC_LOST_RLDCU_1_MESSAGE,		//U120187  
	{0xD2, 0x02, 0x87},//	DTC_LOST_RRDCU_1_MESSAGE,		//U120287 
	//{0xC1, 0x59, 0x87},//DTC_LOST_PDC_1_MESSAGE,			//U015987  
//	{0xD1, 0x46, 0x87},//DTC_LOST_DP_1_MESSAGE,				//U114687  
	{0xD1, 0x31, 0x87},//DTC_LOST_SAS_1_MESSAGE,			//U113187 
//	{0xD1, 0x41, 0x87},//DTC_LOST_PLG_1_MESSAGE,			//U114187 
	{0xD1, 0x55, 0x87},//	DTC_LOST_IC_1_MESAGE,			//U115587   //60
	{0xD1, 0x01, 0x87},//DTC_LOST_TCU_MESAGE,				//U110187
	{0xD1, 0x38, 0x87},//DTC_LOST_DMS_MESAGE,				//U113887
	{0xD1, 0x00, 0x87},//DTC_LOST_EMS_MESAGE,				//U113887


	{0xC4, 0x15, 0x82},//DTC_ESP_MESSAGE_LIVECOUNTER_ERROR,   //U041582 
	{0xC4, 0x15, 0x83},//DTC_ESP_MESSAGE_CHECKSUM_ERROR,	  //U041583
	{0xC4, 0x15, 0x86},//DTC_ESP_MESSAGE_SIGNAL_INVALID,	  //U041586
	{0xC4, 0x20, 0x82},//DTC_SAS_MESSAGE_LIVECOUNTER_ERROR,   //U042082 	
	{0xC4, 0x20, 0x83},//DTC_SAS_MESSAGE_CHECKSUM_ERROR,	  //U042083
	{0xC4, 0x20, 0x86},//DTC_SAS_MESSAGE_SIGNAL_INVALID,	  //U042086 
	{0xD4, 0x4C, 0x8A},//	DTC_APA_ETH_1_NO_Link,	  		  //U144C8A  //68
};

DTC_RECORD_TYPE dtc_status_record[DTC_CODE_MAX_NUM] = {0x00};
DTC_RECORD_CNT_TYPE dtc_status_record_cnt[DTC_CODE_MAX_NUM] = {{0x00,0x00}};
U8 dtc_status_occurrence_cnt[DTC_CODE_MAX_NUM] = {0x00};
U8 dtc_status_aging_cnt[DTC_CODE_MAX_NUM] = {0x00};
U8 dtc_status_aged_cnt[DTC_CODE_MAX_NUM] = {0x00};
U8 dtc_status_fid_data[DTC_CODE_MAX_NUM] = {0x00};

DTC_SNAPSHOT_RECORD_IDENTIFIERS dtc_snapshot_record[DTC_CODE_MAX_NUM] = {{0x00,0x00,0x00}};

BOOL bMessageLostStaForGWNodeLost[GW_MESSAGE_MONITOR_MAX]= {FALSE};
U8 uMessageTimeOutCntForGWNodeLost[GW_MESSAGE_MONITOR_MAX] = {0};

BOOL bMessageLostStaForADVNodeLost[ADV_MESSAGE_MONITOR_MAX]= {FALSE};
U8 uMessageTimeOutCntForADVNodeLost[ADV_MESSAGE_MONITOR_MAX] = {0};


BOOL bMessageLostForESPMissing[ESP_MESSAGE_MONITOR_MAX]= {FALSE};
U8 uMessageTimeOutCntForESPMissing[ESP_MESSAGE_MONITOR_MAX] = {0};

BOOL bMessageLostForHUMissing[HU_MESSAGE_MONITOR_MAX]= {FALSE};
U8 uMessageTimeOutCntForHUMissing[HU_MESSAGE_MONITOR_MAX] = {0};

BOOL bMessageLostForBCM1Missing[BCM1_MESSAGE_MONITOR_MAX]= {FALSE};
U8 uMessageTimeOutCntForBCM1Missing[BCM1_MESSAGE_MONITOR_MAX] = {0};


BOOL bMessageTimeOutStatus[MESSAGE_TIMEOUT_TYPE_NUMBER] = {FALSE};
U16 uMessageTimeOutCnt[MESSAGE_TIMEOUT_TYPE_NUMBER] = {0};
U16 uMessageTimeoutStartTime[MESSAGE_TIMEOUT_TYPE_NUMBER] =	//t=N*20MS  TIMEOUT=t*20
{
    50,	//ATC_2   
//    50,	//BCM1_1
    50,	//DDCU_1
    50,	//PDCU_1
    50,	//RLDCU_1
    50,	//RRDCU_1
    //50,	//PDC_1
//    25, //DP_1
    25,	//SAS_1   
//    50,	//PLG_1 
    50,	//IC_1 
    25,	//TCU_3
    50,	//DMS_2
    25,	//EMS_3
};

U8 FID_Definition[FID_DEFINITION_MAX_INDEX] = 
{
	0x01, //ABS_1(0xC0) is missing
	0x02, //ABS_2(0xC2) is missing
	0x03, //ESP_2(0x132) is missing
	0x04, //HU_5(0x288) is missing
	0x05, //IC_1(0x290) is missing
	0x06, //Livecounter_ABS_1: same counts are received. or Two consecutive cycles counter values are greater than 2.
	0x07, //Livecounter_ABS_2: same counts are received. or Two consecutive cycles counter values are greater than 2.
	0x08, //Livecounter_ESP_2: same counts are received. or Two consecutive cycles counter values are greater than 2.
	0x09, //Checksum_ABS_1: received and calculated values are inconsistent
	0x0A, //Checksum_ABS_2: received and calculated values are inconsistent
	0x0B, //Checksum_ESP_2: received and calculated values are inconsistent
	0x0C, //Signal invalid error: WheelSpeed_FL = Invalid Value
	0x0D, //Signal invalid error: WheelSpeed_FR = Invalid Value
	0x0E, //Signal invalid error: WheelSpeed_RL = Invalid Value
	0x0F, //Signal invalid error: WheelSpeed_RR = Invalid Value
	0x10, //Signal invalid error: VehicleSpeed = Invalid Value
};


/* USS */
DTC_USS_FAILURE USS_FailureSta[NUM_DTC_USS_FAILURE_MAX] = {{FALSE,FALSE,FALSE}};

DTC_MESSAGE_CONTENT_FAULT tagMessageContentFault[MESSAGE_CONTENT_FAULT_MAX];

BOOL bSetClearHistoryFaultCntFlag[DTC_CODE_MAX_NUM];



