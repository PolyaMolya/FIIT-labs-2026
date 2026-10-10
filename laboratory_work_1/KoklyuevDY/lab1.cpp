#include <stdio.h>
#include <windows.h>
int countpol(int h,int t2){
	int count;
	count = (h-2*t2)/400;
	return count;
}

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int h,w,d, t1 = 5, t2 = 15, t3 = 10;
	const int plotn_dvp = 850, plotn_dsp = 700, plotn_der = 600;
	double vzad, vbok, vverhniz,vdver, vpol;
	int count;
	double massa;

	printf("Введите данные:\n\nВысота задней стенки(180-220)-h\nШирина задней стенки(80-120)-w\nГлубина боковины(50-90)-d\n\n");
	scanf_s("%i %i %i", &h, &w, &d);
	if ((180 <= h && h <= 220) && (80 <= w && w <= 120) && (50 <= d && d <= 90)) {
		h = h * 10;
		w = w * 10;
		d = d * 10;
		count = countpol(h,t2);
		vzad = (h * w * t1);
		vbok = 2*h * d * t2;
		vverhniz = 2 * w * d * t2;
		vdver = h * w * t3;
		vpol = count * (w-2*t2) * d * t2; //взял толщину как у других элементов из ДСП
		massa = (plotn_dvp * vzad + plotn_dsp * (vbok + vverhniz + vpol) + plotn_der * vdver)/1000000000;
		printf("\nМасса шкафа: %lf кг", massa);
	}
	else {
		printf("\nДанные введены неверно(\n");
	}
	
	return 0;
}