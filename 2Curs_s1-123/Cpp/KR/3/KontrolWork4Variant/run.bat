@echo off
cmd /c gcc -c modules/sqlite3.c -static-libgcc -o objects/sqlite3.o
SET mypath=%~dp0
cmd /c gcc -c modules/main.cpp -static-libgcc -o objects/main.o
cmd /c gcc -c modules/node.cpp -static-libgcc -o objects/node.o
cmd /c gcc objects/sqlite3.o objects/node.o objects/main.o -static-libgcc -o program
pause

