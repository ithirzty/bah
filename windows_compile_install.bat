@echo off
cd ./installer/libs/
mkdir "C:/Bah"
xcopy /E/H/C/I/Y "./common" "C:/Bah"
xcopy /E/H/C/I/Y "./windows" "C:/Bah"
cd ../
gcc windows.c -w  -static -I "C:/Bah/libs/windows/include/" -L "C:/Bah/libs/windows/" -l:gc.a -O1-lpthread -lm
MOVE ./a.exe C:/Windows/bah.exe