# Copyright 2006 The Android Open Source Project

LOCAL_PATH := $(my-dir)
include $(CLEAR_VARS)

strace_version := $(shell grep Version $(LOCAL_PATH)/strace.spec | cut -d " " -f 2)

LOCAL_SRC_FILES := \
    bjm.c \
    block.c \
    count.c \
    desc.c \
    file.c \
    io.c \
    ioctl.c \
    ipc.c \
    loop.c \
    mem.c \
    mtd.c \
    net.c \
    pathtrace.c \
    proc.c \
    process.c \
    quota.c \
    resource.c \
    signal.c \
    sock.c \
    strace.c \
    stream.c \
    syscall.c \
    system.c \
    term.c \
    time.c \
    util.c \

LOCAL_SHARED_LIBRARIES :=

LOCAL_CFLAGS := \
    -DGETGROUPS_T=gid_t \
    -DHAVE_ASM_SIGCONTEXT_H=1 \
    -DHAVE_DECL_PTRACE_EVENT_FORK=1 \
    -DHAVE_DECL_PTRACE_EVENT_VFORK=1 \
    -DHAVE_DECL_PTRACE_EVENT_CLONE=1 \
    -DHAVE_DECL_PTRACE_EVENT_EXEC=1 \
    -DHAVE_DECL_PTRACE_EVENT_VFORK_DONE=1 \
    -DHAVE_DECL_PTRACE_EVENT_EXIT=1 \
    -DHAVE_DECL_PTRACE_GETEVENTMSG=1 \
    -DHAVE_DECL_PTRACE_GETSIGINFO=1 \
    -DHAVE_DECL_PTRACE_O_TRACECLONE=1 \
    -DHAVE_DECL_PTRACE_O_TRACEEXEC=1 \
    -DHAVE_DECL_PTRACE_O_TRACEEXIT=1 \
    -DHAVE_DECL_PTRACE_O_TRACEFORK=1 \
    -DHAVE_DECL_PTRACE_O_TRACESYSGOOD=1 \
    -DHAVE_DECL_PTRACE_O_TRACEVFORK=1 \
    -DHAVE_DECL_PTRACE_SETOPTIONS=1 \
    -UHAVE_DECL_IO_CMD_PWRITE \
    -UHAVE_DECL_IO_CMD_PWRITEV \
    -UHAVE_DECL_LO_FLAGS_AUTOCLEAR \
    -UHAVE_DECL_LO_FLAGS_PARTSCAN \
    -DHAVE_DECL_SYS_ERRLIST=1 \
    -DHAVE_FORK=1 \
    -DHAVE_IF_INDEXTONAME=1 \
    -DHAVE_INET_NTOP=1 \
    -DHAVE_LINUX_CAPABILITY_H=1 \
    -DHAVE_LINUX_ICMP_H=1 \
    -DHAVE_LINUX_IF_PACKET_H=1 \
    -DHAVE_LINUX_IN6_H=1 \
    -DHAVE_LINUX_NETLINK_H=1 \
    -DHAVE_LITTLE_ENDIAN_LONG_LONG=1 \
    -DHAVE_LONG_LONG=1 \
    -DHAVE_NETINET_TCP_H=1 \
    -DHAVE_NETINET_UDP_H=1 \
    -DHAVE_POLL_H=1 \
    -DHAVE_PRCTL=1 \
    -DHAVE_SENDMSG=1 \
    -DHAVE_SIGACTION=1 \
    -DHAVE_SIGINFO_T=1 \
    -DHAVE_SIG_ATOMIC_T=1 \
    -DHAVE_STATFS64=1 \
    -DHAVE_STDBOOL_H=1 \
    -DHAVE_STRERROR=1 \
    -DHAVE_STRUCT_MSGHDR_MSG_CONTROL=1 \
    -DHAVE_STRUCT_SIGCONTEXT \
    -DHAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID=1 \
    -DHAVE_STRUCT_STAT_ST_BLKSIZE=1 \
    -DHAVE_STRUCT_STAT_ST_BLOCKS=1 \
    -DHAVE_STRUCT_STAT_ST_RDEV=1 \
    -DHAVE_STRUCT_USER_DESC=1 \
    -DHAVE_SYS_EPOLL_H=1 \
    -DHAVE_SYS_IOCTL_H=1 \
    -DHAVE_SYS_POLL_H=1 \
    -DHAVE_SYS_REG_H=1 \
    -DHAVE_SYS_VFS_H=1 \
    -DMAJOR_IN_SYSMACROS \
    -DPACKAGE_NAME='"strace"' \
    -DVERSION='"$(strace_version)"' \
    -DSIZEOF_LONG_LONG=8 \
    -DSTDC_HEADERS=1 \
    -D_LFS64_LARGEFILE=1 \

LOCAL_CFLAGS += -D_GNU_SOURCE=1 -D_POSIX_SOURCE=1

# bionic doesn't have fputs_unlocked.
LOCAL_CFLAGS += -Dfputs_unlocked=fputs
# bionic's LFS64 support is incomplete.
LOCAL_CFLAGS += -Dfopen64=fopen
LOCAL_CFLAGS += -Dreaddir64=readdir
# uapi's asm/sigcontext.h doesn't have sigcontext_struct.
LOCAL_CFLAGS += -Dsigcontext_struct=sigcontext

ifeq ($(TARGET_IS_64_BIT),true)
    LOCAL_CFLAGS += -DSIZEOF_LONG=8 -DSIZEOF_RLIM_T=8
else
    LOCAL_CFLAGS += -DSIZEOF_LONG=4 -DSIZEOF_RLIM_T=4
endif

arch := $(TARGET_ARCH)
ifeq ($(TARGET_ARCH),arm)
    LOCAL_CFLAGS += -DARM=1
    LOCAL_CFLAGS += -DHAVE_STAT64=1
    LOCAL_CFLAGS += -DHAVE_STRUCT___OLD_KERNEL_STAT=1
else ifeq ($(TARGET_ARCH),mips)
    LOCAL_CFLAGS += -DMIPS=1
    LOCAL_CFLAGS += -DHAVE_STAT64=1
    LOCAL_CFLAGS += -DHAVE_ASM_SYSMIPS_H=1
    LOCAL_CFLAGS += -UHAVE_STRUCT___OLD_KERNEL_STAT 
else ifeq ($(TARGET_ARCH),x86)
    LOCAL_CFLAGS += -DI386=1
    LOCAL_CFLAGS += -DHAVE_STAT64=1
    LOCAL_CFLAGS += -DHAVE_STRUCT___OLD_KERNEL_STAT=1
    arch := i386
else ifeq ($(TARGET_ARCH),x86_64)
    LOCAL_CFLAGS += -DX86_64=1
endif

LOCAL_CFLAGS += \
    -Wall \
    -Wno-missing-field-initializers \
    -Wno-unused-parameter \
    -Wno-sign-compare \

LOCAL_C_INCLUDES := \
    $(KERNEL_HEADERS) \
    $(LOCAL_PATH)/linux/$(arch) \
    $(LOCAL_PATH)/linux

LOCAL_MODULE := strace

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := debug

LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk

include $(BUILD_EXECUTABLE)
