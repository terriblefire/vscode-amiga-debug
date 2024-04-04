/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__s' for stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */

#ifndef _STDIO_H_
#define	_STDIO_H_

#include "_ansi.h"

#define	_FSTDIO			/* ``function stdio'' */

#define __need_size_t
#define __need_NULL
#include <sys/cdefs.h>
#include <stddef.h>

/* typedef only __gnuc_va_list, used throughout the header */
#define __need___va_list
#include <stdarg.h>

/* typedef va_list only when required */
#if __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE
#ifdef __GNUC__
#ifndef _VA_LIST_DEFINED
typedef __gnuc_va_list va_list;
#define _VA_LIST_DEFINED
#endif
#else /* !__GNUC__ */
#include <stdarg.h>
#endif
#endif /* __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE */

/*
 * <sys/reent.h> defines __FILE, _fpos_t.
 * They must be defined there because struct _reent needs them (and we don't
 * want reent.h to include this file.
 */

#include <sys/reent.h>
#include <sys/types.h>

_BEGIN_STD_C

#if !defined(__FILE_defined)
typedef __FILE FILE;
# define __FILE_defined
#endif

#ifdef __CYGWIN__
typedef _fpos64_t fpos_t;
#else
typedef _fpos_t fpos_t;
#ifdef __LARGE64_FILES
typedef _fpos64_t fpos64_t;
#endif
#endif /* !__CYGWIN__ */

#include <sys/stdio.h>

#define	__SLBF	0x0001		/* line buffered */
#define	__SNBF	0x0002		/* unbuffered */
#define	__SRD	0x0004		/* OK to read */
#define	__SWR	0x0008		/* OK to write */
	/* RD and WR are never simultaneously asserted */
#define	__SRW	0x0010		/* open for reading & writing */
#define	__SEOF	0x0020		/* found EOF */
#define	__SERR	0x0040		/* found error */
#define	__SMBF	0x0080		/* _buf is from malloc */
#define	__SAPP	0x0100		/* fdopen()ed in append mode - so must  write to end */
#define	__SSTR	0x0200		/* this is an sprintf/snprintf string */
#define	__SOPT	0x0400		/* do fseek() optimisation */
#define	__SNPT	0x0800		/* do not do fseek() optimisation */
#define	__SOFF	0x1000		/* set iff _offset is in fact correct */
#define	__SORD	0x2000		/* true => stream orientation (byte/wide) decided */
#if defined(__CYGWIN__)
#  define __SCLE  0x4000        /* convert line endings CR/LF <-> NL */
#endif
#define	__SL64	0x8000		/* is 64-bit offset large file */

/* _flags2 flags */
#define	__SNLK  0x0001		/* stdio functions do not lock streams themselves */
#define	__SWID	0x2000		/* true => stream orientation wide, false => byte, only valid if __SORD in _flags is true */

/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which stupidly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although these happen to match their counterparts above, the
 * implementation does not rely on that (so these could be renumbered).
 */
#define	_IOFBF	0		/* setvbuf should set fully buffered */
#define	_IOLBF	1		/* setvbuf should set line buffered */
#define	_IONBF	2		/* setvbuf should set unbuffered */

#define	EOF	(-1)

#ifdef __BUFSIZ__
#define	BUFSIZ		__BUFSIZ__
#else
#define	BUFSIZ		1024
#endif

#ifdef __FOPEN_MAX__
#define FOPEN_MAX	__FOPEN_MAX__
#else
#define	FOPEN_MAX	20
#endif

#ifdef __FILENAME_MAX__
#define FILENAME_MAX    __FILENAME_MAX__
#else
#define	FILENAME_MAX	1024
#endif

#ifdef __L_tmpnam__
#define L_tmpnam	__L_tmpnam__
#else
#define	L_tmpnam	FILENAME_MAX
#endif

#if __BSD_VISIBLE || __XSI_VISIBLE
#define P_tmpdir        "T:"
#endif

#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

#define	TMP_MAX		26

#define	stdin	(_REENT->_stdin)
#define	stdout	(_REENT->_stdout)
#define	stderr	(_REENT->_stderr)

#define _stdin_r(x)	((x)->_stdin)
#define _stdout_r(x)	((x)->_stdout)
#define _stderr_r(x)	((x)->_stderr)

/*
 * Functions defined in ANSI C standard.
 */

#ifndef __VALIST
#ifdef __GNUC__
#define __VALIST __gnuc_va_list
#else
#define __VALIST char*
#endif
#endif

#if __POSIX_VISIBLE
__stdargs char *	ctermid (char *);
#endif
#if __XSI_VISIBLE && __XSI_VISIBLE < 600
__stdargs char *	cuserid (char *);
#endif
__stdargs FILE *	tmpfile (void);
__stdargs char *	tmpnam (char *);
#if __BSD_VISIBLE || __XSI_VISIBLE || __POSIX_VISIBLE >= 200112
__stdargs char *	tempnam (const char *, const char *);
#endif
__stdargs int	fclose (FILE *);
__stdargs int	fflush (FILE *);
__stdargs FILE *	freopen (const char *__restrict, const char *__restrict, FILE *__restrict);
__stdargs void	setbuf (FILE *__restrict, char *__restrict);
__stdargs int	setvbuf (FILE *__restrict, char *__restrict, int, size_t);
__stdargs int	fprintf (FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	fscanf (FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs int	printf (const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 1, 2)));
__stdargs int	scanf (const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 2)));
__stdargs int	sscanf (const char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs int	vfprintf (FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	vprintf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 1, 0)));
__stdargs int	vsprintf (char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	fgetc (FILE *);
__stdargs char *  fgets (char *__restrict, int, FILE *__restrict);
__stdargs int	fputc (int, FILE *);
__stdargs int	fputs (const char *__restrict, FILE *__restrict);
__stdargs int	getc (FILE *);
__stdargs int	getchar (void);
__stdargs char *  gets (char *);
__stdargs int	putc (int, FILE *);
__stdargs int	putchar (int);
__stdargs int	puts (const char *);
__stdargs int	ungetc (int, FILE *);
__stdargs size_t	fread (void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs size_t	fwrite (const void *__restrict , size_t _size, size_t _n, FILE *);
#ifdef _COMPILING_NEWLIB
__stdargs int	fgetpos (FILE *, _fpos_t *);
#else
__stdargs int	fgetpos (FILE *__restrict, fpos_t *__restrict);
#endif
__stdargs int	fseek (FILE *, long, int);
#ifdef _COMPILING_NEWLIB
__stdargs int	fsetpos (FILE *, const _fpos_t *);
#else
__stdargs int	fsetpos (FILE *, const fpos_t *);
#endif
__stdargs long	ftell ( FILE *);
__stdargs void	rewind (FILE *);
__stdargs void	clearerr (FILE *);
__stdargs int	feof (FILE *);
__stdargs int	ferror (FILE *);
__stdargs void    perror (const char *);
#ifndef _REENT_ONLY
__stdargs FILE *	fopen (const char *__restrict _name, const char *__restrict _type);
__stdargs int	sprintf (char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	remove (const char *);
__stdargs int	rename (const char *, const char *);
#ifdef _COMPILING_NEWLIB
__stdargs int	_rename (const char *, const char *);
#endif
#endif
#if __LARGEFILE_VISIBLE || __POSIX_VISIBLE >= 200112
#ifdef _COMPILING_NEWLIB
__stdargs int	fseeko (FILE *, _off_t, int);
__stdargs _off_t	ftello (FILE *);
#else
__stdargs int	fseeko (FILE *, off_t, int);
__stdargs off_t	ftello (FILE *);
#endif
#endif
#if __GNU_VISIBLE
__stdargs int	fcloseall (void);
#endif
#ifndef _REENT_ONLY
#if __ISO_C_VISIBLE >= 1999
__stdargs int	snprintf (char *__restrict, size_t, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	vsnprintf (char *__restrict, size_t, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	vfscanf (FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
__stdargs int	vscanf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 0)));
__stdargs int	vsscanf (const char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
#endif
#if __GNU_VISIBLE
__stdargs int	asprintf (char **__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	vasprintf (char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
#endif
#if __MISC_VISIBLE /* Newlib-specific */
__stdargs int	asiprintf (char **, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs char *	asniprintf (char *, size_t *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs char *	asnprintf (char *__restrict, size_t *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
#ifndef diprintf
__stdargs int	diprintf (int, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
#endif
__stdargs int	fiprintf (FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	fiscanf (FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs int	iprintf (const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 1, 2)));
__stdargs int	iscanf (const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 2)));
__stdargs int	siprintf (char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	siscanf (const char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs int	sniprintf (char *, size_t, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	vasiprintf (char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs char *	vasniprintf (char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs char *	vasnprintf (char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	vdiprintf (int, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	vfiprintf (FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	vfiscanf (FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
__stdargs int	viprintf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 1, 0)));
__stdargs int	viscanf (const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 1, 0)));
__stdargs int	vsiprintf (char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	vsiscanf (const char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
__stdargs int	vsniprintf (char *, size_t, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
#endif /* __MISC_VISIBLE */
#endif /* !_REENT_ONLY */

/*
 * Routines in POSIX 1003.1:2001.
 */

#if __POSIX_VISIBLE
#ifndef _REENT_ONLY
__stdargs FILE *	fdopen (int, const char *);
#endif
__stdargs int	fileno (FILE *);
#endif
#if __MISC_VISIBLE || __POSIX_VISIBLE >= 199209
__stdargs int	pclose (FILE *);
__stdargs FILE *  popen (const char *, const char *);
#endif

#if __BSD_VISIBLE
__stdargs void    setbuffer (FILE *, char *, int);
__stdargs int	setlinebuf (FILE *);
#endif

#if __MISC_VISIBLE || (__XSI_VISIBLE && __POSIX_VISIBLE < 200112)
__stdargs int	getw (FILE *);
__stdargs int	putw (int, FILE *);
#endif
#if __MISC_VISIBLE || __POSIX_VISIBLE
__stdargs int	getc_unlocked (FILE *);
__stdargs int	getchar_unlocked (void);
__stdargs void	flockfile (FILE *);
__stdargs int	ftrylockfile (FILE *);
__stdargs void	funlockfile (FILE *);
__stdargs int	putc_unlocked (int, FILE *);
__stdargs int	putchar_unlocked (int);
#endif

/*
 * Routines in POSIX 1003.1:200x.
 */

#if __POSIX_VISIBLE >= 200809
# ifndef _REENT_ONLY
#  ifndef dprintf
__stdargs int	dprintf (int, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
#  endif
__stdargs FILE *	fmemopen (void *__restrict, size_t, const char *__restrict);
/* getdelim - see __getdelim for now */
/* getline - see __getline for now */
__stdargs FILE *	open_memstream (char **, size_t *);
__stdargs int	vdprintf (int, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
# endif
#endif
#if __ATFILE_VISIBLE
__stdargs int	renameat (int, const char *, int, const char *);
# ifdef __CYGWIN__
__stdargs int	renameat2 (int, const char *, int, const char *, unsigned int);
# endif
#endif

/*
 * Recursive versions of the above.
 */

__stdargs int	_asiprintf_r (struct _reent *, char **, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs char *	_asniprintf_r (struct _reent *, char *, size_t *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
__stdargs char *	_asnprintf_r (struct _reent *, char *__restrict, size_t *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
__stdargs int	_asprintf_r (struct _reent *, char **__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_diprintf_r (struct _reent *, int, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_dprintf_r (struct _reent *, int, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_fclose_r (struct _reent *, FILE *);
__stdargs int	_fcloseall_r (struct _reent *);
__stdargs FILE *	_fdopen_r (struct _reent *, int, const char *);
__stdargs int	_fflush_r (struct _reent *, FILE *);
__stdargs int	_fgetc_r (struct _reent *, FILE *);
__stdargs int	_fgetc_unlocked_r (struct _reent *, FILE *);
__stdargs char *  _fgets_r (struct _reent *, char *__restrict, int, FILE *__restrict);
__stdargs char *  _fgets_unlocked_r (struct _reent *, char *__restrict, int, FILE *__restrict);
#ifdef _COMPILING_NEWLIB
__stdargs int	_fgetpos_r (struct _reent *, FILE *__restrict, _fpos_t *__restrict);
__stdargs int	_fsetpos_r (struct _reent *, FILE *, const _fpos_t *);
#else
__stdargs int	_fgetpos_r (struct _reent *, FILE *, fpos_t *);
__stdargs int	_fsetpos_r (struct _reent *, FILE *, const fpos_t *);
#endif
__stdargs int	_fiprintf_r (struct _reent *, FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_fiscanf_r (struct _reent *, FILE *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
__stdargs FILE *	_fmemopen_r (struct _reent *, void *__restrict, size_t, const char *__restrict);
__stdargs FILE *	_fopen_r (struct _reent *, const char *__restrict, const char *__restrict);
__stdargs FILE *	_freopen_r (struct _reent *, const char *__restrict, const char *__restrict, FILE *__restrict);
__stdargs int	_fprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_fpurge_r (struct _reent *, FILE *);
__stdargs int	_fputc_r (struct _reent *, int, FILE *);
__stdargs int	_fputc_unlocked_r (struct _reent *, int, FILE *);
__stdargs int	_fputs_r (struct _reent *, const char *__restrict, FILE *__restrict);
__stdargs int	_fputs_unlocked_r (struct _reent *, const char *__restrict, FILE *__restrict);
__stdargs size_t	_fread_r (struct _reent *, void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs size_t	_fread_unlocked_r (struct _reent *, void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs int	_fscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
__stdargs int	_fseek_r (struct _reent *, FILE *, long, int);
__stdargs int	_fseeko_r (struct _reent *, FILE *, _off_t, int);
__stdargs long	_ftell_r (struct _reent *, FILE *);
__stdargs _off_t	_ftello_r (struct _reent *, FILE *);
__stdargs void	_rewind_r (struct _reent *, FILE *);
__stdargs size_t	_fwrite_r (struct _reent *, const void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs size_t	_fwrite_unlocked_r (struct _reent *, const void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs int	_getc_r (struct _reent *, FILE *);
__stdargs int	_getc_unlocked_r (struct _reent *, FILE *);
__stdargs int	_getchar_r (struct _reent *);
__stdargs int	_getchar_unlocked_r (struct _reent *);
__stdargs char *	_gets_r (struct _reent *, char *);
__stdargs int	_iprintf_r (struct _reent *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	_iscanf_r (struct _reent *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs FILE *	_open_memstream_r (struct _reent *, char **, size_t *);
__stdargs void	_perror_r (struct _reent *, const char *);
__stdargs int	_printf_r (struct _reent *, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
__stdargs int	_putc_r (struct _reent *, int, FILE *);
__stdargs int	_putc_unlocked_r (struct _reent *, int, FILE *);
__stdargs int	_putchar_unlocked_r (struct _reent *, int);
__stdargs int	_putchar_r (struct _reent *, int);
__stdargs int	_puts_r (struct _reent *, const char *);
__stdargs int	_remove_r (struct _reent *, const char *);
__stdargs int	_rename_r (struct _reent *,
			   const char *_old, const char *_new);
__stdargs int	_scanf_r (struct _reent *, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
__stdargs int	_siprintf_r (struct _reent *, char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_siscanf_r (struct _reent *, const char *, const char *, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
__stdargs int	_sniprintf_r (struct _reent *, char *, size_t, const char *, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
__stdargs int	_snprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 4, 5)));
__stdargs int	_sprintf_r (struct _reent *, char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
__stdargs int	_sscanf_r (struct _reent *, const char *__restrict, const char *__restrict, ...)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 4)));
__stdargs char *	_tempnam_r (struct _reent *, const char *, const char *);
__stdargs FILE *	_tmpfile_r (struct _reent *);
__stdargs char *	_tmpnam_r (struct _reent *, char *);
__stdargs int	_ungetc_r (struct _reent *, int, FILE *);
__stdargs int	_vasiprintf_r (struct _reent *, char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs char *	_vasniprintf_r (struct _reent*, char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
__stdargs char *	_vasnprintf_r (struct _reent*, char *, size_t *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
__stdargs int	_vasprintf_r (struct _reent *, char **, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vdiprintf_r (struct _reent *, int, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vdprintf_r (struct _reent *, int, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vfiprintf_r (struct _reent *, FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vfiscanf_r (struct _reent *, FILE *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
__stdargs int	_vfprintf_r (struct _reent *, FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vfscanf_r (struct _reent *, FILE *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
__stdargs int	_viprintf_r (struct _reent *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	_viscanf_r (struct _reent *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
__stdargs int	_vprintf_r (struct _reent *, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 2, 0)));
__stdargs int	_vscanf_r (struct _reent *, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 2, 0)));
__stdargs int	_vsiprintf_r (struct _reent *, char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vsiscanf_r (struct _reent *, const char *, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));
__stdargs int	_vsniprintf_r (struct _reent *, char *, size_t, const char *, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
__stdargs int	_vsnprintf_r (struct _reent *, char *__restrict, size_t, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 4, 0)));
__stdargs int	_vsprintf_r (struct _reent *, char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__printf__, 3, 0)));
__stdargs int	_vsscanf_r (struct _reent *, const char *__restrict, const char *__restrict, __VALIST)
               _ATTRIBUTE ((__format__ (__scanf__, 3, 0)));

/* Other extensions.  */

__stdargs int	fpurge (FILE *);
__stdargs ssize_t __getdelim (char **, size_t *, int, FILE *);
__stdargs ssize_t __getline (char **, size_t *, FILE *);

#if __MISC_VISIBLE
__stdargs void	clearerr_unlocked (FILE *);
__stdargs int	feof_unlocked (FILE *);
__stdargs int	ferror_unlocked (FILE *);
__stdargs int	fileno_unlocked (FILE *);
__stdargs int	fflush_unlocked (FILE *);
__stdargs int	fgetc_unlocked (FILE *);
__stdargs int	fputc_unlocked (int, FILE *);
__stdargs size_t	fread_unlocked (void *__restrict, size_t _size, size_t _n, FILE *__restrict);
__stdargs size_t	fwrite_unlocked (const void *__restrict , size_t _size, size_t _n, FILE *);
#endif

#if __GNU_VISIBLE
__stdargs char *  fgets_unlocked (char *__restrict, int, FILE *__restrict);
__stdargs int	fputs_unlocked (const char *__restrict, FILE *__restrict);
#endif

#ifdef __LARGE64_FILES
#if !defined(__CYGWIN__) || defined(_COMPILING_NEWLIB)
__stdargs FILE *	fdopen64 (int, const char *);
__stdargs FILE *  fopen64 (const char *, const char *);
__stdargs FILE *  freopen64 (const char *, const char *, FILE *);
__stdargs _off64_t ftello64 (FILE *);
__stdargs _off64_t fseeko64 (FILE *, _off64_t, int);
__stdargs int     fgetpos64 (FILE *, _fpos64_t *);
__stdargs int     fsetpos64 (FILE *, const _fpos64_t *);
__stdargs FILE *  tmpfile64 (void);

__stdargs FILE *	_fdopen64_r (struct _reent *, int, const char *);
__stdargs FILE *  _fopen64_r (struct _reent *,const char *, const char *);
__stdargs FILE *  _freopen64_r (struct _reent *, const char *, const char *, FILE *);
__stdargs _off64_t _ftello64_r (struct _reent *, FILE *);
__stdargs _off64_t _fseeko64_r (struct _reent *, FILE *, _off64_t, int);
__stdargs int     _fgetpos64_r (struct _reent *, FILE *, _fpos64_t *);
__stdargs int     _fsetpos64_r (struct _reent *, FILE *, const _fpos64_t *);
__stdargs FILE *  _tmpfile64_r (struct _reent *);
#endif /* !__CYGWIN__ */
#endif /* __LARGE64_FILES */

/*
 * Routines internal to the implementation.
 */

__stdargs int	__srget_r (struct _reent *, FILE *);
__stdargs int	__swbuf_r (struct _reent *, int, FILE *);

/*
 * Stdio function-access interface.
 */

#if __BSD_VISIBLE
# ifdef __LARGE64_FILES
__stdargs FILE	*funopen (const void *__cookie,
		__stdargs int (*__readfn)(void *__c, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		__stdargs int (*__writefn)(void *__c, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		__stdargs _fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
		__stdargs int (*__closefn)(void *__c));
__stdargs FILE	*_funopen_r (struct _reent *, const void *__cookie,
		__stdargs int (*__readfn)(void *__c, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
		__stdargs int (*__writefn)(void *__c, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
		__stdargs _fpos64_t (*__seekfn)(void *__c, _fpos64_t __off, int __whence),
		__stdargs int (*__closefn)(void *__c));
# else
__stdargs FILE	*funopen (const void *__cookie,
		__stdargs int (*__readfn)(void *__cookie, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
				__stdargs int (*__writefn)(void *__cookie, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
				 __stdargs fpos_t (*__seekfn)(void *__cookie, fpos_t __off, int __whence),
				 __stdargs int (*__closefn)(void *__cookie));
__stdargs FILE	*_funopen_r (struct _reent *, const void *__cookie,
		__stdargs int (*__readfn)(void *__cookie, char *__buf,
				_READ_WRITE_BUFSIZE_TYPE __n),
				__stdargs int (*__writefn)(void *__cookie, const char *__buf,
				 _READ_WRITE_BUFSIZE_TYPE __n),
				 __stdargs fpos_t (*__seekfn)(void *__cookie, fpos_t __off, int __whence),
				 __stdargs int (*__closefn)(void *__cookie));
# endif /* !__LARGE64_FILES */

# define	fropen(__cookie, __fn) funopen(__cookie, __fn, (int (*)())0, \
					       (fpos_t (*)())0, (int (*)())0)
# define	fwopen(__cookie, __fn) funopen(__cookie, (int (*)())0, __fn, \
					       (fpos_t (*)())0, (int (*)())0)
#endif /* __BSD_VISIBLE */

#if __GNU_VISIBLE
__stdargs typedef ssize_t cookie_read_function_t(void *__cookie, char *__buf, size_t __n);
__stdargs typedef ssize_t cookie_write_function_t(void *__cookie, const char *__buf,
					size_t __n);
# ifdef __LARGE64_FILES
typedef int cookie_seek_function_t(void *__cookie, _off64_t *__off,
				   int __whence);
# else
typedef __stdargs int cookie_seek_function_t(void *__cookie, off_t *__off, int __whence);
# endif /* !__LARGE64_FILES */
typedef __stdargs int cookie_close_function_t(void *__cookie);
typedef struct
{
  /* These four struct member names are dictated by Linux; hopefully,
     they don't conflict with any macros.  */
  cookie_read_function_t  *read;
  cookie_write_function_t *write;
  cookie_seek_function_t  *seek;
  cookie_close_function_t *close;
} cookie_io_functions_t;
__stdargs FILE *fopencookie (void *__cookie,
		const char *__mode, cookie_io_functions_t __functions);
__stdargs FILE *_fopencookie_r (struct _reent *, void *__cookie,
		const char *__mode, cookie_io_functions_t __functions);
#endif /* __GNU_VISIBLE */

#ifndef __CUSTOM_FILE_IO__
/*
 * The __sfoo macros are here so that we can 
 * define function versions in the C library.
 */
#define       __sgetc_raw_r(__ptr, __f) (--(__f)->_r < 0 ? __srget_r(__ptr, __f) : (int)(*(__f)->_p++))

#ifdef __SCLE
/*  For a platform with CR/LF, additional logic is required by
  __sgetc_r which would otherwise simply be a macro; therefore we
  use an inlined function.  The function is only meant to be inlined
  in place as used and the function body should never be emitted.  

  There are two possible means to this end when compiling with GCC,
  one when compiling with a standard C99 compiler, and for other
  compilers we're just stuck.  At the moment, this issue only
  affects the Cygwin target, so we'll most likely be using GCC. */

_ELIDABLE_INLINE int __sgetc_r(struct _reent *__ptr, FILE *__p);

_ELIDABLE_INLINE int __sgetc_r(struct _reent *__ptr, FILE *__p)
  {
    int __c = __sgetc_raw_r(__ptr, __p);
    if ((__p->_flags & __SCLE) && (__c == '\r'))
      {
      int __c2 = __sgetc_raw_r(__ptr, __p);
      if (__c2 == '\n')
        __c = __c2;
      else
        ungetc(__c2, __p);
      }
    return __c;
  }
#else
#define __sgetc_r(__ptr, __p) __sgetc_raw_r(__ptr, __p)
#endif

#ifdef __GNUC__
_ELIDABLE_INLINE int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {
#ifdef __SCLE
	if ((_p->_flags & __SCLE) && _c == '\n')
	  __sputc_r (_ptr, '\r', _p);
#endif
	if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
		return (*_p->_p++ = _c);
	else
		return (__swbuf_r(_ptr, _c, _p));
}
#else
/*
 * This has been tuned to generate reasonable code on the vax using pcc
 */
#define       __sputc_raw_r(__ptr, __c, __p) \
	(--(__p)->_w < 0 ? \
		(__p)->_w >= (__p)->_lbfsize ? \
			(*(__p)->_p = (__c)), *(__p)->_p != '\n' ? \
				(int)*(__p)->_p++ : \
				__swbuf_r(__ptr, '\n', __p) : \
			__swbuf_r(__ptr, (int)(__c), __p) : \
		(*(__p)->_p = (__c), (int)*(__p)->_p++))
#ifdef __SCLE
#define __sputc_r(__ptr, __c, __p) \
        ((((__p)->_flags & __SCLE) && ((__c) == '\n')) \
          ? __sputc_raw_r(__ptr, '\r', (__p)) : 0 , \
        __sputc_raw_r((__ptr), (__c), (__p)))
#else
#define __sputc_r(__ptr, __c, __p) __sputc_raw_r(__ptr, __c, __p)
#endif
#endif

#define	__sfeof(p)	((int)(((p)->_flags & __SEOF) != 0))
#define	__sferror(p)	((int)(((p)->_flags & __SERR) != 0))
#define	__sclearerr(p)	((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define	__sfileno(p)	((p)->_file)

#ifndef __cplusplus
#ifndef _REENT_SMALL
#define	feof(p)		__sfeof(p)
#define	ferror(p)	__sferror(p)
#define	clearerr(p)	__sclearerr(p)

#if __MISC_VISIBLE
#define	feof_unlocked(p)	__sfeof(p)
#define	ferror_unlocked(p)	__sferror(p)
#define	clearerr_unlocked(p)	__sclearerr(p)
#endif /* __MISC_VISIBLE */
#endif /* _REENT_SMALL */

#if 0 /* __POSIX_VISIBLE - FIXME: must initialize stdio first, use fn */
#define	fileno(p)	__sfileno(p)
#endif

static __inline int
_getchar_unlocked(void)
{
	struct _reent *_ptr;

	_ptr = _REENT;
	return (__sgetc_r(_ptr, _stdin_r(_ptr)));
}

static __inline int
_putchar_unlocked(int _c)
{
	struct _reent *_ptr;

	_ptr = _REENT;
	return (__sputc_r(_ptr, _c, _stdout_r(_ptr)));
}

#ifdef __SINGLE_THREAD__
#define	getc(_p)	__sgetc_r(_REENT, _p)
#define	putc(_c, _p)	__sputc_r(_REENT, _c, _p)
#define	getchar()	_getchar_unlocked()
#define	putchar(_c)	_putchar_unlocked(_c)
#endif /* __SINGLE_THREAD__ */

#if __MISC_VISIBLE || __POSIX_VISIBLE
#define	getchar_unlocked()	_getchar_unlocked()
#define	putchar_unlocked(_c)	_putchar_unlocked(_c)
#endif
#endif /* __cplusplus */

#if __MISC_VISIBLE
/* fast always-buffered version, true iff error */
#define	fast_putc(x,p) (--(p)->_w < 0 ? \
	__swbuf_r(_REENT, (int)(x), p) == EOF : (*(p)->_p = (x), (p)->_p++, 0))
#endif

#if __GNU_VISIBLE || (__XSI_VISIBLE && __XSI_VISIBLE < 600)
#define	L_cuserid	9		/* posix says it goes in stdio.h :( */
#endif
#if __POSIX_VISIBLE
#define L_ctermid       16
#endif

#else /* __CUSTOM_FILE_IO__ */

#define	getchar()	getc(stdin)
#define	putchar(x)	putc(x, stdout)

#if __MISC_VISIBLE || __POSIX_VISIBLE
#define	getchar_unlocked()	getc_unlocked(stdin)
#define	putchar_unlocked(x)	putc_unlocked(x, stdout)
#endif

#endif /* !__CUSTOM_FILE_IO__ */

_END_STD_C

#if __SSP_FORTIFY_LEVEL > 0
#include <ssp/stdio.h>
#endif

#endif /* _STDIO_H_ */