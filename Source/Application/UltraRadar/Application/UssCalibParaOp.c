
#include "canDiagService_if.h"
#include "ObjDetectCommonDefine.h"
#include "UssObjDetInterface.h"
#include "Tools.h"   


/***********************************************************************
*  Name 	   :  ReadUSSInternalParameters
*  Description : Read USS Internal Parameters
*  Parameter   : pReadContext: read data ;
*              : dataLen:Read data len( 8 byte)
*  Protocol    :  
*  Returns	   : None	
***********************************************************************/
BOOL ReadUSSInternalParameters(U8 *pReadContext,U8 dataLen)
{
	
	/*e.g:*/
	/* byte0：CMD  
	   byte1：snsIndex
	   byte2~byte7: data
	*/
	U8 USS_para[8] = {0x00};

	
	_memcpy(pReadContext,USS_para, dataLen);

	return TRUE;
}

/***********************************************************************
*  Name 	   :  ReadUSSInternalParameters
*  Description : Read USS Internal Parameters
*  Parameter   : pWriteContext: write data;
*              : dataLen:Read data len( 8 byte)
*  Protocol    :  
*  Returns	   : None	
***********************************************************************/
BOOL WriteUSSInternalParameters(const U8 *pWriteContext,U8 dataLen)
{
	/*e.g:*/
	/* byte0：CMD  
	   byte1：snsIndex
	   byte2~byte7: data
	*/
	U8 USS_para[8] = {0x00};
	
	_memcpy(USS_para, (U8 *)pWriteContext, dataLen);


	/*The data processing*/
	

	return TRUE;
}


SnsCaibDatType getCalibPara(PASysType sysType, SnsIndexType snsIndex)
 {
	SnsCaibDatType dat;
	dat.F_DRV = 0;//106;//g_110
	//dat.I_DRV = 1;
	dat.I_DRV = 0;//snsIndex;
	dat.G_ANA = 0;
	dat.G_DIG = 0;//33;
	dat.CUSTOMER_BITS = 0;//sysType;
	dat.OSC_TRIM = 0;
	dat.reserve1 = 0;
	dat.reserve2 = 0;
	return(dat);
 }








