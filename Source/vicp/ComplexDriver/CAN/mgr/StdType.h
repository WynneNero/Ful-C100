
/******************************************************************************************************
*                 Standard Types Define
*    (c)Copyright 2014,Auto-Electric SOFTEC HEFEI Research CO.,Ltd.
*                  All Rights Reserved
* File : StdType.h

    Date         Author       Version                  Description 
 2014.05.05    Zhiyan Xiao    1.00.00        Initialization Version.
*******************************************************************************************************/

#ifndef    _StdType_H_
#define    _StdType_H_
/**************************************** Macro Define **************************************************/
//Auto SAR CPU.
#define    CPU_TYPE_8               8
#define    CPU_TYPE_16              16
#define    CPU_TYPE_32              32

#define    MSB_FIRST                0
#define    LSB_FIRST                1

#define    HIGH_BYTE_FIRST          0
#define    LOW_BYTE_FIRST           1

#define    CPU_TYPE                 CPU_TYPE_32
#define    CPU_BIT_ORDER            MSB_FIRST
#define    CPU_BYTE_ORDER           HIGH_BYTE_FIRST


//Software ID Store Length.
#define    SOFTWARE_ID_STORE_DATA_LENGTH         40u
//Sofware Part Number ID Data Length.
#define    ECU_SOFTWARE_PART_NUM_DATA_LENGTH     16u
//Software Type Defien.
#define    SOFTWARE_TYPE_APP                     ('A')
#define    SOFTWARE_TYPE_BOOT                    ('B')
#define    SOFTWARE_TYPE_CALIBRATION             ('C')
#define    SOFTWARE_TYPE_FLASH_DRV               ('F')
#define    SOFTWARE_TYPE_SOFTWARE_PART           ('P')
#define    SOFTWARE_TYPE_ALL                     ('S')
//True.
#ifndef    TRUE
#define    TRUE                                  1u
#endif
//False.
#ifndef    FALSE
#define    FALSE                                 0u
#endif
//ON - OFF State.
#define    STD_ON                                1u
#define    STD_OFF                               0u
//Standard Error State.
#define    E_OK                                  0u
#define    E_NOT_OK                              1u
#define    E_BUSY                                2u
#define    E_SELF_TEST_FAULT                     3u
#define    E_DATA_OVERFLOW                       4u
#define    E_INPUT_OUTOFRANGE                    5u
#define    E_CHECKSUM_FAULT                      6u
#define    E_DATA_NOT_INITLIZITE                 7u
#define    E_TIME_OUT                            8u
//System Hareware Failture Status.
#define    SYSTEN_HARDWARE_NORMAL                0x00
#define    SYSTEN_HARDWARE_FAULT                 0x01
#define    SYSTEN_HARDWARE_STATUS_UNKNOW         0x02
/********************************************************************************************************/

/**************************************** Type redefine type *******************************************/
//Boolean type.
typedef    unsigned char                  Boolean;
typedef    unsigned char                  boolean;
//8 Bits Integer.
//typedef    unsigned char                  uchar;
typedef    unsigned char                  uint8;
//typedef    volatile unsigned char         vuint8;
//typedef    signed char                    schar;
typedef    signed char                    sint8;
typedef    signed int*                    p_uint8;
typedef    unsigned char*                 p_uchar;
typedef    signed int*                    p_sint8;
typedef    signed char*                   p_schar;
//16 Bits Integer.
typedef    unsigned short int             uint;
typedef    unsigned short int             uint16;
//typedef    volatile unsigned short int    vuint16;
typedef    signed short int               sint;
typedef    signed short int               sint16;
typedef    unsigned short int*            p_uint;
typedef    unsigned short int*            p_uint16;
typedef    signed short int*              p_sint;
typedef    signed short int*              p_sint16;
//32 Bits Integer.
//typedef    unsigned long                  ulong;
typedef    unsigned long                  uint32;
//typedef    volatile unsigned long         vuint32;
//typedef    signed long                    slong;
typedef    signed long                    sint32;
typedef    unsigned long*                 p_ulong;
typedef    signed long*                   p_slong;
//64 Bits Integer.
typedef    unsigned long long             uint64;
typedef    volatile unsigned long long    vuint64;
//32 Bits Float.
typedef    float                          flt32;
typedef    float                          float32;
typedef    float                          real32;
//64 Bits Float.
typedef    double                         flt64;
typedef    double                         float64;
typedef    double                         real64;
//Standard Function Return Data Type.
//typedef    uint32                         Std_ReturnType;
//CPU Integer Type.
typedef    uint32                         CPU_IntType;
//Software Version DataType.
typedef    struct{
   uint8   SoftwareId[SOFTWARE_ID_STORE_DATA_LENGTH]; //Software ID.
   uint8   D_Seperation1;                        //'-'.
   uint8   SoftwareType;                         //Software Type.
   uint8   D_Seperation2;                        //'-'.
   uint8   SoftWareReleaseDate[8];               //Software Release Date.
   uint8   D_Seperation3;                        //'-'.
   uint8   FirstVerID;                           //First Version ID.
   uint8   V_Seperation1;                        //'.'.
   uint8   SecondVerID[2];                       //Second Version ID.
   uint8   V_Seperation2;                        //'.'.
   uint8   ThirdVerID[2];                        //Third Version ID.
}Std_SoftwareVersionDataType;
//
#ifndef  NULL
#define  NULL    ((void *)0)
#endif
/*********************************************************************************************************/
#endif
