#include "stdio.h"
#include "math.h"

int main(){
	double x1, y1, r1;
	double x2, y2, r2;
	const double eps = 1e-8;
	printf("Enter x1 y1 r1\n");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);
	printf("Enter x2 y2 r2\n");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);
	double d = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (d > r1 + r2 + eps) {
		printf("The circles have no common points");
	}
	else if (fabs(d - (r1+r2)) <= eps) {
		printf("The circles touch externally");
	}
	else if ((fabs(r1 - r2) <= eps) && (d <= eps)) {
		printf("The circles coincide");
	}
	else if ((fabs(r1 - r2) > eps) && (fabs(x1 - x2) <= eps) && (fabs(y1 - y2) <= eps)) {
		printf("The centers of the circles coincide, but the radii do not");
	}
	else if (fabs(d - fabs(r1 - r2)) <= eps) {
		printf("The circles touch internally");
	}
	else if (d < fabs(r1 - r2) - eps) {
		printf("One circle is inside another, without touching it");
	}
	else{
		printf("The circles intersect at 2 points");
	}
	return 0;
}
