#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t mtype;
char mtext[1];
unsigned char mpers_end_filler_1[3];
} ATTRIBUTE_PACKED m32_msgbuf_t;
#define MPERS_m32_msgbuf_t m32_msgbuf_t
