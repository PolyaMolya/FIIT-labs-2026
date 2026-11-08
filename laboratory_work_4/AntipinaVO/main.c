#include <stdio.h>    
#include <stdlib.h>   
#include <locale.h>   
#define p 20

const char* titles[p] = {
    "Шампунь", "Кондиционер", "Бальзам", "Маска", "Масло",
    "Текстуайзер", "Термозащита", "Пилинг", "Сухой шампунь", "Сыворотка",
    "Тоник для кожи головы", "Пенка", "Лак", "Гель", "Воск",
    "Солевой спрей", "Мусс", "Лосьон", "Жидкий шелк", "Молочко"
};
const int cost[p] = {
    700, 900, 700, 1000, 600, 600, 500, 500, 400, 900, 500, 600, 400, 400, 500, 600, 400, 700, 1000, 500
};
const int discount_pct[p] = {
    10, 5, 15, 20, 5, 10, 5, 10, 2, 5, 8, 12, 15, 10, 5, 2, 5, 8, 12, 10
};

int cart[p] = { 0 };

void print_tovar() {
    printf("Выберите товар:\n");
    for (int i = 0; i < p; i++) {
        printf("%s - %d\n", titles[i], 1001 + i);
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    int menu;
    int finish = 0;
    while (finish == 0) {
        printf("\n 1 - Выбрать товар\n 2 - Рассчитать итоговую сумму к оплате\n");
        scanf_s("%d", &menu);
        switch (menu) {
        case 1: {
            int tovar, ans;
            print_tovar();
            printf("Введите код товара: ");
            scanf_s("%d", &tovar);
            int number = tovar - 1001;
            if (number < 0 || number >= p) {
                printf("Нет такого товара!\n");
                break; 
            }
            printf("Вы выбрали - %s, стоимость - %d, скидка - %d%%. Хотите добавить в чек?(1 - Да, 2 - Нет)\n",
                titles[number], cost[number], discount_pct[number]);
            scanf_s("%d", &ans);
            if (ans == 1) {
                cart[number]++;
            }
            else if (ans == 2) {
                printf("Отменено.\n");
            }
            break;
        }
        case 2:
            finish = 1;
            break;
        }
    }
    int all_buy = 0;
    int all_discounts = 0;
    printf("\n--------------------------------------------------------\n Чек:");
    for (int i = 0; i < p; i++) {
        if (cart[i] != 0) {
            printf("%s - стоимость за единицу %d руб. - количество %d шт. - общая стоимость за товар %d руб.\n",
                titles[i], cost[i], cart[i], cart[i] * cost[i]);
            all_buy += cart[i] * cost[i];
            all_discounts += (cart[i] * cost[i] * discount_pct[i]) / 100;
        }
    }
    printf("Общая стоимость товаров - %d руб.\n", all_buy);
    printf("Суммарная скидка - %d руб.\n", all_discounts);
    printf("Итоговая сумма - %d руб.\n", all_buy - all_discounts);
    printf("--------------------------------------------------------\n");
    printf("Сумма к оплате: %d\n", all_buy - all_discounts);
    return 0;
}