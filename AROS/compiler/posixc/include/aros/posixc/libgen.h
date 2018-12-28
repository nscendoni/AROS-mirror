/*
    Copyright © 2008, The AROS Development Team. All rights reserved.
    $Id: libgen.h 48028 2013-09-08 21:13:29Z verhaegs $

    POSIX.1-2008 header file libgen.h
*/

#ifndef _POSIXC_LIBGEN_H
#define _POSIXC_LIBGEN_H

#include <aros/system.h>

__BEGIN_DECLS

char *basename(char *);
char *dirname(char *);

__END_DECLS

#endif /* _POSIXC_LIBGEN_H */
