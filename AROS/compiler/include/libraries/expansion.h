#ifndef LIBRARIES_EXPANSION_H
#define LIBRARIES_EXPANSION_H

/*
    Copyright � 1995-2001, The AROS Development Team. All rights reserved.
    $Id: expansion.h 39836 2011-07-05 16:20:12Z jmcmullan $

    Desc: expansion.library external definitions
    Lang: english
*/

#define EXPANSIONNAME   "expansion.library"

/* Flag for the AddDosNode()/AddBootNode() calls */

/* Start FileSystem process. */
#define ADNB_STARTPROC      0
#define ADNF_STARTPROC      (1L<< ADNB_STARTPROC)

#endif /* LIBRARIES_EXPANSION_H */
