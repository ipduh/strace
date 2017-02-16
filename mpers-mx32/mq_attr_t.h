#include <inttypes.h>
typedef uint32_t mpers_ptr_t;
typedef
struct {
int64_t mq_flags;
int64_t mq_maxmsg;
int64_t mq_msgsize;
int64_t mq_curmsgs;
int64_t __pad[4];
} ATTRIBUTE_PACKED mx32_mq_attr_t;
#define MPERS_mx32_mq_attr_t mx32_mq_attr_t
