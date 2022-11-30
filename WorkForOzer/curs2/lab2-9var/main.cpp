#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>


typedef struct element {
    char name[14];
    char specific[14];
    float price_of_one;
    int numbers;
    element* next;
} element;

element * start = NULL;
int End_of_program = 1;


void display()
{
    element* ptr;
    if (start == NULL)
    {
        return;
    }
    else
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("|%14s|%14s|%+26f|%26.1d|\n", ptr->name, ptr->specific, ptr->price_of_one, ptr->numbers);
            ptr = ptr->next;
        }
    }
}




void insert_end()
{
    element* temp, * ptr;
    temp = (element*)malloc(sizeof(element));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        return;
    }
    printf(" >> ");
    scanf("%s", &temp->name);

    if (strcmp(temp->name, ".")) {
        scanf("%s", &temp->specific);
        scanf("%f", &temp->price_of_one);
        scanf("%d", &temp->numbers);

        if (temp->numbers < 0 || temp->price_of_one < 0) {
            printf("Not valid values \n");
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
        End_of_program = 0;
    }
}


void create()
{
    element* temp, * ptr;
    temp = (element*)malloc(sizeof(element));
    if (temp == NULL)
    {
        printf("Out of Memory Space\n");
        exit(0);
    }
    printf(" >> ");
    scanf("%s", &temp->name);
    if (strcmp(temp->name, ".")) {
        scanf("%s", &temp->specific);
        scanf("%f", &temp->price_of_one);
        scanf("%d", &temp->numbers);

        if (temp->numbers < 0 || temp->price_of_one < 0) {
            printf("Not valid values \n");
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
        End_of_program = 0;
    }

}


int main() {
    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    printf("Entering Prise list : name (max 14 liters: string) type of product (max 14 liters: string) \n");
    printf("Price for 1 pc. ( number: float ) Minimum quantity per batch (number: integer)\n");
    printf("To finish typing type \".\"\n");

    create();
    while (End_of_program == 1) {
        insert_end();
    };

    printf(_strdup("-------------------------------------------------------------------------------------\n"));
    printf(_strdup("|Price list                                                                         |\n"));

    printf(_strdup("-------------------------------------------------------------------------------------\n"));

    printf(_strdup("|Name          |Product type  |Price for 1 pc. (UAH)     |Minimum quantity per batch|\n"));

    printf(_strdup("-------------------------------------------------------------------------------------\n"));
    display();
    printf(_strdup("-------------------------------------------------------------------------------------\n"));

    printf(_strdup("|Note: TO - stationery, PRO - office equipment                                      |\n"));
    
    printf(_strdup("-------------------------------------------------------------------------------------\n"));

    float x, y;
    float t1, t2;
    printf("Types a x,y parameters >> ");

    scanf("%f %f", &x, &y);
    printf("-------------------------------------------------------------\n");
    // ми перебираємо параметри a та b
    for (float a = -1.5; a < 1.5; a += 0.25){
        for (float b = -1.5; b < 1.5; b += 0.25){
            float t1,t2;
            if (b != 0 && x!= 0 && y!=0){
                if (y/x > 0){
                    t1 = (float)(1/b/b*(log(y/x)+a*x/y));
                    printf("|%+18.4f",t1);
                }else {
                    printf("|not valid values  ");

                }
            } else {
                printf("|not valid values  ");
            }
            
            if (a!=0 && sin(a*x/2) > 0 && cos(a*x/2) != 0 ){
                t2 = (float)(-x/a*tan(a*x/2) + 2/a/a*log(sin(a*x/2)));
                printf("|%+18.4f",t2);

            } else {
                printf("|not valid values  ");
            }
            printf("| a = %+4.2f  b = %+4.2f|\n",a,b );
        }
    }

    printf("-------------------------------------------------------------\n");// len = 79 


    system("pause");
    return 0;
}
