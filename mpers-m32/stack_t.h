#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
mpers_ptr_t ss_sp;
int32_t ss_flags;
uint32_t ss_size;
} ATTRIBUTE_PACKED m32_stack_t;
#define MPERS_m32_stack_t m32_stack_t
