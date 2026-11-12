#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int comp(void) {
    int low = 1, high = 1000, guess = 0, attempts = 0;
    char answer;

    printf("загадайте число от 1 до 1000\n");
    printf("> - загаданное число больше\n < - загаданное число меньше\n = - это загаданное число\n\n");
    do {
        guess = (low + high) / 2;
        
        printf("это число %i ?\n", guess);
        scanf_s(" %c", &answer);

        if (answer == '>') {
            low = guess + 1;
            attempts = attempts + 1;
        }
        else if (answer == '<') {
            attempts = attempts + 1;
            high = guess - 1;
        }
    } while (answer != '=');

    attempts = attempts + 1;
    
    printf("Угадал за %i попыток число %i\n", attempts, guess);

    return 0;
}

int person(void) {
	int count_of_attempts = 0, number, guess;
	number = (rand()) % 1000 + 1;

	do {
		printf("введите число\n");
		scanf_s("%i", &guess);
		count_of_attempts++;

		if (guess < number)
			printf("загаданное число бoльше вашего\n");

		else if (guess > number)
			printf("загаданное число меньше вашего\n");

		else if (guess == number)
			printf("угадали\n");
	} while (guess != number);

	printf("Всего %i попыток\n", count_of_attempts);
	return 0;
}


int main() {
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    srand(time(NULL));
    int x = 0;
    do {
        printf("Введите '1' если хотите загадать число или '2' если хотите чтобы компьютер загадывал число\n");
        scanf_s("%i", &x);
            switch (x) {
            case (1):
                comp();
                break;
            case (2):
                person();
                break;
            default:
                x = 0;
                printf("Введено не 1 и не 2\n");
            }
    } while (x==0);


	return 0;

}//