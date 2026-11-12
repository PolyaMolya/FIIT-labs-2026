#include <stdio.h>
#include <locale.h> 
int main() {
	setlocale(LC_ALL, ""); 
	setlocale(LC_NUMERIC, "C");
	float h, w, d;  // высота ширина глубина(см)
	float plot_dsp, plot_dvp, plot_wood; // плотность дсп двп дерево (г/см3)

	printf("введите h w d");
	scanf_s("%f %f %f", &h, &w, &d);
	printf("введите плотность ДСП ДВП дерева");
	scanf_s("%f %f %f", &plot_dsp, &plot_dvp, &plot_wood);
	
	if (h >= 180 && h <= 220 && w >= 80 && w <= 120 && d >= 50 && d <= 90)
	{
		float M_back = h * w * 0.5 * plot_dvp;
		float M_sides = 2.0 * h * d * 1.5 * plot_dsp;
		float M_bottom = 2.0 * w * d * 1.5 * plot_dsp;
		float M_doors = h * w * 1.0 * plot_wood;
		int count_of_shelves = (int)(h / 40.0);
		float M_shelves = w * d * 1.5 * count_of_shelves* plot_dsp;
		float M_full = (M_back + M_bottom + M_doors + M_shelves + M_sides)/(1000.0);
		printf("Масса шкафа= %f кг", M_full);
	}

	else {
		printf("Введено неверное число");
	}

	return 0;
}
