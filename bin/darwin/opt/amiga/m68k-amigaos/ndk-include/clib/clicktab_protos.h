#ifndef  CLIB_CLICKTAB_PROTOS_H
#define  CLIB_CLICKTAB_PROTOS_H

/*
**	$VER: clicktab_protos.h 1.1 (6.10.1999)
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
Class * __stdargs CLICKTAB_GetClass( VOID );
struct Node * __stdargs AllocClickTabNodeA( struct TagItem *tags );
struct Node * __stdargs AllocClickTabNode( Tag firstTag, ... );
VOID  __stdargs FreeClickTabNode( struct Node *node );
VOID  __stdargs SetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetClickTabNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetClickTabNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetClickTabNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_CLICKTAB_PROTOS_H */
