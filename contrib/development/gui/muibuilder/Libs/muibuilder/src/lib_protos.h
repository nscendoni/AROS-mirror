/***************************************************************************

  muibuilder.library - Support library for MUIBuilder's code generators
  Copyright (C) 1990-2009 by Eric Totel
  Copyright (C) 2010-2011 by MUIBuilder Open Source Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  MUIBuilder Support Site: http://sourceforge.net/projects/muibuilder/

  $Id: lib_protos.h 49595 2014-09-09 19:41:34Z mazze $

***************************************************************************/

#ifndef _LIB_PROTOS_H
#define _LIB_PROTOS_H

#include "SDI_lib.h"
#include "base.h"

/* init.c */
ULONG freeBase(struct LibraryHeader* lib);
ULONG initBase(struct LibraryHeader* lib);

/* utils.c */
#if defined(__amigaos4__)
  #define HAVE_ALLOCVECPOOLED 1
  #define HAVE_FREEVECPOOLED  1
  #define HAVE_GETHEAD        1
  #define HAVE_GETTAIL        1
  #define HAVE_GETPRED        1
  #define HAVE_GETSUCC        1
#elif defined(__MORPHOS__)
  #define HAVE_ALLOCVECPOOLED 1
  #define HAVE_FREEVECPOOLED  1
#elif defined(__AROS__)
  #define HAVE_ALLOCVECPOOLED 1
  #define HAVE_FREEVECPOOLED  1
  #define HAVE_GETHEAD        1
  #define HAVE_GETTAIL        1
  #define HAVE_GETPRED        1
  #define HAVE_GETSUCC        1
#endif

#if defined(HAVE_ALLOCVECPOOLED)
#define allocVecPooled(pool,size) AllocVecPooled(pool,size)
#else
APTR allocVecPooled(APTR pool, ULONG size);
#endif
#if defined(HAVE_FREEVECPOOLED)
#define freeVecPooled(pool,mem)   FreeVecPooled(pool,mem)
#else
void freeVecPooled(APTR pool, APTR mem);
#endif
APTR reallocVecPooled(APTR pool, APTR mem, ULONG oldSize, ULONG newSize);
APTR allocArbitrateVecPooled(ULONG size);
void freeArbitrateVecPooled(APTR mem);
APTR reallocArbitrateVecPooled(APTR mem, ULONG oldSize, ULONG newSize);
#if !defined(HAVE_GETHEAD)
struct Node *GetHead(struct List *list);
#endif
#if !defined(HAVE_GETPRED)
struct Node *GetPred(struct Node *node);
#endif
#if !defined(HAVE_GETSUCC)
struct Node *GetSucc(struct Node *node);
#endif
#if !defined(HAVE_GETTAIL)
struct Node *GetTail(struct List *list);
#endif


LIBPROTO(MB_Open,  BOOL, REG(a6, UNUSED __BASE_OR_IFACE));
LIBPROTO(MB_Close, void, REG(a6, UNUSED __BASE_OR_IFACE));
LIBPROTO(MB_GetA,  void, REG(a6, UNUSED __BASE_OR_IFACE), REG(a1, struct TagItem * TagList));

#if defined(__amigaos4__)
LIBPROTOVA(MB_Get, void, REG(a6, UNUSED __BASE_OR_IFACE), ...);
#else
LIBPROTOVA(MB_Get, void, REG(a6, UNUSED __BASE_OR_IFACE), REG(a1, Tag tag1), ...);
#endif

LIBPROTO(MB_GetVarInfoA, void, REG(a6, UNUSED __BASE_OR_IFACE), REG(d0, ULONG varnb), REG(a1, struct TagItem * TagList));

#if defined(__amigaos4__)
LIBPROTOVA(MB_GetVarInfo, void, REG(a6, UNUSED __BASE_OR_IFACE), ULONG varnb, ...);
#else
LIBPROTOVA(MB_GetVarInfo, void, REG(a6, UNUSED __BASE_OR_IFACE), REG(d0, ULONG varnb), REG(a1, Tag tag1), ...);
#endif

LIBPROTO(MB_GetNextCode,   void, REG(a6, UNUSED __BASE_OR_IFACE), REG(a0, ULONG * type), REG(a1, char ** code));
LIBPROTO(MB_GetNextNotify, void, REG(a6, UNUSED __BASE_OR_IFACE), REG(a0, ULONG * type), REG(a1, char ** code));

#if defined(__AROS__)
AROS_LD0(BOOL, MB_Open,
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);

AROS_LD0(void, MB_Close,
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);

AROS_LD1(void, MB_GetA,
    AROS_LDA(struct TagItem *, ___TagList, A1),
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);

AROS_LD2(void, MB_GetVarInfoA,
    AROS_LDA(ULONG, ___varnb, D0),
    AROS_LDA(struct TagItem *, ___TagList, A1),
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);

AROS_LD2(void, MB_GetNextCode,
    AROS_LDA(ULONG *, ___type, A0),
    AROS_LDA(char **, ___code, A1),
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);

AROS_LD2(void, MB_GetNextNotify,
    AROS_LDA(ULONG *, ___type, A0),
    AROS_LDA(char **, ___code, A1),
    struct LibraryHeader *, __BASE_OR_IFACE_VAR, 0, LIBSTUB
);
#endif /* __AROS__ */

#endif /* _LIB_PROTOS_H */
