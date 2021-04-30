
This example uses the uart at 115200 N81.

You will need a 3.3v UART solution, or use another pico as a debugger
and connect gpio0 on the target mcu with gpio5

apt-get install minicom lrzsz

[25384.819818] usb 1-3.4.4: new full-speed USB device number 91 using ehci-pci
[25384.928874] usb 1-3.4.4: New USB device found, idVendor=2e8a, idProduct=0004
[25384.928877] usb 1-3.4.4: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[25384.928879] usb 1-3.4.4: Product: Picoprobe
[25384.928881] usb 1-3.4.4: Manufacturer: Raspberry Pi
[25384.928882] usb 1-3.4.4: SerialNumber: 123456
[25384.929424] cdc_acm 1-3.4.4:1.0: ttyACM0: USB ACM device

so it is on ttyACM0

create /etc/minicom/minirc.acm0 with these contents

pu port             /dev/ttyACM0
pu minit            
pu mhangup          
pu rtscts           No 
pu sound            No 

then 

minicom acm0

ctrl-a then w to deal with wrapping
ctrl-a then q to quit

Can create as many minirc files as you like with the various ttyXXXY
devices as you want.


GP0 UART0_TX
GP1 UART0_RX
