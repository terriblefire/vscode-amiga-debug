#ifndef  CLIB_WB_PROTOS_H
#define  CLIB_WB_PROTOS_H

/*
**	$VER: wb_protos.h 44.5 (21.6.1999)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*--- functions in V36 or higher (Release 2.0) ---*/
#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

struct AppWindow * __stdargs AddAppWindowA( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, struct TagItem *taglist );
struct AppWindow * __stdargs AddAppWindow( ULONG id, ULONG userdata, struct Window *window, struct MsgPort *msgport, Tag tag1, ... );

BOOL  __stdargs RemoveAppWindow( struct AppWindow *appWindow );

struct AppIcon * __stdargs AddAppIconA( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, struct TagItem *taglist );
struct AppIcon * __stdargs AddAppIcon( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, BPTR lock, struct DiskObject *diskobj, Tag tag1, ... );

BOOL  __stdargs RemoveAppIcon( struct AppIcon *appIcon );

struct AppMenuItem * __stdargs AddAppMenuItemA( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, struct TagItem *taglist );
struct AppMenuItem * __stdargs AddAppMenuItem( ULONG id, ULONG userdata, UBYTE *text, struct MsgPort *msgport, Tag tag1, ... );

BOOL  __stdargs RemoveAppMenuItem( struct AppMenuItem *appMenuItem );

/*--- functions in V39 or higher (Release 3) ---*/


VOID  __stdargs WBInfo( BPTR lock, STRPTR name, struct Screen *screen );

/*--- functions in V44 or higher (Release 3.5) ---*/
BOOL  __stdargs OpenWorkbenchObjectA( STRPTR name, struct TagItem *tags );
BOOL  __stdargs OpenWorkbenchObject( STRPTR name, ... );
BOOL  __stdargs CloseWorkbenchObjectA( STRPTR name, struct TagItem *tags );
BOOL  __stdargs CloseWorkbenchObject( STRPTR name, ... );
BOOL  __stdargs WorkbenchControlA( STRPTR name, struct TagItem *tags );
BOOL  __stdargs WorkbenchControl( STRPTR name, ... );
struct AppWindowDropZone * __stdargs AddAppWindowDropZoneA( struct AppWindow *aw, ULONG id, ULONG userdata, struct TagItem *tags );
struct AppWindowDropZone * __stdargs AddAppWindowDropZone( struct AppWindow *aw, ULONG id, ULONG userdata, ... );
BOOL  __stdargs RemoveAppWindowDropZone( struct AppWindow *aw, struct AppWindowDropZone *dropZone );
BOOL  __stdargs ChangeWorkbenchSelectionA( STRPTR name, struct Hook *hook, struct TagItem *tags );
BOOL  __stdargs ChangeWorkbenchSelection( STRPTR name, struct Hook *hook, ... );
BOOL  __stdargs MakeWorkbenchObjectVisibleA( STRPTR name, struct TagItem *tags );
BOOL  __stdargs MakeWorkbenchObjectVisible( STRPTR name, ... );


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_WB_PROTOS_H */
