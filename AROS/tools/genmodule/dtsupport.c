/*
    Copyright © 1995-2005, The AROS Development Team. All rights reserved.
    $Id: dtsupport.c 48665 2013-12-31 08:20:42Z mazze $

    Functions to support datatypes. Part of genmodule.
*/
#include <stdio.h>

#include "genmodule.h"

void writeobtainengine(FILE *out, struct config *cfg)
{
    fprintf
    (
        out,
        "\n"
        "/* ObtainEngine function */\n"
        "/* ===================== */\n"
        "\n"
        "AROS_LH0(struct IClass *, ObtainEngine,\n"
        "         LIBBASETYPEPTR, base, 5, %s\n"
        ")\n"
        "{\n"
        "    AROS_LIBFUNC_INIT\n"
        "\n"
        "    return GM_CLASSPTR_FIELD(base);\n"
        "\n"
        "    AROS_LIBFUNC_EXIT\n"
        "}\n",
        cfg->basename
    );
}
