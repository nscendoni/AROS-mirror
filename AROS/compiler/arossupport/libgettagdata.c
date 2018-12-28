/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: libgettagdata.c 49667 2014-09-30 17:35:27Z neil $
*/

#include <proto/arossupport.h>

IPTR LibGetTagData(Tag tagValue, IPTR defaultVal, const struct TagItem *tagList)
{
    struct TagItem *tag = LibFindTagItem(tagValue, tagList);
 
    return tag ? tag->ti_Data : defaultVal;
}
