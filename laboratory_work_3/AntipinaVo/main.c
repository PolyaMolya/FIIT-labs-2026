#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void generate(int* secret, int n) {
    int i = 0;
    while (i < n) {
        int digit = rand() % 10;

        if (i == 0 && digit == 0) continue;

        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (secret[j] == digit) {
                is_unique = 0;
                break;
            }
        }

        if (is_unique) {
            secret[i] = digit;
            i++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    int n;
    printf("Введите длину загадываемого числа (от 2 до 5): ");
    scanf_s("%d", &n);

    while (n < 2 || n > 5) {
        printf("ОШИБКА! Введите длину от 2 до 5: ");
        scanf_s("%d", &n);
    }
    int secret[5];
    generate(secret, n);
    printf("Компьютер загадал %d-значное число с уникальными цифрами.\n", n);
    printf("Попробуйте отгадать его!\n");
    int bulls = 0;
    int cows = 0;
    int trying = 0; 
    while (bulls != n) {
        bulls = 0;
        cows = 0;
        printf("\nВаш вариант: ");

        if (scanf_s("%d", &trying) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода! Введите число.\n");
            continue;
        }
        int min_val = (int)pow(10, n - 1);
        int max_val = (int)pow(10, n);
        if (trying < min_val || trying >= max_val) {
            printf("ОШИБКА! Введите ровно %d-значное число.\n", n);
            continue;
        }
        int guess[5];
        int temp_trying = trying;
        for (int i = n - 1; i >= 0; i--) {
            guess[i] = temp_trying % 10;
            temp_trying = temp_trying / 10;
        }
        int is_unique_input = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (guess[i] == guess[j]) {
                    is_unique_input = 0;
                    break;
                }
            }
        }
        if (!is_unique_input) {
            printf("ОШИБКА! Цифры не должны повторяться. Попробуйте снова.\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (secret[i] == guess[j]) {
                    if (i == j) {
                        bulls++;
                    }
                    else {
                        cows++;
                    }
                }
            }
        }
        if (bulls != n) {
            printf("Результат: %d коров и %d быков \n", cows, bulls);
        }
    }
    printf("\nПОЗДРАВЛЯЮ! Вы отгадали число %d!\n", trying);
    return 0;
}
