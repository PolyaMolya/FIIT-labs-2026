#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generate(int* num, int n) { // заполнение загаданного числа разными цифрами
	int i = 0;
	while (i < n) {
		int a = rand() % 10;
		if (i == 0 && a == 0) continue;
		int uniq = 1;
		for (int ind = 0; ind < i; ind++) {
			if (num[ind] == a) {
				uniq = 0;
				break;
			}
		}
		if (uniq == 1) {
			num[i] = a;
			i++;
		}
	}
}
int uniqueness(int* arr, int n) { // проверка вводимого числа на уникальность
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) { 
			if (arr[i] == arr[j]) {
				return 0; 
			}
		}
	}
	return 1;
}

int main()
{
	srand(time(NULL));
	int n;
	printf("Enter the length og the number from 2 to 5.\n");
	scanf_s("%d", &n);

	while (n < 2 || n>5) { // проверка на длину числа
		printf("!!PLEASE!! Enter the length of the number from TWO to FIVE.\n");
		scanf_s("%d", &n);
	}
	int* num = (int*)malloc(sizeof(int) * n);
	if (num == NULL) { 
		printf("Error: memory allocation failed.\n");
		return 1; 
	}
	
	generate(num, n); //создание загаданного числа
	
	printf("The computer has thought of a number, try to guess it.\n");
	int cow = 0, bull = 0, trying;

	while (bull != n) {

		cow = 0, bull = 0;
		scanf_s("%d", &trying);
		if (trying < pow(10, (n - 1)) || trying >= pow(10, n)) { // проверка на длину числа
			printf("!!PLEASE!! Enter a number whose length is %d.\n", n);
			continue;
		}
		int x = trying;
		int* try1 = (int*)malloc(sizeof(int) * n);
		if (try1 == NULL) {
			printf("Error: memory allocation failed.\n");
			return 1;
		}

		for (int i = n - 1; i >= 0; i--) { // заполнение массива вводимого числа
			try1[i] = trying % 10;
			trying = trying / 10;
		}
		if (uniqueness(try1, n)==0) { // проверка на уникальность цифр
			printf("!!PLEASE!! Enter a number with different digits.\n");
			continue;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (num[i] == try1[j]) {
					if (i == j) bull++;
					else cow++;
				}
			}
		}
		if (bull != n) {
			printf("Cows = %d, bulls = %d, try again!\n", cow, bull);
		}
		if (bull == n) {
			printf("That's correct! It is %d!\n", x);
		}
		free(try1);
	}
	
	free(num);
	return 0;
}