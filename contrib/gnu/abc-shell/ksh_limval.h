/* Wrapper around the values.h/limits.h includes/ifdefs */
/* $Id: ksh_limval.h 36659 2011-01-18 13:26:51Z neil $ */

/* limits.h is included in sh.h */

#ifndef DMAXEXP
# define DMAXEXP        128     /* should be big enough */
#endif

#ifndef BITSPERBYTE
# define BITSPERBYTE   CHAR_BIT
#endif

#ifndef BITS
# define BITS(t)        (CHAR_BIT * sizeof(t))
#endif
