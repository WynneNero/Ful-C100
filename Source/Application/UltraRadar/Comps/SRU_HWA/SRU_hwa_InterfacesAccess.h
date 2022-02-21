#ifndef _SRU_HWA_INTERFACESACCESS_H_
#define _SRU_HWA_INTERFACESACCESS_H_

/*Interface from Basic Software, called by Function software*/
extern unsigned int iTauj1msCount;
extern void HWA_ObjDetectTimerStart(unsigned short wTime, unsigned char ECT_TIM_InitReq);
extern void HWA_ObjDetectTimerStop(void);
extern unsigned char SnsIntp_GetIntFlag(unsigned char index);
extern void SnsIntp_ClearIntFlag(unsigned char index);
extern void SnsIntp_EnableInt(unsigned char index);
extern void SnsIntp_DisableAllInt(void);
extern void Intp_init(void);
extern void TAUJ0_Channel1_stop(void);
extern void TAUJ0_Channel1_start(unsigned short tauj0_channel1_duty);
extern void HWA_TimeDelay(unsigned short wTime /*UNIT: us*/);


/*Interface from Function Software, called by Basic Software */
extern void ElmosCtl_SensorInputInterrupt(unsigned char index);
extern void ElmosCtl_TimerInterrupt(void);

extern void HWA_DisableElmosRxPinInt(unsigned char index);
extern unsigned long HWA_Get_Intp_Init_Time_Point(void);
extern unsigned int HWA_Get1msCount(void);
extern void HWA_Set1msCount(unsigned int count);
extern unsigned long HWA_Get_Systime(void);
extern void HWA_SetRrSensorHigh(void);
extern void HWA_SetRrSensorLow(void);
extern void HWA_SetRlSensorHigh(void);
extern void HWA_SetRlSensorLow(void);
extern void HWA_SetRrmSensorHigh(void);
extern void HWA_SetRrmSensorLow(void);
extern void HWA_SetRlmSensorHigh(void);
extern void HWA_SetRlmSensorLow(void);
extern void HWA_SetRrsSensorHigh(void);
extern void HWA_SetRrsSensorLow(void);
extern void HWA_SetRlsSensorHigh(void);
extern void HWA_SetRlsSensorLow(void);
extern void HWA_SetFrSensorHigh(void);
extern void HWA_SetFrSensorLow(void);
extern void HWA_SetFlSensorHigh(void);
extern void HWA_SetFlSensorLow(void);
extern void HWA_SetFrmSensorHigh(void);
extern void HWA_SetFrmSensorLow(void);
extern void HWA_SetFlmSensorHigh(void);
extern void HWA_SetFlmSensorLow(void);
extern void HWA_SetFrsSensorHigh(void);
extern void HWA_SetFrsSensorLow(void);
extern void HWA_SetFlsSensorHigh(void);
extern void HWA_SetFlsSensorLow(void);
extern unsigned char HWA_GetSensorLineLevel(unsigned char index);
extern void HWA_SetAllApaSensorLineHigh(void);
extern void HWA_SetAllUpaSensorLineHigh(void);

/* END WRITE ACCESS */

#endif
