#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t op;
int32_t flags;
int32_t datalen;
mpers_ptr_t data;
} ATTRIBUTE_PACKED mx32_struct_blkpg_ioctl_arg;
#define MPERS_mx32_struct_blkpg_ioctl_arg mx32_struct_blkpg_ioctl_arg
