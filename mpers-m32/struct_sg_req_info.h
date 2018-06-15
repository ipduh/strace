#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
char req_state;
char orphan;
char sg_io_owned;
char problem;
int32_t pack_id;
mpers_ptr_t usr_ptr;
uint32_t duration;
int32_t unused;
} ATTRIBUTE_PACKED m32_struct_sg_req_info;
#define MPERS_m32_struct_sg_req_info m32_struct_sg_req_info
