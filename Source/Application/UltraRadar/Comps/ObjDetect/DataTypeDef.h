

#ifndef _H_SSAETYPE
#define _H_SSAETYPE


/***********Inhibit the following defines when sw release**************/

#define SUPPORT_UPA_ACTIVE_BY_MODULE_ID



/************Open the following defines when sw release**********/

#define MCU_RH850_BIT_STRUCT

#define SENSOR_ELMOS            
#define UPA_WITH_GMLAN

/************Choose the kind of version from following defines when sw release**********/
//#define D2XX_SUPPORT_D2SC_CAL
#define D2XX_SUPPORT_D2UB_CAL

#define APA_SYSTEM_WITH_12_CH


#ifndef NULL
# define NULL ((void*)0)
#endif


#ifndef FALSE
	#define  FALSE  0
#endif
#ifndef TRUE
	#define  TRUE   1
#endif

#ifndef FAILURE
	#define FAILURE 0
#endif
#ifndef SUCCESS
	#define SUCCESS 	1
#endif


//typedef unsigned char      					BOOL;

typedef unsigned char      					BOOLEAN;

typedef unsigned char      					UINT8;
typedef unsigned short    					UINT16;
typedef unsigned long   					UINT32;
typedef unsigned long long					UINT64;

typedef signed char      					SINT8;
typedef signed short    					SINT16;
typedef signed long   						SINT32;
typedef signed long long					SINT64;

typedef volatile signed char 				VINT8;
typedef volatile signed short 				VINT16;
typedef volatile signed long 				VINT32;
typedef volatile signed long long 			VINT64;

typedef volatile unsigned short 			VUINT16;
typedef volatile unsigned long 				VUINT32;
typedef volatile unsigned long long 		VUINT64;

typedef unsigned char   					UBYTE;
typedef signed   char   					SBYTE;
typedef unsigned short  					USHORT;
typedef signed   short  					SSHORT;

typedef unsigned char 						UCHAR;
typedef unsigned short/*int*/ 				WORD;
typedef unsigned long 						DWORD;
typedef long double 						DDWORD;

typedef unsigned char 						byte;
typedef unsigned short/*int*/ 				word;
typedef unsigned long 						dword;
typedef long double 						ddword;

typedef unsigned char      					uchar;
typedef unsigned long      					ulong;

typedef signed char        					schar;
typedef signed long        					slong;


/* decompose 16 bit data in byte stream */
#define GetHiByte(data)                                  ((uchar)(((word)(data))>>8))
#define GetLoByte(data)                                 	((uchar)(data))

/* decompose 32 bit data in byte stream */
#define GetHiHiByte(data)                                ((uchar)(((dword)(data))>>24))
#define GetHiLoByte(data)                                ((uchar)(((dword)(data))>>16))
#define GetLoHiByte(data)                                ((uchar)(((dword)(data))>>8))
#define GetLoLoByte(data)                                ((uchar)(data))


typedef union {
	byte bt;
	struct {
		byte  BIT0        :1;
		byte  BIT1        :1;
		byte  BIT2        :1;
		byte  BIT3        :1;
		byte  BIT4        :1;
		byte  BIT5        :1;
		byte  BIT6        :1;
		byte  BIT7        :1;
	} Bits;
} tAPAByteBitType;

typedef union {
	word Word;
	struct {
		word  BIT0        :1;
		word  BIT1        :1;
		word  BIT2        :1;
		word  BIT3        :1;
		word  BIT4        :1;
		word  BIT5        :1;
		word  BIT6        :1;
		word  BIT7        :1;
		word  BIT8        :1;
		word  BIT9        :1;
		word  BIT10       :1;
		word  BIT11       :1;
		word  BIT12       :1;
		word  BIT13       :1;
		word  BIT14       :1;
		word  BIT15       :1;
	} Bits;
} tAPAWordBitType;



#endif 

