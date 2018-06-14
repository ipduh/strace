#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
uint32_t id;
uint32_t size;
uint32_t reserved2[1];
union {
int32_t value;
int64_t value64;
mpers_ptr_t string;
mpers_ptr_t p_u8;
mpers_ptr_t p_u16;
mpers_ptr_t p_u32;
mpers_ptr_t ptr;
} ;
} ATTRIBUTE_PACKED m32_struct_v4l2_ext_control;
#define MPERS_m32_struct_v4l2_ext_control m32_struct_v4l2_ext_control
