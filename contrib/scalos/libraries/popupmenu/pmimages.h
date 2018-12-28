// pmimages.h
//
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

enum {
	PMIMG_SUBMENU,
	PMIMG_SUBMENU_S,
	PMIMG_CHECKMARK,
	PMIMG_CHECKMARK_S,
	PMIMG_EXCLUDE,
	PMIMG_EXCLUDE_S,
	PMIMG_AMIGAKEY,
	PMIMG_AMIGAKEY_S,
	PMIMG_CTRLKEY,
	PMIMG_CTRLKEY_S,
	PMIMG_MULTISELECT,
	PMIMG_MULTISELECT_S,
	PMIMG_LAST
};

void PM_Image_Allocate(struct PM_Root *p);
void PM_Image_Free(struct PM_Root *p);
UWORD PM_Image_Height(struct PM_Root *p, ULONG type, struct PopupMenu *item);
UWORD PM_Image_Width(struct PM_Root *p, ULONG type, struct PopupMenu *item);
UWORD PM_Image_Draw(struct PM_Window *w, ULONG type, WORD l, struct DrawInfo *dri, ULONG state, struct PopupMenu *item);

