#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
union {
int32_t sival_int;
uint32_t sival_ptr;
} sigev_value;
int32_t sigev_signo;
int32_t sigev_notify;
union {
int32_t tid;
struct {
uint32_t function;
uint32_t attribute;
} ATTRIBUTE_PACKED sigev_thread;
} sigev_un;
} ATTRIBUTE_PACKED m32_struct_sigevent;
#define MPERS_m32_struct_sigevent m32_struct_sigevent
