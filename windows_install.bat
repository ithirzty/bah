@echo off
cd ./installer/libs/
mkdir "C:/Bah"
xcopy /E/H/C/I/Y "./common" "C:/Bah"

mkdir "C:/Bah/libs"
mkdir "C:/Bah/libs/windows"
mkdir "C:/Bah/libs/linux"
mkdir "C:/Bah/libs/darwin"
xcopy /E/H/C/I/Y "./windows/libs" "C:/Bah/libs/windows"
xcopy /E/H/C/I/Y "./linux/libs" "C:/Bah/libs/linux"
xcopy /E/H/C/I/Y "./darwin/libs" "C:/Bah/libs/darwin"

cd ../
gcc -I "C:/Bah/libs/windows/include/" -L "C:/Bah/libs/windows/" ./windows.c -static -O1 -w  -l:gc.a -lpthread -lm -o "../bin/windows.exe"

cd ../bin/
xcopy /S /Q /Y /F ".\windows.exe" "C:\WINDOWS\bah.exe"