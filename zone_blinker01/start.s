
.cpu cortex-m0
.thumb

    ldr r1,=0xD0000000 ;@SIO_CPUID
    ldr r0,[r1]
    cmp r0,#0
    bne core_one

    ;@ core_zero
    ldr r0,=0x20002000
    mov sp,r0
    bl zero_entry
    b .

core_one:
    ;@ core_one
    bl notmain
    b .

.align
.ltorg


;@ ----------------------------------
.balign 0x100

.thumb_func
.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.thumb_func
.globl GET32
GET32:
    ldr r0,[r0]
    bx lr

.globl SEV
.thumb_func
SEV:
    sev
    bx lr

.globl WFE
.thumb_func
WFE:
    wfe
    bx lr

.globl DELAY
.thumb_func
DELAY:
    sub r0,#1
    bne DELAY
    bx lr

;@-------------------------------------------------------------------------
;@
;@ Copyright (c) 2021 David Welch dwelch@dwelch.com
;@
;@ Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
;@
;@ The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
;@
;@ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
;@
;@-------------------------------------------------------------------------
