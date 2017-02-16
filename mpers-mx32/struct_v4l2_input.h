#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t index;
unsigned char name[32];
uint32_t type;
uint32_t audioset;
uint32_t tuner;
uint64_t std;
uint32_t status;
uint32_t capabilities;
uint32_t reserved[3];
unsigned char mpers_end_filler_1[4];
} ATTRIBUTE_PACKED mx32_struct_v4l2_input;
#define MPERS_mx32_struct_v4l2_input mx32_struct_v4l2_input
