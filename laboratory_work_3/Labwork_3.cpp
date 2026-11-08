#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void printarr(int *arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%i", arr[i]);
}

int stepen_10(int n) {
	int res = 1;
	for (int i = 0; i < n; i++) {
		res *= 10;
	}
	return res;
}

int main() {
	srand(time(NULL));
	int n;
	do {
		printf("Enter n from 2 to 5: ");
		scanf_s("%i", &n);
	} while (n > 5 || n < 2);
	int *num = (int*)malloc(sizeof(int) * n);
	num[0] = rand() % 9 + 1;
	int i = 1;
	while (i < n) {
		int elem = rand() % 10;
		int flag = 0;
		for (int k = 0; k < i; k++) {
			if (num[k] == elem) {
				flag++;
				break;
			}
		}
		if (flag == 0) {
			num[i] = elem;
			i++;
		}
	}

	int *guess = (int*)malloc(sizeof(int) * n);
	int guess_int;
	int bulls = 0, cows = 0;
	int *bulls_index = (int*)malloc(sizeof(int) * n);
	while (bulls != n) {
		bulls = 0;
		cows = 0;
		for (int i = 0; i < n; i++)
			bulls_index[i] = 0;
		int flag = 0;
		do {
			flag = 0;
			printf("Enter your guess: ");
			scanf_s("%i", &guess_int);
			for (int k = 1; k <= n; k++) {
				guess[n - k] = (guess_int % stepen_10(k)) / (stepen_10(k) / 10);
				guess_int -= guess_int % stepen_10(k);
			}
			for (int i = 0; i < n; i++) {
				for (int k = 0; k < n; k++)
					if (guess[i] == guess[k] && k != i) {
						flag++;
						printf("Numbers must be different\n");
						break;
					}
				if (flag)
					break;
			}
		} while (flag);
		for (int i = 0; i < n; i++) {
			if (guess[i] == num[i]) {
				bulls++;
				bulls_index[i] = i + 1;
			}
			for (int k = 0; k < n; k++)
				if (guess[i] == num[k])
					cows++;
		}
		cows -= bulls;
		printf("Cows: %i\nBulls: %i\n", cows, bulls);
		if (bulls) {
			printf("bulls index: ");
			for (int i = 0; i < n; i++)
				if (bulls_index[i] != 0)
					printf("%i ", bulls_index[i]);
			printf("\n");
		}
	}
	printf("You won!");
}