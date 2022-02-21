/*------------------------------------------------------------------------------

    File Name: can_sig_ops.h

    CAN signal data manipulation functions definition.
--------------------------------------------------------------------------------
                       A U T H O R   I D E N T I T Y
--------------------------------------------------------------------------------
    Author          User ID
    --------        --------
    Sun Yilin       uida3867        Desay SV HZH / IDA R&D

--------------------------------------------------------------------------------
                      R E V I S I O N   H I S T O R Y
--------------------------------------------------------------------------------
    Date        Ver     Author      Description
    ----------  ---     ------      --------------------------------------------
    2018-2-10   1.0     uida3867    Initial version.

--------------------------------------------------------------------------------
                           C O P Y R I G H T
--------------------------------------------------------------------------------
         Copyright (c) 2018 by Huizhou Desay SV Automotive Co., Ltd.
                          All rights reserved.
------------------------------------------------------------------------------*/


#ifndef _CAN_SIG_OPS_H_
#define _CAN_SIG_OPS_H_


/* Macros */
/*----------------------------------------------------------------------------*/

#define get_sig_value_raw(x)        IlGetRx##x()
#define get_sig_value_phy(x)        raw_to_phy(IlGetRx##x(), x##_factor, x##_offset, x##_signed, x##_bitlen)
#define set_sig_value_raw(x, val)   IlPutTx##x(val)
#define set_sig_value_phy(x, val)   IlPutTx##x(phy_to_raw(val, x##_factor, x##_offset))


/* Functions */
/*----------------------------------------------------------------------------*/

float raw_to_phy(unsigned int raw_val, float factor, float offset, unsigned char is_signed, unsigned char bitlen);
unsigned int phy_to_raw(float phy_val, float factor, float offset);


#endif  /* _CAN_SIG_OPS_H_ */

