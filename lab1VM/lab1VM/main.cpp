#include <iostream>
#include <math.h>

using namespace std;

class NonLinearEquations
{
private:
	double a, b, eps;
	double f(double);
	double df(double);
	double d2f(double);
	double equivalent(double);
public:
	double NewtonMethod();
	double IterationMethod();
	double secantMethod();
	NonLinearEquations(double, double, double);
};

NonLinearEquations::NonLinearEquations(double a, double b, double eps)
{
	this->a = a;
	this->b = b;
	this->eps = eps;
}

double NonLinearEquations::f(double x)
{
	return (exp(x) - 4 * pow(x, 2) - 3 * x);
}

double NonLinearEquations::df(double x)
{
	return (exp(x) - 8 * x - 3);
}

double NonLinearEquations::d2f(double x)
{
	return (exp(x) - 8);
}
double NonLinearEquations::equivalent(double x)
{
	return (exp(x) - 4 * pow(x, 2)) / 3;
}

double NonLinearEquations::NewtonMethod()
{
	
	double x0, 
		x;
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
	x = x0;
	do
	{
		i++;
		x0 = x;
		x = x0 - f(x0) / df(x0);
	} while (abs(x-x0)>eps);
	cout << "Количество итераций: " << i << endl;
	return x;
}

double NonLinearEquations::IterationMethod()
{
	
	double x0 = (a + b) / 2;
	double x = x0;
	int i = 0;
	do
	{
		i++;
		x0 = x;
		x = equivalent(x);
	} while (abs(x-x0)>eps);
	cout << "Количество итераций: " << i << endl;
	return x;
}

double NonLinearEquations::secantMethod()
{
	double res = b,
		fx,
		f0x;
	int i = 0;
	do
	{
		i++;
		fx = f(res);
		f0x = f(a);
		res = res - fx / (fx - f0x) * (res - a);
	} while (abs(fx) > eps);
	cout << "Количество итераций: " << i << endl;
	return res;
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

	NonLinearEquations equations(a, b, eps);

	while (1)
	{
		cout << "1. Метод Ньютона"
			<< endl << "2. Метод простых итераций"
			<< endl << "3. Метод секущих" << endl;
		cin >> count;
		switch (count)
		{
		case 1:
			cout << equations.NewtonMethod() << endl;
			break;
		case 2:
			cout << equations.IterationMethod() << endl;
			break;
		case 3:
			cout << equations.secantMethod() << endl;
			break;
		}
	}
}