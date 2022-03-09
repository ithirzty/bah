#!/bin/bash

# Copying librairies
cd installer
#common librairies
cp /opt/bah/builtin.bah ./libs/common/
cp /opt/bah/rcp.bah ./libs/common/
cp /opt/bah/fastrcp.bah ./libs/common/
cp /opt/bah/pipe.bah ./libs/common/
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
cp /opt/bah/matrix.bah ./libs/common/
cp /opt/bah/sqlite3.bah ./libs/common/
cp /opt/bah/gc.bah ./libs/common/
cp /opt/bah/iostream.bah ./libs/common/
cp /opt/bah/time.bah ./libs/common/
cp /opt/bah/rand.bah ./libs/common/
cp /opt/bah/memory.bah ./libs/common/
cp /opt/bah/http.bah ./libs/common/
cp /opt/bah/eval.bah ./libs/common/
#linux specific libs
# cp /opt/bah/window.bah ./libs/linux/
#static libs
cp -r /opt/bah/libs/linux/* ./libs/linux/libs/
cp -r /opt/bah/libs/windows/* ./libs/windows/libs/
cp -r /opt/bah/libs/darwin/* ./libs/darwin/libs/