#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>

int input_int() {	
	int n;
	scanf("%d", &n);
	return n;
}

void sum(int n) {
	int x = 2, q = 3, r = 2;
	int suma = x;
	for (int i = 1; i < n; i++) {
		x = x * q;
		suma += x;
	}
	suma += n * r;
	printf("Сума = %d \n",suma);
}

float get_conformity(int a) {
	return ((float)a - 32) / 9 * 5;
}


void display_the_table(int i,int start) {
	int ent_temperature = start+i;
	printf("-----------------\n");
	printf("|C    |F        |\n");
	printf("------+----------\n");
	while (start < ent_temperature)
	{
		start++;
		printf("|%5d| %+8.4f|\n",start-1,get_conformity(start-1));
	}
	printf("-----------------\n");
}


int main()
{
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
	printf("Завдання А\nВведіть кількість елементів суму яких потрібно знайти (ціле число) \n>>: ");
	int n = input_int();
	sum(n);
	printf("Завдання Б\nВведіть кількість елементів таблиці та її початковий елемент (цілі числа)\nПочатковий(С - температура в градусах цельсія)\n>>: ");
	int start = input_int();
	printf("Кількість елементів таблиці\n>>: ");
	int namber_of_elements = input_int();
	display_the_table(namber_of_elements,start);
	system("pause");
	return 0;
}
