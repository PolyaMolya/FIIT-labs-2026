#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int laba3() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int number, n, try = 1;
    int flag = 0;
    printf("Выберите длину загадываемого числа(от 2 до 5): \n");
    scanf("%i", &n);
    int *numberp = malloc(sizeof(int)*n);
    int *nump = malloc(sizeof(int)*n);
    int *b = malloc(sizeof(int)*10);
    for (int i = 0; i<10; i++) {
        b[i] = 0;
    }
    if ((n<2) || (n>5)) {
        printf("Ошибка диапазона\n");
        exit(1);
    } else {
        int *a = malloc(sizeof(int)*n);
        for (int i=0; i<n; i++) {
            a[i] = rand()%10;
            int k = a[i];
            if (b[k] != 0) {
                i--;
            } else {
                b[k] = 1;
            }
        }
        while (flag!=1) {
            int *memory = malloc(sizeof(int)*n);
            printf("Попытка №%i. Введите %i-значное число: \n", try, n);
            scanf("%i", &number);
            if (!number) {
                printf("Ошибка!\n");
                exit(1);
            }
            if (number/pow(10, n-1)<10 && number/pow(10, n-1)>=1) {
                for (int i = 0; i<n; i++) {
                    numberp[i] = number%(10);
                    number = (int) number/10;
                }
                for (int i=0; i<n; i++) {
                    nump[i] = numberp[n-i-1];
                }
                printf("\n\n------------------- Отчёт попытки -------------------\n\n");
                int bp = 0;
                for (int i=0;i<n;i++) {
                    if (a[i]==nump[i]) {
                        bp++;
                    }
                }
                if (bp==n) {
                    flag = 1;
                    printf("Победа! Количество попыток: %i\n", try);
                    exit(1);
                }
                for (int i = 0; i<n; i++) {
                    if (nump[i] == a[i] && memory[i]!=1) {
                        printf("Цифра на позиции %i совпадает с цифрой загаданного числа на той же позиции.\n", i+1);
                        memory[i] = 1;
                    }
                }
                for (int i = 0; i<n; i++) {
                    for (int j = 0; j<n; j++) {
                        if (i!=j && a[i] == nump[j] && memory[i]!=1) {
                            printf("Цифра на позиции %i есть в загаданном числе. \n", j+1);
                            memory[i] = 1;
                        }
                    }
                }
            } else {
                printf("Неверное число");
                try--;
            }
            printf("\n-----------------------------------------------------\n\n");
            try++;
            free(memory);
        }
        free(a);
    }
    free(nump);
    free(b);
    free(numberp);
    return 0;
}

int main() {
    laba3();
    return 0;
}
