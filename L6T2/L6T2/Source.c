#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
//сортировка строк по убыванию значения минимального элемента методом вставок
void main() {
	int** matr, N, M;
	printf("input number of rows ");
	while (scanf_s("%d", &N) != 1 || N < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	matr = (int**)calloc(N, sizeof(int*));
	printf("input number of columns  ");
	while (scanf_s("%d", &M) != 1 || M < 1 || getchar() != '\n') {
		printf("error\n");
		rewind(stdin);
	}
	for (int i = 0; i < N; i++) {
		*(matr + i) = (int*)calloc(M, sizeof(int));
		for (int j = 0; j < M; j++) {
			printf("input %d %d element  ",i+1,j+1);
			while (scanf_s("%d", *(matr+i)+j) != 1 || getchar() != '\n') {
				printf("error\n");
				rewind(stdin);
			}
		}
	}
	show(matr, N, M);
	sort_ins(matr, N, M);
	show(matr, N, M);
}