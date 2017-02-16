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
} ATTRIBUTE_PACKED shm_perm;
uint32_t shm_segsz;
int32_t shm_atime;
uint32_t __glibc_reserved1;
int32_t shm_dtime;
uint32_t __glibc_reserved2;
int32_t shm_ctime;
uint32_t __glibc_reserved3;
int32_t shm_cpid;
int32_t shm_lpid;
uint32_t shm_nattch;
uint32_t __glibc_reserved4;
uint32_t __glibc_reserved5;
} ATTRIBUTE_PACKED m32_shmid_ds_t;
#define MPERS_m32_shmid_ds_t m32_shmid_ds_t
