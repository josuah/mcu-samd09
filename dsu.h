#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define DSU ((struct zmcu_dsu *)0x41002000)

struct zmcu_dsu {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define DSU_CTRL_SMSA				(1u << 7)
#define DSU_CTRL_ARR				(1u << 6)
#define DSU_CTRL_CE				(1u << 4)
#define DSU_CTRL_MBIST				(1u << 3)
#define DSU_CTRL_CRC				(1u << 2)
#define DSU_CTRL_SWRST				(1u << 0)

	/* 0x01: Status A */
	uint8_t volatile STATUSA;
#define DSU_STATUSA_PERR			(1u << 4)
#define DSU_STATUSA_FAIL			(1u << 3)
#define DSU_STATUSA_BERR			(1u << 2)
#define DSU_STATUSA_CRSTEXT			(1u << 1)
#define DSU_STATUSA_DONE			(1u << 0)

	/* 0x02: Status B */
	uint8_t volatile STATUSB;
#define DSU_STATUSB_HPE				(1u << 4)
#define DSU_STATUSB_DCCDx(x)			((x) << 2)
#define DSU_STATUSB_DCCDx_MASK			DSU_STATUSB_DCCDx(B00000011)
#define DSU_STATUSB_DBGPRES			(1u << 1)
#define DSU_STATUSB_PROT			(1u << 0)

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Address */
	uint32_t volatile ADDR;
#define DSU_ADDR_ADDR(x)			((x) << 2)
#define DSU_ADDR_AMOD(x)			((x) << 0)
#define DSU_ADDR_AMOD_MASK			DSU_ADDR_AMOD(B00000011)

	/* 0x08: Length */
	uint32_t volatile LENGTH;
#define DSU_LENGTH_LENGTH(x)			((x) << 2)

	/* 0x0C: Data */
	uint32_t volatile DATA;
#define DSU_DATA_DATA(x)			((x) << 0)

	/* 0x10: Debug Communication Channel n */
	uint32_t volatile DCCn;
#define DSU_DCCn_DATA(x)			((x) << 0)

	/* 0x14 */
	uint8_t volatile RESERVED1[0x18-0x14];

	/* 0x18: Device Identification */
	uint32_t volatile DID;
#define DSU_DID_PROCESSOR(x)			((x) << 28)
#define DSU_DID_PROCESSOR_MASK			DSU_DID_PROCESSOR(B00001111)
#define DSU_DID_FAMILY(x)			((x) << 23)
#define DSU_DID_FAMILY_MASK			DSU_DID_FAMILY(B00011111)
#define DSU_DID_SERIES(x)			((x) << 16)
#define DSU_DID_SERIES_MASK			DSU_DID_SERIES(B00111111)
#define DSU_DID_DIE(x)				((x) << 12)
#define DSU_DID_DIE_MASK			DSU_DID_DIE(B00001111)
#define DSU_DID_REVISION(x)			((x) << 8)
#define DSU_DID_REVISION_MASK			DSU_DID_REVISION(B00001111)
#define DSU_DID_DEVSEL(x)			((x) << 0)
#define DSU_DID_DEVSEL_MASK			DSU_DID_DEVSEL(B11111111)

	/* 0x1C */
	uint8_t volatile RESERVED2[0xF0-0x1C];

	/* 0xF0: Device Configuration */
	uint32_t volatile DCFGn;
#define DSU_DCFGn_DCFG(x)			((x) << 0)

	/* 0xF4 */
	uint8_t volatile RESERVED3[0x1000-0xF4];

	/* 0x1000: Coresight ROM Table Entry n */
	uint32_t volatile ENTRYn;
#define DSU_ENTRYn_ADDOFF(x)			((x) << 12)
#define DSU_ENTRYn_FMT				(1u << 1)
#define DSU_ENTRYn_EPRES			(1u << 0)

	/* 0x1004 */
	uint8_t volatile RESERVED4[0x1008-0x1004];

	/* 0x1008: Coresight ROM Table End */
	uint32_t volatile END;
#define DSU_END_END(x)				((x) << 0)

	/* 0x100C */
	uint8_t volatile RESERVED5[0x1FCC-0x100C];

	/* 0x1FCC: Coresight ROM Table Memory Type */
	uint32_t volatile MEMTYPE;
#define DSU_MEMTYPE_SMEMP			(1u << 0)

	/* 0x1FD0: Peripheral Identification 4 */
	uint32_t volatile PID4;
#define DSU_PID4_FKBC(x)			((x) << 4)
#define DSU_PID4_FKBC_MASK			DSU_PID4_FKBC(B00001111)
#define DSU_PID4_JEPCC(x)			((x) << 0)
#define DSU_PID4_JEPCC_MASK			DSU_PID4_JEPCC(B00001111)

	/* 0x1FD4: Peripheral Identification 5 */
	uint32_t volatile PID5;

	/* 0x1FD8: Peripheral Identification 6 */
	uint32_t volatile PID6;

	/* 0x1FDC: Peripheral Identification 7 */
	uint32_t volatile PID7;

	/* 0x1FE0: Peripheral Identification 0 */
	uint32_t volatile PID0;
#define DSU_PID0_PARTNBL(x)			((x) << 0)
#define DSU_PID0_PARTNBL_MASK			DSU_PID0_PARTNBL(B11111111)

	/* 0x1FE4: Peripheral Identification 1 */
	uint32_t volatile PID1;
#define DSU_PID1_JEPIDCL(x)			((x) << 4)
#define DSU_PID1_JEPIDCL_MASK			DSU_PID1_JEPIDCL(B00001111)
#define DSU_PID1_PARTNBH(x)			((x) << 0)
#define DSU_PID1_PARTNBH_MASK			DSU_PID1_PARTNBH(B00001111)

	/* 0x1FE8: Peripheral Identification 2 */
	uint32_t volatile PID2;
#define DSU_PID2_REVISION(x)			((x) << 4)
#define DSU_PID2_REVISION_MASK			DSU_PID2_REVISION(B00001111)
#define DSU_PID2_JEPU				(1u << 3)
#define DSU_PID2_JEPIDCH(x)			((x) << 0)
#define DSU_PID2_JEPIDCH_MASK			DSU_PID2_JEPIDCH(B00000111)

	/* 0x1FEC: Peripheral Identification 3 */
	uint32_t volatile PID3;
#define DSU_PID3_REVAND(x)			((x) << 4)
#define DSU_PID3_REVAND_MASK			DSU_PID3_REVAND(B00001111)
#define DSU_PID3_CUSMOD(x)			((x) << 0)
#define DSU_PID3_CUSMOD_MASK			DSU_PID3_CUSMOD(B00001111)

	/* 0x1FF0: Component Identification 0 */
	uint32_t volatile CID0;
#define DSU_CID0_PREAMBLEB0(x)			((x) << 0)
#define DSU_CID0_PREAMBLEB0_MASK		DSU_CID0_PREAMBLEB0(B11111111)

	/* 0x1FF4: Component Identification 1 */
	uint32_t volatile CID1;
#define DSU_CID1_CCLASS(x)			((x) << 4)
#define DSU_CID1_CCLASS_MASK			DSU_CID1_CCLASS(B00001111)
#define DSU_CID1_PREAMBLE(x)			((x) << 0)
#define DSU_CID1_PREAMBLE_MASK			DSU_CID1_PREAMBLE(B00001111)

	/* 0x1FF8: Component Identification 2 */
	uint32_t volatile CID2;
#define DSU_CID2_PREAMBLEB2(x)			((x) << 0)
#define DSU_CID2_PREAMBLEB2_MASK		DSU_CID2_PREAMBLEB2(B11111111)

	/* 0x1FFC: Component Identification 3 */
	uint32_t volatile CID3;
#define DSU_CID3_PREAMBLEB3(x)			((x) << 0)
#define DSU_CID3_PREAMBLEB3_MASK		DSU_CID3_PREAMBLEB3(B11111111)

};

