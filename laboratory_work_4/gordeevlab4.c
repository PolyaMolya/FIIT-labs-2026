#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define N         12   /* количество товаров            */
#define CODE_LEN  4    /* длина штрих-кода              */
#define NAME_LEN  32   /* макс. длина наименования      */
#define PRICE_LEN 8    /* макс. длина цены (строкой)    */
#define DISC_LEN  4    /* макс. длина скидки (строкой)  */
char barcodes[N][CODE_LEN] = {
    "0123", "0458", "1279", "1364",
    "2580", "3149", "4627", "5091",
    "6812", "7354", "8236", "9071"
};
 
/* 2. Наименования товаров */
char names[N][NAME_LEN] = {
    "Хлеб",   "Молоко", "Сыр",    "Масло",
    "Яйца",   "Кефир",  "Чай",    "Кофе",
    "Сахар",  "Гречка", "Яблоки", "Шоколад"
};

/* 3. Цена за единицу, руб. (без копеек) */
char prices[N][PRICE_LEN] = {
    "45",  "89",  "320", "165",
    "110", "75",  "140", "450",
    "70",  "95",  "130", "99"
};

/* 4. Скидка на товар, % */
char discounts[N][DISC_LEN] = {
    "0",  "5",  "10", "0",
    "5",  "0",  "15", "10",
    "0",  "5",  "0",  "20"
};
int main(){
    SetConsoleCP(65001);       
    SetConsoleOutputCP(65001); // русификация
    int cart[N] = {0}; // заполняем массив нулями, чтобы потом в него складывать количество товаров
    char n[5];  // 4 символа + '\0' //
    while(1){               
        scanf("%4s", n);  // считываем 4 символа и не берём в счёт \0 //
        if (memcmp(n, "exit", 4) == 0){

        
            int total = 0;
            int total_discount = 0;
            printf("\n==================== ИТОГОВЫЙ ЧЕК ====================\n");
            printf("%-12s %-10s %-8s %-12s\n", "Товар", "Цена/шт", "Кол-во", "Сумма");
            printf("------------------------------------------------------\n");
            for (int i = 0; i < N; i++) {
                if (cart[i] > 0) {
                    int price = atoi(prices[i]);
                    int discount = atoi(discounts[i]);
                    int rub_discount = (price * discount) / 100;
                    int final_price = price - rub_discount;
                    int item_total = final_price * cart[i];
                    total += item_total;
                    total_discount += rub_discount * cart[i];

                    printf("%-12s %-10d %-8d %-12d\n", names[i], price, cart[i], item_total);
                }
            }
            printf("------------------------------------------------------\n");
            printf("%-12s %-10s %-8s %-12d\n", "ИТОГО:", "", "", total);
            printf("%-12s %-10s %-8s %-12d\n", "СКИДКА:", "", "", total_discount); // если введён exit то выходим из цикла
            
        }
        else{

        
            int index = -1;
            for (int i = 0; i < N; i++) {
                if (memcmp(n, barcodes[i], 4) == 0) { // побайтовое сравнение n и barcodes[i] на 4 байта если всё совпадёт функция выведет 0
                    index = i;
                    break;
                } // тут работаем с переменнной index как с флагом, -1 индекса нет поэтому будет обозначать что товар не найден
                // а если найден то запомним индекс и выведим его
            }
            cart[index]++;
            if (index != -1) {
            int price = atoi(prices[index]);         // переводим текстовый формат в числовой
            int discount = atoi(discounts[index]);   

        
            int rub_discount = (price * discount) / 100;
            int final_price = price - rub_discount;   // здесь считаем цену со скидкой

            printf("Товар: %s | Цена: %d руб. | Скидка: %d%% | Итого: %d руб.\n", 
                names[index], price, discount, final_price);
            } 
            else {
                printf("Штрих-код не найден\n");
            }
        }
    }

}