/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
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
* Version       Date    Name            Changes and comments
*-----------------------------------------------------------------------
* 0.1    Aug 11,2016   LIU Chenxi    Initial version
*----------------------------------------------------------------------
* 0.2    Dec 20,2016   ShangQiuju   Remove unused include files.
*----------------------------------------------------------------------
* 0.3    Dec 21,2016   Peijingli        Change file include path
*----------------------------------------------------------------------
* 0.4    Jan 05,2017   ShangQiuju        Update sync and async function.
*----------------------------------------------------------------------
* 0.5    Jan 24,2017   ZhangJie        FIX Coverity warnings.
*----------------------------------------------------------------------
* 0.6   Mar 07,2017    PEI Jingli    Fix headfile included.
*=====================================================================*/
#include "Sig_Combine.h"

U8 Sig_AccStatus = (U8)0;
U8 Sig_WakeupReason;
U8 Sig_SystemState = (U8)1;
U8 Sig_eVoltageStatus;
U8 Sig_bSleepAllow ;
U8 Sig_bPowerOnReq;
U8 Sig_bWakeupReq;
U8 Sig_bSleepReq;
U8 Sig_bNaviConnectedState;
U8 Sig_bNaviPowerOn;
U8 bSocConnected;
U8 Sig_bNAVICommfail;
U8 Sig_IllumeLcdTargetAutomanul;
U8 Sig_IllumeLcdTargetDaynight;
U8 Sig_bEEPCommfail;
U8 Sig_cameraCtrl;
U8 Sig_cameraONOFF;
U8 Sig_bCanInAccStatus ;
U8 Sig_bCanInDiagAccStatus ;
U8 Sig_bCanTransieverError;
U8 Sig_bAPS_turnon;
U8 Sig_bAVM_turnon;
U8 Sig_bLIGHT_turnon;
U8 Sig_bFRONT_VideoStreamSta;
U8 Sig_bREAR_VideoStreamSta;
U8 Sig_bLEFT_VideoStreamSta;
U8 Sig_bRIGHT_VideoStreamSta;
U8 Sig_PreNmSta;
U8 Sig_CurNmSta;
U8 Sig_bCanPublicBusoff;
U8 Sig_bCanPrivateBusoff;

/*---Global-----------------------------------------------------------*/
/***********************************************************************
*  Name        : Sig_CombineGetValue
*  Description :        
*  Parameter   : sig,value
*  Returns     : U8
***********************************************************************/
U8 Sig_CombineGetValue( U16 sig, U16* value)
{
    return (U8)ERR_OK;
}

/***********************************************************************
*  Name        : Sig_CombineSetValue
*  Description :        
*  Parameter   : sig,value
*  Returns     : None
***********************************************************************/
void Sig_CombineSetValue( U16 sig, U8* value)
{
}

/***********************************************************************
*  Name        : Sig_CombineGetDirectValue
*  Description :        
*  Parameter   : sig,value
*  Returns     : U8
***********************************************************************/
U8 Sig_CombineGetDirectValue( U16 sig, U8* value)
{
    ERR_TYPE ret = ERR_OK;

    if((sig>=(U16)SIG_COM_NUM) || (value == NULL))
    {
        ret = ERR_RANGE;
    }
    else
    {
		  switch(sig)
  {
	 case SIG_COMBINE_ACCSTATUS:
            *((U8*)value) = Sig_AccStatus;
        break;
        case SIG_COMBINE_WAKEUPREASION:		/*WAKE UP REASON*/
            *((U8*)value) = Sig_WakeupReason;
        break;
        case SIG_COMBINE_SYSTEMSTATE:			/*SYSTEM STATE*/
            *((U8*)value) = Sig_SystemState;
        break;
        case SIG_COMBINE_VOLTAGESTATUS:		/*SYSTEM VOLTAGE STATUS*/
            *((U8*)value) = Sig_eVoltageStatus;
        break;
        case SIG_COMBINE_SLEEPALLOW:			/*SLEEP ALLOW OR NOT*/
            *((U8*)value) = Sig_bSleepAllow;	
        break;    		
        case SIG_COMBINE_POWERONREQ:  	      /*SYSTEM POWER ON REQUEST*/ 
            *((U8*)value) = Sig_bPowerOnReq;	
        break;
        case  SIG_COMBINE_WAKEUPREQ:	     	      /*SYSTEM WAKE UP REQUEST*/   
            *((U8*)value) = Sig_bWakeupReq;	
        break;
        case SIG_COMBINE_SLEEPREQ:     		      /*SYSTEM SLEEP REQUEST*/    
            *((U8*)value) = Sig_bSleepReq;
        break;	
        case SIG_COMBINE_SOC_POWER_ON:
            *((U8*)value) = Sig_bNaviPowerOn;
        break;
        case SIG_COMBINE_SOC_CONNECTED_STATUS:
            *((U8*)value) = bSocConnected;	
        break;
		case SIG_COMBINE_NAVICOMMU_FAIL:
            *((U8*)value) = Sig_bNAVICommfail;	
	    break;
    	case SIG_COMBINE_EEPROMCOMMUFAIL:
            *((U8*)value) = Sig_bEEPCommfail;	
	    break;
		case SIG_COMBINE_CANIN_ACC:
            *((U8*)value) = Sig_bCanInAccStatus;	
        break;
		case SIG_COMBINE_CANIN_DIAG_ACC:
            *((U8*)value) = Sig_bCanInDiagAccStatus;	
        break;
		case SIG_COMBINE_CAMERA_CONTROL:
            *((U8*)value) = Sig_cameraCtrl;	
        break;
		case SIG_COMBINE_CAMERA_ONOFF:
			*((U8*)value) = Sig_cameraONOFF;
        break;
		case SIG_COMBINE_CAN_TRANSIEVER_ERROR:
            *((U8*)value) = Sig_bCanTransieverError;
        break;
		case SIG_COMBINE_APS_TURNON_FLAG:
			*((U8*)value) = Sig_bAPS_turnon;
		break;
		case SIG_COMBINE_LIGHT_TURNON_FLAG:
			*((U8*)value) = Sig_bLIGHT_turnon;
		break;
		case SIG_COMBINE_FRONT_VIDEO_STREAM:
			*((U8*)value) = Sig_bFRONT_VideoStreamSta;
		break;
		case SIG_COMBINE_REAR_VIDEO_STREAM:
			*((U8*)value) = Sig_bREAR_VideoStreamSta;
		break;
		case SIG_COMBINE_LEFT_VIDEO_STREAM:
			*((U8*)value) = Sig_bLEFT_VideoStreamSta;
		break;
		case SIG_COMBINE_RIGHT_VIDEO_STREAM:
			*((U8*)value) = Sig_bRIGHT_VideoStreamSta;
		break;
		case SIG_COMBINE_CAN_PRE_NM_STATE:
            *((U8*)value) = Sig_PreNmSta;
        break;	
		case SIG_COMBINE_CAN_CUR_NM_STATE:
            *((U8*)value) = Sig_CurNmSta;
        break;	
		case SIG_COMBINE_CAN_BUPLIC_BUSOFF:
			*((U8*)value) = Sig_bCanPublicBusoff;
		break;
		case SIG_COMBINE_CAN_PRIVATE_BUSOFF:
			*((U8*)value) = Sig_bCanPrivateBusoff;
		break;		
   	default:
		break;
  }
	
//		  switch(sig)
//		  {
//			 case SIG_COMBINE_ACCSTATUS:
//		            *((U8*)value) = Sig_AccStatus;
//		        break;
//		        case SIG_COMBINE_WAKEUPREASION:		/*WAKE UP REASON*/
//		            *((U8*)value) = Sig_WakeupReason;
//		        break;
//		        case SIG_COMBINE_SYSTEMSTATE:			/*SYSTEM STATE*/
//		            *((U8*)value) = Sig_SystemState;
//		        break;
//		        case SIG_COMBINE_VOLTAGESTATUS:		/*SYSTEM VOLTAGE STATUS*/
//		            *((U8*)value) = Sig_eVoltageStatus;
//		        break;
//		        case SIG_COMBINE_SLEEPALLOW:			/*SLEEP ALLOW OR NOT*/
//		            *((U8*)value) = Sig_bSleepAllow;	
//		        break;    		
//		        case SIG_COMBINE_POWERONREQ:  	      /*SYSTEM POWER ON REQUEST*/ 
//		            *((U8*)value) = Sig_bPowerOnReq;	
//		        break;
//		        case  SIG_COMBINE_WAKEUPREQ:	     	      /*SYSTEM WAKE UP REQUEST*/   
//		            *((U8*)value) = Sig_bWakeupReq;	
//		        break;
//		        case SIG_COMBINE_SLEEPREQ:     		      /*SYSTEM SLEEP REQUEST*/    
//		            *((U8*)value) = Sig_bSleepReq;
//		        break;	
//		        case SIG_COMBINE_NAVI_POWER_ON:
//		            *((U8*)value) = Sig_bNaviPowerOn;
//		        break;
//		        case SIG_COMBINE_SOC_CONNECTED_STATUS:
//		            *((U8*)value) = bSocConnected;	
//		        break;
//		    	case SIG_COMBINE_EEPROMCOMMUFAIL:
//		            *((U8*)value) = Sig_bEEPCommfail;	
//			    break;		
//				case SIG_COMBINE_REVERSE_DET:
//					*((U8*)value) = Sig_bRVCReverse;
//				break;
//		   	default:
//				break;
//		  }
    }

    return (U8)ret;
}

/***********************************************************************
*  Name        : Sig_CombineSetDirectValue
*  Description :        
*  Parameter   : sig,value
*  Returns     : None
***********************************************************************/
void Sig_CombineSetDirectValue( U16 sig, U8* value)
{
    if((sig>=(U16)SIG_COM_NUM) || (value == NULL))
    {
        /*nothing to do*/
    }
    else
    {
    		switch(sig)
			{
	            case SIG_COMBINE_ACCSTATUS:
	                Sig_AccStatus = (U8)(*value);
	            break;
	            case SIG_COMBINE_WAKEUPREASION:
	                Sig_WakeupReason = (U8)(*value);			
	            break;	
	            case SIG_COMBINE_SYSTEMSTATE:
	                Sig_SystemState = (U8)(*value);			
	            break;	
	            case SIG_COMBINE_VOLTAGESTATUS:
	                Sig_eVoltageStatus = (U8)(*value);						
	            break;	
	            case SIG_COMBINE_SLEEPALLOW:
	                Sig_bSleepAllow = (U8)(*value);			
	            break;	  		
	            case SIG_COMBINE_POWERONREQ:
	                Sig_bPowerOnReq= (U8)(*value);	
	            break;
	            case SIG_COMBINE_WAKEUPREQ:
	                Sig_bWakeupReq= (U8)(*value);	
	            break;		    			    		
	            case SIG_COMBINE_SLEEPREQ:
	                Sig_bSleepReq =  (U8)(*value);
	            break;		 
	            case SIG_COMBINE_SOC_POWER_ON:
	                Sig_bNaviPowerOn = (U8)(*value);	
	            break; 	
	            case SIG_COMBINE_SOC_CONNECTED_STATUS:
	                bSocConnected =  (U8)(*value);
	            break;
				case SIG_COMBINE_NAVICOMMU_FAIL:
	                Sig_bNAVICommfail = *((U8*)value);
	            break;
	            case SIG_COMBINE_EEPROMCOMMUFAIL:
	                Sig_bEEPCommfail = *((U8*)value);
	            break;
				case SIG_COMBINE_CANIN_ACC:
					Sig_bCanInAccStatus = (U8)(*value); 
				break;
				case SIG_COMBINE_CANIN_DIAG_ACC:
					Sig_bCanInDiagAccStatus = (U8)(*value); 
				break;	
				case SIG_COMBINE_CAN_TRANSIEVER_ERROR:
					Sig_bCanTransieverError = (U8)(*value); 
				break;
				case SIG_COMBINE_CAMERA_CONTROL:
					Sig_cameraCtrl = *((U8*)value);
        		break;
				case SIG_COMBINE_CAMERA_ONOFF:
					Sig_cameraONOFF = *((U8*)value);
        		break;
				case SIG_COMBINE_APS_TURNON_FLAG:
					Sig_bAPS_turnon = *((U8*)value);
				break;
				case SIG_COMBINE_LIGHT_TURNON_FLAG:
					Sig_bLIGHT_turnon= *((U8*)value);
				break;
				case SIG_COMBINE_FRONT_VIDEO_STREAM:
					Sig_bFRONT_VideoStreamSta= *((U8*)value);
				break;
				case SIG_COMBINE_REAR_VIDEO_STREAM:
					Sig_bREAR_VideoStreamSta= *((U8*)value);
				break;
				case SIG_COMBINE_LEFT_VIDEO_STREAM:
					Sig_bLEFT_VideoStreamSta= *((U8*)value);
				break;
				case SIG_COMBINE_RIGHT_VIDEO_STREAM:
					Sig_bRIGHT_VideoStreamSta= *((U8*)value);
				break;
				case SIG_COMBINE_CAN_PRE_NM_STATE:
		            Sig_PreNmSta = *((U8*)value);
		        break;	
				case SIG_COMBINE_CAN_CUR_NM_STATE:
		            Sig_CurNmSta = *((U8*)value);
		        break;
				case SIG_COMBINE_CAN_BUPLIC_BUSOFF:
					Sig_bCanPublicBusoff = *((U8*)value);
				break;
				case SIG_COMBINE_CAN_PRIVATE_BUSOFF:
					Sig_bCanPrivateBusoff = *((U8*)value);
				break;		
				default:
					break;
			}
		
//	switch(sig)
//	{
//            case SIG_COMBINE_ACCSTATUS:
//                Sig_AccStatus = (U8)(*value);
//            break;
//            case SIG_COMBINE_WAKEUPREASION:
//                Sig_WakeupReason = (U8)(*value);			
//            break;	
//            case SIG_COMBINE_SYSTEMSTATE:
//                Sig_SystemState = (U8)(*value);			
//            break;	
//            case SIG_COMBINE_VOLTAGESTATUS:
//                Sig_eVoltageStatus = (U8)(*value);						
//            break;	
//            case SIG_COMBINE_SLEEPALLOW:
//                Sig_bSleepAllow = (U8)(*value);			
//            break;	  		
//            case SIG_COMBINE_POWERONREQ:
//                Sig_bPowerOnReq= (U8)(*value);	
//            break;
//            case SIG_COMBINE_WAKEUPREQ:
//                Sig_bWakeupReq= (U8)(*value);	
//            break;		    			    		
//            case SIG_COMBINE_SLEEPREQ:
//                Sig_bSleepReq =  (U8)(*value);
//            break;		 
//            case SIG_COMBINE_NAVI_POWER_ON:
//                Sig_bNaviPowerOn = (U8)(*value);	
//            break; 	
//            case SIG_COMBINE_SOC_CONNECTED_STATUS:
//                bSocConnected =  (U8)(*value);
//            break;		
//            case SIG_COMBINE_EEPROMCOMMUFAIL:
//                Sig_bEEPCommfail = *((U8*)value);
//            break;
//			case SIG_COMBINE_REVERSE_DET:
//				Sig_bRVCReverse = (U8)(*value);
//			break;

//	   		
//		default:
//			break;
//	}

	}

}

/**************** END OF FILE *****************************************/

