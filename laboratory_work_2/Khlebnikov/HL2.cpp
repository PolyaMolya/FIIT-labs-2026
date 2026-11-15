// HL2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
int main()
{
    int vibor;
    scanf_s("%i", &vibor);
    if (vibor == 0) {
        int x = rand();
        printf("The computer has chosen a number from 1 to 1000; try to guess it. Enter your number.)");
        int h = 0;
        int i = 0;
        while (h != x) {
            // int ch;
            //while ((ch = getchar()) != '\n');
            scanf_s("%i", &h);
            if (h < x) {
                printf("Your number is less than the one you were thinking of");
                i++;
            }
            else if (h > x) {
                printf("Your number is greater than the guessed one");
                i++;
            }
            else {
                i++;
                printf("That is right, you guessed the number in %i attempts.", i);
                break;
            }
        }
    }
    else if (vibor==1) {
        printf("Enter a number from 1 to 1000");
        int y;
        scanf_s("%i", &y);
        int h=500 ;
        int i = 0;
        int r = 250;
        printf("%i", h);
        while (h <1001) {
            char k;
            scanf_s("%c", &k,1);
            if (r < 1) {
                r = 1;
            }
            if (k == '<') {
                h =h -  r;
                r = r / 2;
                i++;
                printf("%i", h);
            }
            else if (k == '>') {
                h = h + r;
                r = r / 2;
                i++;
                printf("%i", h);
            }
            else if(h==y){
                i++;
                printf("This number %i ", h);
                printf("Computer guessed it in %i attempts", i);
                break;
            }
        }
    }
    
    
    //printf("%i", x);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
