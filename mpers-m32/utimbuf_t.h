#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t actime;
int32_t modtime;
} ATTRIBUTE_PACKED m32_utimbuf_t;
#define MPERS_m32_utimbuf_t m32_utimbuf_t
