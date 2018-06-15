#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
uint32_t index;
uint32_t type;
uint32_t bytesused;
uint32_t flags;
uint32_t field;
struct {
int32_t tv_sec;
int32_t tv_usec;
} ATTRIBUTE_PACKED timestamp;
struct {
uint32_t type;
uint32_t flags;
unsigned char frames;
unsigned char seconds;
unsigned char minutes;
unsigned char hours;
unsigned char userbits[4];
} ATTRIBUTE_PACKED timecode;
uint32_t sequence;
uint32_t memory;
union {
uint32_t offset;
uint32_t userptr;
mpers_ptr_t planes;
int32_t fd;
} m;
uint32_t length;
uint32_t reserved2;
uint32_t reserved;
} ATTRIBUTE_PACKED m32_struct_v4l2_buffer;
#define MPERS_m32_struct_v4l2_buffer m32_struct_v4l2_buffer
