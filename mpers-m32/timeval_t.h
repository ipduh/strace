#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t tv_sec;
int32_t tv_usec;
} ATTRIBUTE_PACKED m32_timeval_t;
#define MPERS_m32_timeval_t m32_timeval_t
