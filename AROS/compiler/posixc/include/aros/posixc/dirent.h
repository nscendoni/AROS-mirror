#ifndef _POSIXC_DIRENT_H_
#define _POSIXC_DIRENT_H_

/*
    Copyright � 1995-2012, The AROS Development Team. All rights reserved.
    $Id: dirent.h 53132 2016-12-29 10:32:06Z deadwood $

    Desc: POSIX.1-2008 header file dirent.h
*/

#include <aros/system.h>

/* FIXME: Is this allowed ? */
#include <limits.h>

#include <aros/types/ino_t.h>
#include <aros/types/off_t.h>

#ifndef _POSIX_SOURCE
/* These defines seems quite common althoug not defined by POSIX.1-2008
   so we define these by default
*/

/* d_type */
#define DT_UNKNOWN     0
#define DT_FIFO        1
#define DT_CHR         2
#define DT_DIR         4
#define DT_BLK         6
#define DT_REG         8
#define DT_LNK        10
#define DT_SOCK       12
#define DT_WHT        14

#endif /* !_POSIX_SOURCE */

/* ABI_V0 compatibility */
struct dirent
{
    ino_t   d_ino;
    unsigned short int d_reclen;
    unsigned char d_type;
#define MAXNAMLEN NAME_MAX
    char    d_name[MAXNAMLEN + 1];  /* name must be no longer than this */
};


/* structure describing an open directory. */
struct __dirdesc;
typedef struct __dirdesc DIR;

__BEGIN_DECLS

/* NOTIMPL int alphasort(const struct dirent **a, const struct dirent **b); */
int closedir(DIR *dir);
int dirfd(DIR *dir);
/* NOTIMPL DIR *fdopendir(int); */
DIR *opendir(const char *filename);
struct dirent *readdir(DIR *dir);
/* NOTIMPL int readdir_r(DIR *restrict, struct dirent *restrict, struct dirent **restrict); */
void rewinddir(DIR *dir);
/* NOTIMPL int scandir (const char *dir, struct dirent ***namelist,
              int (*select)(const struct dirent *),
              int (*compar)(const struct dirent **, const struct dirent **)); */
void seekdir(DIR *dir, off_t loc);
long telldir(DIR *dir);

__END_DECLS

#endif /* !_POSIXC_DIRENT_H_ */
