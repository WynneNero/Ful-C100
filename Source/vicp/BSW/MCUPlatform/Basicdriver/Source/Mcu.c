/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD     									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        : Mcu.c
* Module        :
* Instance      :
* Description   :
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comment__DSB__DSBs
** ----------------------------------------------------------------------
* 0.1    Feb 10,2013    NI Rujin    Initial version
* ----------------------------------------------------------------------
* 0.2    Mar 11,2013    LIU Chenxi  Fix issues found on entering LP
* ----------------------------------------------------------------------
* 0.3    Jun 09,2013    LIU Chenxi  Update P2 setting for switch on
         battery power supply when main power lost
------------------------------------------------------------------------
* 0.4	 July 07,2016  PEI Jingli  Adapt 64pin MCU
------------------------------------------------------------------------
* 0.5	 July 07,2016  LIU Chenxi  Refine code structure
------------------------------------------------------------------------
* 0.6	 July 07,2016  LIU Chenxi  merge with remotes/origin/ui4959_bs1
------------------------------------------------------------------------
* 0.7	 July 21,2016  PEI Jingli  Implement code review comments.
* ----------------------------------------------------------------------
* 0.8    Aug  01,2016  PEI Jingli  Change interface by MCU_PIN   
* ----------------------------------------------------------------------
* 0.9    Aug  26,2016  PEI Jingli  Modify IO_Init inf for filtering noise 
                       Modify mcu reset reason micro
* ----------------------------------------------------------------------
* 1.0    Nov 17,2016  PEI Jingli  Add default value setting of IO   
* ----------------------------------------------------------------------
* 1.1    Dec 14,2016  Ren Weimin		Add PFCAE11,PFCE11 for IO config.
* ----------------------------------------------------------------------
* 1.2    Dec 20,2016  ShangQiuju		Remove unused include files.
* ----------------------------------------------------------------------
* 1.3    Dec 29,2016  PEI Jingli  Change for codeReview result   
* ----------------------------------------------------------------------
* 1.4    Jan 06,2016  PEI Jingli  Add parameter checking
* ----------------------------------------------------------------------
* 1.5    Jan 06,2016  PEI Jingli  Delete pwmd code
*------------------------------------------------------------------------
* 1.6    Jan 13,2017  ZhangJie  Fix Coverity warning.
 ----------------------------------------------------------------------
* 1.7    Jan 16,2017  RenWeimin  Add test code. Add interface to get reset reason.
*-----------------------------------------------------------------------
* 1.8    Jan 24,2017   ZhangJie   Remove unused include file.
*-----------------------------------------------------------------------
* 1.9    Feb 09,2017   ZhangJie   Using micro to call app function.
* ----------------------------------------------------------------------
* 2.0    Feb 20,2017  PEI Jingli  Rename interface
* ----------------------------------------------------------------------
* 2.1    Mar 23,2017  PEI Jingli  Fix enter-stop mode processing.
*=====================================================================*/

#include "CONFIG.H"
#include "MCU.h"
#include "Mcu_I.h"
#include "GPIO.h"
#include "wpreg.h"
#include "mcu_if.h"
#include "Gpio_if.h"
#include "clock_if.h"
#include "irq_if.h"
#include "stbc_if.h"
#include "TimerUnit_if.h"
#include "Service_HOOKS.h"
#include "Pwmd.h"
#include "CSI_dma.h"
void PEGuard_Config(void);

/* general PORT register struct */
typedef struct {
    U8    portNo; /*GPIO_PORT_TYPE*/
    U16  pmc;
    U16  pipc;
    U16  pm;
    U16  pibc;
    U16  pfc;
    U16  pfce;
    U16  pfcae;
    U16  pbdc;
    U16  pu;
    U16  pd;
    U16  pdsc;
    U16  podc;
    U16  p;
}MCU_PORT_REGVAL;

/*general IO in active mode*/
const MCU_PORT_REGVAL MCU_IOACTIVE_REGLIST[MCU_PORT_NUM]=
{/*PORT number
      pmc                                   pipc                                    pm                                      pibc                                   pfc                                      pfce                            
      pfcae                                 pbdc                                   pu                                      pd                                     pdsc                                    podc                                */
  {GPIO_PORT_0,
   GPIO_PMC0_ACTIVE_VAL,  GPIO_PIPC0_ACTIVE_VAL,  GPIO_PM0_ACTIVE_VAL,  GPIO_PIBC0_ACTIVE_VAL,  GPIO_PFC0_ACTIVE_VAL,   GPIO_PFCE0_ACTIVE_VAL, 
   GPIO_PFCAE0_ACTIVE_VAL, GPIO_PBDC0_ACTIVE_VAL,  GPIO_PU0_ACTIVE_VAL,  GPIO_PD0_ACTIVE_VAL,  GPIO_PDSC0_ACTIVE_VAL,  GPIO_PODC0_ACTIVE_VAL, GPIO_P0_ACTIVE_VAL}
 ,{GPIO_PORT_8,
   GPIO_PMC8_ACTIVE_VAL,  GPIO_PIPC8_ACTIVE_VAL,  GPIO_PM8_ACTIVE_VAL,  GPIO_PIBC8_ACTIVE_VAL,  GPIO_PFC8_ACTIVE_VAL,   GPIO_PFCE8_ACTIVE_VAL, 
   GPIO_PFCAE8_ACTIVE_VAL, GPIO_PBDC8_ACTIVE_VAL,  GPIO_PU8_ACTIVE_VAL,  GPIO_PD8_ACTIVE_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC8_ACTIVE_VAL, GPIO_P8_ACTIVE_VAL}
 ,{GPIO_PORT_9,
   GPIO_PMC9_ACTIVE_VAL,  GPIO_PIPC9_ACTIVE_VAL,  GPIO_PM9_ACTIVE_VAL,  GPIO_PIBC9_ACTIVE_VAL,  GPIO_PFC9_ACTIVE_VAL,   GPIO_PFCE9_ACTIVE_VAL, 
   GPIO_PFCAE9_ACTIVE_VAL, GPIO_PBDC9_ACTIVE_VAL,  GPIO_PU9_ACTIVE_VAL,  GPIO_PD9_ACTIVE_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC9_ACTIVE_VAL , GPIO_P9_ACTIVE_VAL}
 
 ,{GPIO_PORT_10,
   GPIO_PMC10_ACTIVE_VAL,  GPIO_PIPC10_ACTIVE_VAL,  GPIO_PM10_ACTIVE_VAL,  GPIO_PIBC10_ACTIVE_VAL,  GPIO_PFC10_ACTIVE_VAL,   GPIO_PFCE10_ACTIVE_VAL, 
   GPIO_PFCAE10_ACTIVE_VAL, GPIO_PBDC10_ACTIVE_VAL,  GPIO_PU10_ACTIVE_VAL,  GPIO_PD10_ACTIVE_VAL,    GPIO_PDSC10_ACTIVE_VAL,  GPIO_PODC10_ACTIVE_VAL, GPIO_P10_ACTIVE_VAL}
 
#if (MCU_PIN >=PIN100) 
 ,{GPIO_PORT_11,
	GPIO_PMC11_ACTIVE_VAL,	GPIO_PIPC11_ACTIVE_VAL,  GPIO_PM11_ACTIVE_VAL,	GPIO_PIBC11_ACTIVE_VAL, GPIO_PFC11_ACTIVE_VAL,	 GPIO_PFCE11_ACTIVE_VAL, 
	GPIO_PFCAE11_ACTIVE_VAL,	  GPIO_PBDC11_ACTIVE_VAL,  GPIO_PU11_ACTIVE_VAL,  GPIO_PD11_ACTIVE_VAL,  GPIO_PDSC11_ACTIVE_VAL,  GPIO_PODC11_ACTIVE_VAL, GPIO_P11_ACTIVE_VAL}

 #endif
 
#if (MCU_PIN >=PIN144) 	 
 ,{GPIO_PORT_1,
	GPIO_PMC1_ACTIVE_VAL,	GPIO_PIPC1_ACTIVE_VAL,	GPIO_PM1_ACTIVE_VAL,  GPIO_PIBC1_ACTIVE_VAL,  GPIO_PFC1_ACTIVE_VAL,   GPIO_PFCE1_ACTIVE_VAL, 
	GPIO_PFCAE1_ACTIVE_VAL, GPIO_PBDC1_ACTIVE_VAL,  GPIO_PU1_ACTIVE_VAL,  GPIO_PD1_ACTIVE_VAL,  GPIO_PDSC1_ACTIVE_VAL,  GPIO_PODC1_ACTIVE_VAL, GPIO_P1_ACTIVE_VAL}
 ,{GPIO_PORT_2,
	GPIO_PMC2_ACTIVE_VAL,	GPIO_PIPC2_ACTIVE_VAL,	GPIO_PM2_ACTIVE_VAL,  GPIO_PIBC2_ACTIVE_VAL,  GPIO_PFC2_ACTIVE_VAL,   GPIO_PFCE2_ACTIVE_VAL, 
	GPIO_PFCAE2_ACTIVE_VAL, GPIO_PBDC2_ACTIVE_VAL,  GPIO_PU2_ACTIVE_VAL,  GPIO_PD2_ACTIVE_VAL,  GPIO_PDSC2_ACTIVE_VAL,  GPIO_PODC2_ACTIVE_VAL, GPIO_P2_ACTIVE_VAL}
 ,{GPIO_PORT_12,
	GPIO_PMC12_ACTIVE_VAL, GPIO_PIPC12_ACTIVE_VAL, GPIO_PM12_ACTIVE_VAL,	GPIO_PIBC12_ACTIVE_VAL,  GPIO_PFC12_ACTIVE_VAL,   GPIO_PFCE12_ACTIVE_VAL, 
	GPIO_PFCAE12_ACTIVE_VAL, GPIO_PBDC12_ACTIVE_VAL,	GPIO_PU12_ACTIVE_VAL,  GPIO_PD12_ACTIVE_VAL,  GPIO_PDSC12_ACTIVE_VAL,  GPIO_PODC12_ACTIVE_VAL, GPIO_P12_ACTIVE_VAL}
 ,{GPIO_PORT_18,
	GPIO_PMC18_ACTIVE_VAL,  GPIO_PIPC18_ACTIVE_VAL,  GPIO_PM18_ACTIVE_VAL,  GPIO_PIBC18_ACTIVE_VAL,  GPIO_PFC18_ACTIVE_VAL,  GPIO_PFCE18_ACTIVE_VAL, 
	GPIO_PFCAE18_ACTIVE_VAL, GPIO_PBDC18_ACTIVE_VAL,	 GPIO_PU18_ACTIVE_VAL,	GPIO_PD18_ACTIVE_VAL,	 GPIO_PDSC18_ACTIVE_VAL, GPIO_PODC18_ACTIVE_VAL, GPIO_P18_ACTIVE_VAL}
 ,{GPIO_PORT_20,
	GPIO_PMC20_ACTIVE_VAL,  GPIO_PIPC20_ACTIVE_VAL,  GPIO_PM20_ACTIVE_VAL,  GPIO_PIBC20_ACTIVE_VAL,  GPIO_PFC20_ACTIVE_VAL,  GPIO_PFCE20_ACTIVE_VAL, 
	GPIO_PFCAE20_ACTIVE_VAL, GPIO_PBDC20_ACTIVE_VAL,	 GPIO_PU20_ACTIVE_VAL,	GPIO_PD20_ACTIVE_VAL,	 GPIO_PDSC20_ACTIVE_VAL, GPIO_PODC20_ACTIVE_VAL, GPIO_P20_ACTIVE_VAL}
	 	 
#endif
};

/*general IO in reset mode*/
const MCU_PORT_REGVAL MCU_IORESET_REGLIST[MCU_PORT_NUM]=
{/*PORT number
      pmc                                   pipc                                    pm                                      pibc                                   pfc                                      pfce                            
      pfcae                                 pbdc                                   pu                                      pd                                     pdsc                                    podc                                */
 {GPIO_PORT_0,
  GPIO_PMC0_RESET_VAL,  GPIO_PIPC0_RESET_VAL,  GPIO_PM0_RESET_VAL,  GPIO_PIBC0_RESET_VAL,  GPIO_PFC0_RESET_VAL,   GPIO_PFCE0_RESET_VAL, 
  GPIO_PFCAE0_RESET_VAL, GPIO_PBDC0_RESET_VAL,  GPIO_PU0_RESET_VAL,  GPIO_PD0_RESET_VAL,  GPIO_PDSC0_RESET_VAL,  GPIO_PODC0_RESET_VAL, GPIO_P0_RESET_VAL}
,{GPIO_PORT_8,
  GPIO_PMC8_RESET_VAL,  GPIO_PIPC8_RESET_VAL,  GPIO_PM8_RESET_VAL,  GPIO_PIBC8_RESET_VAL,  GPIO_PFC8_RESET_VAL,   GPIO_PFCE8_RESET_VAL, 
  GPIO_PFCAE8_RESET_VAL, GPIO_PBDC8_RESET_VAL,  GPIO_PU8_RESET_VAL,  GPIO_PD8_RESET_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC8_RESET_VAL, GPIO_P8_RESET_VAL}
,{GPIO_PORT_9,
  GPIO_PMC9_RESET_VAL,  GPIO_PIPC9_RESET_VAL,  GPIO_PM9_RESET_VAL,  GPIO_PIBC9_RESET_VAL,  GPIO_PFC9_RESET_VAL,   GPIO_PFCE9_RESET_VAL, 
  GPIO_PFCAE9_RESET_VAL, GPIO_PBDC9_RESET_VAL,  GPIO_PU9_RESET_VAL,  GPIO_PD9_RESET_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC9_RESET_VAL, GPIO_P9_RESET_VAL}

,{GPIO_PORT_10,
  GPIO_PMC10_RESET_VAL,  GPIO_PIPC10_RESET_VAL,  GPIO_PM10_RESET_VAL,  GPIO_PIBC10_RESET_VAL,  GPIO_PFC10_RESET_VAL,   GPIO_PFCE10_RESET_VAL, 
  GPIO_PFCAE10_RESET_VAL, GPIO_PBDC10_RESET_VAL,  GPIO_PU10_RESET_VAL,  GPIO_PD10_RESET_VAL,    GPIO_PDSC10_RESET_VAL,  GPIO_PODC10_RESET_VAL, GPIO_P10_RESET_VAL}

#if (MCU_PIN >=PIN100)    
,{GPIO_PORT_11,
	GPIO_PMC11_RESET_VAL,  GPIO_PIPC11_RESET_VAL,  GPIO_PM11_RESET_VAL,  GPIO_PIBC11_RESET_VAL, GPIO_PFC11_RESET_VAL,	GPIO_PFCE11_RESET_VAL, 
	GPIO_PFCAE11_RESET_VAL,	   GPIO_PBDC11_RESET_VAL,  GPIO_PU11_RESET_VAL,  GPIO_PD11_RESET_VAL,  GPIO_PDSC11_RESET_VAL,  GPIO_PODC11_RESET_VAL, GPIO_P11_RESET_VAL}

#endif

#if (MCU_PIN >=PIN144)
,{GPIO_PORT_1,
	GPIO_PMC1_RESET_VAL,  GPIO_PIPC1_RESET_VAL,  GPIO_PM1_RESET_VAL,  GPIO_PIBC1_RESET_VAL,  GPIO_PFC1_RESET_VAL,	 GPIO_PFCE1_RESET_VAL, 
	GPIO_PFCAE1_RESET_VAL, GPIO_PBDC1_RESET_VAL,	GPIO_PU1_RESET_VAL,  GPIO_PD1_RESET_VAL,	GPIO_PDSC1_RESET_VAL,	GPIO_PODC1_RESET_VAL, GPIO_P1_RESET_VAL}
,{GPIO_PORT_2,
	GPIO_PMC2_RESET_VAL,  GPIO_PIPC2_RESET_VAL,  GPIO_PM2_RESET_VAL,  GPIO_PIBC2_RESET_VAL,  GPIO_PFC2_RESET_VAL,	 GPIO_PFCE2_RESET_VAL, 
	GPIO_PFCAE2_RESET_VAL, GPIO_PBDC2_RESET_VAL,	GPIO_PU2_RESET_VAL,  GPIO_PD2_RESET_VAL,	GPIO_PDSC2_RESET_VAL,	GPIO_PODC2_RESET_VAL, GPIO_P2_RESET_VAL}
,{GPIO_PORT_12,
	 GPIO_PMC12_RESET_VAL,	GPIO_PIPC12_RESET_VAL,	GPIO_PM12_RESET_VAL,  GPIO_PIBC12_RESET_VAL,  GPIO_PFC12_RESET_VAL,   GPIO_PFCE12_RESET_VAL, 
	 GPIO_PFCAE12_RESET_VAL, GPIO_PBDC12_RESET_VAL,  GPIO_PU12_RESET_VAL,  GPIO_PD12_RESET_VAL,  GPIO_PDSC12_RESET_VAL,  GPIO_PODC12_RESET_VAL, GPIO_P12_RESET_VAL}
,{GPIO_PORT_18,
	GPIO_PMC18_RESET_VAL,  GPIO_PIPC18_RESET_VAL,  GPIO_PM18_RESET_VAL,  GPIO_PIBC18_RESET_VAL,  GPIO_PFC18_RESET_VAL,	 GPIO_PFCE18_RESET_VAL, 
	GPIO_PFCAE18_RESET_VAL, GPIO_PBDC18_RESET_VAL,	GPIO_PU18_RESET_VAL,  GPIO_PD18_RESET_VAL,	GPIO_PDSC18_RESET_VAL,	GPIO_PODC18_RESET_VAL, GPIO_P18_RESET_VAL}
,{GPIO_PORT_20,
	GPIO_PMC20_RESET_VAL,  GPIO_PIPC20_RESET_VAL,  GPIO_PM20_RESET_VAL,  GPIO_PIBC20_RESET_VAL,  GPIO_PFC20_RESET_VAL,	 GPIO_PFCE20_RESET_VAL, 
	GPIO_PFCAE20_RESET_VAL, GPIO_PBDC20_RESET_VAL,	GPIO_PU20_RESET_VAL,  GPIO_PD20_RESET_VAL,	GPIO_PDSC20_RESET_VAL,	GPIO_PODC20_RESET_VAL, GPIO_P20_RESET_VAL}

#endif
};


/*general IO in standby mode*/
const MCU_PORT_REGVAL MCU_IOSTANDBY_REGLIST[MCU_PORT_NUM]=
{/*PORT number
      pmc                                   pipc                                    pm                                      pibc                                   pfc                                      pfce                            
      pfcae                                 pbdc                                   pu                                      pd                                     pdsc                                    podc                                */
 {GPIO_PORT_0,
  GPIO_PMC0_STANDBY_VAL,  GPIO_PIPC0_STANDBY_VAL,  GPIO_PM0_STANDBY_VAL,  GPIO_PIBC0_STANDBY_VAL,  GPIO_PFC0_STANDBY_VAL,   GPIO_PFCE0_STANDBY_VAL, 
  GPIO_PFCAE0_STANDBY_VAL, GPIO_PBDC0_STANDBY_VAL,  GPIO_PU0_STANDBY_VAL,  GPIO_PD0_STANDBY_VAL,  GPIO_PDSC0_STANDBY_VAL,  GPIO_PODC0_STANDBY_VAL, GPIO_P0_STANDBY_VAL}
	  
,{GPIO_PORT_8,
  GPIO_PMC8_STANDBY_VAL,  GPIO_PIPC8_STANDBY_VAL,  GPIO_PM8_STANDBY_VAL,  GPIO_PIBC8_STANDBY_VAL,  GPIO_PFC8_STANDBY_VAL,   GPIO_PFCE8_STANDBY_VAL, 
  GPIO_PFCAE8_STANDBY_VAL, GPIO_PBDC8_STANDBY_VAL,  GPIO_PU8_STANDBY_VAL,  GPIO_PD8_STANDBY_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC8_STANDBY_VAL, GPIO_P8_STANDBY_VAL}

,{GPIO_PORT_9,
  GPIO_PMC9_STANDBY_VAL,  GPIO_PIPC9_STANDBY_VAL,  GPIO_PM9_STANDBY_VAL,  GPIO_PIBC9_STANDBY_VAL,  GPIO_PFC9_STANDBY_VAL,   GPIO_PFCE9_STANDBY_VAL, 
  GPIO_PFCAE9_STANDBY_VAL, GPIO_PBDC9_STANDBY_VAL,  GPIO_PU9_STANDBY_VAL,  GPIO_PD9_STANDBY_VAL,  GPIO_REG_NONE_VAL,  GPIO_PODC9_STANDBY_VAL, GPIO_P9_STANDBY_VAL}

,{GPIO_PORT_10,
  GPIO_PMC10_STANDBY_VAL,  GPIO_PIPC10_STANDBY_VAL,  GPIO_PM10_STANDBY_VAL,  GPIO_PIBC10_STANDBY_VAL,  GPIO_PFC10_STANDBY_VAL,   GPIO_REG_NONE_VAL, 
  GPIO_REG_NONE_VAL,      GPIO_PBDC10_STANDBY_VAL,  GPIO_PU10_STANDBY_VAL,  GPIO_PD10_STANDBY_VAL,    GPIO_PDSC10_STANDBY_VAL,  GPIO_PODC10_STANDBY_VAL, GPIO_P10_STANDBY_VAL}

#if (MCU_PIN >= PIN100)    
,{GPIO_PORT_11,
	GPIO_PMC11_STANDBY_VAL,  GPIO_PIPC11_STANDBY_VAL,  GPIO_PM11_STANDBY_VAL,  GPIO_PIBC11_STANDBY_VAL, GPIO_PFC11_STANDBY_VAL,   GPIO_PFCE11_STANDBY_VAL, 
	GPIO_PFCAE11_STANDBY_VAL,		GPIO_PBDC11_STANDBY_VAL,  GPIO_PU11_STANDBY_VAL,  GPIO_PD11_STANDBY_VAL,  GPIO_PDSC11_STANDBY_VAL,	GPIO_PODC11_STANDBY_VAL, GPIO_P11_STANDBY_VAL}	
#endif

#if (MCU_PIN >=PIN144)
,{GPIO_PORT_1,
	GPIO_PMC1_STANDBY_VAL,	GPIO_PIPC1_STANDBY_VAL,  GPIO_PM1_STANDBY_VAL,	GPIO_PIBC1_STANDBY_VAL,  GPIO_PFC1_STANDBY_VAL,  GPIO_PFCE1_STANDBY_VAL, 
	GPIO_PFCAE1_STANDBY_VAL, GPIO_PBDC1_STANDBY_VAL,	GPIO_PU1_STANDBY_VAL,  GPIO_PD1_STANDBY_VAL,	GPIO_PDSC1_STANDBY_VAL, GPIO_PODC1_STANDBY_VAL, GPIO_P1_STANDBY_VAL}
,{GPIO_PORT_2,
	GPIO_PMC2_STANDBY_VAL,	GPIO_PIPC2_STANDBY_VAL,  GPIO_PM2_STANDBY_VAL,	GPIO_PIBC2_STANDBY_VAL,  GPIO_PFC2_STANDBY_VAL,  GPIO_PFCE2_STANDBY_VAL, 
	GPIO_PFCAE2_STANDBY_VAL, GPIO_PBDC2_STANDBY_VAL,	GPIO_PU2_STANDBY_VAL,  GPIO_PD2_STANDBY_VAL,	GPIO_PDSC2_STANDBY_VAL, GPIO_PODC2_STANDBY_VAL, GPIO_P2_STANDBY_VAL}
,{GPIO_PORT_12,
	GPIO_PMC12_STANDBY_VAL,	GPIO_PIPC12_STANDBY_VAL,	GPIO_PM12_STANDBY_VAL,	GPIO_PIBC12_STANDBY_VAL,  GPIO_PFC12_STANDBY_VAL,	GPIO_PFCE12_STANDBY_VAL, 
	GPIO_PFCAE12_STANDBY_VAL, GPIO_PBDC12_STANDBY_VAL,  GPIO_PU12_STANDBY_VAL,  GPIO_PD12_STANDBY_VAL,  GPIO_PDSC12_STANDBY_VAL,  GPIO_PODC12_STANDBY_VAL, GPIO_P12_STANDBY_VAL}
,{GPIO_PORT_18,
	GPIO_PMC18_STANDBY_VAL,  GPIO_PIPC18_STANDBY_VAL,  GPIO_PM18_STANDBY_VAL,  GPIO_PIBC18_STANDBY_VAL,  GPIO_PFC18_STANDBY_VAL,	 GPIO_PFCE18_STANDBY_VAL, 
	GPIO_PFCAE18_STANDBY_VAL, GPIO_PBDC18_STANDBY_VAL,	GPIO_PU18_STANDBY_VAL,	GPIO_PD18_STANDBY_VAL,	GPIO_PDSC18_STANDBY_VAL,	GPIO_PODC18_STANDBY_VAL, GPIO_P18_STANDBY_VAL}
 ,{GPIO_PORT_20,
	GPIO_PMC20_STANDBY_VAL,  GPIO_PIPC20_STANDBY_VAL,  GPIO_PM20_STANDBY_VAL,  GPIO_PIBC20_STANDBY_VAL,  GPIO_PFC20_STANDBY_VAL,	 GPIO_PFCE20_STANDBY_VAL, 
    GPIO_PFCAE20_STANDBY_VAL, GPIO_PBDC20_STANDBY_VAL,	GPIO_PU20_STANDBY_VAL,	GPIO_PD20_STANDBY_VAL,	GPIO_PDSC20_STANDBY_VAL,	GPIO_PODC20_STANDBY_VAL, GPIO_P20_STANDBY_VAL}
	 
#endif	 

};

/*#pragma arm section rwdata = "backup_ram_data"*/
MCU_RESET_TYPE sResetReason = MCU_RESET_BY_NONE;
/*#pragma arm section rwdata*/


/* IO configration of General Ports,except for APort andJPort. */
static void McuIoInit2GeneralPort(const MCU_PORT_REGVAL *pReglist);
static MCU_RESET_TYPE GetMcuResetFlag( void );

MCU_RESET_TYPE mcu_get_reset_flag( void );

MCU_RESET_TYPE mcu_get_reset_flag( void )
{
    return sResetReason;
}
/* PE Guard area */

const PEG_CONFIG_ST PEG_Configration[4]=
{
{FALSE,  0xFEBF0000|SPID0_DISABLE|SPID1_ENABLE|SPID2_ENABLE|SPID3_ENABLE|PEG_WR_ENABLE|PEG_RD_ENABLE},
{TRUE,	0xFEBD0000|SPID0_DISABLE|SPID1_ENABLE|SPID2_ENABLE|SPID3_ENABLE|PEG_WR_ENABLE|PEG_RD_ENABLE},
{FALSE, 0x00000000},
{FALSE, 0x00000000}
};  

/***********************************************************************
*  Name        : mcu_setup_high_clock
*  Description : setup mcu clock in high speed mode, and set cloclk domains related.
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void mcu_setup_high_clock( void )
{
  /* 1. set cpu clock*/
  Clock_Setup_External_Highclock();
}

/***********************************************************************
*  Name        : mcu_setup_low_clock
*  Description : setup mcu clock in low speed mode,
*  				 after this function the mcu speed to LSI frequecy
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void mcu_setup_low_clock( void )
{
  /*1.stop high clock sources*/
  Clock_Stop_External_Highclock();
  /*2.set cpu clock*/
  Clock_Setup_Internal_Lowclock();
}

/***********************************************************************
*  Name        : mcu_io_init_active
*  Description :always called after wakeup from sleep mode
*  Parameter   :None
*  Returns     : None
***********************************************************************/
void mcu_io_init_active( void )
{
    /* Genaral Port */
    McuIoInit2GeneralPort(MCU_IOACTIVE_REGLIST);

    /* JPort */
    JPORT_REG_JPBDC0=GPIO_JPBDC0_ACTIVE_VAL ;
    JPORT_REG_JPU0    =GPIO_JPU0_ACTIVE_VAL ;
    JPORT_REG_JPD0    =GPIO_JPD0_ACTIVE_VAL ;
    GPIO_SetOpenDrain_Port( JP_PORT_0, (U32)GPIO_JPODC0_ACTIVE_VAL);
    JPORT_REG_JPFC0   =GPIO_JPFC0_ACTIVE_VAL; 
    JPORT_REG_JPMC0   =GPIO_JPMC0_ACTIVE_VAL; 
    JPORT_REG_JPM0     =(U8)GPIO_JPM0_ACTIVE_VAL;     
    JPORT_REG_JPIBC0 =GPIO_JPIBC0_ACTIVE_VAL; 
    JPORT_REG_P(0u) =GPIO_JP0_ACTIVE_VAL; 

//    /* APort */
//    APORT_REG_APBDC(0u)=GPIO_APBDC0_ACTIVE_VAL;
//    APORT_REG_APM(0u)    =GPIO_APM0_ACTIVE_VAL;
//    APORT_REG_APIBC(0u) =GPIO_APIBC0_ACTIVE_VAL;
//    APORT_REG_P(0u) =GPIO_AP0_ACTIVE_VAL;
	/* APort0 */
    APORT0_REG_APBDC(0u)=GPIO_APBDC0_ACTIVE_VAL;
    APORT0_REG_APM(0u)	 =GPIO_APM0_ACTIVE_VAL;
    APORT0_REG_APIBC(0u) =GPIO_APIBC0_ACTIVE_VAL;
    APORT0_REG_P(0u) =GPIO_AP0_ACTIVE_VAL;
  
	/* APort1 */
    APORT1_REG_APBDC(0u)=GPIO_APBDC1_ACTIVE_VAL;
    APORT1_REG_APM(0u)	 =GPIO_APM1_ACTIVE_VAL;
    APORT1_REG_APIBC(0u) =GPIO_APIBC1_ACTIVE_VAL;
	APORT1_REG_P(0u) =GPIO_AP1_ACTIVE_VAL;
	

}

/***********************************************************************
*  Name        : mcu_io_init_reset
*  Description : called after mcu reset
*  Parameter   :None
*  Returns     : None
***********************************************************************/
void mcu_io_init_reset( void )
{
    /* Genaral Port */
    McuIoInit2GeneralPort(MCU_IORESET_REGLIST);

    /* JPort */
    JPORT_REG_JPBDC0=GPIO_JPBDC0_RESET_VAL ;
    JPORT_REG_JPU0    =GPIO_JPU0_RESET_VAL ;
    JPORT_REG_JPD0    =GPIO_JPD0_RESET_VAL ;
    GPIO_SetOpenDrain_Port( JP_PORT_0, (U32)GPIO_JPODC0_RESET_VAL);
    JPORT_REG_JPFC0   =GPIO_JPFC0_RESET_VAL; 
    JPORT_REG_JPMC0   =GPIO_JPMC0_RESET_VAL;  
    JPORT_REG_JPM0     =(U8)GPIO_JPM0_RESET_VAL;     
    JPORT_REG_JPIBC0 =GPIO_JPIBC0_RESET_VAL; 
    JPORT_REG_P(0u) =GPIO_JP0_RESET_VAL; 

//    /* APort */
//    APORT_REG_APBDC(0u)=GPIO_APBDC0_RESET_VAL;
//    APORT_REG_APM(0u)    =GPIO_APM0_RESET_VAL;
//    APORT_REG_APIBC(0u) =GPIO_APIBC0_RESET_VAL;
//    APORT_REG_P(0u) =GPIO_AP0_RESET_VAL;

	 /* APort0*/
	APORT0_REG_APBDC(0u)=GPIO_APBDC0_RESET_VAL;
	APORT0_REG_APM(0u)	  =GPIO_APM0_RESET_VAL;
	APORT0_REG_APIBC(0u) =GPIO_APIBC0_RESET_VAL;
	APORT0_REG_P(0u) =GPIO_AP0_RESET_VAL;

	/* APort1 */
    APORT1_REG_APBDC(0u)=GPIO_APBDC1_RESET_VAL;
	APORT1_REG_APM(0u)	  =GPIO_APM1_RESET_VAL;
	APORT1_REG_APIBC(0u) =GPIO_APIBC1_RESET_VAL;
	APORT1_REG_P(0u) =GPIO_AP1_RESET_VAL; 

}

/***********************************************************************
*  Name        : mcu_io_init_standby
*  Description : IO setting for standby mode
*  Parameter   :None
*  Returns     : None
***********************************************************************/
void mcu_io_init_standby( void )
{
    /* Genaral Port */
    McuIoInit2GeneralPort(MCU_IOSTANDBY_REGLIST);

    /* JPort */
    JPORT_REG_JPBDC0=GPIO_JPBDC0_STANDBY_VAL ;
    JPORT_REG_JPU0    =GPIO_JPU0_STANDBY_VAL ;
    JPORT_REG_JPD0    =GPIO_JPD0_STANDBY_VAL ;
    GPIO_SetOpenDrain_Port( JP_PORT_0,  (U32)GPIO_JPODC0_STANDBY_VAL);
    JPORT_REG_JPFC0   =GPIO_JPFC0_STANDBY_VAL; 
    JPORT_REG_JPMC0   =GPIO_JPMC0_STANDBY_VAL;  
    JPORT_REG_JPM0     =(U8)GPIO_JPM0_STANDBY_VAL;     
    JPORT_REG_JPIBC0 =GPIO_JPIBC0_STANDBY_VAL; 
    JPORT_REG_P(0u) =GPIO_JP0_STANDBY_VAL; 

    /* APort */
//    APORT_REG_APBDC(0u)=GPIO_APBDC0_STANDBY_VAL;
//    APORT_REG_APM(0u)    =GPIO_APM0_STANDBY_VAL;
//    APORT_REG_APIBC(0u) =GPIO_APIBC0_STANDBY_VAL;
//    APORT_REG_P(0u) =GPIO_AP0_STANDBY_VAL;
	/* APort0 */
    APORT0_REG_APBDC(0u)=GPIO_APBDC0_STANDBY_VAL;
    APORT0_REG_APM(0u)	 =GPIO_APM0_STANDBY_VAL;
    APORT0_REG_APIBC(0u) =GPIO_APIBC0_STANDBY_VAL;
    APORT0_REG_P(0u) =GPIO_AP0_STANDBY_VAL;
    
    /* APort1 */
 	APORT1_REG_APBDC(0u)=GPIO_APBDC1_STANDBY_VAL;
    APORT1_REG_APM(0u)	 =GPIO_APM1_STANDBY_VAL;
	APORT1_REG_APIBC(0u) =GPIO_APIBC1_STANDBY_VAL;
    APORT1_REG_P(0u) =GPIO_AP1_STANDBY_VAL;	

}

/* IO configration of General Ports,except for APort andJPort. */
void McuIoInit2GeneralPort(const MCU_PORT_REGVAL *pReglist)
{
    U8  index=0;
    if(NULL==pReglist)
    {
        /* Error handle*/
    }
//    else
//    {
//        while(index<MCU_PORT_NUM)
//        {
//            /* initialization */
//            PORT_REG_PIBC(pReglist->portNo) = 0;
//            PORT_REG_PBDC(pReglist->portNo) = 0;
//            PORT_REG_PM(pReglist->portNo) = 0xFFFF;
//            PORT_REG_PMC(pReglist->portNo) = 0;
//            PORT_REG_PIPC(pReglist->portNo) = 0;
//            /* set port filers.not do here */    
//            
//            /* GPIO to be use as I/O of Peripheral */
//            PORT_REG_PBDC(pReglist->portNo)  = (pReglist)->pbdc;
//            PORT_REG_PU(pReglist->portNo)     = (pReglist)->pu;
//            PORT_REG_PD(pReglist->portNo)     = (pReglist)->pd;
//            if((pReglist->portNo!= (U8)GPIO_PORT_8) && (pReglist->portNo!= (U8)GPIO_PORT_9) )
//              GPIO_SetDriverStrengthDrain_Port( pReglist->portNo , (U32)(pReglist->pdsc));
//            GPIO_SetOpenDrain_Port((U8)(pReglist->portNo) ,(U32) (pReglist->podc));
//            
//            PORT_REG_PFC(pReglist->portNo)   = pReglist->pfc;
//            PORT_REG_PFCE(pReglist->portNo) = pReglist->pfce;
//            if((pReglist->portNo== (U8)GPIO_PORT_0) || (pReglist->portNo== (U8)GPIO_PORT_10) ||(pReglist->portNo== (U8)GPIO_PORT_11))
//              PORT_REG_PFCAE(pReglist->portNo) = pReglist->pfcae;
//            PORT_REG_PIPC(pReglist->portNo) = pReglist->pipc;
//            /*TODO pn*/
//            PORT_REG_PMC(pReglist->portNo)  = pReglist->pmc;
//            PORT_REG_PM(pReglist->portNo)    = pReglist->pm;
//            PORT_REG_PIBC(pReglist->portNo) = pReglist->pibc;
//            PORT_REG_P(pReglist->portNo) = pReglist->p;
//            pReglist++;
//            index++;
//        }
//    }
	else
	{
		while(index<MCU_PORT_NUM)
		{
			/* initialization */
			PORT_REG_PIBC(pReglist->portNo) = 0;
			PORT_REG_PBDC(pReglist->portNo) = 0;
			PORT_REG_PM(pReglist->portNo) = 0xFFFF;
			PORT_REG_PMC(pReglist->portNo) = 0;
			PORT_REG_PIPC(pReglist->portNo) = 0;
			/* set port filers.not do here */	 
			
			/* GPIO to be use as I/O of Peripheral */
			PORT_REG_PBDC(pReglist->portNo)  = (pReglist)->pbdc;
			PORT_REG_PU(pReglist->portNo)	  = (pReglist)->pu;
			PORT_REG_PD(pReglist->portNo)	  = (pReglist)->pd;
			if((pReglist->portNo!= (U8)GPIO_PORT_1) && (pReglist->portNo!= (U8)GPIO_PORT_2) 
				&&(pReglist->portNo!= (U8)GPIO_PORT_8) && (pReglist->portNo!= (U8)GPIO_PORT_9) 
				&& (pReglist->portNo!= (U8)GPIO_PORT_18) && (pReglist->portNo!= (U8)GPIO_PORT_20))
				GPIO_SetDriverStrengthDrain_Port( pReglist->portNo , (U32)(pReglist->pdsc));
				GPIO_SetOpenDrain_Port((U8)(pReglist->portNo) ,(U32) (pReglist->podc));
			
				PORT_REG_PFC(pReglist->portNo)	 = pReglist->pfc;
				PORT_REG_PFCE(pReglist->portNo) = pReglist->pfce;
			if((pReglist->portNo== (U8)GPIO_PORT_0) || (pReglist->portNo== (U8)GPIO_PORT_10) 
				||(pReglist->portNo== (U8)GPIO_PORT_11)|| (pReglist->portNo== (U8)GPIO_PORT_12))
				PORT_REG_PFCAE(pReglist->portNo) = pReglist->pfcae;
				PORT_REG_PIPC(pReglist->portNo) = pReglist->pipc;
			/*TODO pn*/
				PORT_REG_PMC(pReglist->portNo)	= pReglist->pmc;
				PORT_REG_PM(pReglist->portNo)	 = pReglist->pm;
	 			PORT_REG_PIBC(pReglist->portNo) = pReglist->pibc;
				PORT_REG_P(pReglist->portNo) = pReglist->p;
				pReglist++;
				index++;
		}
	}
	 

}

/***********************************************************************
*  Name        : mcu_disable_all_interrupt
*  Description :
*  Parameter   :None
*  Returns     : None
***********************************************************************/
void mcu_disable_all_interrupt(void)
{
  IRQ_IntDisAll();
}

/***********************************************************************
*  Name        : mcu_enable_all_interrupt
*  Description :
*  Parameter   :None
*  Returns     : None
***********************************************************************/
void mcu_enable_all_interrupt(void)
{
    IRQ_IntEnableAll();
}

/***********************************************************************
*  Name        : mcu_sw_reset
*  Description :set mcu reset register to software reset
*  Parameter   :None
*  called: app functions
*  Returns     : None
***********************************************************************/
void mcu_sw_reset( void )
{
	//U8 flag = 1;
	//while(flag);
  /* software reset register
    bit 31~1 reserved
    bit 0       reset enable. =1 to reset */
    PROTECTED_WRITE(CONTRL_CLUST0_REG_PROTCMD0, CONTRL_CLUST0_REG_PROTS0, MCU_REG_RESET, 0x00000001u);
}



/***********************************************************************
*  Name        : mcu_get_reset_reason
*  Description : Get mcu reset reason of reset register. 
*    If a deepstop caused reset, release IO hold state. 
*  Parameter   : None
*  Returns     : MCU_RESET_TYPE mcu reset type
***********************************************************************/
MCU_RESET_TYPE mcu_get_reset_reason( void )
{
    U32 temp_val = ( U32 )MCU_REG_RESET_REASON;
    MCU_RESET_TYPE ret_val = MCU_RESET_BY_NONE;

    if(temp_val& (1u<<MCU_RESET_BY_SW))
    {
        ret_val = MCU_RESET_BY_SW;
    }
    else if(temp_val&0x02u)
    {
        ret_val = MCU_RESET_BY_WDTA0;
    }
    else if(temp_val&0x04u)
    {
        ret_val = MCU_RESET_BY_WDTA1;
    }
    else if(temp_val&0x08u)
    {
        ret_val = MCU_RESET_BY_CLMA0;
    }
    else if(temp_val&0x10u)
    {
        ret_val = MCU_RESET_BY_CLMA1;
    }
    else if(temp_val&0x20u)
    {
        ret_val = MCU_RESET_BY_CLMA2;
    }
    else if(temp_val&0x40u)
    {
        ret_val = MCU_RESET_BY_LVI;
    }
    else if(temp_val&0x80u)
    {
        ret_val = MCU_RESET_BY_CVM;
    }
    else if(temp_val&0x100u)
    {
        ret_val = MCU_RESET_BY_EXTERNAL;
    }
    else if(temp_val&0x200u)
    {
        ret_val = MCU_RESET_BY_POWERUP;
    }
    else if(temp_val&0x400u)
    {
        ret_val = MCU_RESET_BY_DEEPSTOP;
    }

    /*clear reset flat*/
    MCU_REG_RESETFLAG_CLEAR=0x7ffu;

    sResetReason = ret_val;
    return ret_val;
}

/*Get mcu reset type*/
MCU_RESET_TYPE GetMcuResetFlag( void )
{
    return sResetReason;
}

/***********************************************************************
*  Name        : mcu_io_init_sleep
*  Description :IO setting for sleep mode.
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void mcu_io_init_sleep( void )
{
    mcu_io_init_standby();
}

/***********************************************************************
*  Name        : mcu_io_init_sleep
*  Description :IO setting when power on.
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void mcu_io_init_poweron(void)
{
    mcu_io_init_reset();
}

/***********************************************************************
*  Name        : mcu_io_init_wakeup
*  Description :IO initializing after wakeup from sleep.
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void mcu_io_init_wakeup(void)
{
    mcu_io_init_active();
}
/***********************************************************************
*  Name        : mcu_to_sleep_mode
*  Description :this function to make mcu to stop/ mode
*  Parameter   : type MCU_STOP_MODE,MCU_DEEPSTOP_MODE
*  Returns     : None
***********************************************************************/
void mcu_to_sleep_mode( MCU_SLEEP_TYPE type )
{
    if((MCU_STOP_MODE==type)||(MCU_DEEPSTOP_MODE==type))
    {
        /* Stop all the peripheral functions to stop clock supply. */
        /* do in app layer */
        TAU_setup_deinit();
       
        /* Set wake-up registers. 
        1.clear wake-up factor flag 2.mask non-wakeup factor 3.unmask wakeup factor */
        Stbc_Set_WakeupFactor();
        
        /* Set the clock stop mask and select the clock domains to be stopped and to continue operating.*/
        /*select the clock source to be stopped and to continue operating.   */
        /* if need, select the clock enabled as CPU clock */
        
		
        if(MCU_STOP_MODE == type)
        {
            /*enter stop mode*/
            Stbc_Run2Stop();
        }
	 else if(MCU_DEEPSTOP_MODE == type)      
        {
            if(Stbc_CyclicRunEnableCheck())
                mcu_setup_low_clock(); 

            /*enter deepstop mode*/
            Stbc_Run2DeepStop();
        }
    }
    else
    {
        /*TODO in sleep mode,using timer factor to wake-up*/
    }
}

/***********************************************************************
*  Name        : mcu_to_wakup_mode
*  Description : mcu handler afer wakeup from stand-by mode.If from deepstop mode, 
                    release IO buffer hold-state first
*  Parameter   : type always be MCU_FULL_MODE
*  Returns     : None
***********************************************************************/
void mcu_to_wakup_mode(MCU_WAKEUP_TYPE type) 
{
    MCU_RESET_TYPE resRsn=GetMcuResetFlag();

    /*Release IO buffer hold*/
    if( MCU_RESET_BY_DEEPSTOP==resRsn)
     {  
     	Stbc_Clear_IoHoldMode();
	 }

	PEGuard_Config();   /*PE Guard settings for DMA*/
    if(MCU_FULL_MODE==type)
    {
        /*Reset wake-up registers. */
        Stbc_Reset_WakeupFactor();
        
        /*2. init clock and CPU Mode*/
        mcu_setup_high_clock();
        
        /*4.TAU setup*/
        TAU_setup_init();
        
        /*5.timer init*/
        
        /*6.pwm init*/
//		PWMD_Unit_Init();
        /*7.capture init */   
    }
    else
    {
        /*TODO if nopll .Unused*/
    }
   #if(SERVICE_HOOKS_EN==1u)
        SERVICE_HARDWARE_INIT_HOOK();
   #endif	              
  
}

/***********************************************************************
*  Name        : mcu_set_interrupt_table_address
*  Description :  Not used vector table.
*  Parameter   : addr value
*  Returns     : None
***********************************************************************/
void mcu_set_irq_table_address(U32 addr)
{
    /*Set vector register*/
}

/***********************************************************************
*  Name        : PEGuard_Config
*  Description :Set PE Guard Area0~3 and enable external master with specified SPID
*                  external master always be used by DMA
*  Parameter  : None
*  Returns     : None
***********************************************************************/
void PEGuard_Config(void)
{
    U8 n=0;
    for(n=0;  n<4; n++)
    {
	/** PE Guard Area0 settings **/
	/*PEGGnMK �� PEG Area n Mask Setting Register (n = 0 to 3)
	31 to 12 GnMASK 
		0: Target bits are compared when determining the PE guard area.
		1: Target bits are not compared when determining the PE guard area.
	*/
	if(PEG_Configration[n].AreaEnable)
	{
	    //PEG_REG_PEGGnMK(n) =0x0000f000;
	    PEG_REG_PEGGnMK(n) =0xfffff000;
	/*PEGGnBA �� PEG Area n Base Setting Register (n = 0 to 3)
	31 to 12 GnBASE Base address that specifies the range of PE guard protection area n.
	                       Base address is in Local RAM/Retetion RAM.
	7 GnSP3 	Access permission setting from SPID = 3 external master to PE guard
			protection area n.
		0: Not permit.
		1: Permit.										---set 0
	6 GnSP2 	Access permission setting from SPID = 2 external master to PE guard
			protection area n.
		0: Not permit.										---set 0
		1: Permit.
	5 GnSP1 	Access permission setting from SPID = 1 external master to PE guard
			protection area n.
		0: Not permit.										---set 1
		1: Permit.
	4 GnSP0 	Access permission setting from SPID = 0 external master to PE guard
			protection area n.
		0: Not permit.										---set 0
		1: Permit.
	2 GnWR 	Write access permission to PE guard protection area n.
		0: Write access is disabled.
		1: Write access is enabled.							---set
	1 GnRD 	Read access permission to PE guard protection area n.
		0: Read access is disabled.
		1: Read access is enabled.							---set
	0 GnEN 	Enables or Disables the setting for the access enable conditions to PE guard
		   	protection area n.
		0: Settings for access enable conditions are disabled.
		1: Settings for access enable conditions are enabled.		---set
	*/
	PEG_REG_PEGGnBA(n)=PEG_Configration[n].Config|0x01  ;/*local ram 0xFEBD0000, permit SPID1, read/write/access enable */
	}
	else
	{
	    PEG_REG_PEGGnMK(n) =0x00000000;
	}
    }

	/*PEGSP �� PEG SPID Control Register
	0 SPEN 	Access permission to external master with specified SPID.
		0: Not permit.
		1: Permit.		---set
	*/
	PEG_REG_PEGSP=0x01;
}

/**************** END OF FILE *****************************************/

