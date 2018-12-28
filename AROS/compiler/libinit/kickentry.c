/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: kickentry.c 49667 2014-09-30 17:35:27Z neil $
*/

/*
 * This is the special version of entry code for kickstart modules.
 * The difference is declaration of absolute SysBase symbol.
 * Note that the bootstrap can relocate this symbol if necessary.
 */

#include <aros/system.h>

int __startup __kick_entry(void)
{
    return -1;
}

asm(".globl SysBase\n"
    ".set SysBase, 4");
