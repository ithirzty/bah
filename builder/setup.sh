#!/bin/sh

# This is the builder setup script.
# The builder compiles the Bah compiler for linux, windows and darwin.
# The builder is configured to run on arch linux.

# darwin
git clone https://github.com/tpoechtrager/osxcross
cd osxcross
wget -nc https://s3.dockerproject.org/darwin/v2/MacOSX10.10.sdk.tar.xz
mv MacOSX10.10.sdk.tar.xz tarballs/
UNATTENDED=yes OSX_VERSION_MIN=10.7 ./build.sh
./build_gcc.sh
# currDir=$(readlink -f .)
# export PATH=$currDir"/target/bin:"$PATH


# windows
sudo pacman -S mingw-w64

# /home/alois/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/bin:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl