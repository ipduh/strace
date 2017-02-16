#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
struct {
int32_t __key;
uint32_t uid;
uint32_t gid;
uint32_t cuid;
uint32_t cgid;
uint16_t mode;
uint16_t __pad1;
uint16_t __seq;
uint16_t __pad2;
uint32_t __glibc_reserved1;
uint32_t __glibc_reserved2;
} ATTRIBUTE_PACKED msg_perm;
int32_t msg_stime;
uint32_t __glibc_reserved1;
int32_t msg_rtime;
uint32_t __glibc_reserved2;
int32_t msg_ctime;
uint32_t __glibc_reserved3;
uint32_t __msg_cbytes;
uint32_t msg_qnum;
uint32_t msg_qbytes;
int32_t msg_lspid;
int32_t msg_lrpid;
uint32_t __glibc_reserved4;
uint32_t __glibc_reserved5;
} ATTRIBUTE_PACKED m32_msqid_ds_t;
#define MPERS_m32_msqid_ds_t m32_msqid_ds_t
