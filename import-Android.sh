#!/bin/bash
#
# Assists with importing a new version of Strace for Android.
# Removes source files from the Strace original distribution that are not
# needed on Android.
#
# Run this script after extracting an Strace distribution into external/strace.
#

UNNEEDED_SOURCES="\
  Makefile.am \
  Makefile.in \
  README-freebsd \
  README-sunos4 \
  README-svr4 \
  acinclude.m4 \
  aclocal.m4 \
  config.guess \
  config.h.in \
  config.log \
  config.status \
  config.sub \
  configure \
  configure.ac \
  debian \
  depcomp \
  errnoent.sh \
  freebsd \
  install-sh \
  linux/alpha \
  linux/avr32 \
  linux/bfin \
  linux/hppa \
  linux/ia64 \
  linux/m68k \
  linux/microblaze \
  linux/powerpc \
  linux/s390 \
  linux/s390x \
  linux/sh \
  linux/sh64 \
  linux/sparc \
  linux/sparc64 \
  linux/tile \
  m4 \
  missing \
  mkinstalldirs \
  signalent.sh \
  sunos4 \
  svr4 \
  syscallent.sh \
  test \
  tests \
  xlate.el \
"

rm -rf $UNNEEDED_SOURCES
find . -name ioctlent.h.in -print0 | xargs -0 rm -f
