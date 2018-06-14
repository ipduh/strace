#include <stdint.h>
typedef
struct {
uint32_t st_dev;
uint32_t st_ino;
uint32_t st_mode;
uint32_t st_nlink;
uint32_t st_uid;
uint32_t st_gid;
uint32_t st_rdev;
uint32_t __pad1;
int32_t st_size;
int32_t st_blksize;
int32_t __pad2;
int32_t st_blocks;
int32_t st_atime;
uint32_t st_atime_nsec;
int32_t st_mtime;
uint32_t st_mtime_nsec;
int32_t st_ctime;
uint32_t st_ctime_nsec;
uint32_t __unused4;
uint32_t __unused5;
} ATTRIBUTE_PACKED m32_struct_stat;
#define MPERS_m32_struct_stat m32_struct_stat
