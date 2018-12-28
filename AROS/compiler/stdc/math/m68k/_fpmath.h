/*
    Copyright © 1995-2007, The AROS Development Team. All rights reserved.
    $Id: _fpmath.h 48031 2013-09-08 21:16:04Z verhaegs $

    IEEE floating point layout; m68k version
*/

union IEEEl2bits {
	long double	e;
	struct {
		unsigned int		sign	:1;
		unsigned int		exp	:15;
		unsigned int		zero	:16;
		unsigned int		manh	:32;
		unsigned int		manl	:32;
	} bits;
};

#define	LDBL_NBIT	0x80000000
#define	mask_nbit_l(u)	((u).bits.manh &= ~LDBL_NBIT)

#define	LDBL_MANH_SIZE	32
#define	LDBL_MANL_SIZE	32

#define	LDBL_TO_ARRAY32(u, a) do {			\
	(a)[0] = (uint32_t)(u).bits.manl;		\
	(a)[1] = (uint32_t)(u).bits.manh;		\
} while(0)
