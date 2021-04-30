
.cpu cortex-m0
.thumb

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

.thumb_func
reset:
    ldr r1,=0xE000ED08 ;@ VTOR
    ldr r0,=vector_table
    str r0,[r1]

    ldr r1,=0xD0000000 ;@SIO_CPUID
    ldr r0,[r1]
    cmp r0,#0
    beq core_zero

    ;@ core_one
    ldr r0,stack_one
    mov sp,r0
    bl notmain
    b loop

.thumb_func
loop:
    b loop

core_zero:
    ldr r0,stack_zero
    mov sp,r0
    bl zero_entry
    b loop

.align
.globl stack_zero
stack_zero: .word 0x20002000
.globl stack_one
stack_one:  .word 0x20003000
.globl one_entry
one_entry: .word centry

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
