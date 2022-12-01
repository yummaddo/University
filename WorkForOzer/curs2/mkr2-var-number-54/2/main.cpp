#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>
#include <time.h>
int main(){
	int index = 0;
	int * el;
	printf("Keep track of the number of array elements \n");
	printf("\t\t>> ");
	int d;
	scanf("%d", &d);
	printf("Start array: \n");
	if (d >= 0){
		srand(time(NULL));
		el = (int *)malloc(sizeof(int) * d);
		for (int i =0;i < d; i ++) {
			el[i] = rand() % 200 - 100;
			printf("%+4d\t",el[i]);
			if (el[index] < 0 && index+1 < d) {
				index++;
			}
		}
		for (int i =0;i < d; i ++) {
			if ( el[index] >= el[i] && el[i] > 0 ){
				index = i;
			}
		}
		for (int i =0;i < d; i ++) {
			if ( el[i] < 0 ){
				el[i] = el[index];
			}
		}
		printf("\nEnd erray\n");
		for (int i =0;i < d; i ++) {
			printf("%+4d\t",el[i]);
		}
	}
}