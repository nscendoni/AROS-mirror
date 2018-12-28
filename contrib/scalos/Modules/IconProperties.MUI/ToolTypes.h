// ToolTypes.h
// $Date: 2013-12-01 23:08:26 +0100 (Sun, 01 Dec 2013) $
// $Revision: 48481 $


#ifndef TOOLTYPES_H
#define	TOOLTYPES_H

//----------------------------------------------------------------------------

LONG SetToolType(Object *iconObj, CONST_STRPTR ToolTypeName, CONST_STRPTR ToolTypeValue);
LONG RemoveToolType(Object *iconObj, CONST_STRPTR ToolTypeName);
STRPTR *CloneToolTypeArray(CONST_STRPTR *ToolTypeArray, ULONG AdditionalEntries);
LONG CmpToolTypeArrays(CONST_STRPTR *ToolTypeArray1, CONST_STRPTR *ToolTypeArray2);

//----------------------------------------------------------------------------

#endif /* TOOLTYPES_H */
