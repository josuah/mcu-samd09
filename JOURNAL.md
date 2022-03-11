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
Note that these 4 days are only for the I²C peripheral, there were
more than that for the USART. A lot of trying around also took place
everyday.

Now exploring the interface between the I²C peripheral and the pins,
but manually from the `PORT.*` registers instead of through the
peripheral itself.

PORT is all configured for peripheral use like USART is (and USART
works), so by deduction, it *should* work for I²C as well. So maybe
there is something particular to I²C about port <-> peripheral
interface.  Maybe because the core checks its own pins after each
read/write to check for "clock stretching" from the other end.

It should not cause a problem to not have any peripheral responding
though (I am testing with a oscilloscope + a peripheral), as the
peripheral is not expected to wait that the address is fully
transfered to say anything at all, so the MCU should start by sending
the address *first*, and then check for anything from the slave...

Does it really require checking its own output? What would a slave
module on the bus ever keep the SCL pin low *before* the address
is transfered?

Maybe I need to read more about I²C to understand this.

After configuring everything, then writing to ADDR.ADDR:
`I2CM0.STATUS == 00000010 01010001` (`BUSERR=1 BUSSTATE=01 LOWTOUT=1
CLKHOLD=0 SEXTOUT=1 MEXTOUT=0`).

All the timeout ("*TOUT") values are for SCL pin held low: this is
an open-drain, releasing the pin is keeping it up due to the
open-drain.

Reading the value from PORT.IN, the pin is up, not dow...
So if we timeout on a low value, this suggests the peripheral did
not "see" that the clock was held up by the external pull resistor.

How do I let the I²C (SERCOM) peripheral read the value coming from
the PAD?

My pin multiplexing macro seems wrong! I might have missed that bug
during USART, by only using even pin numbers, unaffected by the bug.
Although, fixing that bug does not seems to fix anything.

At this point:

* I know the peripheral is up and running: it triggers error interrupts
  when writing in I2CM0.ADDR.ADDR register, which is the documented
  behavior (without the error part).

* I know the port is setup for output alternate function: the same code
  works with USART.

* I know the input pin can be read out of the PAD, with INEN I can
  get the value.

This suggests something is still there between the peripheral and the PAD
that makes it unhappy.

What now? I cannot see the internal pull-up resistor active on the
pin 22?

Sparkle of hope. I see something moving, but it's weak. I might
have been using the wrong SERCOM, not matching the PINs I had.

The oscilloscope "trigger" led blinked. Once. Time to inspect all
registers again. And try with different timeout modes, now configured
for around a 10 ms.

Hurray! The status register is different! I have a different error.
This is far from a victory, but it made about 70 without any progress
so in comparison this is much.

```
- 00000010 01010001 BUSERR        BUSSTATE=01 LOWTOUT         SEXTOUT
+ 00000001 00010101 BUSERR RXNACK BUSSTATE=01         MEXTOUT
```

So... I have RXNACK... which means no answer from the slave? It
actually sent something? I need to try with a real slave on the
bus...

Dezooming, I can see the message passing through the oscilloscope.
Hell if I need a logic analizer... Wait can I pause the display
on trigger? Oh yes I can! Logic analizer acquired!

I can clearly see the signal of both the SCL and SDA pins showing
up on the oscilloscope. We did it. Taking a break, see you later.

*"Fish, Silent Cruise" playing on the background.*

From that, I could get an answer from an SSD1306 screen. Let's
keep going.

Day 5
-----
The SSD1306 screen was reactiing to the writes, but I was never
sending a stop condition. That is done through the I2CM.CTRLB.CMD
field, in either read, or write.

Flushing data to the screen seems to be slow, and I did not really
check reading data from the bus, but the core of the implementation
is there and works. I can place pixels on the screen using an
existing driver that was working with an ATmega328P.
