#include <stdint.h>
typedef
struct {
struct {
int32_t key;
uint32_t uid;
uint32_t gid;
uint32_t cuid;
uint32_t cgid;
uint32_t mode;
unsigned char __pad1[0];
uint16_t seq;
uint16_t __pad2;
uint32_t __unused1;
uint32_t __unused2;
} ATTRIBUTE_PACKED msg_perm;
int32_t msg_stime;
int32_t msg_rtime;
int32_t msg_ctime;
uint32_t msg_cbytes;
uint32_t msg_qnum;
uint32_t msg_qbytes;
int32_t msg_lspid;
int32_t msg_lrpid;
uint32_t __unused4;
uint32_t __unused5;
} ATTRIBUTE_PACKED m32_msqid_ds_t;
#define MPERS_m32_msqid_ds_t m32_msqid_ds_t
