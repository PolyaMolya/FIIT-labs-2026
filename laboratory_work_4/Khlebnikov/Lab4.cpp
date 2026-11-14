// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int kolvo(int a[], int b) {
    int c = 0;
    for (int i = 0;i < 100;i++) {
        if (a[i] == b) {
            c++;
        }
    }
    return c;
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(int arr[100], int n) {
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    const int N = 15;
    int cod[N];
    for (int i = 0;i < N;i++) {
        cod[i] = 1000 + 1 * i;
    }
    
    char name[N][101] = { "Khleb","Moloko","Semechki","Mayonez","Voda", "Govyadina","Riba","Ris", "Psheno", "Kartophel", "Lyk", "Morkov", "Yabloko", "Myka", "Kapysta" };
    char opis[N][100] = { "Fresh baked bread, soft inside with a golden crispy crust","Pure fresh milk, creamy and rich in calcium","Roasted sunflower seeds, salty and perfect for snacking","Classic creamy mayonnaise, adds rich taste to any dish","Clean drinking water, refreshing and essential for life" ,"Fresh beef meat, tender, juicy and high in protein" ,"Fresh fish, delicate flavor, rich in healthy omega-3" ,"White rice grains, soft and fluffy when cooked" ,"Golden millet grain, great for hearty porridge" ,"Fresh potatoes, versatile and perfect for any meal" ,"Fresh onion, sharp aroma and bold savory flavor" ,"Crunchy orange carrots, sweet and full of vitamins" ,"Juicy ripe apple, crisp, sweet and full of flavor" ,"Fine wheat flour, the base for baking bread and pastry" ,"Fresh cabbage, crisp leaves packed with vitamins" };
    int cost[N] = { 55,99,87,98,120,1012,1000,100,50,32,40,31,100,60,35 };
    int pokypka[100] ;
    int skidka[100];
    for (int i = 0;i < 100;i++) {
        skidka[i] = rand() % 50;
        //printf("%i ", skidka[i]);
    }
    
    for (int i = 0;i < 100;i++) {
        pokypka[i] = -1;
    }
    int c = -1;
    int f = 0;
    for (int i = 0;i < 10000;i++) {
        printf("\n1.Scan the product\n2.Display the description of the scanned product\n3.Add product data to the receipt\n4.Generate a receipt for the purchase\n5.Calculate the total amount to be paid\n");
        int a = 0;
        scanf_s("%i", &a);
        
        if (a == 1) {
            int b = 0;
            scanf_s("%i", &b);
            for (int l = 0;l < N;l++) {
                if (1000 + l == b) {
                    c = l;
                    
                }
            }
            
        }
        else if (a == 2) {
            if (c != -1) {
                for (int j = 0;j < 100;j++) {
                    printf("%c", opis[c][j]);
                }
            }
        }
        else if (a == 3) {
            pokypka[f] = c;
            c = -1;
            f++;
        }
        else if (a == 4) {
            bubbleSort(pokypka, 100);
            /*for (int j = 0;j < 100;j++) {
                
                printf("%i ", pokypka[j]);
            }*/
            if (i != 0) {
                int itog = 0;
                int itogSkidka = 0;
                for (int j = 0;j < 100;j++) {
                    if (pokypka[j] != -1&&pokypka[j-1]!=pokypka[j]) {
                        for (int y = 0;y < 100;y++) {
                            printf("%c", name[pokypka[j]][y]);
                            
                        }
                        printf(" ");
                        printf("%irub ", cost[pokypka[j]]);
                        int n = kolvo(pokypka, pokypka[j]);
                        printf("%i shtuk ", n);
                        printf("skidka=%i ", skidka[j]);
                        int neitog = n * cost[pokypka[j]]- n * cost[pokypka[j]]*skidka[j]/100;
                        printf("%irub za tovar\n", neitog);
                        itog = itog + n * cost[pokypka[j]];
                        itogSkidka = itogSkidka + neitog;
                    }
                    
                }
                int vsyaskidka = itog - itogSkidka;
                printf("The total cost of the goods in the purchase=%irub\n", itog);
                printf("The total discount=%irub\n", vsyaskidka);
                printf("The total amount to be paid=%irub\n", itogSkidka);
            }
            break;
        }
        else if (a == 5) {
            if (i != 0) {
                bubbleSort(pokypka, 100);
                int itogSkidka = 0;
                for (int j = 0;j < 100;j++) {
                    if (pokypka[j] != -1 && pokypka[j - 1] != pokypka[j]) {
                        int n = kolvo(pokypka, pokypka[j]);
                        int neitog = n * cost[pokypka[j]] - n * cost[pokypka[j]] * skidka[j] / 100;
                        itogSkidka = itogSkidka + neitog;
                    }
                    
                }
                printf("The total amount to be paid=%irub\n", itogSkidka);
            }
        }
    }

    
    
}

