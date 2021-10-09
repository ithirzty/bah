#!/bin/bash

if ! command -v apt &> /dev/null
then
  echo "╭───────────────────────────────╮"
  echo "│Installing dependencies (clang)│"
  echo "╰───────────────────────────────╯"
  xcode-select --install
fi

echo "╭────────────────────────────────────────────────╮"
echo "│Creating bah directory and creating bah std-libs│"
echo "╰────────────────────────────────────────────────╯"

{
cd ./installer
sudo mkdir /opt/bah
sudo mkdir /opt/bah/libs
sudo cp -r ./libs/darwin/* /opt/bah/
sudo cp ./libs/common/* /opt/bah/
sudo chmod 777 /opt/bah/*
} &> /dev/null
# Compilling source code
echo "╭──────────────────────╮"
echo "│Compilling source code│"
echo "╰──────────────────────╯"
line=$(head -n 1 ./darwin.c)
line=$(echo ${line:0: ${#line} - 1} | cut -b 18-)
$line

{
sudo cp ./a.out /opt/bah/bah
sudo ln -s /opt/bah/bah /usr/bin/bah
sudo chmod 777 /opt/bah
sudo chmod +x /usr/bin/bah
export PATH="/opt/bah/:$PATH"
rm ./a.out
} &>/dev/null
