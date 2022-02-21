#!/bin/sh

cd ../src

# linux
echo -e "\n---> LINUX BUILD\n"
bah ./main.bah -o ../bin/linux_amd64
bah ./main.bah -o ../installer/linux.c -c
sudo cp ../bin/linux_amd64 /opt/bah/bah

# windows
echo -e "\n---> WINDOWS BUILD\n"
bah ./main.bah -o ../bin/windows.exe -CC x86_64-w64-mingw32-gcc -target windows
bah ./main.bah -o ../installer/windows.c -CC x86_64-w64-mingw32-gcc -target windows -c

# dariwn (not working at the moment)
echo "\n---> DARWIN BUILD\n"
# bah ./main.bah -o ../bin/darwin_amd64 -CC ../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -target darwin
bah ./main.bah -o ../installer/darwin.c -CC ../builder/osxcross/target/bin/x86_64h-apple-darwin14-clang -target darwin -c