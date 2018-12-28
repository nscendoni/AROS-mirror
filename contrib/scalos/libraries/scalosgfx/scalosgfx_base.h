// scalosgfx_base.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef SCALOSGFXBASE_H
#define	SCALOSGFXBASE_H

#include <exec/types.h>
#include <exec/lists.h>
#include <exec/libraries.h>


struct ScalosGfxBase
{
	struct Library sgb_LibNode;

	struct SegList *sgb_SegList;

	BOOL sgb_Initialized;

	struct SignalSemaphore sgb_MemPoolSemaphore;
	APTR sgb_MemPool;

	struct SignalSemaphore sgb_PrefsListSem;
	struct List sgb_PrefsList;
};

//----------------------------------------------------------------------------

#endif /* SCALOSGFXBASE_H */
