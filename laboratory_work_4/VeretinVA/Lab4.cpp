#include "stdio.h"
#include "locale.h"

int main()
{
    const int N = 10;

    setlocale(LC_ALL, "Russian");

    char codes[N][5] = { "1111", "2222", "3333", "4444", "5555",
                         "6666", "7777", "8888", "9999", "0001" };
    char names[N][20] = { "Хлеб", "Молоко", "Сок", "Йогурт", "Пельмени",
                          "Яйца", "Масло", "Сахар", "Чай", "Кофе" };
    int prices[N] = { 49, 94, 169, 69, 419,
                      104, 126, 48, 88, 2099 };
    int discount[N] = { 3, 10, 17, 25, 32,
                        6, 8, 11, 2, 49 };
    int count[N] = { 0 };

    int lastScanned = -1;
    int choice = -1;

    while (choice != 0) {
        printf("\n=== ЭЛЕКТРОННАЯ КАССА ===\n");
        printf("1. Сканировать очередной товар\n");
        printf("2. Вывести описание отсканированного товара\n");
        printf("3. Добавить данные о товаре в чек\n");
        printf("4. Сформировать чек за покупку\n");
        printf("5. Рассчитать итоговую сумму к оплате\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            if (lastScanned != -1) {
                printf("%s. Товар не обработан! Сначала добавьте или отмените его (пункт 3)\n", names[lastScanned]);
                break;
            }

            char input[100];
            printf("Введите штрих-код товара: ");
            scanf_s("%99s", input, 100);

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
                lastScanned = found;
                printf("Товар отсканирован.\n");
            }
            break;
        }

        case 2: {
            if (lastScanned == -1) {
                printf("Сначала отсканируйте товар (пункт 1).\n");
            }
            else {
                printf("Товар: %s, %d руб., скидка %d%%\n", names[lastScanned], prices[lastScanned], discount[lastScanned]);
            }
            break;
        }

        case 3: {
            if (lastScanned == -1) {
                printf("Сначала отсканируйте товар (пункт 1).\n");
            }
            else {
                int action = 0;
                printf("%s. 1 - добавить в чек, 0 - не добавлять: ", names[lastScanned]);
                scanf_s("%d", &action);

                if (action == 1) {
                    count[lastScanned]++;
                    printf("%s. Товар добавлен в чек\n", names[lastScanned]);
                    lastScanned = -1;
                }
                else {
                    printf ("%s. Товар не добавлен в чек\n", names[lastScanned]);
                    lastScanned = -1;
                }
            }
            break;
        }

        case 4: {
            int items = 0;
            for (int i = 0; i < N; i++) {
                items += count[i];
            }

            if (items == 0) {
                printf("Чек пуст. Добавьте хотя бы один товар.\n");
            }
            else {
                int total = 0;
                int sale = 0;
                printf("\n----- ЧЕК -----\n");
                for (int i = 0; i < N; i++) {
                    if (count[i] > 0) {
                        int sum = prices[i] * count[i];
                        int itemDiscount = sum * discount[i] / 100;
                        printf("%s - %d руб. x %d шт. (скидка %d%%) = %d руб.\n", names[i], prices[i], count[i], discount[i], sum - itemDiscount);
                        total = total + sum;
                        sale = sale + sum * discount[i] / 100;
                    }
                }
                printf("Общая стоимость: %d руб.\n", total);
                printf("Суммарная скидка: %d руб.\n", sale);
                printf("Итого к оплате: %d руб.\n", total - sale);
            }
            break;
        }

        case 5: {
            int items = 0;
            int total = 0;
            int sale = 0;
            for (int i = 0; i < N; i++) {
                if (count[i] > 0) {
                    int sum = prices[i] * count[i];
                    items += count[i];
                    total += sum;
                    sale += sum * discount[i] / 100;
                }
            }

            if (items == 0) {
                printf("В чеке нет товаров.\n");
            }
            else {
                printf("Общая стоимость: %d руб.\n", total);
                printf("Суммарная скидка: %d руб.\n", sale);
                printf("Итоговая сумма к оплате: %d руб.\n", total - sale);
            }
            break;
        }

        case 0: {
            printf("Работа кассы завершена.\n");
            break;
        }

        default:
            printf("Неверный пункт меню. Введите число от 0 до 5.\n");
            break;
        }
    }

    return 0;
}
