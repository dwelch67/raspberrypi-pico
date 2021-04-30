
This demonstrates a simple event.  More of a cortex-m thing than a
pico thing.  This uses the systick timer in the ARM core.  I am
not sure why there are two WFE's per event (two characters come out
the uart per event).
