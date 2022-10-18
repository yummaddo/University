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

// Функция для реализации функции `strcat()` в C
char* MyRight(char* str1, int l)
{
    int num1 = 0;
    char* temp1;


    temp1 = str1;
    while (*str1 != '\0') {
        num1++;
        str1++;
    }
    char* str = (char*)malloc((num1 + l + 1) * sizeof(char));
    *(str + num1 + l) = '\0';
    int i = 0;
    for (i; i < l; i++) {
        *(str + i) = ' ';
    }

    while (*temp1 != '\0') {
        *(str + i) = *temp1;
        temp1++;
        i++;
    }
    return str;

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
        for (i = 0; i < n-10; i++)
        {
            
            int local_max = 0;
            for (int inside_i = i; inside_i < i + 10; inside_i++) {
                local_max += *(mass1 + inside_i);
            }
        
            if (local_max >= max_el) {

                max_el = local_max;
                max_index = i+1;

            }

        }

    }
    else {
        printf("\nМасив немає неперервних ділянок розмірністю 10\n");
    }

    for (int i = 0; i < n;i++) {
        if (i >= max_index-1 && i < max_index+9) {
            printf("%s%3d %s",RED,*(mass1+i),NONE);
        }
        else {
            printf("%3d ", *(mass1 + i));
        }
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
 
    }

    printf("\nНайбільша неперервна ділянка з %d індексу по %d сума якої рівна %d\n\n", max_index, max_index+9, max_el);
    printf("\nЗавдання 2, реалізація right(), для завершення сесії введіть . \n");
    printf("Введіть строку та значення відступу (name 4) \n");
    char str1[50];
    int l;
    do
    {
        printf(">> ");
        scanf("%s", &str1);
        if (strcmp(str1, ".") == 0) break;
        scanf("%d", &l);
        printf("\nРезультат роботи right(str,%d)\n%s\n",l ,MyRight(str1, l));
    } while (1);
    
    return 0;
}
