#include <stdio.h>

#define MX  4
#define LEN 20

char kod[LEN][MX] = 
{{'0','1','9','2'},
 {'3','4','5','6'},
 {'7','8','0','1'},
 {'2','3','4','5'},
 {'6','7','8','9'},
 {'0','2','4','6'},
 {'1','3','5','7'},
 {'8','9','0','2'},
 {'4','6','8','0'},
 {'1','5','9','3'},
 {'0','3','6','9'},
 {'7','1','5','9'},
 {'1','4','7','9'},
 {'9','3','7','1'},
 {'0','5','2','8'},
 {'4','9','1','6'},
 {'8','3','6','0'},
 {'5','7','2','9'},
 {'1','8','4','7'},
 {'6','2','9','5'}};
char product[LEN][30] = 
{ "Хлеб",
	"Молоко",
	"Яйца",
	"Сыр",
	"Йогурт",
	"Масло_сливочное",
	"Куриное_филе",
	"Фарш_мясной",
	"Рыба",
	"Макароны",
	"Рис",
	"Картофель",
	"Морковь",
	"Лук",
	"Помидоры",
	"Огурцы",
	"Яблоки",
	"Бананы",
	"Сахар",
	"Чай"};
int skidki[LEN] = 
{20, 30, 10, 25, 40, 35, 10, 5, 30, 50, 25, 15, 45, 40, 20, 
10, 5, 15, 20, 50};
int price[LEN] = 
{60, 65, 100, 400, 80, 200, 450, 470, 300, 70, 50, 55, 45, 40, 120, 110, 90, 
130, 75, 105};

char vvod() 
{
	char c, v;
	int i = 0;
	while ((c = getchar()) != '\n') {
		if (c < '0' || c > '5' || i++==1) {
			printf("ошибка ввода, повторите попытку: ");
			while (getchar() != '\n');
			continue;
		} else v = c;
	}
	return v;
}

int v1(char scan[])
{
	char c;
	char scan1[MX];

	printf("Отсканируйте товар: ");
	for (int i = 0; i < MX; i++) {
		c = getchar();
		if (c == '\n')  							
			return -1;
		else if (c < '0' || c > '9')  
			return -2;
		else 
			scan1[i] = c;
	}
	while ((c = getchar()) != '\n') 
		return -2; 

	for (int i = 0; i < MX; i++) 
		scan[i] = scan1[i];

	return 0;
}

int poisk(char scan[])
{
	int sv;
	for (int i = 0; i < LEN; i++) {
		sv = 0;
		for (int j = 0; j < MX; j++) {
			if (scan[j] == kod[i][j]) sv++;
			else continue;
		}
		if (sv == 4) return i;
	}
	return -1;
}

int itog(int x, int y, int z) {
	return
		((float)x - ((float)x/100*z))*y;
}

int proverka(int check[]) {
	for (int i = 0; i < LEN; i++)
		if (check[i] > 0) return 1;
	return 0;
}

int main() 
{
	char v;
	int check[LEN] = {0};
	char scan[MX];
	int inx = -1, res = -1;
	int n, sum, skr;

	for (;;) 
	{
		printf("Меню:\n");
    printf(" 1. Сканировать товар\n");
    printf(" 2. Показать описание последнего отсканированного товара\n");
    printf(" 3. Добавить последний отсканированный товар в чек\n");
    printf(" 4. Сформировать чек\n");
    printf(" 5. Новая покупка (очистить чек)\n");
    printf(" 0. Выход\n");
    printf("Ваш выбор: ");
    v = vvod();

    if (v == '0') break;

    else if (v == '1') {
    	res = v1(scan);
    	if (res != 0) {
    		printf("Ошибка ввода\n\n");
    		if (res == -2) while (getchar() != '\n');
    		continue;
    	} 
    	res = poisk(scan);
    	if (res == -1) {
    		printf("Товар не найден\n\n");
    		continue;
    	}
    	else {
    		printf("Отсканирован товар: %s\n\n", product[res]);
    		inx = res;
    	}
    }

    else if (v == '2') {
    	if (inx == -1) {
    		printf("Сначало отсканируйте товар\n\n");
    		continue;
    	}
	    printf("\n--- Описание товара ---\n");
	    printf("Штрих-код     : %s\n", scan);
	    printf("Наименование  : %s\n", product[inx]);
	    printf("Цена за ед.   : %d руб.\n", price[inx]);
	    printf("Скидка        : %d%%\n\n", skidki[inx]);
    }
    else if (v == '3') {
    	if (inx == -1) {
    		printf("Сначало отсканируйте товар\n\n");
    		continue;
    	}
    	check[inx]++;
    	printf("Товар %s добавлен в чек (количество %i)\n\n",
    					product[inx], check[inx]);
    }
    else if (v == '4') {
    	if (proverka(check) == 0) {
    		printf("В чеке нету товаров\n\n"); 
    		continue;
    	}
    	printf("\nЧек:\n");

    	n = sum = skr = 0;
    	for (int i = 0; i < LEN; i++) {
    		if (check[i] > 0) {
    			res = itog(price[i], check[i], skidki[i]);
    			printf("%i %4s\n", ++n, product[i]);
    			printf("%ix%i => %iр(-%i%%)\n",
    							price[i], check[i], res, skidki[i]);
    			sum += price[i]*check[i];
    			skr += price[i]*check[i] - res;
    		}
    	}
    	printf("-------------------------\n");
    	printf("Товары на сумму %8iр\n", sum);
    	printf("Ваша скидка %12iр\n", skr);
    	printf("ИТОГО %18iр", sum-skr);
    	printf("\n\n");
    }
    else if (v == '5') {
    	for (int i = 0; i < LEN; i++)
    		check[i] = 0;
    	inx = res = -1;
    	printf("Чек очищен");
    	printf("\n\n");
    }
    else printf("Ошибка\n\n");
	}

	return 0;
}