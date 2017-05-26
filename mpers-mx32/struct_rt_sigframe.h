#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
uint64_t pretcode;
struct {
uint32_t uc_flags;
mpers_ptr_t uc_link;
struct {
mpers_ptr_t ss_sp;
int32_t ss_flags;
uint32_t ss_size;
} ATTRIBUTE_PACKED uc_stack;
unsigned char mpers_filler_1[4];
struct {
int64_t gregs[23];
mpers_ptr_t fpregs;
unsigned char mpers_filler_2[4];
uint64_t __reserved1[8];
} ATTRIBUTE_PACKED uc_mcontext;
struct {
uint32_t __val[32];
} ATTRIBUTE_PACKED uc_sigmask;
struct {
uint16_t cwd;
uint16_t swd;
uint16_t ftw;
uint16_t fop;
uint64_t rip;
uint64_t rdp;
uint32_t mxcsr;
uint32_t mxcr_mask;
struct {
uint16_t significand[4];
uint16_t exponent;
uint16_t padding[3];
} ATTRIBUTE_PACKED _st[8];
struct {
uint32_t element[4];
} ATTRIBUTE_PACKED _xmm[16];
uint32_t padding[24];
} ATTRIBUTE_PACKED __fpregs_mem;
} ATTRIBUTE_PACKED uc;
} ATTRIBUTE_PACKED mx32_struct_rt_sigframe;
#define MPERS_mx32_struct_rt_sigframe mx32_struct_rt_sigframe
