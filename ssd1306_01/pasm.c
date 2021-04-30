
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pasm ( void );

static unsigned int pc;

static unsigned int labels;
static char have_label[32][64];
static char need_label[32][64];
static unsigned short inst[32];


//static const uint16_t squarewave_program_instructions[] = {
            ////     .wrap_target
    //0x80a0, //  0: pull   block
    //0x6001, //  1: out    pins, 1
    //0x0000, //  2: jmp    0
            ////     .wrap
//};



static void label ( char *s )
{
    strncpy(have_label[pc],s,63);
    //have_label[pc][63]=0;
}
static void jmp ( char *s )
{
    strncpy(need_label[pc],s,63);
    //need_label[pc][63]=0;
    if(pc>31) exit(1);
    inst[pc]=0<<13;
    pc++;
}
static void pull_block ( void )
{
    if(pc>31) exit(1);
    inst[pc]=4<<13;
    inst[pc]|=1<<7;
    inst[pc]|=1<<5;
    pc++;
}
static void set_pindirs ( unsigned int p )
{
    if(pc>31) exit(1);
    inst[pc]=7<<13;
    inst[pc]|=4<<5;
    inst[pc]|=(p&0x1F)<<0;
    pc++;
}
static void set_pins ( unsigned int p, unsigned int d )
{
    if(pc>31) exit(1);
    inst[pc]=7<<13;
    inst[pc]|=0<<5;
    inst[pc]|=(p&0x1F)<<0;
    inst[pc]|=(d&0x1F)<<8;
    pc++;
}
static void out_pins ( unsigned int p, unsigned int d )
{
    if(pc>31) exit(1);
    inst[pc]=3<<13;
    inst[pc]|=0<<5;
    inst[pc]|=(p&0x1F)<<0;
    inst[pc]|=(d&0x1F)<<8;
    pc++;
}

                ////     .wrap_target
    //0xe081, //  0: set    pindirs, 1
    //0xfe01, //  1: set    pins, 1                [30]
    //0xfd00, //  2: set    pins, 0                [29]
    //0x0001, //  3: jmp    1
            ////     .wrap

#include "pio.c"
int main ( void )
{
    unsigned int ra;
    unsigned int rb;

    pc=0;
    labels=0;
    memset(have_label,0x00,sizeof(have_label));
    memset(need_label,0x00,sizeof(need_label));
    pasm();


    printf("//pc %u\n",pc);
    for(ra=0;ra<pc;ra++)
    {
        if(have_label[ra][0])
        {
            printf("//have_label[%u] (%s)\n",ra,have_label[ra]);
        }
    }
    for(ra=0;ra<pc;ra++)
    {
        if(need_label[ra][0])
        {
            printf("//need_label[%u] (%s)\n",ra,need_label[ra]);
            for(rb=0;rb<pc;rb++)
            {
                if(strcmp(need_label[ra],have_label[rb])==0)
                {
                    inst[ra]|=rb;
                    break;
                }
            }
            if(rb<pc)
            {
            }
            else
            {
                fprintf(stderr,"label not found\n");
                //exit(1);
            }
        }
    }
    printf("\n\n");
    for(ra=0;ra<pc;ra++)
    {
        printf("PUT32(PIO0_INSTR_MEM%u_RW,0x%04X);\n",ra,inst[ra]);
    }
    printf("\n\n");
    return(0);
}


