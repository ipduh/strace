# Copyright 2006 The Android Open Source Project

LOCAL_PATH := $(my-dir)
include $(CLEAR_VARS)

# From autoconf-generated Makefile
strace_SOURCES = strace.c syscall.c util.c desc.c file.c \
                 io.c ioctl.c mem.c net.c process.c bjm.c \
                 resource.c signal.c sock.c system.c term.c time.c \
                 proc.c stream.c

#excluded_sources = ipc.c

LOCAL_SRC_FILES:= $(strace_SOURCES)

LOCAL_SHARED_LIBRARIES :=

# Hack for ARM devices. This version of strace does not support ARM, and the
# patch that was used to add ARM support actually adds the ARM syscalls to
# linux/sh/ (Sega Megadrive/Dreamcast/...) instead of linux/arm/ . The proper
# way to fix this would be to upgrade to a version of strace that does support
# ARM (e.g. 4.5.1.8), but that would mean having to reapply all Android-specific
# changes. Sigh.
ifeq ($(TARGET_ARCH),arm)
	STRACE_ARCH_HEADERS := $(LOCAL_PATH)/strace/linux/sh
else
	STRACE_ARCH_HEADERS := $(LOCAL_PATH)/strace/linux/$(TARGET_ARCH)
endif

LOCAL_C_INCLUDES := \
	$(STRACE_ARCH_HEADERS) \
	$(KERNEL_HEADERS) \
	$(LOCAL_PATH)/linux \
	$(LOCAL_PATH)/android/arch/$(TARGET_ARCH)

LOCAL_CFLAGS := -DHAVE_CONFIG_H -Dd_fileno=d_ino -D_LFS64_LARGEFILE=1

ifeq ($(TARGET_ARCH),x86)
LOCAL_CFLAGS += -Ulinux
endif

LOCAL_MODULE := strace

LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)

LOCAL_MODULE_TAGS := debug

include $(BUILD_EXECUTABLE)
