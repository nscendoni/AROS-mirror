#ifndef	_POSIXC_UTIME_H_
#define	_POSIXC_UTIME_H_

/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: utime.h 48028 2013-09-08 21:13:29Z verhaegs $

    Desc: POSIX.1-2008 header file utime.h
*/

#include <aros/types/time_t.h>

struct utimbuf {
    time_t actime;		/* Access time */
    time_t modtime;		/* Modification time */
};

__BEGIN_DECLS

int utime(const char *, const struct utimbuf *);

__END_DECLS

#endif /* !_POSIXC_UTIME_H_ */
