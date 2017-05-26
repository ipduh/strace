#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
struct {
int32_t left;
int32_t top;
int32_t width;
int32_t height;
} ATTRIBUTE_PACKED c;
mpers_ptr_t next;
} ATTRIBUTE_PACKED m32_struct_v4l2_clip;
#define MPERS_m32_struct_v4l2_clip m32_struct_v4l2_clip
