#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
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
uint32_t flags;
union {
uint32_t ycbcr_enc;
uint32_t hsv_enc;
} ;
uint32_t quantization;
uint32_t xfer_func;
} ATTRIBUTE_PACKED pix;
struct {
uint32_t width;
uint32_t height;
uint32_t pixelformat;
uint32_t field;
uint32_t colorspace;
struct {
uint32_t sizeimage;
uint32_t bytesperline;
uint16_t reserved[6];
} ATTRIBUTE_PACKED plane_fmt[8];
unsigned char num_planes;
unsigned char flags;
union {
unsigned char ycbcr_enc;
unsigned char hsv_enc;
} ;
unsigned char quantization;
unsigned char xfer_func;
unsigned char reserved[7];
} ATTRIBUTE_PACKED pix_mp;
struct {
struct {
int32_t left;
int32_t top;
uint32_t width;
uint32_t height;
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
uint16_t service_lines[2][24];
unsigned char mpers_filler_2[2];
uint32_t io_size;
uint32_t reserved[2];
} ATTRIBUTE_PACKED sliced;
struct {
uint32_t pixelformat;
uint32_t buffersize;
unsigned char reserved[24];
} ATTRIBUTE_PACKED sdr;
struct {
uint32_t dataformat;
uint32_t buffersize;
} ATTRIBUTE_PACKED meta;
unsigned char raw_data[200];
} fmt;
} ATTRIBUTE_PACKED m32_struct_v4l2_format;
#define MPERS_m32_struct_v4l2_format m32_struct_v4l2_format
