#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>

float diag(int a,int b) {
	return sqrt(a * a + b * b);
}

int comparison(float d1, float d2, float d3) {
	if (d1 > d2 && d1 > d3) {
		return 1;
	}
	else if (d2 > d1 && d2 > d3) {
		return 2;
	}
	else if (d3 > d1 && d3 > d2) {
		return 3;
	}
	else {
		return 1;
	}
}


int rec(int num, int sum) {
	if (num > 9) {
		sum = sum += num % 10;
		num = num / 10;
		rec(num, sum);
	}
	else {
		return sum + num;
	}

}


int rec3(float e,float number,float n) {
	n += 1;

	float next = number * (1 - (1 / (n+1)));
	float b = 1 - (1 / (n + 1));
	float res = next - number;
	//printf("%f %f ,",next,number);
	if (res < 0) {
		res = -res;
	}
	if (res < e) {
		return n;
	}
	else {
		rec3(e,next,n);
	}

}

float rec_element(float start, float n) {
	for (int i = 1; (int)n >= i; i++) {
		start *= 1 - (1 / ((float)i + 1));
		//printf("%f",start);
	}
	return start;
}


int main() {
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/
	int a1, b1, a2, b2, a3, b3;
	printf("ВВедіть трикутники 1(a,b) 2(a, b) 3(a, b) \n");
	scanf("%d %d %d %d %d %d", &a1, &b1, &a2, &b2, &a3, &b3);
	printf("Найбільша діагональ в трикутника номер %d \n", comparison(diag(a1, b1), diag(a2, b2), diag(a3, b3)));
	printf("\nРекурсія 1: \n");
	int number;
	int sum = 0;
	printf("Введите число N\n");
	scanf("%d", &number);
	int n = rec(number,sum);
	printf("Сума цифр= %d",n);
	printf("\n\nРекурсія 3: \n");
	printf("Введите число E\n");
	float e;
	scanf("%f", &e);

	float start = 1 - (1 / 2);
	float n1 = 1;
	float res = rec3(e,start,n1);
	printf("N = %d, An = %f ", (int)res, rec_element(1, (float)res));
}
