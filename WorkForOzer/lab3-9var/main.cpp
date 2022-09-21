#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>





int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    unsigned int S,P;
    unsigned int Data = 0;
    printf("Введіть Код сисетеми що звантажується коритсувачем (S < 32768):  ");
    scanf("%u", &S);
    printf("Введіть привілейованість (P < 2):  ");
    scanf("%u", &P);
    Data |= (S & 32767) << 1;
    Data |= (P & 1) << 0;


    unsigned int encodedData;
    printf("Data в десятичній системі: %u", Data);
    printf("\n\nДекодування\n");
    printf("Введіть закодоване число: ");
    scanf("%u", &encodedData);

    P = encodedData & 1;
    encodedData = encodedData >> 1;
    S = encodedData & 32767; 
    printf("Закодованані дані\n");
    printf("P : %u\n", P);
    printf("S : %u", S);



    return 1;
}