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
#include "SlotParaCfg.h"
#include "ObjDetectCommonDefine.h"
#include "CarPosTracing.h"

#ifdef D2XX_SUPPORT_D2UB_CAL

uchar   cAPARequestChimeCmd;
tAPAWordBitType   _APACommonFlag0;
APACarParameterInfoType   APACarPar;
APASlotSnsDtdObjPtBufType   APASnsDtdObjPtBuf[APA_SIDE_SENSOR_NUM];

const  SlotSearchingCaliCfgData   SlotCaliCfg =
{

/*2.4.1***Vehicle pararmeter****/
	5082,//4666,//4658,// 4838, // APA_DISTANCE_TYPE LengthOfCar;
	1923,//1822,//1814,// 1817, // APA_DISTANCE_TYPE WidthOfCar;
	961,//1822/2,//1814/2,// 1817 / 2, // APA_DISTANCE_TYPE HalfWidthOfCar;
	810,//849,//770,//780, // APA_DISTANCE_TYPE HalfWidthOfFrontAxis;
	817,//850,//775,//760, // APA_DISTANCE_TYPE HalfWidthOfRearAxis;
	3000,//2750,//2685,//2761, // APA_DISTANCE_TYPE LenBetweenFRAxis;
	3955,//3658,//4838 - 1089, // APA_DISTANCE_TYPE LenBetweenRAxisAndFBumper;
	1123,//921,//1000,//1089, // APA_DISTANCE_TYPE LenBetweenRAxisAndRBumper;

	// APA_DISTANCE_TYPE WheelTireDiameter[MAX_TIRE_SIZE_NUM];		// unit:mm
	{
	(634 - 30),	// Tire size 1:(195/65R15)
	(632 - 30),	// Tire size 2:(205/55R16)
	(643 - 30),	// Tire size 3:(215/55R16)
	(647 - 30),	// Tire size 4:(215/50R17)
	(634 - 30),	// Tire size 5:(225/45R17)
	(724 - 23),	// Tire size 6:(225/65R17)
	(637 - 30),	// Tire size 7:(225/40R18)
	(727 - 30),	// Tire size 8:(225/60R18)
	(717 - 30),	// Tire size 9:(235/50R19)
	(685 - 30),	// Tire size 10:(225/45R19)
	(705 - 11), // Tire size 11:(225/55R18) //GAC AM8
	(717 - 30),	// Tire size 12:()
	(717 - 30),	// Tire size 13:()
	(717 - 30),	// Tire size 14:()
	(717 - 30),	// Tire size 15:()
	(717 - 30),	// Tire size 16:()
	(717 - 30),	// Tire size 17:()
	(717 - 30),	// Tire size 18:()
	(717 - 30),	// Tire size 19:()
	(717 - 30),	// Tire size 20:()
	(717 - 30),	// Tire size 21:()
	(717 - 30),	// Tire size 22:()
	(717 - 30),	// Tire size 23:()
	(717 - 30),	// Tire size 24:()
	(717 - 30),	// Tire size 25:()
	(717 - 30),	// Tire size 26:()
	(717 - 30),	// Tire size 27:()
	(717 - 30),	// Tire size 28:()
	(717 - 30),	// Tire size 29:()
	(717 - 30),	// Tire size 30:()
	(717 - 30),	// Tire size 31:()
	(717 - 30)		// Tire size 32:()
	},

/*2.4.2***Sensor fixed information****/
	// APACoordinateDataType SnsPos[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center
	{
		{
		903,
		-558
		},    //RRS
		{
		694,
		-1018
		},    //RR
		{
		230,
		-1119  //RRM
		},
		{
		-230,
		-1119 //RLM
		},
		{
		-694,
		-1018 //RL
		},

		{
		-903,
		-558  //RLS
		},
		{
		929,
		3402   //FRS
		},
		{
		662,
		3817  //FR
		},
		{
		317,
		3908   //FRM
		},
		{
		-317,
		3908  // FLM
		},
		{
		-662,
		3817  //FL
		},

		{
		-929,
		3402  //FLS
		}
	},

	///APA_ANGLE_TYPE SnsAng[APA_SUPPORT_APA_SNS_NUM]; // relative to car rotation center, (unit: radian)
	{
		350 / 180.0 * PI, //		APACal.SnsAng[APA_RRS_SNS_INDEX] = 351.0 / 180.0 * PI;
		300 / 180.0 * PI, //      APACal.SnsAng[APA_RR_SNS_INDEX]  = 315.0 / 180.0 * PI;//285.0 / 180.0 * PI;
		275 / 180.0 * PI, //      APACal.SnsAng[APA_RRM_SNS_INDEX] = ;//275.0 / 180.0 * PI;
	    265 / 180.0 * PI, //      APACal.SnsAng[APA_RLM_SNS_INDEX] = 260.0 / 180.0 * PI;//265.0 / 180.0 * PI; // radian
		240/ 180.0 * PI, //      APACal.SnsAng[APA_RL_SNS_INDEX]  = 225.0 / 180.0 * PI;//255.0 / 180.0 * PI; // radian
		190/ 180.0 * PI, //      APACal.SnsAng[APA_RLS_SNS_INDEX] = 189.0 / 180.0 * PI; // radian
		10 / 180.0 * PI,   //      APACal.SnsAng[APA_FRS_SNS_INDEX] = 9.0 / 180.0 * PI;//2.0 / 180.0 * PI;
		55 / 180.0 * PI,  //      APACal.SnsAng[APA_FR_SNS_INDEX]  = 45.0 / 180.0 * PI;
		80 / 180.0 * PI,  //      APACal.SnsAng[APA_FRM_SNS_INDEX] = 80.0 / 180.0 * PI;
		100 / 180.0 * PI, //      APACal.SnsAng[APA_FLM_SNS_INDEX] = 100.0 / 180.0 * PI;
		125 / 180.0 *PI,  //      APACal.SnsAng[APA_FL_SNS_INDEX]  = 135.0 / 180.0 *PI;
		170 / 180.0 * PI //       APACal.SnsAng[APA_FLS_SNS_INDEX] = 171.0 / 180.0 * PI;//178.0 / 180.0 * PI;
	},

    // APA_ANGLE_CAL_FLOAT_TYPE SnsAngCos[APA_SUPPORT_APA_SNS_NUM];
	{
		0.984807753,  //RRS 0.98480775301220805936674302458952
		0.5,          //RR   0.5
		0.087155743,  //RRM  0.08715574274765817355806427083747
		-0.087155743, //RLM  -0.08715574274765817355806427083747
		-0.5,         //RL -0.5
		-0.984807753, //RLS -0.98480775301220805936674302458952

		0.984807753,  //FRS 0.98480775301220805936674302458952
		0.573576436,  //FR	0.57357643635104609610803191282616
		0.173648178,  //FRM 0.17364817766693034885171662676931
		-0.173648178, //FLM -0.17364817766693034885171662676931
		-0.573576436, //FL  -0.52991926423320495404678115181609//-0.57357643635104609610803191282616
		-0.984807753  //FLS -0.99337276560039642191489960537272 //-0.98480775301220805936674302458952
	},
	// APA_ANGLE_CAL_FLOAT_TYPE SnsAngSin[APA_SUPPORT_APA_SNS_NUM];
	{
		-0.173648178,  //RRS -0.17364817766693034885171662676931
		-0.866025404,  //RR -0.86602540378443864676372317075294
		-0.996194698,  //RRM -0.99619469809174553229501040247389
		-0.996194698, //RLM -0.99619469809174553229501040247389
		-0.866025404, //RL  -0.86602540378443864676372317075294
		-0.173648178, //RLS -0.17364817766693034885171662676931

		0.173648178,  //FRS 0.08715574274765817355806427083747//0.17364817766693034885171662676931
		0.819152044,  //FR 0.84804809615642597038617617869039//0.81915204428899178968448838591684
		0.984807753,  //FRM 0.99992536966045199446367259653333//0.98480775301220805936674302458952
		0.984807753, //FLM 0.99992536966045199446367259653333//0.98480775301220805936674302458952
		0.819152044, //FL 0.84804809615642597038617617869039//0.81915204428899178968448838591684
		0.173648178  //FLS 0.11493715049286660983496550109583//0.17364817766693034885171662676931
	},
/*2.4.5***apa state relatively ****/
	APA_CAR_PARK_AT_RIGHT_SIDE, // APA_ENUM_TYPE CarParkAtLeftOrRightSide; // Car park at left if true other wise park at right
	(
	APA_SUPPORT_FUNC_MODE_ParallelParkingIn
	| APA_SUPPORT_FUNC_MODE_PerpendicularlParkingIn
	),

/*2.4.7***boolean define ****/
#ifdef APA_SYSTEM_WITH_10_CH
	0x1fcd,
#else

	0x1dcd,// 0x1dcd, // 0x15CD, // def: 0x17CD,
#endif
/*2.4.8*** common use ****/
	0.0617 * PI / 180, // APA_ANGLE_TYPE APARxSteeringWheelAngleConvertFactor; //Convert the D0 (EPS Tx steering wheel angle) to unit: rad. APA_RX_STEERING_WHEEL_ANGLE_CAL_FACTOR
	300.0,// APA_DISTANCE_CAL_FLOAT_TYPE APAAllowWheelRotateDisMinTol; // For different tire radius and pulse cnt, this value should be different.
	300.0,//APA_DISTANCE_CAL_FLOAT_TYPE APAWheelPulseNeedUpdateDis; //when the car position is not updated,and the wheel distance is more than NeedUpdateDis,then updated the car positon.
	4096,//SKODA: 1001, GM D2xx: 1024, APASupportMaxWheelPulseCnt;//for different type of cars,the supported max wheel pulse cnt would be different.
/*2.4.9*** Searching Slot Algorithm****/
/*2.4.9.1*** Parrallel slot****/
	600, // 60cm APA_DISTANCE_TYPE APASlotRoundObjPtSearchBackMaxDis;
	3000, // 300cm APA_DISTANCE_TYPE APASlotDisToCarCheckCarDrvDis; // if it is set to 3m, for the pole or squre, the first slot will be removed. so just set the dis less than the min perpendicular slot len.
	2000, // 100cm APA_DISTANCE_TYPE APASlotCarToObjDisCalObjWidthToBeConsidered;
	200, // 20cm APA_DISTANCE_TYPE APASlotPointFilterDeltaDis;
	200, // 50cm def: 20cm APA_DISTANCE_TYPE APASlotCarToObjDisCalObjToCarDisTolLen;
	1000, //APA_DISTANCE_TYPE APASlotSnsDtRoundObjMaxDeltaDis;
	100,  //APA_DISTANCE_TYPE APASlotSnsDtRoundObjMinDeltaDis;
	100,  //APA_DISTANCE_TYPE APASlotSnsDtSQuareObjMaxDeltaDis;

	30, // 30%, def: 20 = 20%, APA_ENUM_TYPE APASlotObjDetProbabilityPercentage; // 1~90%

	//APA_DISTANCE_TYPE APASlotHFOVWidthBySeg[APA_SLOT_APA_SENSOR_HFOV_DIVIDED_SEG_NUM];
	{
		800,
		1000,  // 500mm
		1000,
		1000,  // 1000mm
		1000,
		1000,  //1500mm
		1000,
		800,   // 2000mm
		600,
		600,   //2500mm
		600,
		600,   //3000mm
		500,
		400,   // 3500mm
		400,
		400,   // 4000mm
		400,
		400,   // 4500mm
		400,
		400	  // 5000mm
	},

	APA_FLS_SNS_INDEX,
	APA_FRS_SNS_INDEX,
	// APA_DISTANCE_TYPE APASlotDetectionCompensateLengthHead[3][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_DEVIDED_NUM]; // Slot start
	{
		//  APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		},
		//  APA_SLOT_OBJ_TYPE_ROUND,
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		},
		//  APA_SLOT_OBJ_TYPE_SQUARE
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		}
	},
	// APA_DISTANCE_TYPE APASlotDetectionCompensateLengthTail[3][APA_SLOT_SUPPORT_SLOT_LENGTH_COMPENSATE_DEVIDED_NUM]; // Slot end.
	{
		// Obj1 = block, obj2 = ISO pole, com_h = 200, com_t = 100, spd < 10, tol = -350.
		//  APA_SLOT_OBJ_TYPE_UNKNOWN = 0,
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		},
		//  APA_SLOT_OBJ_TYPE_ROUND,
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		},
		//  APA_SLOT_OBJ_TYPE_SQUARE
		{
			300, // 0 ~ 5 km/h
			300, // 5 ~ 10 km/h
			300, // 10 ~ 15 km/h
			300, // 15 ~ 20 km/h
			300, // 20 ~ 25 km/h
			300 // 25 ~ 30 km/h
		}
	},
	400, // APA_DISTANCE_TYPE APASlotDetectionToleranceDis;
	7200, // APA_DISTANCE_TYPE APASlotMaxSlotLengthWithInvalidObj2;
	300, // 300mm, APA_DISTANCE_TYPE APASlotMinDisCarToObjByPassingSlot;
	2000, // 200mm, APA_DISTANCE_TYPE APASlotMaxDisCarToObjByPassingSlot;
	1300, // 100mm, 	APA_DISTANCE_TYPE APASlotMaxOffsetDisBetweenObj1AndObj2ForParallel;
	1800 + 3500, // mm , APA_DISTANCE_TYPE APASlotMaxDisForCurbDetection;// Use car side as the reference point
	500, // 50cm , APA_DISTANCE_TYPE APASlotConsiderSecondSlotDepthMinDeltaSlotLen;
	5200 + 600, // min small slot len + 60cm , APA_DISTANCE_TYPE APASlotConsiderSecondSlotDepthMinDeltaSlotLen;
	2000, // 2000mm , APA_DISTANCE_TYPE APASlotMinStartCheckingCurbOffsetLen;
	200, // 50cm , APA_DISTANCE_TYPE APASlotMinRegardedAsCurbMinCurbLenAtSlotHeadAndTail;
	5400, // APA_DISTANCE_TYPE APASlotMinSmallSlotLen; // 6 steps parking. 200 = 20cm, slot tolerance.
	18000, // 18m, def:12m , APA_DISTANCE_TYPE APASlotMaxSlotLength;
	100, // 300 mm , APA_DISTANCE_TYPE APASlotCurbLineTolerance;

	1400, // def: 500mm , APA_DISTANCE_TYPE APASlotMinSlotDepth;// Use car rear axis center as the reference point
	3500, // 3500mm , APA_DISTANCE_TYPE APASlotMaxSlotDepth;// Use car rear axis center as the reference point
	18000, // mm , APA_DISTANCE_TYPE APASlotMaxPathAfterSlot;
	3500, // def: 3000mm , APA_DISTANCE_TYPE APASlotMinPathAfterSlot; // Important notes: this value should great than APASlotDisToCarCheckCarDrvDis, and less than min per slot width.
/*2.4.9.2*** Perpendicular slot ****/
	2000,//2600, // def: 2.4m, APA_DISTANCE_TYPE APASlotPMinSmallSlotLen; // 6 steps parking.
	3500, // def: 3.5m, APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj1;
	3500, // def: 3.5m, APA_DISTANCE_TYPE APASlotPDefSlotLenWithoutObj2;
	12000,//APA_DISTANCE_TYPE APASlotPMaxSlotLength;
	3800,  // def: 4800, APA_DISTANCE_TYPE APASlotPMinSlotDepth;// Use car rear axis center as the reference point
	3000, // 300cm , APA_DISTANCE_TYPE APASlotPMinStartCheckingCurbOffsetLen;

	0.1 * PI / 180.0, // 0.1 deg, APA_ANGLE_TYPE APAParkProcCarDriveStraightlyMinSteeringWheelAng;
	0.05 / 3.6, // 0.05 km/ h -> m/s , APA_SPEED_TYPE APAParkProcMaxVehicleStaticSpeed;
	30,//30.0 / 3.6, // 30 km/h -> m/s , APA_SPEED_TYPE APAParkProcMaxSearchingSlotSpeed;

    	0.1 * PI / 180.0, // 0.1 deg, APA_ANGLE_TYPE APATrajCalCarDriveVerticallyMaxCarAng;
	89.9 * PI / 180, // 89.9 deg, APA_ANGLE_TYPE APATrajCalCarDriveHorMinCarAng;
	800, // 800 mm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowSnsDtObjDisTolerance;
	300, // 30cm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance;
	400, // 40cm, APA_DISTANCE_TYPE APASlotCurbLineFitAllowCurbLineToObjDisTolerance2;
	3, // APA_ENUM_TYPE APASlotCurbLineFitAllowMinObjPt;
	1500, // 1.5m,	APA_DISTANCE_TYPE APASlotCurbLineFitAllowMinCurbLength;
	1.0 / 600.0, // 10m, APA_RATIO_TYPE APATrajCalLineIsHMinK; // if the K of the line is less than APATrajCalLineIsHMinK, means the line is horizontal,
	60.0 * PI / 180.0, // 60 deg.	APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxDeltaCarAngAndCurbLineAng;
	70.0 * PI / 180.0, // 70deg. APA_ANGLE_TYPE APASlotCurbLineFitAllowMaxCurbLineAndYAng;
	10.0 / 8.12, // actual 10deg -> fit 8.12deg. APA_ANGLE_TYPE APASlotCurbLineFitCurbLineAngCompensateRatio;
/*2.4.10***Car position calculate parament****/
 	10, // 10ms  APACarPosCalculationTaskCallCycleTime
       5, // 1s: 1s car drive 5cm. APACalCarPosUpdateCycleTimeCount
 	3, // APASupportWheelPluseCounterErrorRecoverCycleTimeCount
 	200, // APASupportMaxUseVehicleSpeedAndAccToEvaluateCarPosDurationCycleTimeCount
 	2000, // 2m.APASupportMaxUseVehicleSpeedAndAccToEvaluateCarPosTotalDis
	400, // 40cm. APASupportMaxCarPosCalUpdateDetalTolance
 	1.0, // unit. m/s considering update cycle: max 100ms and a = 10 m/s^2. APASupportMaxVehicleSpeedUpdateDeltaTolance
 	0.01, // unit: /s. APACalCarPosVehicleSpeedCalAccFactor
 	10, // unit: ms. APACalCarPosVehicleSpeedEvaluateByCarDriveDisDeltaCycleTime
 	100, // 1s unit: s. APACalCarPosVehicleSpeedMissToBeUpdatedRecoverTime
 	1.0 / 3.6, // 1km/h. APACalCarPosStartToAccumulateDisMinVehicleSpeed
	0, //unit:mm. APASlotCarCenterPointXDefaultValue;
	-5000, // unit:mm, this value can not less than MaxSlotLenth + APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS, ie. 18m APASlotCarCenterPointYDefaultValue;
	5000, // unit:mm, this value can not less than MaxSlotLenth + APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS, ie. 18m APASlotCarCenterPointResetYValueMax;
	-15000, // unit:mm, this value can not less than MaxSlotLenth + APA_SLOT_DIS_TO_CAR_CHECK_CAR_TRAVELLING_DIS, ie. 18m APASlotCarCenterPointResetYValueMin;
	45.0 * PI / 180.0, // 45deg. APASlotCarCenterPointCarAngMax;
/*2.4.11***Slot Searching Common Define***/
	4000, //mm, APASlotSamplePtNoObjDisPtRemoveMinSlotLen;
	1000, //mm, APASlotSamplePointUpdateLongDeltaLen;
	500, //mm, APASlotSamplePointUpdateSmallDeltaLen;
	400, //mm, APASlotPointCanBeRemovedContiguousPointMinDisP;
	25000, //mm, Should not exceed 25000 (considering + 5000 (APA_SLOT_CAR_CENTER_POINT_Y_DEFAUT_VALUE)) shold not exceed 32m. APASlotMaxDistanceBetweenStartEndPtWithObj1Invalid;
	70.0 * PI / 180.0, //70deg, APASlotMaxDeltaCarAngBetweenStartEndPt;
	40.0 * PI / 180.0, //40deg, APASlotMaxDeltaCarAngBetweenObjPt;
	40, //ms, APASlotSensorDtOneLoopTimeMs;
	1.0 / 3.6, //km/h, APASlotNumberOfDtTimesCalMinSpd;
	55, //APASlotMaxNumberOfDtTimes;
	100, //APASlotObjectMaxWeightCoefficient;
	50, //APASlotObjectAckWeightCoefficient;
	700, //mm, APASlotSensorDetectSameObjTolDis;
	600, //mm, APASlotSensorDetectObjRegionAreaWidth;
	20, //20*40=800ms, APASlotSensorMaxDetectLoopCntToConfirmObject;
	600, //mm, APASlotMinPerSlotDeltaCarPosDisAtSlotStAndEndPt;
	3000, //mm, APASlotApSlotDisToCarCheckCarTravellingDis;
	1000/40, // 1s, APASlotVehicleStaticUpdateSlotPtTime;
	1200, //APASlotSearcingEdgeDistanceTolerance;
	3000, //APASlotMaxOffsetDisBetweenObj1AndObj2ForPerpendicular;
	200 //APASlotMaxOffsetBetweenMinDisToCarIndexToObjEdgeIndex
};
#endif
