#include "stdio.h"

int main() {
    //плотность в кг/см^3
    double p_dsp = 0.00055, p_dvp = 0.0004, p_derevo = 0.00054;
    //ввод высоты h, ширины w и глубины d
    int h, w, d;
    scanf_s("%i %i %i", &h, &w, &d);
    double mass = 0;
    //масса шкафа
    mass = mass + p_dvp * h * w * 0.5 + 2 * p_dsp * h * d * 1.5 + 2 * p_dsp * 2 * d * 1.5 + 2 * p_derevo * h * w;
    //плюс полки
    mass = mass + h / 40 * p_dsp * w * (d - 1.5 * 2) * 1.5;
    printf("%lf", mass);
    return 0;
}