#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
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
union {
char name[4040];
uint64_t devid;
} ;
} ATTRIBUTE_PACKED m32_struct_btrfs_ioctl_vol_args_v2;
#define MPERS_m32_struct_btrfs_ioctl_vol_args_v2 m32_struct_btrfs_ioctl_vol_args_v2
