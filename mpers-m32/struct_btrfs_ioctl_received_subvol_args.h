#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
char uuid[16];
uint64_t stransid;
uint64_t rtransid;
struct {
uint64_t sec;
uint32_t nsec;
} ATTRIBUTE_PACKED stime;
struct {
uint64_t sec;
uint32_t nsec;
} ATTRIBUTE_PACKED rtime;
uint64_t flags;
uint64_t reserved[16];
} ATTRIBUTE_PACKED m32_struct_btrfs_ioctl_received_subvol_args;
#define MPERS_m32_struct_btrfs_ioctl_received_subvol_args m32_struct_btrfs_ioctl_received_subvol_args
