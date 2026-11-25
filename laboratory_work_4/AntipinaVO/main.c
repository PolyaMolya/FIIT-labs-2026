#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int P = 20;

const char* barcodes[P] = {
    "1001", "1002", "1003", "1004", "1005",
    "1006", "1007", "1008", "1009", "1010",
    "1011", "1012", "1013", "1014", "1015",
    "1016", "1017", "1018", "1019", "1020"
};

const char* titles[P] = {
    "Шампунь", "Кондиционер", "Бальзам", "Маска", "Масло",
    "Текстурайзер", "Термозащита", "Пилинг", "Сухой шампунь", "Сыворотка",
    "Тоник для кожи головы", "Пенка", "Лак", "Гель", "Воск",
    "Солевой спрей", "Мусс", "Лосьон", "Жидкий шелк", "Молочко"
};

const int cost[P] = {
    700, 900, 700, 1000, 600, 600, 500, 500, 400, 900,
    500, 600, 400, 400, 500, 600, 400, 700, 1000, 500
};

const int discount_pct[P] = {
    10, 5, 15, 20, 5, 10, 5, 10, 2, 5,
    8, 12, 15, 10, 5, 2, 5, 8, 12, 10
};

int cart[P] = { 0 };

void print_catalog() {
    printf("\n--- Доступные товары ---\n");
    for (int i = 0; i < P; i++) {
        printf("Штрих-код: %s | %-25s | Цена: %4d руб. | Скидка: %2d%%\n",
            barcodes[i], titles[i], cost[i], discount_pct[i]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int menu;
    int finish = 0;
    int scanned_index = -1;
    while (finish == 0) {
        printf("\n ЭЛЕКТРОННАЯ КАССА \n");
        printf("1. Сканировать очередной товар\n");
        printf("2. Вывести описание отсканированного товара\n");
        printf("3. Добавить данные о товаре в чек\n");
        printf("4. Сформировать чек за покупку\n");
        printf("5. Рассчитать итоговую сумму к оплате\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        if (scanf_s("%d", &menu) != 1) {
            while (getchar() != '\n');
            printf("Ошибка ввода! Введите число.\n");
            continue;
        }
        switch (menu) {
        case 1: {
            char input_barcode[5] = { 0 };

            print_catalog();
            printf("Введите 4-значный штрих-код: ");

            scanf_s("%4s", input_barcode, (unsigned)sizeof(input_barcode));
            while (getchar() != '\n');

            scanned_index = -1;
            for (int i = 0; i < P; i++) {
                if (strcmp(barcodes[i], input_barcode) == 0) {
                    scanned_index = i;
                    break;
                }
            }

            if (scanned_index == -1) {
                printf("Ошибка: Товар со штрих-кодом %s не найден!\n", input_barcode);
            }
            else {
                printf("Успех: Товар '%s' отсканирован.\n", titles[scanned_index]);
            }
            break;
        }
        case 2: {
            if (scanned_index != -1) {
                printf("\n--- Описание товара ---\n");
                printf("Наименование: %s\n", titles[scanned_index]);
                printf("Стоимость за единицу: %d руб.\n", cost[scanned_index]);
                printf("Скидка: %d%%\n", discount_pct[scanned_index]);
                printf("-----------------------\n");
            }
            else {
                printf("Сначала отсканируйте товар (пункт 1).\n");
            }
            break;
        }
        case 3: {
            if (scanned_index != -1) {
                cart[scanned_index]++;
                printf("Товар '%s' добавлен в чек. Количество: %d шт.\n",
                    titles[scanned_index], cart[scanned_index]);
            }
            else {
                printf("Сначала отсканируйте товар (пункт 1).\n");
            }
            break;
        }
        case 4: {
            int has_items = 0;
            printf("\n------------------------- ЧЕК -------------------------\n");
            for (int i = 0; i < P; i++) {
                if (cart[i] > 0) {
                    int total_item_cost = cart[i] * cost[i];
                    printf("%-25s | %4d руб. | %2d шт. | %5d руб.\n",
                        titles[i], cost[i], cart[i], total_item_cost);
                    has_items = 1;
                }
            }
            if (!has_items) {
                printf("Чек пуст. Добавьте товары (пункт 3).\n");
            }
            printf("-------------------------------------------------------\n");
            break;
        }
        case 5: {
            int all_buy = 0;
            int all_discounts = 0;
            int has_items = 0;

            for (int i = 0; i < P; i++) {
                if (cart[i] > 0) {
                    all_buy += cart[i] * cost[i];
                    all_discounts += (cart[i] * cost[i] * discount_pct[i]) / 100;
                    has_items = 1;
                }
            }

            if (has_items) {
                printf("\n--- ИТОГОВЫЙ РАСЧЕТ ---\n");
                printf("Общая стоимость товаров:  %d руб.\n", all_buy);
                printf("Суммарная скидка:         %d руб.\n", all_discounts);
                printf("Итоговая сумма к оплате:  %d руб.\n", all_buy - all_discounts);
                printf("-----------------------\n");
            }
            else {
                printf("Невозможно рассчитать сумму: чек пуст.\n");
            }
            break;
        }
        case 0: {
            finish = 1;
            printf("Работа кассы завершена.\n");
            break;
        }
        }
    }
    return 0;
}
