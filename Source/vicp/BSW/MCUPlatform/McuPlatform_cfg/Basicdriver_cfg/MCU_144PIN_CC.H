/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT      									           *
*   AUTHOR	   : 										   			   *
************************************************************************
* Object        : Mcu_pin_cc.h
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version		Date			Name    			Changes 
------------------------------------------------------------------------
* 0.1	   		201708/17  		Chen Dingding  		Adapt 144pin  MCU  
------------------------------------------------------------------------ 
*=====================================================================*/
#ifndef _PIN_MAP_CC_H
#define _PIN_MAP_CC_H

#include "CONFIG.H"
#include "SystemMode_Cfg.h"

/*--------------------configration method-------------------
* 1. independent IO
    PMC:bit=0 -> PM
                         1:input  -> PIBC,PU,PD
                 
                         0:output->PBDC,PDSC,PODC
*2. alternative mode
   PMC:bit=1 ->PIPC
                         0   -> PFC,PFCE,PFCAE
                              ->PM
                                  1: input   -> same as 1.
                                  0:output-> same as 1.
                                   
                         1  ->PFC,PFCE,PFCAE
                       (directIO chapter2.11)
*---------------------------------------------------------*/
#if ( MCU_PIN == PIN144 )
/*-- MCU_RH850_F1L:  PORT 0,8,9,10,11,JP0,AP0 --*/
#define MCU_PORT_NUM      10u
#define MCU_APORT_NUM     2u
#define MCU_JPORT_NUM     1u

/* PMC: 0=port mode 1=alternative */
#define GPIO_PMC0_ACTIVE_VAL          0x7f8fu //0111 1111 1000 1111 alt:P0_0,1,2,3,4 7,8,9,10,11,12,13,14
#define GPIO_PMC1_ACTIVE_VAL          0x0300u //0000 0011 0000 0000 alt:P1_0,1,8,9	
#define GPIO_PMC2_ACTIVE_VAL          0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PMC8_ACTIVE_VAL          0x0189u //0000 0001 1000 1001 alt:P8_0,3,7,8
#define GPIO_PMC9_ACTIVE_VAL          0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PMC10_ACTIVE_VAL         0x62c3u //0110 0010 1100 0011 alt:P10_0,1,6,7,9,13,14,out:0,3,4,5,15
#define GPIO_PMC11_ACTIVE_VAL         0x7ce6u //0111 1100 1110 0110 alt:P11_1,2,5,6,9,10,,14
#define GPIO_PMC12_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PMC18_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PMC20_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 alt:
#define GPIO_JPMC0_ACTIVE_VAL         0x0008u //0000 0000 0000 1000 alt:JP0_3  
//no Anolog
#define GPIO_REG_NONE_VAL      0x0000u /*none register*/

/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */
#define GPIO_PIPC0_ACTIVE_VAL      0x000cu //0000 0000 0000 1100  ,p0_2,p0_3(SCLK,MISO) control by alt spi,
#define GPIO_PIPC1_ACTIVE_VAL      0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC2_ACTIVE_VAL      0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC8_ACTIVE_VAL      0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC9_ACTIVE_VAL      0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC10_ACTIVE_VAL     0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC11_ACTIVE_VAL     0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC12_ACTIVE_VAL     0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC18_ACTIVE_VAL     0x0000u //0000 0000 0000 0000 alt:
#define GPIO_PIPC20_ACTIVE_VAL     0x0000u //0000 0000 0000 0000 alt:

/*no Jtag*/
/*no Anolog*/

/* PM: 0=output 1=input */
#define GPIO_PM0_ACTIVE_VAL          0xffe7u //1111 1111 1110 0111 out:p0_0,p0_1,p0_2,p0_6,4
#define GPIO_PM1_ACTIVE_VAL          0xf9fDu //1111 1001 1111 1101 out:P1_9,10,in:P1_11
#define GPIO_PM2_ACTIVE_VAL          0xffffu //1111 1111 1111 1111
#define GPIO_PM8_ACTIVE_VAL          0xe232u //1110 0010 0011 0010 out:P8_0,2,3,6,7,8,9,10,11,12
#define GPIO_PM9_ACTIVE_VAL          0xffffu //0000 0000 0000 0000 alt:
#define GPIO_PM10_ACTIVE_VAL         0x6341u //0110 0011 0100 0001 out:P10_2,3,4,5,7,10,11,12 1
#define GPIO_PM11_ACTIVE_VAL         0x00deu //0000 0000 1101 1110 out:P11_8,15,0
#define GPIO_PM12_ACTIVE_VAL         0xfffcu //1111 1111 1111 1100 out:P12_0,1
#define GPIO_PM18_ACTIVE_VAL         0xfff0u //1111 1111 1111 1111 alt:
#define GPIO_PM20_ACTIVE_VAL         0xffffu //1111 1111 1111 1111 alt:
#define GPIO_APM0_ACTIVE_VAL         0xffffu //1111 1111 1111 1111 alt:
#define GPIO_APM1_ACTIVE_VAL         0xffffu //1111 1111 1111 1111 alt:
#define GPIO_JPM0_ACTIVE_VAL         0xffffu //1111 1111 1111 1111 alt:



/*Port InputBuffer Control: all 0,unused here */
#define GPIO_PIBC0_ACTIVE_VAL          0x7f87u //0111 1111 1000 0111 general_port_input P0_0,2,3,7,8,9,10,11,12,13,14
#define GPIO_PIBC1_ACTIVE_VAL          0x0808u //0000 1000 0000 1000 general_port_input P1_3 P1_11
#define GPIO_PIBC2_ACTIVE_VAL          0x0000u //1111 1111 1111 1111 
#define GPIO_PIBC8_ACTIVE_VAL          0x0230u //0000 0010 0011 0000 general_port_input P8_,4,5
#define GPIO_PIBC9_ACTIVE_VAL          0x0078u //0000 0000 0111 1000 general_port_input P9_3,4,5,6
#define GPIO_PIBC10_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 general_port_input P10_
#define GPIO_PIBC11_ACTIVE_VAL         0x0008u //0000 0000 0000 0000 general_port_input P11_7
#define GPIO_PIBC12_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 general_port_input P12_2
#define GPIO_PIBC18_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 general_prot_inout 
#define GPIO_PIBC20_ACTIVE_VAL         0x0030u //0000 0000 0011 0000  general_port_input P20_4,5
#define GPIO_APIBC0_ACTIVE_VAL         0x0080u //0000 0000 7000 0000  general_port_input AP0_7 
#define GPIO_APIBC1_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 
#define GPIO_JPIBC0_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 

 /* PFCAE,PFCE,PFC:IN alternative mode, select a alternative function in 0~4.
*  binary value [PFCAEn_m,PFCEn_m,PFCn_m]b  from 0~4  is a alternative function.
*/
#define GPIO_PFC0_ACTIVE_VAL           0x078eu //0000 0111 1000 1110 P0_0:alt0_in_/TAUD0I2_000  P0_1:alt4_in_CSIH0SI_110   P0_2:alt4_in_CSIH0SC_110 
#define GPIO_PFCE0_ACTIVE_VAL          0x7f8eu //0111 1111 1000 1110 P0_3:alt4_out_CSIH0SO_110    P0_7:alt4_in_TAUB0I0_110   P0_8:alt4_in_TAUB0I2_110 
#define GPIO_PFCAE0_ACTIVE_VAL         0x0000u //0000 0000 0000 0000 P0_9:alt4_in_TAUB0I4_110  P0_10:alt4_in_ TAUB0I6_110   P0_11:alt3_in_TAUB0I8_010     P0_12:alt3_in_TAUB0I10_010
											   //P0_13:alt3_in_TAUB0I12_010  P0_14:alt3_in_TAUB0I14_010  

#define GPIO_PFC1_ACTIVE_VAL           0x0000u //0000 0000 0000 0000
#define GPIO_PFCE1_ACTIVE_VAL          0x0000u //0000 0000 0000 0000
#define GPIO_PFCAE1_ACTIVE_VAL         0x0000u //0000 0000 0000 0000

#define GPIO_PFC2_ACTIVE_VAL           0x000eu
#define GPIO_PFCE2_ACTIVE_VAL          0x000eu     
#define GPIO_PFCAE2_ACTIVE_VAL         0x0000u

#define GPIO_PFC8_ACTIVE_VAL           0x1f80u //0001 1111 1000 0000 P8_0:alt1_in_TAUJ0I0_000  P8_2:alt3_out_PWGA22O_010   P8_3:alt1_in_TAUJ0I1_000  P8_7:alt2_out_PWGA39O_100   P8_8:alt2_out_PWGA40O_100     P8_9:alt2_out_PWGA41O_100
#define GPIO_PFCE8_ACTIVE_VAL          0x0004u //0000 0000 0000 0100 P8_10:alt2_out_PWGA42O_100   P8_11:alt2_out_PWGA43O_100    P8_12:alt2_out_PWGA44O_100     
#define GPIO_PFCAE8_ACTIVE_VAL         0x0000u 
  
#define GPIO_PFC9_ACTIVE_VAL           0x0000u 
#define GPIO_PFCE9_ACTIVE_VAL          0x0000u 
#define GPIO_PFCAE9_ACTIVE_VAL         0x0000u  

#define GPIO_PFC10_ACTIVE_VAL          0x62c3u //0110 0010 1100 0011 10_6:alt4_in_CAN1RX_110 P10_7:alt4_out_CAN1TX_110   P10_9 INTP10:alter2_input=100 
#define GPIO_PFCE10_ACTIVE_VAL         0x60c0u //0110 0000 1100 0000 P10_0:alt2_in_CAN0RX_100 P10_1:alt2_out_CAN0TX_100
#define GPIO_PFCAE10_ACTIVE_VAL        0x0000u //0000 0000 0000 0000 P10_13:alt4_in_TAUB0I5_110 P10_14:alt4_in_TAUB0I7_110

#define GPIO_PFC11_ACTIVE_VAL          0x7e06u //0111 1110 0000 0110 P11_1:alt4_in_TAUB0I13_110 P11_2:alt4_in_TAUB0I13_110    P11_10:alt2_out_PWGA50O_100    P11_11:alt2_out_PWGA51O_100
#define GPIO_PFCE11_ACTIVE_VAL         0x0006u //0000 0000 0000 0110 P11_12:alt2_out_PWGA52O_100 P11_13:alt2_out_PWGA53O_100   P11_14:alt2_out_PWGA54O_100
#define GPIO_PFCAE11_ACTIVE_VAL        0x0000u //0000 0000 0000 0000P11_5:alt1_out_RLIN33TX_000   P11_6:alt1_in_RLIN33RX_000

#define GPIO_PFC12_ACTIVE_VAL          0x0000u 
#define GPIO_PFCE12_ACTIVE_VAL         0x0000u 
#define GPIO_PFCAE12_ACTIVE_VAL        0x0000u  

#define GPIO_PFC18_ACTIVE_VAL          0x0000u 
#define GPIO_PFCE18_ACTIVE_VAL         0x0000u 
#define GPIO_PFCAE18_ACTIVE_VAL        0x0000u 

#define GPIO_PFC20_ACTIVE_VAL          0x0000u 
#define GPIO_PFCE20_ACTIVE_VAL         0x0000u 
#define GPIO_PFCAE20_ACTIVE_VAL        0x0000u 

#define GPIO_JPFC0_ACTIVE_VAL          0x0008u //0000 0000 0000 1001 JP0_3:alt2_IN_TAUJ0I3_100
#define GPIO_JPFCE0_ACTIVE_VAL         0x0000u
#define GPIO_JPFCAE0_ACTIVE_VAL        0x0000u
/*no Anolog*/


/* Port Bidirection Control: 1= Bidirection */
#define GPIO_PBDC0_ACTIVE_VAL      0x0000u    
#define GPIO_PBDC1_ACTIVE_VAL      0x0000u    
#define GPIO_PBDC2_ACTIVE_VAL      0x0000u    
#define GPIO_PBDC8_ACTIVE_VAL      0x0000u  //8_6 os data
#define GPIO_PBDC9_ACTIVE_VAL      0x0000u
#define GPIO_PBDC10_ACTIVE_VAL     0x0000u
#define GPIO_PBDC11_ACTIVE_VAL     0x0000u
#define GPIO_PBDC12_ACTIVE_VAL     0x0000u
#define GPIO_PBDC18_ACTIVE_VAL     0x0000u
#define GPIO_PBDC20_ACTIVE_VAL     0x0000u
#define GPIO_APBDC0_ACTIVE_VAL     0x0000u
#define GPIO_APBDC1_ACTIVE_VAL     0x0000u
#define GPIO_JPBDC0_ACTIVE_VAL     0x0000u
 
/* PullUp Control: input mode.  1= internal pullup.
* Care that PUn.PUn_m=1 and PDn.PDn_m=1, then the real Pin is pulldown
*/
#define GPIO_PU0_ACTIVE_VAL      0x0000u  // 
#define GPIO_PU1_ACTIVE_VAL      0x0000u  //  
#define GPIO_PU2_ACTIVE_VAL      0x0000u  // 
#define GPIO_PU8_ACTIVE_VAL      0x0000u  //
#define GPIO_PU9_ACTIVE_VAL      0x0000u
#define GPIO_PU10_ACTIVE_VAL     0x0000u  
#define GPIO_PU11_ACTIVE_VAL     0x0000u
#define GPIO_PU12_ACTIVE_VAL     0x0000u
#define GPIO_PU18_ACTIVE_VAL     0x0000u
#define GPIO_PU20_ACTIVE_VAL     0x0000u
#define GPIO_JPU0_ACTIVE_VAL     0x0000u
/*no Anolog*/

/* PullDown Control: input mode.  1= internal pulldown */
#define GPIO_PD0_ACTIVE_VAL      0x0000u   
#define GPIO_PD1_ACTIVE_VAL      0x0000u   
#define GPIO_PD2_ACTIVE_VAL      0x0000u   
#define GPIO_PD8_ACTIVE_VAL      0x0000u 
#define GPIO_PD9_ACTIVE_VAL      0x0000u
#define GPIO_PD10_ACTIVE_VAL     0x0000u
#define GPIO_PD11_ACTIVE_VAL     0x0000u
#define GPIO_PD12_ACTIVE_VAL     0x0000u
#define GPIO_PD18_ACTIVE_VAL     0x0000u
#define GPIO_PD20_ACTIVE_VAL     0x0010u //0000 0000 0001 0000 alt:4
#define GPIO_JPD0_ACTIVE_VAL     0x0000u
/*no Anolog*/

 
/* Port Driver Strength: output mode. 0:<=10mhz, 1:<=40mhz
* 40MHZ pin select:P0_2,3,5,6,7,13,14  ; P10_ALL ;P11_0~7  
*/
#define GPIO_PDSC0_ACTIVE_VAL      0x000eu  //0000 0000 0000 1100 40Mhz:SPI,P0_2,P0_3
#define GPIO_PDSC1_ACTIVE_VAL      0x0000u  //
#define GPIO_PDSC2_ACTIVE_VAL      0x0000u  //
#define GPIO_PDSC8_ACTIVE_VAL      0x0000u   
#define GPIO_PDSC9_ACTIVE_VAL      0x0000u   
#define GPIO_PDSC10_ACTIVE_VAL     0x0000u// 0x0000u
#define GPIO_PDSC11_ACTIVE_VAL     0x0000u
#define GPIO_PDSC12_ACTIVE_VAL     0x0000u
#define GPIO_PDSC18_ACTIVE_VAL     0x0000u
#define GPIO_PDSC20_ACTIVE_VAL     0x0000u
/*no Jtag*/
/*no Anolog*/

/* Port open drain control: output mode. 0:push-pull, 1:open-drain*/
#define GPIO_PODC0_ACTIVE_VAL      0x0000u   
#define GPIO_PODC1_ACTIVE_VAL      0x0000u   
#define GPIO_PODC2_ACTIVE_VAL      0x0000u   
#define GPIO_PODC8_ACTIVE_VAL      0x0000u  
#define GPIO_PODC9_ACTIVE_VAL      0x0000u
#define GPIO_PODC10_ACTIVE_VAL     0x0000u
#define GPIO_PODC11_ACTIVE_VAL     0x0000u
#define GPIO_PODC12_ACTIVE_VAL     0x0000u
#define GPIO_PODC18_ACTIVE_VAL     0x0000u
#define GPIO_PODC20_ACTIVE_VAL     0x0000u
#define GPIO_JPODC0_ACTIVE_VAL     0x0000u
/*no Anolog*/

/* Set default for output pin */
#define GPIO_P0_ACTIVE_VAL        0x0000u
#define GPIO_P1_ACTIVE_VAL        0x0000u
#define GPIO_P2_ACTIVE_VAL        0x0000u
#define GPIO_P8_ACTIVE_VAL        0x0000u
#define GPIO_P9_ACTIVE_VAL        0x0000u
#define GPIO_P10_ACTIVE_VAL       0x0000u
#define GPIO_P11_ACTIVE_VAL       0x0000u
#define GPIO_P12_ACTIVE_VAL       0x0000u
#define GPIO_P18_ACTIVE_VAL       0x0000u
#define GPIO_P20_ACTIVE_VAL       0x0000u
#define GPIO_AP0_ACTIVE_VAL       0x0000u
#define GPIO_AP1_ACTIVE_VAL       0x0000u
#define GPIO_JP0_ACTIVE_VAL       0x0000u
/*----------------------- GPIO RESET ---------------------------- */
/* PMC: 0=port mode 1=alternative */ 
#define GPIO_PMC0_RESET_VAL           0x7f8fu //0111 1111 1000 1111 alt:P0_0,1,2,3,7,8,9,10,11,12,13,14
#define GPIO_PMC1_RESET_VAL           0x0300u //0000 0011 0000 0000 
#define GPIO_PMC2_RESET_VAL           0x0000u 
#define GPIO_PMC8_RESET_VAL           0x0189u //0000 0001 1000 1001 alt:P8_0,3,7,8
#define GPIO_PMC9_RESET_VAL           0x0000u 
#define GPIO_PMC10_RESET_VAL          0x62c3u //0110 0010 1100 0011 alt:P10_0,1,6,7,9,13,14
#define GPIO_PMC11_RESET_VAL          0x7ce6u //0111 1110 1110 0110 alt:P11_1,2,5,6,10,14
#define GPIO_PMC12_RESET_VAL          0x0000u 
#define GPIO_PMC18_RESET_VAL          0x0000u 
#define GPIO_PMC20_RESET_VAL          0x0000u
#define GPIO_JPMC0_RESET_VAL          0x0008u  
/*no Anolog*/
//#define GPIO_REG_NONE_VAL      0x0000u  /*none register*/

/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */
#define GPIO_PIPC0_RESET_VAL      0x000cu   //0000 0000 0000   1100  ,p0_2,p0_3 control by alt spi  
#define GPIO_PIPC1_RESET_VAL      0x0000u    
#define GPIO_PIPC2_RESET_VAL      0x0000u  
#define GPIO_PIPC8_RESET_VAL      0x0000u
#define GPIO_PIPC9_RESET_VAL      0x0000u
#define GPIO_PIPC10_RESET_VAL     0x0000u
#define GPIO_PIPC11_RESET_VAL     0x0000u
#define GPIO_PIPC12_RESET_VAL     0x0000u
#define GPIO_PIPC18_RESET_VAL     0x0000u
#define GPIO_PIPC20_RESET_VAL     0x0000u
/*no Jtag*/
/*no Anolog*/


/* PM: 0=output 1=input */
#define GPIO_PM0_RESET_VAL          0xffe7u //1111 1111 1110 0111 out:P0_3,4,
#define GPIO_PM1_RESET_VAL          0xf90du //1111 1001 0000 1101 out:P1_1,4,5,6,7,9,10,11
#define GPIO_PM2_RESET_VAL          0xffffu 
#define GPIO_PM8_RESET_VAL          0xe232u //1110 0010 0011 0010 out:P8_0,2,3,6,7,8,10,11,12
#define GPIO_PM9_RESET_VAL          0xffffu 
#define GPIO_PM10_RESET_VAL         0x6341u //0110 0011 0100 0001 out:P10_2,3,4,5,7,10,11,12
#define GPIO_PM11_RESET_VAL         0x00deu //0000 0000 1101 1110 out:P11_8,10,11,12,13,14,15,0
#define GPIO_PM12_RESET_VAL         0xfffcu //1111 1111 1111 1100 out:P12_0,1
#define GPIO_PM18_RESET_VAL         0xfff0u 
#define GPIO_PM20_RESET_VAL         0xffffu //1111 1111 1111 1111 
#define GPIO_APM0_RESET_VAL         0xffffu 
#define GPIO_APM1_RESET_VAL         0xffffu 
#define GPIO_JPM0_RESET_VAL         0xffffu  

/* Port InputBuffer Control: 1 ,all :0  */
#define GPIO_PIBC0_RESET_VAL          0x7f87u   //0111 1111 1001 0111 general_port_input P0_7,8,9,10,11,12,13,14
#define GPIO_PIBC1_RESET_VAL          0x0808u	//0000 1000 0000 1000 general_port_input P1_3
#define GPIO_PIBC2_RESET_VAL          0x0000u
#define GPIO_PIBC8_RESET_VAL          0x0230u   //0000 0010 0011 0000 general_port_input P8_,4,5
#define GPIO_PIBC9_RESET_VAL          0x0078u   //0000 0000 0111 1000 general_port_input P9_3,4,5,6
#define GPIO_PIBC10_RESET_VAL         0x0000u   
#define GPIO_PIBC11_RESET_VAL         0x0008u   //0000 0000 0000 0000 general_port_input P11_7
#define GPIO_PIBC12_RESET_VAL         0x0000u   //0000 0000 0000 0000 general_port_input P12_2
#define GPIO_PIBC18_RESET_VAL         0x0000u
#define GPIO_PIBC20_RESET_VAL         0x0033u   //0000 0000 0011 0011 general_port_input P20_4,5
#define GPIO_APIBC0_RESET_VAL         0x0080u  // 0000 0000 1000 0000 0xffffu   general_port_input AP0_7
#define GPIO_APIBC1_RESET_VAL         0xff80u  // 1111 1111 1000 0000
#define GPIO_JPIBC0_RESET_VAL         0x0000u  


/* PFCAE,PFCE,PFC:IN alternative mode, select a alternative function in 0~4.
*  binary value [PFCAEn_m,PFCEn_m,PFCn_m]b  from 0~4  is a alternative function.
*/

#define GPIO_PFC0_RESET_VAL           0x078eu //0000 0111 1000 1110 P0_0:alt0_in_TAUD0I2_000  P0_1:alt4_in_CSIH0SI_110   P0_2:alt4_in_CSIH0SC_110 
#define GPIO_PFCE0_RESET_VAL          0x7f8eu //0111 1111 1000 1110 P0_3:alt4_out_CSIH0SO_110  P0_4:alt2_in_INTP11_100     P0_7:alt4_in_TAUB0I0_110   P0_8:alt4_in_TAUB0I2_110 
#define GPIO_PFCAE0_RESET_VAL         0x0000u //0000 0000 0000 0000 P0_9:alt4_in_TAUB0I4_110  P0_10:alt4_in_ TAUB0I6_110   P0_11:alt3_in_TAUB0I8_010     P0_12:alt3_in_TAUB0I10_010
											  //P0_13:alt3_in_TAUB0I12_010  P0_14:alt3_in_TAUB0I14_010  
#define GPIO_PFC1_RESET_VAL           0x0000u 
#define GPIO_PFCE1_RESET_VAL          0x0000u    
#define GPIO_PFCAE1_RESET_VAL         0x0000u

#define GPIO_PFC2_RESET_VAL           0x000eu
#define GPIO_PFCE2_RESET_VAL          0x000eu     
#define GPIO_PFCAE2_RESET_VAL         0x0000u

#define GPIO_PFC8_RESET_VAL           0x1f80u //0001 1111 1000 0000 P8_0:alt1_in_TAUJ0I0_000  P8_2:alt3_out_PWGA22O_010   P8_3:alt1_in_TAUJ0I1_000   P8_7:alt2_out_PWGA39O_100   P8_8:alt2_out_PWGA40O_100     P8_9:alt2_out_PWGA41O_100
#define GPIO_PFCE8_RESET_VAL          0x0004u //0000 0000 0000 0100 P8_10:alt2_out_PWGA42O_100   P8_11:alt2_out_PWGA43O_100    P8_12:alt2_out_PWGA44O_100     
#define GPIO_PFCAE8_RESET_VAL         0x0000u 
  
#define GPIO_PFC9_RESET_VAL           0x0000u 
#define GPIO_PFCE9_RESET_VAL          0x0000u 
#define GPIO_PFCAE9_RESET_VAL         0x0000u  

#define GPIO_PFC10_RESET_VAL          0x62c3u //0110 0010 1100 0011 P10_6:alt4_in_CAN1RX_110 P10_7:alt4_out_CAN1TX_110   P10_9 INTP10:alter2_input=100 
#define GPIO_PFCE10_RESET_VAL         0x60c0u //0110 0000 1100 0000 P10_0:alt2_in_CAN0RX_100 P10_1:alt2_out_CAN0TX_100
#define GPIO_PFCAE10_RESET_VAL        0x0000u //0000 0000 0000 0000 P10_13:alt4_in_TAUB0I5_110 P10_14:alt4_in_TAUB0I7_100

#define GPIO_PFC11_RESET_VAL          0x7e06u //0111 1110 0000 0110 P11_1:alt4_in_TAUB0I13_110 P11_2:alt4_in_TAUB0I13_110    P11_10:alt2_out_PWGA50O_100    P11_11:alt2_out_PWGA51O_100
#define GPIO_PFCE11_RESET_VAL         0x0006u //0000 0000 0000 0110 P11_12:alt2_out_PWGA52O_100 P11_13:alt2_out_PWGA53O_100   P11_14:alt2_out_PWGA54O_100
#define GPIO_PFCAE11_RESET_VAL        0x0000u //0000 0000 0000 0000 P11_5:alt1_out_RLIN33TX_000   P11_6:alt1_in_RLIN33RX_000

#define GPIO_PFC12_RESET_VAL            0x0000u
#define GPIO_PFCE12_RESET_VAL           0x0000u                                       
#define GPIO_PFCAE12_RESET_VAL          0x0000u

#define GPIO_PFC18_RESET_VAL            0x0000u
#define GPIO_PFCE18_RESET_VAL           0x0000u                                       
#define GPIO_PFCAE18_RESET_VAL          0x0000u

#define GPIO_PFC20_RESET_VAL            0x0000u
#define GPIO_PFCE20_RESET_VAL           0x0000u                                       
#define GPIO_PFCAE20_RESET_VAL          0x0000u
  
#define GPIO_APFC0_RESET_VAL           0x0000u 
#define GPIO_APFCE0_RESET_VAL          0x0000u  
#define GPIO_APFCAE0_RESET_VAL         0x0000u 

#define GPIO_APFC1_RESET_VAL           0x0000u 
#define GPIO_APFCE1_RESET_VAL          0x0000u  
#define GPIO_APFCAE1_RESET_VAL         0x0000u

#define GPIO_JPFC0_RESET_VAL           0x0008u  
#define GPIO_JPFCE0_RESET_VAL          0x0000u 
#define GPIO_JPFCAE0_RESET_VAL         0x0000u   

  
/* Port Bidirection Control: 1= Bidirection */
#define GPIO_PBDC0_RESET_VAL      0x0000u   
#define GPIO_PBDC1_RESET_VAL      0x0000u   
#define GPIO_PBDC2_RESET_VAL      0x0000u   
#define GPIO_PBDC8_RESET_VAL      0x0000u
#define GPIO_PBDC9_RESET_VAL      0x0000u
#define GPIO_PBDC10_RESET_VAL     0x0000u
#define GPIO_PBDC11_RESET_VAL     0x0000u
#define GPIO_PBDC12_RESET_VAL     0x0000u
#define GPIO_PBDC18_RESET_VAL     0x0000u
#define GPIO_PBDC20_RESET_VAL     0x0000u
#define GPIO_APBDC0_RESET_VAL     0x0000u
#define GPIO_APBDC1_RESET_VAL     0x0000u
#define GPIO_JPBDC0_RESET_VAL     0x0000u 
 
/* PullUp Control: input mode.  1= internal pullup.
* Care that PUn.PUn_m=1 and PDn.PDn_m=1, then the real Pin is pulldown
*/
#define GPIO_PU0_RESET_VAL      0x0000u   
#define GPIO_PU1_RESET_VAL      0x0000u  
#define GPIO_PU2_RESET_VAL      0x0000u    
#define GPIO_PU8_RESET_VAL      0x0000u  
#define GPIO_PU9_RESET_VAL      0x0000u
#define GPIO_PU10_RESET_VAL     0x0000u
#define GPIO_PU11_RESET_VAL     0x0000u
#define GPIO_PU12_RESET_VAL     0x0000u
#define GPIO_PU18_RESET_VAL     0x0000u
#define GPIO_PU20_RESET_VAL     0x0000u
#define GPIO_JPU0_RESET_VAL     0x0000u
/*no Anolog*/

/* PullDown Control: input mode.  1= internal pulldown */
#define GPIO_PD0_RESET_VAL      0x0000u    
#define GPIO_PD1_RESET_VAL      0x0000u    
#define GPIO_PD2_RESET_VAL      0x0000u    
#define GPIO_PD8_RESET_VAL      0x0000u
#define GPIO_PD9_RESET_VAL      0x0000u
#define GPIO_PD10_RESET_VAL     0x0000u
#define GPIO_PD11_RESET_VAL     0x0000u
#define GPIO_PD12_RESET_VAL     0x0000u
#define GPIO_PD18_RESET_VAL     0x0000u
#define GPIO_PD20_RESET_VAL     0x0000u
#define GPIO_JPD0_RESET_VAL     0x0000u
/*no Anolog*/

/* Port Driver Strength: output mode. 0:<=10mhz, 1:<=40mhz
* 40MHZ pin select:P0_2,3,5,6,7,13,14  ; P10_ALL ;P11_0~7
*/
#define GPIO_PDSC0_RESET_VAL      0x000eu   
#define GPIO_PDSC1_RESET_VAL      0x0000u    
#define GPIO_PDSC2_RESET_VAL      0x0000u  
#define GPIO_PDSC8_RESET_VAL      0x0000u  
#define GPIO_PDSC9_RESET_VAL      0x0000u  
#define GPIO_PDSC10_RESET_VAL     0x0000u
#define GPIO_PDSC11_RESET_VAL     0x0000u
#define GPIO_PDSC12_RESET_VAL     0x0000u
#define GPIO_PDSC18_RESET_VAL     0x0000u
#define GPIO_PDSC20_RESET_VAL     0x0000u
/*no Jtag*/
/*no Anolog*/
 

/* Port open drain control: output mode. 0:push-pull, 1:open-drain*/
#define GPIO_PODC0_RESET_VAL      0x0000u   
#define GPIO_PODC1_RESET_VAL      0x0000u   
#define GPIO_PODC2_RESET_VAL      0x0000u   
#define GPIO_PODC8_RESET_VAL      0x0000u  
#define GPIO_PODC9_RESET_VAL      0x0000u
#define GPIO_PODC10_RESET_VAL     0x0000u
#define GPIO_PODC11_RESET_VAL     0x0000u
#define GPIO_PODC12_RESET_VAL     0x0000u
#define GPIO_PODC18_RESET_VAL     0x0000u
#define GPIO_PODC20_RESET_VAL     0x0000u
#define GPIO_JPODC0_RESET_VAL     0x0000u
/*no Anolog*/

/* Set default for output pin */
#define GPIO_P0_RESET_VAL        0x0000u
#define GPIO_P1_RESET_VAL        0x0000u
#define GPIO_P2_RESET_VAL        0x0000u
#define GPIO_P8_RESET_VAL        0x0000u
#define GPIO_P9_RESET_VAL        0x0000u
#define GPIO_P10_RESET_VAL       0x0000u
#define GPIO_P11_RESET_VAL       0x0000u
#define GPIO_P12_RESET_VAL       0x0000u
#define GPIO_P18_RESET_VAL       0x0000u
#define GPIO_P20_RESET_VAL       0x0000u
#define GPIO_AP0_RESET_VAL       0x0000u
#define GPIO_AP1_RESET_VAL       0x0000u
#define GPIO_JP0_RESET_VAL       0x0000u


/*----------------------- GPIO STANDBY ---------------------------- */
/* PMC: 0=port mode 1=alternative */
#define GPIO_PMC0_STANDBY_VAL         0x0000u 
#define GPIO_PMC1_STANDBY_VAL         0x0000u 
#define GPIO_PMC2_STANDBY_VAL         0x0000u 
#define GPIO_PMC8_STANDBY_VAL         0x0000u
#define GPIO_PMC9_STANDBY_VAL         0x0000u 
#define GPIO_PMC10_STANDBY_VAL        0x0000u  
#define GPIO_PMC11_STANDBY_VAL        0x3C00u //0011 1100 0000 0000
#define GPIO_PMC12_STANDBY_VAL        0x0000u 
#define GPIO_PMC18_STANDBY_VAL        0x0000u 
#define GPIO_PMC20_STANDBY_VAL        0x0000u 
#define GPIO_JPMC0_STANDBY_VAL        0x0000u  
/*no Anolog*/
//#define GPIO_REG_NONE_VAL      0x0000u  /*none register*/ 

/* Port IP Control: IN alternative mode, mask PM.  1=unuse PM */
#define GPIO_PIPC0_STANDBY_VAL      0x0000u
#define GPIO_PIPC1_STANDBY_VAL      0x0000u
#define GPIO_PIPC2_STANDBY_VAL      0x0000u
#define GPIO_PIPC8_STANDBY_VAL      0x0000u
#define GPIO_PIPC9_STANDBY_VAL      0x0000u
#define GPIO_PIPC10_STANDBY_VAL     0x0000u
#define GPIO_PIPC11_STANDBY_VAL     0x0000u
#define GPIO_PIPC12_STANDBY_VAL     0x0000u
#define GPIO_PIPC18_STANDBY_VAL     0x0000u
#define GPIO_PIPC20_STANDBY_VAL     0x0000u
/*no Jtag*/
/*no Anolog*/

/* PM: 0=output 1=input */
#define GPIO_PM0_STANDBY_VAL          0xffffu 
#define GPIO_PM1_STANDBY_VAL          0xffffu 
#define GPIO_PM2_STANDBY_VAL          0xffffu 
#define GPIO_PM8_STANDBY_VAL          0xffffu 
#define GPIO_PM9_STANDBY_VAL          0xffffu
#define GPIO_PM10_STANDBY_VAL         0xffffu  
#define GPIO_PM11_STANDBY_VAL         0xc3ffu    //1100 0011 1111 1111
#define GPIO_PM12_STANDBY_VAL         0xffffu    
#define GPIO_PM18_STANDBY_VAL         0xffffu    
#define GPIO_PM20_STANDBY_VAL         0xffffu    
#define GPIO_APM0_STANDBY_VAL         0xffffu 
#define GPIO_APM1_STANDBY_VAL         0xffffu 
#define GPIO_JPM0_STANDBY_VAL         0xffffu  

/* Port InputBuffer Control: all 0,unused here */
#define GPIO_PIBC0_STANDBY_VAL          0x0000u  
#define GPIO_PIBC1_STANDBY_VAL          0x0000u  
#define GPIO_PIBC2_STANDBY_VAL          0x0000u  
#define GPIO_PIBC8_STANDBY_VAL          0x0000u 
#define GPIO_PIBC9_STANDBY_VAL          0x0000u
#define GPIO_PIBC10_STANDBY_VAL         0x0000u  
#define GPIO_PIBC11_STANDBY_VAL         0x0008u 
#define GPIO_PIBC12_STANDBY_VAL         0x0000u 
#define GPIO_PIBC18_STANDBY_VAL         0x0000u 
#define GPIO_PIBC20_STANDBY_VAL         0x0030u //0000 0000 0011 0000
#define GPIO_APIBC0_STANDBY_VAL         0x0000u  
#define GPIO_APIBC1_STANDBY_VAL         0x0000u  
#define GPIO_JPIBC0_STANDBY_VAL         0x0000u 
 

/* PFCAE,PFCE,PFC:IN alternative mode, select a alternative function in 0~4.
*  binary value [PFCAEn_m,PFCEn_m,PFCn_m]b  from 0~4  is a alternative function.
* PFC port:no register
* PFCE port:no register
*/
#define GPIO_PFC0_STANDBY_VAL            0x0000u 
#define GPIO_PFCE0_STANDBY_VAL           0x0000u
#define GPIO_PFCAE0_STANDBY_VAL          0x0000u 
                                           
#define GPIO_PFC1_STANDBY_VAL            0x0000u 
#define GPIO_PFCE1_STANDBY_VAL           0x0000u
#define GPIO_PFCAE1_STANDBY_VAL          0x0000u 
                                          
#define GPIO_PFC2_STANDBY_VAL            0x0000u 
#define GPIO_PFCE2_STANDBY_VAL           0x0000u
#define GPIO_PFCAE2_STANDBY_VAL          0x0000u 
                                          
#define GPIO_PFC8_STANDBY_VAL            0x0000u  
#define GPIO_PFCE8_STANDBY_VAL           0x0000u 
#define GPIO_PFCAE8_STANDBY_VAL          0x0000u 

 
#define GPIO_PFC9_STANDBY_VAL            0x0000u 
#define GPIO_PFCE9_STANDBY_VAL           0x0000u 
#define GPIO_PFCAE9_STANDBY_VAL          0x0000u

#define GPIO_PFC10_STANDBY_VAL           0x0000u  
#define GPIO_PFCE10_STANDBY_VAL          0x0000u  
#define GPIO_PFCAE10_STANDBY_VAL         0x0000u 

#define GPIO_PFC11_STANDBY_VAL           0x3C00u //0011 1100 0000 0000
#define GPIO_PFCE11_STANDBY_VAL          0x0000u
#define GPIO_PFCAE11_STANDBY_VAL         0x0000u 

#define GPIO_PFC12_STANDBY_VAL           0x0000u
#define GPIO_PFCE12_STANDBY_VAL          0x0000u
#define GPIO_PFCAE12_STANDBY_VAL         0x0000u 

#define GPIO_PFC18_STANDBY_VAL           0x0000u
#define GPIO_PFCE18_STANDBY_VAL          0x0000u
#define GPIO_PFCAE18_STANDBY_VAL         0x0000u 

#define GPIO_PFC20_STANDBY_VAL           0x0000u
#define GPIO_PFCE20_STANDBY_VAL          0x0000u
#define GPIO_PFCAE20_STANDBY_VAL         0x0000u 

#define GPIO_APFC0_STANDBY_VAL           0x0000u 
#define GPIO_APFCE0_STANDBY_VAL          0x0000u
#define GPIO_APFCAE0_STANDBY_VAL         0x0000u 

#define GPIO_APFC1_STANDBY_VAL           0x0000u 
#define GPIO_APFCE1_STANDBY_VAL          0x0000u
#define GPIO_APFCAE1_STANDBY_VAL         0x0000u 

#define GPIO_JPFC0_STANDBY_VAL           0x0000u  
#define GPIO_JPFCE0_STANDBY_VAL          0x0000u 
#define GPIO_JPFCAE0_STANDBY_VAL         0x0000u  

 
/* Port Bidirection Control: 1= Bidirection */
#define GPIO_PBDC0_STANDBY_VAL      0x0000u     
#define GPIO_PBDC1_STANDBY_VAL      0x0000u     
#define GPIO_PBDC2_STANDBY_VAL      0x0000u     
#define GPIO_PBDC8_STANDBY_VAL      0x0000u
#define GPIO_PBDC9_STANDBY_VAL      0x0000u
#define GPIO_PBDC10_STANDBY_VAL     0x0000u
#define GPIO_PBDC11_STANDBY_VAL     0x0000u
#define GPIO_PBDC12_STANDBY_VAL     0x0000u
#define GPIO_PBDC18_STANDBY_VAL     0x0000u
#define GPIO_PBDC20_STANDBY_VAL     0x0000u
#define GPIO_APBDC0_STANDBY_VAL     0x0000u
#define GPIO_APBDC1_STANDBY_VAL     0x0000u
#define GPIO_JPBDC0_STANDBY_VAL     0x0000u
 
/* PullUp Control: input mode.  1= internal pullup.
* Care that PUn.PUn_m=1 and PDn.PDn_m=1, then the real Pin is pulldown
*/
#define GPIO_PU0_STANDBY_VAL      0x0000u    
#define GPIO_PU1_STANDBY_VAL      0x0000u    
#define GPIO_PU2_STANDBY_VAL      0x0000u    
#define GPIO_PU8_STANDBY_VAL      0x0000u
#define GPIO_PU9_STANDBY_VAL      0x0000u
#define GPIO_PU10_STANDBY_VAL     0x0000u
#define GPIO_PU11_STANDBY_VAL     0x0000u
#define GPIO_PU12_STANDBY_VAL     0x0000u
#define GPIO_PU18_STANDBY_VAL     0x0000u
#define GPIO_PU20_STANDBY_VAL     0x0000u
#define GPIO_JPU0_STANDBY_VAL     0x0000u

/*no Anolog*/

/* PullUp Control: input mode.  1= internal pulldown */
#define GPIO_PD0_STANDBY_VAL      0x0000u    
#define GPIO_PD1_STANDBY_VAL      0x0000u    
#define GPIO_PD2_STANDBY_VAL      0x0000u    
#define GPIO_PD8_STANDBY_VAL      0x0000u
#define GPIO_PD9_STANDBY_VAL      0x0000u
#define GPIO_PD10_STANDBY_VAL     0x0000u
#define GPIO_PD11_STANDBY_VAL     0x0000u
#define GPIO_PD12_STANDBY_VAL     0x0000u
#define GPIO_PD18_STANDBY_VAL     0x0000u
#define GPIO_PD20_STANDBY_VAL     0x0000u
#define GPIO_JPD0_STANDBY_VAL     0x0000u
/*no Anolog*/

/* Port Driver Strength: output mode. 0:<=10mhz, 1:<=40mhz
* 40MHZ pin select:no register
*/
#define GPIO_PDSC0_STANDBY_VAL     0x0000u    
#define GPIO_PDSC1_STANDBY_VAL     0x0000u    
#define GPIO_PDSC2_STANDBY_VAL     0x0000u    
#define GPIO_PDSC8_STANDBY_VAL     0x0000u  
#define GPIO_PDSC9_STANDBY_VAL     0x0000u  
#define GPIO_PDSC10_STANDBY_VAL    0x0000u
#define GPIO_PDSC11_STANDBY_VAL    0x0000u
#define GPIO_PDSC12_STANDBY_VAL    0x0000u
#define GPIO_PDSC18_STANDBY_VAL    0x0000u
#define GPIO_PDSC20_STANDBY_VAL    0x0000u
/*no Jtag*/
/*no Anolog*/

/* Port open drain control: output mode. 0:push-pull, 1:open-drain*/
#define GPIO_PODC0_STANDBY_VAL      0x0000u   
#define GPIO_PODC1_STANDBY_VAL      0x0000u   
#define GPIO_PODC2_STANDBY_VAL      0x0000u   
#define GPIO_PODC8_STANDBY_VAL      0x0000u   
#define GPIO_PODC9_STANDBY_VAL      0x0000u   
#define GPIO_PODC10_STANDBY_VAL     0x0000u   
#define GPIO_PODC11_STANDBY_VAL     0x0000u  
#define GPIO_PODC12_STANDBY_VAL     0x0000u  
#define GPIO_PODC18_STANDBY_VAL     0x0000u  
#define GPIO_PODC20_STANDBY_VAL     0x0000u  
#define GPIO_JPODC0_STANDBY_VAL     0x0000u   

/* Set default for output pin */
#define GPIO_P0_STANDBY_VAL        0x0000u
#define GPIO_P1_STANDBY_VAL        0x0000u
#define GPIO_P2_STANDBY_VAL        0x0000u
#define GPIO_P8_STANDBY_VAL        0x0000u
#define GPIO_P9_STANDBY_VAL        0x0000u
#define GPIO_P10_STANDBY_VAL       0x0000u
#define GPIO_P11_STANDBY_VAL       0x0000u
#define GPIO_P12_STANDBY_VAL       0x0000u
#define GPIO_P18_STANDBY_VAL       0x0000u
#define GPIO_P20_STANDBY_VAL       0x0000u
#define GPIO_AP0_STANDBY_VAL       0x0000u
#define GPIO_AP1_STANDBY_VAL       0x0000u
#define GPIO_JP0_STANDBY_VAL       0x0000u


#endif

 
#endif //_PIN_MAP_CC_H
/**************** END OF FILE *****************************************/



