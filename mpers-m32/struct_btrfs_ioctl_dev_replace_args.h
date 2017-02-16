#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint64_t cmd;
uint64_t result;
union {
struct {
uint64_t srcdevid;
uint64_t cont_reading_from_srcdev_mode;
unsigned char srcdev_name[1025];
unsigned char tgtdev_name[1025];
unsigned char mpers_end_filler_1[2];
} ATTRIBUTE_PACKED start;
struct {
uint64_t replace_state;
uint64_t progress_1000;
uint64_t time_started;
uint64_t time_stopped;
uint64_t num_write_errors;
uint64_t num_uncorrectable_read_errors;
} ATTRIBUTE_PACKED status;
} ;
uint64_t spare[64];
} ATTRIBUTE_PACKED m32_struct_btrfs_ioctl_dev_replace_args;
#define MPERS_m32_struct_btrfs_ioctl_dev_replace_args m32_struct_btrfs_ioctl_dev_replace_args
