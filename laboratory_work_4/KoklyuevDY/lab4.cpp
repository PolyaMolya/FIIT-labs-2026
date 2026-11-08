#include <stdio.h>
#include <windows.h>

#define N 20 

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    char code[N][5] = {
        "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010",
        "0011", "0012", "0013", "0014", "0015", "0016", "0017", "0018", "0019", "0020"
    };
    char name[N][30] = { "Хлеб", "Гречка", "Кефир", "Сыр", "Колбаса", "Яйца", "Масло", "Сахар", "Соль", "Чай", "Кофе", "Печенье", "Арахис", "Сок",

        "Сладости", "Молоко", "Мясо", "Овощи", "Уголь", "Шашлыки" };

    int price[N] = { 50, 100, 75, 400, 500, 120, 180, 60, 20, 150, 400, 90, 400, 150, 150, 90, 400, 190, 300, 550 };
    int discount[N] = { 5, 10, 5, 15, 20, 5, 10, 2, 0, 25, 30, 10, 15, 20, 5, 10, 12, 10, 15, 20 };
    int cart[N] = { 0 };
    int index = -1;
    int choice;
    while (1) {
        printf("\n=== Меню электронной кассы ===\n");
        printf("0.Выход\n");
        printf("1.Сканировать товар\n");
        printf("2.Вывести описание отсканированного товара\n");
        printf("3.Добавить данные о товаре в чек\n");
        printf("4.Сформировать чек за покупку\n");
        printf("5.Рассчитать итоговую сумму к оплате\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &choice);
        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            char code1[10];
            printf("Введите штрих-код: ");
            scanf_s("%s", code1, 10);

            index = -1;

            for (int i = 0; i < N; i++) {
                int match = 1;
                for (int j = 0; j < 4; j++) {
                    if (code[i][j] != code1[j]) {
                        match = 0;
                        break;
                    }
                }
                if (match == 1) {
                    index = i;
                    break;
                }
            }
            if (index != -1) {
                printf("Товар найден!\n");
            }
            else {
                printf("Ошибка: штрих-код не найден.\n");
            }
        }
        else if (choice == 2) {
            if (index == -1) {
                printf("Сначала отсканируйте существующий товар.\n");
            }
            else {
                printf("\n--- Описание ---\n");
                printf("Наименование: %s\n", name[index]);
                printf("Штрих-код: %s\n", code[index]);
                printf("Цена: %d руб.\n", price[index]);
                printf("Скидка: %d %%\n", discount[index]);
            }
        }
        else if (choice == 3) {
            if (index == -1) {
                printf("Сначала отсканируйте товар.\n");
            }
            else {
                cart[index]++;
                printf("Товар '%s' добавлен в чек.\n", name[index]);
                index = -1;
            }
        }
        else if (choice == 4) {
            int is_empty = 1;
            printf("\n====================== ЧЕК ======================\n");
            for (int i = 0; i < N; i++) {
                if (cart[i] > 0) {
                    is_empty = 0;
                    int totalprice = price[i] * cart[i];
                    printf("%s - %d руб. - %d шт. - %d руб.\n",
                        name[i], price[i], cart[i], totalprice);
                }
            }
            if (is_empty) {
                printf("Чек пуст.\n");
            }
            printf("=================================================\n");
        }
        else if (choice == 5) {
            int totalsum = 0;
            int totaldiscount = 0;
            int items = 0;

            for (int i = 0; i < N; i++) {
                if (cart[i] > 0) {
                    items = 1;
                    int cost = price[i] * cart[i];
                    int discountrub = (cost * discount[i]) / 100;

                    totalsum += cost;
                    totaldiscount += discountrub;
                }
            }

            if (items == 0) {
                printf("Чек пуст. Итоговая сумма: 0 руб.\n");
            }
            else {
                int final = totalsum - totaldiscount;
                printf("\n=== ИТОГ ===\n");
                printf("Сумма без скидки: %d руб.\n", totalsum);
                printf("Суммарная скидка: %d руб.\n", totaldiscount);
                printf("К оплате: %d руб.\n", final);
                printf("============\n");
            }
        }
        else {
            printf("Неверная команда.\n");
        }
    }
    return 0;
}