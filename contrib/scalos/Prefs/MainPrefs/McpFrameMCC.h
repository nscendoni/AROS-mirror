// McpFrameMCC.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef MCPFRAME_MCC_H
#define	MCPFRAME_MCC_H

/* ------------------------------------------------------------------------- */

#include <defs.h>
#include "MCPFrame_mcc.h"

/* ------------------------------------------------------------------------- */

struct MUI_CustomClass *InitMcpFrameClass(void);
void CleanupMcpFrameClass(struct MUI_CustomClass *mcc);

/* ------------------------------------------------------------------------- */

extern struct MUI_CustomClass *MccFrameClass;

/* ------------------------------------------------------------------------- */

#endif /* MCPFRAME_MCC_H */
