#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
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
    return 0;
}