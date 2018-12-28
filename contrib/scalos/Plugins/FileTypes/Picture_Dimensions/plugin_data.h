// plugin_data.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef PLUGIN_DATA_H_INCLUDED
#define PLUGIN_DATA_H_INCLUDED

#include <defs.h>
#include <Year.h>

#define PLUGIN_TYPE	FILETYPE

#define LIB_BASETYPE	struct PictureDimensionsBase

#define	LIB_VERSION	40
#define	LIB_REVISION	6

#define LIB_NAME	"picturedimensions.plugin"
#define LIB_VERSTRING   "$VER: picturedimensions.plugin " \
			STR(LIB_VERSION) "." STR(LIB_REVISION)  " (20.02.2005)" \
			COMPILER_STRING " ©2003" CURRENTYEAR \
			" The Scalos Team"


#define FT_INFOSTRING		LIBToolTipInfoString
#define FT_INFOSTRING_AROS	PluginBase_0_LIBToolTipInfoString

//----------------------------------------------------------------------------
// code and includes to define the structs and functions used above

#include "picturedimensions_base.h"

#endif /* PLUGUN_DATA_H_INCLUDED */

