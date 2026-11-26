#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void swap(int& x, int& y);
void viborka(int a[], int N);
void merge(int* a, int* b, int n, int m, int* c);
void merge_sort(int* a, int n, int* b);
void radix_sort(int* a, int n);
void radix_sort_negative(int* a, int n);
void bubble_sort(int* a, int N);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int N;
    int x = 100;
    clock_t start, end;
    double res_time;

    printf("Введите размер массива: ");
    scanf_s("%d", &N);

    if (N <= 0) {
        printf("Некорректный размер массива!\n");
        return 1;
    }

    int* a = (int*)malloc(N * sizeof(int));
    int* original = (int*)malloc(N * sizeof(int));



    for (int i = 0; i < N; i++) {
        a[i] = rand() % 200100 - 10000;
    }
    memcpy(original, a, N * sizeof(int));

    while (x != 0) {
        printf("Выберите сортировку:\n 1-выбором\n 2-merge_sort\n 3-radix_sort\n 4-просмотр массива\n 5-поменять размер массива\n 6 - сортировка пузырьком\n 0-завершить программу\n");
         
        scanf_s("%d", &x);

        switch (x) {

        case 1:
            memcpy(a, original, N * sizeof(int));
            start = clock();

            viborka(a, N);


            end = clock();
            res_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
            printf("сортировка выполнена за %lf мс / %lf сек\nмассив из %d элементов\n", res_time, res_time / 1000, N);
            end = start = 0;
            break;

        case 2: {
            memcpy(a, original, N * sizeof(int));
            int* b = (int*)malloc(N * sizeof(int));
            start = clock();

            merge_sort(a, N, b);

            end = clock();
            res_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
            printf("сортировка выполнена за %lf мс\nмассив из %d элементов\n", res_time, N);
            end = start = 0;
            free(b);
            break;
        }
        case 3:
            memcpy(a, original, N * sizeof(int));
            start = clock();

            radix_sort_negative(a, N);

            end = clock();
            res_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
            printf("сортировка выполнена за %lf мс\nмассив из %d элементов\n", res_time, N);
            end = start = 0;
            break;

        case 4:

            printf("Отсортированный массив:\n");

            for (int i = 0; i < N; i++) {
                printf("%d ", a[i]);
            }

            printf("\n");

            break;

        case 5: {
            int newN;
            printf("Введите новый размер массива: ");
            scanf_s("%d", &newN);
            int* newA = (int*)malloc(newN * sizeof(int));
            int* newOrig = (int*)malloc(newN * sizeof(int));

            free(a);
            free(original);
            a = newA;
            original = newOrig;
            N = newN;

            for (int i = 0; i < N; i++)
                a[i] = rand() % 200100 - 10000;
            memcpy(original, a, N * sizeof(int));

            printf("Массив пересоздан. Новый размер: %d элементов\n", N);
            break;
        }
        case 6:
            memcpy(a, original, N * sizeof(int));

            start = clock();

            bubble_sort(a, N);

            end = clock();
            res_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

            printf("сортировка выполнена за %lf мс / %lf сек\nмассив из %d элементов\n", res_time, res_time / 1000, N);
            break;

        }
    }     
    free(a);
    free(original);



    return 0;
    }






    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }



    void viborka(int a[], int N) {
        for (int i = 0;i < N; i++) {
            int k = i;
            for (int j = i + 1;j < N;j++) {
                if (a[k] > a[j])
                    k = j;
            }
            swap(a[k], a[i]);
        }
    }





    void merge(int* a, int* b, int n, int m, int* c) {
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
    void merge_sort(int* a, int n, int* b) {
        if (n <= 1) return;
        merge_sort(&a[0], n / 2, &b[0]);
        merge_sort(&a[n / 2], n - n / 2, &b[n / 2]);
        merge(&a[0], &a[n / 2], n / 2, n - n / 2, &b[0]);
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }





    void radix_sort(int* a, int n) {
        if (n <= 1) return;
        int max = a[0];
        for (int i = 1; i < n; i++) if (a[i] > max) max = a[i];

        int* out = (int*)malloc(n * sizeof(int));
        for (long exp = 1; max / exp > 0; exp *= 10) {
            int count[10] = { 0 };
            for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
            for (int d = 1; d < 10; d++) count[d] += count[d - 1];
            for (int i = n - 1; i >= 0; i--) {
                int d = (a[i] / exp) % 10;
                out[--count[d]] = a[i];
            }
            memcpy(a, out, n * sizeof(int));
        }
        free(out);
    }


    void radix_sort_negative(int* a, int n) {
        int* neg = (int*)malloc(n * sizeof(int));
        int* pos = (int*)malloc(n * sizeof(int));
        int nn = 0, np = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] < 0) neg[nn++] = -a[i];
            else          pos[np++] = a[i];
        }
        radix_sort(neg, nn);
        radix_sort(pos, np);

        int k = 0;
        for (int i = nn - 1; i >= 0; i--) a[k++] = -neg[i];
        for (int i = 0; i < np; i++)      a[k++] = pos[i];

        free(neg);
        free(pos);
    }

    void bubble_sort(int* a, int N) {
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
    }