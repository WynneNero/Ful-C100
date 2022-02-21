#include "il_inc.h"
#include "il_par.h"
#include "CanApp.h" 
#include "APSAPP.h"

#include "UssInfoMsg.h"
#include "ApsCanApp.h"
#include "ussLibIf.h"
#include "FVAlgLibInterface.h"

#define MATH_PI 3.14

/********************variable declare*************************/
U8 Error_PathPoint[50] = 0;
U8 Path_Point_Index = 0;
BOOL DRIsAbsolutePose = FALSE;
BOOL OncePathReplantFlag = FALSE;

static float32 YawAngleOffset;
static float32 ParkSlotCentrePoint_X;
static float32 ParkSlotCentrePoint_Y;

static float32 TargetPoint_YAW;
static float32 TargetPoint_X_Offset;
static float32 TargetPoint_Y_Offset;

static float32 HQCoordinateSystem_YAW;
static float32 HQCoordinateSystem_X_Offset;
static float32 HQCoordinateSystem_Y_Offset;

gType_VehPos_st FV_ODO = {0};
gType_VehPos_st FV_ODO_CUR = {0};

APS_PATH_PLAN_STATUS PathPlanStatus;
Alg2App_Can_Control PathPointCopy;
Alg2App_Can_Control PathPointChange;

/********************extern variable declare*************************/
extern U8 APA_Park_type;
extern U8 g_APA_park_fusion_type;
extern U8 TargetSlotInfo_ParkDirection;

extern APS_MODULE_STATUS APSModuleCurrentStatus;
extern P_STK_USS_Slot_Search p_stk_uss_slot_search;
extern APA_RELOAT_PLACE_INFO apa_reloat_place_info;

/********************static function declare*************************/
void APS_Path_Point_Sender(void);
BOOL Get_PathPoint_SendError_Flag(void);
void APS_PathPoint_SendError_Handler(void);

App2Alg_ParkingPlace_TargetSlot APS_Calculate_ABCD_TargetSlot_Data(void);
void APS_PathPlan_Moudle(void);
void Cal_ParkSlotCentrePoint(void);
void TargetSlot_DebugDataSender(void);


/********************function entity*************************/
void APS_PathPlan_Module_10ms_Entry(void)
{	
//	APS_PathPlan_Moudle();
//    App2AlgInfo_ControlCommandInfo_Command_Notify_ApaStateHandler();
	Alg2AppDebugSignalHandler();
}

void App2AlgInfo_CanReceiveHandler(void)
{

}

void App2AlgInfo_ControlCommandInfo_Command_Notify_ApaStateHandler(void)
{
	App2AlgInfo.ControlCommandInfo.Command_Notify_ApaState = APSModuleCurrentStatus;
}

void Alg2AppDebugSignalHandler(void)
{	
	g_FV_adiGetVehPosOdo_bl(&FV_ODO);   //get FV odo

	if(GetMmiTouchDebugFlag() == 1)
	{		
		TargetSlot_DebugDataSender();
/*2021/07/09, DBC change/remove, resulting in no this signal*/
		can_send_sig(DR_X, FV_ODO.XPosMM_si32); 
		can_send_sig(DR_Y, FV_ODO.YPosMM_si32);
		can_send_sig(DR_RAW, FV_ODO.YawAngle_ui32);

//		can_send_sig(Debug_ReloatTheta_R, (S16)App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Theta * 10);
//		can_send_sig(Debug_ReloatValid_R, App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Validity);
//		can_send_sig(Debug_ReloatDistance_R, App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Distance);
//
//		can_send_sig(Debug_ReloatTheta_L, (S16)App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Theta * 10);
//		can_send_sig(Debug_ReloatValid_L, App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Validity);
//		can_send_sig(Debug_ReloatDistance_L, App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Distance); 		
	}
}

void Clear_App2Alg_ParkingPlace_TargetSlot(void)
{
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Ax      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Ay      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Bx      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_By      = 0;
    
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Cx      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Cy      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Dx      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Dy      = 0;
    App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.SearchingDirection = 0;
}


void Set_Dr_Initialize(BOOL DrInitFlag)
{
    App2AlgInfo.ControlCommandInfo.Command_Dr_Initialize = DrInitFlag;
}

void Set_Dr_Calculate(U8 DrCalFlag)
{
    App2AlgInfo.ControlCommandInfo.Command_Dr_Calculate = DrCalFlag;
}

void Notify_FV_ApaState(APS_MODULE_STATUS ApaState)
{
    App2AlgInfo.ControlCommandInfo.Command_Notify_ApaState = ApaState;
}

void Notify_ApaInterruptState(U8 InterruptState)
{
    App2AlgInfo.ControlCommandInfo.Command_Notify_ApaInterruptState = InterruptState;
}

void Set_Avm_OppositeSpace(float OppositeSpace)
{
    App2AlgInfo.ParkingPlaceInfo.AvmSpaceDetectInfo.AvmSpaceDetect_OppositeSpace = OppositeSpace;
}

void Set_Avm_NeighBoringSlotStatus(U16 NeighBoringSlotStatus)
{
    App2AlgInfo.ParkingPlaceInfo.AvmSpaceDetectInfo.AvmSpaceDetect_NeighBoringSlotStatus = NeighBoringSlotStatus;
}

void Set_Avm_TargetSlotType(void)
{	
	App2AlgInfo.ParkingPlaceInfo.AvmSpaceDetectInfo.AvmSpaceDetect_TargetSlotType = APA_Park_type;
	App2AlgInfo.ParkingPlaceInfo.AvmSpaceDetectInfo.AvmSpaceDetect_TargetSlotFusionMode = g_APA_park_fusion_type;
}

void Set_PathPlan(APS_PATH_PLAN_STATUS SetPathPlanStatus)
{
	PathPlanStatus = SetPathPlanStatus;
}

void Set_ReloatPlaceInfo(void)
{
	if(APS_PARKING_ACTIVE_PARKIN == APSModuleCurrentStatus)
	{	
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Validity  = apa_reloat_place_info.L_Valid;	
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Distance  = apa_reloat_place_info.DistL;
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Left_Theta     = apa_reloat_place_info.ThetaL;
		
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Validity = apa_reloat_place_info.R_Valid;
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Distance = apa_reloat_place_info.DistR;
		App2AlgInfo.ParkingPlaceInfo.AvmSlotRedressInfo.AvmSlotRedree_Right_Theta    = apa_reloat_place_info.ThetaR;
	}
}

void Clear_ReloatPlaceInfo(void)
{
	_memset(&apa_reloat_place_info,0,sizeof(apa_reloat_place_info)); //clear
}

/***********************************************************************
*  Name        : Cal_ParkSlotCentrePoint
*  Description : Path Point from FV convert Path Point from Fahwq and then send by can
*  Parameter   :
*  Returns     :
***********************************************************************/
void Cal_ParkSlotCentrePoint(void)
{
	if(APA_Park_type == ParkingType_PARALLEL)
	{
		if(HQCoordinateSystem_YAW > 0 && MATH_PI < HQCoordinateSystem_YAW)
		{
			ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 - 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
			ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
		}
		else
		{
			ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
			ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
		}
	}
	else
	{
		if(App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.SearchingDirection == 0x0)//left
		{
			if(HQCoordinateSystem_YAW > 0 && MATH_PI < HQCoordinateSystem_YAW)
			{
				ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 - 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
				ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 - 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
			}
			else
			{
				ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 - 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
				ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
			}
		}
		else
		{
			if(HQCoordinateSystem_YAW > 0 && MATH_PI < HQCoordinateSystem_YAW)
			{
				ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
				ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
			}
			else
			{
				ParkSlotCentrePoint_Y = PathPointCopy.Control_TargetPoint_Y[PathPointCopy.Control_Total_Index - 1] * 100 + 143 * cos(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm			
				ParkSlotCentrePoint_X = PathPointCopy.Control_TargetPoint_X[PathPointCopy.Control_Total_Index - 1] * 100 - 143 * sin(fabs(HQCoordinateSystem_YAW));  //unit:mm -> cm
			}
		}
	}
}


/***********************************************************************
*  Name        : Cal_ParkSlotCentrePoint
*  Description : Path Point from FV convert Path Point from Fahwq and then send by can
*  Parameter   :
*  Returns     :
***********************************************************************/
void CoordinateSystem_Change(void)
{
	_memset(&PathPointChange,0,sizeof(PathPointChange));
	_memcpy(&PathPointChange,&PathPointCopy,sizeof(PathPointChange));

	//value range convert : -PI ~ PI -> 0 ~ 2PI
	for(U8 curIndex = 0;curIndex < PathPointChange.Control_Total_Index;curIndex ++)
	{
		if(PathPointChange.Control_TargetPoint_Angle[curIndex] < 0)
		{
			PathPointChange.Control_TargetPoint_Angle[curIndex] = 2 * MATH_PI + PathPointChange.Control_TargetPoint_Angle[curIndex];
		}
	}	
	
	HQCoordinateSystem_YAW = TargetPoint_YAW - (PathPointChange.Control_TargetPoint_Angle[PathPointChange.Control_Total_Index - 1]);	
	Cal_ParkSlotCentrePoint();
	HQCoordinateSystem_X_Offset = (TargetPoint_X_Offset) * cos(HQCoordinateSystem_YAW) + (TargetPoint_Y_Offset) * sin(HQCoordinateSystem_YAW) - ParkSlotCentrePoint_X;
	HQCoordinateSystem_Y_Offset = (TargetPoint_Y_Offset) * cos(HQCoordinateSystem_YAW) - (TargetPoint_X_Offset) * sin(HQCoordinateSystem_YAW) - ParkSlotCentrePoint_Y;		

	for(U8 curIndex = 0;curIndex < PathPointCopy.Control_Total_Index;curIndex ++)
	{
		PathPointChange.Control_TargetPoint_X[curIndex] = (PathPointCopy.Control_TargetPoint_X[curIndex] * 100 + HQCoordinateSystem_X_Offset) * cos(HQCoordinateSystem_YAW) 
							  - (PathPointCopy.Control_TargetPoint_Y[curIndex] * 100 + HQCoordinateSystem_Y_Offset) * sin(HQCoordinateSystem_YAW);

		PathPointChange.Control_TargetPoint_Y[curIndex] = (PathPointCopy.Control_TargetPoint_X[curIndex] * 100 + HQCoordinateSystem_X_Offset) * sin(HQCoordinateSystem_YAW) 
								  + (PathPointCopy.Control_TargetPoint_Y[curIndex] * 100 + HQCoordinateSystem_Y_Offset) * cos(HQCoordinateSystem_YAW);

		//value range convert : 0 ~ 2PI -> -PI ~ PI 
		PathPointChange.Control_TargetPoint_Angle[curIndex] = (PathPointChange.Control_TargetPoint_Angle[curIndex] + HQCoordinateSystem_YAW);
		if(PathPointChange.Control_TargetPoint_Angle[curIndex] > MATH_PI)
		{
			PathPointChange.Control_TargetPoint_Angle[curIndex] = PathPointChange.Control_TargetPoint_Angle[curIndex] - 2 * MATH_PI;
		}
		else if (PathPointChange.Control_TargetPoint_Angle[curIndex] < - MATH_PI)
		{
			PathPointChange.Control_TargetPoint_Angle[curIndex] = PathPointChange.Control_TargetPoint_Angle[curIndex] + 2 * MATH_PI;
		}
		
		PathPointChange.Control_Center_Radius_X[curIndex] = (PathPointCopy.Control_Center_Radius_X[curIndex] * 100 + HQCoordinateSystem_X_Offset) * cos(HQCoordinateSystem_YAW) 
							  - (PathPointCopy.Control_Center_Radius_X[curIndex] * 100 + HQCoordinateSystem_Y_Offset) * sin(HQCoordinateSystem_YAW);
		
		PathPointChange.Control_Center_Radius_Y[curIndex] = (PathPointCopy.Control_Center_Radius_Y[curIndex] * 100 + HQCoordinateSystem_X_Offset) * sin(HQCoordinateSystem_YAW) 
								  + (PathPointCopy.Control_Center_Radius_Y[curIndex] * 100 + HQCoordinateSystem_Y_Offset) * cos(HQCoordinateSystem_YAW);	
	}
}

void APS_Replan_Path_Point_Sender(void)
{ 	
	static U8 msgSendFlag = 0;
    if(Path_Point_Index > (PathPointChange.Control_Total_Index - 1))
    {	
    	msgSendFlag = 0;
    	Path_Point_Index = 0;	
		PathPlanStatus = PATH_PLAN_HANDLER;		
		can_send_sig(APS_ReplanResult, PATH_INACTIVE);
    }
    else if(msgSendFlag == 0)
    { 	
    	//Way_Point_Info_1
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//    	can_send_sig(Total_Index, PathPointChange.Control_Total_Index - 1);
//		can_send_sig(Current_Index_WPI1,PathPointChange.Control_Current_Index[Path_Point_Index]);
//		can_send_sig(Way_Point_Angle, (PathPointChange.Control_TargetPoint_Angle[Path_Point_Index])/0.005 + 628);		
//		can_send_sig(Way_Point_X, PathPointChange.Control_TargetPoint_X[Path_Point_Index] + 1000);
//		can_send_sig(Way_Point_Y, PathPointChange.Control_TargetPoint_Y[Path_Point_Index] + 1000);

		msgSendFlag ++;
    }
	else
	{	
		//Way_Point_Info_2
		if(Path_Point_Index == 1)
		{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			can_send_sig(WayPoint_Direction, 0x2);
			PathPointChange.Control_TargetDirection[Path_Point_Index] = 0x2;
		}
		else
		{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			can_send_sig(WayPoint_Direction, PathPointChange.Control_TargetDirection[Path_Point_Index]);
		}
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//		can_send_sig(Current_Index_WPI2, PathPointChange.Control_Current_Index[Path_Point_Index]);
//		can_send_sig(WayPoint_Curvature, PathPointChange.Control_TargetCurvature[Path_Point_Index]/0.0001 + 10000);
				 		
		msgSendFlag = 0;
		Path_Point_Index++;	
    }
}


void TargetSlot_DebugDataSender(void)
{
/*2021/07/09, DBC change/remove, resulting in no this signal*/
//	can_send_sig(TargetSlot_Ax, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Ax);	
//	can_send_sig(TargetSlot_Ay, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Ay);	
//	can_send_sig(TargetSlot_Bx, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Bx);
//	can_send_sig(TargetSlot_By, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_By);

//	can_send_sig(TargetSlot_Cx, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Cx);	
//	can_send_sig(TargetSlot_Cy, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Cy);	
//	can_send_sig(TargetSlot_Dx, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Dx);
//	can_send_sig(TargetSlot_Dy, (S16)App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo.TargetSlot_Dy);
}


void APS_PathPlan_Moudle(void)
{
	switch(PathPlanStatus)
    {
        case PATH_PLAN_STANDBY:
			OncePathReplantFlag = FALSE;
			App2AlgInfo.ControlCommandInfo.Command_Notify_Plan = 0;	//not plan
			
			if(APS_PARKING_MAP_UPDATE == APSModuleCurrentStatus)
			{
				PathPlanStatus = PATH_PLAN_INIT;
			}
        	break;
			
        case PATH_PLAN_INIT:
			if(SocPositionSendStatus && APS_PARKING_MAP_UPDATE == APSModuleCurrentStatus)
			{						
            	App2AlgInfo.ParkingPlaceInfo.TargetSlotInfo = APS_Calculate_ABCD_TargetSlot_Data();	
				Set_Avm_TargetSlotType();
				
				App2AlgInfo.ControlCommandInfo.Command_Notify_Plan = 1;	//plan
				SocPositionSendStatus = FALSE;
				PathPlanStatus = PATH_PLAN_HANDLER;
			}
			else if(APS_PARKING_MAP_UPDATE != APSModuleCurrentStatus)
			{
				PathPlanStatus = PATH_PLAN_STANDBY;
			}
        	break;
		
        case PATH_PLAN_HANDLER:
			if(0x2 == Alg2AppInfo.CommandRespInfo.CommandResp_Plan_Status)
			{				
				_memcpy(&PathPointCopy,&(Alg2AppInfo.CanControlInfo),sizeof(Alg2App_Can_Control));
				App2AlgInfo.ControlCommandInfo.Command_Notify_Plan = 0;	//not plan				
				
				CoordinateSystem_Change();									//change Coordinate System : FV -> HQ
				Timer_Start(APS_DR_SENDER,20,TIMER_PERIODIC);    			//send vehicle pose
				Path_Point_Index = 0;
				PathPlanStatus = PATH_POINT_SNEDER;
				break;
			}
			else if(0x0 == Alg2AppInfo.CommandRespInfo.CommandResp_Plan_Status || 0x01 == Alg2AppInfo.CommandRespInfo.CommandResp_Plan_Status)
			{
				//wait
			}
			else
			{
				PathPlanStatus = PATH_PLAN_EXIT;
			}

			if((APS_PARKING_ACTIVE_PARKIN == APSModuleCurrentStatus) && (0x1 == can_receive_sig(ADV_ReplanMode)) && can_receive_sig(ADV_ReplanWayPoint) == 0)
			{
//				App2AlgInfo.ControlCommandInfo.Command_Notify_Plan = 2;	//replan
				Path_Point_Index = 1;
				PathPlanStatus = PATH_REPLAN_HANDLER;
   			}

			if(Get_PathPoint_SendError_Flag())
            {   
                PathPlanStatus = PATH_ERRORPOINT_SNEDER;
            }

			can_send_sig(APS_ReplanResult, PATH_INACTIVE);
        	break;

		case PATH_REPLAN_HANDLER:
//			if(0x2 == Alg2AppInfo.CommandRespInfo.CommandResp_Plan_Status)
//			{
//				can_send_sig(APS_ReplanResult, 0x2);
//				if(can_receive_sig(ADV_ReplanWayPoint))
//				{			
//					_memcpy(&PathPointCopy,&(Alg2AppInfo.CanControlInfo),sizeof(Alg2App_Can_Control));
//					App2AlgInfo.ControlCommandInfo.Command_Notify_Plan = 0;					
//					Cal_ParkSlotCentrePoint();
//					Path_Point_Index = 0;
//					PathPlanStatus = PATH_POINT_SNEDER;
//				}
//			}	

			can_send_sig(APS_ReplanResult, PATH_GENERATE_SUCCESS);
			if(0X1 == can_receive_sig(ADV_ReplanWayPoint))
			{
				OncePathReplantFlag = TRUE;
				APS_Replan_Path_Point_Sender();
			}
			break;
			
        case PATH_POINT_SNEDER:
            APS_Path_Point_Sender();
			break;

        case PATH_ERRORPOINT_SNEDER:
            APS_PathPoint_SendError_Handler();
        	break;
            
        case PATH_PLAN_EXIT:
            Clear_App2Alg_ParkingPlace_TargetSlot();
            PathPlanStatus = PATH_PLAN_STANDBY;
       		break;

		default:
			break;
    }   
}


/***********************************************************************
*  Name        : APS_Path_Point_Sender
*  Description : Path Point from FV convert Path Point from Fahwq and then send by can
*				 msgSendFlag = 0  : send Way_Point_Info_1
				 msgSendFlag != 0 : send Way_Point_Info_2
*  Parameter   :
*  Returns     :
***********************************************************************/
void APS_Path_Point_Sender(void)
{ 
	static U8 msgSendFlag = 0;
		
    if(Path_Point_Index >= PathPointChange.Control_Total_Index)
    {	
    	msgSendFlag = 0;
    	Path_Point_Index = 0;
		PathPlanStatus = PATH_PLAN_HANDLER;
    }
    else if(msgSendFlag == 0)
    { 	
		if(GetMmiTouchDebugFlag() == 1)
		{
/*2021/07/09, DBC change/remove, resulting in no this signal*/
//			can_send_sig(FV_TargetPoint_X, (S16)(PathPointCopy.Control_TargetPoint_X[Path_Point_Index] * 1000));			
//			can_send_sig(FV_TargetPoint_Y, (S16)(PathPointCopy.Control_TargetPoint_Y[Path_Point_Index] * 1000));
//			can_send_sig(FV_TargetPoint_Angle, (S16)(PathPointCopy.Control_TargetPoint_Angle[Path_Point_Index] * 10000));
		}
		
    	//Way_Point_Info_1 		
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//    	can_send_sig(Total_Index, PathPointChange.Control_Total_Index);
//		can_send_sig(Current_Index_WPI1,PathPointChange.Control_Current_Index[Path_Point_Index] + 1);
//		can_send_sig(Way_Point_Angle, (PathPointChange.Control_TargetPoint_Angle[Path_Point_Index])/0.005 + 628);		
//		can_send_sig(Way_Point_X, PathPointChange.Control_TargetPoint_X[Path_Point_Index] + 1000);
//		can_send_sig(Way_Point_Y, PathPointChange.Control_TargetPoint_Y[Path_Point_Index] + 1000);

		msgSendFlag ++;
    }
	else
	{	
		//Way_Point_Info_2
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//		can_send_sig(WayPoint_Direction, PathPointChange.Control_TargetDirection[Path_Point_Index]);
//		can_send_sig(Current_Index_WPI2, PathPointChange.Control_Current_Index[Path_Point_Index] + 1);
//		can_send_sig(WayPoint_Curvature, PathPointChange.Control_TargetCurvature[Path_Point_Index]/0.0001 + 10000);		
//		
//		can_send_sig(Center_Radius_X, PathPointChange.Control_Center_Radius_X[Path_Point_Index] + 1000);
//		can_send_sig(Center_Radius_Y, PathPointChange.Control_Center_Radius_Y[Path_Point_Index] + 1000);
		msgSendFlag = 0;
		Path_Point_Index++;	
    }
}

BOOL Get_PathPoint_SendError_Flag(void)
{
    U8 PathPoint_index1[7];   
    U8 PathPoint_index2[7]; 
    
	if(b_Way_Point_Feedback_1_Triger || b_Way_Point_Feedback_2_Triger)
	{
		_memset(PathPoint_index1,0,7);
		_memset(PathPoint_index2,0,7);
		if(b_Way_Point_Feedback_1_Triger)
		{
			b_Way_Point_Feedback_1_Triger = FALSE;
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			IlGetRxValidFlag_WPF1(PathPoint_index1);
		}
		if(b_Way_Point_Feedback_2_Triger)
		{
			b_Way_Point_Feedback_2_Triger = FALSE;
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			IlGetRxValidFlag_WPF2(PathPoint_index2);
		}
		
		_memset(Error_PathPoint,0,50);

		for(U8 index = 0;index < 7; index++)
		{  	
			if(PathPoint_index1[index] != 0x0)
			{
				for(U8 bit_index = 0;bit_index < 8; bit_index++)
				{
					if((PathPoint_index1[index] >> bit_index) & 0x01)
					{
						Error_PathPoint[0] ++;		// the counter of error point
						Error_PathPoint[Error_PathPoint[0]] = bit_index + index * 8;
					}
				}
			}
		}

		if(Error_PathPoint[0])
		{
			return TRUE;
		}   
	}
    return FALSE;
}


void APS_PathPoint_SendError_Handler(void)
{
    static U8 errMsgSendFlag = 0;
	static U8 errMsgPointIndex = 1;
	U8 PathIndexTmp = 0;
	
	if(errMsgPointIndex <= Error_PathPoint[0] && errMsgPointIndex <= PathPointChange.Control_Total_Index)
	{
		if(OncePathReplantFlag)
		{
			PathIndexTmp = Error_PathPoint[errMsgPointIndex] + 1;
		}
		else
		{
			PathIndexTmp = Error_PathPoint[errMsgPointIndex];
		}
		
		if(errMsgSendFlag == 0)
		{
			//Way_Point_Info_1
			if(OncePathReplantFlag)
			{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//				can_send_sig(Total_Index, PathPointChange.Control_Total_Index - 1);
//				can_send_sig(Current_Index_WPI1,PathPointChange.Control_Current_Index[PathIndexTmp]);
			}
			else
			{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//				can_send_sig(Total_Index, PathPointChange.Control_Total_Index);
//				can_send_sig(Current_Index_WPI1,PathPointChange.Control_Current_Index[PathIndexTmp] + 1);
			}
			
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			can_send_sig(Way_Point_Angle, (PathPointChange.Control_TargetPoint_Angle[PathIndexTmp])/0.005 + 628);		
//			can_send_sig(Way_Point_X, PathPointChange.Control_TargetPoint_X[PathIndexTmp] + 1000);
//			can_send_sig(Way_Point_Y, PathPointChange.Control_TargetPoint_Y[PathIndexTmp] + 1000);				
			errMsgSendFlag++;
		}
		else
		{		
			//Way_Point_Info_2
			if(OncePathReplantFlag)
			{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//				can_send_sig(Current_Index_WPI2, PathPointChange.Control_Current_Index[PathIndexTmp]);
			}
			else
			{
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//				can_send_sig(Current_Index_WPI2, PathPointChange.Control_Current_Index[PathIndexTmp] + 1);
			}
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//			can_send_sig(WayPoint_Direction, PathPointChange.Control_TargetDirection[PathIndexTmp]);
//			can_send_sig(WayPoint_Curvature, PathPointChange.Control_TargetCurvature[PathIndexTmp]/0.0001 + 10000);				 			

			errMsgSendFlag = 0;
			Error_PathPoint[errMsgPointIndex] = 0;
			errMsgPointIndex ++;
		}
	}
	else
	{
		errMsgPointIndex = 1;
		Error_PathPoint[0] = 0;
		PathPlanStatus = PATH_PLAN_HANDLER;
	}
}

/***********************************************************************
*  Name        : APS_Calculate_ABCD_Target_Data
*  Description : get target slot info and Coordinate system change : NJ -> FV
*  Parameter   :
*  Returns     : App2Alg_ParkingPlace_TargetSlot
***********************************************************************/
App2Alg_ParkingPlace_TargetSlot APS_Calculate_ABCD_TargetSlot_Data(void)
{
	App2Alg_ParkingPlace_TargetSlot CarPortLocationData = {0};
    
	if((get_ParkPlace_X_1() < 0)&&(get_ParkPlace_X_2() < 0))
	{
		if(APA_Park_type == ParkingType_PERPENDICULAR)
		{			
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = 500;
			TargetPoint_YAW = 4.71; //-1.57

			CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
			CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
			CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
			CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

			CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
			CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
			CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
			CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
		}
		else if(APA_Park_type == ParkingType_PARALLEL)
		{
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = 500;			
			TargetPoint_YAW = 0; 

			if(g_APA_park_fusion_type == AVM_SLOT_TYPE || g_APA_park_fusion_type == AVM_ULTRA_FUSION_SLOT_TYPE)
			{
				CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
				CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1() + 250;
				CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
				CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2() + 250;

				CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
				CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3() + 250;
				CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
				CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4() + 250;
			}
			else
			{
				CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
				CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
				CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
				CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

				CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
				CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
				CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
				CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
			}
		}
		else if(APA_Park_type == ParkingType_OBLIQUE)
		{
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = 500;			
			TargetPoint_YAW = 4.71; //-1.57

			CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
			CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
			CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
			CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

			CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
			CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
			CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
			CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
		}
        
        CarPortLocationData.SearchingDirection = 0; //left
	}
	else if((get_ParkPlace_X_1() > 0)&&(get_ParkPlace_X_2() > 0))
	{
		if(APA_Park_type == ParkingType_PERPENDICULAR)
		{
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = -500;			
			TargetPoint_YAW = 1.57; 

			CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
			CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
			CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
			CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

			CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
			CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
			CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
			CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
		}
		else if(APA_Park_type == ParkingType_PARALLEL)
		{
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = -500;
			TargetPoint_YAW = 0; 

			if(g_APA_park_fusion_type == AVM_SLOT_TYPE || g_APA_park_fusion_type == AVM_ULTRA_FUSION_SLOT_TYPE)
			{
				CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
				CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1() - 250;
				CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
				CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2() - 250;

				CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
				CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3() - 250;
				CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
				CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4() - 250;
			}
			else
			{
				CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
				CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
				CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
				CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

				CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
				CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
				CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
				CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
			}
		}
		else if(APA_Park_type == ParkingType_OBLIQUE)
		{
			TargetPoint_X_Offset = -100;
			TargetPoint_Y_Offset = -500;
			TargetPoint_YAW = 1.57; 

			CarPortLocationData.TargetSlot_Ax  =  get_ParkPlace_Y_1();
			CarPortLocationData.TargetSlot_Ay  = -get_ParkPlace_X_1();
			CarPortLocationData.TargetSlot_Bx  =  get_ParkPlace_Y_2();
			CarPortLocationData.TargetSlot_By  = -get_ParkPlace_X_2();

			CarPortLocationData.TargetSlot_Cx  =  get_ParkPlace_Y_3();
			CarPortLocationData.TargetSlot_Cy  = -get_ParkPlace_X_3();
			CarPortLocationData.TargetSlot_Dx  =  get_ParkPlace_Y_4();
			CarPortLocationData.TargetSlot_Dy  = -get_ParkPlace_X_4();
		}     		
        CarPortLocationData.SearchingDirection = 1; //right
	}

	return CarPortLocationData;
}

/***********************************************************************
*  Name        : VehicleDeadReckoningSender
*  Description : 20ms timer(OPEN_VEHICLE_DEAD_RECKONING) calls
*  Parameter   :
*  Returns     :
***********************************************************************/
void VehicleDeadReckoningSender(void)
{   
	APA_Vehicle_Position_NJ AbsoluteVehPos = GetAbsoluteVehPos();
	APA_Vehicle_Position_NJ RelativeVehPos = GetRelativeVehPos(AbsoluteVehPos);

 	AbsoluteVehPos.VEH_DR_X = AbsoluteVehPos.VEH_DR_X /2; //unit : mm -> 2mm
	AbsoluteVehPos.VEH_DR_Y = AbsoluteVehPos.VEH_DR_Y/2;  //unit : mm -> 2mm
	AbsoluteVehPos.VEH_DR_YAW_DEGREES = 100 * AbsoluteVehPos.VEH_DR_YAW_DEGREES; //unit : degree -> 0.01degree
    
	RelativeVehPos.VEH_DR_X = RelativeVehPos.VEH_DR_X/2;//unit : mm -> 2mm
	RelativeVehPos.VEH_DR_Y = RelativeVehPos.VEH_DR_Y/2;//unit : mm -> 2mm
	RelativeVehPos.VEH_DR_YAW_DEGREES = 100 * RelativeVehPos.VEH_DR_YAW_DEGREES;//unit : degree -> 0.01degree   	
	
	M4Msg_Update(E_M4_ABSOLUTE_DELTA_X_U16, VehPosSendToSoc_F32ToU16(AbsoluteVehPos.VEH_DR_X));
	M4Msg_Update(E_M4_ABSOLUTE_DELTA_Y_U16, VehPosSendToSoc_F32ToU16(AbsoluteVehPos.VEH_DR_Y));
	M4Msg_Update(E_M4_ABSOLUTE_DELTA_ANGLE_U16, VehPosSendToSoc_F32ToU16(AbsoluteVehPos.VEH_DR_YAW_DEGREES));
    
	M4Msg_Update(E_M4_RELATIVE_DELTA_X_U16, VehPosSendToSoc_F32ToU16(RelativeVehPos.VEH_DR_X));
	M4Msg_Update(E_M4_RELATIVE_DELTA_Y_U16, VehPosSendToSoc_F32ToU16(RelativeVehPos.VEH_DR_Y));
	M4Msg_Update(E_M4_RELATIVE_DELTA_ANGLE_U16, VehPosSendToSoc_F32ToU16(RelativeVehPos.VEH_DR_YAW_DEGREES));
}


/***********************************************************************
*  Name        : VehPosSendToSoc_F32ToU16
*  Description : conversion : float -> unsigned short 
*  Parameter   :
*  Returns     :
***********************************************************************/
U16 VehPosSendToSoc_F32ToU16(float32 VehPosition)
{
	U16 VehPositionU16 = 0;
	if(VehPosition >= 0)
	{
		VehPositionU16 = (U16)(VehPosition)&0x7FFF;
	}
	else
	{
		VehPositionU16 = (U16)(VehPosition*(-1))|0x8000;
	}
	return VehPositionU16;
}


/***********************************************************************
*  Name        : Get_FV_Current_DR
*  Description : FV_ODO_CUR record Vheicle Pose
*  Parameter   :
*  Returns     :
***********************************************************************/
void Get_FV_Current_DR(void)
{	
	DRIsAbsolutePose = TRUE;
	g_FV_adiGetVehPosOdo_bl(&FV_ODO_CUR);
	M4Msg_Update(E_M4_RESET_POSITION_REQ_U8, TRUE);		//NJ reset DR
	Timer_Start(DR_M4_INITREQUEST_ISFALSE, 20, TIMER_ONE_SHOT);	// stop reset after 20ms
}

/***********************************************************************
*  Name        : Get_FV_DR
*  Description : FV: ODO = SV:DR
*  Parameter   :
*  Returns     :
***********************************************************************/
APA_Vehicle_Position_FV Get_FV_DR(void)
{
    APA_Vehicle_Position_FV FV_DR = {0};     

	if(DRIsAbsolutePose)
	{
		FV_DR.VEH_DR_X           =  FV_ODO.XPosMM_si32 - FV_ODO_CUR.XPosMM_si32;              //mm
	    FV_DR.VEH_DR_Y           =  FV_ODO.YPosMM_si32 - FV_ODO_CUR.YPosMM_si32;              //mm
	    FV_DR.VEH_DR_YAW_RAD     =  FV_ODO.YawAngle_ui32 - FV_ODO_CUR.YawAngle_ui32;          //1/2^22 rad  
	}
	else
	{
	    FV_DR.VEH_DR_X           =  FV_ODO.XPosMM_si32;            //mm
	    FV_DR.VEH_DR_Y           =  FV_ODO.YPosMM_si32;            //mm
	    FV_DR.VEH_DR_YAW_RAD     =  FV_ODO.YawAngle_ui32;          //1/2^22 rad   
	}    
    return FV_DR;
}

APA_Vehicle_Position_FV VehicleCurrentPosition_FV = {0};
/***********************************************************************
*  Name        : GetAbsoluteVehPos
*  Description :
*  Parameter   :
*  Returns     :
***********************************************************************/
APA_Vehicle_Position_NJ GetAbsoluteVehPos(void)
{	
     
	static float PosAngleStor[5];   
    APA_Vehicle_Position_NJ VehicleCurrentLocation_NJ = {0};
	U8 OnRoadCalibReq = Get_Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS();

    VehicleCurrentPosition_FV = Get_FV_DR();
    VehicleCurrentLocation_NJ = DR_Change_TO_NJ(VehicleCurrentPosition_FV);
	return VehicleCurrentLocation_NJ;
}

/***********************************************************************
*  Name        : GetRelativeVehPos
*  Description :
*  Parameter   :
*  Returns     :
***********************************************************************/
APA_Vehicle_Position_NJ GetRelativeVehPos(APA_Vehicle_Position_NJ AbsoluteVehPos)
{
    static APA_Vehicle_Position_NJ VehLastPosition;
	APA_Vehicle_Position_NJ VehRelativePosition = {0};
	   
	U8 BlindPaddingReq = GetBlindPaddingStatus();
	U8 ModSetStatus = GetModStatus();
	U8 OnRoadCalibReq = Get_Soc_CPU_NOTIFY_M3_OnRoadCalib_STATUS();
    
	VehRelativePosition.VEH_DR_X = AbsoluteVehPos.VEH_DR_X - VehLastPosition.VEH_DR_X;
	VehRelativePosition.VEH_DR_Y = AbsoluteVehPos.VEH_DR_Y - VehLastPosition.VEH_DR_Y;
	VehRelativePosition.VEH_DR_YAW_DEGREES = AbsoluteVehPos.VEH_DR_YAW_DEGREES - VehLastPosition.VEH_DR_YAW_DEGREES;
	VehLastPosition = AbsoluteVehPos;
    
	return VehRelativePosition;
}


/***********************************************************************
*  Name        : DR_Change_SV_TO_NJ
*  Description : SV DR change NJ DR
*  Parameter   :
*  Returns     :
***********************************************************************/
APA_Vehicle_Position_NJ DR_Change_TO_NJ(APA_Vehicle_Position_FV Vehicle_Position_FV)
{	
    APA_Vehicle_Position_NJ Vehicle_Position_NJ;
    
	Vehicle_Position_NJ.VEH_DR_X = (float32)(-Vehicle_Position_FV.VEH_DR_Y); /* mm */
	Vehicle_Position_NJ.VEH_DR_Y = (float32)(Vehicle_Position_FV.VEH_DR_X);  /* mm */
    Vehicle_Position_NJ.VEH_DR_YAW_DEGREES = ((float32)(Vehicle_Position_FV.VEH_DR_YAW_RAD/64))*57.3; /*1/2^22 rad -> 1/2^16 degrees*/
    Vehicle_Position_NJ.VEH_DR_YAW_DEGREES = (float32)(-(Vehicle_Position_NJ.VEH_DR_YAW_DEGREES)/ 65536); /* 1/2^16 degrees -> degree */

	if((Vehicle_Position_NJ.VEH_DR_YAW_DEGREES > 180)&&(Vehicle_Position_NJ.VEH_DR_YAW_DEGREES < 360))
	{
		Vehicle_Position_NJ.VEH_DR_YAW_DEGREES = Vehicle_Position_NJ.VEH_DR_YAW_DEGREES - 360;
	}
	else if((Vehicle_Position_NJ.VEH_DR_YAW_DEGREES < -180)&&(Vehicle_Position_NJ.VEH_DR_YAW_DEGREES > -360))
	{
		Vehicle_Position_NJ.VEH_DR_YAW_DEGREES = Vehicle_Position_NJ.VEH_DR_YAW_DEGREES + 360;
	}
	
	return Vehicle_Position_NJ;
}

/***********************************************************************
*  Name        : VehiclePositionInitRequest
*  Description : InitReq = TRUE : notify NJ reset DR
*  Parameter   :
*  Returns     :
***********************************************************************/
void DRInitRequest(U8 InitReq)
{
	if(InitReq == TRUE)
	{
        g_FV_adiReSetSlotPS_bl();
	}
	
	M4Msg_Update(E_M4_RESET_POSITION_REQ_U8, InitReq);
	Timer_Start(DR_M4_INITREQUEST_ISFALSE, 20, TIMER_ONE_SHOT);
}

/***********************************************************************
*  Name        : VehiclePositionInitRequest
*  Description : notify NJ stop reset DR
*  Parameter   :
*  Returns     :
***********************************************************************/
void DRInitRequest_IsFalse()
{
	M4Msg_Update(E_M4_RESET_POSITION_REQ_U8, FALSE);
}


/***********************************************************************
*  Name        : IsResetDR
*  Description : 20ms timer(DR_ISRESET_POLLING) calls
*  Parameter   :
*  Returns     : 
***********************************************************************/
void DR_Reset_Handler(void)
{
	static U8 counter_third_reset = 0;   
	static BOOL isResetDRFlag = FALSE;
     	
	if((fabs(VehicleCurrentPosition_FV.VEH_DR_X) >= 40000) || (fabs(VehicleCurrentPosition_FV.VEH_DR_Y) >= 40000))// 40m reset
	{
		isResetDRFlag = TRUE;
	}
    
	if(isResetDRFlag == TRUE)
	{	
	    DRInitRequest(TRUE);
		counter_third_reset++;
		if(counter_third_reset>3)
		{
			isResetDRFlag = FALSE;
			counter_third_reset = 0;
		}
	}
} 

void APS_DR_Sender(void)
{
	float32 Pose_X;	
	float32 Pose_Y;	
	float32 Pose_Angle_FV;
	float32 Pose_Angle_HQ;

	Pose_X = (FV_ODO.XPosMM_si32  + HQCoordinateSystem_X_Offset * 10) * cos(HQCoordinateSystem_YAW) 
		   - (FV_ODO.YPosMM_si32  + HQCoordinateSystem_Y_Offset * 10) * sin(HQCoordinateSystem_YAW);
	
	Pose_Y = (FV_ODO.XPosMM_si32  + HQCoordinateSystem_X_Offset * 10) * sin(HQCoordinateSystem_YAW) 
		   + (FV_ODO.YPosMM_si32  + HQCoordinateSystem_Y_Offset * 10) * cos(HQCoordinateSystem_YAW);
	
	Pose_Angle_FV = ((float)(FV_ODO.YawAngle_ui32)/(4194304.0));	// value range : 0 ~ 2PI
	if(Pose_Angle_FV < 0)		
	{
		Pose_Angle_FV = Pose_Angle_FV + 2 * MATH_PI;
	}
	else if(Pose_Angle_FV > 2 * MATH_PI)
	{
		Pose_Angle_FV = Pose_Angle_FV - 2 * MATH_PI;
	}
	
	Pose_Angle_HQ = Pose_Angle_FV + HQCoordinateSystem_YAW;
	//value range convert : -PI ~ PI -> 0 ~ 2PI
	if(Pose_Angle_HQ > MATH_PI)
	{
		Pose_Angle_HQ = Pose_Angle_HQ - 2 * MATH_PI;
	} 
	else if(Pose_Angle_HQ < - MATH_PI)
	{
		Pose_Angle_HQ = Pose_Angle_HQ + 2 * MATH_PI;
	}
	
/*2021/08/30, DBC change/remove, resulting in no this signal*/
//	can_send_sig(APS_Pose_X, (U16)(Pose_X / 2 + 20000));	//mm
//	can_send_sig(APS_Pose_Y, (U16)(Pose_Y / 2 + 20000));	//mm
//	can_send_sig(APS_Pose_Angle, (U16)(Pose_Angle_HQ/0.005 + 628.0));	//unit : rad , value range : -PI ~ PI
}

