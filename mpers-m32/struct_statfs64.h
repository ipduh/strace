#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t f_type;
uint32_t f_bsize;
uint64_t f_blocks;
uint64_t f_bfree;
uint64_t f_bavail;
uint64_t f_files;
uint64_t f_ffree;
struct {
int32_t val[2];
} ATTRIBUTE_PACKED f_fsid;
uint32_t f_namelen;
uint32_t f_frsize;
uint32_t f_flags;
uint32_t f_spare[4];
} ATTRIBUTE_PACKED m32_struct_statfs64;
#define MPERS_m32_struct_statfs64 m32_struct_statfs64
