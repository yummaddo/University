#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>
#include <string.h>

char byte_number[20];


#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"


void byte_number_code_rewrite(unsigned int hash) {
    // bytes rewrite

    for (int i = 0; i < 16; i++) {
        if (hash % 2 == 1) {

            byte_number[i] = '1';
        }
        else {
            byte_number[i] = '0';
        }

        hash = hash / 2;
    }
    byte_number[17] = '\0';

}


int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0A");
	unsigned int a = 4567;
    unsigned int res = 0;
    unsigned int leftside = 0;
    unsigned int rightside = 0;
    rightside |= a >> 11;
    leftside |= (a & 31) << 0;

    unsigned int test = 0x1E;
    byte_number_code_rewrite(a);
    printf("%sIn bytes (4567):  ", BLACK);
    for (int i = 0; i < 16; i++) {
        if (i >= 6 && i <= 10) {
            printf("%s%c%s", RED, byte_number[i], BLACK);
        }
        else {
            printf("%c", byte_number[i]);
        }
    }
    byte_number_code_rewrite(test);
    printf("\nIn bytes (0x1E):  %s\n", byte_number);
    res |= test << 6;
    res |= leftside << 0;
    res |= rightside << 11;
    byte_number_code_rewrite(res);
    printf("RESULT = ");
    for (int i = 0; i < 16; i++) {
        if (i >= 6 && i <= 10) {
            printf("%s%c%s",RED,byte_number[i], BLACK);
        }
        else {
            printf("%c", byte_number[i]);
        }
    }
}
