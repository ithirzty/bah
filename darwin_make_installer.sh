#!/bin/bash

# Making C source code
cd ./src
bah ./main_darwin.bah -c -o darwin.c
mv ./darwin.c ../installer/


# Copying librairies
cd ../installer
#common librairies
cp /opt/bah/builtin.bah ./libs/common/
cp /opt/bah/cBinds.bah ./libs/common/
cp /opt/bah/channel.bah ./libs/common/
cp /opt/bah/exec.bah ./libs/common/
cp /opt/bah/flags.bah ./libs/common/
cp /opt/bah/json.bah ./libs/common/
cp /opt/bah/markdown.bah ./libs/common/
cp /opt/bah/path.bah ./libs/common/
cp /opt/bah/queue.bah ./libs/common/
cp /opt/bah/reflect.bah ./libs/common/
cp /opt/bah/regex.bah ./libs/common/
cp /opt/bah/string.bah ./libs/common/
cp /opt/bah/thread.bah ./libs/common/
cp /opt/bah/rope.bah ./libs/common/
cp /opt/bah/iostream.bah ./libs/common/
cp /opt/bah/time.bah ./libs/common/
cp /opt/bah/rand.bah ./libs/common/
cp /opt/bah/memory.bah ./libs/common/
#linux specific libs
cp /opt/bah/http.bah ./libs/darwin/
cp /opt/bah/window.bah ./libs/darwin/
#static libs
cp -r /opt/bah/libs/* ./libs/darwin/libs/
