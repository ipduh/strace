#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
mpers_ptr_t msg_name;
uint32_t msg_namelen;
mpers_ptr_t msg_iov;
uint32_t msg_iovlen;
mpers_ptr_t msg_control;
uint32_t msg_controllen;
int32_t msg_flags;
} ATTRIBUTE_PACKED m32_struct_msghdr;
#define MPERS_m32_struct_msghdr m32_struct_msghdr
