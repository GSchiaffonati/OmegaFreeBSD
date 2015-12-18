/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "flags.h"
#include "ggc.h"
#include "rtl.h"
#include "expr.h"
#include "insn-codes.h"
#include "tm_p.h"
#include "function.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"

#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "toplev.h"
#include "output.h"
#include "target.h"
#include "tm-constrs.h"

static const char *
output_0 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 608 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (ISA_HAS_COND_TRAP)
    return "teq\t$0,$0";
  else if (TARGET_MIPS16)
    return "break 0";
  else
    return "break";
}
}

static const char * const output_6[] = {
  "addu\t%0,%1,%2",
  "addiu\t%0,%1,%2",
};

static const char * const output_7[] = {
  "daddu\t%0,%1,%2",
  "daddiu\t%0,%1,%2",
};

static const char * const output_12[] = {
  "addiu\t%0,%2",
  "addiu\t%0,%1,%2",
  "addu\t%0,%1,%2",
};

static const char * const output_13[] = {
  "daddiu\t%0,%2",
  "daddiu\t%0,%1,%2",
  "daddu\t%0,%1,%2",
};

static const char * const output_14[] = {
  "addu\t%0,%1,%2",
  "addiu\t%0,%1,%2",
};

static const char *
output_27 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1034 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 1)
    return "mult\t%1,%2";
  if (TARGET_MAD
      || TARGET_MIPS5400
      || TARGET_MIPS5500
      || TARGET_MIPS7000
      || TARGET_MIPS9000
      || ISA_MIPS32
      || ISA_MIPS32R2
      || ISA_MIPS64
      || ISA_MIPS64R2)
    return "mul\t%0,%1,%2";
  return "mult\t%0,%1,%2";
}
}

static const char *
output_33 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1165 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  static const char *const madd[] = { "madd\t%1,%2", "madd\t%0,%1,%2" };
  if (which_alternative == 2)
    return "#";
  if (ISA_HAS_MADD_MSUB && which_alternative != 0)
    return "#";
  return madd[which_alternative];
}
}

static const char *
output_34 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1225 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 1)
    return "macc\t%0,%1,%2";
  else if (TARGET_MIPS5500)
    return "madd\t%1,%2";
  else
    /* The VR4130 assumes that there is a two-cycle latency between a macc
       that "writes" to $0 and an instruction that reads from it.  We avoid
       this by assigning to $1 instead.  */
    return "%[macc\t%@,%1,%2%]";
}
}

static const char *
output_35 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1247 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 1)
    return "msac\t%0,%2,%3";
  else if (TARGET_MIPS5500)
    return "msub\t%2,%3";
  else
    return "msac\t$0,%2,%3";
}
}

static const char * const output_39[] = {
  "msub\t%2,%3",
  "#",
  "#",
};

static const char * const output_40[] = {
  "muls\t$0,%1,%2",
  "muls\t%0,%1,%2",
};

static const char *
output_51 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1611 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS5500)
    return "msub\t%1,%2";
  else
    return "msac\t$0,%1,%2";
}
}

static const char *
output_52 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1611 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS5500)
    return "msubu\t%1,%2";
  else
    return "msacu\t$0,%1,%2";
}
}

static const char * const output_55[] = {
  "mult\t%1,%2",
  "mulhi\t%0,%1,%2",
};

static const char * const output_56[] = {
  "multu\t%1,%2",
  "mulhiu\t%0,%1,%2",
};

static const char * const output_57[] = {
  "mulshi\t%.,%1,%2",
  "mulshi\t%0,%1,%2",
};

static const char * const output_58[] = {
  "mulshiu\t%.,%1,%2",
  "mulshiu\t%0,%1,%2",
};

static const char *
output_62 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1729 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MAD)
    return "mad\t%1,%2";
  else if (TARGET_MIPS5500)
    return "madd\t%1,%2";
  else
    /* See comment in *macc.  */
    return "%[macc\t%@,%1,%2%]";
}
}

static const char *
output_63 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1729 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MAD)
    return "madu\t%1,%2";
  else if (TARGET_MIPS5500)
    return "maddu\t%1,%2";
  else
    /* See comment in *macc.  */
    return "%[maccu\t%@,%1,%2%]";
}
}

static const char *
output_82 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1851 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "div.s\t%0,%1,%2\n\tmov.s\t%0,%0";
  else
    return "div.s\t%0,%1,%2";
}
}

static const char *
output_83 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1851 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "div.d\t%0,%1,%2\n\tmov.d\t%0,%0";
  else
    return "div.d\t%0,%1,%2";
}
}

static const char *
output_84 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1851 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "div.ps\t%0,%1,%2\n\tmov.ps\t%0,%0";
  else
    return "div.ps\t%0,%1,%2";
}
}

static const char *
output_85 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1869 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "recip.s\t%0,%2\n\tmov.s\t%0,%0";
  else
    return "recip.s\t%0,%2";
}
}

static const char *
output_86 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1869 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "recip.d\t%0,%2\n\tmov.d\t%0,%0";
  else
    return "recip.d\t%0,%2";
}
}

static const char *
output_87 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1869 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "recip.ps\t%0,%2\n\tmov.ps\t%0,%0";
  else
    return "recip.ps\t%0,%2";
}
}

static const char *
output_88 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1892 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_division ("div\t$0,%1,%2", operands); }
}

static const char *
output_89 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1892 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_division ("ddiv\t$0,%1,%2", operands); }
}

static const char *
output_90 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1904 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_division ("divu\t$0,%1,%2", operands); }
}

static const char *
output_91 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1904 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_division ("ddivu\t$0,%1,%2", operands); }
}

static const char *
output_92 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1922 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "sqrt.s\t%0,%1\n\tmov.s\t%0,%0";
  else
    return "sqrt.s\t%0,%1";
}
}

static const char *
output_93 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1922 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "sqrt.d\t%0,%1\n\tmov.d\t%0,%0";
  else
    return "sqrt.d\t%0,%1";
}
}

static const char *
output_94 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1922 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "sqrt.ps\t%0,%1\n\tmov.ps\t%0,%0";
  else
    return "sqrt.ps\t%0,%1";
}
}

static const char *
output_95 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1940 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.s\t%0,%2\n\tmov.s\t%0,%0";
  else
    return "rsqrt.s\t%0,%2";
}
}

static const char *
output_96 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1940 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.d\t%0,%2\n\tmov.d\t%0,%0";
  else
    return "rsqrt.d\t%0,%2";
}
}

static const char *
output_97 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1940 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.ps\t%0,%2\n\tmov.ps\t%0,%0";
  else
    return "rsqrt.ps\t%0,%2";
}
}

static const char *
output_98 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1958 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.s\t%0,%2\n\tmov.s\t%0,%0";
  else
    return "rsqrt.s\t%0,%2";
}
}

static const char *
output_99 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1958 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.d\t%0,%2\n\tmov.d\t%0,%0";
  else
    return "rsqrt.d\t%0,%2";
}
}

static const char *
output_100 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 1958 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_FIX_SB1)
    return "rsqrt.ps\t%0,%2\n\tmov.ps\t%0,%0";
  else
    return "rsqrt.ps\t%0,%2";
}
}

static const char *
output_106 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2020 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    return "neg\t%0,%1";
  else
    return "subu\t%0,%.,%1";
}
}

static const char *
output_111 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2053 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    return "not\t%0,%1";
  else
    return "nor\t%0,%.,%1";
}
}

static const char *
output_112 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2053 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (TARGET_MIPS16)
    return "not\t%0,%1";
  else
    return "nor\t%0,%.,%1";
}
}

static const char * const output_113[] = {
  "and\t%0,%1,%2",
  "andi\t%0,%1,%x2",
};

static const char * const output_114[] = {
  "and\t%0,%1,%2",
  "andi\t%0,%1,%x2",
};

static const char * const output_117[] = {
  "or\t%0,%1,%2",
  "ori\t%0,%1,%x2",
};

static const char * const output_118[] = {
  "or\t%0,%1,%2",
  "ori\t%0,%1,%x2",
};

static const char * const output_121[] = {
  "xor\t%0,%1,%2",
  "xori\t%0,%1,%x2",
};

static const char * const output_122[] = {
  "xor\t%0,%1,%2",
  "xori\t%0,%1,%x2",
};

static const char * const output_123[] = {
  "xor\t%0,%2",
  "cmpi\t%1,%2",
  "cmp\t%1,%2",
};

static const char * const output_124[] = {
  "xor\t%0,%2",
  "cmpi\t%1,%2",
  "cmp\t%1,%2",
};

static const char * const output_128[] = {
  "sll\t%0,%1,0",
  "sw\t%1,%0",
};

static const char * const output_129[] = {
  "sll\t%0,%1,0",
  "sh\t%1,%0",
};

static const char * const output_130[] = {
  "sll\t%0,%1,0",
  "sb\t%1,%0",
};

static const char * const output_138[] = {
  "#",
  "lwu\t%0,%1",
};

static const char *
output_139 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2361 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 0)
    return "#";

  operands[1] = gen_lowpart (SImode, operands[1]);
  return "lwu\t%0,%1";
}
}

static const char * const output_140[] = {
  "andi\t%0,%1,0x00ff",
  "lbu\t%0,%1",
};

static const char * const output_141[] = {
  "andi\t%0,%1,0x00ff",
  "lbu\t%0,%1",
};

static const char * const output_142[] = {
  "andi\t%0,%1,0xffff",
  "lhu\t%0,%1",
};

static const char * const output_143[] = {
  "andi\t%0,%1,0xffff",
  "lhu\t%0,%1",
};

static const char * const output_152[] = {
  "andi\t%0,%1,0x00ff",
  "lbu\t%0,%1",
};

static const char * const output_154[] = {
  "#",
  "lw\t%0,%1",
};

static const char * const output_155[] = {
  "seb\t%0",
  "lb\t%0,%1",
};

static const char * const output_156[] = {
  "seb\t%0",
  "lb\t%0,%1",
};

static const char * const output_157[] = {
  "seh\t%0",
  "lh\t%0,%1",
};

static const char * const output_158[] = {
  "seh\t%0",
  "lh\t%0,%1",
};

static const char * const output_159[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_160[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_161[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_162[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_163[] = {
  "seb\t%0,%1",
  "lb\t%0,%1",
};

static const char * const output_164[] = {
  "seb\t%0,%1",
  "lb\t%0,%1",
};

static const char * const output_165[] = {
  "seh\t%0,%1",
  "lh\t%0,%1",
};

static const char * const output_166[] = {
  "seh\t%0,%1",
  "lh\t%0,%1",
};

static const char *
output_170 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2589 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (set_nomacro)
    return ".set\tmacro\n\ttrunc.w.d %0,%1,%2\n\t.set\tnomacro";
  else
    return "trunc.w.d %0,%1,%2";
}
}

static const char *
output_172 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 2627 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (set_nomacro)
    return ".set\tmacro\n\ttrunc.w.s %0,%1,%2\n\t.set\tnomacro";
  else
    return "trunc.w.s %0,%1,%2";
}
}

static const char *
output_209 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3268 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_210 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3279 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_211 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3290 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_212 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3301 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_213 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3386 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_214 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3397 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_215 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3487 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char * const output_228[] = {
  "move\t%0,%1",
  "li\t%0,%1",
  "lhu\t%0,%1",
  "sh\t%z1,%0",
  "mfc1\t%0,%1",
  "mtc1\t%1,%0",
  "mov.s\t%0,%1",
  "mt%0\t%1",
};

static const char * const output_229[] = {
  "move\t%0,%1",
  "move\t%0,%1",
  "move\t%0,%1",
  "li\t%0,%1",
  "#",
  "lhu\t%0,%1",
  "sh\t%1,%0",
};

static const char * const output_230[] = {
  "move\t%0,%1",
  "li\t%0,%1",
  "lbu\t%0,%1",
  "sb\t%z1,%0",
  "mfc1\t%0,%1",
  "mtc1\t%1,%0",
  "mov.s\t%0,%1",
  "mt%0\t%1",
};

static const char * const output_231[] = {
  "move\t%0,%1",
  "move\t%0,%1",
  "move\t%0,%1",
  "li\t%0,%1",
  "#",
  "lbu\t%0,%1",
  "sb\t%1,%0",
};

static const char *
output_232 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3764 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_233 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3775 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_234 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3786 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_235 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3809 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_236 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3820 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_237 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3831 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_238 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3842 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_239 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3902 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_move (operands[0], operands[1]); }
}

static const char *
output_242 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3940 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (REGNO (operands[1]) == HI_REGNUM)
    return "macchi\t%0,%.,%.";
  else
    return "macc\t%0,%.,%.";
}
}

static const char *
output_243 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3940 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (REGNO (operands[1]) == HI_REGNUM)
    return "dmacchi\t%0,%.,%.";
  else
    return "dmacc\t%0,%.,%.";
}
}

static const char *
output_244 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3959 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[0] = mips_subword (operands[0], 0);
  return mips_output_move (operands[0], operands[1]);
}
}

static const char *
output_245 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3974 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[0] = mips_subword (operands[0], 1);
  return mips_output_move (operands[0], operands[1]);
}
}

static const char *
output_246 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 3988 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = mips_subword (operands[1], 1);
  return mips_output_move (operands[0], operands[1]);
}
}

static const char *
output_250 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4047 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (set_nomacro && which_alternative == 1)
    return ".set\tmacro\n\t.cprestore\t%0\n\t.set\tnomacro";
  else
    return ".cprestore\t%0";
}
}

static const char *
output_251 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return "sll\t%0,%1,%2";
}
}

static const char *
output_252 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return "sra\t%0,%1,%2";
}
}

static const char *
output_253 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return "srl\t%0,%1,%2";
}
}

static const char *
output_254 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "dsll\t%0,%1,%2";
}
}

static const char *
output_255 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "dsra\t%0,%1,%2";
}
}

static const char *
output_256 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4117 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "dsrl\t%0,%1,%2";
}
}

static const char *
output_257 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4133 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sll\t%0,%1,%2";
}
}

static const char *
output_258 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4133 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sra\t%0,%1,%2";
}
}

static const char *
output_259 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4133 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "srl\t%0,%1,%2";
}
}

static const char *
output_260 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4147 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 0)
    return "sll\t%0,%2";

  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "sll\t%0,%1,%2";
}
}

static const char *
output_261 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4147 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 0)
    return "sra\t%0,%2";

  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "sra\t%0,%1,%2";
}
}

static const char *
output_262 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4147 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 0)
    return "srl\t%0,%2";

  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "srl\t%0,%1,%2";
}
}

static const char *
output_263 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4169 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (which_alternative == 0)
    return "dsll\t%0,%2";

  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x3f);
  return "dsll\t%0,%1,%2";
}
}

static const char *
output_264 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4189 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x3f);

  return "dsra\t%0,%2";
}
}

static const char *
output_265 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4208 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x3f);

  return "dsrl\t%0,%2";
}
}

static const char *
output_267 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4264 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    gcc_assert (INTVAL (operands[2]) >= 0
		&& INTVAL (operands[2]) < GET_MODE_BITSIZE (SImode));

  return "ror\t%0,%1,%2";
}
}

static const char *
output_268 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4264 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    gcc_assert (INTVAL (operands[2]) >= 0
		&& INTVAL (operands[2]) < GET_MODE_BITSIZE (DImode));

  return "dror\t%0,%1,%2";
}
}

static const char *
output_269 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4336 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%F0", "%Z2%1"),
					 MIPS_BRANCH ("b%W0", "%Z2%1"));
}
}

static const char *
output_270 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4353 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%W0", "%Z2%1"),
					 MIPS_BRANCH ("b%F0", "%Z2%1"));
}
}

static const char *
output_271 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4372 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_order_conditional_branch (insn, operands, false); }
}

static const char *
output_272 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4372 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_order_conditional_branch (insn, operands, false); }
}

static const char *
output_273 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4385 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_order_conditional_branch (insn, operands, true); }
}

static const char *
output_274 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4385 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return mips_output_order_conditional_branch (insn, operands, true); }
}

static const char *
output_275 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4400 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%C0", "%2,%z3,%1"),
					 MIPS_BRANCH ("b%N0", "%2,%z3,%1"));
}
}

static const char *
output_276 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4400 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%C0", "%2,%z3,%1"),
					 MIPS_BRANCH ("b%N0", "%2,%z3,%1"));
}
}

static const char *
output_277 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4417 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%N0", "%2,%z3,%1"),
					 MIPS_BRANCH ("b%C0", "%2,%z3,%1"));
}
}

static const char *
output_278 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4417 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%N0", "%2,%z3,%1"),
					 MIPS_BRANCH ("b%C0", "%2,%z3,%1"));
}
}

static const char *
output_279 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4436 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (operands[2] != pc_rtx)
    {
      if (which_alternative == 0)
	return "b%C0z\t%1,%2";
      else
	return "bt%C0z\t%2";
    }
  else
    {
      if (which_alternative == 0)
	return "b%N0z\t%1,%3";
      else
	return "bt%N0z\t%3";
    }
}
}

static const char *
output_280 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4436 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (operands[2] != pc_rtx)
    {
      if (which_alternative == 0)
	return "b%C0z\t%1,%2";
      else
	return "bt%C0z\t%2";
    }
  else
    {
      if (which_alternative == 0)
	return "b%N0z\t%1,%3";
      else
	return "bt%N0z\t%3";
    }
}
}

static const char *
output_297 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4609 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_298 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4609 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%0,%1,%2";
}
}

static const char *
output_299 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4621 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%1,%2";
}
}

static const char *
output_300 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4621 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt\t%1,%2";
}
}

static const char *
output_311 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4714 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_312 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4714 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%0,%1,%2";
}
}

static const char *
output_313 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4726 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%1,%2";
}
}

static const char *
output_314 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4726 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "sltu\t%1,%2";
}
}

static const char *
output_337 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 4774 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  if (flag_pic)
    {
      if (get_attr_length (insn) <= 8)
	return "%*b\t%l0%/";
      else
	{
	  output_asm_insn (mips_output_load_label (), operands);
	  return "%*jr\t%@%/%]";
	}
    }
  else
    return "%*j\t%l0%/";
}
}

static const char *
output_351 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5092 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("j", operands, 0); }
}

static const char *
output_352 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5112 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("j", operands, 1); }
}

static const char *
output_353 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5123 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("j", operands, 1); }
}

static const char *
output_354 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5179 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return TARGET_SPLIT_CALLS ? "#" : MIPS_CALL ("jal", operands, 0); }
}

static const char *
output_355 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5197 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("jal", operands, 0); }
}

static const char *
output_356 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5219 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return TARGET_SPLIT_CALLS ? "#" : MIPS_CALL ("jal", operands, 1); }
}

static const char *
output_357 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5239 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("jal", operands, 1); }
}

static const char *
output_358 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5252 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return TARGET_SPLIT_CALLS ? "#" : MIPS_CALL ("jal", operands, 1); }
}

static const char *
output_359 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5275 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{ return MIPS_CALL ("jal", operands, 1); }
}

static const char *
output_360 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5315 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[1] = mips_prefetch_cookie (operands[1], operands[2]);
  return "pref\t%1,%a0";
}
}

static const char *
output_361 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5327 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = mips_prefetch_cookie (operands[2], operands[3]);
  return "prefx\t%2,%1(%0)";
}
}

static const char *
output_362 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5327 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  operands[2] = mips_prefetch_cookie (operands[2], operands[3]);
  return "prefx\t%2,%1(%0)";
}
}

static const char *
output_364 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5344 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
    if (set_noreorder)
      return "nop";
    else
      return "#nop";
  }
}

static const char * const output_365[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_366[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_367[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_368[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_369[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_370[] = {
  "mov%T4\t%0,%z2,%1",
  "mov%t4\t%0,%z3,%1",
};

static const char * const output_371[] = {
  "mov%T4.s\t%0,%2,%1",
  "mov%t4.s\t%0,%3,%1",
};

static const char * const output_372[] = {
  "mov%T4.d\t%0,%2,%1",
  "mov%t4.d\t%0,%3,%1",
};

static const char * const output_373[] = {
  "mov%T4.s\t%0,%2,%1",
  "mov%t4.s\t%0,%3,%1",
};

static const char * const output_374[] = {
  "mov%T4.d\t%0,%2,%1",
  "mov%t4.d\t%0,%3,%1",
};

static const char * const output_375[] = {
  "mov%T4.s\t%0,%2,%1",
  "mov%t4.s\t%0,%3,%1",
};

static const char * const output_376[] = {
  "mov%T4.d\t%0,%2,%1",
  "mov%t4.d\t%0,%3,%1",
};

static const char *
output_377 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  assemble_integer (operands[0], INTVAL (operands[1]),
		    BITS_PER_UNIT * INTVAL (operands[1]), 1);
  return "";
}
}

static const char *
output_378 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 5434 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
{
  REAL_VALUE_TYPE d;

  gcc_assert (GET_CODE (operands[0]) == CONST_DOUBLE);
  REAL_VALUE_FROM_CONST_DOUBLE (d, operands[0]);
  assemble_real (d, GET_MODE (operands[0]),
		 GET_MODE_BITSIZE (GET_MODE (operands[0])));
  return "";
}
}

static const char * const output_382[] = {
  "mov%T4.ps\t%0,%2,%1",
  "mov%t4.ps\t%0,%3,%1",
};

static const char * const output_383[] = {
  "mov%T4.ps\t%0,%2,%1",
  "mov%t4.ps\t%0,%3,%1",
};

static const char * const output_384[] = {
  "movt.ps\t%0,%1,%3",
  "movf.ps\t%0,%2,%3",
};

static const char *
output_389 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 143 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  if (BYTES_BIG_ENDIAN)
    return "cvt.ps.s\t%0,%1,%2";
  else
    return "cvt.ps.s\t%0,%2,%1";
}
}

static const char *
output_390 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 162 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  if (INTVAL (operands[2]) == !BYTES_BIG_ENDIAN)
    return "cvt.s.pu\t%0,%1";
  else
    return "cvt.s.pl\t%0,%1";
}
}

static const char *
output_418 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 509 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  operands[2]
    = gen_rtx_REG (CCmode, REGNO (operands[2]) + INTVAL (operands[3]));
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%F0", "%2,%1"),
					 MIPS_BRANCH ("b%W0", "%2,%1"));
}
}

static const char *
output_419 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 531 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
{
  operands[2]
    = gen_rtx_REG (CCmode, REGNO (operands[2]) + INTVAL (operands[3]));
  return mips_output_conditional_branch (insn, operands,
					 MIPS_BRANCH ("b%W0", "%2,%1"),
					 MIPS_BRANCH ("b%F0", "%2,%1"));
}
}

static const char *
output_462 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 306 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
	  & ~(unsigned HOST_WIDE_INT) 0xf)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
      return "shll.ph\t%0,%1,%2";
    }
  return "shllv.ph\t%0,%1,%2";
}
}

static const char *
output_463 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 306 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
	  & ~(unsigned HOST_WIDE_INT) 0x7)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
      return "shll.qb\t%0,%1,%2";
    }
  return "shllv.qb\t%0,%1,%2";
}
}

static const char *
output_464 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 328 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
          & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "shll_s.w\t%0,%1,%2";
    }
  return "shllv_s.w\t%0,%1,%2";
}
}

static const char *
output_465 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 328 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
          & ~(unsigned HOST_WIDE_INT) 0xf)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
      return "shll_s.ph\t%0,%1,%2";
    }
  return "shllv_s.ph\t%0,%1,%2";
}
}

static const char *
output_466 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 348 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x7)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
      return "shrl.qb\t%0,%1,%2";
    }
  return "shrlv.qb\t%0,%1,%2";
}
}

static const char *
output_467 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 367 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0xf)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
      return "shra.ph\t%0,%1,%2";
    }
  return "shrav.ph\t%0,%1,%2";
}
}

static const char *
output_468 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 385 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
	  & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "shra_r.w\t%0,%1,%2";
    }
  return "shrav_r.w\t%0,%1,%2";
}
}

static const char *
output_469 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 385 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2])
	  & ~(unsigned HOST_WIDE_INT) 0xf)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
      return "shra_r.ph\t%0,%1,%2";
    }
  return "shrav_r.ph\t%0,%1,%2";
}
}

static const char *
output_490 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 690 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[1]) & ~(unsigned HOST_WIDE_INT) 0xff)
	operands[1] = GEN_INT (INTVAL (operands[1]) & 0xff);
      return "repl.qb\t%0,%1";
    }
  return "replv.qb\t%0,%1";
}
}

static const char * const output_491[] = {
  "repl.ph\t%0,%1",
  "replv.ph\t%0,%1",
};

static const char *
output_504 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 812 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extr.w\t%0,%q1,%2";
    }
  return "extrv.w\t%0,%q1,%2";
}
}

static const char *
output_505 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 833 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extr_r.w\t%0,%q1,%2";
    }
  return "extrv_r.w\t%0,%q1,%2";
}
}

static const char *
output_506 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 854 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extr_rs.w\t%0,%q1,%2";
    }
  return "extrv_rs.w\t%0,%q1,%2";
}
}

static const char *
output_507 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 876 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extr_s.h\t%0,%q1,%2";
    }
  return "extrv_s.h\t%0,%q1,%2";
}
}

static const char *
output_508 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 899 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extp\t%0,%q1,%2";
    }
  return "extpv\t%0,%q1,%2";
}
}

static const char *
output_509 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 924 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) & ~(unsigned HOST_WIDE_INT) 0x1f)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "extpdp\t%0,%q1,%2";
    }
  return "extpdpv\t%0,%q1,%2";
}
}

static const char *
output_510 (rtx *operands ATTRIBUTE_UNUSED, rtx insn ATTRIBUTE_UNUSED)
{
#line 943 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
{
  if (which_alternative == 0)
    {
      if (INTVAL (operands[2]) < -32 || INTVAL (operands[2]) > 31)
	operands[2] = GEN_INT (INTVAL (operands[2]) & 0x3f);
      return "shilo\t%q0,%2";
    }
  return "shilov\t%q0,%2";
}
}



static const struct insn_operand_data operand_data[] = 
{
  {
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    trap_comparison_operator,
    "",
    SImode,
    0,
    0
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    SImode,
    0,
    1
  },
  {
    trap_comparison_operator,
    "",
    DImode,
    0,
    0
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "d,Q",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "d,Q",
    DImode,
    0,
    1
  },
  {
    const_arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    const_arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "Q,O,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,d,d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "Q,O,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "d,Q",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "Q,O,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=l,X",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "=l",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=l",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l,*d,*d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,l,*d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,3,l",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,&d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,l",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,3",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,1",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=d,d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l,*d,*d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,l,*d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d,d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,1,l",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,X,&d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=l,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h,h",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,l",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=x",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=l",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "=h",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "=d",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=l",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=h",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=x",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=h",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=l",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=h,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=l,l",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "=X,h",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=h",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=l",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "+l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=h",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    const_1_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    const_1_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    const_1_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=h",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=l",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=h",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "%d,d",
    SImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "d,K",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "%d,d",
    DImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "d,K",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "%0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "%0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,t,t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "%0,d,d",
    SImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "d,K,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,t,t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "%0,d,d",
    DImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "d,K,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    const_arith_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,W",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,o",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "d,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    HImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "0,m",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=d",
    DFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    scratch_operand,
    "=d",
    SFmode,
    0,
    0
  },
  {
    register_operand,
    "=f",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+d",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "+d",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    BLKmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    BLKmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    BLKmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    BLKmode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    BLKmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "=m",
    BLKmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    BLKmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    memory_operand,
    "+m",
    BLKmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    general_symbolic_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&d",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    local_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    local_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    stack_operand,
    "=m",
    SImode,
    0,
    1
  },
  {
    stack_operand,
    "=m",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,d,m,*a,*d,*B*C*D,*B*C*D,*d,*m",
    DImode,
    0,
    1
  },
  {
    move_operand,
    "d,i,m,d,*J*d,*a,*d,*m,*B*C*D,*B*C*D",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,d,d,m,*d",
    DImode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,K,N,m,d,*x",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,e,d,m,*f,*f,*f,*d,*m,*x,*B*C*D,*B*C*D,*d,*m",
    DImode,
    0,
    1
  },
  {
    move_operand,
    "d,U,T,m,dJ,*f,*d*J,*m,*f,*f,*J*d,*d,*m,*B*C*D,*B*C*D",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,d,d,d,m",
    DImode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,K,N,U,m,d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,e,d,m,*f,*f,*f,*d,*m,*d,*z,*a,*d,*B*C*D,*B*C*D,*d,*m",
    SImode,
    0,
    1
  },
  {
    move_operand,
    "d,U,T,m,dJ,*f,*d*J,*m,*f,*f,*z,*d,*J*d,*A,*d,*m,*B*C*D,*B*C*D",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,d,d,d,m",
    SImode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,K,N,U,m,d",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,*d,*d,*m,*d,*f,*f,*f,*m",
    CCmode,
    0,
    1
  },
  {
    general_operand,
    "z,*d,*m,*d,*f,*d,*f,*m,*f",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,d,m,*d,*f,*f,*x",
    HImode,
    0,
    1
  },
  {
    move_operand,
    "d,I,m,dJ,*f,*d,*f,*d",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,d,d,m",
    HImode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,K,N,m,d",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,d,m,*d,*f,*f,*x",
    QImode,
    0,
    1
  },
  {
    move_operand,
    "d,I,m,dJ,*f,*d,*f,*d",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,d,d,m",
    QImode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,K,N,m,d",
    QImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*d,*d,*d,*m",
    SFmode,
    0,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*d,*f,*G*d,*m,*d",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,m",
    SFmode,
    0,
    1
  },
  {
    move_operand,
    "Gd,m,d",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,m",
    SFmode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,m,d",
    SFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*d,*d,*d,*m",
    DFmode,
    0,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*d,*f,*d*G,*m,*d",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,d,m,d,f,f",
    DFmode,
    0,
    1
  },
  {
    move_operand,
    "dG,m,dG,f,d,f",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,y,d,d,m",
    DFmode,
    0,
    1
  },
  {
    move_operand,
    "d,d,y,m,d",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*d,*d,*d,*m",
    V2SFmode,
    0,
    1
  },
  {
    move_operand,
    "f,YG,m,f,YG,*d,*f,*d*YG,*m,*d",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "h,l",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "l,h",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "h,l",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "l,h",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    general_operand,
    "dJ,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "=d,m",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,f",
    DFmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "I,i",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "d,I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "d,I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "d,I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "m",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "z",
    CCmode,
    0,
    1
  },
  {
    order_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    order_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "d,t",
    SImode,
    0,
    1
  },
  {
    pc_or_label_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    pc_or_label_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "d,t",
    DImode,
    0,
    1
  },
  {
    pc_or_label_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    pc_or_label_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "dI",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=t,t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "d,I",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=t,t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "d,I",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    sle_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    sle_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    sle_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    sle_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    sleu_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    sleu_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    sleu_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=t",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    sleu_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    pmode_register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "=&d",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=c",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=c",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "r",
    DImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    call_insn_operand,
    "j,S",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df,df",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "j,S",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df,df",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "c,S",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "cS",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "cS",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df,df",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "c,S",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df,df",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "cS",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=df",
    VOIDmode,
    0,
    1
  },
  {
    address_operand,
    "p",
    QImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "n",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    SImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    DImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    SImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    DImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "z,z",
    CCmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    SImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    CCmode,
    0,
    0
  },
  {
    register_operand,
    "=d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "z,z",
    CCmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "dJ,0",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "0,dJ",
    DImode,
    0,
    1
  },
  {
    equality_operator,
    "",
    CCmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "z,z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    SFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    CCmode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "z,z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    DFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    CCmode,
    0,
    0
  },
  {
    consttable_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=v",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=v",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "=f,f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    V2SFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    V2SFmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=f,f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f,0",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "0,f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "z,z",
    CCV2mode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    const_0_or_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    SFmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    DFmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCV4mode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=z",
    CCV2mode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "f",
    V2SFmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "z",
    CCV4mode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "z",
    CCV2mode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    equality_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "z",
    CCV2mode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    V2HImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    V4QImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d,d",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    scratch_operand,
    "=x",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V2HImode,
    0,
    1
  },
  {
    register_operand,
    "=a",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "0",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    V4QImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    V2HImode,
    0,
    1
  },
  {
    reg_imm10_operand,
    "YB,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    V4QImode,
    0,
    1
  },
  {
    register_operand,
    "=d,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "a,a",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=a,a",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "0,0",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "I,d",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "d",
    SImode,
    0,
    1
  },
  {
    const_uimm6_operand,
    "YA",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "=d",
    SImode,
    0,
    1
  },
  {
    const_uimm6_operand,
    "YA",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "I",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    0
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    macc_msac_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    macc_msac_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "d",
    SImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    macc_msac_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    reg_or_1_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    reg_or_1_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    reg_or_1_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    uns_arith_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    memory_operand,
    "",
    QImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_symbolic_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "d",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    general_symbolic_operand,
    "",
    DImode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    DImode,
    0,
    0
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    global_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    local_got_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    local_got_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    splittable_const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    splittable_const_int_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    splittable_symbolic_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    splittable_symbolic_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    0,
    "",
    DImode,
    0,
    1
  },
  {
    0,
    "",
    DImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    fcc_reload_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    general_operand,
    "",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "=&f",
    TFmode,
    0,
    1
  },
  {
    fcc_reload_operand,
    "=z",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "",
    CCmode,
    0,
    1
  },
  {
    register_operand,
    "=&f",
    TFmode,
    0,
    1
  },
  {
    0,
    "",
    HImode,
    0,
    1
  },
  {
    0,
    "",
    HImode,
    0,
    1
  },
  {
    register_operand,
    "",
    HImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    0,
    "",
    QImode,
    0,
    1
  },
  {
    register_operand,
    "",
    QImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    0,
    "",
    SFmode,
    0,
    1
  },
  {
    0,
    "",
    SFmode,
    0,
    1
  },
  {
    0,
    "",
    DFmode,
    0,
    1
  },
  {
    0,
    "",
    DFmode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DImode,
    0,
    1
  },
  {
    move_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonimmediate_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    move_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    V2SFmode,
    0,
    1
  },
  {
    0,
    "",
    V2SFmode,
    0,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    1
  },
  {
    general_operand,
    "",
    BLKmode,
    0,
    1
  },
  {
    0,
    "",
    SImode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    arith_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    memory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    immediate_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    nonmemory_operand,
    "",
    DImode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    general_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    scratch_operand,
    "",
    VOIDmode,
    0,
    0
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    call_insn_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "",
    SImode,
    0,
    1
  },
  {
    register_operand,
    "",
    DImode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "",
    DImode,
    0,
    1
  },
  {
    reg_or_0_operand,
    "",
    DImode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    DFmode,
    0,
    1
  },
  {
    small_data_pattern,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    comparison_operator,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    0,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    const_0_or_1_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    CCV4mode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    const_int_operand,
    "",
    VOIDmode,
    0,
    1
  },
  {
    0,
    "",
    CCV2mode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    0,
    "",
    VOIDmode,
    0,
    0
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
  {
    register_operand,
    "",
    V2SFmode,
    0,
    1
  },
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data insn_data[] = 
{
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:605 */
  {
    "trap",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_0 },
#else
    { 0, 0, output_0 },
#endif
    (insn_gen_fn) gen_trap,
    &operand_data[0],
    0,
    0,
    0,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:634 */
  {
    "*conditional_trapsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "t%C0\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[1],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:634 */
  {
    "*conditional_trapdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "t%C0\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[4],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
  {
    "addsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addsf3,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
  {
    "adddf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_adddf3,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:651 */
  {
    "addv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "add.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addv2sf3,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:666 */
  {
    "*addsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_6 },
#else
    { 0, output_6, 0 },
#endif
    0,
    &operand_data[16],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:666 */
  {
    "*adddi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_7 },
#else
    { 0, output_7, 0 },
#endif
    0,
    &operand_data[19],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:681 */
  {
    "*addsi3_sp1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addiu\t%$,%$,%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[22],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:681 */
  {
    "*adddi3_sp1",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "daddiu\t%$,%$,%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[23],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:693 */
  {
    "*addsi3_sp2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addiu\t%0,%$,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[24],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:693 */
  {
    "*adddi3_sp2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "daddiu\t%0,%$,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[26],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:705 */
  {
    "*addsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_12 },
#else
    { 0, output_12, 0 },
#endif
    0,
    &operand_data[28],
    3,
    0,
    3,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:705 */
  {
    "*adddi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_13 },
#else
    { 0, output_13, 0 },
#endif
    0,
    &operand_data[31],
    3,
    0,
    3,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:854 */
  {
    "*addsi3_extended",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_14 },
#else
    { 0, output_14, 0 },
#endif
    0,
    &operand_data[34],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:868 */
  {
    "*addsi3_extended_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[37],
    3,
    0,
    3,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
  {
    "subsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subsf3,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
  {
    "subdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subdf3,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:890 */
  {
    "subv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subv2sf3,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:899 */
  {
    "subsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subu\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subsi3,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:899 */
  {
    "subdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dsubu\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subdi3,
    &operand_data[43],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:908 */
  {
    "*subsi3_extended",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subu\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[46],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:933 */
  {
    "*mulsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:933 */
  {
    "*muldf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:946 */
  {
    "*mulsf3_r4300",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul.s\t%0,%1,%2\n\tnop",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:946 */
  {
    "*muldf3_r4300",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul.d\t%0,%1,%2\n\tnop",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:956 */
  {
    "mulv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mulv2sf3,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1027 */
  {
    "mulsi3_mult3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_27 },
#else
    { 0, 0, output_27 },
#endif
    (insn_gen_fn) gen_mulsi3_mult3,
    &operand_data[49],
    5,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1052 */
  {
    "muldi3_mult3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dmult\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_muldi3_mult3,
    &operand_data[54],
    5,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1089 */
  {
    "mulsi3_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mulsi3_internal,
    &operand_data[59],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1089 */
  {
    "muldi3_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dmult\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_muldi3_internal,
    &operand_data[63],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1099 */
  {
    "mulsi3_r4000",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%1,%2\n\tmflo\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mulsi3_r4000,
    &operand_data[67],
    5,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1099 */
  {
    "muldi3_r4000",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dmult\t%1,%2\n\tmflo\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_muldi3_r4000,
    &operand_data[54],
    5,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1154 */
  {
    "*mul_acc_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_33 },
#else
    { 0, 0, output_33 },
#endif
    0,
    &operand_data[72],
    7,
    0,
    3,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1217 */
  {
    "*macc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_34 },
#else
    { 0, 0, output_34 },
#endif
    0,
    &operand_data[79],
    6,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1239 */
  {
    "*msac",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_35 },
#else
    { 0, 0, output_35 },
#endif
    0,
    &operand_data[85],
    6,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1259 */
  {
    "*msac_using_macc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[85],
    7,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1285 */
  {
    "*macc2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "macc\t%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[92],
    5,
    4,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1300 */
  {
    "*msac2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "msac\t%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[92],
    5,
    4,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1415 */
  {
    "*mul_sub_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_39 },
#else
    { 0, output_39, 0 },
#endif
    0,
    &operand_data[97],
    7,
    0,
    3,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1472 */
  {
    "*muls",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_40 },
#else
    { 0, output_40, 0 },
#endif
    0,
    &operand_data[104],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1509 */
  {
    "mulsidi3_32bit_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mulsidi3_32bit_internal,
    &operand_data[109],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1509 */
  {
    "umulsidi3_32bit_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "multu\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_umulsidi3_32bit_internal,
    &operand_data[109],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1518 */
  {
    "mulsidi3_32bit_r4000",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%1,%2\n\tmflo\t%L0;mfhi\t%M0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mulsidi3_32bit_r4000,
    &operand_data[112],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1518 */
  {
    "umulsidi3_32bit_r4000",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "multu\t%1,%2\n\tmflo\t%L0;mfhi\t%M0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_umulsidi3_32bit_r4000,
    &operand_data[112],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
  {
    "*mulsidi3_64bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[116],
    6,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
  {
    "*umulsidi3_64bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[116],
    6,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1576 */
  {
    "*mulsidi3_64bit_parts",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[122],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1576 */
  {
    "*umulsidi3_64bit_parts",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "multu\t%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[122],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1592 */
  {
    "*muls_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "muls\t$0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[109],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1592 */
  {
    "*mulsu_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulsu\t$0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[109],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1603 */
  {
    "*msac_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_51 },
#else
    { 0, 0, output_51 },
#endif
    0,
    &operand_data[126],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1603 */
  {
    "*msacu_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_52 },
#else
    { 0, 0, output_52 },
#endif
    0,
    &operand_data[126],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1641 */
  {
    "smulsi3_highpart_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mult\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_smulsi3_highpart_internal,
    &operand_data[130],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1641 */
  {
    "umulsi3_highpart_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "multu\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_umulsi3_highpart_internal,
    &operand_data[130],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1654 */
  {
    "smulsi3_highpart_mulhi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_55 },
#else
    { 0, output_55, 0 },
#endif
    (insn_gen_fn) gen_smulsi3_highpart_mulhi_internal,
    &operand_data[134],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1654 */
  {
    "umulsi3_highpart_mulhi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_56 },
#else
    { 0, output_56, 0 },
#endif
    (insn_gen_fn) gen_umulsi3_highpart_mulhi_internal,
    &operand_data[134],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1671 */
  {
    "*smulsi3_highpart_neg_mulhi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_57 },
#else
    { 0, output_57, 0 },
#endif
    0,
    &operand_data[134],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1671 */
  {
    "*umulsi3_highpart_neg_mulhi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_58 },
#else
    { 0, output_58, 0 },
#endif
    0,
    &operand_data[134],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1692 */
  {
    "smuldi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dmult\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_smuldi3_highpart,
    &operand_data[139],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1692 */
  {
    "umuldi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dmultu\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_umuldi3_highpart,
    &operand_data[139],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1710 */
  {
    "madsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mad\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_madsi,
    &operand_data[143],
    4,
    1,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1721 */
  {
    "*smul_acc_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_62 },
#else
    { 0, 0, output_62 },
#endif
    0,
    &operand_data[126],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1721 */
  {
    "*umul_acc_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_63 },
#else
    { 0, 0, output_63 },
#endif
    0,
    &operand_data[126],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1743 */
  {
    "*maddsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "madd.s\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1743 */
  {
    "*madddf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "madd.d\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1743 */
  {
    "*maddv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "madd.ps\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1753 */
  {
    "*msubsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "msub.s\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1753 */
  {
    "*msubdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "msub.d\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1753 */
  {
    "*msubv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "msub.ps\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1763 */
  {
    "*nmaddsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.s\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1763 */
  {
    "*nmadddf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.d\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1763 */
  {
    "*nmaddv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.ps\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1776 */
  {
    "*nmaddsf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.s\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1776 */
  {
    "*nmadddf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.d\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1776 */
  {
    "*nmaddv2sf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmadd.ps\t%0,%3,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1789 */
  {
    "*nmsubsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1789 */
  {
    "*nmsubdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1789 */
  {
    "*nmsubv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.ps\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1802 */
  {
    "*nmsubsf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[147],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1802 */
  {
    "*nmsubdf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[151],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1802 */
  {
    "*nmsubv2sf_fastmath",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nmsub.ps\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[155],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1846 */
  {
    "*divsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_82 },
#else
    { 0, 0, output_82 },
#endif
    0,
    &operand_data[7],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1846 */
  {
    "*divdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_83 },
#else
    { 0, 0, output_83 },
#endif
    0,
    &operand_data[10],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1846 */
  {
    "*divv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_84 },
#else
    { 0, 0, output_84 },
#endif
    0,
    &operand_data[13],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1864 */
  {
    "*recipsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_85 },
#else
    { 0, 0, output_85 },
#endif
    0,
    &operand_data[159],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1864 */
  {
    "*recipdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_86 },
#else
    { 0, 0, output_86 },
#endif
    0,
    &operand_data[162],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1864 */
  {
    "*recipv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_87 },
#else
    { 0, 0, output_87 },
#endif
    0,
    &operand_data[165],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1884 */
  {
    "divmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_88 },
#else
    { 0, 0, output_88 },
#endif
    (insn_gen_fn) gen_divmodsi4,
    &operand_data[168],
    4,
    2,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1884 */
  {
    "divmoddi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_89 },
#else
    { 0, 0, output_89 },
#endif
    (insn_gen_fn) gen_divmoddi4,
    &operand_data[172],
    4,
    2,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1896 */
  {
    "udivmodsi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_90 },
#else
    { 0, 0, output_90 },
#endif
    (insn_gen_fn) gen_udivmodsi4,
    &operand_data[168],
    4,
    2,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1896 */
  {
    "udivmoddi4",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_91 },
#else
    { 0, 0, output_91 },
#endif
    (insn_gen_fn) gen_udivmoddi4,
    &operand_data[172],
    4,
    2,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
  {
    "sqrtsf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_92 },
#else
    { 0, 0, output_92 },
#endif
    (insn_gen_fn) gen_sqrtsf2,
    &operand_data[7],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
  {
    "sqrtdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_93 },
#else
    { 0, 0, output_93 },
#endif
    (insn_gen_fn) gen_sqrtdf2,
    &operand_data[10],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1918 */
  {
    "sqrtv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_94 },
#else
    { 0, 0, output_94 },
#endif
    (insn_gen_fn) gen_sqrtv2sf2,
    &operand_data[13],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1935 */
  {
    "*rsqrtsfa",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_95 },
#else
    { 0, 0, output_95 },
#endif
    0,
    &operand_data[159],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1935 */
  {
    "*rsqrtdfa",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_96 },
#else
    { 0, 0, output_96 },
#endif
    0,
    &operand_data[162],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1935 */
  {
    "*rsqrtv2sfa",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_97 },
#else
    { 0, 0, output_97 },
#endif
    0,
    &operand_data[165],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1953 */
  {
    "*rsqrtsfb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_98 },
#else
    { 0, 0, output_98 },
#endif
    0,
    &operand_data[159],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1953 */
  {
    "*rsqrtdfb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_99 },
#else
    { 0, 0, output_99 },
#endif
    0,
    &operand_data[162],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1953 */
  {
    "*rsqrtv2sfb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_100 },
#else
    { 0, 0, output_100 },
#endif
    0,
    &operand_data[165],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
  {
    "abssf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "abs.s\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_abssf2,
    &operand_data[7],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
  {
    "absdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "abs.d\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absdf2,
    &operand_data[10],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1985 */
  {
    "absv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "abs.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_absv2sf2,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2001 */
  {
    "clzsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "clz\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_clzsi2,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2001 */
  {
    "clzdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dclz\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_clzdi2,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2016 */
  {
    "negsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_106 },
#else
    { 0, 0, output_106 },
#endif
    (insn_gen_fn) gen_negsi2,
    &operand_data[40],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2029 */
  {
    "negdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dsubu\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_negdi2,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
  {
    "negsf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg.s\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_negsf2,
    &operand_data[7],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
  {
    "negdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg.d\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_negdf2,
    &operand_data[10],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2041 */
  {
    "negv2sf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_negv2sf2,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2049 */
  {
    "one_cmplsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_111 },
#else
    { 0, 0, output_111 },
#endif
    (insn_gen_fn) gen_one_cmplsi2,
    &operand_data[40],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2049 */
  {
    "one_cmpldi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_112 },
#else
    { 0, 0, output_112 },
#endif
    (insn_gen_fn) gen_one_cmpldi2,
    &operand_data[43],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2083 */
  {
    "*andsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_113 },
#else
    { 0, output_113, 0 },
#endif
    0,
    &operand_data[176],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2083 */
  {
    "*anddi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_114 },
#else
    { 0, output_114, 0 },
#endif
    0,
    &operand_data[179],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2094 */
  {
    "*andsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[182],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2094 */
  {
    "*anddi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "and\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[185],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2113 */
  {
    "*iorsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_117 },
#else
    { 0, output_117, 0 },
#endif
    0,
    &operand_data[176],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2113 */
  {
    "*iordi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_118 },
#else
    { 0, output_118, 0 },
#endif
    0,
    &operand_data[179],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2124 */
  {
    "*iorsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[182],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2124 */
  {
    "*iordi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "or\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[185],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2140 */
  {
    "*mips.md:2140",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_121 },
#else
    { 0, output_121, 0 },
#endif
    0,
    &operand_data[176],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2140 */
  {
    "*mips.md:2140",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_122 },
#else
    { 0, output_122, 0 },
#endif
    0,
    &operand_data[179],
    3,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2151 */
  {
    "*mips.md:2151",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_123 },
#else
    { 0, output_123, 0 },
#endif
    0,
    &operand_data[188],
    3,
    0,
    3,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2151 */
  {
    "*mips.md:2151",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_124 },
#else
    { 0, output_124, 0 },
#endif
    0,
    &operand_data[191],
    3,
    0,
    3,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2169 */
  {
    "*norsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nor\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2169 */
  {
    "*nordi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "nor\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2187 */
  {
    "truncdfsf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.s.d\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_truncdfsf2,
    &operand_data[194],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2209 */
  {
    "truncdisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_128 },
#else
    { 0, output_128, 0 },
#endif
    (insn_gen_fn) gen_truncdisi2,
    &operand_data[196],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2220 */
  {
    "truncdihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_129 },
#else
    { 0, output_129, 0 },
#endif
    (insn_gen_fn) gen_truncdihi2,
    &operand_data[198],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2231 */
  {
    "truncdiqi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_130 },
#else
    { 0, output_130, 0 },
#endif
    (insn_gen_fn) gen_truncdiqi2,
    &operand_data[200],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2244 */
  {
    "*mips.md:2244",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dsra\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2254 */
  {
    "*mips.md:2254",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dsra\t%0,%1,32",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2267 */
  {
    "*mips.md:2267",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2282 */
  {
    "*mips.md:2282",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2300 */
  {
    "*mips.md:2300",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andi\t%0,%1,0xffff",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2309 */
  {
    "*mips.md:2309",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andi\t%0,%1,0xff",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[202],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2318 */
  {
    "*mips.md:2318",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "andi\t%0,%1,0xff",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[205],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2336 */
  {
    "zero_extendsidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_138 },
#else
    { 0, output_138, 0 },
#endif
    (insn_gen_fn) gen_zero_extendsidi2,
    &operand_data[207],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2356 */
  {
    "*clear_upper32",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_139 },
#else
    { 0, 0, output_139 },
#endif
    0,
    &operand_data[209],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2394 */
  {
    "*zero_extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_140 },
#else
    { 0, output_140, 0 },
#endif
    0,
    &operand_data[211],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2394 */
  {
    "*zero_extendqidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_141 },
#else
    { 0, output_141, 0 },
#endif
    0,
    &operand_data[213],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2394 */
  {
    "*zero_extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_142 },
#else
    { 0, output_142, 0 },
#endif
    0,
    &operand_data[215],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2394 */
  {
    "*zero_extendhidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_143 },
#else
    { 0, output_143, 0 },
#endif
    0,
    &operand_data[217],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2405 */
  {
    "*zero_extendqisi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "zeb\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[219],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2405 */
  {
    "*zero_extendqidi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "zeb\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[221],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2405 */
  {
    "*zero_extendhisi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "zeh\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[223],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2405 */
  {
    "*zero_extendhidi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "zeh\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[225],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2413 */
  {
    "*zero_extendqisi2_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[227],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2413 */
  {
    "*zero_extendqidi2_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[229],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2413 */
  {
    "*zero_extendhisi2_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[231],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2413 */
  {
    "*zero_extendhidi2_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[233],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2434 */
  {
    "*zero_extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_152 },
#else
    { 0, output_152, 0 },
#endif
    0,
    &operand_data[235],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2444 */
  {
    "*zero_extendqihi2_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[237],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2470 */
  {
    "extendsidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_154 },
#else
    { 0, output_154, 0 },
#endif
    (insn_gen_fn) gen_extendsidi2,
    &operand_data[239],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2491 */
  {
    "*extendqisi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_155 },
#else
    { 0, output_155, 0 },
#endif
    0,
    &operand_data[241],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2491 */
  {
    "*extendqidi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_156 },
#else
    { 0, output_156, 0 },
#endif
    0,
    &operand_data[243],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2491 */
  {
    "*extendhisi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_157 },
#else
    { 0, output_157, 0 },
#endif
    0,
    &operand_data[245],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2491 */
  {
    "*extendhidi2_mips16e",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_158 },
#else
    { 0, output_158, 0 },
#endif
    0,
    &operand_data[247],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "*extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_159 },
#else
    { 0, output_159, 0 },
#endif
    0,
    &operand_data[211],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "*extendqidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_160 },
#else
    { 0, output_160, 0 },
#endif
    0,
    &operand_data[213],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "*extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_161 },
#else
    { 0, output_161, 0 },
#endif
    0,
    &operand_data[215],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "*extendhidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_162 },
#else
    { 0, output_162, 0 },
#endif
    0,
    &operand_data[217],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2521 */
  {
    "*extendqisi2_seb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_163 },
#else
    { 0, output_163, 0 },
#endif
    0,
    &operand_data[211],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2521 */
  {
    "*extendqidi2_seb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_164 },
#else
    { 0, output_164, 0 },
#endif
    0,
    &operand_data[213],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2521 */
  {
    "*extendhisi2_seh",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_165 },
#else
    { 0, output_165, 0 },
#endif
    0,
    &operand_data[215],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2521 */
  {
    "*extendhidi2_seh",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_166 },
#else
    { 0, output_166, 0 },
#endif
    0,
    &operand_data[217],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2534 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendqihi2,
    &operand_data[235],
    2,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2546 */
  {
    "extendsfdf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.d.s\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extendsfdf2,
    &operand_data[249],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2574 */
  {
    "fix_truncdfsi2_insn",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "trunc.w.d %0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfsi2_insn,
    &operand_data[251],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2584 */
  {
    "fix_truncdfsi2_macro",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_170 },
#else
    { 0, 0, output_170 },
#endif
    (insn_gen_fn) gen_fix_truncdfsi2_macro,
    &operand_data[251],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2612 */
  {
    "fix_truncsfsi2_insn",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "trunc.w.s %0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfsi2_insn,
    &operand_data[254],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2622 */
  {
    "fix_truncsfsi2_macro",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_172 },
#else
    { 0, 0, output_172 },
#endif
    (insn_gen_fn) gen_fix_truncsfsi2_macro,
    &operand_data[254],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2639 */
  {
    "fix_truncdfdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "trunc.l.d %0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfdi2,
    &operand_data[257],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2650 */
  {
    "fix_truncsfdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "trunc.l.s %0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfdi2,
    &operand_data[259],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2661 */
  {
    "floatsidf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.d.w\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatsidf2,
    &operand_data[261],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2672 */
  {
    "floatdidf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.d.l\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatdidf2,
    &operand_data[263],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2683 */
  {
    "floatsisf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.s.w\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatsisf2,
    &operand_data[265],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2694 */
  {
    "floatdisf2",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.s.l\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_floatdisf2,
    &operand_data[267],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2924 */
  {
    "extzvsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ext\t%0,%1,%3,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extzvsi,
    &operand_data[269],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2924 */
  {
    "extzvdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dext\t%0,%1,%3,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_extzvdi,
    &operand_data[273],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2960 */
  {
    "insvsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ins\t%0,%z3,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_insvsi,
    &operand_data[277],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2960 */
  {
    "insvdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dins\t%0,%z3,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_insvdi,
    &operand_data[281],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2982 */
  {
    "mov_lwl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwl\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_lwl,
    &operand_data[285],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2982 */
  {
    "mov_ldl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldl\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_ldl,
    &operand_data[288],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2992 */
  {
    "mov_lwr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwr\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_lwr,
    &operand_data[291],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2992 */
  {
    "mov_ldr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldr\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_ldr,
    &operand_data[295],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3003 */
  {
    "mov_swl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "swl\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_swl,
    &operand_data[299],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3003 */
  {
    "mov_sdl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdl\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_sdl,
    &operand_data[302],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3013 */
  {
    "mov_swr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "swr\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_swr,
    &operand_data[305],
    3,
    1,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3013 */
  {
    "mov_sdr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdr\t%z1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mov_sdr,
    &operand_data[308],
    3,
    1,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3039 */
  {
    "*lea_high64",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[311],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3092 */
  {
    "*lea64",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[311],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
  {
    "*xgot_hisi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[314],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
  {
    "*xgot_hidi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[316],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
  {
    "*xgot_losi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[318],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
  {
    "*xgot_lodi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[321],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
  {
    "*got_dispsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[314],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
  {
    "*got_dispdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[316],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
  {
    "*got_pagesi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[324],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
  {
    "*got_pagedi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[326],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3179 */
  {
    "load_gotsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%R2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_load_gotsi,
    &operand_data[328],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3179 */
  {
    "load_gotdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%0,%R2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_load_gotdi,
    &operand_data[331],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3194 */
  {
    "*lowsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addiu\t%0,%1,%R2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[328],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3194 */
  {
    "*lowdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "daddiu\t%0,%1,%R2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[331],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3203 */
  {
    "*lowsi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addiu\t%0,%R2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[334],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3203 */
  {
    "*lowdi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "daddiu\t%0,%R2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[337],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3254 */
  {
    "*movsi_ra",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t$31,%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[340],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3254 */
  {
    "*movdi_ra",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t$31,%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[341],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3262 */
  {
    "*movdi_32bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_209 },
#else
    { 0, 0, output_209 },
#endif
    0,
    &operand_data[342],
    2,
    0,
    10,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3273 */
  {
    "*movdi_32bit_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_210 },
#else
    { 0, 0, output_210 },
#endif
    0,
    &operand_data[344],
    2,
    0,
    8,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3284 */
  {
    "*movdi_64bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_211 },
#else
    { 0, 0, output_211 },
#endif
    0,
    &operand_data[346],
    2,
    0,
    15,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3295 */
  {
    "*movdi_64bit_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_212 },
#else
    { 0, 0, output_212 },
#endif
    0,
    &operand_data[348],
    2,
    0,
    8,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3380 */
  {
    "*movsi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_213 },
#else
    { 0, 0, output_213 },
#endif
    0,
    &operand_data[350],
    2,
    0,
    18,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3391 */
  {
    "*movsi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_214 },
#else
    { 0, 0, output_214 },
#endif
    0,
    &operand_data[352],
    2,
    0,
    8,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3483 */
  {
    "movcc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_215 },
#else
    { 0, 0, output_215 },
#endif
    (insn_gen_fn) gen_movcc,
    &operand_data[354],
    2,
    0,
    9,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*lwxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[356],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*ldxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[359],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*ldxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[362],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*lwxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[365],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*ldxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[368],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3539 */
  {
    "*ldxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ldxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[371],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*swxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "swxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[374],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*sdxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[377],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*sdxc1_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[380],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*swxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "swxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[383],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*sdxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[386],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3548 */
  {
    "*sdxc1_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sdxc1\t%0,%1(%2)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[389],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3573 */
  {
    "*movhi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_228 },
#else
    { 0, output_228, 0 },
#endif
    0,
    &operand_data[392],
    2,
    0,
    8,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3592 */
  {
    "*movhi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_229 },
#else
    { 0, output_229, 0 },
#endif
    0,
    &operand_data[394],
    2,
    0,
    7,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3680 */
  {
    "*movqi_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_230 },
#else
    { 0, output_230, 0 },
#endif
    0,
    &operand_data[396],
    2,
    0,
    8,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3699 */
  {
    "*movqi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_231 },
#else
    { 0, output_231, 0 },
#endif
    0,
    &operand_data[398],
    2,
    0,
    7,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3758 */
  {
    "*movsf_hardfloat",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_232 },
#else
    { 0, 0, output_232 },
#endif
    0,
    &operand_data[400],
    2,
    0,
    10,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3769 */
  {
    "*movsf_softfloat",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_233 },
#else
    { 0, 0, output_233 },
#endif
    0,
    &operand_data[402],
    2,
    0,
    3,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3780 */
  {
    "*movsf_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_234 },
#else
    { 0, 0, output_234 },
#endif
    0,
    &operand_data[404],
    2,
    0,
    5,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3803 */
  {
    "*movdf_hardfloat_64bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_235 },
#else
    { 0, 0, output_235 },
#endif
    0,
    &operand_data[406],
    2,
    0,
    10,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3814 */
  {
    "*movdf_hardfloat_32bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_236 },
#else
    { 0, 0, output_236 },
#endif
    0,
    &operand_data[406],
    2,
    0,
    10,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3825 */
  {
    "*movdf_softfloat",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_237 },
#else
    { 0, 0, output_237 },
#endif
    0,
    &operand_data[408],
    2,
    0,
    6,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3836 */
  {
    "*movdf_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_238 },
#else
    { 0, 0, output_238 },
#endif
    0,
    &operand_data[410],
    2,
    0,
    5,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3895 */
  {
    "movv2sf_hardfloat_64bit",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_239 },
#else
    { 0, 0, output_239 },
#endif
    (insn_gen_fn) gen_movv2sf_hardfloat_64bit,
    &operand_data[412],
    2,
    0,
    10,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3924 */
  {
    "*mfhilo_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mf%1\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[414],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3924 */
  {
    "*mfhilo_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mf%1\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[417],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3934 */
  {
    "*mfhilo_si_macc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_242 },
#else
    { 0, 0, output_242 },
#endif
    0,
    &operand_data[414],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3934 */
  {
    "*mfhilo_di_macc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_243 },
#else
    { 0, 0, output_243 },
#endif
    0,
    &operand_data[417],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3954 */
  {
    "load_df_low",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_244 },
#else
    { 0, 0, output_244 },
#endif
    (insn_gen_fn) gen_load_df_low,
    &operand_data[420],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3968 */
  {
    "load_df_high",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_245 },
#else
    { 0, 0, output_245 },
#endif
    (insn_gen_fn) gen_load_df_high,
    &operand_data[420],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3983 */
  {
    "store_df_high",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_246 },
#else
    { 0, 0, output_246 },
#endif
    (insn_gen_fn) gen_store_df_high,
    &operand_data[423],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3998 */
  {
    "loadgp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_loadgp,
    &operand_data[425],
    2,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4016 */
  {
    "loadgp_noshared",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_loadgp_noshared,
    &operand_data[425],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4032 */
  {
    "loadgp_blockage",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_loadgp_blockage,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4043 */
  {
    "cprestore",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_250 },
#else
    { 0, 0, output_250 },
#endif
    (insn_gen_fn) gen_cprestore,
    &operand_data[427],
    1,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*ashlsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_251 },
#else
    { 0, 0, output_251 },
#endif
    0,
    &operand_data[428],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*ashrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_252 },
#else
    { 0, 0, output_252 },
#endif
    0,
    &operand_data[428],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*lshrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_253 },
#else
    { 0, 0, output_253 },
#endif
    0,
    &operand_data[428],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*ashldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_254 },
#else
    { 0, 0, output_254 },
#endif
    0,
    &operand_data[431],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*ashrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_255 },
#else
    { 0, 0, output_255 },
#endif
    0,
    &operand_data[431],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4112 */
  {
    "*lshrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_256 },
#else
    { 0, 0, output_256 },
#endif
    0,
    &operand_data[431],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4127 */
  {
    "*ashlsi3_extend",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_257 },
#else
    { 0, 0, output_257 },
#endif
    0,
    &operand_data[434],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4127 */
  {
    "*ashrsi3_extend",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_258 },
#else
    { 0, 0, output_258 },
#endif
    0,
    &operand_data[434],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4127 */
  {
    "*lshrsi3_extend",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_259 },
#else
    { 0, 0, output_259 },
#endif
    0,
    &operand_data[434],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4142 */
  {
    "*ashlsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_260 },
#else
    { 0, 0, output_260 },
#endif
    0,
    &operand_data[437],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4142 */
  {
    "*ashrsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_261 },
#else
    { 0, 0, output_261 },
#endif
    0,
    &operand_data[437],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4142 */
  {
    "*lshrsi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_262 },
#else
    { 0, 0, output_262 },
#endif
    0,
    &operand_data[437],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4164 */
  {
    "*ashldi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_263 },
#else
    { 0, 0, output_263 },
#endif
    0,
    &operand_data[440],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4184 */
  {
    "*ashrdi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_264 },
#else
    { 0, 0, output_264 },
#endif
    0,
    &operand_data[443],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4203 */
  {
    "*lshrdi3_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_265 },
#else
    { 0, 0, output_265 },
#endif
    0,
    &operand_data[443],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4245 */
  {
    "*mips.md:4245",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[446],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4259 */
  {
    "rotrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_267 },
#else
    { 0, 0, output_267 },
#endif
    (insn_gen_fn) gen_rotrsi3,
    &operand_data[428],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4259 */
  {
    "rotrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_268 },
#else
    { 0, 0, output_268 },
#endif
    (insn_gen_fn) gen_rotrdi3,
    &operand_data[431],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4327 */
  {
    "*branch_fp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_269 },
#else
    { 0, 0, output_269 },
#endif
    0,
    &operand_data[449],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4344 */
  {
    "*branch_fp_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_270 },
#else
    { 0, 0, output_270 },
#endif
    0,
    &operand_data[449],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4363 */
  {
    "*branch_ordersi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_271 },
#else
    { 0, 0, output_271 },
#endif
    0,
    &operand_data[452],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4363 */
  {
    "*branch_orderdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_272 },
#else
    { 0, 0, output_272 },
#endif
    0,
    &operand_data[455],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4376 */
  {
    "*branch_ordersi_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_273 },
#else
    { 0, 0, output_273 },
#endif
    0,
    &operand_data[452],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4376 */
  {
    "*branch_orderdi_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_274 },
#else
    { 0, 0, output_274 },
#endif
    0,
    &operand_data[455],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4391 */
  {
    "*branch_equalitysi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_275 },
#else
    { 0, 0, output_275 },
#endif
    0,
    &operand_data[458],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4391 */
  {
    "*branch_equalitydi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_276 },
#else
    { 0, 0, output_276 },
#endif
    0,
    &operand_data[462],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4408 */
  {
    "*branch_equalitysi_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_277 },
#else
    { 0, 0, output_277 },
#endif
    0,
    &operand_data[458],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4408 */
  {
    "*branch_equalitydi_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_278 },
#else
    { 0, 0, output_278 },
#endif
    0,
    &operand_data[462],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4427 */
  {
    "*branch_equalitysi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_279 },
#else
    { 0, 0, output_279 },
#endif
    0,
    &operand_data[466],
    4,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4427 */
  {
    "*branch_equalitydi_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_280 },
#else
    { 0, 0, output_280 },
#endif
    0,
    &operand_data[470],
    4,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4489 */
  {
    "*seq_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4489 */
  {
    "*seq_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4498 */
  {
    "*seq_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%1,1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[474],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4498 */
  {
    "*seq_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%1,1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[476],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4517 */
  {
    "*sne_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4517 */
  {
    "*sne_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4533 */
  {
    "*sgt_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[478],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4533 */
  {
    "*sgt_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%z2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[481],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4542 */
  {
    "*sgt_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[484],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4542 */
  {
    "*sgt_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[487],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4558 */
  {
    "*sge_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4558 */
  {
    "*sge_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4574 */
  {
    "*slt_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[428],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4574 */
  {
    "*slt_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[490],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4583 */
  {
    "*slt_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[493],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4583 */
  {
    "*slt_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[496],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4604 */
  {
    "*sle_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_297 },
#else
    { 0, 0, output_297 },
#endif
    0,
    &operand_data[499],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4604 */
  {
    "*sle_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_298 },
#else
    { 0, 0, output_298 },
#endif
    0,
    &operand_data[502],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4616 */
  {
    "*sle_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_299 },
#else
    { 0, 0, output_299 },
#endif
    0,
    &operand_data[505],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4616 */
  {
    "*sle_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_300 },
#else
    { 0, 0, output_300 },
#endif
    0,
    &operand_data[508],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4638 */
  {
    "*sgtu_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[478],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4638 */
  {
    "*sgtu_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%z2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[481],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4647 */
  {
    "*sgtu_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[484],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4647 */
  {
    "*sgtu_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[487],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4663 */
  {
    "*sge_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4663 */
  {
    "*sge_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%.,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[43],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4679 */
  {
    "*sltu_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[428],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4679 */
  {
    "*sltu_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[490],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4688 */
  {
    "*sltu_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[493],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4688 */
  {
    "*sltu_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "sltu\t%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[496],
    3,
    0,
    2,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4709 */
  {
    "*sleu_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_311 },
#else
    { 0, 0, output_311 },
#endif
    0,
    &operand_data[511],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4709 */
  {
    "*sleu_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_312 },
#else
    { 0, 0, output_312 },
#endif
    0,
    &operand_data[514],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4721 */
  {
    "*sleu_si_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_313 },
#else
    { 0, 0, output_313 },
#endif
    0,
    &operand_data[517],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4721 */
  {
    "*sleu_di_mips16",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_314 },
#else
    { 0, 0, output_314 },
#endif
    0,
    &operand_data[520],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunordered_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.un.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunordered_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "suneq_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ueq.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_suneq_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunlt_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunlt_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunle_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunle_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "seq_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.eq.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_seq_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "slt_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_slt_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sle_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.s\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sle_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunordered_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.un.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunordered_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "suneq_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ueq.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_suneq_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunlt_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunlt_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sunle_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunle_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "seq_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.eq.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_seq_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "slt_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_slt_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4743 */
  {
    "sle_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.d\t%Z0%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sle_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sge_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.s\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sge_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sgt_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.s\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sgt_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sunge_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.s\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunge_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sungt_sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.s\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sungt_sf,
    &operand_data[523],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sge_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.d\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sge_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sgt_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.d\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sgt_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sunge_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.d\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunge_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4752 */
  {
    "sungt_df",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.d\t%Z0%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sungt_df,
    &operand_data[526],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4770 */
  {
    "jump",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_337 },
#else
    { 0, 0, output_337 },
#endif
    (insn_gen_fn) gen_jump,
    &operand_data[425],
    1,
    0,
    0,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4804 */
  {
    "*mips.md:4804",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "b\t%l0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[425],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4825 */
  {
    "indirect_jumpsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t%0%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_indirect_jumpsi,
    &operand_data[41],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4825 */
  {
    "indirect_jumpdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t%0%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_indirect_jumpdi,
    &operand_data[44],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4854 */
  {
    "tablejumpsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t%0%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_tablejumpsi,
    &operand_data[529],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4854 */
  {
    "tablejumpdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t%0%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_tablejumpdi,
    &operand_data[531],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4932 */
  {
    "blockage",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_blockage,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4959 */
  {
    "return",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t$31%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4968 */
  {
    "return_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*j\t%0%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_return_internal,
    &operand_data[533],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4996 */
  {
    "eh_set_lr_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_eh_set_lr_si,
    &operand_data[534],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5002 */
  {
    "eh_set_lr_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_eh_set_lr_di,
    &operand_data[536],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5018 */
  {
    "exception_receiver",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_exception_receiver,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5053 */
  {
    "load_callsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%R2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_load_callsi,
    &operand_data[538],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5053 */
  {
    "load_calldi",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%0,%R2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_load_calldi,
    &operand_data[541],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5088 */
  {
    "sibcall_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_351 },
#else
    { 0, 0, output_351 },
#endif
    (insn_gen_fn) gen_sibcall_internal,
    &operand_data[544],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5107 */
  {
    "sibcall_value_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_352 },
#else
    { 0, 0, output_352 },
#endif
    (insn_gen_fn) gen_sibcall_value_internal,
    &operand_data[546],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5115 */
  {
    "sibcall_value_multiple_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_353 },
#else
    { 0, 0, output_353 },
#endif
    (insn_gen_fn) gen_sibcall_value_multiple_internal,
    &operand_data[546],
    4,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5174 */
  {
    "call_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_354 },
#else
    { 0, 0, output_354 },
#endif
    (insn_gen_fn) gen_call_internal,
    &operand_data[550],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5191 */
  {
    "call_split",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_355 },
#else
    { 0, 0, output_355 },
#endif
    (insn_gen_fn) gen_call_split,
    &operand_data[552],
    2,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5213 */
  {
    "call_value_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_356 },
#else
    { 0, 0, output_356 },
#endif
    (insn_gen_fn) gen_call_value_internal,
    &operand_data[549],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5232 */
  {
    "call_value_split",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_357 },
#else
    { 0, 0, output_357 },
#endif
    (insn_gen_fn) gen_call_value_split,
    &operand_data[554],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5243 */
  {
    "call_value_multiple_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_358 },
#else
    { 0, 0, output_358 },
#endif
    (insn_gen_fn) gen_call_value_multiple_internal,
    &operand_data[557],
    4,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5265 */
  {
    "call_value_multiple_split",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_359 },
#else
    { 0, 0, output_359 },
#endif
    (insn_gen_fn) gen_call_value_multiple_split,
    &operand_data[561],
    4,
    2,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5310 */
  {
    "prefetch",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_360 },
#else
    { 0, 0, output_360 },
#endif
    (insn_gen_fn) gen_prefetch,
    &operand_data[565],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5321 */
  {
    "*prefetch_indexed_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_361 },
#else
    { 0, 0, output_361 },
#endif
    0,
    &operand_data[568],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5321 */
  {
    "*prefetch_indexed_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_362 },
#else
    { 0, 0, output_362 },
#endif
    0,
    &operand_data[572],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5333 */
  {
    "nop",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%(nop%)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_nop,
    &operand_data[0],
    0,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5341 */
  {
    "hazard_nop",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_364 },
#else
    { 0, 0, output_364 },
#endif
    (insn_gen_fn) gen_hazard_nop,
    &operand_data[0],
    0,
    0,
    0,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movsi_on_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_365 },
#else
    { 0, output_365, 0 },
#endif
    0,
    &operand_data[576],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movdi_on_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_366 },
#else
    { 0, output_366, 0 },
#endif
    0,
    &operand_data[581],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movsi_on_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_367 },
#else
    { 0, output_367, 0 },
#endif
    0,
    &operand_data[586],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movdi_on_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_368 },
#else
    { 0, output_368, 0 },
#endif
    0,
    &operand_data[591],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movsi_on_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_369 },
#else
    { 0, output_369, 0 },
#endif
    0,
    &operand_data[596],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5354 */
  {
    "*movdi_on_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_370 },
#else
    { 0, output_370, 0 },
#endif
    0,
    &operand_data[601],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movsf_on_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_371 },
#else
    { 0, output_371, 0 },
#endif
    0,
    &operand_data[606],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movdf_on_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_372 },
#else
    { 0, output_372, 0 },
#endif
    0,
    &operand_data[611],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movsf_on_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_373 },
#else
    { 0, output_373, 0 },
#endif
    0,
    &operand_data[616],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movdf_on_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_374 },
#else
    { 0, output_374, 0 },
#endif
    0,
    &operand_data[621],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movsf_on_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_375 },
#else
    { 0, output_375, 0 },
#endif
    0,
    &operand_data[626],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5369 */
  {
    "*movdf_on_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_376 },
#else
    { 0, output_376, 0 },
#endif
    0,
    &operand_data[631],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5418 */
  {
    "consttable_int",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_377 },
#else
    { 0, 0, output_377 },
#endif
    (insn_gen_fn) gen_consttable_int,
    &operand_data[636],
    2,
    0,
    0,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5430 */
  {
    "consttable_float",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_378 },
#else
    { 0, 0, output_378 },
#endif
    (insn_gen_fn) gen_consttable_float,
    &operand_data[636],
    1,
    0,
    0,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5446 */
  {
    "align",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    ".align\t%0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_align,
    &operand_data[637],
    1,
    0,
    0,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5468 */
  {
    "tls_get_tp_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    ".set\tpush\n\t.set\tmips32r2\t\n\trdhwr\t%0,$29\n\t.set\tpop",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_tls_get_tp_si,
    &operand_data[638],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5468 */
  {
    "tls_get_tp_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    ".set\tpush\n\t.set\tmips32r2\t\n\trdhwr\t%0,$29\n\t.set\tpop",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_tls_get_tp_di,
    &operand_data[639],
    1,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:21 */
  {
    "*movcc_v2sf_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_382 },
#else
    { 0, output_382, 0 },
#endif
    0,
    &operand_data[640],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:21 */
  {
    "*movcc_v2sf_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_383 },
#else
    { 0, output_383, 0 },
#endif
    0,
    &operand_data[645],
    5,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:36 */
  {
    "mips_cond_move_tf_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_384 },
#else
    { 0, output_384, 0 },
#endif
    (insn_gen_fn) gen_mips_cond_move_tf_ps,
    &operand_data[650],
    4,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:70 */
  {
    "mips_pul_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pul.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_pul_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:82 */
  {
    "mips_puu_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "puu.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_puu_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:96 */
  {
    "mips_pll_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pll.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_pll_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:110 */
  {
    "mips_plu_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "plu.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_plu_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:137 */
  {
    "vec_initv2sf_internal",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_389 },
#else
    { 0, 0, output_389 },
#endif
    (insn_gen_fn) gen_vec_initv2sf_internal,
    &operand_data[654],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:156 */
  {
    "vec_extractv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_390 },
#else
    { 0, 0, output_390 },
#endif
    (insn_gen_fn) gen_vec_extractv2sf,
    &operand_data[657],
    3,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:226 */
  {
    "mips_alnv_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "alnv.ps\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_alnv_ps,
    &operand_data[660],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:238 */
  {
    "mips_addr_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addr.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addr_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:249 */
  {
    "mips_cvt_pw_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.pw.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cvt_pw_ps,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:259 */
  {
    "mips_cvt_ps_pw",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cvt.ps.pw\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cvt_ps_pw,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:269 */
  {
    "mips_mulr_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulr.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_mulr_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:295 */
  {
    "*mips_abs_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "abs.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    0,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:308 */
  {
    "mips_cabs_cond_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cabs.%Y3.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cabs_cond_s,
    &operand_data[664],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:308 */
  {
    "mips_cabs_cond_d",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cabs.%Y3.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cabs_cond_d,
    &operand_data[668],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:324 */
  {
    "mips_c_cond_4s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_c_cond_4s,
    &operand_data[672],
    6,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:353 */
  {
    "mips_cabs_cond_4s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cabs_cond_4s,
    &operand_data[672],
    6,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:387 */
  {
    "mips_c_cond_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.%Y3.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_c_cond_ps,
    &operand_data[678],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:398 */
  {
    "mips_cabs_cond_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cabs.%Y3.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cabs_cond_ps,
    &operand_data[678],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "sunordered_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.un.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunordered_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "suneq_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ueq.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_suneq_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "sunlt_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunlt_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "sunle_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunle_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "seq_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.eq.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_seq_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "slt_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_slt_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:414 */
  {
    "sle_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sle_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
  {
    "sge_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.le.ps\t%0,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sge_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
  {
    "sgt_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.lt.ps\t%0,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sgt_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
  {
    "sunge_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ule.ps\t%0,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sunge_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:425 */
  {
    "sungt_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "c.ult.ps\t%0,%2,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_sungt_ps,
    &operand_data[678],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:441 */
  {
    "bc1any4t",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*bc1any4t\t%0,%1%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bc1any4t,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:453 */
  {
    "bc1any4f",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*bc1any4f\t%0,%1%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bc1any4f,
    &operand_data[682],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:465 */
  {
    "bc1any2t",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*bc1any2t\t%0,%1%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bc1any2t,
    &operand_data[684],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:477 */
  {
    "bc1any2f",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*bc1any2f\t%0,%1%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_bc1any2f,
    &operand_data[684],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:498 */
  {
    "*branch_upper_lower",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_418 },
#else
    { 0, 0, output_418 },
#endif
    0,
    &operand_data[686],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:520 */
  {
    "*branch_upper_lower_inverted",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_419 },
#else
    { 0, 0, output_419 },
#endif
    0,
    &operand_data[686],
    4,
    0,
    1,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
  {
    "mips_rsqrt1_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt1.s\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt1_s,
    &operand_data[7],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
  {
    "mips_rsqrt1_d",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt1.d\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt1_d,
    &operand_data[10],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:545 */
  {
    "mips_rsqrt1_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt1.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt1_ps,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
  {
    "mips_rsqrt2_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt2.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt2_s,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
  {
    "mips_rsqrt2_d",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt2.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt2_d,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:554 */
  {
    "mips_rsqrt2_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rsqrt2.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rsqrt2_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
  {
    "mips_recip1_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip1.s\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip1_s,
    &operand_data[7],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
  {
    "mips_recip1_d",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip1.d\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip1_d,
    &operand_data[10],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:564 */
  {
    "mips_recip1_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip1.ps\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip1_ps,
    &operand_data[13],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
  {
    "mips_recip2_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip2.s\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip2_s,
    &operand_data[7],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
  {
    "mips_recip2_d",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip2.d\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip2_d,
    &operand_data[10],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:573 */
  {
    "mips_recip2_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "recip2.ps\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_recip2_ps,
    &operand_data[13],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1 */
  {
    "addv2hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addq.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addv2hi3,
    &operand_data[690],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1 */
  {
    "addv4qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addu.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_addv4qi3,
    &operand_data[693],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
  {
    "mips_addq_s_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addq_s.w\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addq_s_w,
    &operand_data[40],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
  {
    "mips_addq_s_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addq_s.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addq_s_ph,
    &operand_data[690],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:50 */
  {
    "mips_addu_s_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addu_s.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addu_s_qb,
    &operand_data[693],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:64 */
  {
    "subv2hi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subq.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subv2hi3,
    &operand_data[690],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:64 */
  {
    "subv4qi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subu.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_subv4qi3,
    &operand_data[693],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
  {
    "mips_subq_s_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subq_s.w\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_subq_s_w,
    &operand_data[40],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
  {
    "mips_subq_s_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subq_s.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_subq_s_ph,
    &operand_data[690],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:76 */
  {
    "mips_subu_s_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "subu_s.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_subu_s_qb,
    &operand_data[693],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:90 */
  {
    "mips_addsc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addsc\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addsc,
    &operand_data[40],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:104 */
  {
    "mips_addwc",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "addwc\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_addwc,
    &operand_data[40],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:119 */
  {
    "mips_modsub",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "modsub\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_modsub,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:130 */
  {
    "mips_raddu_w_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "raddu.w.qb\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_raddu_w_qb,
    &operand_data[696],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:140 */
  {
    "mips_absq_s_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "absq_s.w\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_absq_s_w,
    &operand_data[40],
    2,
    1,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:140 */
  {
    "mips_absq_s_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "absq_s.ph\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_absq_s_ph,
    &operand_data[690],
    2,
    1,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:153 */
  {
    "mips_precrq_qb_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precrq.qb.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precrq_qb_ph,
    &operand_data[698],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:163 */
  {
    "mips_precrq_ph_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precrq.ph.w\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precrq_ph_w,
    &operand_data[701],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:173 */
  {
    "mips_precrq_rs_ph_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precrq_rs.ph.w\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precrq_rs_ph_w,
    &operand_data[701],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:188 */
  {
    "mips_precrqu_s_qb_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precrqu_s.qb.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precrqu_s_qb_ph,
    &operand_data[698],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:203 */
  {
    "mips_preceq_w_phl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceq.w.phl\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceq_w_phl,
    &operand_data[704],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:212 */
  {
    "mips_preceq_w_phr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceq.w.phr\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceq_w_phr,
    &operand_data[704],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:222 */
  {
    "mips_precequ_ph_qbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precequ.ph.qbl\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precequ_ph_qbl,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:231 */
  {
    "mips_precequ_ph_qbr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precequ.ph.qbr\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precequ_ph_qbr,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:240 */
  {
    "mips_precequ_ph_qbla",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precequ.ph.qbla\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precequ_ph_qbla,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:249 */
  {
    "mips_precequ_ph_qbra",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "precequ.ph.qbra\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_precequ_ph_qbra,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:259 */
  {
    "mips_preceu_ph_qbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceu.ph.qbl\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceu_ph_qbl,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:268 */
  {
    "mips_preceu_ph_qbr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceu.ph.qbr\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceu_ph_qbr,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:277 */
  {
    "mips_preceu_ph_qbla",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceu.ph.qbla\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceu_ph_qbla,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:286 */
  {
    "mips_preceu_ph_qbra",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "preceu.ph.qbra\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_preceu_ph_qbra,
    &operand_data[706],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:297 */
  {
    "mips_shll_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_462 },
#else
    { 0, 0, output_462 },
#endif
    (insn_gen_fn) gen_mips_shll_ph,
    &operand_data[708],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:297 */
  {
    "mips_shll_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_463 },
#else
    { 0, 0, output_463 },
#endif
    (insn_gen_fn) gen_mips_shll_qb,
    &operand_data[711],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:319 */
  {
    "mips_shll_s_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_464 },
#else
    { 0, 0, output_464 },
#endif
    (insn_gen_fn) gen_mips_shll_s_w,
    &operand_data[714],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:319 */
  {
    "mips_shll_s_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_465 },
#else
    { 0, 0, output_465 },
#endif
    (insn_gen_fn) gen_mips_shll_s_ph,
    &operand_data[708],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:342 */
  {
    "mips_shrl_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_466 },
#else
    { 0, 0, output_466 },
#endif
    (insn_gen_fn) gen_mips_shrl_qb,
    &operand_data[711],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:361 */
  {
    "mips_shra_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_467 },
#else
    { 0, 0, output_467 },
#endif
    (insn_gen_fn) gen_mips_shra_ph,
    &operand_data[708],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:379 */
  {
    "mips_shra_r_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_468 },
#else
    { 0, 0, output_468 },
#endif
    (insn_gen_fn) gen_mips_shra_r_w,
    &operand_data[714],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:379 */
  {
    "mips_shra_r_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_469 },
#else
    { 0, 0, output_469 },
#endif
    (insn_gen_fn) gen_mips_shra_r_ph,
    &operand_data[708],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:400 */
  {
    "mips_muleu_s_ph_qbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "muleu_s.ph.qbl\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_muleu_s_ph_qbl,
    &operand_data[717],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:414 */
  {
    "mips_muleu_s_ph_qbr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "muleu_s.ph.qbr\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_muleu_s_ph_qbr,
    &operand_data[717],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:429 */
  {
    "mips_mulq_rs_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulq_rs.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_mulq_rs_ph,
    &operand_data[721],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:444 */
  {
    "mips_muleq_s_w_phl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "muleq_s.w.phl\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_muleq_s_w_phl,
    &operand_data[725],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:458 */
  {
    "mips_muleq_s_w_phr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "muleq_s.w.phr\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_muleq_s_w_phr,
    &operand_data[725],
    4,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:473 */
  {
    "mips_dpau_h_qbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpau.h.qbl\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpau_h_qbl,
    &operand_data[729],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:484 */
  {
    "mips_dpau_h_qbr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpau.h.qbr\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpau_h_qbr,
    &operand_data[729],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:496 */
  {
    "mips_dpsu_h_qbl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpsu.h.qbl\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpsu_h_qbl,
    &operand_data[729],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:507 */
  {
    "mips_dpsu_h_qbr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpsu.h.qbr\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpsu_h_qbr,
    &operand_data[729],
    4,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:519 */
  {
    "mips_dpaq_s_w_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpaq_s.w.ph\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpaq_s_w_ph,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:535 */
  {
    "mips_dpsq_s_w_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpsq_s.w.ph\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpsq_s_w_ph,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:551 */
  {
    "mips_mulsaq_s_w_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulsaq_s.w.ph\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_mulsaq_s_w_ph,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:567 */
  {
    "mips_dpaq_sa_l_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpaq_sa.l.w\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpaq_sa_l_w,
    &operand_data[737],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:583 */
  {
    "mips_dpsq_sa_l_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "dpsq_sa.l.w\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_dpsq_sa_l_w,
    &operand_data[737],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:599 */
  {
    "mips_maq_s_w_phl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maq_s.w.phl\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_maq_s_w_phl,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:614 */
  {
    "mips_maq_s_w_phr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maq_s.w.phr\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_maq_s_w_phr,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:630 */
  {
    "mips_maq_sa_w_phl",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maq_sa.w.phl\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_maq_sa_w_phl,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:645 */
  {
    "mips_maq_sa_w_phr",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "maq_sa.w.phr\t%q0,%2,%3",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_maq_sa_w_phr,
    &operand_data[733],
    4,
    3,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:662 */
  {
    "mips_bitrev",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "bitrev\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_bitrev,
    &operand_data[40],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:672 */
  {
    "mips_insv",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "insv\t%0,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_insv,
    &operand_data[741],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:685 */
  {
    "mips_repl_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_490 },
#else
    { 0, 0, output_490 },
#endif
    (insn_gen_fn) gen_mips_repl_qb,
    &operand_data[744],
    2,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:702 */
  {
    "mips_repl_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .multi = output_491 },
#else
    { 0, output_491, 0 },
#endif
    (insn_gen_fn) gen_mips_repl_ph,
    &operand_data[746],
    2,
    0,
    2,
    2
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:715 */
  {
    "mips_cmp_eq_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp.eq.ph\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmp_eq_ph,
    &operand_data[691],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:715 */
  {
    "mips_cmpu_eq_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpu.eq.qb\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpu_eq_qb,
    &operand_data[694],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:726 */
  {
    "mips_cmp_lt_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp.lt.ph\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmp_lt_ph,
    &operand_data[691],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:726 */
  {
    "mips_cmpu_lt_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpu.lt.qb\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpu_lt_qb,
    &operand_data[694],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:737 */
  {
    "mips_cmp_le_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmp.le.ph\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmp_le_ph,
    &operand_data[691],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:737 */
  {
    "mips_cmpu_le_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpu.le.qb\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpu_le_qb,
    &operand_data[694],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:748 */
  {
    "mips_cmpgu_eq_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpgu.eq.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpgu_eq_qb,
    &operand_data[748],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:758 */
  {
    "mips_cmpgu_lt_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpgu.lt.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpgu_lt_qb,
    &operand_data[748],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:768 */
  {
    "mips_cmpgu_le_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "cmpgu.le.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_cmpgu_le_qb,
    &operand_data[748],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:779 */
  {
    "mips_pick_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pick.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_pick_ph,
    &operand_data[690],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:779 */
  {
    "mips_pick_qb",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "pick.qb\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_pick_qb,
    &operand_data[693],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:791 */
  {
    "mips_packrl_ph",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "packrl.ph\t%0,%1,%2",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_packrl_ph,
    &operand_data[690],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:803 */
  {
    "mips_extr_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_504 },
#else
    { 0, 0, output_504 },
#endif
    (insn_gen_fn) gen_mips_extr_w,
    &operand_data[751],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:824 */
  {
    "mips_extr_r_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_505 },
#else
    { 0, 0, output_505 },
#endif
    (insn_gen_fn) gen_mips_extr_r_w,
    &operand_data[751],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:845 */
  {
    "mips_extr_rs_w",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_506 },
#else
    { 0, 0, output_506 },
#endif
    (insn_gen_fn) gen_mips_extr_rs_w,
    &operand_data[751],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:867 */
  {
    "mips_extr_s_h",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_507 },
#else
    { 0, 0, output_507 },
#endif
    (insn_gen_fn) gen_mips_extr_s_h,
    &operand_data[751],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:889 */
  {
    "mips_extp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_508 },
#else
    { 0, 0, output_508 },
#endif
    (insn_gen_fn) gen_mips_extp,
    &operand_data[751],
    3,
    2,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:911 */
  {
    "mips_extpdp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_509 },
#else
    { 0, 0, output_509 },
#endif
    (insn_gen_fn) gen_mips_extpdp,
    &operand_data[751],
    3,
    4,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:937 */
  {
    "mips_shilo",
#if HAVE_DESIGNATED_INITIALIZERS
    { .function = output_510 },
#else
    { 0, 0, output_510 },
#endif
    (insn_gen_fn) gen_mips_shilo,
    &operand_data[754],
    3,
    0,
    2,
    3
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:956 */
  {
    "mips_mthlip",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "mthlip\t%2,%q0",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_mthlip,
    &operand_data[737],
    3,
    2,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:972 */
  {
    "mips_wrdsp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "wrdsp\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_wrdsp,
    &operand_data[757],
    2,
    10,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:994 */
  {
    "mips_rddsp",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "rddsp\t%0,%1",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_rddsp,
    &operand_data[759],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1011 */
  {
    "mips_lbux",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbux\t%0,%2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_lbux,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1023 */
  {
    "mips_lhx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhx\t%0,%2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_lhx,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1035 */
  {
    "mips_lwx",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwx\t%0,%2(%1)",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_lwx,
    &operand_data[40],
    3,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md:1047 */
  {
    "mips_bposge",
#if HAVE_DESIGNATED_INITIALIZERS
    { .single =
#else
    {
#endif
    "%*bposge%0\t%1%/",
#if HAVE_DESIGNATED_INITIALIZERS
    },
#else
    0, 0 },
#endif
    (insn_gen_fn) gen_mips_bposge,
    &operand_data[761],
    2,
    0,
    1,
    1
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:618 */
  {
    "conditional_trap",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_conditional_trap,
    &operand_data[763],
    2,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:660 */
  {
    "addsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_addsi3,
    &operand_data[765],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:660 */
  {
    "adddi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_adddi3,
    &operand_data[768],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:732 */
  {
    "adddi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[771],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:761 */
  {
    "adddi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[773],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:793 */
  {
    "adddi3+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[776],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:822 */
  {
    "mulsf3-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[778],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:868 */
  {
    "mulsf3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[781],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:926 */
  {
    "mulsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulsf3,
    &operand_data[784],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:926 */
  {
    "muldf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_muldf3,
    &operand_data[787],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1011 */
  {
    "mulsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulsi3,
    &operand_data[790],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1011 */
  {
    "muldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_muldi3,
    &operand_data[793],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1072 */
  {
    "muldi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[796],
    5,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1120 */
  {
    "muldi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[796],
    5,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1178 */
  {
    "muldi3+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[797],
    7,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1197 */
  {
    "muldi3+4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[797],
    7,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1259 */
  {
    "muldi3+5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[797],
    7,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1322 */
  {
    "mulsidi3-5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[804],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1353 */
  {
    "mulsidi3-4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[808],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1389 */
  {
    "mulsidi3-3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[814],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1433 */
  {
    "mulsidi3-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[797],
    7,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1452 */
  {
    "mulsidi3-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[797],
    7,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1487 */
  {
    "mulsidi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mulsidi3,
    &operand_data[795],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1487 */
  {
    "umulsidi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_umulsidi3,
    &operand_data[795],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
  {
    "umulsidi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[820],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1529 */
  {
    "smulsi3_highpart-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[820],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1622 */
  {
    "smulsi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_smulsi3_highpart,
    &operand_data[790],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1622 */
  {
    "umulsi3_highpart",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_umulsi3_highpart,
    &operand_data[790],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
  {
    "divsf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_divsf3,
    &operand_data[826],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
  {
    "divdf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_divdf3,
    &operand_data[829],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:1823 */
  {
    "divv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_divv2sf3,
    &operand_data[832],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2073 */
  {
    "andsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_andsi3,
    &operand_data[835],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2073 */
  {
    "anddi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_anddi3,
    &operand_data[838],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2103 */
  {
    "iorsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_iorsi3,
    &operand_data[835],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2103 */
  {
    "iordi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_iordi3,
    &operand_data[838],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2133 */
  {
    "xorsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xorsi3,
    &operand_data[835],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2133 */
  {
    "xordi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_xordi3,
    &operand_data[838],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2267 */
  {
    "xordi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[792],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2282 */
  {
    "xordi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[792],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2336 */
  {
    "zero_extendqisi2-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[841],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2356 */
  {
    "zero_extendqisi2-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[843],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
  {
    "zero_extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqisi2,
    &operand_data[845],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
  {
    "zero_extendqidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqidi2,
    &operand_data[847],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
  {
    "zero_extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhisi2,
    &operand_data[849],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2378 */
  {
    "zero_extendhidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendhidi2,
    &operand_data[851],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2421 */
  {
    "zero_extendqihi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_zero_extendqihi2,
    &operand_data[853],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2470 */
  {
    "zero_extendqihi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[841],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
  {
    "extendqisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extendqisi2,
    &operand_data[845],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
  {
    "extendqidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extendqidi2,
    &operand_data[847],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extendhisi2,
    &operand_data[849],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2486 */
  {
    "extendhidi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extendhidi2,
    &operand_data[851],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "extendhidi2+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[845],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "extendhidi2+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[847],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "extendhidi2+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[849],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2501 */
  {
    "fix_truncdfsi2-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[851],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2534 */
  {
    "fix_truncdfsi2-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[853],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2562 */
  {
    "fix_truncdfsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncdfsi2,
    &operand_data[855],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2600 */
  {
    "fix_truncsfsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fix_truncsfsi2,
    &operand_data[857],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2705 */
  {
    "fixuns_truncdfsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fixuns_truncdfsi2,
    &operand_data[855],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2750 */
  {
    "fixuns_truncdfdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fixuns_truncdfdi2,
    &operand_data[859],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2792 */
  {
    "fixuns_truncsfsi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fixuns_truncsfsi2,
    &operand_data[857],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2834 */
  {
    "fixuns_truncsfdi2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_fixuns_truncsfdi2,
    &operand_data[861],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2884 */
  {
    "extv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extv,
    &operand_data[863],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2899 */
  {
    "extzv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_extzv,
    &operand_data[867],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:2935 */
  {
    "insv",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_insv,
    &operand_data[868],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3039 */
  {
    "insv+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[872],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3064 */
  {
    "insv+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[874],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3092 */
  {
    "insv+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[875],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
  {
    "insv+4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[878],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3113 */
  {
    "insv+5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[880],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
  {
    "insv+6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[882],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3128 */
  {
    "insv+7",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[885],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
  {
    "insv+8",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[878],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3143 */
  {
    "movdi-7",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[880],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
  {
    "movdi-6",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[888],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3160 */
  {
    "movdi-5",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[890],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3215 */
  {
    "movdi-4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[892],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3215 */
  {
    "movdi-3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[895],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3227 */
  {
    "movdi-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[898],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3227 */
  {
    "movdi-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[901],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3241 */
  {
    "movdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdi,
    &operand_data[904],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3323 */
  {
    "movdi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[776],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3368 */
  {
    "movsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movsi,
    &operand_data[906],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3418 */
  {
    "movsi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[771],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3460 */
  {
    "reload_incc-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[771],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3506 */
  {
    "reload_incc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_reload_incc,
    &operand_data[908],
    3,
    0,
    1,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3516 */
  {
    "reload_outcc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_reload_outcc,
    &operand_data[911],
    3,
    0,
    1,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3564 */
  {
    "movhi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movhi,
    &operand_data[914],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3626 */
  {
    "movhi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[916],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3671 */
  {
    "movqi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movqi,
    &operand_data[918],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3721 */
  {
    "movqi+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[920],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3749 */
  {
    "movsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movsf,
    &operand_data[922],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3794 */
  {
    "movdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdf,
    &operand_data[924],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3847 */
  {
    "movdf+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[926],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3858 */
  {
    "movdf+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[928],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3871 */
  {
    "movv2sf-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[930],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3886 */
  {
    "movv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movv2sf,
    &operand_data[932],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3918 */
  {
    "mfhilo_si",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mfhilo_si,
    &operand_data[790],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3918 */
  {
    "mfhilo_di",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mfhilo_di,
    &operand_data[793],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:3998 */
  {
    "mfhilo_di+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[425],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4016 */
  {
    "movmemsi-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4062 */
  {
    "movmemsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movmemsi,
    &operand_data[934],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "ashlsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashlsi3,
    &operand_data[765],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "ashrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrsi3,
    &operand_data[765],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "lshrsi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrsi3,
    &operand_data[765],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "ashldi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashldi3,
    &operand_data[938],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "ashrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ashrdi3,
    &operand_data[938],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4082 */
  {
    "lshrdi3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_lshrdi3,
    &operand_data[938],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "lshrdi3+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[773],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "lshrdi3+2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[773],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "lshrdi3+3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[773],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "lshrdi3+4",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[778],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "cmpsi-3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[778],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4224 */
  {
    "cmpsi-2",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[778],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4245 */
  {
    "cmpsi-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[941],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4296 */
  {
    "cmpsi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpsi,
    &operand_data[944],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4296 */
  {
    "cmpdi",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpdi,
    &operand_data[946],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4307 */
  {
    "cmpsf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpsf,
    &operand_data[784],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4307 */
  {
    "cmpdf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_cmpdf,
    &operand_data[787],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bunordered",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bunordered,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bordered",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bordered,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bunlt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bunlt,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bunge",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bunge,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "buneq",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_buneq,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bltgt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bltgt,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bunle",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bunle,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bungt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bungt,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "beq",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_beq,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bne",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bne,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bgt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bgt,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bge",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bge,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "blt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_blt,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "ble",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_ble,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bgtu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bgtu,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bgeu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bgeu,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bltu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bltu,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4456 */
  {
    "bleu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_bleu,
    &operand_data[425],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4469 */
  {
    "condjump",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_condjump,
    &operand_data[948],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4482 */
  {
    "seq",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_seq,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4510 */
  {
    "sne",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sne,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4526 */
  {
    "sgt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sgt,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4551 */
  {
    "sge",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sge,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4567 */
  {
    "slt",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_slt,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4597 */
  {
    "sle",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sle,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4631 */
  {
    "sgtu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sgtu,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4656 */
  {
    "sgeu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sgeu,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4672 */
  {
    "sltu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sltu,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4702 */
  {
    "sleu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sleu,
    &operand_data[765],
    1,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4813 */
  {
    "indirect_jump",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_indirect_jump,
    &operand_data[426],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4832 */
  {
    "tablejump",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_tablejump,
    &operand_data[950],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4868 */
  {
    "builtin_setjmp_setup",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_builtin_setjmp_setup,
    &operand_data[426],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4883 */
  {
    "builtin_longjmp",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_builtin_longjmp,
    &operand_data[426],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4920 */
  {
    "prologue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_prologue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4940 */
  {
    "epilogue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_epilogue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4948 */
  {
    "sibcall_epilogue",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall_epilogue,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:4977 */
  {
    "eh_return",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_eh_return,
    &operand_data[952],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5008 */
  {
    "eh_return+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[953],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5018 */
  {
    "sibcall-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[0],
    0,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5077 */
  {
    "sibcall",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall,
    &operand_data[955],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5095 */
  {
    "sibcall_value",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sibcall_value,
    &operand_data[955],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5126 */
  {
    "call",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call,
    &operand_data[955],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5174 */
  {
    "call+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[959],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5200 */
  {
    "call_value",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_call_value,
    &operand_data[955],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5213 */
  {
    "call_value+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[961],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5243 */
  {
    "untyped_call-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[961],
    4,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5280 */
  {
    "untyped_call",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_untyped_call,
    &operand_data[955],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5386 */
  {
    "movsicc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movsicc,
    &operand_data[965],
    4,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5386 */
  {
    "movdicc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdicc,
    &operand_data[969],
    4,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5398 */
  {
    "movsfcc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movsfcc,
    &operand_data[973],
    4,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5398 */
  {
    "movdfcc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movdfcc,
    &operand_data[977],
    4,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md:5452 */
  {
    "movdfcc+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[981],
    1,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:49 */
  {
    "movv2sfcc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_movv2sfcc,
    &operand_data[982],
    4,
    2,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:126 */
  {
    "vec_initv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_vec_initv2sf,
    &operand_data[985],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:174 */
  {
    "vec_setv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_vec_setv2sf,
    &operand_data[987],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:194 */
  {
    "mips_cvt_ps_s",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mips_cvt_ps_s,
    &operand_data[990],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:210 */
  {
    "mips_cvt_s_pl",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mips_cvt_s_pl,
    &operand_data[992],
    2,
    1,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:218 */
  {
    "mips_cvt_s_pu",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mips_cvt_s_pu,
    &operand_data[992],
    2,
    1,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:280 */
  {
    "mips_abs_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_mips_abs_ps,
    &operand_data[984],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:324 */
  {
    "mips_abs_ps+1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[994],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:353 */
  {
    "scc_ps-1",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    0,
    &operand_data[994],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:410 */
  {
    "scc_ps",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_scc_ps,
    &operand_data[1000],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:490 */
  {
    "single_cc",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_single_cc,
    &operand_data[948],
    2,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:583 */
  {
    "vcondv2sf",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_vcondv2sf,
    &operand_data[1002],
    6,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:598 */
  {
    "sminv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_sminv2sf3,
    &operand_data[995],
    3,
    0,
    0,
    0
  },
  /* /usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md:609 */
  {
    "smaxv2sf3",
#if HAVE_DESIGNATED_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    (insn_gen_fn) gen_smaxv2sf3,
    &operand_data[995],
    3,
    0,
    0,
    0
  },
};


const char *
get_insn_name (int code)
{
  if (code == NOOP_MOVE_INSN_CODE)
    return "NOOP_MOVE";
  else
    return insn_data[code].name;
}
