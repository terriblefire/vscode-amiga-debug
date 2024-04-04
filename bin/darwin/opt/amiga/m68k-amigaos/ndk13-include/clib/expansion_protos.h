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
VOID    __stdargs AddConfigDev( struct ConfigDev *configDev );
/*--- functions in V36 or higher (Release 2.0) ---*/
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
