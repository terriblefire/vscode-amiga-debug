#ifndef  CLIB_ICON_PROTOS_H
#define  CLIB_ICON_PROTOS_H

/*
**	$VER: icon_protos.h 44.17 (15.7.1999)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif
VOID    __stdargs FreeFreeList( struct FreeList *freelist );
BOOL    __stdargs AddFreeList( struct FreeList *freelist, CONST APTR mem, ULONG size );
struct DiskObject *   __stdargs GetDiskObject( CONST STRPTR name );
BOOL    __stdargs PutDiskObject( CONST STRPTR name, CONST struct DiskObject *diskobj );
VOID    __stdargs FreeDiskObject( struct DiskObject *diskobj );
UBYTE *   __stdargs FindToolType( CONST STRPTR *toolTypeArray, CONST STRPTR typeName );
BOOL    __stdargs MatchToolValue( CONST STRPTR typeString, CONST STRPTR value );
STRPTR    __stdargs BumpRevision( STRPTR newname, CONST STRPTR oldname );
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
