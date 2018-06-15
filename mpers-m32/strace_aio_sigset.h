#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
mpers_ptr_t sigmask;
uint32_t sigsetsize;
} ATTRIBUTE_PACKED m32_strace_aio_sigset;
#define MPERS_m32_strace_aio_sigset m32_strace_aio_sigset
