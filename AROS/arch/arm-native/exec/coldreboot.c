/*
    Copyright � 2013, The AROS Development Team. All rights reserved.
    $Id: coldreboot.c 47740 2013-07-20 11:30:00Z mazze $

    Desc: ColdReboot() - Reboot the computer.
    Lang: english
*/

#include <exec/types.h>
#include <exec/execbase.h>
#include <exec/tasks.h>
#include <aros/libcall.h>

#include <proto/exec.h>

#include "exec_intern.h"
#include "exec_util.h"

/* See rom/exec/coldreboot.c for documentation */

AROS_LH0(void, ColdReboot,
    struct ExecBase *, SysBase, 121, Exec)
{
    AROS_LIBFUNC_INIT

    Exec_DoResetCallbacks((struct IntExecBase *)SysBase, SD_ACTION_WARMREBOOT);

    asm volatile("mov pc,#0;");

    AROS_LIBFUNC_EXIT
}
