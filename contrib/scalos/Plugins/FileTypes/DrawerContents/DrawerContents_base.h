// DrawerContents.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef __DRAWERCONTENTS_BASE_H
#define __DRAWERCONTENTS_BASE_H

#include <libraries/locale.h>

#include "plugin.h"

struct DrawerContentsBase
{
	struct PluginBase dcb_LibNode;

	struct	Locale *dcb_Locale;
	struct	Catalog *dcb_Catalog;
};

#endif // __DRAWERCONTENTS_BASE_H

