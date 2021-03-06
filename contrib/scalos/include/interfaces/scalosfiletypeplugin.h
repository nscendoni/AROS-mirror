#ifndef SCALOSFILETYPEPLUGIN_INTERFACE_DEF_H
#define SCALOSFILETYPEPLUGIN_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.1.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef SCALOS_SCALOS_H
#include <scalos/scalos.h>
#endif

struct ScalosFileTypePluginIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ScalosFileTypePluginIFace *Self);
	uint32 APICALL (*Release)(struct ScalosFileTypePluginIFace *Self);
	void APICALL (*Expunge)(struct ScalosFileTypePluginIFace *Self);
	struct Interface * APICALL (*Clone)(struct ScalosFileTypePluginIFace *Self);
	STRPTR APICALL (*SCAToolTipInfoString)(struct ScalosFileTypePluginIFace *Self, struct ScaToolTipInfoHookData * ttshd, CONST_STRPTR args);
};

#endif /* SCALOSFILETYPEPLUGIN_INTERFACE_DEF_H */
