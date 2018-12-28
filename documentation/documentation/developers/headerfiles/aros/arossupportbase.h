#ifndef AROS_AROSSUPPORTBASE_H
#define AROS_AROSSUPPORTBASE_H

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: arossupportbase.h 30800 2009-03-08 17:28:50Z neil $
*/

#include <stdarg.h>

struct AROSSupportBase
{
    void    	    * StdOut;
    int     	    (*kprintf)(const char *, ...);
    int     	    (*rkprintf)(const char *, const char *, int, const char *, ...);
    int     	    (*vkprintf)(const char *, va_list);
    void    	    * DebugConfig;    
    struct MinList  AllocMemList;
};

#endif /* AROS_AROSSUPPORTBASE_H */
