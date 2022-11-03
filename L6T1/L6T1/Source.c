#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"
//сортировка чётных положительных методом Шелла
void main() {
	srand(time(NULL));
	int* arr, n,start,end;
	printf("input size of array  ");
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		/*printf("input %d element  ",i+1);
		while (scanf_s("%d", arr+i) != 1 || getchar() != '\n') {
			printf("error\n");
			rewind(stdin);
		}*/
		*(arr + i) = rand();
	}
	//show(arr, n);
	start = clock();
	//printf("%d\n", start);
	sort_b(arr,n);
	//sort_b(arr, n);
	end = clock();
	//printf("%d\n", end);
	//show(arr, n);
	printf("time of sort:%d\n", end - start);
}