#ifndef _KLM_PROT_H_RPCGEN
#define _KLM_PROT_H_RPCGEN
/*
    Copyright � 2003-2004, The AROS Development Team. All rights reserved.
    $Id: klm_prot.h 30794 2009-03-08 02:19:07Z neil $
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>

#define LM_MAXSTRLEN 1024

enum klm_stats {
	klm_granted = 0,
	klm_denied = 1,
	klm_denied_nolocks = 2,
	klm_working = 3
};
typedef enum klm_stats klm_stats;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_stats(XDR *, klm_stats*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_stats(XDR *, klm_stats*);
#else /* Old Style C */
bool_t xdr_klm_stats();
#endif /* Old Style C */


struct klm_lock {
	char *server_name;
	netobj fh;
	int pid;
	u_int l_offset;
	u_int l_len;
};
typedef struct klm_lock klm_lock;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_lock(XDR *, klm_lock*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_lock(XDR *, klm_lock*);
#else /* Old Style C */
bool_t xdr_klm_lock();
#endif /* Old Style C */


struct klm_holder {
	bool_t exclusive;
	int svid;
	u_int l_offset;
	u_int l_len;
};
typedef struct klm_holder klm_holder;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_holder(XDR *, klm_holder*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_holder(XDR *, klm_holder*);
#else /* Old Style C */
bool_t xdr_klm_holder();
#endif /* Old Style C */


struct klm_stat {
	klm_stats stat;
};
typedef struct klm_stat klm_stat;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_stat(XDR *, klm_stat*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_stat(XDR *, klm_stat*);
#else /* Old Style C */
bool_t xdr_klm_stat();
#endif /* Old Style C */


struct klm_testrply {
	klm_stats stat;
	union {
		struct klm_holder holder;
	} klm_testrply_u;
};
typedef struct klm_testrply klm_testrply;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_testrply(XDR *, klm_testrply*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_testrply(XDR *, klm_testrply*);
#else /* Old Style C */
bool_t xdr_klm_testrply();
#endif /* Old Style C */


struct klm_lockargs {
	bool_t block;
	bool_t exclusive;
	struct klm_lock alock;
};
typedef struct klm_lockargs klm_lockargs;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_lockargs(XDR *, klm_lockargs*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_lockargs(XDR *, klm_lockargs*);
#else /* Old Style C */
bool_t xdr_klm_lockargs();
#endif /* Old Style C */


struct klm_testargs {
	bool_t exclusive;
	struct klm_lock alock;
};
typedef struct klm_testargs klm_testargs;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_testargs(XDR *, klm_testargs*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_testargs(XDR *, klm_testargs*);
#else /* Old Style C */
bool_t xdr_klm_testargs();
#endif /* Old Style C */


struct klm_unlockargs {
	struct klm_lock alock;
};
typedef struct klm_unlockargs klm_unlockargs;
#ifdef __cplusplus
extern "C" bool_t xdr_klm_unlockargs(XDR *, klm_unlockargs*);
#elif defined(__STDC__)
extern  bool_t xdr_klm_unlockargs(XDR *, klm_unlockargs*);
#else /* Old Style C */
bool_t xdr_klm_unlockargs();
#endif /* Old Style C */


#define KLM_PROG ((u_long)100020)
#define KLM_VERS ((u_long)1)

#ifdef __cplusplus
#define KLM_TEST ((u_long)1)
extern "C" klm_testrply * klm_test_1(struct klm_testargs *, CLIENT *);
extern "C" klm_testrply * klm_test_1_svc(struct klm_testargs *, struct svc_req *);
#define KLM_LOCK ((u_long)2)
extern "C" klm_stat * klm_lock_1(struct klm_lockargs *, CLIENT *);
extern "C" klm_stat * klm_lock_1_svc(struct klm_lockargs *, struct svc_req *);
#define KLM_CANCEL ((u_long)3)
extern "C" klm_stat * klm_cancel_1(struct klm_lockargs *, CLIENT *);
extern "C" klm_stat * klm_cancel_1_svc(struct klm_lockargs *, struct svc_req *);
#define KLM_UNLOCK ((u_long)4)
extern "C" klm_stat * klm_unlock_1(struct klm_unlockargs *, CLIENT *);
extern "C" klm_stat * klm_unlock_1_svc(struct klm_unlockargs *, struct svc_req *);

#elif defined(__STDC__)
#define KLM_TEST ((u_long)1)
extern  klm_testrply * klm_test_1(struct klm_testargs *, CLIENT *);
extern  klm_testrply * klm_test_1_svc(struct klm_testargs *, struct svc_req *);
#define KLM_LOCK ((u_long)2)
extern  klm_stat * klm_lock_1(struct klm_lockargs *, CLIENT *);
extern  klm_stat * klm_lock_1_svc(struct klm_lockargs *, struct svc_req *);
#define KLM_CANCEL ((u_long)3)
extern  klm_stat * klm_cancel_1(struct klm_lockargs *, CLIENT *);
extern  klm_stat * klm_cancel_1_svc(struct klm_lockargs *, struct svc_req *);
#define KLM_UNLOCK ((u_long)4)
extern  klm_stat * klm_unlock_1(struct klm_unlockargs *, CLIENT *);
extern  klm_stat * klm_unlock_1_svc(struct klm_unlockargs *, struct svc_req *);

#else /* Old Style C */
#define KLM_TEST ((u_long)1)
extern  klm_testrply * klm_test_1();
extern  klm_testrply * klm_test_1_svc();
#define KLM_LOCK ((u_long)2)
extern  klm_stat * klm_lock_1();
extern  klm_stat * klm_lock_1_svc();
#define KLM_CANCEL ((u_long)3)
extern  klm_stat * klm_cancel_1();
extern  klm_stat * klm_cancel_1_svc();
#define KLM_UNLOCK ((u_long)4)
extern  klm_stat * klm_unlock_1();
extern  klm_stat * klm_unlock_1_svc();
#endif /* Old Style C */

#endif /* !_KLM_PROT_H_RPCGEN */
