#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
struct {
mpers_ptr_t msg_name;
int32_t msg_namelen;
mpers_ptr_t msg_iov;
uint32_t msg_iovlen;
mpers_ptr_t msg_control;
uint32_t msg_controllen;
int32_t msg_flags;
} ATTRIBUTE_PACKED msg_hdr;
uint32_t msg_len;
} ATTRIBUTE_PACKED m32_struct_mmsghdr;
#define MPERS_m32_struct_mmsghdr m32_struct_mmsghdr
