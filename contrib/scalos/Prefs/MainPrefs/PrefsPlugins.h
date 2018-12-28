// PrefsPlugins.h
// $Date: 2016-03-19 17:20:29 +0100 (Sat, 19 Mar 2016) $
// $Revision: 52064 $


#ifndef	PREFSPLUGINS_H
#define	PREFSPLUGINS_H

#include <intuition/classusr.h>
#include "ScalosPrefs.h"

//----------------------------------------------------------------------------

BOOL PrefsPluginsInit(void);
void PrefsPluginsCleanup(void);
void CollectPrefsPlugins(struct SCAModule *app, CONST_STRPTR Path, CONST_STRPTR Pattern);
struct TagItem *GetPrefsPluginSubWindows(struct SCAModule *app);
void CreatePrefsPlugins(struct SCAModule *app);
void InsertPrefsPlugins(struct SCAModule *app, Object *pageGroup, Object *pageList);
ULONG DoMethodForAllPrefsPlugins(ULONG ArgCount, ULONG MethodID, ...);
void SetAttributeForAllPrefsPlugins(ULONG Attribute, IPTR Value);
void NotifyPrefsPluginsPageChange(ULONG ActivePage);
BOOL CheckMCCsForAllPrefsPlugins(void);

//----------------------------------------------------------------------------

#endif /* PREFSPLUGINS_H */
