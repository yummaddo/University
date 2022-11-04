#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <tuple>
#include <ctype.h>
#include <string.h>
using namespace std;

typedef struct Product {
    char name[24];
    char provider[20];
    float price;
    int numbers;
    Product* next;
} Product;

Product* start = NULL;
int end_typing = 1;

// функція змінює координати position
tuple <int, int> inserter(char side, int y, int x) {
    if (side == 't') {
        return tuple<int, int>{y - 1, x};
    }
    else if (side == 'l') {
        return tuple<int, int>{y, x - 1};
    }
    else if (side == 'b') {
        return tuple<int, int>{y + 1, x};
    }
    else if (side == 'r') {
        return tuple<int, int>{y, x + 1};
    }
    else {
        printf("Error");
    }
}

// функція змінює напрям заповнення матриці 
char re_side(char side) {
    char new_side;
    if (side == 't') {
        new_side = 'l';
        return new_side;
    }
    else if (side == 'r') {
        new_side = 't';
        return new_side;
    }
    else if (side == 'l') {
        new_side = 'b';
        return new_side;
    }
    else if (side == 'b') {
        new_side = 'r';
        return new_side;
    }
    else {
        return '0';
    }
}


int** memory(int rows, int cols) {
    int** tmp = new int* [rows];
    tmp[0] = new int[rows * cols];
    for (int i = 1; i < rows; ++i)
        tmp[i] = tmp[i - 1] + cols;
    return tmp;
}


void print_matrix(int** m, int size) {
    int max_number = size * size;


    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (max_number / 100 > 0) {
                printf("%4d", m[y][x]);
            }
            else if (size / 1000 > 0) {
                printf("%5d", m[y][x]);
            }
            else {
                printf("%3d", m[y][x]);
            }
        }
        printf("\n");
    }
    printf("\n");

}


void zav1() {
    int matrix[9][9];
    tuple<int, int> position = make_tuple(4, 4);
    matrix[get<0>(position)][get<1>(position)] = 1;
    int start = 1, item_start = 2;
    char side = 'l';
    while (start < 9) {
        if (start != 8) {
            for (int i = 1; i < 3; i++) {
                for (int p = 0; p < start; p++) {
                    position = inserter(side, get<0>(position), get<1>(position));
                    matrix[get<0>(position)][get<1>(position)] = item_start;
                    item_start += 1;
                }
                side = re_side(side);// змінюємо сторону
            }
        }
        else {
            for (int i = 1; i < 4; i++) {
                for (int p = 0; p < start; p++) {
                    position = inserter(side, get<0>(position), get<1>(position)); // змінюємо координати
                    matrix[get<0>(position)][get<1>(position)] = item_start;
                    item_start += 1;
                }
                side = re_side(side);// змінюємо сторону
            }
        }
        start += 1;
    }

    int it, ij;
    for (it = 0; it < 9; it++) {
        for (ij = 0; ij < 9; ij++) {
            printf("%2d ", matrix[it][ij]);
        }
        printf("\n");
    }

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
            printf("|%23s|%17s|%35d|%9.1f|\n", ptr->name, ptr->provider, ptr->numbers, ptr->price);
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
    printf("{Новий пакет} >> ");
    scanf("%s", &temp->name);

    if (strcmp(temp->name, "***")) {
        scanf("%s", &temp->provider);
        scanf("%d", &temp->numbers);
        scanf("%f", &temp->price);

        if (temp->numbers < 0) {
            printf("Кількість частин повинна бути більша за нуль\n");
            insert_end();
        }
        else if (temp->price < 0) {
            printf("Ціна повинна бути більша за нуль\n");
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
    printf("Офісні пакети \n");
    printf("{Назва:string,   Виробник:string,   Ціна за штуку:float,   Кількість:integer} \n");
    printf("{Новий пакет} >> ");
    scanf("%s", &temp->name);
    if (strcmp(temp->name, "exit")) {
        scanf("%s", &temp->provider);
        scanf("%d", &temp->numbers);
        scanf("%f", &temp->price);
        if (temp->numbers < 0) {
            printf("Кількість частин повинна бути більша за нуль\n");
            create();
        }
        else if (temp->price < 0) {
            printf("Ціна повинна бути більша за нуль\n");
            create();
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
            //printf("a(%c = %d)     b(%c = %d)\n ",a,a-'0',b,b-'0');
            if (a - '0' < b - '0') {
                return 1;
            }
            else if (a-'0' > b-'0') {
                return 0;
            }
            else {
                return -1;
            }

        }
        else if (a - '0' > 0 && b - '0' < 0) {

            return 1;
        }else if (b - '0' > 0 && a - '0' < 0) {

            return 0;
        } else
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
    int code1,code2;

    for (int i = 0; n1_cpy[i] != '\0' || n2_cpy[i] !='\0'; i++ ) {
        if (is_char_avarage(n1_cpy[i],n2_cpy[i]) == 1) { // a > b  ::>> n1 < n2
            return true;
        }
        else if(is_char_avarage(n1_cpy[i], n2_cpy[i]) == 0) { // a < b  ::>> n2 < n2
            return false;
        }
        else { // a == b
            if (n1_cpy[i+1] == '\0' && n2_cpy[i + 1] != '\0') { // n2 > n1
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
    char name[24];
    char provider[18];
    int number;
    float price;


    printf("{Щоб завершити введення, введіть \"***\" і натисніть enter}\n");
    create();
    while (end_typing) {
        insert_end();
    }; // name == exit 
    printf("\nНЕ сортований список\n");

    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Human Resources Department                                                             |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Найменування           |Виробник         |Кількість сост.частин              |Ціна ($) |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    display();
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Примітки: безкоштовно одержати продукт StarOffice через Internet                       |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));


    start = sort(start);
    printf("\nВідсортований список\n");

    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Human Resources Department                                                             |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Найменування           |Виробник         |Кількість сост.частин              |Ціна ($) |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    display();
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Примітки: безкоштовно одержати продукт StarOffice через Internet                       |\n"));
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
}


int main() {

    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    printf("{Блок заповнення матриці}\n\n");
    zav1();
    printf("{Блок сортування введеної інформації}\n\n");
    zav2();
}