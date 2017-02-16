#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t uptime;
uint64_t loads[3];
uint64_t totalram;
uint64_t freeram;
uint64_t sharedram;
uint64_t bufferram;
uint64_t totalswap;
uint64_t freeswap;
uint16_t procs;
uint16_t pad;
unsigned char mpers_filler_1[4];
uint64_t totalhigh;
uint64_t freehigh;
uint32_t mem_unit;
char _f[0];
unsigned char mpers_end_filler_2[4];
} ATTRIBUTE_PACKED mx32_sysinfo_t;
#define MPERS_mx32_sysinfo_t mx32_sysinfo_t
