#!/bin/bash

{
  echo "╭───────────────────────────────╮"
  echo "│Installing dependencies (clang)│"
  echo "╰───────────────────────────────╯"
  xcode-select --install
} &> /dev/null

echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"

# Moving std-libs
{
cd ./installer
sudo mkdir /opt
sudo mkdir /opt/bah
sudo mkdir /opt/bah/libs
sudo cp -r ./libs/darwin/* /opt/bah/
sudo cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*

# Moving bah exec
sudo cp ../bin/darwin_amd64 /opt/bah/bah
sudo ln -s /opt/bah/bah /bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /bin/bah
export PATH="/opt/bah/:$PATH"

cd ../

} &> /dev/null

echo -e "\033[1;32m╭─────────────────────────────────────────────────────────────╮"
echo              "│                            Done!                            │"
echo              "│             Bah is now installed on your system.            │"
echo              "│To test if the installation was successful, execute 'bah -v'.│"
echo              "╰─────────────────────────────────────────────────────────────╯"
echo -e "\033[0m"
