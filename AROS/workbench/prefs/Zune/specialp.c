/*
    Copyright � 2003-2006, The AROS Development Team. All rights reserved.
    $Id: specialp.c 53623 2017-02-13 17:55:17Z neil $
*/

#include <graphics/gfx.h>
#include <graphics/view.h>
#include <clib/alib_protos.h>
#include <libraries/asl.h>
#include <libraries/mui.h>
#include <mui/Rawimage_mcc.h>
#include <proto/exec.h>
#include <proto/graphics.h>
#include <proto/utility.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#ifdef __AROS__
#include <proto/alib.h>
#endif

#include "zunestuff.h"
#include <string.h>

/*  #define DEBUG 1 */
/*  #include <aros/debug.h> */

extern struct Library *MUIMasterBase;

#define NBIMAGES 14

struct MUI_SpecialPData
{
    Object *text_popframe;
    Object *text_popimage;
    Object *gauge_popframe;
    Object *gauge;
    Object *popimage[NBIMAGES];
};

ULONG Imagecfg[NBIMAGES] =
{
    MUICFG_Image_Drawer,
    MUICFG_Image_HardDisk,
    MUICFG_Image_Disk,
    MUICFG_Image_Chip,
    MUICFG_Image_Volume,
    MUICFG_Image_Network,
    MUICFG_Image_Assign,
    MUICFG_Image_TapePlay,
    MUICFG_Image_TapePlayBack,
    MUICFG_Image_TapePause,
    MUICFG_Image_TapeStop,
    MUICFG_Image_TapeRecord,
    MUICFG_Image_TapeUp,
    MUICFG_Image_TapeDown,
};

static Object *MakeSpecialPopimage(CONST_STRPTR title)
{
    return MUI_NewObject
	(
	    MUIC_Popimage,
	    MUIA_Imageadjust_Type, MUIV_Imageadjust_Type_Image,
	    MUIA_CycleChain, 1,
	    MUIA_MaxWidth, 28,
	    MUIA_MaxHeight, 28,
	    MUIA_Imagedisplay_FreeHoriz, FALSE,
	    MUIA_Imagedisplay_FreeVert, FALSE,
	    MUIA_Window_Title, (IPTR)title,
	    TAG_DONE
	    );
}

static IPTR SpecialP_New(struct IClass *cl, Object *obj, struct opSet *msg)
{
    struct MUI_SpecialPData *data;
    struct MUI_SpecialPData d;
    
    obj = (Object *) DoSuperNewTags
    (
        cl, obj, NULL,
	MUIA_Group_Horiz, FALSE,
	Child, (IPTR) ColGroup(2),

	Child, (IPTR) VGroup,
	GroupFrameT(_(MSG_TEXT_FIELDS)),
	Child, (IPTR) HGroup,
	MUIA_Group_SameWidth, TRUE,
	Child, (IPTR) VGroup,
	MUIA_Group_VertSpacing, 1,
	Child, (IPTR) (d.text_popframe = MakePopframe()),
	Child, (IPTR) CLabel(_(MSG_FRAME)),
	End, // VGroup
	Child, (IPTR) VGroup,
	MUIA_Group_VertSpacing, 1,
	Child, (IPTR) (d.text_popimage = MakeBackgroundPopimage()),
	Child, (IPTR) CLabel(_(MSG_BACKGROUND)),
	End, // VGroup
	End, // HGroup
	Child, (IPTR) TextObject,
	TextFrame,
	MUIA_Background, MUII_TextBack,
	MUIA_Text_PreParse, (IPTR) "\33c",
	MUIA_Text_Contents, (IPTR) _(MSG_EXAMPLE_TEXTFIELD),
	End, // TextObject
	End, // VGroup
	Child, (IPTR) ColGroup(2),
	GroupFrameT(_(MSG_PROGRESS_INDICATOR)),
	Child, (IPTR) FreeLabel(_(MSG_FRAME_COLON)),
	Child, (IPTR) (d.gauge_popframe = MakePopframe()),
	Child, (IPTR) Label(_(MSG_EXAMPLE)),
	Child, (IPTR) (d.gauge = GaugeObject, MUIA_Gauge_InfoText, "%ld %%",
		       GaugeFrame, MUIA_Gauge_Horiz, TRUE, End),
	Child, (IPTR) VSpace(0),
	Child, (IPTR) ScaleObject, End,
	End, // Progress Indicator
	End, // HGroup
	Child, (IPTR) HGroup,
	GroupFrameT(_(MSG_DEVICE_IMAGES)),
	Child, (IPTR) HSpace(0),
	Child, d.popimage[0] = MakeSpecialPopimage(_(MSG_DRAWER)),
	Child, d.popimage[1] = MakeSpecialPopimage(_(MSG_HARDDISK)),
	Child, d.popimage[2] = MakeSpecialPopimage(_(MSG_DISK)),
	Child, d.popimage[3] = MakeSpecialPopimage(_(MSG_RAM)),
	Child, d.popimage[4] = MakeSpecialPopimage(_(MSG_VOLUME)),
	Child, d.popimage[5] = MakeSpecialPopimage(_(MSG_NETWORK)),
	Child, d.popimage[6] = MakeSpecialPopimage(_(MSG_ASSIGN)),
	Child, (IPTR) HSpace(0),
	End, // Device Images
	Child, (IPTR) HGroup,
	GroupFrameT(_(MSG_TAPE_IMAGES)),
	Child, (IPTR) HSpace(0),
	Child, d.popimage[7] = MakeSpecialPopimage(_(MSG_TAPE_PLAY)),
	Child, d.popimage[8] = MakeSpecialPopimage(_(MSG_TAPE_PLAYBACK)),
	Child, d.popimage[9] = MakeSpecialPopimage(_(MSG_TAPE_PAUSE)),
	Child, d.popimage[10] = MakeSpecialPopimage(_(MSG_TAPE_STOP)),
	Child, d.popimage[11] = MakeSpecialPopimage(_(MSG_TAPE_RECORD)),
	Child, d.popimage[12] = MakeSpecialPopimage(_(MSG_TAPE_UP)),
	Child, d.popimage[13] = MakeSpecialPopimage(_(MSG_TAPE_DOWN)),
	Child, (IPTR) HSpace(0),
	End, // Tape Images
	
    	TAG_MORE, (IPTR) msg->ops_AttrList);
	
    if (!obj) return FALSE;
    
    data = INST_DATA(cl, obj);
    *data = d;

    return (IPTR)obj;
}


/*
 * MUIM_Settingsgroup_ConfigToGadgets
 */
static IPTR SpecialP_ConfigToGadgets(struct IClass *cl, Object *obj,
				    struct MUIP_Settingsgroup_ConfigToGadgets *msg)
{
    struct MUI_SpecialPData *data = INST_DATA(cl, obj);
    STRPTR spec;
    int i;

/* Frames */
    spec = (STRPTR)DoMethod(msg->configdata, MUIM_Configdata_GetString,
			    MUICFG_Frame_Text);
    set(data->text_popframe, MUIA_Framedisplay_Spec, (IPTR)spec);
    spec = (STRPTR)DoMethod(msg->configdata, MUIM_Configdata_GetString,
			    MUICFG_Frame_Gauge);
    set(data->gauge_popframe, MUIA_Framedisplay_Spec, (IPTR)spec);

/* Looks */
    spec = (STRPTR)DoMethod(msg->configdata, MUIM_Configdata_GetString,
			    MUICFG_Background_Text);
    set(data->text_popimage, MUIA_Imagedisplay_Spec, (IPTR)spec);

    for (i = 0; i < NBIMAGES; i++)
    {
	spec = (STRPTR)DoMethod(msg->configdata, MUIM_Configdata_GetString,
				Imagecfg[i]);
	set(data->popimage[i], MUIA_Imagedisplay_Spec, (IPTR)spec);
    }

    return 1;    
}


/*
 * MUIM_Settingsgroup_ConfigToGadgets
 */
static IPTR SpecialP_GadgetsToConfig(struct IClass *cl, Object *obj,
				    struct MUIP_Settingsgroup_GadgetsToConfig *msg)
{
    struct MUI_SpecialPData *data = INST_DATA(cl, obj);
    STRPTR str;
    int i;

/* Frames */
    str = (STRPTR)XGET(data->text_popframe, MUIA_Framedisplay_Spec);
    DoMethod(msg->configdata, MUIM_Configdata_SetFramespec, MUICFG_Frame_Text,
	     (IPTR)str);
    str = (STRPTR)XGET(data->gauge_popframe, MUIA_Framedisplay_Spec);
    DoMethod(msg->configdata, MUIM_Configdata_SetFramespec, MUICFG_Frame_Gauge,
	     (IPTR)str);

/* Looks */
    str = (STRPTR)XGET(data->text_popimage, MUIA_Imagedisplay_Spec);
    DoMethod(msg->configdata, MUIM_Configdata_SetImspec, MUICFG_Background_Text,
	     (IPTR)str);

    for (i = 0; i < NBIMAGES; i++)
    {
	str = (STRPTR)XGET(data->popimage[i], MUIA_Imagedisplay_Spec);
	DoMethod(msg->configdata, MUIM_Configdata_SetImspec, Imagecfg[i],
		 (IPTR)str);
    }
    return TRUE;
}


BOOPSI_DISPATCHER(IPTR, SpecialP_Dispatcher, cl, obj, msg)
{
    switch (msg->MethodID)
    {
	case OM_NEW: return SpecialP_New(cl, obj, (struct opSet *)msg);
	case MUIM_Settingsgroup_ConfigToGadgets: return SpecialP_ConfigToGadgets(cl,obj,(APTR)msg);break;
	case MUIM_Settingsgroup_GadgetsToConfig: return SpecialP_GadgetsToConfig(cl,obj,(APTR)msg);break;
    }
    
    return DoSuperMethodA(cl, obj, msg);
}
BOOPSI_DISPATCHER_END

/*
 * Class descriptor.
 */
const struct __MUIBuiltinClass _MUIP_Special_desc = { 
    "Special",
    MUIC_Group,
    sizeof(struct MUI_SpecialPData),
    (void*)SpecialP_Dispatcher 
};


static const UBYTE icon32[] =
{
    0x00, 0x00, 0x00, 0x18,  // width
    0x00, 0x00, 0x00, 0x13,  // height
    'B', 'Z', '2', '\0',
    0x00, 0x00, 0x00, 0x9c,  // number of bytes

    0x42, 0x5a, 0x68, 0x39, 0x31, 0x41, 0x59, 0x26, 0x53, 0x59, 0x4b, 0x3c, 
    0xe9, 0x24, 0x00, 0x03, 0x3b, 0xd3, 0x36, 0xa0, 0x02, 0x20, 0x00, 0x40, 
    0x00, 0x00, 0x07, 0x30, 0x00, 0x4a, 0x00, 0x00, 0x42, 0x42, 0x40, 0x00, 
    0x00, 0xb0, 0x00, 0xd8, 0x81, 0x26, 0x92, 0x9e, 0xa8, 0x06, 0x80, 0x53, 
    0x4c, 0x8c, 0x4c, 0x4c, 0x40, 0xa5, 0x22, 0x44, 0x68, 0xf4, 0x87, 0xea, 
    0x9c, 0x2a, 0xde, 0x2d, 0xe5, 0x6b, 0x29, 0x74, 0xa1, 0x79, 0x3e, 0x0d, 
    0x9e, 0x88, 0xf4, 0x46, 0x93, 0xe7, 0x22, 0xfb, 0x1d, 0x8d, 0x0f, 0xc3, 
    0xf4, 0xd1, 0xfc, 0x94, 0x38, 0x94, 0x34, 0xaa, 0x1b, 0x76, 0x18, 0xe7, 
    0x39, 0xd6, 0x6b, 0x5d, 0x2c, 0x18, 0xcc, 0xc1, 0x65, 0x82, 0xd3, 0x17, 
    0xd4, 0x25, 0xaa, 0xb0, 0x60, 0x52, 0x9a, 0x69, 0xc1, 0x9a, 0x5a, 0x40, 
    0xd6, 0x96, 0xc2, 0x0a, 0x48, 0x26, 0x1b, 0x81, 0x89, 0x11, 0x22, 0x84, 
    0x52, 0x70, 0xc2, 0x05, 0x91, 0x52, 0xb5, 0x24, 0x24, 0x7a, 0x01, 0x95, 
    0x3f, 0x8b, 0xb9, 0x22, 0x9c, 0x28, 0x48, 0x25, 0x9e, 0x74, 0x92, 0x00, 
};


Object *specialclass_get_icon(void)
{
    return RawimageObject,
        MUIA_Rawimage_Data, icon32,
    End;
}
