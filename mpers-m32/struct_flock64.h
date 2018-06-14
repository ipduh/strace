#include <stdint.h>
typedef
struct {
int16_t l_type;
int16_t l_whence;
unsigned char mpers_filler_1[4];
int64_t l_start;
int64_t l_len;
int32_t l_pid;
unsigned char mpers_end_filler_2[4];
} ATTRIBUTE_PACKED m32_struct_flock64;
#define MPERS_m32_struct_flock64 m32_struct_flock64
