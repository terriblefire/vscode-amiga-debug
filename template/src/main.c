#include <stdio.h>

#define TITLE		"Program"
#define AUTHOR		"Nomen Nominandum"

#include "version.h"
#include "logging.h"

const char IDString[] = VSTRING;
const char VTAG[] = VERSTAG;

void rainbow(int16_t delay);
uint32_t getvbr();
void lev3irq();

#define ECS_SPECIFIC

#include <exec/types.h>
#include <exec/execbase.h>
#include <exec/memory.h>
#include <graphics/gfxbase.h>
#include <graphics/copper.h>
#include <inline/exec.h>
#include <inline/graphics.h>
#include <hardware/intbits.h>
#include <hardware/custom.h>
#include <hardware/dmabits.h>
#include <hardware/intbits.h>

#include "c2p1x1_8_c5_gen.h"

#define BPLX        (320)
#define BPLY        (200)
#define BPLNR       (8)
#define CHUNKYXRES  (1)
#define CHUNKYYRES  (1)
#define CHUNKYXMAX  (BPLX / CHUNKYXRES)
#define CHUNKYYMAX  (BPLY / CHUNKYYRES)
#define CHUNKYSIZE  (CHUNKYXMAX * CHUNKYYMAX)
#define BPLSIZE     (BPLX * CHUNKYYMAX / 8)
#define BBLANK      (0)       // 0=No, 1=Yes
#define BPLCON0     ( ((BPLNR & 0x7)<<12) | ((BPLNR & 0x8)<<1) | 0x0201 )

uint8_t* bitplanes;

void vertb_irq()
{
    struct Custom* custom = (struct Custom*)0xdff000;
    uint8_t* planar = bitplanes;
    void* volatile* bplptr = &custom->bplpt[0];
    for (int16_t i = 7; i >= 0; --i)
    {
        *bplptr++ = planar;
        planar += BPLSIZE;
    }   
/*
    custom->bplpt[1] = planar; planar += BPLSIZE;
    custom->bplpt[2] = planar; planar += BPLSIZE;
    custom->bplpt[3] = planar; planar += BPLSIZE;
    custom->bplpt[4] = planar; planar += BPLSIZE;
    custom->bplpt[5] = planar; planar += BPLSIZE;
    custom->bplpt[6] = planar; planar += BPLSIZE;
    custom->bplpt[7] = planar; planar += BPLSIZE;*/
}

void takedown()
{
    struct ExecBase* SysBase = *(struct ExecBase**)4;

    Disable();

    struct GfxBase* GfxBase = (struct GfxBase*)SysBase->IntVects[INTB_BLIT].iv_Data;
    struct View* oldView = GfxBase->ActiView;
    LoadView(NULL);
    WaitTOF();
    WaitTOF();

    struct Custom* custom = (struct Custom*)0xdff000;
    custom->bplcon0 = 0;
    custom->beamcon0 = DISPLAYPAL;
    uint16_t oldintena = custom->intenar;
    uint16_t oldintreq = custom->intreqr;
    uint16_t olddmacon = custom->dmaconr;
    custom->intena = (uint16_t)~INTF_SETCLR;
    custom->intreq = (uint16_t)~INTF_SETCLR;
    custom->dmacon = (uint16_t)~DMAF_SETCLR;

    uint32_t vbr = Supervisor((void*)getvbr);
    void** lev3vec = (void*)vbr+0x6c;
    void* oldlev3vec = *lev3vec;
    *lev3vec = lev3irq;

    custom->intena = (INTF_SETCLR | INTF_INTEN | INTF_VERTB);
    custom->dmacon = (DMAF_SETCLR | DMAF_MASTER | DMAF_RASTER);

    custom->bplcon0 = 0x0211;
    custom->diwstrt = 0x2c81;
    custom->diwstop = 0x2cc1;
    custom->ddfstrt = 0x0038;
    custom->ddfstop = 0x00d0;
//    custom->bplcon0 = 0x1200;
    custom->bplcon1 = 0x0000;
    custom->bplcon3 = 0x0000;
    custom->bplcon4 = 0x0011;
    custom->bpl1mod = 0x0000;
    custom->bpl2mod = 0x0000;
    custom->fmode = 0x0003;

    // set colors (black -> white gradient)
    for (uint16_t c = 0; c < 256; ++c)
    {
        uint16_t bank = c >> 5;
        uint16_t index = c & 31;
        uint16_t LOCT = 1 << 9;

        uint16_t hi = (c >> 4);
        uint16_t lo = (c & 0xf);

        uint16_t hi_color = (hi << 8) | (hi << 4) | (hi);
        uint16_t lo_color = (lo << 8) | (lo << 4) | (lo);

        custom->bplcon3 = (bank << 13);
        custom->color[index] = hi_color;
        custom->bplcon3 = (bank << 13) | LOCT;
        custom->color[index] = lo_color;
    }
    custom->bplcon3 = 0x0000;

    uint32_t width = 320;
    uint32_t height = 256;
    uint32_t numplanes = 8;

    bitplanes = (uint8_t*)AllocMem(numplanes * (width * height / 8), MEMF_CHIP);
    uint8_t* chunky = (uint8_t*)AllocMem((width * height), MEMF_PUBLIC);

    c2p1x1_8_c5_gen_init(width, height, 0);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            uint32_t offset = y * width + x;
            chunky[offset] = offset & 0xff;
        }
    }
    
    c2p1x1_8_c5_gen(chunky, bitplanes);

    rainbow(9999);

    FreeMem(bitplanes, numplanes * (width * height / 8));

    *lev3vec = oldlev3vec;

    custom->intena = INTF_SETCLR | oldintena;
    custom->intreq = INTF_SETCLR | oldintreq;
    custom->dmacon = DMAF_SETCLR | olddmacon;
    custom->cop1lc = (uint32_t)GfxBase->copinit;
    LoadView(oldView);

    Enable();
}


void restore()
{

}

__stdargs  // main() uses arguments passed via the stack
int main(int argc, const char* argv[])
{
    // print to stdout
    printf("\n%s :\n", argv[0]);
    printf("VSTRING = %s", IDString);

    // print to serial (9600 8N1)
    kprintf("\n%s :\n", argv[0]);

    KLOG(LOG_INFO, __FILE__, "VSTRING = %s\n", IDString);

    KFATAL  ("FATAL",   "This is a fatal error\n");
    KERROR  ("ERROR",   "This is an error\n");
    KWARN   ("WARN",    "This is a warning\n");
    KINFO   ("INFO",    "This is an info message\n");
    KDEBUG  ("DEBUG",   "This is debug info\n");
    KVERBOSE("VERBOSE", "This is verbose output\n");

    // call some assembly code
    // rainbow(111);
    takedown();

    return 0;
}
