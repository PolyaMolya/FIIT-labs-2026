#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int rezhim;
    printf("Выберите режим игры(1 - компьютер загадывает число или 2 - игрок загадывает число):\n");
    scanf("%i", &rezhim);
    if (rezhim==1) {
        int c = 1;
        srand(time(NULL));
        int z = (rand()%1000)+1;
        for(int flag = 0; flag != 1;) {
            printf("Ввелите число от 1 до 1000: ");
            int number;
            scanf("%d", &number);
            if (number == z) {
                flag = 1;
            }
            else if (number>z) {
                printf("Загаданное число меньше\n");
                c+=1;
            }
            else if (number<z) {
                printf("Загаданное число больше\n");
                c+=1;
            }
        }
        printf("Попадание! Количество попыток:%i\n", c);
    } else if (rezhim == 2) {
        srand(time(NULL));
        int flag = 0;
        int c = 1;
        int mx = 1000;
        int mn = 1;
        while (flag==0) {
            char ans;
            int range = mx-mn+1;
            if (range<=0) {
                printf("Ошибка: диапазон пуст!\n");
                break;
            }
            int z = (rand()%range)+mn;
            printf("Загаданное число > < или = %i?\n", z);
            scanf(" %c", &ans);
            if (ans=='>') {
                mn = z+1;
                c++;
            } else if (ans=='<') {
                mx = z-1;
                c++;
            } else if (ans=='=') {
                printf("Попадание! Количество попыток: %i\n", c);
                flag++;
            } else {
                printf("Ошибка, неверный параметр для оценки\n");
                flag++;
            }
            
        }
    } else {
        printf("Данного режима не существует\n");
        exit(1);
    }
    return 0;
}
