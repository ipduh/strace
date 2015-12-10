#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <sys/syscall.h>

#undef TEST_SYSCALL_NAME
#if defined __NR_select && !defined __NR__newselect
# define TEST_SYSCALL_NAME select
#endif

#include "xselect.c"
