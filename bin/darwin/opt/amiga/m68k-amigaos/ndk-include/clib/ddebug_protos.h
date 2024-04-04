#ifndef  CLIB_DDEBUG_PROTOS_H
#define  CLIB_DDEBUG_PROTOS_H

/*
**	$VER: ddebug_protos.h 40.1 (17.5.1996)
**	Includes Release 45.1
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
VOID  __stdargs DDoFmt( CONST_STRPTR formatString, CONST APTR dataStream, CONST APTR putChProc, APTR putChData );
LONG  __stdargs DGetChar( VOID );
LONG  __stdargs dgetchar( VOID );
LONG  __stdargs dgetch( VOID );
LONG  __stdargs dgetc( VOID );
LONG  __stdargs DGetNum( VOID );
LONG  __stdargs dgetnum( VOID );
LONG  __stdargs DMayGetChar( VOID );
LONG  __stdargs DMayGetCh( VOID );
VOID  __stdargs DPutChar( LONG ch );
VOID  __stdargs dputchar( LONG ch );
VOID  __stdargs dputch( LONG ch );
VOID  __stdargs dputc( LONG ch );
VOID  __stdargs DPutCh( LONG ch );
VOID  __stdargs DPutFmt( CONST_STRPTR formatString, CONST APTR values );
VOID  __stdargs DVPrintF( CONST_STRPTR formatString, CONST APTR values );
VOID  __stdargs DPrintF( CONST_STRPTR formatString, ... );
VOID  __stdargs dprintf( CONST_STRPTR formatString, ... );
VOID  __stdargs DPutStr( CONST_STRPTR string );
VOID  __stdargs dputstr( CONST_STRPTR string );
VOID  __stdargs dputs( CONST_STRPTR string );
VOID  __stdargs DPutS( CONST_STRPTR string );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_DDEBUG_PROTOS_H */
