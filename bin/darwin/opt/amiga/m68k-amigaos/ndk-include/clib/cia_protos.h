#ifndef  CLIB_CIA_PROTOS_H
#define  CLIB_CIA_PROTOS_H

/*
**	$VER: cia_protos.h 40.1 (17.5.1996)
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
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
struct Interrupt * __stdargs AddICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
VOID  __stdargs RemICRVector( struct Library *resource, LONG iCRBit, struct Interrupt *interrupt );
WORD  __stdargs AbleICR( struct Library *resource, LONG mask );
WORD  __stdargs SetICR( struct Library *resource, LONG mask );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_CIA_PROTOS_H */
