/*
    Copyright © 2012-2013, The AROS Development Team. All rights reserved.
    $Id: __stdcio_stdstreams.c 48044 2013-09-08 21:18:52Z verhaegs $

    Get pointer to standard IO streams.
    These function is both in static linklib as in stdcio.library.
*/
#include <libraries/stdcio.h>

#include <stdio.h>

FILE *__stdio_getstdin(void)
{
    return __aros_getbase_StdCIOBase()->_stdin;
}

FILE *__stdio_getstdout(void)
{
    return __aros_getbase_StdCIOBase()->_stdout;
}

FILE *__stdio_getstderr(void)
{
    return __aros_getbase_StdCIOBase()->_stderr;
}
