#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int32_t uptime;
uint32_t loads[3];
uint32_t totalram;
uint32_t freeram;
uint32_t sharedram;
uint32_t bufferram;
uint32_t totalswap;
uint32_t freeswap;
uint16_t procs;
uint16_t pad;
uint32_t totalhigh;
uint32_t freehigh;
uint32_t mem_unit;
char _f[8];
} ATTRIBUTE_PACKED m32_sysinfo_t;
#define MPERS_m32_sysinfo_t m32_sysinfo_t
