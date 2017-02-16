#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t modes;
unsigned char mpers_filler_1[4];
int64_t offset;
int64_t freq;
int64_t maxerror;
int64_t esterror;
int32_t status;
unsigned char mpers_filler_2[4];
int64_t constant;
int64_t precision;
int64_t tolerance;
struct {
int64_t tv_sec;
int64_t tv_usec;
} ATTRIBUTE_PACKED time;
int64_t tick;
int64_t ppsfreq;
int64_t jitter;
int32_t shift;
unsigned char mpers_filler_3[4];
int64_t stabil;
int64_t jitcnt;
int64_t calcnt;
int64_t errcnt;
int64_t stbcnt;
int32_t tai;
unsigned char mpers_end_filler_4[44];
} ATTRIBUTE_PACKED mx32_struct_timex;
#define MPERS_mx32_struct_timex mx32_struct_timex
