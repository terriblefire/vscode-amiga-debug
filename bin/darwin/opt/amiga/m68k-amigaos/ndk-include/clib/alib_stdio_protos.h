#ifndef  CLIB_ALIB_STDIO_PROTOS_H
#define  CLIB_ALIB_STDIO_PROTOS_H

/*
**	$VER: alib_stdio_protos.h 40.1 (20.7.1996)
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

/* stdio functions that duplicate those in a typical C library */

LONG  __stdargs printf( CONST_STRPTR fmt, ... );
LONG  __stdargs sprintf( CONST_STRPTR buffer, CONST_STRPTR fmt, ... );
LONG  __stdargs fclose( LONG stream );
LONG  __stdargs fgetc( LONG stream );
LONG  __stdargs fprintf( LONG stream, CONST_STRPTR fmt, ... );
LONG  __stdargs fputc( LONG c, LONG stream );
LONG  __stdargs fputs( CONST_STRPTR s, LONG stream );
LONG  __stdargs getchar( VOID );
LONG  __stdargs putchar( ULONG c );
LONG  __stdargs puts( CONST_STRPTR s );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_ALIB_STDIO_PROTOS_H */
