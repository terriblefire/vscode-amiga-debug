#ifndef  CLIB_DATATYPES_PROTOS_H
#define  CLIB_DATATYPES_PROTOS_H

/*
**	$VER: datatypes_protos.h 44.2 (21.4.1999)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif
#ifndef  DATATYPES_DATATYPES_H
#include <datatypes/datatypes.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

struct DataType * __stdargs ObtainDataTypeA( ULONG type, APTR handle, struct TagItem *attrs );
struct DataType * __stdargs ObtainDataType( ULONG type, APTR handle, Tag tag1, ... );
VOID  __stdargs ReleaseDataType( struct DataType *dt );
Object * __stdargs NewDTObjectA( APTR name, struct TagItem *attrs );
Object * __stdargs NewDTObject( APTR name, Tag tag1, ... );
VOID  __stdargs DisposeDTObject( Object *o );
ULONG  __stdargs SetDTAttrsA( Object *o, struct Window *win, struct Requester *req, struct TagItem *attrs );
ULONG  __stdargs SetDTAttrs( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
ULONG  __stdargs GetDTAttrsA( Object *o, struct TagItem *attrs );
ULONG  __stdargs GetDTAttrs( Object *o, Tag tag1, ... );
LONG  __stdargs AddDTObject( struct Window *win, struct Requester *req, Object *o, LONG pos );
VOID  __stdargs RefreshDTObjectA( Object *o, struct Window *win, struct Requester *req, struct TagItem *attrs );
VOID  __stdargs RefreshDTObjects( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
VOID  __stdargs RefreshDTObject( Object *o, struct Window *win, struct Requester *req, Tag tag1, ... );
ULONG  __stdargs DoAsyncLayout( Object *o, struct gpLayout *gpl );
ULONG  __stdargs DoDTMethodA( Object *o, struct Window *win, struct Requester *req, Msg msg );
ULONG  __stdargs DoDTMethod( Object *o, struct Window *win, struct Requester *req, ULONG data, ... );
LONG  __stdargs RemoveDTObject( struct Window *win, Object *o );
ULONG * __stdargs GetDTMethods( Object *object );
struct DTMethods * __stdargs GetDTTriggerMethods( Object *object );
ULONG  __stdargs PrintDTObjectA( Object *o, struct Window *w, struct Requester *r, struct dtPrint *msg );
ULONG  __stdargs PrintDTObject( Object *o, struct Window *w, struct Requester *r, ULONG data, ... );
APTR  __stdargs ObtainDTDrawInfoA( Object *o, struct TagItem *attrs );
APTR  __stdargs ObtainDTDrawInfo( Object *o, Tag tag1, ... );
LONG  __stdargs DrawDTObjectA( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, struct TagItem *attrs );
LONG  __stdargs DrawDTObject( struct RastPort *rp, Object *o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, Tag tag1, ... );
VOID  __stdargs ReleaseDTDrawInfo( Object *o, APTR handle );
STRPTR  __stdargs GetDTString( ULONG id );
/* Just in case, make sure we reserve space for datatypes.library V45 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DATATYPES_PROTOS_H */
