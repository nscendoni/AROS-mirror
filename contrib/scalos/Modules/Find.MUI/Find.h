// Find.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef FIND_MODULE_H
#define FIND_MODULE_H

//----------------------------------------------------------------------------

#define	VERSION_MAJOR	40
#define	VERSION_MINOR	3

#define	VERS_MAJOR	STR(VERSION_MAJOR)
#define	VERS_MINOR	STR(VERSION_MINOR)

//----------------------------------------------------------------------------

#define OBJID_NLIST_NAME	4913001
#define OBJID_NLIST_TEXT	4913002

struct FileTypesEntry
	{
	STRPTR fte_AllocatedName;	// allocated space for tn_Name
	struct TypeNode fte_TypeNode;

	struct List fte_MagicList;	// List of FileTypesActionListEntry
	};

struct FileTypesPrefsInst
{
	BPTR	fpb_DefIconsSegList;
	struct TypeNode *fpb_RootType;
	BOOL   fpb_DefIconsInit;
};

//----------------------------------------------------------------------------

extern Object *ListtreeFileTypes;

//----------------------------------------------------------------------------

// Functions in DefIcons.c
LONG InitDefIcons(void);
void CleanupDefIcons(void);
struct TypeNode *DefIconsIdentify(BPTR dirLock, CONST_STRPTR Name);

//----------------------------------------------------------------------------

#if defined(__SASC)
int snprintf(char *, size_t, const char *, /*args*/ ...);
int vsnprintf(char *, size_t, const char *, va_list ap);
#endif /* __SASC */

//----------------------------------------------------------------------------

struct Find_LocaleInfo
{
	APTR li_LocaleBase;
	APTR li_Catalog;
	struct LocaleIFace *li_ILocale;
};

//----------------------------------------------------------------------------

#endif	/* FIND_MODULE_H */
