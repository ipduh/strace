#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint16_t len;
unsigned char mpers_filler_1[2];
uint32_t filter;
} ATTRIBUTE_PACKED mx32_seccomp_fprog_t;
#define MPERS_mx32_seccomp_fprog_t mx32_seccomp_fprog_t
