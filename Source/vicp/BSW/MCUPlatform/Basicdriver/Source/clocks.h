/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.		           *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									                   *
************************************************************************
* Object        :  clock.h 
* Module        : 
* Instance      : 
* Description   : 5 clock OSC, clock domain
*-----------------------------------------------------------------------
* Version: 
* Date: 
* Author: 
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1  Apr 15,2016  PEI Jingli  Initial 5 clock OSC, and clock domain.
* ----------------------------------------------------------------------
* 0.2 Nov 25,2016  PEI Jingli  Code architecture for code review
*------------------------------------------------------------------------
* 0.3 Jan 11,2017  ZhangJie  Add u for constant value to avoid Coverity warning.
*-----------------------------------------------------------------------
* 0.4 Jan 24,2017   ZhangJie   Remove unused include file.
===============================================================*/
#ifndef  _CLOCK_H
#define   _CLOCK_H

/*----types defination ----*/
/* clock start or stop */
#define CLOCK_START_TRIGGER    (0x01UL)    /* starts the clock */
#define CLOCK_STOP_TRIGGER     (0x02UL)    /* stop the clock   */

/* Is clock active */
#define CLOCK_STATUS_INACTIVE    (0x00UL)    /* inactive status */
#define CLOCK_STATUS_ACTIVE        (0x04UL)    /* active status   */

/*   MainOsc control register (MOSCC)*/
/*MainOsc Frequency selection for external resonator*/
typedef enum
{
	E_HIGH_24MUP=0,
	E_MIDH_20MUP,		
	E_MIDL_16MUP,		
	E_LOW_8MUP		    
}MOSCC_AMPSEL_MODE;

/* MainOsc stop mask (MOSCESTPM) */
#define CLOCK_STPMASK_EN    (0x01UL)  /*not stop in stand-by mode*/

/*
    PLLk control register (PLLC)
*/
/* Input frequency PLLC[12:11]=M[1:0],  Mr val=M[1:0]+1 */
#define CGC_PLLC_Mr(n)      (((n)-1)<<11)

#ifdef IC_RH850_F1K
/* divisoin ratio Nr  PLLC[5:0]=N[2:0],  Nr va=N[5:0]+1 l */
#define CGC_PLLC_Nr(n)       ((n)-1)

/* pll input clock */
#define CKSC_PLLIS_CTL_MOSC      (0x00000001UL)  /* used Main OSC . Default*/
#define CKSC_PLLIS_CTL_HSI         (0x00000002UL)  /* used High speed internal OSC */

/* PPLLCLK source clock selection */
#define CKSC_PPLLCLKS_CTL_EMCLK     (0x00000001UL)  /* used emergency clock. Default */
#define CKSC_PPLLCLKS_CTL_MOSC       (0x00000002UL)  /* used Main OSC  */
#define CKSC_PPLLCLKS_CTL_PPLLOUT  (0x00000003UL)  /* used Peri-PLL out */

#else //IC_RH850_F1K

/*  CPU PLLCLK selection.Other than ADVANCE,PREMIUM,and Gateway  be sure to wirte 0
     otherwise, write 0/1 */
#define CGC_PLLC_OUTBSEL_0        (0x00000000UL)  /* same clock as PPLL */
#define CGC_PLLC_OUTBSEL_1        (0x00010000UL)  /* dividing fVCOOUT  by 5 */
/* P divider selection  PLLC[10:8]=PA[2:0],  Par val */
#define CGC_PLLC_Par4       (0x00000200UL)  /* PLL output fre range 60~80 MHz */
#define CGC_PLLC_Par6       (0x00000300UL)  /* 40~80 MHz */
#define CGC_PLLC_Par8       (0x00000400UL)  /* 30~60 MHz */
#define CGC_PLLC_Par16     (0x00000500UL)  /* 25~30MHz */
/* divisoin ratio Nr  PLLC[5:0]=N[2:0],  Nr va=N[5:0]+1 l */
#define CGC_PLLC_Nr(n)       ((n)-1U)

#endif //IC_RH850_F1K

/*----- definetion of clock domains ----*/
/*  Clock Divider Setting for AWDTA0 */
typedef enum
{
	E_AWDTD_LSI128D=1, /*used Low Speed Internal clock of 240KHZ  frequency= 240KHZ/128*/
	E_AWDTD_LSI1D          /*frequency= 240KHZ/1*/
} WDTA0_DIV_TYPE;

/* Source Clock Setting for ATAUJ.Before shifting to DEEPSTOP mode, select one other than PPLLCLK2 */
typedef enum
{
	E_ATAUJS_DIS=0,            /*clock disabled*/
	E_ATAUJS_HSI8MHZ=1,  /*default value, used High Speed Internal clock of 8MHZ  frequency= 8MHZ*/
	E_ATAUJS_MOSCFX,       /*used main-osc,also external  oscillator*/
	E_ATAUJS_LSI240KHZ,  /*used Low Speed Internal clock of 240KHZ*/
	E_ATAUJS_PPLLCLK2     /*used Peri-PLL 2 dividing,also cpu clock 2 dividing*/
} TAUJS_SRCCLK_TYPE;
/*  Clock Divider Setting for TAUJS  */
typedef enum
{
	E_ATAUJ_DIS=0,   /*clock disabled*/
 	E_ATAUJ_DIV1=1, /*default value. 1 dividing*/
	E_ATAUJ_DIV2=2, /* 2 dividing*/
	E_ATAUJ_DIV4=3, /* 4 dividing*/
	E_ATAUJ_DIV8=4  /* 8 dividing*/
} TAUJS_DIV_TYPE;

/* Source Clock Setting for ARTCA */
typedef enum
{
	E_ARTCAS_DIS=0, /*clock disabled*/
	E_ARTCAS_SOSC, /*used sub-osc*/
	E_ARTCAS_MOSC,/*used main-osc */
	E_ARTCAS_LSI     /*used Low Speed Internal clock */
} ARTCA_SRCCLK_TYPE;
/*  Clock Divider Setting for ARTCA  */
typedef enum
{
	E_ARTCA_DIVDIS=0,/*clock disabled*/
	E_ARTCA_DIV1=1,    /*default value. 1 dividing*/
	E_ARTCA_DIV2=2,
    E_ARTCA_DIV4=3,
    E_ARTCA_DIV8=4    /* 8 dividing*/
} ARTCA_DIV_TYPE;

/* Source Clock Setting for AADCA/IADCA.Before shifting to DEEPSTOP mode, select one other than PPLLCLK2 */
typedef enum
{
    E_AADCAS_DIS=0, /*clock disabled*/
    E_AADCAS_HSI,     /*used High Speed Internal clock*/
    E_AADCAS_MOSC, /*used main-osc*/
    E_AADCAS_PPLLCLK2 /*used Peri-PLL 2 dividing*/
} AADCA_SRCCLK_TYPE;
/*  Clock Divider Setting for AADCA/IADCA  */
typedef enum
{
    E_AADCA_DIVDIS=0,/*clock disabled*/
    E_AADCA_DIV1=1, 
    E_AADCA_DIV2=2 /*frequency of CKSC_AADCA is no less than 8MHz after division by 2.*/
} AADCA_DIV_TYPE;

/* Source Clock Setting for AFOUT.Before shifting to DEEPSTOP mode, select one other than CPLLCLK2 and PPLLCLK4*/
typedef enum
{
    E_AFOUTS_DIS=0,     /*clock disabled*/
    E_AFOUTS_MOSCFX, /*used main-osc*/
    E_AFOUTS_HSI8MHZ,/*used High Speed Internal clock of 8MHZ*/
    E_AFOUTS_LSI,          /*used Low Speed Internal clock of 240KHZ*/
    E_AFOUTS_SOSC,      /*used sub-osc*/
#ifdef IC_RH850_F1K
    E_AFOUTS_PPLLCLK4, //used Peri-PLL 4 dividing,also CPU clock 4 dividing
    E_AFOUTS_PPLLCLK4_SAME  //used Peri-PLL 4 dividing,also CPU clock 4 dividing
#else
    E_AFOUTS_CPLLCLK2, /*used CPU-PLL 2 dividing,also CPU clock 2 dividing*/
    E_AFOUTS_PPLLCLK4  /*used Peri-PLL 4 dividing,also CPU clock 4 dividing*/
#endif	
} AFOUTS_SRCCLK_TYPE;

/* Source Clock Setting for CPUCLK */
typedef enum
{
    E_ICPUCLK_EMG=1, /*HSI or LSI, def*/
    E_ICPUCLK_MOSC,  /*used main-osc*/
    E_ICPUCLK_CPLLCLK /*used CPU-PLL clock*/
} ICPUCLK_SRCCLK_TYPE;
/*  Clock Divider Setting for CPUCLK */
typedef enum
{
    E_ICPUCLK_DIV1=1, /* 1 dividing*/
    E_ICPUCLK_DIV2=2, /* 2 dividing*/
    E_ICPUCLK_DIV4=3, /* 4 dividing*/
    E_ICPUCLK_DIV8=4  /* 8 dividing*/
} ICPUCLK_DIV_TYPE;
/* CPLL Setting*/ 
typedef enum
{
    E_CPLLDIV_DIV6_80MHZ=0x00, /* ECO &advance& premium 80MHZ*/
    E_ICPUCLK_DIV5_96MHZ=0x08, /* advance& premium 96MHZ*/
    E_ICPUCLK_DIV4_120MHZ=0x10, /* advance& premium 120MHZ*/
} CPLLCLK_DIV_TYPE;

#ifdef IC_RH850_F1K

/* Source Clock Setting for IPERI1 and IPERI2*/
typedef enum
{
    E_IPERI1S_DISABLE=0, //clock disabled
    E_IPERI1S_PPLLCLK_DEF, //default value.used Peri-PLL clock 1dividing
    E_IPERI1S_PPLLCLK          //used Peri-PLL clock 1dividing
} IPERI1_SRCCLK_TYPE;
typedef enum
{
    E_IPERI2S_DISABLE=0, //clock disabled
    E_IPERI2S_PPLLCLK2_DEF, //default value.used Peri-PLL clock 2dividing
    E_IPERI2S_PPLLCLK2          //used Peri-PLL clock 1dividing
} IPERI2_SRCCLK_TYPE;

/* Source Clock Setting for ILIN */
typedef enum
{
    E_ILIN_DIS,   //clock disabled
    E_ILIN_PPLLCLK2_DEF, //default value.used CPU clock 2 dividing
    E_ILIN_MOSC,      //used main-osc 
    E_ILIN_PPLLCLK2, //used Peri-PLL 2 dividing
    E_ILIN_HSI //used HSI 8MHZ
} ILIN_SRCCLK_TYPE;

#else //IC_RH850_F1K

/* Source Clock Setting for IPERI1 and IPERI2*/
typedef enum
{
    E_IPERIS_DISABLE=0, /*clock disabled*/
    E_IPERIS_CPUCLK2,    /*default value.used CPU-PLL 2 dividing,also CPU clock 2 dividing*/
    E_IPERIS_PPLLCLK      /*For PERI1 is Peri-PLL clock 1dividing.For PERI2 is Peri-PLL clock 2dividing*/
} IPERI_SRCCLK_TYPE;

/* Source Clock Setting for ILIN */
typedef enum
{
    E_ILIN_DIS,   /*clock disabled*/
    E_ILIN_CPUCLK2, /*default value.used CPU clock 2 dividing*/
    E_ILIN_MOSC,      /*used main-osc */
    E_ILIN_PPLLCLK2 /*used Peri-PLL 2 dividing*/
} ILIN_SRCCLK_TYPE;
#endif //IC_RH850_F1K

/*  Clock Divider Setting for CPUCLK */
typedef enum
{
    E_ILIN_DIV1=1, /*default value.1 dividing*/
    E_ILIN_DIV4=2, /* 4 dividing*/
    E_ILIN_DIV8=3  /*8 dividing*/
} ILIN_DIV_TYPE;

/* Source Clock Setting for RS CAN */
typedef enum
{
    E_ICANS_DIS,   /*clock disabled*/
    E_ICANS_MOSC,     /*used main-osc */
    E_ICANS_PPLLCLK,/*used Peri-PLL*/
#ifdef IC_RH850_F1K
    E_ICANS_CPUCLK  /*default value.used CPU clock*/
#else
    E_ICANS_PPLLCLK_DEF 
#endif
} ICAN_SRCCLK_TYPE;
/*  Clock Divider Setting for CANOSC */
typedef enum
{
    E_ICANOSCD_DIS=0, /*clock disabled*/
    E_ICANOSCD_MOSC1, /*used main-osc 1*/
    E_ICANOSCD_MOSC2  /*used main-osc 2*/
} ICANOSC_DIV_TYPE;

#ifdef IC_RH850_F1K
/* Source Clock Setting for ISO CSI */
typedef enum
{
    E_ICSIS_DIS,  /*clock disabled*/
    E_ICSIS_PPLLCLK_DEF, //used PPLL
    E_ICSIS_PPLLCLK, //used Peri-PLL
    E_ICSIS_MOSC, //used main OSC
    E_ICSIS_HSI    
} ICSI_SRCCLK_TYPE;

/* Source Clock Setting for ISO IIC */
typedef enum
{
    E_IIICS_DIS,  //clock disabled
    E_IIICS_PPLLCLK2_DEF, //used PPLL
    E_IIICS_PPLLCLK2 //used Peri-PLL
}IIIC_SRCCLK_TYPE;

/* Register address */
#define CLK_REG_PLLIS_CTL        (*(CPU_REG32 *)(0xFFF8A700ul))
#define CLK_REG_PLLIS_ACT        (*(CPU_REG32 *)(0xFFF8A708ul))  /*read-only*/
#define CLK_REG_PPLLCLKS_CTL  (*(CPU_REG32 *)(0xFFF8A010ul))
#define CLK_REG_PPLLCLKS_ACT  (*(CPU_REG32 *)(0xFFF8A018ul))  /*read-only*/

#else //IC_RH850_F1K
/* Source Clock Setting for ISO CSI */
typedef enum
{
    E_ICSIS_DIS,  /*clock disabled*/
    E_ICSIS_CPU,         /*used CPU clock*/
    E_ICSIS_PPLLCLK, /*used Peri-PLL*/
} ICSI_SRCCLK_TYPE;
#endif //IC_RH850_F1K

/******************************************************************************
 *                                            clock domains config             
 *
 ******************************************************************************/
  /* A-watchdog:LSI by 128 division ,stopped in stand-by mode*/
#define  DOMAIN_AWDTD       E_AWDTD_LSI128D
#define  DOMAIN_AWDT_STPMSK  FALSE
/*ATAUJ:LSI by 1 division,stopped  in stand-by mode*/
#define  DOMAIN_ATAUJS      E_ATAUJS_PPLLCLK2
#define  DOMAIN_ATAUJD      E_ATAUJ_DIV1
#define  DOMAIN_ATAUJ_STPMSK FALSE
/*ARTC:disabled*/
#define  DOMAIN_RTCS     E_ARTCAS_DIS
#define  DOMAIN_RTCD     E_ARTCA_DIVDIS
#define  DOMAIN_RTC_STPMSK FALSE
/*AADC: PPLL2 by 1 division,stopped  in stand-by mode*/
#define  DOMAIN_ADCAS  E_AADCAS_PPLLCLK2
#define  DOMAIN_ADCAS1  E_AADCAS_HSI
#define  DOMAIN_ADCAD  E_AADCA_DIV1
#define  DOMAIN_ADCA_STPMSK  FALSE
/*AFOUT: disabled*/
#define  DOMAIN_FOUTS    E_AFOUTS_DIS
#define  DOMAIN_FOUT_STPMSK  FALSE
/*ILIN:CPUCLK2 by 1 division,stopped  in stand-by mode*/
#ifdef IC_RH850_F1K
#define  DOMAIN_ILINS   E_ILIN_PPLLCLK2_DEF
#else
#define  DOMAIN_ILINS   E_ILIN_CPUCLK2
#endif
#define  DOMAIN_ILIND   E_ILIN_DIV1
#define  DOMAIN_ILIN_STPMSK  FALSE
/*IADC:disabled*/
#define  DOMAIN_IADCS E_AADCAS_DIS
#define  DOMAIN_IADCD E_AADCA_DIVDIS
/*ICAN:PLLCLK by 1 division,stopped  in stand-by mode*/
#define  DOMAIN_ICANS  E_ICANS_PPLLCLK
#define  DOMAIN_ICANOSCD  E_ICANOSCD_DIS
#define  DOMAIN_ICAN_STPMSK  FALSE
#define  DOMAIN_ICANOSC_STPMSK  FALSE
#ifdef IC_RH850_F1K
/*ICSI:PLLCLK by 1 division*/
#define  DOMAIN_ICSIS E_ICSIS_PPLLCLK_DEF
//IIC:PLLCLK by 1 division
#define  DOMAIN_IICS E_IIICS_PPLLCLK2_DEF
#else //IC_RH850_F1K
/*ICSI:PLLCLK by 1 division*/
#define  DOMAIN_ICSIS E_ICSIS_PPLLCLK

#endif //IC_RH850_F1K

#endif/*_CLOCK_H*/

