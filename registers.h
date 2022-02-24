/* generated from SVD file, then edited by hand */



#define ADC ((struct zmcu_adc *)0x42002000)

/* Analog Digital Converter */
struct zmcu_adc {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
	/* Software Reset */
#define ADC_CTRLA_SWRST				0u
	/* Enable */
#define ADC_CTRLA_ENABLE			1u
	/* Run in Standby */
#define ADC_CTRLA_RUNSTDBY			2u

	/* 0x01: Reference Control */
	uint8_t volatile REFCTRL;
	/* Reference Selection */
#define ADC_REFCTRL_REFSEL_Lsb			0u
#define ADC_REFCTRL_REFSEL_Msb			3u
#define ADC_REFCTRL_REFSEL_INT1V		0x0
#define ADC_REFCTRL_REFSEL_INTVCC0		0x1
#define ADC_REFCTRL_REFSEL_INTVCC1		0x2
#define ADC_REFCTRL_REFSEL_AREFA		0x3
#define ADC_REFCTRL_REFSEL_AREFB		0x4
	/* Reference Buffer Offset Compensation Enable */
#define ADC_REFCTRL_REFCOMP			7u

	/* 0x02: Average Control */
	uint8_t volatile AVGCTRL;
	/* Number of Samples to be Collected */
#define ADC_AVGCTRL_SAMPLENUM_Lsb		0u
#define ADC_AVGCTRL_SAMPLENUM_Msb		3u
#define ADC_AVGCTRL_SAMPLENUM_1			0x0
#define ADC_AVGCTRL_SAMPLENUM_2			0x1
#define ADC_AVGCTRL_SAMPLENUM_4			0x2
#define ADC_AVGCTRL_SAMPLENUM_8			0x3
#define ADC_AVGCTRL_SAMPLENUM_16		0x4
#define ADC_AVGCTRL_SAMPLENUM_32		0x5
#define ADC_AVGCTRL_SAMPLENUM_64		0x6
#define ADC_AVGCTRL_SAMPLENUM_128		0x7
#define ADC_AVGCTRL_SAMPLENUM_256		0x8
#define ADC_AVGCTRL_SAMPLENUM_512		0x9
#define ADC_AVGCTRL_SAMPLENUM_1024		0xa
	/* Adjusting Result / Division Coefficient */
#define ADC_AVGCTRL_ADJRES_Lsb			4u
#define ADC_AVGCTRL_ADJRES_Msb			6u

	/* 0x03: Sampling Time Control */
	uint8_t volatile SAMPCTRL;
	/* Sampling Time Length */
#define ADC_SAMPCTRL_SAMPLEN_Lsb		0u
#define ADC_SAMPCTRL_SAMPLEN_Msb		5u

	/* 0x04: Control B */
	uint16_t volatile CTRLB;
	/* Differential Mode */
#define ADC_CTRLB_DIFFMODE			0u
	/* Left-Adjusted Result */
#define ADC_CTRLB_LEFTADJ			1u
	/* Free Running Mode */
#define ADC_CTRLB_FREERUN			2u
	/* Digital Correction Logic Enabled */
#define ADC_CTRLB_CORREN			3u
	/* Conversion Result Resolution */
#define ADC_CTRLB_RESSEL_Lsb			4u
#define ADC_CTRLB_RESSEL_Msb			5u
#define ADC_CTRLB_RESSEL_12BIT			0x0
#define ADC_CTRLB_RESSEL_16BIT			0x1
#define ADC_CTRLB_RESSEL_10BIT			0x2
#define ADC_CTRLB_RESSEL_8BIT			0x3
	/* Prescaler Configuration */
#define ADC_CTRLB_PRESCALER_Lsb			8u
#define ADC_CTRLB_PRESCALER_Msb			10u
#define ADC_CTRLB_PRESCALER_DIV4		0x0
#define ADC_CTRLB_PRESCALER_DIV8		0x1
#define ADC_CTRLB_PRESCALER_DIV16		0x2
#define ADC_CTRLB_PRESCALER_DIV32		0x3
#define ADC_CTRLB_PRESCALER_DIV64		0x4
#define ADC_CTRLB_PRESCALER_DIV128		0x5
#define ADC_CTRLB_PRESCALER_DIV256		0x6
#define ADC_CTRLB_PRESCALER_DIV512		0x7

	/* 0x06 */
	uint8_t volatile RESERVED0[0x08-0x06];

	/* 0x08: Window Monitor Control */
	uint8_t volatile WINCTRL;
	/* Window Monitor Mode */
#define ADC_WINCTRL_WINMODE_Lsb			0u
#define ADC_WINCTRL_WINMODE_Msb			2u
#define ADC_WINCTRL_WINMODE_DISABLE		0x0
#define ADC_WINCTRL_WINMODE_MODE1		0x1
#define ADC_WINCTRL_WINMODE_MODE2		0x2
#define ADC_WINCTRL_WINMODE_MODE3		0x3
#define ADC_WINCTRL_WINMODE_MODE4		0x4

	/* 0x09 */
	uint8_t volatile RESERVED1[0x0C-0x09];

	/* 0x0C: Software Trigger */
	uint8_t volatile SWTRIG;
	/* ADC Conversion Flush */
#define ADC_SWTRIG_FLUSH			0u
	/* ADC Start Conversion */
#define ADC_SWTRIG_START			1u

	/* 0x0D */
	uint8_t volatile RESERVED2[0x10-0x0D];

	/* 0x10: Input Control */
	uint32_t volatile INPUTCTRL;
	/* Positive Mux Input Selection */
#define ADC_INPUTCTRL_MUXPOS_Lsb		0u
#define ADC_INPUTCTRL_MUXPOS_Msb		4u
#define ADC_INPUTCTRL_MUXPOS_PIN0		0x0
#define ADC_INPUTCTRL_MUXPOS_PIN1		0x1
#define ADC_INPUTCTRL_MUXPOS_PIN2		0x2
#define ADC_INPUTCTRL_MUXPOS_PIN3		0x3
#define ADC_INPUTCTRL_MUXPOS_PIN4		0x4
#define ADC_INPUTCTRL_MUXPOS_PIN5		0x5
#define ADC_INPUTCTRL_MUXPOS_PIN6		0x6
#define ADC_INPUTCTRL_MUXPOS_PIN7		0x7
#define ADC_INPUTCTRL_MUXPOS_PIN8		0x8
#define ADC_INPUTCTRL_MUXPOS_PIN9		0x9
#define ADC_INPUTCTRL_MUXPOS_PIN10		0xa
#define ADC_INPUTCTRL_MUXPOS_PIN11		0xb
#define ADC_INPUTCTRL_MUXPOS_PIN12		0xc
#define ADC_INPUTCTRL_MUXPOS_PIN13		0xd
#define ADC_INPUTCTRL_MUXPOS_PIN14		0xe
#define ADC_INPUTCTRL_MUXPOS_PIN15		0xf
#define ADC_INPUTCTRL_MUXPOS_PIN16		0x10
#define ADC_INPUTCTRL_MUXPOS_PIN17		0x11
#define ADC_INPUTCTRL_MUXPOS_PIN18		0x12
#define ADC_INPUTCTRL_MUXPOS_PIN19		0x13
#define ADC_INPUTCTRL_MUXPOS_TEMP		0x18
#define ADC_INPUTCTRL_MUXPOS_BANDGAP		0x19
#define ADC_INPUTCTRL_MUXPOS_SCALEDCOREVCC	0x1a
#define ADC_INPUTCTRL_MUXPOS_SCALEDIOVCC	0x1b
	/* Negative Mux Input Selection */
#define ADC_INPUTCTRL_MUXNEG_Lsb		8u
#define ADC_INPUTCTRL_MUXNEG_Msb		12u
#define ADC_INPUTCTRL_MUXNEG_PIN0		0x0
#define ADC_INPUTCTRL_MUXNEG_PIN1		0x1
#define ADC_INPUTCTRL_MUXNEG_PIN2		0x2
#define ADC_INPUTCTRL_MUXNEG_PIN3		0x3
#define ADC_INPUTCTRL_MUXNEG_PIN4		0x4
#define ADC_INPUTCTRL_MUXNEG_PIN5		0x5
#define ADC_INPUTCTRL_MUXNEG_PIN6		0x6
#define ADC_INPUTCTRL_MUXNEG_PIN7		0x7
#define ADC_INPUTCTRL_MUXNEG_GND		0x18
#define ADC_INPUTCTRL_MUXNEG_IOGND		0x19
	/* Number of Input Channels Included in Scan */
#define ADC_INPUTCTRL_INPUTSCAN_Lsb		16u
#define ADC_INPUTCTRL_INPUTSCAN_Msb		19u
	/* Positive Mux Setting Offset */
#define ADC_INPUTCTRL_INPUTOFFSET_Lsb		20u
#define ADC_INPUTCTRL_INPUTOFFSET_Msb		23u
	/* Gain Factor Selection */
#define ADC_INPUTCTRL_GAIN_Lsb			24u
#define ADC_INPUTCTRL_GAIN_Msb			27u
#define ADC_INPUTCTRL_GAIN_1X			0x0
#define ADC_INPUTCTRL_GAIN_2X			0x1
#define ADC_INPUTCTRL_GAIN_4X			0x2
#define ADC_INPUTCTRL_GAIN_8X			0x3
#define ADC_INPUTCTRL_GAIN_16X			0x4
#define ADC_INPUTCTRL_GAIN_DIV2			0xf

	/* 0x14: Event Control */
	uint8_t volatile EVCTRL;
	/* Start Conversion Event In */
#define ADC_EVCTRL_STARTEI			0u
	/* Synchronization Event In */
#define ADC_EVCTRL_SYNCEI			1u
	/* Result Ready Event Out */
#define ADC_EVCTRL_RESRDYEO			4u
	/* Window Monitor Event Out */
#define ADC_EVCTRL_WINMONEO			5u

	/* 0x15 */
	uint8_t volatile RESERVED3[0x16-0x15];

	/* 0x16: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Result Ready Interrupt Enable */
#define ADC_INTENCLR_RESRDY			0u
	/* Overrun Interrupt Enable */
#define ADC_INTENCLR_OVERRUN			1u
	/* Window Monitor Interrupt Enable */
#define ADC_INTENCLR_WINMON			2u
	/* Synchronization Ready Interrupt Enable */
#define ADC_INTENCLR_SYNCRDY			3u

	/* 0x17: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Result Ready Interrupt Enable */
#define ADC_INTENSET_RESRDY			0u
	/* Overrun Interrupt Enable */
#define ADC_INTENSET_OVERRUN			1u
	/* Window Monitor Interrupt Enable */
#define ADC_INTENSET_WINMON			2u
	/* Synchronization Ready Interrupt Enable */
#define ADC_INTENSET_SYNCRDY			3u

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Result Ready */
#define ADC_INTFLAG_RESRDY			0u
	/* Overrun */
#define ADC_INTFLAG_OVERRUN			1u
	/* Window Monitor */
#define ADC_INTFLAG_WINMON			2u
	/* Synchronization Ready */
#define ADC_INTFLAG_SYNCRDY			3u

	/* 0x19: Status */
	uint8_t volatile const STATUS;
	/* Synchronization Busy */
#define ADC_STATUS_SYNCBUSY			7u

	/* 0x1A: Result */
	uint16_t volatile const RESULT;
	/* Result Conversion Value */
#define ADC_RESULT_RESULT_Lsb			0u
#define ADC_RESULT_RESULT_Msb			15u

	/* 0x1C: Window Monitor Lower Threshold */
	uint16_t volatile WINLT;
	/* Window Lower Threshold */
#define ADC_WINLT_WINLT_Lsb			0u
#define ADC_WINLT_WINLT_Msb			15u

	/* 0x1E */
	uint8_t volatile RESERVED4[0x20-0x1E];

	/* 0x20: Window Monitor Upper Threshold */
	uint16_t volatile WINUT;
	/* Window Upper Threshold */
#define ADC_WINUT_WINUT_Lsb			0u
#define ADC_WINUT_WINUT_Msb			15u

	/* 0x22 */
	uint8_t volatile RESERVED5[0x24-0x22];

	/* 0x24: Gain Correction */
	uint16_t volatile GAINCORR;
	/* Gain Correction Value */
#define ADC_GAINCORR_GAINCORR_Lsb		0u
#define ADC_GAINCORR_GAINCORR_Msb		11u

	/* 0x26: Offset Correction */
	uint16_t volatile OFFSETCORR;
	/* Offset Correction Value */
#define ADC_OFFSETCORR_OFFSETCORR_Lsb		0u
#define ADC_OFFSETCORR_OFFSETCORR_Msb		11u

	/* 0x28: Calibration */
	uint16_t volatile CALIB;
	/* Linearity Calibration Value */
#define ADC_CALIB_LINEARITY_CAL_Lsb		0u
#define ADC_CALIB_LINEARITY_CAL_Msb		7u
	/* Bias Calibration Value */
#define ADC_CALIB_BIAS_CAL_Lsb			8u
#define ADC_CALIB_BIAS_CAL_Msb			10u

	/* 0x2A: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Run */
#define ADC_DBGCTRL_DBGRUN			0u

};


#define DMAC ((struct zmcu_dmac *)0x41004800)

/* Direct Memory Access Controller */
struct zmcu_dmac {

	/* 0x00: Control */
	uint16_t volatile CTRL;
	/* Software Reset */
#define DMAC_CTRL_SWRST				0u
	/* DMA Enable */
#define DMAC_CTRL_DMAENABLE			1u
	/* CRC Enable */
#define DMAC_CTRL_CRCENABLE			2u
	/* Priority Level 0 Enable */
#define DMAC_CTRL_LVLEN0			8u
	/* Priority Level 1 Enable */
#define DMAC_CTRL_LVLEN1			9u
	/* Priority Level 2 Enable */
#define DMAC_CTRL_LVLEN2			10u
	/* Priority Level 3 Enable */
#define DMAC_CTRL_LVLEN3			11u

	/* 0x02: CRC Control */
	uint16_t volatile CRCCTRL;
	/* CRC Beat Size */
#define DMAC_CRCCTRL_CRCBEATSIZE_Lsb		0u
#define DMAC_CRCCTRL_CRCBEATSIZE_Msb		1u
#define DMAC_CRCCTRL_CRCBEATSIZE_BYTE		0x0
#define DMAC_CRCCTRL_CRCBEATSIZE_HWORD		0x1
#define DMAC_CRCCTRL_CRCBEATSIZE_WORD		0x2
	/* CRC Polynomial Type */
#define DMAC_CRCCTRL_CRCPOLY_Lsb		2u
#define DMAC_CRCCTRL_CRCPOLY_Msb		3u
#define DMAC_CRCCTRL_CRCPOLY_CRC16		0x0
#define DMAC_CRCCTRL_CRCPOLY_CRC32		0x1
	/* CRC Input Source */
#define DMAC_CRCCTRL_CRCSRC_Lsb			8u
#define DMAC_CRCCTRL_CRCSRC_Msb			13u
#define DMAC_CRCCTRL_CRCSRC_NOACT		0x0
#define DMAC_CRCCTRL_CRCSRC_IO			0x1

	/* 0x04: CRC Data Input */
	uint32_t volatile CRCDATAIN;
	/* CRC Data Input */
#define DMAC_CRCDATAIN_CRCDATAIN_Lsb		0u
#define DMAC_CRCDATAIN_CRCDATAIN_Msb		31u

	/* 0x08: CRC Checksum */
	uint32_t volatile CRCCHKSUM;
	/* CRC Checksum */
#define DMAC_CRCCHKSUM_CRCCHKSUM_Lsb		0u
#define DMAC_CRCCHKSUM_CRCCHKSUM_Msb		31u

	/* 0x0C: CRC Status */
	uint8_t volatile CRCSTATUS;
	/* CRC Module Busy */
#define DMAC_CRCSTATUS_CRCBUSY			0u
	/* CRC Zero */
#define DMAC_CRCSTATUS_CRCZERO			1u

	/* 0x0D: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Run */
#define DMAC_DBGCTRL_DBGRUN			0u

	/* 0x0E: QOS Control */
	uint8_t volatile QOSCTRL;
	/* Write-Back Quality of Service */
#define DMAC_QOSCTRL_WRBQOS_Lsb			0u
#define DMAC_QOSCTRL_WRBQOS_Msb			1u
#define DMAC_QOSCTRL_WRBQOS_DISABLE		0x0
#define DMAC_QOSCTRL_WRBQOS_LOW			0x1
#define DMAC_QOSCTRL_WRBQOS_MEDIUM		0x2
#define DMAC_QOSCTRL_WRBQOS_HIGH		0x3
	/* Fetch Quality of Service */
#define DMAC_QOSCTRL_FQOS_Lsb			2u
#define DMAC_QOSCTRL_FQOS_Msb			3u
#define DMAC_QOSCTRL_FQOS_DISABLE		0x0
#define DMAC_QOSCTRL_FQOS_LOW			0x1
#define DMAC_QOSCTRL_FQOS_MEDIUM		0x2
#define DMAC_QOSCTRL_FQOS_HIGH			0x3
	/* Data Transfer Quality of Service */
#define DMAC_QOSCTRL_DQOS_Lsb			4u
#define DMAC_QOSCTRL_DQOS_Msb			5u
#define DMAC_QOSCTRL_DQOS_DISABLE		0x0
#define DMAC_QOSCTRL_DQOS_LOW			0x1
#define DMAC_QOSCTRL_DQOS_MEDIUM		0x2
#define DMAC_QOSCTRL_DQOS_HIGH			0x3

	/* 0x0F */
	uint8_t volatile RESERVED0[0x10-0x0F];

	/* 0x10: Software Trigger Control */
	uint32_t volatile SWTRIGCTRL;
	/* Channel 0 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG0			0u
	/* Channel 1 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG1			1u
	/* Channel 2 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG2			2u
	/* Channel 3 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG3			3u
	/* Channel 4 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG4			4u
	/* Channel 5 Software Trigger */
#define DMAC_SWTRIGCTRL_SWTRIG5			5u

	/* 0x14: Priority Control 0 */
	uint32_t volatile PRICTRL0;
	/* Level 0 Channel Priority Number */
#define DMAC_PRICTRL0_LVLPRI0_Lsb		0u
#define DMAC_PRICTRL0_LVLPRI0_Msb		2u
	/* Level 0 Round-Robin Scheduling Enable */
#define DMAC_PRICTRL0_RRLVLEN0			7u
	/* Level 1 Channel Priority Number */
#define DMAC_PRICTRL0_LVLPRI1_Lsb		8u
#define DMAC_PRICTRL0_LVLPRI1_Msb		10u
	/* Level 1 Round-Robin Scheduling Enable */
#define DMAC_PRICTRL0_RRLVLEN1			15u
	/* Level 2 Channel Priority Number */
#define DMAC_PRICTRL0_LVLPRI2_Lsb		16u
#define DMAC_PRICTRL0_LVLPRI2_Msb		18u
	/* Level 2 Round-Robin Scheduling Enable */
#define DMAC_PRICTRL0_RRLVLEN2			23u
	/* Level 3 Channel Priority Number */
#define DMAC_PRICTRL0_LVLPRI3_Lsb		24u
#define DMAC_PRICTRL0_LVLPRI3_Msb		26u
	/* Level 3 Round-Robin Scheduling Enable */
#define DMAC_PRICTRL0_RRLVLEN3			31u

	/* 0x18 */
	uint8_t volatile RESERVED1[0x20-0x18];

	/* 0x20: Interrupt Pending */
	uint16_t volatile INTPEND;
	/* Channel ID */
#define DMAC_INTPEND_ID_Lsb			0u
#define DMAC_INTPEND_ID_Msb			2u
	/* Transfer Error */
#define DMAC_INTPEND_TERR			8u
	/* Transfer Complete */
#define DMAC_INTPEND_TCMPL			9u
	/* Channel Suspend */
#define DMAC_INTPEND_SUSP			10u
	/* Fetch Error */
#define DMAC_INTPEND_FERR			13u
	/* Busy */
#define DMAC_INTPEND_BUSY			14u
	/* Pending */
#define DMAC_INTPEND_PEND			15u

	/* 0x22 */
	uint8_t volatile RESERVED2[0x24-0x22];

	/* 0x24: Interrupt Status */
	uint32_t volatile const INTSTATUS;
	/* Channel 0 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT0			0u
	/* Channel 1 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT1			1u
	/* Channel 2 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT2			2u
	/* Channel 3 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT3			3u
	/* Channel 4 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT4			4u
	/* Channel 5 Pending Interrupt */
#define DMAC_INTSTATUS_CHINT5			5u

	/* 0x28: Busy Channels */
	uint32_t volatile const BUSYCH;
	/* Busy Channel 0 */
#define DMAC_BUSYCH_BUSYCH0			0u
	/* Busy Channel 1 */
#define DMAC_BUSYCH_BUSYCH1			1u
	/* Busy Channel 2 */
#define DMAC_BUSYCH_BUSYCH2			2u
	/* Busy Channel 3 */
#define DMAC_BUSYCH_BUSYCH3			3u
	/* Busy Channel 4 */
#define DMAC_BUSYCH_BUSYCH4			4u
	/* Busy Channel 5 */
#define DMAC_BUSYCH_BUSYCH5			5u

	/* 0x2C: Pending Channels */
	uint32_t volatile const PENDCH;
	/* Pending Channel 0 */
#define DMAC_PENDCH_PENDCH0			0u
	/* Pending Channel 1 */
#define DMAC_PENDCH_PENDCH1			1u
	/* Pending Channel 2 */
#define DMAC_PENDCH_PENDCH2			2u
	/* Pending Channel 3 */
#define DMAC_PENDCH_PENDCH3			3u
	/* Pending Channel 4 */
#define DMAC_PENDCH_PENDCH4			4u
	/* Pending Channel 5 */
#define DMAC_PENDCH_PENDCH5			5u

	/* 0x30: Active Channel and Levels */
	uint32_t volatile const ACTIVE;
	/* Level 0 Channel Trigger Request Executing */
#define DMAC_ACTIVE_LVLEX0			0u
	/* Level 1 Channel Trigger Request Executing */
#define DMAC_ACTIVE_LVLEX1			1u
	/* Level 2 Channel Trigger Request Executing */
#define DMAC_ACTIVE_LVLEX2			2u
	/* Level 3 Channel Trigger Request Executing */
#define DMAC_ACTIVE_LVLEX3			3u
	/* Active Channel ID */
#define DMAC_ACTIVE_ID_Lsb			8u
#define DMAC_ACTIVE_ID_Msb			12u
	/* Active Channel Busy */
#define DMAC_ACTIVE_ABUSY			15u
	/* Active Channel Block Transfer Count */
#define DMAC_ACTIVE_BTCNT_Lsb			16u
#define DMAC_ACTIVE_BTCNT_Msb			31u

	/* 0x34: Descriptor Memory Section Base Address */
	uint32_t volatile BASEADDR;
	/* Descriptor Memory Base Address */
#define DMAC_BASEADDR_BASEADDR_Lsb		0u
#define DMAC_BASEADDR_BASEADDR_Msb		31u

	/* 0x38: Write-Back Memory Section Base Address */
	uint32_t volatile WRBADDR;
	/* Write-Back Memory Base Address */
#define DMAC_WRBADDR_WRBADDR_Lsb		0u
#define DMAC_WRBADDR_WRBADDR_Msb		31u

	/* 0x3C */
	uint8_t volatile RESERVED3[0x3F-0x3C];

	/* 0x3F: Channel ID */
	uint8_t volatile CHID;
	/* Channel ID */
#define DMAC_CHID_ID_Lsb			0u
#define DMAC_CHID_ID_Msb			2u

	/* 0x40: Channel Control A */
	uint8_t volatile CHCTRLA;
	/* Channel Software Reset */
#define DMAC_CHCTRLA_SWRST			0u
	/* Channel Enable */
#define DMAC_CHCTRLA_ENABLE			1u

	/* 0x41 */
	uint8_t volatile RESERVED4[0x44-0x41];

	/* 0x44: Channel Control B */
	uint32_t volatile CHCTRLB;
	/* Event Input Action */
#define DMAC_CHCTRLB_EVACT_Lsb			0u
#define DMAC_CHCTRLB_EVACT_Msb			2u
#define DMAC_CHCTRLB_EVACT_NOACT		0x0
#define DMAC_CHCTRLB_EVACT_TRIG			0x1
#define DMAC_CHCTRLB_EVACT_CTRIG		0x2
#define DMAC_CHCTRLB_EVACT_CBLOCK		0x3
#define DMAC_CHCTRLB_EVACT_SUSPEND		0x4
#define DMAC_CHCTRLB_EVACT_RESUME		0x5
#define DMAC_CHCTRLB_EVACT_SSKIP		0x6
	/* Channel Event Input Enable */
#define DMAC_CHCTRLB_EVIE			3u
	/* Channel Event Output Enable */
#define DMAC_CHCTRLB_EVOE			4u
	/* Channel Arbitration Level */
#define DMAC_CHCTRLB_LVL_Lsb			5u
#define DMAC_CHCTRLB_LVL_Msb			6u
#define DMAC_CHCTRLB_LVL_LVL0			0x0
#define DMAC_CHCTRLB_LVL_LVL1			0x1
#define DMAC_CHCTRLB_LVL_LVL2			0x2
#define DMAC_CHCTRLB_LVL_LVL3			0x3
	/* Trigger Source */
#define DMAC_CHCTRLB_TRIGSRC_Lsb		8u
#define DMAC_CHCTRLB_TRIGSRC_Msb		12u
#define DMAC_CHCTRLB_TRIGSRC_DISABLE		0x0
	/* Trigger Action */
#define DMAC_CHCTRLB_TRIGACT_Lsb		22u
#define DMAC_CHCTRLB_TRIGACT_Msb		23u
#define DMAC_CHCTRLB_TRIGACT_BLOCK		0x0
#define DMAC_CHCTRLB_TRIGACT_BEAT		0x2
#define DMAC_CHCTRLB_TRIGACT_TRANSACTION	0x3
	/* Software Command */
#define DMAC_CHCTRLB_CMD_Lsb			24u
#define DMAC_CHCTRLB_CMD_Msb			25u
#define DMAC_CHCTRLB_CMD_NOACT			0x0
#define DMAC_CHCTRLB_CMD_SUSPEND		0x1
#define DMAC_CHCTRLB_CMD_RESUME			0x2

	/* 0x48 */
	uint8_t volatile RESERVED5[0x4C-0x48];

	/* 0x4C: Channel Interrupt Enable Clear */
	uint8_t volatile CHINTENCLR;
	/* Channel Transfer Error Interrupt Enable */
#define DMAC_CHINTENCLR_TERR			0u
	/* Channel Transfer Complete Interrupt Enable */
#define DMAC_CHINTENCLR_TCMPL			1u
	/* Channel Suspend Interrupt Enable */
#define DMAC_CHINTENCLR_SUSP			2u

	/* 0x4D: Channel Interrupt Enable Set */
	uint8_t volatile CHINTENSET;
	/* Channel Transfer Error Interrupt Enable */
#define DMAC_CHINTENSET_TERR			0u
	/* Channel Transfer Complete Interrupt Enable */
#define DMAC_CHINTENSET_TCMPL			1u
	/* Channel Suspend Interrupt Enable */
#define DMAC_CHINTENSET_SUSP			2u

	/* 0x4E: Channel Interrupt Flag Status and Clear */
	uint8_t volatile CHINTFLAG;
	/* Channel Transfer Error */
#define DMAC_CHINTFLAG_TERR			0u
	/* Channel Transfer Complete */
#define DMAC_CHINTFLAG_TCMPL			1u
	/* Channel Suspend */
#define DMAC_CHINTFLAG_SUSP			2u

	/* 0x4F: Channel Status */
	uint8_t volatile const CHSTATUS;
	/* Channel Pending */
#define DMAC_CHSTATUS_PEND			0u
	/* Channel Busy */
#define DMAC_CHSTATUS_BUSY			1u
	/* Channel Fetch Error */
#define DMAC_CHSTATUS_FERR			2u

};


#define DSU ((struct zmcu_dsu *)0x41002000)

/* Device Service Unit */
struct zmcu_dsu {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Software Reset */
#define DSU_CTRL_SWRST				0u
	/* 32-bit Cyclic Redundancy Code */
#define DSU_CTRL_CRC				2u
	/* Memory built-in self-test */
#define DSU_CTRL_MBIST				3u
	/* Chip-Erase */
#define DSU_CTRL_CE				4u
	/* Auxiliary Row Read */
#define DSU_CTRL_ARR				6u
	/* Start Memory Stream Access */
#define DSU_CTRL_SMSA				7u

	/* 0x01: Status A */
	uint8_t volatile STATUSA;
	/* Done */
#define DSU_STATUSA_DONE			0u
	/* CPU Reset Phase Extension */
#define DSU_STATUSA_CRSTEXT			1u
	/* Bus Error */
#define DSU_STATUSA_BERR			2u
	/* Failure */
#define DSU_STATUSA_FAIL			3u
	/* Protection Error */
#define DSU_STATUSA_PERR			4u

	/* 0x02: Status B */
	uint8_t volatile const STATUSB;
	/* Protected */
#define DSU_STATUSB_PROT			0u
	/* Debugger Present */
#define DSU_STATUSB_DBGPRES			1u
	/* Debug Communication Channel 0 Dirty */
#define DSU_STATUSB_DCCD0			2u
	/* Debug Communication Channel 1 Dirty */
#define DSU_STATUSB_DCCD1			3u
	/* Hot-Plugging Enable */
#define DSU_STATUSB_HPE				4u

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Address */
	uint32_t volatile ADDR;
	/* Access Mode */
#define DSU_ADDR_AMOD_Lsb			0u
#define DSU_ADDR_AMOD_Msb			1u
	/* Address */
#define DSU_ADDR_ADDR_Lsb			2u
#define DSU_ADDR_ADDR_Msb			31u

	/* 0x08: Length */
	uint32_t volatile LENGTH;
	/* Length */
#define DSU_LENGTH_LENGTH_Lsb			2u
#define DSU_LENGTH_LENGTH_Msb			31u

	/* 0x0C: Data */
	uint32_t volatile DATA;
	/* Data */
#define DSU_DATA_DATA_Lsb			0u
#define DSU_DATA_DATA_Msb			31u

	/* 0x10: Debug Communication Channel n */
	uint32_t volatile DCC[2];
	/* Data */
#define DSU_DCC_DATA_Lsb			0u
#define DSU_DCC_DATA_Msb			31u

	/* 0x18: Device Identification */
	uint32_t volatile const DID;
	/* Device Select */
#define DSU_DID_DEVSEL_Lsb			0u
#define DSU_DID_DEVSEL_Msb			7u
	/* Revision Number */
#define DSU_DID_REVISION_Lsb			8u
#define DSU_DID_REVISION_Msb			11u
	/* Die Number */
#define DSU_DID_DIE_Lsb				12u
#define DSU_DID_DIE_Msb				15u
	/* Series */
#define DSU_DID_SERIES_Lsb			16u
#define DSU_DID_SERIES_Msb			21u
#define DSU_DID_SERIES_0			0x0
#define DSU_DID_SERIES_1			0x1
	/* Family */
#define DSU_DID_FAMILY_Lsb			23u
#define DSU_DID_FAMILY_Msb			27u
#define DSU_DID_FAMILY_0			0x0
#define DSU_DID_FAMILY_1			0x1
	/* Processor */
#define DSU_DID_PROCESSOR_Lsb			28u
#define DSU_DID_PROCESSOR_Msb			31u
#define DSU_DID_PROCESSOR_0			0x0
#define DSU_DID_PROCESSOR_1			0x1
#define DSU_DID_PROCESSOR_2			0x2
#define DSU_DID_PROCESSOR_3			0x3

	/* 0x1C */
	uint8_t volatile RESERVED1[0xF0-0x1C];

	/* 0xF0: Device Configuration */
	uint32_t volatile DCFG[2];
	/* Device Configuration */
#define DSU_DCFG_DCFG_Lsb			0u
#define DSU_DCFG_DCFG_Msb			31u

	/* 0x130 */
	uint8_t volatile RESERVED2[0x1000-0x130];

	/* 0x1000: CoreSight ROM Table Entry 0 */
	uint32_t volatile const ENTRY0;
	/* Entry Present */
#define DSU_ENTRY0_EPRES			0u
	/* Format */
#define DSU_ENTRY0_FMT				1u
	/* Address Offset */
#define DSU_ENTRY0_ADDOFF_Lsb			12u
#define DSU_ENTRY0_ADDOFF_Msb			31u

	/* 0x1004: CoreSight ROM Table Entry 1 */
	uint32_t volatile const ENTRY1;

	/* 0x1008: CoreSight ROM Table End */
	uint32_t volatile const END;
	/* End Marker */
#define DSU_END_END_Lsb				0u
#define DSU_END_END_Msb				31u

	/* 0x100C */
	uint8_t volatile RESERVED3[0x1FCC-0x100C];

	/* 0x1FCC: CoreSight ROM Table Memory Type */
	uint32_t volatile const MEMTYPE;
	/* System Memory Present */
#define DSU_MEMTYPE_SMEMP			0u

	/* 0x1FD0: Peripheral Identification 4 */
	uint32_t volatile const PID4;
	/* JEP-106 Continuation Code */
#define DSU_PID4_JEPCC_Lsb			0u
#define DSU_PID4_JEPCC_Msb			3u
	/* 4KB count */
#define DSU_PID4_FKBC_Lsb			4u
#define DSU_PID4_FKBC_Msb			7u

	/* 0x1FD4: Peripheral Identification 5 */
	uint32_t volatile const PID5;

	/* 0x1FD8: Peripheral Identification 6 */
	uint32_t volatile const PID6;

	/* 0x1FDC: Peripheral Identification 7 */
	uint32_t volatile const PID7;

	/* 0x1FE0: Peripheral Identification 0 */
	uint32_t volatile const PID0;
	/* Part Number Low */
#define DSU_PID0_PARTNBL_Lsb			0u
#define DSU_PID0_PARTNBL_Msb			7u

	/* 0x1FE4: Peripheral Identification 1 */
	uint32_t volatile const PID1;
	/* Part Number High */
#define DSU_PID1_PARTNBH_Lsb			0u
#define DSU_PID1_PARTNBH_Msb			3u
	/* Low part of the JEP-106 Identity Code */
#define DSU_PID1_JEPIDCL_Lsb			4u
#define DSU_PID1_JEPIDCL_Msb			7u

	/* 0x1FE8: Peripheral Identification 2 */
	uint32_t volatile const PID2;
	/* JEP-106 Identity Code High */
#define DSU_PID2_JEPIDCH_Lsb			0u
#define DSU_PID2_JEPIDCH_Msb			2u
	/* JEP-106 Identity Code is used */
#define DSU_PID2_JEPU				3u
	/* Revision Number */
#define DSU_PID2_REVISION_Lsb			4u
#define DSU_PID2_REVISION_Msb			7u

	/* 0x1FEC: Peripheral Identification 3 */
	uint32_t volatile const PID3;
	/* ARM CUSMOD */
#define DSU_PID3_CUSMOD_Lsb			0u
#define DSU_PID3_CUSMOD_Msb			3u
	/* Revision Number */
#define DSU_PID3_REVAND_Lsb			4u
#define DSU_PID3_REVAND_Msb			7u

	/* 0x1FF0: Component Identification 0 */
	uint32_t volatile const CID0;
	/* Preamble Byte 0 */
#define DSU_CID0_PREAMBLEB0_Lsb			0u
#define DSU_CID0_PREAMBLEB0_Msb			7u

	/* 0x1FF4: Component Identification 1 */
	uint32_t volatile const CID1;
	/* Preamble */
#define DSU_CID1_PREAMBLE_Lsb			0u
#define DSU_CID1_PREAMBLE_Msb			3u
	/* Component Class */
#define DSU_CID1_CCLASS_Lsb			4u
#define DSU_CID1_CCLASS_Msb			7u

	/* 0x1FF8: Component Identification 2 */
	uint32_t volatile const CID2;
	/* Preamble Byte 2 */
#define DSU_CID2_PREAMBLEB2_Lsb			0u
#define DSU_CID2_PREAMBLEB2_Msb			7u

	/* 0x1FFC: Component Identification 3 */
	uint32_t volatile const CID3;
	/* Preamble Byte 3 */
#define DSU_CID3_PREAMBLEB3_Lsb			0u
#define DSU_CID3_PREAMBLEB3_Msb			7u

};


#define EIC ((struct zmcu_eic *)0x40001800)

/* External Interrupt Controller */
struct zmcu_eic {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Software Reset */
#define EIC_CTRL_SWRST				0u
	/* Enable */
#define EIC_CTRL_ENABLE				1u

	/* 0x01: Status */
	uint8_t volatile const STATUS;
	/* Synchronization Busy */
#define EIC_STATUS_SYNCBUSY			7u

	/* 0x02: Non-Maskable Interrupt Control */
	uint8_t volatile NMICTRL;
	/* Non-Maskable Interrupt Sense */
#define EIC_NMICTRL_NMISENSE_Lsb		0u
#define EIC_NMICTRL_NMISENSE_Msb		2u
#define EIC_NMICTRL_NMISENSE_NONE		0x0
#define EIC_NMICTRL_NMISENSE_RISE		0x1
#define EIC_NMICTRL_NMISENSE_FALL		0x2
#define EIC_NMICTRL_NMISENSE_BOTH		0x3
#define EIC_NMICTRL_NMISENSE_HIGH		0x4
#define EIC_NMICTRL_NMISENSE_LOW		0x5
	/* Non-Maskable Interrupt Filter Enable */
#define EIC_NMICTRL_NMIFILTEN			3u

	/* 0x03: Non-Maskable Interrupt Flag Status and Clear */
	uint8_t volatile NMIFLAG;
	/* Non-Maskable Interrupt */
#define EIC_NMIFLAG_NMI				0u

	/* 0x04: Event Control */
	uint32_t volatile EVCTRL;
	/* External Interrupt 0 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO0			0u
	/* External Interrupt 1 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO1			1u
	/* External Interrupt 2 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO2			2u
	/* External Interrupt 3 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO3			3u
	/* External Interrupt 4 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO4			4u
	/* External Interrupt 5 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO5			5u
	/* External Interrupt 6 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO6			6u
	/* External Interrupt 7 Event Output Enable */
#define EIC_EVCTRL_EXTINTEO7			7u

	/* 0x08: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
	/* External Interrupt 0 Enable */
#define EIC_INTENCLR_EXTINT0			0u
	/* External Interrupt 1 Enable */
#define EIC_INTENCLR_EXTINT1			1u
	/* External Interrupt 2 Enable */
#define EIC_INTENCLR_EXTINT2			2u
	/* External Interrupt 3 Enable */
#define EIC_INTENCLR_EXTINT3			3u
	/* External Interrupt 4 Enable */
#define EIC_INTENCLR_EXTINT4			4u
	/* External Interrupt 5 Enable */
#define EIC_INTENCLR_EXTINT5			5u
	/* External Interrupt 6 Enable */
#define EIC_INTENCLR_EXTINT6			6u
	/* External Interrupt 7 Enable */
#define EIC_INTENCLR_EXTINT7			7u

	/* 0x0C: Interrupt Enable Set */
	uint32_t volatile INTENSET;
	/* External Interrupt 0 Enable */
#define EIC_INTENSET_EXTINT0			0u
	/* External Interrupt 1 Enable */
#define EIC_INTENSET_EXTINT1			1u
	/* External Interrupt 2 Enable */
#define EIC_INTENSET_EXTINT2			2u
	/* External Interrupt 3 Enable */
#define EIC_INTENSET_EXTINT3			3u
	/* External Interrupt 4 Enable */
#define EIC_INTENSET_EXTINT4			4u
	/* External Interrupt 5 Enable */
#define EIC_INTENSET_EXTINT5			5u
	/* External Interrupt 6 Enable */
#define EIC_INTENSET_EXTINT6			6u
	/* External Interrupt 7 Enable */
#define EIC_INTENSET_EXTINT7			7u

	/* 0x10: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
	/* External Interrupt 0 */
#define EIC_INTFLAG_EXTINT0			0u
	/* External Interrupt 1 */
#define EIC_INTFLAG_EXTINT1			1u
	/* External Interrupt 2 */
#define EIC_INTFLAG_EXTINT2			2u
	/* External Interrupt 3 */
#define EIC_INTFLAG_EXTINT3			3u
	/* External Interrupt 4 */
#define EIC_INTFLAG_EXTINT4			4u
	/* External Interrupt 5 */
#define EIC_INTFLAG_EXTINT5			5u
	/* External Interrupt 6 */
#define EIC_INTFLAG_EXTINT6			6u
	/* External Interrupt 7 */
#define EIC_INTFLAG_EXTINT7			7u

	/* 0x14: Wake-Up Enable */
	uint32_t volatile WAKEUP;
	/* External Interrupt 0 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN0			0u
	/* External Interrupt 1 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN1			1u
	/* External Interrupt 2 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN2			2u
	/* External Interrupt 3 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN3			3u
	/* External Interrupt 4 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN4			4u
	/* External Interrupt 5 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN5			5u
	/* External Interrupt 6 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN6			6u
	/* External Interrupt 7 Wake-up Enable */
#define EIC_WAKEUP_WAKEUPEN7			7u

	/* 0x18: Configuration n */
	uint32_t volatile CONFIG;
	/* Input Sense 0 Configuration */
#define EIC_CONFIG_SENSE0_Lsb			0u
#define EIC_CONFIG_SENSE0_Msb			2u
#define EIC_CONFIG_SENSE0_NONE			0x0
#define EIC_CONFIG_SENSE0_RISE			0x1
#define EIC_CONFIG_SENSE0_FALL			0x2
#define EIC_CONFIG_SENSE0_BOTH			0x3
#define EIC_CONFIG_SENSE0_HIGH			0x4
#define EIC_CONFIG_SENSE0_LOW			0x5
	/* Filter 0 Enable */
#define EIC_CONFIG_FILTEN0			3u
	/* Input Sense 1 Configuration */
#define EIC_CONFIG_SENSE1_Lsb			4u
#define EIC_CONFIG_SENSE1_Msb			6u
#define EIC_CONFIG_SENSE1_NONE			0x0
#define EIC_CONFIG_SENSE1_RISE			0x1
#define EIC_CONFIG_SENSE1_FALL			0x2
#define EIC_CONFIG_SENSE1_BOTH			0x3
#define EIC_CONFIG_SENSE1_HIGH			0x4
#define EIC_CONFIG_SENSE1_LOW			0x5
	/* Filter 1 Enable */
#define EIC_CONFIG_FILTEN1			7u
	/* Input Sense 2 Configuration */
#define EIC_CONFIG_SENSE2_Lsb			8u
#define EIC_CONFIG_SENSE2_Msb			10u
#define EIC_CONFIG_SENSE2_NONE			0x0
#define EIC_CONFIG_SENSE2_RISE			0x1
#define EIC_CONFIG_SENSE2_FALL			0x2
#define EIC_CONFIG_SENSE2_BOTH			0x3
#define EIC_CONFIG_SENSE2_HIGH			0x4
#define EIC_CONFIG_SENSE2_LOW			0x5
	/* Filter 2 Enable */
#define EIC_CONFIG_FILTEN2			11u
	/* Input Sense 3 Configuration */
#define EIC_CONFIG_SENSE3_Lsb			12u
#define EIC_CONFIG_SENSE3_Msb			14u
#define EIC_CONFIG_SENSE3_NONE			0x0
#define EIC_CONFIG_SENSE3_RISE			0x1
#define EIC_CONFIG_SENSE3_FALL			0x2
#define EIC_CONFIG_SENSE3_BOTH			0x3
#define EIC_CONFIG_SENSE3_HIGH			0x4
#define EIC_CONFIG_SENSE3_LOW			0x5
	/* Filter 3 Enable */
#define EIC_CONFIG_FILTEN3			15u
	/* Input Sense 4 Configuration */
#define EIC_CONFIG_SENSE4_Lsb			16u
#define EIC_CONFIG_SENSE4_Msb			18u
#define EIC_CONFIG_SENSE4_NONE			0x0
#define EIC_CONFIG_SENSE4_RISE			0x1
#define EIC_CONFIG_SENSE4_FALL			0x2
#define EIC_CONFIG_SENSE4_BOTH			0x3
#define EIC_CONFIG_SENSE4_HIGH			0x4
#define EIC_CONFIG_SENSE4_LOW			0x5
	/* Filter 4 Enable */
#define EIC_CONFIG_FILTEN4			19u
	/* Input Sense 5 Configuration */
#define EIC_CONFIG_SENSE5_Lsb			20u
#define EIC_CONFIG_SENSE5_Msb			22u
#define EIC_CONFIG_SENSE5_NONE			0x0
#define EIC_CONFIG_SENSE5_RISE			0x1
#define EIC_CONFIG_SENSE5_FALL			0x2
#define EIC_CONFIG_SENSE5_BOTH			0x3
#define EIC_CONFIG_SENSE5_HIGH			0x4
#define EIC_CONFIG_SENSE5_LOW			0x5
	/* Filter 5 Enable */
#define EIC_CONFIG_FILTEN5			23u
	/* Input Sense 6 Configuration */
#define EIC_CONFIG_SENSE6_Lsb			24u
#define EIC_CONFIG_SENSE6_Msb			26u
#define EIC_CONFIG_SENSE6_NONE			0x0
#define EIC_CONFIG_SENSE6_RISE			0x1
#define EIC_CONFIG_SENSE6_FALL			0x2
#define EIC_CONFIG_SENSE6_BOTH			0x3
#define EIC_CONFIG_SENSE6_HIGH			0x4
#define EIC_CONFIG_SENSE6_LOW			0x5
	/* Filter 6 Enable */
#define EIC_CONFIG_FILTEN6			27u
	/* Input Sense 7 Configuration */
#define EIC_CONFIG_SENSE7_Lsb			28u
#define EIC_CONFIG_SENSE7_Msb			30u
#define EIC_CONFIG_SENSE7_NONE			0x0
#define EIC_CONFIG_SENSE7_RISE			0x1
#define EIC_CONFIG_SENSE7_FALL			0x2
#define EIC_CONFIG_SENSE7_BOTH			0x3
#define EIC_CONFIG_SENSE7_HIGH			0x4
#define EIC_CONFIG_SENSE7_LOW			0x5
	/* Filter 7 Enable */
#define EIC_CONFIG_FILTEN7			31u

};


#define EVSYS ((struct zmcu_evsys *)0x42000400)

/* Event System Interface */
struct zmcu_evsys {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Software Reset */
#define EVSYS_CTRL_SWRST			0u
	/* Generic Clock Requests */
#define EVSYS_CTRL_GCLKREQ			4u

	/* 0x01 */
	uint8_t volatile RESERVED0[0x04-0x01];

	/* 0x04: Channel */
	uint32_t volatile CHANNEL;
	/* Channel Selection */
#define EVSYS_CHANNEL_CHANNEL_Lsb		0u
#define EVSYS_CHANNEL_CHANNEL_Msb		2u
	/* Software Event */
#define EVSYS_CHANNEL_SWEVT			8u
	/* Event Generator Selection */
#define EVSYS_CHANNEL_EVGEN_Lsb			16u
#define EVSYS_CHANNEL_EVGEN_Msb			21u
	/* Path Selection */
#define EVSYS_CHANNEL_PATH_Lsb			24u
#define EVSYS_CHANNEL_PATH_Msb			25u
#define EVSYS_CHANNEL_PATH_SYNCHRONOUS		0x0
#define EVSYS_CHANNEL_PATH_RESYNCHRONIZED	0x1
#define EVSYS_CHANNEL_PATH_ASYNCHRONOUS		0x2
	/* Edge Detection Selection */
#define EVSYS_CHANNEL_EDGSEL_Lsb		26u
#define EVSYS_CHANNEL_EDGSEL_Msb		27u
#define EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT	0x0
#define EVSYS_CHANNEL_EDGSEL_RISING_EDGE	0x1
#define EVSYS_CHANNEL_EDGSEL_FALLING_EDGE	0x2
#define EVSYS_CHANNEL_EDGSEL_BOTH_EDGES		0x3

	/* 0x08: User Multiplexer */
	uint16_t volatile USER;
	/* User Multiplexer Selection */
#define EVSYS_USER_USER_Lsb			0u
#define EVSYS_USER_USER_Msb			4u
	/* Channel Event Selection */
#define EVSYS_USER_CHANNEL_Lsb			8u
#define EVSYS_USER_CHANNEL_Msb			11u
#define EVSYS_USER_CHANNEL_0			0x0

	/* 0x0A */
	uint8_t volatile RESERVED1[0x0C-0x0A];

	/* 0x0C: Channel Status */
	uint32_t volatile const CHSTATUS;
	/* Channel 0 User Ready */
#define EVSYS_CHSTATUS_USRRDY0			0u
	/* Channel 1 User Ready */
#define EVSYS_CHSTATUS_USRRDY1			1u
	/* Channel 2 User Ready */
#define EVSYS_CHSTATUS_USRRDY2			2u
	/* Channel 3 User Ready */
#define EVSYS_CHSTATUS_USRRDY3			3u
	/* Channel 4 User Ready */
#define EVSYS_CHSTATUS_USRRDY4			4u
	/* Channel 5 User Ready */
#define EVSYS_CHSTATUS_USRRDY5			5u
	/* Channel 0 Busy */
#define EVSYS_CHSTATUS_CHBUSY0			8u
	/* Channel 1 Busy */
#define EVSYS_CHSTATUS_CHBUSY1			9u
	/* Channel 2 Busy */
#define EVSYS_CHSTATUS_CHBUSY2			10u
	/* Channel 3 Busy */
#define EVSYS_CHSTATUS_CHBUSY3			11u
	/* Channel 4 Busy */
#define EVSYS_CHSTATUS_CHBUSY4			12u
	/* Channel 5 Busy */
#define EVSYS_CHSTATUS_CHBUSY5			13u

	/* 0x10: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
	/* Channel 0 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR0			0u
	/* Channel 1 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR1			1u
	/* Channel 2 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR2			2u
	/* Channel 3 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR3			3u
	/* Channel 4 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR4			4u
	/* Channel 5 Overrun Interrupt Enable */
#define EVSYS_INTENCLR_OVR5			5u
	/* Channel 0 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD0			8u
	/* Channel 1 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD1			9u
	/* Channel 2 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD2			10u
	/* Channel 3 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD3			11u
	/* Channel 4 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD4			12u
	/* Channel 5 Event Detection Interrupt Enable */
#define EVSYS_INTENCLR_EVD5			13u

	/* 0x14: Interrupt Enable Set */
	uint32_t volatile INTENSET;
	/* Channel 0 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR0			0u
	/* Channel 1 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR1			1u
	/* Channel 2 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR2			2u
	/* Channel 3 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR3			3u
	/* Channel 4 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR4			4u
	/* Channel 5 Overrun Interrupt Enable */
#define EVSYS_INTENSET_OVR5			5u
	/* Channel 0 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD0			8u
	/* Channel 1 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD1			9u
	/* Channel 2 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD2			10u
	/* Channel 3 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD3			11u
	/* Channel 4 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD4			12u
	/* Channel 5 Event Detection Interrupt Enable */
#define EVSYS_INTENSET_EVD5			13u

	/* 0x18: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
	/* Channel 0 Overrun */
#define EVSYS_INTFLAG_OVR0			0u
	/* Channel 1 Overrun */
#define EVSYS_INTFLAG_OVR1			1u
	/* Channel 2 Overrun */
#define EVSYS_INTFLAG_OVR2			2u
	/* Channel 3 Overrun */
#define EVSYS_INTFLAG_OVR3			3u
	/* Channel 4 Overrun */
#define EVSYS_INTFLAG_OVR4			4u
	/* Channel 5 Overrun */
#define EVSYS_INTFLAG_OVR5			5u
	/* Channel 0 Event Detection */
#define EVSYS_INTFLAG_EVD0			8u
	/* Channel 1 Event Detection */
#define EVSYS_INTFLAG_EVD1			9u
	/* Channel 2 Event Detection */
#define EVSYS_INTFLAG_EVD2			10u
	/* Channel 3 Event Detection */
#define EVSYS_INTFLAG_EVD3			11u
	/* Channel 4 Event Detection */
#define EVSYS_INTFLAG_EVD4			12u
	/* Channel 5 Event Detection */
#define EVSYS_INTFLAG_EVD5			13u

};


#define GCLK ((struct zmcu_gclk *)0x40000C00)

/* Generic Clock Generator */
struct zmcu_gclk {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Software Reset */
#define GCLK_CTRL_SWRST				0u

	/* 0x01: Status */
	uint8_t volatile const STATUS;
	/* Synchronization Busy Status */
#define GCLK_STATUS_SYNCBUSY			7u

	/* 0x02: Generic Clock Control */
	uint16_t volatile CLKCTRL;
	/* Generic Clock Selection ID */
#define GCLK_CLKCTRL_ID_Lsb			0u
#define GCLK_CLKCTRL_ID_Msb			5u
#define GCLK_CLKCTRL_ID_DFLL48			0x0
#define GCLK_CLKCTRL_ID_FDPLL			0x1
#define GCLK_CLKCTRL_ID_FDPLL32K		0x2
#define GCLK_CLKCTRL_ID_WDT			0x3
#define GCLK_CLKCTRL_ID_RTC			0x4
#define GCLK_CLKCTRL_ID_EIC			0x5
#define GCLK_CLKCTRL_ID_EVSYS_0			0x7
#define GCLK_CLKCTRL_ID_EVSYS_1			0x8
#define GCLK_CLKCTRL_ID_EVSYS_2			0x9
#define GCLK_CLKCTRL_ID_EVSYS_3			0xa
#define GCLK_CLKCTRL_ID_EVSYS_4			0xb
#define GCLK_CLKCTRL_ID_EVSYS_5			0xc
#define GCLK_CLKCTRL_ID_SERCOMX_SLOW		0xd
#define GCLK_CLKCTRL_ID_SERCOM0_CORE		0xe
#define GCLK_CLKCTRL_ID_SERCOM1_CORE		0xf
#define GCLK_CLKCTRL_ID_SERCOM2_CORE		0x10
#define GCLK_CLKCTRL_ID_TC1_TC2			0x12
#define GCLK_CLKCTRL_ID_ADC			0x13
#define GCLK_CLKCTRL_ID_AC_DIG			0x14
#define GCLK_CLKCTRL_ID_AC_ANA			0x15
	/* Generic Clock Generator */
#define GCLK_CLKCTRL_GEN_Lsb			8u
#define GCLK_CLKCTRL_GEN_Msb			11u
#define GCLK_CLKCTRL_GEN_GCLK0			0x0
#define GCLK_CLKCTRL_GEN_GCLK1			0x1
#define GCLK_CLKCTRL_GEN_GCLK2			0x2
#define GCLK_CLKCTRL_GEN_GCLK3			0x3
#define GCLK_CLKCTRL_GEN_GCLK4			0x4
#define GCLK_CLKCTRL_GEN_GCLK5			0x5
	/* Clock Enable */
#define GCLK_CLKCTRL_CLKEN			14u
	/* Write Lock */
#define GCLK_CLKCTRL_WRTLOCK			15u

	/* 0x04: Generic Clock Generator Control */
	uint32_t volatile GENCTRL;
	/* Generic Clock Generator Selection */
#define GCLK_GENCTRL_ID_Lsb			0u
#define GCLK_GENCTRL_ID_Msb			3u
	/* Source Select */
#define GCLK_GENCTRL_SRC_Lsb			8u
#define GCLK_GENCTRL_SRC_Msb			12u
#define GCLK_GENCTRL_SRC_XOSC			0x0
#define GCLK_GENCTRL_SRC_GCLKIN			0x1
#define GCLK_GENCTRL_SRC_GCLKGEN1		0x2
#define GCLK_GENCTRL_SRC_OSCULP32K		0x3
#define GCLK_GENCTRL_SRC_OSC32K			0x4
#define GCLK_GENCTRL_SRC_XOSC32K		0x5
#define GCLK_GENCTRL_SRC_OSC8M			0x6
#define GCLK_GENCTRL_SRC_DFLL48M		0x7
#define GCLK_GENCTRL_SRC_DPLL96M		0x8
	/* Generic Clock Generator Enable */
#define GCLK_GENCTRL_GENEN			16u
	/* Improve Duty Cycle */
#define GCLK_GENCTRL_IDC			17u
	/* Output Off Value */
#define GCLK_GENCTRL_OOV			18u
	/* Output Enable */
#define GCLK_GENCTRL_OE				19u
	/* Divide Selection */
#define GCLK_GENCTRL_DIVSEL			20u
	/* Run in Standby */
#define GCLK_GENCTRL_RUNSTDBY			21u

	/* 0x08: Generic Clock Generator Division */
	uint32_t volatile GENDIV;
	/* Generic Clock Generator Selection */
#define GCLK_GENDIV_ID_Lsb			0u
#define GCLK_GENDIV_ID_Msb			3u
	/* Division Factor */
#define GCLK_GENDIV_DIV_Lsb			8u
#define GCLK_GENDIV_DIV_Msb			23u

};


#define HMATRIX ((struct zmcu_hmatrixb *)0x41007000)

/* HSB Matrix */
struct zmcu_hmatrixb {

	/* 0x0C */
	uint8_t volatile RESERVED0[0x80-0x0C];

	/* 0x80: Priority A for Slave */
	uint64_t volatile PRAS[16];
	/* Master 0 Priority */
#define HMATRIXB_PRAS_M0PR_Lsb			0u
#define HMATRIXB_PRAS_M0PR_Msb			3u
	/* Master 1 Priority */
#define HMATRIXB_PRAS_M1PR_Lsb			4u
#define HMATRIXB_PRAS_M1PR_Msb			7u
	/* Master 2 Priority */
#define HMATRIXB_PRAS_M2PR_Lsb			8u
#define HMATRIXB_PRAS_M2PR_Msb			11u
	/* Master 3 Priority */
#define HMATRIXB_PRAS_M3PR_Lsb			12u
#define HMATRIXB_PRAS_M3PR_Msb			15u
	/* Master 4 Priority */
#define HMATRIXB_PRAS_M4PR_Lsb			16u
#define HMATRIXB_PRAS_M4PR_Msb			19u
	/* Master 5 Priority */
#define HMATRIXB_PRAS_M5PR_Lsb			20u
#define HMATRIXB_PRAS_M5PR_Msb			23u
	/* Master 6 Priority */
#define HMATRIXB_PRAS_M6PR_Lsb			24u
#define HMATRIXB_PRAS_M6PR_Msb			27u
	/* Master 7 Priority */
#define HMATRIXB_PRAS_M7PR_Lsb			28u
#define HMATRIXB_PRAS_M7PR_Msb			31u

	/* 0x84: Priority B for Slave */
	uint64_t volatile PRBS[16];
	/* Master 8 Priority */
#define HMATRIXB_PRBS_M8PR_Lsb			0u
#define HMATRIXB_PRBS_M8PR_Msb			3u
	/* Master 9 Priority */
#define HMATRIXB_PRBS_M9PR_Lsb			4u
#define HMATRIXB_PRBS_M9PR_Msb			7u
	/* Master 10 Priority */
#define HMATRIXB_PRBS_M10PR_Lsb			8u
#define HMATRIXB_PRBS_M10PR_Msb			11u
	/* Master 11 Priority */
#define HMATRIXB_PRBS_M11PR_Lsb			12u
#define HMATRIXB_PRBS_M11PR_Msb			15u
	/* Master 12 Priority */
#define HMATRIXB_PRBS_M12PR_Lsb			16u
#define HMATRIXB_PRBS_M12PR_Msb			19u
	/* Master 13 Priority */
#define HMATRIXB_PRBS_M13PR_Lsb			20u
#define HMATRIXB_PRBS_M13PR_Msb			23u
	/* Master 14 Priority */
#define HMATRIXB_PRBS_M14PR_Lsb			24u
#define HMATRIXB_PRBS_M14PR_Msb			27u
	/* Master 15 Priority */
#define HMATRIXB_PRBS_M15PR_Lsb			28u
#define HMATRIXB_PRBS_M15PR_Msb			31u

	/* 0x110: Special Function */
	uint32_t volatile SFR[16];
	/* Special Function Register */
#define HMATRIXB_SFR_SFR_Lsb			0u
#define HMATRIXB_SFR_SFR_Msb			31u

};


#define MTB ((struct zmcu_mtb *)0x41006000)

/* Cortex-M0+ Micro-Trace Buffer */
struct zmcu_mtb {

	/* 0x00: MTB Position */
	uint32_t volatile POSITION;
	/* Pointer Value Wraps */
#define MTB_POSITION_WRAP			2u
	/* Trace Packet Location Pointer */
#define MTB_POSITION_POINTER_Lsb		3u
#define MTB_POSITION_POINTER_Msb		31u

	/* 0x04: MTB Master */
	uint32_t volatile MASTER;
	/* Maximum Value of the Trace Buffer in SRAM */
#define MTB_MASTER_MASK_Lsb			0u
#define MTB_MASTER_MASK_Msb			4u
	/* Trace Start Input Enable */
#define MTB_MASTER_TSTARTEN			5u
	/* Trace Stop Input Enable */
#define MTB_MASTER_TSTOPEN			6u
	/* Special Function Register Write Privilege */
#define MTB_MASTER_SFRWPRIV			7u
	/* SRAM Privilege */
#define MTB_MASTER_RAMPRIV			8u
	/* Halt Request */
#define MTB_MASTER_HALTREQ			9u
	/* Main Trace Enable */
#define MTB_MASTER_EN				31u

	/* 0x08: MTB Flow */
	uint32_t volatile FLOW;
	/* Auto Stop Tracing */
#define MTB_FLOW_AUTOSTOP			0u
	/* Auto Halt Request */
#define MTB_FLOW_AUTOHALT			1u
	/* Watermark value */
#define MTB_FLOW_WATERMARK_Lsb			3u
#define MTB_FLOW_WATERMARK_Msb			31u

	/* 0x0C: MTB Base */
	uint32_t volatile const BASE;

	/* 0x10 */
	uint8_t volatile RESERVED0[0xF00-0x10];

	/* 0xF00: MTB Integration Mode Control */
	uint32_t volatile ITCTRL;

	/* 0xF04 */
	uint8_t volatile RESERVED1[0xFA0-0xF04];

	/* 0xFA0: MTB Claim Set */
	uint32_t volatile CLAIMSET;

	/* 0xFA4: MTB Claim Clear */
	uint32_t volatile CLAIMCLR;

	/* 0xFA8 */
	uint8_t volatile RESERVED2[0xFB0-0xFA8];

	/* 0xFB0: MTB Lock Access */
	uint32_t volatile LOCKACCESS;

	/* 0xFB4: MTB Lock Status */
	uint32_t volatile const LOCKSTATUS;

	/* 0xFB8: MTB Authentication Status */
	uint32_t volatile const AUTHSTATUS;

	/* 0xFBC: MTB Device Architecture */
	uint32_t volatile const DEVARCH;

	/* 0xFC0 */
	uint8_t volatile RESERVED3[0xFC8-0xFC0];

	/* 0xFC8: MTB Device Configuration */
	uint32_t volatile const DEVID;

	/* 0xFCC: MTB Device Type */
	uint32_t volatile const DEVTYPE;

	/* 0xFD0: CoreSight */
	uint32_t volatile const PID4;

	/* 0xFD4: CoreSight */
	uint32_t volatile const PID5;

	/* 0xFD8: CoreSight */
	uint32_t volatile const PID6;

	/* 0xFDC: CoreSight */
	uint32_t volatile const PID7;

	/* 0xFE0: CoreSight */
	uint32_t volatile const PID0;

	/* 0xFE4: CoreSight */
	uint32_t volatile const PID1;

	/* 0xFE8: CoreSight */
	uint32_t volatile const PID2;

	/* 0xFEC: CoreSight */
	uint32_t volatile const PID3;

	/* 0xFF0: CoreSight */
	uint32_t volatile const CID0;

	/* 0xFF4: CoreSight */
	uint32_t volatile const CID1;

	/* 0xFF8: CoreSight */
	uint32_t volatile const CID2;

	/* 0xFFC: CoreSight */
	uint32_t volatile const CID3;

};


#define NVMCTRL ((struct zmcu_nvmctrl *)0x41004000)

/* Non-Volatile Memory Controller */
struct zmcu_nvmctrl {

	/* 0x00: Control A */
	uint16_t volatile CTRLA;
	/* Command */
#define NVMCTRL_CTRLA_CMD_Lsb			0u
#define NVMCTRL_CTRLA_CMD_Msb			6u
#define NVMCTRL_CTRLA_CMD_ER			0x2
#define NVMCTRL_CTRLA_CMD_WP			0x4
#define NVMCTRL_CTRLA_CMD_EAR			0x5
#define NVMCTRL_CTRLA_CMD_WAP			0x6
#define NVMCTRL_CTRLA_CMD_SF			0xa
#define NVMCTRL_CTRLA_CMD_WL			0xf
#define NVMCTRL_CTRLA_CMD_LR			0x40
#define NVMCTRL_CTRLA_CMD_UR			0x41
#define NVMCTRL_CTRLA_CMD_SPRM			0x42
#define NVMCTRL_CTRLA_CMD_CPRM			0x43
#define NVMCTRL_CTRLA_CMD_PBC			0x44
#define NVMCTRL_CTRLA_CMD_SSB			0x45
#define NVMCTRL_CTRLA_CMD_INVALL		0x46
	/* Command Execution */
#define NVMCTRL_CTRLA_CMDEX_Lsb			8u
#define NVMCTRL_CTRLA_CMDEX_Msb			15u
#define NVMCTRL_CTRLA_CMDEX_KEY			0xa5

	/* 0x02 */
	uint8_t volatile RESERVED0[0x04-0x02];

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
	/* NVM Read Wait States */
#define NVMCTRL_CTRLB_RWS_Lsb			1u
#define NVMCTRL_CTRLB_RWS_Msb			4u
#define NVMCTRL_CTRLB_RWS_SINGLE		0x0
#define NVMCTRL_CTRLB_RWS_HALF			0x1
#define NVMCTRL_CTRLB_RWS_DUAL			0x2
	/* Manual Write */
#define NVMCTRL_CTRLB_MANW			7u
	/* Power Reduction Mode during Sleep */
#define NVMCTRL_CTRLB_SLEEPPRM_Lsb		8u
#define NVMCTRL_CTRLB_SLEEPPRM_Msb		9u
#define NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS	0x0
#define NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT	0x1
#define NVMCTRL_CTRLB_SLEEPPRM_DISABLED		0x3
	/* NVMCTRL Read Mode */
#define NVMCTRL_CTRLB_READMODE_Lsb		16u
#define NVMCTRL_CTRLB_READMODE_Msb		17u
#define NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY	0x0
#define NVMCTRL_CTRLB_READMODE_LOW_POWER	0x1
#define NVMCTRL_CTRLB_READMODE_DETERMINISTIC	0x2
	/* Cache Disable */
#define NVMCTRL_CTRLB_CACHEDIS			18u

	/* 0x08: NVM Parameter */
	uint32_t volatile PARAM;
	/* NVM Pages */
#define NVMCTRL_PARAM_NVMP_Lsb			0u
#define NVMCTRL_PARAM_NVMP_Msb			15u
	/* Page Size */
#define NVMCTRL_PARAM_PSZ_Lsb			16u
#define NVMCTRL_PARAM_PSZ_Msb			18u
#define NVMCTRL_PARAM_PSZ_8			0x0
#define NVMCTRL_PARAM_PSZ_16			0x1
#define NVMCTRL_PARAM_PSZ_32			0x2
#define NVMCTRL_PARAM_PSZ_64			0x3
#define NVMCTRL_PARAM_PSZ_128			0x4
#define NVMCTRL_PARAM_PSZ_256			0x5
#define NVMCTRL_PARAM_PSZ_512			0x6
#define NVMCTRL_PARAM_PSZ_1024			0x7

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* NVM Ready Interrupt Enable */
#define NVMCTRL_INTENCLR_READY			0u
	/* Error Interrupt Enable */
#define NVMCTRL_INTENCLR_ERROR			1u

	/* 0x0D */
	uint8_t volatile RESERVED1[0x10-0x0D];

	/* 0x10: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* NVM Ready Interrupt Enable */
#define NVMCTRL_INTENSET_READY			0u
	/* Error Interrupt Enable */
#define NVMCTRL_INTENSET_ERROR			1u

	/* 0x11 */
	uint8_t volatile RESERVED2[0x14-0x11];

	/* 0x14: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* NVM Ready */
#define NVMCTRL_INTFLAG_READY			0u
	/* Error */
#define NVMCTRL_INTFLAG_ERROR			1u

	/* 0x15 */
	uint8_t volatile RESERVED3[0x18-0x15];

	/* 0x18: Status */
	uint16_t volatile STATUS;
	/* Power Reduction Mode */
#define NVMCTRL_STATUS_PRM			0u
	/* NVM Page Buffer Active Loading */
#define NVMCTRL_STATUS_LOAD			1u
	/* Programming Error Status */
#define NVMCTRL_STATUS_PROGE			2u
	/* Lock Error Status */
#define NVMCTRL_STATUS_LOCKE			3u
	/* NVM Error */
#define NVMCTRL_STATUS_NVME			4u
	/* Security Bit Status */
#define NVMCTRL_STATUS_SB			8u

	/* 0x1A */
	uint8_t volatile RESERVED4[0x1C-0x1A];

	/* 0x1C: Address */
	uint32_t volatile ADDR;
	/* NVM Address */
#define NVMCTRL_ADDR_ADDR_Lsb			0u
#define NVMCTRL_ADDR_ADDR_Msb			21u

	/* 0x20: Lock Section */
	uint16_t volatile LOCK;
	/* Region Lock Bits */
#define NVMCTRL_LOCK_LOCK_Lsb			0u
#define NVMCTRL_LOCK_LOCK_Msb			15u

};


#define PAC0 ((struct zmcu_pac *)0x40000000)
#define PAC1 ((struct zmcu_pac *)0x41000000)
#define PAC2 ((struct zmcu_pac *)0x42000000)

/* Peripheral Access Controller 0 */
struct zmcu_pac {

	/* 0x00: Write Protection Clear */
	uint32_t volatile WPCLR;
	/* Write Protection Clear */
#define PAC_WPCLR_WP_Lsb			1u
#define PAC_WPCLR_WP_Msb			31u

	/* 0x04: Write Protection Set */
	uint32_t volatile WPSET;
	/* Write Protection Set */
#define PAC_WPSET_WP_Lsb			1u
#define PAC_WPSET_WP_Msb			31u

};


#define PM ((struct zmcu_pm *)0x40000400)

/* Power Manager */
struct zmcu_pm {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Clock Failure Detector Enable */
#define PM_CTRL_CFDEN				2u
	/* Backup Clock Select */
#define PM_CTRL_BKUPCLK				4u

	/* 0x01: Sleep Mode */
	uint8_t volatile SLEEP;
	/* Idle Mode Configuration */
#define PM_SLEEP_IDLE_Lsb			0u
#define PM_SLEEP_IDLE_Msb			1u
#define PM_SLEEP_IDLE_CPU			0x0
#define PM_SLEEP_IDLE_AHB			0x1
#define PM_SLEEP_IDLE_APB			0x2

	/* 0x02: External Reset Controller */
	uint8_t volatile EXTCTRL;
	/* External Reset Disable */
#define PM_EXTCTRL_SETDIS			0u

	/* 0x03 */
	uint8_t volatile RESERVED0[0x08-0x03];

	/* 0x08: CPU Clock Select */
	uint8_t volatile CPUSEL;
	/* CPU Prescaler Selection */
#define PM_CPUSEL_CPUDIV_Lsb			0u
#define PM_CPUSEL_CPUDIV_Msb			2u
#define PM_CPUSEL_CPUDIV_DIV1			0x0
#define PM_CPUSEL_CPUDIV_DIV2			0x1
#define PM_CPUSEL_CPUDIV_DIV4			0x2
#define PM_CPUSEL_CPUDIV_DIV8			0x3
#define PM_CPUSEL_CPUDIV_DIV16			0x4
#define PM_CPUSEL_CPUDIV_DIV32			0x5
#define PM_CPUSEL_CPUDIV_DIV64			0x6
#define PM_CPUSEL_CPUDIV_DIV128			0x7

	/* 0x09: APBA Clock Select */
	uint8_t volatile APBASEL;
	/* APBA Prescaler Selection */
#define PM_APBASEL_APBADIV_Lsb			0u
#define PM_APBASEL_APBADIV_Msb			2u
#define PM_APBASEL_APBADIV_DIV1			0x0
#define PM_APBASEL_APBADIV_DIV2			0x1
#define PM_APBASEL_APBADIV_DIV4			0x2
#define PM_APBASEL_APBADIV_DIV8			0x3
#define PM_APBASEL_APBADIV_DIV16		0x4
#define PM_APBASEL_APBADIV_DIV32		0x5
#define PM_APBASEL_APBADIV_DIV64		0x6
#define PM_APBASEL_APBADIV_DIV128		0x7

	/* 0x0A: APBB Clock Select */
	uint8_t volatile APBBSEL;
	/* APBB Prescaler Selection */
#define PM_APBBSEL_APBBDIV_Lsb			0u
#define PM_APBBSEL_APBBDIV_Msb			2u
#define PM_APBBSEL_APBBDIV_DIV1			0x0
#define PM_APBBSEL_APBBDIV_DIV2			0x1
#define PM_APBBSEL_APBBDIV_DIV4			0x2
#define PM_APBBSEL_APBBDIV_DIV8			0x3
#define PM_APBBSEL_APBBDIV_DIV16		0x4
#define PM_APBBSEL_APBBDIV_DIV32		0x5
#define PM_APBBSEL_APBBDIV_DIV64		0x6
#define PM_APBBSEL_APBBDIV_DIV128		0x7

	/* 0x0B: APBC Clock Select */
	uint8_t volatile APBCSEL;
	/* APBC Prescaler Selection */
#define PM_APBCSEL_APBCDIV_Lsb			0u
#define PM_APBCSEL_APBCDIV_Msb			2u
#define PM_APBCSEL_APBCDIV_DIV1			0x0
#define PM_APBCSEL_APBCDIV_DIV2			0x1
#define PM_APBCSEL_APBCDIV_DIV4			0x2
#define PM_APBCSEL_APBCDIV_DIV8			0x3
#define PM_APBCSEL_APBCDIV_DIV16		0x4
#define PM_APBCSEL_APBCDIV_DIV32		0x5
#define PM_APBCSEL_APBCDIV_DIV64		0x6
#define PM_APBCSEL_APBCDIV_DIV128		0x7

	/* 0x0C */
	uint8_t volatile RESERVED1[0x14-0x0C];

	/* 0x14: AHB Mask */
	uint32_t volatile AHBMASK;
	/* HPB0 AHB Clock Mask */
#define PM_AHBMASK_HPB0				0u
	/* HPB1 AHB Clock Mask */
#define PM_AHBMASK_HPB1				1u
	/* HPB2 AHB Clock Mask */
#define PM_AHBMASK_HPB2				2u
	/* DSU AHB Clock Mask */
#define PM_AHBMASK_DSU				3u
	/* NVMCTRL AHB Clock Mask */
#define PM_AHBMASK_NVMCTRL			4u
	/* DMAC AHB Clock Mask */
#define PM_AHBMASK_DMAC				5u

	/* 0x18: APBA Mask */
	uint32_t volatile APBAMASK;
	/* PAC0 APB Clock Enable */
#define PM_APBAMASK_PAC0			0u
	/* PM APB Clock Enable */
#define PM_APBAMASK_PM				1u
	/* SYSCTRL APB Clock Enable */
#define PM_APBAMASK_SYSCTRL			2u
	/* GCLK APB Clock Enable */
#define PM_APBAMASK_GCLK			3u
	/* WDT APB Clock Enable */
#define PM_APBAMASK_WDT				4u
	/* RTC APB Clock Enable */
#define PM_APBAMASK_RTC				5u
	/* EIC APB Clock Enable */
#define PM_APBAMASK_EIC				6u

	/* 0x1C: APBB Mask */
	uint32_t volatile APBBMASK;
	/* PAC1 APB Clock Enable */
#define PM_APBBMASK_PAC1			0u
	/* DSU APB Clock Enable */
#define PM_APBBMASK_DSU				1u
	/* NVMCTRL APB Clock Enable */
#define PM_APBBMASK_NVMCTRL			2u
	/* PORT APB Clock Enable */
#define PM_APBBMASK_PORT			3u
	/* DMAC APB Clock Enable */
#define PM_APBBMASK_DMAC			4u
	/* HMATRIX APB Clock Enable */
#define PM_APBBMASK_HMATRIX			6u

	/* 0x20: APBC Mask */
	uint32_t volatile APBCMASK;
	/* PAC2 APB Clock Enable */
#define PM_APBCMASK_PAC2			0u
	/* EVSYS APB Clock Enable */
#define PM_APBCMASK_EVSYS			1u
	/* SERCOM0 APB Clock Enable */
#define PM_APBCMASK_SERCOM0			2u
	/* SERCOM1 APB Clock Enable */
#define PM_APBCMASK_SERCOM1			3u
	/* TC1 APB Clock Enable */
#define PM_APBCMASK_TC1				6u
	/* TC2 APB Clock Enable */
#define PM_APBCMASK_TC2				7u
	/* ADC APB Clock Enable */
#define PM_APBCMASK_ADC				8u
	/* PTC APB Clock Enable */
#define PM_APBCMASK_PTC				11u

	/* 0x24 */
	uint8_t volatile RESERVED2[0x34-0x24];

	/* 0x34: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Clock Ready Interrupt Enable */
#define PM_INTENCLR_CKRDY			0u
	/* Clock Failure Detector Interrupt Enable */
#define PM_INTENCLR_CFD				1u

	/* 0x35: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Clock Ready Interrupt Enable */
#define PM_INTENSET_CKRDY			0u
	/* Clock Failure Detector Interrupt Enable */
#define PM_INTENSET_CFD				1u

	/* 0x36: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Clock Ready */
#define PM_INTFLAG_CKRDY			0u
	/* Clock Failure Detector */
#define PM_INTFLAG_CFD				1u

	/* 0x37 */
	uint8_t volatile RESERVED3[0x38-0x37];

	/* 0x38: Reset Cause */
	uint8_t volatile const RCAUSE;
	/* Power On Reset */
#define PM_RCAUSE_POR				0u
	/* Brown Out 12 Detector Reset */
#define PM_RCAUSE_BOD12				1u
	/* Brown Out 33 Detector Reset */
#define PM_RCAUSE_BOD33				2u
	/* External Reset */
#define PM_RCAUSE_EXT				4u
	/* Watchdog Reset */
#define PM_RCAUSE_WDT				5u
	/* System Reset Request */
#define PM_RCAUSE_SYST				6u

};


#define PORT ((struct zmcu_port *)0x41004400)
#define PORT_IOBUS ((struct zmcu_port_iobus *)0x60000000)

/* Port Module */
struct zmcu_port {

	/* 0x00: Data Direction */
	uint32_t volatile DIR;
	/* Port Data Direction */
#define PORT_DIR_DIR_Lsb			0u
#define PORT_DIR_DIR_Msb			31u

	/* 0x04: Data Direction Clear */
	uint32_t volatile DIRCLR;
	/* Port Data Direction Clear */
#define PORT_DIRCLR_DIRCLR_Lsb			0u
#define PORT_DIRCLR_DIRCLR_Msb			31u

	/* 0x08: Data Direction Set */
	uint32_t volatile DIRSET;
	/* Port Data Direction Set */
#define PORT_DIRSET_DIRSET_Lsb			0u
#define PORT_DIRSET_DIRSET_Msb			31u

	/* 0x0C: Data Direction Toggle */
	uint32_t volatile DIRTGL;
	/* Port Data Direction Toggle */
#define PORT_DIRTGL_DIRTGL_Lsb			0u
#define PORT_DIRTGL_DIRTGL_Msb			31u

	/* 0x10: Data Output Value */
	uint32_t volatile OUT;
	/* Port Data Output Value */
#define PORT_OUT_OUT_Lsb			0u
#define PORT_OUT_OUT_Msb			31u

	/* 0x14: Data Output Value Clear */
	uint32_t volatile OUTCLR;
	/* Port Data Output Value Clear */
#define PORT_OUTCLR_OUTCLR_Lsb			0u
#define PORT_OUTCLR_OUTCLR_Msb			31u

	/* 0x18: Data Output Value Set */
	uint32_t volatile OUTSET;
	/* Port Data Output Value Set */
#define PORT_OUTSET_OUTSET_Lsb			0u
#define PORT_OUTSET_OUTSET_Msb			31u

	/* 0x1C: Data Output Value Toggle */
	uint32_t volatile OUTTGL;
	/* Port Data Output Value Toggle */
#define PORT_OUTTGL_OUTTGL_Lsb			0u
#define PORT_OUTTGL_OUTTGL_Msb			31u

	/* 0x20: Data Input Value */
	uint32_t volatile const IN;
	/* Port Data Input Value */
#define PORT_IN_IN_Lsb				0u
#define PORT_IN_IN_Msb				31u

	/* 0x24: Control */
	uint32_t volatile CTRL;
	/* Input Sampling Mode */
#define PORT_CTRL_SAMPLING_Lsb			0u
#define PORT_CTRL_SAMPLING_Msb			31u

	/* 0x28: Write Configuration */
	uint32_t volatile WRCONFIG;
	/* Pin Mask for Multiple Pin Configuration */
#define PORT_WRCONFIG_PINMASK_Lsb		0u
#define PORT_WRCONFIG_PINMASK_Msb		15u
	/* Peripheral Multiplexer Enable */
#define PORT_WRCONFIG_PMUXEN			16u
	/* Input Enable */
#define PORT_WRCONFIG_INEN			17u
	/* Pull Enable */
#define PORT_WRCONFIG_PULLEN			18u
	/* Output Driver Strength Selection */
#define PORT_WRCONFIG_DRVSTR			22u
	/* Peripheral Multiplexing */
#define PORT_WRCONFIG_PMUX_Lsb			24u
#define PORT_WRCONFIG_PMUX_Msb			27u
	/* Write PMUX */
#define PORT_WRCONFIG_WRPMUX			28u
	/* Write PINCFG */
#define PORT_WRCONFIG_WRPINCFG			30u
	/* Half-Word Select */
#define PORT_WRCONFIG_HWSEL			31u

	/* 0x2C */
	uint8_t volatile RESERVED0[0x30-0x2C];

	/* 0x30: Peripheral Multiplexing n - Group 0 */
	uint8_t volatile PMUX0_[16];
	/* Peripheral Multiplexing Even */
#define PORT_PMUX0__PMUXE_Lsb			0u
#define PORT_PMUX0__PMUXE_Msb			3u
#define PORT_PMUX0__PMUXE_A			0x0
#define PORT_PMUX0__PMUXE_B			0x1
#define PORT_PMUX0__PMUXE_C			0x2
#define PORT_PMUX0__PMUXE_D			0x3
#define PORT_PMUX0__PMUXE_E			0x4
#define PORT_PMUX0__PMUXE_F			0x5
#define PORT_PMUX0__PMUXE_G			0x6
#define PORT_PMUX0__PMUXE_H			0x7
	/* Peripheral Multiplexing Odd */
#define PORT_PMUX0__PMUXO_Lsb			4u
#define PORT_PMUX0__PMUXO_Msb			7u
#define PORT_PMUX0__PMUXO_A			0x0
#define PORT_PMUX0__PMUXO_B			0x1
#define PORT_PMUX0__PMUXO_C			0x2
#define PORT_PMUX0__PMUXO_D			0x3
#define PORT_PMUX0__PMUXO_E			0x4
#define PORT_PMUX0__PMUXO_F			0x5
#define PORT_PMUX0__PMUXO_G			0x6
#define PORT_PMUX0__PMUXO_H			0x7

	/* 0x40: Pin Configuration n - Group 0 */
	uint8_t volatile PINCFG0_[32];
	/* Peripheral Multiplexer Enable */
#define PORT_PINCFG0__PMUXEN			0u
	/* Input Enable */
#define PORT_PINCFG0__INEN			1u
	/* Pull Enable */
#define PORT_PINCFG0__PULLEN			2u
	/* Output Driver Strength Selection */
#define PORT_PINCFG0__DRVSTR			6u

};


#define RTC ((struct zmcu_rtc *)0x40001400)

/* Real-Time Counter */
struct zmcu_rtc {


/* RTC: Real-Time Counter: 32-bit Counter with Single 32-bit Compare */
struct zmcu_rtc_mode0 {

	/* 0x00: MODE0 Control */
	uint16_t volatile CTRL;
	/* Software Reset */
#define RTC_MODE0_CTRL_SWRST			0u
	/* Enable */
#define RTC_MODE0_CTRL_ENABLE			1u
	/* Operating Mode */
#define RTC_MODE0_CTRL_MODE_Lsb			2u
#define RTC_MODE0_CTRL_MODE_Msb			3u
#define RTC_MODE0_CTRL_MODE_COUNT32		0x0
#define RTC_MODE0_CTRL_MODE_COUNT16		0x1
#define RTC_MODE0_CTRL_MODE_CLOCK		0x2
	/* Clear on Match */
#define RTC_MODE0_CTRL_MATCHCLR			7u
	/* Prescaler */
#define RTC_MODE0_CTRL_PRESCALER_Lsb		8u
#define RTC_MODE0_CTRL_PRESCALER_Msb		11u
#define RTC_MODE0_CTRL_PRESCALER_DIV1		0x0
#define RTC_MODE0_CTRL_PRESCALER_DIV2		0x1
#define RTC_MODE0_CTRL_PRESCALER_DIV4		0x2
#define RTC_MODE0_CTRL_PRESCALER_DIV8		0x3
#define RTC_MODE0_CTRL_PRESCALER_DIV16		0x4
#define RTC_MODE0_CTRL_PRESCALER_DIV32		0x5
#define RTC_MODE0_CTRL_PRESCALER_DIV64		0x6
#define RTC_MODE0_CTRL_PRESCALER_DIV128		0x7
#define RTC_MODE0_CTRL_PRESCALER_DIV256		0x8
#define RTC_MODE0_CTRL_PRESCALER_DIV512		0x9
#define RTC_MODE0_CTRL_PRESCALER_DIV1024	0xa

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define RTC_MODE0_READREQ_ADDR_Lsb		0u
#define RTC_MODE0_READREQ_ADDR_Msb		5u
	/* Read Continuously */
#define RTC_MODE0_READREQ_RCONT			14u
	/* Read Request */
#define RTC_MODE0_READREQ_RREQ			15u

	/* 0x04: MODE0 Event Control */
	uint16_t volatile EVCTRL;
	/* Periodic Interval 0 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO0			0u
	/* Periodic Interval 1 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO1			1u
	/* Periodic Interval 2 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO2			2u
	/* Periodic Interval 3 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO3			3u
	/* Periodic Interval 4 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO4			4u
	/* Periodic Interval 5 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO5			5u
	/* Periodic Interval 6 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO6			6u
	/* Periodic Interval 7 Event Output Enable */
#define RTC_MODE0_EVCTRL_PEREO7			7u
	/* Compare 0 Event Output Enable */
#define RTC_MODE0_EVCTRL_CMPEO0			8u
	/* Overflow Event Output Enable */
#define RTC_MODE0_EVCTRL_OVFEO			15u

	/* 0x06: MODE0 Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Compare 0 Interrupt Enable */
#define RTC_MODE0_INTENCLR_CMP0			0u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE0_INTENCLR_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE0_INTENCLR_OVF			7u

	/* 0x07: MODE0 Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Compare 0 Interrupt Enable */
#define RTC_MODE0_INTENSET_CMP0			0u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE0_INTENSET_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE0_INTENSET_OVF			7u

	/* 0x08: MODE0 Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Compare 0 */
#define RTC_MODE0_INTFLAG_CMP0			0u
	/* Synchronization Ready */
#define RTC_MODE0_INTFLAG_SYNCRDY		6u
	/* Overflow */
#define RTC_MODE0_INTFLAG_OVF			7u

	/* 0x09 */
	uint8_t volatile RESERVED0[0x0A-0x09];

	/* 0x0A: Status */
	uint8_t volatile STATUS;
	/* Synchronization Busy */
#define RTC_MODE0_STATUS_SYNCBUSY		7u

	/* 0x0B: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Run During Debug */
#define RTC_MODE0_DBGCTRL_DBGRUN		0u

	/* 0x0C: Frequency Correction */
	uint8_t volatile FREQCORR;
	/* Correction Value */
#define RTC_MODE0_FREQCORR_VALUE_Lsb		0u
#define RTC_MODE0_FREQCORR_VALUE_Msb		6u
	/* Correction Sign */
#define RTC_MODE0_FREQCORR_SIGN			7u

	/* 0x0D */
	uint8_t volatile RESERVED1[0x10-0x0D];

	/* 0x10: MODE0 Counter Value */
	uint32_t volatile COUNT;
	/* Counter Value */
#define RTC_MODE0_COUNT_COUNT_Lsb		0u
#define RTC_MODE0_COUNT_COUNT_Msb		31u

	/* 0x14 */
	uint8_t volatile RESERVED2[0x18-0x14];

	/* 0x18: MODE0 Compare n Value */
	uint32_t volatile COMP;
	/* Compare Value */
#define RTC_MODE0_COMP_COMP_Lsb			0u
#define RTC_MODE0_COMP_COMP_Msb			31u

};


/* RTC: Real-Time Counter: 16-bit Counter with Two 16-bit Compares */
struct zmcu_rtc_mode1 {

	/* 0x00: MODE1 Control */
	uint16_t volatile CTRL;
	/* Software Reset */
#define RTC_MODE1_CTRL_SWRST			0u
	/* Enable */
#define RTC_MODE1_CTRL_ENABLE			1u
	/* Operating Mode */
#define RTC_MODE1_CTRL_MODE_Lsb			2u
#define RTC_MODE1_CTRL_MODE_Msb			3u
#define RTC_MODE1_CTRL_MODE_COUNT32		0x0
#define RTC_MODE1_CTRL_MODE_COUNT16		0x1
#define RTC_MODE1_CTRL_MODE_CLOCK		0x2
	/* Prescaler */
#define RTC_MODE1_CTRL_PRESCALER_Lsb		8u
#define RTC_MODE1_CTRL_PRESCALER_Msb		11u
#define RTC_MODE1_CTRL_PRESCALER_DIV1		0x0
#define RTC_MODE1_CTRL_PRESCALER_DIV2		0x1
#define RTC_MODE1_CTRL_PRESCALER_DIV4		0x2
#define RTC_MODE1_CTRL_PRESCALER_DIV8		0x3
#define RTC_MODE1_CTRL_PRESCALER_DIV16		0x4
#define RTC_MODE1_CTRL_PRESCALER_DIV32		0x5
#define RTC_MODE1_CTRL_PRESCALER_DIV64		0x6
#define RTC_MODE1_CTRL_PRESCALER_DIV128		0x7
#define RTC_MODE1_CTRL_PRESCALER_DIV256		0x8
#define RTC_MODE1_CTRL_PRESCALER_DIV512		0x9
#define RTC_MODE1_CTRL_PRESCALER_DIV1024	0xa

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define RTC_MODE1_READREQ_ADDR_Lsb		0u
#define RTC_MODE1_READREQ_ADDR_Msb		5u
	/* Read Continuously */
#define RTC_MODE1_READREQ_RCONT			14u
	/* Read Request */
#define RTC_MODE1_READREQ_RREQ			15u

	/* 0x04: MODE1 Event Control */
	uint16_t volatile EVCTRL;
	/* Periodic Interval 0 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO0			0u
	/* Periodic Interval 1 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO1			1u
	/* Periodic Interval 2 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO2			2u
	/* Periodic Interval 3 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO3			3u
	/* Periodic Interval 4 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO4			4u
	/* Periodic Interval 5 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO5			5u
	/* Periodic Interval 6 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO6			6u
	/* Periodic Interval 7 Event Output Enable */
#define RTC_MODE1_EVCTRL_PEREO7			7u
	/* Compare 0 Event Output Enable */
#define RTC_MODE1_EVCTRL_CMPEO0			8u
	/* Compare 1 Event Output Enable */
#define RTC_MODE1_EVCTRL_CMPEO1			9u
	/* Overflow Event Output Enable */
#define RTC_MODE1_EVCTRL_OVFEO			15u

	/* 0x06: MODE1 Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Compare 0 Interrupt Enable */
#define RTC_MODE1_INTENCLR_CMP0			0u
	/* Compare 1 Interrupt Enable */
#define RTC_MODE1_INTENCLR_CMP1			1u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE1_INTENCLR_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE1_INTENCLR_OVF			7u

	/* 0x07: MODE1 Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Compare 0 Interrupt Enable */
#define RTC_MODE1_INTENSET_CMP0			0u
	/* Compare 1 Interrupt Enable */
#define RTC_MODE1_INTENSET_CMP1			1u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE1_INTENSET_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE1_INTENSET_OVF			7u

	/* 0x08: MODE1 Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Compare 0 */
#define RTC_MODE1_INTFLAG_CMP0			0u
	/* Compare 1 */
#define RTC_MODE1_INTFLAG_CMP1			1u
	/* Synchronization Ready */
#define RTC_MODE1_INTFLAG_SYNCRDY		6u
	/* Overflow */
#define RTC_MODE1_INTFLAG_OVF			7u

	/* 0x09 */
	uint8_t volatile RESERVED3[0x0A-0x09];

	/* 0x0A: Status */
	uint8_t volatile STATUS;
	/* Synchronization Busy */
#define RTC_MODE1_STATUS_SYNCBUSY		7u

	/* 0x0B: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Run During Debug */
#define RTC_MODE1_DBGCTRL_DBGRUN		0u

	/* 0x0C: Frequency Correction */
	uint8_t volatile FREQCORR;
	/* Correction Value */
#define RTC_MODE1_FREQCORR_VALUE_Lsb		0u
#define RTC_MODE1_FREQCORR_VALUE_Msb		6u
	/* Correction Sign */
#define RTC_MODE1_FREQCORR_SIGN			7u

	/* 0x0D */
	uint8_t volatile RESERVED4[0x10-0x0D];

	/* 0x10: MODE1 Counter Value */
	uint16_t volatile COUNT;
	/* Counter Value */
#define RTC_MODE1_COUNT_COUNT_Lsb		0u
#define RTC_MODE1_COUNT_COUNT_Msb		15u

	/* 0x12 */
	uint8_t volatile RESERVED5[0x14-0x12];

	/* 0x14: MODE1 Counter Period */
	uint16_t volatile PER;
	/* Counter Period */
#define RTC_MODE1_PER_PER_Lsb			0u
#define RTC_MODE1_PER_PER_Msb			15u

	/* 0x16 */
	uint8_t volatile RESERVED6[0x18-0x16];

	/* 0x18: MODE1 Compare n Value */
	uint16_t volatile COMP[2];
	/* Compare Value */
#define RTC_MODE1_COMP_COMP_Lsb			0u
#define RTC_MODE1_COMP_COMP_Msb			15u

};


/* RTC: Real-Time Counter: Clock/Calendar with Alarm */
struct zmcu_rtc_mode2 {

	/* 0x00: MODE2 Control */
	uint16_t volatile CTRL;
	/* Software Reset */
#define RTC_MODE2_CTRL_SWRST			0u
	/* Enable */
#define RTC_MODE2_CTRL_ENABLE			1u
	/* Operating Mode */
#define RTC_MODE2_CTRL_MODE_Lsb			2u
#define RTC_MODE2_CTRL_MODE_Msb			3u
#define RTC_MODE2_CTRL_MODE_COUNT32		0x0
#define RTC_MODE2_CTRL_MODE_COUNT16		0x1
#define RTC_MODE2_CTRL_MODE_CLOCK		0x2
	/* Clock Representation */
#define RTC_MODE2_CTRL_CLKREP			6u
	/* Clear on Match */
#define RTC_MODE2_CTRL_MATCHCLR			7u
	/* Prescaler */
#define RTC_MODE2_CTRL_PRESCALER_Lsb		8u
#define RTC_MODE2_CTRL_PRESCALER_Msb		11u
#define RTC_MODE2_CTRL_PRESCALER_DIV1		0x0
#define RTC_MODE2_CTRL_PRESCALER_DIV2		0x1
#define RTC_MODE2_CTRL_PRESCALER_DIV4		0x2
#define RTC_MODE2_CTRL_PRESCALER_DIV8		0x3
#define RTC_MODE2_CTRL_PRESCALER_DIV16		0x4
#define RTC_MODE2_CTRL_PRESCALER_DIV32		0x5
#define RTC_MODE2_CTRL_PRESCALER_DIV64		0x6
#define RTC_MODE2_CTRL_PRESCALER_DIV128		0x7
#define RTC_MODE2_CTRL_PRESCALER_DIV256		0x8
#define RTC_MODE2_CTRL_PRESCALER_DIV512		0x9
#define RTC_MODE2_CTRL_PRESCALER_DIV1024	0xa

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define RTC_MODE2_READREQ_ADDR_Lsb		0u
#define RTC_MODE2_READREQ_ADDR_Msb		5u
	/* Read Continuously */
#define RTC_MODE2_READREQ_RCONT			14u
	/* Read Request */
#define RTC_MODE2_READREQ_RREQ			15u

	/* 0x04: MODE2 Event Control */
	uint16_t volatile EVCTRL;
	/* Periodic Interval 0 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO0			0u
	/* Periodic Interval 1 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO1			1u
	/* Periodic Interval 2 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO2			2u
	/* Periodic Interval 3 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO3			3u
	/* Periodic Interval 4 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO4			4u
	/* Periodic Interval 5 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO5			5u
	/* Periodic Interval 6 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO6			6u
	/* Periodic Interval 7 Event Output Enable */
#define RTC_MODE2_EVCTRL_PEREO7			7u
	/* Alarm 0 Event Output Enable */
#define RTC_MODE2_EVCTRL_ALARMEO0		8u
	/* Overflow Event Output Enable */
#define RTC_MODE2_EVCTRL_OVFEO			15u

	/* 0x06: MODE2 Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Alarm 0 Interrupt Enable */
#define RTC_MODE2_INTENCLR_ALARM0		0u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE2_INTENCLR_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE2_INTENCLR_OVF			7u

	/* 0x07: MODE2 Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Alarm 0 Interrupt Enable */
#define RTC_MODE2_INTENSET_ALARM0		0u
	/* Synchronization Ready Interrupt Enable */
#define RTC_MODE2_INTENSET_SYNCRDY		6u
	/* Overflow Interrupt Enable */
#define RTC_MODE2_INTENSET_OVF			7u

	/* 0x08: MODE2 Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Alarm 0 */
#define RTC_MODE2_INTFLAG_ALARM0		0u
	/* Synchronization Ready */
#define RTC_MODE2_INTFLAG_SYNCRDY		6u
	/* Overflow */
#define RTC_MODE2_INTFLAG_OVF			7u

	/* 0x09 */
	uint8_t volatile RESERVED7[0x0A-0x09];

	/* 0x0A: Status */
	uint8_t volatile STATUS;
	/* Synchronization Busy */
#define RTC_MODE2_STATUS_SYNCBUSY		7u

	/* 0x0B: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Run During Debug */
#define RTC_MODE2_DBGCTRL_DBGRUN		0u

	/* 0x0C: Frequency Correction */
	uint8_t volatile FREQCORR;
	/* Correction Value */
#define RTC_MODE2_FREQCORR_VALUE_Lsb		0u
#define RTC_MODE2_FREQCORR_VALUE_Msb		6u
	/* Correction Sign */
#define RTC_MODE2_FREQCORR_SIGN			7u

	/* 0x0D */
	uint8_t volatile RESERVED8[0x10-0x0D];

	/* 0x10: MODE2 Clock Value */
	uint32_t volatile CLOCK;
	/* Second */
#define RTC_MODE2_CLOCK_SECOND_Lsb		0u
#define RTC_MODE2_CLOCK_SECOND_Msb		5u
	/* Minute */
#define RTC_MODE2_CLOCK_MINUTE_Lsb		6u
#define RTC_MODE2_CLOCK_MINUTE_Msb		11u
	/* Hour */
#define RTC_MODE2_CLOCK_HOUR_Lsb		12u
#define RTC_MODE2_CLOCK_HOUR_Msb		16u
#define RTC_MODE2_CLOCK_HOUR_AM			0x0
#define RTC_MODE2_CLOCK_HOUR_PM			0x10
	/* Day */
#define RTC_MODE2_CLOCK_DAY_Lsb			17u
#define RTC_MODE2_CLOCK_DAY_Msb			21u
	/* Month */
#define RTC_MODE2_CLOCK_MONTH_Lsb		22u
#define RTC_MODE2_CLOCK_MONTH_Msb		25u
	/* Year */
#define RTC_MODE2_CLOCK_YEAR_Lsb		26u
#define RTC_MODE2_CLOCK_YEAR_Msb		31u

	/* 0x14 */
	uint8_t volatile RESERVED9[0x18-0x14];

	/* 0x18: MODE2 Alarm n Value */
	uint32_t volatile ALARM;
	/* Second */
#define RTC_MODE2_ALARM_SECOND_Lsb		0u
#define RTC_MODE2_ALARM_SECOND_Msb		5u
	/* Minute */
#define RTC_MODE2_ALARM_MINUTE_Lsb		6u
#define RTC_MODE2_ALARM_MINUTE_Msb		11u
	/* Hour */
#define RTC_MODE2_ALARM_HOUR_Lsb		12u
#define RTC_MODE2_ALARM_HOUR_Msb		16u
#define RTC_MODE2_ALARM_HOUR_AM			0x0
#define RTC_MODE2_ALARM_HOUR_PM			0x10
	/* Day */
#define RTC_MODE2_ALARM_DAY_Lsb			17u
#define RTC_MODE2_ALARM_DAY_Msb			21u
	/* Month */
#define RTC_MODE2_ALARM_MONTH_Lsb		22u
#define RTC_MODE2_ALARM_MONTH_Msb		25u
	/* Year */
#define RTC_MODE2_ALARM_YEAR_Lsb		26u
#define RTC_MODE2_ALARM_YEAR_Msb		31u

	/* 0x1C: MODE2 Alarm n Mask */
	uint8_t volatile MASK;
	/* Alarm Mask Selection */
#define RTC_MODE2_MASK_SEL_Lsb			0u
#define RTC_MODE2_MASK_SEL_Msb			2u
#define RTC_MODE2_MASK_SEL_OFF			0x0
#define RTC_MODE2_MASK_SEL_SS			0x1
#define RTC_MODE2_MASK_SEL_MMSS			0x2
#define RTC_MODE2_MASK_SEL_HHMMSS		0x3
#define RTC_MODE2_MASK_SEL_DDHHMMSS		0x4
#define RTC_MODE2_MASK_SEL_MMDDHHMMSS		0x5
#define RTC_MODE2_MASK_SEL_YYMMDDHHMMSS		0x6

};


#define SERCOM0 ((struct zmcu_sercom *)0x42000800)
#define SERCOM1 ((struct zmcu_sercom *)0x42000C00)


/* SERCOM: Serial Communication Interface 0: I2C Master Mode */
struct zmcu_i2cm {

	/* 0x00: I2CM Control A */
	uint32_t volatile CTRLA;
	/* Software Reset */
#define I2CM_CTRLA_SWRST			0u
	/* Enable */
#define I2CM_CTRLA_ENABLE			1u
	/* Operating Mode */
#define I2CM_CTRLA_MODE_Lsb			2u
#define I2CM_CTRLA_MODE_Msb			4u
#define I2CM_CTRLA_MODE_USART_EXT_CLK		0x0
#define I2CM_CTRLA_MODE_USART_INT_CLK		0x1
#define I2CM_CTRLA_MODE_SPI_SLAVE		0x2
#define I2CM_CTRLA_MODE_SPI_MASTER		0x3
#define I2CM_CTRLA_MODE_I2C_SLAVE		0x4
#define I2CM_CTRLA_MODE_I2C_MASTER		0x5
	/* Run in Standby */
#define I2CM_CTRLA_RUNSTDBY			7u
	/* Pin Usage */
#define I2CM_CTRLA_PINOUT			16u
	/* SDA Hold Time */
#define I2CM_CTRLA_SDAHOLD_Lsb			20u
#define I2CM_CTRLA_SDAHOLD_Msb			21u
	/* Master SCL Low Extend Timeout */
#define I2CM_CTRLA_MEXTTOEN			22u
	/* Slave SCL Low Extend Timeout */
#define I2CM_CTRLA_SEXTTOEN			23u
	/* Transfer Speed */
#define I2CM_CTRLA_SPEED_Lsb			24u
#define I2CM_CTRLA_SPEED_Msb			25u
	/* SCL Clock Stretch Mode */
#define I2CM_CTRLA_SCLSM			27u
	/* Inactive Time-Out */
#define I2CM_CTRLA_INACTOUT_Lsb			28u
#define I2CM_CTRLA_INACTOUT_Msb			29u
	/* SCL Low Timeout Enable */
#define I2CM_CTRLA_LOWTOUTEN			30u

	/* 0x04: I2CM Control B */
	uint32_t volatile CTRLB;
	/* Smart Mode Enable */
#define I2CM_CTRLB_SMEN				8u
	/* Quick Command Enable */
#define I2CM_CTRLB_QCEN				9u
	/* Command */
#define I2CM_CTRLB_CMD_Lsb			16u
#define I2CM_CTRLB_CMD_Msb			17u
	/* Acknowledge Action */
#define I2CM_CTRLB_ACKACT			18u

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: I2CM Baud Rate */
	uint32_t volatile BAUD;
	/* Baud Rate Value */
#define I2CM_BAUD_BAUD_Lsb			0u
#define I2CM_BAUD_BAUD_Msb			7u
	/* Baud Rate Value Low */
#define I2CM_BAUD_BAUDLOW_Lsb			8u
#define I2CM_BAUD_BAUDLOW_Msb			15u
	/* High Speed Baud Rate Value */
#define I2CM_BAUD_HSBAUD_Lsb			16u
#define I2CM_BAUD_HSBAUD_Msb			23u
	/* High Speed Baud Rate Value Low */
#define I2CM_BAUD_HSBAUDLOW_Lsb			24u
#define I2CM_BAUD_HSBAUDLOW_Msb			31u

	/* 0x10 */
	uint8_t volatile RESERVED1[0x14-0x10];

	/* 0x14: I2CM Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Master On Bus Interrupt Disable */
#define I2CM_INTENCLR_MB			0u
	/* Slave On Bus Interrupt Disable */
#define I2CM_INTENCLR_SB			1u
	/* Combined Error Interrupt Disable */
#define I2CM_INTENCLR_ERROR			7u

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: I2CM Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Master On Bus Interrupt Enable */
#define I2CM_INTENSET_MB			0u
	/* Slave On Bus Interrupt Enable */
#define I2CM_INTENSET_SB			1u
	/* Combined Error Interrupt Enable */
#define I2CM_INTENSET_ERROR			7u

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: I2CM Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Master On Bus Interrupt */
#define I2CM_INTFLAG_MB				0u
	/* Slave On Bus Interrupt */
#define I2CM_INTFLAG_SB				1u
	/* Combined Error Interrupt */
#define I2CM_INTFLAG_ERROR			7u

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: I2CM Status */
	uint16_t volatile STATUS;
	/* Bus Error */
#define I2CM_STATUS_BUSERR			0u
	/* Arbitration Lost */
#define I2CM_STATUS_ARBLOST			1u
	/* Received Not Acknowledge */
#define I2CM_STATUS_RXNACK			2u
	/* Bus State */
#define I2CM_STATUS_BUSSTATE_Lsb		4u
#define I2CM_STATUS_BUSSTATE_Msb		5u
	/* SCL Low Timeout */
#define I2CM_STATUS_LOWTOUT			6u
	/* Clock Hold */
#define I2CM_STATUS_CLKHOLD			7u
	/* Master SCL Low Extend Timeout */
#define I2CM_STATUS_MEXTTOUT			8u
	/* Slave SCL Low Extend Timeout */
#define I2CM_STATUS_SEXTTOUT			9u
	/* Length Error */
#define I2CM_STATUS_LENERR			10u

	/* 0x1C: I2CM Syncbusy */
	uint32_t volatile const SYNCBUSY;
	/* Software Reset Synchronization Busy */
#define I2CM_SYNCBUSY_SWRST			0u
	/* SERCOM Enable Synchronization Busy */
#define I2CM_SYNCBUSY_ENABLE			1u
	/* System Operation Synchronization Busy */
#define I2CM_SYNCBUSY_SYSOP			2u

	/* 0x20 */
	uint8_t volatile RESERVED5[0x24-0x20];

	/* 0x24: I2CM Address */
	uint32_t volatile ADDR;
	/* Address Value */
#define I2CM_ADDR_ADDR_Lsb			0u
#define I2CM_ADDR_ADDR_Msb			10u
	/* Length Enable */
#define I2CM_ADDR_LENEN				13u
	/* High Speed Mode */
#define I2CM_ADDR_HS				14u
	/* Ten Bit Addressing Enable */
#define I2CM_ADDR_TENBITEN			15u
	/* Length */
#define I2CM_ADDR_LEN_Lsb			16u
#define I2CM_ADDR_LEN_Msb			23u

	/* 0x28: I2CM Data */
	uint8_t volatile DATA;
	/* Data Value */
#define I2CM_DATA_DATA_Lsb			0u
#define I2CM_DATA_DATA_Msb			7u

	/* 0x29 */
	uint8_t volatile RESERVED6[0x30-0x29];

	/* 0x30: I2CM Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Mode */
#define I2CM_DBGCTRL_DBGSTOP			0u

};


/* SERCOM: Serial Communication Interface 0: I2C Slave Mode */
struct zmcu_i2cs {

	/* 0x00: I2CS Control A */
	uint32_t volatile CTRLA;
	/* Software Reset */
#define I2CS_CTRLA_SWRST			0u
	/* Enable */
#define I2CS_CTRLA_ENABLE			1u
	/* Operating Mode */
#define I2CS_CTRLA_MODE_Lsb			2u
#define I2CS_CTRLA_MODE_Msb			4u
#define I2CS_CTRLA_MODE_USART_EXT_CLK		0x0
#define I2CS_CTRLA_MODE_USART_INT_CLK		0x1
#define I2CS_CTRLA_MODE_SPI_SLAVE		0x2
#define I2CS_CTRLA_MODE_SPI_MASTER		0x3
#define I2CS_CTRLA_MODE_I2C_SLAVE		0x4
#define I2CS_CTRLA_MODE_I2C_MASTER		0x5
	/* Run during Standby */
#define I2CS_CTRLA_RUNSTDBY			7u
	/* Pin Usage */
#define I2CS_CTRLA_PINOUT			16u
	/* SDA Hold Time */
#define I2CS_CTRLA_SDAHOLD_Lsb			20u
#define I2CS_CTRLA_SDAHOLD_Msb			21u
	/* Slave SCL Low Extend Timeout */
#define I2CS_CTRLA_SEXTTOEN			23u
	/* Transfer Speed */
#define I2CS_CTRLA_SPEED_Lsb			24u
#define I2CS_CTRLA_SPEED_Msb			25u
	/* SCL Clock Stretch Mode */
#define I2CS_CTRLA_SCLSM			27u
	/* SCL Low Timeout Enable */
#define I2CS_CTRLA_LOWTOUTEN			30u

	/* 0x04: I2CS Control B */
	uint32_t volatile CTRLB;
	/* Smart Mode Enable */
#define I2CS_CTRLB_SMEN				8u
	/* PMBus Group Command */
#define I2CS_CTRLB_GCMD				9u
	/* Automatic Address Acknowledge */
#define I2CS_CTRLB_AACKEN			10u
	/* Address Mode */
#define I2CS_CTRLB_AMODE_Lsb			14u
#define I2CS_CTRLB_AMODE_Msb			15u
	/* Command */
#define I2CS_CTRLB_CMD_Lsb			16u
#define I2CS_CTRLB_CMD_Msb			17u
	/* Acknowledge Action */
#define I2CS_CTRLB_ACKACT			18u

	/* 0x08 */
	uint8_t volatile RESERVED7[0x14-0x08];

	/* 0x14: I2CS Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Stop Received Interrupt Disable */
#define I2CS_INTENCLR_PREC			0u
	/* Address Match Interrupt Disable */
#define I2CS_INTENCLR_AMATCH			1u
	/* Data Interrupt Disable */
#define I2CS_INTENCLR_DRDY			2u
	/* Combined Error Interrupt Disable */
#define I2CS_INTENCLR_ERROR			7u

	/* 0x15 */
	uint8_t volatile RESERVED8[0x16-0x15];

	/* 0x16: I2CS Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Stop Received Interrupt Enable */
#define I2CS_INTENSET_PREC			0u
	/* Address Match Interrupt Enable */
#define I2CS_INTENSET_AMATCH			1u
	/* Data Interrupt Enable */
#define I2CS_INTENSET_DRDY			2u
	/* Combined Error Interrupt Enable */
#define I2CS_INTENSET_ERROR			7u

	/* 0x17 */
	uint8_t volatile RESERVED9[0x18-0x17];

	/* 0x18: I2CS Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Stop Received Interrupt */
#define I2CS_INTFLAG_PREC			0u
	/* Address Match Interrupt */
#define I2CS_INTFLAG_AMATCH			1u
	/* Data Interrupt */
#define I2CS_INTFLAG_DRDY			2u
	/* Combined Error Interrupt */
#define I2CS_INTFLAG_ERROR			7u

	/* 0x19 */
	uint8_t volatile RESERVED10[0x1A-0x19];

	/* 0x1A: I2CS Status */
	uint16_t volatile STATUS;
	/* Bus Error */
#define I2CS_STATUS_BUSERR			0u
	/* Transmit Collision */
#define I2CS_STATUS_COLL			1u
	/* Received Not Acknowledge */
#define I2CS_STATUS_RXNACK			2u
	/* Read/Write Direction */
#define I2CS_STATUS_DIR				3u
	/* Repeated Start */
#define I2CS_STATUS_SR				4u
	/* SCL Low Timeout */
#define I2CS_STATUS_LOWTOUT			6u
	/* Clock Hold */
#define I2CS_STATUS_CLKHOLD			7u
	/* Slave SCL Low Extend Timeout */
#define I2CS_STATUS_SEXTTOUT			9u
	/* High Speed */
#define I2CS_STATUS_HS				10u

	/* 0x1C: I2CS Syncbusy */
	uint32_t volatile const SYNCBUSY;
	/* Software Reset Synchronization Busy */
#define I2CS_SYNCBUSY_SWRST			0u
	/* SERCOM Enable Synchronization Busy */
#define I2CS_SYNCBUSY_ENABLE			1u

	/* 0x20 */
	uint8_t volatile RESERVED11[0x24-0x20];

	/* 0x24: I2CS Address */
	uint32_t volatile ADDR;
	/* General Call Address Enable */
#define I2CS_ADDR_GENCEN			0u
	/* Address Value */
#define I2CS_ADDR_ADDR_Lsb			1u
#define I2CS_ADDR_ADDR_Msb			10u
	/* Ten Bit Addressing Enable */
#define I2CS_ADDR_TENBITEN			15u
	/* Address Mask */
#define I2CS_ADDR_ADDRMASK_Lsb			17u
#define I2CS_ADDR_ADDRMASK_Msb			26u

	/* 0x28: I2CS Data */
	uint8_t volatile DATA;
	/* Data Value */
#define I2CS_DATA_DATA_Lsb			0u
#define I2CS_DATA_DATA_Msb			7u

};


/* SERCOM: Serial Communication Interface 0: SPI Mode */
struct zmcu_spi {

	/* 0x00: SPI Control A */
	uint32_t volatile CTRLA;
	/* Software Reset */
#define SPI_CTRLA_SWRST				0u
	/* Enable */
#define SPI_CTRLA_ENABLE			1u
	/* Operating Mode */
#define SPI_CTRLA_MODE_Lsb			2u
#define SPI_CTRLA_MODE_Msb			4u
#define SPI_CTRLA_MODE_USART_EXT_CLK		0x0
#define SPI_CTRLA_MODE_USART_INT_CLK		0x1
#define SPI_CTRLA_MODE_SPI_SLAVE		0x2
#define SPI_CTRLA_MODE_SPI_MASTER		0x3
#define SPI_CTRLA_MODE_I2C_SLAVE		0x4
#define SPI_CTRLA_MODE_I2C_MASTER		0x5
	/* Run during Standby */
#define SPI_CTRLA_RUNSTDBY			7u
	/* Immediate Buffer Overflow Notification */
#define SPI_CTRLA_IBON				8u
	/* Data Out Pinout */
#define SPI_CTRLA_DOPO_Lsb			16u
#define SPI_CTRLA_DOPO_Msb			17u
	/* Data In Pinout */
#define SPI_CTRLA_DIPO_Lsb			20u
#define SPI_CTRLA_DIPO_Msb			21u
	/* Frame Format */
#define SPI_CTRLA_FORM_Lsb			24u
#define SPI_CTRLA_FORM_Msb			27u
	/* Clock Phase */
#define SPI_CTRLA_CPHA				28u
	/* Clock Polarity */
#define SPI_CTRLA_CPOL				29u
	/* Data Order */
#define SPI_CTRLA_DORD				30u

	/* 0x04: SPI Control B */
	uint32_t volatile CTRLB;
	/* Character Size */
#define SPI_CTRLB_CHSIZE_Lsb			0u
#define SPI_CTRLB_CHSIZE_Msb			2u
	/* Data Preload Enable */
#define SPI_CTRLB_PLOADEN			6u
	/* Slave Select Low Detect Enable */
#define SPI_CTRLB_SSDE				9u
	/* Master Slave Select Enable */
#define SPI_CTRLB_MSSEN				13u
	/* Address Mode */
#define SPI_CTRLB_AMODE_Lsb			14u
#define SPI_CTRLB_AMODE_Msb			15u
	/* Receiver Enable */
#define SPI_CTRLB_RXEN				17u

	/* 0x08 */
	uint8_t volatile RESERVED12[0x0C-0x08];

	/* 0x0C: SPI Baud Rate */
	uint8_t volatile BAUD;
	/* Baud Rate Value */
#define SPI_BAUD_BAUD_Lsb			0u
#define SPI_BAUD_BAUD_Msb			7u

	/* 0x0D */
	uint8_t volatile RESERVED13[0x14-0x0D];

	/* 0x14: SPI Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Data Register Empty Interrupt Disable */
#define SPI_INTENCLR_DRE			0u
	/* Transmit Complete Interrupt Disable */
#define SPI_INTENCLR_TXC			1u
	/* Receive Complete Interrupt Disable */
#define SPI_INTENCLR_RXC			2u
	/* Slave Select Low Interrupt Disable */
#define SPI_INTENCLR_SSL			3u
	/* Combined Error Interrupt Disable */
#define SPI_INTENCLR_ERROR			7u

	/* 0x15 */
	uint8_t volatile RESERVED14[0x16-0x15];

	/* 0x16: SPI Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Data Register Empty Interrupt Enable */
#define SPI_INTENSET_DRE			0u
	/* Transmit Complete Interrupt Enable */
#define SPI_INTENSET_TXC			1u
	/* Receive Complete Interrupt Enable */
#define SPI_INTENSET_RXC			2u
	/* Slave Select Low Interrupt Enable */
#define SPI_INTENSET_SSL			3u
	/* Combined Error Interrupt Enable */
#define SPI_INTENSET_ERROR			7u

	/* 0x17 */
	uint8_t volatile RESERVED15[0x18-0x17];

	/* 0x18: SPI Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Data Register Empty Interrupt */
#define SPI_INTFLAG_DRE				0u
	/* Transmit Complete Interrupt */
#define SPI_INTFLAG_TXC				1u
	/* Receive Complete Interrupt */
#define SPI_INTFLAG_RXC				2u
	/* Slave Select Low Interrupt Flag */
#define SPI_INTFLAG_SSL				3u
	/* Combined Error Interrupt */
#define SPI_INTFLAG_ERROR			7u

	/* 0x19 */
	uint8_t volatile RESERVED16[0x1A-0x19];

	/* 0x1A: SPI Status */
	uint16_t volatile STATUS;
	/* Buffer Overflow */
#define SPI_STATUS_BUFOVF			2u

	/* 0x1C: SPI Syncbusy */
	uint32_t volatile const SYNCBUSY;
	/* Software Reset Synchronization Busy */
#define SPI_SYNCBUSY_SWRST			0u
	/* SERCOM Enable Synchronization Busy */
#define SPI_SYNCBUSY_ENABLE			1u
	/* CTRLB Synchronization Busy */
#define SPI_SYNCBUSY_CTRLB			2u

	/* 0x20 */
	uint8_t volatile RESERVED17[0x24-0x20];

	/* 0x24: SPI Address */
	uint32_t volatile ADDR;
	/* Address Value */
#define SPI_ADDR_ADDR_Lsb			0u
#define SPI_ADDR_ADDR_Msb			7u
	/* Address Mask */
#define SPI_ADDR_ADDRMASK_Lsb			16u
#define SPI_ADDR_ADDRMASK_Msb			23u

	/* 0x28: SPI Data */
	uint32_t volatile DATA;
	/* Data Value */
#define SPI_DATA_DATA_Lsb			0u
#define SPI_DATA_DATA_Msb			8u

	/* 0x2C */
	uint8_t volatile RESERVED18[0x30-0x2C];

	/* 0x30: SPI Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Mode */
#define SPI_DBGCTRL_DBGSTOP			0u

};


/* SERCOM: Serial Communication Interface 0: USART Mode */
struct zmcu_usart {

	/* 0x00: USART Control A */
	uint32_t volatile CTRLA;
	/* Software Reset */
#define USART_CTRLA_SWRST			0u
	/* Enable */
#define USART_CTRLA_ENABLE			1u
	/* Operating Mode */
#define USART_CTRLA_MODE_Lsb			2u
#define USART_CTRLA_MODE_Msb			4u
#define USART_CTRLA_MODE_USART_EXT_CLK		0x0
#define USART_CTRLA_MODE_USART_INT_CLK		0x1
#define USART_CTRLA_MODE_SPI_SLAVE		0x2
#define USART_CTRLA_MODE_SPI_MASTER		0x3
#define USART_CTRLA_MODE_I2C_SLAVE		0x4
#define USART_CTRLA_MODE_I2C_MASTER		0x5
	/* Run during Standby */
#define USART_CTRLA_RUNSTDBY			7u
	/* Immediate Buffer Overflow Notification */
#define USART_CTRLA_IBON			8u
	/* Sample */
#define USART_CTRLA_SAMPR_Lsb			13u
#define USART_CTRLA_SAMPR_Msb			15u
	/* Transmit Data Pinout */
#define USART_CTRLA_TXPO_Lsb			16u
#define USART_CTRLA_TXPO_Msb			17u
	/* Receive Data Pinout */
#define USART_CTRLA_RXPO_Lsb			20u
#define USART_CTRLA_RXPO_Msb			21u
	/* Sample Adjustment */
#define USART_CTRLA_SAMPA_Lsb			22u
#define USART_CTRLA_SAMPA_Msb			23u
	/* Frame Format */
#define USART_CTRLA_FORM_Lsb			24u
#define USART_CTRLA_FORM_Msb			27u
	/* Communication Mode */
#define USART_CTRLA_CMODE			28u
	/* Clock Polarity */
#define USART_CTRLA_CPOL			29u
	/* Data Order */
#define USART_CTRLA_DORD			30u

	/* 0x04: USART Control B */
	uint32_t volatile CTRLB;
	/* Character Size */
#define USART_CTRLB_CHSIZE_Lsb			0u
#define USART_CTRLB_CHSIZE_Msb			2u
	/* Stop Bit Mode */
#define USART_CTRLB_SBMODE			6u
	/* Collision Detection Enable */
#define USART_CTRLB_COLDEN			8u
	/* Start of Frame Detection Enable */
#define USART_CTRLB_SFDE			9u
	/* Encoding Format */
#define USART_CTRLB_ENC				10u
	/* Parity Mode */
#define USART_CTRLB_PMODE			13u
	/* Transmitter Enable */
#define USART_CTRLB_TXEN			16u
	/* Receiver Enable */
#define USART_CTRLB_RXEN			17u

	/* 0x08 */
	uint8_t volatile RESERVED19[0x0C-0x08];

	/* 0x0C: USART Baud Rate */
	uint16_t volatile BAUD;
	/* Baud Rate Value */
#define USART_BAUD_BAUD_Lsb			0u
#define USART_BAUD_BAUD_Msb			15u

	/* 0x0C: USART Baud Rate */
	uint16_t volatile BAUD_FRAC_MODE;
	/* Baud Rate Value */
#define USART_BAUD_FRAC_MODE_BAUD_Lsb		0u
#define USART_BAUD_FRAC_MODE_BAUD_Msb		12u
	/* Fractional Part */
#define USART_BAUD_FRAC_MODE_FP_Lsb		13u
#define USART_BAUD_FRAC_MODE_FP_Msb		15u

	/* 0x0C: USART Baud Rate */
	uint16_t volatile BAUD_FRACFP_MODE;
	/* Baud Rate Value */
#define USART_BAUD_FRACFP_MODE_BAUD_Lsb		0u
#define USART_BAUD_FRACFP_MODE_BAUD_Msb		12u
	/* Fractional Part */
#define USART_BAUD_FRACFP_MODE_FP_Lsb		13u
#define USART_BAUD_FRACFP_MODE_FP_Msb		15u

	/* 0x0C: USART Baud Rate */
	uint16_t volatile BAUD_USARTFP_MODE;
	/* Baud Rate Value */
#define USART_BAUD_USARTFP_MODE_BAUD_Lsb	0u
#define USART_BAUD_USARTFP_MODE_BAUD_Msb	15u

	/* 0x0E: USART Receive Pulse Length */
	uint8_t volatile RXPL;
	/* Receive Pulse Length */
#define USART_RXPL_RXPL_Lsb			0u
#define USART_RXPL_RXPL_Msb			7u

	/* 0x0F */
	uint8_t volatile RESERVED20[0x14-0x0F];

	/* 0x14: USART Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Data Register Empty Interrupt Disable */
#define USART_INTENCLR_DRE			0u
	/* Transmit Complete Interrupt Disable */
#define USART_INTENCLR_TXC			1u
	/* Receive Complete Interrupt Disable */
#define USART_INTENCLR_RXC			2u
	/* Receive Start Interrupt Disable */
#define USART_INTENCLR_RXS			3u
	/* Clear To Send Input Change Interrupt Disable */
#define USART_INTENCLR_CTSIC			4u
	/* Break Received Interrupt Disable */
#define USART_INTENCLR_RXBRK			5u
	/* Combined Error Interrupt Disable */
#define USART_INTENCLR_ERROR			7u

	/* 0x15 */
	uint8_t volatile RESERVED21[0x16-0x15];

	/* 0x16: USART Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Data Register Empty Interrupt Enable */
#define USART_INTENSET_DRE			0u
	/* Transmit Complete Interrupt Enable */
#define USART_INTENSET_TXC			1u
	/* Receive Complete Interrupt Enable */
#define USART_INTENSET_RXC			2u
	/* Receive Start Interrupt Enable */
#define USART_INTENSET_RXS			3u
	/* Clear To Send Input Change Interrupt Enable */
#define USART_INTENSET_CTSIC			4u
	/* Break Received Interrupt Enable */
#define USART_INTENSET_RXBRK			5u
	/* Combined Error Interrupt Enable */
#define USART_INTENSET_ERROR			7u

	/* 0x17 */
	uint8_t volatile RESERVED22[0x18-0x17];

	/* 0x18: USART Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Data Register Empty Interrupt */
#define USART_INTFLAG_DRE			0u
	/* Transmit Complete Interrupt */
#define USART_INTFLAG_TXC			1u
	/* Receive Complete Interrupt */
#define USART_INTFLAG_RXC			2u
	/* Receive Start Interrupt */
#define USART_INTFLAG_RXS			3u
	/* Clear To Send Input Change Interrupt */
#define USART_INTFLAG_CTSIC			4u
	/* Break Received Interrupt */
#define USART_INTFLAG_RXBRK			5u
	/* Combined Error Interrupt */
#define USART_INTFLAG_ERROR			7u

	/* 0x19 */
	uint8_t volatile RESERVED23[0x1A-0x19];

	/* 0x1A: USART Status */
	uint16_t volatile STATUS;
	/* Parity Error */
#define USART_STATUS_PERR			0u
	/* Frame Error */
#define USART_STATUS_FERR			1u
	/* Buffer Overflow */
#define USART_STATUS_BUFOVF			2u
	/* Clear To Send */
#define USART_STATUS_CTS			3u
	/* Inconsistent Sync Field */
#define USART_STATUS_ISF			4u
	/* Collision Detected */
#define USART_STATUS_COLL			5u

	/* 0x1C: USART Syncbusy */
	uint32_t volatile const SYNCBUSY;
	/* Software Reset Synchronization Busy */
#define USART_SYNCBUSY_SWRST			0u
	/* SERCOM Enable Synchronization Busy */
#define USART_SYNCBUSY_ENABLE			1u
	/* CTRLB Synchronization Busy */
#define USART_SYNCBUSY_CTRLB			2u

	/* 0x20 */
	uint8_t volatile RESERVED24[0x28-0x20];

	/* 0x28: USART Data */
	uint16_t volatile DATA;
	/* Data Value */
#define USART_DATA_DATA_Lsb			0u
#define USART_DATA_DATA_Msb			8u

	/* 0x2A */
	uint8_t volatile RESERVED25[0x30-0x2A];

	/* 0x30: USART Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Mode */
#define USART_DBGCTRL_DBGSTOP			0u

};


#define SYSCTRL ((struct zmcu_sysctrl *)0x40000800)

/* System Control */
struct zmcu_sysctrl {

	/* 0x00: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
	/* XOSC Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_XOSCRDY		0u
	/* XOSC32K Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_XOSC32KRDY		1u
	/* OSC32K Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_OSC32KRDY		2u
	/* OSC8M Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_OSC8MRDY		3u
	/* DFLL Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_DFLLRDY		4u
	/* DFLL Out Of Bounds Interrupt Enable */
#define SYSCTRL_INTENCLR_DFLLOOB		5u
	/* DFLL Lock Fine Interrupt Enable */
#define SYSCTRL_INTENCLR_DFLLLCKF		6u
	/* DFLL Lock Coarse Interrupt Enable */
#define SYSCTRL_INTENCLR_DFLLLCKC		7u
	/* DFLL Reference Clock Stopped Interrupt Enable */
#define SYSCTRL_INTENCLR_DFLLRCS		8u
	/* BOD33 Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_BOD33RDY		9u
	/* BOD33 Detection Interrupt Enable */
#define SYSCTRL_INTENCLR_BOD33DET		10u
	/* BOD33 Synchronization Ready Interrupt Enable */
#define SYSCTRL_INTENCLR_B33SRDY		11u
	/* DPLL Lock Rise Interrupt Enable */
#define SYSCTRL_INTENCLR_DPLLLCKR		15u
	/* DPLL Lock Fall Interrupt Enable */
#define SYSCTRL_INTENCLR_DPLLLCKF		16u
	/* DPLL Lock Timeout Interrupt Enable */
#define SYSCTRL_INTENCLR_DPLLLTO		17u

	/* 0x04: Interrupt Enable Set */
	uint32_t volatile INTENSET;
	/* XOSC Ready Interrupt Enable */
#define SYSCTRL_INTENSET_XOSCRDY		0u
	/* XOSC32K Ready Interrupt Enable */
#define SYSCTRL_INTENSET_XOSC32KRDY		1u
	/* OSC32K Ready Interrupt Enable */
#define SYSCTRL_INTENSET_OSC32KRDY		2u
	/* OSC8M Ready Interrupt Enable */
#define SYSCTRL_INTENSET_OSC8MRDY		3u
	/* DFLL Ready Interrupt Enable */
#define SYSCTRL_INTENSET_DFLLRDY		4u
	/* DFLL Out Of Bounds Interrupt Enable */
#define SYSCTRL_INTENSET_DFLLOOB		5u
	/* DFLL Lock Fine Interrupt Enable */
#define SYSCTRL_INTENSET_DFLLLCKF		6u
	/* DFLL Lock Coarse Interrupt Enable */
#define SYSCTRL_INTENSET_DFLLLCKC		7u
	/* DFLL Reference Clock Stopped Interrupt Enable */
#define SYSCTRL_INTENSET_DFLLRCS		8u
	/* BOD33 Ready Interrupt Enable */
#define SYSCTRL_INTENSET_BOD33RDY		9u
	/* BOD33 Detection Interrupt Enable */
#define SYSCTRL_INTENSET_BOD33DET		10u
	/* BOD33 Synchronization Ready Interrupt Enable */
#define SYSCTRL_INTENSET_B33SRDY		11u
	/* DPLL Lock Rise Interrupt Enable */
#define SYSCTRL_INTENSET_DPLLLCKR		15u
	/* DPLL Lock Fall Interrupt Enable */
#define SYSCTRL_INTENSET_DPLLLCKF		16u
	/* DPLL Lock Timeout Interrupt Enable */
#define SYSCTRL_INTENSET_DPLLLTO		17u

	/* 0x08: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
	/* XOSC Ready */
#define SYSCTRL_INTFLAG_XOSCRDY			0u
	/* XOSC32K Ready */
#define SYSCTRL_INTFLAG_XOSC32KRDY		1u
	/* OSC32K Ready */
#define SYSCTRL_INTFLAG_OSC32KRDY		2u
	/* OSC8M Ready */
#define SYSCTRL_INTFLAG_OSC8MRDY		3u
	/* DFLL Ready */
#define SYSCTRL_INTFLAG_DFLLRDY			4u
	/* DFLL Out Of Bounds */
#define SYSCTRL_INTFLAG_DFLLOOB			5u
	/* DFLL Lock Fine */
#define SYSCTRL_INTFLAG_DFLLLCKF		6u
	/* DFLL Lock Coarse */
#define SYSCTRL_INTFLAG_DFLLLCKC		7u
	/* DFLL Reference Clock Stopped */
#define SYSCTRL_INTFLAG_DFLLRCS			8u
	/* BOD33 Ready */
#define SYSCTRL_INTFLAG_BOD33RDY		9u
	/* BOD33 Detection */
#define SYSCTRL_INTFLAG_BOD33DET		10u
	/* BOD33 Synchronization Ready */
#define SYSCTRL_INTFLAG_B33SRDY			11u
	/* DPLL Lock Rise */
#define SYSCTRL_INTFLAG_DPLLLCKR		15u
	/* DPLL Lock Fall */
#define SYSCTRL_INTFLAG_DPLLLCKF		16u
	/* DPLL Lock Timeout */
#define SYSCTRL_INTFLAG_DPLLLTO			17u

	/* 0x0C: Power and Clocks Status */
	uint32_t volatile const PCLKSR;
	/* XOSC Ready */
#define SYSCTRL_PCLKSR_XOSCRDY			0u
	/* XOSC32K Ready */
#define SYSCTRL_PCLKSR_XOSC32KRDY		1u
	/* OSC32K Ready */
#define SYSCTRL_PCLKSR_OSC32KRDY		2u
	/* OSC8M Ready */
#define SYSCTRL_PCLKSR_OSC8MRDY			3u
	/* DFLL Ready */
#define SYSCTRL_PCLKSR_DFLLRDY			4u
	/* DFLL Out Of Bounds */
#define SYSCTRL_PCLKSR_DFLLOOB			5u
	/* DFLL Lock Fine */
#define SYSCTRL_PCLKSR_DFLLLCKF			6u
	/* DFLL Lock Coarse */
#define SYSCTRL_PCLKSR_DFLLLCKC			7u
	/* DFLL Reference Clock Stopped */
#define SYSCTRL_PCLKSR_DFLLRCS			8u
	/* BOD33 Ready */
#define SYSCTRL_PCLKSR_BOD33RDY			9u
	/* BOD33 Detection */
#define SYSCTRL_PCLKSR_BOD33DET			10u
	/* BOD33 Synchronization Ready */
#define SYSCTRL_PCLKSR_B33SRDY			11u
	/* DPLL Lock Rise */
#define SYSCTRL_PCLKSR_DPLLLCKR			15u
	/* DPLL Lock Fall */
#define SYSCTRL_PCLKSR_DPLLLCKF			16u
	/* DPLL Lock Timeout */
#define SYSCTRL_PCLKSR_DPLLLTO			17u

	/* 0x10: External Multipurpose Crystal Oscillator (XOSC) Control */
	uint16_t volatile XOSC;
	/* Oscillator Enable */
#define SYSCTRL_XOSC_ENABLE			1u
	/* Crystal Oscillator Enable */
#define SYSCTRL_XOSC_XTALEN			2u
	/* Run in Standby */
#define SYSCTRL_XOSC_RUNSTDBY			6u
	/* On Demand Control */
#define SYSCTRL_XOSC_ONDEMAND			7u
	/* Oscillator Gain */
#define SYSCTRL_XOSC_GAIN_Lsb			8u
#define SYSCTRL_XOSC_GAIN_Msb			10u
#define SYSCTRL_XOSC_GAIN_0			0x0
#define SYSCTRL_XOSC_GAIN_1			0x1
#define SYSCTRL_XOSC_GAIN_2			0x2
#define SYSCTRL_XOSC_GAIN_3			0x3
#define SYSCTRL_XOSC_GAIN_4			0x4
	/* Automatic Amplitude Gain Control */
#define SYSCTRL_XOSC_AMPGC			11u
	/* Start-Up Time */
#define SYSCTRL_XOSC_STARTUP_Lsb		12u
#define SYSCTRL_XOSC_STARTUP_Msb		15u

	/* 0x12 */
	uint8_t volatile RESERVED0[0x14-0x12];

	/* 0x14: 32kHz External Crystal Oscillator (XOSC32K) Control */
	uint16_t volatile XOSC32K;
	/* Oscillator Enable */
#define SYSCTRL_XOSC32K_ENABLE			1u
	/* Crystal Oscillator Enable */
#define SYSCTRL_XOSC32K_XTALEN			2u
	/* 32kHz Output Enable */
#define SYSCTRL_XOSC32K_EN32K			3u
	/* 1kHz Output Enable */
#define SYSCTRL_XOSC32K_EN1K			4u
	/* Automatic Amplitude Control Enable */
#define SYSCTRL_XOSC32K_AAMPEN			5u
	/* Run in Standby */
#define SYSCTRL_XOSC32K_RUNSTDBY		6u
	/* On Demand Control */
#define SYSCTRL_XOSC32K_ONDEMAND		7u
	/* Oscillator Start-Up Time */
#define SYSCTRL_XOSC32K_STARTUP_Lsb		8u
#define SYSCTRL_XOSC32K_STARTUP_Msb		10u
	/* Write Lock */
#define SYSCTRL_XOSC32K_WRTLOCK			12u

	/* 0x16 */
	uint8_t volatile RESERVED1[0x18-0x16];

	/* 0x18: 32kHz Internal Oscillator (OSC32K) Control */
	uint32_t volatile OSC32K;
	/* Oscillator Enable */
#define SYSCTRL_OSC32K_ENABLE			1u
	/* 32kHz Output Enable */
#define SYSCTRL_OSC32K_EN32K			2u
	/* 1kHz Output Enable */
#define SYSCTRL_OSC32K_EN1K			3u
	/* Run in Standby */
#define SYSCTRL_OSC32K_RUNSTDBY			6u
	/* On Demand Control */
#define SYSCTRL_OSC32K_ONDEMAND			7u
	/* Oscillator Start-Up Time */
#define SYSCTRL_OSC32K_STARTUP_Lsb		8u
#define SYSCTRL_OSC32K_STARTUP_Msb		10u
	/* Write Lock */
#define SYSCTRL_OSC32K_WRTLOCK			12u
	/* Oscillator Calibration */
#define SYSCTRL_OSC32K_CALIB_Lsb		16u
#define SYSCTRL_OSC32K_CALIB_Msb		22u

	/* 0x1C: 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control */
	uint8_t volatile OSCULP32K;
	/* Oscillator Calibration */
#define SYSCTRL_OSCULP32K_CALIB_Lsb		0u
#define SYSCTRL_OSCULP32K_CALIB_Msb		4u
	/* Write Lock */
#define SYSCTRL_OSCULP32K_WRTLOCK		7u

	/* 0x1D */
	uint8_t volatile RESERVED2[0x20-0x1D];

	/* 0x20: 8MHz Internal Oscillator (OSC8M) Control */
	uint32_t volatile OSC8M;
	/* Oscillator Enable */
#define SYSCTRL_OSC8M_ENABLE			1u
	/* Run in Standby */
#define SYSCTRL_OSC8M_RUNSTDBY			6u
	/* On Demand Control */
#define SYSCTRL_OSC8M_ONDEMAND			7u
	/* Oscillator Prescaler */
#define SYSCTRL_OSC8M_PRESC_Lsb			8u
#define SYSCTRL_OSC8M_PRESC_Msb			9u
#define SYSCTRL_OSC8M_PRESC_0			0x0
#define SYSCTRL_OSC8M_PRESC_1			0x1
#define SYSCTRL_OSC8M_PRESC_2			0x2
#define SYSCTRL_OSC8M_PRESC_3			0x3
	/* Oscillator Calibration */
#define SYSCTRL_OSC8M_CALIB_Lsb			16u
#define SYSCTRL_OSC8M_CALIB_Msb			27u
	/* Oscillator Frequency Range */
#define SYSCTRL_OSC8M_FRANGE_Lsb		30u
#define SYSCTRL_OSC8M_FRANGE_Msb		31u
#define SYSCTRL_OSC8M_FRANGE_0			0x0
#define SYSCTRL_OSC8M_FRANGE_1			0x1
#define SYSCTRL_OSC8M_FRANGE_2			0x2
#define SYSCTRL_OSC8M_FRANGE_3			0x3

	/* 0x24: DFLL48M Control */
	uint16_t volatile DFLLCTRL;
	/* DFLL Enable */
#define SYSCTRL_DFLLCTRL_ENABLE			1u
	/* Operating Mode Selection */
#define SYSCTRL_DFLLCTRL_MODE			2u
	/* Stable DFLL Frequency */
#define SYSCTRL_DFLLCTRL_STABLE			3u
	/* Lose Lock After Wake */
#define SYSCTRL_DFLLCTRL_LLAW			4u
	/* USB Clock Recovery Mode */
#define SYSCTRL_DFLLCTRL_USBCRM			5u
	/* Run in Standby */
#define SYSCTRL_DFLLCTRL_RUNSTDBY		6u
	/* On Demand Control */
#define SYSCTRL_DFLLCTRL_ONDEMAND		7u
	/* Chill Cycle Disable */
#define SYSCTRL_DFLLCTRL_CCDIS			8u
	/* Quick Lock Disable */
#define SYSCTRL_DFLLCTRL_QLDIS			9u
	/* Bypass Coarse Lock */
#define SYSCTRL_DFLLCTRL_BPLCKC			10u
	/* Wait Lock */
#define SYSCTRL_DFLLCTRL_WAITLOCK		11u

	/* 0x26 */
	uint8_t volatile RESERVED3[0x28-0x26];

	/* 0x28: DFLL48M Value */
	uint32_t volatile DFLLVAL;
	/* Fine Value */
#define SYSCTRL_DFLLVAL_FINE_Lsb		0u
#define SYSCTRL_DFLLVAL_FINE_Msb		9u
	/* Coarse Value */
#define SYSCTRL_DFLLVAL_COARSE_Lsb		10u
#define SYSCTRL_DFLLVAL_COARSE_Msb		15u
	/* Multiplication Ratio Difference */
#define SYSCTRL_DFLLVAL_DIFF_Lsb		16u
#define SYSCTRL_DFLLVAL_DIFF_Msb		31u

	/* 0x2C: DFLL48M Multiplier */
	uint32_t volatile DFLLMUL;
	/* DFLL Multiply Factor */
#define SYSCTRL_DFLLMUL_MUL_Lsb			0u
#define SYSCTRL_DFLLMUL_MUL_Msb			15u
	/* Fine Maximum Step */
#define SYSCTRL_DFLLMUL_FSTEP_Lsb		16u
#define SYSCTRL_DFLLMUL_FSTEP_Msb		25u
	/* Coarse Maximum Step */
#define SYSCTRL_DFLLMUL_CSTEP_Lsb		26u
#define SYSCTRL_DFLLMUL_CSTEP_Msb		31u

	/* 0x30: DFLL48M Synchronization */
	uint8_t volatile DFLLSYNC;
	/* Read Request */
#define SYSCTRL_DFLLSYNC_READREQ		7u

	/* 0x31 */
	uint8_t volatile RESERVED4[0x34-0x31];

	/* 0x34: 3.3V Brown-Out Detector (BOD33) Control */
	uint32_t volatile BOD33;
	/* Enable */
#define SYSCTRL_BOD33_ENABLE			1u
	/* Hysteresis */
#define SYSCTRL_BOD33_HYST			2u
	/* BOD33 Action */
#define SYSCTRL_BOD33_ACTION_Lsb		3u
#define SYSCTRL_BOD33_ACTION_Msb		4u
#define SYSCTRL_BOD33_ACTION_NONE		0x0
#define SYSCTRL_BOD33_ACTION_RESET		0x1
#define SYSCTRL_BOD33_ACTION_INTERRUPT		0x2
	/* Run in Standby */
#define SYSCTRL_BOD33_RUNSTDBY			6u
	/* Operation Mode */
#define SYSCTRL_BOD33_MODE			8u
	/* Clock Enable */
#define SYSCTRL_BOD33_CEN			9u
	/* Prescaler Select */
#define SYSCTRL_BOD33_PSEL_Lsb			12u
#define SYSCTRL_BOD33_PSEL_Msb			15u
#define SYSCTRL_BOD33_PSEL_DIV2			0x0
#define SYSCTRL_BOD33_PSEL_DIV4			0x1
#define SYSCTRL_BOD33_PSEL_DIV8			0x2
#define SYSCTRL_BOD33_PSEL_DIV16		0x3
#define SYSCTRL_BOD33_PSEL_DIV32		0x4
#define SYSCTRL_BOD33_PSEL_DIV64		0x5
#define SYSCTRL_BOD33_PSEL_DIV128		0x6
#define SYSCTRL_BOD33_PSEL_DIV256		0x7
#define SYSCTRL_BOD33_PSEL_DIV512		0x8
#define SYSCTRL_BOD33_PSEL_DIV1K		0x9
#define SYSCTRL_BOD33_PSEL_DIV2K		0xa
#define SYSCTRL_BOD33_PSEL_DIV4K		0xb
#define SYSCTRL_BOD33_PSEL_DIV8K		0xc
#define SYSCTRL_BOD33_PSEL_DIV16K		0xd
#define SYSCTRL_BOD33_PSEL_DIV32K		0xe
#define SYSCTRL_BOD33_PSEL_DIV64K		0xf
	/* BOD33 Threshold Level */
#define SYSCTRL_BOD33_LEVEL_Lsb			16u
#define SYSCTRL_BOD33_LEVEL_Msb			21u

	/* 0x38 */
	uint8_t volatile RESERVED5[0x40-0x38];

	/* 0x40: Voltage References System (VREF) Control */
	uint32_t volatile VREF;
	/* Temperature Sensor Enable */
#define SYSCTRL_VREF_TSEN			1u
	/* Bandgap Output Enable */
#define SYSCTRL_VREF_BGOUTEN			2u
	/* Bandgap Voltage Generator Calibration */
#define SYSCTRL_VREF_CALIB_Lsb			16u
#define SYSCTRL_VREF_CALIB_Msb			26u

	/* 0x44: DPLL Control A */
	uint8_t volatile DPLLCTRLA;
	/* DPLL Enable */
#define SYSCTRL_DPLLCTRLA_ENABLE		1u
	/* Run in Standby */
#define SYSCTRL_DPLLCTRLA_RUNSTDBY		6u
	/* On Demand Clock Activation */
#define SYSCTRL_DPLLCTRLA_ONDEMAND		7u

	/* 0x45 */
	uint8_t volatile RESERVED6[0x48-0x45];

	/* 0x48: DPLL Ratio Control */
	uint32_t volatile DPLLRATIO;
	/* Loop Divider Ratio */
#define SYSCTRL_DPLLRATIO_LDR_Lsb		0u
#define SYSCTRL_DPLLRATIO_LDR_Msb		11u
	/* Loop Divider Ratio Fractional Part */
#define SYSCTRL_DPLLRATIO_LDRFRAC_Lsb		16u
#define SYSCTRL_DPLLRATIO_LDRFRAC_Msb		19u

	/* 0x4C: DPLL Control B */
	uint32_t volatile DPLLCTRLB;
	/* Proportional Integral Filter Selection */
#define SYSCTRL_DPLLCTRLB_FILTER_Lsb		0u
#define SYSCTRL_DPLLCTRLB_FILTER_Msb		1u
#define SYSCTRL_DPLLCTRLB_FILTER_DEFAULT	0x0
#define SYSCTRL_DPLLCTRLB_FILTER_LBFILT		0x1
#define SYSCTRL_DPLLCTRLB_FILTER_HBFILT		0x2
#define SYSCTRL_DPLLCTRLB_FILTER_HDFILT		0x3
	/* Low-Power Enable */
#define SYSCTRL_DPLLCTRLB_LPEN			2u
	/* Wake Up Fast */
#define SYSCTRL_DPLLCTRLB_WUF			3u
	/* Reference Clock Selection */
#define SYSCTRL_DPLLCTRLB_REFCLK_Lsb		4u
#define SYSCTRL_DPLLCTRLB_REFCLK_Msb		5u
#define SYSCTRL_DPLLCTRLB_REFCLK_REF0		0x0
#define SYSCTRL_DPLLCTRLB_REFCLK_REF1		0x1
#define SYSCTRL_DPLLCTRLB_REFCLK_GCLK		0x2
	/* Lock Time */
#define SYSCTRL_DPLLCTRLB_LTIME_Lsb		8u
#define SYSCTRL_DPLLCTRLB_LTIME_Msb		10u
#define SYSCTRL_DPLLCTRLB_LTIME_NONE		0x0
#define SYSCTRL_DPLLCTRLB_LTIME_8MS		0x4
#define SYSCTRL_DPLLCTRLB_LTIME_9MS		0x5
#define SYSCTRL_DPLLCTRLB_LTIME_10MS		0x6
#define SYSCTRL_DPLLCTRLB_LTIME_11MS		0x7
	/* Lock Bypass */
#define SYSCTRL_DPLLCTRLB_LBYPASS		12u
	/* Clock Divider */
#define SYSCTRL_DPLLCTRLB_DIV_Lsb		16u
#define SYSCTRL_DPLLCTRLB_DIV_Msb		26u

	/* 0x50: DPLL Status */
	uint8_t volatile const DPLLSTATUS;
	/* DPLL Lock Status */
#define SYSCTRL_DPLLSTATUS_LOCK			0u
	/* Output Clock Ready */
#define SYSCTRL_DPLLSTATUS_CLKRDY		1u
	/* DPLL Enable */
#define SYSCTRL_DPLLSTATUS_ENABLE		2u
	/* Divider Enable */
#define SYSCTRL_DPLLSTATUS_DIV			3u

};


#define TC1 ((struct zmcu_tc *)0x42001800)
#define TC2 ((struct zmcu_ *)0x42001C00)

/* Basic Timer Counter 1 */
struct zmcu_tc {


/* TC: Basic Timer Counter 1: 8-bit Counter Mode */
struct zmcu_tc_count8 {

	/* 0x00: Control A */
	uint16_t volatile CTRLA;
	/* Software Reset */
#define TC_COUNT8_CTRLA_SWRST			0u
	/* Enable */
#define TC_COUNT8_CTRLA_ENABLE			1u
	/* TC Mode */
#define TC_COUNT8_CTRLA_MODE_Lsb		2u
#define TC_COUNT8_CTRLA_MODE_Msb		3u
#define TC_COUNT8_CTRLA_MODE_COUNT16		0x0
#define TC_COUNT8_CTRLA_MODE_COUNT8		0x1
#define TC_COUNT8_CTRLA_MODE_COUNT32		0x2
	/* Waveform Generation Operation */
#define TC_COUNT8_CTRLA_WAVEGEN_Lsb		5u
#define TC_COUNT8_CTRLA_WAVEGEN_Msb		6u
#define TC_COUNT8_CTRLA_WAVEGEN_NFRQ		0x0
#define TC_COUNT8_CTRLA_WAVEGEN_MFRQ		0x1
#define TC_COUNT8_CTRLA_WAVEGEN_NPWM		0x2
#define TC_COUNT8_CTRLA_WAVEGEN_MPWM		0x3
	/* Prescaler */
#define TC_COUNT8_CTRLA_PRESCALER_Lsb		8u
#define TC_COUNT8_CTRLA_PRESCALER_Msb		10u
#define TC_COUNT8_CTRLA_PRESCALER_DIV1		0x0
#define TC_COUNT8_CTRLA_PRESCALER_DIV2		0x1
#define TC_COUNT8_CTRLA_PRESCALER_DIV4		0x2
#define TC_COUNT8_CTRLA_PRESCALER_DIV8		0x3
#define TC_COUNT8_CTRLA_PRESCALER_DIV16		0x4
#define TC_COUNT8_CTRLA_PRESCALER_DIV64		0x5
#define TC_COUNT8_CTRLA_PRESCALER_DIV256	0x6
#define TC_COUNT8_CTRLA_PRESCALER_DIV1024	0x7
	/* Run in Standby */
#define TC_COUNT8_CTRLA_RUNSTDBY		11u
	/* Prescaler and Counter Synchronization */
#define TC_COUNT8_CTRLA_PRESCSYNC_Lsb		12u
#define TC_COUNT8_CTRLA_PRESCSYNC_Msb		13u
#define TC_COUNT8_CTRLA_PRESCSYNC_GCLK		0x0
#define TC_COUNT8_CTRLA_PRESCSYNC_PRESC		0x1
#define TC_COUNT8_CTRLA_PRESCSYNC_RESYNC	0x2

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define TC_COUNT8_READREQ_ADDR_Lsb		0u
#define TC_COUNT8_READREQ_ADDR_Msb		4u
	/* Read Continuously */
#define TC_COUNT8_READREQ_RCONT			14u
	/* Read Request */
#define TC_COUNT8_READREQ_RREQ			15u

	/* 0x04: Control B Clear */
	uint8_t volatile CTRLBCLR;
	/* Counter Direction */
#define TC_COUNT8_CTRLBCLR_DIR			0u
	/* One-Shot */
#define TC_COUNT8_CTRLBCLR_ONESHOT		2u
	/* Command */
#define TC_COUNT8_CTRLBCLR_CMD_Lsb		6u
#define TC_COUNT8_CTRLBCLR_CMD_Msb		7u
#define TC_COUNT8_CTRLBCLR_CMD_NONE		0x0
#define TC_COUNT8_CTRLBCLR_CMD_RETRIGGER	0x1
#define TC_COUNT8_CTRLBCLR_CMD_STOP		0x2

	/* 0x05: Control B Set */
	uint8_t volatile CTRLBSET;
	/* Counter Direction */
#define TC_COUNT8_CTRLBSET_DIR			0u
	/* One-Shot */
#define TC_COUNT8_CTRLBSET_ONESHOT		2u
	/* Command */
#define TC_COUNT8_CTRLBSET_CMD_Lsb		6u
#define TC_COUNT8_CTRLBSET_CMD_Msb		7u
#define TC_COUNT8_CTRLBSET_CMD_NONE		0x0
#define TC_COUNT8_CTRLBSET_CMD_RETRIGGER	0x1
#define TC_COUNT8_CTRLBSET_CMD_STOP		0x2

	/* 0x06: Control C */
	uint8_t volatile CTRLC;
	/* Output Waveform 0 Invert Enable */
#define TC_COUNT8_CTRLC_INVEN0			0u
	/* Output Waveform 1 Invert Enable */
#define TC_COUNT8_CTRLC_INVEN1			1u
	/* Capture Channel 0 Enable */
#define TC_COUNT8_CTRLC_CPTEN0			4u
	/* Capture Channel 1 Enable */
#define TC_COUNT8_CTRLC_CPTEN1			5u

	/* 0x07 */
	uint8_t volatile RESERVED0[0x08-0x07];

	/* 0x08: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Run Mode */
#define TC_COUNT8_DBGCTRL_DBGRUN		0u

	/* 0x09 */
	uint8_t volatile RESERVED1[0x0A-0x09];

	/* 0x0A: Event Control */
	uint16_t volatile EVCTRL;
	/* Event Action */
#define TC_COUNT8_EVCTRL_EVACT_Lsb		0u
#define TC_COUNT8_EVCTRL_EVACT_Msb		2u
#define TC_COUNT8_EVCTRL_EVACT_OFF		0x0
#define TC_COUNT8_EVCTRL_EVACT_RETRIGGER	0x1
#define TC_COUNT8_EVCTRL_EVACT_COUNT		0x2
#define TC_COUNT8_EVCTRL_EVACT_START		0x3
#define TC_COUNT8_EVCTRL_EVACT_PPW		0x5
#define TC_COUNT8_EVCTRL_EVACT_PWP		0x6
	/* TC Inverted Event Input */
#define TC_COUNT8_EVCTRL_TCINV			4u
	/* TC Event Input */
#define TC_COUNT8_EVCTRL_TCEI			5u
	/* Overflow/Underflow Event Output Enable */
#define TC_COUNT8_EVCTRL_OVFEO			8u
	/* Match or Capture Channel 0 Event Output Enable */
#define TC_COUNT8_EVCTRL_MCEO0			12u
	/* Match or Capture Channel 1 Event Output Enable */
#define TC_COUNT8_EVCTRL_MCEO1			13u

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Overflow Interrupt Enable */
#define TC_COUNT8_INTENCLR_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT8_INTENCLR_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT8_INTENCLR_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT8_INTENCLR_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT8_INTENCLR_MC1			5u

	/* 0x0D: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Overflow Interrupt Enable */
#define TC_COUNT8_INTENSET_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT8_INTENSET_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT8_INTENSET_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT8_INTENSET_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT8_INTENSET_MC1			5u

	/* 0x0E: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Overflow */
#define TC_COUNT8_INTFLAG_OVF			0u
	/* Error */
#define TC_COUNT8_INTFLAG_ERR			1u
	/* Synchronization Ready */
#define TC_COUNT8_INTFLAG_SYNCRDY		3u
	/* Match or Capture Channel 0 */
#define TC_COUNT8_INTFLAG_MC0			4u
	/* Match or Capture Channel 1 */
#define TC_COUNT8_INTFLAG_MC1			5u

	/* 0x0F: Status */
	uint8_t volatile const STATUS;
	/* Stop */
#define TC_COUNT8_STATUS_STOP			3u
	/* Slave */
#define TC_COUNT8_STATUS_SLAVE			4u
	/* Synchronization Busy */
#define TC_COUNT8_STATUS_SYNCBUSY		7u

	/* 0x10: COUNT8 Counter Value */
	uint8_t volatile COUNT;
	/* Counter Value */
#define TC_COUNT8_COUNT_COUNT_Lsb		0u
#define TC_COUNT8_COUNT_COUNT_Msb		7u

	/* 0x11 */
	uint8_t volatile RESERVED2[0x14-0x11];

	/* 0x14: COUNT8 Period Value */
	uint8_t volatile PER;
	/* Period Value */
#define TC_COUNT8_PER_PER_Lsb			0u
#define TC_COUNT8_PER_PER_Msb			7u

	/* 0x15 */
	uint8_t volatile RESERVED3[0x18-0x15];

	/* 0x18: COUNT8 Compare/Capture */
	uint8_t volatile CC[2];
	/* Compare/Capture Value */
#define TC_COUNT8_CC_CC_Lsb			0u
#define TC_COUNT8_CC_CC_Msb			7u

};


/* TC: Basic Timer Counter 1: 16-bit Counter Mode */
struct zmcu_tc_count16 {

	/* 0x00: Control A */
	uint16_t volatile CTRLA;
	/* Software Reset */
#define TC_COUNT16_CTRLA_SWRST			0u
	/* Enable */
#define TC_COUNT16_CTRLA_ENABLE			1u
	/* TC Mode */
#define TC_COUNT16_CTRLA_MODE_Lsb		2u
#define TC_COUNT16_CTRLA_MODE_Msb		3u
#define TC_COUNT16_CTRLA_MODE_COUNT16		0x0
#define TC_COUNT16_CTRLA_MODE_COUNT8		0x1
#define TC_COUNT16_CTRLA_MODE_COUNT32		0x2
	/* Waveform Generation Operation */
#define TC_COUNT16_CTRLA_WAVEGEN_Lsb		5u
#define TC_COUNT16_CTRLA_WAVEGEN_Msb		6u
#define TC_COUNT16_CTRLA_WAVEGEN_NFRQ		0x0
#define TC_COUNT16_CTRLA_WAVEGEN_MFRQ		0x1
#define TC_COUNT16_CTRLA_WAVEGEN_NPWM		0x2
#define TC_COUNT16_CTRLA_WAVEGEN_MPWM		0x3
	/* Prescaler */
#define TC_COUNT16_CTRLA_PRESCALER_Lsb		8u
#define TC_COUNT16_CTRLA_PRESCALER_Msb		10u
#define TC_COUNT16_CTRLA_PRESCALER_DIV1		0x0
#define TC_COUNT16_CTRLA_PRESCALER_DIV2		0x1
#define TC_COUNT16_CTRLA_PRESCALER_DIV4		0x2
#define TC_COUNT16_CTRLA_PRESCALER_DIV8		0x3
#define TC_COUNT16_CTRLA_PRESCALER_DIV16	0x4
#define TC_COUNT16_CTRLA_PRESCALER_DIV64	0x5
#define TC_COUNT16_CTRLA_PRESCALER_DIV256	0x6
#define TC_COUNT16_CTRLA_PRESCALER_DIV1024	0x7
	/* Run in Standby */
#define TC_COUNT16_CTRLA_RUNSTDBY		11u
	/* Prescaler and Counter Synchronization */
#define TC_COUNT16_CTRLA_PRESCSYNC_Lsb		12u
#define TC_COUNT16_CTRLA_PRESCSYNC_Msb		13u
#define TC_COUNT16_CTRLA_PRESCSYNC_GCLK		0x0
#define TC_COUNT16_CTRLA_PRESCSYNC_PRESC	0x1
#define TC_COUNT16_CTRLA_PRESCSYNC_RESYNC	0x2

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define TC_COUNT16_READREQ_ADDR_Lsb		0u
#define TC_COUNT16_READREQ_ADDR_Msb		4u
	/* Read Continuously */
#define TC_COUNT16_READREQ_RCONT		14u
	/* Read Request */
#define TC_COUNT16_READREQ_RREQ			15u

	/* 0x04: Control B Clear */
	uint8_t volatile CTRLBCLR;
	/* Counter Direction */
#define TC_COUNT16_CTRLBCLR_DIR			0u
	/* One-Shot */
#define TC_COUNT16_CTRLBCLR_ONESHOT		2u
	/* Command */
#define TC_COUNT16_CTRLBCLR_CMD_Lsb		6u
#define TC_COUNT16_CTRLBCLR_CMD_Msb		7u
#define TC_COUNT16_CTRLBCLR_CMD_NONE		0x0
#define TC_COUNT16_CTRLBCLR_CMD_RETRIGGER	0x1
#define TC_COUNT16_CTRLBCLR_CMD_STOP		0x2

	/* 0x05: Control B Set */
	uint8_t volatile CTRLBSET;
	/* Counter Direction */
#define TC_COUNT16_CTRLBSET_DIR			0u
	/* One-Shot */
#define TC_COUNT16_CTRLBSET_ONESHOT		2u
	/* Command */
#define TC_COUNT16_CTRLBSET_CMD_Lsb		6u
#define TC_COUNT16_CTRLBSET_CMD_Msb		7u
#define TC_COUNT16_CTRLBSET_CMD_NONE		0x0
#define TC_COUNT16_CTRLBSET_CMD_RETRIGGER	0x1
#define TC_COUNT16_CTRLBSET_CMD_STOP		0x2

	/* 0x06: Control C */
	uint8_t volatile CTRLC;
	/* Output Waveform 0 Invert Enable */
#define TC_COUNT16_CTRLC_INVEN0			0u
	/* Output Waveform 1 Invert Enable */
#define TC_COUNT16_CTRLC_INVEN1			1u
	/* Capture Channel 0 Enable */
#define TC_COUNT16_CTRLC_CPTEN0			4u
	/* Capture Channel 1 Enable */
#define TC_COUNT16_CTRLC_CPTEN1			5u

	/* 0x07 */
	uint8_t volatile RESERVED4[0x08-0x07];

	/* 0x08: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Run Mode */
#define TC_COUNT16_DBGCTRL_DBGRUN		0u

	/* 0x09 */
	uint8_t volatile RESERVED5[0x0A-0x09];

	/* 0x0A: Event Control */
	uint16_t volatile EVCTRL;
	/* Event Action */
#define TC_COUNT16_EVCTRL_EVACT_Lsb		0u
#define TC_COUNT16_EVCTRL_EVACT_Msb		2u
#define TC_COUNT16_EVCTRL_EVACT_OFF		0x0
#define TC_COUNT16_EVCTRL_EVACT_RETRIGGER	0x1
#define TC_COUNT16_EVCTRL_EVACT_COUNT		0x2
#define TC_COUNT16_EVCTRL_EVACT_START		0x3
#define TC_COUNT16_EVCTRL_EVACT_PPW		0x5
#define TC_COUNT16_EVCTRL_EVACT_PWP		0x6
	/* TC Inverted Event Input */
#define TC_COUNT16_EVCTRL_TCINV			4u
	/* TC Event Input */
#define TC_COUNT16_EVCTRL_TCEI			5u
	/* Overflow/Underflow Event Output Enable */
#define TC_COUNT16_EVCTRL_OVFEO			8u
	/* Match or Capture Channel 0 Event Output Enable */
#define TC_COUNT16_EVCTRL_MCEO0			12u
	/* Match or Capture Channel 1 Event Output Enable */
#define TC_COUNT16_EVCTRL_MCEO1			13u

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Overflow Interrupt Enable */
#define TC_COUNT16_INTENCLR_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT16_INTENCLR_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT16_INTENCLR_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT16_INTENCLR_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT16_INTENCLR_MC1			5u

	/* 0x0D: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Overflow Interrupt Enable */
#define TC_COUNT16_INTENSET_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT16_INTENSET_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT16_INTENSET_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT16_INTENSET_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT16_INTENSET_MC1			5u

	/* 0x0E: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Overflow */
#define TC_COUNT16_INTFLAG_OVF			0u
	/* Error */
#define TC_COUNT16_INTFLAG_ERR			1u
	/* Synchronization Ready */
#define TC_COUNT16_INTFLAG_SYNCRDY		3u
	/* Match or Capture Channel 0 */
#define TC_COUNT16_INTFLAG_MC0			4u
	/* Match or Capture Channel 1 */
#define TC_COUNT16_INTFLAG_MC1			5u

	/* 0x0F: Status */
	uint8_t volatile const STATUS;
	/* Stop */
#define TC_COUNT16_STATUS_STOP			3u
	/* Slave */
#define TC_COUNT16_STATUS_SLAVE			4u
	/* Synchronization Busy */
#define TC_COUNT16_STATUS_SYNCBUSY		7u

	/* 0x10: COUNT16 Counter Value */
	uint16_t volatile COUNT;
	/* Count Value */
#define TC_COUNT16_COUNT_COUNT_Lsb		0u
#define TC_COUNT16_COUNT_COUNT_Msb		15u

	/* 0x12 */
	uint8_t volatile RESERVED6[0x18-0x12];

	/* 0x18: COUNT16 Compare/Capture */
	uint16_t volatile CC[2];
	/* Compare/Capture Value */
#define TC_COUNT16_CC_CC_Lsb			0u
#define TC_COUNT16_CC_CC_Msb			15u

};


/* TC: Basic Timer Counter 1: 32-bit Counter Mode */
struct zmcu_tc_count32 {

	/* 0x00: Control A */
	uint16_t volatile CTRLA;
	/* Software Reset */
#define TC_COUNT32_CTRLA_SWRST			0u
	/* Enable */
#define TC_COUNT32_CTRLA_ENABLE			1u
	/* TC Mode */
#define TC_COUNT32_CTRLA_MODE_Lsb		2u
#define TC_COUNT32_CTRLA_MODE_Msb		3u
#define TC_COUNT32_CTRLA_MODE_COUNT16		0x0
#define TC_COUNT32_CTRLA_MODE_COUNT8		0x1
#define TC_COUNT32_CTRLA_MODE_COUNT32		0x2
	/* Waveform Generation Operation */
#define TC_COUNT32_CTRLA_WAVEGEN_Lsb		5u
#define TC_COUNT32_CTRLA_WAVEGEN_Msb		6u
#define TC_COUNT32_CTRLA_WAVEGEN_NFRQ		0x0
#define TC_COUNT32_CTRLA_WAVEGEN_MFRQ		0x1
#define TC_COUNT32_CTRLA_WAVEGEN_NPWM		0x2
#define TC_COUNT32_CTRLA_WAVEGEN_MPWM		0x3
	/* Prescaler */
#define TC_COUNT32_CTRLA_PRESCALER_Lsb		8u
#define TC_COUNT32_CTRLA_PRESCALER_Msb		10u
#define TC_COUNT32_CTRLA_PRESCALER_DIV1		0x0
#define TC_COUNT32_CTRLA_PRESCALER_DIV2		0x1
#define TC_COUNT32_CTRLA_PRESCALER_DIV4		0x2
#define TC_COUNT32_CTRLA_PRESCALER_DIV8		0x3
#define TC_COUNT32_CTRLA_PRESCALER_DIV16	0x4
#define TC_COUNT32_CTRLA_PRESCALER_DIV64	0x5
#define TC_COUNT32_CTRLA_PRESCALER_DIV256	0x6
#define TC_COUNT32_CTRLA_PRESCALER_DIV1024	0x7
	/* Run in Standby */
#define TC_COUNT32_CTRLA_RUNSTDBY		11u
	/* Prescaler and Counter Synchronization */
#define TC_COUNT32_CTRLA_PRESCSYNC_Lsb		12u
#define TC_COUNT32_CTRLA_PRESCSYNC_Msb		13u
#define TC_COUNT32_CTRLA_PRESCSYNC_GCLK		0x0
#define TC_COUNT32_CTRLA_PRESCSYNC_PRESC	0x1
#define TC_COUNT32_CTRLA_PRESCSYNC_RESYNC	0x2

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
	/* Address */
#define TC_COUNT32_READREQ_ADDR_Lsb		0u
#define TC_COUNT32_READREQ_ADDR_Msb		4u
	/* Read Continuously */
#define TC_COUNT32_READREQ_RCONT		14u
	/* Read Request */
#define TC_COUNT32_READREQ_RREQ			15u

	/* 0x04: Control B Clear */
	uint8_t volatile CTRLBCLR;
	/* Counter Direction */
#define TC_COUNT32_CTRLBCLR_DIR			0u
	/* One-Shot */
#define TC_COUNT32_CTRLBCLR_ONESHOT		2u
	/* Command */
#define TC_COUNT32_CTRLBCLR_CMD_Lsb		6u
#define TC_COUNT32_CTRLBCLR_CMD_Msb		7u
#define TC_COUNT32_CTRLBCLR_CMD_NONE		0x0
#define TC_COUNT32_CTRLBCLR_CMD_RETRIGGER	0x1
#define TC_COUNT32_CTRLBCLR_CMD_STOP		0x2

	/* 0x05: Control B Set */
	uint8_t volatile CTRLBSET;
	/* Counter Direction */
#define TC_COUNT32_CTRLBSET_DIR			0u
	/* One-Shot */
#define TC_COUNT32_CTRLBSET_ONESHOT		2u
	/* Command */
#define TC_COUNT32_CTRLBSET_CMD_Lsb		6u
#define TC_COUNT32_CTRLBSET_CMD_Msb		7u
#define TC_COUNT32_CTRLBSET_CMD_NONE		0x0
#define TC_COUNT32_CTRLBSET_CMD_RETRIGGER	0x1
#define TC_COUNT32_CTRLBSET_CMD_STOP		0x2

	/* 0x06: Control C */
	uint8_t volatile CTRLC;
	/* Output Waveform 0 Invert Enable */
#define TC_COUNT32_CTRLC_INVEN0			0u
	/* Output Waveform 1 Invert Enable */
#define TC_COUNT32_CTRLC_INVEN1			1u
	/* Capture Channel 0 Enable */
#define TC_COUNT32_CTRLC_CPTEN0			4u
	/* Capture Channel 1 Enable */
#define TC_COUNT32_CTRLC_CPTEN1			5u

	/* 0x07 */
	uint8_t volatile RESERVED7[0x08-0x07];

	/* 0x08: Debug Control */
	uint8_t volatile DBGCTRL;
	/* Debug Run Mode */
#define TC_COUNT32_DBGCTRL_DBGRUN		0u

	/* 0x09 */
	uint8_t volatile RESERVED8[0x0A-0x09];

	/* 0x0A: Event Control */
	uint16_t volatile EVCTRL;
	/* Event Action */
#define TC_COUNT32_EVCTRL_EVACT_Lsb		0u
#define TC_COUNT32_EVCTRL_EVACT_Msb		2u
#define TC_COUNT32_EVCTRL_EVACT_OFF		0x0
#define TC_COUNT32_EVCTRL_EVACT_RETRIGGER	0x1
#define TC_COUNT32_EVCTRL_EVACT_COUNT		0x2
#define TC_COUNT32_EVCTRL_EVACT_START		0x3
#define TC_COUNT32_EVCTRL_EVACT_PPW		0x5
#define TC_COUNT32_EVCTRL_EVACT_PWP		0x6
	/* TC Inverted Event Input */
#define TC_COUNT32_EVCTRL_TCINV			4u
	/* TC Event Input */
#define TC_COUNT32_EVCTRL_TCEI			5u
	/* Overflow/Underflow Event Output Enable */
#define TC_COUNT32_EVCTRL_OVFEO			8u
	/* Match or Capture Channel 0 Event Output Enable */
#define TC_COUNT32_EVCTRL_MCEO0			12u
	/* Match or Capture Channel 1 Event Output Enable */
#define TC_COUNT32_EVCTRL_MCEO1			13u

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Overflow Interrupt Enable */
#define TC_COUNT32_INTENCLR_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT32_INTENCLR_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT32_INTENCLR_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT32_INTENCLR_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT32_INTENCLR_MC1			5u

	/* 0x0D: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Overflow Interrupt Enable */
#define TC_COUNT32_INTENSET_OVF			0u
	/* Error Interrupt Enable */
#define TC_COUNT32_INTENSET_ERR			1u
	/* Synchronization Ready Interrupt Enable */
#define TC_COUNT32_INTENSET_SYNCRDY		3u
	/* Match or Capture Channel 0 Interrupt Enable */
#define TC_COUNT32_INTENSET_MC0			4u
	/* Match or Capture Channel 1 Interrupt Enable */
#define TC_COUNT32_INTENSET_MC1			5u

	/* 0x0E: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Overflow */
#define TC_COUNT32_INTFLAG_OVF			0u
	/* Error */
#define TC_COUNT32_INTFLAG_ERR			1u
	/* Synchronization Ready */
#define TC_COUNT32_INTFLAG_SYNCRDY		3u
	/* Match or Capture Channel 0 */
#define TC_COUNT32_INTFLAG_MC0			4u
	/* Match or Capture Channel 1 */
#define TC_COUNT32_INTFLAG_MC1			5u

	/* 0x0F: Status */
	uint8_t volatile const STATUS;
	/* Stop */
#define TC_COUNT32_STATUS_STOP			3u
	/* Slave */
#define TC_COUNT32_STATUS_SLAVE			4u
	/* Synchronization Busy */
#define TC_COUNT32_STATUS_SYNCBUSY		7u

	/* 0x10: COUNT32 Counter Value */
	uint32_t volatile COUNT;
	/* Count Value */
#define TC_COUNT32_COUNT_COUNT_Lsb		0u
#define TC_COUNT32_COUNT_COUNT_Msb		31u

	/* 0x14 */
	uint8_t volatile RESERVED9[0x18-0x14];

	/* 0x18: COUNT32 Compare/Capture */
	uint32_t volatile CC[2];
	/* Compare/Capture Value */
#define TC_COUNT32_CC_CC_Lsb			0u
#define TC_COUNT32_CC_CC_Msb			31u

};


#define WDT ((struct zmcu_wdt *)0x40001000)

/* Watchdog Timer */
struct zmcu_wdt {

	/* 0x00: Control */
	uint8_t volatile CTRL;
	/* Enable */
#define WDT_CTRL_ENABLE				1u
	/* Watchdog Timer Window Mode Enable */
#define WDT_CTRL_WEN				2u
	/* Always-On */
#define WDT_CTRL_ALWAYSON			7u

	/* 0x01: Configuration */
	uint8_t volatile CONFIG;
	/* Time-Out Period */
#define WDT_CONFIG_PER_Lsb			0u
#define WDT_CONFIG_PER_Msb			3u
#define WDT_CONFIG_PER_8			0x0
#define WDT_CONFIG_PER_16			0x1
#define WDT_CONFIG_PER_32			0x2
#define WDT_CONFIG_PER_64			0x3
#define WDT_CONFIG_PER_128			0x4
#define WDT_CONFIG_PER_256			0x5
#define WDT_CONFIG_PER_512			0x6
#define WDT_CONFIG_PER_1K			0x7
#define WDT_CONFIG_PER_2K			0x8
#define WDT_CONFIG_PER_4K			0x9
#define WDT_CONFIG_PER_8K			0xa
#define WDT_CONFIG_PER_16K			0xb
	/* Window Mode Time-Out Period */
#define WDT_CONFIG_WINDOW_Lsb			4u
#define WDT_CONFIG_WINDOW_Msb			7u
#define WDT_CONFIG_WINDOW_8			0x0
#define WDT_CONFIG_WINDOW_16			0x1
#define WDT_CONFIG_WINDOW_32			0x2
#define WDT_CONFIG_WINDOW_64			0x3
#define WDT_CONFIG_WINDOW_128			0x4
#define WDT_CONFIG_WINDOW_256			0x5
#define WDT_CONFIG_WINDOW_512			0x6
#define WDT_CONFIG_WINDOW_1K			0x7
#define WDT_CONFIG_WINDOW_2K			0x8
#define WDT_CONFIG_WINDOW_4K			0x9
#define WDT_CONFIG_WINDOW_8K			0xa
#define WDT_CONFIG_WINDOW_16K			0xb

	/* 0x02: Early Warning Interrupt Control */
	uint8_t volatile EWCTRL;
	/* Early Warning Interrupt Time Offset */
#define WDT_EWCTRL_EWOFFSET_Lsb			0u
#define WDT_EWCTRL_EWOFFSET_Msb			3u
#define WDT_EWCTRL_EWOFFSET_8			0x0
#define WDT_EWCTRL_EWOFFSET_16			0x1
#define WDT_EWCTRL_EWOFFSET_32			0x2
#define WDT_EWCTRL_EWOFFSET_64			0x3
#define WDT_EWCTRL_EWOFFSET_128			0x4
#define WDT_EWCTRL_EWOFFSET_256			0x5
#define WDT_EWCTRL_EWOFFSET_512			0x6
#define WDT_EWCTRL_EWOFFSET_1K			0x7
#define WDT_EWCTRL_EWOFFSET_2K			0x8
#define WDT_EWCTRL_EWOFFSET_4K			0x9
#define WDT_EWCTRL_EWOFFSET_8K			0xa
#define WDT_EWCTRL_EWOFFSET_16K			0xb

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
	/* Early Warning Interrupt Enable */
#define WDT_INTENCLR_EW				0u

	/* 0x05: Interrupt Enable Set */
	uint8_t volatile INTENSET;
	/* Early Warning Interrupt Enable */
#define WDT_INTENSET_EW				0u

	/* 0x06: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
	/* Early Warning */
#define WDT_INTFLAG_EW				0u

	/* 0x07: Status */
	uint8_t volatile const STATUS;
	/* Synchronization Busy */
#define WDT_STATUS_SYNCBUSY			7u

	/* 0x08: Clear */
	uint8_t volatile CLEAR;
	/* Watchdog Clear */
#define WDT_CLEAR_CLEAR_Lsb			0u
#define WDT_CLEAR_CLEAR_Msb			7u

};
