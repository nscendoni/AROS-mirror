// Updater.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef UPDATER_MODULE_H
#define UPDATER_MODULE_H

//----------------------------------------------------------------------------

#define	VERSION_MAJOR	40
#define	VERSION_MINOR	3

#define	VERS_MAJOR	STR(VERSION_MAJOR)
#define	VERS_MINOR	STR(VERSION_MINOR)

//----------------------------------------------------------------------------

#if defined(__SASC)
int snprintf(char *, size_t, const char *, /*args*/ ...);
int vsnprintf(char *, size_t, const char *, va_list ap);
#endif /* __SASC */

//----------------------------------------------------------------------------

struct Updater_LocaleInfo
{
	APTR li_LocaleBase;
	APTR li_Catalog;
	struct LocaleIFace *li_ILocale;
};

//----------------------------------------------------------------------------

#endif	/* UPDATER_MODULE_H */
