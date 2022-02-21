#include "config.h"
#include "typeDefine.h"
#include "ussLibIf.h"


static uint8_t libStatus = 0;

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
	switch(cmd)
	{
		case USS_IO_CTRL_CMD_GET_OBJ_DIS:
			//USSDistanceResultStructType *pUSSDistanceResult = (USSDistanceResultStructType*)buff;
			//_memcpy(pUSSDistanceResult,NULL,sizeof(USSDistanceResultStructType)); // NULL for source databuff.
			break;
	}
}
uint8_t ussLibDrvPowerControl(uint8_t opCmd)// opCmd:DEV_PWR_OP_TYPE
{
	switch(opCmd)
	{
		case DEV_OP_OPEN:
			break;
		case DEV_OP_PWR_ON:
			break;
		case DEV_OP_PWR_WAKEUP:
			break;
		case DEV_OP_PWR_SLEEP:
			break;
		case DEV_OP_PWR_OFF:
			break;
		case DEV_OP_CLOSE:
			break;
		default:
			break;
	}
}
uint8_t ussLibDrvPowerStatus(void)// return para: DEV_PWR_STATE_TYPE
{
	return libStatus;
}


void isrIntervalTimer0(void)
{
 
}
void isrIntervalTimer1(void) 
{
}
void ussObjLibRunnable_Bg1ms(void)           // 1ms.
{
	
}
void ussObjLibRunnable_Main10ms(void)         // 10ms.
{
    
}

// LF's temperory funtiong realization

