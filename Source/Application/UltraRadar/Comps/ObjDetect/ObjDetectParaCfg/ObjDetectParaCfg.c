/* Global variables and const data definitions */

#include "ObjDetectParaCfg.h"
#include "InfoOutput.h"
#include "ObjDetectCommonDefine.h"
#include "UltraRadarDriver.h"

#ifdef D2XX_SUPPORT_D2UB_CAL

#define	D2XX_VEHICLE_REAR_BUMPER		

/*1.3************************************* SENSOR ASSEMBLY MACRO-DEFINITION START ********************************/
#define DISTANCE_BETWEEN_SNS_RRS_RR					505
#define DISTANCE_BETWEEN_SNS_RRS_RRM				876
#define DISTANCE_BETWEEN_SNS_RR_RRM					475
#define DISTANCE_BETWEEN_SNS_RRM_RLM				460
#define DISTANCE_BETWEEN_SNS_RL_RLM					475
#define DISTANCE_BETWEEN_SNS_RL_RLS					505
#define DISTANCE_BETWEEN_SNS_RLM_RLS				876
#define DISTANCE_BETWEEN_SNS_FRS_FR					493
#define DISTANCE_BETWEEN_SNS_FRS_FRM				794
#define DISTANCE_BETWEEN_SNS_FR_FRM					357
#define DISTANCE_BETWEEN_SNS_FRM_FLM				634
#define DISTANCE_BETWEEN_SNS_FL_FLM					357
#define DISTANCE_BETWEEN_SNS_FL_FLS					493
#define DISTANCE_BETWEEN_SNS_FLM_FLS				794

#define DELTA_HIGHT_SNS_RRS_RR						460
#define DELTA_HIGHT_SNS_RRS_RRM						561
#define DELTA_HIGHT_SNS_RR_RRM						101
#define DELTA_HIGHT_SNS_RRM_RLM						0
#define DELTA_HIGHT_SNS_RL_RLM						101
#define DELTA_HIGHT_SNS_RL_RLS						460
#define DELTA_HIGHT_SNS_RLM_RLS						561
#define DELTA_HIGHT_SNS_FRS_FR						415
#define DELTA_HIGHT_SNS_FRS_FRM						506
#define DELTA_HIGHT_SNS_FR_FRM						91 
#define DELTA_HIGHT_SNS_FRM_FLM						0
#define DELTA_HIGHT_SNS_FL_FLM						91 
#define DELTA_HIGHT_SNS_FL_FLS						415
#define DELTA_HIGHT_SNS_FLM_FLS						506

#define DELTA_H_lLENGTH_SNS_RRS_RR					209
#define DELTA_H_lLENGTH_SNS_RRS_RRM					673
#define DELTA_H_lLENGTH_SNS_RR_RRM					464
#define DELTA_H_lLENGTH_SNS_RRM_RLM					460
#define DELTA_H_lLENGTH_SNS_RL_RLM					464
#define DELTA_H_lLENGTH_SNS_RL_RLS					209
#define DELTA_H_lLENGTH_SNS_RLM_RLS					673
#define DELTA_H_lLENGTH_SNS_FRS_FR					267
#define DELTA_H_lLENGTH_SNS_FRS_FRM					612
#define DELTA_H_lLENGTH_SNS_FR_FRM					345
#define DELTA_H_lLENGTH_SNS_FRM_FLM					634
#define DELTA_H_lLENGTH_SNS_FL_FLM					345
#define DELTA_H_lLENGTH_SNS_FL_FLS					267
#define DELTA_H_lLENGTH_SNS_FLM_FLS					612
/*1.3************************************* SENSOR POSITION MACRO-DEFINITION END***********************************/

/***********************************************************************
//-------------RPA Calibration Data-------------------------------------
//
//----------------------------------------------------------------------
************************************************************************/
const unsigned long long cSnsDefCaliData_ApaControl[PA_SNS_NUM] =
{
	// SnsOpMode In avm mode and aps controling mode, and now the APA sensor just 2500mm detect distance
	/* RRS	         RR          RRM	       RLM         RL	         RLS	       FRS	        FR          FRM	        FLM           FL	       FLS */			
	0x8A22B9B4E, 0x6A21BA046, 0x6A21BA046, 0x6A21BA046, 0x6A21BA046, 0x8A22B9B4E, 0x8A22B9B4E, 0x6A21BA046, 0x6A22BA046, 0x6A22BA046, 0x6A21BA046, 0x8A22B9B4E
};

/*2.1************************************* OBJECT DETECTE STRUCTURE DEFINE START ****************************/
const PACalibrationDataType PACal = 
{
	/*2.1.1***Sensors dispatching table.****/
	3,// uchar cSnsSupportMaxDtCntPerLoop;
	// uchar cSnsTxSnsMask[PA_SYS_NUM][SNS_SUPPORT_OPERATION_MODE_NUM][SNS_SUPPORT_DT_CNT_PER_LOOP];
	{
		// Rear sys
		{
			// SNS_SUPPORT_DT_CNT_PER_LOOP		4
			// 0, 		1, 		2, 		3
			// RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
			// If corresponding bit is 1: Tx.
			// SnsOpModeUPA,
			{0x25, 0x33, 0x29, 0x25},
			// SnsOpModeAPASearchingSlot,
			{0x25, 0x33, 0x29, 0x25},
			// SnsOpModeSBSA
			{0x33, 0x33, 0x33, 0x33}
		},
		// Front sys
		{
			// SNS_SUPPORT_DT_CNT_PER_LOOP		4
			// 0, 		1, 		2, 		3
			// RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
			// If corresponding bit is 1: Tx.
			// SnsOpModeUPA,
			{0x25, 0x33, 0x29, 0x25},// 12, 10 sns
			// SnsOpModeAPASearchingSlot,
			{0x25, 0x33, 0x29, 0x25},// 12, 10 sns
			// SnsOpModeSBSA
			{0x21, 0x21, 0x21, 0x21}
		}
	},
	// uchar cSnsRxSnsMask[PA_SYS_NUM][SNS_SUPPORT_OPERATION_MODE_NUM][SNS_SUPPORT_DT_CNT_PER_LOOP];
	{
		// Rear sys
		{
			// SNS_SUPPORT_DT_CNT_PER_LOOP		4
			// 0, 		1, 		2, 		3
			// RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
			// If corresponding bit is 1: Rx.
			// SnsOpModeUPA,
			{0x0a, 0x0c, 0x14, 0x0a},
			// SnsOpModeAPASearchingSlot,
			{0x0a, 0x0c, 0x14, 0x0a},
			// SnsOpModeSBSA
			{0x00, 0x00, 0x00, 0x00}
		},
		// Front sys
		{
			// SNS_SUPPORT_DT_CNT_PER_LOOP		4
			// 0, 		1, 		2, 		3
			// RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK
			// If corresponding bit is 1: Rx.
			// SnsOpModeUPA,
			{0x0a, 0x0c, 0x14, 0x0a},
			// SnsOpModeAPASearchingSlot,
			{0x0a, 0x0c, 0x14, 0x0a},
			// SnsOpModeSBSA
			{0x00, 0x00, 0x00, 0x00}
		}
	},

	/*2.1.2***Sensors parameter.****/
	/* CALIB_WRITE:1000, AUDIOWELL-190111_V0.2
		Bit Position	Bit Length	Name	Configuration value
		33 : 30 4	OSC_TRIM	0 a€?no trim; binary: 0000
		29 : 23 7	CUSTOMER BITS	0000000
		22 : 16 7	G_DIG	64 / binary: 100 0000 
		15 : 13 3	G_ANA	4 / binary: 100
		12 : 8	5	I_DRV	16. binary: 1 0000
		7 : 0	8	F_DRV	UPA: 74;   APA: 106
		Binary:0100 1010   APA:0110 1010 */
	// tSnsEEPROMDataType SnsEEPROMData[PA_SYS_NUM][SNS_INTI_MAX_NUM_TEMPERATURE][PA_REAR_SNS_NUM];
	{  
		// Rear sys
		// 		RS,	     	RC,         RM,         LM,         LC,         LS
	    {
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A},// -40 <= -20.
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A},// -20 <= 0.
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A},// 0 <= 10.
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A},// 10 <= 20.
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A},// 20 <= 40.
			{0x0021016A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x001A446A} // 40 <= 85.
	    },
		// Front sys
		// 	RS,	     		RC,         RM,			LM,         LC,         LS
	    {
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A},// Temperature <= wSensor_Initia_Temperature1
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A},// wSensor_Initia_Temperature1 <= Temperature <= wSensor_Initia_Temperature2
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A},// wSensor_Initia_Temperature2 <= Temperature <= wSensor_Initia_Temperature3
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A},// wSensor_Initia_Temperature3 <= Temperature <= wSensor_Initia_Temperature4
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A},// wSensor_Initia_Temperature4 <= Temperature <= wSensor_Initia_Temperature5
			{0x001F446A, 0x000B2748, 0x000B2748, 0x000B2748, 0x000B2748, 0x0018446A} // Temperature <= wSensor_Initia_Temperature5
	    },
	},
	//uchar cSnsRingTimeUpdateCnt;
	32,// 32 cnt * 40ms = 1.28 s. every sensor may have at least check sns ring time 8 times.
 	48,// uchar UPAFUCID;
	
	/*2.1.3***Sensors mask.****/
	// uchar cPASnsMask[PA_SYS_NUM];
	{
		(SYS_WITHOUT_SNS_MASK | RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK),// PARearSys.
		(SYS_WITHOUT_SNS_MASK | RS_SNS_MASK | R_SNS_MASK | RM_SNS_MASK | LM_SNS_MASK | L_SNS_MASK | LS_SNS_MASK) // PAFrontSys.
	},
	
	/*2.1.4***Customization data.****/
	// tDIDA1ECUConfigOrCustomizationData1Type;
	{
		/*-----------------GMNA Automatic----------------*/
		// Byte 0	Default:0x20
		(WHEEL_SIZE11_MASK
		| TOWBAR_OPTION_OFF_ENABLE_MASK
		| TRAILER_HITCH_COMPENSATION_DISABLE_MASK
		| SPEED_SIGNAL_TYPE_NON_DRIVEN_MASK
		),
		// Byte 1	Default:0x0B
		(GMLAN_WITH_TRAILER_SWITCH_MASK
		| AUTO_GEAR_BOX_MASK
		| DRIVEN_WHEEL_FRONT_MASK
		| PA_ENABLE_DISABLE_METHOD_PH_SW_MASK
		| STEERING_LOCATION_LEFT_MASK
		| PARKING_BRAKE_SWITCH_DISABLED_MASK),
		// Byte 2	Default:0xB8
		(APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_TOUCH_SCREEN_MASK
		| UPA_STRATEGY_AUTOMATIC_MASK
		| UPA_WITH_FRONT_AND_REAR_SYSTEM_MASK
		| DRIVEN_AND_NONDRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK
		| MEMORIZATION_CUSTOMIZATION_DISABLE_MASK
		| GEAR_SIGNAL_SELECT_VEHICLE_MOVEMENT_STATE_MASK),		
	} ,

	/*2.1.5***Vehicle speed factor.****/
	11 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR,// word cPAReverseCutOffSpdUp;
	9 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR, // word cPAReverseCutOffSpdBack;
	11 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR,// word wPAForwardCutOffSpdUp;
	9 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR, // word wPAForwardCutOffSpdBack;
	25 * VEHICLE_SPEED_AVG_NON_DRVN_FACTOR,// word wPAForwardSpdInhibit2;
	
	/*2.1.6***Warn zone.****/
	// tObjZoneInfoStruct ObjZoneInfoStruct[PA_SYS_NUM];
	{
		// UPA_SYS_WITH_GMNA_AUTOMATCI_VISUAL_AUDIBLE
		{4, 5, {30, 60, 90, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},// Rear System.
		{4, 5, {30, 60, 90, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}// Front System.
	}, 
	
	/*2.1.7***Distance tolerance.****/
	50,// uchar cObjStateApproachingToleranceDis;
	50,// uchar cObjStateDescendingToleranceDis;
	
	100,// uchar cObjNotDetectedObjStateUpdateTime;

	/*2.1.8***Maximum times, sensor emit.****/
	// uchar cMaxSensorEmitCnt[PA_SYS_NUM];
	{
		3,// Rear System, 3 - sensor will use 4 compare to confirm the object.
		3 // Front System 3 - sensor will use 4 compare to confirm the object.
	},
	1, /* uchar cRemainLastValueWhenSnsDstbd; 0xff - disable this function,
		1 - at the 3 time emition, if the sensor is disturbed just remain the last value
		2 - at the 4 time emition, if the sensor is disturbed just remain the last value */
	// uchar cSnsMaxDataTxTryCnt[SNS_OPERATING_DATA_SEND_REQ_NUM]; 60 * 40ms = 2.4s ==> should great than 4.
	{
		10,// SnsOpCmdThresholdProgramming,
		10,// SnsOpCmdEEPROMWrite,
		3, // SnsOpCmdMeasurementConfiguration,
	},
	10,// uchar cSnsReInitDelayTime; 10 * 1ms = 10 ms.
	
	/*2.1.9***12 Sensors parameter.****/
	// SnsParameterType SnsPar[SENSOR_VERSION_NUM];
	{
		{
			// threshold settings:0000.
			// Sensor Version -> 2 Sensor Parameter.
			// uchar cSnsDefThresholdData[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SNS_NUM * (SNS_PARAMETER_NUM)];
			// Initial: 0 ~ 2.0ms;
			// Seg1: 2.0 ~ 4.0ms;
			// Seg2: 4.0 ~ 6.0ms;
			{
				{
					// SnsOpModeUPA,
					// Def: UPA Sns: 20, 20, 15, 14, 13, 9, 8, : At BaiYou Road it may mis detect with sunshine day. 25deg C.
					// RRS	RR     RRM	 RLM   RL	 RLS	  FRS      FR	  FRM    FLM   FL	FLS
					  31,   31,    31,	 31,   31,   31, 	  31,	   31,    31,	 31,   31,  31,// 0.255
					  31,   15,    15,	 15,   15,   31, 	  31,	   15,    15,	 15,   15,  31,// 0.425
					  31,   13,    13,	 13,   13,   31, 	  31,	   13,    13,	 13,   13,  31,// 0.595
					  31,   22,    22,	 22,   22,   31, 	  31,	   22,    22,	 22,   22,  31,// 0.765
					  31,   24,    24,	 24,   24,   31, 	  31,	   24,    25,	 25,   24,  31,// 1.205
					  31,   26,    26,	 26,   26,   31, 	  31,	   26,    26,	 26,   26,  31,// 1.445
					  29,   25,    25,	 25,   25,   29, 	  28,	   25,    24,	 24,   25,  28,// 1.785
					  27,   14,	   14,   14,   14,   27, 	  27,	   14,    14,	 14,   14,  27,// 2.125
					  26,   14,    14,	 14,   14,   26, 	  26,	   14,    13,	 13,   14,  26,// 2.465
					  24,   14,    14,	 14,   14,   24, 	  24,      14,    14,	 14,   14,  24,// 2.805
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 3.485
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 4.165
					0x00, 0x02, 0x02,  0x02,  0x02, 0x00, 	0x00,    0x02,  0x02,  0x02,  0x02, 0x00,	
					0x02, 0x02,	0x02,  0x02,  0x02, 0x02, 	0x02,    0x02,  0x02,  0x02,  0x02, 0x02,//	476 - 510 Seg14.
					0x02, 0x01,	0x01,  0x01,  0x01, 0x02, 	0x02,    0x01,  0x01,  0x01,  0x01, 0x02,// Down scaling in receive mode ???1 / 1 b0: THRES_LEN; b1:TRES_INI; b2.3: THRES_SCALE.
				},
				{
					// SnsOpModeAPASearchingSlot,
					//RRS	RR     RRM	 RLM   RL	 RLS      FRS	   FR     FRM	 FLM   FL	FLS 
					  31,   31,    31,	 31,   31,   31, 	  31,	   31,    31,	 31,   31,  31,//	34cm - 68cm 	Seg1.
					  31,   15,    15,	 15,   15,   31, 	  31,	   15,    15,	 15,   15,  31,// 29,	/* 68 - 112 Seg2  */
					  31,   13,    13,	 13,   13,   31, 	  31,	   13,    13,	 13,   13,  31,// 26,	APA: def: 27 112 - 136cm Seg3  */
					  31,   22,    22,	 22,   22,   31, 	  31,	   22,    22,	 22,   22,  31,// 23,	/* APA: def: 25 136 - 170	Seg4  */
					  31,   24,    24,	 24,   24,   31, 	  31,	   24,    25,	 25,   24,  31,// 21,	/* 170 - 204	Seg5  */
					  31,   26,    26,	 26,   26,   31, 	  31,	   26,    26,	 26,   26,  31,// 19,	/*	204 - 238 Seg6	*/
					  29,   25,    25,	 25,   25,   29, 	  28,	   25,    24,	 24,   25,  28,// 16,	/*	238 - 272 Seg7	*/					
					  27,   14,	   14,   14,   14,   27, 	  27,	   14,    14,	 14,   14,  27,// 14,	/*	272 - 306 Seg8	*/
					  26,   14,    14,	 14,   14,   26, 	  26,	   14,    13,	 13,   14,  26,// 13,	/*	306 - 340 Seg9	*/
					  24,   14,    14,	 14,   14,   24, 	  24,      14,    14,	 14,   14,  24,// 11,	/*	340 - 374 Seg10  */ 				
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 9,	/*	374 - 408 Seg11  */ 				
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 9, /*	408 - 442 Seg12  */ 				
					0x00, 0x02, 0x02,  0x02,  0x02, 0x00, 	0x00,    0x02,  0x02,  0x02,  0x02, 0x00,//	442 - 476 Seg13  */ 
					0x02, 0x02,	0x02,  0x02,  0x02, 0x02, 	0x02,    0x02,  0x02,  0x02,  0x02, 0x02,//	476 - 510 Seg14  */ 																							
					0x02, 0x01,	0x01,  0x01,  0x01, 0x02, 	0x02,    0x01,  0x01,  0x01,  0x01, 0x02,// b0: THRES_LEN; b0x0D:TRES_INI; b2.3: THRES_SCALE*/
				},
				{
					// SnsOpModeSBSA
					//RRS   RR     RRM   RLM   RL    RLS      FRS      FR     FRM    FLM   FL   FLS
					  31,   31,    31,	 31,   31,   31, 	  31,	   31,    31,	 31,   31,  31,// 34cm - 68cm 	Seg1.
					  31,   15,    15,	 15,   15,   31, 	  31,	   15,    15,	 15,   15,  31,// 68 - 112		Seg2.
					  31,   13,    13,	 13,   13,   31, 	  31,	   13,    13,	 13,   13,  31,// 112 - 136cm	Seg3.
					  31,   22,    22,	 22,   22,   31, 	  31,	   22,    22,	 22,   22,  31,// 136 - 170	Seg4.
					  31,   24,    24,	 24,   24,   31, 	  31,	   24,    25,	 25,   24,  31,// 170 - 204	Seg5.
					  31,   26,    26,	 26,   26,   31, 	  31,	   26,    26,	 26,   26,  31,// 204 - 238 	Seg6.
					  29,   25,    25,	 25,   25,   29, 	  28,	   25,    24,	 24,   25,  28,// 238 - 272 	Seg7.
					  27,   14,	   14,   14,   14,   27, 	  27,	   14,    14,	 14,   14,  27,// 272 - 306 	Seg8.
					  26,   14,    14,	 14,   14,   26, 	  26,	   14,    13,	 13,   14,  26,// 306 - 340 	Seg9.
					  24,   14,    14,	 14,   14,   24, 	  24,      14,    14,	 14,   14,  24,// 340 - 374 	Seg10.
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 374 - 408 	Seg11.
					  13,   15,    15,	 15,   15,   13, 	  14,      15,    15,	 15,   15,  14,// 408 - 442 	Seg12.
					0x00, 0x02, 0x02,  0x02,  0x02, 0x00, 	0x00,    0x02,  0x02,  0x02,  0x02, 0x00,// 442 - 476 	Seg13. If the value is set to 31.the sensor will stop detect obj.
					0x02, 0x02,	0x02,  0x02,  0x02, 0x02, 	0x02,    0x02,  0x02,  0x02,  0x02, 0x02,// 476 - 510 	Seg14.
					0x02, 0x01,	0x01,  0x01,  0x01, 0x02, 	0x02,    0x01,  0x01,  0x01,  0x01, 0x02,// b0: THRES_LEN; b0x0D:TRES_INI; b2.3: THRES_SCALE.
				}

			},
			// MEAS_SETUP:0001.
			{
				{
				// SnsOpModeUPA,
				 /* RRS	         RR          RRM	       RLM         RL	         RLS	       FRS	        FR          FRM	        FLM           FL	       FLS */      		
				0x8A22B9946, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x8A22B9946, 0x8A22B9946, 0x6A21BA846, 0x6A22BA846, 0x6A22BA846, 0x6A21BA846, 0x8A22B9946
				},
				{
				// SnsOpModeAPASearchingSlot,
			    	/* RRS	         RR          RRM	       RLM         RL	         RLS	       FRS	        FR          FRM	        FLM           FL	       FLS */			
				0x9A22B9946, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x9A22B9946, 0x9A22B9946, 0x6A21BA846, 0x6A22BA846, 0x6A22BA846, 0x6A21BA846, 0x9A22B9946
				},
				{
				// SnsOpModeSBSA
				 /* RRS	         RR          RRM	       RLM         RL	         RLS	       FRS	        FR          FRM	        FLM           FL	       FLS */																	
				0x8A22B9946, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x6A21BA846, 0x8A22B9946, 0x8A22B9946, 0x6A21BA846, 0x6A22BA846, 0x6A22BA846, 0x6A21BA846, 0x8A22B9946
			    }
			},
			TIME700US, // word wMinSnsRingTime, The ring time of the new sensor maybe less than 700us.
			TIME700US, // word wMinSnsRingTime, The ring time of the new sensor maybe less than 700us.
			TIME15MS,  // word wMaxSnsRingTime;
			TIME15MS,  // word wMaxSnsRingTime;
			TIME1300US,// word wMinNormalSnsRingTime;
			TIME1300US,// word wMinNormalSnsRingTime;
			TIME1000US,// word wMaxNormalSnsRingTime;
			TIME1000US,// word wMaxNormalSnsRingTime;
			TIME1500US,// word wMaxSnsDeltaRingTime;
			TIME750US, // word wMinSnsRingTimeBlocked UPA SNS
			TIME950US,// word wMinSnsRingTimeBlocked  APA SNS
			TIME300US, // word wObjIsWithinRingTimeObjDtdTime1;
			TIME400US, // word wObjIsWithinRingTimeObjDtdTime2;

			// word wValidObjBkWvWidthTxRx[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
			{
				// SnsOpModeUPA,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US // 450 - 150 cm.			
				},
				// SnsOpModeAPASearchingSlot,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US // 450 - 150 cm.
				},
				// SnsOpModeSBSA
				{
					TIME400US,// 0 - 30 cm.
					TIME300US,// 30 - 60 cm.
					TIME300US,// 60 - 90 cm.
					TIME300US,// 90 - 120 cm.
					TIME300US,// 120 - 150 cm.
					TIME200US,// 150 - 180 cm.
					TIME200US,// 210 - 70 cm.
					TIME200US,// 240 - 80 cm.
					TIME200US,// 270 - 90 cm.
					TIME200US,// 300 - 100 cm.
					TIME200US,// 330 - 110 cm.
					TIME200US,// 360 - 120 cm.
					TIME200US,// 390 - 130 cm.
					TIME200US,// 420 - 140 cm.
					TIME200US // 450 - 150 cm.
				}
			},
			//word wValidObjBkWvWidthRxOnly[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
			{
				// SnsOpModeUPA = 0,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US // 450 - 150 cm.		
				},
				// SnsOpModeAPASearchingSlot,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US //450 - 150 cm.
				},

				// SnsOpModeSBSA
				{
					TIME400US,// 0 - 30 cm.
					TIME300US,// 30 - 60 cm.
					TIME300US,// 60 - 90 cm.
					TIME300US,// 90 - 120 cm.
					TIME300US,// 120 - 150 cm.
					TIME200US,// 150 - 180 cm.
					TIME200US,// 210 - 70 cm.
					TIME200US,// 240 - 80 cm.
					TIME200US,// 270 - 90 cm.
					TIME200US,// 300 - 100 cm.
					TIME200US,// 330 - 110 cm.
					TIME200US,// 360 - 120 cm.
					TIME200US,// 390 - 130 cm.
					TIME200US,// 420 - 140 cm.
					TIME200US // 450 - 150 cm.
				}
			},
			// word wValidObjBkWvWidthTxRxForSideSns[SNS_SUPPORT_OPERATION_MODE_NUM][APA_SNS_DT_OBJ_DISTANCE_DEVIDE_SEGMENT_NUM];
			{
				// SnsOpModeUPA = 0,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US // 450 - 150 cm.			
				},
				// SnsOpModeAPASearchingSlot,
				{
					TIME150US,// 0 - 30 cm.
					TIME150US,// 30 - 60 cm.
					TIME150US,// 60 - 90 cm.
					TIME150US,// 90 - 120 cm.
					TIME150US,// 120 - 150 cm.
					TIME150US,// 150 - 180 cm.
					TIME150US,// 210 - 70 cm.
					TIME150US,// 240 - 80 cm.
					TIME150US,// 270 - 90 cm.
					TIME150US,// 300 - 100 cm.
					TIME150US,// 330 - 110 cm.
					TIME150US,// 360 - 120 cm.
					TIME150US,// 390 - 130 cm.
					TIME150US,// 420 - 140 cm.
					TIME150US // 450 - 150 cm.			
				},
				// SnsOpModeSBSA
				{
					TIME400US,// 0 - 30 cm.
					TIME300US,// 30 - 60 cm.
					TIME300US,// 60 - 90 cm.
					TIME300US,// 90 - 120 cm.
					TIME300US,// 120 - 150 cm.
					TIME200US,// 150 - 180 cm.
					TIME200US,// 210 - 70 cm.
					TIME200US,// 240 - 80 cm.
					TIME200US,// 270 - 90 cm.
					TIME200US,// 300 - 100 cm.
					TIME200US,// 330 - 110 cm.
					TIME200US,// 360 - 120 cm.
					TIME200US,// 390 - 130 cm.
					TIME200US,// 420 - 140 cm.
					TIME200US // 450 - 150 cm.
				}
			},
			
			// uchar MAX_SNS_FAIL_CNT[SNS_SUPPORT_TOTAL_FAILED_TYPE_NUM];
			{
				20,// SNS_FAILED_SHORT_TO_BASSAERY_INDEX					0.
				20,// SNS_FAILED_SHORT_TO_GND_INDEX 				 		1.
				20,// SNS_FAILED_BLOCKED_INDEX              				2.
				20,// SNS_FAILED_RING_TIME_TOO_LONG_INDEX   				3.
				20,// SNS_FAILED_NO_RING_TIME_OR_RING_TIME_TOO_SHORT_INDEX  4.
				20,// SNS_FAILED_NO_BACK_WAVE_INDEX							5.
				20,// SNS_FAILED_SIGNAL_INVALID_INDEX		  				6.
				20,// SNS_FAILED_COMPONENT_INCORRECT_INDEX  				7.
				40 // SNS_FAILED_DISTURBED_INDEX							8.
			},
			TIME7MS,// def: TIME4MS word MIN_PA_DISABLE_TOTAL_NOISE_TIME; 40 %.
			30,// def: 15 uchar MAX_SNS_DISTURBED_PULSES_NUM_AFTER_TIME15MS; 10 - 10 noise pulse == 20 times interrupt.
			100// uchar MAX_PA_DISABLE_SNS_INT_NUM;
		}
	},

	1021,// word wAPASnsDtdObjDisCompensateFactor; 1.021, = 2.1% tolerance. 

	/*2.1.10***Begin to accumulate infomation after the time.****/
	TIME20MS,// word wAccumulateSnsBackWaveStartTime;
	TIME15MS,// word wAccumulateNoisePulseNumStartTime;
	
	TIME250US,// word wTwoDataIsWithinTolleranceTime; Not use.

	0, // uchar cSnsDisturbedCounterInitialValue;
	60,// uchar cMaxSnsDisburbedCount;
	20,// uchar cSns3EmitDisturbedCount;
	40,// uchar cSns4EmitDisturbedCount;
	6, // uchar cSnsBadlyDisburbedCounterAddStep;
	4, // uchar cSnsSlightlyDisburbedCounterAddStep;
	0, /*uchar cCurrentFirstObjMismatchPrevousFirstObjDisburbedCounterAddStep; 0 - Due to first obj mismatch will often
	happen when there are multi-objects, the sensor will easily enter 4 times comparation. And this will reduce the UPA detection
	performance sharply. Just set the value to 0 to disable this feature.
	*/

	/*2.1.11***Assembly parameter.****/
	// SnsAssemblyParameterType SnsAssemblyParameter[PA_SYS_NUM];
	{
		// PA Rear sys.
		{
			// word wDisBetweenSns[PA_REAR_SNS_NUM][2];
			{
				{DISTANCE_BETWEEN_SNS_RRS_RR, DISTANCE_BETWEEN_SNS_RRS_RRM},// RRS - RR, RRS - RRM. Unit: mm.
				{DISTANCE_BETWEEN_SNS_RR_RRM, DISTANCE_BETWEEN_SNS_RRS_RR},// RR - RRM, RR - RRS. Unit: mm.
				{DISTANCE_BETWEEN_SNS_RRM_RLM, DISTANCE_BETWEEN_SNS_RR_RRM},// RRM - RLM, RRM - RR. Unit: mm.
				{DISTANCE_BETWEEN_SNS_RRM_RLM, DISTANCE_BETWEEN_SNS_RL_RLM},// RLM - RRM, RLM - RL. Unit: mm.
				{DISTANCE_BETWEEN_SNS_RL_RLM, DISTANCE_BETWEEN_SNS_RL_RLS},// RL - RLM, RL - RLS. Unit: mm.
				{DISTANCE_BETWEEN_SNS_RL_RLS, DISTANCE_BETWEEN_SNS_RLM_RLS}// RLS - RL, RLS - RLM. Unit: mm.
			},
			// SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosSinAlfa[PA_REAR_SNS_NUM][2];
			{
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RRS_RR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RR), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RRS_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RRM)},// RRS - RR, RRS - RRM. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RR_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RR_RRM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RRS_RR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RR)},// RR - RRM, RR - RRS. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RRM_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRM_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RR_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RR_RRM)},// RRM - RLM, RRM - RR. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RRM_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRM_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RL_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLM)},// RLM - RRM, RLM - RL. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RL_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RL_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLS)},// RL - RLM, RL - RLS. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RL_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLS), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_RLM_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RLM_RLS)}// RLS - RL, RLS - RLM. Unit: mm.
			},
			// SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosCosAlfa[PA_REAR_SNS_NUM][2];
			{
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RRS_RR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RR), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RRS_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RRM)},// RRS - RR, RRS - RRM. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RR_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RR_RRM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RRS_RR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRS_RR)},// RR - RRM, RR - RRS. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RRM_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRM_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RR_RRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RR_RRM)},// RRM - RLMR, RRM - R. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RRM_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RRM_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RL_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLM)},// RLM - RRM, RLM - RL. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RL_RLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RL_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLS)},// RL - RLM, RL - RLS. Unit: mm.
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RL_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RL_RLS), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_RLM_RLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_RLM_RLS)}// RLS - RL, RLS - RLM. Unit: mm.
			},
			// word wDeltaHightForSns[PA_REAR_SNS_NUM][2];
			{
				{0, 0},// RRS - RR, RRS - RRM. Unit: mm.
		        {DELTA_HIGHT_SNS_RRS_RR, 0},// RR - RRM, RR - RRS. Unit: mm.
			    {DELTA_HIGHT_SNS_RRS_RRM, DELTA_HIGHT_SNS_RRS_RR},// RRM - RLM, RRM - RR. Unit: mm.
				{DELTA_HIGHT_SNS_RLM_RLS, DELTA_HIGHT_SNS_RL_RLS},// RLM - RRM, RLM - RL. Unit: mm.
				{DELTA_HIGHT_SNS_RL_RLS, 0},// RL - RLM, RL - RLS. Unit: mm.
				{0, 0}// RLS - RL, RLS - RLM. Unit: mm.
			},
			// word wObjOffsetFromBumper[OBJ_OFFSET_FROM_BUMPER_DEVIDE_NUM];
			{
				// PA Rear Bumper, UNIT: MM.
					431,// 0 ~ 90 mm.
					425,// 100 ~ 190 mm.
					416,// 200 ~ 290 mm.
					402,// 300 ~ 390 mm.
					381,// 400 ~ 490 mm.
					355,// 500 ~ 590 mm.
					319,// 600 ~ 690 mm.
					268,// 700 ~ 790 mm.
					268,// 800 ~ 890 mm.
					268,// 900 ~ 990 mm.
					268 // 1000 ~ 1090 mm.
				}
			
	    },
		// PA Front sys.
	    {
			// word wDisBetweenSns[PA_SNS_NUM][2];
			{
				{DISTANCE_BETWEEN_SNS_FRS_FR, DISTANCE_BETWEEN_SNS_FRS_FRM},// FRS - FR, FRS - FRM. Unit: mm.
				{DISTANCE_BETWEEN_SNS_FR_FRM, DISTANCE_BETWEEN_SNS_FRS_FR},// FR - FRM, FR - FRS. Unit: mm.
				{DISTANCE_BETWEEN_SNS_FRM_FLM, DISTANCE_BETWEEN_SNS_FR_FRM},// FRM - FLM, FRM - FR. Unit: mm.
				{DISTANCE_BETWEEN_SNS_FRM_FLM, DISTANCE_BETWEEN_SNS_FL_FLM},// FLM - FRM, FLM - FL. Unit: mm.
				{DISTANCE_BETWEEN_SNS_FL_FLM, DISTANCE_BETWEEN_SNS_FL_FLS},// FL - FLM, FL - FLS. Unit: mm.
				{DISTANCE_BETWEEN_SNS_FL_FLS, DISTANCE_BETWEEN_SNS_FLM_FLS}// FLS - FL, FLS - FLM. Unit: mm.
			},
			// SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosSinAlfa[PA_SYS_NUM]][PA_SNS_NUM][2];
			{
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FRS_FR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FR), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FRS_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FRM)},     /* FRS - FR, FRS - FRM. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FR_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FR_FRM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FRS_FR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FR)},     /* FR - FRM, FR - FRS. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FRM_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRM_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FR_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FR_FRM)},     /* FRM - FLM, FRM - FR.  Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FRM_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRM_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FL_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLM)},     /* FLM - FRM, FLM - FL. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FL_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FL_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLS)},     /* FL - FLM, FL - FLS. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FL_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLS), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_HIGHT_SNS_FLM_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FLM_FLS)}     /* FLS - FL, FLS - FLM. Unit: mm */
			},
			// SNS_DISTANCE_CAL_FLOAT_TYPE ddwDtmObjPosCosAlfa[PA_SYS_NUM][PA_SNS_NUM][2];
			{
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FRS_FR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FR), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FRS_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FRM)},     /* FRS - FR, FRS - FRM. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FR_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FR_FRM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FRS_FR) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRS_FR)},     /* FR - FRM, FR - FRS. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FRM_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRM_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FR_FRM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FR_FRM)},     /* FRM - FLM, FRM - FR. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FRM_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FRM_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FL_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLM)},     /* FLM - FRM, FLM - FL. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FL_FLM) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLM), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FL_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLS)},     /* FL - FLM, FL - FLS. Unit: mm */
				{((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FL_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FL_FLS), ((SNS_DISTANCE_CAL_FLOAT_TYPE)DELTA_H_lLENGTH_SNS_FLM_FLS) / ((SNS_DISTANCE_CAL_FLOAT_TYPE)DISTANCE_BETWEEN_SNS_FLM_FLS)}     /* FLS - FL, FLS - FLM. Unit: mm */
			},
			// word wDeltaHightForSns[PA_FRONT_SNS_NUM][2];
			{
				{0, 0},     /* FRS - FR, FRS - FRM. Unit: mm */
				{DELTA_HIGHT_SNS_FRS_FR, 0},     /* FR - FRM, FR - FRS. Unit: mm */
				{DELTA_HIGHT_SNS_FRS_FRM, DELTA_HIGHT_SNS_FRS_FR},     /* FRM - FLM, FRM - FR. Unit: mm */
				{DELTA_HIGHT_SNS_FLM_FLS, DELTA_HIGHT_SNS_FL_FLS},     /* FLM - FRM, FLM - FL. Unit: mm */
				{DELTA_HIGHT_SNS_FL_FLS, 0},     /* FL - FLM, FL - FLS. Unit: mm */
				{0, 0}     /* FLS - FL, FLS - FLM. Unit: mm */
			},
			// word wObjOffsetFromBumper[OBJ_OFFSET_FROM_BUMPER_DEVIDE_NUM];
			{
				/* PA Front Bumper */  
				554, /* 0 ~ 90 mm */
				541, /* 100 ~ 190 mm */
				522, /* 200 ~ 290 mm */
				495, /* 300 ~ 390 mm */
				456, /* 400 ~ 490 mm */
				396, /* 500 ~ 590 mm */
				331, /* 600 ~ 690 mm */
				255, /* 700 ~ 790 mm */
				112, /* 800 ~ 890 mm */
			    112, /* 900 ~ 990 mm */
				112 /* 1000 ~ 1090 mm */
			}
		}
	},

	SENSOR_READ_RING_TIME_FIRST_WHEN_PA_ENTER_ACTIVE,// uchar cSnsOperatingCmdWhenPAEnterActive;

	// uchar cSnsRxChannelIndex[SNS_INPUT_CAPTURE_CHANNEL_NUM][2];
	{
		{SNS_CHANNEL_DISABLED_INDEX, SNS_CHANNEL_DISABLED_INDEX}, // RRS_SNS_INDEX = 0, tx.
		{RRM_SNS_INDEX, SNS_CHANNEL_DISABLED_INDEX}, // RR_SNS_INDEX, /*1*/ tx
		{RLM_SNS_INDEX, RR_SNS_INDEX}, // RRM_SNS_INDEX,/*2*/ TX
		{RRM_SNS_INDEX, RL_SNS_INDEX}, //RLM_SNS_INDEX/*3*/ TX
		{RLM_SNS_INDEX, SNS_CHANNEL_DISABLED_INDEX},//RL_SNS_INDEX/*4*/ TX
		{SNS_CHANNEL_DISABLED_INDEX, SNS_CHANNEL_DISABLED_INDEX },//RLS_SNS_INDEX/*5*/ TX
		{SNS_CHANNEL_DISABLED_INDEX, SNS_CHANNEL_DISABLED_INDEX},//FRS_SNS_INDEX/*6*/TX
		{FRM_SNS_INDEX, SNS_CHANNEL_DISABLED_INDEX}, // FR_SNS_INDEX, /*7*/ tx
		{FLM_SNS_INDEX, FR_SNS_INDEX}, // FRM_SNS_INDEX,/*8*/ TX
		{FRM_SNS_INDEX, FL_SNS_INDEX}, //FLM_SNS_INDEX/*9*/ TX
		{FLM_SNS_INDEX, SNS_CHANNEL_DISABLED_INDEX},//FL_SNS_INDEX/*10*/ TX
		{SNS_CHANNEL_DISABLED_INDEX, SNS_CHANNEL_DISABLED_INDEX }//FLS_SNS_INDEX/*11*/ TX
	},
	// word wMaxEachSnsDtTime[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_INPUT_CAPTURE_CHANNEL_NUM / 2][3];
	{
		// SnsOpModeUPA,
		{
			// Rear sys
			{DISTANCE530CM_TIME, 0, 0},// RRS - RRS, RRS - RR, RRS - RRM or LS - LS, LS - L, LS - LM.
			{DISTANCE280CM_TIME, DISTANCE150CM_TIME, 0},// R - R, R - RM, R - RS or L - L, L - LM, L - LS.
			{DISTANCE280CM_TIME, DISTANCE280CM_TIME, DISTANCE280CM_TIME},// RM - RM, RM - LM, RM - R or LM - LM, LM - RM, LM - L.
			// Front sys
			{DISTANCE530CM_TIME, 0, 0},// FRS - FRS, FRS - FR, FRS - FRM or LS - LS, LS - L, LS - LM.
			{DISTANCE100CM_TIME, DISTANCE120CM_TIME, DISTANCE100CM_TIME},// R - R, R - RM, R - RS.
			{DISTANCE150CM_TIME, DISTANCE150CM_TIME, DISTANCE140CM_TIME}// RM - RM, RM - LM, RM - R.
		},
		// SnsOpModeAPASearchingSlot,
		{
			// Rear sys
			{DISTANCE530CM_TIME, 0, 0},// RRS - RRS, RRS - RR, RRS - RRM or LS - LS, LS - L, LS - LM.
			{DISTANCE280CM_TIME, DISTANCE140CM_TIME, 0},// R - R, R - RM, R - RS */ /* or L - L, L - LM, L - LS.
			{DISTANCE280CM_TIME, DISTANCE280CM_TIME, DISTANCE280CM_TIME},// RM - RM, RM - LM, RM - R or LM - LM, LM - RM, LM - L.
			// Front sys
			{DISTANCE530CM_TIME, 0, 0},// FRS - FRS, FRS - FR, FRS - FRM or LS - LS, LS - L, LS - LM.
			{DISTANCE100CM_TIME, DISTANCE120CM_TIME, 0},// R - R, R - RM, R - RS.
			{DISTANCE150CM_TIME, DISTANCE150CM_TIME, DISTANCE140CM_TIME}// RM - RM, RM - LM, RM - R.
		},

		// SnsOpModeSBSA
		{
			// Rear sys.
			{DISTANCE530CM_TIME, 0, 0},// RRS - RRS, RRS - RR, RRS - RRM or LS - LS, LS - L, LS - LM.
			{DISTANCE530CM_TIME, DISTANCE530CM_TIME, 0},// R - R, R - RM, R - RS or L - L, L - LM, L - LS.
			{DISTANCE530CM_TIME, DISTANCE530CM_TIME, DISTANCE530CM_TIME},// RM - RM, RM - LM, RM - R or LM - LM, LM - RM, LM - L.
			// Front sys.
			{DISTANCE530CM_TIME, 0, 0},// FRS - FRS, FRS - FR, FRS - FRM or LS - LS, LS - L, LS - LM.
			{DISTANCE530CM_TIME, DISTANCE530CM_TIME, 0},// R - R, R - RM, R - RS.
			{0, 0, 0}// RM - RM, RM - LM, RM - R.
		}
	},

	// word wMinEachSnsDtTime[SNS_SUPPORT_OPERATION_MODE_NUM][SNS_INPUT_CAPTURE_CHANNEL_NUM / 2][3];
	{
		// SnsOpModeUPA = 0,
		{
			// Rear sys

			// DISTANCE5CM_TIME -> actually it is the obj at 10cm.

			{DISTANCE5CM_TIME, 0, 0},	/* RRS - RRS, RRS - RR, RRS - RRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, 0}, /* R - R, R - RM, R - RS */ /* or L - L, L - LM, L - LS */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, DISTANCE20CM_TIME}, /* RM - RM, RM - LM, RM - R */ /* or LM - LM, LM - RM, LM - L */
			// Front sys
			{DISTANCE5CM_TIME, 0, 0},	/* FRS - FRS, FRS - FR, FRS - FRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, 0},/* R - R, R - RM, R - RS */
			{DISTANCE5CM_TIME, DISTANCE30CM_TIME, DISTANCE20CM_TIME}/* RM - RM, RM - LM, RM - R */
		},
		// SnsOpModeAPASearchingSlot,
		{
			// Rear sys
			{DISTANCE5CM_TIME, 0, 0},	/* RRS - RRS, RRS - RR, RRS - RRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, 0}, /* R - R, R - RM, R - RS */ /* or L - L, L - LM, L - LS */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, DISTANCE20CM_TIME}, /* RM - RM, RM - LM, RM - R */ /* or LM - LM, LM - RM, LM - L */
			// Front sys
			{DISTANCE5CM_TIME, 0, 0},	/* FRS - FRS, FRS - FR, FRS - FRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE5CM_TIME, DISTANCE20CM_TIME, 0},/* R - R, R - RM, R - RS */
			{DISTANCE5CM_TIME, DISTANCE30CM_TIME, DISTANCE20CM_TIME}/* RM - RM, RM - LM, RM - R */
		},

		// SnsOpModeSBSA
		{
			// Rear sys
			{DISTANCE15CM_TIME, 0, 0},	/* RRS - RRS, RRS - RR, RRS - RRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE15CM_TIME, DISTANCE20CM_TIME, 0}, /* R - R, R - RM, R - RS */ /* or L - L, L - LM, L - LS */
			{DISTANCE15CM_TIME, DISTANCE20CM_TIME, DISTANCE20CM_TIME}, /* RM - RM, RM - LM, RM - R */ /* or LM - LM, LM - RM, LM - L */
			// Front sys
			{DISTANCE15CM_TIME, 0, 0},	/* FRS - FRS, FRS - FR, FRS - FRM */ /* or LS - LS, LS - L, LS - LM */
			{DISTANCE15CM_TIME, DISTANCE20CM_TIME, 0},/* R - R, R - RM, R - RS */
			{DISTANCE15CM_TIME, DISTANCE30CM_TIME, DISTANCE20CM_TIME}/* RM - RM, RM - LM, RM - R */
		}
	},

	/*2.1.12***Parameter of FOV.****/
	// word wMinSnsDtDis[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SYS_NUM][UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];unit : mm.
	{
		// SnsOpModeUPA,
		{
			{
				// PA Rear Sys.
				200,// RS-RS
				150,// RR_EMIT_RR_RX_OBJ_INDEX,		3.
				250,// RR_EMIT_RRM_RX_OBJ_INDEX,	4.
				150,// RRM_EMIT_RRM_RX_OBJ_INDEX,	6.
				250,// RRM_EMIT_RLM_RX_OBJ_INDEX,   8.
				250,// RRM_EMIT_RR_RX_OBJ_INDEX,	7.
				150,// RLM_EMIT_RLM_RX_OBJ_INDEX,   9.
				250,// RLM_EMIT_RRM_RX_OBJ_INDEX,	10.
				250,// RLM_EMIT_RL_RX_OBJ_INDEX,    11.
				150,// RL_EMIT_RL_RX_OBJ_INDEX,     12.
				250,// RL_EMIT_RLM_RX_OBJ_INDEX,	13.
				200 // LS - LS
			},
			/* PA Front Sys */
			{
				200, // RS - RS
				150,/*FR_EMIT_FR_RX_OBJ_INDEX,     27 */
				250,/*FR_EMIT_FRM_RX_OBJ_INDEX,*/
				150,/*FRM_EMIT_FRM_RX_OBJ_INDEX,   30 */
				250,/*FRM_EMIT_FLM_RX_OBJ_INDEX,*/
				250,/*FRM_EMIT_FR_RX_OBJ_INDEX,*/
				150,/*FLM_EMIT_FLM_RX_OBJ_INDEX,   33 */
				250,/*FLM_EMIT_FRM_RX_OBJ_INDEX,*/
				250,/*FLM_EMIT_FL_RX_OBJ_INDEX,*/
				150,/*FL_EMIT_FL_RX_OBJ_INDEX,     36 */
				250,/*FL_EMIT_FLM_RX_OBJ_INDEX,*/
				200 // LS - LS
			}
		},
		// APA MODEL
		{
			{
				/*typedef enum{*/
				200, // RS - RS
				150,  /*RR_EMIT_RR_RX_OBJ_INDEX,    3 */
				250, /* RR_EMIT_RRM_RX_OBJ_INDEX,  4 */
				150, /* RRM_EMIT_RRM_RX_OBJ_INDEX, 6 */
				250,/*RRM_EMIT_RLM_RX_OBJ_INDEX,   8 */
				250, /*RRM_EMIT_RR_RX_OBJ_INDEX,   7 */
				150,/*RLM_EMIT_RLM_RX_OBJ_INDEX,   9 */
				250,/*RLM_EMIT_RRM_RX_OBJ_INDEX,  10 */
				250,/*RLM_EMIT_RL_RX_OBJ_INDEX,    11 */
				150,/*RL_EMIT_RL_RX_OBJ_INDEX,     12 */
				250,/* RL_EMIT_RLM_RX_OBJ_INDEX,   13 */
				200 // LS - LS
			},
			/* PA Front Sys */
			{
				200, // RS - RS
				150,/*FR_EMIT_FR_RX_OBJ_INDEX,	   27 */
				250,/*FR_EMIT_FRM_RX_OBJ_INDEX,*/
				150,/*FRM_EMIT_FRM_RX_OBJ_INDEX,   30 */
				250,/*FRM_EMIT_FLM_RX_OBJ_INDEX,*/
				250,/*FRM_EMIT_FR_RX_OBJ_INDEX,*/
				150,/*FLM_EMIT_FLM_RX_OBJ_INDEX,   33 */
				250,/*FLM_EMIT_FRM_RX_OBJ_INDEX,*/
				250,/*FLM_EMIT_FL_RX_OBJ_INDEX,*/
				150,/*FL_EMIT_FL_RX_OBJ_INDEX,	   36 */
				250,/*FL_EMIT_FLM_RX_OBJ_INDEX,*/
				200 // LS - LS
			}
		},
		// SBSA MODEL
		{
			{
				/*typedef enum{*/
				200,  // RS-RS
				150,  /*RR_EMIT_RR_RX_OBJ_INDEX,    3 */
				250, /* RR_EMIT_RRM_RX_OBJ_INDEX,  4 */
				150, /* RRM_EMIT_RRM_RX_OBJ_INDEX, 6 */
				250,/*RRM_EMIT_RLM_RX_OBJ_INDEX,   8 */
				250, /*RRM_EMIT_RR_RX_OBJ_INDEX,   7 */
				150,/*RLM_EMIT_RLM_RX_OBJ_INDEX,   9 */
				250,/*RLM_EMIT_RRM_RX_OBJ_INDEX,  10 */
				250,/*RLM_EMIT_RL_RX_OBJ_INDEX,    11 */
				150,/*RL_EMIT_RL_RX_OBJ_INDEX,     12 */
				250,/* RL_EMIT_RLM_RX_OBJ_INDEX,   13 */
				200 // LS - LS
			},
			/* PA Front Sys */
			{
				200, // RS - RS
				150,/*FR_EMIT_FR_RX_OBJ_INDEX,	   27 */
				250,/*FR_EMIT_FRM_RX_OBJ_INDEX,*/
				150,/*FRM_EMIT_FRM_RX_OBJ_INDEX,   30 */
				250,/*FRM_EMIT_FLM_RX_OBJ_INDEX,*/
				250,/*FRM_EMIT_FR_RX_OBJ_INDEX,*/
				150,/*FLM_EMIT_FLM_RX_OBJ_INDEX,   33 */
				250,/*FLM_EMIT_FRM_RX_OBJ_INDEX,*/
				250,/*FLM_EMIT_FL_RX_OBJ_INDEX,*/
				150,/*FL_EMIT_FL_RX_OBJ_INDEX,	   36 */
				250,/*FL_EMIT_FLM_RX_OBJ_INDEX,*/
				200 // LS - LS
			}
		}
	},
	// word wMaxSnsDtDis[SNS_SUPPORT_OPERATION_MODE_NUM][PA_SYS_NUM][UPA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM];unit : mm.
	{
		//UPA MODEL
		{	
			// PA Rear Sys.
			{
				2500,// RS - RS									0.
				2500,// 50 def: 60, RR_EMIT_RR_RX_OBJ_INDEX,    1.
				2500,// def: 100, RR_EMIT_RRM_RX_OBJ_INDEX,		2.
				2500,// def: 80, RRM_EMIT_RRM_RX_OBJ_INDEX,		3.
				2500,// RRM_EMIT_RLM_RX_OBJ_INDEX,   			4.
				2500,// def: 80, RRM_EMIT_RR_RX_OBJ_INDEX,   	5.
				2500,// RLM_EMIT_RLM_RX_OBJ_INDEX,   			6.
				2500,// RLM_EMIT_RRM_RX_OBJ_INDEX,  			7.
				2500,// def: 80, RLM_EMIT_RL_RX_OBJ_INDEX,    	8.
				2500,// 50 def: 60, RL_EMIT_RL_RX_OBJ_INDEX,	9.
				2500,// def: 100, RL_EMIT_RLM_RX_OBJ_INDEX,   	10.
				2500 // LS - LS 								11.
			},
			/* PA Front Sys */
			{
				2500,// RS - RS
				2500,// FR_EMIT_FR_RX_OBJ_INDEX,     27.
				2500,// FR_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FRM_RX_OBJ_INDEX,   30.
				2500,// FRM_EMIT_FLM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FR_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FLM_RX_OBJ_INDEX,   33
				2500,// FLM_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FL_RX_OBJ_INDEX,
				2500,// FL_EMIT_FL_RX_OBJ_INDEX,     36.
				2500,// FL_EMIT_FLM_RX_OBJ_INDEX,
				2500 // LS - LS
			}
		},
		// APA MODEL
		{
			// PA Rear Sys.
			{
				5000,// RS - RS
				2500,// 50 def: 60, RR_EMIT_RR_RX_OBJ_INDEX,3.
				2500,// def: 100, RR_EMIT_RRM_RX_OBJ_INDEX,	4.
				2500,// def: 80, RRM_EMIT_RRM_RX_OBJ_INDEX, 6.
				2500,// RRM_EMIT_RLM_RX_OBJ_INDEX,			8.
				2500,// def: 80, RRM_EMIT_RR_RX_OBJ_INDEX,	7.
				2500,// RLM_EMIT_RLM_RX_OBJ_INDEX,			9.
				2500,// RLM_EMIT_RRM_RX_OBJ_INDEX,			10.
				2500,// def: 80, RLM_EMIT_RL_RX_OBJ_INDEX,	11.
				2500,// 50 def: 60, RL_EMIT_RL_RX_OBJ_INDEX,	12.
				2500,// def: 100, RL_EMIT_RLM_RX_OBJ_INDEX,	13.
				5000 // LS - LS
			},
			// PA Front Sys.
			{
				5000,// RS - RS
				2500,// FR_EMIT_FR_RX_OBJ_INDEX,     27
				2500,// FR_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FRM_RX_OBJ_INDEX,   30
				2500,// FRM_EMIT_FLM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FR_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FLM_RX_OBJ_INDEX,   33
				2500,// FLM_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FL_RX_OBJ_INDEX,
				2500,// FL_EMIT_FL_RX_OBJ_INDEX,     36
				2500,// FL_EMIT_FLM_RX_OBJ_INDEX,
				5000 // LS - LS
			}
		},
		//SBSA MODEL
		{
			// PA Rear Sys.
			{
				5000,// RS - RS
				2500,// RR_EMIT_RR_RX_OBJ_INDEX, 				3.
				2500,// def: 100, RR_EMIT_RRM_RX_OBJ_INDEX,		4.
				2500,// def: 80, RRM_EMIT_RRM_RX_OBJ_INDEX,		6.
				2500,// RRM_EMIT_RLM_RX_OBJ_INDEX,   			8
				2500,// def: 80, RRM_EMIT_RR_RX_OBJ_INDEX,		7.
				2500,// RLM_EMIT_RLM_RX_OBJ_INDEX,   			9.
				2500,// RLM_EMIT_RRM_RX_OBJ_INDEX,  			10.
				2500,// def: 80, RLM_EMIT_RL_RX_OBJ_INDEX,		11.
				2500,// 50 def: 60, RL_EMIT_RL_RX_OBJ_INDEX,	12.
				2500,// def: 100, RL_EMIT_RLM_RX_OBJ_INDEX,		13.
				5000 // LS - LS
			},
			// PA Front Sys.
			{
				5000,// RS - RS
				2500,// FR_EMIT_FR_RX_OBJ_INDEX,     27
				2500,// FR_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FRM_RX_OBJ_INDEX,   30
				2500,// FRM_EMIT_FLM_RX_OBJ_INDEX,
				2500,// FRM_EMIT_FR_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FLM_RX_OBJ_INDEX,   33
				2500,// FLM_EMIT_FRM_RX_OBJ_INDEX,
				2500,// FLM_EMIT_FL_RX_OBJ_INDEX,
				2500,// FL_EMIT_FL_RX_OBJ_INDEX,     36
				2500,// FL_EMIT_FLM_RX_OBJ_INDEX,
				5000 // LS - LS
			}
		}
	},
	//wMaxSnsDtDisNoFOVCut[cDtObjSnsOperatingMode][cDtObjToBeProcessedSysType] unit: mm
	{
		//Rear // Front
	  	//{5000,		5000},// UPA MODEL
	  	{2500,		2500},// UPA MODEL
	  	{5000, 		5000},// APA MODEL
	  	{5000,   	5000} // SBSA MODEL
	},
	// word wMinRMTxLMRxObjCutOffDis[PA_SYS_NUM];
	{
		/* PA Rear Sys , mm */
		800,
		/* PA Front Sys, mm; 0xffff - this function will be disabled */
		800
	},
	// word wRMTxRRxObjCutOffHDis[PA_SYS_NUM]
	{
		500,// def: 50, Rear system.
		0 // Front system.
	},
	// word wMinRmTxRRxObjCutOffDis[PA_SYS_NUM]
	{
		1000, /* Rear system */
		1000 /* Front system */
	},
	// word wRMTxRRxObjCutOffHDis2[PA_SYS_NUM]
	{
		900,// def: 100, Rear system.
		0xffff// Front system.
	},
	// word wMinRmTxRRxObjCutOffDis2[PA_SYS_NUM]
	{
		2550,// Rear system.
		1000 // Front system.
	},
	// word wMinRmTxRRxObjCutOffDis3[PA_SYS_NUM]
	{
		2550,// Rear system.
		1500 // Front system.
	},
	// word wRTxRMRxObjCutOffHDis[PA_SYS_NUM]
	{
		500,// def: 50, Rear system.
		0 // Front system.
	},
	// word wMaxRTxRMRxObjCutOffDis[PA_SYS_NUM]
	{
		1000, /* def: 50, Rear system */
		1000 /* Front system */
	},
	// word wMinSnsTriDtDis[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
	{
		// unit : mm.
		// PA Rear Sys.
		{
			/*typedef enum{*/
			50,// RR_RRM_TRIANGLE_OBJ_INDEX,   21.
			50,// RRM_RLM_TRIANGLE_OBJ_INDEX,  23.
			50,// RRM_RR_TRIANGLE_OBJ_INDEX,   22.
			50,// RLM_RRM_TRIANGLE_OBJ_INDEX,  24.
			50,// RLM_RL_TRIANGLE_OBJ_INDEX,   25.
			50,// RL_RLM_TRIANGLE_OBJ_INDEX,   26.
		},
		/* PA Front Sys */
		{
			50,// FR_FRM_TRIANGLE_OBJ_INDEX,   51.
			50,// FRM_FLM_TRIANGLE_OBJ_INDEX,  53.
			50,// FRM_FR_TRIANGLE_OBJ_INDEX,   52.
			50,// FLM_FRM_TRIANGLE_OBJ_INDEX,  54.
			50,// FLM_FL_TRIANGLE_OBJ_INDEX,   55.
			50,// FL_FLM_TRIANGLE_OBJ_INDEX,   56.
		}
	},
	// word wMaxSnsTriDtDis[PA_SYS_NUM][UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM];
	{
		// unit : mm.
		// PA Rear Sys.
		{
			2530,// RR_RRM_TRIANGLE_OBJ_INDEX,   21.
			2530,// RRM_RLM_TRIANGLE_OBJ_INDEX,  23.
			2530,// RRM_RR_TRIANGLE_OBJ_INDEX,   22.
			2530,// RLM_RRM_TRIANGLE_OBJ_INDEX,  24.
			2530,// RLM_RL_TRIANGLE_OBJ_INDEX,   25.
			2530,// RL_RLM_TRIANGLE_OBJ_INDEX,   26.
		},
		// PA Front Sys.
		{
			/*typedef enum{*/
			2530, /*FR_FRM_TRIANGLE_OBJ_INDEX,   51 */
			2530, /*FRM_FLM_TRIANGLE_OBJ_INDEX,  53 */
			2530, /*FRM_FR_TRIANGLE_OBJ_INDEX,   52 */
			2530, /*FLM_FRM_TRIANGLE_OBJ_INDEX,  54 */
			2530, /*FLM_FL_TRIANGLE_OBJ_INDEX,   55 */
			2530, /*FL_FLM_TRIANGLE_OBJ_INDEX,   56 */
		}
	},
	// word wSnsRingTimeCheckCycle;
	10000 / 40,
	// word wVehicleOutSideCutOffDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM][TRIANGLE_EXIST_CALIBRATING_POINT_NUM];
	{
		// PARearSys   unit: mm.
		{
			/* 250cm / TRIANGLE_EXIST_CALIBRATING_POINT_NUM = 50cm */
			/* 0 ~ 50cm, 50 ~ 100cm, 100 ~ 150cm, 150 ~ 200cm, 200 ~ 250 cm */
			{0,            100,         150,          300,        300}, /* RS - R, R - RS, LS - L, L - LS */
			{0,			   0,           0,            100,        150}, /* RS - RM, LS - LM */
			{0,            400,         400,          300,        300}, /* R - RM, RM - R, L - LM, LM - L */
			/*{0,          20,          50,           50,         50},  R - RM, RM - R, L - LM, LM - L */
			{0,            200,         400,          900,        900} /* RM - LM, LM - RM */
			/*{0,          20,          40,           90,         90}  RM - LM, LM - RM */
		},
		// PAFrontSys.
		{
			/* 120cm / TRIANGLE_EXIST_CALIBRATING_POINT_NUM = 24cm */
			/* 0 ~ 24cm, 24 ~ 48cm, 48 ~ 73cm, 72 ~ 96cm, 96 ~ 120 cm */
			{0,            100,        150,       300,       300}, /* RS - R, R - RS, LS - L, L - LS */
			{0,			   0,          0,         100,       150}, /* RS - RM, LS - LM */
			{0,            200,        500,       500,       500}, /* R - RM, RM - R, L - LM, LM - L */
			{0,            100,        400,       500,       700} /* RM - LM, LM - RM */
		},
	},
	// word wSnsSideOfDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM]; unit: mm.
	{
	  {930, 930, (DELTA_H_lLENGTH_SNS_RR_RRM + DELTA_H_lLENGTH_SNS_RRM_RLM/2), DELTA_H_lLENGTH_SNS_RRM_RLM/2}, /* PARearSys */
	  {790, 790, (DELTA_H_lLENGTH_SNS_FR_FRM + DELTA_H_lLENGTH_SNS_FRM_FLM/2), DELTA_H_lLENGTH_SNS_FRM_FLM/2}  /* PAFrontSys */
	},
	// word wVehicleInSideCutOffDis[PA_SYS_NUM][VEHICLE_SIDE_CUT_OFF_DIS_NUM][TRIANGLE_EXIST_CALIBRATING_POINT_NUM];
	{
		/* PARearSys unit: mm */
		{
			/* 250cm / TRIANGLE_EXIST_CALIBRATING_POINT_NUM = 50cm */
			/* 0 ~ 50cm, 50 ~ 100cm, 100 ~ 150cm, 150 ~ 200cm, 200 ~ 250 cm */
			{200,         200,        300,          400,          600}, /* RS - R, R - RS, LS - L, L - LS */
			{0,			  0,          0,            300,          300}, /* RS - RM, LS - LM */
			{200,         400,        500,          500,          500}, /* R - RM, RM - R, L - LM, LM - L */
			/*{20,         40,         60,          60,           60},  R - RM, RM - R, L - LM, LM - L */
			{400,         600,        700,          800,          900} /* RM - LM, LM - RM */
			/*{40,         60,         80,          90,         100}  RM - LM, LM - RM */
		},
		/* PAFrontSys */
		{
			/* 120cm / TRIANGLE_EXIST_CALIBRATING_POINT_NUM = 24cm */
			/* 0 ~ 24cm, 24 ~ 48cm, 48 ~ 73cm, 72 ~ 96cm, 96 ~ 120 cm */
			{200,         200,        300,        400,        600}, /* RS - R, R - RS, LS - L, L - LS */
			{0,					 0,         0,    300,        300}, /* RS - RM, LS - LM */
			{200,         400,        600,        600,        600}, /* R - RM, RM - R, L - LM, LM - L */
			{400,         600,        800,        1000,       1000} /* RM - LM, LM - RM */
			/*{40,         60,        80,        100,       110}  RM - LM, LM - RM */
		}
	},
	// uchar cWallDetectionEnabled[PA_SYS_NUM];
	{
		TRUE, /* PARearSys */
		TRUE /* PAFrontSys */
	},
	/*OBJ_STATIC_JUDGE_ACCORDING_TO_WALL_DT_HYS_DIS, OBJ_STATIC_JUDGE_ACCORDING_TO_STATIC_TOL uchar cObjStaticJudgeMethod; */
	// word wWallDetectionCutOffSpd[PA_SYS_NUM];
	{
	  VEHICLE_SPEED_AVG_NON_DRVN_FACTOR / 2, /* PARearSys */
	  VEHICLE_SPEED_AVG_NON_DRVN_FACTOR / 2/* PAFrontSys */
	},
	12, // uchar cWallDetectEnableTime; 3s ;(3000 / WALL_DETECTION_TASK_CALL_TIME).
	100,// uchar cMinWallDetectHysteresisDis; unit: mm.
	// wrod wWallDetectInnerCutOffDis[PA_SYS_NUM][2][6];
	{
		// PA Rear Sys   unit: mm.
		{
			// Right side of the vehicle.
			{
				300,// RS - RS,
				300,// RR - RR,
				450,// RR - RRM,
				2550,// RM - RM, Not used. just set to 255.
				2550,// RRM - RLM, Not used. just set to 255.
				450 // RRM - RR, 7
			},
			// Left side of the  vehicle.
			{
				2550,// RLM - RLM
				2550,// RLM - RRM
				450,// RLM - RL
				300,// RL - RL
				450,// RL - RLM
				300 // LS - LS
			}
		},
		// PA Front Sys unit: mm.
		{
			// Right side of the vehicle.
			{
				300,// RS - RS,
				300,// RR - RR,
				500,// RR - RRM,
				2550,// RM - RM, Not used. just set to 255.
				2550,// RRM - RLM, Not used. just set to 255.
				500 //RRM - RR, 7 
			},
			// Left side of the  vehicle.
			{
				2550,// RLM - RLM
				2550,// RLM - RRM
				500, // RLM - RL
				300, // RL - RL
				500, // RL - RLM
				300  // LS - LS
			}
		}
	},
	// word wWallDetectHCutOffDis[PA_SYS_NUM] unit: mm.
	{
		950,// def:90, PARearSys.
		950 // def:90, PAFrontSys.
	},
	// uchar cRegionDivideDis[PA_SYS_NUM] unit: cm.
	{
		50,// Rear sys.
		50 // Front Sys.
	},
	// uchar cRegionDivideDisTol[PA_SYS_NUM][PA_REGION_DIVIDE_DIS_TOL_NUM] unit: cm.
	{
		// 0 - 50, 50 - 100, 100 - 150, 150 - 200, 200 - 250cm  Rear sys.
		{30,         30,        30,        30,        30},
		// 0 - 24, 24 - 48, 48 - 72, 72 - 96, 96 - 120 cm Front Sys.
		{30,        30,       30,       30,      30}
	},
	// uchar cMinRegionReportDis[PA_SYS_NUM];unit: cm.
	{
		/* RRM_RLM, RLM_RRM */
		80,
		/* FRM_FLM, FLM_FRM */
		80,
	},
	// tSpeedInfoStruct SpeedChangeReqSensorInitStruct; unit:km/h.
    {6, 2, {5,10,15,20,30,80,120,140}},// ZoneNum mean the real number of zons are  ZoneNum+1
    /*For Speed1:5km/h, the speed zone is zone1, if the speed higher than 7.99km/h(Hystersis is 2km/h), 
      the speed zone will changed to Zone2 and then if the speed lower than 4.99km/h, it will be changed to zone1
      Other zones will have the same behavious as above description. */
	
    // tTemperatureInfoStruct TemperatureChangeReqSensorInitStruct;
	{5, 5, {-10, 15, 35, 60, 85}},//{5, 10, {40,80,100,120,160}},//{5, 10, {40,80,100,120,160}},//Sensor_Initia_Temperatrue_Struct;//ZoneNum mean the real number of zons are  ZoneNum+1
	//  5   -20, 0, 10, 20, 40 degree  Actual temperature should be multiplied 0.5 and subtract 40. Tollerance should be multiplied 0.5
	
	/*2.1.13***Threshold value change.****/
	// SINT8 sSensorThresholdDeltaBySpeedChange[MAX_SUPPORT_SNS_TYPE_NUM][SNS_INTI_NUM_SPEED][SNS_THRESHOLD_NUM];
	{
			//Seg1  Seg2 Seg3 Seg4 Seg5 Seg6 Seg7 Seg8 Seg9 Seg10 Seg11 Seg12 Seg13 Seg14
		{ 	//APA SNS
			{0,   1,   1,	1,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 0 ~ 5km/h, Vehicle speed <= Speed1
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 5 ~ 10km/h, Speed1 < Vehicle speed <= Speed2
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 10 ~ 15, Speed2 < Vehicle speed <= Speed3 
			{-1,  -1,  -1,	-1,	 - 1, -1,	- 2, -2, -2,	-2,	  -2,  -2,	0,	 0},// 15 ~ 20, Speed3 < Vehicle speed <= Speed4
			{-2,  -2,  -2,	-3,	 -3,  -3,	-4,	 -4,  -4,	-4,	  -3,  -3,	0,	 0},// 20 ~ 30, Speed4 < Vehicle speed <= Speed5
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 30 ~ 80, Speed5 < Vehicle speed <= Speed6
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 80 ~ 120, Speed6 < Vehicle speed <= Speed7
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// 120 ~ 140, Speed7 < Vehicle speed <= Speed8
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0}// 140 ~ , Speed8 < Vehicle speed 
		},
		{ //UPA SNS
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Vehicle speed <= Speed1
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed1 < Vehicle speed <= Speed2
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed2 < Vehicle speed <= Speed3 
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed3 < Vehicle speed <= Speed4
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed4 < Vehicle speed <= Speed5
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed5 < Vehicle speed <= Speed6
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed6 < Vehicle speed <= Speed7
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0},// Speed7 < Vehicle speed <= Speed8
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0}// Speed8 < Vehicle speed 
		},
	},
	//SINT8 sSensorThresholdDeltaByTemperatrueChange[MAX_SUPPORT_SNS_TYPE_NUM][SNS_INTI_NUM_TEMP][SNS_THRESHOLD_NUM];
	//		Seg1  Seg2 Seg3 Seg4 Seg5 Seg6 Seg7 Seg8 Seg9 Seg10 Seg11 Seg12 Seg13 Seg14
	{
		{ //APA SNS			
		  //Seg2  3    4    5    6    7     8    9    10    11    12   13 
			{0,   0,   0,	0,	 0,   4,	3,	 4,   -8,	 -10,   -7,   -6,	0,	 0},//-40 ~-10
			{0,   0,   0,	0,	 0,   4,	7,	 6,   5,	   5,	   15,   16,	0,	 0},//-10 ~ 15
			{0,   0,   0,	0,	 0,   0,	 0,	 0,   0,	   0,	    0,     0,	0,	 0},//15 ~ 35
			{0,   0,  -1,  -4,   -4,  -4,	-1,	-4,  -4,	  -7,	   -7,   -6,	0,	 0},//35 ~ 60
			{0,   0,  -1,  -4,  -21, -22, -19,	-17, -17, -16,   -7,   -6,	0,	 0},//60 ~ 85
			{0,   0,   0,	0,	 0,   0,	 0,	 0,    0,	    0,    0,     0,	0,	 0}
		},
		{ //UPA SNS
		  //Seg2  3    4    5    6    7     8    9    10    11    12   13    
			{0,   0,   0,	0,	 1,   4,	7,	 10,   11,		0,	  0,   0,	0,	 0},//-40 ~ -10
			{0,   0,   0,	0,	 1,   4,	6,	 9,     11,		0,	  0,   0,	0,	 0},//-10 ~ 15
			{0,   0,   0,	0,	 0,   0,	0,	 0,      0,		0,	  0,   0,	0,	 0},//15 ~ 35
			{0,   0,   -2,	-7,	 -9,   -10,	-2,	 -1,   -2,	  0,	  0,   0,	0,	 0},//35 ~ 60
			{0,   0,  -2,   -7,	 -9,  -17,   -12,	-11,  -8,   0,	  0,   0,	0,	 0},//60 ~ 85
			{0,   0,   0,	0,	 0,   0,	0,	 0,   0,	0,	  0,   0,	0,	 0}
		}
	},

	TRUE,//cSupportAPASystemDegradationFunction  When only APA SNS was failed, System support UPA normal function, when non-SBSA SNS was failed, System support SBSA function.

    /*2.1.14***Below parameters is regarding vehicle HMI, ignore them.****/
	50 / DISPLAY_LED_TASK_CALL_TIME,// uchar cFrontDisplayOnDelayTime.
	5000 / DISPLAY_LED_TASK_CALL_TIME,// word wFrontDisplayCheckOnTime; 5s.
	1500 / DISPLAY_LED_TASK_CALL_TIME,// word wRearDisplayCheckRogerOnTime; 1s.
	TRUE,// uchar cFlashRearLEDAtRvSpdTooHigh;
	// tDisplayLEDFlashTimerType DisplayLEDFlashInfo[PA_SYS_NUM];
	{
		// Rear Display.
        {
	        150 / DISPLAY_LED_TASK_CALL_TIME,// uchar cFlashOnTimer;
			150 / DISPLAY_LED_TASK_CALL_TIME // uchar cFlashOffTimer;
		},
		// Front Display.
		{
			150 / DISPLAY_LED_TASK_CALL_TIME,// uchar cFlashOnTimer;
			150 / DISPLAY_LED_TASK_CALL_TIME // uchar cFlashOffTimer;
		}
	},
	// uchar cMaxLEDTestTime[2];
	{
		// LED short to Gnd test time.
		200, // 200 - test for 200ms, if it has 7 LED, it will need 200 * 7 = 1.4s to set the DTC.
		// LED short to Battery test time.
		40 // 50 - test for 50ms, if it has 7 LED, it will need 50 * 7 = 350ms to set the DTC.
	},
	// uchar cMaxLEDTestPassCnt[2];
	{
		// LED short to Gnd test Pass count.
		5,// 5 - if it has 5 times of detection pass, the DTC will be cleared.
		// LED short to Battery test pass count.
		5 // 5 - if it has 5 times of detection pass, the DTC will be cleared.
	},
	// uchar cMaxLEDTestFailCnt[2];
	{
		// LED short to Gnd test Fail count.
		100,// 200 - if it has 200 times of detection fail, the DTC will be set.
		// LED short to Battery test Fail count.
		20 // 30 - if it has 30 times of detection fail, the DTC will be set.
	},
	TRUE,// uchar cSendGMLANSignalFrontSysStatus;
	TRUE,// uchar cSendGMLANSignalRearSysStatus;
	TRUE,// uchar cSendGMLANSignalGeneralStatus;
	TRUE,// uchar cSendGMLANSignalODIIndAndEnumeDynData;
	TRUE,// uchar cSendGMLANSignalODIEvent;
	FALSE,// uchar cRepeatDisableMessage;
	FALSE,// uchar cRepeatFailDisableMessage;
	/*TRUE, uchar cTurnOffLEDWhenSpdTooHighAtDisableState */
	0xFC,// 0x03 uchar cPADisbleEnblLEDCmd; 0xF4 - LED On at enable, active, front active, rear and front active, front disable and rear active.
	0x00,// word wDsblEnblLEDFlashMask;
	// tFlashInfoStructType DsblEnblLEDFlashInfo;
	{
		4,// uchar cFlashNum; 0xff - always flash. Flashing num = cFlashNum - 1. eg. cFlashNum = 2 will only flash one time.
		166 / DTM_DRV_INFO_OUTPUT_TASK_CALL_TIME,// uchar cFlashOnTime;
		166 / DTM_DRV_INFO_OUTPUT_TASK_CALL_TIME // uchar cFlashOffTime;
	},
	// uchar cMaxGMLANSignalsValueUpdateCnt;
	(200 / PRS_DRV_INPT_AND_DTM_PA_OPR_ST_TASK_CALL_CYCLE_TIME),// 0 - GMLAN signal update immediately; default ->  uchar cMaxGMLANSignalsValueUpdateCnt;
	1000 / PRS_DRV_INPT_AND_DTM_PA_OPR_ST_TASK_CALL_CYCLE_TIME,// word wNeutralDeactiveDelayTime;
	20 * 1000 / ECU_POWER_MONITOR_TASK_CALL_CYCLE_TIME,// word wBatteryVoltageOverSetDtcTime;
	20 * 1000 / ECU_POWER_MONITOR_TASK_CALL_CYCLE_TIME,// word wBatteryVoltageUnderSetDtcTime;
	TRUE,// uchar cSendGMLANPowerUpInitSig;
	/* uchar cObjDisBufSize[PA_SYS_NUM]; it should less then or equal to OBJ_BUFFER_SIZE = 10.
	this parameter effects the judge of the obj state and the obj report delay time when an obj is disapeared.
	if the total sns num of rear system or front system is big the value should be small.
	eg. 6 sns - cObjDisBufSize = 6, 2 sns - cObjDisBufSize = 10.
	*/
	{
		6,// PARearSys.
		6 // PAFrontSys.
	},
	TRUE,// uchar cCheckGMLANSignalOutside_Air_Temperature_LS; : NOT USE.
	TRUE,// uchar cShowTheNearestObjRegionAndZone;
	UPA_INITIAL_STATE_ON,// UPA_INITIAL_STATE_OFF UPA_INITIAL_STATE_LAST  uchar cUPAInitialState;
	TRUE,// uchar cUPAODISupportJustTurnOnOffUPASys;
	// uchar DisableTheEntireSytemWhenAttachedObjDtd; :NOT USE.
	30, // If use continuously checking the EEPROM, the value should less than 54.
	
	// 1. Calibration for HAPTIC_SEAT.
	HAPTIC_SEAT_PRESENT_PRESENT,// uchar cHapticSeatPresent; :NOT USE.
	FALSE, //FALSE 	uchar cSpkeakerActivatedEvenHapticSeatIsPresent; :NOT USE.
	//uchar cHapticSeatVibrationReptition[PA_SYS_NUM][OBJ_MAX_ZONE_NUM]; :NOT USE.
	{
		// Rear System
		// Zone1, Zone 2, Zone 3,......
		{5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		// Front System
		// Zone1, Zone 2, Zone 3,......
		{5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	},
	// 2. Calibration for ESS System.
	ESS_CONTROLLER_PRESENT_NOT_PRESENT,// uchar cESSControllerPresent; :NOT USE.
	TRUE,// FALSE uchar cSendGMLANSignalFrntPrkAstDrvSeatVibReqLS; :NOT USE.
	FALSE,// TRUE uchar cSendGMLANSignalParkAssistESSbasedInfoLS; :NOT USE.
	TRUE,// FALSE def: FALSE, // uchar cSendGMLANSignalRearPrkAstDrvSeatVibReqLS; :NOT USE.
	TRUE,// def TRUE, uchar cVibrateOnlyOnceAtZone21; :NOT USE.
	TRUE,// def TRUE, uchar cTeenParkAssistAlwaysOn;
};

#endif /* D2XX_SUPPORT_D2UB_CAL */
