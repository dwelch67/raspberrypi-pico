
void pasm ( void )
{
    set_pindirs(0x1F);
label("loop");
    pull_block();
    out_pins(5,0);
    jmp("loop");
}

