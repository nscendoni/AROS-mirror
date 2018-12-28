/*
    Copyright © 2009-2012, The AROS Development Team. All rights reserved.
    $Id: peropenertest_child.c 45839 2012-09-19 18:55:57Z verhaegs $
*/
#include <proto/dos.h>
#include <proto/pertask.h>

int main (int argc, char ** argv)
{
    FPuts(Output(), (STRPTR)"\nTesting pertask.library in child\n");

    FPrintf(Output(), (STRPTR)"base=%lx, parent=%lx, parent2=%lx\n",
            __aros_getbase_PertaskBase(),
            GetParentBase(), GetParentBase2()
    );
    
    return 0;
}
