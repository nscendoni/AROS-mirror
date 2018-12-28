#ifndef LINEREAD_H
#define LINEREAD_H
/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: lineread.h 30794 2009-03-08 02:19:07Z neil $

*/

/* #include <sys/cdefs.h> */

#ifndef RL_BUFSIZE
#define RL_BUFSIZE 1024
#endif

struct rl_private {
/*  struct Library * rlp_SocketBase; */
  int        rlp_Startp;
  int        rlp_Bufpointer;
  int        rlp_Howlong;
  int	     rlp_Buffersize;
#define bool int
  bool	     rlp_Line_completed;
  bool	     rlp_Selected;
#undef bool  
  char       rlp_Saved;
  char       rlp_Buffer[RL_BUFSIZE + 1];
};

struct LineRead {
  char *							rl_Line;
  enum {RL_LFNOTREQ = 0, RL_LFREQLF = 1, RL_LFREQNUL = 2}	rl_Lftype;
  int								rl_Fd;
  struct rl_private						rl_Private;
};

/*__BEGIN_DECLS
  
int	lineRead __P((struct LineRead * rl));
void	initLineRead __P((struct LineRead * rl, int fd,
			  int lftype, int buffersize));

__END_DECLS */

int	lineRead (struct LineRead * rl);
void	initLineRead (struct LineRead * rl, int fd,
			  int lftype, int buffersize);

#endif /* LINEREAD_H */
