#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <malloc.h>
#include <time.h>

void one() {
	struct A {
		char pr[50];
		char in[50];
		int br;
		char sl[50];
	};
	printf("Keep track of the number of array elements \n");
	printf("\t\t>> ");
	int d;
	scanf("%d", &d);
	if (d > 0) {
		A* elemments = (A*)malloc(sizeof(A)*d);
		for (int i = 0; i < d; i++) {
			printf("Enter information Processor, Frequency (MНz), RAM (Mb), Type (c/r/i) [%d] ", i + 1);
			scanf("%s %s %d %s", &elemments[i].pr, &elemments[i].in, &elemments[i].br, &elemments[i].sl);


		}
		printf("отриманий масив\n");
		for (int i = 0; i < d; i++) {
			printf("[%d] {Processor %20s} {Frequency (MНz) %20s} {RAM (Mb) %10d} {Type (c/r/i) %8s}\n",i+1, elemments[i].pr, elemments[i].in, elemments[i].br, elemments[i].sl);
		}
	}
}

void two() {

	int one, two, tree;

	for (int i = 0; i < 1000; i++) {
		tree = i % 10;
		two = i / 10 % 10;
		one = i / 100;
		if (one == two && one % 2 ==1 && two % 2 == 1 ){
			printf("%d\n",i);	
		} else if ( two == tree & two  % 2 == 1 && tree %2 == 1) {
			printf("%d\n",i);	
		} else if ( one == tree & one  % 2 == 1 && tree %2 == 1) {
			printf("%d\n",i);	
		}	
	}
}


void tree(){
	int index[3] = {0};
	int * el;
	printf("Keep track of the number of array elements \n");
	printf("\t\t>> ");
	int d;
	scanf("%d", &d);
	printf("Start array: \n");
	if (d >= 3){
		srand(time(NULL));
		el = (int *)malloc(sizeof(int) * d);
		for (int i =0;i < d; i ++) {
			el[i] = rand() % 120 - 10;
			printf("%d\t",el[i]);
		}	
		for (int i = 0; i<d; i++ ){
			if ( el[i] >= el[index[0]] ){
				index[0] = i;
			}
		}
		for (int i = 0; i<d; i++ ){
			if ( el[i] >= el[index[1]] ){
				if (i != index[0]){
					index[1] = i;
				}
				
			}
				
		}
		for (int i = 0; i<d; i++ ){
			if ( el[i] >= el[index[2]]){
				if (i != index[0] && i != index[1]){
					index[2] = i;
				}
			}
		}
	}
	el[index[0]] = el[index[2]];
	el[index[1]] = el[index[2]];
	printf("\nEnd array: %d %d %d \n",index[0], index[1], index[2]);
	for (int i = 0; i<d; i++ ){
		printf("%d\t",el[i]);
	}
		
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("\n Number of the last 2 digits of the scorebook = 54\n\n");


	printf("\nOption 5+4 = 9 task 1\n\n");
	//one();
	printf("\nOption abs(5-4) = 1 task 2\n\n");
	//two();
	printf("\nOption 1+4 = 5 task 1\n\n");
	tree();
	
}