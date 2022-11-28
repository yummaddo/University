#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
using namespace std;

#define RESET   "\033[1;32m" // green
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define DBLUE   "\033[1;36m"
#define BLACK   "\033[1;30m"
#define WHITE   "\033[1;37m"
#define PURPLE  "\033[1;35m"
#define BROWN   "\033[0;33m"


typedef struct Product {
    char name[24];
    char type[20];
    int mgz;
    int ram;
    Product* next;
} Product;

Product* start = NULL;
int end_typing = 1;


void print_matrix(int m[9][9], int prefix) {
    int max_number = 9 * 9;
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (!prefix) {
                if (y%2==0) {
                    printf("%s%5d", RED, m[y][x]);
                }
                else {
                    printf("%s%5d", BLACK, m[y][x]);
                }
            }
            else {
                if (x % 2 == 0) {
                    printf("%s%5d", RED, m[y][x]);
                }
                else {
                    printf("%s%5d", BLACK, m[y][x]);
                }
            
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("%s", BLACK);

}


void zav1() {
    srand(time(NULL));
    int x;
    //x = rand();
    int matrix[9][9];
    int matrix90[9][9];

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            matrix[y][x] = rand() % 1000;
        }
    }
    printf("\nЗгенерована матриця\n\n");
    print_matrix(matrix,0);
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            matrix90[x][8 - y] = matrix[y][x];
        }
    }
    printf("\nПеревернута на 90 градусів у право попередня матриця\n\n");
    print_matrix(matrix90,1);
}


void display()
{
    Product* ptr;
    if (start == NULL)
    {
        return;
    }
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("|%23s|%17d|%35d|%9s|\n", ptr->name, ptr->mgz, ptr->ram, ptr->type);
            ptr = ptr->next;
        }
    }
}


void insert_end()
{
    Product* temp, * ptr;
    temp = (Product*)malloc(sizeof(Product));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        return;
    }
    printf("Новий ПЭВМ >> ");
    scanf("%s", &temp->name);

    if (strcmp(temp->name, "***")) {
        scanf("%d", &temp->mgz);
        scanf("%d", &temp->ram);
        scanf("%s", &temp->type);

        if (temp->ram < 0) {
            printf("Кількість RAM повинна бути більша за нуль\n");
            insert_end();
        }
        else if (temp->mgz < 0) {
            printf("Частота повинна бути більша за нуль\n");
            insert_end();
        }
        else {
            temp->next = NULL;
            if (start == NULL)
            {
                start = temp;
            }
            else
            {
                ptr = start;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }
        }
    }
    else {
        end_typing = 0;
    }
}


void create()
{
    Product* temp, * ptr;
    temp = (Product*)malloc(sizeof(Product));
    if (temp == NULL)
    {
        printf("nOut of Memory Space:\n");
        exit(0);
    }
    printf("Новий ПЭВМ >> ");
    scanf("%s", &temp->name);

    if (strcmp(temp->name, "***")) {
        scanf("%d", &temp->mgz);
        scanf("%d", &temp->ram);
        scanf("%s", &temp->type);

        if (temp->ram < 0) {
            printf("Кількість RAM повинна бути більша за нуль\n");
            insert_end();
        }
        else if (temp->mgz < 0) {
            printf("Частота повинна бути більша за нуль\n");
            insert_end();
        }
        else {

            temp->next = NULL;
            if (start == NULL)
            {
                start = temp;
            }
            else
            {
                ptr = start;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }
        }

    }
    else {
        end_typing = 0;
    }

}


int is_char_avarage(char a, char b) {
    //       [testing]
    // printf("eng: a rus a = %d\n", is_char_avarage('a', 'а')); assert 1
    // printf("eng: A rus a = %d\n", is_char_avarage('A', 'а')); assert 1
    // printf("eng: a rus А = %d\n", is_char_avarage('a', 'А')); assert 1
    // printf("eng: a eng A = %d\n", is_char_avarage('a', 'A')); assert -1
    // printf("eng: a end a = %d\n", is_char_avarage('a', 'a')); assert -1
    // printf("eng: A end q = %d\n", is_char_avarage('A', 'q')); assert 1
    // printf("eng: a end Q = %d\n", is_char_avarage('a', 'Q')); assert 1
    // printf("eng: Q end A = %d\n", is_char_avarage('Q', 'A')); assert 0
    // printf("eng: A end Q = %d\n", is_char_avarage('A', 'Q')); assert 1

    if (abs(a - b) != 32) { // a != b like A == a but A != b
        if (a - '0' < 0 && b - '0' < 0) {
            if (a - '0' < -80) {
                a = (a - '0' + 32) + '0';
            }
            if (b - '0' < -80) {
                b = (b - '0' + 32) + '0';

            }
            //printf("a(%c = %d)     b(%c = %d)\n ", a, a - '0', b, b - '0');
            if (a - '0' < b - '0') {
                return 1;
            }
            else if (a - '0' > b - '0') {
                return 0;
            }
            else {
                return -1;
            }

        }
        else if (a - '0' > 0 && b - '0' < 0) {

            return 1;
        }
        else if (b - '0' > 0 && a - '0' < 0) {

            return 0;
        }
        else
        {

            if (a - '0' < 49) {
                a = (a - '0' + 32) + '0';
            }
            if (b - '0' < 49) {
                b = (b - '0' + 32) + '0';
            }
            if (a - '0' > b - '0') {
                return 0;
            }
            else if (a - '0' < b - '0') {
                return 1;
            }
            else {
                return -1;
            }
        }
    }
    else {

        return -1;
    }
}


bool is_avarage(char name1[], char name2[]) {
    char n1_cpy[24];
    char n2_cpy[24];
    strcpy(n1_cpy, name1);
    strcpy(n2_cpy, name2);
    int code1, code2;

    for (int i = 0; n1_cpy[i] != '\0' || n2_cpy[i] != '\0'; i++) {
        if (is_char_avarage(n1_cpy[i], n2_cpy[i]) == 1) { // a > b  ::>> n1 < n2
            return true;
        }
        else if (is_char_avarage(n1_cpy[i], n2_cpy[i]) == 0) { // a < b  ::>> n2 < n2
            return false;
        }
        else { // a == b
            if (n1_cpy[i + 1] == '\0' && n2_cpy[i + 1] != '\0') { // n2 > n1
                return true;
            }
            else if (n1_cpy[i + 1] != '\0' && n2_cpy[i + 1] == '\0') { // n1 > n2
                return false;
            }
            else {
                continue;
            }
        }
    }
    return true; // if n1==n2  return true
}


struct Product* sort(struct Product* root) //  сортування структури Product по numbers
{
    struct Product* new_root = NULL;

    while (root != NULL)
    {
        struct Product* node = root;
        root = root->next;
        if (new_root == NULL || is_avarage(node->name, new_root->name))
        {
            node->next = new_root;
            new_root = node;
        }
        else
        {
            struct Product* current = new_root;
            while (current->next != NULL && !is_avarage(node->name, current->next->name))
            {
                current = current->next;
            }

            node->next = current->next;
            current->next = node;
        }
    }

    return new_root;
}



void zav2() {
    printf("{Щоб завершити введення, введіть \"***\" і натисніть enter}\n");
    printf("Назва процесора, частота процесора, кількість оперативної памяті, тип\n");
    create();
    while (end_typing) {
        insert_end();
    }; // name == exit 
    printf("\n\nПочаткова таблиця\n\n");
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Характеристики ПЭВМ                                                                    |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Процесор               |Частота (Mgz)    |RAM (Mb)                           |Тип      |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    display();
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Тип: C - CISC-процесор, R - RISC-процесор                                              |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));


    start = sort(start);
    printf("\n\nВідсортована таблиця\n\n");
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Характеристики ПЭВМ                                                                    |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Процесор               |Частота (Mgz)    |RAM (Mb)                           |Тип      |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    display();
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Тип: C - CISC-процесор, R - RISC-процесор                                              |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
}


int main() {
    printf("%s", BLACK);
    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    printf("заповнення матриці\n\n");
    zav1();
    printf("%s", BLACK);
    printf("Сортування та введення інформації\n\n");
    zav2();

}