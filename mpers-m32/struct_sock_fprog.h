#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
uint16_t len;
unsigned char mpers_filler_1[2];
mpers_ptr_t filter;
} ATTRIBUTE_PACKED m32_struct_sock_fprog;
#define MPERS_m32_struct_sock_fprog m32_struct_sock_fprog
