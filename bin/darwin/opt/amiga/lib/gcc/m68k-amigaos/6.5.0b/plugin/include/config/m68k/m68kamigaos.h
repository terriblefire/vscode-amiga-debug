/* m68kelf support, derived from m68kv4.h */

/* Target definitions for GNU compiler for mc680x0 running AmigaOs
   Copyright (C) 1991-2016 Free Software Foundation, Inc.

   Written by Ron Guilmette (rfg@netcom.com) and Fred Fish (fnf@cygnus.com).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef TARGET_AMIGA
#define TARGET_AMIGA 1
#endif

#define HAS_INIT_SECTION

#ifndef SWBEG_ASM_OP
#define SWBEG_ASM_OP "\t.swbeg\t"
#endif

#ifdef TARGET_AMIGAOS_VASM
#undef ASM_STABS_OP
#define  ASM_STABS_OP "|\t.stabs\t"

#undef ASM_STABD_OP
#define ASM_STABD_OP "|\t.stabd\t"

#undef ASM_STABN_OP
#define ASM_STABN_OP "|\t.stabn\t"
#endif

#undef PIC_REG
#define PIC_REG 12

#undef FRAME_POINTER_REGNUM
#define FRAME_POINTER_REGNUM 13

#undef M68K_REGNAME
#define M68K_REGNAME(r) ( \
  ( ((r) == FRAME_POINTER_REGNUM) \
    && frame_pointer_needed) ? \
    M68K_FP_REG_NAME : reg_names[(r)])



/* Here are three prefixes that are used by asm_fprintf to
   facilitate customization for alternate assembler syntaxes.
   Machines with no likelihood of an alternate syntax need not
   define these and need not use asm_fprintf.  */

/* The prefix for register names.  Note that REGISTER_NAMES
   is supposed to include this prefix. Also note that this is NOT an
   fprintf format string, it is a literal string */

#undef REGISTER_PREFIX
#define REGISTER_PREFIX ""

/* The prefix for local (compiler generated) labels.
   These labels will not appear in the symbol table.  */

#undef LOCAL_LABEL_PREFIX
#ifndef TARGET_AMIGAOS_VASM
#define LOCAL_LABEL_PREFIX "."
#else
#define LOCAL_LABEL_PREFIX "_."
#endif

/* The prefix to add to user-visible assembler symbols.  */

#undef USER_LABEL_PREFIX
#define USER_LABEL_PREFIX "_"

/* config/m68k.md has an explicit reference to the program counter,
   prefix this by the register prefix.  */

#ifndef TARGET_AMIGAOS_VASM
#define ASM_RETURN_CASE_JUMP \
  do { \
      return "jmp %%pc@(2,%0:w)"; \
  } while (0)
#else
#define ASM_RETURN_CASE_JUMP \
  do { \
     return "jmp (2,pc,%0.w)"; \
  } while (0)
#endif

/* This is how to output an assembler line that says to advance the
   location counter to a multiple of 2**LOG bytes.  */

#ifndef TARGET_AMIGAOS_VASM
#ifndef ALIGN_ASM_OP
#define ALIGN_ASM_OP "\t.align\t"
#endif
#else
#define ALIGN_ASM_OP "\talign\t"
#endif

#undef ASM_OUTPUT_ALIGN
#ifndef TARGET_AMIGAOS_VASM
#define ASM_OUTPUT_ALIGN(FILE,LOG) \
do { \
  if ((LOG) > 0) \
    fprintf ((FILE), "%s%u\n", ALIGN_ASM_OP, 1 << (LOG)); \
} while (0)
#else
#define ASM_OUTPUT_ALIGN(FILE,LOG) \
do { \
  if ((LOG) > 0) \
    fprintf ((FILE), "%s%u\n", ALIGN_ASM_OP, (LOG)); \
} while (0)
#endif

#if 0
extern int amiga_declare_object;

#define ASM_DECLARE_OBJECT_NAME(FILE,NAME,DECL) \
if (!DECL_INITIAL (DECL) || \
    initializer_zerop (DECL_INITIAL (decl))) \
  { \
    amiga_declare_object = 1; \
    fprintf ((FILE), ".comm\t%s,", NAME); \
  } \
else \
ASM_OUTPUT_LABEL (FILE, NAME)

#undef ASM_OUTPUT_SKIP
#define ASM_OUTPUT_SKIP(FILE,SIZE) \
if (amiga_declare_object) \
  fprintf (FILE, "%u\n", (int)(SIZE)); \
else \
  fprintf (FILE, "\t.skip %u\n", (int)(SIZE)); \
amiga_declare_object = 0
#endif

/* Register in which address to store a structure value is passed to a
   function.  The default in m68k.h is a1.  For m68k/SVR4 it is a0.  */

#undef M68K_STRUCT_VALUE_REGNUM
#define M68K_STRUCT_VALUE_REGNUM A0_REG

/* The static chain regnum defaults to a0, but we use that for
   structure return, so have to use a1 for the static chain.  */

#undef STATIC_CHAIN_REGNUM
#define STATIC_CHAIN_REGNUM A1_REG
#undef M68K_STATIC_CHAIN_REG_NAME
#define M68K_STATIC_CHAIN_REG_NAME REGISTER_PREFIX "a1"

#ifndef TARGET_AMIGAOS_VASM
#define ASM_COMMENT_START "|"
#else
#define ASM_COMMENT_START "|"
#endif

/* Define how the m68k registers should be numbered for Dwarf output.
   The numbering provided here should be compatible with the native
   SVR4 SDB debugger in the m68k/SVR4 reference port, where d0-d7
   are 0-7, a0-a8 are 8-15, and fp0-fp7 are 16-23.  */

#undef DBX_REGISTER_NUMBER
#define DBX_REGISTER_NUMBER(REGNO) (REGNO)

#if 0
/* SVR4 m68k assembler is bitching on the `comm i,1,1' which askes for
   1 byte alignment. Don't generate alignment for COMMON seems to be
   safer until we the assembler is fixed.  */
#undef ASM_OUTPUT_ALIGNED_COMMON
/* Same problem with this one.  */
#undef ASM_OUTPUT_ALIGNED_LOCAL
#endif

#undef ASM_OUTPUT_COMMON
#undef ASM_OUTPUT_LOCAL
#ifndef TARGET_AMIGAOS_VASM
#define ASM_OUTPUT_COMMON(FILE, NAME, SIZE, ROUNDED) \
( fputs (".comm ", (FILE)), \
  assemble_name ((FILE), (NAME)), \
  fprintf ((FILE), ",%u\n", (int)(SIZE)))
#else
#define ASM_OUTPUT_COMMON(FILE, NAME, SIZE, ROUNDED) \
  ( switch_to_section (bss_section), \
  fputs ("|.comm\n\tcnop 0,4\n", (FILE)), \
  assemble_name ((FILE), (NAME)), \
  fprintf ((FILE), ":\n\tds.b %u\n", (int)(SIZE)), \
  fputs ("\txdef ", (FILE)), \
  assemble_name ((FILE), (NAME)), \
  fprintf ((FILE), "\n"))
#endif

#ifndef TARGET_AMIGAOS_VASM
#define ASM_OUTPUT_LOCAL(FILE, NAME, SIZE, ROUNDED) \
( fputs (".lcomm ", (FILE)), \
  assemble_name ((FILE), (NAME)), \
  fprintf ((FILE), ",%u\n", (int)(SIZE)))
#else
#define ASM_OUTPUT_LOCAL(FILE, NAME, SIZE, ROUNDED) \
( switch_to_section (bss_section), \
  fputs ("|.lcomm\n\tcnop 0,4\n", (FILE)), \
  assemble_name ((FILE), (NAME)), \
  fprintf ((FILE), ":\n\tds.b %u\n", (int)(SIZE)))
#endif

/* Currently, JUMP_TABLES_IN_TEXT_SECTION must be defined in order to
   keep switch tables in the text section.  */

#define JUMP_TABLES_IN_TEXT_SECTION 1

/* In m68k svr4, using swbeg is the standard way to do switch
   table.  */
#undef ASM_OUTPUT_BEFORE_CASE_LABEL
#define ASM_OUTPUT_BEFORE_CASE_LABEL(FILE,PREFIX,NUM,TABLE) \
  fprintf ((FILE), "%s&%d\n", SWBEG_ASM_OP, XVECLEN (PATTERN (TABLE), 1));
/* end of stuff from m68kv4.h */

#ifndef TARGET_AMIGAOS_VASM
#undef BSS_SECTION_ASM_OP
#define BSS_SECTION_ASM_OP    "\t.bss"
#else
#define BSS_SECTION_ASM_OP    (!flag_pic?"\tsection\t.bss,bss":"\tsection\t.bss_near,bss")
#endif

#ifndef TARGET_AMIGAOS_VASM
#undef DATA_SECTION_ASM_OP
#define DATA_SECTION_ASM_OP    "\t.data"
#else
#define DATA_SECTION_ASM_OP    (!flag_pic?"\tsection\t.data,data":"\tsection\t.data_near,data")
#endif

#ifndef ASM_OUTPUT_ALIGNED_BSS
#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN) \
  asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
#endif


/* Specs, switches.  */

/* amiga/amigaos are the new "standard" defines for the Amiga.
   MCH_AMIGA, AMIGA, __chip etc. are used in other compilers and are
   provided for compatibility reasons.
   When creating shared libraries, use different 'errno'.  */

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() \
  do \
    { \
      builtin_define ("__entrypoint=__attribute__((__entrypoint__))"); \
      builtin_define ("__saveallregs=__attribute__((__saveallregs__))");\
      builtin_define ("__chip=__attribute__((__chip__))"); \
      builtin_define ("__fast=__attribute__((__fast__))"); \
      builtin_define ("__far=__attribute__((__far__))"); \
      builtin_define ("__near=__attribute__((section(\".data\")))"); \
      builtin_define ("__saveds=__attribute__((__saveds__))"); \
      builtin_define ("__interrupt=__attribute__((__interrupt__))"); \
      builtin_define ("__stackext=__attribute__((__stackext__))"); \
      builtin_define ("__regargs=__attribute__((__regparm__(2)))"); \
      builtin_define ("__stdargs=__attribute__((__stkparm__))"); \
      builtin_define ("__retfp0=__attribute__((__retfp0__))"); \
      builtin_define ("__aligned=__attribute__((__aligned__(4)))"); \
      builtin_define ("__retfp0=__attribute__((__retfp0__))"); \
      builtin_define_std ("amiga"); \
      builtin_define_std ("amigaos"); \
      builtin_define_std ("amigaos3"); \
      builtin_define_std ("AMIGA"); \
      builtin_define_std ("MCH_AMIGA"); \
      builtin_assert ("system=amigaos"); \
      if (flag_pic > 2) \
    { \
      builtin_define ("__baserel__"); \
      if (flag_pic > 3) \
        builtin_define ("__baserel32__"); \
    } \
      if (flag_resident) \
    builtin_define ("__resident__"); \
      if (__POSIX_THREADS__) \
    builtin_define ("__posix_threads__"); \
    } \
  while (0)

#if 0
if (target_flags & (MASK_RESTORE_A4|MASK_ALWAYS_RESTORE_A4)) \
  builtin_define ("errno=(*ixemul_errno)"); \

#endif

/* SBF: same as linux.h */

/* 1 if N is a possible register number for a function value.  For
   m68k/SVR4 allow d0, a0, or fp0 as return registers, for integral,
   pointer, or floating types, respectively.  Reject fp0 if not using
   a 68881 coprocessor.  */

#undef FUNCTION_VALUE_REGNO_P
#define FUNCTION_VALUE_REGNO_P(N) \
  ((N) == D0_REG || (N) == A0_REG || (TARGET_68881 && (N) == FP0_REG))

/* Define this to be true when FUNCTION_VALUE_REGNO_P is true for
   more than one register.  */

#undef NEEDS_UNTYPED_CALL
#define NEEDS_UNTYPED_CALL 1

/* Define how to generate (in the callee) the output value of a
   function and how to find (in the caller) the value returned by a
   function.  VALTYPE is the data type of the value (as a tree).  If
   the precise function being called is known, FUNC is its
   FUNCTION_DECL; otherwise, FUNC is 0.  For m68k/SVR4 generate the
   result in d0, a0, or fp0 as appropriate.  */

#undef FUNCTION_VALUE
#define FUNCTION_VALUE(VALTYPE, FUNC)					\
  m68k_function_value (VALTYPE, FUNC)


/* When creating shared libraries, use different 'errno'. */
#define CPP_IXEMUL_SPEC \
  "%{!ansi:-Dixemul} -D__ixemul__ -D__ixemul " \
  "%{malways-restore-a4:-Derrno=(*ixemul_errno)} " \
  "%{mrestore-a4:-Derrno=(*ixemul_errno)}"
#define CPP_LIBNIX_SPEC \
  "-isystem %:sdk_root(libnix/include) " \
  "%{!ansi:-Dlibnix} -D__libnix__ -D__libnix " \
  "%{mcrt=nix13:-D__KICK13__}"
#define CPP_CLIB2_SPEC \
  "-isystem %:sdk_root(clib2/include) " \
  "%{!ansi:-DCLIB2} -D__CLIB2__ -D__CLIB2"

/* Define __HAVE_68881__ in preprocessor according to the -m flags.
   This will control the use of inline 68881 insns in certain macros.
   Note: it should be set in TARGET_CPU_CPP_BUILTINS but TARGET_68881
         isn't the same -m68881 since its also true for -m680[46]0 ...
   Differentiate between libnix and ixemul.  */

#define CPP_SPEC \
  "%{!m68881:%{mhard-float:-D__HAVE_68881__}} " \
  "%{m68881:-D__HAVE_68881__} " \
  "%{!ansi:" \
    "%{m68020:-Dmc68020} " \
    "%{mc68020:-Dmc68020} " \
    "%{m68020-40:-Dmc68020} " \
    "%{m68020-60:-Dmc68020} " \
    "%{m68030:-Dmc68030} " \
    "%{m68040:-Dmc68040} " \
    "%{m68060:-Dmc68060}} " \
  "%{m68020:-D__mc68020__ -D__mc68020} " \
  "%{mc68020:-D__mc68020__ -D__mc68020} " \
  "%{m68020-40:-D__mc68020__ -D__mc68020} " \
  "%{m68020-60:-D__mc68020__ -D__mc68020} " \
  "%{m68030:-D__mc68030__ -D__mc68030} " \
  "%{m68040:-D__mc68040__ -D__mc68040} " \
  "%{m68060:-D__mc68060__ -D__mc68060} " \
  "-isystem %:sdk_root(../include) " \
  "%{mcrt=nix13:-isystem %:sdk_root(ndk13-include)} " \
  "%{noixemul:%(cpp_libnix)} " \
  "%{mcrt=nix*:%(cpp_libnix)} " \
  "%{mcrt=ixemul:%(cpp_ixemul)} " \
  "%{mcrt=clib2:%(cpp_clib2)}"

/* Various -m flags require special flags to the assembler.  */

#undef ASM_SPEC
#ifndef TARGET_AMIGAOS_VASM
#define ASM_SPEC \
   "%(asm_cpu) %(asm_cpu_default) %{msmall-code:-sc} "
#else
#define ASM_SPEC \
   "-gas -esc -ldots -Fhunk -quiet %(asm_cpu) %(asm_cpu_default) %{msmall-code:-sc}"
#endif

#undef ASM_CPU_SPEC
#define ASM_CPU_SPEC \
  "%{mcpu=*:-m%*} " \
  "%{m68000|mc68000:-m68010} " \
  "%{m6802*|mc68020:-m68020} " \
  "%{m68030} " \
  "%{m68040} " \
  "%{m68060}"

#ifndef TARGET_AMIGAOS_VASM
#define ASM_CPU_DEFAULT_SPEC \
   "%{!m680*:%{!mc680*:%{!mcpu=*:-m68000}}}"
#else
#define ASM_CPU_DEFAULT_SPEC \
   "%{!m680*:%{!mc680*:-m68000}}"
#endif

/* Choose the right startup file, depending on whether we use base relative
   code, base relative code with automatic relocation (-resident), their
   32-bit versions, libnix, profiling or plain crt0.o.  */

#define STARTFILE_IXEMUL_SPEC \
  "%{fbaserel:%{!resident:bcrt0.o%s}}" \
  "%{resident:rcrt0.o%s}" \
  "%{fbaserel32:%{!resident32:lcrt0.o%s}}" \
  "%{resident32:scrt0.o%s}" \
  "%{!resident:%{!fbaserel:%{!resident32:%{!fbaserel32:" \
    "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}}}"

#define STARTFILE_LIBNIX_SPEC \
  "%{ramiga-*:" \
    "%{ramiga-lib:libinit.o%s}" \
    "%{ramiga-libr:libinitr.o%s}" \
    "%{ramiga-dev:devinit.o%s}}" \
  "%{!ramiga-*:" \
    "%{resident32:nlrcrt0.o%s}" \
    "%{!resident32:%{fbaserel32:nlbcrt0.o%s}" \
    "%{!fbaserel32:" \
    "%{!mcpu=68000:%{!mcpu=68010:-u___cpucheck }} "\
    "%{resident:nrcrt0.o%s}" \
    "%{!resident:%{fbaserel:nbcrt0.o%s}" \
    "%{!fbaserel:ncrt0.o%s}}}}}"

#define ENDFILE_LIBNIX_SPEC \
  "%{!ramiga-*:xcrt0.o%s}"

#define STARTFILE_CLIB2_SPEC \
  "%{resident32:nr32crt0.o%s}" \
  "%{!resident32:" \
    "%{fbaserel32:nb32crt0.o%s}" \
    "%{!fbaserel32:" \
      "%{resident:nrcrt0.o%s}" \
      "%{!resident:" \
        "%{fbaserel:nbcrt0.o%s}" \
        "%{!fbaserel:ncrt0.o%s}}}}"

#define STARTFILE_NEWLIB_SPEC \
    "crt0.o%s "

#define SELF_SPEC \
 "%{noixemul:-B %:sdk_root(libnix/lib/)} " \
 "%{mcrt=nix*:-B %:sdk_root(libnix/lib/)} " \
 "%{mcrt=clib2:-B %:sdk_root(clib2/lib/)} "

#undef    STARTFILE_SPEC
#ifdef TARGET_AMIGAOS_VASM
#define STARTFILE_SPEC \
   "startup%O%s"
#else
#define STARTFILE_SPEC \
  "%{noixemul:%(startfile_libnix)} " \
  "%{mcrt=nix*:%(startfile_libnix)} " \
  "%{mcrt=ixemul:%(startfile_ixemul)} " \
  "%{mcrt=clib2:%(startfile_clib2)} " \
  "%{!mcrt=*:%{!noixemul:%(startfile_newlib)}} "
#endif

#if 0
#undef ENDFILE_SPEC
#define ENDFILE_SPEC ""
#else
#ifdef TARGET_AMIGAOS_VASM
#else
#define ENDFILE_SPEC \
  "%{noixemul:%(endfile_libnix)} " \
  "%{mcrt=nix*:%(endfile_libnix)} "
#endif
#endif

/* Automatically search libamiga.a for AmigaOS specific functions.  Note
   that we first search the standard C library to resolve as much as
   possible from there, since it has names that are duplicated in libamiga.a
   which we *don't* want from there.  Then search libamiga.a for any calls
   that were not generated inline, and finally search the standard C library
   again to resolve any references that libamiga.a might have generated.
   This may only be a temporary solution since it might be better to simply
   remove the things from libamiga.a that should be pulled in from libc.a
   instead, which would eliminate the first reference to libc.a.  Note that
   if we don't search it automatically, it is very easy for the user to try
   to put in a -lamiga himself and get it in the wrong place, so that (for
   example) calls like sprintf come from -lamiga rather than -lc. */

#define LIB_IXEMUL_SPEC \
  "%{!p:%{!pg:-lc}} " \
  "%{p:-lc_p} %{pg:-lc_p}"
#define LIB_LIBNIX_SPEC \
  "%{mcrt=*:-l%*} " \
  "%{!mcrt=*:-lnix20} " \
  "-lnixmain -lnix -lstubs " \
  "%{mstackcheck:-lstack} " \
  "%{mstackextend:-lstack}"
#define LIB_CLIB2_SPEC \
  "-lc -ldebug " \
  "%{mstackcheck:-lstack} " \
  "%{mstackextend:-lstack}"

#define LIB_NEWLIB_SPEC \
  "-lc " \
  "-lstubs "

#if __POSIX_THREADS__
#define __LPTHREAD__ "-lpthread "
#else
#define __LPTHREAD__   "%{pthread:-lpthread} %{lpthread:-lpthread } "
#endif

#ifdef TARGET_AMIGAOS_VASM
#define LIB_SPEC \
  "-lvc -lamiga "
#else
#define LIB_SPEC \
  "-( " \
  "%{noixemul:%(lib_libnix)} " \
  "%{mcrt=nix*:%(lib_libnix)} " \
  "%{mcrt=ixemul:%(lib_ixemul)} " \
  "%{mcrt=clib2:%(lib_clib2)} " \
  "%{!mcrt=*:%{!noixemul:%(lib_newlib)}} " \
  "-lamiga -lgcc "\
  __LPTHREAD__ \
  "%{lm:-lm -l__m__ } "\
  "-) "
#endif

#define LIBGCC_SPEC ""

/* If debugging, tell the linker to output amiga-hunk symbols *and* a BSD
   compatible debug hunk.
   Also, pass appropriate linker flavours depending on user-supplied
   commandline options.  */

#define LINK_IXEMUL_SPEC ""
#define LINK_LIBNIX_SPEC "-L%:sdk_root(libnix/lib)"
#define LINK_CLIB2_SPEC "-L%:sdk_root(clib2/lib)"

/* If debugging, tell the linker to output amiga-hunk symbols *and* a BSD
   compatible debug hunk.
   Also, pass appropriate linker flavours depending on user-supplied
   commandline options.  */

#ifdef TARGET_AMIGAOS_VASM
#define LINK_SPEC \
  "%{noixemul:%(link_libnix)} " \
  "%{mcrt=nix*:%(link_libnix)} " \
  "%{mcrt=ixemul:%(link_ixemul)} " \
  "%{mcrt=clib2:%(link_clib2)} " \
  "%{fbaserel:%{!resident:-m amiga_bss -fl libb}} " \
  "%{resident:-m amiga_bss -amiga-datadata-reloc -fl libb} " \
  "%{fbaserel32:%{!resident32:-m amiga_bss -fl libb32}} " \
  "%{resident32:-m amiga_bss -amiga-datadata-reloc -fl libb32} " \
  "%(link_cpu) "
#else
#define LINK_SPEC \
  "-L%:sdk_root(../lib) " \
  "%{noixemul:%(link_libnix)} " \
  "%{mcrt=nix*:%(link_libnix)} " \
  "%{mcrt=ixemul:%(link_ixemul)} " \
  "%{mcrt=clib2:%(link_clib2)} " \
  "%{fbaserel:%{!resident:-m amiga_bss -fl libb}} " \
  "%{resident:-m amiga_bss -amiga-datadata-reloc -fl libb} " \
  "%{fbaserel32:%{!resident32:-m amiga_bss -fl libb32}} " \
  "%{resident32:-m amiga_bss -amiga-datadata-reloc -fl libb32} " \
  "%{g:-amiga-debug-hunk} " \
  "%(link_cpu) "
#endif

/* Translate '-resident' to '-fbaserel' (they differ in linking stage only).
   Don't put function addresses in registers for PC-relative code.  */

#define CC1_SPEC \
  "%{resident:-fbaserel} " \
  "%{resident32:-fbaserel32} " \
  "%{msmall-code:-fno-function-cse}"

#define LINK_CPU_SPEC \
  "%{m6806*|mcpu=6806*:-fl libm060} " \
  "%{m6802*|mc6802*|m6803*|m6804*|m6806*|m6808*|mcpu=6802*|mcpu=6803*|mcpu=6804*|mcpu=6806*|mcpu=6808*:-fl libm020} " \
  "%{mhard-float|m68881|mcpu=6804*|mcpu=6806*|mcpu=6808*:-fl libm881}"

#ifdef TARGET_AMIGAOS_VASM
#define LINK_COMMAND_SPEC \
  "%{!fsyntax-only:" \
    "%{!c:" \
      "%{!M:" \
    "%{!MM:" \
      "%{!E:" \
        "%{!S:" \
          "%(linker) -Cvbcc %l %X %{o*} %{A} %{d} %{e*} %{m} " \
          "%{N} %{n} %{r} %{s} %{t} %{u*} %{x} %{z} %{Z} " \
          "%{!A:%{!nostdlib:%{!nostartfiles:%S}}} " \
          "%{static:} %{L*} %D %o " \
          "%{!nostdlib:%{!nodefaultlibs:%L}} " \
          "%{!A:%{!nostdlib:%{!nostartfiles:%E}}} " \
          "%{!nostdlib:%{!nodefaultlibs:%G}} " \
          "%{flto} " \
          "%{T*} }}}}}} "
#else
#define LINK_COMMAND_SPEC \
  "%{!fsyntax-only:" \
    "%{!c:" \
      "%{!M:" \
    "%{!MM:" \
      "%{!E:" \
        "%{!S:" \
          "%(linker) %l %X %{o*} %{A} %{d} %{e*} %{m} " \
          "%{N} %{n} %{r} %{s} %{t} %{u*} %{x} %{z} %{Z} " \
          "%{!A:%{!nostdlib:%{!nostartfiles:%S}}} " \
          "%{static:} %{L*} %D %o " \
          "%{!nostdlib:%{!nodefaultlibs:%L}} " \
          "%{!A:%{!nostdlib:%{!nostartfiles:%E}}} " \
          "%{!nostdlib:%{!nodefaultlibs:%G}} " \
              "%{flto} " \
          "%{T*} }}}}}} "
#endif

extern const char * amiga_m68k_prefix_func(int, const char **);

#define EXTRA_SPEC_FUNCTIONS \
  { "sdk_root", amiga_m68k_prefix_func },

/* This macro defines names of additional specifications to put in the specs
   that can be used in various specifications like CC1_SPEC.  Its definition
   is an initializer with a subgrouping for each command option.

   Each subgrouping contains a string constant, that defines the
   specification name, and a string constant that used by the GCC driver
   program.

   Do not define this macro if it does not need to do anything.  */
#undef EXTRA_SPECS
#define EXTRA_SPECS \
  {"asm_cpu", ASM_CPU_SPEC }, \
  {"asm_cpu_default", ASM_CPU_DEFAULT_SPEC }, \
  {"link_cpu", LINK_CPU_SPEC }, \
  {"cpp_ixemul", CPP_IXEMUL_SPEC}, \
  {"cpp_libnix", CPP_LIBNIX_SPEC}, \
  {"cpp_clib2", CPP_CLIB2_SPEC}, \
  {"lib_ixemul", LIB_IXEMUL_SPEC}, \
  {"lib_newlib", LIB_NEWLIB_SPEC}, \
  {"lib_libnix", LIB_LIBNIX_SPEC}, \
  {"lib_clib2", LIB_CLIB2_SPEC}, \
  {"link_ixemul", LINK_IXEMUL_SPEC}, \
  {"link_libnix", LINK_LIBNIX_SPEC}, \
  {"link_clib2", LINK_CLIB2_SPEC}, \
  {"startfile_ixemul", STARTFILE_IXEMUL_SPEC}, \
  {"startfile_libnix", STARTFILE_LIBNIX_SPEC}, \
  {"endfile_libnix", ENDFILE_LIBNIX_SPEC}, \
  {"startfile_clib2", STARTFILE_CLIB2_SPEC}, \
  {"startfile_newlib", STARTFILE_NEWLIB_SPEC}, \

/* begin-GG-local: dynamic libraries */

extern int amigaos_do_collecting (void);
extern void amigaos_gccopts_hook (const char *);
extern void amigaos_libname_hook (const char* arg);
extern void amigaos_collect2_cleanup (void);
extern void amigaos_prelink_hook (const char **, int *);
extern void amigaos_postlink_hook (const char *);

/* This macro is used to check if all collect2 facilities should be used.
   We need a few special ones, like stripping after linking.  */

#define DO_COLLECTING (do_collecting || amigaos_do_collecting())

/* This macro is called in collect2 for every GCC argument name.
   ARG is a part of commandline (without '\0' at the end).  */

#define COLLECT2_GCC_OPTIONS_HOOK(ARG) amigaos_gccopts_hook(ARG)

/* This macro is called in collect2 for every ld's "-l" or "*.o" or "*.a"
   argument.  ARG is a complete argument, with '\0' at the end.  */

#define COLLECT2_LIBNAME_HOOK(ARG) amigaos_libname_hook(ARG)

/* This macro is called at collect2 exit, to clean everything up.  */

#define COLLECT2_EXTRA_CLEANUP amigaos_collect2_cleanup

/* This macro is called just before the first linker invocation.
   LD1_ARGV is "char** argv", which will be passed to "ld".  STRIP is an
   *address* of "strip_flag" variable.  */

#define COLLECT2_PRELINK_HOOK(LD1_ARGV, STRIP) \
amigaos_prelink_hook((const char **)(LD1_ARGV), (STRIP))

/* This macro is called just after the first linker invocation, in place of
   "nm" and "ldd".  OUTPUT_FILE is the executable's filename.  */

#define COLLECT2_POSTLINK_HOOK(OUTPUT_FILE) amigaos_postlink_hook(OUTPUT_FILE)
/* end-GG-local */

#define USE_COLLECT2

#undef MAX_OFILE_ALIGNMENT
#define MAX_OFILE_ALIGNMENT ((1 << 15)*BITS_PER_UNIT)

#ifdef __amiga__
#define CROSS_DIRECTORY_STRUCTURE

#undef CROSS_INCLUDE_DIR
#define CROSS_INCLUDE_DIR "GCC:m68k-amigaos/sys-include"

#undef FIXED_INCLUDE_DIR
#define FIXED_INCLUDE_DIR "GCC:m68k-amigaos/ndk-include"

#else

#undef FIXED_INCLUDE_DIR
#define FIXED_INCLUDE_DIR CROSS_INCLUDE_DIR "/../ndk-include"

#endif

/* Baserel support.  */
extern int amiga_is_const_pic_ref(const_rtx x);

#undef CONSTANT_ADDRESS_P
#define CONSTANT_ADDRESS_P(X) \
((GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF \
 || GET_CODE (X) == CONST_INT || GET_CODE (X) == CONST \
 || GET_CODE (X) == HIGH \
 ))



/* Given that symbolic_operand(X), return TRUE if no special
   base relative relocation is necessary */

#undef LEGITIMATE_PIC_OPERAND_P
#define LEGITIMATE_PIC_OPERAND_P(X) ( \
    (! symbolic_operand (X, VOIDmode) && \
    ! amiga_is_const_pic_ref(X))) \
    || amiga_is_far_symbol(X)

extern int amiga_is_far_symbol(const_rtx x);

// (GET_CODE(X) == CONST && (GET_CODE(XEXP(X, 0)) == SYMBOL_REF || GET_CODE(XEXP(X, 0)) == LABEL_REF) && !CONSTANT_POOL_ADDRESS_P (XEXP(X, 0))) ||

#undef TARGET_GCC_EXCEPT_TABLE
#define TARGET_GCC_EXCEPT_TABLE ".text"

#undef TARGET_GCC_EXCEPT_TABLE_S
#define TARGET_GCC_EXCEPT_TABLE_S ".text"

#define EH_TABLES_CAN_BE_READ_ONLY 1


/* Max. number of data, address and float registers to be used for passing
   integer, pointer and float arguments when TARGET_REGPARM.
   It's 4, so d0-d3, a0-a3 and fp0-fp3 can be used.  */
#undef AMIGAOS_MAX_REGPARM
#define AMIGAOS_MAX_REGPARM 4

/* The default number of data, address and float registers to use when
   user specified '-mregparm' switch, not '-mregparm=<value>' option.  */
#undef AMIGAOS_DEFAULT_REGPARM
#define AMIGAOS_DEFAULT_REGPARM 2

/* 1 if N is a possible register number for function argument passing.  */
#undef FUNCTION_ARG_REGNO_P
#define FUNCTION_ARG_REGNO_P(N)    amigaos_function_arg_reg(N)

extern int
amigaos_function_arg_reg(unsigned regno);

//extern bool debug_recog(char const * txt, int which_alternative, int n, rtx * operands);

/* SBF: modified RATIOs there 3 operand pushes, the call and the sp correction -> 5 insns.
 *
 * Plus the compare is a '<' => use 6 to create up to 5 clr/move insns.
 */
#undef MOVE_RATIO
#undef CLEAR_RATIO
//#define MOVE_RATIO(speed) ((speed) ? 15 : 3)
//#define CLEAR_RATIO(speed) ((speed) ? 15 :3)
#define MOVE_RATIO(speed) ((speed) ? 15 : 6)
#define CLEAR_RATIO(speed) ((speed) ? 15 : 6)

/* Compile with a4 restoring in public functions.  */

#define MASK_RESTORE_A4 0x10000000 /* 1 << 28 */
#define TARGET_RESTORE_A4 \
  ((target_flags & MASK_RESTORE_A4) && TREE_PUBLIC (current_function_decl))

/* Compile with a4 restoring in all functions.  */

#define MASK_ALWAYS_RESTORE_A4 0x8000000 /* 1 << 27 */
#define TARGET_ALWAYS_RESTORE_A4 (target_flags & MASK_ALWAYS_RESTORE_A4)


#undef  SIZE_TYPE
#define SIZE_TYPE "unsigned int"

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

#undef  WCHAR_TYPE
#define WCHAR_TYPE "int"

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE BITS_PER_WORD

#undef STDINT_LONG32
#define STDINT_LONG32 0

#undef HAVE_GAS_CFI_DIRECTIVE
#define HAVE_GAS_CFI_DIRECTIVE 0

#undef FUNCTION_PROFILER
#define FUNCTION_PROFILER(FILE, LABELNO) \
  asm_fprintf (FILE, "\tjsr _mcount\n")


#define DOUBLE_INDIRECT_JUMP 1

#define HAVE_GAS_WEAKREF 1

/* This is how we tell the assembler that a symbol is weak.  */
#define ASM_WEAKEN_LABEL(FILE, NAME)	\
  do					\
    {					\
      fputs ("\t.weak\t", (FILE));	\
      assemble_name ((FILE), (NAME));	\
      fputc ('\n', (FILE));		\
    }					\
  while (0)

#define MAKE_DECL_ONE_ONLY(DECL) (DECL_WEAK (DECL) = 1)

#if 0

#undef  SET_ASM_OP
#define SET_ASM_OP	"\t.set\t"

/* Output a definition (implements alias) */
#define ASM_OUTPUT_DEF(FILE,LABEL1,LABEL2)				\
do									\
{									\
    fputs (SET_ASM_OP, (FILE));						\
    assemble_name (FILE, LABEL1);					\
    fputc (',', (FILE));						\
    assemble_name (FILE, LABEL2);					\
    fputc ('\n', (FILE));						\
    }									\
while (0)
#endif

#define CTOR_LISTS_DEFINED_EXTERNALLY 1
