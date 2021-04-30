

void pasm ( void )
{
    set_pindirs(1);
label("loop");
    pull_block();
    out_pins(1,0);
    jmp("loop");
}

