#ifndef ___EXITFUNC_H
#define ___EXITFUNC_H

/*
    Copyright � 1995-2002, The AROS Development Team. All rights reserved.
    $Id: __exitfunc.h 48031 2013-09-08 21:16:04Z verhaegs $
*/

#include <exec/lists.h>
#include <exec/nodes.h>

struct AtExitNode
{
    struct Node node;
    union
    {
        void (*fvoid)(void);
        void (*fptr)(int, void *);
    } func;
    void *ptr;
};

#define AEN_VOID 0
#define AEN_PTR 1

int __addexitfunc(struct AtExitNode *aen);
void __callexitfuncs(void);

#endif
