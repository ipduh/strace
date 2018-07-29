#!/bin/bash
# build strace for android
# g0, 2018

if [ "$1" = "-h" -o "$1" = "-help" ]
  then
    echo -e "\t $0 arch api_version rmbuild verbose stip"
    echo -e "\t example: $0 arm64 24 rmbuild"
    echo -e "\t with no arguments, it will  attempt to build socat for the android seen over adb"
    echo ""
    exit 0
fi

PROJECT='strace'
COLORS=1
DEFAULT_ARCH='arm'
DEFAULT_SDKV='23'

SDKV=$(adb shell getprop ro.build.version.sdk 2>/dev/null)
[ -z "$SDKV" ] && SDKV=$DEFAULT_SDKV

ARCH=$(adb shell getprop ro.product.cpu.abi 2>/dev/null)
[ -z "$ARCH" ] && ARCH=$DEFAULT_ARCH
[[ "$ARCH" = *"-"* ]] && ARCH=$(echo "$ARCH" |awk -F '-' '{print $1}')

_not_in_archs(){
  archs=(arm arm64 mips mips64 x86 x86_64)
  for arch in ${archs[*]}
    do
      [ "$arch" = "$1" ] && return 1
  done
  echo "$1 is not a supported arch."
  return 0
}

if _not_in_archs $ARCH; then
   ARCH=$DEFAULT_ARCH
fi

[ "$COLORS" -eq "1" ] && ESC8='\033['
[ "$COLORS" -eq "1" ] && GREEN=${ESC8}"01;32m"
[ "$COLORS" -eq "1" ] && RED=${ESC8}"31;01m"
[ "$COLORS" -eq "1" ] && RESET=${ESC8}"00m"
STATUS=0

_die(){
  printf "${RED}%s${RESET}\n" "${1}"
  STATUS=$((STATUS+1))
  exit $STATUS
}

_say(){
  printf "${GREEN}%s${RESET}\n" "${1}"
}

# ARCH='arm64'
# SDKV='26'
# OP3='rmbuild'
# OP4='verbose'
# OP5='strip'
[ $# -ge 1 ] && ARCH=$1
[ $# -ge 2 ] && SDKV=$2
[ $# -ge 3 ] && OP3=$3
[ $# -ge 4 ] && OP4=$4
[ $# -ge 5 ] && OP5=$5

_say "Building $PROJECT for Architecture:$ARCH, Android SDK API version:$SDKV"

ROOT=`pwd`
BUILD="${ROOT}/builds/${ARCH}_${SDKV}"
mkdir -p $BUILD

HOST='arm-linux-androideabi'
TCDIR="${BUILD}/toolchain_${ARCH}${SDKV}"
SYSROOT="${BUILD}/toolchain_${ARCH}${SDKV}/sysroot"

[[ "$ARCH" = 'arm' ]] && HOST='arm-linux-androideabi'
[[ "$ARCH" = 'arm64' ]] && HOST='aarch64-linux-android'
[[ "$ARCH" = 'x86' ]] && HOST='i686-linux-android'
[[ "$ARCH" = 'x86_64' ]] && HOST='x86_64-linux-android'
[[ "$ARCH" = 'mips' ]] && HOST='mipsel-linux-android'
[[ "$ARCH" = 'mips64' ]] && HOST='mips64el-linux-android'

CC="$TCDIR/bin/$HOST-clang --sysroot=$SYSROOT"
LD="$TCDIR/bin/$HOST-ld"
AR="$TCDIR/bin/$HOST-ar"
RANLIB="$TCDIR/bin/$HOST-ranlib"
STRIP="$TCDIR/bin/$HOST-strip"
# SIZE="$TCDIR/bin/$HOST-size"
# CLIBS="-lm -lefence"
# LIBS="-static"

CFLAGS="-fPIE -fPIC"
# CFLAGS="-fPIE -fPIC -static -fno-debug-info-for-profiling -fno-debug-macro"
# CFLAGS="-02 -static"
[[ "$OP4" = 'verbose' ]] && CFLAGS="$CFLAGS -v"

LDFLAGS="-fPIE -pie"
[[ "$OP4" = 'verbose' ]] && LDFLAGS="$LDFLAGS -v"

_say "HOST: $HOST"
_say "CC: $CC"
_say "CFLAGS: $CFLAGS"
_say "LD: $LD"
_say "LDFLAGS: $LDFLAGS"
_say "AR: $AR"
_say "RANLIB: $RANLIB"
# _say "CLIBS: $CLIBS"
# _say "LIBS: $LIBS"

export CFLAGS="$CFLAGS"
export CC="$CC"
export RANLIB="$RANLIB"
export AR="$AR"
export LDFLAGS="$LDFLAGS"
export LD="$LD"
export PATH="$TCDIR/bin:$PATH"
# export SIZE="$SIZE"
# export CLIBS="$CLIBS"
# export LIBS="$LIBS"


rm -rf $TCDIR
V=''
[[ "$OP4" = 'verbose' ]] && V="-v"
make_standalone_toolchain.py $V --arch $ARCH --api $SDKV --install-dir $TCDIR --force

# Create configure script
# autoconf || _die "autoconf failed"
# cd $BUILD

cd ${ROOT}

${ROOT}/configure \
--host=$HOST \
|| _die "configure failed"

# --enable-arm-oabi
# --srcdir=$ROOT

_handle_bin(){
  if [ -e "${ROOT}/${1}" ]
    then
      mkdir -p ${ROOT}/binaries/${ARCH}/${SDKV}
      cp ${ROOT}/${1} ${ROOT}/binaries/${ARCH}/${SDKV}/${1}
      [[ "$OP5" = 'strip' ]] && $STRIP ${ROOT}/binaries/${ARCH}/${SDKV}/${1}

      _say "Build finished, ${1} has been generated successfuly in ${ROOT}/binaries/$ARCH/$SDKV/${1}"
  else
      STATUS=$((STATUS+1))
      printf "${RED}%s${RESET}\n" "${1} was not made"
  fi
}

# MAKE='make'
MAKE="$TCDIR/bin/make"
J=$(sysctl -n hw.ncpu)
# [ "$J" -ge 2 -a "$J" -le 16 ] && MAKE="$MAKE -j${J}"
_say "$MAKE"

$MAKE || _die "make failed"
_say "Build finished, $PROJECT has been generated successfuly in $ROOT/$PROJECT"

_handle_bin "$PROJECT"

if [ "$OP3" = 'rmbuild' -a -d "$BUILD" ]
  then
    rm -r ${BUILD}
    [ ! -d "$BUILD" ] && _say "deleted $BUILD"
fi

exit $STATUS
