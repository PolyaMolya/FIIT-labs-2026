#include <stdio.h>
#include <math.h>

int main() {
    double ra, rb, xa, ya, xb, yb;
    scanf_s("%lf %lf %lf %lf %lf %lf", &ra, &rb, &xa, &ya, &xb, &yb);

    double dist = sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb));
    double eps = 1e-8;

    if (fabs(ra - rb) < eps && fabs(dist) < eps) {
        printf("okrugnosty sovpadayut\n");
        return 0;
    }
    else if (fabs(dist - (ra + rb)) < eps) {
        printf("okrugnosty kasautsya drug druga\n");
        return 0;
    }
    else if (dist > ra + rb) {
        printf("okrugnosty ne imeut obshih tochek\n");
        return 0;
    }
    else if (fabs(dist - fabs(ra - rb)) < eps) {
        printf("odna okrugnost vnutri drugoi i kasaetsya ee\n");
        return 0;
    }
    else if (dist < fabs(ra - rb)) {
        printf("odna okrugnost vnutri drugoi\n");
        return 0;
    }
    else {
        printf("okrugnosty peresekautsya\n");
    }
}
