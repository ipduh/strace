#include <stdint.h>
typedef
struct {
struct {
int32_t tv_sec;
int32_t tv_usec;
} ATTRIBUTE_PACKED ru_utime;
struct {
int32_t tv_sec;
int32_t tv_usec;
} ATTRIBUTE_PACKED ru_stime;
int32_t ru_maxrss;
int32_t ru_ixrss;
int32_t ru_idrss;
int32_t ru_isrss;
int32_t ru_minflt;
int32_t ru_majflt;
int32_t ru_nswap;
int32_t ru_inblock;
int32_t ru_oublock;
int32_t ru_msgsnd;
int32_t ru_msgrcv;
int32_t ru_nsignals;
int32_t ru_nvcsw;
int32_t ru_nivcsw;
} ATTRIBUTE_PACKED m32_rusage_t;
#define MPERS_m32_rusage_t m32_rusage_t
