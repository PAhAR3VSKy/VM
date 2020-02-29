#include <iostream>
#include <math.h>

using namespace std;

float f(double x)// f(x)
{
	return (float)(pow(exp(1), x) - 4 * pow(x, 2) - 3 * x);
}

float df(float x) // f'(x)
{
	return (float)(pow(exp(1), x) - 8 * x - 3);
}

float d2f(float x) // f''(x)
{
	return (float)(pow(exp(1), x) - 8);
}

float equivalent(float x) // эквивалентная функция
{
	return sqrt((-(exp(1), x) + 3 * x) / 4);
}

float NewtonMethod(float a, float b, float eps)
{
	cout << "-------------------------" << endl;
	cout << "метод Ньютона" << endl;
	float x0, x;
	int i = 0;
	if (f(a) > 0 && d2f(a) > 0 || f(a) < 0 && d2f(a) < 0)
	{
		x0 = a;
	}
	else if (f(b) > 0 && d2f(b) > 0 || f(b) < 0 && d2f(b) < 0)
	{
		x0 = b;
	}
	else
	{
		cout << " нет приблизительного значения " << endl;
		return -1;
	}
	cout << "x0 = " << x0 << endl;
	x = x0;
	do
	{
		x = x - f(x) / df(x);
		i++;
	} while (abs(f(x))> eps && i < i < 10000);
	cout << "Количество итераций = " << i << endl;
	return x;
}

float IterationMethod(double a, double b, double eps)
{
	cout << "-------------------------" << endl;
	cout << "метод простых итераций" << endl;
	float x, x0;
	int i = 0;
	x0 = a;
	x = x0;
	cout << "x0 = " << x0;
	do
	{
		x = equivalent(x0);
		i++;
	} while (abs(x-x0)>eps);
	cout << "Количество итерацций = " << i << endl;
	return x;
}

float secantMethod(float a, float b, float eps)
{
	float x0, x1, x;
	int i = 0;
	if (f(a) > 0 && d2f(a) > 0 || f(a) < 0 && d2f(a) < 0)
	{
		x0 = a;
	}
	else if (f(b) > 0 && d2f(b) > 0 || f(b) < 0 && d2f(b) < 0)
	{
		x0 = b;
	}
	else
	{
		cout << " нет приблизительного значения " << endl;
		return -1;
	}
	x1 = x0 + eps;
	cout << "x0 = " << x0
		<< endl << "x1 = " << x1 << endl;
	do
	{
		x = x1 - (((x1 - x0) * f(x1)) / (f(x0) - f(x1)));		
		x0 = x1;
		x1 = x;
		i++;
	} while (abs(x1 - x0) < eps && i < 10000);
	cout << "Количество итераций = " << i << endl;
	return x;
}

int main()
{
	setlocale(LC_ALL, "ru");
	float a, b, eps;
	int count;
	cout << "a: " << endl;
	cin >> a;
	cout << "b: " << endl;
	cin >> b;
	cout << "eps: " << endl;
	cin >> eps;
	while (1)
	{
		cout << "1. Метод Ньютона"
			<< endl << "2. Метод простых итераций"
			<< endl << "3. Метод секущих" << endl;
		cin >> count;
		switch (count)
		{
		case 1:
			NewtonMethod(a, b, eps);
			break;
		case 2:
			IterationMethod(a, b, eps);
			break;
		case 3:
			secantMethod(a, b, eps);
			break;
		}
	}


}