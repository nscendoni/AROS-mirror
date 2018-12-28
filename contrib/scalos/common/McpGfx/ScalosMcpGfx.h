// ScalosMcpGfx.c
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef SCALOS_MCPGFX_H
#define	SCALOS_MCPGFX_H

#include <libraries/mcpgfx.h>

/* ------------------------------------------------------------------------- */

void McpGfxRectFill(struct RastPort *rp,
	UWORD MinX, WORD MinY, WORD MaxX, WORD MaxY, ULONG FirstTag, ...);
void McpGfxDrawFrame(struct RastPort *rp,
	UWORD MinX, WORD MinY, WORD MaxX, WORD MaxY, ULONG FirstTag, ...);
const struct FrameSize *McpGetFrameSize(UWORD frameType);

/* ------------------------------------------------------------------------- */

#endif /* SCALOS_MCPGFX_H */
