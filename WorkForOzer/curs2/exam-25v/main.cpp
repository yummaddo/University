#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>
#include <time.h>

int main(){
	printf("EXAM var 25\nRundom array>>( random size: [10:20] )\n");
	srand(time(NULL));
	int d = rand() % 20 + 10;
	int* A = (int*)malloc(sizeof(int)*d); 
	for (int i = 0; i < d; i++){
		A[i] = rand() % 100 - 50;
		printf("%d\t",A[i]);
	}
	printf("\n Inpute the string: ");
	char str[200];
	gets(str);
	int res = 0;
	for (int i = 0; i < strlen(str)-1; i ++){
		if (str[i] == str[i+1]){
			res++;
		}
	}
	printf("\n The number of pairs of elements that are identical in value = %d", res);
}