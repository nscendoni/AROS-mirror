/*
    Copyright � 1995-2007, The AROS Development Team. All rights reserved.
    $Id: freegadgets.c 52221 2016-03-24 09:04:52Z stegerg $

    Desc:
    Lang: english
*/
#include <proto/exec.h>
#include "gadtools_intern.h"

/*********************************************************************

    NAME */
#include <proto/gadtools.h>
#include <intuition/intuition.h>

	AROS_LH1(VOID, FreeGadgets,

/*  SYNOPSIS */
	AROS_LHA(struct Gadget *, glist, A0),

/*  LOCATION */
	struct Library *, GadToolsBase, 6, GadTools)

/*  FUNCTION
	Frees all gadtools gadgets in a linked list of gadgets.

    INPUTS
	glist - pointer to the first gadget to be freed, may be NULL.

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
	CreateGadgetA()

    INTERNALS

    HISTORY

***************************************************************************/
{
    AROS_LIBFUNC_INIT

    struct Gadget 	*lastgad = NULL, *nextgad = NULL;

    DEBUG_FREEGADGETS(dprintf("FreeGadgets: glist 0x%lx\n", glist));

    if (!glist)
	return;

    for (; glist; glist = nextgad)
    {
	nextgad = glist->NextGadget;
	if (glist->GadgetType & GTYP_GADTOOLS)
	{
	    if ((glist->GadgetType & GTYP_GTYPEMASK) == GTYP_CUSTOMGADGET)
	    {	
		DEBUG_FREEGADGETS(dprintf("FreeGadgets: free gadget 0x%lx\n", glist));

	        /* must check this, because arrowclass uses GA_LabelImage! */
		if ((glist->Flags & GFLG_LABELMASK) == GFLG_LABELITEXT)
		{		
            	    freeitext(GTB(GadToolsBase), glist->GadgetText);
		}
	    	DisposeObject(glist);
		
	    } /* if ((glist->GadgetType & GTYP_GTYPEMASK) == GTYP_CUSTOMGADGET) */
	    else
	    {
                struct GT_ContextGadget *contextgad = (struct GT_ContextGadget *)glist;
                struct GT_GenericGadget *genericgad = (struct GT_GenericGadget *)glist;
                
	        if ( (contextgad->magic  == CONTEXT_MAGIC) &&
		     (contextgad->magic2 == CONTEXT_MAGIC2) )
		{
		    /* This is a GadTools Context Gadget */
		    
                    if (contextgad->gtmsg_used)
                    {
                        /* App is calling FreeGadgets() while still holding unreplied GT Messages.
                           Delay killing of context gad because the gtmsg is embedded in it.
                           Kill will happen in GT_PostFilterImsg() */

 		        DEBUG_FREEGADGETS(dprintf("FreeGadgets: delaying freeing of context 0x%lx\n", glist));

                        contextgad->killme = TRUE;
                    }
                    else
                    {
 		        DEBUG_FREEGADGETS(dprintf("FreeGadgets: free context 0x%lx\n", glist));
		        FreeMem(glist, sizeof(struct GT_ContextGadget));
                    }
		}
		else if ( (genericgad->magic  == GENERIC_MAGIC) &&
			  (genericgad->magic2 == GENERIC_MAGIC2) )
		{
		    /* This is a GadTools Generic Kind Gadget */
		    
		    DEBUG_FREEGADGETS(dprintf("FreeGadgets: free generic 0x%lx\n", glist));
		    freeitext(GTB(GadToolsBase), ((struct GT_GenericGadget *)glist)->itext);
		    FreeMem(glist, sizeof(struct GT_GenericGadget));
		}
		else
		{
		    DEBUG_FREEGADGETS(dprintf("FreeGadgets: bad gadget 0x%lx\n", glist));
		}
		
	    } /* if ((glist->GadgetType & GTYP_GTYPEMASK) == GTYP_CUSTOMGADGET) else ... */
	    
	} /* if (glist->GadgetType & GTYP_GADTOOLS) */
	else
	{
	    DEBUG_FREEGADGETS(dprintf("FreeGadgets: skip non-gadtools 0x%lx\n", glist));
	    if (lastgad != NULL)
		lastgad->NextGadget = glist;
	    lastgad = glist;
	}
	
    } /* for (; glist; glist = nextgad) */

    if (lastgad != NULL)
	lastgad->NextGadget = NULL;

    DEBUG_FREEGADGETS(dprintf("FreeGadgets: done\n"));

    AROS_LIBFUNC_EXIT
} /* FreeGadgets */
