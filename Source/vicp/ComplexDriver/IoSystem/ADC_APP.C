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
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1    Feb 10,2013    NI Rujin    Initial version
* ----------------------------------------------------------------------
* 0.2    Apr 20,2013    LIU Chenxi  Fix issues found when implementing 
             power management module
------------------------------------------------------------------------
* 0.3    July 07,2016  PEI Jingli  Adapt 64pin MCU
------------------------------------------------------------------------
* 0.4    Aug 1,2016    PEI Jingli   Rename interface and Correct errors about ADC conversion 		
*----------------------------------------------------------------------
* 0.5    Dec 20,2016   ShangQiuju Remove unused include files.
*----------------------------------------------------------------------
* 0.6    Dec 23,2016  PEI Jingli  Change adc channel micro
------------------------------------------------------------------------
* 0.7    Dec 28,2016  PEI Jingli  Modify for CodeReview result,add descripton
------------------------------------------------------------------------
* 0.8    Jan 06,2017   ShangQiuju  Update Sig get func accoding SIG update.
*------------------------------------------------------------------------
* 0.9    Jan 12,2017  ZhangJie  Add Update for Coverity warnings.
*----------------------------------------------------------------------
* 1.0    Jan 16,2017   RenWeimin  Add test code.
*------------------------------------------------------------------------
* 1.1   Jan 24,2017  ZhangJie  Fix Coverity warnings phase2.
*-----------------------------------------------------------------------
* 1.2    Feb 09,2017   ZhangJie   Remove EOL definition.
*-----------------------------------------------------------------------
* 1.3   Apr 01,2017   PEI Jingli  Fix headfiles.
*----------------------------------------------------------------------
* 1.4   Apr 07,2017  PEI Jingli  Fix warnings.
*=====================================================================*/
#include "Startup.h"
#include "ADC_APP.h"
#include "ADC_if.h"
#include "ADC.h"
#include "Config.h"
  
#define   ADC0_IN_CHANNEL    (ADCA0_CHANNEL_USED)
#if (MCU_PIN > PIN100)
#define   ADC1_IN_CHANNEL    (ADCA1_CHANNEL_USED)
#endif 
//#define   ADC_IN_CHANNEL    (ADCA0_CHANNEL_USED)
static Sig_AD0Data  Sig_AD0Global =
{
    FALSE,	
    { 0u },
    { 0u }, 
    { 0u },
    { 0u }
}; 
	
#if (MCU_PIN > PIN100)
static Sig_AD1Data  Sig_AD1Global =
  {
		FALSE,	
		{ 0u },
		{ 0u }, 
		{ 0u },
		{ 0u }
  };
#endif 



//ERR_TYPE read_adsignal(U8 number, E_ADDeviceType devicetype, U16* pvalue);
ERR_TYPE read_adG0signal(U8 number, E_ADDeviceType devicetype, U16* pvalue);
#if (MCU_PIN > PIN100)
ERR_TYPE read_adG1signal(U8 number, E_ADDeviceType devicetype, U16* pvalue);
#endif
 

/***********************************************************************
*  Name        : Sig_ADInit
*  Description : Initializes the Sig_AD module, and calls AD driver initial.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG0Init(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
    U16 Loops = 0U;
	
	/* clear the raw and filter value buffer */
	for (Loops=0U; Loops<(U16)SIG_AD0_NUM; Loops++)
	{
		Sig_AD0Global.RawValue[Loops] = 0U;
		Sig_AD0Global.ResultCounter[Loops] = 0U;
		Sig_AD0Global.ResultValue[Loops] = 0U;
	}
	Sig_AD0Global.InitState = TRUE; /* set sig_adc module as initialized. */
	ADCG0_Init(ADC0_IN_CHANNEL, ADC0_CHANNEL_COUNT - 1u);
}
/***********************************************************************
*  Name        : Sig_ADG0DeInit
*  Description : de-Initializes the Sig_AD module.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG0DeInit(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
	U16 Loops = 0U;

	/* clear the raw and filter value buffer */
	for (Loops = 0U; Loops<(U16)SIG_AD0_NUM; Loops++)
	{
	   Sig_AD0Global.RawValue[Loops] = 0U;
	   Sig_AD0Global.ResultCounter[Loops] = 0U;
	   Sig_AD0Global.ResultValue[Loops] = 0U;
	}

	Sig_AD0Global.InitState = FALSE; /* set sig_adc module as initialized. */

	ADCG0_DeInit(); 
}
/***********************************************************************
*  Name        : Sig_ADG0Tick
*  Description : Restart A/D conversion by tick time.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG0Tick(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
   
    U16 Index;
	
	U8 ch_index = 0;
    ERR_TYPE ret;
    U16 RawValue =0xFFFFu;
    Sig_ADChannelConfigType ChannelConfig;

    /******************************************************************
    * FUNCTION CODE
    *******************************************************************/
    if (Sig_AD0Global.InitState == FALSE)
    {
		return;
	}
 	ADCG0_Conversion();
	delay_us(4u);  /*conversion time need mor than 3.75us.*/
	ADCG0_Update_Polling_Handler();


	for(Index=0u; Index<(U16)SIG_AD0_NUM; Index++)
	{
		if (Sig_AD0Global.FreezeReq[Index])
		{
			continue;
		}
		ChannelConfig = Sig_AD0Config[Index];
		ret = read_adG0signal(ChannelConfig.Portnumb, ChannelConfig.DeviceType, &RawValue);
		if (ERR_OK == ret)
		{
			if (ChannelConfig.Damp ==TRUE)
			{
				 /*Sig_AD0Global.RawValue[Signal] =RawValue;*/
			}
			else
			{ 
				 Sig_AD0Global.ResultValue[Index] = RawValue;
			}			 
		}
		else
		{
			/*nothing todo*/
		}
	}
	
	

}
/***********************************************************************
*  Name        : Sig_ADG0GetRawValue
*  Description : Get AD value after debounce handler.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
U16 Sig_ADG0GetRawValue(U16 Signal)
{	
	return Sig_AD0Global.RawValue[Signal]; 
}
/***********************************************************************
*  Name        : Sig_ADG0DirectGetValue
*  Description : Get current value   
*  Parameter   : Signal,pvalue
*  Returns     : ERR_TYPE
***********************************************************************/
U8 Sig_ADG0DirectGetValue(U16 Signal, U8* pvalue)
{
    U8 retVal = (U8)ERR_OK;
	
    if (pvalue == NULL)
    {
        retVal = (U8)ERR_VALUE;
    }
    else
    {
        U16 adVal = 0u;
        Sig_ADChannelConfigType ChannelConfig;
		ADCG0_Conversion();
		ChannelConfig = Sig_AD0Config[Signal];
		delay_us(4u);  /*conversion time need mor than 3.75us.*/
		ADCG0_GetValue((ADC_TYPE)(ChannelConfig.Portnumb), &adVal);
        pvalue[0] = (U8)(adVal>>8);
        pvalue[1] = (U8)(adVal&0xFFu);
    }
	
    return retVal;
}
/***********************************************************************
*  Name        : Sig_ADG0DirectGetValue
*  Description : Get A/D value   
*  Parameter   : Signal,pvalue
*  Returns     : ERR_TYPE
***********************************************************************/
U8 Sig_ADG0GetValue(U16 Signal, U8* pvalue)
{
    U8 retVal = (U8)ERR_OK;
	
    if (pvalue == NULL)
    {
        retVal = (U8)ERR_VALUE;
    }
    else
    {
        U16 adVal = 0;
		adVal = Sig_AD0Global.ResultValue[Signal];
        pvalue[0] = (U8)(adVal & 0xFFu);
		pvalue[1] = (U8)(adVal >> 8);
    }
	
    return retVal;
}
/***********************************************************************
*  Name        : AdcG0_Freeze
*  Description : Freeze all signals   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void AdcG0_Freeze(void)
{
	Sig_AD0Global.InitState = TRUE; 
}

/***********************************************************************
*  Name        : AdcG0_UnFreeze
*  Description : Un-freeze all signals    
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void AdcG0_UnFreeze(void)
{
	Sig_AD0Global.InitState = FALSE; 
}

/***********************************************************************
*  Name        : AdcG0_FreezeSignal
*  Description :  Freeze a signal  
*  Parameter   : Signal
*  Returns     : None
***********************************************************************/
void AdcG0_FreezeSignal(U16 Signal)
{
	Sig_AD0Global.FreezeReq[Signal]= TRUE; 
}
/***********************************************************************
*  Name        : AdcG0_UnFreezeSignal
*  Description :  Un-freeze a signal  
*  Parameter   : Signal
*  Returns     : None
***********************************************************************/
void AdcG0_UnFreezeSignal(U16 Signal)
{
	Sig_AD0Global.FreezeReq[Signal] = FALSE;   
}

/***********************************************************************
*  Name        : read_adG0signal
*  Description :    
*  Parameter   : number,devicetype,pvalue
*  Returns     : U8
***********************************************************************/
ERR_TYPE read_adG0signal(U8 number, E_ADDeviceType devicetype, U16* pvalue)
{
    ERR_TYPE value = ERR_OK;

	if (devicetype == E_AD)
	{
		value = ADG0_READ((ADC_TYPE)number, pvalue);
	}
	
    return value;
}
#if (MCU_PIN > PIN100)
/***********************************************************************
*  Name        : Sig_ADG1Init
*  Description : Initializes the Sig_AD module, and calls AD driver initial.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG1Init(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
    U16 Loops = 0U;
	
	/* clear the raw and filter value buffer */
	for (Loops=0U; Loops<(U16)SIG_AD1_NUM; Loops++)
	{
		Sig_AD1Global.RawValue[Loops] = 0U;
		Sig_AD1Global.ResultCounter[Loops] = 0U;
		Sig_AD1Global.ResultValue[Loops] = 0U;
	}
	Sig_AD1Global.InitState = TRUE; /* set sig_adc module as initialized. */
	ADCG1_Init(ADC1_IN_CHANNEL, ADC1_CHANNEL_COUNT - 1u);

}
/***********************************************************************
*  Name        : Sig_ADG1DeInit
*  Description : de-Initializes the Sig_AD module.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG1DeInit(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
    U16 Loops = 0U;

	/* clear the raw and filter value buffer */
	for( Loops = 0U; Loops < (U16)SIG_AD1_NUM; Loops++)
	{
		Sig_AD1Global.RawValue[Loops] = 0U;
		Sig_AD1Global.ResultCounter[Loops] = 0U;
		Sig_AD1Global.ResultValue[Loops] = 0U;
	}

	Sig_AD1Global.InitState = FALSE; /* set sig_adc module as initialized. */

	ADCG1_DeInit(); 

}

/***********************************************************************
*  Name        : Sig_ADG1Tick
*  Description : Restart A/D conversion by tick time.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Sig_ADG1Tick(void)
{
    /******************************************************************
    * FUNCTION LOCAL DEFINITIONS
    *
    * In this section define
    * - all function local type definitions
    * - all function local ROM-constants
    * - all function local variables (auto and static)
    *******************************************************************/
    U16 Index;
    ERR_TYPE ret;
    U16 RawValue =0xFFFFu;
    Sig_ADChannelConfigType ChannelConfig;

    /******************************************************************
    * FUNCTION CODE
    *******************************************************************/
	if (Sig_AD1Global.InitState == FALSE)
	{
		return;
	}
	ADCG1_Conversion();
	delay_us(4u);  /*conversion time need mor than 3.75us.*/
	ADCG1_Update_Polling_Handler();
	for(Index=0u; Index<(U16)SIG_AD1_NUM; Index++)
	{
		if (Sig_AD1Global.FreezeReq[Index])
		{
			continue;
		}
		ChannelConfig = Sig_AD1Config[Index];
		ret = read_adG1signal(ChannelConfig.Portnumb, ChannelConfig.DeviceType, &RawValue);
		if (ERR_OK == ret)
		{
			if (ChannelConfig.Damp ==TRUE)
			{
				 /*Sig_AD1Global.RawValue[Signal] =RawValue;*/
			}
			else
			{ 
				 Sig_AD1Global.ResultValue[Index] = RawValue;
			}			 
		}
		else
		{
			/*nothing todo*/
		}
	}

}


/***********************************************************************
*  Name        : Sig_ADG1GetRawValue
*  Description : Get AD value after debounce handler.   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
U16 Sig_ADG1GetRawValue(U16 Signal)
{	
	return Sig_AD1Global.RawValue[Signal];
}



/***********************************************************************
*  Name        : Sig_ADG1DirectGetValue
*  Description : Get current value   
*  Parameter   : Signal,pvalue
*  Returns     : ERR_TYPE
***********************************************************************/
U8 Sig_ADG1DirectGetValue(U16 Signal, U8* pvalue)
{
    U8 retVal = (U8)ERR_OK;
	
    if (pvalue == NULL)
    {
        retVal = (U8)ERR_VALUE;
    }
    else
    {
        U16 adVal = 0u;
        Sig_ADChannelConfigType ChannelConfig;
		ADCG1_Conversion();
		ChannelConfig = Sig_AD1Config[Signal];
		delay_us(4u);  /*conversion time need mor than 3.75us.*/
		ADCG1_GetValue((ADC_TYPE)(ChannelConfig.Portnumb), &adVal);
        pvalue[0] = (U8)(adVal>>8);
        pvalue[1] = (U8)(adVal&0xFFu);
    }
	
    return retVal;
}
/***********************************************************************
*  Name        : Sig_ADG1DirectGetValue
*  Description : Get A/D value   
*  Parameter   : Signal,pvalue
*  Returns     : ERR_TYPE
***********************************************************************/
U8 Sig_ADG1GetValue(U16 Signal, U8* pvalue)
{
    U8 retVal = (U8)ERR_OK;
	
    if (pvalue == NULL)
    {
        retVal = (U8)ERR_VALUE;
    }
    else
    {
        U16 adVal = 0;
		adVal = Sig_AD1Global.ResultValue[Signal];
        pvalue[0] = (U8)(adVal & 0xFFu);
		pvalue[1] = (U8)(adVal >> 8);
    }
	
    return retVal;
}



/***********************************************************************
*  Name        : AdcG1_Freeze
*  Description : Freeze all signals   
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void AdcG1_Freeze(void)
{
	Sig_AD1Global.InitState = TRUE;
}


/***********************************************************************
*  Name        : AdcG1_UnFreeze
*  Description : Un-freeze all signals    
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void AdcG1_UnFreeze(void)
{
	Sig_AD1Global.InitState = FALSE; 
}


/***********************************************************************
*  Name        : AdcG1_FreezeSignal
*  Description :  Freeze a signal  
*  Parameter   : Signal
*  Returns     : None
***********************************************************************/
void AdcG1_FreezeSignal(U16 Signal)
{
	Sig_AD1Global.FreezeReq[Signal]= TRUE; 
}



/***********************************************************************
*  Name        : AdcG1_UnFreezeSignal
*  Description :  Un-freeze a signal  
*  Parameter   : Signal
*  Returns     : None
***********************************************************************/
void AdcG1_UnFreezeSignal(U16 Signal)
{
	Sig_AD1Global.FreezeReq[Signal] = FALSE;    
}


/***********************************************************************
*  Name        : read_adG1signal
*  Description :    
*  Parameter   : number,devicetype,pvalue
*  Returns     : U8
***********************************************************************/
ERR_TYPE read_adG1signal(U8 number, E_ADDeviceType devicetype, U16* pvalue)
{
    ERR_TYPE value = ERR_OK;

	if (devicetype == E_AD)
	{	
		value = ADG1_READ((ADC_TYPE)number, pvalue);
	}
	
    return value;
}

#endif
/**************** END OF FILE *****************************************/

