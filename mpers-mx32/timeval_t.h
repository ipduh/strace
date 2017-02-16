#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t tv_sec;
int64_t tv_usec;
} ATTRIBUTE_PACKED mx32_timeval_t;
#define MPERS_mx32_timeval_t mx32_timeval_t
