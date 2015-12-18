/* Generated automatically by the program './genpreds'
   from the machine description file 'insn-conditions.md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "tree.h"
#include "tm_p.h"
#include "function.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "resource.h"
#include "toplev.h"
#include "reload.h"
#include "regs.h"
#include "tm-constrs.h"

int
const_uns_arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 23 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(SMALL_OPERAND_UNSIGNED (INTVAL (op))));
}

int
uns_arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_uns_arith_operand (op, mode)) || (register_operand (op, mode));
}

int
const_arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 31 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(SMALL_OPERAND (INTVAL (op))));
}

int
arith_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_arith_operand (op, mode)) || (register_operand (op, mode));
}

int
const_uimm6_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 39 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(UIMM6_OPERAND (INTVAL (op))));
}

int
const_imm10_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 43 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(IMM10_OPERAND (INTVAL (op))));
}

int
reg_imm10_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_imm10_operand (op, mode)) || (register_operand (op, mode));
}

int
sle_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 51 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(SMALL_OPERAND (INTVAL (op) + 1)));
}

int
sleu_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (sle_operand (op, mode)) && (
#line 55 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(INTVAL (op) + 1 != 0));
}

int
const_0_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return 
#line 59 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(op == CONST0_RTX (GET_MODE (op)));
}

int
reg_or_0_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((const_0_operand (op, mode)) && (
#line 63 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(!TARGET_MIPS16))) || (register_operand (op, mode));
}

int
const_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return 
#line 68 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(op == CONST1_RTX (GET_MODE (op)));
}

int
reg_or_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_1_operand (op, mode)) || (register_operand (op, mode));
}

int
const_0_or_1_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && ((
#line 77 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(op == CONST0_RTX (GET_MODE (op)))) || (
#line 78 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(op == CONST1_RTX (GET_MODE (op)))));
}

int
fpr_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == REG) && (
#line 82 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(FP_REG_P (REGNO (op))))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
lo_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == REG) && (
#line 86 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(REGNO (op) == LO_REGNUM))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
fcc_reload_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case REG:
    case SUBREG:
      break;
    default:
      return false;
    }
  return (
#line 90 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(ST_REG_P (true_regnum (op)))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
pc_or_label_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case PC:
    case LABEL_REF:
      return true;
    default:
      break;
    }
  return false;
}

static inline int
const_call_insn_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 97 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type symbol_type;

  if (!mips_symbolic_constant_p (op, &symbol_type))
    return false;

  switch (symbol_type)
    {
    case SYMBOL_GENERAL:
      /* We can only use direct calls for TARGET_ABSOLUTE_ABICALLS if we
	 are sure that the target function does not need $25 to be live
	 on entry.  This is true for any locally-defined function because
	 any such function will use %hi/%lo accesses to set up $gp.  */
      if (TARGET_ABSOLUTE_ABICALLS
          && !(GET_CODE (op) == SYMBOL_REF
	       && SYMBOL_REF_DECL (op)
	       && !DECL_EXTERNAL (SYMBOL_REF_DECL (op))))
	return false;

      /* If -mlong-calls, force all calls to use register addressing.  Also,
	 if this function has the long_call attribute, we must use register
	 addressing.  */
      return (!TARGET_LONG_CALLS
	      && !(GET_CODE (op) == SYMBOL_REF
		   && SYMBOL_REF_LONG_CALL_P (op)));

    case SYMBOL_GOT_GLOBAL:
      /* Without explicit relocs, there is no special syntax for
	 loading the address of a call destination into a register.
	 Using "la $25,foo; jal $25" would prevent the lazy binding
	 of "foo", so keep the address of global symbols with the
	 jal macro.  */
      return !TARGET_EXPLICIT_RELOCS;

    default:
      return false;
    }
}

int
const_call_insn_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(const_call_insn_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
call_insn_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_call_insn_operand (op, mode)) || (register_operand (op, mode));
}

static inline int
splittable_const_int_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 144 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  /* When generating mips16 code, LEGITIMATE_CONSTANT_P rejects
     CONST_INTs that can't be loaded using simple insns.  */
  if (TARGET_MIPS16)
    return false;

  /* Don't handle multi-word moves this way; we don't want to introduce
     the individual word-mode moves until after reload.  */
  if (GET_MODE_SIZE (mode) > UNITS_PER_WORD)
    return false;

  /* Otherwise check whether the constant can be loaded in a single
     instruction.  */
  return !LUI_INT (op) && !SMALL_INT (op) && !SMALL_INT_UNSIGNED (op);
}

int
splittable_const_int_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
(splittable_const_int_operand_1 (op, mode)));
}

static inline int
splittable_symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 164 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type symbol_type;
  return (mips_symbolic_constant_p (op, &symbol_type)
	  && mips_split_p[symbol_type]);
}

int
splittable_symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(splittable_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
move_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 172 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type symbol_type;

  /* The thinking here is as follows:

     (1) The move expanders should split complex load sequences into
	 individual instructions.  Those individual instructions can
	 then be optimized by all rtl passes.

     (2) The target of pre-reload load sequences should not be used
	 to store temporary results.  If the target register is only
	 assigned one value, reload can rematerialize that value
	 on demand, rather than spill it to the stack.

     (3) If we allowed pre-reload passes like combine and cse to recreate
	 complex load sequences, we would want to be able to split the
	 sequences before reload as well, so that the pre-reload scheduler
	 can see the individual instructions.  This falls foul of (2);
	 the splitter would be forced to reuse the target register for
	 intermediate results.

     (4) We want to define complex load splitters for combine.  These
	 splitters can request a temporary scratch register, which avoids
	 the problem in (2).  They allow things like:

	      (set (reg T1) (high SYM))
	      (set (reg T2) (low (reg T1) SYM))
	      (set (reg X) (plus (reg T2) (const_int OFFSET)))

	 to be combined into:

	      (set (reg T3) (high SYM+OFFSET))
	      (set (reg X) (lo_sum (reg T3) SYM+OFFSET))

	 if T2 is only used this once.  */
  switch (GET_CODE (op))
    {
    case CONST_INT:
      return !splittable_const_int_operand (op, mode);

    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      if (CONST_GP_P (op))
	return true;
      return (mips_symbolic_constant_p (op, &symbol_type)
	      && !mips_split_p[symbol_type]);

    default:
      return true;
    }
}

int
move_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (general_operand (op, mode)) && (
(move_operand_1 (op, mode)));
}

int
consttable_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return (
#line 226 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(CONSTANT_P (op))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 230 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type type;
  return mips_symbolic_constant_p (op, &type);
}

int
symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
general_symbolic_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 237 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type type;
  return mips_symbolic_constant_p (op, &type) && type == SYMBOL_GENERAL;
}

int
general_symbolic_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(general_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
global_got_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 244 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type type;
  return mips_symbolic_constant_p (op, &type) && type == SYMBOL_GOT_GLOBAL;
}

int
global_got_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(global_got_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
local_got_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 251 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  enum mips_symbol_type type;
  return mips_symbolic_constant_p (op, &type) && type == SYMBOL_GOT_LOCAL;
}

int
local_got_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(local_got_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
stack_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == MEM) && (
#line 258 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(mips_stack_address_p (XEXP (op, 0), GET_MODE (op))))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

static inline int
macc_msac_operand_1 (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
#line 263 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
{
  rtx mult = XEXP (op, GET_CODE (op) == PLUS ? 0 : 1);
  rtx accum = XEXP (op, GET_CODE (op) == PLUS ? 1 : 0);
  return (GET_CODE (mult) == MULT
	  && REG_P (XEXP (mult, 0))
	  && REG_P (XEXP (mult, 1))
	  && REG_P (accum));
}

int
macc_msac_operand (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((((GET_CODE (op) == PLUS) && (
#line 261 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(ISA_HAS_MACC))) || ((GET_CODE (op) == MINUS) && (
#line 262 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(ISA_HAS_MSAC)))) && (
(macc_msac_operand_1 (op, mode)))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
equality_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
extend_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case ZERO_EXTEND:
    case SIGN_EXTEND:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
trap_comparison_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
    case LT:
    case LTU:
    case GE:
    case GEU:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
order_operator (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case LT:
    case LTU:
    case LE:
    case LEU:
    case GE:
    case GEU:
    case GT:
    case GTU:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
small_data_pattern (rtx op, enum machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case SET:
    case PARALLEL:
    case UNSPEC:
    case UNSPEC_VOLATILE:
    case PREFETCH:
      break;
    default:
      return false;
    }
  return (
#line 288 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/predicates.md"
(mips_small_data_pattern_p (op))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

enum constraint_num
lookup_constraint (const char *str)
{
  switch (str[0])
    {
    case 'A':
      return CONSTRAINT_A;
    case 'B':
      return CONSTRAINT_B;
    case 'C':
      return CONSTRAINT_C;
    case 'D':
      return CONSTRAINT_D;
    case 'G':
      return CONSTRAINT_G;
    case 'I':
      return CONSTRAINT_I;
    case 'J':
      return CONSTRAINT_J;
    case 'K':
      return CONSTRAINT_K;
    case 'L':
      return CONSTRAINT_L;
    case 'M':
      return CONSTRAINT_M;
    case 'N':
      return CONSTRAINT_N;
    case 'O':
      return CONSTRAINT_O;
    case 'P':
      return CONSTRAINT_P;
    case 'Q':
      return CONSTRAINT_Q;
    case 'R':
      return CONSTRAINT_R;
    case 'S':
      return CONSTRAINT_S;
    case 'T':
      return CONSTRAINT_T;
    case 'U':
      return CONSTRAINT_U;
    case 'W':
      return CONSTRAINT_W;
    case 'Y':
      if (!strncmp (str, "YA", 2))
        return CONSTRAINT_YA;
      if (!strncmp (str, "YB", 2))
        return CONSTRAINT_YB;
      if (!strncmp (str, "YG", 2))
        return CONSTRAINT_YG;
      break;
    case 'a':
      return CONSTRAINT_a;
    case 'b':
      return CONSTRAINT_b;
    case 'c':
      return CONSTRAINT_c;
    case 'd':
      return CONSTRAINT_d;
    case 'e':
      return CONSTRAINT_e;
    case 'f':
      return CONSTRAINT_f;
    case 'h':
      return CONSTRAINT_h;
    case 'j':
      return CONSTRAINT_j;
    case 'l':
      return CONSTRAINT_l;
    case 't':
      return CONSTRAINT_t;
    case 'v':
      return CONSTRAINT_v;
    case 'x':
      return CONSTRAINT_x;
    case 'y':
      return CONSTRAINT_y;
    case 'z':
      return CONSTRAINT_z;
    default: break;
    }
  return CONSTRAINT__UNKNOWN;
}

enum reg_class
regclass_for_constraint (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_d: return BASE_REG_CLASS;
    case CONSTRAINT_t: return T_REG;
    case CONSTRAINT_f: return TARGET_HARD_FLOAT ? FP_REGS : NO_REGS;
    case CONSTRAINT_h: return HI_REG;
    case CONSTRAINT_l: return LO_REG;
    case CONSTRAINT_x: return MD_REGS;
    case CONSTRAINT_b: return ALL_REGS;
    case CONSTRAINT_c: return TARGET_ABICALLS ? PIC_FN_ADDR_REG
				 : TARGET_MIPS16 ? M16_NA_REGS
				 : GR_REGS;
    case CONSTRAINT_e: return LEA_REGS;
    case CONSTRAINT_j: return PIC_FN_ADDR_REG;
    case CONSTRAINT_v: return V1_REG;
    case CONSTRAINT_y: return GR_REGS;
    case CONSTRAINT_z: return ST_REGS;
    case CONSTRAINT_A: return DSP_ACC_REGS;
    case CONSTRAINT_a: return ACC_REGS;
    case CONSTRAINT_B: return COP0_REGS;
    case CONSTRAINT_C: return COP2_REGS;
    case CONSTRAINT_D: return COP3_REGS;
    default: break;
    }
  return NO_REGS;
}

bool
constraint_satisfied_p (rtx op, enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_I: return satisfies_constraint_I (op);
    case CONSTRAINT_J: return satisfies_constraint_J (op);
    case CONSTRAINT_K: return satisfies_constraint_K (op);
    case CONSTRAINT_L: return satisfies_constraint_L (op);
    case CONSTRAINT_M: return satisfies_constraint_M (op);
    case CONSTRAINT_N: return satisfies_constraint_N (op);
    case CONSTRAINT_O: return satisfies_constraint_O (op);
    case CONSTRAINT_P: return satisfies_constraint_P (op);
    case CONSTRAINT_G: return satisfies_constraint_G (op);
    case CONSTRAINT_Q: return satisfies_constraint_Q (op);
    case CONSTRAINT_R: return satisfies_constraint_R (op);
    case CONSTRAINT_S: return satisfies_constraint_S (op);
    case CONSTRAINT_T: return satisfies_constraint_T (op);
    case CONSTRAINT_U: return satisfies_constraint_U (op);
    case CONSTRAINT_W: return satisfies_constraint_W (op);
    case CONSTRAINT_YG: return satisfies_constraint_YG (op);
    case CONSTRAINT_YA: return satisfies_constraint_YA (op);
    case CONSTRAINT_YB: return satisfies_constraint_YB (op);
    default: break;
    }
  return false;
}

size_t
insn_constraint_len (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_YG: return 2;
    case CONSTRAINT_YA: return 2;
    case CONSTRAINT_YB: return 2;
    default: break;
    }
  return 1;
}

bool
insn_const_int_ok_for_constraint (HOST_WIDE_INT ival, enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_I:
      return 
#line 86 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(SMALL_OPERAND (ival));

    case CONSTRAINT_J:
      return 
#line 91 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(ival == 0);

    case CONSTRAINT_K:
      return 
#line 96 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(SMALL_OPERAND_UNSIGNED (ival));

    case CONSTRAINT_L:
      return 
#line 102 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(LUI_OPERAND (ival));

    case CONSTRAINT_M:
      return (
#line 108 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(!SMALL_OPERAND (ival))) && ((
#line 109 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(!SMALL_OPERAND_UNSIGNED (ival))) && (
#line 110 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(!LUI_OPERAND (ival))));

    case CONSTRAINT_N:
      return 
#line 115 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(ival >= -0xffff && ival < 0);

    case CONSTRAINT_O:
      return 
#line 120 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(ival >= -0x4000 && ival < 0x4000);

    case CONSTRAINT_P:
      return 
#line 125 "/usr/home/freebsd/omega/src/gnu/usr.bin/cc/cc_tools/../../../../contrib/gcc/config/mips/constraints.md"
(ival > 0 && ival < 0x10000);

    default: break;
    }
  return false;
}

bool
insn_extra_memory_constraint (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_R:
      return true;

    case CONSTRAINT_W:
      return true;

    default: break;
    }
  return false;
}

