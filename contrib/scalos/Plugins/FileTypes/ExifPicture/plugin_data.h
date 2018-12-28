// plugin_data.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef PLUGIN_DATA_H_INCLUDED
#define PLUGIN_DATA_H_INCLUDED

#include <defs.h>
#include <Year.h>

#define PLUGIN_TYPE	FILETYPE

#define LIB_BASETYPE	struct ExifPictureBase

#define	LIB_VERSION	40
#define	LIB_REVISION	0

#define LIB_NAME	"exifpicture.plugin"
#define LIB_VERSTRING   "$VER: exifpicture.plugin " \
			STR(LIB_VERSION) "." STR(LIB_REVISION)  " (30.09.2005)" \
			COMPILER_STRING " �2005" CURRENTYEAR \
			" The Scalos Team, parts of code from Jhead(public domain software) �Matthias Wandel"


#define FT_INFOSTRING		LIBToolTipInfoString
#define FT_INFOSTRING_AROS	PluginBase_0_LIBToolTipInfoString

//----------------------------------------------------------------------------
// code and includes to define the structs and functions used above

#include "ExifPicture_base.h"

#endif /* PLUGUN_DATA_H_INCLUDED */

