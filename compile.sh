#!/bin/bash

cd ./src
bah ./main.bah -o ../bin/bah
sudo cp ../bin/bah /opt/bah/bah
rm ../bin/bah