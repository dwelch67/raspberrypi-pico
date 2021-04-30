
See other Nokia 5110 examples.

This is a GPS clock using a Nokia 5110 display.  This is set for a 
9600 baud gps (somewhat typical today, otherwise make the uart slower
to match 4800 or 2400).  Looking for GPRMC or GNRMC, the latter is
from some of the newer ones.  If in doubt then hook your GPS to a
usb uart (3.3v level, need a 3.3v level GPS!!!) and check the baud
rate and the RMC string.  Note that some will power up with a bogus
time but will count through it until enough of a signal to read it
from GPS.

$GNRMC,194912.00,V,,,,,,,190221,,,N*6C

others may simply have no timestamp at all

$GNRMC,,...

And this will not work until there is a pattern there.

Same hook up as before

RST GPIO 2   
CE  GPIO 3
DC  GPIO 4
DIN GPIO 5
CLK GPIO 6

VCC VCC
GND GND
LIGHT (no connect)

The GPS TX goes to GPIO 1 (UART0_RX)

If you want to power the GPS from the pi you will need something to
split the one pin into two to power the Nokia display and the GPS.
