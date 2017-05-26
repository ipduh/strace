#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint32_t pretcode;
int32_t sig;
uint32_t pinfo;
uint32_t puc;
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
int32_t si_utime;
int32_t si_stime;
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
} ATTRIBUTE_PACKED info;
struct {
uint32_t uc_flags;
mpers_ptr_t uc_link;
struct {
mpers_ptr_t ss_sp;
int32_t ss_flags;
uint32_t ss_size;
} ATTRIBUTE_PACKED uc_stack;
struct {
int32_t gregs[19];
mpers_ptr_t fpregs;
uint32_t oldmask;
uint32_t cr2;
} ATTRIBUTE_PACKED uc_mcontext;
struct {
uint32_t __val[32];
} ATTRIBUTE_PACKED uc_sigmask;
struct {
uint32_t cw;
uint32_t sw;
uint32_t tag;
uint32_t ipoff;
uint32_t cssel;
uint32_t dataoff;
uint32_t datasel;
struct {
uint16_t significand[4];
uint16_t exponent;
} ATTRIBUTE_PACKED _st[8];
uint32_t status;
} ATTRIBUTE_PACKED __fpregs_mem;
} ATTRIBUTE_PACKED uc;
} ATTRIBUTE_PACKED m32_struct_rt_sigframe;
#define MPERS_m32_struct_rt_sigframe m32_struct_rt_sigframe
