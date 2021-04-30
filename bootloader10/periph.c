
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

#define PADS_BANK0_BASE             0x4001C000

#define PADS_BANK0_GPIO0_RW         (PADS_BANK0_BASE+0x04+0x0000)
#define PADS_BANK0_GPIO0_XOR        (PADS_BANK0_BASE+0x04+0x1000)
#define PADS_BANK0_GPIO0_SET        (PADS_BANK0_BASE+0x04+0x2000)
#define PADS_BANK0_GPIO0_CLR        (PADS_BANK0_BASE+0x04+0x3000)

#define PADS_BANK0_GPIO1_RW         (PADS_BANK0_BASE+0x08+0x0000)
#define PADS_BANK0_GPIO1_XOR        (PADS_BANK0_BASE+0x08+0x1000)
#define PADS_BANK0_GPIO1_SET        (PADS_BANK0_BASE+0x08+0x2000)
#define PADS_BANK0_GPIO1_CLR        (PADS_BANK0_BASE+0x08+0x3000)

#define PADS_BANK0_GPIO25_RW        (PADS_BANK0_BASE+0x68+0x0000)
#define PADS_BANK0_GPIO25_XOR       (PADS_BANK0_BASE+0x68+0x1000)
#define PADS_BANK0_GPIO25_SET       (PADS_BANK0_BASE+0x68+0x2000)
#define PADS_BANK0_GPIO25_CLR       (PADS_BANK0_BASE+0x68+0x3000)

#define IO_BANK0_BASE               0x40014000

#define IO_BANK0_GPIO0_CTRL_RW      (IO_BANK0_BASE+0x004+0x0000)
#define IO_BANK0_GPIO0_CTRL_XOR     (IO_BANK0_BASE+0x004+0x1000)
#define IO_BANK0_GPIO0_CTRL_SET     (IO_BANK0_BASE+0x004+0x2000)
#define IO_BANK0_GPIO0_CTRL_CLR     (IO_BANK0_BASE+0x004+0x3000)

#define IO_BANK0_GPIO1_CTRL_RW      (IO_BANK0_BASE+0x00C+0x0000)
#define IO_BANK0_GPIO1_CTRL_XOR     (IO_BANK0_BASE+0x00C+0x1000)
#define IO_BANK0_GPIO1_CTRL_SET     (IO_BANK0_BASE+0x00C+0x2000)
#define IO_BANK0_GPIO1_CTRL_CLR     (IO_BANK0_BASE+0x00C+0x3000)

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

#define CLK_PERI_CTRL_RW            (CLOCKS_BASE+0x48+0x0000)
#define CLK_PERI_CTRL_XOR           (CLOCKS_BASE+0x48+0x1000)
#define CLK_PERI_CTRL_SET           (CLOCKS_BASE+0x48+0x2000)
#define CLK_PERI_CTRL_CLR           (CLOCKS_BASE+0x48+0x3000)


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

#define UART0_BASE                  0x40034000

#define UART0_BASE_UARTDR_RW        (UART0_BASE+0x000+0x0000)
#define UART0_BASE_UARTFR_RW        (UART0_BASE+0x018+0x0000)
#define UART0_BASE_UARTIBRD_RW      (UART0_BASE+0x024+0x0000)
#define UART0_BASE_UARTFBRD_RW      (UART0_BASE+0x028+0x0000)
#define UART0_BASE_UARTLCR_H_RW     (UART0_BASE+0x02C+0x0000)
#define UART0_BASE_UARTCR_RW        (UART0_BASE+0x030+0x0000)

#define STK_CSR 0xE000E010
#define STK_RVR 0xE000E014
#define STK_CVR 0xE000E018

unsigned int uart_recv ( void )
{
    while(1)
    {
        if((GET32(UART0_BASE_UARTFR_RW)&(1<<4))==0) break;
    }
    return(GET32(UART0_BASE_UARTDR_RW));
}

void uart_send ( unsigned int x )
{
    while(1)
    {
        if((GET32(UART0_BASE_UARTFR_RW)&(1<<5))==0) break;
    }
    PUT32(UART0_BASE_UARTDR_RW,x);
}

void uart_flush ( void )
{
    while(1)
    {
        if((GET32(UART0_BASE_UARTFR_RW)&(1<<7))!=0) break;
    }
}


static void hexstrings ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_send(rc);
        if(rb==0) break;
    }
    uart_send(0x20);
}
void hexstring ( unsigned int d )
{
    hexstrings(d);
    uart_send(0x0D);
    uart_send(0x0A);
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

int uart_init ( void )
{
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
    PUT32(RESETS_RESET_CLR,(1<<22)); //UART0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<22))!=0) break;
    }

    //GPIO 0 UART0 TX function 2
    //GPIO 1 UART0 RX function 2

    //(12000000/(16/115200)) = 6.514
    //0.514*64 = 32.666
    PUT32(UART0_BASE_UARTIBRD_RW,6);
    PUT32(UART0_BASE_UARTFBRD_RW,33);
    //0 11 1 0 0 0 0
    //0111 0000
    PUT32(UART0_BASE_UARTLCR_H_RW,0x70);
    PUT32(UART0_BASE_UARTCR_RW,(1<<9)|(1<<8)|(1<<0));

    PUT32(IO_BANK0_GPIO0_CTRL_RW,2);    //UART
    PUT32(IO_BANK0_GPIO1_CTRL_RW,2);  //UART

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
