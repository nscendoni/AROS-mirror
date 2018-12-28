#ifndef AROS_AROSSUPPORTBASE_H
#define AROS_AROSSUPPORTBASE_H

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif

/*
    Copyright © 1995-2010, The AROS Development Team. All rights reserved.
    $Id: arossupportbase.h 36214 2010-12-23 08:27:33Z sonic $
*/

#include <stdarg.h>

struct AROSSupportBase
{
    void    	    * StdOut;
    int     	    (*kprintf)(const char *, ...);
    int     	    (*rkprintf)(const char *, const char *, int, const char *, ...);
    int     	    (*vkprintf)(const char *, va_list);
    void    	    * DebugConfig;    
};

#endif /* AROS_AROSSUPPORTBASE_H */
