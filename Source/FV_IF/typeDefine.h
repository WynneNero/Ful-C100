#ifndef _TYPE_DEFINE_H_
#define _TYPE_DEFINE_H_ 

/**** Definition of constants ****/
/**** Definition of types ****/ 


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef signed char     SInt8;        //        -128 .. +127         ARREF:PLATFORM016
typedef unsigned char   UInt8;        //           0 .. 255          ARREF:PLATFORM013
typedef signed short    SInt16;       //      -32768 .. +32767       ARREF:PLATFORM017
typedef unsigned short  UInt16;       //           0 .. 65535        ARREF:PLATFORM014
typedef signed long     SInt32;       // -2147483648 .. +2147483647  ARREF:PLATFORM018
typedef unsigned long   UInt32;       //           0 .. 4294967295   ARREF:PLATFORM015
typedef unsigned char   Boolean;  


#ifndef NULL
#define NULL          ((void*)0)
#endif

/**** Definition of macros ****/
#ifndef TRUE
#define TRUE         ((BOOL)1)
#endif

#ifndef FALSE
#define FALSE        ((BOOL)0)
#endif

#endif /*_TYPE_DEFINE_H_*/

/****************************** END OF FILE ***************************/

