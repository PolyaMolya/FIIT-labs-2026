// Ott.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vibor;
    printf("Enter 0 if you want to guess the number; enter 1 if you want the computer to guess the number.\n");
    scanf_s("%i", &vibor);
    if (vibor == 0) {
        int x = rand();
        printf("The computer has chosen a number from 1 to 1000; try to guess it. Enter your number.\n");
        int h = 0;
        int i = 0;
        while (h != x) {
            // int ch;
            //while ((ch = getchar()) != '\n');
            scanf_s("%i", &h);
            if (h < x) {
                printf("Your number is less than the one you were thinking of\n");
                i++;
            }
            else if (h > x) {
                printf("Your number is greater than the guessed one\n");
                i++;
            }
            else {
                i++;
                printf("That is right, you guessed the number in %i attempts.\n", i);
                break;
            }
        }
    }
    else if (vibor == 1) {
        printf("Enter a number from 1 to 1000\n");
        int y;
        scanf_s("%i", &y);
        int h = 500;
        int i = 0;
        int r = 250;
        printf("%i\n", h);
        while (h < 1001) {
            char k;
            scanf_s("%c", &k, 1);
            if (r < 1) {
                r = 1;
            }
            if (k == '<') {
                h = h - r;
                r = r / 2;
                i++;
                printf("%i\n", h);
            }
            else if (k == '>') {
                h = h + r;
                r = r / 2;
                i++;
                printf("%i\n", h);
            }
            else if (h == y) {
                i++;
                printf("This number %i \n", h);
                printf("Computer guessed it in %i attempts", i);
                break;
            }
        }
    }

}