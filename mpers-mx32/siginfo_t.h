#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t si_signo;
int32_t si_errno;
int32_t si_code;
union {
int32_t _pad[29];
struct {
int32_t si_pid;
uint32_t si_uid;
} ATTRIBUTE_PACKED _kill;
struct {
int32_t si_tid;
int32_t si_overrun;
union {
int32_t sival_int;
mpers_ptr_t sival_ptr;
} si_sigval;
} ATTRIBUTE_PACKED _timer;
struct {
int32_t si_pid;
uint32_t si_uid;
union {
int32_t sival_int;
mpers_ptr_t sival_ptr;
} si_sigval;
} ATTRIBUTE_PACKED _rt;
struct {
int32_t si_pid;
uint32_t si_uid;
int32_t si_status;
int64_t si_utime;
int64_t si_stime;
} ATTRIBUTE_PACKED _sigchld;
struct {
mpers_ptr_t si_addr;
int16_t si_addr_lsb;
unsigned char mpers_end_filler_1[2];
} ATTRIBUTE_PACKED _sigfault;
struct {
int32_t si_band;
int32_t si_fd;
} ATTRIBUTE_PACKED _sigpoll;
struct {
mpers_ptr_t _call_addr;
int32_t _syscall;
uint32_t _arch;
} ATTRIBUTE_PACKED _sigsys;
} _sifields;
} ATTRIBUTE_PACKED mx32_siginfo_t;
#define MPERS_mx32_siginfo_t mx32_siginfo_t
