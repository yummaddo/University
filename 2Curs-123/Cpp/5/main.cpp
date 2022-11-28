#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>
#include <string.h>


#define MAX 200;
#define MIN 50;



// Функция для реализации функции `strcat()` в C
char* MyStrcat(char* str1, char* str2)
{
    int num1 = 0;
    int num2 = 0;

    char* temp1;
    char* temp2;

    temp1 = str1;
    temp2 = str2;

    while (*str1 != '\0') {
        num1++;
        str1++;
    }
    while (*str2 != '\0') {
        num2++;
        str2++;
    }
    char* str = (char*)malloc((num1 + num2 + 1)*sizeof(char));
    *(str + num1 + num2) = '\0';
    int i = 0;
    while (*temp1 != '\0') {
        *(str+i) = *temp1;
        temp1++;
        i++;
    }
    while (*temp2 != '\0') {
        *(str +i ) = *temp2;
        temp2++;
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
    int max = MAX;
    int min = MIN;

    n = min + rand() % (max - min + 1);

    printf(" Розмір масиву: %d\n\n",n);
    mass1 = (int*)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        *(mass1 + i) = (rand() % 50)%2==0 ? rand() % 50: (rand() % 50*(-1));
        if (i % 12 == 11) {
            printf("%d\n", *(mass1 + i));
        }
        else {
            printf("%d\t", *(mass1 + i));
        }
    }
    for (i = 1; i < n; i++)
    {
        if (*(mass1 + i) > 0 && *(mass1 + i - 1) < 0) m++;
        if (*(mass1 + i) < 0 && *(mass1 + i - 1) > 0) m++;
    }

    printf("\nКкількість пар сусідніх елементів, що мають протилежні знаки: %d\n\n",m);
    printf("\nЗавдання 2, реалізація strcat(), для завершення сесії введіть *** \n");
    char str1[50];
    char str2[50];
    do
    {
        printf("введіть значення 1 строки:");
        gets_s(str1);
        if (strcmp(str1, "***") == 0) break;
        printf("введіть значення 2 строки:");
        gets_s(str2);
        printf("\nРезультат канкатенації = %s\n\n", MyStrcat(str1, str2));
    } while (1);

    return 0;
}