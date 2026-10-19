
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main() {
    const double EPS = 1e-8;
    int n=1;
    while (n==1) {
        double x1, y1, r1, x2, y2, r2;
        printf("Введите x1 y1 r1:\n");
        scanf("%lf %lf %lf", &x1, &y1, &r1);
        printf("Введите x2 y2 r2:\n");
        scanf("%lf %lf %lf", &x2, &y2, &r2);
        double dist = pow(pow(x1-x2, 2)+pow(y1-y2, 2), 0.5);
        double ans = dist-(r1+r2);
        double ANS = ans*(-1);
        if ((fabs(dist) <= EPS) && (fabs(r1-r2)<=EPS)) {
            printf("Окружности совпадают\n");
        } else if (fabs(dist)<=EPS) {
            printf("Центры совпадают\n");
        } else if (fabs(dist-(r1+r2))<=EPS) {
            printf("Окружности касаются внешне\n");
        } else if ((fabs(dist-(r1-r2))<=EPS) || (fabs(dist-(r2-r1))<=EPS)) {
            printf("Окружности касаются внутри\n");
        } else if ((dist<r1) || (dist<r2)) {
                    if (r1<r2) {
                        printf("Первая окружность внутри второй\n");
                    } else {
                        printf("Вторая окружность внутри первой\n");
                    }
        } else if ((dist<(r1+r2)) && ((ANS<r1) || (ANS<r2))) {
            printf("Окружности пересекаются\n");
        } else {
            printf("Окружности далеко друг от друга\n");
        }
    }
    return 0;
}
