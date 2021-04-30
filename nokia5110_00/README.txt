
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



The wider border is the top.  Data comes in from the top left.

If you tilt your head to the left the first byte that comes
in after setting the row and column is as follows

00000000...    bank 0
11111111...
22222222...
33333333...
44444444...
55555555...
66666666...
77777777...
0              bank 1
1
2
3
4
5
6
7
...

bit 0 of the first byte sent is the top left corner
bit 1 of the first byte is the bit below that 
bit 0 of the second byte is the bit to the right of the top left corner

The first 84 bytes of pixels is the first bank if you will.  The
display is 84 pixels wide by 48 tall.  48/8 = 6, so 6 banks or rows
of bytes.  And 84 bytes across per bank.  

84*6 = 504 bytes.
(84*48/8 = 504)






