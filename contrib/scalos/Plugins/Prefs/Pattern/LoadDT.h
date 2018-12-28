// loaddt.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

//--------------------------------------------------------------------------------

extern struct Library *DataTypesBase;

//--------------------------------------------------------------------------------

struct ScalosBitMapAndColor *DoLoadDT(STRPTR source, struct RastPort *rast,
	ULONG ScaledWidth, ULONG ScaledHeight,
	struct Screen *screen);
void ShowError(const char *str, ...);

//--------------------------------------------------------------------------------

extern int KPrintF(const char *fmt, ...);

//--------------------------------------------------------------------------------

