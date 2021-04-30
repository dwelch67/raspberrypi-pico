
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );

#define RESETS_BASE                 0x4000C000

#define RESETS_RESET_RW        (RESETS_BASE+0x0+0x0000)
#define RESETS_RESET_XOR       (RESETS_BASE+0x0+0x1000)
#define RESETS_RESET_SET       (RESETS_BASE+0x0+0x2000)
#define RESETS_RESET_CLR       (RESETS_BASE+0x0+0x3000)

#define RESETS_WDSEL_RW        (RESETS_BASE+0x4+0x0000)
#define RESETS_WDSEL_XOR       (RESETS_BASE+0x4+0x1000)
#define RESETS_WDSEL_SET       (RESETS_BASE+0x4+0x2000)
#define RESETS_WDSEL_CLR       (RESETS_BASE+0x4+0x3000)

#define RESETS_RESET_DONE_RW   (RESETS_BASE+0x8+0x0000)
#define RESETS_RESET_DONE_XOR  (RESETS_BASE+0x8+0x1000)
#define RESETS_RESET_DONE_SET  (RESETS_BASE+0x8+0x2000)
#define RESETS_RESET_DONE_CLR  (RESETS_BASE+0x8+0x3000)

#define SIO_BASE                    0xD0000000

#define SIO_GPIO_OUT_RW             (SIO_BASE+0x10)
#define SIO_GPIO_OUT_SET            (SIO_BASE+0x14)
#define SIO_GPIO_OUT_CLR            (SIO_BASE+0x18)
#define SIO_GPIO_OUT_XOR            (SIO_BASE+0x1C)

#define SIO_GPIO_OE_RW              (SIO_BASE+0x20)
#define SIO_GPIO_OE_SET             (SIO_BASE+0x24)
#define SIO_GPIO_OE_CLR             (SIO_BASE+0x28)
#define SIO_GPIO_OE_XOR             (SIO_BASE+0x2C)

#define IO_BANK0_BASE               0x40014000

#define IO_BANK0_GPIO25_STATUS_RW   (IO_BANK0_BASE+0x0C8+0x0000)
#define IO_BANK0_GPIO25_STATUS_XOR  (IO_BANK0_BASE+0x0C8+0x1000)
#define IO_BANK0_GPIO25_STATUS_SET  (IO_BANK0_BASE+0x0C8+0x2000)
#define IO_BANK0_GPIO25_STATUS_CLR  (IO_BANK0_BASE+0x0C8+0x3000)

#define IO_BANK0_GPIO25_CTRL_RW     (IO_BANK0_BASE+0x0CC+0x0000)
#define IO_BANK0_GPIO25_CTRL_XOR    (IO_BANK0_BASE+0x0CC+0x1000)
#define IO_BANK0_GPIO25_CTRL_SET    (IO_BANK0_BASE+0x0CC+0x2000)
#define IO_BANK0_GPIO25_CTRL_CLR    (IO_BANK0_BASE+0x0CC+0x3000)


#define CLOCKS_BASE                 0x40008000


#define CLK_REF_CTRL_RW             (CLOCKS_BASE+0x30+0x0000)
#define CLK_REF_CTRL_XOR            (CLOCKS_BASE+0x30+0x1000)
#define CLK_REF_CTRL_SET            (CLOCKS_BASE+0x30+0x2000)
#define CLK_REF_CTRL_CLR            (CLOCKS_BASE+0x30+0x3000)

#define CLK_SYS_CTRL_RW             (CLOCKS_BASE+0x3C+0x0000)
#define CLK_SYS_CTRL_XOR            (CLOCKS_BASE+0x3C+0x1000)
#define CLK_SYS_CTRL_SET            (CLOCKS_BASE+0x3C+0x2000)
#define CLK_SYS_CTRL_CLR            (CLOCKS_BASE+0x3C+0x3000)



#define CLK_SYS_RESUS_CTRL_RW       (CLOCKS_BASE+0x78+0x0000)
#define CLK_SYS_RESUS_CTRL_XOR      (CLOCKS_BASE+0x78+0x1000)
#define CLK_SYS_RESUS_CTRL_SET      (CLOCKS_BASE+0x78+0x2000)
#define CLK_SYS_RESUS_CTRL_CLR      (CLOCKS_BASE+0x78+0x3000)


#define XOSC_BASE                   0x40024000

#define XOSC_CTRL_RW                (XOSC_BASE+0x00+0x0000)
#define XOSC_CTRL_XOR               (XOSC_BASE+0x00+0x1000)
#define XOSC_CTRL_SET               (XOSC_BASE+0x00+0x2000)
#define XOSC_CTRL_CLR               (XOSC_BASE+0x00+0x3000)

#define XOSC_STATUS_RW              (XOSC_BASE+0x04+0x0000)
#define XOSC_STATUS_XOR             (XOSC_BASE+0x04+0x1000)
#define XOSC_STATUS_SET             (XOSC_BASE+0x04+0x2000)
#define XOSC_STATUS_CLR             (XOSC_BASE+0x04+0x3000)

#define XOSC_STARTUP_RW             (XOSC_BASE+0x0C+0x0000)
#define XOSC_STARTUP_XOR            (XOSC_BASE+0x0C+0x1000)
#define XOSC_STARTUP_SET            (XOSC_BASE+0x0C+0x2000)
#define XOSC_STARTUP_CLR            (XOSC_BASE+0x0C+0x3000)

#define STK_CSR 0xE000E010
#define STK_RVR 0xE000E014
#define STK_CVR 0xE000E018

static void do_delay ( unsigned int x )
{
    unsigned int ra;

    for(ra=0;ra<x;)
    {
        if((GET32(STK_CSR)&(1<<16))!=0)
        {
            ra++;
        }
    }
}
static void clock_init ( void )
{
    PUT32(CLK_SYS_RESUS_CTRL_RW,0);
    //PUT32(CLK_REF_CTRL_RW,0);
    //PUT32(CLK_SYS_CTRL_RW,0);
    PUT32(XOSC_CTRL_RW,0xAA0);      //1 - 15MHZ
    PUT32(XOSC_STARTUP_RW,47);      //straight from the datasheet
    PUT32(XOSC_CTRL_SET,0xFAB000);  //enable
    while(1)
    {
        if((GET32(XOSC_STATUS_RW)&0x80000000)!=0) break;
    }
    PUT32(CLK_REF_CTRL_RW,2); //XOSC
    PUT32(CLK_SYS_CTRL_RW,0); //reset/clk_ref
}

int notmain ( void )
{
    unsigned int ra;

    clock_init();

    PUT32(RESETS_RESET_CLR,1<<5); //IO_BANK0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<5))!=0) break;
    }

    PUT32(SIO_GPIO_OE_CLR,1<<25);
    PUT32(SIO_GPIO_OUT_CLR,1<<25);
    PUT32(IO_BANK0_GPIO25_CTRL_RW,5); //SIO
    PUT32(SIO_GPIO_OE_SET,1<<25);

    PUT32(STK_CSR,0x00000004);
    PUT32(STK_RVR,12000000-1);
    PUT32(STK_CVR,12000000-1);
    PUT32(STK_CSR,0x00000005);

    for(ra=0;ra<100;ra++)
    {
        PUT32(SIO_GPIO_OUT_XOR,1<<25);
        do_delay(10);
    }

    return(0);
}

//-------------------------------------------------------------------------
//
// Copyright (c) 2021 David Welch dwelch@dwelch.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------
