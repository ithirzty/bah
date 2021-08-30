#!/bin/bash

cd ./src
bah ./main_darwin.bah -o ../bin/darwin_amd64
sudo cp ../bin/darwin_amd64 /opt/bah/bah
