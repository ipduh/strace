#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
union {
char ifrn_name[16];
} ifr_ifrn;
union {
struct {
uint16_t sa_family;
char sa_data[14];
} ATTRIBUTE_PACKED ifru_addr;
struct {
uint16_t sa_family;
char sa_data[14];
} ATTRIBUTE_PACKED ifru_dstaddr;
struct {
uint16_t sa_family;
char sa_data[14];
} ATTRIBUTE_PACKED ifru_broadaddr;
struct {
uint16_t sa_family;
char sa_data[14];
} ATTRIBUTE_PACKED ifru_netmask;
struct {
uint16_t sa_family;
char sa_data[14];
} ATTRIBUTE_PACKED ifru_hwaddr;
int16_t ifru_flags;
int32_t ifru_ivalue;
int32_t ifru_mtu;
struct {
uint32_t mem_start;
uint32_t mem_end;
uint16_t base_addr;
unsigned char irq;
unsigned char dma;
unsigned char port;
unsigned char mpers_end_filler_1[3];
} ATTRIBUTE_PACKED ifru_map;
char ifru_slave[16];
char ifru_newname[16];
mpers_ptr_t ifru_data;
struct {
uint32_t type;
uint32_t size;
union {
mpers_ptr_t raw_hdlc;
mpers_ptr_t cisco;
mpers_ptr_t fr;
mpers_ptr_t fr_pvc;
mpers_ptr_t fr_pvc_info;
mpers_ptr_t sync;
mpers_ptr_t te1;
} ifs_ifsu;
} ATTRIBUTE_PACKED ifru_settings;
} ifr_ifru;
} ATTRIBUTE_PACKED m32_struct_ifreq;
#define MPERS_m32_struct_ifreq m32_struct_ifreq
