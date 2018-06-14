#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
int64_t send_fd;
uint64_t clone_sources_count;
mpers_ptr_t clone_sources;
unsigned char mpers_filler_1[4];
uint64_t parent_root;
uint64_t flags;
uint64_t reserved[4];
} ATTRIBUTE_PACKED m32_struct_btrfs_ioctl_send_args;
#define MPERS_m32_struct_btrfs_ioctl_send_args m32_struct_btrfs_ioctl_send_args
