/*
    Copyright © 2004, The AROS Development Team. All rights reserved.
    $Id: htmlclass.h 33378 2010-05-29 13:35:32Z mazze $
*/

/*******************************************************************************************/
/* Internal Class Data */

struct HtmlData
{
	APTR		mempool;
	page_struct	*page;
	parse_struct	*pdata;
	layout_struct	*ldata;
	struct List	*linelist;
	struct RastPort	*rastport;
	struct TextFont	*font;
	ULONG		style;
	UBYTE		fgpen;
	UBYTE		bgpen;
	long		linenum;
};

