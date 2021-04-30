
extern void PUT8 ( unsigned int, unsigned int );
extern unsigned int GETPC ( void );
extern void BRANCHTO ( unsigned int );

extern void uart_init ( void );
extern void uart_send ( unsigned int );
extern unsigned int uart_recv ( void );
extern void hexstring ( unsigned int );
extern void uart_flush ( void );

static unsigned int ctonib ( unsigned int c )
{
    if(c>0x39) c-=7;
    return(c&0xF);
}

int notmain ( void )
{
    unsigned int state;
    unsigned int ra;
    unsigned int type;
    unsigned int count;
    unsigned int sum;
    unsigned int entry;
    unsigned int addr;
    unsigned int data;

    uart_init();
    hexstring(0x12345678);
    hexstring(GETPC());
    uart_send(0x0D);
    uart_send(0x0A);
    uart_send('S');
    uart_send('R');
    uart_send('E');
    uart_send('C');
    uart_send(0x0D);
    uart_send(0x0A);

    data=0;
    state=0;
    count=0;
    sum=0;
    addr=0;
    type=0;
    entry=0x20000000;
    while(1)
    {
        ra=uart_recv();
        switch(state)
        {
            case 0:
            {
                if(ra=='S')
                {
                    sum=0;
                    state++;
                }
                if((ra=='g')||(ra=='G'))
                {
                    hexstring(entry);
                    uart_flush();
                    BRANCHTO(entry|1);
                }
                break;
            }
            case 1:
            {
                switch(ra)
                {
                    case '0':
                    {
                        state=0;
                        break;
                    }
                    case '3':
                    {
                        type=3;
                        state++;
                        break;
                    }
                    case '7':
                    {
                        type=7;
                        state++;
                        break;
                    }
                    default:
                    {
                        hexstring(ra);
                        hexstring(0xBADBAD00);
                        return(1);
                    }
                }
                break;
            }

            case 2:
            {
                count=ctonib(ra);
                state++;
                break;
            }
            case 3:
            {
                count<<=4;
                count|=ctonib(ra);
                if(count<5)
                {
                    hexstring(0xBADBAD01);
                    return(1);
                }
                sum+=count&0xFF;
                addr=0;
                state++;
                break;
            }
            case  4:
            case  6:
            case  8:
            case 10:
            {
                addr<<=4;
                addr|=ctonib(ra);
                state++;
                break;
            }
            case  5:
            case  7:
            case  9:
            {
                count--;
                addr<<=4;
                addr|=ctonib(ra);
                sum+=addr&0xFF;
                state++;
                break;
            }
            case 11:
            {
                count--;
                addr<<=4;
                addr|=ctonib(ra);
                sum+=addr&0xFF;
                state++;
                break;
            }
            case 12:
            {
                data=ctonib(ra);
                state++;
                break;
            }
            case 13:
            {
                data<<=4;
                data|=ctonib(ra);
                sum+=data&0xFF;
                count--;
                if(count==0)
                {
                    if(type==7)
                    {
                        entry=addr;
                    }
                    sum&=0xFF;
                    if(sum!=0xFF)
                    {
                        hexstring(0xBADBAD02);
                        return(1);
                    }
                    state=0;
                }
                else
                {
                    PUT8(addr,data);
                    addr++;
                    state=12;
                }
                break;
            }
        }

    }
    return(0);
}

//-------------------------------------------------------------------------
//
// Copyright (c) 2014 David Welch dwelch@dwelch.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------
