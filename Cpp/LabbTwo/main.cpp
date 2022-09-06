#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>



struct Product {
    char* name;
    char* provider;
    int numbers;
    float price;
};

#define is_ua 1


void FirstProgramSecion() {

    struct Product data[3] = {
        {_strdup("Office"), _strdup("Microsoft"), 4,870 },
        {_strdup("SmartSute"), _strdup("Lotus"), 5,1020 },
        {_strdup("StarOffice"), _strdup("Sun"), 4,9 }
    };
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    #if is_ua == 1
        printf(_strdup("|Human Resources Department                                                             |\n"));
    #else
        printf(_strdup("|Відділ кадрів                                                                          |\n"));
    #endif

    printf(_strdup("-----------------------------------------------------------------------------------------\n"));

    #if is_ua == 1
        printf(_strdup("|Name                   | Manufacturer    |Number of components               |Price ($)|\n"));
    #else
        printf(_strdup("|Найменування           |Виробник         |Кількість сост.частин              |Ціна ($) |\n"));
    #endif

    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
    for (int i = 0; i < 3; i++)
        printf("|%23s|%17s|%35d|%9.1f|\n", data[i].name, data[i].provider, data[i].numbers, data[i].price);
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));

    #if is_ua == 1
        printf(_strdup("|Notes: Get a free StarOffice product over the Internet                                 |\n"));
    #else
        printf(_strdup("|Примітки: безкоштовно одержати продукт StarOffice через Internet                       |\n"));
    #endif
    printf(_strdup("-----------------------------------------------------------------------------------------\n"));
}


void SecondProgramSecion() {
    float x, y;
    float t1, t2;
    printf("Input x,y parameters : ");

    scanf("%f %f", &x, &y);
    printf("------------------------------------------------------------------------------------------\n");
    for (float a = -5.0f; a < 5; a += 0.25) {
        for (float b = -5.0f; b < 5; b += 0.25) {
            if (b != a && b != -x && b != x && ((a + x) / (b + x)) > 0) {
                t1 = (float)(b / ((a - b) * (b + x)) - a / (a - b) * (a - b) * log((a + x) / (b + x)));
                printf("|%+34.10f|", t1);
            }
            else {
                printf(_strdup("|                 invalid values t1|"));
            }

            if (a != 0 && tan(a * x / 2) > 0 && sin(a * x) != 0) {
                t2 = (float)(1 / a * (log(tan(a * x / 2)) - 1 / sin(a * x)));
                printf("%+34.10f|", t2);
            }
            else {
                printf(_strdup("                 invalid values t2|"));
            }
            printf("  a=%+4.2f",a);
            printf("  b=%+4.2f |\n",b);

        }
    }
    printf("------------------------------------------------------------------------------------------\n");


}


void ThirdProgramSecion() {

}



int main() {
    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    FirstProgramSecion();
    SecondProgramSecion();
    system("pause");
    return 0;
}
