#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>

void allcopy(int *dst, const int *src, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void print1d(int *a, int n) {
    for (int i = 0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void scan_int(int *n) {
    if (scanf("%d", n) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        printf("Ошибка ввода!\n");
        exit(1);
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Sort1(int *a, int n) {
    for (int i = 0; i<n; i++) {
        int k = i;
        for (int j = i+1; j<n; j++) {
            if (a[k]>a[j]) {
                k = j;
            }
        }
        swap(&a[k], &a[i]);
    }
}

void qSort(int *a, int left, int right) {
    if (left>=right) {
        return;
    }
    int pivo = a[(left+right)/2];
    int i = left;
    int j = right;
    while (i<=j) {
        while (a[i]<pivo) {
            i++;
        }
        while (a[j]>pivo) {
            j--;
        }
        if (i<=j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    qSort(a, left, j);
    qSort(a,i, right);
}

void Sort3(int *a, int n, int mx) {
    int *b = (int *)malloc((mx + 1) * sizeof(int));
    if (!b) {
        printf("Не удалось выделить память.\n");
        return;
    }
    for (int i = 0; i <= mx; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    int id = 0;
    for (int i = 0; i <= mx; i++) {
        while (b[i] > 0) {
            a[id++] = i;
            b[i]--;
        }
    }
    free(b);
}

int main() {
    int f = 0;
    srand(time(NULL));
    clock_t start, end;
    int n, n1, flag, limit, fprint;
    double srz;
    printf("Введите количество чисел: \n");
    scan_int(&n);
    if (n>1000) {
        limit = 100;
    } else {
        limit = 10000;
    }
    printf("Введите ограничение значений чисел: \n");
    scan_int(&n1);
    if (n<=0) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    if (n1<=0) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    printf("Выводить числа? (0 - да, 1 - нет):\n");
    scan_int(&fprint);
    if (fprint < 0 || fprint > 1) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    if (a == NULL) {
        printf("Не удалось выделить память.\n");
        exit(1);
    }
    for (int i = 0; i<n; i++) {
        a[i] = rand()%n1;
    }
    if (fprint == 0) {
        print1d(a, n);
    }
    allcopy(b, a, n);
    while (f==0) {
        srz = 0.0;
        printf("Выберите сортировку: \n 1. Сортировка выбором\n 2. Сортировка Хоара\n 3. Сортировка подсчётом\n");
        scan_int(&flag);
        switch (flag) {
            case 1:
                for (int i = 0; i<limit; i++) {
                    allcopy(a, b, n);
                    start = clock();
                    Sort1(a, n);
                    end = clock();
                    srz += (((double)(end - start)) / CLOCKS_PER_SEC)*1000;
                }
                srz /= limit;
                printf("Программа выполнилась за %.6lf мс.\n", srz);
                break;
            case 2:
                for (int i = 0; i<limit; i++) {
                    allcopy(a, b, n);
                    start = clock();
                    qSort(a, 0, n-1);
                    end = clock();
                    srz += (((double)(end - start)) / CLOCKS_PER_SEC)*1000;
                }
                srz /= limit;
                printf("Программа выполнилась за %.6lf мс.\n", srz);
                break;
            case 3:
                for (int i = 0; i<limit; i++) {
                    allcopy(a, b, n);
                    start = clock();
                    Sort3(a, n, n1);
                    end = clock();
                    srz += (((double)(end - start)) / CLOCKS_PER_SEC)*1000;
                }
                srz /= limit;
                printf("Программа выполнилась за %.6lf мс.\n", srz);
                break;
            default:
                printf("Ошибка ввода!\n");
                break;
        }
        if (fprint == 0) {
            print1d(a, n);
        }
        allcopy(a, b, n);
        printf("Продолжить? (0 - да, 1 - нет)\n");
        scan_int(&f);
        if (f>1) {
            printf("Ошибка ввода!\n");
            exit(1);
        }
    }
    free(b);
    free(a);
    return 0;
}
