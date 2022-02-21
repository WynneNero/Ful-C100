/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : RN R&D SW1      									   *
*   AUTHOR	   : Shao Guangxian										   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   : Interface of IRQ module.
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date    Name    Changes and comments
* ----------------------------------------------------------------------
* 0.1    Aug 01,2016 PEI Jingli      Iinitial version
* ----------------------------------------------------------------------
* 0.2    Nov 30,2016 PEI Jingli      Add interface of IRQ_IntEnableAll
* ----------------------------------------------------------------------
* 0.3    Dec 06,2016 PEI Jingli      Merge changes from REN Weimin after code review
* ----------------------------------------------------------------------
* 0.4    Dec 20,2016 ShangQiuju  remove other module used define here
*----------------------------------------------------------------------
* 0.5    Jan 24,2017  ZhangJie     Fix Coverity warning.
*=====================================================================*/

#ifndef _IRQ_IF_H_
#define _IRQ_IF_H_
#include "Define.h"   

#if 1//def IC_RH850_F1K

#define INTTAUD0I0  	((U16)(0+8))
#define INTTAUD0I2  	((U16)(1+8))
#define INTTAUD0I4  	((U16)(2+8))
#define INTTAUD0I6  	((U16)(3+8))
#define INTTAUD0I8  	((U16)(4+8))
#define INTTAUD0I10     ((U16)(5+8))
#define INTTAUD0I12     ((U16)(6+8))
#define INTTAUD0I14     ((U16)(7+8))
#define INTTAPA0IPEK0 	((U16)(8+8))
#define INTTAPA0IVLY0 	((U16)(9+8))
#define INTADCA0I0 		((U16)(10+8))
#define INTADCA0I1 		((U16)(11+8))
#define INTADCA0I2 		((U16)(12+8))
#define INTDCUTDI   	((U16)(13+8))
#define INTRCANGERR   	((U16)(14+8))
#define INTRCANGRECC 	((U16)(15+8))
#define INTRCAN0ERR   	((U16)(16+8))
#define INTRCAN0REC   	((U16)(17+8))
#define INTRCAN0TRX   	((U16)(18+8))
#define INTCSIG0IC   	((U16)(19+8))
#define INTCSIG0IR   	((U16)(20+8))
#define INTCSIH0IC   	((U16)(21+8))
#define INTCSIH0IR   	((U16)(22+8))
#define INTCSIH0IRE 	((U16)(23+8))
#define INTCSIH0IJC  	((U16)(24+8)
#define INTRLIN30     	((U16)(25+8)
#define INTRLIN30UR0 	((U16)(26+8))
#define INTRLIN30UR1 	((U16)(27+8))
#define INTRLIN30UR2 	((U16)(28+8))
#define INTP0 			((U16)(29+8))
#define INTP1 			((U16)(30+8))
#define INTP2 			((U16)(31+8))
#define INTWDTA0 		((U16)(32+8))
#define INTWDTA1 		((U16)(33+8))
#define INTRESERVED42   ((U16)42)
#define INTP3   		((U16)(34+9))
#define INTP4   		((U16)(35+9))
#define INTP5   		((U16)(36+9))
#define INTP10 			((U16)(37+9))
#define INTP11 			((U16)(38+9))	
#define INTTAUD0I1   	((U16)(39+9))
#define INTTAUD0I3   	((U16)(40+9))
#define INTTAUD0I5   	((U16)(41+9))
#define INTTAUD0I7   	((U16)(42+9))
#define INTTAUD0I9   	((U16)(43+9))
#define INTTAUD0I11 	((U16)(44+9))
#define INTTAUD0I13 	((U16)(45+9))
#define INTTAUD0I15 	((U16)(46+9))
#define INTADCA0ERR 	((U16)(47+9))

#define INTCSIG0IRE 	((U16)(49+8))
#define INTRLIN20     	((U16)(50+8))
#define INTRLIN21     	((U16)(51+8))
#define INTDMA0 ((U16)(52+8))
#define INTDMA1 ((U16)(53+8))
#define INTDMA2 ((U16)(54+8))
#define INTDMA3 ((U16)(55+8))
#define INTDMA4 ((U16)(56+8))
#define INTDMA5 ((U16)(57+8))
#define INTDMA6 ((U16)(58+8))
#define INTDMA7 ((U16)(59+8))
#define INTDMA8  ((U16)(60+8))
#define INTDMA9  ((U16)(61+8))
#define INTDMA10  ((U16)(62+8))
#define INTDMA11  ((U16)(63+8))
#define INTDMA12  ((U16)(64+8))
#define INTDMA13  ((U16)(65+8))
#define INTDMA14  ((U16)(66+8))
#define INTDMA15  ((U16)(67+8))
#define INTRIIC0TI   ((U16)(68+8))
#define INTRIIC0TEI ((U16)(69+10))
#define INTRIIC0RI  ((U16)(70+8))
#define INTRIIC0EE ((U16)(71+6))
#define INTTAUJ0I0 ((U16)(72+8)) //80
#define INTTAUJ0I1 ((U16)(73+8)) //81
#define INTTAUJ0I2 ((U16)(74+8)) //82
#define INTTAUJ0I3 ((U16)(75+8))
#define INTOSTM0    ((U16)(76+8))
#define INTENCA0IOV_PWGA4 ((U16)(77+8))
#define INTENCA0IUD_PWGA5 ((U16)(78+8))
#define INTENCA0I0_PWGA6   ((U16)(79+8))
#define INTENCA0I1_PWGA7   ((U16)(80+8))
#define INTENCA0IEC ((U16)(81+8))
#define INTKR0         ((U16)(82+8))
#define INTQFULL     ((U16)(83+8))
#define INTPWGA0    ((U16)(84+8))
#define INTPWGA1    ((U16)(85+8))
#define INTPWGA2    ((U16)(86+8))
#define INTPWGA3    ((U16)(87+8))
#define INTPWGA8    ((U16)(88+8))
#define INTPWGA9    ((U16)(89+8))
#define INTPWGA10  ((U16)(90+8))
#define INTPWGA11  ((U16)(91+8))
#define INTPWGA12  ((U16)(92+8))
#define INTPWGA13  ((U16)(93+8))
#define INTPWGA14  ((U16)(94+8))
#define INTPWGA15  ((U16)(95+8))

#define INTFLERR         ((U16)(102+8))
#define INTFLENDNM   ((U16)(103+8))
#define INTCWEND       ((U16)(104+8))
#define INTRCAN1ERR  ((U16)(105+8))
#define INTRCAN1REC  ((U16)(106+8))
#define INTRCAN1TRX  ((U16)(107+8))
#define INTCSIH1IC     ((U16)(108+8))
#define INTCSIH1IR     ((U16)(109+8))
#define INTCSIH1IRE   ((U16)(110+8))
#define INTCSIH1IJC    ((U16)(111+8))
#define INTRLIN31       ((U16)(112+8))
#define INTRLIN31UR0  ((U16)(113+8))
#define INTRLIN31UR1  ((U16)(114+8))
#define INTRLIN31UR2  ((U16)(115+8))
#define INTPWGA20  ((U16)(116+8))
#define INTPWGA21  ((U16)(117+8))
#define INTPWGA22  ((U16)(118+8))
#define INTPWGA23  ((U16)(119+8))
#define INTP6           ((U16)(120+8))
#define INTP7           ((U16)(121+8))
#define INTP8           ((U16)(122+8))
#define INTP12         ((U16)(123+8))
#define INTCSIH2IC  ((U16)(124+8))
#define INTCSIH2IR  ((U16)(125+8))
#define INTCSIH2IRE   ((U16)(126+8))
#define INTCSIH2IJC  ((U16)(127+8))

#define INTTAUB0I0 ((U16)(134+8)) //142
#define INTTAUB0I1 ((U16)(135+8))
#define INTTAUB0I2 ((U16)(136+8)) //144
#define INTTAUB0I3_PWGA16  ((U16)(137+8))
#define INTTAUB0I4  ((U16)(138+8))  //146
#define INTTAUB0I5  ((U16)(139+8))  //147
#define INTTAUB0I6  ((U16)(140+8)) //148
#define INTTAUB0I7  ((U16)(141+8)) //149
#define INTTAUB0I8  ((U16)(142+8)) //150
#define INTTAUB0I9_PWGA19  ((U16)(143+8))
#define INTTAUB0I10  ((U16)(144+8)) //152
#define INTTAUB0I11_PWGA26  ((U16)(145+8))
#define INTTAUB0I12  ((U16)(146+8)) //154
#define INTTAUB0I13  ((U16)(147+8)) //155
#define INTTAUB0I14  ((U16)(148+8)) //156
#define INTTAUB0I15  ((U16)(149+8)) //157
#define INTCSIH3IC         ((U16)(150+8))
#define INTCSIH3IR         ((U16)(151+8))
#define INTCSIH3IRE       ((U16)(152+8))
#define INTCSIH3IJC       ((U16)(153+8))
#define INTRLIN22          ((U16)(154+8))

#define INTRLIN32        ((U16)(156+8))
#define INTRLIN32UR0  ((U16)(157+8))
#define INTRLIN32UR1  ((U16)(158+8))
#define INTRLIN32UR2  ((U16)(159+8))
#define INTTAUJ1I0  ((U16)(160+8))
#define INTTAUJ1I1  ((U16)(161+8))
#define INTTAUJ1I2  ((U16)(162+8))
#define INTTAUJ1I3  ((U16)(163+8))

#define INTPWGA24  ((U16)(176+8))
#define INTPWGA25  ((U16)(177+8))
#define INTPWGA27  ((U16)(178+8))
#define INTPWGA28  ((U16)(179+8))
#define INTPWGA29  ((U16)(180+8))
#define INTPWGA32  ((U16)(181+8))
#define INTPWGA33  ((U16)(182+8))
#define INTPWGA34  ((U16)(183+8))
#define INTPWGA35  ((U16)(184+8))
#define INTPWGA36  ((U16)(185+8))
#define INTPWGA37  ((U16)(186+8))
#define INTPWGA38  ((U16)(187+8))
#define INTPWGA39  ((U16)(188+8))
#define INTPWGA40  ((U16)(189+8))
#define INTPWGA41  ((U16)(190+8))
#define INTPWGA42  ((U16)(191+8))
#define INTPWGA43  ((U16)(192+8))
#define INTPWGA44  ((U16)(193+8))
#define INTPWGA45  ((U16)(194+8))
#define INTPWGA46  ((U16)(195+8))
#define INTPWGA47  ((U16)(196+8))
#if ( MCU_PIN > PIN100 )
#define INTP9  ((U16)(197+8))
#endif
#define INTP13  ((U16)(198+8))
#if ( MCU_PIN > PIN100 )
#define INTP14  ((U16)(199+8))
#define INTP15  ((U16)(200+8))
#endif

#define Reserved      ((U16)(208+8))
#define INTRCAN2ERR   ((U16)(209+8))
#define INTRCAN2REC   ((U16)(210+8))
#define INTRCAN2TRX   ((U16)(211+8))

#define INTRLIN33     ((U16)(220+8))
#define INTRLIN33UR0  ((U16)(221+8))
#define INTRLIN33UR1  ((U16)(222+8))
#define INTRLIN33UR2  ((U16)(223+8))

#define INTRLIN34     ((U16)(224+8))
#define INTRLIN34UR0  ((U16)(225+8))
#define INTRLIN34UR1  ((U16)(226+8))
#define INTRLIN34UR2  ((U16)(227+8))

#define INTRCAN4ERR   ((U16)(272))
#define INTRCAN4REC   ((U16)(273))
#define INTRCAN4TRX   ((U16)(274))

#else

#endif

//#define IRQ_INT_ID_MAX       (INTRLIN33UR2+1ul)
#define IRQ_INT_ID_MAX       (289+1ul)		//WYJ

extern void IRQ_Init_Setup (void);
extern void IRQ_IntClr           (U16     int_id);
extern void IRQ_IntDis           (U16     int_id);
extern void IRQ_IntEn            (U16     int_id);
extern void IRQ_IntDisAll        (void);
extern void IRQ_IntEnableAll 	 (void);
extern void IRQ_IntClrAll        (void);

#endif
/****************************** END OF FILE ***************************/
