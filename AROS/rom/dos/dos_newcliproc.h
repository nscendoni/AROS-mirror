/*
    Copyright � 1995-2011, The AROS Development Team. All rights reserved.
    $Id: dos_newcliproc.h 48995 2014-05-07 18:33:26Z deadwood $

    Desc:
    Lang: English
*/

#ifndef  DOS_NEWCLIPROC_H
#define  DOS_NEWCLIPROC_H

#include <dos/cliinit.h>

/* Shared code between CliInitRun() and CliInitNewcli()
 */
ULONG internal_CliInitAny(struct DosPacket *dp, APTR DOSBase);

struct ExtArg
{
    BPTR    ea_CES;
    LONG    ea_Flags;
};

#define EAF_CLOSECES (1L << 0)

#endif /* DOS_NEWCLIPROC_H */
