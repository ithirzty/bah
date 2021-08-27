#!/bin/bash

# Fetching the repo
echo "╭───────────────────╮"
echo "│Updating repository│ Note: this will fail if you"
echo "╰───────────────────╯ made any modification to it."
git pull origin main
# Installing the new version
sudo chmod +x ./install.sh
sudo ./install.sh