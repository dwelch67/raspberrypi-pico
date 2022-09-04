
See zone first.

If you take the VTOR from core zero and give that to core one it does
not work.  I am not using vectors so dont really care.  But if I 
hardcode the value passed for the vector table as 0x20000000 where I
would have one if I had one.  Then it does work.  There must be some
checking going on in the core one bootstrap.

I did experiment and you can (obviously) have separate entry points
for core zero and core one.  In this case for simplicity I sorted
the cores.

core zero starts core one
core one blinks the led
