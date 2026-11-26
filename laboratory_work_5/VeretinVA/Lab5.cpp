#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int N) {
	int temp;
	for (int i = 0; i < N; i++) {
		int minId = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] < arr[minId]) {
				minId = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minId];
		arr[minId] = temp;
	}
}

void merge(int a[], int b[], int c[], int n, int m) {
	int j = 0, k = 0;
	for (int i = 0; i < n + m; i++) {
		if (j == n) {
			c[i] = b[k++];
		}
		else if (k == m) {
			c[i] = a[j++];
		}
		else if (a[j] < b[k]) {
			c[i] = a[j++];
		}
		else {
			c[i] = b[k++];
		}
	}
}
void mergeSort(int a[], int temp[], int n) {
	if (n <= 1) {
		return;
	}
	int mid = n / 2;
	int right_n = n - mid;
	mergeSort(a, temp, mid);
	mergeSort(a + mid, temp + mid, right_n);
	merge(a, a + mid, temp, mid, right_n);
	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}
}

void countingSort(int a[], int n) {
	if (n <= 1) {
		return;
	}
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int* count = (int*)malloc((max + 1) * sizeof(int));
	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		count[a[i]] = count[a[i]] + 1;
	}
	int index = 0;
	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index] = i;
			index++;
		}
	}
	free(count);
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int swapped = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0) {
			break;
		}
	}
}

int main() {
    int sizes1[5] = { 5000, 10000, 20000, 40000, 80000 };
	int sizes2[5] = { 200000, 400000, 800000, 1600000, 3200000 };
	int sizes3[5] = { 2000000, 4000000, 8000000, 16000000, 32000000 };
    int choice = -1;

	setlocale(LC_ALL, "Russian");
    srand(time(NULL)); 

    while (choice != 0) {
        printf("\n=== ВЫБЕРИТЕ СОРТИРОВКУ ===\n");
        printf("1 - Сортировка выбором (Selection Sort)\n");
        printf("2 - Сортировка слиянием (Merge Sort)\n");
        printf("3 - Сортировка подсчётом (Counting Sort)\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("Программа завершена.\n");
			break;
        }

        for (int i = 0; i < 5; i++) {
            int n = 0;
			if (choice == 1) {
				n = sizes1[i];
			}
			else if(choice == 2) {
				n = sizes2[i];
			}
			else if (choice == 3) {
				n = sizes3[i];
			}

            int* arr = (int*)malloc(n * sizeof(int));
            int* check = (int*)malloc(n * sizeof(int));
            int* temp = (int*)malloc(n * sizeof(int));

            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 1001;
            }

            clock_t start = clock();
            switch (choice) {
            case 1:
                selectionSort(arr, n);
                break;
            case 2:
                mergeSort(arr, temp, n);
                break;
            case 3:
                countingSort(arr, n);
                break;
            }
            clock_t end = clock();
            double time_sec = (double)(end - start) / CLOCKS_PER_SEC;

            for (int i = 0; i < n; i++) {
                check[i] = arr[i];
            }
            bubbleSort(check, n);

            int ok = 1;
            for (int i = 0; i < n; i++) {
                if (arr[i] != check[i]) {
                    ok = 0;
                    break;
                }
            }

            printf("Итерация %d | Размер: %d | Время: %lf сек | Проверка пузырьком: ", i + 1, n, time_sec);
			if (ok == 1) {
				printf("Массивы совпали\n");
			}
			else {
				printf("Массивы не совпали\n");
			}


            free(arr);
            free(check);
            free(temp);
        }
    }
    return 0;
}