// Backfill.h
// $Date: 2016-03-19 17:20:57 +0100 (Sat, 19 Mar 2016) $
// $Revision: 52065 $


#ifndef SCALOS_BACKFILL_H
#define SCALOS_BACKFILL_H

//----------------------------------------------------------------------------

#define BACKFILLBASE		0x80430100


#define BFA_BitmapObject	(BACKFILLBASE+1)	// [IS.] Object *

//----------------------------------------------------------------------------

struct SetBackFillMsg
	{
	STACKED ULONG sbf_MethodID;
	STACKED CONST_STRPTR sbf_FileName;
	STACKED ULONG sbf_PattFlags;
	STACKED ULONG sbf_DefsFlags;
	};

//----------------------------------------------------------------------------

extern struct MUI_CustomClass *BackfillClass;
extern struct MUI_CustomClass *BitMapPicClass;

#ifdef __AROS__
#define BackfillObject BOOPSIOBJMACRO_START(BackfillClass->mcc_Class)
#define BitMapPicObject BOOPSIOBJMACRO_START(BitMapPicClass->mcc_Class)
#else
#define BackfillObject NewObject(BackfillClass->mcc_Class, 0
#define BitMapPicObject NewObject(BitMapPicClass->mcc_Class, 0
#endif

//----------------------------------------------------------------------------

struct MUI_CustomClass *InitBackfillClass(void);
void CleanupBackfillClass(void);

//----------------------------------------------------------------------------

#endif /* SCALOS_BACKFILL_H */

