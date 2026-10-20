#include <stdio.h>
#include <math.h>

int main() {
    const double eps = 1e-8;
    double a, b, xa, ya, xb, yb;
    scanf_s("%lf %lf %lf %lf %lf %lf", &a, &b, &xa, &ya, &xb, &yb);
    double dx = xa - xb;
    double dy = ya - yb;
    double dist = sqrt(dx * dx + dy * dy);
    if (fabs(dist - (a + b)) < eps){
        printf("okrugnosty kasautsya \n");
        return 0;
    }
    else if (dist > a + b) {
        printf("okrugnosty ne kasautsya \n");
        return 0;
    }
    else if ((fabs(a - b) < eps) && (fabs(dist) < eps)) {
            printf("okrugnosty sovpadayut\n");
            return 0;
    }
    else if (fabs(dist - (fmax(a, b) - fmin(a, b))) < eps {
        printf("odna okrygnost vnutri drugoi i kasaetsya ee\n");
        return 0;
    }
    else if (dist < (fmax(a, b) - fmin(a, b))) {
        printf("odna okrygnost vnutri drugoi\n");
        return 0;
    }
    else {
        printf("okrugnosty peresekautsya\n");
    }
}
