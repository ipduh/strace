#include "mpers_type.h"
#include DEF_MPERS_TYPE(sample_struct)
typedef struct {
	struct {
		void *p;
		char sc;
		/* unsigned char mpers_filler_1[1]; */
		short ss;
		unsigned char uc;
		/* unsigned char mpers_filler_2[3]; */
		int si;
		unsigned ui;
		long sl;
		unsigned short us;
		/* unsigned char mpers_filler_3[6]; */
		long long sll __attribute__((__aligned__(8)));
		unsigned long long ull;
		unsigned long ul;
		long asl[3][5][7];
		char f;
		/* unsigned char mpers_end_filler_4[7]; */
	} s;
	union {
		long long sll;
		unsigned long long ull;
		void *p;
		long sl;
		unsigned long ul;
		int si;
		unsigned ui;
		short ss[7][9];
		unsigned short us[4];
		char sc;
		unsigned char uc;
	} u[3][2];
	short f[0];
} sample_struct;
#include MPERS_DEFS
