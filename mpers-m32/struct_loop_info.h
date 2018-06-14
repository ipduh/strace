#include <stdint.h>
typedef
struct {
int32_t lo_number;
uint32_t lo_device;
uint32_t lo_inode;
uint32_t lo_rdevice;
int32_t lo_offset;
int32_t lo_encrypt_type;
int32_t lo_encrypt_key_size;
int32_t lo_flags;
char lo_name[64];
unsigned char lo_encrypt_key[32];
uint32_t lo_init[2];
char reserved[4];
} ATTRIBUTE_PACKED m32_struct_loop_info;
#define MPERS_m32_struct_loop_info m32_struct_loop_info
