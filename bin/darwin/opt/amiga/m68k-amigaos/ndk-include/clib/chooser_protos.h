#ifndef  CLIB_CHOOSER_PROTOS_H
#define  CLIB_CHOOSER_PROTOS_H

/*
**	$VER: chooser_protos.h 1.1 (6.10.1999)
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
Class * __stdargs CHOOSER_GetClass( VOID );
struct Node * __stdargs AllocChooserNodeA( struct TagItem *tags );
struct Node * __stdargs AllocChooserNode( Tag firstTag, ... );
VOID  __stdargs FreeChooserNode( struct Node *node );
VOID  __stdargs SetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetChooserNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetChooserNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetChooserNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_CHOOSER_PROTOS_H */
