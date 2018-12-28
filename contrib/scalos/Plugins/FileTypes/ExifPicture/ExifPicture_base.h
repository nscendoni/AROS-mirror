// ExifPicture_base.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef __EXIFPICTURE_BASE
#define __EXIFPICTURE_BASE

#include <libraries/locale.h>

#include "plugin.h"

struct ExifPictureBase
{
	struct PluginBase pdb_PluginBase;

	struct	Locale *pdb_Locale;
	struct	Catalog *pdb_Catalog;
};

#endif //__EXIFPICTURE_BASE

