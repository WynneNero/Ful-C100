/* -----------------------------------------------------------------------------
  Filename:    ccl_par.c
  Description: Toolversion: 02.03.11.01.70.09.79.00.00.00
               
               Serial Number: CBD1700979
               Customer Info: Huizhou Desay SV Automotive Co., Ltd.
                              Package: CBD_Vector_SLP2
                              Micro: R7F7016213AFP
                              Compiler: Green Hills 2015.1.7
               
               
               Generator Fwk   : GENy 
               Generator Module: Ccl__core
               
               Configuration   : D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\CBD1700979 D00 Rh850 GreenHills FAW C100 APA.gny
               
               ECU: 
                       TargetSystem: Hw_Rh850Cpu
                       Compiler:     GreenHills
                       Derivates:    F1K
               
               Channel "Channel0":
                       Databasefile: D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\AB02_979_C100_APA_PublicCAN_V0.1_20210609.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         APA
               Channel "Channel1":
                       Databasefile: D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\AB02_979_C100_ADV_PrivateCAN_V0.1_20210629.dbc
                       Bussystem:    CAN
                       Manufacturer: Vector
                       Node:         APA

 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2015 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

#define CCL_PAR_MODULE
#include "ccl_inc.h"
#include "ccl_par.h"

/******************************************************************************/
/* function external declaration                                              */
/******************************************************************************/



/******************************************************************************/
/* internal declarations (ROM const)                                          */
/******************************************************************************/
/******************************************************************************/
/* external declarations (ROM const)                                          */
/******************************************************************************/
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclNmWakeUpAble = 0x3;   /* The variable store the wake up able channels (one bit per channel). */
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclChannelWithoutNm = 0x2;
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclStartIndex[2] = {
    0
  , 1
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclStopIndex[2] = {
    0
  , 1
};
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclUserOffset[kCclNumberOfUser] = {
      0x0,   0x1,   0x0
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclUserMask[kCclNumberOfUser] = {
      0x1,   0x1,   0x2
};

V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 cclUserChannel[kCclNumberOfUser] = {
    0x0, 0x1, 0x0
};
/******************************************************************************/
/* global data definitions                                                    */
/******************************************************************************/
/***************************************************************************** 
| NAME:             CclInitPowerOnFct                                          
| PROTOTYPE:        void CclInitPowerOnFct( void )                             
| CALLED BY:        CclInitPowerOn                                             
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: void                                                       
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function is a generated init container function. It   
|                   contains different init routines depending on the          
|                   used modules.                                              
|*****************************************************************************/

void CclInitPowerOnFct(void)
{
  CanNm_InitMemory();
  #if defined(C_SINGLE_RECEIVE_CHANNEL) || defined(C_MULTIPLE_RECEIVE_CHANNEL)
    CanInitPowerOn();
  #else
    CanInitPowerOn(0);
  #endif
  IlInitPowerOn();
  Nm_Init(NULL_PTR);
  CanNm_Init(NULL_PTR);
  CbdWrpInit(0);
  CanOffline(1);
  CclCanStandby(1);
  TpInitPowerOn();
  DescInitPowerOn(kDescPowerOnInitParam);
}
/***************************************************************************** 
| NAME:             CclInitFct                                                 
| PROTOTYPE:        void CclInitFct_0( )                
| CALLED BY:        CclInit                                                    
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: void                                                       
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function is a generated init container function. It   
|                   contains different init routines depending on the          
|                   used modules.                                              
|*****************************************************************************/

void CclInitFct_0(void)
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  CanInit(0, 0);
#else
  CanInit(0);
#endif
  IlInit(0);
  Nm_Init(NULL_PTR);
  CanNm_Init(NULL_PTR);
  CbdWrpInit(0);
  ApplCclInit(0);
}


/***************************************************************************** 
| NAME:             CclInitFct                                                 
| PROTOTYPE:        void CclInitFct_1( )                
| CALLED BY:        CclInit                                                    
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: void                                                       
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function is a generated init container function. It   
|                   contains different init routines depending on the          
|                   used modules.                                              
|*****************************************************************************/

void CclInitFct_1(void)
{
#if defined( C_MULTIPLE_RECEIVE_CHANNEL )
  CanInit(1, 0);
#else
  CanInit(0);
#endif
  IlInit(1);
  CanOffline(1);
  CclCanStandby(1);
  ApplCclInit(1);
}

/*************************************************************************************
| NAME:             CclSystemShutdownFct_0                         
| PROTOTYPE:        void CclSystemShutdownFct_0( void )            
| CALLED BY:        CclSystemShutdown                                                 
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                 
| INPUT PARAMETERS: void                                                              
| RETURN VALUE:     void                                                              
| DESCRIPTION:      This function is a generated system shutdown container           
|                   function. It could be used to stop services or deinitialize       
|                   variables after the system leaves the "normal" mode.            
|************************************************************************************/

void CclSystemShutdownFct_0(void) 
{ 
}


/*************************************************************************************
| NAME:             CclSystemShutdownFct_1                         
| PROTOTYPE:        void CclSystemShutdownFct_1( void )            
| CALLED BY:        CclSystemShutdown                                                 
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                 
| INPUT PARAMETERS: void                                                              
| RETURN VALUE:     void                                                              
| DESCRIPTION:      This function is a generated system shutdown container           
|                   function. It could be used to stop services or deinitialize       
|                   variables after the system leaves the "normal" mode.            
|************************************************************************************/

void CclSystemShutdownFct_1(void) 
{ 
  ApplCclSleepTrcv(1);
}
/**********************************************************************************
| NAME:             CclPollingTask                                                 
| PROTOTYPE:        void CclPollingTask( void )                                    
| CALLED BY:        Application or operating system                                
| PRECONDITIONS:    looptime < callcycle                                           
| INPUT PARAMETERS: void                                                           
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function is a generated polling task container. It        
|                   contains different cyclic routines                             
|                   depending on the used modules.                                 
|*********************************************************************************/
void CCL_API_CALL_TYPE CclPollingTask (void)
{ 
  CanTask();
}

/****************************************************************************************
| NAME:             CclScheduleTask                                                      
| PROTOTYPE:        void CclScheduleTask                                                 
| CALLED BY:        task handler                                                         
| PRECONDITIONS:    has to be called every 10ms                                           
| INPUT PARAMETERS: void                                                                 
| RETURN VALUE:     void                                                                 
| DESCRIPTION:      This function is a generated schedule task. This task call all other 
|                   task with in the right task cycle + offset.                          
|***************************************************************************************/
void CCL_API_CALL_TYPE CclScheduleTask(void)
{ 
  IlTxTask(0);

  IlTxTask(1);

  IlRxTask(0);

  IlRxTask(1);

  CclTask();

  CanNm_MainFunction_0();

  CbdWrpTask(0);

   TpRxTask();

  DescTask();

   TpTxTask();



}

/******************************************************************************
| NAME:             CclComStart                                                
| PROTOTYPE:        void CclComStart(CanChannelHandle channel)              
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function start the communication with interaction layer.
|*****************************************************************************/
void CclComStart(CanChannelHandle channel)
{
  cclComSwState[channel]=kCclComSwOn;
  ApplCclComStart(channel);
    IlTxStart(channel);
  IlRxStart(channel);
}
/******************************************************************************
| NAME:             CclComStop                                                 
| PROTOTYPE:        void CclComStop(CanChannelHandle channel)                  
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function stop the communication with interaction layer.
|*****************************************************************************/
void CclComStop(CanChannelHandle channel)
{
  IlTxStop(channel);
  IlRxStop(channel);
  cclComSwState[channel]=kCclComSwOff;
  ApplCclComStop(channel);
}
/******************************************************************************
| NAME:             CclComWait                                                
| PROTOTYPE:        void CclComWait(CanChannelHandle channel)              
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function start the communication with interaction layer.
|*****************************************************************************/
void CclComWait(CanChannelHandle channel)
{
  cclComSwState[channel]=kCclComSwOff;
  ApplCclComWait(channel);
  IlTxWait(channel);
  IlRxWait(channel);
}
/******************************************************************************
| NAME:             CclComResume                                                 
| PROTOTYPE:        void CclComResume(CanChannelHandle channel)                  
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function stop the communication with interaction layer.
|*****************************************************************************/
void CclComResume(CanChannelHandle channel)
{
    IlTxRelease(channel);
  IlRxRelease(channel);
  cclComSwState[channel]=kCclComSwOn;
  ApplCclComResume(channel);
}






/******************************************************************************
| NAME:             CclBusOffStart                                             
| PROTOTYPE:        void CclBusOffStart(CanChannelHandle channel)              
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function stop the communication with interaction layer.
|*****************************************************************************/
void CclBusOffStart(CanChannelHandle channel)
{
  #if defined(CCL_ENABLE_STOP_TIMEOUT)
    //IlTxWait(channel);
    //IlRxWait(channel);
    IlTxStop(channel);
    IlRxStop(channel);
  #endif
  ApplCclBusOffStart(channel);
}
/******************************************************************************
| NAME:             CclBusOffEnd                                               
| PROTOTYPE:        void CclBusOffEnd(CanChannelHandle channel)                
| CALLED BY:        network management                                         
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!          
| INPUT PARAMETERS: channel                                                    
| RETURN VALUE:     void                                                       
| DESCRIPTION:      This function start the communication with interaction layer.
|*****************************************************************************/
void CclBusOffEnd(CanChannelHandle channel)
{
  #if defined( CCL_ENABLE_STOP_TIMEOUT)
    //IlTxRelease(channel);
    //IlRxRelease(channel);
	IlTxStart(channel);
	IlRxStart(channel);
  #endif
  ApplCclBusOffEnd(channel);
}

/**********************************************************************************
| NAME:             CclNmActiveReqFct_0                         
| PROTOTYPE:        vuint8 CclNmActiveReqFct_0( vuint8 network )
| CALLED BY:        CclTask                                                        
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: vunit8 network                                                 
| RETURN VALUE:     vuint8                                                         
| DESCRIPTION:      This function contains the algorithm to go in the active       
|                   mode. The algorithm depends on the used modules.               
|*********************************************************************************/

vuint8 CclNmActiveReqFct_0(vuint8 network)
{
#if defined V_ENABLE_USE_DUMMY_STATEMENT
  network = network;

#endif
  (void)Nm_NetworkRequest((NetworkHandleType)0);
  return NM_OK;
}


/**********************************************************************************
| NAME:             CclNmActiveReqFct_1                         
| PROTOTYPE:        vuint8 CclNmActiveReqFct_1( vuint8 network )
| CALLED BY:        CclTask                                                        
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: vunit8 network                                                 
| RETURN VALUE:     vuint8                                                         
| DESCRIPTION:      This function contains the algorithm to go in the active       
|                   mode. The algorithm depends on the used modules.               
|*********************************************************************************/

vuint8 CclNmActiveReqFct_1(vuint8 network)
{
  switch(cclNmState[1])
  {
    case kCclStateWaitBusSleep:
      CanOnline(1);
      CclComResume(1);
      break;
    case kCclNmStateSleep:
      CclCanNormal(1);
      CanOnline(1);
      CclComStart(1);
      break;
    default: /* nothing to do */
      break;
  }
  return NM_OK;
}
/**********************************************************************************
| NAME:             CclNmPrepareSleepReqFct_0                   
| PROTOTYPE:        void CclNmPrepareSleepReqFct_0( void )      
| CALLED BY:        CclTask                                                        
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: void                                                           
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function contains the algorithm to set the system in      
|                   prepare sleep mode. The algorithm depends on the used          
|                   modules.                                                       
|*********************************************************************************/

void CclNmPrepareSleepReqFct_0(void)
{
  (void)Nm_PassiveStartUp((NetworkHandleType)0);
}


/**********************************************************************************
| NAME:             CclNmPrepareSleepReqFct_1                   
| PROTOTYPE:        void CclNmPrepareSleepReqFct_1( void )      
| CALLED BY:        CclTask                                                        
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: void                                                           
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function contains the algorithm to set the system in      
|                   prepare sleep mode. The algorithm depends on the used          
|                   modules.                                                       
|*********************************************************************************/

void CclNmPrepareSleepReqFct_1(void)
{
  CclCanNormal(1);
  CanOnline(1);
  CclComStart(1);
}
/**********************************************************************************
| NAME:             CclNmSleepReqFct_0                          
| PROTOTYPE:        void CclNmSleepReqFct_0( vuint8 network )   
| CALLED BY:        CclRelNetRequest                                               
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: vuint8 network                                                 
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function contains the algorithm to go in the sleep        
|                   mode. The algorithm depends on the used modules.               
|*********************************************************************************/
void CclNmSleepReqFct_0(vuint8 network)
{
#if defined V_ENABLE_USE_DUMMY_STATEMENT
  network = network;

#endif
  (void)Nm_NetworkRelease((NetworkHandleType)0);
}


/**********************************************************************************
| NAME:             CclNmSleepReqFct_1                          
| PROTOTYPE:        void CclNmSleepReqFct_1( vuint8 network )   
| CALLED BY:        CclRelNetRequest                                               
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!              
| INPUT PARAMETERS: vuint8 network                                                 
| RETURN VALUE:     void                                                           
| DESCRIPTION:      This function contains the algorithm to go in the sleep        
|                   mode. The algorithm depends on the used modules.               
|*********************************************************************************/
void CclNmSleepReqFct_1(vuint8 network)
{
  network = network;

}





/********************************************************************************
| NAME:             CclInitTrcvFct_0                         
| PROTOTYPE:        void CclInitTrcvFct_0( void )            
| CALLED BY:        CclInitPortsPowerOn                                          
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function contains the transceiver init routine.         
|                   The routine depends on the used transceiver type.            
|*******************************************************************************/

void CclInitTrcvFct_0(void)
{
  ApplCclInitTrcv(0);
}


/********************************************************************************
| NAME:             CclInitTrcvFct_1                         
| PROTOTYPE:        void CclInitTrcvFct_1( void )            
| CALLED BY:        CclInitPortsPowerOn                                          
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!            
| INPUT PARAMETERS: void                                                         
| RETURN VALUE:     void                                                         
| DESCRIPTION:      This function contains the transceiver init routine.         
|                   The routine depends on the used transceiver type.            
|*******************************************************************************/

void CclInitTrcvFct_1(void)
{
  ApplCclInitTrcv(1);
}
/************************************************************************************
| NAME:             CclWakeUpTrcvFct_0                           
| PROTOTYPE:        void CclWakeUpTrcvFct_0( void )              
| CALLED BY:        ApplNmCanNormal                                                  
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to wakeup the                 
|                   transceiver. The routine depends on the used transceiver         
|                   type.                                                            
|***********************************************************************************/

void CclWakeUpTrcvFct_0(void)
{ 
  ApplCclWakeUpTrcv(0);
}


/************************************************************************************
| NAME:             CclWakeUpTrcvFct_1                           
| PROTOTYPE:        void CclWakeUpTrcvFct_1( void )              
| CALLED BY:        ApplNmCanNormal                                                  
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to wakeup the                 
|                   transceiver. The routine depends on the used transceiver         
|                   type.                                                            
|***********************************************************************************/

void CclWakeUpTrcvFct_1(void)
{ 
  ApplCclWakeUpTrcv(1);
}
/************************************************************************************
| NAME:             CclSleepTrcvFct_0                            
| PROTOTYPE:        void CclSleepTrcvFct_0( void )               
| CALLED BY:        ApplNmCanSleep                                                   
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to switch the                 
|                   transceiver into sleep mode. The routine depends on              
|                   the used transceiver type.                                       
|***********************************************************************************/

void CclSleepTrcvFct_0(void)
{
  ApplCclStandbyTrcv(0);
}


/************************************************************************************
| NAME:             CclSleepTrcvFct_1                            
| PROTOTYPE:        void CclSleepTrcvFct_1( void )               
| CALLED BY:        ApplNmCanSleep                                                   
| PRECONDITIONS:    Application is NOT ALLOWED to call this function!                
| INPUT PARAMETERS: void                                                             
| RETURN VALUE:     void                                                             
| DESCRIPTION:      This function contains the routine to switch the                 
|                   transceiver into sleep mode. The routine depends on              
|                   the used transceiver type.                                       
|***********************************************************************************/

void CclSleepTrcvFct_1(void)
{
  ApplCclStandbyTrcv(1);
}












/*lint -save -e546 */
V_MEMROM0 V_MEMROM1 tCclNmSleepReqFctTbl V_MEMROM2 CclNmSleepReqFctTbl[] = {
        &CclNmSleepReqFct_0
      , &CclNmSleepReqFct_1
};

V_MEMROM0 V_MEMROM1 tCclNmActiveReqFctTbl V_MEMROM2 CclNmActiveReqFctTbl[] = {
        &CclNmActiveReqFct_0
      , &CclNmActiveReqFct_1
};

V_MEMROM0 V_MEMROM1 tCclNmPrepareSleepReqFctTbl V_MEMROM2 CclNmPrepareSleepReqFctTbl[] = {
        &CclNmPrepareSleepReqFct_0
      , &CclNmPrepareSleepReqFct_1
};

V_MEMROM0 V_MEMROM1 tCclInitTrcvFctTbl V_MEMROM2 CclInitTrcvFctTbl[] = {
        &CclInitTrcvFct_0
      , &CclInitTrcvFct_1
};

V_MEMROM0 V_MEMROM1 tCclWakeUpTrcvFctTbl V_MEMROM2 CclWakeUpTrcvFctTbl[] = {
        &CclWakeUpTrcvFct_0
      , &CclWakeUpTrcvFct_1
};

V_MEMROM0 V_MEMROM1 tCclSleepTrcvFctTbl V_MEMROM2 CclSleepTrcvFctTbl[] = {
        &CclSleepTrcvFct_0
      , &CclSleepTrcvFct_1
};

V_MEMROM0 V_MEMROM1 tCclGetTrcvErrorPortFctTbl V_MEMROM2 CclGetTrcvErrorPortFctTbl[] = {
        V_NULL
      , V_NULL
};

V_MEMROM0 V_MEMROM1 tCclExtCanComReqFctTbl V_MEMROM2 CclExtCanComReqFctTbl[] = {
      V_NULL
      , V_NULL
};

V_MEMROM0 V_MEMROM1 tCclIntComReqFctTbl V_MEMROM2 CclIntComReqFctTbl[] = {
      V_NULL
      , V_NULL
};

V_MEMROM0 V_MEMROM1 tCclComRelFctTbl V_MEMROM2 CclComRelFctTbl[] = {
      V_NULL
      , V_NULL
};

V_MEMROM0 V_MEMROM1 tCclInitFctTbl V_MEMROM2 CclInitFctTbl[] = {
        &CclInitFct_0
      , &CclInitFct_1
};

V_MEMROM0 V_MEMROM1 tCclSystemShutdownFctTbl V_MEMROM2 CclSystemShutdownFctTbl[] = {
        &CclSystemShutdownFct_0
      , &CclSystemShutdownFct_1
};

/*lint -restore */

/* begin Fileversion check */
#ifndef SKIP_MAGIC_NUMBER
#ifdef MAGIC_NUMBER
  #if MAGIC_NUMBER != 390049630
      #error "The magic number of the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\ccl_par.c> is different. Please check time and date of generated files!"
  #endif
#else
  #error "The magic number is not defined in the generated file <D:\Renesas_Platform\fawhq_c100_apa_mcu\Source\vicp\ComplexDriver\CANdriver\tool\gen979\ccl_par.c> "

#endif  /* MAGIC_NUMBER */
#endif  /* SKIP_MAGIC_NUMBER */

/* end Fileversion check */

