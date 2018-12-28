#ifndef _POSIXC_STRING_H_
#define _POSIXC_STRING_H_

/*
    Copyright © 2012-2013, The AROS Development Team. All rights reserved.
    $Id: string.h 48052 2013-09-08 21:19:58Z verhaegs $

    Desc: C99/POSIX.1-2008 header file string.h
*/
#include <aros/stdc/string.h>

__BEGIN_DECLS

char * __posixc_strerror (int n);

__END_DECLS

#endif /* _POSIXC_STRING_H_ */
