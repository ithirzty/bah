#!/bin/bash
if command -v apt &> /dev/null
then
    echo "╭─────────────────────────────╮"
    echo "│Installing dependencies (apt)│"
    echo "╰─────────────────────────────╯"
    {
    sudo apt-get install gcc build-essential libgc-dev checkinstall zlib1g-dev libssl-dev -y
    } &> /dev/null
    
else
    if command -v pacman &> /dev/null
    then
        echo "╭────────────────────────────────╮"
        echo "│Installing dependencies (pacman)│"
        echo "╰────────────────────────────────╯"
        {
        yes | sudo pacman -Sy gcc gc openssl #libgccjit
        } &> /dev/null
        
    else
        echo "Could not install dependencies, no package manager found (pacman or apt)."
        echo "Please install: "
        echo "- gcc"
        echo "- build-essential (for gcc) (or equivalent)"
        echo "- libgc (dev branch) (or equivalent)"
        echo "- libssl (dev branch) (or equivalent)"
        echo "- zlib (dev branch) (or equivalent)"
        exit
    fi
fi

echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"

# Moving std-libs
{
cd ./installer
sudo mkdir /opt/bah
sudo mkdir /opt/bah/libs/
sudo mkdir /opt/bah/libs/linux/
sudo mkdir /opt/bah/libs/windows/
sudo mkdir /opt/bah/libs/darwin/
sudo cp -r ./libs/linux/libs/* /opt/bah/libs/linux/
sudo cp -r ./libs/windows/libs/* /opt/bah/libs/windows/
sudo cp -r ./libs/darwin/libs/* /opt/bah/libs/darwin/
sudo cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*
sudo rm /opt/bah/cache/*

# Moving bah exec
sudo cp ../bin/linux_amd64 /opt/bah/bah
sudo cp -s /opt/bah/bah /bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /bin/bah
rm ./a.out

# Making the update script executable
cd ../
sudo chmod +x ./update.sh

} &> /dev/null
echo -e "\033[1;32m╭─────────────────────────────────────────────────────────────╮"
echo              "│                            Done!                            │"
echo              "│             Bah is now installed on your system.            │"
echo              "│To test if the installation was successful, execute 'bah -v'.│"
echo              "╰─────────────────────────────────────────────────────────────╯"
echo -e "\033[0m"