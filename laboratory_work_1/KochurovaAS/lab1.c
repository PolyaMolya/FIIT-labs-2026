#include <stdio.h>

int main() {
    double h, w, d;
    printf("Введите высоту шкафа (180-220 см): ");
    scanf("%lf", &h);
    printf("Введите ширину шкафа w (80-120 см): ");
    scanf("%lf", &w);
    printf("Введите глубину шкафа d (50-90 см): ");
    scanf("%lf", &d);

    double p_dvp, p_dsp, p_d;
    printf("Введите плотность ДВП (кг/м3): ");
    scanf("%lf", &p_dvp);
    printf("Введите плотность ДСП (кг/м3): ");
    scanf("%lf", &p_dsp);
    printf("Введите плотность дерева (кг/м3): ");
    scanf("%lf", &p_d);

//переводим в метры
    double h_m = h / 100;
    double w_m = w / 100;
    double d_m = d / 100;
//масса задней стенки из двп
    double m_dvp = (h_m * w_m * 0.005) * p_dvp;

//считаем массу дсп
    double v_dsp_bokovini = 2 * (h_m * d_m * 0.015); //объем боковушек
    double v_dsp_krishki = 2 * (w_m * d_m * 0.015); //объем крышек

    int kolvo_polok = (int)(h_m / 0.4) - 1; //кол-во полок
    double v_one_polki = (w_m - 2 * 0.015) * (d_m - 0.005) * 0.015; //объем одной полки
    double v_polok = kolvo_polok * v_one_polki;

    double m_dsp = (v_dsp_bokovini + v_dsp_krishki + v_polok) * p_dsp;

    double v_dveri = 2 * (h_m * (w_m / 2.0) * 0.01); //180объьем дверей
    double m_dveri = v_dveri * p_d;

    double m = m_dvp + m_dsp + m_dveri;

    printf("Общая масса шкафа: ");
    printf("%f", m);

    return 0;
}