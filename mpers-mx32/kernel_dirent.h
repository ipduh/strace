#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint64_t d_ino;
uint64_t d_off;
uint16_t d_reclen;
char d_name[1];
unsigned char mpers_end_filler_1[5];
} ATTRIBUTE_PACKED mx32_kernel_dirent;
#define MPERS_mx32_kernel_dirent mx32_kernel_dirent
