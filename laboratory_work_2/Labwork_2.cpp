#include "stdio.h"
#include "stdlib.h"
#include "time.h"


int main() {
	srand(time(NULL));
	printf("1 - you guessing computer`s number \n2 - computer guessing your number \nSelect mode: ");
	int a;
	scanf_s("%i", &a);
	int num, guess, k = 1, step = 500;
	int ans = 3;
	switch(a) {
		case(1):
			num = rand() % 1000 + 1;
			guess = 0;
			while (guess != num) {
				printf("\nEnter your guess: ");
				scanf_s("%i", &guess);
				if (num == guess) {
					printf("\nYes! %i\n\n", k);
				}
				else if (guess < num) {
					printf("\nNumber is bigger\n");
					k += 1;
				}
				else {
					printf("\nNumber is smaller\n");
					k += 1;
				}
			}
			break;
		case(2):
			printf("1 - my number is bigger \n2 - my number is smaller \n0 - is my number");
			printf("\nEnter number: ");
			scanf_s("%i", &num);
			guess = 500;
			while (ans != 0) {
				printf("\n%i\n", guess);
				scanf_s("%i", &ans);
				switch (ans) {
					case(1):
						guess = guess + step / 2 + step % 2;
						step /= 2;
						k += 1;
						break;
					case(2):
						guess = guess - step / 2 - step % 2;
						step /= 2;
						k += 1;
						break;
					case(0):
						printf("\nYes! %i\n", k);
						break;
				} 
			}
	}
}