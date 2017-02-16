#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
char name[32];
uint16_t act_mask;
unsigned char mpers_filler_1[2];
uint32_t buf_size;
uint32_t buf_nr;
unsigned char mpers_filler_2[4];
uint64_t start_lba;
uint64_t end_lba;
uint32_t pid;
unsigned char mpers_end_filler_3[4];
} ATTRIBUTE_PACKED mx32_struct_blk_user_trace_setup;
#define MPERS_mx32_struct_blk_user_trace_setup mx32_struct_blk_user_trace_setup
