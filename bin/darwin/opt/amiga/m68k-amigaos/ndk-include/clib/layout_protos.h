#ifndef  CLIB_LAYOUT_PROTOS_H
#define  CLIB_LAYOUT_PROTOS_H

/*
**	$VER: layout_protos.h 1.1 (6.10.1999)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif
Class * __stdargs LAYOUT_GetClass( VOID );
BOOL  __stdargs ActivateLayoutGadget( struct Gadget *gadget, struct Window *window, struct Requester *requester, ULONG object );
VOID  __stdargs FlushLayoutDomainCache( struct Gadget *gadget );
BOOL  __stdargs RethinkLayout( struct Gadget *gadget, struct Window *window, struct Requester *requester, LONG refresh );
VOID  __stdargs LayoutLimits( struct Gadget *gadget, struct LayoutLimits *limits, struct TextFont *font, struct Screen *screen );
Class * __stdargs PAGE_GetClass( VOID );
ULONG  __stdargs SetPageGadgetAttrsA( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester, struct TagItem *tags );
ULONG  __stdargs SetPageGadgetAttrs( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester, ... );
VOID  __stdargs RefreshPageGadget( struct Gadget *gadget, Object *object, struct Window *window, struct Requester *requester );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_LAYOUT_PROTOS_H */
