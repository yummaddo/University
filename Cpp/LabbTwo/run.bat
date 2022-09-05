@echo off
@REM cmd /c gcc -c sqlite3.c -static-libgcc -o sqlite3.o
SET mypath=%~dp0
cmd /c g++ -c main.cpp -static-libstdc++ -o main.o
cmd /c g++ main.o -static-libstdc++ -o main

chcp 1251
cd /d "%~dp0"
cls
main.exe
exit /b
pause