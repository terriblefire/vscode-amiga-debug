@rem copy c:\amiga-mingw\opt\libexec\gcc\m68k-amiga-elf\11.2.0\cc1.exe ..\..\..\..\..\bin\opt\libexec\gcc\m68k-amiga-elf\11.2.0\
md out\win32
del /y out\win32\*.*
..\..\..\..\..\bin\win32\opt\bin\m68k-amiga-elf-gcc -dumpspecs >out\win32\specs
..\..\..\..\..\bin\win32\opt\bin\m68k-amiga-elf-gcc -dP -dD -dA -mcpu=68000 -g -Og -Wall -Wno-strict-aliasing -Wno-pointer-sign -Wno-unused-function -Wno-volatile-register-var -Wno-switch -Werror=incompatible-pointer-types -Werror=return-type -fomit-frame-pointer -fno-tree-loop-distribution -fdata-sections -ffunction-sections -fno-exceptions -fdump-rtl-dwarf2 -fdwarf2-cfi-asm -c item.c -o out\win32\item.o -Wa,-ahl=out\win32\item.dump
..\..\..\..\..\bin\win32\opt\bin\m68k-amiga-elf-gcc -dP -dD -dA -mcpu=68000 -g -Og -Wall -Wno-strict-aliasing -Wno-pointer-sign -Wno-unused-function -Wno-volatile-register-var -Wno-switch -Werror=incompatible-pointer-types -Werror=return-type -fomit-frame-pointer -fno-tree-loop-distribution -fdata-sections -ffunction-sections -fno-exceptions -fdump-rtl-dwarf2 -fdwarf2-cfi-asm -c item.c -S -o out\win32\item.s
@rem c:\amiga-mingw\build-gcc-11.2.0\gcc\cc1.exe -quiet item.c -quiet -dumpbase item.c -dP -dD -dA -mcpu=68000 -auxbase-strip item.o -g -Og -Wall -Wno-strict-aliasing -Wno-pointer-sign -Wno-unused-function -Wno-volatile-register-var -Wno-switch -Werror=incompatible-pointer-types -Werror=return-type -version -fomit-frame-pointer -fno-tree-loop-distribution -fdata-sections -ffunction-sections -fno-exceptions -fdump-rtl-dwarf2 -fdwarf2-cfi-asm  -o item.s
..\..\..\..\..\bin\win32\opt\bin\m68k-amiga-elf-objdump --dwarf=frames-interp out\win32\item.o >out\win32\item.frames.objdump
..\..\..\..\..\bin\win32\opt\m68k-amiga-elf\bin\readelf.exe --debug=frames out\win32\item.o >out\win32\item.frames.readelf