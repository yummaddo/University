@echo off
SET mypath=%~dp0
cmd /c gcc -c main.cpp -static-libgcc -o main.o
cmd /c gcc main.o -static-libgcc -o main
cmd /c main
pause