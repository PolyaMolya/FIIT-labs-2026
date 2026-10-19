
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double h, w, d;
    printf("Введите через пробел: h w d в см\n");
    scanf("%lf %lf %lf", &h, &w, &d);
    if ((h < 180.0 || h > 220.0) || (w < 80.0 || w > 120.0) || (d < 50.0 || d > 90.0)) {
        printf("Ошибка, неверные параметры\n");
        exit(1);
    }
    h = h * pow(10.0, -2.0);
    w = w * pow(10.0, -2.0);
    d = d * pow(10.0, -2.0);
    double backthick = 0.005;
    double bockovina = 0.015, updown = 0.015, polka = 0.015;
    double door = 0.01;
    double wpolka = w - (2.0 * bockovina);
    double dpolka = d - (door + backthick);
    if (wpolka <= 0.0 || dpolka <= 0.0) {
        printf("Ошибка, параметр w или d слишком маленький\n");
        exit(1);
    }
    int countpolka = (h - (2.0 * updown)) / 0.4;
    double DSP, DVP, WOOD;
    printf("Введите плотность(через пробел в кг/м3): ДСП ДВП ДЕРЕВА\n");
    scanf("%lf %lf %lf", &DSP, &DVP, &WOOD);
    double vpolka = wpolka * dpolka * polka;
    double ans = (h * w * backthick * DVP) + (2.0 * DSP * h * d * bockovina)+ (2.0 * w * d * updown * DSP)+ (h * w * door * WOOD)+ (countpolka * vpolka * DSP);
    printf("Масса шкафа = %lf кг\n", ans);
    return 0;
}
