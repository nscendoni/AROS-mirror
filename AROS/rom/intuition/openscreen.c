/*
    (C) 1995-96 AROS - The Amiga Replacement OS
    $Id$
    $Log$
    Revision 1.3  1996/10/24 15:51:23  aros
    Use the official AROS macros over the __AROS versions.

    Revision 1.2  1996/09/21 15:54:01  digulla
    Fill private fields

    Revision 1.1  1996/09/21 14:11:39  digulla
    Open and close screens


    Desc:
    Lang: english
*/
#include "intuition_intern.h"
#include <exec/memory.h>
#include <clib/exec_protos.h>
#include <clib/graphics_protos.h>

#ifndef DEBUG_OpenScreen
#   define DEBUG_OpenScreen 0
#endif
#if DEBUG_OpenScreen
#   undef DEBUG
#   define DEBUG 1
#endif
#include <aros/debug.h>

/*****************************************************************************

    NAME */
	#include <intuition/screens.h>
	#include <clib/intuition_protos.h>

	AROS_LH1(struct Screen *, OpenScreen,

/*  SYNOPSIS */
	AROS_LHA(struct NewScreen *, newScreen, A0),

/*  LOCATION */
	struct IntuitionBase *, IntuitionBase, 33, Intuition)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
	29-10-95    digulla automatically created from
			    intuition_lib.fd and clib/intuition_protos.h

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    AROS_LIBBASE_EXT_DECL(struct IntuitionBase *,IntuitionBase)
    struct IntScreen * screen;
#define COPY(x)     screen->Screen.x = newScreen->x

    D(bug("OpenScreen (%p = { Left=%d Top=%d Width=%d Height=%d Depth=%d })\n"
	, newScreen
	, newScreen->LeftEdge
	, newScreen->TopEdge
	, newScreen->Width
	, newScreen->Height
	, newScreen->Depth
    ));

    if ((screen = AllocMem (sizeof (struct IntScreen), MEMF_ANY | MEMF_CLEAR)))
    {
	COPY(LeftEdge);
	COPY(TopEdge);
	COPY(Width);
	COPY(Height);
	COPY(DetailPen);
	COPY(BlockPen);
	COPY(Font);
	COPY(DefaultTitle);

	screen->Screen.Flags = newScreen->Type;

	screen->Screen.BitMap.Depth = newScreen->Depth;

	screen->Screen.BarHeight = 0;
	screen->Screen.BarVBorder = 0;
	screen->Screen.BarHBorder = 0;
	screen->Screen.MenuVBorder = 0;
	screen->Screen.MenuHBorder = 0;

	screen->Screen.WBorTop = 0;
	screen->Screen.WBorLeft = 0;
	screen->Screen.WBorRight = 0;
	screen->Screen.WBorBottom = 0;

	InitRastPort (&screen->Screen.RastPort);

	screen->Screen.RastPort.BitMap = &screen->Screen.BitMap;

	screen->Screen.Title = newScreen->DefaultTitle;

	screen->Screen.NextScreen = IntuitionBase->FirstScreen;
	IntuitionBase->FirstScreen =
	    IntuitionBase->ActiveScreen = &screen->Screen;

	screen->DInfo.dri_Version = DRI_VERSION;
	screen->DInfo.dri_NumPens = NUMDRIPENS;
	screen->DInfo.dri_Pens = screen->Pens;
	screen->DInfo.dri_Depth = newScreen->Depth;
	screen->DInfo.dri_Resolution.X = 44;
	screen->DInfo.dri_Resolution.Y = 44;
	screen->DInfo.dri_Flags = 0;

	if (screen->Screen.Font)
	    screen->DInfo.dri_Font = OpenFont (screen->Screen.Font);

	if (!screen->DInfo.dri_Font)
	    screen->DInfo.dri_Font = GfxBase->DefaultFont;

	screen->Pens[DETAILPEN] = screen->Screen.DetailPen;
	screen->Pens[BLOCKPEN]	= screen->Screen.BlockPen;
	screen->Pens[TEXTPEN] = 1;
	screen->Pens[SHINEPEN] = 2;
	screen->Pens[SHADOWPEN] = 1;
	screen->Pens[FILLPEN] = 3;
	screen->Pens[FILLTEXTPEN] = 2;
	screen->Pens[BACKGROUNDPEN] = 0;
	screen->Pens[HIGHLIGHTTEXTPEN] = 1;
	screen->Pens[BARDETAILPEN] = 1;
	screen->Pens[BARBLOCKPEN] = 2;
	screen->Pens[BARTRIMPEN] = 1;
    }

    ReturnPtr ("OpenScreen", struct Screen *, screen);
    AROS_LIBFUNC_EXIT
} /* OpenScreen */
