#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void OutPutInformation(int type){
    switch (type)
    {
    case 0:
        printf("Input D:  ");    
        break;
    case 1:
        printf("Input R: ");    
        break;
    case 2:
        printf("Input A: ");    
        break;
    case 3:
        printf("Information has coded  ");    
        break;
    }
}


void process_one(){
    //initialization vars
    char D[1];
    char R[4];
    char A[4];
    unsigned int UnitStateWord = 113;
    // printf("Value: %u\n", UnitStateWord);
    UnitStateWord = UnitStateWord << 9;
    // printf("Value: %u\n", UnitStateWord);
    unsigned int d = 0;
    OutPutInformation(0);
    /* read a sequence of at most 99 binary digits into buf */
    if (scanf(" %99[01]", D) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; D[i]; i++) {
            d = (d << 1) | (D[i] - '0');
        }
    }
    UnitStateWord|=(d&1)<<8;
    // printf("Value: %u\n", UnitStateWord);
    OutPutInformation(1);
    if (scanf(" %99[01]", R) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; R[i]; i++) {
            d = (d << 1) | (R[i] - '0');
        }
    }
    UnitStateWord|=(d&0XF)<<4;
    // printf("Value: %u\n", UnitStateWord);
    OutPutInformation(2);
    if (scanf(" %99[01]", A) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; A[i]; i++) {
            d = (d << 1) | (A[i] - '0');
        }
    }
    UnitStateWord|= d&0XF<<0;
    // printf("Value: %u\n", UnitStateWord);
    // convert into binary
    char number[16];
    unsigned int hash = UnitStateWord;
    for (int i = 1; i < 17; i++){
        if (hash % 2 == 1) {
            number[16-i] = '1';
        } else {
            number[16-i] = '0';
        }
        hash = hash / 2;
    }
    OutPutInformation(3);
    printf("In byte code: %s\n", number);

}



int main(){


    process_one();


    return 1;
}