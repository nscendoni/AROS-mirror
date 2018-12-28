// plugin_data.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef PLUGIN_DATA_H_INCLUDED
#define PLUGIN_DATA_H_INCLUDED

#include <defs.h>
#include <Year.h>

#define PLUGIN_TYPE		OOP

#define LIB_BASETYPE 		struct XTWindowsBase

#define	LIB_VERSION		40
#define	LIB_REVISION		6

#define LIB_NAME 		"xtwindows.plugin"
#define LIB_VERSTRING 		"$VER: xtwindows.plugin " \
				STR(LIB_VERSION) "." STR(LIB_REVISION) \
				" (25.04.05) " COMPILER_STRING

#define CI_CLASSNAME 		"IconWindow.sca"
#define CI_SUPERCLASSNAME 	"IconWindow.sca"
#define CI_PLUGINNAME 		"XTWindows class"
#define CI_DESCRIPTION 		"This class extends the windows functions " COMPILER_STRING
#define CI_AUTHOR 		"David Rydh"
#define CI_PRIORITY 		-70
#define CI_INSTSIZE 		sizeof(struct XTWindowsInstanceData)
#define CI_HOOKFUNC 		Dispatcher

//----------------------------------------------------------------------------
// code and includes to define the structs and functions used above

#include "XTWindows.h"

#endif /* PLUGUN_DATA_H_INCLUDED */

