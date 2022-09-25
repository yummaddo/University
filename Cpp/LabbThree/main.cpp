#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"

char byte_number[17],byte_gray[17];


void process_one() {
    //initialization vars
    unsigned int UnitStateWord = 113;
    UnitStateWord = UnitStateWord << 9;
    unsigned int d = 0;
    unsigned int a = 0;
    unsigned int r = 0;


    /* read a sequence of at most 99 binary digits into buf */
    printf("Введіть значення направлення передачі - в регістр(0)/в пам’ять(1) \n");
    printf(" :>> ");
    scanf("%u", &d);
    UnitStateWord |= (d & 1) << 8;
    printf("Введіть 1-й операнд - регістр (R..R < 16)\n");
    printf(" :>> ");
    scanf("%u", &r);
    UnitStateWord |= (r & 15) << 4;
    printf("Введіть регістр адреси 2-го операнду (A..A < 16) \n");
    printf(" :>> ");
    scanf("%u", &a);
    UnitStateWord |= (a & 15) << 0;
    printf("%u", UnitStateWord);
}



void process_two() {
    unsigned int a = 0;
    unsigned int r = 0;
    unsigned int d = 0;

    int ComposeInt;
    printf("\n\nВведіть закодоване число\n");
    printf(" :>> ");
    scanf("%d", &ComposeInt);
    int ComposeInt_hash = ComposeInt;

    a = ((unsigned int)ComposeInt) & 15;


    ComposeInt = ComposeInt >> 4;
    r = ((unsigned int)ComposeInt) & 15;


    ComposeInt = ComposeInt >> 4;
    d = ((unsigned int)ComposeInt) & 1;

    printf("A := ");
    printf("%s%d%s \n", RED,a, RESET);

    printf("R := ");
    printf("%s%d%s \n", RED, r, RESET);

    printf("D := ");
    printf("%s%d%s \n", RED, d, RESET);
}



void SetBianryEcv(){

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

void gray_number_code_rewrite(unsigned int hash) {
    for (int i = 1; i < 17; i++) {
        if (hash % 2 == 1) {
            byte_gray[16 - i] = '1';
        }
        else {
            byte_gray[16 - i] = '0';
        }
        hash = hash / 2;
    }
    byte_gray[17] = '\0';
}


unsigned int grayENcode(unsigned int g)
{
    return g ^ (g >> 1); // gray code =  number xor ( number(i+1) )
}

unsigned int grayDEcode(unsigned int gray) 
{
    unsigned int bin;
    for (bin = 0; gray; gray >>= 1) {
      bin ^= gray;
    }
    return bin;
}


void print_table(unsigned int u){
    printf("------------------------------------------------\n");
    printf("|Decimal |  Number in bytes |  Number in gray  |\n");
    printf("------------------------------------------------\n");
    printf("|%8d", u);
    printf("|%18s", byte_number);
    printf("|%18s|\n", byte_gray);
    printf("------------------------------------------------\n");
}


void SesionConvert(){
    int d;
    unsigned int uns;
    printf("\n\nВведіть як закодованого числа\n");
    printf("Код Грея = 1\n");
    printf("Код Двійковий Код = 2\n");
    printf("Код Десятковий Код = 3\n");
    printf(" :>> \n");
    scanf("%d",&d);
    if(d==1){
        if (scanf(" %99[01]", byte_gray) == 1) {
        /* convert the binary digits one at a time into integer d */
        for (int i = 0; byte_gray[i]; i++) {
            if (byte_gray[i] == '1')
                uns += pow(2,i);
        }
        // geting gray code in byte ecvivalent
        gray_number_code_rewrite(uns);
        uns = grayDEcode(uns); // decode from gray to byte
        byte_number_code_rewrite(uns);
        print_table(uns);

    }

    } else if (d==2){



    } else if (d==3){

    }





}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //printf("%s00%s", YELLOW, RESET);
    printf("%s===3%s\n ", RED, RESET);
    //printf("%s-.%s\n", WHITE, RESET);
    process_one();
    process_two();

    SesionConvert();
    return 1;


}