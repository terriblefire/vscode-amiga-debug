#ifndef  CLIB_MATHFFP_PROTOS_H
#define  CLIB_MATHFFP_PROTOS_H

/*
**	$VER: mathffp_protos.h 40.1 (17.5.1996)
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
LONG    __stdargs SPFix( FLOAT parm );
FLOAT    __stdargs SPFlt( LONG integer );
LONG    __stdargs SPCmp( FLOAT leftParm, FLOAT rightParm );
LONG    __stdargs SPTst( FLOAT parm );
FLOAT    __stdargs SPAbs( FLOAT parm );
FLOAT    __stdargs SPNeg( FLOAT parm );
FLOAT    __stdargs SPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs SPDiv( FLOAT leftParm, FLOAT rightParm );
/*--- functions in V33 or higher (Release 1.2) ---*/
FLOAT    __stdargs SPFloor( FLOAT parm );
FLOAT    __stdargs SPCeil( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_MATHFFP_PROTOS_H */
