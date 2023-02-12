@echo off
SET mypath=%~dp0
cmd /c g++ -c main.cpp -static-libstdc++ -o main.o
cmd /c g++ main.o -static-libstdc++ -o program
cmd /c program
pause