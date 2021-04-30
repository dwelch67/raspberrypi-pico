
This uses the PWM to gradually brighten and dim the led.

Very simple, there is a TOP register and a CC register.  Internally it
counts from 0 to TOP (resets to 0xFFFF)  If the count is less than
(or equal?) to CC the output is high, otherwise low.  If you move
CC about the duty cycle changes and the overall energy to the led changes.

