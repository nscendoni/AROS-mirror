/*
    Copyright � 1995-2013, The AROS Development Team. All rights reserved.
    $Id: cachepostdma.c 47740 2013-07-20 11:30:00Z mazze $

    Desc: CachePostDMA() - Do what is necessary for DMA.
    Lang: english
*/

#define DEBUG 0

#include <aros/debug.h>
#include <exec/types.h>
#include <exec/execbase.h>
#include <aros/libcall.h>

#include <proto/exec.h>

/* See rom/exec/cachepostdma.c for documentation */

AROS_LH3(void, CachePostDMA,
    AROS_LHA(APTR,    address, A0),
    AROS_LHA(ULONG *, length,  A1),
    AROS_LHA(ULONG,   flags,  D0),
    struct ExecBase *, SysBase, 128, Exec)
{
    AROS_LIBFUNC_INIT

    D(bug("[exec] CachePostDMA(%08x, %d, %c)\n", address, *length, flags & DMA_ReadFromRAM ? 'R':'W'));

    if (!(flags & DMA_ReadFromRAM))
        CacheClearE(address, *length, CACRF_InvalidateD | CACRF_ClearI);

    AROS_LIBFUNC_EXIT
} /* CachePostDMA */

