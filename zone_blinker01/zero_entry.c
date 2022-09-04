
extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );

extern void SEV ( void );
extern void WFE ( void );

#define SIO_BASE                    0xD0000000

#define SIO_FIFO_ST                 (SIO_BASE+0x50)
#define SIO_FIFO_WR                 (SIO_BASE+0x54)
#define SIO_FIFO_RD                 (SIO_BASE+0x58)

static void fifo_flush ( void )
{
    while(1)
    {
        if((GET32(SIO_FIFO_ST)&0x1) == 0) break; //zero if empty
        GET32(SIO_FIFO_RD);
    }
    SEV();
}

static unsigned int fifo_send ( unsigned int cmd )
{
    while(1)
    {
        if((GET32(SIO_FIFO_ST)&0x2) != 0) break; //one if ready
    }
    PUT32(SIO_FIFO_WR,cmd);
    SEV();
    while(1)
    {
        if((GET32(SIO_FIFO_ST)&0x1) == 0) //zero if  empty
        {
            WFE();
        }
        else
        {
            break;
        }
    }
    return(GET32(SIO_FIFO_RD));
}

extern unsigned int stack_zero;

unsigned int zero_entry ( void )
{
    unsigned int ra;

    while(1)
    {
        fifo_flush();
        ra=fifo_send(0);
        if(ra!=0) continue;
        fifo_flush();
        ra=fifo_send(0);
        if(ra!=0) continue;
        ra=fifo_send(1);
        if(ra!=1) continue;
        ra=fifo_send(0x20000000); //vector_table
        if(ra!=0x20000000) continue;
        ra=fifo_send(0x20003000);    //stack pointer
        if(ra!=0x20003000) continue;
        ra=fifo_send(0x20000001);    //entry
        if(ra!=0x20000001) continue;
        break;
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
