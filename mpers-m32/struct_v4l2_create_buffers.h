#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t index;
uint32_t count;
uint32_t memory;
struct {
uint32_t type;
union {
struct {
uint32_t width;
uint32_t height;
uint32_t pixelformat;
uint32_t field;
uint32_t bytesperline;
uint32_t sizeimage;
uint32_t colorspace;
uint32_t priv;
} ATTRIBUTE_PACKED pix;
struct {
uint32_t width;
uint32_t height;
uint32_t pixelformat;
uint32_t field;
uint32_t colorspace;
struct {
uint32_t sizeimage;
uint16_t bytesperline;
uint16_t reserved[7];
} ATTRIBUTE_PACKED plane_fmt[8];
unsigned char num_planes;
unsigned char reserved[11];
} ATTRIBUTE_PACKED pix_mp;
struct {
struct {
int32_t left;
int32_t top;
int32_t width;
int32_t height;
} ATTRIBUTE_PACKED w;
uint32_t field;
uint32_t chromakey;
mpers_ptr_t clips;
uint32_t clipcount;
mpers_ptr_t bitmap;
unsigned char global_alpha;
unsigned char mpers_end_filler_1[3];
} ATTRIBUTE_PACKED win;
struct {
uint32_t sampling_rate;
uint32_t offset;
uint32_t samples_per_line;
uint32_t sample_format;
int32_t start[2];
uint32_t count[2];
uint32_t flags;
uint32_t reserved[2];
} ATTRIBUTE_PACKED vbi;
struct {
uint16_t service_set;
uint16_t service_lines[24];
unsigned char mpers_filler_2[50];
uint32_t io_size;
uint32_t reserved[2];
} ATTRIBUTE_PACKED sliced;
unsigned char raw_data[200];
} fmt;
} ATTRIBUTE_PACKED format;
uint32_t reserved[8];
} ATTRIBUTE_PACKED m32_struct_v4l2_create_buffers;
#define MPERS_m32_struct_v4l2_create_buffers m32_struct_v4l2_create_buffers
