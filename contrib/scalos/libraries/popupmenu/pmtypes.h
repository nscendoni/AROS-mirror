//
// pmtypes.h
//
// OS independent exec/types.h equivalent
//
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $
//

#ifndef PM_TYPES_H
#define PM_TYPES_H

#define AMIGA 1

#ifdef AMIGA

#include <exec/types.h>

#else

typedef unsigned long ULONG;
typedef long LONG;

typedef unsigned short UWORD;
typedef short WORD;

typedef unsigned char UBYTE;
typedef char BYTE;

typedef char BOOL;

typedef char * STRPTR;

#define TRUE	1
#define FALSE	0

#endif

#endif /* PM_TYPES_H */
