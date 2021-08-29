@echo off
cd ./installer/libs/
mkdir "C:/Bah"
xcopy /E/H/C/I/Y "./common" "C:/Bah"
xcopy /E/H/C/I/Y "./windows" "C:/Bah"
cd ../
gcc windows.c -w  -static C:/Bah/libs/gc.a -lpthread -lm
MOVE ./a.exe C:/Windows/bah.exe