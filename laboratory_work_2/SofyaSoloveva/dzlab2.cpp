#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int typ;
    printf("Choose the type of game. Enter 0 if you want to guess the number yourself. Enter 1 if the computer is guessing.\n");
    scanf_s("%d", &typ);  

    if (typ == 0) {
        int num1 = rand() % (1000 - 1 + 1) + 1; 
        int x, trying = 1;
        printf("The computer has thought of a number, try to guess it\n");
        scanf_s("%d", &x);

        while (x != num1) {
            if (x > num1) printf("Not correct, less\n");
            else printf("Not correct, greater\n");
            scanf_s("%d", &x);
            trying += 1;
        }
        printf("That's correct = %d, trying = %d.\n", num1, trying);
        if (trying <= 3) printf("You have amazing intuition!");
    }

    else if (typ == 1) {
        int max = 1000, min = 1;
        int num1 = rand() % (max - min + 1) + min; 
        int trying = 1; 
        char help;
        printf("Is in %d ?\n", num1);
        scanf_s(" %c", &help, 1);

        while (1) {
            switch (help) {
            case '=': 
                printf("That's correct = %d, trying = %d.\n", num1, trying);
                return 0;
            case '>':
                min = num1+1;
                num1 = (max + min) / 2;
                printf("Is in %d ?\n", num1);
                scanf_s(" %c", &help, 1);
                trying += 1;
                break;
            case '<':
                max = num1-1;
                num1 = (max + min) / 2;
                printf("Is in %d ?\n", num1);
                scanf_s(" %c", &help, 1);
                trying += 1;
                break;
            }
        }
    }
    return 0;
}