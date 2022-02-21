#ifndef _COM_PUB_H_
#define _COM_PUB_H_

#include <com_cfg.h>


extern void Com_RxSignalULL( unsigned char SignalID_u8, unsigned long long * SignalValue_pu16 );

extern void Com_RxSignalUL( unsigned char SignalID_u8, unsigned long * SignalValue_pu16 );

extern void Com_RxSignalSW( unsigned char SignalID_u8, signed short * SignalValue_ps16 );

extern void Com_RxSignalUW( unsigned char SignalID_u8, unsigned short *SignalValue_pu16 );

extern void Com_RxSignalUB( unsigned char SignalID_u8, unsigned char *SignalValue_pu8 );

extern void Com_TxSignalUW( unsigned char SignalID_u8, unsigned short SignalValue_pu16 );

extern void Com_TxSignalUL( unsigned char SignalID_u8, unsigned int SignalValue_pu32 );

extern void Com_TxSignalUB( unsigned char SignalID_u8, unsigned char SignalValue_pu8 );

extern void Com_TxSignalSW( unsigned char SignalID_u8, signed short  SignalValue_pu16 );

extern unsigned char Com_GetTxSignalUB( unsigned char SignalID_u8);

extern unsigned short Com_GetTxSignalUW( unsigned char SignalID_u8);

extern void Com_ClearTxMsg_ODIEnumDynamicData_LS(void);

extern void Com_ClearTxMsg_ODIIndication_LS(void);

extern void Com_ClearTxMsg_ODIDynamicData_LS(void);

extern void Com_MainFunctionRx(void);

extern void Com_RxIndication(unsigned long msgId, unsigned char* PduInfoPtr, unsigned char canId);

extern void Com_MainFunctionTx(void);

extern void Com_Init(void);

#endif
