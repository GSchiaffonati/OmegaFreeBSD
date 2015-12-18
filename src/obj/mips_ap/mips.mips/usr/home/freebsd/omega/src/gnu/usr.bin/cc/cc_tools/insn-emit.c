/* Generated automatically by the program `genemit'
from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"
#include "expr.h"
#include "optabs.h"
#include "real.h"
#include "flags.h"
#include "output.h"
#include "insn-config.h"
#include "hard-reg-set.h"
#include "recog.h"
#include "resource.h"
#include "reload.h"
#include "toplev.h"
#include "tm-constrs.h"
#include "ggc.h"

#include "basic-block.h"

#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:605 */
rtx
gen_trap (void)
{
  return gen_rtx_TRAP_IF (VOIDmode,
	const1_rtx,
	const0_rtx);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
rtx
gen_addsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
rtx
gen_adddf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
rtx
gen_addv2sf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (V2SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
rtx
gen_subsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
rtx
gen_subdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (DFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
rtx
gen_subv2sf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (V2SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:899 */
rtx
gen_subsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (SImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:899 */
rtx
gen_subdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (DImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:956 */
rtx
gen_mulv2sf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (V2SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1027 */
rtx
gen_mulsi3_mult3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1052 */
rtx
gen_muldi3_mult3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1089 */
rtx
gen_mulsi3_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1089 */
rtx
gen_muldi3_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1099 */
rtx
gen_mulsi3_r4000 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1099 */
rtx
gen_muldi3_r4000 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1509 */
rtx
gen_mulsidi3_32bit_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1509 */
rtx
gen_umulsidi3_32bit_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1518 */
rtx
gen_mulsidi3_32bit_r4000 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1518 */
rtx
gen_umulsidi3_32bit_r4000 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1641 */
rtx
gen_smulsi3_highpart_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1641 */
rtx
gen_umulsi3_highpart_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1654 */
rtx
gen_smulsi3_highpart_mulhi_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1654 */
rtx
gen_umulsi3_highpart_mulhi_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1692 */
rtx
gen_smuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1692 */
rtx
gen_umuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_ZERO_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)]))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1710 */
rtx
gen_madsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	gen_rtx_MULT (SImode,
	operand1,
	operand2),
	operand0)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1884 */
rtx
gen_divmodsi4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (SImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_MOD (SImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1884 */
rtx
gen_divmoddi4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (DImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_MOD (DImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1896 */
rtx
gen_udivmodsi4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UDIV (SImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_UMOD (SImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1896 */
rtx
gen_udivmoddi4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UDIV (DImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_UMOD (DImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
rtx
gen_sqrtsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SQRT (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
rtx
gen_sqrtdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SQRT (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
rtx
gen_sqrtv2sf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SQRT (V2SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
rtx
gen_abssf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ABS (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
rtx
gen_absdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ABS (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
rtx
gen_absv2sf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ABS (V2SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2001 */
rtx
gen_clzsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CLZ (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2001 */
rtx
gen_clzdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CLZ (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2016 */
rtx
gen_negsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2029 */
rtx
gen_negdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
rtx
gen_negsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
rtx
gen_negdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
rtx
gen_negv2sf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NEG (V2SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2049 */
rtx
gen_one_cmplsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NOT (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2049 */
rtx
gen_one_cmpldi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NOT (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2187 */
rtx
gen_truncdfsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT_TRUNCATE (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2209 */
rtx
gen_truncdisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2220 */
rtx
gen_truncdihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (HImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2231 */
rtx
gen_truncdiqi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (QImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2336 */
rtx
gen_zero_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2470 */
rtx
gen_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2534 */
rtx
gen_extendqihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (HImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2546 */
rtx
gen_extendsfdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT_EXTEND (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2574 */
rtx
gen_fix_truncdfsi2_insn (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2584 */
rtx
gen_fix_truncdfsi2_macro (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DFmode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2612 */
rtx
gen_fix_truncsfsi2_insn (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2622 */
rtx
gen_fix_truncsfsi2_macro (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SFmode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2639 */
rtx
gen_fix_truncdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2650 */
rtx
gen_fix_truncsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2661 */
rtx
gen_floatsidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2672 */
rtx
gen_floatdidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2683 */
rtx
gen_floatsisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2694 */
rtx
gen_floatdisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2924 */
rtx
gen_extzvsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTRACT (SImode,
	operand1,
	operand2,
	operand3));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2924 */
rtx
gen_extzvdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTRACT (DImode,
	operand1,
	operand2,
	operand3));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2960 */
rtx
gen_insvsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_ZERO_EXTRACT (SImode,
	operand0,
	operand1,
	operand2),
	operand3);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2960 */
rtx
gen_insvdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_ZERO_EXTRACT (DImode,
	operand0,
	operand1,
	operand2),
	operand3);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2982 */
rtx
gen_mov_lwl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	18));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2982 */
rtx
gen_mov_ldl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	18));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2992 */
rtx
gen_mov_lwr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	19));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2992 */
rtx
gen_mov_ldr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	19));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3003 */
rtx
gen_mov_swl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (2,
		operand1,
		operand2),
	20));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3003 */
rtx
gen_mov_sdl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (2,
		operand1,
		operand2),
	20));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3013 */
rtx
gen_mov_swr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand0),
	21));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3013 */
rtx
gen_mov_sdr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand0),
	21));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3179 */
rtx
gen_load_gotsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	24));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3179 */
rtx
gen_load_gotdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	24));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3483 */
rtx
gen_movcc (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	operand1);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3895 */
rtx
gen_movv2sf_hardfloat_64bit (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	operand1);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3954 */
rtx
gen_load_df_low (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (1,
		operand1),
	0));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3968 */
rtx
gen_load_df_high (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3983 */
rtx
gen_store_df_high (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3998 */
rtx
gen_loadgp (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (2,
		operand0,
		operand1),
	22);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4016 */
rtx
gen_loadgp_noshared (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	22);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4032 */
rtx
gen_loadgp_blockage (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		gen_rtx_REG (DImode,
	28)),
	4);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4043 */
rtx
gen_cprestore (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	5);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4259 */
rtx
gen_rotrsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ROTATERT (SImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4259 */
rtx
gen_rotrdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ROTATERT (DImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunordered_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNORDERED (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_suneq_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNEQ (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunlt_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNLT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunle_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNLE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_seq_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_EQ (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_slt_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sle_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunordered_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNORDERED (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_suneq_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNEQ (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunlt_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNLT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sunle_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNLE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_seq_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_EQ (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_slt_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
rtx
gen_sle_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sge_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sgt_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sunge_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNGE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sungt_sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNGT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sge_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sgt_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sunge_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNGE (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
rtx
gen_sungt_df (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNGT (CCmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4770 */
rtx
gen_jump (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_LABEL_REF (VOIDmode,
	operand0));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4825 */
rtx
gen_indirect_jumpsi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4825 */
rtx
gen_indirect_jumpdi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4854 */
rtx
gen_tablejumpsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4854 */
rtx
gen_tablejumpdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4932 */
rtx
gen_blockage (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	4);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4959 */
rtx
gen_return (void)
{
  return gen_rtx_RETURN (VOIDmode);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4968 */
rtx
gen_return_internal (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_RETURN (VOIDmode),
		gen_rtx_USE (VOIDmode,
	operand0)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4996 */
rtx
gen_eh_set_lr_si (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	7),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5002 */
rtx
gen_eh_set_lr_di (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	7),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5018 */
rtx
gen_exception_receiver (void)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (SImode,
	28),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (1,
		const0_rtx),
	6));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5053 */
rtx
gen_load_callsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (SImode,
	79)),
	23));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5053 */
rtx
gen_load_calldi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (DImode,
	79)),
	23));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5088 */
rtx
gen_sibcall_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5107 */
rtx
gen_sibcall_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5115 */
rtx
gen_sibcall_value_multiple_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5174 */
rtx
gen_call_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1),
		gen_hard_reg_clobber (SImode, 31)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5191 */
rtx
gen_call_split (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1),
		gen_hard_reg_clobber (SImode, 31),
		gen_hard_reg_clobber (SImode, 28)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5213 */
rtx
gen_call_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 31)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5232 */
rtx
gen_call_value_split (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 31),
		gen_hard_reg_clobber (SImode, 28)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5243 */
rtx
gen_call_value_multiple_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 31)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5265 */
rtx
gen_call_value_multiple_split (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode, gen_rtvec (4,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 31),
		gen_hard_reg_clobber (SImode, 28)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5310 */
rtx
gen_prefetch (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PREFETCH (VOIDmode,
	operand0,
	operand1,
	operand2);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5333 */
rtx
gen_nop (void)
{
  return const0_rtx;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5341 */
rtx
gen_hazard_nop (void)
{
  return const1_rtx;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5418 */
rtx
gen_consttable_int (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (2,
		operand0,
		operand1),
	8);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5430 */
rtx
gen_consttable_float (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	9);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5446 */
rtx
gen_align (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	14);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5468 */
rtx
gen_tls_get_tp_si (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		const0_rtx),
	28));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5468 */
rtx
gen_tls_get_tp_di (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		const0_rtx),
	28));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:36 */
rtx
gen_mips_cond_move_tf_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	200));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:70 */
rtx
gen_mips_pul_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_MERGE (V2SFmode,
	operand1,
	operand2,
	const_int_rtx[MAX_SAVED_CONST_INT + (2)]));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:82 */
rtx
gen_mips_puu_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_MERGE (V2SFmode,
	operand1,
	gen_rtx_VEC_SELECT (V2SFmode,
	operand2,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		const1_rtx,
		const0_rtx))),
	const_int_rtx[MAX_SAVED_CONST_INT + (2)]));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:96 */
rtx
gen_mips_pll_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_MERGE (V2SFmode,
	gen_rtx_VEC_SELECT (V2SFmode,
	operand1,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		const1_rtx,
		const0_rtx))),
	operand2,
	const_int_rtx[MAX_SAVED_CONST_INT + (2)]));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:110 */
rtx
gen_mips_plu_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_MERGE (V2SFmode,
	gen_rtx_VEC_SELECT (V2SFmode,
	operand1,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		const1_rtx,
		const0_rtx))),
	gen_rtx_VEC_SELECT (V2SFmode,
	operand2,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		const1_rtx,
		const0_rtx))),
	const_int_rtx[MAX_SAVED_CONST_INT + (2)]));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:137 */
rtx
gen_vec_initv2sf_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_CONCAT (V2SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:156 */
rtx
gen_vec_extractv2sf (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_SELECT (SFmode,
	operand1,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (1,
		operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:226 */
rtx
gen_mips_alnv_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	202));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:238 */
rtx
gen_mips_addr_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	204));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:249 */
rtx
gen_mips_cvt_pw_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (1,
		operand1),
	205));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:259 */
rtx
gen_mips_cvt_ps_pw (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (1,
		operand1),
	206));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:269 */
rtx
gen_mips_mulr_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	207));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:308 */
rtx
gen_mips_cabs_cond_s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	203));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:308 */
rtx
gen_mips_cabs_cond_d (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	203));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:324 */
rtx
gen_mips_c_cond_4s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV4mode,
	gen_rtvec (5,
		operand1,
		operand2,
		operand3,
		operand4,
		operand5),
	201));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:353 */
rtx
gen_mips_cabs_cond_4s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV4mode,
	gen_rtvec (5,
		operand1,
		operand2,
		operand3,
		operand4,
		operand5),
	203));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:387 */
rtx
gen_mips_c_cond_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	201));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:398 */
rtx
gen_mips_cabs_cond_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	203));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_sunordered_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNORDERED (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_suneq_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNEQ (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_sunlt_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNLT (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_sunle_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNLE (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_seq_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_EQ (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_slt_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_LT (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
rtx
gen_sle_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_LE (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
rtx
gen_sge_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_GE (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
rtx
gen_sgt_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_GT (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
rtx
gen_sunge_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNGE (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
rtx
gen_sungt_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		gen_rtx_UNGT (VOIDmode,
	operand1,
	operand2)),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:441 */
rtx
gen_bc1any4t (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_NE (VOIDmode,
	operand0,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:453 */
rtx
gen_bc1any4f (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_NE (VOIDmode,
	operand0,
	constm1_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:465 */
rtx
gen_bc1any2t (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_NE (VOIDmode,
	operand0,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:477 */
rtx
gen_bc1any2f (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_NE (VOIDmode,
	operand0,
	constm1_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
rtx
gen_mips_rsqrt1_s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SFmode,
	gen_rtvec (1,
		operand1),
	209));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
rtx
gen_mips_rsqrt1_d (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (1,
		operand1),
	209));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
rtx
gen_mips_rsqrt1_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (1,
		operand1),
	209));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
rtx
gen_mips_rsqrt2_s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	210));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
rtx
gen_mips_rsqrt2_d (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	210));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
rtx
gen_mips_rsqrt2_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	210));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
rtx
gen_mips_recip1_s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SFmode,
	gen_rtvec (1,
		operand1),
	211));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
rtx
gen_mips_recip1_d (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (1,
		operand1),
	211));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
rtx
gen_mips_recip1_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (1,
		operand1),
	211));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
rtx
gen_mips_recip2_s (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	212));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
rtx
gen_mips_recip2_d (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	212));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
rtx
gen_mips_recip2_ps (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	212));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1 */
rtx
gen_addv2hi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (V2HImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	300))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1 */
rtx
gen_addv4qi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (V4QImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	300))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
rtx
gen_mips_addq_s_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	301)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	301))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
rtx
gen_mips_addq_s_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	301)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	301))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
rtx
gen_mips_addu_s_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	301)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	301))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:64 */
rtx
gen_subv2hi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (V2HImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	302))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:64 */
rtx
gen_subv4qi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (V4QImode,
	operand1,
	operand2)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	302))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
rtx
gen_mips_subq_s_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	303)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	303))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
rtx
gen_mips_subq_s_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	303)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	303))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
rtx
gen_mips_subu_s_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	303)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	303))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:90 */
rtx
gen_mips_addsc (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	304)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	184),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	304))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:104 */
rtx
gen_mips_addwc (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	184)),
	305)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	305))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:119 */
rtx
gen_mips_modsub (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	306));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:130 */
rtx
gen_mips_raddu_w_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	307));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:140 */
rtx
gen_mips_absq_s_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	308)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (1,
		operand1),
	308))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:140 */
rtx
gen_mips_absq_s_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	308)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (1,
		operand1),
	308))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:153 */
rtx
gen_mips_precrq_qb_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	309));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:163 */
rtx
gen_mips_precrq_ph_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	310));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:173 */
rtx
gen_mips_precrq_rs_ph_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	311)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	311))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:188 */
rtx
gen_mips_precrqu_s_qb_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	312)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	312))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:203 */
rtx
gen_mips_preceq_w_phl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	313));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:212 */
rtx
gen_mips_preceq_w_phr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	314));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:222 */
rtx
gen_mips_precequ_ph_qbl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	315));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:231 */
rtx
gen_mips_precequ_ph_qbr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	316));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:240 */
rtx
gen_mips_precequ_ph_qbla (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	317));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:249 */
rtx
gen_mips_precequ_ph_qbra (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	318));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:259 */
rtx
gen_mips_preceu_ph_qbl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	319));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:268 */
rtx
gen_mips_preceu_ph_qbr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	320));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:277 */
rtx
gen_mips_preceu_ph_qbla (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	321));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:286 */
rtx
gen_mips_preceu_ph_qbra (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	322));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:297 */
rtx
gen_mips_shll_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	323)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	323))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:297 */
rtx
gen_mips_shll_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	323)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	323))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:319 */
rtx
gen_mips_shll_s_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	324)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	324))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:319 */
rtx
gen_mips_shll_s_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	324)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	324))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:342 */
rtx
gen_mips_shrl_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (2,
		operand1,
		operand2),
	325));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:361 */
rtx
gen_mips_shra_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	326));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:379 */
rtx
gen_mips_shra_r_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	327));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:379 */
rtx
gen_mips_shra_r_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	327));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:400 */
rtx
gen_mips_muleu_s_ph_qbl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	328)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	328)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:414 */
rtx
gen_mips_muleu_s_ph_qbr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	329)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	329)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:429 */
rtx
gen_mips_mulq_rs_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	330)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	330)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:444 */
rtx
gen_mips_muleq_s_w_phl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	331)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	331)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:458 */
rtx
gen_mips_muleq_s_w_phr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	332)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	332)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:473 */
rtx
gen_mips_dpau_h_qbl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	333));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:484 */
rtx
gen_mips_dpau_h_qbr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	334));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:496 */
rtx
gen_mips_dpsu_h_qbl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	335));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:507 */
rtx
gen_mips_dpsu_h_qbr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	336));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:519 */
rtx
gen_mips_dpaq_s_w_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	337)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	337))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:535 */
rtx
gen_mips_dpsq_s_w_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	338)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	338))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:551 */
rtx
gen_mips_mulsaq_s_w_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	339)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	339))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:567 */
rtx
gen_mips_dpaq_sa_l_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	340)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	340))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:583 */
rtx
gen_mips_dpsq_sa_l_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	341)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	341))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:599 */
rtx
gen_mips_maq_s_w_phl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	342)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	342))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:614 */
rtx
gen_mips_maq_s_w_phr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	343)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	343))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:630 */
rtx
gen_mips_maq_sa_w_phl (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	344)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	344))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:645 */
rtx
gen_mips_maq_sa_w_phr (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	345)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	345))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:662 */
rtx
gen_mips_bitrev (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	346));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:672 */
rtx
gen_mips_insv (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (4,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	183),
		gen_rtx_REG (CCDSPmode,
	182)),
	347));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:685 */
rtx
gen_mips_repl_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (1,
		operand1),
	348));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:702 */
rtx
gen_mips_repl_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (1,
		operand1),
	349));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:715 */
rtx
gen_mips_cmp_eq_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	350));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:715 */
rtx
gen_mips_cmpu_eq_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	350));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:726 */
rtx
gen_mips_cmp_lt_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	351));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:726 */
rtx
gen_mips_cmpu_lt_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	351));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:737 */
rtx
gen_mips_cmp_le_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	352));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:737 */
rtx
gen_mips_cmpu_le_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand0,
		operand1,
		gen_rtx_REG (CCDSPmode,
	186)),
	352));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:748 */
rtx
gen_mips_cmpgu_eq_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	353));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:758 */
rtx
gen_mips_cmpgu_lt_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	354));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:768 */
rtx
gen_mips_cmpgu_le_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	355));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:779 */
rtx
gen_mips_pick_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	186)),
	356));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:779 */
rtx
gen_mips_pick_qb (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V4QImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	186)),
	356));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:791 */
rtx
gen_mips_packrl_ph (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2HImode,
	gen_rtvec (2,
		operand1,
		operand2),
	357));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:803 */
rtx
gen_mips_extr_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	358)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	358))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:824 */
rtx
gen_mips_extr_r_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	359)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	359))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:845 */
rtx
gen_mips_extr_rs_w (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	360)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	360))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:867 */
rtx
gen_mips_extr_s_h (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	361)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	361))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:889 */
rtx
gen_mips_extp (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	182)),
	362)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	187),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	362))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:911 */
rtx
gen_mips_extpdp (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	182)),
	363)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	182),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	182)),
	363)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	187),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand1,
		operand2),
	363))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:937 */
rtx
gen_mips_shilo (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	364));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:956 */
rtx
gen_mips_mthlip (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	182)),
	365)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	182),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (3,
		operand1,
		operand2,
		gen_rtx_REG (CCDSPmode,
	182)),
	365))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:972 */
rtx
gen_mips_wrdsp (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (6,
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	182),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	183),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	184),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	185),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	186),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366)),
		gen_rtx_SET (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	187),
	gen_rtx_UNSPEC (CCDSPmode,
	gen_rtvec (2,
		operand0,
		operand1),
	366))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:994 */
rtx
gen_mips_rddsp (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (7,
		operand1,
		gen_rtx_REG (CCDSPmode,
	182),
		gen_rtx_REG (CCDSPmode,
	183),
		gen_rtx_REG (CCDSPmode,
	184),
		gen_rtx_REG (CCDSPmode,
	185),
		gen_rtx_REG (CCDSPmode,
	186),
		gen_rtx_REG (CCDSPmode,
	187)),
	367));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1011 */
rtx
gen_mips_lbux (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	gen_rtx_MEM (QImode,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1023 */
rtx
gen_mips_lhx (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	gen_rtx_MEM (HImode,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2))));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1035 */
rtx
gen_mips_lwx (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MEM (SImode,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2)));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1047 */
rtx
gen_mips_bposge (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_GE (VOIDmode,
	gen_rtx_REG (CCDSPmode,
	182),
	operand0),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:618 */
rtx
gen_conditional_trap (rtx operand0,
	rtx operand1)
{
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
#line 623 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_MODE_CLASS (GET_MODE (cmp_operands[0])) == MODE_INT
      && operands[1] == const0_rtx)
    {
      mips_gen_conditional_trap (operands);
      DONE;
    }
  else
    FAIL;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_insn (gen_rtx_TRAP_IF (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand2,
		operand3),
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:660 */
rtx
gen_addsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:660 */
rtx
gen_adddi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:732 */
extern rtx gen_split_521 (rtx, rtx *);
rtx
gen_split_521 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 746 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val >= 0)
    {
      operands[1] = GEN_INT (0x7f);
      operands[2] = GEN_INT (val - 0x7f);
    }
  else
    {
      operands[1] = GEN_INT (- 0x80);
      operands[2] = GEN_INT (val + 0x80);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:761 */
extern rtx gen_split_522 (rtx, rtx *);
rtx
gen_split_522 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 778 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[2]);

  if (val >= 0)
    {
      operands[2] = GEN_INT (0x7);
      operands[3] = GEN_INT (val - 0x7);
    }
  else
    {
      operands[2] = GEN_INT (- 0x8);
      operands[3] = GEN_INT (val + 0x8);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:793 */
extern rtx gen_split_523 (rtx, rtx *);
rtx
gen_split_523 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 807 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val >= 0)
    {
      operands[1] = GEN_INT (0xf);
      operands[2] = GEN_INT (val - 0xf);
    }
  else
    {
      operands[1] = GEN_INT (- 0x10);
      operands[2] = GEN_INT (val + 0x10);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:822 */
extern rtx gen_split_524 (rtx, rtx *);
rtx
gen_split_524 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 839 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[2]);

  if (val >= 0)
    {
      operands[2] = GEN_INT (0x7);
      operands[3] = GEN_INT (val - 0x7);
    }
  else
    {
      operands[2] = GEN_INT (- 0x8);
      operands[3] = GEN_INT (val + 0x8);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:868 */
extern rtx gen_split_525 (rtx, rtx *);
rtx
gen_split_525 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 877 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[3] = gen_lowpart (SImode, operands[0]); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:926 */
rtx
gen_mulsf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:926 */
rtx
gen_muldf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DFmode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1011 */
rtx
gen_mulsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1016 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GENERATE_MULT3_SI)
    emit_insn (gen_mulsi3_mult3 (operands[0], operands[1], operands[2]));
  else if (!TARGET_FIX_R4000)
    emit_insn (gen_mulsi3_internal (operands[0], operands[1],
					operands[2]));
  else
    emit_insn (gen_mulsi3_r4000 (operands[0], operands[1], operands[2]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1011 */
rtx
gen_muldi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1016 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GENERATE_MULT3_DI)
    emit_insn (gen_muldi3_mult3 (operands[0], operands[1], operands[2]));
  else if (!TARGET_FIX_R4000)
    emit_insn (gen_muldi3_internal (operands[0], operands[1],
					operands[2]));
  else
    emit_insn (gen_muldi3_r4000 (operands[0], operands[1], operands[2]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1072 */
extern rtx gen_peephole2_530 (rtx, rtx *);
rtx
gen_peephole2_530 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  start_sequence ();
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	operand3),
		gen_rtx_CLOBBER (VOIDmode,
	operand0))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1120 */
extern rtx gen_peephole2_531 (rtx, rtx *);
rtx
gen_peephole2_531 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  start_sequence ();
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	const0_rtx));
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (SImode,
	gen_rtx_MULT (SImode,
	operand1,
	operand2),
	copy_rtx (operand0))),
		gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_PLUS (SImode,
	gen_rtx_MULT (SImode,
	copy_rtx (operand1),
	copy_rtx (operand2)),
	copy_rtx (operand0))),
		gen_rtx_CLOBBER (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1178 */
extern rtx gen_split_532 (rtx, rtx *);
rtx
gen_split_532 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx _val = 0;
  start_sequence ();
#line 1194 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand6,
	gen_rtx_MULT (SImode,
	operand1,
	operand2)),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand5))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand6),
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1197 */
extern rtx gen_split_533 (rtx, rtx *);
rtx
gen_split_533 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx _val = 0;
  start_sequence ();
#line 1215 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (4,
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_PLUS (SImode,
	gen_rtx_MULT (SImode,
	operand1,
	operand2),
	copy_rtx (operand3))),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand5),
		gen_rtx_CLOBBER (VOIDmode,
	operand6))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		copy_rtx (operand5),
		copy_rtx (operand4)),
	26)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1259 */
extern rtx gen_split_534 (rtx, rtx *);
rtx
gen_split_534 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx _val = 0;
  start_sequence ();
#line 1279 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand6,
	gen_rtx_NEG (SImode,
	operand3)));
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	gen_rtx_MULT (SImode,
	operand2,
	copy_rtx (operand6)),
	operand1)),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand5))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1322 */
extern rtx gen_peephole2_535 (rtx, rtx *);
rtx
gen_peephole2_535 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  start_sequence ();
#line 1336 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_SET (VOIDmode,
	operand3,
	copy_rtx (operand1)),
		gen_rtx_CLOBBER (VOIDmode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1353 */
extern rtx gen_peephole2_536 (rtx, rtx *);
rtx
gen_peephole2_536 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx operand7;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  if ((operands[0] = peep2_find_free_register (0, 1, "d", SImode, &_regs_allocated)) == NULL_RTX)
    return NULL;
  start_sequence ();
#line 1373 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[6] = XEXP (operands[4], GET_CODE (operands[4]) == PLUS ? 0 : 1);
  operands[7] = gen_rtx_fmt_ee (GET_CODE (operands[4]), SImode,
				operands[2], operands[0]);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  operand7 = operands[7];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand6),
		gen_rtx_CLOBBER (VOIDmode,
	operand5),
		gen_rtx_CLOBBER (VOIDmode,
	operand1))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand3,
	operand7));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1389 */
extern rtx gen_peephole2_537 (rtx, rtx *);
rtx
gen_peephole2_537 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx operand7;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  if ((operands[0] = peep2_find_free_register (0, 2, "d", SImode, &_regs_allocated)) == NULL_RTX)
    return NULL;
  start_sequence ();
#line 1409 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[6] = XEXP (operands[4], GET_CODE (operands[4]) == PLUS ? 0 : 1);
  operands[7] = gen_rtx_fmt_ee (GET_CODE (operands[4]), SImode,
				operands[2], operands[0]);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  operand7 = operands[7];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand6),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand1))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	operand7));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1433 */
extern rtx gen_split_538 (rtx, rtx *);
rtx
gen_split_538 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx _val = 0;
  start_sequence ();
#line 1449 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand6,
	gen_rtx_MULT (SImode,
	operand2,
	operand3)),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand5))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MINUS (SImode,
	operand1,
	copy_rtx (operand6))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1452 */
extern rtx gen_split_539 (rtx, rtx *);
rtx
gen_split_539 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx _val = 0;
  start_sequence ();
#line 1470 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (4,
		gen_rtx_SET (VOIDmode,
	operand1,
	gen_rtx_MINUS (SImode,
	copy_rtx (operand1),
	gen_rtx_MULT (SImode,
	operand2,
	operand3))),
		gen_rtx_CLOBBER (VOIDmode,
	operand4),
		gen_rtx_CLOBBER (VOIDmode,
	operand5),
		gen_rtx_CLOBBER (VOIDmode,
	operand6))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		copy_rtx (operand5),
		copy_rtx (operand4)),
	26)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1487 */
rtx
gen_mulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1496 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (!TARGET_64BIT)
    {
      if (!TARGET_FIX_R4000)
	emit_insn (gen_mulsidi3_32bit_internal (operands[0], operands[1],
						   operands[2]));
      else
	emit_insn (gen_mulsidi3_32bit_r4000 (operands[0], operands[1],
					        operands[2]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (4,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1487 */
rtx
gen_umulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1496 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (!TARGET_64BIT)
    {
      if (!TARGET_FIX_R4000)
	emit_insn (gen_umulsidi3_32bit_internal (operands[0], operands[1],
						   operands[2]));
      else
	emit_insn (gen_umulsidi3_32bit_r4000 (operands[0], operands[1],
					        operands[2]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (4,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2))),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode)))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
extern rtx gen_split_542 (rtx, rtx *);
rtx
gen_split_542 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 1571 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_MULT (SImode,
	operand1,
	operand2))),
		gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	copy_rtx (operand1)),
	gen_rtx_SIGN_EXTEND (DImode,
	copy_rtx (operand2))),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		copy_rtx (operand3),
		copy_rtx (operand4)),
	26)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		copy_rtx (operand4),
		copy_rtx (operand3)),
	26)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand5),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand5),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand5),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand5),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_IOR (DImode,
	copy_rtx (operand0),
	copy_rtx (operand5))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
extern rtx gen_split_543 (rtx, rtx *);
rtx
gen_split_543 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 1571 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand3,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_MULT (SImode,
	operand1,
	operand2))),
		gen_rtx_SET (VOIDmode,
	operand4,
	gen_rtx_ASHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	copy_rtx (operand1)),
	gen_rtx_ZERO_EXTEND (DImode,
	copy_rtx (operand2))),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])))));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand5,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		copy_rtx (operand3),
		copy_rtx (operand4)),
	26)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		copy_rtx (operand4),
		copy_rtx (operand3)),
	26)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand5),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand5),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand5),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand5),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_IOR (DImode,
	copy_rtx (operand0),
	copy_rtx (operand5))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1622 */
rtx
gen_smulsi3_highpart (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1630 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (ISA_HAS_MULHI)
    emit_insn (gen_smulsi3_highpart_mulhi_internal (operands[0],
						       operands[1],
						       operands[2]));
  else
    emit_insn (gen_smulsi3_highpart_internal (operands[0], operands[1],
					         operands[2]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1622 */
rtx
gen_umulsi3_highpart (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1630 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (ISA_HAS_MULHI)
    emit_insn (gen_umulsi3_highpart_mulhi_internal (operands[0],
						       operands[1],
						       operands[2]));
  else
    emit_insn (gen_umulsi3_highpart_internal (operands[0], operands[1],
					         operands[2]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)]))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
rtx
gen_divsf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (const_1_operand (operands[1], SFmode))
    if (!(ISA_HAS_FP4 && flag_unsafe_math_optimizations))
      operands[1] = force_reg (SFmode, operands[1]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (SFmode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
rtx
gen_divdf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (const_1_operand (operands[1], DFmode))
    if (!(ISA_HAS_FP4 && flag_unsafe_math_optimizations))
      operands[1] = force_reg (DFmode, operands[1]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (DFmode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
rtx
gen_divv2sf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 1828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (const_1_operand (operands[1], V2SFmode))
    if (!(ISA_HAS_FP4 && flag_unsafe_math_optimizations))
      operands[1] = force_reg (V2SFmode, operands[1]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_DIV (V2SFmode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2073 */
rtx
gen_andsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 2078 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    operands[2] = force_reg (SImode, operands[2]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_AND (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2073 */
rtx
gen_anddi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 2078 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    operands[2] = force_reg (DImode, operands[2]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_AND (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2103 */
rtx
gen_iorsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 2108 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    operands[2] = force_reg (SImode, operands[2]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IOR (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2103 */
rtx
gen_iordi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 2108 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    operands[2] = force_reg (DImode, operands[2]);
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IOR (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2133 */
rtx
gen_xorsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (SImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2133 */
rtx
gen_xordi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_XOR (DImode,
	operand1,
	operand2));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2267 */
extern rtx gen_split_555 (rtx, rtx *);
rtx
gen_split_555 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2280 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = gen_lowpart (DImode, operands[0]); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand2,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (48)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_ASHIFTRT (DImode,
	copy_rtx (operand2),
	const_int_rtx[MAX_SAVED_CONST_INT + (48)]))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2282 */
extern rtx gen_split_556 (rtx, rtx *);
rtx
gen_split_556 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2295 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = gen_lowpart (DImode, operands[0]); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand2,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (56)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_ASHIFTRT (DImode,
	copy_rtx (operand2),
	const_int_rtx[MAX_SAVED_CONST_INT + (56)]))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2336 */
extern rtx gen_split_557 (rtx, rtx *);
rtx
gen_split_557 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 2348 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[1] = gen_lowpart (DImode, operands[1]); }
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2356 */
extern rtx gen_split_558 (rtx, rtx *);
rtx
gen_split_558 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 2373 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
rtx
gen_zero_extendqisi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2382 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16 && !GENERATE_MIPS16E
      && !memory_operand (operands[1], QImode))
    {
      emit_insn (gen_andsi3 (operands[0],
				     gen_lowpart (SImode, operands[1]),
				     force_reg (SImode,
						GEN_INT (0x00ff))));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
rtx
gen_zero_extendqidi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2382 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16 && !GENERATE_MIPS16E
      && !memory_operand (operands[1], QImode))
    {
      emit_insn (gen_anddi3 (operands[0],
				     gen_lowpart (DImode, operands[1]),
				     force_reg (DImode,
						GEN_INT (0x00ff))));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
rtx
gen_zero_extendhisi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2382 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16 && !GENERATE_MIPS16E
      && !memory_operand (operands[1], HImode))
    {
      emit_insn (gen_andsi3 (operands[0],
				     gen_lowpart (SImode, operands[1]),
				     force_reg (SImode,
						GEN_INT (0xffff))));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
rtx
gen_zero_extendhidi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2382 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16 && !GENERATE_MIPS16E
      && !memory_operand (operands[1], HImode))
    {
      emit_insn (gen_anddi3 (operands[0],
				     gen_lowpart (DImode, operands[1]),
				     force_reg (DImode,
						GEN_INT (0xffff))));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2421 */
rtx
gen_zero_extendqihi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16 && !memory_operand (operands[1], QImode))
    {
      emit_insn (gen_zero_extendqisi2 (gen_lowpart (SImode, operands[0]),
				       operands[1]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTEND (HImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2470 */
extern rtx gen_split_564 (rtx, rtx *);
rtx
gen_split_564 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 2479 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  emit_note (NOTE_INSN_DELETED);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
rtx
gen_extendqisi2 (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
rtx
gen_extendqidi2 (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
rtx
gen_extendhisi2 (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
rtx
gen_extendhidi2 (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
extern rtx gen_split_569 (rtx, rtx *);
rtx
gen_split_569 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2512 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
extern rtx gen_split_570 (rtx, rtx *);
rtx
gen_split_570 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2512 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = gen_lowpart (DImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (DImode)
			 - GET_MODE_BITSIZE (QImode));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
extern rtx gen_split_571 (rtx, rtx *);
rtx
gen_split_571 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2512 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
extern rtx gen_split_572 (rtx, rtx *);
rtx
gen_split_572 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 2512 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = gen_lowpart (DImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (DImode)
			 - GET_MODE_BITSIZE (HImode));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2534 */
extern rtx gen_split_573 (rtx, rtx *);
rtx
gen_split_573 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 2541 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[0] = gen_lowpart (SImode, operands[0]); }
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2562 */
rtx
gen_fix_truncdfsi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2566 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (!ISA_HAS_TRUNC_W)
    {
      emit_insn (gen_fix_truncdfsi2_macro (operands[0], operands[1]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2600 */
rtx
gen_fix_truncsfsi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2604 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (!ISA_HAS_TRUNC_W)
    {
      emit_insn (gen_fix_truncsfsi2_macro (operands[0], operands[1]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_FIX (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2705 */
rtx
gen_fixuns_truncdfsi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2709 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  rtx reg1 = gen_reg_rtx (DFmode);
  rtx reg2 = gen_reg_rtx (DFmode);
  rtx reg3 = gen_reg_rtx (SImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset;

  real_2expN (&offset, 31);

  if (reg1)			/* Turn off complaints about unreached code.  */
    {
      emit_move_insn (reg1, CONST_DOUBLE_FROM_REAL_VALUE (offset, DFmode));
      do_pending_stack_adjust ();

      emit_insn (gen_cmpdf (operands[1], reg1));
      emit_jump_insn (gen_bge (label1));

      emit_insn (gen_fix_truncdfsi2 (operands[0], operands[1]));
      emit_jump_insn (gen_rtx_SET (VOIDmode, pc_rtx,
				   gen_rtx_LABEL_REF (VOIDmode, label2)));
      emit_barrier ();

      emit_label (label1);
      emit_move_insn (reg2, gen_rtx_MINUS (DFmode, operands[1], reg1));
      emit_move_insn (reg3, GEN_INT (trunc_int_for_mode
				     (BITMASK_HIGH, SImode)));

      emit_insn (gen_fix_truncdfsi2 (operands[0], reg2));
      emit_insn (gen_iorsi3 (operands[0], operands[0], reg3));

      emit_label (label2);

      /* Allow REG_NOTES to be set on last insn (labels don't have enough
	 fields, and can't be used for REG_NOTES anyway).  */
      emit_insn (gen_rtx_USE (VOIDmode, stack_pointer_rtx));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2750 */
rtx
gen_fixuns_truncdfdi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2754 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  rtx reg1 = gen_reg_rtx (DFmode);
  rtx reg2 = gen_reg_rtx (DFmode);
  rtx reg3 = gen_reg_rtx (DImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset;

  real_2expN (&offset, 63);

  emit_move_insn (reg1, CONST_DOUBLE_FROM_REAL_VALUE (offset, DFmode));
  do_pending_stack_adjust ();

  emit_insn (gen_cmpdf (operands[1], reg1));
  emit_jump_insn (gen_bge (label1));

  emit_insn (gen_fix_truncdfdi2 (operands[0], operands[1]));
  emit_jump_insn (gen_rtx_SET (VOIDmode, pc_rtx,
			       gen_rtx_LABEL_REF (VOIDmode, label2)));
  emit_barrier ();

  emit_label (label1);
  emit_move_insn (reg2, gen_rtx_MINUS (DFmode, operands[1], reg1));
  emit_move_insn (reg3, GEN_INT (BITMASK_HIGH));
  emit_insn (gen_ashldi3 (reg3, reg3, GEN_INT (32)));

  emit_insn (gen_fix_truncdfdi2 (operands[0], reg2));
  emit_insn (gen_iordi3 (operands[0], operands[0], reg3));

  emit_label (label2);

  /* Allow REG_NOTES to be set on last insn (labels don't have enough
     fields, and can't be used for REG_NOTES anyway).  */
  emit_insn (gen_rtx_USE (VOIDmode, stack_pointer_rtx));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2792 */
rtx
gen_fixuns_truncsfsi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2796 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  rtx reg1 = gen_reg_rtx (SFmode);
  rtx reg2 = gen_reg_rtx (SFmode);
  rtx reg3 = gen_reg_rtx (SImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset;

  real_2expN (&offset, 31);

  emit_move_insn (reg1, CONST_DOUBLE_FROM_REAL_VALUE (offset, SFmode));
  do_pending_stack_adjust ();

  emit_insn (gen_cmpsf (operands[1], reg1));
  emit_jump_insn (gen_bge (label1));

  emit_insn (gen_fix_truncsfsi2 (operands[0], operands[1]));
  emit_jump_insn (gen_rtx_SET (VOIDmode, pc_rtx,
			       gen_rtx_LABEL_REF (VOIDmode, label2)));
  emit_barrier ();

  emit_label (label1);
  emit_move_insn (reg2, gen_rtx_MINUS (SFmode, operands[1], reg1));
  emit_move_insn (reg3, GEN_INT (trunc_int_for_mode
				 (BITMASK_HIGH, SImode)));

  emit_insn (gen_fix_truncsfsi2 (operands[0], reg2));
  emit_insn (gen_iorsi3 (operands[0], operands[0], reg3));

  emit_label (label2);

  /* Allow REG_NOTES to be set on last insn (labels don't have enough
     fields, and can't be used for REG_NOTES anyway).  */
  emit_insn (gen_rtx_USE (VOIDmode, stack_pointer_rtx));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2834 */
rtx
gen_fixuns_truncsfdi2 (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 2838 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  rtx reg1 = gen_reg_rtx (SFmode);
  rtx reg2 = gen_reg_rtx (SFmode);
  rtx reg3 = gen_reg_rtx (DImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset;

  real_2expN (&offset, 63);

  emit_move_insn (reg1, CONST_DOUBLE_FROM_REAL_VALUE (offset, SFmode));
  do_pending_stack_adjust ();

  emit_insn (gen_cmpsf (operands[1], reg1));
  emit_jump_insn (gen_bge (label1));

  emit_insn (gen_fix_truncsfdi2 (operands[0], operands[1]));
  emit_jump_insn (gen_rtx_SET (VOIDmode, pc_rtx,
			       gen_rtx_LABEL_REF (VOIDmode, label2)));
  emit_barrier ();

  emit_label (label1);
  emit_move_insn (reg2, gen_rtx_MINUS (SFmode, operands[1], reg1));
  emit_move_insn (reg3, GEN_INT (BITMASK_HIGH));
  emit_insn (gen_ashldi3 (reg3, reg3, GEN_INT (32)));

  emit_insn (gen_fix_truncsfdi2 (operands[0], reg2));
  emit_insn (gen_iordi3 (operands[0], operands[0], reg3));

  emit_label (label2);

  /* Allow REG_NOTES to be set on last insn (labels don't have enough
     fields, and can't be used for REG_NOTES anyway).  */
  emit_insn (gen_rtx_USE (VOIDmode, stack_pointer_rtx));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2884 */
rtx
gen_extv (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2890 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_expand_unaligned_load (operands[0], operands[1],
				  INTVAL (operands[2]),
				  INTVAL (operands[3])))
    DONE;
  else
    FAIL;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SIGN_EXTRACT (VOIDmode,
	operand1,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2899 */
rtx
gen_extzv (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2905 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_expand_unaligned_load (operands[0], operands[1],
				  INTVAL (operands[2]),
				  INTVAL (operands[3])))
    DONE;
  else if (mips_use_ins_ext_p (operands[1], operands[2], operands[3]))
    {
      if (GET_MODE (operands[0]) == DImode)
        emit_insn (gen_extzvdi (operands[0], operands[1], operands[2],
				operands[3]));
      else
        emit_insn (gen_extzvsi (operands[0], operands[1], operands[2],
				operands[3]));
      DONE;
    }
  else
    FAIL;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ZERO_EXTRACT (VOIDmode,
	operand1,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2935 */
rtx
gen_insv (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 2941 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_expand_unaligned_store (operands[0], operands[3],
				   INTVAL (operands[1]),
				   INTVAL (operands[2])))
    DONE;
  else if (mips_use_ins_ext_p (operands[0], operands[1], operands[2]))
    {
      if (GET_MODE (operands[0]) == DImode)
        emit_insn (gen_insvdi (operands[0], operands[1], operands[2],
			       operands[3]));
      else
        emit_insn (gen_insvsi (operands[0], operands[1], operands[2],
			       operands[3]));
      DONE;
   }
   else
     FAIL;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	gen_rtx_ZERO_EXTRACT (VOIDmode,
	operand0,
	operand1,
	operand2),
	operand3));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3039 */
extern rtx gen_split_583 (rtx, rtx *);
rtx
gen_split_583 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3050 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = mips_unspec_address (operands[1], SYMBOL_64_HIGH);
  operands[3] = mips_unspec_address (operands[1], SYMBOL_64_MID);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_HIGH (DImode,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LO_SUM (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (16)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LO_SUM (DImode,
	copy_rtx (operand0),
	operand3)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (16)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3064 */
extern rtx gen_peephole2_584 (rtx, rtx *);
rtx
gen_peephole2_584 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  HARD_REG_SET _regs_allocated;
  CLEAR_HARD_REG_SET (_regs_allocated);
  if ((operands[0] = peep2_find_free_register (1, 1, "d", DImode, &_regs_allocated)) == NULL_RTX)
    return NULL;
  start_sequence ();
#line 3074 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[3] = mips_unspec_address (operands[2], SYMBOL_64_HIGH);
  operands[4] = mips_unspec_address (operands[2], SYMBOL_64_LOW);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand1,
	gen_rtx_HIGH (DImode,
	operand3)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_HIGH (DImode,
	operand4)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_LO_SUM (DImode,
	copy_rtx (operand1),
	copy_rtx (operand3))));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand1),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand1),
	gen_rtx_PLUS (DImode,
	copy_rtx (operand1),
	copy_rtx (operand0))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3092 */
extern rtx gen_split_585 (rtx, rtx *);
rtx
gen_split_585 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();
#line 3105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[3] = mips_unspec_address (operands[1], SYMBOL_64_HIGH);
  operands[4] = mips_unspec_address (operands[1], SYMBOL_64_LOW);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_HIGH (DImode,
	operand3)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand2,
	gen_rtx_HIGH (DImode,
	operand4)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LO_SUM (DImode,
	copy_rtx (operand0),
	copy_rtx (operand3))));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand2),
	gen_rtx_LO_SUM (DImode,
	copy_rtx (operand2),
	copy_rtx (operand4))));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
extern rtx gen_split_586 (rtx, rtx *);
rtx
gen_split_586 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3121 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_GLOBAL);
  operands[3] = pic_offset_table_rtx;
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_HIGH (SImode,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
extern rtx gen_split_587 (rtx, rtx *);
rtx
gen_split_587 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3121 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_GLOBAL);
  operands[3] = pic_offset_table_rtx;
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_HIGH (DImode,
	operand2)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
extern rtx gen_split_588 (rtx, rtx *);
rtx
gen_split_588 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3137 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[3] = mips_unspec_address (operands[2], SYMBOL_GOTOFF_GLOBAL); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
extern rtx gen_split_589 (rtx, rtx *);
rtx
gen_split_589 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3137 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[3] = mips_unspec_address (operands[2], SYMBOL_GOTOFF_GLOBAL); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
extern rtx gen_split_590 (rtx, rtx *);
rtx
gen_split_590 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3151 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = pic_offset_table_rtx;
  operands[3] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_GLOBAL);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand2,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
extern rtx gen_split_591 (rtx, rtx *);
rtx
gen_split_591 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3151 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = pic_offset_table_rtx;
  operands[3] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_GLOBAL);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand2,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
extern rtx gen_split_592 (rtx, rtx *);
rtx
gen_split_592 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3168 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = pic_offset_table_rtx;
  operands[3] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_PAGE);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand2,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
extern rtx gen_split_593 (rtx, rtx *);
rtx
gen_split_593 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3168 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = pic_offset_table_rtx;
  operands[3] = mips_unspec_address (operands[1], SYMBOL_GOTOFF_PAGE);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand2,
		operand3),
	24)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3215 */
extern rtx gen_split_594 (rtx, rtx *);
rtx
gen_split_594 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 3221 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_move_integer (operands[0], operands[2], INTVAL (operands[1]));
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3215 */
extern rtx gen_split_595 (rtx, rtx *);
rtx
gen_split_595 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 3221 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_move_integer (operands[0], operands[2], INTVAL (operands[1]));
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3227 */
extern rtx gen_split_596 (rtx, rtx *);
rtx
gen_split_596 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 3233 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[1] = mips_split_symbol (operands[2], operands[1]); }
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3227 */
extern rtx gen_split_597 (rtx, rtx *);
rtx
gen_split_597 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();
#line 3233 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[1] = mips_split_symbol (operands[2], operands[1]); }
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3241 */
rtx
gen_movdi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3245 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (DImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3323 */
extern rtx gen_split_599 (rtx, rtx *);
rtx
gen_split_599 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 3341 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val < 0)
    operands[2] = const0_rtx;
  else if (val >= 32 * 8)
    {
      int off = val & 7;

      operands[1] = GEN_INT (0x8 + off);
      operands[2] = GEN_INT (val - off - 0x8);
    }
  else
    {
      int off = val & 7;

      operands[1] = GEN_INT (off);
      operands[2] = GEN_INT (val - off);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_MEM (DImode,
	gen_rtx_PLUS (DImode,
	copy_rtx (operand0),
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3368 */
rtx
gen_movsi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3372 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (SImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3418 */
extern rtx gen_split_601 (rtx, rtx *);
rtx
gen_split_601 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 3435 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val < 0)
    operands[2] = const0_rtx;
  else if (val >= 32 * 4)
    {
      int off = val & 3;

      operands[1] = GEN_INT (0x7c + off);
      operands[2] = GEN_INT (val - off - 0x7c);
    }
  else
    {
      int off = val & 3;

      operands[1] = GEN_INT (off);
      operands[2] = GEN_INT (val - off);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_MEM (SImode,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3460 */
extern rtx gen_split_602 (rtx, rtx *);
rtx
gen_split_602 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 3471 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  int val = INTVAL (operands[1]);

  operands[1] = GEN_INT (0xff);
  operands[2] = GEN_INT (val - 0xff);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3506 */
rtx
gen_reload_incc (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 3511 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_emit_fcc_reload (operands[0], operands[1], operands[2]);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  emit_insn (gen_rtx_CLOBBER (VOIDmode,
	operand2));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3516 */
rtx
gen_reload_outcc (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 3521 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_emit_fcc_reload (operands[0], operands[1], operands[2]);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  emit_insn (gen_rtx_CLOBBER (VOIDmode,
	operand2));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3564 */
rtx
gen_movhi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3568 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (HImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3626 */
extern rtx gen_split_606 (rtx, rtx *);
rtx
gen_split_606 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 3643 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val < 0)
    operands[2] = const0_rtx;
  else if (val >= 32 * 2)
    {
      int off = val & 1;

      operands[1] = GEN_INT (0x7e + off);
      operands[2] = GEN_INT (val - off - 0x7e);
    }
  else
    {
      int off = val & 1;

      operands[1] = GEN_INT (off);
      operands[2] = GEN_INT (val - off);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_MEM (HImode,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3671 */
rtx
gen_movqi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3675 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (QImode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3721 */
extern rtx gen_split_608 (rtx, rtx *);
rtx
gen_split_608 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 3735 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  HOST_WIDE_INT val = INTVAL (operands[1]);

  if (val < 0)
    operands[2] = const0_rtx;
  else
    {
      operands[1] = GEN_INT (0x7f);
      operands[2] = GEN_INT (val - 0x7f);
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand1)));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_MEM (QImode,
	gen_rtx_PLUS (SImode,
	copy_rtx (operand0),
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3749 */
rtx
gen_movsf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3753 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (SFmode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3794 */
rtx
gen_movdf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3798 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (DFmode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3847 */
extern rtx gen_split_611 (rtx, rtx *);
rtx
gen_split_611 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 3853 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_split_64bit_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3858 */
extern rtx gen_split_612 (rtx, rtx *);
rtx
gen_split_612 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 3864 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_split_64bit_move (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3871 */
extern rtx gen_split_613 (rtx, rtx *);
rtx
gen_split_613 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();
#line 3879 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = gen_lowpart (SImode, operands[0]);
  operands[3] = GEN_INT (-INTVAL (operands[1]));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand2,
	operand3));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand2),
	gen_rtx_NEG (SImode,
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3886 */
rtx
gen_movv2sf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 3890 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_legitimize_move (V2SFmode, operands[0], operands[1]))
    DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3918 */
rtx
gen_mfhilo_si (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	26));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3918 */
rtx
gen_mfhilo_di (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	26));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3998 */
extern rtx gen_split_617 (rtx, rtx *);
rtx
gen_split_617 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
#line 4007 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = pic_offset_table_rtx;
  operands[3] = gen_rtx_HIGH (Pmode, operands[0]);
  operands[4] = gen_rtx_PLUS (Pmode, operands[2], operands[1]);
  operands[5] = gen_rtx_LO_SUM (Pmode, operands[2], operands[0]);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand2,
	operand3));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand2),
	operand4));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand2),
	operand5));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4016 */
extern rtx gen_split_618 (rtx, rtx *);
rtx
gen_split_618 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 4022 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  emit_move_insn (pic_offset_table_rtx, operands[0]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4062 */
rtx
gen_movmemsi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 4068 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (mips_expand_block_move (operands[0], operands[1], operands[2]))
    DONE;
  else
    FAIL;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_ashlsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (SImode);

      emit_insn (gen_ashlsi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_ashlsi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_ashrsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (SImode);

      emit_insn (gen_ashrsi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_ashrsi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_lshrsi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (SImode);

      emit_insn (gen_lshrsi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_lshrsi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_ashldi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (DImode);

      emit_insn (gen_ashldi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_ashldi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_ashrdi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (DImode);

      emit_insn (gen_ashrdi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_ashrdi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
rtx
gen_lshrdi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 4087 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* On the mips16, a shift of more than 8 is a four byte instruction,
     so, for a shift between 8 and 16, it is just as fast to do two
     shifts of 8 or less.  If there is a lot of shifting going on, we
     may win in CSE.  Otherwise combine will put the shifts back
     together again.  This can be called by function_arg, so we must
     be careful not to allocate a new register if we've reached the
     reload pass.  */
  if (TARGET_MIPS16
      && optimize
      && GET_CODE (operands[2]) == CONST_INT
      && INTVAL (operands[2]) > 8
      && INTVAL (operands[2]) <= 16
      && !reload_in_progress
      && !reload_completed)
    {
      rtx temp = gen_reg_rtx (DImode);

      emit_insn (gen_lshrdi3 (temp, operands[1], GEN_INT (8)));
      emit_insn (gen_lshrdi3 (operands[0], temp,
				     GEN_INT (INTVAL (operands[2]) - 8)));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_626 (rtx, rtx *);
rtx
gen_split_626 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_627 (rtx, rtx *);
rtx
gen_split_627 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_628 (rtx, rtx *);
rtx
gen_split_628 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_629 (rtx, rtx *);
rtx
gen_split_629 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_630 (rtx, rtx *);
rtx
gen_split_630 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_ASHIFTRT (DImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
extern rtx gen_split_631 (rtx, rtx *);
rtx
gen_split_631 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4234 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[2] = GEN_INT (INTVAL (operands[2]) - 8); }
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (8)])));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4245 */
extern rtx gen_split_632 (rtx, rtx *);
rtx
gen_split_632 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
#line 4254 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	copy_rtx (operand0),
	gen_rtx_LSHIFTRT (SImode,
	copy_rtx (operand0),
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4296 */
rtx
gen_cmpsi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 4301 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  cmp_operands[0] = operands[0];
  cmp_operands[1] = operands[1];
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	cc0_rtx,
	gen_rtx_COMPARE (CCmode,
	operand0,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4296 */
rtx
gen_cmpdi (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 4301 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  cmp_operands[0] = operands[0];
  cmp_operands[1] = operands[1];
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	cc0_rtx,
	gen_rtx_COMPARE (CCmode,
	operand0,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4307 */
rtx
gen_cmpsf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 4312 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  cmp_operands[0] = operands[0];
  cmp_operands[1] = operands[1];
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	cc0_rtx,
	gen_rtx_COMPARE (CCmode,
	operand0,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4307 */
rtx
gen_cmpdf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 4312 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  cmp_operands[0] = operands[0];
  cmp_operands[1] = operands[1];
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	cc0_rtx,
	gen_rtx_COMPARE (CCmode,
	operand0,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bunordered (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNORDERED);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNORDERED (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bordered (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, ORDERED);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_ORDERED (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bunlt (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNLT);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNLT (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bunge (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNGE);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNGE (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_buneq (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNEQ);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNEQ (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bltgt (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, LTGT);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_LTGT (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bunle (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNLE);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNLE (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bungt (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, UNGT);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_UNGT (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_beq (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, EQ);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_EQ (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bne (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, NE);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_NE (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bgt (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, GT);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_GT (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bge (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, GE);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_GE (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_blt (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, LT);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_LT (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_ble (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, LE);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_LE (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bgtu (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, GTU);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_GTU (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bgeu (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, GEU);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_GEU (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bltu (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, LTU);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_LTU (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
rtx
gen_bleu (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_branch (operands, LEU);
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_LEU (CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand0),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4469 */
rtx
gen_condjump (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	operand0,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4482 */
rtx
gen_seq (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4487 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (EQ, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_EQ (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4510 */
rtx
gen_sne (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4515 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (NE, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_NE (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4526 */
rtx
gen_sgt (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4531 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (GT, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4551 */
rtx
gen_sge (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4556 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (GE, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GE (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4567 */
rtx
gen_slt (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4572 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (LT, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4597 */
rtx
gen_sle (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4602 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (LE, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LE (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4631 */
rtx
gen_sgtu (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4636 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (GTU, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GTU (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4656 */
rtx
gen_sgeu (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4661 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (GEU, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_GEU (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4672 */
rtx
gen_sltu (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4677 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (LTU, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LTU (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4702 */
rtx
gen_sleu (rtx operand0)
{
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
#line 4707 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ if (mips_emit_scc (LEU, operands[0])) DONE; else FAIL; }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_LEU (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4813 */
rtx
gen_indirect_jump (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4816 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[0] = force_reg (Pmode, operands[0]);
  if (Pmode == SImode)
    emit_jump_insn (gen_indirect_jumpsi (operands[0]));
  else
    emit_jump_insn (gen_indirect_jumpdi (operands[0]));
  DONE;
}
    operand0 = operands[0];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4832 */
rtx
gen_tablejump (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 4837 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    operands[0] = expand_binop (Pmode, add_optab,
				convert_to_mode (Pmode, operands[0], false),
				gen_rtx_LABEL_REF (Pmode, operands[1]),
				0, 0, OPTAB_WIDEN);
  else if (TARGET_GPWORD)
    operands[0] = expand_binop (Pmode, add_optab, operands[0],
				pic_offset_table_rtx, 0, 0, OPTAB_WIDEN);

  if (Pmode == SImode)
    emit_jump_insn (gen_tablejumpsi (operands[0], operands[1]));
  else
    emit_jump_insn (gen_tablejumpdi (operands[0], operands[1]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_jump_insn (gen_rtx_SET (VOIDmode,
	pc_rtx,
	operand0));
  emit_insn (gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4868 */
rtx
gen_builtin_setjmp_setup (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4871 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  rtx addr;

  addr = plus_constant (operands[0], GET_MODE_SIZE (Pmode) * 3);
  emit_move_insn (gen_rtx_MEM (Pmode, addr), pic_offset_table_rtx);
  DONE;
}
    operand0 = operands[0];
  }
  emit_insn (gen_rtx_USE (VOIDmode,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4883 */
rtx
gen_builtin_longjmp (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4886 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  /* The elements of the buffer are, in order:  */
  int W = GET_MODE_SIZE (Pmode);
  rtx fp = gen_rtx_MEM (Pmode, operands[0]);
  rtx lab = gen_rtx_MEM (Pmode, plus_constant (operands[0], 1*W));
  rtx stack = gen_rtx_MEM (Pmode, plus_constant (operands[0], 2*W));
  rtx gpv = gen_rtx_MEM (Pmode, plus_constant (operands[0], 3*W));
  rtx pv = gen_rtx_REG (Pmode, PIC_FUNCTION_ADDR_REGNUM);
  /* Use gen_raw_REG to avoid being given pic_offset_table_rtx.
     The target is bound to be using $28 as the global pointer
     but the current function might not be.  */
  rtx gp = gen_raw_REG (Pmode, GLOBAL_POINTER_REGNUM);

  /* This bit is similar to expand_builtin_longjmp except that it
     restores $gp as well.  */
  emit_move_insn (hard_frame_pointer_rtx, fp);
  emit_move_insn (pv, lab);
  emit_stack_restore (SAVE_NONLOCAL, stack, NULL_RTX);
  emit_move_insn (gp, gpv);
  emit_insn (gen_rtx_USE (VOIDmode, hard_frame_pointer_rtx));
  emit_insn (gen_rtx_USE (VOIDmode, stack_pointer_rtx));
  emit_insn (gen_rtx_USE (VOIDmode, gp));
  emit_indirect_jump (pv);
  DONE;
}
    operand0 = operands[0];
  }
  emit_insn (gen_rtx_USE (VOIDmode,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4920 */
rtx
gen_prologue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 4923 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_prologue ();
  DONE;
}
  }
  emit_insn (const1_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4940 */
rtx
gen_epilogue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 4943 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_epilogue (false);
  DONE;
}
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4948 */
rtx
gen_sibcall_epilogue (void)
{
  rtx _val = 0;
  start_sequence ();
  {
#line 4951 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_epilogue (true);
  DONE;
}
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4977 */
rtx
gen_eh_return (rtx operand0)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#line 4980 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  enum machine_mode gpr_mode = TARGET_64BIT ? DImode : SImode;

  if (GET_MODE (operands[0]) != gpr_mode)
    operands[0] = convert_to_mode (gpr_mode, operands[0], 0);
  if (TARGET_64BIT)
    emit_insn (gen_eh_set_lr_di (operands[0]));
  else
    emit_insn (gen_eh_set_lr_si (operands[0]));

  DONE;
}
    operand0 = operands[0];
  }
  emit_insn (gen_rtx_USE (VOIDmode,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5008 */
extern rtx gen_split_674 (rtx, rtx *);
rtx
gen_split_674 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 5013 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_set_return_address (operands[0], operands[1]);
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5018 */
extern rtx gen_split_675 (rtx, rtx *);
rtx
gen_split_675 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 5025 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_restore_gp ();
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5077 */
rtx
gen_sibcall (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5083 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_call (0, XEXP (operands[0], 0), operands[1], operands[2], true);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5095 */
rtx
gen_sibcall_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5101 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_call (operands[0], XEXP (operands[1], 0),
		    operands[2], operands[3], true);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5126 */
rtx
gen_call (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_call (0, XEXP (operands[0], 0), operands[1], operands[2], false);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5174 */
extern rtx gen_split_679 (rtx, rtx *);
rtx
gen_split_679 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 5182 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  emit_call_insn (gen_call_split (operands[0], operands[1]));
  if (!find_reg_note (operands[2], REG_NORETURN, 0))
    mips_restore_gp ();
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5200 */
rtx
gen_call_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5206 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  mips_expand_call (operands[0], XEXP (operands[1], 0),
		    operands[2], operands[3], false);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5213 */
extern rtx gen_split_681 (rtx, rtx *);
rtx
gen_split_681 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 5222 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  emit_call_insn (gen_call_value_split (operands[0], operands[1],
					operands[2]));
  if (!find_reg_note (operands[3], REG_NORETURN, 0))
    mips_restore_gp ();
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5243 */
extern rtx gen_split_682 (rtx, rtx *);
rtx
gen_split_682 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx _val = 0;
  start_sequence ();
#line 5255 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  emit_call_insn (gen_call_value_multiple_split (operands[0], operands[1],
						 operands[2], operands[3]));
  if (!find_reg_note (operands[4], REG_NORETURN, 0))
    mips_restore_gp ();
  DONE;
}
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5280 */
rtx
gen_untyped_call (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 5286 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  int i;

  emit_call_insn (GEN_CALL (operands[0], const0_rtx, NULL, const0_rtx));

  for (i = 0; i < XVECLEN (operands[2], 0); i++)
    {
      rtx set = XVECEXP (operands[2], 0, i);
      emit_move_insn (SET_DEST (set), SET_SRC (set));
    }

  emit_insn (gen_blockage ());
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	const0_rtx),
		operand1,
		operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5386 */
rtx
gen_movsicc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5393 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_move (operands);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (SImode,
	operand5,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5386 */
rtx
gen_movdicc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5393 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_move (operands);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (DImode,
	operand5,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5398 */
rtx
gen_movsfcc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5405 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_move (operands);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (SFmode,
	operand5,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5398 */
rtx
gen_movdfcc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 5405 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  gen_conditional_move (operands);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (DFmode,
	operand5,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5452 */
extern rtx gen_split_688 (rtx, rtx *);
rtx
gen_split_688 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx _val = 0;
  start_sequence ();
#line 5456 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ operands[0] = mips_rewrite_small_data (operands[0]); }
  operand0 = operands[0];
  emit (operand0);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:49 */
rtx
gen_movv2sfcc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx operand4;
  rtx operand5;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#line 56 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  /* We can only support MOVN.PS and MOVZ.PS.
     NOTE: MOVT.PS and MOVF.PS have different semantics from MOVN.PS and 
	   MOVZ.PS.  MOVT.PS and MOVF.PS depend on two CC values and move 
	   each item independently.  */

  if (GET_MODE_CLASS (GET_MODE (cmp_operands[0])) != MODE_INT)
    FAIL;

  gen_conditional_move (operands);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand4,
	operand1));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (V2SFmode,
	operand5,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:126 */
rtx
gen_vec_initv2sf (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 130 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  rtx op0 = force_reg (SFmode, XVECEXP (operands[1], 0, 0));
  rtx op1 = force_reg (SFmode, XVECEXP (operands[1], 0, 1));
  emit_insn (gen_vec_initv2sf_internal (operands[0], op0, op1));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit (operand0);
  emit (operand1);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:174 */
rtx
gen_vec_setv2sf (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 179 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  rtx temp;

  /* We don't have an insert instruction, so we duplicate the float, and
     then use a PUL instruction.  */
  temp = gen_reg_rtx (V2SFmode);
  emit_insn (gen_mips_cvt_ps_s (temp, operands[1], operands[1]));
  if (INTVAL (operands[2]) == !BYTES_BIG_ENDIAN)
    emit_insn (gen_mips_pul_ps (operands[0], temp, operands[0]));
  else
    emit_insn (gen_mips_pul_ps (operands[0], operands[0], temp));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit (operand0);
  emit (operand1);
  emit (operand2);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:194 */
rtx
gen_mips_cvt_ps_s (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 199 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  if (BYTES_BIG_ENDIAN)
    emit_insn (gen_vec_initv2sf_internal (operands[0], operands[1],
	       operands[2]));
  else
    emit_insn (gen_vec_initv2sf_internal (operands[0], operands[2],
	       operands[1]));
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit (operand0);
  emit (operand1);
  emit (operand2);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:210 */
rtx
gen_mips_cvt_s_pl (rtx operand0,
	rtx operand1)
{
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
#line 215 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{ operands[2] = GEN_INT (BYTES_BIG_ENDIAN); }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_SELECT (SFmode,
	operand1,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (1,
		operand2)))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:218 */
rtx
gen_mips_cvt_s_pu (rtx operand0,
	rtx operand1)
{
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
#line 223 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{ operands[2] = GEN_INT (!BYTES_BIG_ENDIAN); }
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_VEC_SELECT (SFmode,
	operand1,
	gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (1,
		operand2)))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:280 */
rtx
gen_mips_abs_ps (rtx operand0,
	rtx operand1)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#line 285 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  /* If we can ignore NaNs, this operation is equivalent to the
     rtl ABS code.  */
  if (!HONOR_NANS (V2SFmode))
    {
      emit_insn (gen_absv2sf2 (operands[0], operands[1]));
      DONE;
    }
}
    operand0 = operands[0];
    operand1 = operands[1];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (V2SFmode,
	gen_rtvec (1,
		operand1),
	208)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:324 */
extern rtx gen_split_696 (rtx, rtx *);
rtx
gen_split_696 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx operand7;
  rtx _val = 0;
  start_sequence ();
#line 345 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  operands[6] = simplify_gen_subreg (CCV2mode, operands[0], CCV4mode, 0);
  operands[7] = simplify_gen_subreg (CCV2mode, operands[0], CCV4mode, 8);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  operand7 = operands[7];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand6,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand5),
	201)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand7,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand3,
		operand4,
		copy_rtx (operand5)),
	201)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:353 */
extern rtx gen_split_697 (rtx, rtx *);
rtx
gen_split_697 (rtx curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx operand7;
  rtx _val = 0;
  start_sequence ();
#line 374 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  operands[6] = simplify_gen_subreg (CCV2mode, operands[0], CCV4mode, 0);
  operands[7] = simplify_gen_subreg (CCV2mode, operands[0], CCV4mode, 8);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  operand7 = operands[7];
  emit_insn (gen_rtx_SET (VOIDmode,
	operand6,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand5),
	203)));
  emit_insn (gen_rtx_SET (VOIDmode,
	operand7,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (3,
		operand3,
		operand4,
		copy_rtx (operand5)),
	203)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:410 */
rtx
gen_scc_ps (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_UNSPEC (CCV2mode,
	gen_rtvec (1,
		operand1),
	214));
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:490 */
rtx
gen_single_cc (rtx operand0,
	rtx operand1)
{
  return gen_rtx_NE (VOIDmode,
	gen_rtx_UNSPEC (CCmode,
	gen_rtvec (2,
		operand0,
		operand1),
	213),
	const0_rtx);
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:583 */
rtx
gen_vcondv2sf (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3,
	rtx operand4,
	rtx operand5)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[6];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
    operands[4] = operand4;
    operands[5] = operand5;
#line 592 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  mips_expand_vcondv2sf (operands[0], operands[1], operands[2],
			 GET_CODE (operands[3]), operands[4], operands[5]);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
    operand3 = operands[3];
    operand4 = operands[4];
    operand5 = operands[5];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_IF_THEN_ELSE (V2SFmode,
	gen_rtx_fmt_ee (GET_CODE (operand3), VOIDmode,
		operand4,
		operand5),
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:598 */
rtx
gen_sminv2sf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 603 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  mips_expand_vcondv2sf (operands[0], operands[1], operands[2],
			 LE, operands[1], operands[2]);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMIN (V2SFmode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:609 */
rtx
gen_smaxv2sf3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx _val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#line 614 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  mips_expand_vcondv2sf (operands[0], operands[1], operands[2],
			 LE, operands[2], operands[1]);
  DONE;
}
    operand0 = operands[0];
    operand1 = operands[1];
    operand2 = operands[2];
  }
  emit_insn (gen_rtx_SET (VOIDmode,
	operand0,
	gen_rtx_SMAX (V2SFmode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}



void
add_clobbers (rtx pattern ATTRIBUTE_UNUSED, int insn_code_number)
{
  switch (insn_code_number)
    {
    case 359:
      XVECEXP (pattern, 0, 2) = gen_hard_reg_clobber (SImode, 31);
      XVECEXP (pattern, 0, 3) = gen_hard_reg_clobber (SImode, 28);
      break;

    case 358:
      XVECEXP (pattern, 0, 2) = gen_hard_reg_clobber (SImode, 31);
      break;

    case 357:
    case 355:
      XVECEXP (pattern, 0, 1) = gen_hard_reg_clobber (SImode, 31);
      XVECEXP (pattern, 0, 2) = gen_hard_reg_clobber (SImode, 28);
      break;

    case 356:
    case 354:
      XVECEXP (pattern, 0, 1) = gen_hard_reg_clobber (SImode, 31);
      break;

    case 172:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SFmode));
      break;

    case 170:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DFmode));
      break;

    case 46:
    case 45:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      XVECEXP (pattern, 0, 3) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    case 38:
    case 37:
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 39:
    case 36:
    case 33:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      XVECEXP (pattern, 0, 3) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 347:
    case 192:
    case 60:
    case 59:
    case 44:
    case 43:
    case 30:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    case 346:
    case 61:
    case 54:
    case 53:
    case 29:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 32:
    case 28:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    case 58:
    case 57:
    case 56:
    case 55:
    case 40:
    case 35:
    case 34:
    case 31:
    case 27:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    default:
      gcc_unreachable ();
    }
}


int
added_clobbers_hard_reg_p (int insn_code_number)
{
  switch (insn_code_number)
    {
    case 172:
    case 170:
    case 46:
    case 45:
    case 38:
    case 37:
    case 39:
    case 36:
    case 33:
    case 347:
    case 192:
    case 60:
    case 59:
    case 44:
    case 43:
    case 30:
    case 346:
    case 61:
    case 54:
    case 53:
    case 29:
    case 32:
    case 28:
    case 58:
    case 57:
    case 56:
    case 55:
    case 40:
    case 35:
    case 34:
    case 31:
    case 27:
      return 0;

    case 359:
    case 358:
    case 357:
    case 355:
    case 356:
    case 354:
      return 1;

    default:
      gcc_unreachable ();
    }
}
