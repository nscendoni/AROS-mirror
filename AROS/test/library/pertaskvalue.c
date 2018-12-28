/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: pertaskvalue.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/pertask.h>
#include "pertaskbase.h"

void PertaskSetValue(int value)
{
    struct PertaskBase *PertaskBase = (struct PertaskBase *)__aros_getbase_PertaskBase();

    PertaskBase->value = value;
}


int PertaskGetValue(void)
{
    struct PertaskBase *PertaskBase = (struct PertaskBase *)__aros_getbase_PertaskBase();

    return PertaskBase->value;
}
