#
# Copyright (C) 2006 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

#
# To update:
#

#  git remote add strace git://git.code.sf.net/p/strace/code
#  git fetch strace
#  git merge strace/master
#  mm -j32
#  # (Make any necessary Android.mk changes and test the new strace.)
#  git push aosp HEAD:master  # Push directly, avoiding gerrit.
#  git push aosp HEAD:refs/for/master  # Push to gerrit.
#
#  # Now commit any necessary Android.mk changes like normal:
#  repo start post-sync .
#  git commit -a
#

# -------------------------------------------------------------------------

include $(CLEAR_VARS)

strace_version := $(shell grep Version $(LOCAL_PATH)/strace.spec | cut -d " " -f 2)

LOCAL_SRC_FILES := \
    aio.c \
    bjm.c \
    block.c \
    count.c \
    desc.c \
    fanotify.c \
    file.c \
    inotify.c \
    io.c \
    ioctl.c \
    ioprio.c \
    ipc.c \
    kexec.c \
    keyctl.c \
    ldt.c \
    loop.c \
    mem.c \
    mtd.c \
    net.c \
    pathtrace.c \
    process.c \
    ptp.c \
    quota.c \
    reboot.c \
    resource.c \
    scsi.c \
    signal.c \
    sock.c \
    strace.c \
    stream.c \
    syscall.c \
    system.c \
    term.c \
    time.c \
    util.c \
    vsprintf.c \

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
    -DHAVE_ELF_H=1 \
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
    -DHAVE_STRUCT_FLOCK64=1 \
    -DHAVE_STRUCT_MSGHDR_MSG_CONTROL=1 \
    -DHAVE_STRUCT_SIGCONTEXT=1 \
    -DHAVE_STRUCT_SIGEVENT__SIGEV_UN__PAD=1 \
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
    -DSIZEOF_OFF_T=SIZEOF_LONG \
    -DSIZEOF_LONG_LONG=8 \
    -DSTDC_HEADERS=1 \
    -DSTRACE_KNOWS_ONLY_EABI=1 \
    -D_LFS64_LARGEFILE=1 \

LOCAL_CFLAGS += -D_GNU_SOURCE=1 -D_POSIX_SOURCE=1

LOCAL_CFLAGS_32 += -DSIZEOF_LONG=4 -DSIZEOF_RLIM_T=4 -DHAVE_STAT64=1
LOCAL_CFLAGS_64 += -DSIZEOF_LONG=8 -DSIZEOF_RLIM_T=8

LOCAL_CFLAGS_arm += -DARM=1
LOCAL_CFLAGS_arm += -DHAVE_STRUCT___OLD_KERNEL_STAT=1

LOCAL_CFLAGS_arm64 += -DAARCH64=1

LOCAL_CFLAGS_mips += -DMIPS=1
LOCAL_CFLAGS_mips += -DHAVE_ASM_SYSMIPS_H=1

LOCAL_CFLAGS_x86 += -DI386=1
LOCAL_CFLAGS_x86 += -DHAVE_STRUCT___OLD_KERNEL_STAT=1

LOCAL_CFLAGS_x86_64 += -DX86_64=1

LOCAL_CFLAGS += \
    -Wall \
    -Wno-missing-field-initializers \
    -Wno-unused-parameter \
    -Wno-sign-compare \

LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/linux

LOCAL_C_INCLUDES_arm := $(LOCAL_PATH)/linux/arm
LOCAL_C_INCLUDES_arm64 := $(LOCAL_PATH)/linux/aarch64
LOCAL_C_INCLUDES_mips := $(LOCAL_PATH)/linux/mips
LOCAL_C_INCLUDES_mips64 := $(LOCAL_PATH)/linux/mips
LOCAL_C_INCLUDES_x86 := $(LOCAL_PATH)/linux/i386
LOCAL_C_INCLUDES_x86_64 := $(LOCAL_PATH)/linux/x86_64

LOCAL_MODULE := strace

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := debug

LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk

include $(BUILD_EXECUTABLE)


# -------------------------------------------------------------------------

.PHONY: update-ioctls
update-ioctls:
	# Build the generated .h files needed by ioctlsort from the current bionic uapi headers.
	cd external/strace; ./linux/ioctlent.sh ../../bionic/libc/kernel/uapi/
	# Build the ioctlsort tool.
	ONE_SHOT_MAKEFILE=external/strace/Android.mk make -f build/core/main.mk $(TARGET_OUT_EXECUTABLES)/ioctlsort
	# Remove the generated .h files now we've built ioctlsort.
	rm external/strace/ioctls.h external/strace/ioctldefs.h
	# Run the ioctlsort tool on the target to generate the one file we do want to check in.
	adb sync
	adb shell ioctlsort | tr -d '\r' > external/strace/linux/ioctlent.h
	# Rebuild strace with the new "ioctlent.h".
	ONE_SHOT_MAKEFILE=external/strace/Android.mk make -f build/core/main.mk

# We don't build ioctlsort unless really necessary, because we don't check
# in the temporary files needed to build it. This tool is only necessary
# when updating strace's list of ioctls.
ifneq (,$(filter $(TARGET_OUT_EXECUTABLES)/ioctlsort,$(MAKECMDGOALS)))
include $(CLEAR_VARS)
LOCAL_SRC_FILES := linux/ioctlsort.c
LOCAL_CFLAGS += -include asm/types.h -include linux/ashmem.h
LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_MODULE := ioctlsort
LOCAL_MODULE_TAGS := optional
LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk
include $(BUILD_EXECUTABLE)
endif

# -------------------------------------------------------------------------

include $(LOCAL_PATH)/test/Android.mk
