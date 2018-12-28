// WBRexxMain.c
// $Date: 2016-03-15 05:14:25 +0100 (Tue, 15 Mar 2016) $
// $Revision: 51969 $


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <exec/types.h>
#include <exec/nodes.h>
#include <intuition/classes.h>
#include <intuition/intuitionbase.h>
#include <datatypes/iconobject.h>
#include <dos/dos.h>
#include <dos/dosextens.h>
#include <dos/dostags.h>
#include <scalos/scalos.h>
#include <scalos/preferences.h>
#include <workbench/workbench.h>
#include <workbench/startup.h>
#include <workbench/icon.h>
#include <libraries/iffparse.h>
#include <libraries/commodities.h>

#include <clib/alib_protos.h>

#include <proto/iconobject.h>
#include <proto/utility.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/scalos.h>
#include <proto/intuition.h>
#include <proto/layers.h>
#include <proto/icon.h>
#include <proto/iffparse.h>
#include <proto/preferences.h>

#include <defs.h>

//#include "wb39.h"
//#include "wb39proto.h"
#include "wbrexx.h"
#include "Scalos_Helper.h"

#ifdef __AROS__
#include "plugin.h"
#include "plugin-common.c"
#endif

static BOOL OpenLibraries(void);
static void CloseLibraries(void);


#ifndef __AROS__
struct DosLibrary *DOSBase;
T_UTILITYBASE UtilityBase;
struct IntuitionBase *IntuitionBase;
struct Library *LayersBase;
struct Library *IconBase;
struct Library *IFFParseBase;
#endif
struct ScalosBase *ScalosBase;
struct Library *IconobjectBase;
struct Library *WorkbenchBase;
struct Library *GfxBase;
struct Library *AmigaGuideBase;
T_LOCALEBASE *LocaleBase;
struct Library *CxBase;

#ifdef __amigaos4__
struct Library *NewlibBase;

struct DOSIFace *IDOS;
struct IconobjectIFace *IIconobject;
struct WorkbenchIFace *IWorkbench;
struct UtilityIFace *IUtility;
struct ScalosIFace *IScalos;
struct IntuitionIFace *IIntuition;
struct LayersIFace *ILayers;
struct GraphicsIFace *IGraphics;
struct IconIFace *IIcon;
struct IFFParseIFace *IIFFParse;
struct CommoditiesIFace *ICommodities;
struct Interface *INewlib;
struct AmigaGuideIFace *IAmigaGuide;
struct LocaleIFace *ILocale;
#endif

#if defined(__GNUC__) && !defined(__MORPHOS__) && !defined(__amigaos4__) && !defined(__AROS__)
extern T_UTILITYBASE __UtilityBase;
#endif /* defined(__GNUC__) && !defined(__MORPHOS__) && !defined(__amigaos4__) */

static BOOL fInit;

struct List AppWindowList;	// list of all AppWindows
struct SignalSemaphore AppWindowSema;

ULONG DefaultStackSize = 4095;
ULONG fVolumeGauge = TRUE;
ULONG fTitleBar = TRUE;
ULONG TypeRestartTime = 3;		// Keyboard restart delay in s
BOOL NewIconsSupport = TRUE;
BOOL ColorIconsSupport = TRUE;


WORD ScalosPrefs_IconOffsets[4] = { 1, 1, 1, 1 };

struct ScaRootList *rList = NULL;


M68KFUNC_P3(IPTR, myHookFunc,
	A0, Class *, cl,
	A2, Object *, obj,
	A1, Msg, msg)
{
	IPTR Result;

	d1(kprintf(__FUNC__ "/%ld: MethodID=%08lx\n", __LINE__, msg->MethodID));

	rList = (struct ScaRootList *) obj;

	d1(kprintf(__FUNC__ "/%ld: rList=%08lx\n", __LINE__, rList);)

	switch (msg->MethodID)
		{
	case SCCM_IconWin_RawKey:
		{
		struct msg_RawKey *mrk = (struct msg_RawKey *) msg;

		DoKeyboardCommand(mrk->mrk_iMsg);

		Result = DoSuperMethodA(cl, obj, msg);
		}
		break;

	default:
		Result = DoSuperMethodA(cl, obj, msg);
		break;
		}

	return Result;
}
M68KFUNC_END


BOOL initPlugin(struct PluginBase *base)
{
	d(kprintf(__FUNC__ "/%ld: \n", __LINE__));

#ifdef __AROS__
	base->pl_PlugID = MAKE_ID('P','L','U','G');
#endif

	if (!fInit)
		{
		if (!OpenLibraries())
			return FALSE;

		d(kprintf(__FUNC__ "/%ld: IconobjectBase=%08lx WorkbenchBase=%08lx UtilityBase=%08lx\n", \
			__LINE__, IconobjectBase, WorkbenchBase, UtilityBase));

		rList = GetScalosRootList();
		d1(kprintf(__FUNC__ "/%ld: ScaRootList=%08lx\n", __LINE__, rList));

		fInit = StartWBRexxProcess();

		if (fInit)
			{
			// try to use current WB settings
			ParseWBPrefs("ENV:sys/Workbench.prefs");

			// Read some Scalos preferences settings
			ReadScalosPrefs();
			}
		else
			closePlugin(base);

		return fInit;
		}

	return TRUE;
}


BOOL closePlugin(struct PluginBase *base)
{
	ShutdownWBRexxProcess();

	CloseLibraries();

	fInit = FALSE;
	return TRUE;
}


static BOOL OpenLibraries(void)
{
	DOSBase = (struct DosLibrary *) OpenLibrary(DOSNAME, 39);
	if (NULL == DOSBase)
		return FALSE;
#ifdef __amigaos4__
	IDOS = (struct DOSIFace *)GetInterface((struct Library *)DOSBase, "main", 1, NULL);
	if (NULL == IDOS)
		return FALSE;
#endif //__amigaos4__

	IconobjectBase = OpenLibrary("iconobject.library", 39);
	if (NULL == IconobjectBase)
		return FALSE;
#ifdef __amigaos4__
	IIconobject = (struct IconobjectIFace *)GetInterface((struct Library *)IconobjectBase, "main", 1, NULL);
	if (NULL == IIconobject)
		return FALSE;
#endif //__amigaos4__

	WorkbenchBase = OpenLibrary(WORKBENCH_NAME, 39);
	if (NULL == WorkbenchBase)
		return FALSE;
#ifdef __amigaos4__
	IWorkbench = (struct WorkbenchIFace *)GetInterface((struct Library *)WorkbenchBase, "main", 1, NULL);
	if (NULL == IWorkbench)
		return FALSE;
#endif //__amigaos4__

	UtilityBase = (T_UTILITYBASE) OpenLibrary("utility.library", 39);
	if (NULL == UtilityBase)
		return FALSE;
#ifdef __amigaos4__
	IUtility = (struct UtilityIFace *)GetInterface((struct Library *)UtilityBase, "main", 1, NULL);
	if (NULL == IUtility)
		return FALSE;
#endif
#if defined(__GNUC__) && !defined(__MORPHOS__) && !defined(__amigaos4__) && !defined(__AROS__)
	__UtilityBase = UtilityBase;
#endif /* defined(__GNUC__) && !defined(__MORPHOS__) && !defined(__amigaos4__) */

	ScalosBase = (struct ScalosBase *) OpenLibrary(SCALOSNAME, 41);
	if (NULL == ScalosBase)
		return FALSE;
#ifdef __amigaos4__
	IScalos = (struct ScalosIFace *)GetInterface((struct Library *)ScalosBase, "main", 1, NULL);
	if (NULL == IScalos)
		return FALSE;
#endif //__amigaos4__

	// keep library open count at 0 otherwise Scalos will refuse to quit
	CloseLibrary((struct Library *) ScalosBase);

	IntuitionBase = (struct IntuitionBase *) OpenLibrary("intuition.library", 39);
	if (NULL == IntuitionBase)
		return FALSE;
#ifdef __amigaos4__
	IIntuition = (struct IntuitionIFace *)GetInterface((struct Library *)IntuitionBase, "main", 1, NULL);
	if (NULL == IIntuition)
		return FALSE;
#endif //__amigaos4__

	LayersBase = OpenLibrary("layers.library", 39);
	if (NULL == LayersBase)
		return FALSE;
#ifdef __amigaos4__
	ILayers = (struct LayersIFace *)GetInterface((struct Library *)LayersBase, "main", 1, NULL);
	if (NULL == ILayers)
		return FALSE;
#endif //__amigaos4__

	GfxBase = OpenLibrary("graphics.library", 39);
	if (NULL == GfxBase)
		return FALSE;
#ifdef __amigaos4__
	IGraphics = (struct GraphicsIFace *)GetInterface((struct Library *)GfxBase, "main", 1, NULL);
	if (NULL == IGraphics)
		return FALSE;
#endif //__amigaos4__

	IconBase = OpenLibrary("icon.library", 39);
	if (NULL == IconBase)
		return FALSE;
#ifdef __amigaos4__
	IIcon = (struct IconIFace *)GetInterface((struct Library *)IconBase, "main", 1, NULL);
	if (NULL == IIcon)
		return FALSE;
#endif //__amigaos4__

	IFFParseBase = OpenLibrary("iffparse.library", 39);
	if (NULL == IFFParseBase)
		return FALSE;
#ifdef __amigaos4__
	IIFFParse = (struct IFFParseIFace *)GetInterface((struct Library *)IFFParseBase, "main", 1, NULL);
	if (NULL == IIFFParse)
		return FALSE;
#endif //__amigaos4__

	LocaleBase = (T_LOCALEBASE *) OpenLibrary("locale.library", 39);
	if (NULL == LocaleBase)
		return FALSE;
#ifdef __amigaos4__
	ILocale  = (struct LocaleIFace *)GetInterface((struct Library *)LocaleBase, "main", 1, NULL);
	if (NULL == ILocale)
		return FALSE;

#endif //__amigaos4__
	AmigaGuideBase = OpenLibrary("amigaguide.library", 39);
	if (NULL == AmigaGuideBase)
		return FALSE;
#ifdef __amigaos4__
	IAmigaGuide = (struct AmigaGuideIFace *)GetInterface((struct Library *)AmigaGuideBase, "main", 1, NULL);
	if (NULL == IAmigaGuide)
		return FALSE;
#endif //__amigaos4__

	CxBase = OpenLibrary("commodities.library", 39);
	if (NULL == CxBase)
		return FALSE;

#ifdef __amigaos4__
	ICommodities = (struct CommoditiesIFace *)GetInterface((struct Library *)CxBase, "main", 1, NULL);
	if (NULL == ICommodities)
		return FALSE;

	NewlibBase = OpenLibrary("newlib.library", 0);
	if (NULL == NewlibBase)
		return FALSE;
	INewlib = GetInterface(NewlibBase, "main", 1, NULL);
	if (NULL == INewlib)
		return FALSE;
#endif //__amigaos4__

	return TRUE;
}


static void CloseLibraries(void)
{
#ifdef __amigaos4__
	if (INewlib)
		{
		DropInterface(INewlib);
		INewlib = NULL;
		}
	if (NewlibBase)
		{
		CloseLibrary(NewlibBase);
		NewlibBase = NULL;
		}
	if (ICommodities)
		{
		DropInterface((struct Interface *)ICommodities);
		ICommodities = NULL;
		}
#endif //__amigaos4__
	if (CxBase)
		{
		CloseLibrary(CxBase);
		CxBase = NULL;
		}

#ifdef __amigaos4__
	if (ILocale)
		{
		DropInterface((struct Interface *) ILocale);
		ILocale	= NULL;
		}
#endif //__amigaos4__
	if (LocaleBase)
		{
		CloseLibrary((struct Library *) LocaleBase);
		LocaleBase = NULL;
		}

#ifdef __amigaos4__
	if (IAmigaGuide)
		{
		DropInterface((struct Interface *) IAmigaGuide);
		IAmigaGuide = NULL;
		}
#endif //__amigaos4__
	if (AmigaGuideBase)
		{
		CloseLibrary(AmigaGuideBase);
		AmigaGuideBase = NULL;
		}

#ifdef __amigaos4__
	if (IIFFParse)
		{
		DropInterface((struct Interface *)IIFFParse);
		IIFFParse = NULL;
		}
#endif //__amigaos4__
	if (IFFParseBase)
		{
		CloseLibrary(IFFParseBase);
		IFFParseBase = NULL;
		}
#ifdef __amigaos4__
	if (IIcon)
		{
		DropInterface((struct Interface *)IIcon);
		IIcon = NULL;
		}
#endif //__amigaos4__
	if (IconBase)
		{
		CloseLibrary(IconBase);
		IconBase = NULL;
		}
#ifdef __amigaos4__
	if (IGraphics)
		{
		DropInterface((struct Interface *)IGraphics);
		IGraphics = NULL;
		}
#endif //__amigaos4__
	if (GfxBase)
		{
		CloseLibrary(GfxBase);
		GfxBase = NULL;
		}
#ifdef __amigaos4__
	if (IDOS)
		{
		DropInterface((struct Interface *)IDOS);
		IDOS = NULL;
		}
#endif //__amigaos4__
	if (DOSBase)
		{
		CloseLibrary((struct Library *) DOSBase);
		DOSBase = NULL;
		}
#ifdef __amigaos4__
	if (IIconobject)
		{
		DropInterface((struct Interface *)IIconobject);
		IIconobject = NULL;
		}
#endif //__amigaos4__
	if (IconobjectBase)
		{
		CloseLibrary(IconobjectBase);
		IconobjectBase = NULL;
		}
#ifdef __amigaos4__
	if (IWorkbench)
		{
		DropInterface((struct Interface *)IWorkbench);
		IWorkbench = NULL;
		}
#endif //__amigaos4__
	if (WorkbenchBase)
		{
		CloseLibrary(WorkbenchBase);
		WorkbenchBase = NULL;
		}
#ifdef __amigaos4__
	if (IUtility)
		{
		DropInterface((struct Interface *)IUtility);
		IUtility = NULL;
		}
#endif //__amigaos4__
	if (UtilityBase)
		{
		CloseLibrary((struct Library *) UtilityBase);
		UtilityBase = NULL;
		}
#ifdef __amigaos4__
	if (IScalos)
		{
		DropInterface((struct Interface *)IScalos);
		IScalos = NULL;
		}
#endif //__amigaos4__
#if 0
	if (ScalosBase)
		{
		CloseLibrary((struct Library *) ScalosBase);
		ScalosBase = NULL;
		}
#endif //0
#ifdef __amigaos4__
	if (IIntuition)
		{
		DropInterface((struct Interface *)IIntuition);
		IIntuition = NULL;
		}
#endif //__amigaos4__
	if (IntuitionBase)
		{
		CloseLibrary((struct Library *) IntuitionBase);
		IntuitionBase = NULL;
		}
#ifdef __amigaos4__
	if (ILayers)
		{
		DropInterface((struct Interface *)ILayers);
		ILayers = NULL;
		}
#endif //__amigaos4__
	if (LayersBase)
		{
		CloseLibrary(LayersBase);
		LayersBase = NULL;
		}
}

#ifdef __SASC

void _XCEXIT(long x)
{
	(void) x;
}

#else /* __SASC */

#ifndef __amigaos4__

void exit(int x)
{
	(void) x;
	while (1)
		;
}

APTR _WBenchMsg;

#endif /* __amigaos4__ */

#endif /* __SASC */

//----------------------------------------------------------------------------

#if defined(__AROS__)

#include "aros/symbolsets.h"

ADD2EXPUNGELIB(closePlugin, 0);
ADD2OPENLIB(initPlugin, 0);

#endif

//----------------------------------------------------------------------------
