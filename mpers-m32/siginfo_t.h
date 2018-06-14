#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
int32_t si_signo;
int32_t si_errno;
int32_t si_code;
union {
int32_t _pad[28];
struct {
int32_t _pid;
uint32_t _uid;
} ATTRIBUTE_PACKED _kill;
struct {
int32_t _tid;
int32_t _overrun;
char _pad[0];
union {
int32_t sival_int;
mpers_ptr_t sival_ptr;
} _sigval;
int32_t _sys_private;
} ATTRIBUTE_PACKED _timer;
struct {
int32_t _pid;
uint32_t _uid;
union {
int32_t sival_int;
mpers_ptr_t sival_ptr;
} _sigval;
} ATTRIBUTE_PACKED _rt;
struct {
int32_t _pid;
uint32_t _uid;
int32_t _status;
int32_t _utime;
int32_t _stime;
} ATTRIBUTE_PACKED _sigchld;
struct {
mpers_ptr_t _addr;
int16_t _addr_lsb;
unsigned char mpers_filler_1[2];
union {
struct {
mpers_ptr_t _lower;
mpers_ptr_t _upper;
} ATTRIBUTE_PACKED _addr_bnd;
uint32_t _pkey;
} ;
} ATTRIBUTE_PACKED _sigfault;
struct {
int32_t _band;
int32_t _fd;
} ATTRIBUTE_PACKED _sigpoll;
struct {
mpers_ptr_t _call_addr;
int32_t _syscall;
uint32_t _arch;
} ATTRIBUTE_PACKED _sigsys;
} _sifields;
} ATTRIBUTE_PACKED m32_siginfo_t;
#define MPERS_m32_siginfo_t m32_siginfo_t
