
5 pin, 20 led charlieplexed board.  

This works great.  The pads reset to have a pull down, so dont pull
either way and then control the output enables.

It always scares me to do something like this where if either side
gets out of order or there is a hiccup, then it will go off the rails.

Am intentionally not polling the fifo full bit because the pio is
running at the system clock rate and we cannot feed the fifo faster
than it is being used so it should probably not even have two items
at one time much less fill up.
