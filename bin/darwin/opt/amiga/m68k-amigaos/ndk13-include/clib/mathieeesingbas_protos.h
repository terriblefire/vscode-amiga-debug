#ifndef  CLIB_MATHIEEESINGBAS_PROTOS_H
#define  CLIB_MATHIEEESINGBAS_PROTOS_H

/*
**	$VER: mathieeesingbas_protos.h 40.1 (17.5.1996)
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
LONG    __stdargs IEEESPFix( FLOAT parm );
FLOAT    __stdargs IEEESPFlt( LONG integer );
LONG    __stdargs IEEESPCmp( FLOAT leftParm, FLOAT rightParm );
LONG    __stdargs IEEESPTst( FLOAT parm );
FLOAT    __stdargs IEEESPAbs( FLOAT parm );
FLOAT    __stdargs IEEESPNeg( FLOAT parm );
FLOAT    __stdargs IEEESPAdd( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs IEEESPSub( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs IEEESPMul( FLOAT leftParm, FLOAT rightParm );
FLOAT    __stdargs IEEESPDiv( FLOAT dividend, FLOAT divisor );
FLOAT    __stdargs IEEESPFloor( FLOAT parm );
FLOAT    __stdargs IEEESPCeil( FLOAT parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_MATHIEEESINGBAS_PROTOS_H */
