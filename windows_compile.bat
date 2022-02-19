@echo off
cd ./src
bah ./main.bah -o ../bin/windows.exe
XCOPY /E/H/C/I/Y "..\bin\windows.exe" "C:\WINDOWS\bah.exe"