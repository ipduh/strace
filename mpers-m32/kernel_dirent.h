#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t d_ino;
uint32_t d_off;
uint16_t d_reclen;
char d_name[1];
unsigned char mpers_end_filler_1[1];
} ATTRIBUTE_PACKED m32_kernel_dirent;
#define MPERS_m32_kernel_dirent m32_kernel_dirent
