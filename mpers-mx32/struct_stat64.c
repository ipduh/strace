/*
 * Copyright (c) 2014-2016 Dmitry V. Levin <ldv@altlinux.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "defs.h"


#include "asm_stat.h"

#if defined MPERS_IS_m32
# undef HAVE_STRUCT_STAT64
# undef HAVE_STRUCT_STAT64_ST_MTIME_NSEC
# ifdef HAVE_M32_STRUCT_STAT64
#  define HAVE_STRUCT_STAT64 1
#  ifdef HAVE_M32_STRUCT_STAT64_ST_MTIME_NSEC
#   define HAVE_STRUCT_STAT64_ST_MTIME_NSEC 1
#  endif /* HAVE_M32_STRUCT_STAT64_ST_MTIME_NSEC */
# endif /* HAVE_M32_STRUCT_STAT64 */
#elif defined MPERS_IS_mx32
# undef HAVE_STRUCT_STAT64
# undef HAVE_STRUCT_STAT64_ST_MTIME_NSEC
# ifdef HAVE_MX32_STRUCT_STAT64
#  define HAVE_STRUCT_STAT64 1
#  ifdef HAVE_MX32_STRUCT_STAT64_ST_MTIME_NSEC
#   define HAVE_STRUCT_STAT64_ST_MTIME_NSEC 1
#  endif /* HAVE_MX32_STRUCT_STAT64_ST_MTIME_NSEC */
# endif /* HAVE_MX32_STRUCT_STAT64 */
#endif /* MPERS_IS_m32 || MPERS_IS_mx32 */

#ifndef HAVE_STRUCT_STAT64
struct stat64 {};
#endif

typedef struct stat64 struct_stat64;

struct_stat64 mpers_target_var;
