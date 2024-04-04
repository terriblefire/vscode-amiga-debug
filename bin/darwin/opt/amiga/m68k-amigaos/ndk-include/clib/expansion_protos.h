#ifndef  CLIB_EXPANSION_PROTOS_H
#define  CLIB_EXPANSION_PROTOS_H

/*
**	$VER: expansion_protos.h 40.2 (6.6.1998)
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
#ifndef  LIBRARIES_CONFIGVARS_H
#include <libraries/configvars.h>
#endif
#ifndef  DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif
/*--- functions in V33 or higher (Release 1.2) ---*/
VOID  __stdargs AddConfigDev( struct ConfigDev *configDev );
/*--- functions in V36 or higher (Release 2.0) ---*/
BOOL  __stdargs AddBootNode( LONG bootPri, ULONG flags, struct DeviceNode *deviceNode, struct ConfigDev *configDev );
/*--- functions in V33 or higher (Release 1.2) ---*/
VOID  __stdargs AllocBoardMem( ULONG slotSpec );
struct ConfigDev * __stdargs AllocConfigDev( VOID );
APTR  __stdargs AllocExpansionMem( ULONG numSlots, ULONG slotAlign );
VOID  __stdargs ConfigBoard( APTR board, struct ConfigDev *configDev );
VOID  __stdargs ConfigChain( APTR baseAddr );
struct ConfigDev * __stdargs FindConfigDev( CONST struct ConfigDev *oldConfigDev, LONG manufacturer, LONG product );
VOID  __stdargs FreeBoardMem( ULONG startSlot, ULONG slotSpec );
VOID  __stdargs FreeConfigDev( struct ConfigDev *configDev );
VOID  __stdargs FreeExpansionMem( ULONG startSlot, ULONG numSlots );
UBYTE  __stdargs ReadExpansionByte( CONST APTR board, ULONG offset );
VOID  __stdargs ReadExpansionRom( CONST APTR board, struct ConfigDev *configDev );
VOID  __stdargs RemConfigDev( struct ConfigDev *configDev );
VOID  __stdargs WriteExpansionByte( APTR board, ULONG offset, ULONG byte );
VOID  __stdargs ObtainConfigBinding( VOID );
VOID  __stdargs ReleaseConfigBinding( VOID );
VOID  __stdargs SetCurrentBinding( struct CurrentBinding *currentBinding, ULONG bindingSize );
ULONG  __stdargs GetCurrentBinding( CONST struct CurrentBinding *currentBinding, ULONG bindingSize );
struct DeviceNode * __stdargs MakeDosNode( CONST APTR parmPacket );
BOOL  __stdargs AddDosNode( LONG bootPri, ULONG flags, struct DeviceNode *deviceNode );
/*--- functions in V36 or higher (Release 2.0) ---*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_EXPANSION_PROTOS_H */
