/*
    Copyright � 1995-2014, The AROS Development Team. All rights reserved.
    $Id: libfindtagitem.c 51766 2016-03-10 13:20:54Z NicJA $
*/

#include <proto/arossupport.h>

struct TagItem *LibFindTagItem(Tag tagValue, const struct TagItem *tagList)
{
    struct TagItem *tstate = (struct TagItem *)tagList;
    struct TagItem *tag;

    while ((tag = LibNextTagItem(&tstate)))
    {
	if ((ULONG)tag->ti_Tag == (ULONG)tagValue)
	    return tag;
    }

    return NULL;
}
