/* Generated by ./xlat/gen.sh from ./xlat/kexec_load_flags.in; do not edit. */

#include "gcc_compat.h"
#include "static_assert.h"

#if defined(KEXEC_ON_CRASH) || (defined(HAVE_DECL_KEXEC_ON_CRASH) && HAVE_DECL_KEXEC_ON_CRASH)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((KEXEC_ON_CRASH) == (0x00000001), "KEXEC_ON_CRASH != 0x00000001");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define KEXEC_ON_CRASH 0x00000001
#endif
#if defined(KEXEC_PRESERVE_CONTEXT) || (defined(HAVE_DECL_KEXEC_PRESERVE_CONTEXT) && HAVE_DECL_KEXEC_PRESERVE_CONTEXT)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((KEXEC_PRESERVE_CONTEXT) == (0x00000002), "KEXEC_PRESERVE_CONTEXT != 0x00000002");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define KEXEC_PRESERVE_CONTEXT 0x00000002
#endif

#ifndef XLAT_MACROS_ONLY

# ifdef IN_MPERS

#  error static const struct xlat kexec_load_flags in mpers mode

# else

static
const struct xlat kexec_load_flags[] = {
 XLAT(KEXEC_ON_CRASH),
 XLAT(KEXEC_PRESERVE_CONTEXT),
 XLAT_END
};

# endif /* !IN_MPERS */

#endif /* !XLAT_MACROS_ONLY */
