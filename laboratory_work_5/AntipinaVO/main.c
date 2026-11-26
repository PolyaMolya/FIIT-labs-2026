#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void random(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void vstavSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void qSort(int* arr, int left, int right) {
    if (left >= right)
        return;
    int pivot = arr[left + (right - left) / 2];
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

void CountingSort(int* arr, int n) {
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
    int n = 0, input = 0, continue_cycle = 0, flag = 0, n_for_cycle;

    do {
        flag = 0;
        printf("Enter n: ");
        scanf_s("%d", &n);
        while (getchar() != '\n');
        if (n < 1) {
            printf("\nn>1!\n");
            flag++;
        }
    } while (flag);
    printf("\n");
    do {
        continue_cycle = 0;
        do {
            flag = 0;
            printf("\nChoose sort:\n1) Insertion sort\n2) Quick sort\n3) Counting sort\n");
            scanf_s("%d", &input);
            while (getchar() != '\n');
            if (input > 3 || input < 1) {
                flag++;
                printf(" 1-3\n");
            }
        } while (flag);
        switch (input) {
        case 1:
            printf("\n#el   Time\n");
            n_for_cycle = n;
            for (int i = 0; i < 5; i++) {
                int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
                random(arr, n_for_cycle);
                clock_t start = clock();
                vstavSort(arr, n_for_cycle);
                clock_t end = clock();
                printf("%i %i %lf\n", i + 1, n_for_cycle, (double)(end - start) / CLOCKS_PER_SEC);
                n_for_cycle *= 5;
                free(arr);
            }
            break;
        case 2:
            printf("\n#el   Time\n");
            n_for_cycle = n;
            for (int i = 0; i < 5; i++) {
                int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
                random(arr, n_for_cycle);
                clock_t start = clock();
                qSort(arr, 0, n_for_cycle - 1);
                clock_t end = clock();
                printf("%i %i %lf\n", i + 1, n_for_cycle, (double)(end - start) / CLOCKS_PER_SEC);
                n_for_cycle *= 5;
                free(arr);
            }
            break;
        case 3:
            printf("\n#el   Time\n");
            n_for_cycle = n;
            for (int i = 0; i < 5; i++) {
                int* arr = (int*)malloc(sizeof(int) * n_for_cycle);
                random(arr, n_for_cycle);
                clock_t start = clock();
                CountingSort(arr, n_for_cycle); 
                clock_t end = clock();
                printf("%i %i %lf\n", i + 1, n_for_cycle, (double)(end - start) / CLOCKS_PER_SEC);
                n_for_cycle *= 5;
                free(arr);
            }
            break;
        }
        do {
            flag = 0;
            printf("\nContinue? (0|1)\n");
            if (scanf_s("%d", &continue_cycle) != 1) {
                while (getchar() != '\n');
                printf("Invalid input!\n");
                flag++;
                continue;
            }
            if (continue_cycle != 0 && continue_cycle != 1) {
                flag++;
                printf(" 0 or 1!\n");
            }
        } while (flag);
    } while (continue_cycle);
    return 0;
}