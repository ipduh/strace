#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t st_dev;
uint32_t st_ino;
uint16_t st_mode;
uint16_t st_nlink;
uint16_t st_uid;
uint16_t st_gid;
uint32_t st_rdev;
uint32_t st_size;
uint32_t st_blksize;
uint32_t st_blocks;
uint32_t st_atime;
uint32_t st_atime_nsec;
uint32_t st_mtime;
uint32_t st_mtime_nsec;
uint32_t st_ctime;
uint32_t st_ctime_nsec;
uint32_t __unused4;
uint32_t __unused5;
} ATTRIBUTE_PACKED m32_struct_stat;
#define MPERS_m32_struct_stat m32_struct_stat
