
void pasm ( void )
{
    set_pindirs(0x3);
label("loop");
    pull_block();
    out_pins(2,0);
    jmp("loop");
}

