// IconobjectMCC.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef ICONOBJECT_MCC_H
#define	ICONOBJECT_MCC_H

/* ------------------------------------------------------------------------- */

struct MUI_CustomClass *InitIconobjectClass(void);
void CleanupIconobjectClass(struct MUI_CustomClass *mcc);

/* ------------------------------------------------------------------------- */

#ifdef __AROS__
#define IconobjectMCCObject BOOPSIOBJMACRO_START(IconobjectClass->mcc_Class)
#else
#define IconobjectMCCObject NewObject(IconobjectClass->mcc_Class, 0
#endif

/* ------------------------------------------------------------------------- */

#define MUIA_Iconobj_Object			0x80429876 	/* I.. Object * */

/* ------------------------------------------------------------------------- */

#endif /* ICONOBJECT_MCC_H */
