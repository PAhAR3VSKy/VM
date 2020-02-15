#include <iostream>
#include <math.h>

using namespace std;

float f(double x)
{
	return (float)(pow(exp(1), x) - 4 * pow(x, 2) - 3 * x);
}

float df(float x) //возвращает значение производной
{
	return (float)(pow(exp(1), x) - 8 * x - 3);
}

float d2f(float x) // значение второй производной
{
	return (float)(pow(exp(1), x) - 8);
}

int main()
{
	int exit = 0, i = 0;//переменные для выхода и цикла
	double x0, xn;// вычисляемые приближения для корня
	double a, b, eps;// границы отрезка и необходимая точность
	do {
		i = 0;
		cout << "Please input [a;b]\n=>";
		cin >> a >> b; // вводим границы отрезка, на котором будем искать корень
		cout << "\nPlease input epsilon\n=>";
		cin >> eps; // вводим нужную точность вычислений
		if (a > b) // если пользователь перепутал границы отрезка, меняем их местами
		{
			x0 = a;
			a = b;
			b = x0;
		}
		if (f(a) * f(b) > 0) // если знаки функции на краях отрезка одинаковые, то здесь нет корня
			cout << "\nError! No roots in this interval\n";
		else
		{
			if (f(a) * d2f(a) > 0)
				x0 = a;
			else
				x0 = b;
			xn = x0 - f(x0) / df(x0); // считаем первое приближение
			cout << ++i << "-th iteration = " << xn << "\n";
			while (fabs(x0 - xn) > eps) // пока не достигнем необходимой точности, будет продолжать вычислять
			{
				x0 = xn;
				xn = x0 - f(x0) / df(x0); // непосредственно формула Ньютона
				cout << ++i << "-th iteration = " << xn << "\n";
			}
			cout << "\nRoot = " << xn; // вывод вычисленного корня
		}
		cout << "\nExit?=>";
		cin >> exit;
	} while (exit != 1); // пока пользователь не ввел exit = 1

	return 0;

}