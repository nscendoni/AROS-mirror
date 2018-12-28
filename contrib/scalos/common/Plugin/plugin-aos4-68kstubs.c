// plugin-aos4-68kstubs.c
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#include "plugin.h"

#if PLUGIN_TYPE == OOP
#include "scalosplugin-aos4-68kstubs.c"
#elif PLUGIN_TYPE == FILETYPE
#include "scalosfiletypeplugin-aos4-68kstubs.c"
#elif PLUGIN_TYPE == PREVIEW
#include "scalospreviewplugin-aos4-68kstubs.c"
#elif PLUGIN_TYPE == PREFS
#include "scalosprefsplugin-aos4-68kstubs.c"
#else
#error Unsupported plugin type
#endif

