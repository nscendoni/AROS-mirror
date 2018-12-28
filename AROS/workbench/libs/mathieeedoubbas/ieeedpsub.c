/*
    Copyright © 1995-2003, The AROS Development Team. All rights reserved.
    $Id: ieeedpsub.c 47354 2013-05-04 17:12:25Z mazze $
*/

#include "mathieeedoubbas_intern.h"

/*****************************************************************************

    NAME */

        AROS_LHQUAD2(double, IEEEDPSub,

/*  SYNOPSIS */
        AROS_LHAQUAD(double, y, D0, D1),
        AROS_LHAQUAD(double, z, D2, D3),

/*  LOCATION */
        struct MathIeeeDoubBasBase *, MathIeeeDoubBasBase, 12, MathIeeeDoubBas)

/*  FUNCTION
        Subtracts two IEEE double precision numbers

    INPUTS

    RESULT
       +1 : y > z
        0 : y = z
       -1 : y < z

        Flags:
          zero     : y = z
          negative : y < z
          overflow : 0

    BUGS

    INTERNALS

*****************************************************************************/
{
    AROS_LIBFUNC_INIT

    QUAD * Qz = (QUAD *)&z;
    
    XOR64QC(*Qz, IEEEDPSign_Mask_Hi, IEEEDPSign_Mask_Lo );
    return IEEEDPAdd(y,z);

    AROS_LIBFUNC_EXIT
}
