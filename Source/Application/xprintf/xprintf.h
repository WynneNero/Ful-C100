/*------------------------------------------------------------------------*/
/* Universal string handler for user console interface  (C)ChaN, 2011     */
/*------------------------------------------------------------------------*/

#ifndef _XPRINTF_H
#define _XPRINTF_H

#define	_CR_CRLF		0	/* 1: Convert \n ==> \r\n in the output char */

#define xdev_out(func) xfunc_out = (void(*)(unsigned char))(func)

#define TRACE_DISABLE  0
#define TRACE_ENABLE  1
#define PM_TRACE_SW  TRACE_DISABLE
#define FUN_ENTER_SW TRACE_DISABLE
#define FUN_EXIT_SW  TRACE_DISABLE
#define SYS_STATUS_MOD_TRACE_SW TRACE_DISABLE
#define SYS_STATE_MOD_TRACE_SW TRACE_DISABLE
#define SYS_MODE_MOD_TRACE_SW TRACE_DISABLE
#define POWER_MNG_MOD_TRACE_SW TRACE_DISABLE
#define ANW_TRACE_SW TRACE_DISABLE
#define SYS_INT_TRACE_SW TRACE_DISABLE
#define SOC_MESSAGE_TRACE_SW  TRACE_DISABLE
#define DEFAULT_TRACE_SW TRACE_DISABLE
#define APA_STATE_SW TRACE_DISABLE
#define APA_TRACE_SW TRACE_DISABLE
#define ALG_INPUT_SW TRACE_DISABLE
#define ALG_OUTPUT_SW TRACE_DISABLE
#define APA_DR_SW TRACE_DISABLE


#define PM_TRACE  1
#define FUN_ENTER  2
#define FUN_EXIT   3
#define SYS_STATUS_MOD_TRACE 4
#define SYS_STATE_MOD_TRACE 6
#define SYS_MODE_MOD_TRACE 7
#define POWER_MNG_MOD_TRACE 5
#define DEFAULT_TRACE  8
#define ANW_TRACE 9
#define SYS_INT_TRACE 10
#define SOC_MESSAGE_TRACE  11
#define APA_STATE 12
#define APA_TRACE 13
#define ALG_INPUT 14
#define ALG_OUTPUT 15
#define APA_DR 16
extern void (*xfunc_out)(unsigned char);

#if XPRINTF_ENABLE
    #define LOG(type,ARG...) trace(type,ARG)
	#define LOG_X(ARG...) 	xprintf(ARG)	
	//#define LOG(type,ARG...) printf(ARG)
	//#define LOG_X(ARG...) printf(ARG)		//console printf
#else
    #define LOG(type,ARG...)
	#define LOG_X(ARG...)
#endif
void xputc (char c);
void xputs (const char* str);
void xfputs (void (*func)(unsigned char), const char* str);
void xprintf (const char* fmt, ...); 
void put_dump (const void* buff, unsigned long addr, int len, int width);
#define DW_CHAR		sizeof(char)
#define DW_SHORT	sizeof(short)
#define DW_LONG		sizeof(long)

void xprintfOpen(void);
void xprintfClose(void);
void xprintfSleep(void);
void xprintfWakeup(void);
void xprintfLoop(void);
void trace(int type,const char*fmt,...);


#endif


