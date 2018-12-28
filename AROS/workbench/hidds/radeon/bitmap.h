#ifndef BITMAP_H_
#define BITMAP_H_

/*
    Copyright © 2004-2007, The AROS Development Team. All rights reserved.
    $Id: bitmap.h 30792 2009-03-07 22:40:04Z neil $
*/


#include "ati.h"

void BitmapInit(struct ati_staticdata *sd);
ULONG BitmapAlloc(struct ati_staticdata *sd, ULONG size);
void BitmapFree(struct ati_staticdata *sd, ULONG ptr, ULONG size);

#endif /*BITMAP_H_*/
