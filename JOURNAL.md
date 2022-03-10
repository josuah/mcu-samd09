Journal on SAM D09
==================
I start from my previous efforts on this MCU: I got GPIO working,
clock bouncing, and a first peripheral to work: USART.

Day 1
-----
I am now in the middle of getting I²C working, which happen to be
more challenging than I thought, as I am stuck with no signal going
out of the SDA and SCL pins.

I am using the Adafruit Seesaw board that has pull-up resistors on
pin 22 and 23, and actually labelled SDA and SCL, so I am trying
with these without internal pull-ups (I2CM.PINCFGx.PULLEN).

Day 2
-----
I had the idea of using the STATUS register to get more feedback on
what is going wrong. Interrupts are being triggered at this point,
right after I am writing to I2CM.ADDR.ADDR: good! It reacts.

But still no output, while it should be transferring the address.

Day 3
-----
The interrupt is actually an error triggered, the error flag is set
and I have the STATUS flag telling me that the problem is a SCL
being held low.

Is it possible that the peripheral cannot read the value of the pins?
Should I add PORT.PORTCFG.INEN and have it in output mode? Or have it
in input mode?

Sparkle of hope: checking why I cannot read the "high" value triggered
by the external pull-up resistor might get me on a lead, or maybe it is
due to the port being configured in peripheral mode.

Too late for today, I'll sleep over this.

Day 4
-----
Note that these 4 days are only for the I²C peripheral, there were more
than that for the USART. A lot of trying around also took place everyday.

Now exploring the interface between the I²C peripheral and the pins,
but manually from the `PORT.*` registers instead of through the
peripheral itself.
