/*
    (C) 1997 AROS - The Amiga Research OS
    $Id$

    Desc:
    Lang: english
*/
#include <aros/libcall.h>
#include <graphics/clip.h>
#include <graphics/layers.h>
#include "basicfuncs.h"

/*****************************************************************************

    NAME */
#include <proto/layers.h>
	AROS_LH9(struct Layer *, CreateBehindHookLayer,

/*  SYNOPSIS */
	AROS_LHA(struct Layer_Info *, li, A0),
	AROS_LHA(struct BitMap     *, bm, A1),
	AROS_LHA(LONG               , x0, D0),
	AROS_LHA(LONG               , y0, D1),
	AROS_LHA(LONG               , x1, D2),
	AROS_LHA(LONG               , y1, D3),
	AROS_LHA(LONG               , flags, D4),
	AROS_LHA(struct Hook       *, hook, A3),
	AROS_LHA(struct BitMap     *, bm2, A2),

/*  LOCATION */
	struct LayersBase *, LayersBase, 32, Layers)

/*  FUNCTION
        Creates a layer behind other layers. A backdrop layer will
        be created at the most behind positon, a non-backdrop layer 
        will be placed behind the last non-backdrop layer and in front
        of the first backdrop layer.

    INPUTS
        li    - pointer to layer info structure
        bm    - pointer to common bitmap (= bitmap of screen)
        x0    - upper left corner x-coordinate
        y0    - upper left corner y-coordinate
        x1    - lower right corner x-coordinate
        y1    - lower right corner y-coordinate
        flags - flags for this layer
        Hook  - Backfill hook for this layer
        BitMap- optional SuperBitMap for this layer. Used if the LAYERSUPER
                flag is set
        
    RESULT
        Pointer to the newly created layer. NULL if layer could not be 
        created (Probably out of memory).
        
    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY
	27-11-96    digulla automatically created from
			    layers_lib.fd and clib/layers_protos.h

*****************************************************************************/
{
  AROS_LIBFUNC_INIT
  AROS_LIBBASE_EXT_DECL(struct LayersBase *,LayersBase)
/*
  D(bug("CreateBehindHookLayer(li@$lx, bm@$lx, x0 %ld, y0 %ld, x1 %ld, y1 %ld, flags %ld, hook@$%lx, bm2@$lx)\n", li, bm, x0, y0, x1, y1, flags, hook, bm2));
*/

  struct Layer * L;
  struct ClipRect * CR;
  struct RastPort * RP;

  L  = (struct Layer    *) AllocMem(sizeof(struct Layer)   , MEMF_CLEAR|MEMF_PUBLIC);
  CR = _AllocClipRect(li);
  RP = (struct RastPort *) AllocMem(sizeof(struct RastPort), MEMF_CLEAR|MEMF_PUBLIC);

  /* is everything there that I need?  */
  if (NULL != L && NULL != CR && NULL != RP)
  {
    struct Layer * L_front;
    /* first of all we init. the layers structure */
    L->ClipRect = CR;
    L->rp       = RP;

    L->bounds.MinX = x0;
    L->bounds.MinY = y0;
    L->bounds.MaxX = x1;
    L->bounds.MaxY = y1;

    L->Flags     = (WORD) flags;
    L->LayerInfo = li;
    L->Width     = x1-x0+1;
    L->Height    = y1-y0+1;
    L->SuperBitMap = bm2;

    InitSemaphore(&L->Lock);
    LockLayer(0, L);

    L->DamageList = NewRegion();

    /*
      L->priority = ;
    */

    /* and now init the ClipRect structure */
    CR->bounds.MinX = x0;
    CR->bounds.MinY = y0;
    CR->bounds.MaxX = x1;
    CR->bounds.MaxY = y1;

    /* and now init the RastPort structure */
    InitRastPort(RP);

    RP->Layer  = L;
    RP->BitMap = bm;

    /* 
       add the layer at the correct position in the linked list of layers
       non-BACKDROP layer: insert it before the first non-BACKDROP layer
           BACKDROP layer: insert it at the very end of the list  
    */
   
    L_front = li->top_layer;

    /* Now nobody else may play around with the layers while I am
     * doing this here 
     */
    LockLayers(li);

    if ((NULL == L_front) ||
        ( (0 != (L_front->Flags & LAYERBACKDROP)) && 
          (0 == (flags & LAYERBACKDROP) ) 
        ))
    {
      /* the new one is the very first one in the list */
      if (NULL != li->top_layer)
      {
        L ->back             = li->top_layer;
        li->top_layer->front = L;
      }
      /* make the new layer the top layer */
      li->top_layer          = L; 
    }
    else
    {
      /* search for the exact place in the list */
      if (0 != (flags & LAYERBACKDROP))
      {
        /* 
          for a BACKDROP layer we have to go to the very end of the list
         */
        while (NULL != L_front->back)
          L_front = L_front ->back;
        L_front->back = L;
        L -> front    = L_front;
      }
      else
      {
         /* 
           for a non BACKDROP layer we have to go to the end of the non-
           BACKDROP layers list
         */
         while  (NULL != L_front->back && 
               ((L_front->back->Flags & LAYERBACKDROP) == 0) )
           L_front = L_front->back;
         /* insert it behind L_front */
         if (L_front->back != NULL)
	 {
           L_front->back->front = L;
           L->back              = L_front->back;
         }
         L_front->back = L;
         L->front      = L_front;
      }
    }
    
    /* 
      Now create all ClipRects of all Layers correctly.   
      Comment: CreateClipRects is the only function that does the
               job correctly if you want to create a layer somewhere
               behind other layers.
    */

    CreateClipRects(li, L);

    if (li->top_layer == L && NULL != L->back)
      CreateClipRectsSelf(L->back, FALSE); 

    /*
       Ok, all other layers were visited and pixels are backed up.
       Now we can draw the new layer by clearing these parts of the
       displaybitmap for which the ClipRects of this layer have no
       entry in lobs (these are not hidden, but might be hiding other
       layers behind them, but those parts are backed up now)
    */

    
    /* the whole part from here ... */

    CR = L->ClipRect;
    while (CR != NULL)
    {
      /* only show those cliprects that are visible, of course. */
      if (NULL == CR->lobs)
      {
        if (0 == (L->Flags & LAYERSUPER))
	{
          /* no superbitmap */
          /* fill visible area with backfill hook */
          _CallLayerHook(hook,
                         L->rp,
                         L,
                         &CR->bounds,
                         CR->bounds.MinX - L->bounds.MinX,
                         CR->bounds.MinY - L->bounds.MinY);

/*          
          BltBitMap(
            bm, // Source Bitmap - we don't need one for clearing, but this
                //  one will also do :-) 
            0,
            0,
            bm, // Destination Bitmap
            CR->bounds.MinX,
            CR->bounds.MinY,
            CR->bounds.MaxX-CR->bounds.MinX+1,
            CR->bounds.MaxY-CR->bounds.MinY+1,
            0x000, // supposed to clear the destination
            0xff,
            NULL
          );
*/
	}
        else
	{
          /* with superbitmap */
          BltBitMap(
            bm2 /* Source Bitmap = superbitmap  */,
            CR->bounds.MinX - L->bounds.MinX /* + L->Scroll_X = 0! */,
            CR->bounds.MinY - L->bounds.MinY /* + L->Scroll_Y = 0! */,
            bm, /* Destination Bitmap - */
            CR->bounds.MinX,
            CR->bounds.MinY,
            CR->bounds.MaxX-CR->bounds.MinX+1,
            CR->bounds.MaxY-CR->bounds.MinY+1,
            0x0c0, /* copy  */
            0xff,
            NULL
          );
	}
      }
      else
      {
        /* this is an invisible cliprect */
        /* if it's from a smart layer then I will have to fill it
           with the backfill hook. */
        if (LAYERSMART == (flags & (LAYERSMART|LAYERSUPER)) &&
            hook != LAYERS_BACKFILL && /* try to avoid wasting time */
            hook != LAYERS_NOBACKFILL)
        {
          /*
            it's a pure smart layer that needs to be filled with a 
            !! pattern !!. LAYERS_BACKFILL & LAYERS_NOBACKFILL wouldn't 
            do anything good here at all.
          */
          struct Rectangle bounds;
          struct BitMap * bm = L->rp->BitMap;
          bounds.MinX = CR->bounds.MinX & 0x0f;
          bounds.MinY = 0;
          bounds.MaxX = CR->bounds.MaxX - CR->bounds.MinX + (CR->bounds.MinX & 0x0f);
          bounds.MaxY = CR->bounds.MaxY;
          
          /* filling the hidden cliprect's bitmap with the pattern */
          L->rp->BitMap = CR->BitMap;
          _CallLayerHook(hook,
                         L->rp,
                         L,
                         &bounds,
                         CR->bounds.MinX - L->bounds.MinX,
                         CR->bounds.MinX - L->bounds.MinY);
          L->rp->BitMap = bm;
        }
      }
      CR = CR->Next;
    }  
 
    /* ... to here will be replaced by : */
    /*
    DoHookClipRects(hook, RP, L->bounds);
     */
    /*
       once DoHookClipRects is there and a default backfill is implemented. 
       (basically the same code as above) 
     */

    UnlockLayers(li);
  } /* if (all memory is there) */  
  else /* not enough memory */
  {
    if (NULL != L ) FreeMem(L , sizeof(struct Layer));
    if (NULL != RP) FreeMem(RP, sizeof(struct RastPort));
    if (NULL != CR) _FreeClipRect(CR, li);
    L = NULL;
  }

  return L;
  
  AROS_LIBFUNC_EXIT
} /* CreateBehindHookLayer */
