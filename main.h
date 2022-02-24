#define BITMASK32(o)		((o) == 31 ? 0xFFFFFFFF : (1u << (o) + 1) - 1)
#define BITMASK(fld)		(BITMASK32(fld##_Msb) - BITMASK32(fld##_Lsb))
#define BIT(fld, val)		(fld##_##val << fld##_Lsb)
#define BITREAD(dev, reg, fld)	(dev->reg >> dev##_##reg##_##fld##_Lsb)
#define BITWRITE(dev, reg, fld, val) ((dev->reg & ~BITMASK(dev##_##reg##_##fld)) \
				 | BITVAL(dev##_##reg##_##fld, val))

/* halt the execution */
void __stop_program(void);
