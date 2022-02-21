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
* 0.1    Feb 10,2013    NI Rujin    Initial version
* ----------------------------------------------------------------------
* 0.2    JUN 6,2015    Shang Qiuju  Add signal configuration
* ----------------------------------------------------------------------
* 0.3    Dec 28,2016  Pei Jingli  Add signal configuration for ds03 test
                            re-define used channel ADCA0_CHANNEL_USED
* ----------------------------------------------------------------------
* 0.4    Jan 06,2017   ShangQiuju  Remove HW switch of ds03 and 64pin-platform,this 
                                 file only used for plaform.
*------------------------------------------------------------------------
* 0.5    Jan 12,2017  ZhangJie  Add u for constant value and remove unused typedef to avoid Coverity warning.
*-----------------------------------------------------------------------
* 0.6    Jan 24,2017    ZhangJie     Remove unused include headfile.
*=====================================================================*/
#ifndef _ADC_CFG_H_
#define _ADC_CFG_H_
#include "Define.h"
//#include "CONFIG.H"
#include "Config.h" 

/**** Definition of constants ****/
/* ADCA0 channels used. Bit_n=1,means channel n enabled. channel numbers is 0~15 */
//#define ADCA0_CHANNEL_USED 0xF611U /* channel:4,9,10,13,14,15 */


#define ADCA0_CHANNEL_USED 0x017FU //0000 0001 0111 1111 /* channel:0,1,2,3,4,5,6,8 */

//#define ADC_REMAP_STANDBY_VAL       (_ADCA0I4 | _ADCA0I9 | _ADCA0I10 |_ADCA0I13 | _ADCA0I14 | _ADCA0I15)
/* ADCA1 channels used. Bit_n=1,means channel n enabled. channel numbers is 0~7 */
#if (MCU_PIN > PIN100)
#define ADCA1_CHANNEL_USED 0x001FU /* channel:1 */ /*0000 0000 0001 1111 changnel:0,1,2,3,4*/
#endif
 


/* Signal definition  and please check the hardware channel with the comment*/
enum
{	
	/*=====Signal Name=========ADC Channel Used==ADC Group dividid=*/
	/* adc group0 */
    SIG_AD0_PWR,
    SIG_AD0_TEMP,
	SIG_AD_CAMERA_B_PWR,
	SIG_AD_CAMERA_F_PWR,
	SIG_AD_CAMERA_R_PWR,
	SIG_AD_CAMERA_L_PWR,
    SIG_AD_RADAR_F_PWR,
    SIG_AD_RADAR_R_PWR,
    SIG_AD0_NUM             
};//E_ADType;

#if (MCU_PIN > PIN100)
enum
{	
	/*=====Signal Name=========ADC Channel Used==ADC Group dividid=*/
	/* adc group1 */
    SIG_AD_BSD_RIGHT
    ,SIG_AD_BSD_LEFT
    ,SIG_AD_APA_LED
    ,SIG_AD_PDC_LED
    ,SIG_AD_BSD_LED
    ,SIG_AD5_SVA
    ,SIG_AD6_SVA
    ,SIG_AD7_SVA
   ,SIG_AD1_NUM            
};
#endif
 

/* Signal definition  and please check the hardware channel with the comment*/

typedef enum
{
    E_AD,
    E_BUFFERAD,
    E_ADDEVICE_NUMBER
}E_ADDeviceType;


/**** Declaration of variables ****/

typedef struct
{
    BOOL Damp;
    U8 Portnumb;
    E_ADDeviceType DeviceType;      
}Sig_ADChannelConfigType;

//extern const Sig_ADChannelConfigType Sig_ADConfig[SIG_AD_NUM];


extern const Sig_ADChannelConfigType Sig_AD0Config[SIG_AD0_NUM];
#if (MCU_PIN > PIN100)
extern const Sig_ADChannelConfigType Sig_AD1Config[SIG_AD1_NUM];
#endif 

#define ADC_IN_PRIO_CHANEL 		15U
#define ADC_PRIOCHANNEL_COUNT   1U

/**** Declaration of constants ****/


/**** Declaration of variables ****/
//#define AD_READ(x,y)  	ADC_GetValue(x,y)
#define ADG0_READ(x,y)  	ADCG0_GetValue(x,y)
#if (MCU_PIN > PIN100)
#define ADG1_READ(x,y)  	ADCG1_GetValue(x,y)
#endif 


/**** Declaration of functions ****/


#endif
/****************************** END OF FILE ***************************/
