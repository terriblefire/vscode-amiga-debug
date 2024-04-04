#ifndef  CLIB_DISK_PROTOS_H
#define  CLIB_DISK_PROTOS_H

/*
**	$VER: disk_protos.h 40.1 (17.5.1996)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  RESOURCES_DISK_H
#include <resources/disk.h>
#endif
BOOL  __stdargs AllocUnit( LONG unitNum );
VOID  __stdargs FreeUnit( LONG unitNum );
struct DiscResourceUnit * __stdargs GetUnit( struct DiscResourceUnit *unitPointer );
VOID  __stdargs GiveUnit( VOID );
LONG  __stdargs GetUnitID( LONG unitNum );
/*------ new for V37 ------*/
LONG  __stdargs ReadUnitID( LONG unitNum );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DISK_PROTOS_H */
