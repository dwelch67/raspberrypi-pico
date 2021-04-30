

This drives the widely available Nokia 5110 display.  Not the phone
itself but the display used in the phone.  For some reason there is a
gobzillion of these things, everyone and their brother is selling them
and have been around $10 since forever.

They have a Philips PCD8544 48 × 84 pixels matrix LCD controller/driver

Which is basically spi with an extra control signal.

You hook it up to the pico like this:

RST GPIO 2   
CE  GPIO 3
DC  GPIO 4
DIN GPIO 5
CLK GPIO 6

VCC VCC
GND GND
LIGHT (no connect)

Derived from prior example, this uses 8x8 font data to display ASCII
characters on the display.
