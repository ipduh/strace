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

ifneq ($(strip $(TARGET_ARCH)),mips)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
    access.c \
    affinity.c \
    aio.c \
    bjm.c \
    block.c \
    bpf.c \
    btrfs.c \
    cacheflush.c \
    capability.c \
    chdir.c \
    chmod.c \
    clone.c \
    copy_file_range.c \
    count.c \
    desc.c \
    dirent.c \
    dirent64.c \
    dm.c \
    dyxlat.c \
    epoll.c \
    evdev.c \
    eventfd.c \
    execve.c \
    fadvise.c \
    fallocate.c \
    fanotify.c \
    fchownat.c \
    fcntl.c \
    fetch_seccomp_fprog.c \
    fetch_struct_flock.c \
    fetch_struct_mmsghdr.c \
    fetch_struct_msghdr.c \
    fetch_struct_stat.c \
    fetch_struct_stat64.c \
    fetch_struct_statfs.c \
    file_handle.c \
    file_ioctl.c \
    flock.c \
    fstatfs.c \
    fstatfs64.c \
    fs_x_ioctl.c \
    futex.c \
    getcpu.c \
    getcwd.c \
    getrandom.c \
    get_robust_list.c \
    hdio.c \
    hostname.c \
    inotify.c \
    io.c \
    ioctl.c \
    ioperm.c \
    iopl.c \
    ioprio.c \
    ipc.c \
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
    mmsghdr.c \
    mount.c \
    mq.c \
    msghdr.c \
    mtd.c \
    net.c \
    netlink.c \
    netlink_sock_diag.c \
    nlattr.c \
    nsfs.c \
    numa.c \
    oldstat.c \
    open.c \
    pathtrace.c \
    perf.c \
    personality.c \
    pkeys.c \
    poll.c \
    prctl.c \
    print_dev_t.c \
    print_mq_attr.c \
    print_msgbuf.c \
    print_sigevent.c \
    print_sg_req_info.c \
    print_statfs.c \
    print_struct_stat.c \
    print_time.c \
    print_timespec.c \
    print_timeval.c \
    print_timex.c \
    printmode.c \
    printrusage.c \
    printsiginfo.c \
    process.c \
    process_vm.c \
    ptp.c \
    qualify.c \
    quota.c \
    readahead.c \
    readlink.c \
    reboot.c \
    renameat.c \
    resource.c \
    rtc.c \
    rt_sigframe.c \
    rt_sigreturn.c \
    sched.c \
    scsi.c \
    seccomp.c \
    sendfile.c \
    sg_io_v3.c \
    sg_io_v4.c \
    sigaltstack.c \
    signal.c \
    signalfd.c \
    sigreturn.c \
    sock.c \
    sockaddr.c \
    socketcall.c \
    socketutils.c \
    sram_alloc.c \
    stat.c \
    stat64.c \
    statfs.c \
    statfs64.c \
    statx.c \
    strace.c \
    swapon.c \
    sync_file_range.c \
    sync_file_range2.c \
    syscall.c \
    sysctl.c \
    sysinfo.c \
    syslog.c \
    sysmips.c \
    term.c \
    time.c \
    times.c \
    truncate.c \
    ubi.c \
    uid16.c \
    uid.c \
    umask.c \
    umount.c \
    uname.c \
    upeek.c \
    upoke.c \
    userfaultfd.c \
    ustat.c \
    util.c \
    utime.c \
    utimes.c \
    v4l2.c \
    wait.c \
    xattr.c \
    xlat.c \
    xmalloc.c \

# We have "config.h", but since we're using one file for both LP32 and LP64,
# we need to set the hard-coded size #defines here instead.
LOCAL_CFLAGS := -DHAVE_CONFIG_H
LOCAL_CFLAGS_32 += -DSIZEOF_LONG_LONG=8 -DSIZEOF_LONG=4 -DSIZEOF_RLIM_T=4 -DHAVE_STRUCT_STAT64=1
LOCAL_CFLAGS_64 += -DSIZEOF_LONG_LONG=8 -DSIZEOF_LONG=8 -DSIZEOF_RLIM_T=8
LOCAL_CFLAGS += -DSIZEOF_KERNEL_LONG_T=SIZEOF_LONG -DSIZEOF_OFF_T=SIZEOF_LONG

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
    -Werror \
    -Wno-missing-field-initializers \
    -Wno-pointer-arith \
    -Wno-unused-parameter \
    -Wno-sign-compare \
    -fno-strict-aliasing \

LOCAL_C_INCLUDES_arm := $(LOCAL_PATH)/linux/arm $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_arm64 := $(LOCAL_PATH)/linux/aarch64 $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_mips := $(LOCAL_PATH)/linux/mips $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_mips64 := $(LOCAL_PATH)/linux/mips $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_x86 := $(LOCAL_PATH)/linux/i386 $(LOCAL_PATH)/linux
LOCAL_C_INCLUDES_x86_64 := $(LOCAL_PATH)/linux/x86_64 $(LOCAL_PATH)/linux

LOCAL_MODULE := strace

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := debug

include $(BUILD_EXECUTABLE)

endif
