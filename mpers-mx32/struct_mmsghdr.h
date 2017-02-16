#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
struct {
mpers_ptr_t msg_name;
uint32_t msg_namelen;
mpers_ptr_t msg_iov;
uint32_t msg_iovlen;
mpers_ptr_t msg_control;
uint32_t msg_controllen;
int32_t msg_flags;
} ATTRIBUTE_PACKED msg_hdr;
uint32_t msg_len;
} ATTRIBUTE_PACKED mx32_struct_mmsghdr;
#define MPERS_mx32_struct_mmsghdr mx32_struct_mmsghdr
