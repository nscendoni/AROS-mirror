/*
    Copyright © 1995-2001, The AROS Development Team. All rights reserved.
    $Id: debug.h 30792 2009-03-07 22:40:04Z neil $
*/

#ifndef __DEBUG_H
#define __DEBUG_H

/* Debug Macros */

#ifdef __AROS__

#undef DEBUG
#define DEBUG 1
#include <aros/debug.h>

#else /* __AROS__ */

#define bug kprintf

#ifdef MYDEBUG
void kprintf(char *string, ...);
#define D(x) {kprintf("%s/%ld (%s): ", __FILE__, __LINE__, FindTask(NULL)->tc_Node.ln_Name);(x);};
#else
#define D(x) ;

#endif /* MYDEBUG */

#endif /*__AROS__ */

#endif /* __DEBUG_H */
