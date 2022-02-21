#include "config.h"
#include "define.h"
#include "ussLibIf.h"
#include "gpio_if.h"
#include "gpioApp.h"
#include "r_cg_tauj.h"
#include "r_cg_taub.h"
#include "r_cg_dmac.h"
#include "r_cg_userdefine.h"
#include "ComplexDrvier_Globaldef_IF.H"


// need FV impl
#ifdef USS_LIB_STUB
uint8_t ussLibDrvOpen(void)
{

}
uint8_t ussLibDrvClose(void)
{
}
uint16_t ussLibDrvRead(uint8_t *buff,uint16_t Len)
{
}
uint16_t ussLibDrvWrite(uint8_t *buff,uint16_t Len)
{
}
uint8_t ussLibIoControl(uint8_t cmd, void *buff)
{
}
uint8_t ussLibDrvPowerControl(U8 opCmd)// opCmd:DEV_PWR_OP_TYPE
{
}
uint8_t ussLibDrvPowerStatus(void)// return para: DEV_PWR_STATE_TYPE
{
}


void isrIntervalTimer0(void)
{  


}
void isrIntervalTimer1(void)
{

}
void ussObjLibRunnable_Bg1ms(void)           // 1ms.空闲时间即运行后台任务
{  
}
void ussObjLibRunnable_Main10ms(void)           // 10ms.周期10ms执行一次，需要优先级提高
{
}


#endif

#ifdef USS_LIB_STUB_TEST
void isrIntervalTimer00(void)
{  
    /*test Tx***********/
    static uint8_t flag = 0;
	static uint32_t timeType = 20;
    flag = !flag;  
    g_setPortValue_vd_0(flag);
	g_setPortValue_vd_1(flag);
	g_setPortValue_vd_2(flag);
	g_setPortValue_vd_3(flag);
	g_setPortValue_vd_4(flag);
	g_setPortValue_vd_5(flag);
	g_setPortValue_vd_6(flag);
	g_setPortValue_vd_7(flag);
	g_setPortValue_vd_8(flag);
	g_setPortValue_vd_9(flag);
	g_setPortValue_vd_10(flag);
	g_setPortValue_vd_11(flag);

    g_IntervalTimer0_setValue_vd(timeType);
	
    g_IntervalTimer0_start_vd();

}
#endif

void ISR_TAUJ1I0func(void)		/* 10us*/
{
#ifdef USS_LIB_STUB_TEST
	isrIntervalTimer00();
#else
	isrIntervalTimer0();
#endif
    /*Systemtick_10us must be added in the timer isr which was configured as a 10us timer*/
#if 0
    Systemtick_10us++;
     /* callback */
 #if(MCU_PIN>=PIN100)
    if(tau_func_callback[TAUJ1_U4][TAU_CH0]!=NULL)
      tau_func_callback[TAUJ1_U4][TAU_CH0](0);

    if(!(allTauChannelCtrl[TAUJ1_U4][TAU_CH0].isLoop))
      TAU_REG_TAUJnTT(TAUB_BASEADDR[TAUJ1_U4]) |= (1<<TAU_CH0);
 #endif
 #endif
}

void ISR_TAUJ1I1func(void)
{
	isrIntervalTimer1();
}


void  g_IntervalTimer0_start_vd(void)
{
    R_TAUJ1_Channel0_Start(); // 1us free clock
}
void  g_IntervalTimer0_stop_vd(void)
{
    R_TAUJ1_Channel0_Stop();
}
void  g_IntervalTimer0_setValue_vd(uint32_t         f_value_ui32)
{
    ussSetTime0_1Us(f_value_ui32);
}


void  g_IntervalTimer1_start_vd(void)
{
    R_TAUJ1_Channel1_Start(); // 1us free clock
}
void  g_IntervalTimer1_stop_vd(void)
{  
    R_TAUJ1_Channel1_Stop();
}
void  g_IntervalTimer1_setValue_vd(uint32_t         f_value_ui32)
{
    ussSetTime1_1Us(f_value_ui32);
}


void  g_captureTimer0_start_vd(void)
{    
    R_TAUB0_Channel15_Start();
}
void  g_captureTimer0_stop_vd(void)
{
    R_TAUB0_Channel15_Stop();
}
void  g_captureTimer1_start_vd(void)
{
    R_TAUB0_Channel8_Start();
}
void  g_captureTimer1_stop_vd(void)
{
    R_TAUB0_Channel8_Stop();
}
void  g_captureTimer2_start_vd(void)
{
    R_TAUB0_Channel10_Start();
}
void  g_captureTimer2_stop_vd(void)
{
    R_TAUB0_Channel10_Stop();
}
void  g_captureTimer3_start_vd(void)
{
    R_TAUB0_Channel12_Start();
}
void  g_captureTimer3_stop_vd(void)
{
    R_TAUB0_Channel12_Stop();
}
void  g_captureTimer4_start_vd(void)
{
    R_TAUB0_Channel14_Start();
}
void  g_captureTimer4_stop_vd(void)
{
    R_TAUB0_Channel14_Stop();
}
void  g_captureTimer5_start_vd(void)
{
    R_TAUB0_Channel13_Start();
}
void  g_captureTimer5_stop_vd(void)
{
    R_TAUB0_Channel13_Stop();
}

void  g_captureTimer6_start_vd(void)
{
    R_TAUB0_Channel7_Start();
}
void  g_captureTimer6_stop_vd(void)
{
    R_TAUB0_Channel7_Stop();
}
void  g_captureTimer7_start_vd(void)
{
    R_TAUB0_Channel6_Start();
}
void  g_captureTimer7_stop_vd(void)
{
    R_TAUB0_Channel6_Stop();
}
void  g_captureTimer8_start_vd(void)
{
    R_TAUB0_Channel4_Start();
}
void  g_captureTimer8_stop_vd(void)
{
    R_TAUB0_Channel4_Stop();
}
void  g_captureTimer9_start_vd(void)
{
    R_TAUB0_Channel2_Start();
}
void  g_captureTimer9_stop_vd(void)
{
    R_TAUB0_Channel2_Stop();
}
void  g_captureTimer10_start_vd(void)
{
    R_TAUB0_Channel0_Start();
}
void  g_captureTimer10_stop_vd(void)
{
    R_TAUB0_Channel0_Stop();
}
void  g_captureTimer11_start_vd(void)
{
    R_TAUB0_Channel5_Start();
}
void  g_captureTimer11_stop_vd(void)
{
    R_TAUB0_Channel5_Stop();
}


void g_DMAC_0_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(0,f_counter_ui32);
    setUssDmaDestinationAddr(0, f_Ddaddr_ui32);
    //DMAC.DDA0 = _DMAC0_DESTINATION_ADDRESS;
    //DMAC.DTC0 = _DMAC0_ADDRESS_RELOAD_COUNT | _DMAC0_TRANSFER_COUNT;
    
    R_DMAC00_Create();
    R_DMAC00_Start();
}
void g_DMAC_0_Stop_vd (void)
{
    R_DMAC00_Stop();
}
void g_DMAC_1_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(1,f_counter_ui32);
    setUssDmaDestinationAddr(1, f_Ddaddr_ui32);
    //DMAC.DDA1 = _DMAC1_DESTINATION_ADDRESS;
    //DMAC.DTC1 = _DMAC1_ADDRESS_RELOAD_COUNT | _DMAC1_TRANSFER_COUNT;
    
    R_DMAC01_Create();
    R_DMAC01_Start();
}
void g_DMAC_1_Stop_vd (void)
{
    R_DMAC01_Stop();
}
void g_DMAC_2_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(2,f_counter_ui32);
    setUssDmaDestinationAddr(2, f_Ddaddr_ui32);
    //DMAC.DDA12 = _DMAC12_DESTINATION_ADDRESS;
    //DMAC.DTC12 = _DMAC12_ADDRESS_RELOAD_COUNT | _DMAC12_TRANSFER_COUNT;
    
    R_DMAC14_Create();
    R_DMAC14_Start();
}
void g_DMAC_2_Stop_vd (void)
{
    R_DMAC14_Stop();
}
void g_DMAC_3_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{   
    setUssDmaCounter(3,f_counter_ui32);
    setUssDmaDestinationAddr(3, f_Ddaddr_ui32);
    //DMAC.DDA13 = _DMAC13_DESTINATION_ADDRESS;
    //DMAC.DTC13 = _DMAC13_ADDRESS_RELOAD_COUNT | _DMAC13_TRANSFER_COUNT;
    
    R_DMAC15_Create();
    R_DMAC15_Start();
}
void g_DMAC_3_Stop_vd (void)
{
    R_DMAC15_Stop();
}
void g_DMAC_4_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(4,f_counter_ui32);
    setUssDmaDestinationAddr(4, f_Ddaddr_ui32);
    //DMAC.DDA4 = _DMAC4_DESTINATION_ADDRESS;
    //DMAC.DTC4 = _DMAC4_ADDRESS_RELOAD_COUNT | _DMAC4_TRANSFER_COUNT;
    
    R_DMAC04_Create();
    R_DMAC04_Start();
}
void g_DMAC_4_Stop_vd (void)
{
    R_DMAC04_Stop();
}
void g_DMAC_5_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(5,f_counter_ui32);
    setUssDmaDestinationAddr(5, f_Ddaddr_ui32);
    //DMAC.DDA5 = _DMAC5_DESTINATION_ADDRESS;
    //DMAC.DTC5 = _DMAC5_ADDRESS_RELOAD_COUNT | _DMAC5_TRANSFER_COUNT;
    
    R_DMAC05_Create();
    R_DMAC05_Start();
}
void g_DMAC_5_Stop_vd (void)
{
    R_DMAC05_Stop();
}
void g_DMAC_6_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(6,f_counter_ui32);
    setUssDmaDestinationAddr(6, f_Ddaddr_ui32);
    //DMAC.DDA6 = _DMAC6_DESTINATION_ADDRESS;
    //DMAC.DTC6 = _DMAC6_ADDRESS_RELOAD_COUNT | _DMAC6_TRANSFER_COUNT;
    
    R_DMAC06_Create();
    R_DMAC06_Start();
}
void g_DMAC_6_Stop_vd (void)
{
    R_DMAC06_Stop();
}
void g_DMAC_7_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(7,f_counter_ui32);
    setUssDmaDestinationAddr(7, f_Ddaddr_ui32);
    //DMAC.DDA7 = _DMAC7_DESTINATION_ADDRESS;
    //DMAC.DTC7 = _DMAC7_ADDRESS_RELOAD_COUNT | _DMAC7_TRANSFER_COUNT;
    
    R_DMAC07_Create();
    R_DMAC07_Start();
}
void g_DMAC_7_Stop_vd (void)
{
    R_DMAC07_Stop();
}
void g_DMAC_8_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(8,f_counter_ui32);
    setUssDmaDestinationAddr(8, f_Ddaddr_ui32);
    //DMAC.DDA8 = _DMAC8_DESTINATION_ADDRESS;
    //DMAC.DTC8 = _DMAC8_ADDRESS_RELOAD_COUNT | _DMAC8_TRANSFER_COUNT;
    
    R_DMAC10_Create();
    R_DMAC10_Start();
}
void g_DMAC_8_Stop_vd (void)
{
    R_DMAC10_Stop();
}
void g_DMAC_9_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(9,f_counter_ui32);
    setUssDmaDestinationAddr(9, f_Ddaddr_ui32);
    //DMAC.DDA14 = _DMAC14_DESTINATION_ADDRESS;
    //DMAC.DTC14 = _DMAC14_ADDRESS_RELOAD_COUNT | _DMAC14_TRANSFER_COUNT;
    
    R_DMAC16_Create();
    R_DMAC16_Start();
}
void g_DMAC_9_Stop_vd (void)
{
    R_DMAC16_Stop();
}
void g_DMAC_10_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(10,f_counter_ui32);
    setUssDmaDestinationAddr(10, f_Ddaddr_ui32);
    //DMAC.DDA10 = _DMAC10_DESTINATION_ADDRESS;
    //DMAC.DTC10 = _DMAC10_ADDRESS_RELOAD_COUNT | _DMAC10_TRANSFER_COUNT;
    
    R_DMAC12_Create();
    R_DMAC12_Start();

}
void g_DMAC_10_Stop_vd (void)
{
    R_DMAC12_Stop();
}
void g_DMAC_11_Start_vd(uint32_t    f_counter_ui32,    uint32_t   f_Ddaddr_ui32)
{
    setUssDmaCounter(11,f_counter_ui32);
    setUssDmaDestinationAddr(11, f_Ddaddr_ui32);
    //DMAC.DDA11 = _DMAC11_DESTINATION_ADDRESS;
    //DMAC.DTC11 = _DMAC11_ADDRESS_RELOAD_COUNT | _DMAC11_TRANSFER_COUNT;
    
    R_DMAC13_Create();
    R_DMAC13_Start();
}
void g_DMAC_11_Stop_vd (void)
{
    R_DMAC13_Stop();
}

void        g_setPortValue_vd_0 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RRS_TX_PORT,USS_SNS_RRS_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_0(void)
{
    return GPIO_GetVal(USS_SNS_RRS_TX_PORT,USS_SNS_RRS_TX_PIN);
}
uint8_t     g_getInputValue_0(void)
{
    return GPIO_GetVal(USS_SNS_RRS_RX_PORT,USS_SNS_RRS_RX_PIN);
}

void        g_setPortValue_vd_1 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RR_TX_PORT,USS_SNS_RR_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_1(void)
{
    return GPIO_GetVal(USS_SNS_RR_TX_PORT,USS_SNS_RR_TX_PIN);
}

uint8_t     g_getInputValue_1(void)
{
    return GPIO_GetVal(USS_SNS_RR_RX_PORT,USS_SNS_RR_RX_PIN);
}


void        g_setPortValue_vd_2 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RRM_TX_PORT,USS_SNS_RRM_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_2(void)
{
    return GPIO_GetVal(USS_SNS_RRM_TX_PORT,USS_SNS_RRM_TX_PIN);
}

uint8_t     g_getInputValue_2(void)
{
    return GPIO_GetVal(USS_SNS_RRM_RX_PORT,USS_SNS_RRM_RX_PIN);
}

void        g_setPortValue_vd_3 (  uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RLM_TX_PORT,USS_SNS_RLM_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_3(void)
{
    return GPIO_GetVal(USS_SNS_RLM_TX_PORT,USS_SNS_RLM_TX_PIN);
}

uint8_t     g_getInputValue_3(void)
{
    return GPIO_GetVal(USS_SNS_RLM_RX_PORT,USS_SNS_RLM_RX_PIN);
}

void        g_setPortValue_vd_4 (  uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RL_TX_PORT,USS_SNS_RL_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_4(void)
{   
    return GPIO_GetVal(USS_SNS_RL_TX_PORT,USS_SNS_RL_TX_PIN);
}

uint8_t     g_getInputValue_4(void)
{
    return GPIO_GetVal(USS_SNS_RL_RX_PORT,USS_SNS_RL_RX_PIN);
}

void        g_setPortValue_vd_5 (  uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_RLS_TX_PORT,USS_SNS_RLS_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_5(void)
{
    return GPIO_GetVal(USS_SNS_RLS_TX_PORT,USS_SNS_RLS_TX_PIN);
}
uint8_t     g_getInputValue_5(void)
{
    return GPIO_GetVal(USS_SNS_RLS_RX_PORT,USS_SNS_RLS_RX_PIN);
}
void        g_setPortValue_vd_6 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FRS_TX_PORT,USS_SNS_FRS_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_6(void)
{
    return GPIO_GetVal(USS_SNS_FRS_TX_PORT,USS_SNS_FRS_TX_PIN);
}
uint8_t     g_getInputValue_6(void)
{
    return GPIO_GetVal(USS_SNS_FRS_RX_PORT,USS_SNS_FRS_RX_PIN);
}
void        g_setPortValue_vd_7 (  uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FR_TX_PORT,USS_SNS_FR_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_7(void)
{
    return GPIO_GetVal(USS_SNS_FR_TX_PORT,USS_SNS_FR_TX_PIN);
}
uint8_t     g_getInputValue_7(void)
{
    return GPIO_GetVal(USS_SNS_FR_RX_PORT,USS_SNS_FR_RX_PIN);

}
void        g_setPortValue_vd_8 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FRM_TX_PORT,USS_SNS_FRM_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_8(void)
{
    return GPIO_GetVal(USS_SNS_FRM_TX_PORT,USS_SNS_FRM_TX_PIN);
}
uint8_t     g_getInputValue_8(void)
{
    return GPIO_GetVal(USS_SNS_FRM_RX_PORT,USS_SNS_FRM_RX_PIN);
}
void        g_setPortValue_vd_9 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FLM_TX_PORT,USS_SNS_FLM_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_9(void)
{
    return GPIO_GetVal(USS_SNS_FLM_TX_PORT,USS_SNS_FLM_TX_PIN);

}
uint8_t     g_getInputValue_9(void)
{
    return GPIO_GetVal(USS_SNS_FLM_RX_PORT,USS_SNS_FLM_RX_PIN);
}
void        g_setPortValue_vd_10 (  uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FL_TX_PORT,USS_SNS_FL_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_10(void)
{
    return GPIO_GetVal(USS_SNS_FL_TX_PORT,USS_SNS_FL_TX_PIN);
}
uint8_t     g_getInputValue_10(void)
{
    return GPIO_GetVal(USS_SNS_FL_RX_PORT,USS_SNS_FL_RX_PIN);
}
void        g_setPortValue_vd_11 (uint8_t      f_value_ui8)
{
    GPIO_SetVal(USS_SNS_FLS_TX_PORT,USS_SNS_FLS_TX_PIN,f_value_ui8);
}
uint8_t     g_getOutputValue_11(void)
{
    return GPIO_GetVal(USS_SNS_FLS_TX_PORT,USS_SNS_FLS_TX_PIN);
}
uint8_t     g_getInputValue_11(void)
{
    return GPIO_GetVal(USS_SNS_FLS_RX_PORT,USS_SNS_FLS_RX_PIN);
}

void g_setOutputPin_0(void)
{
    //GPIO_SetOutputMode(USS_SNS_RRS_TX_PORT,USS_SNS_RRS_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_0(void)
{
    //GPIO_SetInputMode(USS_SNS_RRS_RX_PORT,USS_SNS_RRS_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_1(void)
{
    //GPIO_SetOutputMode(USS_SNS_RR_TX_PORT,USS_SNS_RR_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_1(void)
{
    //GPIO_SetInputMode(USS_SNS_RR_RX_PORT,USS_SNS_RR_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_2(void)
{
    //GPIO_SetOutputMode(USS_SNS_RRM_TX_PORT,USS_SNS_RRM_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_2(void)
{
    //GPIO_SetInputMode(USS_SNS_RRM_RX_PORT,USS_SNS_RRM_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_3(void)
{
    //GPIO_SetOutputMode(USS_SNS_RLM_TX_PORT,USS_SNS_RLM_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_3(void)
{
    //GPIO_SetInputMode(USS_SNS_RLM_RX_PORT,USS_SNS_RLM_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_4(void)
{
    //GPIO_SetOutputMode(USS_SNS_RL_TX_PORT,USS_SNS_RL_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_4(void)
{
    //GPIO_SetInputMode(USS_SNS_RL_RX_PORT,USS_SNS_RL_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_5(void)
{
    //GPIO_SetOutputMode(USS_SNS_RLS_TX_PORT,USS_SNS_RLS_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_5(void)
{
    //GPIO_SetInputMode(USS_SNS_RLS_RX_PORT,USS_SNS_RLS_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_6(void)
{
    //GPIO_SetOutputMode(USS_SNS_FRS_TX_PORT,USS_SNS_FRS_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_6(void)
{
    //GPIO_SetInputMode(USS_SNS_FRS_RX_PORT,USS_SNS_FRS_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_7(void)
{
    //GPIO_SetOutputMode(USS_SNS_FR_TX_PORT,USS_SNS_FR_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_7(void)
{
    //GPIO_SetInputMode(USS_SNS_FR_RX_PORT,USS_SNS_FR_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_8(void)
{
    //GPIO_SetOutputMode(USS_SNS_FRM_TX_PORT,USS_SNS_FRM_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_8(void)
{
    //GPIO_SetInputMode(USS_SNS_FRM_RX_PORT,USS_SNS_FRM_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_9(void)
{
    //GPIO_SetOutputMode(USS_SNS_FLM_TX_PORT,USS_SNS_FLM_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_9(void)
{
    //GPIO_SetInputMode(USS_SNS_FLM_RX_PORT,USS_SNS_FLM_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_10(void)
{
    //GPIO_SetOutputMode(USS_SNS_FL_TX_PORT,USS_SNS_FL_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_10(void)
{
    //GPIO_SetInputMode(USS_SNS_FL_RX_PORT,USS_SNS_FL_RX_PIN,E_NO_MODE);
}
void g_setOutputPin_11(void)
{
    //GPIO_SetOutputMode(USS_SNS_FLS_TX_PORT,USS_SNS_FLS_TX_PIN,E_OPEN_DRAIN,E_LOW_10MHZ);
}
void g_setInputPin_11(void)
{
    //GPIO_SetInputMode(USS_SNS_FLS_RX_PORT,USS_SNS_FLS_RX_PIN,E_NO_MODE);
}

#ifdef USS_LIB_STUB_TEST
unsigned short echoWaveArray[12][1];
void ussLibDriverTest(void)
{
    F_RADAR_EN_ON();
    R_RADAR_EN_ON();

	g_setOutputPin_0();
	g_setOutputPin_1(); 
	g_setOutputPin_2();
	g_setOutputPin_3();
	g_setOutputPin_4(); 
	g_setOutputPin_5();
	g_setOutputPin_6();
	g_setOutputPin_7(); 
	g_setOutputPin_8();
	g_setOutputPin_9();
	g_setOutputPin_10();	
	g_setOutputPin_11();



	 g_IntervalTimer0_setValue_vd(50); 
	 g_IntervalTimer0_start_vd();
	//g_DMAC_0_Start_vd(100,(uint32_t)&echoWaveArray[0][0]);
	//g_captureTimer0_start_vd();

#if 0
	g_setInputPin_1(); 
	g_DMAC_1_Start_vd(100,(uint32_t)&echoWaveArray[1][0]);
	g_captureTimer1_start_vd();

	g_setInputPin_2(); 
	g_DMAC_2_Start_vd(100,(uint32_t)&echoWaveArray[2][0]);
	g_captureTimer0_start_vd();


	g_setInputPin_3(); 
	g_DMAC_3_Start_vd(100,(uint32_t)&echoWaveArray[3][0]);
	g_captureTimer3_start_vd();

	g_setInputPin_4(); 
	g_DMAC_4_Start_vd(100,(uint32_t)&echoWaveArray[4][0]);
	g_captureTimer4_start_vd();


	g_setInputPin_5(); 
	g_DMAC_5_Start_vd(100,(uint32_t)&echoWaveArray[5][0]);
	g_captureTimer5_start_vd();

	g_setInputPin_6(); 
	g_DMAC_6_Start_vd(100,(uint32_t)&echoWaveArray[6][0]);
	g_captureTimer6_start_vd();


	g_setInputPin_7(); 
	g_DMAC_7_Start_vd(100,(uint32_t)&echoWaveArray[7][0]);
	g_captureTimer7_start_vd();

	g_setInputPin_8(); 
	g_DMAC_8_Start_vd(100,(uint32_t)&echoWaveArray[8][0]);
	g_captureTimer8_start_vd();


	g_setInputPin_9(); 
	g_DMAC_9_Start_vd(100,(uint32_t)&echoWaveArray[9][0]);
	g_captureTimer9_start_vd();

	g_setInputPin_10(); 
	g_DMAC_10_Start_vd(100,(uint32_t)&echoWaveArray[10][0]);
	g_captureTimer10_start_vd();


	g_setInputPin_11(); 
	g_DMAC_11_Start_vd(100,(uint32_t)&echoWaveArray[11][0]);
	g_captureTimer11_start_vd();
#endif
	
}
#endif



