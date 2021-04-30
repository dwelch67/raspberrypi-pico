
This uses PIO to drive an ssd1306 based i2c display.  They come in two
sizes 128x32 or 128x64.  As written is for 128x32 (I think it will
work as is for both (top half of the 128x64)).

If I remember right these do not actually ACK, but either way dont
care if it ACKs, just going to blast out the writes.

SCL GPIO 2
SDA GPIO 3
GND GND
VCC 3V3

This is a gps based clock that just does hours and minutes. clock00 does
hours minutes seconds.
