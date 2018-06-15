#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
struct {
int32_t left;
int32_t top;
uint32_t width;
uint32_t height;
} ATTRIBUTE_PACKED c;
mpers_ptr_t next;
} ATTRIBUTE_PACKED m32_struct_v4l2_clip;
#define MPERS_m32_struct_v4l2_clip m32_struct_v4l2_clip
