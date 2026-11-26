#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void randmass(unsigned int* arr, int n) {
	for (int i = 0;i < n;i++) {
		arr[i] = 1 + rand() % (1000);
	}
}
void printmass(unsigned int* arr, int n) {
	for (int i = 0;i < n; i++) {
		printf("%u ", arr[i]);
	}
	printf("\n");
}
void swap(unsigned int& a, unsigned int& b) {
	unsigned int tmp = a;
	a = b;
	b = tmp;
}
unsigned int get_max(unsigned int* arr, unsigned int n) {
	unsigned int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
void insertionSort(unsigned int* arr, int n) { // 1
	for (int i = 0; i < n;i++) {
		int k = i;
		for (int j = i - 1;j >= 0; j--) {
			if (arr[k] < arr[j]) {
				swap(arr[k], arr[j]);
				k--;
			}
			else break;
		}
	}
}
void merge(unsigned int* a, unsigned int* b, int n, int m, unsigned int* c) { // 2 
	int j = 0, k = 0;
	for (int i = 0;i < n + m;i++) {
		if (j == n) {
			c[i] = b[k++];
		}
		else {
			if (k == m) {
				c[i] = a[j++];
			}
			else {
				if (a[j] < b[k]) {
					c[i] = a[j++];
				}
				else c[i] = b[k++];
			}
		}
	}
}
void mergeSort(unsigned int* a, int n, unsigned int* b) { // 2
	if (n <= 1) {
		return;
	}
	mergeSort(&a[0], n / 2, &b[0]);
	mergeSort(&a[n / 2], n - n / 2, &b[n / 2]);
	merge(&a[0], &a[n / 2], n / 2, n - n / 2, &b[0]);
	for (int i = 0; i < n;i++) {
		a[i] = b[i];
	}
}
void bubbleSort(unsigned int* arr, int n) { // 3
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void countingSort(unsigned int* arr, int n, unsigned int div) { // 4
	unsigned int count[10] = { 0 };
	unsigned int* output = (unsigned int*)malloc(n * sizeof(unsigned int));
	for (int i = 0; i < n; i++) {
		unsigned int digit = (arr[i] / div) % 10;
		count[digit]++;
	}
	for (int i = 1;i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1;i >= 0;i--) {
		unsigned int digit = (arr[i] / div) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}
	for (int i = 0;i < n;i++) {
		arr[i] = output[i];
	}
	free(output);
}
void radixSort(unsigned int* arr, int n) { // 4
	unsigned int max = get_max(arr, n);
	for (unsigned int div = 1; max / div > 0;div *= 10) {
		countingSort(arr, n, div);
	}
}
void vivod(unsigned int* arr, int n, int pick) {
	int pick2;
	int pick3 = 1;
	double predTime = 0;
	if (pick >= 1 && pick <= 4) {
		printf("Выбрана сортировка %d. Хотите увидеть изначальный и отсортированный массивы? (0 - нет, 1 - да) ", pick);
		scanf_s("%d", &pick2);
		if (pick2 != 0 && pick2 != 1) {
			printf("Введено неправильное число\n");
			free(arr);
			return;
		}
		while (1) {
			clock_t start = 0, end = 0;
			unsigned int* arr2 = (unsigned int*)malloc(n * sizeof(unsigned int));
			for (int i = 0;i < n;i++) {
				arr2[i] = arr[i];
			}
			start = clock();
			bubbleSort(arr2, n);
			end = clock();
			double bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;
			free(arr2);
			if (pick2 == 1) {
				printmass(arr, n);
			}
			switch (pick) {
			case 1: {
				start = clock();
				insertionSort(arr, n);
				end = clock();
				break;
			}
			case 2: {
				unsigned int* b = (unsigned int*)malloc(n * sizeof(unsigned int));
				start = clock();
				mergeSort(arr, n, b);
				end = clock();
				free(b);
				break;
			}
			case 3: {
				start = clock();
				bubbleSort(arr, n);
				end = clock();
				break;
			}
			case 4: {
				start = clock();
				radixSort(arr, n);
				end = clock();
				break;
			}
			}
			if (pick2 == 1) {
				printmass(arr, n);
			}
			double resTime = (double)(end - start) / CLOCKS_PER_SEC;
			printf("\nКоличество элементов массива: %d | Время сортировки %d: %lf | Время сортировки пузырьком: %lf\n\n", n, pick, resTime, bubbleTime);
			printf("На сколько умножить количество элементов (0 - выход в меню)? ");
			scanf_s("%d", &pick3);
			if (pick3 <= 0) {
				printf("\n");
				return;
			}
			n = n * pick3;
			free(arr);
			arr = (unsigned int*)malloc(n * sizeof(unsigned int));
			randmass(arr, n);
		}

	}
	else printf("Введен неправильный номер типа сортировки");
	free(arr);
}
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(NULL));
	int n;
	int pick;
	while (1) {
		printf("================МЕНЮ================\n");
		printf("Введите количество элементов массива (для выхода введите '0'): ");
		scanf_s("%d", &n);
		if (n == 0) {
			return 0;
		}
		if (n < 1) {
			printf("Введено неверное количество элементов массива");
			return 0;
		}
		unsigned int* arr = (unsigned int*)malloc(n * sizeof(unsigned int));
		randmass(arr, n);
		printf("Сортировки на выбор:\n1.Сортировка вставками - InsertionSort\n2.Сортировка слиянием - MergeSort\n3.Сортировка пузырьком - BubbleSort\n4.Поразрядная сортировка - RadixSort\n");
		printf("Выберите тип сортировки: ");
		scanf_s("%d", &pick);
		vivod(arr, n, pick);
	}
	return 0;
}