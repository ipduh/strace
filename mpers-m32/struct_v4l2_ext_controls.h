#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t ctrl_class;
uint32_t count;
uint32_t error_idx;
uint32_t reserved[2];
mpers_ptr_t controls;
} ATTRIBUTE_PACKED m32_struct_v4l2_ext_controls;
#define MPERS_m32_struct_v4l2_ext_controls m32_struct_v4l2_ext_controls
