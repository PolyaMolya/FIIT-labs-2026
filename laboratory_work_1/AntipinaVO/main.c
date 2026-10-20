#include <stdio.h>

int main(void) {
    double h, w, d, pdvp, pdsp, pwood;
    scanf_s("%lf %lf %lf %lf %lf %lf", &h, &w, &d, &pdvp, &pdsp, &pwood);
    double H = h / 100.0;
    double W = w / 100.0;
    double D = d / 100.0;
    double dvp = 0.005, dsp = 0.015, wood = 0.010;

    double back = H * W * dvp * pdvp;
    double sides = 2.0 * H * D * dsp * pdsp;
    double caps = 2.0 * W * D * dsp * pdsp;
    double doors = H * W * wood * pwood;
    int shelves = (int)(H / 0.4) - 1;
    if (shelves < 0) shelves = 0;
    double shelf_w = W - 2.0 * dsp;
    double shelf_d = D - dvp;
    if (shelf_w < 0) shelf_w = 0;
    if (shelf_d < 0) shelf_d = 0;
    double mshelves = shelves * shelf_w * shelf_d * dsp * pdsp;
    double massa = back + sides + caps + doors + mshelves;
    printf("massa:  %f \n", massa);
    return 0;
}
