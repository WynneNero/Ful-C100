/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.		       
*				  All Rights Reserved.                 
*   Department :  CT AD NKG      				     
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   : Functions in General Port Mode
***********************************************************************/
/*-History--------------------------------------------------------------
* Version  Date   	 Name        Changes and comments
------------------------------------------------------------------------
* 0.1	   Jun 26,2016   PEI Jingli  Initial version
------------------------------------------------------------------------
* 0.2	   Jun 29,2016   LIU Chenxi  Correct errors during merging	
------------------------------------------------------------------------
* 0.3	   July 07,2016  PEI Jingli  Adapt 64pin MCU
------------------------------------------------------------------------
* 0.4	   July 07,2016  LIU Chenxi  Refine macro definition.
------------------------------------------------------------------------
* 0.5	   July 21,2016  PEI Jingli  Update EXIT settings
------------------------------------------------------------------------
* 0.6	   Aug 10,2016  PEI Jingli  Modify PDSC,PODC interface
                               add APORT interface
*=====================================================================*/

//============================================================================
// Includes
//============================================================================
#include "config.h"
#include "GPIO_if.h"
#include "GPIO.h"
#include "define.h"
//#include "wpreg.h"
//#include "sys_assert_if.h"
//#include "IRQ.H"
#include "mcu_pin_cc.h"


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
 
#if (MCU_PIN == PIN100) 
 ,{GPIO_PORT_11,
   GPIO_PMC11_ACTIVE_VAL,  GPIO_PIPC11_ACTIVE_VAL,  GPIO_PM11_ACTIVE_VAL,  GPIO_PIBC11_ACTIVE_VAL, GPIO_PFC11_ACTIVE_VAL,   GPIO_PFCE11_ACTIVE_VAL, 
   GPIO_PFCAE11_ACTIVE_VAL,      GPIO_PBDC11_ACTIVE_VAL,  GPIO_PU11_ACTIVE_VAL,  GPIO_PD11_ACTIVE_VAL,  GPIO_PDSC11_ACTIVE_VAL,  GPIO_PODC11_ACTIVE_VAL, GPIO_P11_ACTIVE_VAL}
#endif
};


//INTP0~15 filter control register 
#define  GPIO_REG_FCLA0TLn_INTP_BASE		 ( (CPU_INT32U )0xFFC34020u)
#define  GPIO_REG_FCLA0TLn_INTP(n)           (*(CPU_REG08 *)(GPIO_REG_FCLA0TLn_INTP_BASE + (n)*4))

#if MCU_PIN ==PIN100
#define IS_VALID_PORT(port)    ( (port==GPIO_PORT_0)   \
                            ||(port>=GPIO_PORT_8)&&(port<=GPIO_PORT_11)   \
                            ||0)  //AP0 JP0

#define IS_VALID_INTP(pin)        ((pin<EXTI_NUM) && (EXTI_09!=pin)&&(EXTI_14!=pin)&&(EXTI_15 !=pin) )
#elif (MCU_PIN ==PIN64)
#define IS_VALID_PORT(port)    ( (port==GPIO_PORT_0)   \
                            ||(port>=GPIO_PORT_8)&&(port<=GPIO_PORT_10)   \
                            ||0)  //AP0 JP0

#define IS_VALID_INTP(pin)        ( ((EXTI_00<=pin) &&(pin<=EXTI_05)) ||(EXTI_10==pin) ||(EXTI_11==pin))

#else
NOTIFY_MACRO_DEFINITION_ERROR
//#define IS_VALID_PORT(port)  (port<GPIO_PORT_NUM)
//#define IS_VALID_INTP(pin)       (pin<EXTI_NUM)
#endif

/* port protection register related */
typedef struct
{
    GPIO_PORT_TYPE portNo;
    U32 PPCMDAddr;
    U32 PPROTSAddr;
}GPIO_PORT_PROTECT;

/*  relation of INTP channel and the INT  */
typedef struct{
  EXTI_TYPE  intp;
  U8  int_id;
}ST_INTP_INTID;

const GPIO_PORT_PROTECT PPRegAddr[]=
{
{GPIO_PORT_0,   0xFFC14C00, 0xFFC14B00},
{GPIO_PORT_1,   0xFFC14C04, 0xFFC14B04},
{GPIO_PORT_2,   0xFFC14C08, 0xFFC14B08},
{GPIO_PORT_8,   0xFFC14C20, 0xFFC14B20},
{GPIO_PORT_9,   0xFFC14C24, 0xFFC14B24},
{GPIO_PORT_10,  0xFFC14C28, 0xFFC14B28},
{GPIO_PORT_11,  0xFFC14C2C, 0xFFC14B2C},
{GPIO_PORT_12,  0xFFC14C30, 0xFFC14B30},

#if((MCU_PIN>PIN100)&&(MCU_PIN<PIN176))
{GPIO_PORT_18, 0xFFC14C48, 0xFFC14B48},
#endif

#if(MCU_PIN==PIN176)
{GPIO_PORT_20, 0xFFC14C50, 0xFFC14B50},
#endif
{GPIO_PORT_NUM, 0, 0}
};

#if 0
/* table of TAU channel and the INT  */
const ST_INTP_INTID Intp_INT_Table[EXTI_NUM]=
{
  {EXTI_00, INTP0}
 ,{EXTI_01, INTP1}
 ,{EXTI_02, INTP2}
 ,{EXTI_03, INTP3}
 ,{EXTI_04, INTP4}
 ,{EXTI_05, INTP5}
 
 #if MCU_PIN<=PIN64
 ,{EXTI_06, IRQ_INT_ID_MAX} //invalid
 ,{EXTI_07, IRQ_INT_ID_MAX}
 ,{EXTI_08, IRQ_INT_ID_MAX}
#else
 ,{EXTI_06, INTP6}
 ,{EXTI_07, INTP7}
 ,{EXTI_08, INTP8}
#endif

#if MCU_PIN<=PIN100
 ,{EXTI_09, IRQ_INT_ID_MAX}
#else
,{EXTI_09, INTP9}
#endif

 ,{EXTI_10, INTP10}
 ,{EXTI_11, INTP11}
 
#if MCU_PIN<=PIN64
 ,{EXTI_12, IRQ_INT_ID_MAX}
#else
 ,{EXTI_12, INTP12}
#endif
#if MCU_PIN<=PIN80
 ,{EXTI_13, IRQ_INT_ID_MAX}
#else
 ,{EXTI_13, INTP13}
#endif

#if MCU_PIN<=PIN100
  ,{EXTI_14, IRQ_INT_ID_MAX}
  ,{EXTI_15, IRQ_INT_ID_MAX}
#else
 ,{EXTI_14, INTP14}
 ,{EXTI_15, INTP15}
#endif
};
#endif

U32 GetPortPCRegAddress(U8 port);
U32 GetPortPSRegAddress(U8 port);
BOOL SetPODC_pin(U8 port, U8 pin,BOOL isOpenDrain);
BOOL SetPDSC_pin(U8 port, U8 pin,BOOL isHigh);


/***********************************************************************
*  Name        : GetPortPCRegAddress
*  Description :  get port protection command address
*  Parameter   : None
*  Returns     : None
***********************************************************************/
U32 GetPortPCRegAddress(U8 port)
{
    U32 Address =0;
	U8 index=0;
	while(PPRegAddr[index].PPCMDAddr)
	{
		if(PPRegAddr[index].portNo==port)
		{
			Address=PPRegAddr[index].PPCMDAddr;
			break;
		}
		index++;
	}
	
	return Address;
}

//get port protection status reg address
U32 GetPortPSRegAddress(U8 port)
{
  U32 Address =0;
	U8 index=0;
	while(PPRegAddr[index].PPROTSAddr)
	{
		if(PPRegAddr[index].portNo==port)
		{
			Address=PPRegAddr[index].PPROTSAddr;
			break;
		}
		index++;
	}
	
	return Address;
}

/***********************************************************************
*  Name        : GPIO_SetInPinMode
*  Description : set a input pin of PORT mode
*  Parameter   : Mode  E_NO_MODE, E_PLLUP, E_PLLDOWN
*                    isEnableBuffer input buff enable
*  Returns     : when disable in-buff,what happen ?
***********************************************************************/
extern void GPIO_SetInMode( U8 port, U8 pin, GPIO_INOUT_TYPE Mode, BOOL isEnableBuffer)
{
//  CPU_SR_ALLOC();
//  CPU_CRITICAL_ENTER();
  assert_param((E_PLLUP==Mode)||(E_PLLDOWN==Mode)||(E_NO_MODE==Mode));
  
    if(AP_PORT_0 == port)
    {
        APPORT_SetInMode(port, pin, isEnableBuffer);
        return ;
    }
  //In port mode input buffer must be enabled
    PORT_REG_PIBC(port)|=(1<<pin);
  
  switch(Mode)
  {
  	case E_PLLUP:
	  {
	      PORT_REG_PU(port)|=(1<<pin);
		PORT_REG_PD(port)&=(~(1<<pin));
		break;
	  }
  	case E_PLLDOWN:
	  {
	      PORT_REG_PD(port)|=(1<<pin);
		PORT_REG_PU(port)&=(~(1<<pin));
		break;
	  }     
	case E_NO_MODE:
    default:
		  PORT_REG_PU(port)&=(~(1<<pin));
		  PORT_REG_PD(port)&=(~(1<<pin));
		break;
  }
  PORT_REG_PMC(port) &=(U16)(~(1<<pin));
  PORT_REG_PM(port) |= (U16)(1<<pin);
	
//  CPU_CRITICAL_EXIT();         
}

/***********************************************************************
*  Name        : GPIO_SetOutPinMode
*  Description : set a output pin of PORT mode
*  Parameter   : 
*  Returns     : 
***********************************************************************/
void GPIO_SetOutMode( U8 port, U8 pin,  GPIO_INOUT_TYPE Mode, GPIO_DRIVSTRH drvStrgth )
{
  //  CPU_SR_ALLOC();
  //  CPU_CRITICAL_ENTER();
    if(AP_PORT_0 == port)
    {
        APPORT_SetOutMode(port, pin);
        return ;
    }
 
  if(Mode==E_OPEN_DRAIN ) //out type
  {
    SetPODC_pin(port, pin, TRUE );
  }
  else// if(Mode==E_PUSH_PULL)
  {
    SetPODC_pin(port, pin, FALSE);
  }   

  if(drvStrgth==E_HIGH_40MHZ) //speed
	  SetPDSC_pin(port,pin,TRUE);
	else
	  SetPDSC_pin(port,pin,FALSE);

	PORT_REG_PMC(port)&=(U16)(~(1<<pin));			//0-port, 1- alternate mode
	PORT_REG_PM(port)&=(U16)(~(1<<pin));			//0-OUTPUT

//  CPU_CRITICAL_EXIT();         
}

/***********************************************************************
*  Name        : GPIO_SetAlterMode
*  Description : set alternative mode
*  Parameter   : AlterMode:  function 1~5
*               isDirectIO: TRUE,  pipc=0 deirect IO
*                   FALSE,then input/output Mode is used.
*               Mode when isDirectIO is FALSE, 
*                   input mode can be E_NO_MODE, E_PLLUP, E_PLLDOWN
*                   output mode can be E_PUSH_PULL,E_OPEN_DRAIN
*   input buffer need ?
*  Returns     : 
***********************************************************************/
void GPIO_SetAlterMode( U8 port, U8 pin,  GPIO_ALTERMODE AlterMode, BOOL isDirectIO, GPIO_INOUT_TYPE Mode )
{
 // CPU_SR_ALLOC();
 // CPU_CRITICAL_ENTER();
   
  PORT_REG_PMC(port)|=(1<<pin); //alernativ mode
  if(isDirectIO)
  {
    PORT_REG_PIPC(port)|=(1<<pin); 
  }
  else
  {
    PORT_REG_PIPC(port)&=(~(1<<pin)); 

     switch(Mode)
     {
       case E_PLLUP:
         PORT_REG_PU(port)|=(1<<pin);
         PORT_REG_PD(port)&=(~(1<<pin));
         PORT_REG_PM(port) |= (U16)(1<<pin);
       break;
       case E_PLLDOWN:
         PORT_REG_PD(port)|=(1<<pin);
         PORT_REG_PU(port)&=(~(1<<pin));
         PORT_REG_PM(port) |= (U16)(1<<pin);
       break;
       case E_PUSH_PULL:
         SetPODC_pin(port, pin, FALSE);
         PORT_REG_PM(port) &= ~(U16)(1<<pin);
       break;
       case E_OPEN_DRAIN:
         SetPODC_pin(port, pin, TRUE);
         PORT_REG_PM(port) &=~ (U16)(1<<pin);
       break;
       case E_NO_MODE:
         PORT_REG_PU(port)&=(~(1<<pin));
         PORT_REG_PD(port)&=(~(1<<pin));
         PORT_REG_PM(port) |= (U16)(1<<pin);
       default:
       break;
     }
  }
  if(AlterMode &0x01)
    PORT_REG_PFC(port)|=(1<<pin);
  else
    PORT_REG_PFC(port)&=~(1<<pin);
  if(port==GPIO_PORT_0 ||port==GPIO_PORT_8 ||port==GPIO_PORT_9
   ||port==GPIO_PORT_10 ||port==GPIO_PORT_11 ||port==GPIO_PORT_12 )
  {
    if(AlterMode &0x02)
      PORT_REG_PFCE(port)|=(1<<pin);
    else
      PORT_REG_PFCE(port)&=~(1<<pin);
  }
  if(port==GPIO_PORT_0 ||port==GPIO_PORT_10 ||port==GPIO_PORT_11)
  {
    if(AlterMode &0x04)
      PORT_REG_PFCAE(port)|=(1<<pin);
    else
      PORT_REG_PFCAE(port)&=~(1<<pin);
  }
//  CPU_CRITICAL_EXIT();         

}

/***********************************************************************
*  Name        : GPIO_In_Read
*  Description : get the GPIO Pin level value
*  Parameter   : 
                 pin can select   GPIO_PIN_0 ~ GPIO_PIN_15
*  Returns     : can be input level of pin or output level from Pn,
               also used to Alternativ funcs
***********************************************************************/
U8 GPIO_In_Read( U8 port, U8 pin )
{    
  U8 Ret=0;
//  CPU_SR_ALLOC();
//  CPU_CRITICAL_ENTER();  
    if(AP_PORT_0 == port)
    {
        return APPORT_In_Read(port, pin);
    }
  Ret=(U8)((PORT_REG_PPR(port)&((U16)(1<<pin)))>>pin);
//  CPU_CRITICAL_EXIT();  

  return Ret;
}

/***********************************************************************
*  Name        : GPIO_Out_Write
*  Description : Set value of the GPIO Pin
*  Parameter   :                
*  Returns     : None
***********************************************************************/
void GPIO_Out_Write( U8 port, U8 pin, BOOL isHlevel)
{
//    CPU_SR_ALLOC();
//    CPU_CRITICAL_ENTER();
    if(AP_PORT_0 == port)
    {
        APPORT_Out_Write(port, pin, isHlevel);
	    return ;
    }
    if(isHlevel)
        PORT_REG_P(port)=(PORT_REG_P(port)|((U16)(1<<pin)));
    else
        PORT_REG_P(port)=(PORT_REG_P(port)&(~((U16)(1<<pin))));
//      CPU_CRITICAL_EXIT();
}

/***********************************************************************
*  Name        : Prot_SetPODC
*  Description : set open-drain output  for port_pin
*  Parameter   : 
*  Returns     : 
***********************************************************************/
//open drain for PORT
BOOL PORT_SetPODC(U8 port,  U32 OpenDrain)
{
    U32 addr=GetPortPCRegAddress(port);
    if(!addr)
      return FALSE;
    do
    {
      (*( CPU_REG32*)addr)=(U32)PROTCMD_WRITE_EN_VAL;
        PORT_REG_PODC(port)   = OpenDrain;
        PORT_REG_PODC(port)   = (U32)(~OpenDrain);
        PORT_REG_PODC(port)   = OpenDrain;
        
      addr=GetPortPSRegAddress(port);
      //    CPU_CRITICAL_EXIT();      
    }while( 0x01&(*( CPU_REG32*)addr));
      
    return TRUE;      
}

BOOL JPORT_SetPODC(U8 port,  U32 OpenDrain)
{
	U32 addr= 0xFFC204C0u;

    do
    {
      (*( CPU_REG32*)addr)=PROTCMD_WRITE_EN_VAL;
      JPORT_REG_JPODC0   = OpenDrain;
      JPORT_REG_JPODC0   = (U32)(~OpenDrain);
      JPORT_REG_JPODC0   = OpenDrain;
        
      addr=0xFFC204B0;
    }while( 0x01&(*( CPU_REG32*)addr));

    return TRUE;     
}

BOOL PORT_SetPDSC(U8 port,  U32 pdscval)
{
    U32 addr=GetPortPCRegAddress(port);
      
    if(GPIO_PORT_8==port ||GPIO_PORT_9==port) //no this register
      return FALSE;
    
    if(!addr)
        return FALSE;
      
    do
    {
      (*( CPU_REG32*)addr)=(U32)PROTCMD_WRITE_EN_VAL;
      PORT_REG_PDSC(port)   = pdscval;
      PORT_REG_PDSC(port)   = (U32)(~pdscval);
      PORT_REG_PDSC(port)   = pdscval;
      
      addr=GetPortPSRegAddress(port);
    }while( 0x01&(*( CPU_REG32*)addr));

    return TRUE;
}

/***********************************************************************
*  Name        : SetPODC_pin
*  Description : set Drive strength as high 40M or low 10M 
*  Parameter   : 
*  Returns     : 
***********************************************************************/
BOOL SetPODC_pin(U8 port, U8 pin, BOOL isOpenDrain)
{
    U32 regdata=0;
    U32 addr=GetPortPCRegAddress(port);
    if(!addr)
      return FALSE;
	
//    CPU_SR_ALLOC();
//    CPU_CRITICAL_ENTER();

    (*( CPU_REG32*)addr)=PROTCMD_WRITE_EN_VAL;
    if(isOpenDrain==TRUE)
    {
      regdata = (PORT_REG_PODC(port) | (1<<pin));
    }
    else
    {
      regdata = (PORT_REG_PODC(port)&( ~(1<<pin)));
    }

    do
    {
      PORT_REG_PODC(port)   = regdata;
      PORT_REG_PODC(port)   = (U32)(~regdata);
      PORT_REG_PODC(port)   = regdata;
  	  
  	addr=GetPortPSRegAddress(port);
    //    CPU_CRITICAL_EXIT();      
    }while( 0x01&(*( CPU_REG32*)addr));
		
    return TRUE;		
}
BOOL SetPDSC_pin(U8 port, U8 pin,BOOL isHigh)
{
    U32 regdata=0;
	  U32 addr=GetPortPCRegAddress(port);
		if(!addr)
			return FALSE;
		
    (*( CPU_REG32*)(addr))=PROTCMD_WRITE_EN_VAL;
    if(!isHigh)
    {
      regdata = (PORT_REG_PDSC(port)&( ~(1<<pin)));
    }
    else
    {
      regdata = (PORT_REG_PDSC(port) | (1<<pin));
    }
    do
    {
      PORT_REG_PDSC(port)   = regdata;
      PORT_REG_PDSC(port)   = (U32)(~regdata);
      PORT_REG_PDSC(port)   = regdata;
		
	  addr=GetPortPSRegAddress(port);
    }while( 0x01&(*( CPU_REG32*)addr));
		
    return TRUE;		
}

/***********************************************************************
*  Name        : APPORT_SetInMode
*  Description : set a input pin of AP0/AP1 mode
*  Parameter   : isEnableBuffer:input buff enable
*  Returns     : when disable in-buff,what happen ?
***********************************************************************/
void APPORT_SetInMode(U8 port, U8 pin, BOOL isEnableBuffer)
{
    //In port mode,input buffer must be enabled
    //if(isEnableBuffer) 
    {
        APORT_REG_APIBC(port - AP_PORT_0)|=(1<<pin);
    }
    APORT_REG_APM(port - AP_PORT_0) |= (U16)(1<<pin);
}

/***********************************************************************
*  Name        : APPORT_SetOutMode
*  Description : set a output pin of AP0/AP1 mode
*  Parameter   : 
*  Returns     : 
***********************************************************************/
void APPORT_SetOutMode(U8 port, U8 pin)
{
    APORT_REG_APM(port - AP_PORT_0)&=(U16)(~(1<<pin));			//0-OUTPUT
}


/***********************************************************************
*  Name        : APPORT_In_Read
*  Description : get the AP0/AP1 Pin level value
*  Parameter   : 
                 pin can select   AP0 ~ AP15
*  Returns     : can be input level of pin or output level from Pn,
               also used to Alternativ funcs
***********************************************************************/
U8 APPORT_In_Read( U8 port, U8 pin )
{    
  U8 Ret=0;
  
  Ret=(U8)((APORT_REG_PPR(port - AP_PORT_0)&((U16)(1<<pin)))>>pin);

  return Ret;
}

/***********************************************************************
*  Name        : APPORT_Out_Write
*  Description : Set value of the AP0/AP1 Pin
*  Parameter   :                
*  Returns     : None
***********************************************************************/
void APPORT_Out_Write( U8 port, U8 pin, BOOL isHlevel)
{
    if(isHlevel)
    {
        APORT_REG_P(port - AP_PORT_0)=(APORT_REG_P(port - AP_PORT_0)|((U16)(1<<pin)));
    }
    else
    {
        APORT_REG_P(port - AP_PORT_0)=(APORT_REG_P(port - AP_PORT_0)&(~((U16)(1<<pin))));
    }
}

/***********************************************************************
*  Name        : GPIO_SetOpenDrain_Port
*  Description : set open-drain output  for all pin of a port
*  Parameter   : OpenDrain  Set the bit to 1,40MHZ speed enabled. 
*                                           If 0,10MHZ speed enabled
*  Returns     : None
***********************************************************************/
void GPIO_SetDriverStrengthDrain_Port(U8 port, U32 pdscval)
{
    U32 protCmd = GetPortPCRegAddress(port);
    U32 protStatus = GetPortPSRegAddress(port);
    if(protCmd &&(GPIO_PORT_8!=port) &&(GPIO_PORT_9!=port)) /*no this register*/
    {
        PROTECTED_WRITE((*( CPU_REG32*)protCmd), (*( CPU_REG32*)protStatus), PORT_REG_PDSC(port), pdscval);
    }
}

/***********************************************************************
*  Name        : GPIO_SetOpenDrain_Port
*  Description : set open-drain output  for all pin of a port
*  Parameter   : OpenDrain  Set the bit to 1,open-drain mode enabled. 
*                                           If 0,push-pull mode enabled
*  Returns     : None
***********************************************************************/
void GPIO_SetOpenDrain_Port(U8 port,  U32 OpenDrain)
{
    U32 protCmd = GetPortPCRegAddress(port);
    U32 protStatus = GetPortPSRegAddress(port);
	
    if(protCmd)
    {
        if(AP_PORT_0 >port)
        {
            PROTECTED_WRITE((*( CPU_REG32*)protCmd), (*( CPU_REG32*)protStatus), PORT_REG_PODC(port), OpenDrain);
        }
        else if(JP_PORT_0<=port)
        {
          	PROTECTED_WRITE((*( CPU_REG32*)protCmd), (*( CPU_REG32*)protStatus), JPORT_REG_JPODC(port-JP_PORT_0), OpenDrain);
        }
    }
}



/* IO configration of General Ports,except for APort andJPort. */
void McuIoInit2GeneralPort(const MCU_PORT_REGVAL *pReglist)
{
    U8 index = 0;
	
    if(NULL == pReglist)
    {
        /* Error handle*/
    }
    else
    {
        while(index < MCU_PORT_NUM)
        {
            /* initialization */
            PORT_REG_PIBC(pReglist->portNo) = 0;
            PORT_REG_PBDC(pReglist->portNo) = 0;
            PORT_REG_PM(pReglist->portNo) = 0xFFFF;
            PORT_REG_PMC(pReglist->portNo) = 0;
            PORT_REG_PIPC(pReglist->portNo) = 0;
            /* set port filers.not do here */    
            
            /* GPIO to be use as I/O of Peripheral */
            PORT_REG_PBDC(pReglist->portNo) = (pReglist)->pbdc;
            PORT_REG_PU(pReglist->portNo) = (pReglist)->pu;
            PORT_REG_PD(pReglist->portNo) = (pReglist)->pd;
            if((pReglist->portNo!= (U8)GPIO_PORT_8) && (pReglist->portNo!= (U8)GPIO_PORT_9) )
            	GPIO_SetDriverStrengthDrain_Port( pReglist->portNo , (U32)(pReglist->pdsc));
            GPIO_SetOpenDrain_Port((U8)(pReglist->portNo), (U32) (pReglist->podc));
            
            PORT_REG_PFC(pReglist->portNo)  = pReglist->pfc;
            PORT_REG_PFCE(pReglist->portNo) = pReglist->pfce;
            if((pReglist->portNo== (U8)GPIO_PORT_0) || (pReglist->portNo== (U8)GPIO_PORT_10) ||(pReglist->portNo== (U8)GPIO_PORT_11))
              	PORT_REG_PFCAE(pReglist->portNo) = pReglist->pfcae;
            PORT_REG_PIPC(pReglist->portNo) = pReglist->pipc;
            /*TODO pn*/
            PORT_REG_PMC(pReglist->portNo) = pReglist->pmc;
            PORT_REG_PM(pReglist->portNo)  = pReglist->pm;
            PORT_REG_PIBC(pReglist->portNo) = pReglist->pibc;
            PORT_REG_P(pReglist->portNo) = pReglist->p;
            pReglist++;
            index++;
        }
    }
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

    /* APort */
    APORT_REG_APBDC(0u)=GPIO_APBDC0_ACTIVE_VAL;
    APORT_REG_APM(0u)    =GPIO_APM0_ACTIVE_VAL;
    APORT_REG_APIBC(0u) =GPIO_APIBC0_ACTIVE_VAL;
    APORT_REG_P(0u) =GPIO_AP0_ACTIVE_VAL;
}

#if 0
/***********************************************************************
*  Name        : EXTI_Config
*  Description : INTP configration
*  Parameter   : exti_x can  select EXTI_00 ~ EXTI_15
                         exti_trigger  can select EXTI_TRIGGER_LOW  EXTI_TRIGGER_HIGH
                                        EXTI_TRIGGER_RISING EXTI_TRIGGER_FALLING
*  Returns     : None
***********************************************************************/
void EXTI_Config( EXTI_TYPE intp, EXTI_TRIGGER_TYPE exti_trigger )
{
   
    /* select trigger mode */
    U8 trig=0 ;
    U8 temp=0;
    assert_param(IS_VALID_INTP(intp) );
    assert_param(IS_RANGE(exti_trigger,EXTI_TRIGGER_LOW,EXTI_TRIGGER_RISFALL) );

    
    while(temp<EXTI_NUM) //get interruput ID
    {
      if(Intp_INT_Table[temp].intp==intp)
        break;
      temp++;
    }
    if(temp>=EXTI_NUM)
    { // TODO ERROR
    }
    temp=Intp_INT_Table[temp].int_id;

    if(EXTI_TRIGGER_LOW==exti_trigger)
      trig= 0x04; // 100 
    else if(EXTI_TRIGGER_HIGH==exti_trigger)
      trig= 0x05; // 101
    else if(EXTI_TRIGGER_RISING==exti_trigger)
      trig= 0x01; // 001
    else if(EXTI_TRIGGER_FALLING==exti_trigger)
      trig= 0x02; 
    else// if(EXTI_TRIGGER_RISFALL==exti_trigger)
      trig= 0x03; 
    IRQ_IntDis(temp);  //disable interrupt
    IRQ_IntClr (temp);

    /*  FCLA0TLn_INTP
    * bit[2]:  0 edge dect     1 level detect
    * bit[1]:  when edge  0 =Falling edge disabled   1=  Falling edge is enabled
    * bit[0]:  when edge, 0 =Raising edge disabled  1=  Raising edge is enabled
    *             when level edge dect,   0= low level  1= high level
    */
    GPIO_REG_FCLA0TLn_INTP(intp)= trig;

//    IRQ_IntEn(temp);  

}

/***********************************************************************
*  Name        : EXTI_Cmd
*  Description : Set GPIO Pin  as a Input pin
*  Parameter   : exti_x can  select EXTI_00 ~ EXTI_15
                 state :ENABLE / DISABLE
*  Returns     : None
***********************************************************************/
void EXTI_Cmd( EXTI_TYPE intp, FUNCTION_STATE state )
{
    U8 temp=0;
    assert_param(IS_VALID_INTP(intp) );
  
    while(temp<EXTI_NUM) //get interruput ID
    {
      if(Intp_INT_Table[temp].intp==intp)
        break;
      temp++;
    }
    if(temp>=EXTI_NUM)
    { // TODO ERROR
    }
    temp=Intp_INT_Table[temp].int_id;
    
    if( state != DISABLE )
    {
      IRQ_IntEn(temp);  
    }
    else
    {
      IRQ_IntDis(temp);
      IRQ_IntClr (temp);
    }
}

/***********************************************************************
*  Name        : EXTI_Flag_Clear
*  Description : clear interruput flag
*  Parameter   : intp can  select EXTI_00 ~ EXTI_15
*  Returns     : None
***********************************************************************/
__inline EXTI_Flag_Clear( EXTI_TYPE intp )
{
    U8 temp=0;
    assert_param(IS_VALID_INTP(intp) );

    while(temp<EXTI_NUM) //get interruput ID
    {
      if(Intp_INT_Table[temp].intp==intp)
        break;
      temp++;
    }
    if(temp>=EXTI_NUM)
    { // TODO ERROR
    }
    temp=Intp_INT_Table[temp].int_id;

    IRQ_IntClr (temp);
}

void ISR_INTP11_Handler(void)
{
    if( mcu_intp_callback[EXTI_11] != NULL )
    {
      mcu_intp_callback[EXTI_11]();
    }
}
#endif
