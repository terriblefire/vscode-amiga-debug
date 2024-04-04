#ifndef  CLIB_AMIGAGUIDE_PROTOS_H
#define  CLIB_AMIGAGUIDE_PROTOS_H

/*
**	$VER: amigaguide_protos.h 39.4 (17.6.1993)
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
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
/*--- functions in V40 or higher (Release 3.1) ---*/

/* Public entries */

LONG  __stdargs LockAmigaGuideBase( APTR handle );
VOID  __stdargs UnlockAmigaGuideBase( LONG key );
APTR  __stdargs OpenAmigaGuideA( struct NewAmigaGuide *nag, struct TagItem *tags );
APTR  __stdargs OpenAmigaGuide( struct NewAmigaGuide *nag, Tag tag1, ... );
APTR  __stdargs OpenAmigaGuideAsyncA( struct NewAmigaGuide *nag, struct TagItem *attrs );
APTR  __stdargs OpenAmigaGuideAsync( struct NewAmigaGuide *nag, Tag tag1, ... );
VOID  __stdargs CloseAmigaGuide( APTR cl );
ULONG  __stdargs AmigaGuideSignal( APTR cl );
struct AmigaGuideMsg * __stdargs GetAmigaGuideMsg( APTR cl );
VOID  __stdargs ReplyAmigaGuideMsg( struct AmigaGuideMsg *amsg );
LONG  __stdargs SetAmigaGuideContextA( APTR cl, ULONG id, struct TagItem *attrs );
LONG  __stdargs SetAmigaGuideContext( APTR cl, ULONG id, Tag tag1, ... );
LONG  __stdargs SendAmigaGuideContextA( APTR cl, struct TagItem *attrs );
LONG  __stdargs SendAmigaGuideContext( APTR cl, Tag tag1, ... );
LONG  __stdargs SendAmigaGuideCmdA( APTR cl, STRPTR cmd, struct TagItem *attrs );
LONG  __stdargs SendAmigaGuideCmd( APTR cl, STRPTR cmd, Tag tag1, ... );
LONG  __stdargs SetAmigaGuideAttrsA( APTR cl, struct TagItem *attrs );
LONG  __stdargs SetAmigaGuideAttrs( APTR cl, Tag tag1, ... );
LONG  __stdargs GetAmigaGuideAttr( Tag tag, APTR cl, ULONG *storage );
LONG  __stdargs LoadXRef( BPTR lock, STRPTR name );
VOID  __stdargs ExpungeXRef( VOID );
APTR  __stdargs AddAmigaGuideHostA( struct Hook *h, STRPTR name, struct TagItem *attrs );
APTR  __stdargs AddAmigaGuideHost( struct Hook *h, STRPTR name, Tag tag1, ... );
LONG  __stdargs RemoveAmigaGuideHostA( APTR hh, struct TagItem *attrs );
LONG  __stdargs RemoveAmigaGuideHost( APTR hh, Tag tag1, ... );
STRPTR  __stdargs GetAmigaGuideString( LONG id );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_AMIGAGUIDE_PROTOS_H */
