#include <stdint.h>
typedef
struct {
unsigned char heads;
unsigned char sectors;
uint16_t cylinders;
uint32_t start;
} ATTRIBUTE_PACKED m32_struct_hd_geometry;
#define MPERS_m32_struct_hd_geometry m32_struct_hd_geometry
