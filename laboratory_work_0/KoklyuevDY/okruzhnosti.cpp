

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "Russian");
	printf("Введите x1 y1 x2 y2 r1 r2\n");
	int x1, x2, y1, y2, r1, r2;
	scanf_s("%i %i %i %i %i %i", &x1,&y1,&x2,&y2,&r1,&r2);
	int dx = x2 - x1;
	int dy = y2 - y1;
	int d2 = dx * dx + dy * dy;

	int sumr = r1 + r2;
	int sumr2 = sumr * sumr;
	int raznr = r1 - r2;
	int raznr2 = raznr * raznr;

	if (d2 == 0 && r1 == r2) {
		printf("Окружности совпадают, бесконечное число общих точек.\n");
	}
	else if ((d2 < (raznr2)) || (d2 == 0 && r1 != r2)) {
		printf("Окружности с центрами O1(%i,%i) O2(%i,%i) и радиусами R1 = %i R2 = %i не имеют общих точек, одна лежит внутри другой.\n", x1, y1, x2, y2, r1, r2);
	}
	else if (d2 > sumr2) {
		printf("Окружности с центрами O1(%i,%i) O2(%i,%i) и радиусами R1 = %i R2 = %i не имеют общих точек.\n", x1, y1, x2, y2, r1, r2);
	}
	else if (d2 == sumr2) {
		printf("Окружности с центрами O1(%i,%i) O2(%i,%i) и радиусами R1 = %i R2 = %i касаются друг друга.\n", x1, y1, x2, y2, r1, r2);
	}
	else if (d2 == raznr2) {
		printf("Окружности с центрами O1(%i,%i) O2(%i,%i) и радиусами R1 = %i R2 = %i касаются друг друга, одна лежит внутри другой.\n", x1, y1, x2, y2, r1, r2);
	}
	else if ((d2 > raznr2) && (d2 < sumr2)) {
		printf("Окружности с центрами O1(%i,%i) O2(%i,%i) и радиусами R1 = %i R2 = %i пересекаются.\n", x1, y1, x2, y2, r1, r2);
	}
	
	return 0;
}


