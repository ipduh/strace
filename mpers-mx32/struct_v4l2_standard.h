#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t index;
unsigned char mpers_filler_1[4];
uint64_t id;
unsigned char name[24];
struct {
uint32_t numerator;
uint32_t denominator;
} ATTRIBUTE_PACKED frameperiod;
uint32_t framelines;
uint32_t reserved[4];
unsigned char mpers_end_filler_2[4];
} ATTRIBUTE_PACKED mx32_struct_v4l2_standard;
#define MPERS_mx32_struct_v4l2_standard mx32_struct_v4l2_standard
