
This is the second example.  This example demonstrates using the
picoprobe

As documented in blinker00 (and in the rp2040 datasheet) the bootrom
copies 256 bytes of which 252 are up to use to use to SRAM5, checks
the crc32 if it passes it branches to this code.  This is the second
stage bootloader.

They have created firmware to allow a Pico to be used as a debugger
for other Pico boards.  This example demonstrates this.  If you have
not soldered pins on your Pico boards this would be a good time,
there are other solutions for wiring boards together that do not
involve solder, you will need to solve this.  I buy 40 pin sticks from
sparkfun as their price is pretty good, one will cover the outer pins
then three more for the SWD pins at the end of the board.

I use a hakko soldering iron the weller choices are equally good,
for $100 you can get a good iron.  Pins are pretty easy to solder and
are a good first thing to learn how to do.  You will want some small
wire cutters to cut the plastic on the breakaway pins.  You will need
solder of course and some wick.  Cut at least one side worth of pins
to length, choose which way you want them pointing, I put a reset
button on the bottom (flat side with no components) so the pins
are pointing up on the component side.  Often I will put the pins
pointing out on the side with the pin names, but not in this case.
Put the pins in the board and point them down with the board on top
solder one pin somewhere in the middle of the row.  Put the solder
down and hold the board with that hand with the pins vertical from
your work surface (something that can handle the heat a soldering 
mask or some scrap wood or something).  Gently pressing down on the
board melt the solder for that pin, very gently move the board so that
it is horizontal with the pins being vertical, from the top you can
to some extent see that they are close to vertical.  Remove the iron
from the pin WAIT a second for the solder to cool and harden.  Now
look to see if the plastic is flush to the board on the other side
and the pins are at a 90 degree angle or if you want them angled out a
little do that.  Once you have the row positioned per your preference
based on this one pin.  Then you can easily go up and down the row
and finish them.  Repeat for the other three rows.  If you end up
having the pins fall out and you have a hole with solder in it note
that you may need to ADD solder to that hole in order to get the wick
to suck it out.  Ideally heat it up and suck it out in one try, you
may have to try to push the wick down in or the tip through the 
wick into the hole.  You can easily, EASILY, damage the pad/hole
if you are not careful.  Do not try to pull wick up if it is sticking
to the board, reapply heat, watch the solder in/on the wick to melt
and then lift the wick gently with the iron.  Never slide wick side
to side, up and down never side to side.

(if you cut all the pins first, and have a spare, unsoldered Pico
board, you can put the pins in both boards, (have to do the three
on the end too) and this does a good job of aligning the pins so you
dont have to adjust, you should still start in the middle and insure
the row is flush before finishing the row)(there are other variations
on this theme).  

I buy and use the bent tips instead of the straight, you can much
more easily lay the tip flat on the board touching the pad and the pin
then touch the solder to the pad, pin, and iron at the same time
and it melts and flows right in.  I find this much easier than a
straight tip.  YMMV.

I have also chosen to put a reset button between RUN and GND on my
boards, this so far eliminates the need to unplug and replug the
usb on the board.  I have found some exceptions where I did have to
power cycle the board.  I assume in that case I pissed off the spi flash
which from my professional experience happens...I cannot confirm this
but the reset button has been invaluable for the history of the pi
boards.

Adding a button is pretty simple you can get these buttons for 
pennies when bought from asia on ebay, although I have been burned
too many times on ebay now that I buy almost nothing from overseas.
I leave either the RUN or GND unsoldered, with tweezers move the switch
into place, careful not to have the body touch the pin in between.
Melt the solder on the pin with solder (RUN or GND) and stick one leg
in.  Then the other leg is in place and can solder the other pin and
that leg at the same time.  Let it cool for a second and go back to
the first leg and add a little soder to that pin/leg combination.  Note
you need to be sure how the switch works otherwise you might end up
shorting the reset through the switch and it will always be in reset
and the board will not work until you remove at least one leg of the
switch.

I did NOT wire my boards together like they show in the documentation
I chose to power each of the boards via usb not share power.  This
leaves the three minimum connections and five total if/when we get
to UART.  I use pins with female to female jumper wires that you can
get from Sparkfun or Adafruit or various Ebay vendors.  YMMV

picoprobe ->  target mcu

GP2 -> SWCLK
GP3 -> SWDIO
GND -> GND (I used the GND pins between the SWD pins on both boards)

So far this has not damaged either board, you should definitely 
power both boards from the same computer/hub/etc. YMMV.

At the time of this writing these are the steps from the documentation
to get and install openocd with picoprobe support.

cd
mkdir pico
cd pico
sudo apt install automake autoconf build-essential texinfo libtool libftdi-dev libusb-1.0-0-dev
git clone https://github.com/raspberrypi/openocd.git --branch picoprobe --depth=1
cd openocd
./bootstrap
./configure --enable-picoprobe
make -j4
sudo make install

Not in this example but later we will want to use the virtual uart
provided by the picoprobe so that we do not have to buy additional
hardware.

Open at least two command line windows.

In the first window using my cfg files

openocd -f picoprobe.cfg -f target.cfg

Open On-Chip Debugger 0.10.0+dev-g14c0d0d-dirty (2021-01-29-19:22)
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
Info : only one transport option; autoselect 'swd'
Warn : Transport "swd" was already selected
adapter speed: 5000 kHz

Warn : Transport "swd" was already selected
Info : Hardware thread awareness created
Info : Hardware thread awareness created
Info : RP2040 Flash Bank Command
Info : Listening on port 6666 for tcl connections
Info : Listening on port 4444 for telnet connections
Info : clock speed 5000 kHz
Info : SWD DPIDR 0x0bc12477
Info : SWD DLPIDR 0x00000001
Info : SWD DPIDR 0x0bc12477
Info : SWD DLPIDR 0x10000001
Info : rp2040.core0: hardware has 4 breakpoints, 2 watchpoints
Info : rp2040.core1: hardware has 4 breakpoints, 2 watchpoints
Info : starting gdb server for rp2040.core0 on 3333
Info : Listening on port 3333 for gdb connections

If you see at least the breakpoints and watchpoints and it does not
return to the command line, then you can continue, otherwise you
cannot.

Not you may need to be root so 

sudo openocd ...

In the second window

telnet localhost 4444
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Open On-Chip Debugger
> 

The first window will show the connection 

Info : accepting 'telnet' connection on tcp/4444

Now normally one would:

> halt
target was in unknown state when halt was requested
> 

and it would say halted in some state with the program counter and
some other registers shown.  This is extremely unusual as we will see.

You can click on and ctrl-c in the openocd window and both openocd and 
telnet will stop and return to the command line.

In my experience it is not expected that if you reset the target other
than using reset through openocd that openocd will recover and re-connect
to the target properly.  So far it keeps working for me YMMV.

Note that with this connection you can reset the target without a
reset button.  You can try that now in the telnet window type
reset but dont hit enter.  Hold the bootsel button down, press enter
in the telnet window.  You should see the virtual drive to show
and you can release bootsel.  

I tend to have a third window open (I use a program called terminator
BTW for this work) so that I can build the program and copy it to
the virtual drive or copy it somewhere easy to get to from 
the telnet window depending on what I am working on.  Build and
copy notmain.uf2 from this directory into the card.  

The card will reset and a lot of text will go by on both openocd
and telnet windows.  warnings/errors, etc.  Mine ends with this:

Info : Read incorrect DLIPDR 00000000 (possibly CTRL/STAT value) when selecting coreid 1
Info : Read incorrect DLIPDR 00000000 (possibly CTRL/STAT value) when selecting coreid 1
Error: Could not find MEM-AP to control the core
Examination failed, GDB will be halted. Polling again in 100ms
Polling target rp2040.core0 failed, trying to reexamine
Info : SWD DPIDR 0x0bc12477
Info : SWD DLPIDR 0x00000001
Info : rp2040.core0: hardware has 4 breakpoints, 2 watchpoints
Info : SWD DPIDR 0x0bc12477
Info : SWD DLPIDR 0x10000001
Polling target rp2040.core1 failed, trying to reexamine
Info : SWD DPIDR 0x0bc12477
Info : SWD DLPIDR 0x10000001
Info : rp2040.core1: hardware has 4 breakpoints, 2 watchpoints

If all went well in the telnet window we can type this command

mdw 0x20001000 20

0x20001000: 20001000 20001004 20001008 2000100c 20001010 20001014 20001018 2000101c 
0x20001020: 20001020 20001024 20001028 2000102c 20001030 20001034 20001038 2000103c 
0x20001040: 20001040 20001044 20001048 2000104c 

which is expected this very small program simply writes the address to
memory at that address from 0x20001000 to 0x20001FFC and does this for
ever.  

Here again this is very unusual and not sure how they are doing this
yet as normally you need to halt the ARM before doing an mdw or other
operation.  

To add to this confusion:

mww 0x20001000 0x123456

mdw 0x20001000 20

0x20001000: 00123456 20001004 20001008 2000100c 20001010 20001014 20001018 2000101c 
0x20001020: 20001020 20001024 20001028 2000102c 20001030 20001034 20001038 2000103c 
0x20001040: 20001040 20001044 20001048 2000104c

Okay that worked!???

Okay if you power cycle or reset the target board (dont have to disconnect
openocd but you can)

> mww 0x20001000 0x123456
> mdw 0x20001000 20      
0x20001000: 20001000 20001004 20001008 2000100c 20001010 20001014 20001018 2000101c 
0x20001020: 20001020 20001024 20001028 2000102c 20001030 20001034 20001038 2000103c 
0x20001040: 20001040 20001044 20001048 2000104c 

The processor is still running!!!!!

I do not understand.  But anyway, now do this:

> halt
target was in unknown state when halt was requested
> resume
> halt
target halted due to debug-request, current mode: Thread 
xPSR: 0x81000000 pc: 0x20041f0a msp: 0x20041ee8
target halted due to debug-request, current mode: Thread 
xPSR: 0x01000000 pc: 0x00000178 msp: 0x20041f00
> 

Now the two processors are halted.  Now:

> mww 0x20001000 0x123456
> mdw 0x20001000 20
0x20001000: 00123456 20001004 20001008 2000100c 20001010 20001014 20001018 2000101c 
0x20001020: 20001020 20001024 20001028 2000102c 20001030 20001034 20001038 2000103c 
0x20001040: 20001040 20001044 20001048 2000104c 

and it is not overwriting that location

Now

> resume
> mdw 0x20001000 20
0x20001000: 20001000 20001004 20001008 2000100c 20001010 20001014 20001018 2000101c 
0x20001020: 20001020 20001024 20001028 2000102c 20001030 20001034 20001038 2000103c 
0x20001040: 20001040 20001044 20001048 2000104c 

and it is running again.

One more thing:

	mov r3,pc
	ldr r4,=0x20000000
	str r3,[r4]
	
this example writes the program counter to 0x20000000 so

> mdw 0x20000000
0x20000000: 20041f04 

And that matches some things I have read so

mdw 0x20041f00 20

0x20041f00: 4c09467b 49096023 60004809 42883004 e7f9d1fb 46c046c0 46c046c0 46c046c0 
0x20041f20: 46c046c0 46c046c0 20000000 20002000 20001000 00000000 00000000 00000000 
0x20041f40: 00000000 00000000 00000000 00000000 

and compare that to the listing

00000000 <outer-0x8>:
   0:	467b      	mov	r3, pc
   2:	4c09      	ldr	r4, [pc, #36]	; (28 <inner+0x1e>)
   4:	6023      	str	r3, [r4, #0]
   6:	4909      	ldr	r1, [pc, #36]	; (2c <inner+0x22>)

00000008 <outer>:
   8:	4809      	ldr	r0, [pc, #36]	; (30 <inner+0x26>)

0000000a <inner>:
   a:	6000      	str	r0, [r0, #0]
   c:	3004      	adds	r0, #4
   e:	4288      	cmp	r0, r1
  10:	d1fb      	bne.n	a <inner>
  12:	e7f9      	b.n	8 <outer>
  
Nice!  It all works.  That is in SRAM5 as documented in the rp2040
databook.  It is at the tail end of SRAM5 but in SRAM5.
