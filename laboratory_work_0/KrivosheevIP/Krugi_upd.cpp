#include "stdio.h"

int main() {
	int x1, y1, x2, y2, r1, r2;
	scanf_s("%i %i %i %i %i %i", &x1, &y1, &r1, &x2, &y2, &r2);
	int d;
	d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	if (x1 == x2 && y1 == y2 && r1 == r2)
		printf("Sovpadaut");
	else {
		if (d > (r1 + r2) * (r1 + r2)) {
			printf("Net peresecheniy");
		}
		else if (d == (r1 + r2) * (r1 + r2) || d == (r1 - r2) * (r1 - r2)) {
			if (d < r1 || d < r2)
				printf("Vnutrennee kasanie");
			else
				printf("Vneshnee kassanie");
		}
		else {
			printf("Dva peresechenia");
		}
	}
}