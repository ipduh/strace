#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t op;
int32_t flags;
int32_t datalen;
mpers_ptr_t data;
} ATTRIBUTE_PACKED m32_struct_blkpg_ioctl_arg;
#define MPERS_m32_struct_blkpg_ioctl_arg m32_struct_blkpg_ioctl_arg
