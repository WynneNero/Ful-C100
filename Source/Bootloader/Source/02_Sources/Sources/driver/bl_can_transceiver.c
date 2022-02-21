/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the can transceiver.
 *
 *  \file       bl_can_transceiver.c
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    1.2.0
 *  \date       05/08/2013
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 17/03/2010 | he.yang          | N/A | BootDrv010001
 *      01.01.00 | 21/02/2011 | ning.chen        | N/A | BootDrv010002
 *      01.02.00 | 05/08/2013 | sijia.hao        | N/A | BootDrv010003
 *
 *****************************************************************************/
#include "bl_can_transceiver.h"
#include "bl_can_if_funcfg.h"
#include "bl_can_cfg.h"
#include "iodefine.h"
#include "Gpio_if.h"
#include "Gpio.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 277,303,602,781,1532,2100,2103,3112,3227,3453,4130 EOF*/
/*
 * 277:An integer constant expression with negative value is being converted
 * to an unsigned type.
 *
 * MISRA-C:2004 11.3(303):Cast a pointer to an integral type.
 * To address a register must cast an integral type to a pointer.
 *
 * MISRA-C:2004 20.2(602):The identifier is reserved for use by the library.
 * The Bootloader do not use any library funtion and use the underscores to
 * indicate that the function is a interal function.
 *
 * MISRA-C:2004 5.6(781):The identifier is used as a structure/union member.
 * The member of the structure is used through the structure object.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2100:Integral promotion : unsigned char promoted to signed int.
 *
 * 2103:Integral promotion, unsigned short promoted to unsigned int.
 * This message will therefore only be generated when a short and an int are of
 * equal size.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect. 
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 * MISRA-C:2004 12.7(4130):Bitwise operations on signed data will give
 * implementation defined results.
 *
 */

/*****************************************************************************
 *  Verify The Configurations of Macro
 *****************************************************************************/

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/
void ApplCanTransceiverInit(void);
void ApplCanTransceiverDeInit(void);

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
#if (CANIF_FUN_INIT_TRANSCEIVER == BL_FUN_ON)
/**************************************************************************//**
 *
 *  \details Initialize can transceiver.
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
void Cantrc_InitTransceiver(void)
{
    /*Can0 STB */

	
     //SBC_vReset();
     ApplCanTransceiverInit();
    
    return ; 
}

void ApplCanTransceiverInit(void)
{
#if CAN_CONTROLLER_USED == CAN_CONTROLLER_0    
	/* configure P11_15  WAKEUP */
	PORT_REG_PMC(GPIO_PORT_11) &= ~(1 << GPIO_PIN_F);  /* configure P11_15 as general IO WAKEUP */
	PORT_REG_PM (GPIO_PORT_11) &= ~(1 << GPIO_PIN_F); 	/* P11_15 Output pin */
    PORT_REG_P  (GPIO_PORT_11) |=  (1 << GPIO_PIN_F);   	/* disable the wake up pin in tranceiver */
	tm_delay_us(100);
	PORT_REG_P  (GPIO_PORT_11) &= ~(1 << GPIO_PIN_F);
	
    /* Configure EN  P12_1 */
    PORT_REG_PMC(GPIO_PORT_12) &= ~(1 << GPIO_PIN_1);  	/* configure P12_1 as general IO */
	PORT_REG_PM (GPIO_PORT_12) &= ~(1 << GPIO_PIN_1); 	/* P12_1 Output pin */
    PORT_REG_P  (GPIO_PORT_12) &= ~(1 << GPIO_PIN_1);    /* disable the EN pin in tranceiver */

    /* Configure STB pin P12_0 */ 
    PORT_REG_PMC(GPIO_PORT_12) &= ~(1 << GPIO_PIN_0); 	/* configure P12_0 as general IO */
   	PORT_REG_PM (GPIO_PORT_12) &= ~(1 << GPIO_PIN_0); 	/* P12_0 Output pin */
    PORT_REG_P  (GPIO_PORT_12) |=  (1 << GPIO_PIN_0);    /* Enable STB pin */

    /* the transceuver is in Pwon/Listen-only mode */
	/* Set CAN0TX as P10_1 and CAN0RX as P10_0*/
    PORT_REG_PMC(GPIO_PORT_10) |= (1 << GPIO_PIN_1)|(1 << GPIO_PIN_0); /* Alternative Functions  RXD:P10_0 TXD:P10_1  */                                                 

	PORT_REG_PFC(GPIO_PORT_10) |= (0x0003); 					/* PFC:1 */                                                 
	PORT_REG_PFCE(GPIO_PORT_10) &= ~(0x0003);					/*  PFCE:0 */ 
	PORT_REG_PFCAE(GPIO_PORT_10)&= ~(0x0003);                   /*  PFCAE:0 */   
	
    PORT_REG_PM (GPIO_PORT_10) &= ~(1 << GPIO_PIN_1);    	/* P10_1 CANTX     Output */                                              
    PORT_REG_PM (GPIO_PORT_10) |=  (1 << GPIO_PIN_0);  		/* P10_0 CANRX     Input */
	PORT_REG_P  (GPIO_PORT_10) |= 0x0003; 					/* set Tx/Rx port high level*/
    
    /* Enable CAN0 by setting P12_1 high EN */
    PORT_REG_P  (GPIO_PORT_12) |= (1 << GPIO_PIN_1); 
#elif CAN_CONTROLLER_USED == CAN_CONTROLLER_1
	/* Configure CAN1 WakeupPin */

	PORT_REG_PMC(GPIO_PORT_10) &= ~(1 << GPIO_PIN_A);  	/* configure P10_10 as general IO */
	PORT_REG_PM (GPIO_PORT_10) &= ~(1 << GPIO_PIN_A); 	/* P8_5 Output pin */
    PORT_REG_P  (GPIO_PORT_10) |=  (1 << GPIO_PIN_A);   	/* disable the wake up pin in tranceiver */
	tm_delay_us(100);
	PORT_REG_P  (GPIO_PORT_10) &= ~(1 << GPIO_PIN_A);
	
    /* Configure CAN1 EnablePin */
    PORT_REG_PMC(GPIO_PORT_10) &= ~(1 << GPIO_PIN_C);  	/* configure P8_1 as general IO */
	PORT_REG_PM (GPIO_PORT_10) &= ~(1 << GPIO_PIN_C); 	/* P8_1 Output pin */
    PORT_REG_P  (GPIO_PORT_10) &= ~(1 << GPIO_PIN_C);    /* disable the EN pin in tranceiver */

    /* Configure CAN1 GPIO-STB pin P10_11 */ 
    PORT_REG_PMC(GPIO_PORT_10) &= ~(1 << GPIO_PIN_B); 	/* configure P8_0 as general IO */
   	PORT_REG_PM (GPIO_PORT_10) &= ~(1 << GPIO_PIN_B); 	/* P8_0 Output pin */
    PORT_REG_P  (GPIO_PORT_10) |=  (1 << GPIO_PIN_B);    /* Enable STB pin */

    /* the transceuver is in Pwon/Listen-only mode */
	/* Set CAN1TX as P10_7 and CAN2RX as P10_6 */
    PORT_REG_PMC(GPIO_PORT_10) |= (1 << GPIO_PIN_7)|(1 << GPIO_PIN_6); /* Alternative Functions */    
	
    PORT_REG_PFC(GPIO_PORT_10) |= (0x00C0); 					/* PFC:1 */                                                 
	PORT_REG_PFCE(GPIO_PORT_10) |= (0x00C0);					/*  PFCE:1 */ 
	PORT_REG_PFCAE(GPIO_PORT_10)&= ~(0x00C0);                   /*  PFCAE:0 */ 
	
    PORT_REG_PM (GPIO_PORT_10) &= ~(1 << GPIO_PIN_7);    	/* P0_4 CANTX     Output */                                              
    PORT_REG_PM (GPIO_PORT_10) |=  (1 << GPIO_PIN_6);  		/* P0_5 CANRX     Input */
	PORT_REG_P  (GPIO_PORT_10) |= 0x00C0; 					/* set Tx/Rx port high level*/
    
    /* Enable CAN1 by setting P8_1 high */
    PORT_REG_P  (GPIO_PORT_10) |= (1 << GPIO_PIN_C); 
	/* the transceiver is in normal mode */
#elif CAN_CONTROLLER_USED == CAN_CONTROLLER_2
	PORT_REG_PMC(GPIO_PORT_8) &= ~(1 << GPIO_PIN_5);  	/* configure P8_5 as general IO */
	PORT_REG_PM (GPIO_PORT_8) &= ~(1 << GPIO_PIN_5); 	/* P8_5 Output pin */
    PORT_REG_P  (GPIO_PORT_8) |=  (1 << GPIO_PIN_5);   	/* disable the wake up pin in tranceiver */
	tm_delay_us(100);
	PORT_REG_P  (GPIO_PORT_8) &= ~(1 << GPIO_PIN_5);
	
    /* Configure CAN2 EnablePin */
    PORT_REG_PMC(GPIO_PORT_11) &= ~(1 << GPIO_PIN_4);  	/* configure P8_1 as general IO */
	PORT_REG_PM (GPIO_PORT_11) &= ~(1 << GPIO_PIN_4); 	/* P8_1 Output pin */
    PORT_REG_P  (GPIO_PORT_11) &= ~(1 << GPIO_PIN_4);    /* disable the EN pin in tranceiver */

    /* Configure CAN2 GPIO-STB pin P8_0 */ 
    PORT_REG_PMC(GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* configure P8_0 as general IO */
   	PORT_REG_PM (GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* P8_0 Output pin */
    PORT_REG_P  (GPIO_PORT_9) |=  (1 << GPIO_PIN_1);    /* Enable STB pin */

    /* the transceuver is in Pwon/Listen-only mode */
	/* Set CAN2TX as P0_4 and CAN2RX as P0_5 */
    PORT_REG_PMC(GPIO_PORT_0) |= (1 << GPIO_PIN_4)|(1 << GPIO_PIN_5); /* Alternative Functions */                                                 
    PORT_REG_PFC(GPIO_PORT_0) |= (0x0000); 					/* Alternative 1 */                                                     
    PORT_REG_PM (GPIO_PORT_0) &= ~(1 << GPIO_PIN_4);    	/* P0_4 CANTX     Output */                                              
    PORT_REG_PM (GPIO_PORT_0) |=  (1 << GPIO_PIN_5);  		/* P0_5 CANRX     Input */
	PORT_REG_P  (GPIO_PORT_0) |= 0x0030; 					/* set Tx/Rx port high level*/
    
    /* Enable CAN2 by setting P8_1 high */
    PORT_REG_P  (GPIO_PORT_11) |= (1 << GPIO_PIN_4); 
	/* the transceiver is in normal mode */
#elif CAN_CONTROLLER_USED == CAN_CONTROLLER_4
	PORT_REG_PMC(GPIO_PORT_8) &= ~(1 << GPIO_PIN_5);  	/* configure P8_5 as general IO */
	PORT_REG_PM (GPIO_PORT_8) &= ~(1 << GPIO_PIN_5); 	/* P8_5 Output pin */
    PORT_REG_P  (GPIO_PORT_8) |=  (1 << GPIO_PIN_5);   	/* disable the wake up pin in tranceiver */
	tm_delay_us(100);
	PORT_REG_P  (GPIO_PORT_8) &= ~(1 << GPIO_PIN_5);
	
    /* Configure CAN4 EnablePin */
    PORT_REG_PMC(GPIO_PORT_11) &= ~(1 << GPIO_PIN_4);  	/* configure P11_4 as general IO */
	PORT_REG_PM (GPIO_PORT_11) &= ~(1 << GPIO_PIN_4); 	/* P11_4 Output pin */
    PORT_REG_P  (GPIO_PORT_11) |=  (1 << GPIO_PIN_4);   /* disable the EN pin in tranceiver */

    /* Configure CAN4 GPIO-STB pin P9_1 */ 
    PORT_REG_PMC(GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* configure P9_1 as general IO */
   	PORT_REG_PM (GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* P9_1 Output pin */
    PORT_REG_P  (GPIO_PORT_9) |=  (1 << GPIO_PIN_1);    /* Enable STB pin */

    /* the transceuver is in Pwon/Listen-only mode */
	/* Set CAN2TX as P0_10 and CAN2RX as P0_9 */
    PORT_REG_PMC(GPIO_PORT_0)  |=  (1 << GPIO_PIN_9)|(1 << GPIO_PIN_A); 	/* Alternative Functions */                                                 
    PORT_REG_PFC(GPIO_PORT_0)  &= ~(0x0600); 					/* Alternative 5 */
	PORT_REG_PFCE(GPIO_PORT_0) &= ~(0x0600);
	PORT_REG_PFCAE(GPIO_PORT_0)|=  (0x0600);
    PORT_REG_PM(GPIO_PORT_0)   &= ~(1 << GPIO_PIN_A);    		/* P0_10 CANTX     Output */                                              
    PORT_REG_PM(GPIO_PORT_0)   |=  (1 << GPIO_PIN_9);  			/* P0_9  CANRX     Input */
	//PORT_REG_P(GPIO_PORT_0)    |=  (GPIO_PIN_9 | GPIO_PIN_A); 	/* set Tx/Rx port high level*/
    
    /* Enable CAN4 by setting P11_4 high */
    //PORT_REG_P(GPIO_PORT_11)   |= (1 << GPIO_PIN_4); 
	/* the transceiver is in normal mode */
#endif
}

void ApplCanTransceiverDeInit(void)
{
#if CAN_CONTROLLER_USED == CAN_CONTROLLER_0  
	/* Configure CAN0 GPIO-STB pin P0_4*/ 
	PORTPM0 &= ~(1<<4); /* configure P0_4 as general IO */
    PORTPM0 &= ~(1<<4); /* P0_4 Output pin */
    PORTP0 &= ~(1<<4);    /* Disable STB pin */
    /* The transceiver entry to sleep mode from normal mode */
#elif CAN_CONTROLLER_USED == CAN_CONTROLLER_2
    /* Configure CAN2 GPIO-STB pin P8_0*/ 
	PORT_REG_PMC(GPIO_PORT_8) &= ~(1 << GPIO_PIN_0); 	/* configure P8_0 as general IO */
    PORT_REG_PM (GPIO_PORT_8) &= ~(1 << GPIO_PIN_0); 	/* P8_0 Output pin */
    PORT_REG_P  (GPIO_PORT_8) &= ~(1 << GPIO_PIN_0);	/* Disable STB pin */
	/* The transceiver entry to sleep mode from normal mode */
#elif CAN_CONTROLLER_USED == CAN_CONTROLLER_4
    /* Configure CAN2 GPIO-STB pin P9_1*/ 
	PORT_REG_PMC(GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* configure P8_0 as general IO */
    PORT_REG_PM (GPIO_PORT_9) &= ~(1 << GPIO_PIN_1); 	/* P8_0 Output pin */
    PORT_REG_P  (GPIO_PORT_9) &= ~(1 << GPIO_PIN_1);	/* Disable STB pin */
	/* The transceiver entry to sleep mode from normal mode */
#endif
}

#endif

