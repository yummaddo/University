#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h> 


void a_task(){
	float x;
	printf("Завдання A\n");
	printf("Введіть значення x \n>>: ");
	scanf("%f", &x);
	if (x > 6) {
		printf("Результат: %f", x*x - 9*x);
	}
	else if (x < 3) {
		printf("Результат: %f", sqrt(x));
	}
	else {
		printf("Результат: %f", cos(x + 2));
	}
	printf("\n");
}


void b_task() {
	float x, y, r;
	printf("Завдання B\n");
	printf("Введіть координати x y\n>>: ");
	scanf("%f %f", &x,&y);
	printf("Введіть радіус круга\n>>: ");
	scanf("%f", &r);
	if (sqrt(x * x + y * y) > r) {
		printf("Точка (%f,%f) не належить колу обмеженому кругом з центром в точці (0,0) та радіусом %f",x,y,r);
	}
	else {
		printf("Точка (%f,%f) належить колу обмеженому кругом з центром в точці (0,0) та радіусом %f", x, y, r);
	}
	printf("\n");
}


void c_task() {
	int x;
	printf("Завдання С\n");
	printf("Введіть номер зодіаку від 1 до 13 \n>>: ");
	scanf("%d", &x);
	const char* zodiac[] = { "Овен", "Телець", "Близнюки", "Рак", "Лев", "Діва", "Терези", "Скорпіон", "Змієносець", "Стрілець", "Козоріг", "Водолій", "Риби" };
	switch(x){
		case 1: printf(" %d-й номер зодіаку це %s",x,zodiac[x-1]);break;
		case 2: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 3: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 4: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 5: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 6: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 7: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 8: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 9: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 10: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 11: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 12: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		case 13: printf(" %d-й номер зодіаку це %s", x, zodiac[x-1]);break;
		default: printf(" %d-го номеру зодіаку немає",x);break;
	};
	printf("\n");
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	a_task();
	b_task();
	c_task();
	system("pause");
	return 0;
}

