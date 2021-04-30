

void pasm ( void )
{

//set pindirs, 1
    set_pindirs(1);
//; Set pin to output
 //again:
label("again");
 //set pins, 1 [30] ; Drive pin high and then delay for one cycle
    set_pins(1,30);
 //set pins, 0 [29]; Drive pin low
    set_pins(0,29);
 //jmp again ; Set PC to label `again`
    jmp("again");
}

