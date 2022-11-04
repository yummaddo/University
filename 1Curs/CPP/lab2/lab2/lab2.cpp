#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>


int main()
{
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
	float x, y, price, price2, price3;
	char *named[18], *manufacturer[14], named2[18], * manufacturer2[14], named3[18], * manufacturer3[14];
	int number_of_parts, number_of_parts3, number_of_parts2;
	printf("1) Визначення значення функції\n");
	printf("Введіть значення х\n>>: ");
	scanf("%f", &x);
	y = 13.45 * exp(x) + cos(fabs(x)) * sin(pow(x, 2) - 2.25) + pow(x, 5);
	printf("Значення функції у(%.2f) = %.2f\n", x, y);

	printf("\n2) Таблиця \n");
	printf("Введіть дані про найменування виробника, кількість частин та ціну:  \n");
	printf("1\n");
	printf("Найменування\n>>: ");
	scanf("%s", &named);
	printf("Виробник\n>>: ");
	scanf("%s", &manufacturer);
	printf("Кількість частин\n>>: ");
	scanf("%d", &number_of_parts);
	printf("Ціна ($)\n>>: ");
	scanf("%f", &price);

	printf("2\n");
	printf("Найменування\n>>: ");
	scanf("%s", &named2);
	printf("Виробник\n>>: ");
	scanf("%s", &manufacturer2);
	printf("Кількість частин\n>>: ");
	scanf("%d", &number_of_parts2);
	printf("Ціна ($)\n>>: ");
	scanf("%f", &price2);
	printf("3\n");
	printf("Найменування\n>>: ");
	scanf("%s", &named3);
	printf("Виробник\n>>: ");
	scanf("%s", &manufacturer3);
	printf("Кількість частин\n>>: ");
	scanf("%d", &number_of_parts3);
	printf("Ціна ($)\n>>: ");
	scanf("%f", &price3);

	printf("--------------------------------------------------------------------------\n");
	printf("|              Офісне програмне забезпечення підрозділу                  |\n");
	printf("|---------------------+--------------+--------------------+--------------|\n");
	printf("|   Найменування      |   Виробник   |  Кількість частин  |   Ціна ($)   |\n");
	printf("|---------------------+-----------------------------------+--------------|\n");
	printf("|%21s|%14s|%20d|%13.4f |\n", named, manufacturer, number_of_parts, price);
	printf("|%21s|%14s|%20d|%13.4f |\n", named2, manufacturer2, number_of_parts2, price2);
	printf("|%21s|%14s|%20d|%13.4f |\n", named3, manufacturer3, number_of_parts3, price3);
	printf("|------------------------------------------------------------------------|\n");
	printf("|                                                    Разом: %12.4f |\n", price * number_of_parts + price2 * number_of_parts2 + price3 * number_of_parts3);
	printf("--------------------------------------------------------------------------\n");
	system("pause");
	return 0;
}
