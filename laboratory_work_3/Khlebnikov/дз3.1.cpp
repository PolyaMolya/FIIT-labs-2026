// дз3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    printf("Enter a number from 2 to 5\n");
    int n;
    scanf_s("%i", &n);
    if (n < 2 || n>5) {
        return 0;
    }

    int* a = new int[n];

    for (int i = 0;i < n;i++) {
        a[i] = rand() % 10;
    }
    
     
    
    int y;
    int* b = new int[n];
    
    for (int i = 0;;i++) {
        int korov = 0;
        int bik = 0;
        printf("Enter a number\n");
        scanf_s("%i", &y);
        int u = y;
        short f=0 ;
        if (y>=10000) {
           f=4 ;
        }
        else if (y>=1000&&y<10000) {
            f=3;
        }
        else if (y>=100&&y<1000) {
            f=2;
        }
        else if (y >= 10 && y < 100) {
            f = 1;
        }
        
        for (int j = 0;j < n;j++) {
            y = u;
            
            if (j == 1) {
                y = y / 10;
            }
            else if (j == 2) {
                y = y / 100;
            }
            else if (j == 3) {
                y = y / 1000;
            }
            else if (j == 4) {
                y = y / 10000;
            }
            b[f] = y % 10;
            f--;
        }
        int otvet = 0;
        for (int j = 0;j < n;j++) {
            if (a[j] == b[j]) {
                otvet++;
            }
            
        }
        int m = 0;
        if (u >= 10000) {
            m = 5;
        }
        else if (u >= 1000 && u < 10000) {
            m = 4;
        }
        else if (u >= 100 && u < 1000) {
            m = 3;
        }
        else if (u >= 10 && u < 100) {
            m= 2;
        }
        
        if (otvet == m)  {
            printf("You guessed the number");
            break;
        }
        for (int j = 0;j < n;j++) {
            if (a[j] == b[j]) {
                bik++;
            }
            for (int s = 0; s < n;s++) {
                if (a[j] == b[s]) {
                    korov++;
                }

            }
        }
        korov = korov - bik;
        printf("%i korov and %i bikov\n", korov, bik);
        
    }

    delete a;
    delete b;
}