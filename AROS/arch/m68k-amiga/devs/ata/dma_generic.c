/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: dma_generic.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <exec/types.h>

#include "ata.h"

/* We don't need DMA support (but there has to be more optimal solution..) */

LONG dma_Setup(APTR addr, ULONG len, BOOL read, struct PRDEntry* array)
{
    return 0;
}

BOOL dma_SetupPRD(struct ata_Unit *unit, APTR buffer, ULONG sectors, BOOL io)
{
    return FALSE;
}

BOOL dma_SetupPRDSize(struct ata_Unit *unit, APTR buffer, ULONG size, BOOL read)
{
    return FALSE;
}

VOID dma_Cleanup(APTR addr, ULONG len, BOOL read)
{
}

VOID dma_StartDMA(struct ata_Unit *unit)
{
}

VOID dma_StopDMA(struct ata_Unit *unit)
{
}
