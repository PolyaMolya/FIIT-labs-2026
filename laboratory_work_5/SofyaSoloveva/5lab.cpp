#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void random_filling(int* arr, int n) {
	for (int i = 0; i < n; i++) { arr[i] = rand() % 10000;}
}
int checksort(int* arr, int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] > arr[i + 1]) { return 0; }
	}
	return 1;
}
/// СОРТИРОВКА ВЫБОРОМ 
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void selection(int* arr, int n) {
	for (int i = 0; i < n-1; i++) {
		int minindex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minindex]) { minindex = j; }
		}
		if (minindex != i) { swap(&arr[i], &arr[minindex]); }
	}
}
/// qSORT
void qSort(int* arr, int leftind, int rightind) {
	if (leftind >= rightind) { return; }
	int pivot = arr[(leftind + rightind) / 2];
	int i = leftind, j = rightind;
	while (i <= j) {
		while (arr[i] < pivot) { i++; }
		while (arr[j] > pivot) { j--; }
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	qSort(arr, leftind, j);
	qSort(arr, i, rightind);
}
/// СОРТИРОВКА ПОДСЧЕТОМ
void counting(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) { max = arr[i]; }
	}
	int* count = (int*)malloc(sizeof(int) * (max + 1));
	if (count == NULL) {
		printf("Memory allocation error!\n");
		return;
	}
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}
	int id = 0;
	for (int i = 0; i <= max; i++) {
		while (count[i] > 0) {
			arr[id] = i;
			id++;
			count[i]--;
		}
	}
	free(count);
}

int main() {
	srand(time(NULL));
	int n;
	printf("Enter the number of array elements up to 2000.\n");
	scanf_s("%d", &n);
	while (n <= 0 || n>2000000000) { 
		printf("The number must be an integer and a natural number, and less than 2000.\n");
		scanf_s("%d", &n);
	}
	int curn = n;
	int steps = 3;
	for (int step = 0;step < steps;step++) {
		int* old = (int*)malloc(sizeof(int) * curn);
		int* arr1 = (int*)malloc(sizeof(int) * curn);
		int* arr2 = (int*)malloc(sizeof(int) * curn);
		int* arr3 = (int*)malloc(sizeof(int) * curn);
		if (old == NULL || arr1 == NULL || arr2 == NULL || arr3 == NULL ) {
			printf("Memory allocation error!\n");
			free(old);
			free(arr1);
			free(arr2);
			free(arr3);
			return 0;
		}
		random_filling(old, curn);
		for (int i = 0; i < curn; i++) {
			arr1[i] = old[i];
			arr2[i] = old[i];
			arr3[i] = old[i];
		}
		///ВРЕМЯ
		clock_t start, end;
		//выбор
		start = clock();
		selection(arr1, curn);
		end = clock();
		double time_selection = (double)(end - start) / CLOCKS_PER_SEC;
		//qsort
		start = clock();
		qSort(arr2, 0, curn - 1);
		end = clock();
		double time_qSort = (double)(end - start) / CLOCKS_PER_SEC;
		//подсчет
		start = clock();
		counting(arr3, curn);
		end = clock();
		double time_counting = (double)(end - start) / CLOCKS_PER_SEC;

		// РЕЗУЛЬТАТЫ
		//проверка сортировки

		printf("\nSize: %d\n", curn);
		printf("| %-20s | %-15s | %-10s |\n", "Sorting", "Time (sec)", "Check");
		printf("\n");

		printf("| %-20s | ", "Selection");
		if (checksort(arr1, n) == 1) { printf("%-15.6f | OK         |\n", time_selection); }
		else { printf("%-15s | ERROR       |\n", "---"); }

		printf("| %-20s | ", "QSort");
		if (checksort(arr2, n) == 1) { printf("%-15.6f | OK         |\n", time_qSort); }
		else { printf("%-15s | ERROR       |\n", "---"); }

		printf("| %-20s | ", "Counting");
		if (checksort(arr3, n) == 1) { printf("%-15.12f | OK         |\n", time_counting); }
		else { printf("%-15s | ERROR       |\n", "---"); }

		free(old);
		free(arr1);
		free(arr2);
		free(arr3);

		curn *= 5;
	}
	return 0;
}