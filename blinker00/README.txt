
This is the first example.

In true Broadcom fashion this is not your average microcontroller, if we
can even call it that.  There is no flash on the chip and the bootrom
burned into the chip is what the ARM cores always boot.  The bootrom
searches for a flash by copying the first 256 bytes to SRAM and uses
a crc32 to verify the data.  It repeats MANY times until it finds
something or fails (not all external flash chips are created equal).
If it does not find something that passes the crc then it boots into
the usb virtual drive as if the bootsel pin was asserted.

This leaves 252 bytes for the second stage bootloader.  I have not
discovered why the bootrom does not simply expose the detected flash,
but it appears the typical use case is our code needs to finish mapping
the flash into the typical 0x10000000 address space and then you decide
how you want to extract and use the flash, run it from there or copy
and jump.

This example lives within the 252 bytes.

The second stage bootloader needs to be position independent so that
it can run from SRAM.  The bootrom simply branches to the code in
SRAM, it does not support the notion of a vector table.

The UF2 file format consists of 512 byte chunks.  The typical use
case is to have 256 bytes of payload per chunk.  8 words of header
a word at the end, and the payload in the middle.  The typical
use case is to specify an address starting at 0x10000000 and to
have 0x100 bytes per chunk.  So the first chunk is going to have
the second stage bootloader and the second chunk if present at all
is up to you, along with the rest.

They support loading into ram as well so for example you can change

    wdata[3]=0x10000000;

to

    wdata[3]=0x20000000;

If loaded into ram it will run from ram but not be written to flash
it will be lost when power goes.  The documentation shows that you
can use most of the SRAM space and you do not have to start at
0x20000000.

I do not know what happens if you mix and match flash and ram.

To see this in action use the 0x10000000 address load it into the
board.  Power cycle or reset and confirm.  Change wdata[3] and the
DELAY values to be faster or slower, using bootsel load this SRAM based
program into the card and it will run in sram and blink at the new
rate.  A reset or power cycle will return it to the program on flash
blinking at the old rate.

The pico board has a LED attached to GPIO 25.  As with most
microcontrollers there is a reset and/or clocking solution to save
power.  Before you can talk to the IO block we have to release reset.

Also as with most microcontrollers the GPIO pins are multiplexed so
that particular pins can connect one of multiple internal peripherals.
The typical GPIO solution for generic manipulation of the pins is the
SIO or Software I/O peripheral (for this part).  After reset the pins
are not assigned a function.  For most GPIO pins function 5 will
connect the pin to SIO.

Not normally visible to programmers or not easly visible the external
pins of a device have I/O pads that among other things control input
and output and voltage levels.  You will often not see these as for
example if you connect to a UART the logic will enable the pad for
output for a TX pin and input for the RX pin.  We apparently have
direct control.  The I/O pads default to output not disabled (the
output enable is controled by the peripheral (SIO) not the pad, and
input enabled.  There is a pull up enabled on reset but that is okay
for this example as we are going to push/pull (drive the pin both
high and low, are not relying on a pull up nor pull down).  It does
not appear that we have to release reset on the PADS in order to use
the pins (only to talk to the pads registers I assume).

Lastly we talk to the SIO peripheral to enable the pin as an output
and then set the pin high and low to blink the led.  The DELAY function
simply counts down to zero to burh some time so we can visually see
the LED at one state or the other.

While the documentation is significantly better than the full sized
raspi docs.  And there has been considerable amount of work done to
provide developers with tools and source code.  I do have issues
with the documentation and the use of structs across compile domains
to access the peripherals, this is a dangerous and unwise solution that
has sadly become a FAD in the microcontroller community.  You have been
warned.  I have already found bugs in the documentation as well as
holes.

If you are not familiar with my programming style used in examples it
is designed to be easy to read and understand as well as to greatly
increase the chances of success in building and running successful
programs.  A noticeable percentage of people will run into what was
otherwise a survivable trap/failure and give up, some going so far
as to preach that bare metal and low level stuff is a waste of time
and has no value.  I have a list of reasons why I do the things I do
and you are welcome to choose another path.  This code is in no way
intended to be a library or skeleton.  It is intended to show that
you can be successful at working at this level.  That it does not
take 12000 bytes to blink an led on this platform.  And that you can
easily see the connection between the code and the hardware.

You are expected to go off and create your own style.  The greatest
thing about bare metal programming is freedom.  The authors of the SDK
and examples were free to chose a path as was I and as will you.  The
path I choose is to use an abstraction layer for access, very easy to
see the address being used, no magic, not hidden, straight out of the
datasheet (where available), in this use case I can control the
exact instruction being used.

Professionally you should be able work at each of these levels.  As of
this writing I am still not able to build the blinker example using
the documented instructions nor adding extra work.

You are expected to understand and basic C programming, there is no
ghee whiz code here that uses cool and fun features of the language.

Assembly language is not required, but a basic understanding is
crucial to continue at this level professionally if that is a path
you wish to choose.

The bootstrap code in start.s

    ldr r0,=0x20001000
    mov sp,r0
    bl notmain
    b .

Performs the minimum steps to bootstrap a C program.  I have taken
shortcuts for above mentioned reasons.  You might see me use .bss
later but not .data.

unsigned int x; //.bss assumed to be zero when the C code starts.
unsigned int y=5; //.data assumed to be 5 when the C code starts.

There is a reason for this and you can worry about that later, assume
that .bss is not zero and there is no .data.  Unless I do a copy and
jump to ram then we can make that work just like the full sized
Raspberry Pi's.

There are a few basic steps for a C bootstrap

- set the stack pointer
- initialize .bss as needed
- initialize .data as needed
- call main()

I am not going to do .bss nor .data, and it appears from other example
that you can use the stack pointer as setup by the bootrom so we dont
have to do that.  But I am for now.  And then I am not calling main
I am using a C entry point other than main() because toolchains
(including gnu) treat that function name specially and can add code
or do things special that otherwise they would not.  So to avoid the
toolchain thinking this is a non-bare metal program targetted at
an operating system the toolchain may be built and configured for we
are going to avoid that by using some other function name.

This is the linker script

MEMORY
{
    flash : ORIGIN = 0x10000000, LENGTH = 0xFC
}
SECTIONS
{
    .text   : { *(.text*)   } > flash
}

It could be made simpler, but this is just fine.  Folks tend to
grossly overcomplicate this.  See reasons above why you do not
see that here, this is in part why .bss and .data are not supported.
We are supposed to remain position independent so the base address
actually should not matter.  Both the linker script and the makeuf2
tool will check for 252 bytes.  If you have a version of gnu ld that
does not tell you how far over you went, you can make the length here
much larger to see how many bytes it does consume so that you can
then see how hard you have to work to reduce the size.

Some vendors do this and each has their own way of doing it but this
chip has a couple of ways to provide atomic operations which for
bit banging GPIO to blink an led are very useful.

#define RESETS_BASE_RESET_RW        (RESETS_BASE+0x0+0x0000)
#define RESETS_BASE_RESET_XOR       (RESETS_BASE+0x0+0x1000)
#define RESETS_BASE_RESET_SET       (RESETS_BASE+0x0+0x2000)
#define RESETS_BASE_RESET_CLR       (RESETS_BASE+0x0+0x3000)

#define SIO_GPIO_OUT_RW             (SIO_BASE+0x10)
#define SIO_GPIO_OUT_SET            (SIO_BASE+0x14)
#define SIO_GPIO_OUT_CLR            (SIO_BASE+0x18)
#define SIO_GPIO_OUT_XOR            (SIO_BASE+0x1C)

These are two schemes used to basically give four types of access to
the same control and status registers.  Some of the registers you
add

0x1000 for XOR meaning the bits written as a 1 will toggle the
    corresponding bit in the register
0x2000 for SET meaning the bits written as 1 will set the bit in the
    corresponding register.
0x3000 will CLeaR ...

For the SIO registers they chose another scheme (and this information
is in the databook).

Other examples will not re-visit these topics unless to expand them
to the next level.

run

make

(apt get install build-essential)

to create notmain.uf2

Examine the beginning of notmain.list

When you press and hold bootsel, reset or power cycle the board,
release bootsel.  Copy notmain.uf2 to the virtual drive that appears,
the program should be written to flash, the virtual drive disappears
and the led starts to blink.  Being in flash you can now unplug and
replug the board into power, not holding bootsel, and the program
will again run. Change the value in passed to the DELAY function calls
to change the blink rate.  And repeat and see that the new program
blinks at a different rate.

The pi folks have a program named flash_nuke.uf2 that you will probably
want to find.  Use the bootsel process to load this program it will
erase the flash and then blink the led.  Once done you will get
the virtual usb drive when you power on the board.  Most of the
examples are SRAM based and you ideally just want to have the flash
erased so you dont have to press and hold bootsel every time.  The
sram directory contains a matching example to this one but is sram
based and does not write to flash.
