// cx_private.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef _PPCINLINE_COMMODITIES_PRIVATE_H
#define _PPCINLINE_COMMODITIES_PRIVATE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef COMMODITIES_BASE_NAME
#define COMMODITIES_BASE_NAME CxBase
#endif /* !COMMODITIES_BASE_NAME */

#define CxCopyBrokerList(list) \
        LP1(186, LONG, CopyBrokerList, struct List *, list, a0, \
        , CxBase, 0, 0, 0, 0, 0, 0)

#define CxFreeBrokerList(list) \
        LP1(192, LONG, FreeBrokerList, struct List *, list, a0, \
        , CxBase, 0, 0, 0, 0, 0, 0)

#define CxBrokerCommand(name,cmd) \
        LP2(198, LONG, BrokerCommand, BYTE *, name, a0, LONG, cmd, d0, \
        , CxBase, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_COMMODITIES_PRIVATE_H */

