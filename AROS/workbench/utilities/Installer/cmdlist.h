/*
    Copyright � 1995-2003, The AROS Development Team. All rights reserved.
    $Id: cmdlist.h 48906 2014-04-04 20:07:36Z deadwood $
*/
#ifndef _CMDLIST_H
#define _CMDLIST_H

#ifndef _EXECUTE_H
#   include "execute.h"
#endif

struct CommandList internal_commands[] =
{
    {"abort",           _ABORT          },
    {"all",             _ALL            },
    {"append",          _APPEND         },
    {"askbool",         _ASKBOOL        },
    {"askchoice",       _ASKCHOICE      },
    {"askdir",          _ASKDIR         },
    {"askdisk",         _ASKDISK        },
    {"askfile",         _ASKFILE        },
    {"asknumber",       _ASKNUMBER      },
    {"askoptions",      _ASKOPTIONS     },
    {"askstring",       _ASKSTRING      },
    {"assigns",         _ASSIGNS        },
    {"cat",             _CAT            },
    {"choices",         _CHOICES        },
    {"command",         _COMMAND        },
    {"complete",        _COMPLETE       },
    {"confirm",         _CONFIRM        },
    {"copyfiles",       _COPYFILES      },
    {"copylib",         _COPYLIB        },
    {"database",        _DATABASE       },
    {"debug",           _DEBUG          },
    {"default",         _DEFAULT        },
    {"delete",          _DELETE         },
    {"delopts",         _DELOPTS        },
    {"dest",            _DEST           },
    {"disk",            _DISK           },
    {"earlier",         _EARLIER        },
    {"execute",         _EXECUTE        },
    {"exists",          _EXISTS         },
    {"exit",            _EXIT           },
    {"expandpath",      _EXPANDPATH     },
    {"fileonly",        _FILEONLY       },
    {"files",           _FILES          },
    {"fonts",           _FONTS          },
    {"foreach",         _FOREACH        },
    {"getassign",       _GETASSIGN      },
    {"getdevice",       _GETDEVICE      },
    {"getdiskspace",    _GETDISKSPACE   },
    {"getenv",          _GETENV         },
    {"getsize",         _GETSIZE        },
    {"getsum",          _GETSUM         },
    {"getversion",      _GETVERSION     },
    {"help",            _HELP           },
    {"iconinfo",        _ICONINFO       },
    {"if",              _IF             },
    {"include",         _INCLUDE        },
    {"infos",           _INFOS          },
    {"makeassign",      _MAKEASSIGN     },
    {"makedir",         _MAKEDIR        },
    {"message",         _MESSAGE        },
    {"newname",         _NEWNAME        },
    {"newpath",         _NEWPATH        },
    {"nogauge",         _NOGAUGE        },
    {"noposition",      _NOPOSITION     },
    {"onerror",         _ONERROR        },
    {"optional",        _OPTIONAL       },
    {"pathonly",        _PATHONLY       },
    {"patmatch",        _PATMATCH       },
    {"pattern",         _PATTERN        },
    {"procedure",       _PROCEDURE      },
    {"prompt",          _PROMPT         },
    {"protect",         _PROTECT        },
    {"quiet",           _QUIET          },
    {"range",           _RANGE          },
    {"rename",          _RENAME         },
    {"resident",        _RESIDENT       },
    {"rexx",            _REXX           },
    {"run",             _RUN            },
    {"safe",            _SAFE           },
    {"select",          _SELECT         },
    {"set",             _SET            },
    {"setdefaulttool",  _SETDEFAULTTOOL },
    {"setposition",     _SETPOSITION    },
    {"setstack",        _SETSTACK       },
    {"settooltype",     _SETTOOLTYPE    },
    {"shiftleft",       _SHIFTLEFT      },
    {"shiftrght",       _SHIFTRGHT      },
    {"source",          _SOURCE         },
    {"startup",         _STARTUP        },
    {"strlen",          _STRLEN         },
    {"substr",          _SUBSTR         },
    {"swapcolors",      _SWAPCOLORS     },
    {"symbolset",       _SYMBOLSET      },
    {"symbolval",       _SYMBOLVAL      },
    {"tackon",          _TACKON         },
    {"textfile",        _TEXTFILE       },
    {"tooltype",        _TOOLTYPE       },
    {"transcript",      _TRANSCRIPT     },
    {"trap",            _TRAP           },
    {"until",           _UNTIL          },
    {"user",            _USER           },
    {"welcome",         _WELCOME        },
    {"while",           _WHILE          },
    {"working",         _WORKING        },

    {"*",               _TIMES          },
    {"+",               _PLUS           },
    {"-",               _MINUS          },
    {"/",               _DIV            },
    {"<",               _LESS           },
    {"<=",              _LESSEQ         },
    {"<>",              _DIFF           },
    {"=",               _EQUAL          },
    {">",               _MORE           },
    {">=",              _MOREEQ         },
    {"and",             _AND            },
    {"bitand",          _BITAND         },
    {"bitnot",          _BITNOT         },
    {"bitor",           _BITOR          },
    {"bitxor",          _BITXOR         },
    {"in",              _IN             },
    {"not",             _NOT            },
    {"or",              _OR             },
    {"xor",             _XOR            },
    {"",                0               }
};


#endif /* _EXECUTE_H */

