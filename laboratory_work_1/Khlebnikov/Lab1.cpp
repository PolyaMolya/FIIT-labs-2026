// Lab1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
int main()
{
    float dsp = 0.6;//средняя плотность в г/см3
    float dvp = 0.9;//тяжелая, подходит для мебели в г/см3
    int h, w, d;
    scanf_s("%i %i %i", &h, &w, &d);
    if (h>179&&h<221&&w>79&&w<121&&d>49&&d<91) {
        float zadst = dvp * h * w * 0.5;
        float bok = 2 * dsp * h * d * 1.5;
        float veini = 2 * w * d * 0.1;
        float dver = dvp * h * w * 1;
        //пусть h внутренней полки = 1см
        float pol;
        if (h < 205) {
            pol = 4 * w * d * dsp;
        }
        else {
            pol = 5 * w * d * dsp;
        }
        float sum = zadst + bok + veini + dver + pol;
        printf("%f", sum);
    }
    
}