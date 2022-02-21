#ifndef _SRU_HWA_ADAPTOR_H_
#define _SRU_HWA_ADAPTOR_H_

/* Include Interfaces here */
#include <SRU_hwa_InterfacesAccess.h>
//#include "App_TypeDefine.h"
#include "ObjDetectCommonDefine.h"


#ifdef SRU_HWA
#define EXTERN
#else
#define EXTERN extern
#endif

/* Read Access Pointer */
EXTERN const struct IF_LAF_LDW_OUTPUT_ST*          sruhwa_if_laf_ldwoutput_T20_read_pst;
EXTERN const struct IF_LOF_ASC_CONTROLREQUEST_ST*  sruhwa_if_lof_asccontrolrequest_T20_read_pst;

extern unsigned long Intp_Init_Time_Point;

/*Macro Define*/

/*Function Define*/


#undef EXTERN
#endif
