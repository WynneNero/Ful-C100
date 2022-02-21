#ifndef _SRU_HWA_CONTROLLER_H_
#define _SRU_HWA_CONTROLLER_H_

/* Include Interfaces here */
#include <SRU_hwa_InterfacesAccess.h>

/* INI function */
void hwa_Init_V( void );

/* T10 main function */
void hwa_Main_T20_V( const struct IF_LAF_LDW_OUTPUT_ST* p_sruhwa_IF_LAF_LdwOutput_pst,
                     const struct IF_LOF_ASC_CONTROLREQUEST_ST*  p_sruhwa_IF_LOF_AsfControlRequest_pst
                   );

void hwa_Main_T10_V( void );

void hwa_Main_Tg_V( void );


#endif
