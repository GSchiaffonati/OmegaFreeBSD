/* Generated automatically from machmode.def and mips/mips-modes.def
   by genmodes.  */

#ifndef GCC_INSN_MODES_H
#define GCC_INSN_MODES_H

enum machine_mode
{
  VOIDmode,                /* machmode.def:150 */
  BLKmode,                 /* machmode.def:154 */
  CCmode,                  /* machmode.def:182 */
  CCV2mode,                /* config/mips/mips-modes.def:34 */
  CCV4mode,                /* config/mips/mips-modes.def:38 */
  CCDSPmode,               /* config/mips/mips-modes.def:43 */
  BImode,                  /* machmode.def:157 */
  QImode,                  /* machmode.def:162 */
  HImode,                  /* machmode.def:163 */
  SImode,                  /* machmode.def:164 */
  DImode,                  /* machmode.def:165 */
  TImode,                  /* machmode.def:166 */
  SFmode,                  /* machmode.def:177 */
  DFmode,                  /* machmode.def:178 */
  TFmode,                  /* config/mips/mips-modes.def:27 */
  SDmode,                  /* machmode.def:194 */
  DDmode,                  /* machmode.def:195 */
  TDmode,                  /* machmode.def:196 */
  CQImode,                 /* machmode.def:190 */
  CHImode,                 /* machmode.def:190 */
  CSImode,                 /* machmode.def:190 */
  CDImode,                 /* machmode.def:190 */
  CTImode,                 /* machmode.def:190 */
  SCmode,                  /* machmode.def:191 */
  DCmode,                  /* machmode.def:191 */
  TCmode,                  /* machmode.def:191 */
  V4QImode,                /* config/mips/mips-modes.def:31 */
  V2HImode,                /* config/mips/mips-modes.def:31 */
  V2SFmode,                /* config/mips/mips-modes.def:30 */
  MAX_MACHINE_MODE,

  MIN_MODE_RANDOM = VOIDmode,
  MAX_MODE_RANDOM = BLKmode,

  MIN_MODE_CC = CCmode,
  MAX_MODE_CC = CCDSPmode,

  MIN_MODE_INT = QImode,
  MAX_MODE_INT = TImode,

  MIN_MODE_PARTIAL_INT = VOIDmode,
  MAX_MODE_PARTIAL_INT = VOIDmode,

  MIN_MODE_FLOAT = SFmode,
  MAX_MODE_FLOAT = TFmode,

  MIN_MODE_DECIMAL_FLOAT = SDmode,
  MAX_MODE_DECIMAL_FLOAT = TDmode,

  MIN_MODE_COMPLEX_INT = CQImode,
  MAX_MODE_COMPLEX_INT = CTImode,

  MIN_MODE_COMPLEX_FLOAT = SCmode,
  MAX_MODE_COMPLEX_FLOAT = TCmode,

  MIN_MODE_VECTOR_INT = V4QImode,
  MAX_MODE_VECTOR_INT = V2HImode,

  MIN_MODE_VECTOR_FLOAT = V2SFmode,
  MAX_MODE_VECTOR_FLOAT = V2SFmode,

  NUM_MACHINE_MODES = MAX_MACHINE_MODE
};

#define CONST_MODE_SIZE
#define CONST_MODE_BASE_ALIGN

#endif /* insn-modes.h */
