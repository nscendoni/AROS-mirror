/*
    Copyright � 2000, The AROS Development Team. All rights reserved.
    $Id: x86_NatSemi.c 48533 2013-12-06 21:24:19Z jmcmullan $

    Desc: Probe installed National Semiconductor  Geode CPUs and display relevant information
    Lang: english
*/

/* BIG TO DO - SEPERATE THE INDIVIDUAL PROCESSOR FAMILY "PROBES" INTO RUNTIME SHARED LIBS OR SIMILAR */

/****************************************************************************************************
     Currently Supports:

        i386 compatable families...
            National Semiconductor  Geode

*****************************************************************************************************/

#include "x86.h"

/********************************************
 National Semiconductor  specific information
 ********************************************/

void    parse_i386_NSC( int maxi, struct i386_compat_intern * CPUi386 )
{

    struct  CPU_INTERN_DATA *global;
    ULONG __unused__        speed;

    if ((global = AllocMem(sizeof(struct CPU_INTERN_DATA),MEMF_PUBLIC|MEMF_CLEAR)))
    {
            speed = i386_approx_mhz();
    }
    else
    {
        printf( "ERROR: Couldn't allocate memory to parse CPU information .." );
        return;
    }
    FreeMem(global,sizeof(struct CPU_INTERN_DATA));

}
