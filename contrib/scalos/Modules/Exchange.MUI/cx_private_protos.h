// cx_private_protos.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef CLIB_COMMODITIES_PRIVATE_PROTOS_H
#define CLIB_COMMODITIES_PRIVATE_PROTOS_H

/*
	commodities.library private C prototypes
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef LIBRARIES_COMMODITIES_H
# include <libraries/commodities.h>
#endif

#ifndef DEVICES_INPUTEVENT_H
# include <devices/inputevent.h>
#endif

#ifndef DEVICES_KEYMAP_H
# include <devices/keymap.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

LONG CxCopyBrokerList(struct List *brokerList);
LONG CxFreeBrokerList(struct List *brokerList);
LONG CxBrokerCommand(CONST_STRPTR name, LONG cmd);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_COMMODITIES_PROTOS_H */
