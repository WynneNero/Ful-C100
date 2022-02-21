#define SRU_HWA

/* Basic Include Path */
//#include <App_TypeDefine.h>
#include <SRU_hwa_Adaptor.h>
#include <SRU_hwa_Controller.h>


void hwa_Init_V( void )
{
    /* Add meaningful code here */
    

    
}

void hwa_Main_T10_V( void )
{

}

void hwa_Main_Tg_V( void )
{

}

void hwa_Main_T20_V( const struct IF_LAF_LDW_OUTPUT_ST* p_sruhwa_IF_LAF_LdwOutput_pst,
                       const struct IF_LOF_ASC_CONTROLREQUEST_ST*  p_sruhwa_IF_LOF_AsfControlRequest_pst
                   )
{
    /* Add meaningful code here */
    sruhwa_if_laf_ldwoutput_T20_read_pst = p_sruhwa_IF_LAF_LdwOutput_pst;
    sruhwa_if_lof_asccontrolrequest_T20_read_pst  = p_sruhwa_IF_LOF_AsfControlRequest_pst;
    

    /* Add your PORT control functions here */


    
    /* de-assign the point defined in Adaptor */
    sruhwa_if_laf_ldwoutput_T20_read_pst = 0;
    sruhwa_if_lof_asccontrolrequest_T20_read_pst = 0;    
}

void HWA_ObjDetectTimerStart(unsigned short wTime, unsigned char ECT_TIM_InitReq) 
{
  TAUJ0_Channel1_start(wTime);

  if(ECT_TIM_InitReq == TRUE)
  {
	  Intp_init();
  }
  
}

void HWA_ObjDetectTimerStop(void) 
{
  TAUJ0_Channel1_stop();

  SnsIntp_DisableAllInt();
}



				   
