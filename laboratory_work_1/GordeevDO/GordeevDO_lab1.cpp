#include <stdio.h>
int main(){
    int h,w,d;
    if (scanf("%d %d %d", &h, &w, &d) != 3){
        printf("Ошибка: нужно ввести три целых числа");
        return 1;
    }
    if (h <= 0 || w <= 0 || d <= 0){
        printf("Ошибка: размеры должны быть положительными");
        return 1;
    }
    double mas;
    mas = 750.0*2.0*(h*w*0.01)+1100.0*(h*w*0.005)+850.0*2.0*(h*d*0.015)+850.0*2.0*(w*d*0.015);//850 - плотность дсп 1100 плотность двп 750 плотность дерева
    if (h<190){
        double masp;
        masp = 3.0*850.0*(0.015*d*(w-0.03));
        mas += masp;

    }
    if (h>=190){
        double masp;
        masp = 3.0*850.0*(0.015*d*(w-0.03));
        mas += masp;

    }

    printf("%lf", mas);
}