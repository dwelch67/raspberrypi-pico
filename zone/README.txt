
Read the zero example first.

This example starts core 1.

I recommend you find and load the flash_nuke.uf2 program, this example
is ram based so each time you reset on the openocd telnet connection
you can simply copy notmain.uf2 to the virtual flash drive.  The
text below assumes you have done this.


As in zero you need one window with the openocd program and another
with a telnet into openocd.

In the telnet window

reset

make and copy notmain.uf2 to the virtual drive, a bunch of stuff
including warnings or errors will pass through both windows and end
up with something like

Read incorrect DLIPDR 00000000 (possibly CTRL/STAT value) when selecting coreid 1
Read incorrect DLIPDR 00000000 (possibly CTRL/STAT value) when selecting coreid 1
Could not find MEM-AP to control the core
Examination failed, GDB will be halted. Polling again in 100ms
Polling target rp2040.core0 failed, trying to reexamine
SWD DPIDR 0x0bc12477
SWD DLPIDR 0x00000001
rp2040.core0: hardware has 4 breakpoints, 2 watchpoints
SWD DPIDR 0x0bc12477
SWD DLPIDR 0x10000001
Polling target rp2040.core1 failed, trying to reexamine
SWD DPIDR 0x0bc12477
SWD DLPIDR 0x10000001
rp2040.core1: hardware has 4 breakpoints, 2 watchpoints

Now

mdw 0x20002000
mdw 0x20003000
mww 0x20002000 0x22
mww 0x20003000 0x33
mdw 0x20002000
mdw 0x20003000


> mdw 0x20002000
0x20002000: 12345678 

> mdw 0x20003000
0x20003000: 76543210 

> mww 0x20002000 0x22
> mww 0x20003000 0x33
> mdw 0x20002000
0x20002000: 12345678 

> mdw 0x20003000
0x20003000: 76543210 

> 

core zero is pounding 0x12345678 to memory at 0x20002000
core one is poinding 0x76543210 to memory at 0x20003000

Now

> halt
target halted due to debug-request, current mode: Thread 
xPSR: 0x61000000 pc: 0x200001ee msp: 0x20001fe8
target halted due to debug-request, current mode: Thread 
xPSR: 0x21000000 pc: 0x2000011c msp: 0x20002ff8

Your addresses may vary.

But if

> mdw 0x20002000
0x20002000: 12345678 

> mdw 0x20003000
0x20003000: 76543210 

> mww 0x20002000 0x22
> mww 0x20003000 0x33
> mdw 0x20002000
0x20002000: 00000022 

> mdw 0x20003000
0x20003000: 00000033 

> targets
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0  rp2040.core0       cortex_m   little rp2040.core0.cpu   halted
 1* rp2040.core1       cortex_m   little rp2040.core1.cpu   halted

now start them again

> resume
> targets
    TargetName         Type       Endian TapName            State       
--  ------------------ ---------- ------ ------------------ ------------
 0  rp2040.core0       cortex_m   little rp2040.core0.cpu   running
 1* rp2040.core1       cortex_m   little rp2040.core1.cpu   running


And check again:

> mdw 0x20002000
0x20002000: 12345678 

> mdw 0x20003000
0x20003000: 76543210 

> mww 0x20002000 0x22
> mww 0x20003000 0x33
> mdw 0x20002000
0x20002000: 12345678 

> mdw 0x20003000
0x20003000: 76543210 

They are running again.


First and foremost I created a vector table.

.globl vector_table
vector_table:
.thumb_func
.globl centry
centry:
	b reset
	.balign 4
	.word reset ;@ has to be offset 4
	.word loop
	.word loop
	.word loop

	.word loop
	.word loop
	.word loop
	.word loop

	.word loop
	.word loop
	.word loop
	.word loop

	.word loop
	.word loop
	.word loop
	.word loop

It is not completely correct as the first word is supposed to be
the value we want to put in the stack pointer on reset, but I chose
to put this at the beginning where it normally would be but, they call
our code at the entry point not look for the vector so I replaced
that first word with branch over the table.  (we are not necessarily
using the vector table just yet, starting core one seems to care, I
need to research this start a bit more).

This leads to important info about the vector table once built
you should always check it on a new project.

20000000 <centry>:
20000000:	e020      	b.n	20000044 <reset>
20000002:	46c0      	nop			; (mov r8, r8)
20000004:	20000045 	andcs	r0, r0, r5, asr #32
20000008:	2000005d 	andcs	r0, r0, sp, asr r0
2000000c:	2000005d 	andcs	r0, r0, sp, asr r0
20000010:	2000005d 	andcs	r0, r0, sp, asr r0
20000014:	2000005d 	andcs	r0, r0, sp, asr r0
20000018:	2000005d 	andcs	r0, r0, sp, asr r0
2000001c:	2000005d 	andcs	r0, r0, sp, asr r0
20000020:	2000005d 	andcs	r0, r0, sp, asr r0
20000024:	2000005d 	andcs	r0, r0, sp, asr r0
20000028:	2000005d 	andcs	r0, r0, sp, asr r0
2000002c:	2000005d 	andcs	r0, r0, sp, asr r0
20000030:	2000005d 	andcs	r0, r0, sp, asr r0
20000034:	2000005d 	andcs	r0, r0, sp, asr r0
20000038:	2000005d 	andcs	r0, r0, sp, asr r0
2000003c:	2000005d 	andcs	r0, r0, sp, asr r0
20000040:	2000005d 	andcs	r0, r0, sp, asr r0

20000044 <reset>:

2000005c <loop>:

(andcs is bogus focus on the word 0x2000005d, etc)

Notice that the vector table contains the address ORRed with one,
this is documented in the ARM ARM.  If the addresses are even numbered
then the table wont work.  .thumb_func or .type myfunname,%function
makes this work.

In the rp2040 manual you will see that under SIO there are a number
of interfaces that go between the cores.  There are two fifos one
goes from core zero to core one, the other from core one to core zero.

After reset the bootrom puts core one in a holding pattern waiting for
core zero to ask it to start.

I again need to look this up (to see what other, if any, commands
are available) but the protocol appears to be these commands (words
that are sent from zero to one over the fifo)

0x00000000
0x00000000
0x00000001
vector_table_address
stack_pointer_init
entry_point (ORRed with 1)

core one will echo these items back, if you dont get what you sent
you start over from the beginning (I am guessing one or two zeros
re-syncs the interface).

The SIO CPUID register returns 0 for core zero and 1 for core one,
so I can "sort the cores" by checking that register and sending
core zero to the core_zero label.  Core one, once started, will fall
into notmain();

	ldr r1,=0xD0000000 ;@SIO_CPUID
	ldr r0,[r1]
	cmp r0,#0
	beq core_zero

	;@ core_one
    ldr r0,stack_one
    mov sp,r0
    bl notmain
	b loop

Even though in theory we are sending both the vector table and the
stack pointer to core one I am setting them here until I understand
more.

Core zero starts core one then lands in a loop writing 0x12345678
and core one lands in a loop writing 0x76543210.
