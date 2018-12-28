#ifndef PKG_BZIP2_PRIVATE_H
#define PKG_BZIP2_PRIVATE_H

/*
    Copyright © 2003, The AROS Development Team. All rights reserved.
    $Id: bzip2_private.h 50095 2015-02-19 13:24:18Z polluks $
*/

#include <exec/types.h>
#include <dos/bptr.h>

#include <bzlib.h>

struct bzFile
{
    BPTR      bzf_File;
    bz_stream bzf_Stream;
    APTR      bzf_Buffer;
    LONG      bzf_BufferAmount;
};

#endif /* PKG_BZIP2_PRIVATE_H */
