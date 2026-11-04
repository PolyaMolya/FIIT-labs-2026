#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"

int* generate_secret(int n) {
	int* secret = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		int digit;
		int unique = 0;
		while (unique == 0) {
			unique = 1;
			digit = rand() % 10;
			if (i == 0 && digit == 0) {
				unique = 0;
				continue;
			}
			for (int j = 0; j < i; j++) {
				if (secret[j] == digit) {
					unique = 0;
					break;
				}
			}
		}
		secret[i] = digit;
	}
	return secret;
}

void check_guess(int* secret, int guess, int n, int* bulls, int* cows) {
	int* guess_digits = (int*)malloc(n * sizeof(int));
	int temp = guess;
	for (int i = n - 1; i >= 0; i--) {
		guess_digits[i] = temp % 10;
		temp = temp / 10;
	}
	*bulls = 0;
	*cows = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (guess_digits[i] == secret[j]) {
				if (i == j) {
					(*bulls)++;
				}
				else {
					(*cows)++;
				}
			}
		}
	}
	free(guess_digits);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	do {
		printf("Введите длину загадываемого числа n (от 2 до 5):\n");
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);

	srand(time(NULL));
	int* secret = generate_secret(n);
	printf("Компьютер загадал %d-значное число с неповторяющимися цифрами\n", n);

	int bulls = 0;
	int cows = 0;
	int attempts = 0;
	while (bulls != n) {
		int guess;
		printf("Ваша попытка:\n");
		scanf_s("%d", &guess);
		attempts++;
		check_guess(secret, guess, n, &bulls, &cows);
		printf("Результат: %d коров, %d быков\n", cows, bulls);
	}
	printf("Вы угадали число за %d шагов\n", attempts);
	free(secret);
	return 0;
}
