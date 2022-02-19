#!/bin/bash

cd ./src
bah ./main.bah -o ../bin/darwin_amd64
sudo cp ../bin/darwin_amd64 /opt/bah/bah
