
#include "Config.h"
#include "define.h"
#include "xprintf.h"
#include "DebugUartDriver_if.h"
#include "debugUartDriver.h"
#include "hal_if.h"

#include <stdarg.h>
void (*xfunc_out)(unsigned char);	/* Pointer to the output stream */
static char *outptr;

static void debugUartPutByte(U8 ch);


void xprintfOpen(void)
{
    xfunc_out = debugUartPutByte;
    debugUartDrvOpen();
}
void xprintfClose(void)
{
    xfunc_out = NULL;
    debugUartDrvClose();
}
void xprintfSleep(void)
{
  debugUartDrvPowerControl(DEV_OP_PWR_SLEEP);
}
void xprintfWakeup(void)
{
  debugUartDrvPowerControl(DEV_OP_PWR_WAKEUP);
}

void xprintfLoop(void)
{
    debugUartDrvTask();
}
/* Private functions ---------------------------------------------------------*/


/*----------------------------------------------*/
/* Put a character                              */
/*----------------------------------------------*/
void xputc (char c /* A character to be output */) 
{
    if (_CR_CRLF && c == '\n') xputc('\r');		/* CR -> CRLF */

    if (outptr) 
    {
        *outptr++ = (unsigned char)c;
        return;
    }
    if (xfunc_out) 
    {
        xfunc_out((unsigned char)c);
    }
}



/*----------------------------------------------*/
/* Put a null-terminated string                 */
/*----------------------------------------------*/

void xputs (					/* Put a string to the default device */
	const char* str				/* Pointer to the string */
)
{
    while (*str)
    	xputc(*str++);
}


void xfputs (					/* Put a string to the specified device */
	void(*func)(unsigned char),	/* Pointer to the output function */
	const char*	str				/* Pointer to the string */
)
{
	void (*pf)(unsigned char);

	pf = xfunc_out;		/* Save current output device */
	xfunc_out = func;	/* Switch output to specified device */
	while (*str)		/* Put the string */
	{
		xputc(*str++);
    }
	xfunc_out = pf;		/* Restore output device */
}


static void xvprintf (
	const char*	fmt,	/* Pointer to the format string */
	va_list arp			/* Pointer to arguments */
)
{
	unsigned int r, i, j, w, f;
	unsigned long v;
	long long v1;
	double t;
	char s[64], c, d, *p,ff,o;


	for (;;) 
	{
		c = *fmt++;					/* Get a char */
		if (!c) break;				/* End of format? */
		if (c != '%') 
		{				/* Pass through it if not a % sequense */
			xputc(c); continue;
		}
		f = 0;
		c = *fmt++;					/* Get first char of the sequense */
		if (c == '0') 
		{				/* Flag: '0' padded */
			f = 1; c = *fmt++;
		} 
		else 
		{
			if (c == '-') 
			{			/* Flag: left justified */
				f = 2; c = *fmt++;
			}
		}
		for (w = 0; c >= '0' && c <= '9'; c = *fmt++)	/* Minimum width */
		{
			w = w * 10 + c - '0';
		}
		if (c == 'l' || c == 'L') 
       {
          /* Prefix: Size is long int */
			f |= 4; c = *fmt++;
		}
		if (!c) break;				/* End of format? */
        
		d = c;
		if (d >= 'a') d -= 0x20;
		switch (d) 
            {				                        /* Type is... */
        		case 'S' :					/* String */
        			p = va_arg(arp, char*);
        			for (j = 0; p[j]; j++) ;
        			while (!(f & 2) && j++ < w) xputc(' ');
        			xputs(p);
        			while (j++ < w) xputc(' ');
        			continue;
        		case 'C' :					/* Character */
        			xputc((char)va_arg(arp, int)); continue;
        		case 'B' :					/* Binary */
        			r = 2; break;
        		case 'O' :					/* Octal */
        			r = 8; break;
        		case 'D' :					/* Signed decimal */
        		case 'U' :					/* Unsigned decimal */
        			r = 10; break;
        		case 'X' :					/* Hexdecimal */
        			r = 16; break;
				case 'F' :					/* Hexdecimal */
        			r = 10; break;
        		default:					/* Unknown type (passthrough) */
        			xputc(c); continue;
		}
		
		if(d == 'F')		//float retain 6 decimal  --  special handle
		{

			/* Get an argument and put it in numeral */
			t =  va_arg(arp, double);//(f & 4) ? va_arg(arp, long) : ((d == 'D') ? (long)va_arg(arp, int) : (long)va_arg(arp, unsigned int));
			if(((t > 0 ) &&(t < 1))||((t < 0 ) &&(t > -1)))
			{
				ff = 1;
			}else
			{
				ff = 0;
			}
			
			v1 = (long long)(t * 10000);		//4 decimal

			if (d == 'F' && (v1 & 0x8000000000000000)) //longlong
			{
				v1 = 0 - v1;
				f |= 8;
			}
			i = 0;
			o = 1;
			do 
			{
			
				d = (char)(v1 % r); v1 /= r;
				s[i++] = d + '0';
				if(i == 4)
				{
					s[i++] = '.';
				}
				if(ff&&(i>5))				//4 decimal
				{	
					o = 0;
				}
				if(ff == 0)
				{
					if((v1 == 0) || (i >= sizeof(s)))
					{
						o = 0;
					}
				}
				
			
			
			} while (o);

		}
		else	
		{
			/* Get an argument and put it in numeral */
			v = (f & 4) ? va_arg(arp, long) : ((d == 'D') ? (long)va_arg(arp, int) : (long)va_arg(arp, unsigned int));

		if (d == 'D' && (v & 0x80000000)) 
		{
			v = 0 - v;
			f |= 8;
		}
		i = 0;
		do 
		{
			d = (char)(v % r); v /= r;
			if (d > 9) d += (c == 'x') ? 0x27 : 0x07;
			s[i++] = d + '0';
		} while (v && i < sizeof(s));
			
		}
		
		if (f & 8) 
		{
			s[i++] = '-';
		}
		j = i; 
		d = (f & 1) ? '0' : ' ';
		while (!(f & 2) && j++ < w) 
		{
			xputc(d);
		}
		
		do 
		{
			xputc(s[--i]); 
		}while(i);
		
		while (j++ < w) 
		{
			xputc(' ');
		}
	}
}


/*----------------------------------------------/
/  xprintf - Formatted string output
/----------------------------------------------*/
/*  
    xprintf("%d", 1234);            "1234"
    xprintf("%6d,%3d%%", -200, 5);  "  -200,  5%"
    xprintf("%-6u", 100);           "100   "
    xprintf("%ld", 12345678L);      "12345678"
    xprintf("%04x", 0xA3);          "00a3"
    xprintf("%08LX", 0x123ABC);     "00123ABC"
    xprintf("%016b", 0x550F);       "0101010100001111"
    xprintf("%s", "String");        "String"
    xprintf("%-4s", "abc");         "abc "
    xprintf("%4s", "abc");          " abc"
    xprintf("%c", 'a');             "a"
    xprintf("%f", 10.0);            <xprintf lacks floating point support>
*/
void xprintf (			/* Put a formatted string to the default device */
	const char*	fmt,	/* Pointer to the format string */
	...					/* Optional arguments */
)
{
#if XPRINTF_ENABLE    
	va_list arp;
	va_start(arp, fmt);
	xvprintf(fmt, arp);
	va_end(arp);
#endif	
}
void trace(int type,const char*fmt,...)
{
    int needOutPut = 0;
    switch(type)
    {
        case PM_TRACE:
          needOutPut = PM_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_PM_ ");
          }
          break;
        case FUN_ENTER:
          needOutPut = FUN_ENTER_SW;
          if(needOutPut)
          {
            xprintf("IN->");
          }
          break;
        case FUN_EXIT:
          needOutPut = FUN_EXIT_SW;
          if(needOutPut)
          {
            xprintf("EX->");
          }
          break;
        case SYS_STATUS_MOD_TRACE:
          needOutPut = SYS_STATUS_MOD_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_STATUS_ ");
          }
          break;
        case SYS_STATE_MOD_TRACE:
          needOutPut = SYS_STATE_MOD_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_STATE_ ");
          }
          break;
        case SYS_MODE_MOD_TRACE:
          needOutPut = SYS_MODE_MOD_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_MODE_ ");
          }
          break;
        case POWER_MNG_MOD_TRACE:
          needOutPut = POWER_MNG_MOD_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_PWRMNG_");
          }
          break;
          
        case ANW_TRACE:
          needOutPut = ANW_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_ANW_");
          }
          break;
        case SYS_INT_TRACE:
          needOutPut = SYS_INT_TRACE_SW;
          if(needOutPut)
          {
            xprintf("_INT_");
          }
          break;
        case DEFAULT_TRACE:
			 needOutPut = DEFAULT_TRACE_SW;
          break;
        case SOC_MESSAGE_TRACE:
          needOutPut = SOC_MESSAGE_TRACE_SW;
          if(needOutPut)
          {
            xprintf("[SOC] ");
          }
        break;
        case APA_STATE:
          needOutPut = APA_STATE_SW;
          if(needOutPut)
          {
            xprintf("[APA_STATE] ");
          }
        break;
        case APA_TRACE:
          needOutPut = APA_TRACE_SW;
          if(needOutPut)
          {
            xprintf("[APA_TRACE] ");
          }
		break;
		case ALG_INPUT:
          needOutPut = ALG_INPUT_SW;
          if(needOutPut)
          {
            xprintf("[I] ");
          }
		break;
		case ALG_OUTPUT:
          needOutPut = ALG_OUTPUT_SW;
          if(needOutPut)
          {
            xprintf("[O] ");
          }
		break;
		case APA_DR:
          needOutPut = APA_DR_SW;
          if(needOutPut)
          {
            xprintf("[APA_DR] ");
          }
		break;
        default:
          break;
    }
    if(TRACE_ENABLE == needOutPut)
    {
        va_list arp;
        va_start(arp, fmt);
        xvprintf(fmt, arp);
        va_end(arp);
    }
    
}

void xsprintf (			/* Put a formatted string to the memory */
	char* buff,			/* Pointer to the output buffer */
	const char*	fmt,	/* Pointer to the format string */
	...					/* Optional arguments */
)
{
	va_list arp;

	outptr = buff;		/* Switch destination for memory */

	va_start(arp, fmt);
	xvprintf(fmt, arp);
	va_end(arp);

	*outptr = 0;		/* Terminate output string with a \0 */
	outptr = 0;			/* Switch destination for device */
}


void xfprintf (					/* Put a formatted string to the specified device */
	void(*func)(unsigned char),	/* Pointer to the output function */
	const char*	fmt,			/* Pointer to the format string */
	...							/* Optional arguments */
)
{
	va_list arp;
	void (*pf)(unsigned char);

	pf = xfunc_out;		/* Save current output device */
	xfunc_out = func;	    /* Switch output to specified device */

	va_start(arp, fmt);
	xvprintf(fmt, arp);
	va_end(arp);

	xfunc_out = pf;		/* Restore output device */
}



/*----------------------------------------------*/
/* Dump a line of binary dump                   */
/*----------------------------------------------*/

void put_dump (
	const void* buff,		/* Pointer to the array to be dumped */
	unsigned long addr,		/* Heading address value */
	int len,				/* Number of items to be dumped */
	int width				/* Size of the items (DF_CHAR, DF_SHORT, DF_LONG) */
)
{
	int i;
	const unsigned char *bp;
	const unsigned short *sp;
	const unsigned long *lp;


	xprintf("%08lX ", addr);		/* address */

	switch (width) {
	case DW_CHAR:
		bp = buff;
		for (i = 0; i < len; i++)		/* Hexdecimal dump */
			xprintf(" %02X", bp[i]);
		xputc(' ');
		for (i = 0; i < len; i++)		/* ASCII dump */
			xputc((bp[i] >= ' ' && bp[i] <= '~') ? bp[i] : '.');
		break;
	case DW_SHORT:
		sp = buff;
		do								/* Hexdecimal dump */
			xprintf(" %04X", *sp++);
		while (--len);
		break;
	case DW_LONG:
		lp = buff;
		do								/* Hexdecimal dump */
			xprintf(" %08LX", *lp++);
		while (--len);
		break;
	}

	xputc('\n');
}

static void debugUartPutByte(U8 ch)
{
  debugUartDrvWrite(&ch, 1);
}



