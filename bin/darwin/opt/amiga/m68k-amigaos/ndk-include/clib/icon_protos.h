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
VOID  __stdargs FreeFreeList( struct FreeList *freelist );
BOOL  __stdargs AddFreeList( struct FreeList *freelist, CONST APTR mem, ULONG size );
struct DiskObject * __stdargs GetDiskObject( CONST STRPTR name );
BOOL  __stdargs PutDiskObject( CONST STRPTR name, CONST struct DiskObject *diskobj );
VOID  __stdargs FreeDiskObject( struct DiskObject *diskobj );
UBYTE * __stdargs FindToolType( CONST STRPTR *toolTypeArray, CONST STRPTR typeName );
BOOL  __stdargs MatchToolValue( CONST STRPTR typeString, CONST STRPTR value );
STRPTR  __stdargs BumpRevision( STRPTR newname, CONST STRPTR oldname );
/*--- functions in V36 or higher (Release 2.0) ---*/
struct DiskObject * __stdargs GetDefDiskObject( LONG type );
BOOL  __stdargs PutDefDiskObject( CONST struct DiskObject *diskObject );
struct DiskObject * __stdargs GetDiskObjectNew( CONST STRPTR name );
/*--- functions in V37 or higher (Release 2.04) ---*/
BOOL  __stdargs DeleteDiskObject( CONST STRPTR name );
/*--- functions in V44 or higher (Release 3.5) ---*/
struct DiskObject * __stdargs DupDiskObjectA( CONST struct DiskObject *diskObject, CONST struct TagItem *tags );
struct DiskObject * __stdargs DupDiskObject( CONST struct DiskObject *diskObject, ... );
ULONG  __stdargs IconControlA( struct DiskObject *icon, CONST struct TagItem *tags );
ULONG  __stdargs IconControl( struct DiskObject *icon, ... );
VOID  __stdargs DrawIconStateA( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem *tags );
VOID  __stdargs DrawIconState( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ... );
BOOL  __stdargs GetIconRectangleA( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, struct Rectangle *rect, CONST struct TagItem *tags );
BOOL  __stdargs GetIconRectangle( struct RastPort *rp, CONST struct DiskObject *icon, CONST STRPTR label, struct Rectangle *rect, ... );
struct DiskObject * __stdargs NewDiskObject( LONG type );
struct DiskObject * __stdargs GetIconTagList( CONST STRPTR name, CONST struct TagItem *tags );
struct DiskObject * __stdargs GetIconTags( CONST STRPTR name, ... );
BOOL  __stdargs PutIconTagList( CONST STRPTR name, CONST struct DiskObject *icon, CONST struct TagItem *tags );
BOOL  __stdargs PutIconTags( CONST STRPTR name, CONST struct DiskObject *icon, ... );
BOOL  __stdargs LayoutIconA( struct DiskObject *icon, struct Screen *screen, struct TagItem *tags );
BOOL  __stdargs LayoutIcon( struct DiskObject *icon, struct Screen *screen, ... );
VOID  __stdargs ChangeToSelectedIconColor( struct ColorRegister *cr );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_ICON_PROTOS_H */
