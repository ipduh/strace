#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
char name[32];
uint16_t act_mask;
unsigned char mpers_filler_1[2];
uint32_t buf_size;
uint32_t buf_nr;
uint64_t start_lba;
uint64_t end_lba;
uint32_t pid;
} ATTRIBUTE_PACKED m32_struct_blk_user_trace_setup;
#define MPERS_m32_struct_blk_user_trace_setup m32_struct_blk_user_trace_setup
