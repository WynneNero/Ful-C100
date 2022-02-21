/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   HiRain Technologies.
************************************************************************************************
*   File Name       : Fls.c
************************************************************************************************
*   Project/Product : Bootloader
*   Title           : Fls driver module Source File
*   Author          : ning.chen
************************************************************************************************
*   Description     : This module is his flash driver used for Bootloader
*
************************************************************************************************
*   Limitations     : Only for Bootloader
*                     
*
************************************************************************************************
*
************************************************************************************************
*   Revision History:
* 
*   Version     Date          Initials          CR#         Descriptions
*   ---------   ----------    ------------  ----------             ---------------
*    01.00.00 | 24/01/2016 | lele.liu    | N/A | BootDrv010001                    Original
*                   
************************************************************************************************
* END_FILE_HDR*/

#include "bl_flash.h"
#include "r_fcl_types.h"
#include "r_fcl.h"
#include "fcl_user.h"
#include "fcl_descriptor.h"
#ifndef IC_RH850_F1K
#include "dr7f701023_0.h"
#endif
#include "iodefine.h"
#include "target.h"
//#include "bl_watchdog.h"

/*********************************************************************************************************************/
/*Macro                                                                                                     */
/*********************************************************************************************************************/    

/*********************************************************************************************************************/
/* HEADER contain version information and 4 driver function pointer   StartAddr +0x20                                */
/*********************************************************************************************************************/
//#if 0
#pragma ghs section rodata = ".R_FCL_CODE_HEAD"
/*different cpu may have different function pointer size,the header type may need to be changed*/

const bl_FlashDrvHeader_t Flashheader  =
{
   
   FLASH_DRIVER_VERSION_TYPE,
   FLASH_DRIVER_VERSION_INDEX,
   FLASH_DRIVER_VERSION_MAGIC,
   FLASH_DRIVER_VERSION_VERSION,
   Flash_Init,

   Flash_Deinit,

   Flash_Erase,

   Flash_Write,

};
#pragma ghs section rodata = default
//#endif


/* This array reserves the copy area in the device RAM */
#define FCL_RAM_EXECUTION_AREA_SIZE (12*1024)

#ifdef IC_RH850_F1K
#define FEED_WDG()  WDTA1WDTE = 0xAC;
#else
#define FEED_WDG()  WDTA1WDTE = 0xAC;
#endif

#if R_FCL_COMPILER == R_FCL_COMP_GHS
    #pragma ghs startdata
    #pragma ghs section bss = ".FCL_RESERVED"
    #define R_FCL_NOINIT
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
    #pragma segment = "FCL_RESERVED"
    #pragma location = "FCL_RESERVED"
    #define R_FCL_NOINIT __no_init
#elif R_FCL_COMPILER == R_FCL_COMP_REC
    #pragma section r0_disp32 "FCL_RESERVED"
    #define R_FCL_NOINIT
#endif

R_FCL_NOINIT uint8_t FCL_Copy_area[FCL_RAM_EXECUTION_AREA_SIZE];

#if R_FCL_COMPILER == R_FCL_COMP_GHS
    #pragma ghs section bss = default
    #pragma ghs enddata
#elif R_FCL_COMPILER == R_FCL_COMP_IAR
    #pragma dataseg = default
#elif R_FCL_COMPILER == R_FCL_COMP_REC
    #pragma section default
#endif


/*********************************************************************************************************************/
/* DriverCode                                                                                                        */
/*********************************************************************************************************************/

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : FlashInit
*
* Description   : Flash moudle init 
*
* Inputs        : fp:standard HIS input parameters structure
*
* Outputs       : None
* 
* Limitations   : None
*                 
************************************************************************************************
END_FUNCTION_HDR */
#pragma ghs section text = ".R_FCL_CODE_USR"
void  Flash_Init(bl_FlashDrvParam_t* fp)
{
    r_fcl_request_t     myRequest;
    r_fcl_status_t ret;

#if (defined R_FCL_DEVICE_SPECIFIC_INIT)
    R_FCL_DEVICE_SPECIFIC_INIT
#endif
    
    /* Set for hardware watchdog */
    //PM8 &= ~(1<<2);/* output mode*/
        
    ret = R_FCL_Init (&sampleApp_fclConfig_enu);
    if( R_FCL_OK == ret)
    {
        R_FCL_CopySections();
    }
    
    fp->errCode = BL_ERR_OK;   
}

void  Flash_Env_Prepare(bl_FlashDrvParam_t* fp)
{
    r_fcl_request_t     myRequest;

    FCLUser_Open ();
 /* prepare environment */
    myRequest.command_enu = R_FCL_CMD_PREPARE_ENV;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
    while (R_FCL_BUSY == myRequest.status_enu)
    {
        R_FCL_Handler ();
    }
    #endif
}

/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : FlashDeinit
*
* Description   : Flash moudle deinit 
*
* Inputs        : fp:standard HIS input parameters structure
*
* Outputs       : None
* 
* Limitations   : None
*                 
************************************************************************************************
END_FUNCTION_HDR */
void  Flash_Deinit(bl_FlashDrvParam_t* fp)
{
    (void)fp;
    FCLUser_Close ();
    fp->errCode = BL_ERR_OK;   
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : FlashErase
*
* Description   : Flash moudle erase
*
* Inputs        : fp:standard HIS input parameters structure
*
* Outputs       : None
* 
* Limitations   : erase  block
*                 
************************************************************************************************
END_FUNCTION_HDR */
bl_u32_t block_start;
bl_u32_t block_end;


bl_u32_t g_addr_start;
bl_u32_t g_addr_end;

bl_u32_t step_value[6];

#define CodeFlashZone 2

#if CodeFlashZone == 0

	#define CodeFlashMax 0x80000 /*512k*/

#elif CodeFlashZone == 1

	#define CodeFlashMax 0x100000 /*1024k*/
#elif CodeFlashZone == 2

	#define CodeFlashMax 0x200000 /*1024k*F1K/

#else

	#define CodeFlashMax 0x60000 /*384k*/
	
#endif

void  Flash_Erase(bl_FlashDrvParam_t* fp)
{
    bl_u32_t addr_start ,address_end;
    bl_u32_t BlockNum,BlockNum_start,BlockNum_end; 
    r_fcl_request_t     myRequest;
    
    addr_start = fp->address;
    address_end = (fp->size + addr_start -1);

    g_addr_start = fp->address;
    g_addr_end = address_end;

    block_start = 0x00;
    block_end = 0x00;
    
    if((addr_start < CodeFlashMax))//0x80000))
    {
        if(0 == (addr_start & 0xFFFF0000))  /* block0~block7,8kb per block */
        {
            BlockNum_start = (addr_start >> 13);// block = addr/8K
            
            if( address_end < 0x10000)    /* address_end in block0~block7 */
            {
                BlockNum_end = (address_end >> 13);
            }
            else if((address_end >= 0x10000)&&(address_end < CodeFlashMax))//0x80000)) /* address_end in block8~block21 */
            {
                BlockNum_end = ((address_end >> 15) + 6);
            }
            else
            {
                BlockNum_end = 21;
            }
            BlockNum = BlockNum_end - BlockNum_start + 1;
        }
        else if(addr_start & 0x007F0000)    /* block8~block21,32kb per block */
        {
            step_value[0] = addr_start;
            step_value[1] = (addr_start >> 15);
            step_value[2] = (addr_start >> 15)+6;

            step_value[3] = address_end;
            step_value[4] = (address_end >> 15);
            step_value[5] = (address_end >> 15)+6;
            
            BlockNum_start = ((addr_start >> 15) + 6);
            
            if(address_end < CodeFlashMax)//0x80000) /* address_end in block8~block21 */
            {
                BlockNum_end = ((address_end >> 15) + 6);
            }
            else
            {
                BlockNum_end = 21;
            }
            
            BlockNum = BlockNum_end - BlockNum_start + 1;
        }
        else
        {
            
        }
       
        FEED_WDG();               

        /* erase block */
        myRequest.command_enu = R_FCL_CMD_ERASE;
        myRequest.idx_u32     = BlockNum_start;  /* erase start  */
        myRequest.cnt_u16     = BlockNum;

        block_start = BlockNum_start;
        block_end = BlockNum_end;
        R_FCL_Execute (&myRequest);
        #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            FEED_WDG(); 
        }
        #endif
        fp->errCode = BL_ERR_OK;
                
    }
    else
    {
        fp->errCode = BL_ERR_NOT_OK;
    }
    
}
/* BEGIN_FUNCTION_HDR
************************************************************************************************
* Function Name : Flash_Write
*
* Description   : Flash moudle write 
*
* Inputs        : fp:standard HIS input parameters structure
*
* Outputs       : None
* 
* Limitations   : write 256 * n bytes 
*                 
************************************************************************************************
END_FUNCTION_HDR */

void  Flash_Write(bl_FlashDrvParam_t* fp)
{    
    bl_u32_t addr = fp->address;
    bl_u32_t source = (bl_u32_t)(fp->buffer);
    bl_Size_t size = fp->size;
    r_fcl_request_t     myRequest;
    bl_u16_t cnt = (size / 256);

//    if((addr < 0x80000) && ((size % 256) == 0))
	if((addr < CodeFlashMax) && ((size % 256) == 0))
    {
        FEED_WDG(); 

        myRequest.command_enu = R_FCL_CMD_WRITE;
        myRequest.bufferAdd_u32 = source;
        myRequest.idx_u32       = addr;
        myRequest.cnt_u16       = cnt;                    /* written bytes = 256 * cnt_u16 */
        R_FCL_Execute (&myRequest);
        #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            FEED_WDG(); 
        }
        #endif
       
        fp->errCode = BL_ERR_OK;
    }
    else
    {
        fp->errCode = BL_ERR_NOT_OK;
    }
}


#pragma ghs section text = default
// uint32_t   (* fpFct)(void);
uint32_t  (* flash_drv_ptr)(bl_FlashDrvParam_t* fp);

/***********************************************************************
*  Name        : Flash_Ram_Init
*  Description :       
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Flash_Ram_Init(uint32_t ram_addr, bl_FlashDrvParam_t* fp) 
{
		
	    Flash_Init(fp);
	    flash_drv_ptr = ( uint32_t (*)(bl_FlashDrvParam_t* ))R_FCL_CalcFctAddr ((uint32_t)(&Flash_Env_Prepare));
		__DI();
	    flash_drv_ptr(fp);
   		__EI();
}
/***********************************************************************
*  Name        : Flash_Ram_Erase
*  Description :       
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Flash_Ram_Erase(uint32_t ram_addr, bl_FlashDrvParam_t* fp) 
{
    flash_drv_ptr = ( uint32_t (*)(bl_FlashDrvParam_t* ))R_FCL_CalcFctAddr ((uint32_t)(&Flash_Erase));
    __DI();
    flash_drv_ptr(fp);
    __EI();
}

/***********************************************************************
*  Name        : Flash_Ram_Write
*  Description :       
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Flash_Ram_Write(uint32_t ram_addr, bl_FlashDrvParam_t* fp) 
{
    flash_drv_ptr = ( uint32_t (*)(bl_FlashDrvParam_t* ))R_FCL_CalcFctAddr ((uint32_t)(&Flash_Write));
    __DI();
    flash_drv_ptr(fp);
    __EI();
}

/***********************************************************************
*  Name        : Flash_Ram_Deinit
*  Description :       
*  Parameter   : None
*  Returns     : None
***********************************************************************/
void Flash_Ram_Deinit(uint32_t ram_addr, bl_FlashDrvParam_t* fp) 
{
    flash_drv_ptr = ( uint32_t (*)(bl_FlashDrvParam_t* ))R_FCL_CalcFctAddr ((uint32_t)(&Flash_Deinit));
    flash_drv_ptr(fp);
}

#if 0

void FCL_Ctrl(void);

r_fcl_status_t ret;

uint8_t state_list[5];

uint32_t            readBuffer_u32[8];
uint8_t             writeBuffer_u08[512]={0,1,2,3,4,5,6,7,8,9,0};
#pragma ghs section text = ".R_FCL_CODE_USR"
void FCL_Ctrl (void)
{
    r_fcl_request_t     myRequest;
#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        r_fcl_request_t mySecRequest;
#endif
    uint16_t            i;

    //REINITIALIZE_BUFFER;

#if 0
    FCLUser_Open ();

    /* prepare environment */
    myRequest.command_enu = R_FCL_CMD_PREPARE_ENV;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            state_list[0] = 1;
            WDTA1WDTE = 0xAC;        /* Feed watchdog. */
            //P8 = (((~P8) & 0x4)|(P8 & 0xfffb)); /* Feed hardware watchdog. */
        }
    #endif
#endif
    /* get block count */
    myRequest.command_enu   = R_FCL_CMD_GET_BLOCK_CNT;
    myRequest.bufferAdd_u32 = (uint32_t)&readBuffer_u32[0];
    R_FCL_Execute (&myRequest);

    /* get block end address of block 2 */
    //REINITIALIZE_BUFFER;
    myRequest.command_enu   = R_FCL_CMD_GET_BLOCK_END_ADDR;
    myRequest.bufferAdd_u32 = (uint32_t)&readBuffer_u32[0];
    myRequest.idx_u32       = 0x2;                   /* result: 0x5fff */
    R_FCL_Execute (&myRequest);


 /* erase block 2 and 3 */
    myRequest.command_enu = R_FCL_CMD_ERASE;
    myRequest.idx_u32     = 0x4;                   /* erased range = 0x4000 to 0x7fff */
    myRequest.cnt_u16     = 2;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            state_list[1] = 2;
            WDTA1WDTE = 0xAC;        /* Feed watchdog. */
            //P8 = (((~P8) & 0x4)|(P8 & 0xfffb)); /* Feed hardware watchdog. */
        }
    #endif


    /* write 512 bytes to address 0x40000 (start of block 2) */
   // REINITIALIZE_BUFFER;
    writeBuffer_u08[0] = writeBuffer_u08[1] = 0xaa;
    myRequest.command_enu = R_FCL_CMD_WRITE;
    myRequest.bufferAdd_u32 = (uint32_t)&writeBuffer_u08[0];
    myRequest.idx_u32       = 0x4000;
    myRequest.cnt_u16       = 2;                    /* written bytes = 256 * cnt_u16 */
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            state_list[2] = 3;
            WDTA1WDTE = 0xAC;        /* Feed watchdog. */
            //P8 = (((~P8) & 0x4)|(P8 & 0xfffb)); /* Feed hardware watchdog. */
        }
    #endif
    

    /* erase block 2 and 3 */
    myRequest.command_enu = R_FCL_CMD_ERASE;
    //myRequest.idx_u32     = 0x4;                   /* erased range = 0x4000 to 0x7fff */
    myRequest.idx_u32     = 14+3;                     /*0X70000, 448K*/
    myRequest.cnt_u16     = 2;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            state_list[1] = 2;
            WDTA1WDTE = 0xAC;        /* Feed watchdog. */
            //P8 = (((~P8) & 0x4)|(P8 & 0xfffb)); /* Feed hardware watchdog. */
        }
    #endif


    /* write 512 bytes to address 0x40000 (start of block 2) */
   // REINITIALIZE_BUFFER;
    writeBuffer_u08[0] = writeBuffer_u08[1] = 0x55;
    myRequest.command_enu = R_FCL_CMD_WRITE;
    myRequest.bufferAdd_u32 = (uint32_t)&writeBuffer_u08[0];
    //myRequest.idx_u32       = 0x4000;
    myRequest.idx_u32       = 0x70000;
    myRequest.cnt_u16       = 2;                    /* written bytes = 256 * cnt_u16 */
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        while (R_FCL_BUSY == myRequest.status_enu)
        {
            R_FCL_Handler ();
            state_list[2] = 3;
            WDTA1WDTE = 0xAC;        /* Feed watchdog. */
            //P8 = (((~P8) & 0x4)|(P8 & 0xfffb)); /* Feed hardware watchdog. */
        }
    #endif

    FCLUser_Close ();
} 
#pragma ghs section text = default




void FCL_main_Ex (void)
{
    r_fcl_status_t ret;
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
        uint32_t   (* fpFct)(void);
    #endif
    uint32_t addr, size;
    bl_FlashDrvParam_t param;
    bl_u32_t checkValue;
    r_fcl_request_t     myRequest;

    //Flash_Init(&param);
    //ret = param.errCode;

#if (defined R_FCL_DEVICE_SPECIFIC_INIT)
    R_FCL_DEVICE_SPECIFIC_INIT
#endif
    
    /* Set for hardware watchdog */
    //PM8 &= ~(1<<2);/* output mode*/
        
    ret = R_FCL_Init (&sampleApp_fclConfig_enu);
    if( R_FCL_OK == ret)
    {
        R_FCL_CopySections();
    }

    FCLUser_Open ();
    /* prepare environment */
    myRequest.command_enu = R_FCL_CMD_PREPARE_ENV;
    R_FCL_Execute (&myRequest);
    #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
    while (R_FCL_BUSY == myRequest.status_enu)
    {
        R_FCL_Handler (); 
    }
    #endif

    if (R_FCL_OK == ret)
    {
        #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
            fpFct = ( uint32_t (*)() )R_FCL_CalcFctAddr ( (uint32_t)(&Flash_Env_Prepare) );
            fpFct();
            fpFct = ( uint32_t (*)() )R_FCL_CalcFctAddr ( (uint32_t)(&FCL_Ctrl) );
            fpFct();
        #else
            Flash_Env_Setup();
            FCL_Ctrl();
        #endif
    }

    addr = 0x4000;
    size = 512;
    while (1)
    {
        /* do nothing */
        //Flash_Read(addr, &writeBuffer_u08, size);
    }
} /* main */

/******************************************************************************
* Function Name : void FCL_main( void )
* Description   : 
* Argument      : none
* Return Value  : none
******************************************************************************/
void FCL_main(void)
{
    r_fcl_status_t ret;
#if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
    uint32_t   (* fpFct)(void);
#endif
    bl_FlashDrvParam_t param;

    Flash_Init(&param);
    ret = param.errCode;
    
    //R_FCL_INIT_CPU_AND_FPERIPHERAL_CLK// initialize CPU and clocks 

    #if (defined R_FCL_DEVICE_SPECIFIC_INIT)
        R_FCL_DEVICE_SPECIFIC_INIT
    #endif

    ret = R_FCL_Init (&sampleApp_fclConfig_enu);
    if (R_FCL_OK == ret)
    {
        ret = R_FCL_CopySections ();
    }

    if (R_FCL_OK == ret)
    {
        
        #if R_FCL_COMMAND_EXECUTION_MODE == R_FCL_HANDLER_CALL_USER
            fpFct = ( uint32_t (*)() )R_FCL_CalcFctAddr ( (uint32_t)(&FCL_Ctrl) );
            fpFct();
        #else
            FCL_Ctrl ();
        #endif
	
    }

  
} 
#endif
    
