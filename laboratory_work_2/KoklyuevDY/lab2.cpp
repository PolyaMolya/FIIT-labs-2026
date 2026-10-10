#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(NULL));

	printf("Выберите режим работы программы (1 или 2):\n\n");
	int r;
	scanf_s("%d", &r);
	if (r == 1) {
		printf("\nВыбран режим 1\n");
		int random, count = 1, vvod;
		random = rand() % 1000 + 1;
		printf("\nПопробуйте угадать число от 1 до 1000:\n");
		scanf_s("%d", &vvod);
		while (vvod != random) {
			if (vvod < random) {
				printf("Загаданное число больше\n");
				count++;
			}
			else if (vvod > random) {
				printf("Загаданное число меньше\n");
				count++;
			}
			scanf_s("%d", &vvod);
		}
		printf("Угадали. Количество попыток: %d\n", count);

	}
	else if (r == 2) {
		printf("\nВыбран режим 2\n");
		int vvod, min = 1, max = 1000, count = 1,pr;
		char znak;
		printf("\nВведите число от 1 до 1000. Программа попытается отгадать его.\n\n");
		scanf_s("%d", &vvod);
		while (min <= max) {
			pr = (min + max) / 2;
			printf("\nВаше число %d?\n", pr);
			scanf_s(" %c", &znak);
			if (znak == '=') {
				printf("Я угадал число. Количество попыток: %d", count);
				break;
			}
			else if (znak == '>') {
				min = pr+1;
				count++;
			}
			else if (znak == '<') {
				max = pr-1;
				count++;
			}
			else {
				printf("Неверный ввод знака");
			}
		}
	}
	else {
		printf("\nНеправильно введен номер режима работы\n");
	}
	return 0;
}