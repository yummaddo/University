#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>
#define is_ua 1

typedef struct Product {
    char name[24];
    char provider[18];
    int numbers;
    float price;
    Product* next;
} Product;

Product * start = NULL;

int end = 1;


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
    printf("{Enter the Human Resources Department value} >> ");
    scanf("%s", &temp->name);

    if (strcmp(temp->name, "exit")) {
        scanf("%s", &temp->provider);
        scanf("%d", &temp->numbers);
        scanf("%f", &temp->price);
        if (temp->numbers < 0) {
            printf("Number must be greater than zero\n");
        }
        else if (temp->price < 0) {
            printf("Price must be greater than zero\n");
        }
        else if (strlen(temp->name) < 4) {
            printf("Name must be greater than or equal to 4 characters\n");
        }
        else if (strlen(temp->provider) < 4) {
            printf("Provider must be greater than or equal to 4 characters\n");
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
        end = 0;
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
    printf("{Enter the Human Resources Department value} >> ");
    scanf("%s", &temp->name);
    if (strcmp(temp->name, "exit")) {
        scanf("%s", &temp->provider);
        scanf("%d", &temp->numbers);
        scanf("%f", &temp->price);
        if (temp->numbers < 0) {
            printf("Number must be greater than zero\n");
        }
        else if (temp->price < 0) {
            printf("Price must be greater than zero\n");
        }
        else if (strlen(temp->name) < 4) {
            printf("Name must be greater than or equal to 4 characters\n");
        }
        else if (strlen(temp->provider) < 4) {
            printf("Provider must be greater than or equal to 4 characters\n");
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
        end = 0;
    }

}

void FirstProgramSecion() {
    char name[24];
    char provider[18];
    int number;
    float price;
    printf("{To finish typing, type \"exit\" and press enter}\n");
    create();
    while (end) {
        insert_end();
    }; // name == exit 

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
    display();
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
    for (float a = -5.0f; a < 5; a += 0.5) {
        for (float b = -5.0f; b < 5; b += 0.5) {
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
            printf("  a=%+4.2f", a);
            printf("  b=%+4.2f |\n", b);

        }
    }
    printf("------------------------------------------------------------------------------------------\n");
}

int main() {
    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    FirstProgramSecion();
    SecondProgramSecion();
    system("pause");
    return 0;
}
