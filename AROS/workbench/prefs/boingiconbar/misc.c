/*
    Copyright � 2003, The AROS Development Team. All rights reserved.
    $Id: misc.c 45057 2012-06-18 13:09:20Z olivieradam $
*/

#include <exec/types.h>

#include <proto/dos.h>
#include <proto/intuition.h>

#include <stdio.h>

#include "locale.h"


VOID ShowMessage(CONST_STRPTR msg)
{
    struct EasyStruct es;

    if (msg)
    {
        if (IntuitionBase)
        {
            es.es_StructSize   = sizeof(es);
            es.es_Flags        = 0;
            es.es_Title        = (CONST_STRPTR) "BIB";
            es.es_TextFormat   = (CONST_STRPTR) msg;
            es.es_GadgetFormat = _(MSG_OK);

            EasyRequestArgs(NULL, &es, NULL, NULL); /* win=NULL -> wb screen */
        }
        else
        {
            printf("BIB: %s\n", msg);
        }
    }
}
