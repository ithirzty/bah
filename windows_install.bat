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

cd ../../bin/
echo F | xcopy /S/Q/Y/F/I ".\windows.exe" "C:\WINDOWS\bah.exe"