/*
    Copyright © 2010-2011, The AROS Development Team. All rights reserved.
    $Id: filesystem.h 43200 2011-12-23 10:13:53Z sonic $

    Desc: Declarations of filesystem-related routines
    Lang: english
*/

char *namepart(char *name);
FILE *file_open (const char *filename, const char *mode);
int SetLog(const char *filename);
