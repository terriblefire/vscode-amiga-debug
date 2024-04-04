#ifndef  CLIB_AML_PROTOS_H
#define  CLIB_AML_PROTOS_H

/*
**	$VER: aml_protos.h 1.2 (6.10.1999)
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
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif
#ifndef  LIBRARIES_AML_H
#include <libraries/aml.h>
#endif
LONG  __stdargs RexxDispatcher( struct RexxMsg *rxm );
APTR  __stdargs CreateServerA( struct TagItem *tags );
APTR  __stdargs CreateServer( Tag firstTag, ... );
VOID  __stdargs DisposeServer( APTR server );
ULONG  __stdargs SetServerAttrsA( APTR server, struct TagItem *tags );
ULONG  __stdargs SetServerAttrs( APTR server, ... );
ULONG  __stdargs GetServerAttrsA( APTR server, struct TagItem *tags );
ULONG  __stdargs GetServerAttrs( APTR server, ... );
ULONG  __stdargs GetServerHeaders( APTR server, ULONG flags );
LONG  __stdargs GetServerArticles( APTR server, APTR folder, struct Hook *hook, ULONG flags );
APTR  __stdargs CreateFolderA( APTR server, struct TagItem *tags );
APTR  __stdargs CreateFolder( APTR server, ... );
BOOL  __stdargs DisposeFolder( APTR folder );
APTR  __stdargs OpenFolderA( APTR server, struct TagItem *tags );
APTR  __stdargs OpenFolder( APTR server, ... );
BOOL  __stdargs SaveFolder( APTR folder );
BOOL  __stdargs RemFolder( APTR folder );
ULONG  __stdargs SetFolderAttrsA( APTR folder, struct TagItem *tags );
ULONG  __stdargs SetFolderAttrs( APTR folder, ... );
ULONG  __stdargs GetFolderAttrsA( APTR folder, struct TagItem *tags );
ULONG  __stdargs GetFolderAttrs( APTR folder, ... );
BOOL  __stdargs AddFolderArticle( APTR folder, ULONG type, APTR data );
BOOL  __stdargs RemFolderArticle( APTR folder, APTR article );
ULONG  __stdargs ReadFolderSpool( APTR folder, STRPTR importfile, ULONG flags );
ULONG  __stdargs WriteFolderSpool( APTR folder, STRPTR exportfile, ULONG flags );
ULONG  __stdargs ScanFolderIndex( APTR folder, struct Hook *hook, ULONG flags );
BOOL  __stdargs ExpungeFolder( APTR folder, APTR trash, struct Hook *hook );
ULONG  __stdargs CreateFolderIndex( APTR folder );
ULONG  __stdargs SortFolderIndex( APTR folder, ULONG field );
APTR  __stdargs CreateArticleA( APTR folder, struct TagItem *tags );
APTR  __stdargs CreateArticle( APTR folder, ... );
BOOL  __stdargs DisposeArticle( APTR article );
APTR  __stdargs OpenArticle( APTR server, APTR folder, ULONG msgID, ULONG flags );
BOOL  __stdargs CopyArticle( APTR folder, APTR article );
ULONG  __stdargs SetArticleAttrsA( APTR article, struct TagItem *tags );
ULONG  __stdargs SetArticleAttrs( APTR article, ... );
ULONG  __stdargs GetArticleAttrsA( APTR article, struct TagItem *tags );
ULONG  __stdargs GetArticleAttrs( APTR article, ... );
BOOL  __stdargs SendArticle( APTR server, APTR article, UBYTE *from_file );
BOOL  __stdargs AddArticlePartA( APTR article, APTR part, struct TagItem *tags );
BOOL  __stdargs AddArticlePart( APTR article, APTR part, ... );
VOID  __stdargs RemArticlePart( APTR article, APTR part );
APTR  __stdargs GetArticlePart( APTR article, ULONG partnum );
ULONG  __stdargs GetArticlePartAttrsA( APTR part, struct TagItem *tags );
ULONG  __stdargs GetArticlePartAttrs( APTR part, ... );
ULONG  __stdargs SetArticlePartAttrsA( APTR part, struct TagItem *tags );
ULONG  __stdargs SetArticlePartAttrs( APTR part, ... );
APTR  __stdargs CreateArticlePartA( APTR article, struct TagItem *tags );
APTR  __stdargs CreateArticlePart( APTR article, ... );
VOID  __stdargs DisposeArticlePart( APTR part );
BOOL  __stdargs GetArticlePartDataA( APTR article, APTR part, struct TagItem *tags );
BOOL  __stdargs GetArticlePartData( APTR article, APTR part, ... );
BOOL  __stdargs SetArticlePartDataA( APTR part, struct TagItem *tags );
BOOL  __stdargs SetArticlePartData( APTR part, ... );
APTR  __stdargs CreateAddressEntryA( struct TagItem *tags );
APTR  __stdargs CreateAddressEntry( Tag firstTag, ... );
BOOL  __stdargs DisposeAddressEntry( APTR addr );
APTR  __stdargs OpenAddressEntry( APTR server, ULONG fileid );
LONG  __stdargs SaveAddressEntry( APTR server, APTR addr );
BOOL  __stdargs RemAddressEntry( APTR server, APTR addr );
ULONG  __stdargs GetAddressEntryAttrsA( APTR addr, struct TagItem *tags );
ULONG  __stdargs GetAddressEntryAttrs( APTR addr, ... );
ULONG  __stdargs SetAddressEntryAttrsA( APTR addr, struct TagItem *tags );
ULONG  __stdargs SetAddressEntryAttrs( APTR addr, ... );
BOOL  __stdargs MatchAddressA( APTR addr, struct TagItem *tags );
BOOL  __stdargs MatchAddress( APTR addr, ... );
APTR  __stdargs FindAddressEntryA( APTR server, struct TagItem *tags );
APTR  __stdargs FindAddressEntry( APTR server, ... );
APTR  __stdargs HuntAddressEntryA( APTR server, struct TagItem *tags );
APTR  __stdargs HuntAddressEntry( APTR server, ... );
ULONG  __stdargs ScanAddressIndex( APTR server, struct Hook *hook, ULONG type, ULONG flags );
BOOL  __stdargs AddCustomField( APTR addr, STRPTR field, STRPTR data );
BOOL  __stdargs RemCustomField( APTR addr, STRPTR field );
STRPTR  __stdargs GetCustomFieldData( APTR addr, STRPTR field );
APTR  __stdargs CreateDecoderA( struct TagItem *tags );
APTR  __stdargs CreateDecoder( Tag firstTag, ... );
VOID  __stdargs DisposeDecoder( APTR dec );
ULONG  __stdargs GetDecoderAttrsA( APTR dec, struct TagItem *tags );
ULONG  __stdargs GetDecoderAttrs( APTR dec, ... );
ULONG  __stdargs SetDecoderAttrsA( APTR dec, struct TagItem *tags );
ULONG  __stdargs SetDecoderAttrs( APTR dec, ... );
LONG  __stdargs Decode( APTR dec, ULONG type );
LONG  __stdargs Encode( APTR dec, ULONG type );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_AML_PROTOS_H */
