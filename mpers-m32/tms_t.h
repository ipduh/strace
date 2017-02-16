#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t tms_utime;
int32_t tms_stime;
int32_t tms_cutime;
int32_t tms_cstime;
} ATTRIBUTE_PACKED m32_tms_t;
#define MPERS_m32_tms_t m32_tms_t
