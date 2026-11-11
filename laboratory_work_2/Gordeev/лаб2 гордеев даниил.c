#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    int r;
    printf("Выберите режим:\n1 - вы угадываете число, загаданное компьютером\n2 - компьютер угадывает ваше число\n");
    scanf("%d",&r);
    if (r == 1){

        int a = rand()%1001; 
        printf("Компьютер загадал число от 0 до 1000. Введите вашу догадку:\n");
        while (1) { // 1 чтобы цикл работал вечно до момента где брикаем его
            int b;
            scanf("%d", &b);

            if (b > a) {
                printf("Загаданное число меньше\n");
            }
            else if (b < a) {
                printf("Загаданное число больше\n"); 
            }
            else {
                printf("Вы угадали!\n");
                break; 
            }


        }
    }
    else if (r == 2){
        int a;
        printf("Загадайте число от 1 до 1000 и введите его:\n");
        scanf("%d",&a);
        int b = 500;
        int min = 1;
        int max = 1000;
        char z;
        printf("Отвечайте: > если ваше число больше, < если меньше, = если я угадал\n");
        printf("Ваше число %i?\n",b);
        while(1){
            scanf(" %c", &z);
            if (z == '>'){
                min = b + 1;
                b = (min + max) / 2;
                printf("Ваше число %i?\n",b);
            }
            else if (z == '<'){
                max = b - 1;
                b = (min + max) / 2;
                printf("Ваше число %i?\n",b);
            }
            else if (z == '='){
                printf("Ура, ваше число %i!\n",b);
                break;
            }
        }
    }

}