
Another pull based pio example.  I see that there is an out pindirs
thing, no desire to mess with that so using the set pindirs works
great.

This basically uses the out shift register and different values
fed to it to create a PWM.

The led oscillates from dim to bright and back as the pattern
goes from

0x0000
0x8000
0xC000
0xE000
0xF000
...
0xFFF0
0xFFF8
0xFFFC
0xFFFE
0xFFFF
0x7FFF
0x3FFF
0x1FFF
...
0x0007
0x0003
0x0001
pull the next value
0x0000
0x8000
...
and so on.
