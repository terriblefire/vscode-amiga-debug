#ifndef  CLIB_BULLET_PROTOS_H
#define  CLIB_BULLET_PROTOS_H

/*
**	$VER: bullet_protos.h 7.1 (22.5.1992)
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2001 Amiga, Inc.
**	    All Rights Reserved
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DISKFONT_GLYPH_H
#include <diskfont/glyph.h>
#endif
struct GlyphEngine * __stdargs OpenEngine( VOID );
VOID  __stdargs CloseEngine( struct GlyphEngine *glyphEngine );
ULONG  __stdargs SetInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
ULONG  __stdargs SetInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );
ULONG  __stdargs ObtainInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
ULONG  __stdargs ObtainInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );
ULONG  __stdargs ReleaseInfoA( struct GlyphEngine *glyphEngine, struct TagItem *tagList );
ULONG  __stdargs ReleaseInfo( struct GlyphEngine *glyphEngine, Tag tag1, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_BULLET_PROTOS_H */
