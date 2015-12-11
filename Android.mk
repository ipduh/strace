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

# We don't currently have a good solution for the 'configure' side of things.
# You can get a list of the HAVE_* variables in use and manually go through it:
#
#   find . -name "*.[ch]" | xargs grep HAVE_ | sed 's/.*\(HAVE_[A-Z0-9_]*\).*/\1/p' | sort | uniq -d

# -------------------------------------------------------------------------

include $(CLEAR_VARS)

strace_version := $(shell grep Version $(LOCAL_PATH)/strace.spec | cut -d " " -f 2)

LOCAL_SRC_FILES := \
    access.c \
    affinity.c \
    aio.c \
    bjm.c \
    block.c \
    bpf.c \
    cacheflush.c \
    capability.c \
    chdir.c \
    chmod.c \
    clone.c \
    count.c \
    desc.c \
    dirent.c \
    dirent64.c \
    epoll.c \
    eventfd.c \
    execve.c \
    exit.c \
    fadvise.c \
    fallocate.c \
    fanotify.c \
    fchownat.c \
    fcntl.c \
    fetch_seccomp_fprog.c \
    fetch_struct_flock.c \
    file.c \
    file_handle.c \
    flock.c \
    futex.c \
    getcpu.c \
    getcwd.c \
    getrandom.c \
    get_robust_list.c \
    hostname.c \
    inotify.c \
    io.c \
    ioctl.c \
    ioperm.c \
    iopl.c \
    ioprio.c \
    ipc_msg.c \
    ipc_msgctl.c \
    ipc_sem.c \
    ipc_shm.c \
    ipc_shmctl.c \
    kcmp.c \
    kexec.c \
    keyctl.c \
    ldt.c \
    link.c \
    lookup_dcookie.c \
    loop.c \
    lseek.c \
    mem.c \
    membarrier.c \
    memfd_create.c \
    mknod.c \
    mount.c \
    mq.c \
    mtd.c \
    net.c \
    open.c \
    pathtrace.c \
    perf.c \
    personality.c \
    poll.c \
    prctl.c \
    print_mq_attr.c \
    print_msgbuf.c \
    print_sigevent.c \
    print_time.c \
    print_timex.c \
    printmode.c \
    printrusage.c \
    printsiginfo.c \
    process.c \
    process_vm.c \
    ptp.c \
    quota.c \
    readahead.c \
    readlink.c \
    reboot.c \
    renameat.c \
    resource.c \
    rtc.c \
    sched.c \
    scsi.c \
    seccomp.c \
    sendfile.c \
    sigaltstack.c \
    signal.c \
    signalfd.c \
    sigreturn.c \
    sock.c \
    socketutils.c \
    sram_alloc.c \
    statfs.c \
    strace.c \
    swapon.c \
    sync_file_range.c \
    syscall.c \
    sysctl.c \
    sysinfo.c \
    syslog.c \
    sysmips.c \
    term.c \
    time.c \
    times.c \
    truncate.c \
    uid16.c \
    uid.c \
    umask.c \
    umount.c \
    uname.c \
    userfaultfd.c \
    util.c \
    utime.c \
    utimes.c \
    v4l2.c \
    vsprintf.c \
    wait.c \
    xattr.c \
    xmalloc.c \

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
    -DHAVE_FOPEN64=1 \
    -DHAVE_FORK=1 \
    -DHAVE_IF_INDEXTONAME=1 \
    -DHAVE_INET_NTOP=1 \
    -DHAVE_LINUX_CAPABILITY_H=1 \
    -DHAVE_LINUX_FALLOC_H=1 \
    -DHAVE_LINUX_FILTER_H=1 \
    -DHAVE_LINUX_FUTEX_H=1 \
    -DHAVE_LINUX_ICMP_H=1 \
    -DHAVE_LINUX_IF_PACKET_H=1 \
    -DHAVE_LINUX_IN6_H=1 \
    -DHAVE_LINUX_IPC_H=1 \
    -DHAVE_LINUX_MQUEUE=1 \
    -DHAVE_LINUX_MSG_H=1 \
    -DHAVE_LINUX_NETLINK_H=1 \
    -DHAVE_LINUX_PERF_EVENT_H=1 \
    -DHAVE_LINUX_SEM_H=1 \
    -DHAVE_LINUX_SHM_H=1 \
    -DHAVE_LITTLE_ENDIAN_LONG_LONG=1 \
    -DHAVE_LONG_LONG=1 \
    -DHAVE_NETINET_TCP_H=1 \
    -DHAVE_NETINET_UDP_H=1 \
    -DHAVE_POLL_H=1 \
    -DHAVE_PRCTL=1 \
    -DHAVE_PWRITEV=1 \
    -DHAVE_SENDMSG=1 \
    -DHAVE_SIGACTION=1 \
    -DHAVE_SIG_ATOMIC_T=1 \
    -DHAVE_SIGINFO_T=1 \
    -DHAVE_SIGINFO_T_SI_OVERRUN=1 \
    -DHAVE_SIGINFO_T_SI_SYSCALL=1 \
    -DHAVE_SIGINFO_T_SI_TIMERID=1 \
    -UHAVE_STAT64 \
    -DHAVE_STATFS64=1 \
    -DHAVE_STDBOOL_H=1 \
    -DHAVE_STRERROR=1 \
    -DHAVE_STRUCT_FLOCK=1 \
    -DHAVE_STRUCT_FLOCK64=1 \
    -DHAVE_STRUCT_MMSGHDR=1 \
    -DHAVE_STRUCT_MSGHDR_MSG_CONTROL=1 \
    -DHAVE_STRUCT_SIGCONTEXT=1 \
    -DHAVE_STRUCT_SIGEVENT__SIGEV_UN__PAD=1 \
    -DHAVE_STRUCT_SOCKADDR_IN6_SIN6_SCOPE_ID=1 \
    -DHAVE_STRUCT_STATFS64=1 \
    -UHAVE_STRUCT_STAT_ST_ACLCNT \
    -DHAVE_STRUCT_STAT_ST_BLKSIZE=1 \
    -DHAVE_STRUCT_STAT_ST_BLOCKS=1 \
    -UHAVE_STRUCT_STAT_ST_FLAGS \
    -UHAVE_STRUCT_STAT_ST_FSTYPE \
    -UHAVE_STRUCT_STAT_ST_GEN \
    -UHAVE_STRUCT_STAT_ST_LEVEL \
    -DHAVE_STRUCT_STAT_ST_RDEV=1 \
    -DHAVE_STRUCT_SYSINFO_FREEHIGH=1 \
    -DHAVE_STRUCT_SYSINFO_MEM_UNIT=1 \
    -DHAVE_STRUCT_SYSINFO_TOTALHIGH=1 \
    -DHAVE_STRUCT_UTSNAME_DOMAINNAME=1 \
    -DHAVE_SYS_EPOLL_H=1 \
    -DHAVE_SYS_IOCTL_H=1 \
    -DHAVE_SYS_POLL_H=1 \
    -DHAVE_SYS_REG_H=1 \
    -DHAVE_SYS_VFS_H=1 \
    -DHAVE_SYS_XATTR_H=1 \
    -DMAJOR_IN_SYSMACROS \
    -DPACKAGE_NAME='"strace"' \
    -DVERSION='"$(strace_version)"' \
    -DSIZEOF_OFF_T=SIZEOF_LONG \
    -DSIZEOF_LONG_LONG=8 \
    -DSTDC_HEADERS=1 \
    -DSTRACE_KNOWS_ONLY_EABI=1 \
    -D_LFS64_LARGEFILE=1 \

LOCAL_CFLAGS += -D_GNU_SOURCE=1 -D_POSIX_SOURCE=1

LOCAL_CFLAGS += -fno-strict-aliasing

LOCAL_CFLAGS_32 += -DSIZEOF_LONG=4 -DSIZEOF_RLIM_T=4 -DHAVE_STAT64=1
LOCAL_CFLAGS_64 += -DSIZEOF_LONG=8 -DSIZEOF_RLIM_T=8

LOCAL_CFLAGS_arm += -DARM=1
LOCAL_CFLAGS_arm += -DHAVE_STRUCT___OLD_KERNEL_STAT=1

LOCAL_CFLAGS_arm64 += -DAARCH64=1

LOCAL_CFLAGS_mips += -DMIPS=1 -DLINUX_MIPSO32=1
LOCAL_CFLAGS_mips += -DHAVE_ASM_SYSMIPS_H=1

LOCAL_CFLAGS_mips64 += -DMIPS=1 -DLINUX_MIPSN64=1
LOCAL_CFLAGS_mips64 += -DHAVE_ASM_SYSMIPS_H=1

LOCAL_CFLAGS_x86 += -DI386=1
LOCAL_CFLAGS_x86 += -DHAVE_STRUCT___OLD_KERNEL_STAT=1

LOCAL_CFLAGS_x86_64 += -DX86_64=1

LOCAL_CFLAGS += \
    -Wall \
    -Wwrite-strings \
    -Wsign-compare \
    -Wno-missing-field-initializers \
    -Wno-unused-parameter \
    -Wno-sign-compare \

LOCAL_C_INCLUDES_arm := $(LOCAL_PATH)/linux/arm $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_arm64 := $(LOCAL_PATH)/linux/aarch64 $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_mips := $(LOCAL_PATH)/linux/mips $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_mips64 := $(LOCAL_PATH)/linux/mips $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_x86 := $(LOCAL_PATH)/linux/i386 $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_x86_64 := $(LOCAL_PATH)/linux/x86_64 $(LOCAL_PATH)/linux

LOCAL_CLANG := true

LOCAL_MODULE := strace

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := debug

LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk

include $(BUILD_EXECUTABLE)
