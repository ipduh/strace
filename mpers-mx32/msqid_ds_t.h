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
unsigned char mpers_filler_1[4];
uint64_t __glibc_reserved1;
uint64_t __glibc_reserved2;
} ATTRIBUTE_PACKED msg_perm;
int64_t msg_stime;
int64_t msg_rtime;
int64_t msg_ctime;
uint64_t __msg_cbytes;
uint64_t msg_qnum;
uint64_t msg_qbytes;
int32_t msg_lspid;
int32_t msg_lrpid;
uint64_t __glibc_reserved4;
uint64_t __glibc_reserved5;
} ATTRIBUTE_PACKED mx32_msqid_ds_t;
#define MPERS_mx32_msqid_ds_t mx32_msqid_ds_t
