
This repository is a collection of bare metal (no operating system,
as well as no library/SDK in this case) examples for the 
Raspberry Pi Pico.

As of this writing:
https://www.raspberrypi.org/products/raspberry-pi-pico/

There are a number of documents that you will want to download

Raspberry Pi RP2040 datasheet
Raspberry Pi Pico datasheet
Getting started with Raspberry Pi Pico
and some others

This chip contains two cortex-m0+ cores from ARM (these are not 
"ARM chips" BTW they are "ARM based chips").  So you will also want

armv6-m Architectural Reference Manual (ARM ARM)
cortex-m0+ Technical Reference Manual (ARM TRM)

I avoid the programmers reference manual it creates as many problems
as it solves.

You can get started with one board as is, but you are going to want
to have two (or more, might as well get a handful an spread out
the shipping cost) so you can use one as a picoprobe.

You will need a GNU toolchain, see the file TOOLCHAIN

Most examples will use uf2 files.

https://github.com/microsoft/uf2

It is simple enough I have my own tool to create the uf2 files.

I wish they would at least put pads down for a reset button. The
reset (RUN) and GND are separated by a pin, so a commonly available
switch can easily be soldered in.  No need for glue. (see image)  

Press and hold bootsel press and release reset release bootsel.  Wait 
for the virtual thumb drive to mount.  Copy the uf2 file over and if 
all goes well the virtual thumb drive will disconnect.  If you do not 
have a reset button then press and hold bootsel unplug and replug the 
board from your usb cable and release bootsel.

Start with blinker00, no pins or jumper wires are needed.  The README
file in this example explains the basics of how the rp2040 boots.

The Raspberry Pi folks made a very wise decision to create firmware
that turns Pico into an SWD/UART debugger, along with openocd support.
See the zero example README.txt for more on this topic.  Some examples
are going to rely on the debugger.  I did try the picoprobe on a third
party cortex-m device and it did not work.  I did not try a non-
picoprobe SWD debugger on the Pico, based on comments made in the
documentation I expect that to work.  At this price it is best to
just get a picoprobe.  If the picoprobe worked on other cortex-ms
it would be the ideal debugger.
