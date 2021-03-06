/*
    Copyright � 1995-2011, The AROS Development Team. All rights reserved.
    $Id: catalog_funcs.c 43286 2011-12-29 02:11:58Z neil $
*/

#include <libraries/locale.h>
#include "locale_intern.h"

/*
** Dispose the catalog's strings but not the Catalog structure 
** itself.
*/
void dispose_catalog(struct IntCatalog * cat,
                     struct LocaleBase * LocaleBase)
{
    if (cat->ic_StringChunk)
    {
            FreeVec(cat->ic_StringChunk);
        cat->ic_StringChunk = NULL;
    }
    
    if (cat->ic_CatStrings)
    {
            FreeVec(cat->ic_CatStrings);
        cat->ic_CatStrings = NULL;
    }
    
}
