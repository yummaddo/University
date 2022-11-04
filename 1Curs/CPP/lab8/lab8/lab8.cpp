
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>



//прізвище, номер групи, середній бал та дату
//народження
void get_numbers(float& aa, float& bb, float& cc, float& dd) {
	scanf("%f %f %f %f", &aa, &bb, &cc, &dd);
	printf(" % f % f % f % f", aa, bb, cc, dd);
}

void re_int(float& aa, float& bb, float& cc, float& dd) {
	aa = bb / dd;
	bb = -cc;
	cc = aa + bb;
	dd = (aa + bb) / cc;
	
}


int main()
{
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/


	printf("Завдання 1\n");
	float aa, bb, cc, dd;
	get_numbers(aa, bb, cc, dd);
	while (aa != 0) {
		get_numbers(aa, bb, cc, dd);
	}
	re_int(aa, bb, cc, dd);
	printf("Результат:%f %f %f %f", aa, bb, cc, dd);
	printf("\nЗавдання 2\n");
	int company, years;
	printf("Введіть кількість фірм\n");
	scanf("%d", &company);
	printf("Введіть кількість років\n");
	scanf("%d", &years);

	int** list_of_company;
	list_of_company = (int**)malloc(sizeof(int*) * company);
	for (int i = 0; i < company; i++) {
		list_of_company[i] = (int*)malloc(sizeof(int) * years);
	};


	for (int i = 0; i < company; i++)
	{
		printf("\nВведіть дані про прибутки для %d-ої компанії", i + 1);
		for (int year = 0; year < years; year++) {
			printf("\nlist[%d][%d] = ", i, year);
			scanf("%d", &list_of_company[i][year]);
		}
	}
	int index_counter = 0, sum, sum_max;
	sum = 0;
	sum_max = 0;
	for (int year = 0; year < years; year++) {
		for (int comp = 0; comp < company; comp++) {
			sum += list_of_company[comp][year];
			if (sum_max < sum) {
				sum_max = sum;
				sum = 0;
				index_counter = year;
			}
		}
	}
	printf("\nНайбільше прибутку у компаній було у %d році та становило загалом %d\n", index_counter + 1, sum_max);
}