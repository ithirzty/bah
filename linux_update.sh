#!/bin/bash

# Check if any update is available
{
git fetch
} &> /dev/null
HEADHASH=$(git rev-parse HEAD)
UPSTREAMHASH=$(git rev-parse main@{upstream})
if [ "$HEADHASH" == "$UPSTREAMHASH" ]
then
    echo -e "\033[1;32m╭────────────────────────╮"
    echo              "│Everything is up to date│"
    echo              "╰────────────────────────╯"
    echo -e "\033[0m"
    exit 0
fi

# Updating the repo
echo "╭───────────────────╮"
echo "│Updating repository│ Note: this will fail if you"
echo "╰───────────────────╯ made any modification to it."
echo ""
git pull origin main
# Installing the new version
sudo chmod +x ./linux_install.sh
sudo ./linux_install.sh