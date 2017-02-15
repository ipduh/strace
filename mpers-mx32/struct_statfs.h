#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t f_type;
int32_t f_bsize;
int32_t f_blocks;
int32_t f_bfree;
int32_t f_bavail;
int32_t f_files;
int32_t f_ffree;
struct {
int32_t val[2];
} ATTRIBUTE_PACKED f_fsid;
int32_t f_namelen;
int32_t f_frsize;
int32_t f_flags;
int32_t f_spare[4];
} ATTRIBUTE_PACKED mx32_struct_statfs;
#define MPERS_mx32_struct_statfs mx32_struct_statfs
