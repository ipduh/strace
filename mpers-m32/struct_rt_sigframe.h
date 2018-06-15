#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
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
} ATTRIBUTE_PACKED info;
unsigned char mpers_filler_2[4];
struct {
uint32_t uc_flags;
mpers_ptr_t uc_link;
struct {
mpers_ptr_t ss_sp;
int32_t ss_flags;
uint32_t ss_size;
} ATTRIBUTE_PACKED uc_stack;
unsigned char mpers_filler_3[12];
struct {
uint64_t fault_address;
uint64_t regs[31];
uint64_t sp;
uint64_t pc;
uint64_t pstate;
unsigned char mpers_filler_4[8];
unsigned char __reserved[4096];
} ATTRIBUTE_PACKED uc_mcontext;
struct {
uint32_t sig[1];
} ATTRIBUTE_PACKED uc_sigmask;
uint32_t __padding_rt_sigset;
char __padding[120];
uint32_t uc_regspace[128];
} ATTRIBUTE_PACKED uc;
} ATTRIBUTE_PACKED m32_struct_rt_sigframe;
#define MPERS_m32_struct_rt_sigframe m32_struct_rt_sigframe
