#include <stdint.h>
#ifndef mpers_ptr_t_is_uint32_t
typedef uint32_t mpers_ptr_t;
#define mpers_ptr_t_is_uint32_t
#endif
typedef
struct {
mpers_ptr_t hashname;
mpers_ptr_t otherinfo;
uint32_t otherinfolen;
uint32_t __spare[8];
} ATTRIBUTE_PACKED m32_struct_keyctl_kdf_params;
#define MPERS_m32_struct_keyctl_kdf_params m32_struct_keyctl_kdf_params
