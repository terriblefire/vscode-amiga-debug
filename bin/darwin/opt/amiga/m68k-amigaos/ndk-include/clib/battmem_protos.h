#ifndef  CLIB_BATTMEM_PROTOS_H
#define  CLIB_BATTMEM_PROTOS_H

/*
**	$VER: battmem_protos.h 40.1 (17.5.1996)
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
VOID  __stdargs ObtainBattSemaphore( VOID );
VOID  __stdargs ReleaseBattSemaphore( VOID );
ULONG  __stdargs ReadBattMem( APTR buffer, ULONG offset, ULONG length );
ULONG  __stdargs WriteBattMem( CONST APTR buffer, ULONG offset, ULONG length );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_BATTMEM_PROTOS_H */
