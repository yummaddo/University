#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	SetConsoleCP(1251); /* налаштувння таблиці кодування вводу*/
	SetConsoleOutputCP(1251); /* налаштувння таблиці кодування виводу*/


	printf("Завдання 1\n");
	char d[225] ="";
	printf("Введите строку:");
	fgets(d,225,stdin);
	int len = strlen(d)-1;
	char new_str[225];
	strcpy(new_str, d);
	for (int index = 0; index < len; index++) {

		if (index < len / 2) {
			new_str[index] = d[index + len / 2 + 1];
		}
		else if (index == len / 2) {
			new_str[index] = d[len / 2];
		}
		else {
			new_str[index] = d[index - len / 2 - 1];
		}
	}
	printf("Результат:%s", new_str);
	printf("\nЗавдання 2\n");
	char rs[225] = "";
	fgets(rs, 225, stdin);
	bool flag = 0;
	int word = 1;
	char probel = ' ';

	printf("Вивід 3 слів\n\n");
	for (int i = 0; i < strlen(rs) - 1; i++) {
		if (word <= 3) {
			if (rs[i] != probel) {
				if (word % 2 != 0) {
					printf("%c", rs[i]);
				}
				else {
					printf("%c\n", rs[i]);
				}
			}
			else {
				word++;
				if (word % 2 == 0) {
					printf("\n");
				}
				continue;
			}
		}
		else {
			break;
		}
	}


}