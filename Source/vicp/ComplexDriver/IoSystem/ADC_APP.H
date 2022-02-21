/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Shao Guangxian										   *
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
* 0.1    Jun 26,2016    PEI Jingli  Initial version
* ----------------------------------------------------------------------
* 0.2    Aug 01,2016   PEI Jingli   interface change
------------------------------------------------------------------------
* 0.3    Dec 28,2016   PEI Jingli  Modify for CodeReview result
------------------------------------------------------------------------
* 0.4    Jan 06,2017   ShangQiuju  Update Sig get func accoding SIG update.
*------------------------------------------------------------------------
* 0.5    Jan 12,2017  ZhangJie  Add Update for Coverity warning.
*-----------------------------------------------------------------------
* 0.6    Jan 17,2017   ZhangJie   Remove unused include file.
*-----------------------------------------------------------------------
* 0.7  Apr 01,2017   PEI Jingli  Fix headfiles.
*=====================================================================*/
#ifndef _ADC_APP_H_
#define _ADC_APP_H_
#include "ADC_CFG.h"

/**** Definition of constants ****/

/**** Definition of types ****/


//#define   ADC_CHANNEL_COUNT  (((ADC_IN_CHANNEL>>15)&0x1U)+((ADC_IN_CHANNEL>>14)&0x1U)+((ADC_IN_CHANNEL>>13)&0x1U)+((ADC_IN_CHANNEL>>12)&0x1U)+\
//                               ((ADC_IN_CHANNEL>>11)&0x1U)+((ADC_IN_CHANNEL>>10)&0x1U)+((ADC_IN_CHANNEL>>9)&0x1U)+((ADC_IN_CHANNEL>>8)&0x1U)+\
//                               ((ADC_IN_CHANNEL>>7)&0x1U)+((ADC_IN_CHANNEL>>6)&0x1U)+((ADC_IN_CHANNEL>>5)&0x1U)+((ADC_IN_CHANNEL>>4)&0x1U)+\
//                               ((ADC_IN_CHANNEL>>3)&0x1U)+((ADC_IN_CHANNEL>>2)&0x1U)+((ADC_IN_CHANNEL>>1)&0x1U)+(ADC_IN_CHANNEL&0x1U))
#define   ADC0_CHANNEL_COUNT  (((ADC0_IN_CHANNEL>>15)&0x1U)+((ADC0_IN_CHANNEL>>14)&0x1U)+((ADC0_IN_CHANNEL>>13)&0x1U)+((ADC0_IN_CHANNEL>>12)&0x1U)+\
                               ((ADC0_IN_CHANNEL>>11)&0x1U)+((ADC0_IN_CHANNEL>>10)&0x1U)+((ADC0_IN_CHANNEL>>9)&0x1U)+((ADC0_IN_CHANNEL>>8)&0x1U)+\
                               ((ADC0_IN_CHANNEL>>7)&0x1U)+((ADC0_IN_CHANNEL>>6)&0x1U)+((ADC0_IN_CHANNEL>>5)&0x1U)+((ADC0_IN_CHANNEL>>4)&0x1U)+\
                               ((ADC0_IN_CHANNEL>>3)&0x1U)+((ADC0_IN_CHANNEL>>2)&0x1U)+((ADC0_IN_CHANNEL>>1)&0x1U)+(ADC0_IN_CHANNEL&0x1U))
#if (MCU_PIN > PIN100)
#define   ADC1_CHANNEL_COUNT  (((ADC1_IN_CHANNEL>>7)&0x1U)+((ADC1_IN_CHANNEL>>6)&0x1U)+((ADC1_IN_CHANNEL>>5)&0x1U)+((ADC1_IN_CHANNEL>>4)&0x1U)+\
                               ((ADC1_IN_CHANNEL>>3)&0x1U)+((ADC1_IN_CHANNEL>>2)&0x1U)+((ADC1_IN_CHANNEL>>1)&0x1U)+(ADC1_IN_CHANNEL&0x1U))
#endif 


/**** Definition of macros ****/

/**** Declaration of constants ****/

/**** Declaration of variables ****/
//typedef struct
//{
//	BOOL InitState; /*record the init state of this module*/	
//	U16 RawValue[SIG_AD_NUM];	/*store the convert result that get from the ResultRegister*/		
//	U16  ResultCounter[SIG_AD_NUM];
//	U16  ResultValue[SIG_AD_NUM];/*store the convert result after 1 order filter*/	
//	BOOL FreezeReq[SIG_AD_NUM];
//} Sig_ADData;
typedef struct
{
	BOOL InitState; /*record the init state of this module*/	
	U16 RawValue[SIG_AD0_NUM];	/*store the convert result that get from the ResultRegister*/		
	U16  ResultCounter[SIG_AD0_NUM];
	U16  ResultValue[SIG_AD0_NUM];/*store the convert result after 1 order filter*/	
	BOOL FreezeReq[SIG_AD0_NUM];
} Sig_AD0Data;

#if (MCU_PIN > PIN100)
typedef struct
{
	BOOL InitState; /*record the init state of this module*/	
	U16 RawValue[SIG_AD1_NUM];	/*store the convert result that get from the ResultRegister*/		
	U16  ResultCounter[SIG_AD1_NUM];
	U16  ResultValue[SIG_AD1_NUM];/*store the convert result after 1 order filter*/	
	BOOL FreezeReq[SIG_AD1_NUM];
} Sig_AD1Data;
#endif

/**** Declaration of functions ****/
/*******************************************************************************************
* EXPORT INTERFACE DEFINITIONS AND DECLARATIONS
*
* In this section
* - define helpful macros for easy data access and for a comfortable function use, if 
*   necessary.
* - define all global define-constants of your module.
* - declare all system global ROM-constants.
* - define all global type definitions of your module.
* - declare all system global variables of your module.
********************************************************************************************/
//extern void Sig_ADInit(void);
//extern void Sig_ADDeInit(void);
//extern void Sig_ADTick(void);

//extern void Adc_Freeze(void);
//extern void Adc_UnFreeze(void);
//extern void Adc_FreezeSignal(U16 Signal);
//extern void Adc_UnFreezeSignal(U16 Signal);

//extern U16 Sig_ADGetRawValue(U16 Signal);
//extern U8 Sig_ADGetValue(U16 Signal, U8* pvalue);
//extern U8 Sig_ADDirectGetValue(U16 Signal, U8* pvalue);
extern void Sig_ADG0Init(void);
extern void Sig_ADG0DeInit(void);
extern void Sig_ADG0Tick(void);

extern void AdcG0_Freeze(void);
extern void AdcG0_UnFreeze(void);
extern void AdcG0_FreezeSignal(U16 Signal);
extern void AdcG0_UnFreezeSignal(U16 Signal);

extern U16 Sig_ADG0GetRawValue(U16 Signal);
extern U8 Sig_ADG0GetValue(U16 Signal, U8* pvalue);
extern U8 Sig_ADG0DirectGetValue(U16 Signal, U8* pvalue);

#if (MCU_PIN > PIN100)
extern void Sig_ADG1Init(void);
extern void Sig_ADG1DeInit(void);
extern void Sig_ADG1Tick(void);

extern void AdcG1_Freeze(void);
extern void AdcG1_UnFreeze(void);
extern void AdcG1_FreezeSignal(U16 Signal);
extern void AdcG1_UnFreezeSignal(U16 Signal);

extern U16 Sig_ADG1GetRawValue(U16 Signal);
extern U8 Sig_ADG1GetValue(U16 Signal, U8* pvalue);
extern U8 Sig_ADG1DirectGetValue(U16 Signal, U8* pvalue);
#endif


#endif
/****************************** END OF FILE ***************************/

