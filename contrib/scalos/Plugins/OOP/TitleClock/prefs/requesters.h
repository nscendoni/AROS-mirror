/*
 *  requesters.h    Protos for ASL requester and such like
 *
 * $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
 * $Revision: 48481 $
 *
 *  0.1
 *  20010804    DM  + Created
 *
 */

#ifndef REQUESTERS_H
#define REQUESTERS_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

STRPTR  SaveFileReq(struct Window *win);
STRPTR  OpenFileReq(struct Window *win);


#endif /* REQUESTERS_H */

