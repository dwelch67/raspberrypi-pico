
.cpu cortex-m0
.thumb

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

copy_loop:
    ldr r3,[r0]
    str r3,[r1]
    add r0,#0x4
    add r1,#0x4
    sub r2,#1
    bne copy_loop

    ldr r0,=0x20000101
    bx r0

pool0:
.align
.ltorg

;@ ----------------------------------
.balign 0x100


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
    .word systick_handler

.thumb_func
reset:
    ldr r1,=0xE000ED08 ;@ VTOR
    ldr r0,=vector_table
    str r0,[r1]

    ldr r0,=0x20002000
    mov sp,r0
    bl notmain
    b loop

.thumb_func
loop:
    b loop


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

.thumb_func
.globl WFE
WFE:
    wfe
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
