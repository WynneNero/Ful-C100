/*------------------------------------------------------------------------------

    File Name: can_sig_ops.c

    CAN signal data manipulating functions implementation.
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


#include "can_sig_ops.h"


/*------------------------------------------------------------------------------
    Function:
        raw_to_phy

    Descriptions:
        Converts raw value to physical value.
        Formula: [phy_val] = [raw_val] * [factor] + [offset]

    Parameters:
        raw_val [in]    - raw value
        factor  [in]    - factor
        offset  [in]    - offset
        is_signed [in]  - defined whether the raw_value is a signed value.
        bitlen [in]     - signal bit length.

    Return:
        Converted physical value.

    Example:
        #define SIGNAL_A_factor         0.05625
        #define SIGNAL_A_offset         0
        #define SIGNAL_A_signed         1
        #define SIGNAL_A_bitlen         8
        SIGNAL_A actual value is 0xFE, which represents -2 in physical.

        1. Call this function
            --> raw_val = 0x000000FE    (8bit -> 32bit unsigned int
            --> shift count = 4 * 8 - 8 = 24
        2. Force convert raw_val to 'signed int', after left shift 24 bits
            --> raw_val = 0xFE000000
        3. Because this MSB is 1, shifting right will add 1s to the MSB (arithmetic shift)
            --> raw_val = 0xFFFFFFFE
        4. now the tmp_val matches the actual value of SIGNAL_A, which is -2
        5. runs the calculation and returns the float type value (float is signed).
-------------------------------------------------------------------------------*/
float raw_to_phy(unsigned int raw_val, float factor, float offset, unsigned char is_signed, unsigned char bitlen)
{
    unsigned char shift_count = 0;
    signed int tmp_val = 0;

    if (is_signed)
    {
        /* Add 1s to the MSB by shifting if the value is negative*/
        shift_count = sizeof(unsigned int) * 8 - bitlen;
        tmp_val = ((signed int)raw_val << shift_count) >> shift_count;

        return tmp_val * factor + offset;
    }
    else
    {
        return raw_val * factor + offset;
    }
}


/*------------------------------------------------------------------------------
    Function:
        phy_to_raw

    Descriptions:
        Converts physical value to raw value.
        Formula: [raw_val] = ([phy_val] - [offset]) / [factor]

    Parameters:
        phy_val [in]    - physical value
        factor  [in]    - factor
        offset  [in]    - offset

    Return:
        Converted raw value.
-------------------------------------------------------------------------------*/
unsigned int phy_to_raw(float phy_val, float factor, float offset)
{
    return ((phy_val - offset) / factor);
}


