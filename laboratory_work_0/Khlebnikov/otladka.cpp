// otladka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
int main()
{
	int r1, x1, y1, r2, x2, y2;
	scanf_s("%i %i %i %i %i %i", &r1, &x1, &y1, &r2, &x2, &y2);
	int Ras = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	int sum = r1 + r2;
	if (Ras > sum) {
		printf("The circles do not touch each other");
	}
	else if (Ras == sum) {
		printf("The circles touch");
	}
	else if (Ras < sum && r1 < Ras && r2 < Ras) {
		printf("The circles intersect");
	}
	else if (r1 >= Ras || r2 >= Ras) {
		if (x1 == x2 && y1 == y2) {
			printf("The centers of the circles coincide");
		}
		else if ((r1 >= r2 && r1 < Ras + r2) || (r2 >= r1 && r2 < Ras + r1)) {
			printf("The circles intersect, and one is inside the other");
		}
		else if (r1 == Ras + r2 || r2 == Ras + r1) {
			printf("The circles are tangent to each other, and one is inside the other");
		}
		else if (r1 > Ras + r2 || r2 > Ras + r1) {
			printf("The circles do not intersect, and one is inside the other");
		}
	}
	else {
		printf("error");
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
