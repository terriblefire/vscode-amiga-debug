#ifndef  CLIB_CARDRES_PROTOS_H
#define  CLIB_CARDRES_PROTOS_H

/*
**	$VER: cardres_protos.h 40.1 (17.5.1996)
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
#ifndef  EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef  RESOURCES_CARD_H
#include <resources/card.h>
#endif
struct CardHandle * __stdargs OwnCard( struct CardHandle *handle );
VOID  __stdargs ReleaseCard( struct CardHandle *handle, ULONG flags );
struct CardMemoryMap * __stdargs GetCardMap( VOID );
BOOL  __stdargs BeginCardAccess( struct CardHandle *handle );
BOOL  __stdargs EndCardAccess( struct CardHandle *handle );
UBYTE  __stdargs ReadCardStatus( VOID );
BOOL  __stdargs CardResetRemove( struct CardHandle *handle, ULONG flag );
UBYTE  __stdargs CardMiscControl( struct CardHandle *handle, ULONG control_bits );
ULONG  __stdargs CardAccessSpeed( struct CardHandle *handle, ULONG nanoseconds );
LONG  __stdargs CardProgramVoltage( struct CardHandle *handle, ULONG voltage );
BOOL  __stdargs CardResetCard( struct CardHandle *handle );
BOOL  __stdargs CopyTuple( CONST struct CardHandle *handle, UBYTE *buffer, ULONG tuplecode, ULONG size );
ULONG  __stdargs DeviceTuple( CONST UBYTE *tuple_data, struct DeviceTData *storage );
struct Resident * __stdargs IfAmigaXIP( CONST struct CardHandle *handle );
BOOL  __stdargs CardForceChange( VOID );
ULONG  __stdargs CardChangeCount( VOID );
ULONG  __stdargs CardInterface( VOID );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_CARDRES_PROTOS_H */
