#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t f_type;
uint32_t f_bsize;
uint32_t f_blocks;
uint32_t f_bfree;
uint32_t f_bavail;
uint32_t f_files;
uint32_t f_ffree;
struct {
int32_t val[2];
} ATTRIBUTE_PACKED f_fsid;
uint32_t f_namelen;
uint32_t f_frsize;
uint32_t f_flags;
uint32_t f_spare[4];
} ATTRIBUTE_PACKED m32_struct_statfs;
#define MPERS_m32_struct_statfs m32_struct_statfs
