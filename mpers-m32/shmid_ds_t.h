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
} ATTRIBUTE_PACKED shm_perm;
uint32_t shm_segsz;
int32_t shm_atime;
int32_t shm_dtime;
int32_t shm_ctime;
int32_t shm_cpid;
int32_t shm_lpid;
uint32_t shm_nattch;
uint32_t __unused4;
uint32_t __unused5;
} ATTRIBUTE_PACKED m32_shmid_ds_t;
#define MPERS_m32_shmid_ds_t m32_shmid_ds_t
