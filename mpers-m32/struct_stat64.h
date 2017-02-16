#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint64_t st_dev;
unsigned char __pad0[4];
uint32_t __st_ino;
uint32_t st_mode;
uint32_t st_nlink;
uint32_t st_uid;
uint32_t st_gid;
uint64_t st_rdev;
unsigned char __pad3[4];
int64_t st_size;
uint32_t st_blksize;
uint64_t st_blocks;
uint32_t st_atime;
uint32_t st_atime_nsec;
uint32_t st_mtime;
uint32_t st_mtime_nsec;
uint32_t st_ctime;
uint32_t st_ctime_nsec;
uint64_t st_ino;
} ATTRIBUTE_PACKED m32_struct_stat64;
#define MPERS_m32_struct_stat64 m32_struct_stat64
