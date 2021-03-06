/*
    Copyright � 2009-2016, The AROS Development Team. All rights reserved.
    $Id: main.c 53084 2016-12-20 17:57:04Z neil $
*/

#define MUIMASTER_YES_INLINE_STDARG

#include <libraries/mui.h>
#include <zune/systemprefswindow.h>

#include <proto/intuition.h>
#include <proto/muimaster.h>
#include <clib/alib_protos.h>

#include "locale.h"
#include "args.h"
#include "booteditor.h"

#define VERSION "$VER: Boot 1.3 (8.3.2015)"

int main(int argc, char **argv)
{
    Object *application,  *window;

    Locale_Initialize();

    ReadArguments(argc, argv);

    /* Show application unless SAVE parameter was used */
    if (!((BOOL)ARG(SAVE)))
    {
        application = (Object *)ApplicationObject,
            MUIA_Application_Title,  __(MSG_NAME),
            MUIA_Application_Version, (IPTR)VERSION,
            MUIA_Application_Description,  __(MSG_DESCRIPTION),
            MUIA_Application_SingleTask, TRUE,
            MUIA_Application_Base, (IPTR)"BOOTPREF",
            SubWindow, (IPTR)(window = (Object *)SystemPrefsWindowObject,
                MUIA_Window_ID, MAKE_ID('B', 'O', 'O', 'T'),
                WindowContents, (IPTR)BootEditorObject,
                End,
            End),
        End;

        if (application != NULL)
        {
            SET(window, MUIA_Window_Open, TRUE);
            DoMethod(application, MUIM_Application_Execute);
            SET(window, MUIA_Window_Open, FALSE);

            MUI_DisposeObject(application);
        }
    }

    FreeArguments();

    Locale_Deinitialize();

    return 0;
}
