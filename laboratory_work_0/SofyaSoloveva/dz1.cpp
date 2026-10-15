#include <stdio.h>
#include <math.h>

int main() {
    double ra, rb, xa, ya, xb, yb;
    scanf_s("%lf %lf %lf %lf %lf %lf", &ra, &rb, &xa, &ya, &xb, &yb);
    double dist = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));

    if ((ra == rb) && (dist == 0)) {
        printf("okrugnosty sovpadayut\n");
        return 0;
    }
    else if (dist == (ra + rb)) {
        printf("okrugnosty kasautsya drug druga\n");
        return 0;
    }
    else if (dist > ra + rb) {
        printf("okrugnosty ne imeut obshih tochek\n");
        return 0;
    }
    else if (dist == (fmax(ra, rb) - fmin(ra, rb))) {
        printf("odna okrygnost vnutri drugoi i kasaetsya ee\n");
        return 0;
    }
    else if (dist < (fmax(ra, rb) - fmin(ra, rb))) {
        printf("odna okrygnost vnutri drugoi\n");
        return 0;
    }

    else {
        printf("okrugnosty peresekautsya\n");
    }
}
