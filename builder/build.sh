#!/bin/sh

cd ../src

# linux
echo "---> LINUX BUILD"
bah ./main.bah -o ../bin/linux_amd64

# windows
echo "---> WINDOWS BUILD"
bah ./main.bah -o ../bin/windows.exe -CC x86_64-w64-mingw32-gcc -target windows

# dariwn (not working at the moment)
# echo "---> DARWIN BUILD"
# bah ./main_darwin.bah -o ../bin/darwin_amd64 -CC ../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -target darwin