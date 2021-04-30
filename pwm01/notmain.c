
void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void DELAY ( unsigned int );

#define RESETS_BASE                 0x4000C000

#define RESETS_RESET_RW        (RESETS_BASE+0x0+0x0000)
//#define RESETS_RESET_XOR       (RESETS_BASE+0x0+0x1000)
//#define RESETS_RESET_SET       (RESETS_BASE+0x0+0x2000)
#define RESETS_RESET_CLR       (RESETS_BASE+0x0+0x3000)

#define RESETS_RESET_DONE_RW   (RESETS_BASE+0x8+0x0000)


#define IO_BANK0_BASE               0x40014000

#define IO_BANK0_GPIO25_CTRL_RW     (IO_BANK0_BASE+0x0CC+0x0000)

#define PWM_BASE                    0x40050000

#define PWM_CH4_CSR_RW              (PWM_BASE+0x50+0x0000)
#define PWM_CH4_DIV_RW              (PWM_BASE+0x54+0x0000)
#define PWM_CH4_CTR_RW              (PWM_BASE+0x58+0x0000)
#define PWM_CH4_CC_RW               (PWM_BASE+0x5C+0x0000)
#define PWM_CH4_TOP_RW              (PWM_BASE+0x60+0x0000)

int notmain ( void )
{
    unsigned int rb;

    PUT32(RESETS_RESET_CLR,1<<5); //IO_BANK0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<5))!=0) break;
    }
    PUT32(RESETS_RESET_CLR,(1<<14)); //PWM
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<14))!=0) break;
    }
    PUT32(IO_BANK0_GPIO25_CTRL_RW,4); //PWM
    PUT32(PWM_CH4_CSR_RW,1);
    while(1)
    {
        for(rb=0x0000;rb<0x10000;rb++)
        {
            PUT32(PWM_CH4_CC_RW,rb<<16);
            DELAY(0x10);
        }
        for(rb--;rb;rb--)
        {
            PUT32(PWM_CH4_CC_RW,rb<<16);
            DELAY(0x10);
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
