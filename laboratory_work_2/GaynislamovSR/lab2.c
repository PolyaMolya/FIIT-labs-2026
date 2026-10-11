#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game1(int x) 
{
	int a;

	printf("Угадай число от 1 до 1000: ");

	for (int kl = 1;;kl++) {
		scanf("%i", &a);

		if (1 <= a && a <= 1000) {

			switch ((x >= a) + (x == a)) {
			case 0: printf("загаданное число меньше\n"); break;
			case 1: printf("загаданное число больше\n"); break;
			case 2: printf("угадали\n"); return kl;
			}
			
		} else printf("число от 1 до 1000 (это тоже считается попыткой)\n");
		
		printf("попробуй еще: ");
  }
}

int game2(int x) 
{
	while (x < 1 || x > 1000) {
		printf("загадай число ОТ 1 ДО 1000: ");
		scanf("%i", &x);
	}

	char c;
	int a, ng, vg;

	vg = 1000;
	ng = 0;;
	a  = (vg - ng) / 2;

	for (int kl = 1;;kl++) {
		printf("загаданное число '>', '<' или '=' %i\n", a);
		scanf(" %c", &c);

		if (ng == 999) a = 1000;

		if (c == '>' && x <= a || c == '<' && x >= a || c == '=' && x != a) {
			printf("играй честно\n"); kl--; continue;
		}

		switch (c) {
		case '>': ng = a; a = ng + (vg - ng) / 2; break;
		case '<': vg = a; a = ng + (vg - ng) / 2; break;
		case '=': return kl;
		default: printf("нужно ввести '>', '<' или '='\n"); kl--;
		}
	}
}

void game(int v) {
	int x, kl;

	switch (v) {
	case 1:
		srand(time(NULL));
		x = rand()%1000+1;
		kl = game1(x);
	break;
	case 2:
		printf("Загадайте число от 1 до 1000: ");
		scanf("%i", &x);
		kl = game2(x);
	break;
	}

	printf("кол-во попыток = %i\n", kl);
}

int main()
{	
	int v;
	char fl;

	fl = 'y';
	while (fl=='y') {
		printf("Режим игры (1, 2): "); 
		while (scanf("%i", &v) != 1 || (v != 1 && v != 2)) {
			printf("такого режима нету, введи еще раз '1' или '2': ");
			while (getchar() != '\n');
		} 

		game(v);

		printf("хотите еще раз? (y/n): ");
		while (scanf(" %c", &fl) != 1 || (fl!='y' && fl!='n')) {
			printf("неверный символ, введите еще раз: ");
			while (getchar() != '\n');
		}
	}

	return 0;
}
