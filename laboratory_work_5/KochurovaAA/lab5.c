#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Выбором
void selectionSort(int mas[], int n, int f) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((f == 0 && mas[j] < mas[minIndex]) || (f == 1 && mas[j] > mas[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&mas[i], &mas[minIndex]);
        }
    }
}

// 4. qSort
void quickSort(int mas[], int left, int right, int f) {
    if (left >= right) {
        return;
    }
    
    int i = left, j = right;
    int pivot = mas[(left + right) / 2];
    
    while (i <= j) {
        while ((f == 0 && mas[i] < pivot) || (f == 1 && mas[i] > pivot)) {
            i++;
        }
        while ((f == 0 && mas[j] > pivot) || (f == 1 && mas[j] < pivot)) {
            j--;
        }
        if (i <= j) {
            swap(&mas[i], &mas[j]);
            i++;
            j--;
        }
    }
    quickSort(mas, left, j, f);
    quickSort(mas, i, right, f);
}

// 7. Radix Sort
void radixSort(int mas[], int n, int f) {
    int *output = (int*)malloc(n * sizeof(int));
    int max = mas[0];
    for (int i = 1; i < n; i++) {
        if (mas[i] > max) max = mas[i];
    }
    
    for (int div = 1; max / div > 0; div *= 10) {
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(mas[i] / div) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(mas[i] / div) % 10] - 1] = mas[i];
            count[(mas[i] / div) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            mas[i] = output[i];
        }
    }
    free(output);

    if (f == 1) {
        for (int i = 0; i < n / 2; i++) {
            swap(&mas[i], &mas[n - 1 - i]);
        }
    }
}

// Генерация случайного массива
void generateArray(int *mas, int n) {
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 10000;
    }
}

int main() {
    int method, order, f;
    int start_n;
    int continue_cycle = 1;

    srand(time(NULL));

    while (continue_cycle) {
        printf("\nВведите количество файлов: ");
        scanf("%d", &start_n);

        if (start_n < 1) {
            printf("Введите число больше 0\n");
            continue;
        }

        printf("\nВыберите метод сортировки:\n");
        printf("2. Выбором\n4. qSort\n7. RadixSort\n");
        printf("Ваш выбор: ");
        scanf("%d", &method);

        printf("Порядок (1 - возрастание, 2 - убывание): ");
        scanf("%d", &order);
        
        if (order == 2) {
            f = 1;
        } else {
            f = 0;
        }

        printf("\nШаг | Размер | Время (сек)\n");

        int n_for_cycle = start_n; 
        
        for (int step = 0; step < 5; step++) {
            int *mas = (int*)malloc(n_for_cycle * sizeof(int));
            generateArray(mas, n_for_cycle); 

            clock_t start = clock();

            if (method == 2) {
                selectionSort(mas, n_for_cycle, f);
            } else if (method == 4) {
                quickSort(mas, 0, n_for_cycle - 1, f);
            } else if (method == 7) {
                radixSort(mas, n_for_cycle, f);
            } else {
                printf("Неверный выбор.\n");
                free(mas);
                break;
            }

            clock_t end = clock();
            double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

            printf(" %d  | %6d | %f\n", step + 1, n_for_cycle, time_spent);

            free(mas); 
            n_for_cycle *= 5; 
        }

        printf("\nВыполнить сортировку еще раз? (1 - Да, 0 - Нет): ");
        scanf("%d", &continue_cycle);
    }

    printf("Выход из программы.\n");
    return 0;
}