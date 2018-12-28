// HistoryGadgetClass.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $

#ifndef HISTORYGADGETCLASS_H
#define HISTORYGADGETCLASS_H


/* Tags for History Gadget class */

#define	SCAHISTORY_TagBase	(TAG_USER + 0x91c00)

#define	SCAHISTORY_Active	(SCAHISTORY_TagBase + 1)  // [ISG] (struct Node *) Node of active label
#define	SCAHISTORY_Labels	(SCAHISTORY_TagBase + 2)  // [I..] (struct List *) List label nodes

#endif /* HISTORYGADGETCLASS_H */

