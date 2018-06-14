#include <stdint.h>
typedef
struct {
uint32_t gr_interface;
struct {
uint16_t ss_family;
char __data[126];
} ATTRIBUTE_PACKED gr_group;
} ATTRIBUTE_PACKED m32_struct_group_req;
#define MPERS_m32_struct_group_req m32_struct_group_req
