#include <stdio.h>
#include <math.h>

int main(){
    int x1,x2,y1,y2,r1,r2;
    printf("Enter x1 y1 r1: \n");
    scanf("%d %d %d", &x1, &y1, &r1);
    printf("Enter x2 y2 r2: \n");
    scanf("%d %d %d", &x2, &y2, &r2);
    if (r1 <= 0 || r2 <= 0){
        printf("r must be > 0\n");
        return 1;
    }

    double d = sqrt((x1 - x2) * (x1-x2) + (y1 - y2) *(y1-y2)); // расстояние между двумя точками
    double diff = fabs(r1 - r2); //модуль разностей радиусов

    if (x1 == x2 && y1 == y2 && r1 == r2){
        printf("the circles coincide\n"); // окружности совпадают
    }
    else if (d > r1 + r2){
        printf("The circles don't intersect\n"); //окружности не пересекаются
    }
    else if (d == r1 + r2){
        printf("external contact of circles\n"); //внешнее касание окружностей
    }
    else if (diff < d && d < r1 + r2){
        printf("The circles intersect at two points\n"); //окружности пересекаются в двух точках
    }
    else if (d == diff){
        printf("Internal tangency\n"); //внутреннее касание
    }
    else if (d < diff){
        printf("One circle lies inside another\n"); //Одна окружность лежит внутри другой без касания
    }
    return 0;
}