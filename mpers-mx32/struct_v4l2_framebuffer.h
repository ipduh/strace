#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t capability;
uint32_t flags;
mpers_ptr_t base;
struct {
uint32_t width;
uint32_t height;
uint32_t pixelformat;
uint32_t field;
uint32_t bytesperline;
uint32_t sizeimage;
uint32_t colorspace;
uint32_t priv;
} ATTRIBUTE_PACKED fmt;
} ATTRIBUTE_PACKED mx32_struct_v4l2_framebuffer;
#define MPERS_mx32_struct_v4l2_framebuffer mx32_struct_v4l2_framebuffer
