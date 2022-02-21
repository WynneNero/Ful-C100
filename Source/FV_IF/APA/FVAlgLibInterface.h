#ifndef _FVALGLIBINTERFACE_H
#define _FVALGLIBINTERFACE_H

#include "FVAlgLibInterfaceIF.h"

/****************************************
the FV state by APP defined
***************************************/
typedef enum
{
    PATH_PLAN_STANDBY,
	PATH_PLAN_INIT,
	PATH_PLAN_HANDLER,
	PATH_REPLAN_HANDLER,
	PATH_POINT_SNEDER,
	PATH_ERRORPOINT_SNEDER,
	PATH_PLAN_EXIT,
}APS_PATH_PLAN_STATUS;

enum
{
    PATH_INACTIVE,
	PATH_CALCULATING,
	PATH_GENERATE_SUCCESS,
	PATH_GENERATE_FALIED,
}APS_REPLANRESULT_STA;

/*********SV coordinate system*********
                 X
          +yaw   ^    
             \   |   
              \  |  
               \ | 
                \|
        Y<-------------------
                 | 0
                 |
                 |
                 |
ps:  The direction of the vehicle is X 
*************************************/
typedef struct
{
    S32 VEH_DR_X;
    S32 VEH_DR_Y;
    U32 VEH_DR_YAW_RAD;
}APA_Vehicle_Position_FV;


/***********NJ coordinate system**********
                Y
                ^   +yaw
                |   /
                |  /
                | /
                |/
      --------------------->x
                |
                |
                |
                |
ps:  The direction of the vehicle is Y      
********************************************/
typedef struct
{
    float32 VEH_DR_X;               // mm 
    float32 VEH_DR_Y;               // mm
    float32 VEH_DR_YAW_DEGREES;     // degrees
}APA_Vehicle_Position_NJ;


/****************************************
extern function declare : SysCycle_apS3FastT10msContainer call
***************************************/
void APS_PathPlan_Module_10ms_Entry(void);
void App2AlgInfo_CanReceiveHandler(void);
void App2AlgInfo_ControlCommandInfo_Command_Notify_ApaStateHandler(void);
void App2AlgInfo_ParkingPlaceInfo_TargetSlotInfo_SearchingDirectionHandler(void);
void Alg2AppDebugSignalHandler(void);


/****************************************
extern function declare : other file call
***************************************/
void Set_Dr_Initialize(U8 DrInitFlag);
void Set_Dr_Calculate(U8 DrCalFlag);
void Notify_FV_ApaState(APS_MODULE_STATUS ApaState);
void Set_Avm_TargetSlotType(void);

void Set_Avm_NeighBoringSlotStatus(U16 NeighBoringSlotStatus);
void Set_Avm_OppositeSpace(float OppositeSpace);
void Set_PathPlan(APS_PATH_PLAN_STATUS SetPathPlanStatus);
void Set_ReloatPlaceInfo(void);

void Clear_ReloatPlaceInfo(void);
void Clear_App2Alg_ParkingPlace_TargetSlot(void);
void VehicleDeadReckoningSender(void);
U16 VehPosSendToSoc_F32ToU16(float VehPosition);

APA_Vehicle_Position_FV Get_FV_DR(void);
APA_Vehicle_Position_NJ GetAbsoluteVehPos(void);
APA_Vehicle_Position_NJ GetRelativeVehPos(APA_Vehicle_Position_NJ AbsoluteVehPos);
APA_Vehicle_Position_NJ DR_Change_TO_NJ(APA_Vehicle_Position_FV Vehicle_Position_FV);

void DRInitRequest(U8 InitReq);
void DR_Reset_Handler(void);
void Get_FV_Current_DR(void);


/****************************************
extern function declare 
***************************************/

#endif


