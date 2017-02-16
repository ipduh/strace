#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
unsigned char heads;
unsigned char sectors;
uint16_t cylinders;
uint32_t start;
} ATTRIBUTE_PACKED mx32_struct_hd_geometry;
#define MPERS_mx32_struct_hd_geometry mx32_struct_hd_geometry
