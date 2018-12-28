/*
        tty.h -- centralized definitions for a variety of terminal interfaces

        created by DPK, Oct. 1986

*/
/* $Id: tty.h 36659 2011-01-18 13:26:51Z neil $ */

/* some useful #defines */
#ifdef EXTERN
# define I__(i) = i
#else
# define I__(i)
# define EXTERN extern
# define EXTERN_DEFINED
#endif

//#include <termios.h>

EXTERN int                tty_fd I__(-1);        /* dup'd tty file descriptor */
EXTERN int                tty_devtty;        /* true if tty_fd is from /dev/tty */
//EXTERN struct termios        tty_state;        /* saved tty state */

extern void        tty_init(int);
extern void        tty_close(void);

/* be sure not to interfere with anyone else's idea about EXTERN */
#ifdef EXTERN_DEFINED
# undef EXTERN_DEFINED
# undef EXTERN
#endif
#undef I__
