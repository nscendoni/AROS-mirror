/* 
    Copyright © 1999, David Le Corfec.
    Copyright © 2002, The AROS Development Team.
    All rights reserved.

    $Id: bubbleengine.h 30792 2009-03-07 22:40:04Z neil $
*/

#ifndef _ZUNE_BUBBLEENGINE_H__
#define _ZUNE_BUBBLEENGINE_H__

APTR zune_bubble_create(Object *obj, LONG x, LONG y, char *text, ULONG flags);
void zune_bubble_delete(Object *obj, APTR bubble);

#endif
