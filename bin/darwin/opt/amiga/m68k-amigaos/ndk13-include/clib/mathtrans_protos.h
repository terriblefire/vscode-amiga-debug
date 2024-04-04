#ifndef  CLIB_MATHTRANS_PROTOS_H
#define  CLIB_MATHTRANS_PROTOS_H

/*
**	$VER: mathtrans_protos.h 40.1 (17.5.1996)
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
FLOAT    __stdargs SPAtan( FLOAT parm );
FLOAT    __stdargs SPSin( FLOAT parm );
FLOAT    __stdargs SPCos( FLOAT parm );
FLOAT    __stdargs SPTan( FLOAT parm );
FLOAT    __stdargs SPSincos( FLOAT *cosResult, FLOAT parm );
FLOAT    __stdargs SPSinh( FLOAT parm );
FLOAT    __stdargs SPCosh( FLOAT parm );
FLOAT    __stdargs SPTanh( FLOAT parm );
FLOAT    __stdargs SPExp( FLOAT parm );
FLOAT    __stdargs SPLog( FLOAT parm );
FLOAT    __stdargs SPPow( FLOAT power, FLOAT arg );
FLOAT    __stdargs SPSqrt( FLOAT parm );
FLOAT    __stdargs SPTieee( FLOAT parm );
FLOAT    __stdargs SPFieee( FLOAT parm );
/*--- functions in V31 or higher (Release 1.1) ---*/
FLOAT    __stdargs SPAsin( FLOAT parm );
FLOAT    __stdargs SPAcos( FLOAT parm );
FLOAT    __stdargs SPLog10( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_MATHTRANS_PROTOS_H */
