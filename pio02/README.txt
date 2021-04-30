
This has the pio wait for a fifo write pulls the data from the
fifo, and writes the lsbit to the output pin.  So far not sure
how they got the output enable to the pin asserted, so I used
set_pindirs and that seemed to work just fine (mixing set and out).

So this is like blinker00 we control the delay from the ARM, just
the path to the pin is different.
