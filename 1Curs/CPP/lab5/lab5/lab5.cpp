#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <ctime>

int main()
{
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
	srand(time(NULL));
	int integer_mass[20];
	for (int i = 0;i < 20;i++) {
		integer_mass[i] = rand();
	}
	printf("Завдання А\n");
	for (int i = 0;i < 20;i++) {
		printf("%d ", integer_mass[i]);
	}
	printf("\nЗавдання Б \n");
	int extremes[4] = { integer_mass[0],integer_mass[0],0,0 };
	for (int i = 0;i < 20;i++) {
		if (integer_mass[i] < extremes[0]) {
			extremes[0] = integer_mass[i];
			extremes[2] = i;
		}
		if (integer_mass[i] > extremes[1]) {
			extremes[1] = integer_mass[i];
			extremes[3] = i;
		}
	}
	printf("Max %d index %d \nMin %d index %d \n", extremes[1], extremes[3], extremes[0], extremes[2]);
	printf("\nЗавдання В \n");
	printf("Введіть діапазон \n");
	int diapasons[2];
	scanf("%d %d", &diapasons[0], &diapasons[1]);
	int i = 0;
	while (i<20) {
		if (integer_mass[i] > diapasons[0] and integer_mass[i] < diapasons[1]) {
			printf("%d ", integer_mass[i]);
		}
		i++;
	}
	
}
