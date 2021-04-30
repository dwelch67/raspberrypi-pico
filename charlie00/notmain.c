

void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void DELAY ( unsigned int );

#define RESETS_BASE                 0x4000C000

//#define RESETS_RESET_RW        (RESETS_BASE+0x0+0x0000)
//#define RESETS_RESET_XOR       (RESETS_BASE+0x0+0x1000)
//#define RESETS_RESET_SET       (RESETS_BASE+0x0+0x2000)
#define RESETS_RESET_CLR       (RESETS_BASE+0x0+0x3000)

#define RESETS_RESET_DONE_RW   (RESETS_BASE+0x8+0x0000)
//#define RESETS_RESET_DONE_XOR  (RESETS_BASE+0x8+0x1000)
//#define RESETS_RESET_DONE_SET  (RESETS_BASE+0x8+0x2000)
//#define RESETS_RESET_DONE_CLR  (RESETS_BASE+0x8+0x3000)


#define CLOCKS_BASE                 0x40008000

#define CLK_REF_CTRL_RW             (CLOCKS_BASE+0x30+0x0000)
//#define CLK_REF_CTRL_XOR            (CLOCKS_BASE+0x30+0x1000)
//#define CLK_REF_CTRL_SET            (CLOCKS_BASE+0x30+0x2000)
//#define CLK_REF_CTRL_CLR            (CLOCKS_BASE+0x30+0x3000)

#define CLK_SYS_CTRL_RW             (CLOCKS_BASE+0x3C+0x0000)
//#define CLK_SYS_CTRL_XOR            (CLOCKS_BASE+0x3C+0x1000)
//#define CLK_SYS_CTRL_SET            (CLOCKS_BASE+0x3C+0x2000)
//#define CLK_SYS_CTRL_CLR            (CLOCKS_BASE+0x3C+0x3000)

#define CLK_PERI_CTRL_RW            (CLOCKS_BASE+0x48+0x0000)
//#define CLK_PERI_CTRL_XOR           (CLOCKS_BASE+0x48+0x1000)
//#define CLK_PERI_CTRL_SET           (CLOCKS_BASE+0x48+0x2000)
//#define CLK_PERI_CTRL_CLR           (CLOCKS_BASE+0x48+0x3000)

#define CLK_SYS_RESUS_CTRL_RW       (CLOCKS_BASE+0x78+0x0000)
//#define CLK_SYS_RESUS_CTRL_XOR      (CLOCKS_BASE+0x78+0x1000)
//#define CLK_SYS_RESUS_CTRL_SET      (CLOCKS_BASE+0x78+0x2000)
//#define CLK_SYS_RESUS_CTRL_CLR      (CLOCKS_BASE+0x78+0x3000)


#define SIO_BASE                    0xD0000000

//#define SIO_GPIO_OUT_RW             (SIO_BASE+0x10)
//#define SIO_GPIO_OUT_SET            (SIO_BASE+0x14)
#define SIO_GPIO_OUT_CLR            (SIO_BASE+0x18)
//#define SIO_GPIO_OUT_XOR            (SIO_BASE+0x1C)

//#define SIO_GPIO_OE_RW              (SIO_BASE+0x20)
#define SIO_GPIO_OE_SET             (SIO_BASE+0x24)
#define SIO_GPIO_OE_CLR             (SIO_BASE+0x28)
//#define SIO_GPIO_OE_XOR             (SIO_BASE+0x2C)


#define PADS_BANK0_BASE             0x4001C000

//#define PADS_BANK0_GPIO00_RW         (PADS_BANK0_BASE+0x04+0x0000)
//#define PADS_BANK0_GPIO00_XOR        (PADS_BANK0_BASE+0x04+0x1000)
//#define PADS_BANK0_GPIO00_SET        (PADS_BANK0_BASE+0x04+0x2000)
//#define PADS_BANK0_GPIO00_CLR        (PADS_BANK0_BASE+0x04+0x3000)

//#define PADS_BANK0_GPIO01_RW         (PADS_BANK0_BASE+0x08+0x0000)
//#define PADS_BANK0_GPIO01_XOR        (PADS_BANK0_BASE+0x08+0x1000)
//#define PADS_BANK0_GPIO01_SET        (PADS_BANK0_BASE+0x08+0x2000)
//#define PADS_BANK0_GPIO01_CLR        (PADS_BANK0_BASE+0x08+0x3000)

#define PADS_BANK0_GPIO02_RW         (PADS_BANK0_BASE+0x0C+0x0000)
#define PADS_BANK0_GPIO02_XOR        (PADS_BANK0_BASE+0x0C+0x1000)
//#define PADS_BANK0_GPIO02_SET        (PADS_BANK0_BASE+0x0C+0x2000)
//#define PADS_BANK0_GPIO02_CLR        (PADS_BANK0_BASE+0x0C+0x3000)

#define PADS_BANK0_GPIO03_RW         (PADS_BANK0_BASE+0x10+0x0000)
#define PADS_BANK0_GPIO03_XOR        (PADS_BANK0_BASE+0x10+0x1000)
//#define PADS_BANK0_GPIO03_SET        (PADS_BANK0_BASE+0x10+0x2000)
//#define PADS_BANK0_GPIO03_CLR        (PADS_BANK0_BASE+0x10+0x3000)

#define PADS_BANK0_GPIO04_RW         (PADS_BANK0_BASE+0x14+0x0000)
#define PADS_BANK0_GPIO04_XOR        (PADS_BANK0_BASE+0x14+0x1000)
//#define PADS_BANK0_GPIO04_SET        (PADS_BANK0_BASE+0x14+0x2000)
//#define PADS_BANK0_GPIO04_CLR        (PADS_BANK0_BASE+0x14+0x3000)

#define PADS_BANK0_GPIO05_RW         (PADS_BANK0_BASE+0x18+0x0000)
#define PADS_BANK0_GPIO05_XOR        (PADS_BANK0_BASE+0x18+0x1000)
//#define PADS_BANK0_GPIO05_SET        (PADS_BANK0_BASE+0x18+0x2000)
//#define PADS_BANK0_GPIO05_CLR        (PADS_BANK0_BASE+0x18+0x3000)

#define PADS_BANK0_GPIO06_RW         (PADS_BANK0_BASE+0x1C+0x0000)
#define PADS_BANK0_GPIO06_XOR        (PADS_BANK0_BASE+0x1C+0x1000)
//#define PADS_BANK0_GPIO05_SET        (PADS_BANK0_BASE+0x18+0x2000)
//#define PADS_BANK0_GPIO05_CLR        (PADS_BANK0_BASE+0x18+0x3000)

//#define PADS_BANK0_GPIO25_RW        (PADS_BANK0_BASE+0x68+0x0000)
//#define PADS_BANK0_GPIO25_XOR       (PADS_BANK0_BASE+0x68+0x1000)
//#define PADS_BANK0_GPIO25_SET       (PADS_BANK0_BASE+0x68+0x2000)
//#define PADS_BANK0_GPIO25_CLR       (PADS_BANK0_BASE+0x68+0x3000)


#define XOSC_BASE                   0x40024000

#define XOSC_CTRL_RW                (XOSC_BASE+0x00+0x0000)
//#define XOSC_CTRL_XOR               (XOSC_BASE+0x00+0x1000)
#define XOSC_CTRL_SET               (XOSC_BASE+0x00+0x2000)
//#define XOSC_CTRL_CLR               (XOSC_BASE+0x00+0x3000)

#define XOSC_STATUS_RW              (XOSC_BASE+0x04+0x0000)
//#define XOSC_STATUS_XOR             (XOSC_BASE+0x04+0x1000)
//#define XOSC_STATUS_SET             (XOSC_BASE+0x04+0x2000)
//#define XOSC_STATUS_CLR             (XOSC_BASE+0x04+0x3000)

#define XOSC_STARTUP_RW             (XOSC_BASE+0x0C+0x0000)
//#define XOSC_STARTUP_XOR            (XOSC_BASE+0x0C+0x1000)
//#define XOSC_STARTUP_SET            (XOSC_BASE+0x0C+0x2000)
//#define XOSC_STARTUP_CLR            (XOSC_BASE+0x0C+0x3000)


#define IO_BANK0_BASE               0x40014000

//#define IO_BANK0_GPIO0_CTRL_RW      (IO_BANK0_BASE+0x004+0x0000)
//#define IO_BANK0_GPIO0_CTRL_XOR     (IO_BANK0_BASE+0x004+0x1000)
//#define IO_BANK0_GPIO0_CTRL_SET     (IO_BANK0_BASE+0x004+0x2000)
//#define IO_BANK0_GPIO0_CTRL_CLR     (IO_BANK0_BASE+0x004+0x3000)

//#define IO_BANK0_GPIO1_CTRL_RW      (IO_BANK0_BASE+0x00C+0x0000)
//#define IO_BANK0_GPIO1_CTRL_XOR     (IO_BANK0_BASE+0x00C+0x1000)
//#define IO_BANK0_GPIO1_CTRL_SET     (IO_BANK0_BASE+0x00C+0x2000)
//#define IO_BANK0_GPIO1_CTRL_CLR     (IO_BANK0_BASE+0x00C+0x3000)

#define IO_BANK0_GPIO02_CTRL_RW      (IO_BANK0_BASE+0x014+0x0000)

#define IO_BANK0_GPIO03_CTRL_RW      (IO_BANK0_BASE+0x01C+0x0000)

#define IO_BANK0_GPIO04_CTRL_RW      (IO_BANK0_BASE+0x024+0x0000)

#define IO_BANK0_GPIO05_CTRL_RW      (IO_BANK0_BASE+0x02C+0x0000)

#define IO_BANK0_GPIO06_CTRL_RW      (IO_BANK0_BASE+0x034+0x0000)

//#define IO_BANK0_GPIO25_STATUS_RW   (IO_BANK0_BASE+0x0C8+0x0000)
//#define IO_BANK0_GPIO25_STATUS_XOR  (IO_BANK0_BASE+0x0C8+0x1000)
//#define IO_BANK0_GPIO25_STATUS_SET  (IO_BANK0_BASE+0x0C8+0x2000)
//#define IO_BANK0_GPIO25_STATUS_CLR  (IO_BANK0_BASE+0x0C8+0x3000)

//#define IO_BANK0_GPIO25_CTRL_RW     (IO_BANK0_BASE+0x0CC+0x0000)
//#define IO_BANK0_GPIO25_CTRL_XOR    (IO_BANK0_BASE+0x0CC+0x1000)
//#define IO_BANK0_GPIO25_CTRL_SET    (IO_BANK0_BASE+0x0CC+0x2000)
//#define IO_BANK0_GPIO25_CTRL_CLR    (IO_BANK0_BASE+0x0CC+0x3000)

#define PIO0_BASE                   0x50200000

#define PIO0_CTRL_RW                (PIO0_BASE+0x000+0x0000)
#define PIO0_FSTAT_RW               (PIO0_BASE+0x004+0x0000)
#define PIO0_TXF0_RW                (PIO0_BASE+0x010+0x0000)

#define PIO0_INSTR_MEM0_RW          (PIO0_BASE+0x048+0x0000)
#define PIO0_INSTR_MEM1_RW          (PIO0_BASE+0x04C+0x0000)

#define PIO0_INSTR_MEM2_RW          (PIO0_BASE+0x050+0x0000)
#define PIO0_INSTR_MEM3_RW          (PIO0_BASE+0x054+0x0000)
#define PIO0_INSTR_MEM4_RW          (PIO0_BASE+0x058+0x0000)
#define PIO0_INSTR_MEM5_RW          (PIO0_BASE+0x05C+0x0000)

#define PIO0_INSTR_MEM6_RW          (PIO0_BASE+0x060+0x0000)
#define PIO0_INSTR_MEM7_RW          (PIO0_BASE+0x064+0x0000)
#define PIO0_INSTR_MEM8_RW          (PIO0_BASE+0x068+0x0000)
#define PIO0_INSTR_MEM9_RW          (PIO0_BASE+0x06C+0x0000)

#define PIO0_INSTR_MEM10_RW         (PIO0_BASE+0x070+0x0000)
#define PIO0_INSTR_MEM11_RW         (PIO0_BASE+0x074+0x0000)
#define PIO0_INSTR_MEM12_RW         (PIO0_BASE+0x078+0x0000)
#define PIO0_INSTR_MEM13_RW         (PIO0_BASE+0x07C+0x0000)

#define PIO0_INSTR_MEM14_RW         (PIO0_BASE+0x080+0x0000)
#define PIO0_INSTR_MEM15_RW         (PIO0_BASE+0x084+0x0000)
#define PIO0_INSTR_MEM16_RW         (PIO0_BASE+0x088+0x0000)
#define PIO0_INSTR_MEM17_RW         (PIO0_BASE+0x08C+0x0000)

#define PIO0_INSTR_MEM18_RW         (PIO0_BASE+0x090+0x0000)
#define PIO0_INSTR_MEM19_RW         (PIO0_BASE+0x094+0x0000)
#define PIO0_INSTR_MEM20_RW         (PIO0_BASE+0x098+0x0000)
#define PIO0_INSTR_MEM21_RW         (PIO0_BASE+0x09C+0x0000)

#define PIO0_SM0_CLKDIV_RW          (PIO0_BASE+0x0C8+0x0000)
//#define PIO0_SM0_EXECCTRL_RW        (PIO0_BASE+0x0CC+0x0000)
//#define PIO0_SM0_EXECCTRL_SET       (PIO0_BASE+0x0CC+0x2000)
#define PIO0_SM0_SHIFTCTRL_RW       (PIO0_BASE+0x0D0+0x0000)
#define PIO0_SM0_PINCTRL_RW         (PIO0_BASE+0x0DC+0x0000)


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

unsigned int delay;
unsigned int updn;
static void doit ( unsigned int m, unsigned int d )
{
    PUT32(PIO0_TXF0_RW,0);
    PUT32(PIO0_TXF0_RW,m);
    PUT32(PIO0_TXF0_RW,d);
    DELAY(delay);
    if(updn)
    {
        delay+=0x40;
        if(delay>=0x10000)
        {
            delay=0x10000;
            updn=0;
        }
    }
    else
    {
        delay-=0x40;
        if(delay<=0x40)
        {
            delay=0x40;
            updn=1;
        }
    }
}


unsigned int notmain ( void )
{
    unsigned int ra;
    unsigned int rb;

    clock_init();

    PUT32(CLK_PERI_CTRL_RW,(1<<11)|(4<<5));

    PUT32(RESETS_RESET_CLR,(1<<5)); //IO_BANK0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<5))!=0) break;
    }
    PUT32(RESETS_RESET_CLR,(1<<8)); //PADS_BANK0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<8))!=0) break;
    }
    PUT32(RESETS_RESET_CLR,(1<<10)); //PIO0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<10))!=0) break;
    }

//static const uint16_t pio_program_instructions[] = {
            ////     .wrap_target
    //0x80a0, //  0: pull   block
    //0x6005, //  1: out    pins, 5
    //0x80a0, //  2: pull   block
    //0x6085, //  3: out    pindirs, 5
    //0x80a0, //  4: pull   block
    //0x6005, //  5: out    pins, 5
    //0x0000, //  6: jmp    0
            ////     .wrap
//};



PUT32(PIO0_INSTR_MEM0_RW,0x80a0);
PUT32(PIO0_INSTR_MEM1_RW,0x6005);
PUT32(PIO0_INSTR_MEM2_RW,0x80a0);
PUT32(PIO0_INSTR_MEM3_RW,0x6085);
PUT32(PIO0_INSTR_MEM4_RW,0x80a0);
PUT32(PIO0_INSTR_MEM5_RW,0x6005);
PUT32(PIO0_INSTR_MEM6_RW,0x0000);

    PUT32(PIO0_SM0_CLKDIV_RW,0x00010000);

    PUT32(PIO0_SM0_PINCTRL_RW,(5<<26)|(2<<5)|(5<<20)|(2<<0));

    PUT32(PADS_BANK0_GPIO02_RW,0x50);
    PUT32(IO_BANK0_GPIO02_CTRL_RW,6); //PIO

    PUT32(PADS_BANK0_GPIO03_RW,0x50);
    PUT32(IO_BANK0_GPIO03_CTRL_RW,6); //PIO

    PUT32(PADS_BANK0_GPIO04_RW,0x50);
    PUT32(IO_BANK0_GPIO04_CTRL_RW,6); //PIO

    PUT32(PADS_BANK0_GPIO05_RW,0x50);
    PUT32(IO_BANK0_GPIO05_CTRL_RW,6); //PIO

    PUT32(PADS_BANK0_GPIO06_RW,0x50);
    PUT32(IO_BANK0_GPIO06_CTRL_RW,6); //PIO

    PUT32(PIO0_CTRL_RW,1<<0);

    delay=0x10000;
    updn=0;

    while(1)
    {
        for(ra=0;ra<5;ra++)
        {
            for(rb=0;rb<5;rb++)
            {
                if(rb==ra) continue;
                doit((1<<ra)|(1<<rb),1<<ra);
                doit((1<<ra)|(1<<rb),1<<rb);
            }
        }
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

