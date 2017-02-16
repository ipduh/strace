#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t modes;
int32_t offset;
int32_t freq;
int32_t maxerror;
int32_t esterror;
int32_t status;
int32_t constant;
int32_t precision;
int32_t tolerance;
struct {
int32_t tv_sec;
int32_t tv_usec;
} ATTRIBUTE_PACKED time;
int32_t tick;
int32_t ppsfreq;
int32_t jitter;
int32_t shift;
int32_t stabil;
int32_t jitcnt;
int32_t calcnt;
int32_t errcnt;
int32_t stbcnt;
int32_t tai;
unsigned char mpers_end_filler_1[44];
} ATTRIBUTE_PACKED m32_struct_timex;
#define MPERS_m32_struct_timex m32_struct_timex
