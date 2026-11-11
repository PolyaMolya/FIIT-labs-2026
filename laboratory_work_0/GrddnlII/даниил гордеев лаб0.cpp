#include <stdio.h>
#include <math.h>
int main() {
    int x1,y1,r1,x2,y2,r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    double d;
    d = sqrt((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));
    if (d == 0){
        if (r1 == r2){
            printf("Окружности совпадают");
        }
        if(r1 != r2){
            printf("Окружности имеют общий центр, но разные радиусы");
        }

    }else{
        if(r1+r2 < d){
            printf("Окружности не пересекаются и не касаются");

        }
        if(r1+r2 == d){
            printf("Окружности касаются");
        }
        if(r1+r2 > d){
            printf("Окружности пересекаются");
        }
    }

}