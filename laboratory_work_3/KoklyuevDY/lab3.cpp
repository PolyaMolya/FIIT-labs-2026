#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int proverka(int a[], int count, int numb) {
    for (int i = 0; i < count; i++) {
        if (a[i] == numb) {
            return 0;
        }
    }
    return 1;
}
void zapolnmass(int a[], int n) {
    a[0] = 1 + rand() % 9;
    for (int i = 1;i < n;i++) {
        int numb;
        do {
            numb = rand() % 10;
        } while (proverka(a, i, numb) == 0);
        a[i] = numb;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));

    int n;
    printf("\nВведите длину загадываемого числа (от 2 до 5): ");
    scanf_s("%d", &n);

    if (n >= 2 && n <= 5) {
        int* a = (int*)malloc(n * sizeof(int));

        zapolnmass(a, n);
        printf("Компьютер загадал %d-значное число. Попробуйте угадать.\n", n);

        int bulls = 0;

        while (bulls != n) {
            printf("Ваш вариант: ");

            int number;
            scanf_s("%d", &number);

            int* guess = (int*)malloc(n * sizeof(int));

            for (int i = n - 1; i >= 0; i--) {
                guess[i] = number % 10;
                number = number / 10;
            }

            bulls = 0;
            int cows = 0;

            for (int i = 0; i < n; i++) {
                int guess_numb = guess[i];

                if (guess_numb == a[i]) {
                    bulls++;
                }
                else if (proverka(a, n, guess_numb) == 0) {
                    cows++;
                }
            }

            printf("Результат: %d коров и %d быков\n", cows, bulls);

        }

        printf("Поздравляем! Вы отгадали всю последовательность!\n");
    }
    else {
        printf("Введено неправильное число(\n");
    }

    return 0;
}