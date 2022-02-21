#ifndef _FVALGLIBINTERFACEIF_H
#define _FVALGLIBINTERFACEIF_H

// fake code : interface of alg
/*******************************************************************
*Sub struct of main struct, indicate the Uss information from USS ALG
********************************************************************/
typedef struct
{	
	unsigned char UssDistance_Reserve;
	//this park to be filled
}App2Alg_Uss;

/*******************************************************************
*Sub struct of main struct, indicate the CAN information from CAN BUS
********************************************************************/
typedef struct
{	
	U8 CanSig_EngineStatus;                             //
	U8 CanSig_AcceleratorPedalPosition;                 //
	U8 CanSig_GearStatus;                               //TCU_LeverInfo
	float CanSig_SteerWheelAngle;                       //SAS_SteeringWheelAngle,SAS_SteeringWheelAngleSign
	float CanSig_VehicleSpeed;                          //ABS_VehicleSpeed
	U8 CanSig_VehicleStandStill;                        //
	U8 CanSig_BrakePedalStatus;                         //EMS_BrakeSwitch
	float CanSig_LateralAcceleration;                   //AY1 AY1Offset
	float CanSig_LongitAcceleration;                    //AX1 AX1Offset
	float CanSig_YawRate;                               //YawRate YawRateOffset
	U8 CanSig_FlWheelPulse;                             //WheelPulse_FL
	U8 CanSig_FrWheelPulse;                             //WheelPulse_FR
	U8 CanSig_RlWheelPulse;                             //WheelPulse_RL
	U8 CanSig_RrWheelPulse;                             //WheelPulse_RR
	float CanSig_FlWheelSpeed;                          //WheelSpeed_FL
	float CanSig_FrWheelSpeed;                          //WheelSpeed_FR
	float CanSig_RlWheelSpeed;                          //WheelSpeed_RL
	float CanSig_RrWheelSpeed;                          //WheelSpeed_RR
	U8 CanSig_FLWheelDirection;                         //ABS_DrivingDirection
	U8 CanSig_FRWheelDirection;
	U8 CanSig_RLWheelDirection;
	U8 CanSig_RRWheelDirection;	
	U8 CanSig_EpbStatus;                                //EPB_Status
	S16 CanSig_Ramp;                                    //
	U8 CanSig_PepsPowerModeStatus;                      //
	U8 CanSig_RainFallLevel;                            //
	float CanSig_AmbientTemperature;                    //AC_OutsideTemperatureIndication
}App2Alg_Can;

/********************************************************************
*Sub struct of main struct, indicate the CAN information from intelligent 
*vision module 
*********************************************************************/
typedef struct
{	
	float TargetSlot_Ax;
	float TargetSlot_Ay;
	float TargetSlot_Bx;
	float TargetSlot_By;
	float TargetSlot_Cx;
	float TargetSlot_Cy;
	float TargetSlot_Dx;
	float TargetSlot_Dy;
    unsigned char SearchingDirection;
}App2Alg_ParkingPlace_TargetSlot;

typedef struct
{	
	float UssSlot_Ax;
	float UssSlot_Ay;
	float UssSlot_Bx;
	float UssSlot_By;
	float UssSlot_Cx;
	float UssSlot_Cy;
	float UssSlot_Dx;
	float UssSlot_Dy;
}App2Alg_ParkingPlace_UssSlot;

typedef struct
{	
	unsigned char AvmSlotRedree_Left_Validity;
	unsigned char AvmSlotRedree_Right_Validity;
	float AvmSlotRedree_Left_Theta;
	float AvmSlotRedree_Right_Theta;
	short AvmSlotRedree_Left_Distance;
	short AvmSlotRedree_Right_Distance;
}App2Alg_ParkingPlace_AvmSlotRedress;

typedef struct
{	
	float AvmSpaceDetect_OppositeSpace;
	unsigned short AvmSpaceDetect_NeighBoringSlotStatus;
	unsigned char AvmSpaceDetect_TargetSlotType;
	unsigned char AvmSpaceDetect_TargetSlotFusionMode;
}App2Alg_ParkingPlace_AvmSpaceDetect;

typedef struct
{		
	App2Alg_ParkingPlace_TargetSlot TargetSlotInfo;
	App2Alg_ParkingPlace_AvmSlotRedress AvmSlotRedressInfo;
	App2Alg_ParkingPlace_AvmSpaceDetect AvmSpaceDetectInfo;
}App2Alg_ParkingPlace;

/********************************************************************
*Sub struct of main struct, indicate the CAN information from CAN BUS
*********************************************************************/
typedef struct
{	
	unsigned char Command_Dr_Initialize;
	unsigned char Command_Dr_Calculate;
	unsigned char Command_Notify_ApaState;
	unsigned char Command_Notify_ApaInterruptState;
    
    unsigned char Command_Notify_Plan;
}App2Alg_ControlCommand;

/****************************************
* main struct of interface from APP to ALG
***************************************/
typedef struct
{	
	App2Alg_Uss UssInfo;  
	App2Alg_Can CanInfo;
    App2Alg_ParkingPlace ParkingPlaceInfo;
	App2Alg_ControlCommand ControlCommandInfo;
}App2Alg;



/********************************************************************
* Sub struct of main struct, indicate the CAN information from CAN BUS
*********************************************************************/
//typedef struct
//{	
//	unsigned char SysCommand_UssModuleInit; //+注释
//	unsigned char SysCommand_ApaModuleInit;
//	unsigned char SysCommand_UssModuleDeInit;
//	unsigned char SysCommand_ApaModuleDeInit;
//}App2Alg_SystemCommand;

//44D5 重定位线
//44D0 车位


/***************************
*------------------------------------------------------------------------------------------------------------------------------------------------
*------------------------------------------------------------------------------------------------------------------------------------------------ 
*------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------

	 		PS.  Pikachu

	 		
			quu..__
			 $$$b  `---.__
			  "$$b		  `--.							___.---uuudP
			   `$$b 		  `.__.------.__	 __.---'	  $$$$" 			 .
				 "$b		  -'			`-.-'			 $$$"			   .'|
				   ".										d$" 			_.'  |
					 `.   / 							 ..."			  .'	 |
					   `./							 ..::-' 		   _.'		 |
						/						  .:::-'			.-' 		.'
					   :						  ::''\ 		 _.'			|
					  .' .-.			 .-.		   `.	   .'				|
					  : /'$$|			.@"$\			`.	 .' 			 _.-'
					 .'|$u$$|		   |$$,$$|			 |	<			 _.-'
					 | `:$$:'		   :$$$$$:			 `.  `. 	  .-'
					 :					`"--'			  |    `-.	   \
					:##.	   ==			  .###. 	  `.	  `.	`\
					|##:					  :###: 	   |		>	  >
					|#' 	`..'`..'		  `###' 	   x:	   /	 /
					 \									 xXX|	  /    ./
					  \ 							   xXXX'|	 /	 ./
					  /`-.									`.	/	/
					 :	  `-  ...........,					 | /  .'
					 |		   ``:::::::'		.			 |<    `.
					 |			   ```| 		  x| \ `.:``.
					 |						   .'	 /'   xXX|	`:`M`M':.
					 |	  | 				   ;	/:' xXXX'|	-'MMMMM:'
					 `.  .' 				  :    /:'		 |-'MMMM.-'
					  |  |					 .'   /'		.'MMM.-'
					  `'`'					 :	,'			|MMM<
						|					  `'			|tbap\
						 \									:MM.-'
						  \ 				|			   .''
						   \.				`.			  /
							/	  .:::::::.. :			 /
						   |	 .:::::::::::`. 		/
						   |   .:::------------\	   /
						  /   .''				>::'  /
						  `',:				   :	.'
											   `:.:'
------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------ 
------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------
**********************************/

/**********************************************************************************
Sub struct of main struct, indicate the parking coordinate information from APA Alg
**********************************************************************************/

typedef struct
{	
	float CoordinateDr_X; //unit mm
	float CoordinateDr_Y; //unit mm
	float CoordinateDr_Yaw; //unit degree(°)
}Alg2App_Coordinate_DR;

typedef struct
{	
	float PredictLocation_X; //unit mm
	float PredictLocation_Y; //unit mm
	float PredictLocation_Yaw; //unit degree(°)
}Alg2App_Coordinate_PredictLocation;

typedef struct
{	
	Alg2App_Coordinate_DR CoordinateDrInfo;
	Alg2App_Coordinate_PredictLocation PredictLocationInfo;
}Alg2App_Coordinate;
   
/**********************************************************************************
Sub struct of main struct, indicate the creen display information from APA Alg
**********************************************************************************/
typedef struct
{	
	unsigned char Display_TargetTotalStep;
	unsigned char Display_TargetCurrentStep;
	float Display_TargetStepProgressBar;//unit precent(%)
}Alg2App_Display;

/**********************************************************************************
Sub struct of main struct, indicate the parking CAN control information from APA Alg
**********************************************************************************/
typedef struct
{	
	unsigned char Control_TargetGear;   //Converted Direction
	float Control_TargetSteeringAngle;  //Converted Curvature
	
	float Control_TargetVehicleSpeed;   
	float Control_TargetAcceleration;   
	unsigned short Control_TargetStopDistance; 
       
	unsigned char Control_TargetDriveoff;   
	unsigned char Control_TargetStandstillReq;

    //Add for C080
    float Control_TargetPoint_X[50];
    float Control_TargetPoint_Y[50]; 
    float Control_TargetPoint_Angle[50];
    float Control_TargetCurvature[50];

	float Control_Center_Radius_X[50];
	float Control_Center_Radius_Y[50];
    
	unsigned char Control_TargetDirection[50];         
    unsigned char Control_Current_Index[50];
    unsigned char Control_Total_Index; 
}Alg2App_Can_Control;

/**********************************************************************************
Sub struct of main struct, indicate the Command response information from  Alg
**********************************************************************************/
typedef struct
{	
	unsigned char CommandResp_Error;
	unsigned char CommandResp_Dr_InitializeStatus;
	unsigned char CommandResp_Dr_CalculateStatus;
	unsigned char CommandResp_Control_Status;
    unsigned char CommandResp_Plan_Status;
}Alg2App_CommandResp;


/****************************************
main struct of interface from ALG to APP
***************************************/
typedef struct
{	
	Alg2App_Coordinate CoordinateInfo;
	Alg2App_Display DisplayInfo;
	Alg2App_Can_Control CanControlInfo;
	Alg2App_CommandResp CommandRespInfo;
}Alg2App;



/********************variable declare*************************/
extern App2Alg App2AlgInfo;
extern Alg2App Alg2AppInfo;


#endif


