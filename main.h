#define BITMASK32(o)		(o == 31 ? 0xFFFFFFFF : (1u << (o + 1)) - 1)
#define BITMASK(fld)		(BITMASK32(fld##_msb) - BITMASK32(fld##_lsb))
#define BITS(fld, val)		(fld##_##val << fld##_lsb)
#define BIT(fld)		(1u << fld)
#define BITREAD(reg, fld)	((reg & BITMASK32(fld##_msb)) >> fld##_lsb)
#define BITWRITE(reg, fld, val)	(reg = (reg & ~BITMASK(fld)) | BITS(fld, val))

/* halt the execution */
void __stop_program(void);
