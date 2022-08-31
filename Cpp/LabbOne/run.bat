@echo off
@REM cmd /c gcc -c C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\sqlite3.c -o C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\sqlite3.o
SET mypath=%~dp0
cmd /c g++ -c main.cpp -o main.o
cmd /c g++ sqlite3.o main.o -o program
cmd /c program
pause