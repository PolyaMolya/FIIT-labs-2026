#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_arr(int *a, int n) {
  int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int t = 10;
  int j = rand()%9+1;
  a[0] = b[j];
  b[j] = b[9];
  b[9] = 0;
  for (int i = 1; i < n; i++) {
 	j = rand()%t;
  	a[i] = b[j];
  	b[j] = b[--t];
  	b[t] = 0;
  }
}

int check_arr(int *b1, int b, int n) {
	for (int i = n-1; i >= 0; i--) {
		b1[i] = b%10;
		b /= 10;
	}

	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			if (b1[i] == b1[j]) return 1;

	return 0;
}

int ten(int n) {
	int r = 1;
	while (0 < n--) 
		r = r*10;
	return r;
}

int main() 
{
	srand(time(NULL));
	int n;

	printf("Выберете длину загаданного числа от 2 до 5: ");
	while (scanf("%i", &n) == 0 || n < 2 || n > 5) {
		printf("Неверный ввод\n");
		printf("Введие длину загаданного числа от 2 до 5: ");
		while (getchar() != '\n');
	}

	int *komp_a = (int*)malloc(sizeof(int) * n);
	find_arr(komp_a, n);

	int r = 0;
	for (int i = n; i > 0; i--) {
		r += 9 * ten(i-1);
	}
	
	int b, flag = 1;
	while (flag == 1) {
		int *user_a = (int*)malloc(sizeof(int)*n);
		printf("введите %i-значное '> 0' число c неповторяющимися цифрами: ", n);
		while (scanf("%i", &b)==0 || b < ten(n-1) || b > r || 
			   check_arr(user_a, b, n)) {
			printf("Неверный ввод, повторите попытку: ");
			while(getchar()!='\n');
		}

		int kor = 0, byk = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (komp_a[i] == user_a[j]) 
					if (i == j) byk++;
					else kor++;
		printf("коров = %i\nбыков = %i\n", kor, byk);
		if (byk == n) flag = 0;
		free(user_a);
	}

	printf("Вы угадали, загаданное чило - %i\n", b);

	free(komp_a);

	return 0;
}
