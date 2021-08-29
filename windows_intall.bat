@echo off
cd ./installer/libs/
mkdir "C:/Bah"
xcopy /E/H/C/I/Y "./common" "C:/Bah"
xcopy /E/H/C/I/Y "./windows" "C:/Bah"
cd ../../bin/
xcopy /S /Q /Y /F ".\windows.exe" "C:\WINDOWS\bah.exe"