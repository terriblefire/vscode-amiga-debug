#ifndef  CLIB_MATHIEEEDOUBBAS_PROTOS_H
#define  CLIB_MATHIEEEDOUBBAS_PROTOS_H

/*
**	$VER: mathieeedoubbas_protos.h 40.1 (17.5.1996)
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
LONG  __stdargs IEEEDPFix( DOUBLE parm );
DOUBLE  __stdargs IEEEDPFlt( LONG integer );
LONG  __stdargs IEEEDPCmp( DOUBLE leftParm, DOUBLE rightParm );
LONG  __stdargs IEEEDPTst( DOUBLE parm );
DOUBLE  __stdargs IEEEDPAbs( DOUBLE parm );
DOUBLE  __stdargs IEEEDPNeg( DOUBLE parm );
DOUBLE  __stdargs IEEEDPAdd( DOUBLE leftParm, DOUBLE rightParm );
DOUBLE  __stdargs IEEEDPSub( DOUBLE leftParm, DOUBLE rightParm );
DOUBLE  __stdargs IEEEDPMul( DOUBLE factor1, DOUBLE factor2 );
DOUBLE  __stdargs IEEEDPDiv( DOUBLE dividend, DOUBLE divisor );
/*--- functions in V33 or higher (Release 1.2) ---*/
DOUBLE  __stdargs IEEEDPFloor( DOUBLE parm );
DOUBLE  __stdargs IEEEDPCeil( DOUBLE parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_MATHIEEEDOUBBAS_PROTOS_H */
