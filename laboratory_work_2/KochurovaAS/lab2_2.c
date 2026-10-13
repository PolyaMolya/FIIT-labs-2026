#include <stdio.h>

int main(){
    printf("Загадайте число от 1 до 1000 \n");
    int x = 1;
    int y = 1000;
    int k = 0;
    char ans;
    while (x <= y) {
        int m = x + (y-x) / 2;
        k ++;
        printf("Попытка номер %i. Ваше число > / < / = %i? \n", k, m);
        scanf(" %c", &ans);
        if (ans == '=') {
            printf("Число %i угадано. Использовано попыток - %i\n", m, k);
            return 0;
        }
        else if (ans == '>') {
            x = m+1;
        }
        else if (ans == '<') {
            y = m-1;
        }
        else {
            printf("Неверный символ\n");
            k --;
        }
    }
    printf ("Такого числа нет в диапазоне\n");
    return 0;
}