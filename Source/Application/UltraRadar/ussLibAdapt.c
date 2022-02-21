#include "config.h"
#include "define.h"
#include "UssInfo_Msg_IF.h"
#include "ussLibAdapt.h"
#include "stdio.h"
#include <math.h>

#include "il_inc.h"
#include "il_par.h"

#include "InputSignalProc.h"
#include "ApsCanAPP.h"
#include "CanApp.h"


#include "ObjDetect_Pub.h" // ObjectProcApaSensorIndex
#include "ussLibIf.h"
#include "ComplexDrvier_Globaldef_IF.h"
#include "sw_timer.h"
#include "xprintf.h"
#include "pdcCtrl.h"

typedef enum 
{
	USS_LIB_PWR_REQ_UNKNOW,
	USS_LIB_PWR_REQ_ON,
	USS_LIB_PWR_REQ_OFF,
}USS_LIB_PWR_REQ_ENUM;

typedef struct 
{
	SInt32 SPosMM_si32;      // 后轴中心点走过的距离  单位mm                              
	SInt32 XPosMM_si32;      // 后轴中心点的全局坐标X 单位mm
	SInt32 YPosMM_si32;      // 后轴中心点的全局坐标Y 单位mm
	float YawAngle_fl;     // 车辆的纵向与全局坐标系X的夹�?单位1/2^22 rad，范围（0-2PI�?
}gType_APA_VehPos_st;
/*
typedef signed long     SInt32;       // -2147483648 .. +2147483647  ARREF:PLATFORM018
typedef unsigned long   UInt32;       //           0 .. 4294967295   ARREF:PLATFORM015
*/

typedef struct 
{
	FV_SlotInformationType Old_Carport;

	U8 ussLibAdaptOpenFlag;
	Message_TimeOut_Type to_sts;
	E_APA_RadarPwr_Status RadarPwr_Status;
	E_APA_Ubatt_Status  Ubatt_Status;
	USS_LIB_PWR_REQ_ENUM ussLibPwrReq;

    Boolean  RadarControlSwitch;
}ussLibAdaptCtrlType;

typedef struct
{
    UInt16 mpVehicleSpeedKph_ui16;
    UInt16 mptempcoeff_ui16;
    //! Mask with bit set for each USS configured in system (independent from current measurement function)
    UInt16 mpSensorsInSystem_bf16;
    //! Mask with bit set for each ECU ASIC port, connected to a USS (independent from current measurement function)
    UInt16 mpSensorPortsUsed_bf16;
    SInt8 mptempprimary_si8;
}gType_mpVehicle_st;

extern gType_mpVehicle_st m_mpVehicleData_st;

ussLibAdaptCtrlType ussLibAdaptCtrl;

static	USSDistanceResultStruct m_USSDistanceResult;

static int FV_ODO_ChangeTo_SV_DR(gType_APA_VehPos_st *DR_Position);
static int Coordinates_Global_change_TO_car(PAS_COORDINATE_POSITION POINT_POSITION,PAS_COORDINATE_POSITION *car_PAS_Coordinate_Position);

void ussLibAdaptOpen(void)
{
	_memset(&m_USSDistanceResult,13,sizeof(USSDistanceResultStruct)); // for test


	ussLibAdaptCtrl.RadarPwr_Status = RadarPwrStsNotValid;
	ussLibAdaptCtrl.ussLibAdaptOpenFlag = TRUE;
    Set_RadarControlSwitch_Status(FALSE);
}

void Set_BCS_5_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_5_A_Timeout = flag;
}

void Set_BCS_10_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_10_A_Timeout = flag;
}

void Set_GW_TCU_1_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.GW_TCU_1_A_Timeout = flag;
}

void Set_BCS_SAS_1_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_SAS_1_A_Timeout = flag;
}

void Set_BCS_9_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_9_A_Timeout = flag;
}

void Set_BCS_EPB_1_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_EPB_1_A_Timeout = flag;
}

void Set_GW_EMS_1_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.GW_EMS_1_A_Timeout = flag;
}

void Set_BCS_11_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_11_A_Timeout = flag;
}

void Set_BCS_6_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.BCS_6_A_Timeout = flag;
}

void Set_GW_ICM_HVAC_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.GW_ICM_HVAC_A_Timeout = flag;
}

void Set_GW_BCM_2_A_Timerout(U8 flag)
{
	ussLibAdaptCtrl.to_sts.GW_BCM_2_A_Timeout = flag;
}

void Set_RadarControlSwitch_Status(Boolean RadarControlSwitch)
{
	ussLibAdaptCtrl.RadarControlSwitch = RadarControlSwitch;
}


extern Boolean CanDiag_GetNMTimeOutFlag(UInt8 nodeindex);

//extern Position_Veh_struct DOD;//当前坐标系原点的坐标点（g,h,θ�?也即车辆DOD
//PAS_COORDINATE_POSITION POINT_POSITION;//在大坐标系下点的坐标


//static	gType_VehPos_st Old_f_VehPosOdo_pst,f_VehPosOdo_pst;
static int FV_ODO_ChangeTo_SV_DR(gType_APA_VehPos_st *DR_Position)
{
	gType_VehPos_st l_VehPosOdo_st={0};
	float  l_yaw;

	g_FV_adiGetVehPosOdo_bl (&l_VehPosOdo_st);
	l_VehPosOdo_st.YawAngle_ui32 = l_VehPosOdo_st.YawAngle_ui32/4096;
	l_VehPosOdo_st.YawAngle_ui32 =l_VehPosOdo_st.YawAngle_ui32%6434;
	l_yaw=((float)(l_VehPosOdo_st.YawAngle_ui32))/((float)1024);

	DR_Position->XPosMM_si32 = -l_VehPosOdo_st.YPosMM_si32;
	DR_Position->YPosMM_si32 = l_VehPosOdo_st.XPosMM_si32;
	DR_Position->YawAngle_fl = l_yaw + 3.141592/2;

}

//如下接口，返回值为当前坐标系下的坐标�?
int Coordinates_Global_change_TO_car(PAS_COORDINATE_POSITION POINT_POSITION,PAS_COORDINATE_POSITION *car_PAS_Coordinate_Position)//FV车位类型大地坐标子转换到车身坐标�?
{
	gType_APA_VehPos_st VehPos;
	FV_ODO_ChangeTo_SV_DR(&VehPos);
	float theta = VehPos.YawAngle_fl - 3.141592/2;
	car_PAS_Coordinate_Position->COORDINATE_X =	POINT_POSITION.COORDINATE_X*(cos(theta)) + POINT_POSITION.COORDINATE_Y*(sin(theta)) - (VehPos.XPosMM_si32*(cos(theta)) + VehPos.YPosMM_si32*(sin(theta)));
	car_PAS_Coordinate_Position->COORDINATE_Y = POINT_POSITION.COORDINATE_Y*(cos(theta)) - POINT_POSITION.COORDINATE_X*(sin(theta)) - (-VehPos.XPosMM_si32*(sin(theta)) + VehPos.YPosMM_si32*(cos(theta)));
	return 1;
}

gType_APA_VehPos_st DR_Position;

int FV_ODO_Over_MAX(PAS_COORDINATE_POSITION POINT_POSITION,gType_VehPos_st * FV_ODO)
{
	gType_VehPos_st l_VehPosOdo_st,l_VehPosOdo_st_old;
	PAS_COORDINATE_POSITION POINT_POSITION_old;
	g_FV_adiGetVehPosOdo_bl (&l_VehPosOdo_st);

	//往前走溢出，把坐标原点移动到溢出的�?
	if (l_VehPosOdo_st.XPosMM_si32 > 2000000000 && l_VehPosOdo_st.XPosMM_si32 > l_VehPosOdo_st_old.XPosMM_si32)
	{
		POINT_POSITION.COORDINATE_X = -(2147483647 - POINT_POSITION_old.COORDINATE_X);
	}
	else if (l_VehPosOdo_st.XPosMM_si32 < -2000000000 && l_VehPosOdo_st.XPosMM_si32 > l_VehPosOdo_st_old.XPosMM_si32)
	{
		POINT_POSITION.COORDINATE_X = -(2147483647 - POINT_POSITION_old.COORDINATE_X);
	}




}

static FV_SlotInformationType FV_slot[2];
extern PARKING_SLOT_TYPE APA_Park_type;
int fill_AD_point(USSParkingSlotSearch side, FV_SlotInformationType *SV_slot)//没有AD点的时候，根据车位类型去构造AD�?D点规则：与c点比较，3米，如果水平就给3010吧，垂直�?990�?
{
	BOOL ret = 0;
	USSParkingSlotSearch Get_FV_USS_Slot_Flag = 0;	

	Get_and_Save_FV_USS_Slot(side,FV_slot);
	
	if((0 != FV_slot[0].SlotID) && (0 == FV_slot[1].SlotID))
	{
		Get_FV_USS_Slot_Flag = LeftSearch_enm;
	}
	else if((0 != FV_slot[1].SlotID) && (0 == FV_slot[0].SlotID))
	{
		Get_FV_USS_Slot_Flag = RightSearch_enm;
	}
	else if((0 != FV_slot[1].SlotID) && (0 != FV_slot[0].SlotID))
	{
	    Get_FV_USS_Slot_Flag = LeftRightSearch_enm;
	}
	else 
	{
		Get_FV_USS_Slot_Flag = NOSearch_enm;
	}
	
	if(NOSearch_enm != Get_FV_USS_Slot_Flag)		
	{
    	if((LeftSearch_enm == Get_FV_USS_Slot_Flag) || (Get_FV_USS_Slot_Flag == LeftRightSearch_enm))
    	{
        	SV_slot[0].Side_en = FV_slot[0].Side_en;
        	SV_slot[0].PSType_en = FV_slot[0].PSType_en;
        	SV_slot[0].SlotID = FV_slot[0].SlotID;

        	if((FV_slot[0].SlotDepth == 2000) || (FV_slot[0].SlotDepth == 1400))
        	{
                SV_slot[0].SlotDepth = 5000;
        	}
        	else
        	{
                SV_slot[0].SlotDepth = FV_slot[0].SlotDepth;
        	}


        	if((SV_slot[0].SlotDepth == 2000) || (SV_slot[0].SlotDepth == 1400))
        	{
                SV_slot[0].SlotDepth = 5000;
        	}

        	SV_slot[0].SlotLocationAx =	-FV_slot[0].SlotLocationAy;
        	SV_slot[0].SlotLocationAy = FV_slot[0].SlotLocationAx ;

        	SV_slot[0].SlotLocationBx =	-FV_slot[0].SlotLocationBy ;
        	SV_slot[0].SlotLocationBy = FV_slot[0].SlotLocationBx ;

        	
        	SV_slot[0].SlotLocationCx =	-FV_slot[0].SlotLocationCy;
        	SV_slot[0].SlotLocationCy = FV_slot[0].SlotLocationCx ;

        	SV_slot[0].SlotLocationDx =	-FV_slot[0].SlotLocationDy;
        	SV_slot[0].SlotLocationDy = FV_slot[0].SlotLocationDx ;

            // 补D�?   
        	if ((SV_slot[0].PSType_en == g_CrossPSType_enm))
        	{
        		SV_slot[0].SlotLocationDx = (SV_slot[0].SlotLocationBx + SV_slot[0].SlotLocationCx)/2;
        		SV_slot[0].SlotLocationDy = SV_slot[0].SlotLocationCy + 2990;
        	}
            else if ((FV_slot[0].PSType_en == g_ParallelPSType_enm))
            {
                SV_slot[0].SlotLocationDx = (SV_slot[0].SlotLocationBx + SV_slot[0].SlotLocationCx)/2;
                SV_slot[0].SlotLocationDy = SV_slot[0].SlotLocationCy + 3010;
            }
            else
            {
            }

            // 补A�?
        	if ((SV_slot[0].PSType_en == g_CrossPSType_enm))
        	{
				SV_slot[0].SlotLocationAx = SV_slot[0].SlotLocationBx;
				SV_slot[0].SlotLocationAy = SV_slot[0].SlotLocationBy - 2990;
        	}
            else if ((FV_slot[0].PSType_en == g_ParallelPSType_enm))
            {
				SV_slot[0].SlotLocationAx = SV_slot[0].SlotLocationBx;
				SV_slot[0].SlotLocationAy = SV_slot[0].SlotLocationBy - 3010;
            }
            else
            {
            }  
            
            ret = 1;
       }
       
        if((RightSearch_enm == Get_FV_USS_Slot_Flag) || (Get_FV_USS_Slot_Flag == LeftRightSearch_enm))
    	{
        	SV_slot[1].Side_en = FV_slot[1].Side_en;
        	SV_slot[1].PSType_en = FV_slot[1].PSType_en;
        	SV_slot[1].SlotID = FV_slot[1].SlotID;

        	if((FV_slot[1].SlotDepth == 2000) || (FV_slot[1].SlotDepth == 1400))
        	{
                SV_slot[1].SlotDepth = 5000;
        	}
        	else
        	{
                SV_slot[1].SlotDepth = FV_slot[1].SlotDepth;
        	}

        	SV_slot[1].SlotLocationAx =	-FV_slot[1].SlotLocationAy;
        	SV_slot[1].SlotLocationAy = FV_slot[1].SlotLocationAx ;

        	SV_slot[1].SlotLocationBx =	-FV_slot[1].SlotLocationBy ;
        	SV_slot[1].SlotLocationBy = FV_slot[1].SlotLocationBx ;

        	
        	SV_slot[1].SlotLocationCx =	-FV_slot[1].SlotLocationCy;
        	SV_slot[1].SlotLocationCy = FV_slot[1].SlotLocationCx ;

        	SV_slot[1].SlotLocationDx =	-FV_slot[1].SlotLocationDy;
        	SV_slot[1].SlotLocationDy = FV_slot[1].SlotLocationDx ;

            // 补D�?   
        	if ((SV_slot[1].PSType_en == g_CrossPSType_enm))
        	{
        		SV_slot[1].SlotLocationDx = (SV_slot[1].SlotLocationBx + SV_slot[1].SlotLocationCx)/2;
        		SV_slot[1].SlotLocationDy = SV_slot[1].SlotLocationCy + 2990;
        	}
            else if ((FV_slot[1].PSType_en == g_ParallelPSType_enm))
            {
                SV_slot[1].SlotLocationDx = (SV_slot[1].SlotLocationBx + SV_slot[1].SlotLocationCx)/2;
                SV_slot[1].SlotLocationDy = SV_slot[1].SlotLocationCy + 3010;
            }
            else
            {
            }

            // 补A�?
        	if ((SV_slot[1].PSType_en == g_CrossPSType_enm))
        	{
				SV_slot[1].SlotLocationAx = SV_slot[1].SlotLocationBx;
				SV_slot[1].SlotLocationAy = SV_slot[1].SlotLocationBy - 2990;
        	}
            else if ((FV_slot[1].PSType_en == g_ParallelPSType_enm))
            {
				SV_slot[1].SlotLocationAx = SV_slot[1].SlotLocationBx;
				SV_slot[1].SlotLocationAy = SV_slot[1].SlotLocationBy - 3010;
            }
            else
            {
            }
            ret = 1;
       }
    }
    else 
    {
        ret = 0;
    }

	return ret;

}

FV_SlotInformationType FV_slot_raw[2][2];
static U8 FV_slot_BACKUP_slotId[2][2];
extern FV_SlotInformationType g_SV_pslPS_st[2][2];
USSParkingSlotSearch Get_and_Save_FV_USS_Slot(USSParkingSlotSearch side, FV_SlotInformationType * FV_slot_backup)
{	
	U8 slotCnt = 0,i = 0;	
    FV_SlotInformationType FV_slot_raw_temp[2][2];
	USSParkingSlotSearch ret = NOSearch_enm;
	
    if((LeftSearch_enm == side)||(LeftRightSearch_enm == side))
    {
    	slotCnt = g_FV_adiGetSlotPSNum_ui8(g_SideLeft_enm);
    	if(slotCnt>0)
    	{	    	
    		for(i=0;i<slotCnt;i++)
    		{
    			g_FV_adiGetSlotPS_bl(g_SideLeft_enm,&(FV_slot_raw_temp[g_SideLeft_enm][i]),i);
    		}
		
            for(i=0;i<slotCnt;i++)
            {
                g_FV_adiGetSlotPS_bl(g_SideLeft_enm,&(FV_slot_raw[g_SideLeft_enm][i]),i);
            }
			
			if(g_ParallelPSType_enm == FV_slot_raw[g_SideLeft_enm][0].PSType_en)
			{				
	    		_memcpy(&(FV_slot_backup[g_SideLeft_enm]), &(FV_slot_raw[g_SideLeft_enm][0]),sizeof(FV_SlotInformationType));
			}
			else if(g_ParallelPSType_enm == FV_slot_raw[g_SideLeft_enm][1].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideLeft_enm]), &(FV_slot_raw[g_SideLeft_enm][1]),sizeof(FV_SlotInformationType));
			}
			else if(g_CrossPSType_enm == FV_slot_raw[g_SideLeft_enm][0].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideLeft_enm]), &(FV_slot_raw[g_SideLeft_enm][0]),sizeof(FV_SlotInformationType));
			}
			else if(g_CrossPSType_enm == FV_slot_raw[g_SideLeft_enm][1].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideLeft_enm]), &(FV_slot_raw[g_SideLeft_enm][1]),sizeof(FV_SlotInformationType));			
			}
			else
			{			
				_memset(&(FV_slot_backup[g_SideLeft_enm]),0,sizeof(FV_SlotInformationType));
			}		
    		ret =  LeftSearch_enm;
    	}
	}
    if((RightSearch_enm == side)||(LeftRightSearch_enm == side))
    {
    	slotCnt = g_FV_adiGetSlotPSNum_ui8(g_SideRight_enm);	
    	if(slotCnt>0)
    	{
    		for(i=0;i<slotCnt;i++)
    		{
    			g_FV_adiGetSlotPS_bl(g_SideRight_enm,&(FV_slot_raw_temp[g_SideRight_enm][i]),i);
    		}
			
    		for(i=0;i<slotCnt;i++)
    		{
    			g_FV_adiGetSlotPS_bl(g_SideRight_enm,&(FV_slot_raw[g_SideRight_enm][i]),i);
    		}			     

			if(g_ParallelPSType_enm == FV_slot_raw[g_SideRight_enm][0].PSType_en)
			{				
	    		_memcpy(&(FV_slot_backup[g_SideRight_enm]), &(FV_slot_raw[g_SideRight_enm][0]),sizeof(FV_SlotInformationType));
			}
			else if(g_ParallelPSType_enm == FV_slot_raw[g_SideRight_enm][1].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideRight_enm]), &(FV_slot_raw[g_SideRight_enm][1]),sizeof(FV_SlotInformationType));
			}
			else if(g_CrossPSType_enm == FV_slot_raw[g_SideRight_enm][0].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideRight_enm]), &(FV_slot_raw[g_SideRight_enm][0]),sizeof(FV_SlotInformationType));
			}
			else if(g_CrossPSType_enm == FV_slot_raw[g_SideRight_enm][1].PSType_en)
			{
				_memcpy(&(FV_slot_backup[g_SideRight_enm]), &(FV_slot_raw[g_SideRight_enm][1]),sizeof(FV_SlotInformationType));			
			}
			else
			{			
				_memset(&(FV_slot_backup[g_SideRight_enm]),0,sizeof(FV_SlotInformationType));
			}
    		ret = RightSearch_enm;
    	}
	}

    if(NOSearch_enm == ret)
    {        
        _memset(&(FV_slot_backup[g_SideLeft_enm]),0,sizeof(FV_SlotInformationType));
        _memset(&(FV_slot_backup[g_SideRight_enm]),0,sizeof(FV_SlotInformationType));
    }
	
	return ret;

}


/***********************************************************************
* FUNCTION    : USS_Get_CAN_Data
* DESCRIPTION : Softec:Received CAN	Signal
* INPUTS      : USS_CAN_DATA_Handle can_signal
* RETURN      : unsigned char
* RETURN VALUE: 0:OK	1:NOT_OK
***********************************************************************/
Boolean g_SV_adiGetCAN_Data_bl(FV_USS_CAN_DATA_Type         *  can_signal)
{
	can_signal->sftc_FLWheelSpeedRC                 = can_receive_sig(WheelPulse_FL);
	can_signal->sftc_FRWheelSpeedRC                 = can_receive_sig(WheelPulse_FR);
	can_signal->sftc_RLWheelSpeedRC                 = can_receive_sig(WheelPulse_RL);
	can_signal->sftc_RRWheelSpeedRC                 = can_receive_sig(WheelPulse_RR);

    can_signal->sftc_FLWheelSpeed                   = can_receive_sig(WheelSpeed_FL);
	can_signal->sftc_FRWheelSpeed                   = can_receive_sig(WheelSpeed_FR);
	can_signal->sftc_RLWheelSpeed                   = can_receive_sig(WheelSpeed_RL);
	can_signal->sftc_RRWheelSpeed                   = can_receive_sig(WheelSpeed_RR);

    can_signal->sftc_FLWheelDirection               = can_receive_sig(DrivingDirection);
	can_signal->sftc_FRWheelDirection               = can_receive_sig(DrivingDirection);
	can_signal->sftc_RLWheelDirection               = can_receive_sig(DrivingDirection);
	can_signal->sftc_RRWheelDirection               = can_receive_sig(DrivingDirection);

	can_signal->sftc_GearStatus                     = get_ActGear();
	can_signal->sftc_VehicleSpeed                   = can_receive_sig(VehicleSpeed);
	can_signal->sftc_SteeringAngle                  = get_SAS_WheelSteerAngle_FV();
	can_signal->sftc_steeringAngleValidity          = can_receive_sig(SAS_St);
       
	can_signal->sftc_PEPS_PowerMode                 = can_receive_sig(PowerMode);
	can_signal->sftc_EPBSwitchSts                   = can_receive_sig(WorkingSt_EPB);
    can_signal->sftc_AC_AmbientTemperature          = can_receive_sig(AmbientTemp);
    can_signal->sftc_EMS_Pedal_Position             = can_receive_sig(BrakePedalSt);
     
    can_signal->sftc_LateralAcce                    = can_receive_sig(Acceleration_Y);      
	can_signal->sftc_LongitAcce                     = can_receive_sig(Acceleration_X);	   
    can_signal->sftc_YRSYawRate                     = can_receive_sig(YawRate);
	can_signal->sftc_LateralSensorSts               = can_receive_sig(ErrorSt_YRS);
    
	can_signal->sftc_LongitSensorSts                = can_receive_sig(ErrorSt_YRS);    
	can_signal->sftc_YRSYawRateSensorSts            = can_receive_sig(ErrorSt_YRS);    
	can_signal->sftc_TurnLight_Left                 = can_receive_sig(TurningSt_Left);
	can_signal->sftc_TurnLight_Right                = can_receive_sig(TurningSt_right);	
    
    
	can_signal->WIC_FR_Tick_ui16                    = get_ABS3_receive_timePoint();	
	can_signal->WIC_FL_Tick_ui16                    = get_ABS3_receive_timePoint();
	can_signal->WIC_RR_Tick_ui16                    = get_ABS3_receive_timePoint();
	can_signal->WIC_RL_Tick_ui16                    = get_ABS3_receive_timePoint();
	
	return TRUE;
};



//编写电源管理适配�?
Boolean g_SV_SetRadarPwrStatus_bl(E_APA_RadarPwr_Status              RadarPwr_Status);
Boolean g_SV_SetUbattStatus_bl(E_APA_Ubatt_Status             Ubatt_Status);

static void radarPowerOnCb(void *p)
{
	g_SV_SetRadarPwrStatus_bl(RadarPwrStsValid);
	g_SV_SetUbattStatus_bl(UbattStsValid);
	
	ussLibAdaptCtrl.ussLibPwrReq = USS_LIB_PWR_REQ_UNKNOW;
}
Boolean g_SV_adiSetRadar_PwrCtrl_ON_bl(void)
{
	F_RADAR_EN_ON();
	R_RADAR_EN_ON();
	ussLibAdaptCtrl.ussLibPwrReq = USS_LIB_PWR_REQ_ON;

	g_SV_SetRadarPwrStatus_bl(RadarPwrStsNotValid);

	// 30 ms delay，pwr OK.
	SwTmrMgr_Start(RADAR_POWER_CTRL_TMR, 500, radarPowerOnCb, NULL, FALSE);
	
}
Boolean g_SV_adiSetRadar_PwrCtrl_OFF_bl(void)
{
	F_RADAR_EN_OFF();
	R_RADAR_EN_OFF();	
	ussLibAdaptCtrl.ussLibPwrReq = USS_LIB_PWR_REQ_OFF;
	g_SV_SetRadarPwrStatus_bl(RadarPwrStsNotValid);

	
}
Boolean g_SV_adiGetRadarPwrStatus_bl(E_APA_RadarPwr_Status  *RadarPwr_Status)
{
	*RadarPwr_Status = ussLibAdaptCtrl.RadarPwr_Status;
	return 0;
}
Boolean g_SV_adiGetUbattStatus_bl(E_APA_Ubatt_Status  *Ubatt_Status)
{
	*Ubatt_Status = ussLibAdaptCtrl.Ubatt_Status;
	return 0;
}

Boolean g_SV_SetRadarPwrStatus_bl(E_APA_RadarPwr_Status              RadarPwr_Status)
{
	ussLibAdaptCtrl.RadarPwr_Status = RadarPwr_Status;
}
Boolean g_SV_SetUbattStatus_bl(E_APA_Ubatt_Status             Ubatt_Status)
{
	ussLibAdaptCtrl.Ubatt_Status = Ubatt_Status;
}

Boolean g_SV_GetRadarControlSwitch_bl(void)
{
    return ussLibAdaptCtrl.RadarControlSwitch;
}

void ussPowerManagerRunning(void)
{
	if(TRUE == ussLibAdaptCtrl.ussLibAdaptOpenFlag)
	{
		if(USS_LIB_PWR_REQ_ON == ussLibAdaptCtrl.ussLibPwrReq)
		{
			
			
		}
	}
	
}


unsigned char Get_Message_TimeOut(Message_TimeOut_Handle to_sts)
{ 
		/*
		message�?
		BCS_5_A
		BCS_10_A
		GW_TCU_1_A 
		BCS_SAS_1_A
		BCS_9_A
		BCS_EPB_1_A
		GW_EMS_1_A
		BCS_11_A
		BCS_6_A
		GW_ICM_HVAC_A
		GW_BCM_2_A
		BCS_SAS_1_A
		GW_EMS_1_A
		*/
#if 0
	if(to_sts!=NULL)
	{
		to_sts->TO_EMS_EngineRPM = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_EMS);/*之前已经定义好的就直接调�?未定义的重新定义*/
		to_sts->TO_ESC_FrontWheelSpeedsKPH = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ESC);/*全部ESC都是同一个节�?/
		to_sts->TO_ESC_RearWheelSpeedsKPH = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ESC);/*,*/
		to_sts->TO_ESC_Status = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ESC);/*,*/
		to_sts->TO_ESC_WheelSpeedsRC = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ESC);/*,*/
		to_sts->TO_MMI_Safety_Info = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_MMI);/*,*/
		to_sts->TO_SAS_Status  = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_TCM);/*SAS与TCM同一个节�?/
		to_sts->TO_TCM_IntegrationSwtCtrl  = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_TCM);/* */
		to_sts->TO_TCU_Status = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_TCU);/**/
		to_sts->TO_YRS1 = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ACU);/**/
		to_sts->TO_YRS2 = CanDiag_GetNMTimeOutFlag(NUM_DTC_LOST_ACU);/**/
		return USS_GET_INFO_OK;
	}
	else
	{
		return USS_GET_INFO_FAIL;
	}
#endif
	
}

#if 1
unsigned int ObjDetect_GetApaSensorDetectedDistance(ObjectProcApaSensorIndex index) // ObjectProcApaSensorIndex index
{
	return 0x7fff;// for test
}
#endif

typedef struct
{
    U16         Current_TX_Sns;              //当前发送传感器
    U16         Current_RX_Sns;              //当前接受传感�?
    U16         Sns_DE_RawData[12][6];       //直接回波，单位mm
    U16         Sns_CE_RawData[12][6];       //间接接回波，单位mm
}gType_EchoRawData_st;

extern U16 g_FV_adiGetDirectEcho_ui16( U8 f_Direction_ui8, U8 f_Sensor_ui8 );
extern gType_EchoRawData_st *g_FV_adiGetRawEcho_pst(void);

typedef union 
{
    U16 pdcLockBits;
    struct 
    {
        U16 flsPdcLock:1;
        U16 frsPdcLock:1;
        U16 flPdcLock:1;
        U16 frPdcLock:1;
        U16 fmlPdcLock:1;
        U16 fmrPdcLock:1;
        
        U16 rlsPdcLock:1;
        U16 rrsPdcLock:1;
        U16 rlPdcLock:1;
        U16 rrPdcLock:1;
        U16 rmlPdcLock:1;
        U16 rmrPdcLock:1; 
        U16 reserved:4;
    };
}ussPdcLockBitsType;
static ussPdcLockBitsType ussPdcLockBits;

typedef union 
{
    S16 ussPdcFlWicPoint;
    S16 ussPdcFlmWicPoint;
    S16 ussPdcFrmWicPoint;
    S16 ussPdcFrWicPoint;

    S16 ussPdcRlWicPoint;
    S16 ussPdcRlmWicPoint;
    S16 ussPdcRrmWicPoint;
    S16 ussPdcRrWicPoint;
}ussPdcLockWicType;
static ussPdcLockWicType ussPdcLockWic;

void clrUssPdcLockBits(void)
{
    ussPdcLockBits.pdcLockBits = 0;
}


#define USS_LONG_SNS_ENABLE_BLIND  0
#define WIC_SPEED_EXPIRY   15
#define WIC_SPEED_MAX  4096

static U8 touchWicSumPoint(S16 speedRc,S16 wicPoint)
{
    S16 speedRcDiff;
    U8 ret = 0;
    speedRcDiff = speedRc - wicPoint;
    if((speedRcDiff)<0)
    {                    
        if((speedRcDiff + WIC_SPEED_MAX)>=WIC_SPEED_EXPIRY)
        {
            ret = 1;
        }
    }
    else 
    {
        if(speedRcDiff > WIC_SPEED_EXPIRY)
        {
            ret = 1;
        }
    }
    return ret;
}

extern  S32 FLS_point_DistanceMin,FRS_point_DistanceMin;
extern BOOL AVM_ENTER_FLAG;
static void ussClrBlindLockCb(void *p)
{
   clrUssPdcLockBits(); 
}


void USS_Distance_CanSender(void)
{
    can_send_sig(DistanceValue_RR,   (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm));
	can_send_sig(DistanceValue_RMR,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm));
	can_send_sig(DisstanceValue_RML, (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm));
	can_send_sig(DisstanceValue_RL,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm));	

	can_send_sig(DistanceValue_FR,   (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm));
	can_send_sig(DistanceValue_FMR,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm));
	can_send_sig(DistanceValue_FML,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm));
	can_send_sig(DistanceValue_FL,   (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm));

	can_send_sig(DistanceValue_FRS,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm));
	can_send_sig(DistanceValue_FLS,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm));
	can_send_sig(DistanceValue_RRS,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm));
	can_send_sig(DistanceValue_RLS,  (USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm));
}


void ObjDetectDistanceUpdateLoop(void)  // 10 ms
{	
	static U8 deDebugPeriod = 0;
	USS_PDC_Struct FV_PDC_distance_st;
	FV_USSDistanceResultStruct f_distance_st;

	if(TRUE == ussLibAdaptCtrl.ussLibAdaptOpenFlag)
	{        
        if(GetMmiTouchDebugFlag() == 3)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RR_Zone  = can_receive_sig(alpha_USS_RR);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RMR_Zone = can_receive_sig(alpha_USS_RMR);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RML_Zone = can_receive_sig(alpha_USS_RML);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RL_Zone  = can_receive_sig(alpha_USS_RL);
            
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FR_Zone  = can_receive_sig(alpha_USS_FR);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FMR_Zone = can_receive_sig(alpha_USS_FMR);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FML_Zone = can_receive_sig(alpha_USS_FML);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FL_Zone  = can_receive_sig(alpha_USS_FL);
    
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone = can_receive_sig(alpha_USS_RR_long);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone = can_receive_sig(alpha_USS_RL_long);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone = can_receive_sig(alpha_USS_FR_long);
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone = can_receive_sig(alpha_USS_FL_long);
        }
        else 
        {                
            g_FV_adiGetPDCDistance_bl(&FV_PDC_distance_st); 
            g_FV_adiGetUssDistance_bl(&f_distance_st);                                  
        }
       
        /* Object Detect Distance For Track Control */
        if(f_distance_st.USS_Distance_RRS > 5000)
        {
            f_distance_st.USS_Distance_RRS = 5000;
        }
        if(f_distance_st.USS_Distance_RLS > 5000)
        {
            f_distance_st.USS_Distance_RLS = 5000;
        }
        if(f_distance_st.USS_Distance_FRS > 5000)
        {
            f_distance_st.USS_Distance_FRS = 5000;
        }
        if(f_distance_st.USS_Distance_FLS > 5000)
        {
            f_distance_st.USS_Distance_FLS = 5000;
        }
        
        USS_Distance_Info.USS_Distance_RRS              = f_distance_st.USS_Distance_RRS;
        USS_Distance_Info.USS_Distance_RLS              = f_distance_st.USS_Distance_RLS;                 
        USS_Distance_Info.USS_Distance_FRS              = f_distance_st.USS_Distance_FRS;
        USS_Distance_Info.USS_Distance_FLS              = f_distance_st.USS_Distance_FLS;
                       
        USS_Distance_Info.USS_Distance_RR               = f_distance_st.USS_Distance_RR;
        USS_Distance_Info.USS_Distance_RRM              = f_distance_st.USS_Distance_RRM;
        USS_Distance_Info.USS_Distance_RLM              = f_distance_st.USS_Distance_RLM;
        USS_Distance_Info.USS_Distance_RL               = f_distance_st.USS_Distance_RL;
        
        USS_Distance_Info.USS_Distance_FR               = f_distance_st.USS_Distance_FR;
        USS_Distance_Info.USS_Distance_FRM              = f_distance_st.USS_Distance_FRM;
        USS_Distance_Info.USS_Distance_FLM              = f_distance_st.USS_Distance_FLM;
        USS_Distance_Info.USS_Distance_FL               = f_distance_st.USS_Distance_FL;
    
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone = 5000;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone = 5000;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone = 5000;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone = 5000;
        }
    
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FLS_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FL_Zone    = FV_PDC_distance_st.PAS_PDC_DISTANCE_FL_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FML_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_FML_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FMR_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_FMR_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FR_Zone    = FV_PDC_distance_st.PAS_PDC_DISTANCE_FR_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_FRS_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone;
        
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RLS_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RL_Zone    = FV_PDC_distance_st.PAS_PDC_DISTANCE_RL_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RML_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_RML_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RMR_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_RMR_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RR_Zone    = FV_PDC_distance_st.PAS_PDC_DISTANCE_RR_Zone;
        USS_PDC_raw_distance_Unit_mm.PAS_PDC_DISTANCE_RRS_Zone   = FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone;
    
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone = 5000;
        }
		if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone = 5000;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone = 5000;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone > 5000)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone = 5000;
        }
		
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FL_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FL_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FML_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FML_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FMR_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FMR_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_FR_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_FR_Zone = 2550;
        }
    
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RL_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RL_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RML_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RML_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RMR_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RMR_Zone = 2550;
        }
        if(FV_PDC_distance_st.PAS_PDC_DISTANCE_RR_Zone > 2550)
        {
            FV_PDC_distance_st.PAS_PDC_DISTANCE_RR_Zone = 2550;
        }
    
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FLS_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FLS_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FL_Zone_cm    = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FL_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FML_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FML_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FMR_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FMR_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FR_Zone_cm    = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FR_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_FRS_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_FRS_Zone/10);

        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RLS_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RLS_Zone/10);            
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RL_Zone_cm    = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RL_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RML_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RML_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RMR_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RMR_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RR_Zone_cm    = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RR_Zone/10);
        USS_PDC_distance_Unit_cm.PAS_PDC_DISTANCE_RRS_Zone_cm   = (FV_PDC_distance_st.PAS_PDC_DISTANCE_RRS_Zone/10);

        USS_Distance_CanSender();    
        if(GetMmiTouchDebugFlag() == 1)
        {
            deDebugPeriod++;
            if(deDebugPeriod >= 2)
            {
                deDebugPeriod = 0;

                can_send_sig(USS_DE_FLS,USS_Distance_Info.USS_Distance_FLS);
                can_send_sig(USS_DE_RLS,USS_Distance_Info.USS_Distance_RLS);
                can_send_sig(USS_DE_FRS,USS_Distance_Info.USS_Distance_FRS);
                can_send_sig(USS_DE_RRS,USS_Distance_Info.USS_Distance_RRS);
                
                can_send_sig(USS_DE_RR, USS_Distance_Info.USS_Distance_RR);
                can_send_sig(USS_DE_RMR,USS_Distance_Info.USS_Distance_RRM);
                can_send_sig(USS_DE_RML,USS_Distance_Info.USS_Distance_RLM);
                can_send_sig(USS_DE_RL, USS_Distance_Info.USS_Distance_RL);
				
                can_send_sig(USS_DE_FR, USS_Distance_Info.USS_Distance_FR);
                can_send_sig(USS_DE_FMR,USS_Distance_Info.USS_Distance_FRM);
                can_send_sig(USS_DE_FML,USS_Distance_Info.USS_Distance_FLM);
                can_send_sig(USS_DE_FL, USS_Distance_Info.USS_Distance_FL);
            }            
        }          
	}	
}

