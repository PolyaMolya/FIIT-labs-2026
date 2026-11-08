#include "stdio.h"
#include "locale.h"
#define N 10

int main()
{
	setlocale(LC_ALL, "Russian");

	char codes[N][5] = { "1111", "2222", "3333", "4444", "5555",
						 "6666", "7777", "8888", "9999", "0001" };
	char names[N][20] = { "Хлеб", "Молоко", "Сок", "Йогурт", "Пельмени",
						  "Яйца", "Масло", "Сахар", "Чай", "Кофе" };
	int prices[N] = { 49, 94, 169, 69, 419,
					  104, 126, 48, 88, 2099 };
	int discount[N] = { 3, 10, 17, 25, 32,
						6, 8, 11, 2, 49 };
	int count[N] = {0};

	int work = 1;
	char input[100];
	while (work == 1) {
		printf("Введите штрих-код товара | 0 - закончить:\n");
		scanf_s("%99s", input, 100);
		if (input[0] == '0' && input[1] == '\0')
			work = 0;
		else {
			int found = -1;
			for (int i = 0; i < N; i++) {
				int same = 1;
				for (int j = 0; j < 5; j++) {
					if (input[j] != codes[i][j])
						same = 0;
				}
				if (same == 1)
					found = i;
			}
			if (found == -1)
				printf("Товар не найден\n\n");
			else {
				count[found]++;
				printf("%s, %d руб., скидка %d%%\n\n", names[found], prices[found], discount[found]);
			}
		}
	}

	int items = 0;
	for (int i = 0; i < N; i++)
		items = items + count[i];
	if (items == 0)
		printf("Покупок нет\n");
	else {
		int total = 0;
		int sale = 0;
		int sum = 0;
		printf("\n-----ЧЕК-----\n");
		for (int i = 0; i < N; i++) {
			if (count[i] > 0) {
				sum = prices[i] * count[i];
				printf("%s - %d руб. - %d шт. - %d руб.\n", names[i], prices[i], count[i], sum);
				total = total + sum;
				sale = sale + sum * discount[i] / 100;
			}
		}
		printf("Общая стоимость: %d руб.\n", total);
		printf("Скидка: %d руб.\n", sale);
		printf("К оплате: %d руб.\n", total - sale);
	}
	return 0;
}