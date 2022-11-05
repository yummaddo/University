#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

#define RESET   "\033[1;32m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define DBLUE   "\033[1;36m"
#define BLACK   "\033[1;30m"
#define WHITE   "\033[1;37m"
#define PURPLE  "\033[1;35m"
#define BROWN   "\033[0;33m"

char byte_number[20];
char byte_gray[20];

void process_one() {
    unsigned int C, E, I, P, KKK;
    unsigned int Data = 0;
    printf("%sВведіть маску каналів                  (C < 16) :>>  ",RED);
    scanf("%u", &C);
    printf("%sВведіть маску зовнішнього перекривання (E < 2)  :>>  ",PURPLE);
    scanf("%u", &E);
    printf("%sВведіть маску внутршнього перекривання (I < 2)  :>>  ",BLACK);
    scanf("%u", &I);
    printf("%sВведіть маску програмного перекривання (P < 2)  :>>  ",WHITE);
    scanf("%u", &P);
    printf("%sВведіть маску зовнішнього перекривання (KKK < 8):>>  ",DBLUE);
    scanf("%u", &KKK);
    Data |= (C & 15) << 12;
    Data |= (E & 1) << 11;
    Data |= (I & 1) << 10;
    Data |= (P & 1) << 9;
    Data |= (KKK & 7) << 3;



    unsigned int encodedData;
    printf("%sЗакодоване число в шіснадцятирічній системі: %X %s",BLUE, Data,RESET);
    printf("\n\nДекодування\n");
    printf("Введіть закодоване число: ");
    scanf("%X", &encodedData);
    encodedData = encodedData >> 3;
    KKK = encodedData & 7;
    encodedData = encodedData >> 6;
    P = encodedData & 1;
    encodedData = encodedData >> 1;
    I = encodedData & 1;
    encodedData = encodedData >> 1;
    E = encodedData & 1;
    encodedData = encodedData >> 1;
    C = encodedData & 15;

    printf("Закодованані дані\n");
    printf("%sC : %u%s\n",RED, C, RESET);
    printf("%sE : %u%s\n",PURPLE, E, RESET);
    printf("%sI : %u%s\n", BLACK, I, RESET);
    printf("%sP : %u%s\n",WHITE, P, RESET);
    printf("%sKKK : %u%s\n", DBLUE, KKK, RESET);
}



void SetBianryEcv() {

}

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

void gray_number_code_rewrite(unsigned int hash) {

    for (int i = 0; i < 16; i++) {
        if (hash % 2 == 1) {
            byte_gray[i] = '1';
        }
        else {
            byte_gray[i] = '0';
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


void print_table(unsigned int u) {
    printf("%s--------------------------------------------------\n",RESET);
    printf("|Десяткова |  Двійкова        |  код Грея        |\n");
    printf("--------------------------------------------------\n");
    printf("|%s%10d%s", PURPLE,u,RESET);
    printf("|%s%18s%s", RED, byte_number, RESET);
    printf("|%s%18s%s|\n", WHITE, byte_gray, RESET);
    printf("--------------------------------------------------\n");
}


void SesionConvert() {
    int d;
    char dc[20];
    unsigned int uns = 0;;
    printf("\n\nВведіть як закодовано число  (щоб завершити сесію введіть будь-який символ)\n");
    printf("%sКод Грея = 1%s          \n", WHITE,RESET);
    printf("%sКод Двійковий Код = 2%s \n",RED, RESET);
    printf("%sКод Десятковий Код = 3%s\n",PURPLE, RESET);
    printf(" :>> ");
    scanf("%s", &dc);
    if (!strcmp(dc,"1") || !strcmp(dc, "2") || !strcmp(dc, "3") ){
        d = dc[0] - '0';
        if (d == 1) {
            printf("%sКод грея :>> ", WHITE);
            scanf("%s", &byte_gray);
            /* convert the binary digits one at a time into integer d */

            for (int i = 0; i < 17; i++) {
                if (byte_gray[i] == '1')
                    uns += pow(2, i);
            }
            // geting gray code in byte ecvivalent
            gray_number_code_rewrite(uns);
            uns = grayDEcode(uns); // decode from gray to byte
            byte_number_code_rewrite(uns);
            print_table(uns);
            char byte_number[20] = "";
            char byte_gray[20] = "";
            SesionConvert();
        }
        else if (d == 2) {
            printf("%sДвійковий код :>> ", RED);
            scanf("%s", &byte_number);
            /* convert the binary digits one at a time into integer d */
            for (int i = 0; i < 17; i++) {
                if (byte_number[i] == '1')
                    uns += pow(2, i);
            }
            byte_number_code_rewrite(uns);
            uns = grayENcode(uns); // decode from gray to byte
            gray_number_code_rewrite(uns);
            uns = grayDEcode(uns); // decode from gray to byte
            print_table(uns);
            char byte_number[20] = "";
            char byte_gray[20] = "";
            SesionConvert();
        }
        else if (d == 3) {
            printf("%sДесятковий код :>> ", PURPLE);
            scanf("%u", &uns);
            byte_number_code_rewrite(uns);
            uns = grayENcode(uns); // decode from gray to byte
            gray_number_code_rewrite(uns);
            uns = grayDEcode(uns); // decode from gray to byte
            print_table(uns);
            char byte_number[20] = "";
            char byte_gray[20] = "";
            SesionConvert();
        }
    }
}



void SesionGap() {
    unsigned int A = 0;
    unsigned int A1 = 0;
    unsigned int B = 0;
    unsigned int B1 = 0;
    unsigned int D = 0;
    int t = 0, avarage = 0;
    printf("Введіть значення A(1 число < 2^16) : ");
    scanf("%u", &A);
    printf("Введіть значення B(2 число < 2^16) : ");
    scanf("%u", &B);
    printf("Введіть значення t(точка розриву < 17) : ");
    scanf("%d", &t);

    byte_number_code_rewrite(A);
    printf("A :: ");
    for (int i = 0; byte_number[i] != '\0'; i++) {
        if (i < t) {
            printf("%s%c%s", PURPLE, byte_number[i], RESET);
        }
        else {
            printf("%c", byte_number[i]);
        }
    }
    printf("\n");
    byte_number_code_rewrite(B);
    printf("B :: ");
    for (int i = 0; byte_number[i] != '\0'; i++) {
        if (i > t - 1) {
            printf("%s%c%s", RED, byte_number[i], RESET);
        }
        else {
            printf("%c", byte_number[i]);
        }
    }
    printf("\n");
    B = B >> t;
    avarage = (pow(2, (16 - t)) - 1);
    B1 |= B & avarage << 0;

    avarage = (pow(2, (t)) - 1);
    A1 |= A & avarage << 0;

    D |= A1 << 0;

    D |= B1 << t;

    printf("Результат операції\n");
    printf("D :: ");
    byte_number_code_rewrite(D);
    for (int i = 0; byte_number[i] != '\0'; i++) {
        if (i < t) {
            printf("%s%c%s", PURPLE, byte_number[i], RESET);
        } else if (i > t - 1) {
            printf("%s%c%s", RED, byte_number[i], RESET);
        }
        else {
            printf("%c", byte_number[i]);
        }
    }
    printf("\n");
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0A");
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);    
    process_one();
    printf("\n{Блок конвертації}\n");
    SesionConvert();
    printf("\n{Блок розриву}\n");
    SesionGap();
    return 1;
}