void show(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d ", *(arr + i));
	}
	printf("\n");
}
void swap(int* a, int* b) {
	(*a) += (*b);
	(*b) = (*a) - (*b);
	(*a) = (*a) - (*b);
}
int next_even(int* arr, int n, int step) {
	for (int i = 0; i < n; i++) {
		if (*(arr + i) % 2 == 0 && *(arr + i) > 0) {
			if (step == 0)
				return i;
			else
				step--;
		}
	}
}
void sort_sh(int* arr, int n) {
	int even = 0,step;
	for (int i = 0; i < n; i++)
		if (*(arr + i) % 2 == 0 && *(arr + i) > 0)
			even++;
	if (even < 2)
		return;
	step = even-even / 2;
	for (; step > 0; step=step-step/2) {
		for (int i = step; i < even; i++) {
			for (int k = i; k>=step&&*(arr+next_even(arr,n,k-step))>*(arr+next_even(arr,n,i));k-=step) {
					swap(arr + next_even(arr, n,k), arr + next_even(arr, n, k-step));
					//show(arr, n);
			}
		}
		if (step == 1)
			step =0;
	}
}
void sort_b(int* arr, int n) {
	int even = 0;
	for (int i = 0; i < n; i++)
		if (*(arr + i) % 2 == 0 && *(arr + i) > 0)
			even++;
	if (even < 2)
		return;
	for (int i = 0; i < even; i++) {
		for (int j = 0; j < even - 1; j++) {
			if(*(arr + next_even(arr, n, j+1)) > *(arr + next_even(arr, n, j)))
				swap(arr + next_even(arr, n, j+1), arr + next_even(arr, n, j));
		}
	}
}