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
    printf("{value : name, provider number price} \n");
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
    printf("{value : name, provider number price} \n");\
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



void ThidProgramSecion(){
    printf(_strdup("-----------------------------------------------------------------------\n"));
    printf(_strdup("|Number | Type          |Expression                                   |\n"));
    printf(_strdup("-----------------------------------------------------------------------\n"));
    printf(_strdup("| 1     | Logarithm     |t=1/(b^3)*(ln(y/x – a^2*x^2/(2*y^2)))        |\n"));
    printf(_strdup("| 2     | Radical       |t=1/(b^0,5)*(y^0,5/x – a^0,5*x^2/(2*y^0,5))) |\n"));
    printf(_strdup("| 3     | Trigonometry  |t=cos(bx+0,5)*sin(y/x – a^0,5*x^2)           |\n"));
    printf(_strdup("-----------------------------------------------------------------------\n"));
    printf("{Enter the number or type of expression} >> ");
    char ex[30];
    scanf("%s",&ex);
    float x, y, t;
    printf("Input x,y parameters : ");

    scanf("%f %f", &x, &y);

    if ( !strcmp(ex,_strdup("1"))  || !strcmp(ex,_strdup("Logarithm"))  ){
        printf("Logarithm\n");
        printf("--------------------------------------------------------\n");

        for (float a = -5.0f; a < 5; a += 0.5) {
            for (float b = -5.0f; b < 5; b += 0.5) { 
                if (b*b*b != 0 && x != 0 && 2*y*y != 0 && y/x-a*a*x*x/(2*y*y) > 0 ){
                    t = 1/(b*b*b)*(log(y/x - a*a*x*x/(2*y*x)));
                    printf("|%+34.8f|", t);
                } else {
                    printf(_strdup("|                  invalid values t|"));
                }
                printf("  a=%+4.2f", a);
                printf("  b=%+4.2f |\n", b);

            }
        }

    } else if ( !strcmp(ex,_strdup("2")) || !strcmp(ex,_strdup("Radical")) ){
        printf("Radical\n");
        printf("--------------------------------------------------------\n");

        for (float a = -5.0f; a < 5; a += 0.5) {
            for (float b = -5.0f; b < 5; b += 0.5) { 
                if ( b > 0 && y > 0 && x != 0 && a >= 0){
                    t = 1/(sqrt(b))*(sqrt(y)/x - sqrt(a)*x*x/(2*sqrt(y)));
                    
                    printf("|%+34.8f|", t);
                } else {
                    printf(_strdup("|                  invalid values t|")); 
                }
                printf("  a=%+4.2f", a);
                printf("  b=%+4.2f |\n", b);
            }
        }
    } else if ( !strcmp(ex,_strdup("3")) || !strcmp(ex,_strdup("Trigonometry")) ){
        printf("Trigonometry\n");
        printf("--------------------------------------------------------\n");

        for (float a = -5.0f; a < 5; a += 0.5) {
            for (float b = -5.0f; b < 5; b += 0.5) { 
                if ( x!=0 && a >= 0){
                    if (y/x != sqrt(a)*x*x) {
                        t = cos(b*x+0.5)*sin(y/x - sqrt(a)*x*x);
                        printf("|%+34.8f|", t);
                        printf(_strdup("|                  invalid values t|")); 
                    }
                } else {
                    printf(_strdup("|                  invalid values t|"));
                }
                printf("  a=%+4.2f", a);
                printf("  b=%+4.2f |\n", b);
            }
        }
    } else {
        printf("No type or number \n");
    }
    printf("--------------------------------------------------------\n");

}

void FourthProgramSecion(){
    system("g++ -c compiller.cpp -static-libstdc++ -o compiller.o" );
    system("g++ compiller.o -static-libstdc++ -o compiller" );
    system( "compiller" );
}


int main() {
    SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
    SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
    FirstProgramSecion();
    SecondProgramSecion();
    ThidProgramSecion();
    FourthProgramSecion();
    return 0;
}
