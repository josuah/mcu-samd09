#include "libc.h"
#include "registers.h"
#include "functions.h"

void
pwm_init(struct sdk_tc_count8 *tc)
{
	switch (tc_get_id(tc)) {
	case 1:
		PM->APBCMASK |= PM_APBCMASK_TC1;
		break;
	case 2:
		PM->APBCMASK |= PM_APBCMASK_TC2;
		break;
	default: assert(!"unknown timer/counter");
	}

	tc->CTRLA = 0
	/* switch timer/counter to 8-bit mode */
	 | TC_COUNT8_CTRLA_MODE_COUNT8
	/* normal PWM mode */
	 | TC_COUNT8_CTRLA_WAVEGEN_NPWM
	/* do not divide the input generic clock */
	 | TC_COUNT8_CTRLA_PRESCALER_DIV1
	/* stick to the prescaler signal on wraparound */
	 | TC_COUNT8_CTRLA_PRESCSYNC_PRESC;

	/* enable the timer/counter */
	tc->CTRLA |= TC_COUNT8_CTRLA_ENABLE;

	/* wait that the register write to complete */
	while (tc->STATUS & TC_COUNT8_STATUS_SYNCBUSY);
}

void
pwm_init_counter(uint8_t pin)
{
	PORT->PINCFG[pin] = 0
	/* enable peripheral multiplexing */
	 | PORT_PINCFG_PMUXEN
	/* internal pull-up resistor on SCL pin */
	 | PORT_PINCFG_PULLEN
	/* permit input to check for SCL pin stretching as common in I²C */
	 | PORT_PINCFG_INEN
	/* increase driver strength a bit */
	 | PORT_PINCFG_DRVSTR;
	/* apply the configuration to the pins */

	/* pin as output */
        PORT->DIRSET = (1u << pin);

	/* plug the pin to the timer/counter */
	port_set_pmux(pin, PORT_PMUX_TC);
}

void
pwm_set_duty_cycle(struct sdk_tc_count8 *tc, uint8_t counter_id, uint8_t duty_cycle)
{
	assert(counter_id < 4);
	tc->CC[counter_id] = duty_cycle;
}
