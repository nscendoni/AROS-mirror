#ifndef _POSIXC_SYS_UIO_H_
#define _POSIXC_SYS_UIO_H_
/*
    Copyright © 1995-2012, The AROS Development Team. All rights reserved.
    $Id: uio.h 48028 2013-09-08 21:13:29Z verhaegs $

    Desc: POSIX.1-2008 header file <sys/uio.h>
*/

#include <aros/system.h>

#include <aros/types/iovec_s.h>
#include <aros/types/ssize_t.h>

__BEGIN_DECLS

ssize_t readv(int fd, const struct iovec *iovec, int count);
ssize_t writev(int fd, const struct iovec *iovec, int count);

__END_DECLS

#endif /* _POSIXC_SYS_UIO_H_ */
