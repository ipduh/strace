# Copyright 2006 The Android Open Source Project

ifneq ($(TARGET_SIMULATOR),true)

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

LOCAL_C_INCLUDES := \
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

endif  # TARGET_SIMULATOR != true
