#ifndef _POSIXC_SYS_TIMEB_H_
#define _POSIXC_SYS_TIMEB_H_
/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: timeb.h 48028 2013-09-08 21:13:29Z verhaegs $

    Desc: POSIX.1-2001 header file <sys/timeb.h>
          This is deprecated and not present anymore in POSIX.1-2008
*/

#include <aros/system.h>

#include <aros/types/time_t.h>

struct timeb
{
    time_t	    time;
    unsigned short  millitm;
    short	    timezone;
    short	    dstflag;
};

__BEGIN_DECLS

int ftime(struct timeb *tp);

__END_DECLS

#endif /* _POSIXC_SYS_TIMEB_H_ */
