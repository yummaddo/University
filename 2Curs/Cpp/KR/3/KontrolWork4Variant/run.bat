@echo off
cmd /c gcc -c sqlite3.c -static-libgcc -o sqlite3.o
SET mypath=%~dp0
cmd /c gcc -c main.cpp -static-libgcc -o main.o
cmd /c gcc sqlite3.o main.o -static-libgcc -o program
pause

