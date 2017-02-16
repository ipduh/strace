#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
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
} ATTRIBUTE_PACKED mx32_struct_sg_req_info;
#define MPERS_mx32_struct_sg_req_info mx32_struct_sg_req_info
