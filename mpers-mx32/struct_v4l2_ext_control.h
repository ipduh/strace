#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t id;
uint32_t size;
uint32_t reserved2[1];
union {
int32_t value;
int64_t value64;
mpers_ptr_t string;
} ;
} ATTRIBUTE_PACKED mx32_struct_v4l2_ext_control;
#define MPERS_mx32_struct_v4l2_ext_control mx32_struct_v4l2_ext_control
