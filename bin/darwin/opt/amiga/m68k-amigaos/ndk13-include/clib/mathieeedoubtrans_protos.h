#ifndef  CLIB_MATHIEEEDOUBTRANS_PROTOS_H
#define  CLIB_MATHIEEEDOUBTRANS_PROTOS_H

/*
**	$VER: mathieeedoubtrans_protos.h 40.1 (17.5.1996)
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
DOUBLE    __stdargs IEEEDPAtan( DOUBLE parm );
DOUBLE    __stdargs IEEEDPSin( DOUBLE parm );
DOUBLE    __stdargs IEEEDPCos( DOUBLE parm );
DOUBLE    __stdargs IEEEDPTan( DOUBLE parm );
DOUBLE    __stdargs IEEEDPSincos( DOUBLE *pf2, DOUBLE parm );
DOUBLE    __stdargs IEEEDPSinh( DOUBLE parm );
DOUBLE    __stdargs IEEEDPCosh( DOUBLE parm );
DOUBLE    __stdargs IEEEDPTanh( DOUBLE parm );
DOUBLE    __stdargs IEEEDPExp( DOUBLE parm );
DOUBLE    __stdargs IEEEDPLog( DOUBLE parm );
DOUBLE    __stdargs IEEEDPPow( DOUBLE exp, DOUBLE arg );
DOUBLE    __stdargs IEEEDPSqrt( DOUBLE parm );
FLOAT    __stdargs IEEEDPTieee( DOUBLE parm );
DOUBLE    __stdargs IEEEDPFieee( FLOAT single );
DOUBLE    __stdargs IEEEDPAsin( DOUBLE parm );
DOUBLE    __stdargs IEEEDPAcos( DOUBLE parm );
DOUBLE    __stdargs IEEEDPLog10( DOUBLE parm );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_MATHIEEEDOUBTRANS_PROTOS_H */
