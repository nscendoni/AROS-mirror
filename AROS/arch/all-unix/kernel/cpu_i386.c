/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: cpu_i386.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <signal.h>

#include "kernel_base.h"
#include "kernel_intern.h"

struct SignalTranslation const sigs[] = {
    {SIGILL   ,  4,  6},
    {SIGTRAP  ,  9,  1},
    {SIGBUS   ,  2, 13},
    {SIGFPE   , 11, 16},
    {SIGSEGV  ,  2, 14},
#ifdef HOST_OS_linux
    {SIGSTKFLT, 14, 12},
#endif
    {-1       , -1, -1}
};
