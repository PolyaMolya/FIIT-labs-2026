#include <stdio.h>
#include <math.h>

int main()
{
    double qdvp = 850.0, qdsp = 700.0, qtree = 600.0, h, d, w;
    double v1, m1, v2, m2, v3, m3, v4, m4, v5, m5, m;
    scanf_s("%lf %lf %lf", &h, &d, &w);
    if ((h < 180.0 || h>220.0) || (d < 50.0 || d>90.0) || (w < 80.0 || w>120.0)) {
        printf("vvedite correct znachenya\n");
        return 1;
    }

    h = h / 100.0;
    d = d / 100.0;
    w = w / 100.0;

    v1 = h * 0.005 * w; // задняя
    m1 = v1 * qdvp;

    v2 = h * 0.015 * d; // две боковые
    m2 = 2.0 * v2 * qdsp;

    v3 = d * 0.015 * w; // верхняя нижняя
    m3 = 2.0 * v3 * qdsp;

    v4 = h * (w / 2.0) * 0.01; // две двери
    m4 = 2.0 * v4 * qtree;

    v5 = d * 0.015 * (w-0.015*2.0); // полки
    if (h <= 2.0) {
        m5 = 4.0 * v5 * qdsp;
    }
    else {
        m5 = 5.0 * v5 * qdsp;
    }
    m = m1 + m2 + m3 + m4 + m5;

    printf("massa shkafa = %f", m);
    return 0;
}
