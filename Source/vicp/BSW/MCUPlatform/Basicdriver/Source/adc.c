
/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.                *
*                 All Rights Reserved.                                 *
*   Department : CT AD                                                 *
*   AUTHOR     :                                                       *
************************************************************************
* Object        :
* Module        :	ADC
* Instance      :
* Description   :	ADC operation, include channel config, start, stop.
				ADC value are updated in Interrupt.
				Support ADC0I0~ADC0I15. 
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date        Name    Changes and comments
* 0.1	   Jun 26,2016   PEI Jingli  Initial version
------------------------------------------------------------------------
* 0.2	   Aug 1,2016    PEI Jingli   Correct getValue inf 		
------------------------------------------------------------------------
* 0.3	   Aug 31,2016   PEI Jingli   Correct channel=0 error
------------------------------------------------------------------------
* 0.4	   Dec 28,2016   PEI Jingli   Modify for CodeReview result
*------------------------------------------------------------------------
* 0.5          Jan 24,2017  ZhangJie  Update for Coverity warning.
------------------------------------------------------------------------
* 0.6	   Apr 13,2017   PEI Jingli   Fix ICxxx.RF setting errors.
*=====================================================================*/
#include "adc.h"
#include "adc_if.h"
#include "irq_if.h"
#include "Config.h"
#include "irq.h"

volatile static U16 adc0_ch_value_array[ADC_MAX]=
{
  0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU, 
  0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU 
};

#if (MCU_PIN > PIN100)
volatile static U16 adc1_ch_value_array[ADC_7+1]=
{
	0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU,0xFFFFU
};
#endif

static U8 adcg0_vcr_ch=0;		/*number of virtual channels*/

#if (MCU_PIN > PIN100)
	static U8 adcg1_vcr_ch=0; 	   /*number of virtual channels*/
#endif 

static ADC_VIR_CH_MAP adcg0_vcr_ch_map[ADC_MAX];


#if (MCU_PIN > PIN100)
	static ADC_VIR_CH_MAP adcg1_vcr_ch_map[ADC_7+1];	   
#endif

/***********************************************************************
*  Name        : ADC0_Init
*  Description :  Initialize adc channel.
*  Parameter   : usedChannel used channels. Each bit represent an ADC physical channel.
*									   bit_n=1, channel n is in use
*   									scannum  unused
*  Returns     : None
***********************************************************************/
void ADCG0_Init(U16 usedChannel, U16 scannum )
{
    ADC_TYPE i = ADC_0;	
	
    if(!usedChannel)
    {
        /*no invalid channel error*/
    }
    else
    {
        /* clear error flag */
       ADC_REG_ADCA0ECR =ADC_ECR_LIMIT_CLEAR|ADC_ECR_OVERWRITE_CLEAR;
       IRQ_IntClr(INTADCA0ERR);   /*Reset InterreuptRequestFlag*/

        /* associate physical channels and virtual channels */
        adcg0_vcr_ch = 0;
        for (i=ADC_0; i<ADC_MAX; i++)
        {
			if ((1u<<i) & usedChannel)
			{
					/* link phy channel to virtual in sequence */
	 			ADC_REG_ADCA0VCR(adcg0_vcr_ch) = i;
	 			adcg0_vcr_ch_map[adcg0_vcr_ch].virtual_channel = adcg0_vcr_ch;
	 			adcg0_vcr_ch_map[adcg0_vcr_ch].phy_channel = (U16)(1u<<i);
	 			adcg0_vcr_ch++; 		
	 		}
		}
        /* configratin */
	   ADC_REG_ADCA0ADCR = ADC_CR_SUSPEND_ASYN|ADC_CR_12BIT|ADC_CR_RIGHT_ALIGN|ADC_CR_SELFDIAG_OFF;
	   ADC_REG_ADCA0SMPCR = ADC_SMCR_SUSPEND_SYN; /*Set sampling time to 18*1/16MHz(8-32MHz) = 1.125us*/
	   ADC_REG_ADCA0SFTCR = ADC_SFTCR_OVERWRITE_ERRORINT_DIS|ADC_SFTCR_LIMMIT_ERRORINT_EN|ADC_SFTCR_READCLEAR_DIS; /*Upper/Lower limit error */ 	  

	   /*Enable group 1*/
 	   ADC_REG_ADCA0SGCR(ADC_GRPUP_1) = ADC_SGCR_SCANEND_INT_DIS; /*ScanGroup interrupt is output when scan ends;use one group*/
 	   ADC_REG_ADCA0SGVCSP(ADC_GRPUP_1) = 0;			/*scan-start channel is virtual channel 0*/
 	   ADC_REG_ADCA0SGVCEP(ADC_GRPUP_1) = adcg0_vcr_ch - 1u; /*scan-start channel is vcr_ch-1*/

	   /* Enable ADCA0 group1 interrupt */
 	   //IRQ_IntEn(INTADCA0I0); 
    }
}

/***********************************************************************
*  Name        : ADCG0_DeInit
*  Description : Always used for ADCA0 group1 with  max 16 channel.
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG0_DeInit(void)

{
    /* Disable ADCA0 group1 interrupt */
	IRQ_IntDis(INTADCA0I0); 
}

/***********************************************************************
*  Name        : ADCG0_Start
*  Description : Conversion start trigger for ADCA0 group1
			  Should be called in cyclic task if not using _BLOCK_READ_ADC.
*  Parameter   : adc_ch- if not using _BLOCK_READ_ADC, specify physical channel

*  Returns     : None
***********************************************************************/
void ADCG0_Start(void)
{
    ADC_REG_ADCA0SGSTCR(ADC_GRPUP_1) = 1U; /*set start-trigger of group1 to conversion starting*/        
}

/***********************************************************************
*  Name        : ADCG0_Stop
*  Description : no useful, automatically stop
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void ADCG0_Stop(void)
{
     /*Nothing to do*/
}

/***********************************************************************
*  Name        : ADCG0_Conversion
*  Description : start to scan group1
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void  ADCG0_Conversion(void)
{
    ADCG0_Start();
}
/***********************************************************************
*  Name        : ADCG0_GetValue
*  Description : Get AD value of channel adc_ch. Always used for ADCA0 group1
*  Parameter   : channelId -index of physical channe,  ADC_TYPE
*                      *val     -A/D conversion value
*  Returns     : ERR_TYPE
***********************************************************************/
ERR_TYPE ADCG0_GetValue( ADC_TYPE channelId, U16* val )
{
	U8 vcr_ch_index = 0;
	ADC_TYPE ch = ADC_0;
	ERR_TYPE eErr = ERR_FAILED;
	
	if ((channelId>=ADC_MAX) || (NULL==val))
	{
	}
	else
	{
		/* search for virtual channel index based on physical channel */
		for (ch=ADC_0; ch<ADC_MAX; ch++)
		{
		   if(adcg0_vcr_ch_map[ch].phy_channel == (U16)(1u<<channelId))
		   {
			   vcr_ch_index = adcg0_vcr_ch_map[ch].virtual_channel;
			   break;
		   }
		}
  
		if (ch < ADC_MAX)
		{
		   *val = adc0_ch_value_array[vcr_ch_index];	
		   eErr = ERR_OK;
		}

	} 
	
    return eErr;
	 
}
/***********************************************************************
*  Name        : ADCG0_Update_G1_Handler
*  Description : Get AD values of ADCA0 scan group1 after scan handler
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG0_Update_Polling_Handler(void)
{
	U8 ch_index = 0;
 
    for(ch_index=0; ch_index<adcg0_vcr_ch; ch_index++)
    {
 	   adc0_ch_value_array[ch_index] = ADC_REG_ADCA0DIR(ch_index);
	}	
}

/***********************************************************************
*  Name        : ADCG1_Update_G1_Handler
*  Description : Get AD values of ADCA0 scan group1 after scan handler
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG1_Update_Polling_Handler(void)
{
	U8 ch_index = 0;
 
    for(ch_index=0; ch_index<adcg1_vcr_ch; ch_index++)
    {
 	   adc1_ch_value_array[ch_index] = ADC_REG_ADCA1DIR(ch_index);
	}	
}

/***********************************************************************
*  Name        : ADCG0_Update_G1_Handler
*  Description : Get AD values of ADCA0 scan group1 after scan handler
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG0_Update_G1_Handler(void)
{
	U8 ch_index = 0;
 
    for(ch_index=0; ch_index<adcg0_vcr_ch; ch_index++)
    {
 	   adc0_ch_value_array[ch_index] = ADC_REG_ADCA0DIR(ch_index);
	}	
}

/***********************************************************************
*  Name        : ISR_ADCA0_INTSG1func
*  Description : ADCA0 scan group1 ISR
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ISR_ADCA0_INTSG1func(void)

{
   ADCG0_Update_G1_Handler();
}

#if (MCU_PIN > PIN100)
/***********************************************************************
*  Name        : ADCG1_Init
*  Description : Initialize adc channel.
*  Parameter   : usedChannel used channels. Each bit represent an ADC physical channel.
                                     bit_n=1, channel n is in use
*                      scannum  unused
*  Returns     : None
***********************************************************************/
void ADCG1_Init(U16 usedChannel, U16 scannum )
{
    ADC_TYPE i = ADC_0;	
	
    if (!usedChannel)
    {
        /*no invalid channel error*/
    }
    else
    {
		
		/* clear error flag */
		ADC_REG_ADCA1ECR = ADC_ECR_LIMIT_CLEAR|ADC_ECR_OVERWRITE_CLEAR;
		IRQ_IntClr(INTADCA1ERR);   /*Reset InterreuptRequestFlag*/

		/* associate physical channels and virtual channels */
		adcg1_vcr_ch = 0;
		for (i=ADC_0; i<ADC_8; i++)
		{
			if ((1u<<i) & usedChannel)
			{
				/* link phy channel to virtual in sequence */
				ADC_REG_ADCA1VCR(adcg1_vcr_ch) = i;
				adcg1_vcr_ch_map[adcg1_vcr_ch].virtual_channel = adcg1_vcr_ch;
				adcg1_vcr_ch_map[adcg1_vcr_ch].phy_channel = (U16)(1u<<i);
				adcg1_vcr_ch++;			
			}
		}

		/* configratin */
		ADC_REG_ADCA1ADCR = ADC_CR_SUSPEND_ASYN|ADC_CR_12BIT|ADC_CR_RIGHT_ALIGN|ADC_CR_SELFDIAG_OFF;
		ADC_REG_ADCA1SMPCR = ADC_SMCR_SUSPEND_SYN; /*Set sampling time to 18*1/16MHz(8-32MHz) = 1.125us*/
		ADC_REG_ADCA1SFTCR = ADC_SFTCR_OVERWRITE_ERRORINT_DIS|ADC_SFTCR_LIMMIT_ERRORINT_EN|ADC_SFTCR_READCLEAR_DIS; /*Upper/Lower limit error */	   
		/*Enable group 1*/
		ADC_REG_ADCA1SGCR(ADC_GRPUP_1) = ADC_SGCR_SCANEND_INT_DIS; /*ScanGroup interrupt is output when scan ends;use one group*/
		ADC_REG_ADCA1SGVCSP(ADC_GRPUP_1) = 0;			 /*scan-start channel is virtual channel 0*/
		ADC_REG_ADCA1SGVCEP(ADC_GRPUP_1) = adcg1_vcr_ch - 1u; /*scan-start channel is vcr_ch-1*/

		/* Enable ADCA1 group1 interrupt */
		//IRQ_IntEn(INTADCA1I0);     
    }
}

/***********************************************************************
*  Name        : ADCG1_DeInit
*  Description : 
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG1_DeInit(void)
{
	/* Disable ADCA1 group1 interrupt */
	IRQ_IntDis(INTADCA1I0);
}
/***********************************************************************
*  Name        : ADCG1_Start
*  Description : Conversion start trigger for ADCA1 group1
			  Should be called in cyclic task if not using _BLOCK_READ_ADC.
*  Parameter   : adc_ch- if not using _BLOCK_READ_ADC, specify physical channel
*  Returns     : None
***********************************************************************/
void ADCG1_Start(void)
{
	ADC_REG_ADCA1SGVCEP(ADC_GRPUP_1) = adcg1_vcr_ch - 1u; /*scan-start channel is vcr_ch-1*/
	ADC_REG_ADCA1SGSTCR(ADC_GRPUP_1) = 1U; /*set start-trigger of group1 to conversion starting*/
}

/***********************************************************************
*  Name        : ADCG1_Stop
*  Description : no useful, automatically stop
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG1_Stop(void)
{
     /*Nothing to do*/
}

/***********************************************************************
*  Name        : ADCG1_Conversion
*  Description : start to scan group1
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void  ADCG1_Conversion(void)
{
    ADCG1_Start();
}

/***********************************************************************
*  Name        : ADCG1_GetValue
*  Description : Get AD value of channel adc_ch. Used for  ADCA1 group1
*  Parameter   : channelId -index of physical channe,  ADC_TYPE
*                      *val     -A/D conversion value
*  Returns     : ERR_TYPE
***********************************************************************/
ERR_TYPE ADCG1_GetValue(ADC_TYPE channelId, U16* val)
{
    U8 vcr_ch_index = 0;
    ADC_TYPE ch = ADC_0;
    ERR_TYPE eErr = ERR_FAILED;
    
    if((channelId>=ADC_MAX) || (NULL==val))
    {
    }
    else
    {
		/* search for virtual channel index based on physical channel */
		for (ch=ADC_0; ch<ADC_8; ch++)
		{
		   if(adcg1_vcr_ch_map[ch].phy_channel == (U16)(1u<<channelId))
		   {
			   vcr_ch_index=adcg1_vcr_ch_map[ch].virtual_channel;
			   break;
		   }
		}

		if (ch < ADC_MAX)
		{
		   *val = adc1_ch_value_array[vcr_ch_index];    
		   eErr = ERR_OK;
		}     
    }
	
    return eErr;
}

/***********************************************************************
*  Name        : ADC_Update_G1_Handler
*  Description : Get AD values of ADCA1 scan group1 after scan handler
*  Parameter   : None

*  Returns     : None
***********************************************************************/
void ADCG1_Update_G1_Handler(void)
{
    U8 ch_index = 0;
 
    for(ch_index=0; ch_index<adcg1_vcr_ch; ch_index++)
    {
        adc1_ch_value_array[ch_index] = ADC_REG_ADCA1DIR(ch_index);
    }
}
/***********************************************************************
*  Name        : ISR_ADCA1_INTSG1func
*  Description : ADCA1 scan group1 ISR
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void ISR_ADCA1_INTSG1func(void)
{
    ADCG1_Update_G1_Handler();
}
#endif




