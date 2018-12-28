/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: host_mmu.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <windows.h>

#include "host_intern.h"

/*
 * A simple glue code. I'm too lazy to import kernel32.dll via hostlib.resource
 * just for one function.
 */

unsigned int __declspec(dllexport) __aros core_protect(void *addr, unsigned int len, unsigned int prot)
{
    DWORD oldprot;

    return VirtualProtect(addr, len, prot, &oldprot);
}

