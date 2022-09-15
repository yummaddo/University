@echo off
SET mypath=%~dp0
cmd /c g++ -c compiller.cpp -static-libstdc++ -o compiller.o
cmd /c g++ compiller.o -static-libstdc++ -o program
cmd /c program
pause