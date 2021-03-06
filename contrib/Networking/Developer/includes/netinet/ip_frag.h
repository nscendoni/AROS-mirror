#ifndef	__IP_FRAG_H__
#define	__IP_FRAG_H__
/*
    Copyright � 2003-2004, The AROS Development Team. All rights reserved.
    $Id: ip_frag.h 30794 2009-03-08 02:19:07Z neil $
*/

/*	$OpenBSD: ip_frag.h,v 1.12 2000/03/13 23:40:18 kjell Exp $	*/

/*
 * Copyright (C) 1993-1998 by Darren Reed.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and due credit is given
 * to the original author and the contributors.
 *
 * @(#)ip_frag.h	1.5 3/24/96
 * $IPFilter: ip_frag.h,v 2.2 1999/08/06 06:26:38 darrenr Exp $
 */

#define	IPFT_SIZE	257

typedef	struct	ipfr	{
	struct	ipfr	*ipfr_next, *ipfr_prev;
	void	*ipfr_data;
	struct	in_addr	ipfr_src;
	struct	in_addr	ipfr_dst;
	u_short	ipfr_id;
	u_char	ipfr_p;
	u_char	ipfr_tos;
	u_short	ipfr_off;
	u_short	ipfr_ttl;
	frentry_t *ipfr_rule;
} ipfr_t;


typedef	struct	ipfrstat {
	u_long	ifs_exists;	/* add & already exists */
	u_long	ifs_nomem;
	u_long	ifs_new;
	u_long	ifs_hits;
	u_long	ifs_expire;
	u_long	ifs_inuse;
	struct	ipfr	**ifs_table;
	struct	ipfr	**ifs_nattab;
} ipfrstat_t;

#define	IPFR_CMPSZ	(4 + 4 + 2 + 1 + 1)

extern	int	fr_ipfrttl;
extern	ipfrstat_t	*ipfr_fragstats __P((void));
extern	int	ipfr_newfrag __P((ip_t *, fr_info_t *, u_int));
extern	int	ipfr_nat_newfrag __P((ip_t *, fr_info_t *, u_int, struct nat *));
extern	nat_t	*ipfr_nat_knownfrag __P((ip_t *, fr_info_t *));
extern	frentry_t *ipfr_knownfrag __P((ip_t *, fr_info_t *));
extern	void	ipfr_forget __P((void *));
extern	void	ipfr_unload __P((void));

#if     (BSD >= 199306) || SOLARIS || defined(__sgi)
# if defined(SOLARIS2) && (SOLARIS2 < 7)
extern	void	ipfr_slowtimer __P((void));
# else
extern	void	ipfr_slowtimer __P((void *));
# endif
#else
extern	int	ipfr_slowtimer __P((void));
#endif

#endif	/* __IP_FIL_H__ */
