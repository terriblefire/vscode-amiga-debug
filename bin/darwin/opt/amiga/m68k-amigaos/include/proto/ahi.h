/* Automatically generated header (sfdc 1.11d)! Do not edit! */

#ifndef PROTO_AHI_H
#define PROTO_AHI_H

#include L<clib/ahi_protos.h>

#ifndef _NO_INLINE
# if defined(__GNUC__)
#  ifdef __AROS__
#   include L<defines/ahi.h>
#  else
#   include L<inline/ahi.h>
#  endif
# else
#  include L<pragmas/ahi_pragmas.h>
# endif
#endif /* _NO_INLINE */

#ifdef __amigaos4__
# include <interfaces/ahi.h>
# ifndef __NOGLOBALIFACE__
   extern struct AHIIFace *IAHI;
# endif /* __NOGLOBALIFACE__*/
#endif /* !__amigaos4__ */
#ifndef __NOLIBBASE__
  extern struct Library *
# ifdef __CONSTLIBBASEDECL__
   __CONSTLIBBASEDECL__
# endif /* __CONSTLIBBASEDECL__ */
  AHIBase;
#endif /* !__NOLIBBASE__ */

#endif /* !PROTO_AHI_H */