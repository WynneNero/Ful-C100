/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.		       
*				  All Rights Reserved.                 
*   Department :  CT AD NKG      				     
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   : Functions in General Port Mode
***********************************************************************/
/*-History--------------------------------------------------------------
* Version  Date   	 Name        Changes and comments
------------------------------------------------------------------------
* 0.1	   Apr 28,2016   PEI Jingli  Initial version
------------------------------------------------------------------------
* 0.2	   Jun 29,2016   LIU Chenxi  Correct errors during merging	
------------------------------------------------------------------------
* 0.3	   July 07,2016  PEI Jingli  Adapt 64pin MCU
* ----------------------------------------------------------------------
* 0.4      July 07,2016  LIU Chenxi  Refine code structure
*=====================================================================*/


//============================================================================
// Includes
//============================================================================

#ifndef  _IRQ_H
#define  _IRQ_H
#include "config.h"
#include "define.h"


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                        DEFAULT CONFIGURATION
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/
                                                                /* ------------------- BIT DEFINES -------------------- */
#define  DEF_BIT_NONE                                   0x00u

#define  DEF_BIT_00                                     0x01u
#define  DEF_BIT_01                                     0x02u
#define  DEF_BIT_02                                     0x04u
#define  DEF_BIT_03                                     0x08u
#define  DEF_BIT_04                                     0x10u
#define  DEF_BIT_05                                     0x20u
#define  DEF_BIT_06                                     0x40u
#define  DEF_BIT_07                                     0x80u

#define  DEF_BIT_08                                   0x0100u
#define  DEF_BIT_09                                   0x0200u
#define  DEF_BIT_10                                   0x0400u
#define  DEF_BIT_11                                   0x0800u
#define  DEF_BIT_12                                   0x1000u
#define  DEF_BIT_13                                   0x2000u
#define  DEF_BIT_14                                   0x4000u
#define  DEF_BIT_15                                   0x8000u

#define  DEF_BIT_16                               0x00010000u
#define  DEF_BIT_17                               0x00020000u
#define  DEF_BIT_18                               0x00040000u
#define  DEF_BIT_19                               0x00080000u
#define  DEF_BIT_20                               0x00100000u
#define  DEF_BIT_21                               0x00200000u
#define  DEF_BIT_22                               0x00400000u
#define  DEF_BIT_23                               0x00800000u

#define  DEF_BIT_24                               0x01000000u
#define  DEF_BIT_25                               0x02000000u
#define  DEF_BIT_26                               0x04000000u
#define  DEF_BIT_27                               0x08000000u
#define  DEF_BIT_28                               0x10000000u
#define  DEF_BIT_29                               0x20000000u
#define  DEF_BIT_30                               0x40000000u
#define  DEF_BIT_31                               0x80000000u

#define  DEF_BIT_SET_08(val, mask)                     ((val) = (CPU_INT08U)(((CPU_INT08U)(val)) | ((CPU_INT08U) (mask))))

#define  DEF_BIT_SET_16(val, mask)                     ((val) = (CPU_INT16U)(((CPU_INT16U)(val)) | ((CPU_INT16U) (mask))))

#define  DEF_BIT_SET_32(val, mask)                     ((val) = (CPU_INT32U)(((CPU_INT32U)(val)) | ((CPU_INT32U) (mask))))

#define  DEF_BIT_SET_64(val, mask)                     ((val) = (CPU_INT64U)(((CPU_INT64U)(val)) | ((CPU_INT64U) (mask))))

#define  DEF_BIT_SET(val, mask)                 ((sizeof(val) == CPU_WORD_SIZE_08) ? DEF_BIT_SET_08(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_16) ? DEF_BIT_SET_16(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_32) ? DEF_BIT_SET_32(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_64) ? DEF_BIT_SET_64(val, mask) : 0))))

#define  DEF_BIT_CLR_08(val, mask)                     ((val) = (CPU_INT08U)(((CPU_INT08U)(val)) & ((CPU_INT08U)~(mask))))

#define  DEF_BIT_CLR_16(val, mask)                     ((val) = (CPU_INT16U)(((CPU_INT16U)(val)) & ((CPU_INT16U)~(mask))))

#define  DEF_BIT_CLR_32(val, mask)                     ((val) = (CPU_INT32U)(((CPU_INT32U)(val)) & ((CPU_INT32U)~(mask))))

#define  DEF_BIT_CLR_64(val, mask)                     ((val) = (CPU_INT64U)(((CPU_INT64U)(val)) & ((CPU_INT64U)~(mask))))

#define  DEF_BIT_CLR(val, mask)                 ((sizeof(val) == CPU_WORD_SIZE_08) ? DEF_BIT_CLR_08(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_16) ? DEF_BIT_CLR_16(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_32) ? DEF_BIT_CLR_32(val, mask) :     \
                                                ((sizeof(val) == CPU_WORD_SIZE_64) ? DEF_BIT_CLR_64(val, mask) : 0))))

#if 0
typedef  struct _IRQTABLE
{
 U8 IRQNo;
 Func_Void_Proc isrproc;
}IRQTable;
#endif
/*  when 2 interruput sources for one interruput channel, selected the 1st one. */
#define SELB_INTC_1ST    1
//ISR No. for F1L 100 pin

#define INTTAUD0I0 (0+8)
#define INTTAUD0I2 (1+8)
#define INTTAUD0I4 (2+8)
#define INTTAUD0I6 (3+8)
#define INTTAUD0I8 (4+8)
#define INTTAUD0I10 (5+8)
#define INTTAUD0I12 (6+8)
#define INTTAUD0I14 (7+8)
#define INTTAPA0IPEK0 (8+8)
#define INTTAPA0IVLY0 (9+8)
#define INTADCA0I0 (10+8)
#define INTADCA0I1 (11+8)
#define INTADCA0I2 (12+8)
#define INTDCUTDI (13+8)
#define INTRCANGERR (14+8)
#define INTRCANGRECC (15+8)
#define INTRCAN0ERR (16+8)
#define INTRCAN0REC (17+8)
#define INTRCAN0TRX (18+8)
#define INTCSIG0IC (19+8)
#define INTCSIG0IR (20+8)
#define INTCSIH0IC (21+8)
#define INTCSIH0IR (22+8)
#define INTCSIH0IRE (23+8)
#define INTCSIH0IJC (24+8)
#define INTRLIN30 (25+8)
#define INTRLIN30UR0 (26+8)
#define INTRLIN30UR1 (27+8)
#define INTRLIN30UR2 (28+8)
#define INTP0 (29+8)
#define INTP1 (30+8)
#define INTP2 (31+8)
#define INTWDTA0 (32+8)
#define INTWDTA1 (33+8)
#define INTRESERVED42     42
#define INTP3 (34+9)
#define INTP4 (35+9)
#define INTP5 (36+9)
#define INTP10 (37+9)
#define INTP11 (38+8)
#define INTTAUD0I1 (39+9)
#define INTTAUD0I3 (40+9)
#define INTTAUD0I5 (41+9)
#define INTTAUD0I7 (42+9)
#define INTTAUD0I9 (43+9)
#define INTTAUD0I11 (44+9)
#define INTTAUD0I13 (45+9)
#define INTTAUD0I15 (46+9)
#define INTADCA0ERR (47+9)

#define INTCSIG0IRE (49+8)
#define INTRLIN20 (50+8)
#define INTRLIN21 (51+8)
#define INTDMA0 (52+8)
#define INTDMA1 (53+8)
#define INTDMA2 (54+8)
#define INTDMA3 (55+8)
#define INTDMA4 (56+8)
#define INTDMA5 (57+8)
#define INTDMA6 (58+8)
#define INTDMA7 (59+8)
#define INTDMA8 (60+8)
#define INTDMA9 (61+8)
#define INTDMA10 (62+8)
#define INTDMA11 (63+8)
#define INTDMA12 (64+8)
#define INTDMA13 (65+8)
#define INTDMA14 (66+8)
#define INTDMA15 (67+8)
#define INTRIIC0TI (68+8)
#define INTRIIC0TEI (69+10)
#define INTRIIC0RI (70+8)
#define INTRIIC0EE (71+6)
#define INTTAUJ0I0 (72+8)
#define INTTAUJ0I1 (73+8)
#define INTTAUJ0I2 (74+8)
#define INTTAUJ0I3 (75+8)
#define INTOSTM0 (76+8)
#define INTENCA0IOV_PWGA4 (77+8)
#define INTENCA0IUD_PWGA5 (78+8)
#define INTENCA0I0_PWGA6 (79+8)
#define INTENCA0I1_PWGA7 (80+8)
#define INTENCA0IEC (81+8)
#define INTKR0 (82+8)
#define INTQFULL (83+8)
#define INTPWGA0 (84+8)
#define INTPWGA1 (85+8)
#define INTPWGA2 (86+8)
#define INTPWGA3 (87+8)
#define INTPWGA8 (88+8)
#define INTPWGA9 (89+8)
#define INTPWGA10 (90+8)
#define INTPWGA11 (91+8)
#define INTPWGA12 (92+8)
#define INTPWGA13 (93+8)
#define INTPWGA14 (94+8)
#define INTPWGA15 (95+8)

#define INTFLERR (102+8)
#define INTFLENDNM (103+8)
#define INTCWEND (104+8)
#define INTRCAN1ERR (105+8)
#define INTRCAN1REC (106+8)
#define INTRCAN1TRX (107+8)
#define INTCSIH1IC (108+8)
#define INTCSIH1IR (109+8)
#define INTCSIH1IRE (110+8)
#define INTCSIH1IJC (111+8)
#define INTRLIN31 (112+8)
#define INTRLIN31UR0 (113+8)
#define INTRLIN31UR1 (114+8)
#define INTRLIN31UR2 (115+8)
#define INTPWGA20 (116+8)
#define INTPWGA21 (117+8)
#define INTPWGA22 (118+8)
#define INTPWGA23 (119+8)
#define INTP6 (120+8)
#define INTP7 (121+8)
#define INTP8 (122+8)
#define INTP12 (123+8)
#define INTCSIH2IC (124+8)
#define INTCSIH2IR (125+8)
#define INTCSIH2IRE (126+8)
#define INTCSIH2IJC (127+8)

#define INTTAUB0I0 (134+8)
#define INTTAUB0I1 (135+8)
#define INTTAUB0I2 (136+8)
#define INTTAUB0I3_PWGA16 (137+8)
#define INTTAUB0I4 (138+8)
#define INTTAUB0I5_PWGA17 (139+8)
#define INTTAUB0I6 (140+8)
#define INTTAUB0I7_PWGA18 (141+8)
#define INTTAUB0I8 (142+8)
#define INTTAUB0I9_PWGA19 (143+8)
#define INTTAUB0I10 (144+8)
#define INTTAUB0I11_PWGA26 (145+8)
#define INTTAUB0I12 (146+8)
#define INTTAUB0I13_PWGA30 147+8
#define INTTAUB0I14 148+8
#define INTTAUB0I15_PWGA31 (149+8)
#define INTCSIH3IC (150+8)
#define INTCSIH3IR (151+8)
#define INTCSIH3IRE (152+8)
#define INTCSIH3IJC (153+8)
#define INTRLIN22 (154+8)

#define INTRLIN32 164//(156+8)
#define INTRLIN32UR0 165//(157+8)
#define INTRLIN32UR1 166//(158+8)
#define INTRLIN32UR2 167//(159+8)
#define INTTAUJ1I0 (160+8)
#define INTTAUJ1I1 (161+8)
#define INTTAUJ1I2 (162+8)
#define INTTAUJ1I3 (163+8)

#define INTPWGA24 (176+8)
#define INTPWGA25 (177+8)
#define INTPWGA27 (178+8)
#define INTPWGA28 (179+8)
#define INTPWGA29 (180+8)
#define INTPWGA32 (181+8)
#define INTPWGA33 (182+8)
#define INTPWGA34 (183+8)
#define INTPWGA35 (184+8)
#define INTPWGA36 (185+8)
#define INTPWGA37 (186+8)
#define INTPWGA38 (187+8)
#define INTPWGA39 (188+8)
#define INTPWGA40 (189+8)
#define INTPWGA41 (190+8)
#define INTPWGA42 (191+8)
#define INTPWGA43 (192+8)
#define INTPWGA44 (193+8)
#define INTPWGA45 (194+8)
#define INTPWGA46 (195+8)
#define INTPWGA47 (196+8)
#if ( MCU_PIN > PIN100 )
#define INTP9 (197+8)
#endif
#define INTP13 (198+8)
#if ( MCU_PIN > PIN100 )
#define INTP14 (199+8)
#define INTP15 (200+8)
#endif

#define Reserved (208+8)
#define INTRCAN2ERR (209+8)
#define INTRCAN2REC (210+8)
#define INTRCAN2TRX (211+8)

#define INTRLIN33 (220+8)
#define INTRLIN33UR0 (221+8)  //UART3 TX
#define INTRLIN33UR1 (222+8)
#define INTRLIN33UR2 (223+8)

#define IRQ_INT_ID_MAX       (INTRLIN33UR2+1)

/* ------------ INTERRUPT PRIORITY DEFINES ---------- */
//#define  IRQ_INT_PRIO_LEVEL_MASK             DEF_BIT_MASK(15, 0)
#define  IRQ_INT_PRIO_LEVEL_00               0u
#define  IRQ_INT_PRIO_LEVEL_01               1u
#define  IRQ_INT_PRIO_LEVEL_02               2u
#define  IRQ_INT_PRIO_LEVEL_03               3u
#define  IRQ_INT_PRIO_LEVEL_04               4u
#define  IRQ_INT_PRIO_LEVEL_05               5u
#define  IRQ_INT_PRIO_LEVEL_06               6u
#define  IRQ_INT_PRIO_LEVEL_07               7u
#define  IRQ_INT_PRIO_LEVEL_08               8u
#define  IRQ_INT_PRIO_LEVEL_09               9u
#define  IRQ_INT_PRIO_LEVEL_10               10u
#define  IRQ_INT_PRIO_LEVEL_11               11u
#define  IRQ_INT_PRIO_LEVEL_12               12u
#define  IRQ_INT_PRIO_LEVEL_13               13u
#define  IRQ_INT_PRIO_LEVEL_14               14u
#define  IRQ_INT_PRIO_LEVEL_15               15u


#define  IRQ_INT_MASK_SRC_OFFSET_00       0   //0x80u

#define IRQ_INT_REG_ICxx_BASE                  ( (U32 )0xFFFEEA00u)  //F1K
//address not continous
#define IRQ_INT_REG_ICxx_BASE_SEC           ( (U32 )0xFFFFB040u)   //F1L  ( (U32 )0xFFFFA040u)

#define IRQ_INT_REG_ICxx(n)                     (*(U16 *)((n>31)?(IRQ_INT_REG_ICxx_BASE_SEC + 2 * (n-32)) : (IRQ_INT_REG_ICxx_BASE + 2 * n))	)

#define IRQ_INT_ICxx_EIMKn                       DEF_BIT_07
#define IRQ_INT_ICxx_EITBn                       DEF_BIT_06
#define IRQ_INT_ICxx_EIRFn                       DEF_BIT_12
/*
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void IRQ_Init_Setup (void);
void IRQ_IntClr           (U8     int_id);
void IRQ_IntDis           (U8     int_id);
void IRQ_IntEn            (U8     int_id);
void IRQ_IntVectReg       (U8     int_id,U8     prio);
void IRQ_IntDisAll        (void);
void  IRQ_IntClrAll        (void);
//void IRQ_IntHandler       (U32     src_nbr);
void IRQ_IntHandler       (void);
void IRQ_IntHandlerDummy (void);
/*
*********************************************************************************************************
*                                              ERROR CHECKING
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/

#endif                                                          /* End of module include.                               */

