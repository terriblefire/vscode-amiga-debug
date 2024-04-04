/* Automatically generated header (sfdc 1.11d)! Do not edit! */

#ifndef _INLINE_EXPANSION_H
#define _INLINE_EXPANSION_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef EXPANSION_BASE_NAME
#define EXPANSION_BASE_NAME ExpansionBase
#endif /* !EXPANSION_BASE_NAME */

#define AddConfigDev(___configDev) \
      LP1NR(0x1e, AddConfigDev , struct ConfigDev *, ___configDev, a0,\
      , EXPANSION_BASE_NAME)

#define AddBootNode(___bootPri, ___flags, ___deviceNode, ___configDev) \
      LP4(0x24, ULONG, AddBootNode , ULONG, ___bootPri, d0, ULONG, ___flags, d1, ULONG, ___deviceNode, a0, ULONG, ___configDev, a1,\
      , EXPANSION_BASE_NAME)

#define AllocBoardMem(___slotSpec) \
      LP1(0x2a, ULONG, AllocBoardMem , ULONG, ___slotSpec, d0,\
      , EXPANSION_BASE_NAME)

#define AllocConfigDev() \
      LP0(0x30, ULONG, AllocConfigDev ,\
      , EXPANSION_BASE_NAME)

#define AllocExpansionMem(___numSlots, ___slotAlign) \
      LP2(0x36, ULONG, AllocExpansionMem , ULONG, ___numSlots, d0, ULONG, ___slotAlign, d1,\
      , EXPANSION_BASE_NAME)

#define ConfigBoard(___board, ___configDev) \
      LP2(0x3c, ULONG, ConfigBoard , ULONG, ___board, a0, ULONG, ___configDev, a1,\
      , EXPANSION_BASE_NAME)

#define ConfigChain(___baseAddr) \
      LP1(0x42, ULONG, ConfigChain , ULONG, ___baseAddr, a0,\
      , EXPANSION_BASE_NAME)

#define FindConfigDev(___oldConfigDev, ___manufacturer, ___product) \
      LP3(0x48, ULONG, FindConfigDev , ULONG, ___oldConfigDev, a0, ULONG, ___manufacturer, d0, ULONG, ___product, d1,\
      , EXPANSION_BASE_NAME)

#define FreeBoardMem(___startSlot, ___slotSpec) \
      LP2(0x4e, ULONG, FreeBoardMem , ULONG, ___startSlot, d0, ULONG, ___slotSpec, d1,\
      , EXPANSION_BASE_NAME)

#define FreeConfigDev(___configDev) \
      LP1(0x54, ULONG, FreeConfigDev , ULONG, ___configDev, a0,\
      , EXPANSION_BASE_NAME)

#define FreeExpansionMem(___startSlot, ___numSlots) \
      LP2(0x5a, ULONG, FreeExpansionMem , ULONG, ___startSlot, d0, ULONG, ___numSlots, d1,\
      , EXPANSION_BASE_NAME)

#define ReadExpansionByte(___board, ___offset) \
      LP2(0x60, ULONG, ReadExpansionByte , ULONG, ___board, a0, ULONG, ___offset, d0,\
      , EXPANSION_BASE_NAME)

#define ReadExpansionRom(___board, ___configDev) \
      LP2(0x66, ULONG, ReadExpansionRom , ULONG, ___board, a0, ULONG, ___configDev, a1,\
      , EXPANSION_BASE_NAME)

#define RemConfigDev(___configDev) \
      LP1(0x6c, ULONG, RemConfigDev , ULONG, ___configDev, a0,\
      , EXPANSION_BASE_NAME)

#define WriteExpansionByte(___board, ___offset, ___byte) \
      LP3(0x72, ULONG, WriteExpansionByte , ULONG, ___board, a0, ULONG, ___offset, d0, ULONG, ___byte, d1,\
      , EXPANSION_BASE_NAME)

#define ObtainConfigBinding() \
      LP0(0x78, ULONG, ObtainConfigBinding ,\
      , EXPANSION_BASE_NAME)

#define ReleaseConfigBinding() \
      LP0(0x7e, ULONG, ReleaseConfigBinding ,\
      , EXPANSION_BASE_NAME)

#define SetCurrentBinding(___currentBinding, ___bindingSize) \
      LP2(0x84, ULONG, SetCurrentBinding , ULONG, ___currentBinding, a0, ULONG, ___bindingSize, d0,\
      , EXPANSION_BASE_NAME)

#define GetCurrentBinding(___currentBinding, ___bindingSize) \
      LP2(0x8a, ULONG, GetCurrentBinding , ULONG, ___currentBinding, a0, ULONG, ___bindingSize, d0,\
      , EXPANSION_BASE_NAME)

#define MakeDosNode(___parmPacket) \
      LP1(0x90, ULONG, MakeDosNode , ULONG, ___parmPacket, a0,\
      , EXPANSION_BASE_NAME)

#define AddDosNode(___bootPri, ___flags, ___deviceNode) \
      LP3(0x96, ULONG, AddDosNode , ULONG, ___bootPri, d0, ULONG, ___flags, d1, ULONG, ___deviceNode, a0,\
      , EXPANSION_BASE_NAME)

#endif /* !_INLINE_EXPANSION_H */
