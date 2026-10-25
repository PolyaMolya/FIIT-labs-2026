#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_s(int *s, int n){
    int used[10] = {0};
    for (int i = 0; i < n; i++) {
        int d;
        do {
            if (i == 0) d = rand() % 9 + 1;
            else        d = rand() % 10;
        } while (used[d]);
        used[d] = 1;
        s[i] = d;
    }
}

int read_guess(int *g, int n){
    int x;
    scanf("%d", &x);
    
    for (int i = n - 1; i >= 0; i--) {
        g[i] = x % 10;
        x = x / 10;
    }
    if (x != 0)    return 0;//проверка что цифр не больше чем n
    if (g[0] == 0) return 0;//проверка что цифр не меньше чем n
    int used[10] = {0};//вспомогательный массив для проверки повторов цифр в числе
    for (int i = 0; i < n; i++) {
        if (used[g[i]] == 1) return 0;
        used[g[i]] = 1;
    }
    return 1;
}

void count(int *s, int *g, int n, int *bulls, int *cows){
    *bulls = 0;//здесь обнуляем чтобы не было ошибок при подсчете быков и коров
    *cows = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i] == s[j]) {
                if (i == j) (*bulls)++;//сошлись индексы значит угадали с местонахождением
                else        (*cows)++;
            }
}

int main(){
    srand(time(NULL));

    int n;
    printf("Enter length (2-5): ");
    scanf("%d", &n);
    

    int *s = (int*)malloc(n * sizeof(int));
    int *g  = (int*)malloc(n * sizeof(int));
    make_s(s, n);

    int bulls = 0, cows = 0, tries = 0;
    while (bulls != n) {
        printf("Your guess: ");
        if (read_guess(g, n)==0) {//проверка на правильность вводимого условия
            printf("Need %d-digit number with different digits!\n", n);
            continue;
        }
        tries++;
        count(s, g, n, &bulls, &cows);
        printf("Bulls: %d, Cows: %d\n", bulls, cows);
    }

    printf("You win in %d tries!\n", tries);
    free(s);
    free(g);
    return 0;
}