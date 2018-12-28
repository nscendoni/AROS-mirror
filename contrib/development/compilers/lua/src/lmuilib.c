/******************************************************************************
* $Id: lmuilib.c 51891 2016-03-13 01:05:47Z NicJA $
*
* Copyright (C) 2006 Matthias Rustler.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/


#include <stdio.h>
#include <string.h>

#define MUIMASTER_YES_INLINE_STDARG

//#define DEBUG 1
#include <aros/debug.h>

#include <libraries/mui.h>
#include <libraries/asl.h>
#include <proto/muimaster.h>
#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/alib.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "lmuilib.h"

#define BUFSIZE (500)

//==============================================================================

#define STRARRAY "strarray"

typedef STRPTR * Strarray;

//------------------------------------------------------------------------------

static Strarray toStrarray (lua_State *L, int index)
{
  Strarray *ps = (Strarray *)lua_touserdata(L, index);
  if (ps == NULL) luaL_error(L, "strarray/toStrarray: wrong type for argument %d", index);
  return *ps;
}

//------------------------------------------------------------------------------

static Strarray checkStrarray (lua_State *L, int index)
{
  Strarray *ps, sa;
  luaL_checktype(L, index, LUA_TUSERDATA);
  ps = (Strarray*)luaL_checkudata(L, index, STRARRAY);
  if (ps == NULL) luaL_error(L, "strarray/checkStrarray: wrong type for argument %d", index);
  sa = *ps;
  if (!sa)
    luaL_error(L, "checkStrarray: Strarray is null");
  return sa;
}

//------------------------------------------------------------------------------

static Strarray *pushStrarray (lua_State *L, Strarray sa)
{
  Strarray *ps = (Strarray *)lua_newuserdata(L, sizeof(Strarray));
  *ps = sa;
  luaL_getmetatable(L, STRARRAY);
  lua_setmetatable(L, -2);
  return ps;
}

//------------------------------------------------------------------------------

static int Strarray_new (lua_State *L)
{
  int i;
  int cnt = lua_gettop(L);
  if (cnt < 1)
    luaL_error(L, "Strarray_new: need at least 1 string");
  // One additional element for the closing NULL
  STRPTR *str = AllocVec(sizeof(STRPTR) * (cnt + 1), MEMF_ANY | MEMF_CLEAR);
  if (str == NULL)
    luaL_error(L, "Strarray_new: can't allocate RAM");
  for (i=0; i < cnt; i++)
  {
    str[i] = StrDup(luaL_checkstring(L, i + 1));
    if (str[i] == NULL)
      luaL_error(L, "Strarray_new: can't allocate RAM");
  }
  pushStrarray(L, str);
  return 1;
}

//------------------------------------------------------------------------------

static int Strarray_dispose (lua_State *L)
{
  STRPTR * str = toStrarray(L, 1);
  int i = 0;
  if (str)
  {
    while (str[i])
    {
      FreeVec(str[i]);
      i++;
    }
    FreeVec(str);
    *((Strarray*)lua_touserdata(L, 1)) = NULL;
  }
  else
  {
      D(bug("Strarray is already NULL\n"));
  }
  return 0;
}

//------------------------------------------------------------------------------

static int Strarray_get (lua_State *L)
{
  STRPTR * str = checkStrarray(L, 1);
  int index = luaL_checkinteger(L, 2) - 1;
  if (index < 0)
      luaL_error(L, "Strarray_get: index must be greater than 0");

  int i = 0;
  while (str[i])
  {
    if (index == i)
    {
      lua_pushstring(L, str[i]);
      return 1;
    }
    i++;
  }
  
  lua_pushnil(L);
  return 1;  // result is 'nil' when index is too large
}

//------------------------------------------------------------------------------

static const luaL_Reg Strarray_methods[] = {
  {"new", Strarray_new},
  {"dispose", Strarray_dispose},
  {"get", Strarray_get},
  {0,0}
};

//------------------------------------------------------------------------------

static const luaL_Reg Strarray_meta[] = {
  //{"__gc", Strarray_gc},
  {0, 0}
};

//==============================================================================

#define MUI "mui"

typedef APTR Muiobj;

//------------------------------------------------------------------------------

static Muiobj toMui (lua_State *L, int index)
{
  Muiobj *pm = (Muiobj *)lua_touserdata(L, index);
  if (pm == NULL) luaL_error(L, "mui/toMui: wrong type for argument %d", index);
  return *pm;
}

//------------------------------------------------------------------------------

static Muiobj checkMui (lua_State *L, int index)
{
  Muiobj *pm, mo;
  luaL_checktype(L, index, LUA_TUSERDATA);
  pm = (Muiobj*)luaL_checkudata(L, index, MUI);
  if (pm == NULL) luaL_error(L, "mui/checkMui: wrong type for argument %d", index);
  mo = *pm;
  if (!mo)
    luaL_error(L, "checkMui: Muiobject is null");
  return mo;
}

//------------------------------------------------------------------------------

static Muiobj *pushMui (lua_State *L, Muiobj mo)
{
  Muiobj *pm = (Muiobj *)lua_newuserdata(L, sizeof(Muiobj));
  *pm = mo;
  luaL_getmetatable(L, MUI);
  lua_setmetatable(L, -2);
  return pm;
}

//------------------------------------------------------------------------------

static struct TagItem *createTagArray(lua_State *L, int start)
{
  int i;
  if (start < 1)
    luaL_error(L, "createTagArray: start must be at least '1'");
  int pairs = (lua_gettop(L) - start + 1) / 2;
  //D(bug("top %d pairs %d\n", lua_gettop(L), pairs));
  if (pairs < 1)
    return 0;
  int param = start;
  struct TagItem *ti = AllocVec(sizeof(struct TagItem) * (pairs + 1), MEMF_ANY | MEMF_CLEAR);
  if (ti == NULL)
    luaL_error(L, "createTagArray: can't allocate RAM for TagItem");
  for (i=0; i < pairs; i++)
  {
    ti[i].ti_Tag = luaL_checkint(L, param);
    param++;
    //D(bug("type %d\n", lua_type(L, param)));
    switch (lua_type(L, param))
    {
      case LUA_TNIL:
        luaL_error(L, "createTagArray: parameter must not be 'nil'");
        break;
      case LUA_TBOOLEAN:
        ti[i].ti_Data = lua_toboolean(L, param) ? TRUE : FALSE;
        break;
      case LUA_TUSERDATA:
        ti[i].ti_Data = *(IPTR *)lua_touserdata(L, param);
        break;
      case LUA_TLIGHTUSERDATA:
        ti[i].ti_Data = (IPTR)lua_touserdata(L, param);
        break;
      case LUA_TNUMBER:
        ti[i].ti_Data = lua_tointeger(L, param);
        break;
      case LUA_TSTRING:
        ti[i].ti_Data = (IPTR)lua_tostring(L, param);
        break;
      default:
        luaL_error(L, "createTagArray: wrong type");
        break;
    }
    param++;
    //D(bug("Tag %x Data %x\n", ti[i].ti_Tag, ti[i].ti_Data));
  }
  ti[pairs].ti_Tag = TAG_DONE;
  return ti;
}

//------------------------------------------------------------------------------

static int Muiobj_new (lua_State *L)
{
  struct TagItem * ti = createTagArray(L, 2);
  CONST_STRPTR class = luaL_checkstring(L, 1);
  APTR obj = MUI_NewObjectA(class, ti);
  FreeVec(ti);
  pushMui(L, obj);
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_make (lua_State *L)
{
  int i;
  int class = luaL_checkinteger(L, 1);
  if (class == 0)
    luaL_error(L, "Muiobj_make: class must not be 0");

  int args = lua_gettop(L) - 1;
  if (args < 1)
    luaL_error(L, "Muiobj_make: need at least a method identifier");
  IPTR *ip = AllocVec(sizeof(IPTR) * args, MEMF_ANY | MEMF_CLEAR);
  if (ip == NULL)
    luaL_error(L, "Muiobj_make: can't allocate RAM");
  for (i=0; i< args; i++)
  {
    switch (lua_type(L, i + 2))
    {
      case LUA_TNIL:
        luaL_error(L, "Muiobj_make: argument must not be 'nil'");
        break;
      case LUA_TBOOLEAN:
        ip[i] = lua_toboolean(L, i + 2) ? TRUE : FALSE;
        break;
      case LUA_TUSERDATA:
        ip[i] = *(IPTR *)lua_touserdata(L, i + 2);
        break;
      case LUA_TLIGHTUSERDATA:
        ip[i] = (IPTR)lua_touserdata(L, i + 2);
        break;
      case LUA_TNUMBER:
        ip[i] = lua_tointeger(L, i + 2);
        break;
      case LUA_TSTRING:
        ip[i] = (IPTR)lua_tostring(L, i + 2);
        break;
      default:
        luaL_error(L, "Muiobj_make: wrong type");
        break;
    }
  }

  APTR obj = MUI_MakeObjectA(class, ip);
  FreeVec(ip);
  pushMui(L, obj);
  return 1;
}

//------------------------------------------------------------------------------

static IPTR Muiobj_domethod_intern (lua_State *L)
{
  IPTR result = 0;
  int i;
  Muiobj mo = checkMui(L, 1);
  int args = lua_gettop(L) - 1;
  if (args < 1)
    luaL_error(L, "Muiobj_domethod: need at least one method identifier");
  IPTR *ip = AllocVec(sizeof(IPTR) * args, MEMF_ANY | MEMF_CLEAR);
  if (ip == NULL)
    luaL_error(L, "Muiobj_domethod: can't allocate RAM");
  for (i=0; i< args; i++)
  {
    switch (lua_type(L, i + 2))
    {
      case LUA_TNIL:
        luaL_error(L, "Muiobj_domethod: argument must not be 'nil'");
        break;
      case LUA_TBOOLEAN:
        ip[i] = lua_toboolean(L, i + 2) ? TRUE : FALSE;
        break;
      case LUA_TUSERDATA:
        ip[i] = *(IPTR *)lua_touserdata(L, i + 2);
        break;
      case LUA_TLIGHTUSERDATA:
        ip[i] = (IPTR)lua_touserdata(L, i + 2);
        break;
      case LUA_TNUMBER:
        ip[i] = lua_tointeger(L, i + 2);
        break;
      case LUA_TSTRING:
        ip[i] = (IPTR)lua_tostring(L, i + 2);
        break;
      default:
        luaL_error(L, "Muiobj_domethod: wrong type");
        break;
    }
  }

  result = DoMethodA(mo, (Msg)ip);
  FreeVec(ip);
  return result;
}

//------------------------------------------------------------------------------

static int Muiobj_domethod_integer(lua_State *L)
{
  lua_pushinteger(L, Muiobj_domethod_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_domethod_string(lua_State *L)
{
  lua_pushstring(L, (char *)Muiobj_domethod_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_domethod_ptr(lua_State *L)
{
  lua_pushlightuserdata(L, (void *)Muiobj_domethod_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_domethod_bool(lua_State *L)
{
  lua_pushboolean(L, Muiobj_domethod_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_set (lua_State *L)
{
  Muiobj mo = checkMui(L, 1);
  struct TagItem * ti = createTagArray(L, 2);
  SetAttrsA(mo, ti);
  FreeVec(ti);
  return 0;
}

//------------------------------------------------------------------------------

static IPTR Muiobj_get_intern(lua_State *L)
{
  Muiobj mo = checkMui(L, 1);
  ULONG attrID = luaL_checkinteger(L, 2);
  IPTR storage = 0;
  GetAttr(attrID, mo, &storage);
  return storage;
}

//------------------------------------------------------------------------------

static int Muiobj_get_integer(lua_State *L)
{
  lua_pushinteger(L, Muiobj_get_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_get_string(lua_State *L)
{
  lua_pushstring(L, (char *)Muiobj_get_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_get_ptr(lua_State *L)
{
  lua_pushlightuserdata(L, (void *)Muiobj_get_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_get_bool(lua_State *L)
{
  lua_pushboolean(L, Muiobj_get_intern(L));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_request(lua_State *L)
{
  if (lua_gettop(L) != 6)
    luaL_error(L, "Muiobj_request: number of parameters must be 6");
  APTR app = NULL;
  if (lua_isuserdata(L, 1))
      app = toMui(L, 1);
  APTR win = NULL;
  if (lua_isuserdata(L, 2))
    win = *(APTR *)lua_touserdata(L, 2);
  LONGBITS flags = lua_tointeger(L, 3);
  const char *title = lua_tostring(L, 4);
  const char *gadgets = luaL_checkstring(L, 5);
  const char *format = luaL_checkstring(L, 6);
  lua_pushinteger(L, MUI_RequestA(app, win, flags, title, gadgets, format, NULL ));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_dispose (lua_State *L)
{
  Muiobj mo = toMui(L, 1);
  MUI_DisposeObject(mo);
  *((Muiobj *)lua_touserdata(L, 1)) = NULL;
  return 0;
}

//------------------------------------------------------------------------------

static int Muiobj_input (lua_State *L)
{
  ULONG sigs;
  Muiobj mo = checkMui(L, 1); // must be application object
  LONG id = DoMethod(mo, MUIM_Application_Input, &sigs);
  lua_pushinteger(L, id);
  lua_pushinteger(L, sigs);
  return 2;
}

//------------------------------------------------------------------------------

static int Muiobj_wait (lua_State *L)
{
  ULONG sigs = luaL_checkinteger(L, 1);
  if (sigs)
    Wait(sigs | SIGBREAKF_CTRL_C);
  return 0;
}

//------------------------------------------------------------------------------

static int Muiobj_make_id(lua_State *L)
{
  const char *str = luaL_checkstring(L, 1);
  if (strlen(str) != 4)
    luaL_error(L, "Muiobj_make_id: string length must be 4");
  lua_pushinteger(L, (LONG)MAKE_ID(str[0], str[1], str[2], str[3]));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_check(lua_State *L)
{
  Muiobj mo = checkMui(L, 1);
  lua_pushboolean(L, (int)(mo != NULL));
  return 1;
}

//------------------------------------------------------------------------------

static int Muiobj_filerequest(lua_State *L)
{
    struct TagItem * ti = createTagArray(L, 1);
    STRPTR path = NULL;
    struct WBArg *frargs;
    int x;
    int rescnt = 0;

    struct FileRequester *fr = (struct FileRequester *)MUI_AllocAslRequest(ASL_FileRequest, ti);
    if (fr)
    {
	if (MUI_AslRequest(fr, NULL))
	{
	    path = AllocVec( BUFSIZE, MEMF_ANY);
	    if (fr->rf_NumArgs > 0) // multi selection
	    {
		frargs = fr->rf_ArgList;
		for ( x=0;  x < fr->rf_NumArgs;  x++ )
		{
		    strcpy(path, fr->rf_Dir);
		    if (AddPart(path, frargs[x].wa_Name, BUFSIZE))
		    {
			lua_pushstring(L, path);
			rescnt++;
		    }
		    else
		    {
			FreeVec(path);
			MUI_FreeAslRequest(fr);
			luaL_error(L, "Muiobj_filerequest: AddPath failed");
		    }
		}
	    }
	    else
	    {
		strcpy(path, fr->rf_Dir);
		if (AddPart(path, fr->rf_File, BUFSIZE))
		{
		    lua_pushstring(L, path);
		    rescnt = 1;
		}
		else
		{
		    FreeVec(path);
		    MUI_FreeAslRequest(fr);
		    luaL_error(L, "Muiobj_filerequest: AddPath failed");
		}
	    }
	}
	else
	{
	    lua_pushnil(L);  //requester cancelled
	    rescnt = 1;
	}
	MUI_FreeAslRequest(fr);
    }
    FreeVec(path);
    return rescnt;
}


//------------------------------------------------------------------------------

static const luaL_Reg Mui_methods[] = {
  {"new",         Muiobj_new},
  {"make",        Muiobj_make},
  {"doint",       Muiobj_domethod_integer},
  {"dostr",       Muiobj_domethod_string},
  {"doptr",       Muiobj_domethod_ptr},
  {"dobool",      Muiobj_domethod_bool},
  {"set",         Muiobj_set},
  {"getint",      Muiobj_get_integer},
  {"getstr",      Muiobj_get_string},
  {"getptr",      Muiobj_get_ptr},
  {"getbool",     Muiobj_get_bool},
  {"dispose",     Muiobj_dispose},
  {"input",       Muiobj_input},
  {"wait",        Muiobj_wait},
  {"request",     Muiobj_request},
  {"makeid",      Muiobj_make_id},
  {"check",       Muiobj_check},
  {"filerequest", Muiobj_filerequest},
  {0,0}
};

//------------------------------------------------------------------------------

static int Mui_gc (lua_State *L)
{
  D(bug("Mui object garbage collector\n"));
  return 0;
}

//------------------------------------------------------------------------------

static const luaL_Reg Mui_meta[] = {
  {"__gc",       Mui_gc},
  {0, 0}
};

//------------------------------------------------------------------------------

int luaopen_muilib (lua_State *L)
{
  luaL_openlib(L, MUI, Mui_methods, 0);
  luaL_newmetatable(L, MUI);
  luaL_openlib(L, 0, Mui_meta, 0);
  lua_pushliteral(L, "__index");
  lua_pushvalue(L, -3);
  lua_rawset(L, -3);
  lua_pushliteral(L, "__metatable");
  lua_pushvalue(L, -3);
  lua_rawset(L, -3);
  lua_pop(L, 1);

  luaL_openlib(L, STRARRAY, Strarray_methods, 0);
  luaL_newmetatable(L, STRARRAY);
  luaL_openlib(L, 0, Strarray_meta, 0);
  lua_pushliteral(L, "__index");
  lua_pushvalue(L, -3);
  lua_rawset(L, -3);
  lua_pushliteral(L, "__metatable");
  lua_pushvalue(L, -3);
  lua_rawset(L, -3);
  lua_pop(L, 1);

  return 1;
}

