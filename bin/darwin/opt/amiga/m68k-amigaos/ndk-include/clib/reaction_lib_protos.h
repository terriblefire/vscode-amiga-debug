#ifndef CLIB_REACTION_LIB_PROTOS_H
#define CLIB_REACTION_LIB_PROTOS_H
/*
**	$VER: reaction_lib_protos.h 45.1 (17.12.2001)
**	Includes Release 45.1
**
**	C prototypes. For use with 32 bit integers only.
**
**	(C) Copyright 1987-2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct List * __stdargs ChooserLabelsA( STRPTR * );
struct List * __stdargs ChooserLabels( STRPTR, ... );
void  __stdargs FreeChooserLabels( struct List * );
struct List * __stdargs RadioButtonsA( STRPTR * );
struct List * __stdargs RadioButtons( STRPTR, ... );
void  __stdargs FreeRadioButtons( struct List * );
struct Window * __stdargs OpenLayoutWindowTagList( struct Gadget *, struct Screen *, struct TagItem * );
struct Window * __stdargs OpenLayoutWindowTags( struct Gadget *, struct Screen *, Tag, ... );
UWORD  __stdargs GetCode( struct IntuiMessage * );
struct ClassLibrary * __stdargs OpenClass(STRPTR, ULONG);
STRPTR  __stdargs OpenLibs(APTR);
void  __stdargs CloseLibs(APTR);
ULONG  __stdargs LibDoGadgetMethodA( struct Gadget *, struct Window *, struct Requester *, Msg );
ULONG  __stdargs LibDoGadgetMethod( struct Gadget *, struct Window *, struct Requester *, Tag, ... );
ULONG  __stdargs GetAttrsA( Object *o, struct TagItem *t );
ULONG  __stdargs GetAttrs( Object *o, Tag t, ... );
struct List * __stdargs BrowserNodesA( STRPTR * );
struct List * __stdargs BrowserNodes( STRPTR, ... );
void  __stdargs FreeBrowserNodes( struct List * );
struct List * __stdargs ClickTabsA( STRPTR * );
struct List * __stdargs ClickTabs( STRPTR, ... );
void  __stdargs FreeClickTabs( struct List * );
struct Node * __stdargs LBAddNodeA( struct Gadget *, struct Window *, struct Requester *, struct Node *, struct TagItem * );
ULONG  __stdargs LBEditNodeA( struct Gadget *, struct Window *, struct Requester *, struct Node *, struct TagItem * );
struct Node * __stdargs LBAddNode( struct Gadget *lb, struct Window *w, struct Requester *r, struct Node *n, ULONG tag, ... );
ULONG  __stdargs LBEditNode( struct Gadget *lb, struct Window *w, struct Requester *r, struct Node *n, ULONG tag, ... );
ULONG  __stdargs LBRemNode( struct Gadget *, struct Window *, struct Requester *, struct Node * );

#ifdef __cplusplus
}
#endif

#endif /* CLIB_REACTION_LIB_PROTOS_H */
