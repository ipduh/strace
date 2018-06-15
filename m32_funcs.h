#undef sys_readdir
#define sys_readdir m32_sys_readdir
#undef sys_getdents
#define sys_getdents m32_sys_getdents
#undef sys_msgctl
#define sys_msgctl m32_sys_msgctl
#undef sys_shmctl
#define sys_shmctl m32_sys_shmctl
#undef sys_time
#define sys_time m32_sys_time
#undef sys_rt_sigreturn
#define sys_rt_sigreturn m32_sys_rt_sigreturn
#undef sys_sigaltstack
#define sys_sigaltstack m32_sys_sigaltstack
#undef sys_sysinfo
#define sys_sysinfo m32_sys_sysinfo
#undef sys_times
#define sys_times m32_sys_times
#undef sys_ustat
#define sys_ustat m32_sys_ustat
#undef sys_utime
#define sys_utime m32_sys_utime
#include "sys_func.h"
