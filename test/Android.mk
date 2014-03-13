#
# Copyright (C) 2014 The Android Open Source Project
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

define declare-strace-test-target
  include $(CLEAR_VARS)
  LOCAL_SRC_FILES := $(1)
  LOCAL_CFLAGS := -Wno-unused-parameter -Wno-error=return-type
  LOCAL_MODULE := strace-$(basename $(1))-test
  LOCAL_MODULE_PATH := $(TARGET_OUT_OPTIONAL_EXECUTABLES)
  LOCAL_MODULE_TAGS := tests
  LOCAL_ADDITIONAL_DEPENDENCIES := $(LOCAL_PATH)/Android.mk
  include $(BUILD_EXECUTABLE)
endef

src_files := \
    childthread.c \
    clone.c \
    fork.c \
    leaderkill.c \
    mmap_offset_decode.c \
    mtd.c \
    select.c \
    sfd.c \
    sig.c \
    sigkill_rain.c \
    sigreturn.c \
    skodic.c \
    threaded_execve.c \
    ubi.c \
    vfork.c \
    wait_must_be_interruptible.c \

$(foreach file, $(src_files), $(eval $(call declare-strace-test-target,$(file))))

# Simple sanity tests meant to be run manually on device. Tests expect that
# strace will report "exit with 0" at the end of the programs. Some tests
# document what string should be expected in the output and for them additional
# checks is made (*-expected output vars)).
#
# Failure should be inspected manually. Usually they require a special test
# setup that can't be easily automated.
#
# adb sync is requreired before running "mm run-strace-tests".
# logs are pulled automatically from the device to the root of the tree
# (strace-log-*)

childthread-expected-output := 'write(1, "OK\\n",'
clone-expected-output := 'write(1, "original\\n",'
fork-expected-output := 'write(1, "parent\\n",'
leaderkill-expected-output := 'write(1, "OK\\n",'
mmap_offset_decode-expected-output := ''
mtd-expected-output := ''
select-expected-output := ''
sfd-expected-output := ''
sig-expected-output := 'write(2, "qwerty\\n",'
sigkill_rain-expected-output := ''
sigreturn-expected-output := 'RT_1 RT_3 RT_31 RT_32'
skodic-expected-output := ''
threaded_execve-expected-output := ''
ubi-expected-output := ''
vfork-expected-output := 'write(1, "parent\\n",'
wait_must_be_interruptible-expected-output := 'write(1, "Good: wait seems to be correctly"'

run-strace-%-test: TEST_TMP_DIR := /data/local/tmp
run-strace-%-test:
	@printf >&2 "\n$*: RUNNING...\n" ; \
	adb shell rm -f $(TEST_TMP_DIR)/strace-log-$* ; \
	timeout -s 9 10 adb shell strace -f -o$(TEST_TMP_DIR)/strace-log-$* strace-$*-test > /dev/null ; \
	adb pull $(TEST_TMP_DIR)/strace-log-$* 2> /dev/null ; \
	if adb shell cat $(TEST_TMP_DIR)/strace-log-$* | grep "exited with 0" > /dev/null ; \
	then \
		if [ -n $($*-expected-output) ] ; then \
			if adb shell cat $(TEST_TMP_DIR)/strace-log-$* | grep $($*-expected-output) > /dev/null ; \
				then printf >&2 "$*: PASSED\n" ; \
				else printf >&2 "$*: FAILED\n" ; \
			fi ; \
		else \
			printf >&2 "$*: PASSED\n" ; \
		fi ; \
	else \
		printf >&2 "$*: FAILED\n" ; \
	fi

adb-sync:
	adb sync

run-strace-tests: adb-sync $(foreach file, $(src_files), run-strace-$(basename $(file))-test)
