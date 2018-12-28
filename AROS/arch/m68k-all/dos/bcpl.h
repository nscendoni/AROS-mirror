/*
    Copyright © 2010, The AROS Development Team. All rights reserved.
    $Id: bcpl.h 43685 2012-01-20 20:03:26Z jmcmullan $

    Desc: BCPL support
    Lang: english
*/

#define BCPL_GlobVec_NegSize	0xb0
#define BCPL_GlobVec_PosSize	0x21c

/* Our BCPL stub private data */

#define GV_DEBUG_Result2	-0xac
#define GV_DOSBase              0x204   /* Not a function, but a value */

/* We can add private data up to -0x88 */
