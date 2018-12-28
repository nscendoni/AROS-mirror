#ifndef FILEHANDLES3_H
#define FILEHANDLES3_H

/*
    Copyright © 1995-2011, The AROS Development Team. All rights reserved.
    $Id: filehandles3.h 36808 2011-01-26 11:53:43Z sonic $
*/

#include "os.h"
#include "filehandles.h"

LONG sameLock(struct AfsHandle *, struct AfsHandle *);
ULONG examine(struct AFSBase *, struct AfsHandle *, struct ExAllData *, ULONG, ULONG, IPTR *);
ULONG examineAll(struct AFSBase *, struct AfsHandle *, struct ExAllData *, struct ExAllControl *, ULONG, ULONG);
ULONG examineNext(struct AFSBase *, struct AfsHandle *, struct FileInfoBlock *);

#endif

