#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 


int main(){

    setlocale(LC_ALL, "Russian");

    char ch[] = "0123456789";
    char secret[5];
	int n,bulls=0,cows=0;
    int i, j;
    char guess[10];

    srand(time(NULL));
    //Ввод длины числа 
    do {
        printf("Напишите длину числа,которое вы хотите отгадать (от 2 до 5): ");
        if (scanf_s("%d", &n) != 1) return 1;
    } while (n < 2 || n > 5);



//перемешивание массива от 0 до 9
    for (i = 9; i > 0; i--) {
        j = rand() % (i + 1);
        char t = ch[i];
        ch[i] = ch[j];
        ch[j] = t;
//создание рандомного числа 
        for (int w = 0;w < n;w++) {
            secret[w] = ch[w];
        }
    }


        //for (int w = 0; w < n; w++) {
        //    printf("%c", secret[w]);
        //}
        //printf("\n");

    do {
        printf("Введите число, цифры которого не повторяются: ");
        scanf_s("%s", guess, 10);

        if (strlen(guess) != n) {
            printf("Нужно ввести %d цифр\n", n);
            continue;
        }


        bulls = 0;
        cows = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (guess[i] == secret[j]) {
                    if (i == j) bulls++;
                    else cows++;
                }

        printf("Быков: %d, коров: %d\n", bulls, cows);
    } while (bulls != n);

    printf("вы угадали это число");
    for (int w = 0; w < n; w++) {
    printf("%c ", secret[w]);
}

    return 0;
}

