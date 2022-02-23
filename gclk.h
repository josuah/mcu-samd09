#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define GCLK ((struct zmcu_gclk *)0x40000C00)

struct zmcu_gclk {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define GCLK_CTRL_SWRST				(1u << 0)

	/* 0x01: Status */
	uint8_t volatile STATUS;
#define GCLK_STATUS_SYNCBUSY			(1u << 7)

        /* CLK* registers are clock destinations, bound to an
         * existing peripheral, such as a SERCOM or RTC */

	/* ID of the destination clock for CLK* registers */
#define GCLK_CLKID_DFLL48M_REF			0x00
#define GCLK_CLKID_DPLL				0x01
#define GCLK_CLKID_DPLL_32K			0x02
#define GCLK_CLKID_WDT				0x03
#define GCLK_CLKID_RTC				0x04
#define GCLK_CLKID_EIC				0x05
#define GCLK_CLKID_EVSYS_CHANNEL_0		0x07
#define GCLK_CLKID_EVSYS_CHANNEL_1		0x08
#define GCLK_CLKID_EVSYS_CHANNEL_2		0x09
#define GCLK_CLKID_EVSYS_CHANNEL_3		0x0A
#define GCLK_CLKID_EVSYS_CHANNEL_4		0x0B
#define GCLK_CLKID_EVSYS_CHANNEL_5		0x0C
#define GCLK_CLKID_SERCOMx_SLOW			0x0D
#define GCLK_CLKID_SERCOM0_CORE			0x0E
#define GCLK_CLKID_SERCOM1_CORE			0X0F
#define GCLK_CLKID_TC2				0x12
#define GCLK_CLKID_ADC				0x13

	/* 0x02: Generic Clock Control */
	uint16_t volatile CLKCTRL;
#define GCLK_CLKCTRL_WRTLOCK			(1u << 15)
#define GCLK_CLKCTRL_CLKEN			(1u << 14)
#define GCLK_CLKCTRL_GEN(x)			((x) << 8)
#define GCLK_CLKCTRL_GEN_MASK			GCLK_CLKCTRL_GEN(B00001111)
#define GCLK_CLKCTRL_ID(x)			((x) << 0)
#define GCLK_CLKCTRL_ID_MASK			GCLK_CLKCTRL_ID(B00111111)

	/* GEN* registers are for clock generators: tools to
	 * generate a frequency for use with CLK* fields. */

	/* ID of the clock generator for GEN* registers */
#define GCLK_GENID_GCLKGEN0                     0x00
#define GCLK_GENID_GCLKGEN1                     0x01
#define GCLK_GENID_GCLKGEN2                     0x02
#define GCLK_GENID_GCLKGEN3                     0x03
#define GCLK_GENID_GCLKGEN4                     0x04
#define GCLK_GENID_GCLKGEN5                     0x05

	/* 0x04: Generic Clock Generator Control */
	uint32_t volatile GENCTRL;
#define GCLK_GENCTRL_RUNSTDBY			(1u << 21)
#define GCLK_GENCTRL_DIVSEL			(1u << 20)
#define GCLK_GENCTRL_OE				(1u << 19)
#define GCLK_GENCTRL_OOV			(1u << 18)
#define GCLK_GENCTRL_IDC			(1u << 17)
#define GCLK_GENCTRL_GENEN			(1u << 16)
#define GCLK_GENCTRL_SRC(x)			((x) << 8)
#define GCLK_GENCTRL_SRC_MASK			GCLK_GENCTRL_SRC(B00011111)
#define GCLK_GENCTRL_SRC_XOSC			0x00
#define GCLK_GENCTRL_SRC_GCLKIN			0x01
#define GCLK_GENCTRL_SRC_GCLKGEN1		0x02
#define GCLK_GENCTRL_SRC_OSCULP32K		0x03
#define GCLK_GENCTRL_SRC_OSC32K			0x04
#define GCLK_GENCTRL_SRC_XOSC32K		0x05
#define GCLK_GENCTRL_SRC_OSC8M			0x06
#define GCLK_GENCTRL_SRC_DFLL48M		0x07
#define GCLK_GENCTRL_SRC_FDPLL96M		0x08
#define GCLK_GENCTRL_ID(x)			((x) << 0)
#define GCLK_GENCTRL_ID_MASK			GCLK_GENCTRL_ID(B00001111)

	/* 0x08: Generic Clock Generator Division */
	uint32_t volatile GENDIV;
#define GCLK_GENDIV_DIV(x)			((x) << 8)
#define GCLK_GENDIV_DIV_MASK			GCLK_GENDIV_DIV(0xFFFF)
#define GCLK_GENDIV_ID(x)			((x) << 0)
#define GCLK_GENDIV_ID_MASK			GCLK_GENDIV_ID(B00001111)

};
