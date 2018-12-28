#ifndef	_UTIME_H_
#define	_UTIME_H_
/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: utime.h 32359 2010-01-16 22:25:24Z verhaegs $

    Desc: ANSI-C header file utime.h
    Lang: english
*/

#include <sys/types/time_t.h>

struct utimbuf {
	time_t actime;		/* Access time */
	time_t modtime;		/* Modification time */
};

__BEGIN_DECLS
int utime(const char *filename, struct utimbuf *buf);
__END_DECLS

#endif /* !_UTIME_H_ */
