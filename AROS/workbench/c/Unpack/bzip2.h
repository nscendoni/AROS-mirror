#ifndef PKG_BZIP2_H
#define PKG_BZIP2_H

/*
    Copyright © 2003-2014, The AROS Development Team. All rights reserved.
    $Id: bzip2.h 49635 2014-09-15 16:02:02Z neil $
*/

#include <exec/types.h>

/****************************************************************************/
/*** Prototypes *************************************************************/

APTR BZ2_Open( CONST_STRPTR path, LONG mode );
void BZ2_Close( APTR file );
LONG BZ2_Read( APTR file, APTR buffer, LONG length );

#endif /* PKG_BZIP2_H */
