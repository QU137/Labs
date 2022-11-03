void show(int** matr, int N,int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%3d ", *(*(matr + i)+j));
		}
		printf("\n");
	}
	printf("\n");
}
void swap(int** a, int** b) {
	int* temp = (*b);
	(*b) = (*a);
	(*a) = temp;
}
int minim(int* row, int M) {
	int mn = *row;
	for (int i = 1; i < M; i++)
		if (*(row + i) < mn)
			mn = *(row + i);
	return mn;
}
void sort_ins(int** matr, int N, int M) {
	for (int i = 0; i < N - 1; i++)
		for (int j = i; j >= 0; j--) {
			if (minim(*(matr + j), M) < minim(*(matr + j + 1), M)) {
				swap(matr + j, matr + j + 1);
			}
			else
				break;
		}
}