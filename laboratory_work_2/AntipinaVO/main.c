#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int task1() {
    int num, n, a = 0;
    srand(time(NULL));
    num = rand() % 1000 + 1;
    do {
        scanf_s("%d", &n);
        a++;
        if (n < num) {
            printf(">\n");
        }
        else if (n > num) {
            printf("<\n");
        }
        else {
            printf("ygodali \n");
            printf("popytki: %d\n", a);
        }
    } while (n != num);
    return 0;
}

int task2() {
    int low = 1, high = 1000;
    int n, a = 0;
    char answer;
    printf("otvechate '<','>','='\n");
    while (low <= high) {
        n = (low + high) / 2;
        printf("%d? ", n);
        scanf_s(" %c", &answer, 1);
        if (answer == '=') {
            a++;
            printf("ygadal %d!\n", n);
            printf("popitka %d\n", a);
            break;
        }
        else if (answer == '>') {
            a++;
            low = n + 1;
        }
        else if (answer == '<') {
            a++;
            high = n - 1;
        }
    }
    return 0;
}
int main() {
    int v;
    printf("Viberite 1 or 2 ");
    scanf_s("%d", &v);
    if (v == 1) {
        task1();
    }
    else if (v == 2) {
        task2();
    }
    return 0;
}
