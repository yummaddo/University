@echo off
cmd /c gcc -c sqlite3.c -static-libgcc -o sqlite3.o
SET mypath=%~dp0
cmd /c g++ -c main.cpp -static-libstdc++ -o main.o
cmd /c g++ sqlite3.o main.o -static-libstdc++ -o program
cmd /c program
pause