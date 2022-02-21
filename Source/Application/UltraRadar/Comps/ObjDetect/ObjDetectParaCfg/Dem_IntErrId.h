//============================================================================
//
//============================================================================
//
// Header file for the Dem code
//
//============================================================================
#ifndef _DEM_INTERRID_H
#define _DEM_INTERRID_H

//============================================================================
// Including files
//============================================================================
//#include "Std_Types.h"
//============================================================================
// Event id define
//============================================================================

typedef union
{
	unsigned short allStatus;
	struct
	{
		unsigned short shortToBattery	:1;
		unsigned short shortToGND		:1;
		unsigned short isBlocked		:1;
		unsigned short ringTimeTooShort	:1;	
		
		unsigned short ringTimeTooLong	:1;
		unsigned short signalDisturbed	:1;
		unsigned short signalError		:1;
		unsigned short initFail			:1;

		unsigned short disconnected		:1;
		unsigned short typeIncorrect	:1;
		unsigned short reserve			:6;
	}item;
}diagnosticTypedef;

typedef struct
{
	union
	{
		unsigned int allStatus;
		struct
		{
			unsigned char mainTaskBgFlg			:1;
			unsigned char seqEmitWaveReq			:1;
			unsigned char seqWaitForNextEmit		:1;
			unsigned char seqProcess2				:1;
			
			unsigned char recTimeOut				:1;
			unsigned char seqRxDat					:1;
			unsigned char seqEmitReqWait			:1;
			unsigned char seqIdle					:1;
			
			unsigned char seqDelayToInit			:1;
			unsigned char seqParaInit				:1;
			unsigned char sendSeqTXcmd			:1;
			unsigned char resetFlg					:1;
			
			unsigned char frontSnsPower				:1;
			unsigned char rearSnsPower				:1;
			unsigned char reverse					:2;
		}item;
	}status;
	unsigned char timeCnt10ms;
}SystemStatusTypedef;

#endif