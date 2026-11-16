#include <stdio.h>
#include <windows.h>
double countpol(double h, double t2) {
	int count;
	count = (int)((h - 2.0 * t2) / 400.0);
	return (double)count;
}

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int h_v, w_v, d_v;

	double h, w, d, t1 = 5.0, t2 = 15.0, t3 = 10.0;
	const double plotn_dvp = 850.0, plotn_dsp = 700.0, plotn_der = 600.0;
	double vzad, vbok, vverhniz, vdver, vpol;
	double count;
	double massa;

	printf("Введите данные:\n\nВысота задней стенки(180-220)-h\nШирина задней стенки(80-120)-w\nГлубина боковины(50-90)-d\n\n");
	scanf_s("%i %i %i", &h_v, &w_v, &d_v);
	if ((180 <= h_v && h_v <= 220) && (80 <= w_v && w_v <= 120) && (50 <= d_v && d_v <= 90)) {
		h = h_v * 10.0;
		w = w_v * 10.0;
		d = d_v * 10.0;
		count = countpol(h, t2);
		vzad = (h * w * t1);
		vbok = 2.0 * h * d * t2;
		vverhniz = 2.0 * w * d * t2;
		vdver = h * w * t3;
		vpol = count * (w - 2.0 * t2) * d * t2; //взял толщину как у других элементов из ДСП
		massa = (plotn_dvp * vzad + plotn_dsp * (vbok + vverhniz + vpol) + plotn_der * vdver) / 1000000000.0;
		printf("\nМасса шкафа: %lf кг", massa);
	}
	else {
		printf("\nДанные введены неверно(\n");
	}

	return 0;
}