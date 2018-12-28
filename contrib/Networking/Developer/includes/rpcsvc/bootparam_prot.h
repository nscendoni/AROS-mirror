#ifndef _BOOTPARAM_PROT_H_RPCGEN
#define _BOOTPARAM_PROT_H_RPCGEN
/*
    Copyright � 2003-2004, The AROS Development Team. All rights reserved.
    $Id: bootparam_prot.h 30794 2009-03-08 02:19:07Z neil $
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#define RPCGEN_VERSION	199506

#include <rpc/rpc.h>

#include <sys/param.h>
#include <rpc/types.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <sys/ucred.h>
#define MAX_MACHINE_NAME 255
#define MAX_PATH_LEN 1024
#define MAX_FILEID 32
#define IP_ADDR_TYPE 1

typedef char *bp_machine_name_t;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_machine_name_t(XDR *, bp_machine_name_t*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_machine_name_t(XDR *, bp_machine_name_t*);
#else /* Old Style C */
bool_t xdr_bp_machine_name_t();
#endif /* Old Style C */


typedef char *bp_path_t;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_path_t(XDR *, bp_path_t*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_path_t(XDR *, bp_path_t*);
#else /* Old Style C */
bool_t xdr_bp_path_t();
#endif /* Old Style C */


typedef char *bp_fileid_t;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_fileid_t(XDR *, bp_fileid_t*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_fileid_t(XDR *, bp_fileid_t*);
#else /* Old Style C */
bool_t xdr_bp_fileid_t();
#endif /* Old Style C */


struct ip_addr_t {
	char net;
	char host;
	char lh;
	char impno;
};
typedef struct ip_addr_t ip_addr_t;
#ifdef __cplusplus
extern "C" bool_t xdr_ip_addr_t(XDR *, ip_addr_t*);
#elif defined(__STDC__)
extern  bool_t xdr_ip_addr_t(XDR *, ip_addr_t*);
#else /* Old Style C */
bool_t xdr_ip_addr_t();
#endif /* Old Style C */


struct bp_address {
	int address_type;
	union {
		ip_addr_t ip_addr;
	} bp_address_u;
};
typedef struct bp_address bp_address;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_address(XDR *, bp_address*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_address(XDR *, bp_address*);
#else /* Old Style C */
bool_t xdr_bp_address();
#endif /* Old Style C */


struct bp_whoami_arg {
	bp_address client_address;
};
typedef struct bp_whoami_arg bp_whoami_arg;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_whoami_arg(XDR *, bp_whoami_arg*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_whoami_arg(XDR *, bp_whoami_arg*);
#else /* Old Style C */
bool_t xdr_bp_whoami_arg();
#endif /* Old Style C */


struct bp_whoami_res {
	bp_machine_name_t client_name;
	bp_machine_name_t domain_name;
	bp_address router_address;
};
typedef struct bp_whoami_res bp_whoami_res;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_whoami_res(XDR *, bp_whoami_res*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_whoami_res(XDR *, bp_whoami_res*);
#else /* Old Style C */
bool_t xdr_bp_whoami_res();
#endif /* Old Style C */


struct bp_getfile_arg {
	bp_machine_name_t client_name;
	bp_fileid_t file_id;
};
typedef struct bp_getfile_arg bp_getfile_arg;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_getfile_arg(XDR *, bp_getfile_arg*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_getfile_arg(XDR *, bp_getfile_arg*);
#else /* Old Style C */
bool_t xdr_bp_getfile_arg();
#endif /* Old Style C */


struct bp_getfile_res {
	bp_machine_name_t server_name;
	bp_address server_address;
	bp_path_t server_path;
};
typedef struct bp_getfile_res bp_getfile_res;
#ifdef __cplusplus
extern "C" bool_t xdr_bp_getfile_res(XDR *, bp_getfile_res*);
#elif defined(__STDC__)
extern  bool_t xdr_bp_getfile_res(XDR *, bp_getfile_res*);
#else /* Old Style C */
bool_t xdr_bp_getfile_res();
#endif /* Old Style C */


#define BOOTPARAMPROG ((u_long)100026)
#define BOOTPARAMVERS ((u_long)1)

#ifdef __cplusplus
#define BOOTPARAMPROC_WHOAMI ((u_long)1)
extern "C" bp_whoami_res * bootparamproc_whoami_1(bp_whoami_arg *, CLIENT *);
extern "C" bp_whoami_res * bootparamproc_whoami_1_svc(bp_whoami_arg *, struct svc_req *);
#define BOOTPARAMPROC_GETFILE ((u_long)2)
extern "C" bp_getfile_res * bootparamproc_getfile_1(bp_getfile_arg *, CLIENT *);
extern "C" bp_getfile_res * bootparamproc_getfile_1_svc(bp_getfile_arg *, struct svc_req *);

#elif defined(__STDC__)
#define BOOTPARAMPROC_WHOAMI ((u_long)1)
extern  bp_whoami_res * bootparamproc_whoami_1(bp_whoami_arg *, CLIENT *);
extern  bp_whoami_res * bootparamproc_whoami_1_svc(bp_whoami_arg *, struct svc_req *);
#define BOOTPARAMPROC_GETFILE ((u_long)2)
extern  bp_getfile_res * bootparamproc_getfile_1(bp_getfile_arg *, CLIENT *);
extern  bp_getfile_res * bootparamproc_getfile_1_svc(bp_getfile_arg *, struct svc_req *);

#else /* Old Style C */
#define BOOTPARAMPROC_WHOAMI ((u_long)1)
extern  bp_whoami_res * bootparamproc_whoami_1();
extern  bp_whoami_res * bootparamproc_whoami_1_svc();
#define BOOTPARAMPROC_GETFILE ((u_long)2)
extern  bp_getfile_res * bootparamproc_getfile_1();
extern  bp_getfile_res * bootparamproc_getfile_1_svc();
#endif /* Old Style C */

#endif /* !_BOOTPARAM_PROT_H_RPCGEN */
