#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    printf("Введите длину загадываемого числа\n");
    int x;
    scanf("%i", &x);
    int n[5];
    srand(time(NULL));
    for (int i = 0; i < x; i++){
        int flag; int d;
        do {
            flag = 1;
            d = rand() % 10;
            for (int j = 0; j < i; j++) {
                if (n[j] == d) flag = 0;
            }
        }
        while (flag == 0);
        n[i] = d;
        printf("%i", n[i]);
    }
    int b = 0, cow;
    while (b != x){
        b = 0, cow = 0;
        printf(" Введите ваш вариант числа\n");
        int ch;
        scanf("%i", &ch);
        int p[5];
        for (int i = x-1; i >= 0; i--){
            p[i] = ch % 10;
            ch = ch / 10;
        }
        for (int i = 0; i < x; i++){
            for (int j = 0; j < x; j++) {
                if (n[i] == p[j]) {
                    if (i == j) b++;
                    else cow++;
                }
            }
        }
        printf("Быков - %i, Коров-%i\n", b, cow);
    }
    printf("Победа!");
}