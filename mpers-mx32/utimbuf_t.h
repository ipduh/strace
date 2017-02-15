#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t actime;
int64_t modtime;
} ATTRIBUTE_PACKED mx32_utimbuf_t;
#define MPERS_mx32_utimbuf_t mx32_utimbuf_t
