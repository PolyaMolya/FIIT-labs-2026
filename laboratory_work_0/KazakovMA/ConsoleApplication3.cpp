#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_NUMERIC, "C");
    float x1, y1, r1;
    float x2, y2, r2;
    printf("введите x1 y1 r1 и x2 y2 r2");
    scanf_s("%f %f %f", &x1, &y1, &r1);
    scanf_s("%f %f %f", &x2, &y2, &r2);

    float razn = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); //расстояние между центрами окр.


    
    if (razn==0 && r1==r2){
        printf("окружности совпадают");
    }
    else if (razn>r1+r2) {
        printf("окружности не соприкасаются и далеко друг от друга");
    }
    else if (razn == r1 + r2) {
        printf("внешнее касание в одной точке");
    }
    else if (razn == fabs(r1-r2)){        // fabs - модуль
        printf("внутринее касание");
    
    }
    else if (razn > fabs(r1 - r2) && razn < r1 + r2) {
        printf("окружности пересекаются в двух точках");
    }
    else {
        printf("окружность находится внутри другой и они не пересекаются");
    }
    return 0;
}