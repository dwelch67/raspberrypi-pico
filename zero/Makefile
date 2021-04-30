
ARMGNU ?= arm-none-eabi

XCPU = -mcpu=cortex-m0

AOPS = --warn --fatal-warnings $(XCPU)
COPS = -Wall -O2 -ffreestanding $(XCPU)
LOPS = -nostdlib -nostartfiles

all : notmain.uf2

clean:
	rm -f *.bin
	rm -f *.o
	rm -f *.elf
	rm -f *.list
	rm -f *.uf2
	rm -f makeuf2
	
makeuf2 : makeuf2.c crcpico.h
	gcc -O2 makeuf2.c -o makeuf2
	
notmain.uf2 : notmain.bin makeuf2
	./makeuf2 notmain.bin notmain.uf2

start.o : start.s
	$(ARMGNU)-as $(AOPS) start.s -o start.o

notmain.bin :               memmap.ld start.o
	$(ARMGNU)-ld $(LOPS) -T memmap.ld start.o -o notmain.elf
	$(ARMGNU)-objdump -D notmain.elf > notmain.list
	$(ARMGNU)-objcopy -O binary notmain.elf notmain.bin

##-------------------------------------------------------------------------
##
## Copyright (c) 2021 David Welch dwelch@dwelch.com
##
## Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
##
## The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
##
##-------------------------------------------------------------------------
