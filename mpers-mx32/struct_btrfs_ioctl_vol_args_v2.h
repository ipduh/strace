#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t fd;
uint64_t transid;
uint64_t flags;
union {
struct {
uint64_t size;
mpers_ptr_t qgroup_inherit;
unsigned char mpers_end_filler_1[4];
} ATTRIBUTE_PACKED ;
uint64_t unused[4];
} ;
char name[4040];
} ATTRIBUTE_PACKED mx32_struct_btrfs_ioctl_vol_args_v2;
#define MPERS_mx32_struct_btrfs_ioctl_vol_args_v2 mx32_struct_btrfs_ioctl_vol_args_v2
