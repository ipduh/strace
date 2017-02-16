#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int16_t l_type;
int16_t l_whence;
int64_t l_start;
int64_t l_len;
int32_t l_pid;
} ATTRIBUTE_PACKED m32_struct_flock64;
#define MPERS_m32_struct_flock64 m32_struct_flock64
