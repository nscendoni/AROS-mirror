/**
 * Scout - The Amiga System Monitor
 *
 *------------------------------------------------------------------
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *------------------------------------------------------------------
 *
 * @author Andreas Gelhausen
 * @author Richard K�rber <rkoerber@gmx.de>
 */

#include "system_headers.h"

struct LowMemoryDetailWinData {
    TEXT lmdwd_Title[WINDOW_TITLE_LENGTH];
    APTR lmdwd_Texts[6];
    struct LowMemoryEntry *lmdwd_LowMemoryHandler;
};

STATIC void SetDetails( struct IClass *cl,
                        Object *obj )
{
    struct LowMemoryDetailWinData *lmdwd = INST_DATA(cl, obj);
    struct LowMemoryEntry *lme = lmdwd->lmdwd_LowMemoryHandler;
    struct Interrupt *is = lme->lme_Addr;

    MySetContentsHealed(lmdwd->lmdwd_Texts[0], "%s", lme->lme_Name);
    MySetContents(lmdwd->lmdwd_Texts[1], "$%08lx", is);
    MySetContents(lmdwd->lmdwd_Texts[2], "%s", GetNodeType(is->is_Node.ln_Type));
    MySetContents(lmdwd->lmdwd_Texts[3], "%ld", is->is_Node.ln_Pri);
    set(lmdwd->lmdwd_Texts[4], MUIA_DisassemblerButton_Address, is->is_Data);
    set(lmdwd->lmdwd_Texts[5], MUIA_DisassemblerButton_Address, is->is_Code);

    set(obj, MUIA_Window_Title, MyGetChildWindowTitle(txtLowMemoryDetailTitle, lme->lme_Name, lmdwd->lmdwd_Title, sizeof(lmdwd->lmdwd_Title)));
}

STATIC IPTR mNew( struct IClass *cl,
                   Object *obj,
                   struct opSet *msg )
{
    APTR group, texts[6], exitButton;

    if ((obj = (Object *)DoSuperNew(cl, obj,
        MUIA_HelpNode, "LowMemory",
        MUIA_Window_ID, MakeID('.','I','N','T'),
        WindowContents, VGroup,

            Child, (IPTR)(group = (Object *)ScrollgroupObject,
                MUIA_CycleChain, TRUE,
                MUIA_Scrollgroup_FreeHoriz, FALSE,
                MUIA_Scrollgroup_Contents, (IPTR)VGroupV,
                    MUIA_Background, MUII_GroupBack,
                    Child, (IPTR)VGroup,
                        GroupFrame,
                        Child, (IPTR)ColGroup(2),
                            Child, (IPTR)MyLabel2(txtNodeName2),
                            Child, (IPTR)(texts[ 0] = MyTextObject6()),
                            Child, (IPTR)MyLabel2(txtAddress2),
                            Child, (IPTR)(texts[ 1] = MyTextObject6()),
                            Child, (IPTR)MyLabel2(txtNodeType2),
                            Child, (IPTR)(texts[ 2] = MyTextObject6()),
                            Child, (IPTR)MyLabel2(txtNodePri2),
                            Child, (IPTR)(texts[ 3] = MyTextObject6()),
                            Child, (IPTR)MyLabel2(txtInterruptData2),
                            Child, (IPTR)(texts[ 4] = (Object *)DisassemblerButtonObject,
                                MUIA_DisassemblerButton_ForceHexDump, TRUE,
                            End),
                            Child, (IPTR)MyLabel2(txtInterruptCode2),
                            Child, (IPTR)(texts[ 5] = (Object *)DisassemblerButtonObject,
                            End),
                        End,
                    End,
                End,
            End),
            Child, (IPTR)MyVSpace(4),
            Child, (IPTR)(exitButton = MakeButton(txtExit)),
        End,
        TAG_MORE, msg->ops_AttrList)) != NULL)
    {
        struct LowMemoryDetailWinData *lmdwd = INST_DATA(cl, obj);
        APTR parent;

        CopyMemQuick(texts, lmdwd->lmdwd_Texts, sizeof(lmdwd->lmdwd_Texts));

        parent = (APTR)GetTagData(MUIA_Window_ParentWindow, (IPTR)NULL, msg->ops_AttrList);

        set(obj, MUIA_Window_DefaultObject, group);

        DoMethod(parent,         MUIM_Window_AddChildWindow, obj);
        DoMethod(obj,            MUIM_Notify, MUIA_Window_CloseRequest, TRUE,  MUIV_Notify_Application, 5, MUIM_Application_PushMethod, parent, 2, MUIM_Window_RemChildWindow, obj);
        DoMethod(exitButton,     MUIM_Notify, MUIA_Pressed,             FALSE, obj,                     3, MUIM_Set, MUIA_Window_CloseRequest, TRUE);
    }

    return (IPTR)obj;
}

STATIC IPTR mDispose( struct IClass *cl,
                       Object *obj,
                       Msg msg )
{
    set(obj, MUIA_Window_Open, FALSE);

    return DoSuperMethodA(cl, obj, msg);
}

STATIC IPTR mSet( struct IClass *cl,
                   Object *obj,
                   struct opSet *msg )
{
    struct LowMemoryDetailWinData *lmdwd = INST_DATA(cl, obj);
    struct TagItem *tags, *tag;

    tags = msg->ops_AttrList;
    while ((tag = NextTagItem((APTR)&tags)) != NULL) {
        switch (tag->ti_Tag) {
            case MUIA_Window_ParentWindow:
                DoMethod(obj, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, MUIV_Notify_Application, 5, MUIM_Application_PushMethod, (APTR)tag->ti_Data, 2, MUIM_Window_RemChildWindow, obj);
                break;

            case MUIA_LowMemoryDetailWin_LowMemoryHandler:
                lmdwd->lmdwd_LowMemoryHandler = (struct LowMemoryEntry *)tag->ti_Data;
                SetDetails(cl, obj);
                break;
        }
    }

    return DoSuperMethodA(cl,obj, (Msg)msg);
}

DISPATCHER(LowMemoryDetailWinDispatcher)
{
    switch (msg->MethodID) {
        case OM_NEW:     return (mNew(cl, obj, (APTR)msg));
        case OM_DISPOSE: return (mDispose(cl, obj, (APTR)msg));
        case OM_SET:     return (mSet(cl, obj, (APTR)msg));
    }

    return DoSuperMethodA(cl, obj, msg);
}

APTR MakeLowMemoryDetailWinClass( void )
{
    return MUI_CreateCustomClass(NULL, NULL, ParentWinClass, sizeof(struct LowMemoryDetailWinData), ENTRY(LowMemoryDetailWinDispatcher));
}

