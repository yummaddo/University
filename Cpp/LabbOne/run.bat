@echo off
@REM cmd /c gcc -c C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\sqlite3.c -o C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\sqlite3.o
cmd /c g++ -c C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\main.cpp -o C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\main.o
cmd /c g++ C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\sqlite3.o C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\main.o -o C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\program
cmd /c C:\Users\OchiAnthropos\Documents\GitHub\University\Cpp\LabbOne\program
pause