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
    //initialization vars
    unsigned int UnitStateWord = 113;
    UnitStateWord = UnitStateWord << 9;
    unsigned int d = 0;
    unsigned int a = 0;
    unsigned int r = 0;


    /* read a sequence of at most 99 binary digits into buf */
    printf("Введіть значення направлення передачі - в регістр(0)/в пам’ять(1) \n");
    printf("%s :>> ",WHITE);
    scanf("%u", &d);
    UnitStateWord |= (d & 1) << 8;
    printf("%sВведіть 1-й операнд - регістр (R..R < 16)\n",RESET);
    printf("%s :>> ",RED);
    scanf("%u", &r);
    UnitStateWord |= (r & 15) << 4;
    printf("%sВведіть регістр адреси 2-го операнду (A..A < 16) \n",RESET);
    printf("%s :>> ",PURPLE);
    scanf("%u", &a);
    UnitStateWord |= (a & 15) << 0;
    printf("%sЗакодоване число = %u%s",BLUE ,UnitStateWord,RESET);
}



void process_two() {
    unsigned int a = 0;
    unsigned int r = 0;
    unsigned int d = 0;

    int ComposeInt;
    printf("\n\n%sВведіть закодоване число\n",BLUE);
    printf(" :>> ");
    scanf("%d", &ComposeInt);
    int ComposeInt_hash = ComposeInt;

    a = ((unsigned int)ComposeInt) & 15;


    ComposeInt = ComposeInt >> 4;
    r = ((unsigned int)ComposeInt) & 15;


    ComposeInt = ComposeInt >> 4;
    d = ((unsigned int)ComposeInt) & 1;

    printf("%sA := %d%s \n", WHITE, a, RESET);
    printf("%sR := %d%s \n", RED, r, RESET);
    printf("%sD := %d%s \n", PURPLE, d, RESET);
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
    printf("|%s%10d%s", WHITE,u,RESET);
    printf("|%s%18s%s", RED, byte_number, RESET);
    printf("|%s%18s%s|\n", PURPLE, byte_gray, RESET);
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
    if (dc[0] == '1' || dc[0] == '2' || dc[0] == '3') {
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
    unsigned int B = 0;
    unsigned int D = 0;
    int t = 0,avarage = 0;
    printf("Введіть значення A(1 число): ");
    scanf("%u", &A);
    printf("Введіть значення B(2 число): ");
    scanf("%u", &B);    
    printf("Введіть значення t(точка розриву): ");
    scanf("%d", &t);

    avarage = 2^(16-t)-1;
    D |= (B & avarage) << 0;
    A = A >> (16 - t);
    D |= (A & t) << (15 - t);
    byte_number_code_rewrite(D);
    printf("%s",D);
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color 0A");
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(h, (((8 << 4) | 10)));
    //printf("%s00%s", YELLOW, RESET);
    //printf("%s-.%s\n", WHITE, RESET);
    //process_one();
    //process_two();
    //SesionConvert();
    SesionGap();
    return 1;


}