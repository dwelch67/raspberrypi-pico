
As with most this was a learning example, I wanted to figure out how
to do two things one was wiggle more than one pin at a time and
how to use out without set to enable the outputs.

Turns out I did not need to do this:

    ra=GET32(PADS_BANK0_GPIO05_RW);
    ra^=0x40; //if input disabled then enable
    ra&=0xC0; //if output disabled then enable
    PUT32(PADS_BANK0_GPIO05_XOR,ra);

They come out of reset ready to use. The output enables are left to the
selected function.  And there is a pull down enabled which I dont care
about normally, but did mess with as well.

It was not necessarily by designed but the scope plots will all pretty
much look the same. gp2 and gp3 are connected to the scope.

scope1.png

.program pio
    set pindirs, 0x3
loop:
    set pins, 0x0 [1]
    set pins, 0x1 [1]
    set pins, 0x2 [1]
    set pins, 0x3
    jmp loop


static const uint16_t pio_program_instructions[] = {
            //     .wrap_target
    0xe083, //  0: set    pindirs, 3
    0xe100, //  1: set    pins, 0                [1]
    0xe101, //  2: set    pins, 1                [1]
    0xe102, //  3: set    pins, 2                [1]
    0xe003, //  4: set    pins, 3
    0x0001, //  5: jmp    1
            //     .wrap
};


PUT32(PIO0_INSTR_MEM0_RW,0xe083);
PUT32(PIO0_INSTR_MEM1_RW,0xe100);
PUT32(PIO0_INSTR_MEM2_RW,0xe101);
PUT32(PIO0_INSTR_MEM3_RW,0xe102);
PUT32(PIO0_INSTR_MEM4_RW,0xe003);
PUT32(PIO0_INSTR_MEM5_RW,0x0001);

    PUT32(PIO0_SM0_PINCTRL_RW,(4<<26)|(2<<5)

This says 4 pins starting at gpio2 so gp2,3,4,5 (only using two of them)

.program pio
    set pindirs, 0x3  make both pins outputs (gp2 and gp3)
loop:
    set pins, 0x0 [1]    make the pins zeros
    set pins, 0x1 [1]    make gp2 on gp3 off
    set pins, 0x2 [1]    make gp2 off gp3 on
    set pins, 0x3        make both on
    jmp loop



scope2.png

.program pio
    set pindirs, 0x3
loop:
    pull block
    out pins, 2
    jmp loop

static const uint16_t pio_program_instructions[] = {
            //     .wrap_target
    0xe083, //  0: set    pindirs, 3
    0x80a0, //  1: pull   block
    0x6002, //  2: out    pins, 2
    0x0001, //  3: jmp    1
            //     .wrap
};

PUT32(PIO0_INSTR_MEM0_RW,0xe083);
PUT32(PIO0_INSTR_MEM1_RW,0x80a0);
PUT32(PIO0_INSTR_MEM2_RW,0x6002);
PUT32(PIO0_INSTR_MEM3_RW,0x0001);

    PUT32(PIO0_SM0_PINCTRL_RW,(4<<26)|(2<<5)|(4<<20)|(2<<0));

both set and out enabling 4 pins starting at pin 2
(only watching gp2 and gp3 on the scope)

    while(1)
    {
        for(rb=0;;rb++)
        {
            while(1)
            {
                if((GET32(PIO0_FSTAT_RW)&(1<<(16+0)))==0) break;
            }
            PUT32(PIO0_TXF0_RW,rb);
        }
    }

.program pio
    set pindirs, 0x3    can use set as an easy way to enable output
loop:
    pull block          wait for (block) and pull a word from the fifo
    out pins, 2         take two bits out of the shifter and apply them to gp2 and 3
    jmp loop

So I was curious here to see if the pins changed at the same time or
if they were shifted into each clock.  They change at the same time which
is what I was hoping for.



scope3.png

.program pio
    set pins, 3
loop:
    pull block
    out pindirs, 2
    jmp loop

PUT32(PIO0_INSTR_MEM0_RW,0xe003);
PUT32(PIO0_INSTR_MEM1_RW,0x80a0);
PUT32(PIO0_INSTR_MEM2_RW,0x6082);
PUT32(PIO0_INSTR_MEM3_RW,0x0001);

    PUT32(PIO0_SM0_PINCTRL_RW,(4<<26)|(2<<5)|(4<<20)|(2<<0));


    while(1)
    {
        for(rb=0;;rb++)
        {
            while(1)
            {
                if((GET32(PIO0_FSTAT_RW)&(1<<(16+0)))==0) break;
            }
            PUT32(PIO0_TXF0_RW,rb);
        }
    }

.program pio
    set pins, 3     make the outputs high, but not yet enabled
loop:
    pull block
    out pindirs, 2  write these to the output direction
    jmp loop

So this one messes with the output direction control rather than outputs
the PADS set for pull down affect this, if you set them for pull up
it will pull up and just be flat lines.  And if you put neither pull up
or pull down it would still drop on the scope but the corner was rounded
indicating it floated there or very weakly pulled.
