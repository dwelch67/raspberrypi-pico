
I am still struggling with this one.  I cannot consistently figure out
how to get it to work on power up.

The bootrom copies the first 256 bytes from flash to ram and runs it.
This is the stage two bootloader.  For flash based applications this
second stage bootloader needs to turn ARM accesses into spi reads
(why didnt they just have the bootrom do this???).

My preference is to copy the application from flash to ram and
then execute (the rest of) it there.


XIP/SPI setup

    ldr r0,=0x18000008
    ldr r1,=0x00000000
    str r1,[r0]

    ldr r0,=0x18000014
    ldr r1,=0x00000008
    str r1,[r0]

    ldr r0,=0x18000000
    ldr r1,=0x001F0300
    str r1,[r0]

    ldr r0,=0x180000F4
    ldr r1,=0x03000218
    str r1,[r0]

    ldr r0,=0x18000004
    ldr r0,=0x00000000
    str r1, [r0]

    ldr r0,=0x18000008
    ldr r1,=0x00000001
    str r1,[r0]

    ldr r0,=0x10000000
    ldr r1,=0x20000000
    ldr r2,=0x400

copy flash to ram

copy_loop:
    ldr r3,[r0]
    str r3,[r1]
    add r0,#0x4
    add r1,#0x4
    sub r2,#1
    bne copy_loop

branch to the rest of the program in sram.

    ldr r0,=0x20000101
    bx r0

Otherwise this is the blinker01 example.

