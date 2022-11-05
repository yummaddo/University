#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>
#include <string.h>


#define MAX 200;
#define MIN 50;

#define NONE         "\033[m"
#define RED          "\033[0;32;31m"

char* MyRight(char* str, int zip_index) {
    int num1 = 0;
    char* temp1;
    temp1 = str;
    while (*str != '\0') {
        num1++;
        str++;
    }
    str--;

    //str -= num1;
    int size = (num1 % zip_index == 0 ? num1 / zip_index : num1 / zip_index + 1) + num1 + 1;
    char* s = (char*)malloc(sizeof(char) * (size));
    *(s + size - 1) = '\0';

    int tic_index = zip_index;
    int full_slides = num1 / zip_index;
    int last_zip_index = num1 % zip_index;


    for (int i = 1; i <= size - 1; i++) {
        if (i == size - 1) {
            *(s + i - 1) = '\n';
        }
        else {
            if (i % (zip_index + 1) != 0) { 
                *(s + i - 1) = *(str-tic_index+1);
                tic_index--;
            }
            else {
                full_slides--;

                if (full_slides == 0) {
                    tic_index = last_zip_index;
                }
                else {
                    tic_index = zip_index;
                }


                str -= zip_index;
                *(s + i - 1) = '\n';

            }
        }
    }

    return s;

}




int main()
{

    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/

    srand(time(NULL));
    int* mass1, i, n, m;
    m = 0;

    int max_el = 0;
    int max_index = 0;

    int max = MAX;
    int min = MIN;

    n = min + rand() % (max - min + 1);

    printf(" Розмір масиву: %d\n\n", n);
    mass1 = (int*)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {

        *(mass1 + i) = rand() % 100;

    }


    if (n >= 10) {
        for (i = 0; i < n - 10; i++)
        {

            int local_max = 0;
            for (int inside_i = i; inside_i < i + 10; inside_i++) {
                local_max += *(mass1 + inside_i);
            }

            if (local_max >= max_el) {

                max_el = local_max;
                max_index = i + 1;

            }

        }

    }
    else {
        printf("\nМасив немає неперервних ділянок розмірністю 10\n");
    }

    for (int i = 0; i < n; i++) {
        if (i >= max_index - 1 && i < max_index + 9) {
            printf("%s%3d %s", RED, *(mass1 + i), NONE);
        }
        else {
            printf("%3d ", *(mass1 + i));
        }
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }

    }

    printf("\nНайбільша неперервна ділянка з %d індексу по %d сума якої рівна %d\n\n", max_index, max_index + 9, max_el);
    printf("\nЗавдання 2, реалізація right() \n");
    char str1[50];
    int l;
    printf("Строка\n>> ");
    gets_s(str1);
    printf("Веричина розподілу\n>> ");
    scanf("%d", &l);
    printf("\nРезультат роботи right(str,%d)\n%s\n", l, MyRight(str1, l));

    return 0;
}



