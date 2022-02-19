@echo off

cd ./src
bah "./main_windows.bah" -c -o windows.c
MOVE ./windows.c ../installer/windows.c

cd ../installer
@REM xcopy /S /Q /Y /F "C:/Bah/iostream.bah" ".\libs\windows\"
@REM xcopy /S /Q /Y /F "C:/Bah/memory.bah" ".\libs\windows\"
@REM xcopy /S /Q /Y /F "C:/Bah/time.bah" ".\libs\windows\"
@REM xcopy /S /Q /Y /F "C:/Bah/rand.bah" ".\libs\windows\"
@REM xcopy /E/H/C/I/Y "C:/Bah/libs" "./libs/windows/libs"