// cx_private.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef PROTO_COMMODITIES_PRIVATE_H
#define PROTO_COMMODITIES_PRIVATE_H

#include <proto/commodities.h>

#if defined(__amigaos4__) || defined(__AROS__)

#define	CxCopyBrokerList	CopyBrokerList
#define	CxFreeBrokerList	FreeBrokerList
#define	CxBrokerCommand	BrokerCommand

#else //!defined(__amigaos4__)

#ifdef __GNUC__
#ifdef __PPC__
#ifndef _NO_PPCINLINE
#include "cx_private_ppcinline.h"
#endif /* _NO_PPCINLINE */
#else
#ifndef _NO_INLINE
#include "cx_private_inline.h"
#endif /* _NO_INLINE */
#endif /* __PPC__ */
#else
#include "cx_private_pragmas.h"
#endif /* __GNUC__ */
#endif //!defined(__amigaos4__)

#endif /* !PROTO_COMMODITIES_PRIVATE_H */

