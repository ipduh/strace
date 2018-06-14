#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
int32_t interface_id;
int32_t dxfer_direction;
unsigned char cmd_len;
unsigned char mx_sb_len;
uint16_t iovec_count;
uint32_t dxfer_len;
mpers_ptr_t dxferp;
mpers_ptr_t cmdp;
mpers_ptr_t sbp;
uint32_t timeout;
uint32_t flags;
int32_t pack_id;
mpers_ptr_t usr_ptr;
unsigned char status;
unsigned char masked_status;
unsigned char msg_status;
unsigned char sb_len_wr;
uint16_t host_status;
uint16_t driver_status;
int32_t resid;
uint32_t duration;
uint32_t info;
} ATTRIBUTE_PACKED m32_struct_sg_io_hdr;
#define MPERS_m32_struct_sg_io_hdr m32_struct_sg_io_hdr
