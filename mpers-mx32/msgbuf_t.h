#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t mtype;
char mtext[1];
unsigned char mpers_end_filler_1[7];
} ATTRIBUTE_PACKED mx32_msgbuf_t;
#define MPERS_mx32_msgbuf_t mx32_msgbuf_t
