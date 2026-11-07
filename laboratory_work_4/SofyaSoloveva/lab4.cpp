#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    SetConsoleCP(65001); // русский язык 
    SetConsoleOutputCP(65001);

    char barcodes[20][5];  // шк (+1 для '\0')
    char products[20][50] = 
    {"Тушь для ресниц", "Помада матовая", "Тональный крем", "Шампунь для волос", "Гель для душа",
        "Крем для рук", "Пенка для умывания", "Мицеллярная вода", "Тени для век", "Лак для ногтей",
        "Духи Chanel", "Бальзам для губ", "Скраб для тела", "Дезодорант", "Зубная паста",
        "Маска для лица", "Кондиционер", "Карандаш для глаз", "Румяна", "Крем для лица"};   
    int prices[20];        // цены
    int discounts[20];     // скидки

    // Чек
    int product_incheck[20]; // индексы отсканированных товаров
    int count_all[20]; // индексы количества товаров
    int count_different=0; // количество разных товаров 


    for (int i = 0; i < 20; i++) {
        sprintf_s(barcodes[i], "%04d", i + 1);
        prices[i] = 199 + rand() % (3000-199 +1); // min + rand() % (max - min + 1)
        discounts[i] = 1 + rand() % (50 - 1 + 1);
    }
    
    printf("Отсканируйте товар и введите '1', если хотите сканировать товары дальше. Когда закончите, введите '0'.\n");
    char code[5] = {0};
    int a;
    while (1) {
        printf("Штрих-код: ");
        scanf_s("%s %d", code, (unsigned int)sizeof(code), &a); 

        int f = 0; // поиск товара в массиве
        for (int i = 0; i < 20; i++) {
            if (strcmp(barcodes[i], code) == 0) {  // сравнение строк
                printf("Товар: %s  ", products[i]);
                printf("Цена: %d  ", prices[i]);
                printf("Скидка: %d%%\n", discounts[i]);
                f = 1;

                int already_in_check = 0;
                for (int j = 0; j < count_different; j++) { // ищем не добавлен ли уже товар в чек
                    if (product_incheck[j] == i) { // j это индекс товара "i" в массиве товаров в чеке
                        count_all[j]++; // j это индекс количества товара "i"
                        already_in_check = 1;
                        break;
                    }
                }
                if (already_in_check == 0) { // добавление нового товара в чек
                    product_incheck[count_different] = i;
                    count_all[count_different] = 1;
                    count_different++;
                }
                break;
            }
        }
        if (f == 0) printf("Товара с таким штрих-кодом не существует.\n");
        if (a == 0) break;
    }

    // выводим чек на экран
    float summa_wtih_discount = 0.0;
    int summa_without_discount = 0;
    float discount = 0.0;

    if (count_different == 0) {
        printf("Вы ничего не купили.");
        return 0;
    }
    else {
        printf("\n");
        printf("\n");
        printf("~~~~~~~~~~~~~~~ ЧЕК ~~~~~~~~~~~~~~~\n");
        for (int i = 0; i < count_different; i++) {

            summa_wtih_discount += prices[product_incheck[i]] * ((100 - discounts[product_incheck[i]]) * 0.01) * count_all[i];
            summa_without_discount += prices[product_incheck[i]] * count_all[i];
            discount += (prices[product_incheck[i]] * count_all[i]) - (prices[product_incheck[i]] * ((100 - discounts[product_incheck[i]]) * 0.01) * count_all[i]);
            
            printf("Товар: %s  |  Стоимость за единицу: %d  |  Количество: %d  |  Общая стоимость товар(а/ов): %d\n",
                products[product_incheck[i]], prices[product_incheck[i]], count_all[i], (prices[product_incheck[i]] * count_all[i]));
        }
        printf("Итого:\nСтоимость товар(а/ов) без скидки:  %d\nСкидка: %.2f\n Стоимость товар(а/ов) с учётом скидки:  %.2f\n", 
            summa_without_discount, discount, summa_wtih_discount);
    }
    return 0;
}