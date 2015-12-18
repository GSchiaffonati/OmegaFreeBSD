/* Generated automatically by the program `genconditions' from the target
   machine description file.  */

#include "bconfig.h"
#include "system.h"

/* It is necessary, but not entirely safe, to include the headers below
   in a generator program.  As a defensive measure, don't do so when the
   table isn't going to have anything in it.  */
#if GCC_VERSION >= 3001

/* Do not allow checking to confuse the issue.  */
#undef ENABLE_CHECKING
#undef ENABLE_TREE_CHECKING
#undef ENABLE_RTL_CHECKING
#undef ENABLE_RTL_FLAG_CHECKING
#undef ENABLE_GC_CHECKING
#undef ENABLE_GC_ALWAYS_COLLECT

#include "coretypes.h"
#include "tm.h"
#include "insn-constants.h"
#include "rtl.h"
#include "tm_p.h"
#include "function.h"

/* Fake - insn-config.h doesn't exist yet.  */
#define MAX_RECOG_OPERANDS 10
#define MAX_DUP_OPERANDS 10
#define MAX_INSNS_PER_SPLIT 5

#include "regs.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "toplev.h"
#include "reload.h"
#include "tm-constrs.h"

#define HAVE_eh_return 1
#include "except.h"

/* Dummy external declarations.  */
extern rtx insn;
extern rtx ins1;
extern rtx operands[];

#endif /* gcc >= 3.0.1 */

/* Structure definition duplicated from gensupport.h rather than
   drag in that file and its dependencies.  */
struct c_test
{
  const char *expr;
  int value;
};

/* This table lists each condition found in the machine description.
   Each condition is mapped to its truth value (0 or 1), or -1 if that
   cannot be calculated at compile time.
   If we don't have __builtin_constant_p, or it's not acceptable in array
   initializers, fall back to assuming that all conditions potentially
   vary at run time.  It works in 3.0.1 and later; 3.0 only when not
   optimizing.  */

#if GCC_VERSION >= 3001
static const struct c_test insn_conditions[] = {

#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_FIX_R4000\n\
   && !(ZERO_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120)",
    __builtin_constant_p 
#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(ZERO_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
    ? (int) 
#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(ZERO_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
    : -1 },
  { "(ISA_HAS_ROTR_DI) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 4263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_DI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 4263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_DI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(!ISA_MIPS1) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GET_CODE (operands[2]) == CONST_INT\n\
   && INTVAL (operands[2]) > 8\n\
   && INTVAL (operands[2]) <= 16) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 4228 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 4228 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 5122 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_SIBCALLS && SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 5122 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SIBCALLS && SIBLING_CALL_P (insn))
    ? (int) 
#line 5122 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SIBCALLS && SIBLING_CALL_P (insn))
    : -1 },
#line 1423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MADD_MSUB",
    __builtin_constant_p 
#line 1423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MADD_MSUB)
    ? (int) 
#line 1423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MADD_MSUB)
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && HONOR_SIGNED_ZEROS (SFmode)\n\
   && !HONOR_NANS (SFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)
   && !HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (SFmode)
   && !HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(!ISA_HAS_MACCHI) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 3929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 3929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && (Pmode == DImode)",
    __builtin_constant_p (
#line 5326 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 5326 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
#line 3725 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) < 0\n\
	&& INTVAL (operands[1]) >= -0x80)\n\
       || (INTVAL (operands[1]) >= 32\n\
	   && INTVAL (operands[1]) <= 31 + 0x7f))",
    __builtin_constant_p 
#line 3725 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32
	   && INTVAL (operands[1]) <= 31 + 0x7f)))
    ? (int) 
#line 3725 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32
	   && INTVAL (operands[1]) <= 31 + 0x7f)))
    : -1 },
  { "(mips_use_ins_ext_p (operands[1], operands[2], operands[3])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 5314 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_PREFETCH && TARGET_EXPLICIT_RELOCS",
    __builtin_constant_p 
#line 5314 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCH && TARGET_EXPLICIT_RELOCS)
    ? (int) 
#line 5314 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCH && TARGET_EXPLICIT_RELOCS)
    : -1 },
#line 4132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_MIPS16",
    __builtin_constant_p 
#line 4132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16)
    ? (int) 
#line 4132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16)
    : -1 },
  { "(TARGET_4300_MUL_FIX) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 950 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 950 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 3463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && INTVAL (operands[1]) >= 0x100\n\
   && INTVAL (operands[1]) <= 0xff + 0x7f",
    __builtin_constant_p 
#line 3463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) >= 0x100
   && INTVAL (operands[1]) <= 0xff + 0x7f)
    ? (int) 
#line 3463 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && INTVAL (operands[1]) >= 0x100
   && INTVAL (operands[1]) <= 0xff + 0x7f)
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 1205 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GP_REG_P (true_regnum (operands[0]))\n\
   && true_regnum (operands[3]) == LO_REGNUM",
    __builtin_constant_p 
#line 1205 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[3]) == LO_REGNUM)
    ? (int) 
#line 1205 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[3]) == LO_REGNUM)
    : -1 },
#line 2697 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT",
    __builtin_constant_p 
#line 2697 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT)
    ? (int) 
#line 2697 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_FLOAT64 && TARGET_DOUBLE_FLOAT)
    : -1 },
#line 5011 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_DEBUG_D_MODE",
    __builtin_constant_p 
#line 5011 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE)
    ? (int) 
#line 5011 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE)
    : -1 },
  { "(TARGET_64BIT && !TARGET_MIPS16) && ( reload_completed)",
    __builtin_constant_p (
#line 2286 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16) && 
#line 2288 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 2286 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16) && 
#line 2288 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
  { "(!TARGET_MIPS16) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 4713 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 4713 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 622 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_COND_TRAP",
    __builtin_constant_p 
#line 622 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP)
    ? (int) 
#line 622 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP)
    : -1 },
#line 3929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!ISA_HAS_MACCHI",
    __builtin_constant_p 
#line 3929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI)
    ? (int) 
#line 3929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MACCHI)
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected) && ( reload_completed)",
    __builtin_constant_p (
#line 3096 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected) && 
#line 3098 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 3096 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected) && 
#line 3098 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 2249 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_MIPS16 && INTVAL (operands[2]) >= 32",
    __builtin_constant_p 
#line 2249 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16 && INTVAL (operands[2]) >= 32)
    ? (int) 
#line 2249 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16 && INTVAL (operands[2]) >= 32)
    : -1 },
  { "(HAVE_AS_TLS && !TARGET_MIPS16) && (Pmode == SImode)",
    __builtin_constant_p (
#line 5472 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(HAVE_AS_TLS && !TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 5472 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(HAVE_AS_TLS && !TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 1402 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "GENERATE_MULT3_SI && peep2_reg_dead_p (3, operands[1])",
    __builtin_constant_p 
#line 1402 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (3, operands[1]))
    ? (int) 
#line 1402 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (3, operands[1]))
    : -1 },
#line 1105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_FIX_R4000)
    ? (int) 
#line 1105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_FIX_R4000)
    : -1 },
  { "(!ISA_MIPS1) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_MIPS1) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(ISA_HAS_COND_TRAP) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 639 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 639 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_COND_TRAP) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_PAIRED_SINGLE_FLOAT) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 29 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 29 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(ISA_HAS_CLZ_CLO) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2004 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2004 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 2494 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "GENERATE_MIPS16E",
    __builtin_constant_p 
#line 2494 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MIPS16E)
    ? (int) 
#line 2494 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MIPS16E)
    : -1 },
  { "(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(ISA_HAS_FP4 && TARGET_FUSED_MADD) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 3276 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && TARGET_MIPS16\n\
   && (register_operand (operands[0], DImode)\n\
       || register_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 3276 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode)))
    ? (int) 
#line 3276 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode)))
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
#line 3630 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) < 0\n\
	&& INTVAL (operands[1]) >= -0x80)\n\
       || (INTVAL (operands[1]) >= 32 * 2\n\
	   && INTVAL (operands[1]) <= 31 * 2 + 0x7e)\n\
       || (INTVAL (operands[1]) >= 0\n\
	   && INTVAL (operands[1]) < 32 * 2\n\
	   && (INTVAL (operands[1]) & 1) != 0))",
    __builtin_constant_p 
#line 3630 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 2
	   && INTVAL (operands[1]) <= 31 * 2 + 0x7e)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 2
	   && (INTVAL (operands[1]) & 1) != 0)))
    ? (int) 
#line 3630 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 2
	   && INTVAL (operands[1]) <= 31 * 2 + 0x7e)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 2
	   && (INTVAL (operands[1]) & 1) != 0)))
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS) && ( flow2_completed)",
    __builtin_constant_p (
#line 3042 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS) && 
#line 3044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( flow2_completed))
    ? (int) (
#line 3042 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS) && 
#line 3044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( flow2_completed))
    : -1 },
#line 2004 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_CLZ_CLO",
    __builtin_constant_p 
#line 2004 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO)
    ? (int) 
#line 2004 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CLZ_CLO)
    : -1 },
#line 4207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && TARGET_MIPS16",
    __builtin_constant_p 
#line 4207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16)
    ? (int) 
#line 4207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16)
    : -1 },
#line 3783 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16\n\
   && (register_operand (operands[0], SFmode)\n\
       || register_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 3783 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || register_operand (operands[1], SFmode)))
    ? (int) 
#line 3783 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || register_operand (operands[1], SFmode)))
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
#line 1682 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MULHI",
    __builtin_constant_p 
#line 1682 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
    ? (int) 
#line 1682 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULHI)
    : -1 },
#line 5180 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && TARGET_SPLIT_CALLS && (operands[2] = insn)",
    __builtin_constant_p 
#line 5180 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[2] = insn))
    ? (int) 
#line 5180 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[2] = insn))
    : -1 },
  { "((!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && (TARGET_64BIT)) && ( reload_completed && REG_P (operands[1]))",
    __builtin_constant_p ((
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 2509 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    ? (int) ((
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 2509 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    : -1 },
#line 1649 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!ISA_HAS_MULHI && !TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1649 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000)
    ? (int) 
#line 1649 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_MULHI && !TARGET_FIX_R4000)
    : -1 },
  { "(ISA_HAS_CONDMOVE) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 5404 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 5404 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 1598 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && ISA_HAS_MULS",
    __builtin_constant_p 
#line 1598 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MULS)
    ? (int) 
#line 1598 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MULS)
    : -1 },
  { "(mips_use_ins_ext_p (operands[0], operands[1], operands[2])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2965 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2965 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(ISA_HAS_FP4 && TARGET_FUSED_MADD) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
  { "(TARGET_SB1 && flag_unsafe_math_optimizations) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1 && flag_unsafe_math_optimizations) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1 && flag_unsafe_math_optimizations) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 2626 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && !ISA_HAS_TRUNC_W",
    __builtin_constant_p 
#line 2626 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && !ISA_HAS_TRUNC_W)
    ? (int) 
#line 2626 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && !ISA_HAS_TRUNC_W)
    : -1 },
#line 4885 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_ABICALLS",
    __builtin_constant_p 
#line 4885 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS)
    ? (int) 
#line 4885 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS)
    : -1 },
#line 3019 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[0])",
    __builtin_constant_p 
#line 3019 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[0]))
    ? (int) 
#line 3019 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[0]))
    : -1 },
#line 4999 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "! TARGET_64BIT",
    __builtin_constant_p 
#line 4999 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(! TARGET_64BIT)
    ? (int) 
#line 4999 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(! TARGET_64BIT)
    : -1 },
#line 1224 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MACC",
    __builtin_constant_p 
#line 1224 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC)
    ? (int) 
#line 1224 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC)
    : -1 },
  { "(ISA_HAS_CONDMOVE) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 5404 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 5404 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(!TARGET_FIX_VR4120) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1891 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 1891 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 1460 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GP_REG_P (true_regnum (operands[0]))\n\
   && true_regnum (operands[1]) == LO_REGNUM",
    __builtin_constant_p 
#line 1460 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[1]) == LO_REGNUM)
    ? (int) 
#line 1460 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && true_regnum (operands[1]) == LO_REGNUM)
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && (Pmode == DImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3134 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3134 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS) && (Pmode == DImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3165 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3165 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 3287 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_MIPS16\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 3287 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 3287 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
#line 3096 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected",
    __builtin_constant_p 
#line 3096 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected)
    ? (int) 
#line 3096 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS && cse_not_expected)
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 1186 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GP_REG_P (true_regnum (operands[0]))\n\
   && GP_REG_P (true_regnum (operands[3]))",
    __builtin_constant_p 
#line 1186 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[3])))
    ? (int) 
#line 1186 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[3])))
    : -1 },
  { "(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 4018 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "mips_current_loadgp_style () == LOADGP_ABSOLUTE",
    __builtin_constant_p 
#line 4018 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_current_loadgp_style () == LOADGP_ABSOLUTE)
    ? (int) 
#line 4018 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_current_loadgp_style () == LOADGP_ABSOLUTE)
    : -1 },
  { "(!HONOR_NANS (SFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(ISA_HAS_SEB_SEH) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2525 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2525 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 1523 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1523 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000)
    ? (int) 
#line 1523 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && TARGET_FIX_R4000)
    : -1 },
#line 3576 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16\n\
   && (register_operand (operands[0], HImode)\n\
       || reg_or_0_operand (operands[1], HImode))",
    __builtin_constant_p 
#line 3576 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || reg_or_0_operand (operands[1], HImode)))
    ? (int) 
#line 3576 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || reg_or_0_operand (operands[1], HImode)))
    : -1 },
#line 1727 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "(TARGET_MAD || ISA_HAS_MACC)\n\
   && !TARGET_64BIT",
    __builtin_constant_p 
#line 1727 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_MAD || ISA_HAS_MACC)
   && !TARGET_64BIT)
    ? (int) 
#line 1727 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_MAD || ISA_HAS_MACC)
   && !TARGET_64BIT)
    : -1 },
  { "(ISA_HAS_MACCHI) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 3939 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 3939 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 1441 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GP_REG_P (true_regnum (operands[0]))\n\
   && GP_REG_P (true_regnum (operands[1]))",
    __builtin_constant_p 
#line 1441 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[1])))
    ? (int) 
#line 1441 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_DEBUG_D_MODE
   && GP_REG_P (true_regnum (operands[0]))
   && GP_REG_P (true_regnum (operands[1])))
    : -1 },
  { "(TARGET_ABICALLS && TARGET_OLDABI) && ( reload_completed)",
    __builtin_constant_p (
#line 5021 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI) && 
#line 5023 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 5021 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI) && 
#line 5023 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 2577 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && ISA_HAS_TRUNC_W",
    __builtin_constant_p 
#line 2577 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && ISA_HAS_TRUNC_W)
    ? (int) 
#line 2577 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && ISA_HAS_TRUNC_W)
    : -1 },
#line 3898 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_PAIRED_SINGLE_FLOAT\n\
   && TARGET_64BIT\n\
   && (register_operand (operands[0], V2SFmode)\n\
       || reg_or_0_operand (operands[1], V2SFmode))",
    __builtin_constant_p 
#line 3898 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT
   && TARGET_64BIT
   && (register_operand (operands[0], V2SFmode)
       || reg_or_0_operand (operands[1], V2SFmode)))
    ? (int) 
#line 3898 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT
   && TARGET_64BIT
   && (register_operand (operands[0], V2SFmode)
       || reg_or_0_operand (operands[1], V2SFmode)))
    : -1 },
#line 2965 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "mips_use_ins_ext_p (operands[0], operands[1], operands[2])",
    __builtin_constant_p 
#line 2965 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2]))
    ? (int) 
#line 2965 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[0], operands[1], operands[2]))
    : -1 },
#line 1128 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MACC && !GENERATE_MULT3_SI",
    __builtin_constant_p 
#line 1128 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !GENERATE_MULT3_SI)
    ? (int) 
#line 1128 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !GENERATE_MULT3_SI)
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && !HONOR_SIGNED_ZEROS (DFmode)\n\
   && !HONOR_NANS (DFmode)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (DFmode)
   && !HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (DFmode)
   && !HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 1891 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_FIX_VR4120",
    __builtin_constant_p 
#line 1891 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120)
    ? (int) 
#line 1891 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_VR4120)
    : -1 },
  { "(TARGET_64BIT && TARGET_MIPS16) && ( reload_completed)",
    __builtin_constant_p (
#line 873 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16) && 
#line 875 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 873 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16) && 
#line 875 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_64BIT)) && (TARGET_64BIT)",
    __builtin_constant_p ((
#line 5362 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) ((
#line 5362 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 3394 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16\n\
   && (register_operand (operands[0], SImode)\n\
       || register_operand (operands[1], SImode))",
    __builtin_constant_p 
#line 3394 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || register_operand (operands[1], SImode)))
    ? (int) 
#line 3394 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || register_operand (operands[1], SImode)))
    : -1 },
#line 736 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) > 0x7f\n\
	&& INTVAL (operands[1]) <= 0x7f + 0x7f)\n\
       || (INTVAL (operands[1]) < - 0x80\n\
	   && INTVAL (operands[1]) >= - 0x80 - 0x80))",
    __builtin_constant_p 
#line 736 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0x7f
	&& INTVAL (operands[1]) <= 0x7f + 0x7f)
       || (INTVAL (operands[1]) < - 0x80
	   && INTVAL (operands[1]) >= - 0x80 - 0x80)))
    ? (int) 
#line 736 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0x7f
	&& INTVAL (operands[1]) <= 0x7f + 0x7f)
       || (INTVAL (operands[1]) < - 0x80
	   && INTVAL (operands[1]) >= - 0x80 - 0x80)))
    : -1 },
#line 3422 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) < 0\n\
	&& INTVAL (operands[1]) >= -0x80)\n\
       || (INTVAL (operands[1]) >= 32 * 4\n\
	   && INTVAL (operands[1]) <= 31 * 4 + 0x7c)\n\
       || (INTVAL (operands[1]) >= 0\n\
	   && INTVAL (operands[1]) < 32 * 4\n\
	   && (INTVAL (operands[1]) & 3) != 0))",
    __builtin_constant_p 
#line 3422 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 4
	   && INTVAL (operands[1]) <= 31 * 4 + 0x7c)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 4
	   && (INTVAL (operands[1]) & 3) != 0)))
    ? (int) 
#line 3422 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x80)
       || (INTVAL (operands[1]) >= 32 * 4
	   && INTVAL (operands[1]) <= 31 * 4 + 0x7c)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 4
	   && (INTVAL (operands[1]) & 3) != 0)))
    : -1 },
  { "(!HONOR_NANS (V2SFmode)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
  { "(!TARGET_FIX_R4000) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1094 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 1094 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_MIPS16) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 4725 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 4725 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 613 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
  { "TARGET_PAIRED_SINGLE_FLOAT",
    __builtin_constant_p 
#line 613 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT)
    ? (int) 
#line 613 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT)
    : -1 },
#line 2525 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_SEB_SEH",
    __builtin_constant_p 
#line 2525 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH)
    ? (int) 
#line 2525 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_SEB_SEH)
    : -1 },
  { "(!TARGET_4300_MUL_FIX) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 937 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 937 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 4514 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16",
    __builtin_constant_p 
#line 4514 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16)
    ? (int) 
#line 4514 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16)
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == SImode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 4961 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "mips_can_use_return_insn ()",
    __builtin_constant_p 
#line 4961 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_can_use_return_insn ())
    ? (int) 
#line 4961 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_can_use_return_insn ())
    : -1 },
  { "(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[0])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 3019 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[0])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 3019 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[0])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_ABICALLS) && (Pmode == SImode)",
    __builtin_constant_p (
#line 5059 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 5059 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
  { "(TARGET_PAIRED_SINGLE_FLOAT) && ( reload_completed)",
    __builtin_constant_p (
#line 332 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 334 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
( reload_completed))
    ? (int) (
#line 332 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_PAIRED_SINGLE_FLOAT) && 
#line 334 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
( reload_completed))
    : -1 },
  { "(!TARGET_MIPS16) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3198 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 3198 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
  { "(TARGET_MIPS16) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 3207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT)",
    __builtin_constant_p ((
#line 5362 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) ((
#line 5362 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 966 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
  { "TARGET_DSP && !TARGET_64BIT",
    __builtin_constant_p 
#line 966 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT)
    ? (int) 
#line 966 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP && !TARGET_64BIT)
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 3839 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16\n\
   && (register_operand (operands[0], DFmode)\n\
       || register_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 3839 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || register_operand (operands[1], DFmode)))
    ? (int) 
#line 3839 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || register_operand (operands[1], DFmode)))
    : -1 },
#line 2837 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_64BIT && TARGET_DOUBLE_FLOAT",
    __builtin_constant_p 
#line 2837 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && TARGET_DOUBLE_FLOAT)
    ? (int) 
#line 2837 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_64BIT && TARGET_DOUBLE_FLOAT)
    : -1 },
#line 3817 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 3817 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 3817 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
#line 1363 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "GENERATE_MULT3_SI\n\
   && true_regnum (operands[1]) == LO_REGNUM\n\
   && peep2_reg_dead_p (2, operands[1])\n\
   && GP_REG_P (true_regnum (operands[3]))",
    __builtin_constant_p 
#line 1363 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI
   && true_regnum (operands[1]) == LO_REGNUM
   && peep2_reg_dead_p (2, operands[1])
   && GP_REG_P (true_regnum (operands[3])))
    ? (int) 
#line 1363 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI
   && true_regnum (operands[1]) == LO_REGNUM
   && peep2_reg_dead_p (2, operands[1])
   && GP_REG_P (true_regnum (operands[3])))
    : -1 },
  { "(TARGET_DSP) && (TARGET_DSP)",
    __builtin_constant_p (
#line 785 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    ? (int) (
#line 785 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP) && 
#line 16 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP))
    : -1 },
  { "(TARGET_MIPS3D) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 2998 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[1])",
    __builtin_constant_p 
#line 2998 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[1]))
    ? (int) 
#line 2998 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (SImode, operands[1]))
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == DImode)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 5100 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_SIBCALLS",
    __builtin_constant_p 
#line 5100 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SIBCALLS)
    ? (int) 
#line 5100 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SIBCALLS)
    : -1 },
#line 4001 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "mips_current_loadgp_style () == LOADGP_NEWABI",
    __builtin_constant_p 
#line 4001 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_current_loadgp_style () == LOADGP_NEWABI)
    ? (int) 
#line 4001 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_current_loadgp_style () == LOADGP_NEWABI)
    : -1 },
  { "(!TARGET_MIPS16) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3198 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 3198 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 826 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && REG_P (operands[1])\n\
   && M16_REG_P (REGNO (operands[1]))\n\
   && REGNO (operands[0]) != REGNO (operands[1])\n\
   && GET_CODE (operands[2]) == CONST_INT\n\
   && ((INTVAL (operands[2]) > 0x7\n\
	&& INTVAL (operands[2]) <= 0x7 + 0xf)\n\
       || (INTVAL (operands[2]) < - 0x8\n\
	   && INTVAL (operands[2]) >= - 0x8 - 0x10))",
    __builtin_constant_p 
#line 826 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0xf)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x10)))
    ? (int) 
#line 826 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0xf)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x10)))
    : -1 },
#line 3939 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MACCHI",
    __builtin_constant_p 
#line 3939 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI)
    ? (int) 
#line 3939 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACCHI)
    : -1 },
#line 5392 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_CONDMOVE",
    __builtin_constant_p 
#line 5392 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE)
    ? (int) 
#line 5392 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE)
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == SImode)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS) && (Pmode == SImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3165 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3165 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 3383 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16\n\
   && (register_operand (operands[0], SImode)\n\
       || reg_or_0_operand (operands[1], SImode))",
    __builtin_constant_p 
#line 3383 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || reg_or_0_operand (operands[1], SImode)))
    ? (int) 
#line 3383 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], SImode)
       || reg_or_0_operand (operands[1], SImode)))
    : -1 },
#line 4067 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16 && !TARGET_MEMCPY",
    __builtin_constant_p 
#line 4067 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && !TARGET_MEMCPY)
    ? (int) 
#line 4067 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && !TARGET_MEMCPY)
    : -1 },
#line 1586 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1586 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000)
    ? (int) 
#line 1586 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000)
    : -1 },
#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && !TARGET_FIX_R4000\n\
   && !(SIGN_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120)",
    __builtin_constant_p 
#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(SIGN_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
    ? (int) 
#line 1701 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000
   && !(SIGN_EXTEND == ZERO_EXTEND && TARGET_FIX_VR4120))
    : -1 },
#line 1610 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && ISA_HAS_MSAC",
    __builtin_constant_p 
#line 1610 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MSAC)
    ? (int) 
#line 1610 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && ISA_HAS_MSAC)
    : -1 },
  { "(ISA_HAS_CONDMOVE) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 5392 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 5392 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(!HONOR_NANS (DFmode)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 2044 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == SImode)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(!TARGET_4300_MUL_FIX) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 937 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 937 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_4300_MUL_FIX) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(TARGET_64BIT && !TARGET_FIX_R4000) && ( reload_completed)",
    __builtin_constant_p (
#line 1536 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000) && 
#line 1538 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 1536 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && !TARGET_FIX_R4000) && 
#line 1538 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 1058 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && GENERATE_MULT3_DI",
    __builtin_constant_p 
#line 1058 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && GENERATE_MULT3_DI)
    ? (int) 
#line 1058 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && GENERATE_MULT3_DI)
    : -1 },
#line 5274 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_SPLIT_CALLS",
    __builtin_constant_p 
#line 5274 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS)
    ? (int) 
#line 5274 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SPLIT_CALLS)
    : -1 },
#line 3265 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && !TARGET_MIPS16\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 3265 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 3265 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && (Pmode == DImode)",
    __builtin_constant_p (
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
#line 3327 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && TARGET_MIPS16 && reload_completed\n\
   && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) < 0\n\
	&& INTVAL (operands[1]) >= -0x10)\n\
       || (INTVAL (operands[1]) >= 32 * 8\n\
	   && INTVAL (operands[1]) <= 31 * 8 + 0x8)\n\
       || (INTVAL (operands[1]) >= 0\n\
	   && INTVAL (operands[1]) < 32 * 8\n\
	   && (INTVAL (operands[1]) & 7) != 0))",
    __builtin_constant_p 
#line 3327 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16 && reload_completed
   && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x10)
       || (INTVAL (operands[1]) >= 32 * 8
	   && INTVAL (operands[1]) <= 31 * 8 + 0x8)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 8
	   && (INTVAL (operands[1]) & 7) != 0)))
    ? (int) 
#line 3327 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16 && reload_completed
   && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) < 0
	&& INTVAL (operands[1]) >= -0x10)
       || (INTVAL (operands[1]) >= 32 * 8
	   && INTVAL (operands[1]) <= 31 * 8 + 0x8)
       || (INTVAL (operands[1]) >= 0
	   && INTVAL (operands[1]) < 32 * 8
	   && (INTVAL (operands[1]) & 7) != 0)))
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && !HONOR_SIGNED_ZEROS (SFmode)\n\
   && !HONOR_NANS (SFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (SFmode)
   && !HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (SFmode)
   && !HONOR_NANS (SFmode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 483 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
  { "TARGET_MIPS3D",
    __builtin_constant_p 
#line 483 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D)
    ? (int) 
#line 483 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D)
    : -1 },
#line 4263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_ROTR_SI",
    __builtin_constant_p 
#line 4263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_SI)
    ? (int) 
#line 4263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_ROTR_SI)
    : -1 },
#line 3298 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT && TARGET_MIPS16\n\
   && (register_operand (operands[0], DImode)\n\
       || register_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 3298 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode)))
    ? (int) 
#line 3298 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT && TARGET_MIPS16
   && (register_operand (operands[0], DImode)
       || register_operand (operands[1], DImode)))
    : -1 },
#line 1495 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT || !TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1495 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT || !TARGET_FIX_R4000)
    ? (int) 
#line 1495 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT || !TARGET_FIX_R4000)
    : -1 },
#line 3772 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_SOFT_FLOAT && !TARGET_MIPS16\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 3772 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SOFT_FLOAT && !TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 3772 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SOFT_FLOAT && !TARGET_MIPS16
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 3987 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT",
    __builtin_constant_p 
#line 3987 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT)
    ? (int) 
#line 3987 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !TARGET_64BIT)
    : -1 },
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT",
    __builtin_constant_p 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)
    ? (int) 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT)
    : -1 },
  { "(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1957 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && flag_unsafe_math_optimizations) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 3861 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && !TARGET_64BIT\n\
   && mips_split_64bit_move_p (operands[0], operands[1])",
    __builtin_constant_p 
#line 3861 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_64BIT
   && mips_split_64bit_move_p (operands[0], operands[1]))
    ? (int) 
#line 3861 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && !TARGET_64BIT
   && mips_split_64bit_move_p (operands[0], operands[1]))
    : -1 },
#line 1295 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MACC && reload_completed",
    __builtin_constant_p 
#line 1295 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && reload_completed)
    ? (int) 
#line 1295 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && reload_completed)
    : -1 },
#line 5220 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && TARGET_SPLIT_CALLS && (operands[3] = insn)",
    __builtin_constant_p 
#line 5220 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[3] = insn))
    ? (int) 
#line 5220 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[3] = insn))
    : -1 },
#line 765 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && REG_P (operands[1])\n\
   && M16_REG_P (REGNO (operands[1]))\n\
   && REGNO (operands[0]) != REGNO (operands[1])\n\
   && GET_CODE (operands[2]) == CONST_INT\n\
   && ((INTVAL (operands[2]) > 0x7\n\
	&& INTVAL (operands[2]) <= 0x7 + 0x7f)\n\
       || (INTVAL (operands[2]) < - 0x8\n\
	   && INTVAL (operands[2]) >= - 0x8 - 0x80))",
    __builtin_constant_p 
#line 765 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0x7f)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x80)))
    ? (int) 
#line 765 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && REG_P (operands[1])
   && M16_REG_P (REGNO (operands[1]))
   && REGNO (operands[0]) != REGNO (operands[1])
   && GET_CODE (operands[2]) == CONST_INT
   && ((INTVAL (operands[2]) > 0x7
	&& INTVAL (operands[2]) <= 0x7 + 0x7f)
       || (INTVAL (operands[2]) < - 0x8
	   && INTVAL (operands[2]) >= - 0x8 - 0x80)))
    : -1 },
  { "(GENERATE_MIPS16E) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2494 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2494 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MIPS16E) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "(ISA_HAS_FP4 && TARGET_FUSED_MADD) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 1758 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4 && TARGET_FUSED_MADD) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 3828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "(TARGET_SOFT_FLOAT || TARGET_SINGLE_FLOAT) && !TARGET_MIPS16\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 3828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_SOFT_FLOAT || TARGET_SINGLE_FLOAT) && !TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 3828 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_SOFT_FLOAT || TARGET_SINGLE_FLOAT) && !TARGET_MIPS16
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT",
    __builtin_constant_p 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)
    ? (int) 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)
    : -1 },
#line 3520 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_8CC && TARGET_HARD_FLOAT",
    __builtin_constant_p 
#line 3520 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_8CC && TARGET_HARD_FLOAT)
    ? (int) 
#line 3520 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_8CC && TARGET_HARD_FLOAT)
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && (Pmode == DImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3148 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 3148 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && HONOR_SIGNED_ZEROS (V2SFmode)\n\
   && !HONOR_NANS (V2SFmode)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (V2SFmode)
   && !HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (V2SFmode)
   && !HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 1053 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
  { "TARGET_DSP",
    __builtin_constant_p 
#line 1053 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
    ? (int) 
#line 1053 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-dsp.md"
(TARGET_DSP)
    : -1 },
#line 797 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && REG_P (operands[0])\n\
   && M16_REG_P (REGNO (operands[0]))\n\
   && GET_CODE (operands[1]) == CONST_INT\n\
   && ((INTVAL (operands[1]) > 0xf\n\
	&& INTVAL (operands[1]) <= 0xf + 0xf)\n\
       || (INTVAL (operands[1]) < - 0x10\n\
	   && INTVAL (operands[1]) >= - 0x10 - 0x10))",
    __builtin_constant_p 
#line 797 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0xf
	&& INTVAL (operands[1]) <= 0xf + 0xf)
       || (INTVAL (operands[1]) < - 0x10
	   && INTVAL (operands[1]) >= - 0x10 - 0x10)))
    ? (int) 
#line 797 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && TARGET_64BIT && reload_completed && !TARGET_DEBUG_D_MODE
   && REG_P (operands[0])
   && M16_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == CONST_INT
   && ((INTVAL (operands[1]) > 0xf
	&& INTVAL (operands[1]) <= 0xf + 0xf)
       || (INTVAL (operands[1]) < - 0x10
	   && INTVAL (operands[1]) >= - 0x10 - 0x10)))
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && !HONOR_SIGNED_ZEROS (V2SFmode)\n\
   && !HONOR_NANS (V2SFmode)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (V2SFmode)
   && !HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1808 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && !HONOR_SIGNED_ZEROS (V2SFmode)
   && !HONOR_NANS (V2SFmode)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 1094 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1094 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000)
    ? (int) 
#line 1094 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_R4000)
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == DImode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "((ISA_HAS_FP4) && (Pmode == DImode)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) ((
#line 3552 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_FP4) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(TARGET_MIPS16) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 3207 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 2588 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !ISA_HAS_TRUNC_W",
    __builtin_constant_p 
#line 2588 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !ISA_HAS_TRUNC_W)
    ? (int) 
#line 2588 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && !ISA_HAS_TRUNC_W)
    : -1 },
#line 1629 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MULHI || !TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1629 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULHI || !TARGET_FIX_R4000)
    ? (int) 
#line 1629 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULHI || !TARGET_FIX_R4000)
    : -1 },
  { "(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD\n\
   && HONOR_SIGNED_ZEROS (DFmode)\n\
   && !HONOR_NANS (DFmode)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)
   && !HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 1795 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_NMADD_NMSUB && TARGET_FUSED_MADD
   && HONOR_SIGNED_ZEROS (DFmode)
   && !HONOR_NANS (DFmode)) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 3806 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && TARGET_64BIT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 3806 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 3806 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT && TARGET_64BIT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
#line 4228 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE\n\
   && GET_CODE (operands[2]) == CONST_INT\n\
   && INTVAL (operands[2]) > 8\n\
   && INTVAL (operands[2]) <= 16",
    __builtin_constant_p 
#line 4228 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16)
    ? (int) 
#line 4228 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && !TARGET_DEBUG_D_MODE
   && GET_CODE (operands[2]) == CONST_INT
   && INTVAL (operands[2]) > 8
   && INTVAL (operands[2]) <= 16)
    : -1 },
  { "(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[1])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 2998 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[1])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 2998 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16 && mips_mem_fits_mode_p (DImode, operands[1])) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_64BIT)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 5021 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_ABICALLS && TARGET_OLDABI",
    __builtin_constant_p 
#line 5021 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI)
    ? (int) 
#line 5021 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS && TARGET_OLDABI)
    : -1 },
  { "(!TARGET_FIX_SB1 || flag_unsafe_math_optimizations) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 1827 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_SB1 || flag_unsafe_math_optimizations) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 1827 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_FIX_SB1 || flag_unsafe_math_optimizations) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && (Pmode == SImode)",
    __builtin_constant_p (
#line 5326 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 5326 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_PREFETCHX && TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 3068 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS",
    __builtin_constant_p 
#line 3068 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS)
    ? (int) 
#line 3068 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && ABI_HAS_64BIT_SYMBOLS)
    : -1 },
#line 3761 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 3761 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 3761 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 1716 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MAD",
    __builtin_constant_p 
#line 1716 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MAD)
    ? (int) 
#line 1716 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MAD)
    : -1 },
#line 1513 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_64BIT && !TARGET_FIX_R4000",
    __builtin_constant_p 
#line 1513 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_FIX_R4000)
    ? (int) 
#line 1513 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_64BIT && !TARGET_FIX_R4000)
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && (Pmode == SImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3134 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3132 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3134 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
  { "((ISA_HAS_CONDMOVE) && (TARGET_64BIT)) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) ((
#line 5377 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_CONDMOVE) && 
#line 415 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)) && 
#line 429 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 3595 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16\n\
   && (register_operand (operands[0], HImode)\n\
       || register_operand (operands[1], HImode))",
    __builtin_constant_p 
#line 3595 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || register_operand (operands[1], HImode)))
    ? (int) 
#line 3595 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], HImode)
       || register_operand (operands[1], HImode)))
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed && REG_P (operands[1]))",
    __builtin_constant_p (
#line 2360 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2368 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    ? (int) (
#line 2360 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2368 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    : -1 },
  { "(TARGET_FIX_R4000) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_FIX_R4000) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    ? (int) (
#line 1105 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_FIX_R4000) && 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT))
    : -1 },
#line 3683 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!TARGET_MIPS16\n\
   && (register_operand (operands[0], QImode)\n\
       || reg_or_0_operand (operands[1], QImode))",
    __builtin_constant_p 
#line 3683 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || reg_or_0_operand (operands[1], QImode)))
    ? (int) 
#line 3683 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || reg_or_0_operand (operands[1], QImode)))
    : -1 },
#line 1267 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MACC && !ISA_HAS_MSAC",
    __builtin_constant_p 
#line 1267 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC)
    ? (int) 
#line 1267 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC)
    : -1 },
  { "((TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && (Pmode == SImode)) && ( reload_completed)",
    __builtin_constant_p ((
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3148 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) ((
#line 3146 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS && !TARGET_XGOT) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)) && 
#line 3148 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "Pmode == SImode",
    __builtin_constant_p 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)
    ? (int) 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode)
    : -1 },
#line 2929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "mips_use_ins_ext_p (operands[1], operands[2], operands[3])",
    __builtin_constant_p 
#line 2929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3]))
    ? (int) 
#line 2929 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(mips_use_ins_ext_p (operands[1], operands[2], operands[3]))
    : -1 },
  { "(TARGET_MIPS3D) && (TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 424 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && TARGET_DOUBLE_FLOAT))
    : -1 },
#line 1081 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "GENERATE_MULT3_SI && peep2_reg_dead_p (2, operands[0])",
    __builtin_constant_p 
#line 1081 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (2, operands[0]))
    ? (int) 
#line 1081 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI && peep2_reg_dead_p (2, operands[0]))
    : -1 },
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "Pmode == DImode",
    __builtin_constant_p 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)
    ? (int) 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode)
    : -1 },
  { "(TARGET_SB1 && (!TARGET_FIX_SB1 || flag_unsafe_math_optimizations)) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1827 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1 && (!TARGET_FIX_SB1 || flag_unsafe_math_optimizations)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1827 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1 && (!TARGET_FIX_SB1 || flag_unsafe_math_optimizations)) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
#line 5253 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed && TARGET_SPLIT_CALLS && (operands[4] = insn)",
    __builtin_constant_p 
#line 5253 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[4] = insn))
    ? (int) 
#line 5253 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed && TARGET_SPLIT_CALLS && (operands[4] = insn))
    : -1 },
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E",
    __builtin_constant_p 
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E)
    ? (int) 
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E)
    : -1 },
#line 3702 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16\n\
   && (register_operand (operands[0], QImode)\n\
       || register_operand (operands[1], QImode))",
    __builtin_constant_p 
#line 3702 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || register_operand (operands[1], QImode)))
    ? (int) 
#line 3702 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16
   && (register_operand (operands[0], QImode)
       || register_operand (operands[1], QImode)))
    : -1 },
#line 1162 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "(TARGET_MIPS3900\n\
   || ISA_HAS_MADD_MSUB)\n\
   && !TARGET_MIPS16",
    __builtin_constant_p 
#line 1162 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_MIPS3900
   || ISA_HAS_MADD_MSUB)
   && !TARGET_MIPS16)
    ? (int) 
#line 1162 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
((TARGET_MIPS3900
   || ISA_HAS_MADD_MSUB)
   && !TARGET_MIPS16)
    : -1 },
  { "(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && ( reload_completed && REG_P (operands[1]))",
    __builtin_constant_p (
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 2509 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    ? (int) (
#line 2505 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(!ISA_HAS_SEB_SEH && !GENERATE_MIPS16E) && 
#line 2509 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && REG_P (operands[1])))
    : -1 },
#line 1033 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "GENERATE_MULT3_SI",
    __builtin_constant_p 
#line 1033 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI)
    ? (int) 
#line 1033 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(GENERATE_MULT3_SI)
    : -1 },
  { "(ISA_HAS_MACC && !ISA_HAS_MSAC) && ( reload_completed)",
    __builtin_constant_p (
#line 1267 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC) && 
#line 1269 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    ? (int) (
#line 1267 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MACC && !ISA_HAS_MSAC) && 
#line 1269 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed))
    : -1 },
#line 2615 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_HARD_FLOAT && ISA_HAS_TRUNC_W",
    __builtin_constant_p 
#line 2615 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && ISA_HAS_TRUNC_W)
    ? (int) 
#line 2615 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT && ISA_HAS_TRUNC_W)
    : -1 },
  { "(TARGET_SB1) && (TARGET_PAIRED_SINGLE_FLOAT)",
    __builtin_constant_p (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    ? (int) (
#line 1921 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_SB1) && 
#line 425 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_PAIRED_SINGLE_FLOAT))
    : -1 },
  { "(TARGET_4300_MUL_FIX) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 950 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 950 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_4300_MUL_FIX) && 
#line 428 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
#line 1246 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MSAC",
    __builtin_constant_p 
#line 1246 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MSAC)
    ? (int) 
#line 1246 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MSAC)
    : -1 },
#line 3874 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16 && reload_completed && INTVAL (operands[1]) < 0",
    __builtin_constant_p 
#line 3874 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && INTVAL (operands[1]) < 0)
    ? (int) 
#line 3874 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16 && reload_completed && INTVAL (operands[1]) < 0)
    : -1 },
  { "(TARGET_MIPS3D) && ( reload_completed)",
    __builtin_constant_p (
#line 361 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 363 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
( reload_completed))
    ? (int) (
#line 361 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 363 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
( reload_completed))
    : -1 },
#line 1310 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MSAC && reload_completed",
    __builtin_constant_p 
#line 1310 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MSAC && reload_completed)
    ? (int) 
#line 1310 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MSAC && reload_completed)
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed && register_operand (operands[1], VOIDmode))",
    __builtin_constant_p (
#line 2473 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2477 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && register_operand (operands[1], VOIDmode)))
    ? (int) (
#line 2473 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT) && 
#line 2477 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
( reload_completed && register_operand (operands[1], VOIDmode)))
    : -1 },
  { "(HAVE_AS_TLS && !TARGET_MIPS16) && (Pmode == DImode)",
    __builtin_constant_p (
#line 5472 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(HAVE_AS_TLS && !TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 5472 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(HAVE_AS_TLS && !TARGET_MIPS16) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },
  { "(TARGET_MIPS3D) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 578 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips-ps-3d.md"
(TARGET_MIPS3D) && 
#line 423 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(TARGET_EXPLICIT_RELOCS) && (Pmode == SImode)",
    __builtin_constant_p (
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    ? (int) (
#line 3163 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_EXPLICIT_RELOCS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == SImode))
    : -1 },
#line 1478 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "ISA_HAS_MULS",
    __builtin_constant_p 
#line 1478 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULS)
    ? (int) 
#line 1478 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(ISA_HAS_MULS)
    : -1 },
#line 5433 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_MIPS16",
    __builtin_constant_p 
#line 5433 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16)
    ? (int) 
#line 5433 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_MIPS16)
    : -1 },
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "TARGET_64BIT",
    __builtin_constant_p 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)
    ? (int) 
#line 407 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_64BIT)
    : -1 },
#line 5454 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
  { "reload_completed",
    __builtin_constant_p 
#line 5454 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed)
    ? (int) 
#line 5454 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(reload_completed)
    : -1 },
  { "(TARGET_ABICALLS) && (Pmode == DImode)",
    __builtin_constant_p (
#line 5059 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    ? (int) (
#line 5059 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(TARGET_ABICALLS) && 
#line 411 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/mips.md"
(Pmode == DImode))
    : -1 },

};
#endif /* gcc >= 3.0.1 */

int
main(void)
{
  unsigned int i;
  const char *p;
  puts ("(define_conditions [");
#if GCC_VERSION >= 3001
  for (i = 0; i < ARRAY_SIZE (insn_conditions); i++)
    {
      printf ("  (%d \"", insn_conditions[i].value);
      for (p = insn_conditions[i].expr; *p; p++)
        {
          switch (*p)
	     {
	     case '\\':
	     case '\"': putchar ('\\'); break;
	     default: break;
	     }
          putchar (*p);
        }
      puts ("\")");
    }
#endif /* gcc >= 3.0.1 */
  puts ("])");
  fflush (stdout);
return ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;
}
