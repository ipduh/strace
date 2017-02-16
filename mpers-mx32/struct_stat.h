#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint64_t st_dev;
uint64_t st_ino;
uint64_t st_nlink;
uint32_t st_mode;
uint32_t st_uid;
uint32_t st_gid;
uint32_t pad0__;
uint64_t st_rdev;
int64_t st_size;
int64_t st_blksize;
int64_t st_blocks;
uint64_t st_atime;
uint64_t st_atime_nsec;
uint64_t st_mtime;
uint64_t st_mtime_nsec;
uint64_t st_ctime;
uint64_t st_ctime_nsec;
int64_t pad1__[3];
} ATTRIBUTE_PACKED mx32_struct_stat;
#define MPERS_mx32_struct_stat mx32_struct_stat
