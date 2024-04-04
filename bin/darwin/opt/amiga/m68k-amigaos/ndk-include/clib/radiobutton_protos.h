#ifndef  CLIB_RADIOBUTTON_PROTOS_H
#define  CLIB_RADIOBUTTON_PROTOS_H

/*
**	$VER: radiobutton_protos.h 1.1 (6.10.1999)
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
Class * __stdargs RADIOBUTTON_GetClass( VOID );
struct Node * __stdargs AllocRadioButtonNodeA( ULONG columns, struct TagItem *tags );
struct Node * __stdargs AllocRadioButtonNode( ULONG columns, Tag firstTag, ... );
VOID  __stdargs FreeRadioButtonNode( struct Node *node );
VOID  __stdargs SetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs SetRadioButtonNodeAttrs( struct Node *node, ... );
VOID  __stdargs GetRadioButtonNodeAttrsA( struct Node *node, struct TagItem *tags );
VOID  __stdargs GetRadioButtonNodeAttrs( struct Node *node, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_RADIOBUTTON_PROTOS_H */
