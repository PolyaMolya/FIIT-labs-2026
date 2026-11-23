#include "stdio.h"
#include "stdlib.h"
#include "time.h"


void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


void bubble_sort(int *arr, int n) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag++;
			}
		if (flag == 0)
			break;
	}
}


void qSort(int *arr, int left, int right) {
	if (left > right)
		return;
	int pivot = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	qSort(arr, left, j);
	qSort(arr, i, right);
}


int get_max(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}


void sort_by_div_for_radix(int* arr, int n, int div) {
	int count[10] = { 0 };
	int* output = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		int digit = (arr[i] / div) % 10;
		count[digit]++;
	}
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int digit = (arr[i] / div) % 10;
		output[--count[digit]] = arr[i];
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

void radix_sort(int *arr, int n) {
	int max = get_max(arr, n);
	for (int div = 1; max / div > 0; div *= 10)
		sort_by_div_for_radix(arr, n, div);
}


int main() {
	int n = 0, input = 0, continue_cycle = 0, flag = 0, n_for_cycle;
	char c;
	do {
		flag = 0;
		printf("Enter n: ");
		scanf_s("%i", &n);
		while ((c = getchar()) != '\n');
		if (n < 1) {
			printf("\nn must be natural\n");
			flag++;
		}
	} while (flag);
	printf("\n");
	do {
		continue_cycle = 0;
		do {
			flag = 0;
			printf("\nChoose sort:\n1)Bubble\n2)qSort\n3)Radix\n");
			scanf_s("%i", &input);
			printf("\n");
			while ((c = getchar()) != '\n');
			if (input > 3 || input < 1) {
				flag++;
				printf("Number must be in range 1-3\n");
			}
		} while (flag);
		switch (input) {
			case(1):
				printf("#elem Time\n");
				n_for_cycle = n;
				for (int i = 0; i < 5; i++) {
					int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
					for (int j = 0; j < n_for_cycle; j++)
						arr[j] = rand() % 1000;
					clock_t start = clock();
					bubble_sort(arr, n_for_cycle);
					clock_t end = clock();
					printf("%i)%i %lf\n", i + 1, n_for_cycle, (double)(end - start)/CLOCKS_PER_SEC);
					n_for_cycle *= 5;
					free(arr);
				}
				break;
			case(2):
				printf("#elem Time\n");
				n_for_cycle = n;
				for (int i = 0; i < 5; i++) {
					int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
					for (int j = 0; j < n_for_cycle; j++)
						arr[j] = rand() % 1000;
					clock_t start = clock();
					qSort(arr, 0, n_for_cycle - 1);
					clock_t end = clock();
					printf("%i)%i %lf\n", i + 1, n_for_cycle, (double)(end - start) / CLOCKS_PER_SEC);
					n_for_cycle *= 5;
					free(arr);
				}
				break;
			case(3):
				printf("#elem Time\n");
				n_for_cycle = n;
				for (int i = 0; i < 5; i++) {
					int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
					for (int j = 0; j < n_for_cycle; j++)
						arr[j] = rand() % 1000;
					clock_t start = clock();
					radix_sort(arr, n_for_cycle);
					clock_t end = clock();
					printf("%i)%i %lf\n", i + 1, n_for_cycle, (double)(end - start) / CLOCKS_PER_SEC);
					n_for_cycle *= 5;
					free(arr);
				}
				break;
		}
		do {
			flag = 0;
			printf("\nContinue? (0|1)\n");
			scanf_s("%i", &continue_cycle);
			printf("\n");
			while ((c = getchar()) != '\n');
			if (!(continue_cycle == 1 || continue_cycle == 0))
				flag++;
		} while (flag);
	} while (continue_cycle);
}