#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t f_tfree;
unsigned char mpers_filler_1[4];
uint64_t f_tinode;
char f_fname[6];
char f_fpack[6];
unsigned char mpers_end_filler_2[4];
} ATTRIBUTE_PACKED mx32_struct_ustat;
#define MPERS_mx32_struct_ustat mx32_struct_ustat
