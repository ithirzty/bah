#!/bin/bash

echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"

# Moving std-libs
{
cd ./installer
sudo mkdir /opt/bah
sudo mkdir /opt/bah/libs
sudo cp -r ./libs/darwin/* /opt/bah/
sudo cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*

# Moving bah exec
sudo cp ../bin/darwin_amd64 /opt/bah/bah
sudo cp -s /opt/bah/bah /bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /bin/bah
rm ./a.out

# Making the update script executable
cd ../

} &> /dev/null
echo -e "\033[1;32m╭─────────────────────────────────────────────────────────────╮"
echo              "│                            Done!                            │"
echo              "│             Bah is now installed on your system.            │"
echo              "│To test if the installation was successful, execute 'bah -v'.│"
echo              "╰─────────────────────────────────────────────────────────────╯"
echo -e "\033[0m"
