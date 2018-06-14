#include <stdint.h>
typedef
struct {
int32_t f_type;
int32_t f_bsize;
uint64_t f_blocks;
uint64_t f_bfree;
uint64_t f_bavail;
uint64_t f_files;
uint64_t f_ffree;
struct {
int32_t val[2];
} ATTRIBUTE_PACKED f_fsid;
int32_t f_namelen;
int32_t f_frsize;
int32_t f_flags;
int32_t f_spare[4];
unsigned char mpers_end_filler_1[4];
} ATTRIBUTE_PACKED m32_struct_statfs64;
#define MPERS_m32_struct_statfs64 m32_struct_statfs64
