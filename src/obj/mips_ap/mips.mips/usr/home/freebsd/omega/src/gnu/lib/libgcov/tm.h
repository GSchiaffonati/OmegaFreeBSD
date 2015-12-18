#ifndef GCC_TM_H
#define GCC_TM_H
#ifdef IN_GCC
# include "options.h"
# include "mips/mips.h"
# include "dbxelf.h"
# include "elfos-undef.h"
# include "elfos.h"
# include "freebsd-native.h"
# include "freebsd-spec.h"
# include "freebsd.h"
# include "mips/elf.h"
# include "mips/freebsd.h"
# include "defaults.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-constants.h"
# include "insn-flags.h"
#endif
#endif /* GCC_TM_H */
#define EXTRA_MODES_FILE "mips/mips-modes.def"
