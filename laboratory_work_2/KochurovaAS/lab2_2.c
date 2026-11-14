#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Режим 1
void mode1() {
    srand(time(NULL));
    int x = rand() % 1000 + 1;
    int k = 0;
    int ans = 0;
    printf("Программа загадала число от 1 до 1000\n");
    while (ans != x){
        printf("Введите свой вариант\n");
        scanf("%i", &ans);
        k ++;
        if (ans > x){
            printf("Загаданное число меньше. ");
        }
        else if (ans < x){
            printf("Загаданное число больше. ");
        }
    }
    printf("Вы угадали! Попыток - %i, загаданное число %i\n", k, x);
}

//Режим 2
void mode2() {
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
            return;
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
}

int main() {
    int choice = 0;
    while (choice != 1 && choice != 2) {
        printf("\nВыберите режим работы:\n");
        printf("1. Программа загадывает число, вы угадываете\n");
        printf("2. Вы загадываете число, программа угадывает\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 1) {
            mode1();
        } else if (choice == 2) {
            mode2();
        } else {
            printf("Неверный выбор. Пожалуйста, выберите 1 или 2.\n");
        }
    }

    return 0;
}