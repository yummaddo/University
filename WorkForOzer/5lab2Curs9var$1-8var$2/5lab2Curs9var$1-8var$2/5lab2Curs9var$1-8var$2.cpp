#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <cstring>
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
    int widht;

    //str -= num1;
    HANDLE hWndConsole;
    if (hWndConsole = GetStdHandle(-12))
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            printf("Widht: %d\n", widht);
        }
        else
            printf("Error: %d\n", GetLastError());
    }
    else
        printf("Error: %d\n", GetLastError());


    int size = (num1 % zip_index == 0 ? num1 / zip_index : num1 / zip_index + 1) + num1 + 1;
    char* s = (char*)malloc(sizeof(char) * (size));
    *(s + size - 1) = '\0';

    char* res = (char*)malloc(sizeof(char) * (widht + 1));
    for (int i = 0; i < widht-zip_index; i++) {
        *(res + i) = ' ';

    }
    *(res + widht) = '\0';

    
    int n_index = num1 / zip_index;
    char *dump = (char*)malloc(sizeof(char)* (zip_index+2) );
    char res1[1000] = "\0";

    int position = 0;
    for (int i = 1; i <= size - 1; i++) {
        if (i == size - 1) {
            *(s + i- 1) = '\n';
            strcat(res1, res);

        }
        else {
            if (i % (zip_index + 1) != 0) {
                if (n_index == 0) {
                
                    *(res + widht + position - zip_index + (num1-(num1/zip_index)*zip_index) ) = *(str);

                }
                else {
                    *(res + widht + position - zip_index) = *(str);
                }
                *(s + i- 1) = *(str);
                position++;
                str--;
            }
            else {
                n_index--;

                position = 0;
                strcat(res1, res);
                for (int itr = 0; itr < zip_index; itr++) {
                    *(res + widht - 1 - itr) = ' ';
                }
                *(s + i- 1) = '\n';
            }
        }
    }


    return res1;

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
    printf("\nЗавдання 2, реалізація right(), для завершення сесії введіть . \n");
    char str1[50];
    int l;

    printf("Строка\n>> ");
    gets_s(str1);
    printf("Веричина розподілу\n>> ");
    scanf("%d", &l);
    printf("\nРезультат роботи right(str,%d)\n%s\n", l, MyRight(str1, l));

    return 0;
}



