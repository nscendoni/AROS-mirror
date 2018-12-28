#ifndef BITMAP_H
#define BITMAP_H

/*
    Copyright � 1995-2003, The AROS Development Team. All rights reserved.
    $Id: bitmap.h 30792 2009-03-07 22:40:04Z neil $
*/

#include "os.h"
#include "volumes.h"

ULONG countUsedBlocks(struct AFSBase *, struct Volume *);
ULONG createNewBitmapBlocks(struct AFSBase *, struct Volume *);
LONG setBitmapFlag(struct AFSBase *, struct Volume *, LONG);
LONG invalidBitmap(struct AFSBase *, struct Volume *);
LONG validBitmap(struct AFSBase *, struct Volume *);
LONG markBlock(struct AFSBase *, struct Volume *, ULONG, ULONG);
ULONG allocBlock(struct AFSBase *, struct Volume *);

#endif
