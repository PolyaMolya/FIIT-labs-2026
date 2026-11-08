#include <stdio.h>
#include <string.h>
#include <locale.h>

int const n = 10;
char barcodes[n][4] = {
    {'1','1','1','1'}, {'2','2','2','2'}, {'1','2','3','4'},
    {'5','6','7','8'}, {'2','3','2','3'}, {'8','9','7','7'},
    {'6','5','7','2'}, {'3','6','2','5'}, {'1','4','7','7'},
    {'1','6','2','5'}
};
char names[n][32] = { "Хлеб", "Молоко", "Сыр", "Яблоки(зеленые)", "Шоколад", 
                      "Чай","кофе", "колбаса","салфетки","котлеты"};
double  prices[n] = {49.0,99.0,349.0,135.0,95.0,190.0,299.0,449.0,200.0,269.0};
int  count[n] = {0,0,0,0,0,0,0,0,0,0};
double discounts[n] = {0.4,0.1,0.30,0.1,0.13,0.5,0.40,0.2,0.15,0.1};


int main() {
    setlocale(LC_ALL, "Russian");
    char input[32];
        while (1) {
            printf("Введите штрих-код (4 цифры), или 'q' для вывода чека : ");
            scanf_s("%31s", input, (unsigned)sizeof(input));



            if (input[0] == 'q' && strlen(input) == 1) {
                break;
            }

            if (strlen(input) != 4) {
                printf("Неправильно введенный штрих-код\n");
                continue;
            }



            int found_index = -1;
            for (int i = 0; i < n; i++) {
                int match = 1;

                for (int j = 0; j < 4; j++) {
                    if (input[j] != barcodes[i][j]) {
                        match = 0; 
                        break;
                    }
                }
                if (match == 1) {
                    found_index = i;
                    count[i]++;
                    break;
                }
            }


            if (found_index != -1) {
                double price = prices[found_index];
                double discountRub = price * discounts[found_index];

                printf("Товар: %s       ", names[found_index]);
                printf("Цена: %.2f руб\n", price - discountRub);
            }

            else {
                printf("Товар с таким штрих-кодом не найден!\n");
            }

        }
        
        double fulldiscount = 0.0;
        double fullprice = 0.0;
        int flag = 0;
        for (int i = 0;i < n;i++) {
            flag += count[i];
        }
        if (flag != 0) {
        printf("\n\nЧЕК:\n\n");
        for (int i = 0; i < n; i++) {
                if (count[i] != 0) {
                    double price_of_one_item = (prices[i] - (prices[i] * discounts[i])) * count[i];
                    printf("Товар: %s     ", names[i]);
                    printf("Цена за единицу без скидки %.0f руб     ", prices[i]);
                    printf("Количество: %i шт     ", count[i]);
                    printf("%.2f руб \n\n", price_of_one_item);

                    fullprice += price_of_one_item;
                    fulldiscount += (prices[i] * discounts[i])*count[i];
                }
            }
        printf("Общая скидка:%.2f руб\n", fulldiscount);
        printf("Общая цена:%.2f руб\n\n\n", fullprice);

        }
        
        else
            printf("В ЧЕКЕ НЕТ ТОВАРОВ\n\n\n");

    return 0;
}

