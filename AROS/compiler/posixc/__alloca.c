/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: __alloca.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/exec.h>

/* private function to get the upper or lower bound (depending on the architecture) of the stack */
/* It has to go into a separate file so that proto/exec.h doesn't get included in the clib headers */

void *__alloca_get_stack_limit(void)
{
    #if AROS_STACK_GROWS_DOWNWARDS
    return FindTask(NULL)->tc_SPLower;
    #else
    return FindTask(NULL)->tc_SPUpper;
    #endif
}

