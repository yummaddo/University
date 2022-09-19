#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char byte_number[17];


void OutPutInformation(int type) {
    switch (type)
    {
    case 0:
        printf("Input D in bytes (2 > inputed): ");
        break;
    case 1:
        printf("Input R in bytes (16 > inputed): ");
        break;
    case 2:
        printf("Input A in bytes (16 > inputed): ");
        break;
    case 3:
        printf("Information has coded  ");
        break;
    case 4:
        printf("Input composed int number: ");
        break;
    }
}

void byte_number_code_rewrite(unsigned int hash) {
    for (int i = 1; i < 17; i++) {
        if (hash % 2 == 1) {
            byte_number[16 - i] = '1';
        }
        else {
            byte_number[16 - i] = '0';
        }
        hash = hash / 2;
    }
    byte_number[17] = '\0';
}

// encoded in gray code
unsigned int grayENcode(unsigned int g)
{
    return g ^ (g >> 1); // gray code =  number xor ( number(i+1) )
}


// decoded in normal code
unsigned int grayDEcode(unsigned int gray) 
{
    unsigned int bin;
    for (bin = 0; gray; gray >>= 1) {
      bin ^= gray;
    }
    return bin;
}


void GrayTable(int composed, unsigned int a, unsigned int  r, unsigned int d) {
    // composed
    printf("----------------------------------------------------------------\n");
    printf("|Element        |Decimal |  Number in bytes |  Number in gray  |\n");
    printf("----------------------------------------------------------------\n");
    printf("|Composed Number");
    printf("|%8d", composed);
    byte_number_code_rewrite((unsigned int)composed);
    printf("|%18s", byte_number);
    byte_number_code_rewrite(grayENcode((unsigned int)composed));
    printf("|%18s|\n", byte_number);
    
    printf("|Coded A        ");
    printf("|%8d", a);
    byte_number_code_rewrite((a));
    printf("|%18s", byte_number);
    byte_number_code_rewrite(grayENcode(a));
    printf("|%18s|\n", byte_number);
    
    printf("|Coded R        ");
    printf("|%8d", r);
    byte_number_code_rewrite(r);
    printf("|%18s", byte_number);
    byte_number_code_rewrite(grayENcode(r));
    printf("|%18s|\n", byte_number);
    
    printf("|Coded D        ");
    printf("|%8d", d);
    byte_number_code_rewrite(d);
    printf("|%18s", byte_number);
    byte_number_code_rewrite(grayENcode(d));
    printf("|%18s|\n", byte_number);
    printf("----------------------------------------------------------------\n");

}



void process_one() {
    //initialization vars
    char D[1];
    char R[4];
    char A[4];
    unsigned int UnitStateWord = 113;
    UnitStateWord = UnitStateWord << 9;
    unsigned int d = 0;
    unsigned int a = 0;
    unsigned int r = 0;

    OutPutInformation(0);
    /* read a sequence of at most 99 binary digits into buf */
    if (scanf(" %99[01]", D) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; D[i]; i++) {
            d = (d << 1) | (D[i] - '0');
        }
    }
    UnitStateWord |= (d & 1) << 8;

    // printf("Value: %u\n", UnitStateWord);
    OutPutInformation(1);
    if (scanf(" %99[01]", R) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; R[i]; i++) {
            r = (r << 1) | (R[i] - '0');
        }
    }
    UnitStateWord |= (r & 15) << 4;

    // printf("Value: %u\n", UnitStateWord);
    OutPutInformation(2);
    if (scanf(" %99[01]", A) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; A[i]; i++) {
            a = (a << 1) | (A[i] - '0');
        }
    }
    UnitStateWord |= a & 15 << 0;
    // printf("Value: %u\n", UnitStateWord);
    // convert into binary
    byte_number_code_rewrite(UnitStateWord);
    printf("\n Composed: %s", byte_number);
    printf("\n Composed in number view: ");
    printf("%u\n", UnitStateWord);
    OutPutInformation(3);

    printf("\n\nGray Table\n");
    GrayTable(UnitStateWord, a,r,d);
}


void process_two() {
    unsigned int a = 0;
    unsigned int r = 0;
    unsigned int d = 0;


    printf("\n\nDecompose program \n\n");
    OutPutInformation(4);
    int ComposeInt;
    scanf("%d", &ComposeInt);
    int ComposeInt_hash = ComposeInt;

    a = ((unsigned int)ComposeInt) & 15;
    byte_number_code_rewrite(ComposeInt);
    printf("\n Composed: %s", byte_number);
    byte_number_code_rewrite(a);
    printf("\n A:        %s", byte_number);
    printf("\n A in number view: ");
    printf("%u", a);


    ComposeInt = ComposeInt >> 4;
    r = ((unsigned int)ComposeInt) & 15;

    byte_number_code_rewrite(ComposeInt);
    printf("\n Composed: %s", byte_number);
    byte_number_code_rewrite(r);
    printf("\n R:        %s", byte_number);
    printf("\n R in number view: ");
    printf("%u", r);


    ComposeInt = ComposeInt >> 4;
    d = ((unsigned int)ComposeInt) & 1;


    byte_number_code_rewrite(ComposeInt);
    printf("\n Composed: %s", byte_number);
    byte_number_code_rewrite(d);
    printf("\n D:        %s", byte_number);
    printf("\n D in number view: ");
    printf("%u\n", d);
    printf("\n\nGray Table\n");
    GrayTable(ComposeInt_hash, a,r,d);

}


int main() {
    // process_one();
    process_two();

    return 1;
}