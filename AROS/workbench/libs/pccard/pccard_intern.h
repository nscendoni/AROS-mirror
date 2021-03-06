/*
    Copyright � 2011, The AROS Development Team. All rights reserved.
    $Id: pccard_intern.h 48674 2014-01-02 17:51:04Z neil $
*/

#ifndef PCCARD_LIBRARY_H
#define PCCARD_LIBRARY_H

#include <exec/types.h>
#include <exec/libraries.h>
#include <libraries/pccard.h>

#ifndef UPINT
#ifdef __AROS__
typedef IPTR UPINT;
typedef SIPTR PINT;
#else
typedef ULONG UPINT;
typedef LONG PINT;
#endif
#endif

struct PCCardBase
{
   struct Library library;
};

#define LEWord(P) (*(P)|(*((P)+1)<<8))

#endif
